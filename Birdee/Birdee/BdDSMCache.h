#ifndef _H_BIRDEE_DSM_CACHE
#define _H_BIRDEE_DSM_CACHE
#include "BdSharedObj.h"
#include "BdSocket.h"
#include <queue>
#include <vector>
#include "hash_compatible.h"
#include <string>

#define CACHE_HELLO_MAGIC (0x2e3a4f01)

extern "C" void init_memcached_this_thread();


#pragma pack(push)
#pragma pack(4)
struct CacheHelloPackage
{
	int magic;
	int cacheid;
};
#pragma pack(pop)

class DSMCache
{
public:
	DSMCache(){}
	//no cache on atomic counters and strings
	virtual SoStatus put(_uint key,int fldid,SoVar v)=0;
	virtual SoVar get(_uint key,int fldid)=0;
};

class DSMNoCache: public DSMCache
{
private:
	SoStorage* backend;
public:
	DSMNoCache(SoStorage* back):backend(back)
	{}
	SoStatus put(_uint key,int fldid,SoVar v)
	{
		return backend->put(key,fldid,v);
	}
	SoVar get(_uint key,int fldid)
	{
		return backend->get(key,fldid);
	}
};


class DSMDirectoryCache: public DSMCache
{
private:

#ifdef BD_DSM_STAT
	unsigned long writes,whit,reads,rhit;
#endif
	SoStorage* backend;
	/*
	cacheline's key:
	|object_id|block_id|
	|  32-bit | 28-bit |
	The lower 4 bit of the original 64bit key is not used.
	Every cache block has 16 entries.
	*/

	typedef std::hash_map<long long,CacheBlock*>::iterator hash_iterator;
	CacheBlock block_cache[DSM_CACHE_SIZE];
	std::queue<CacheBlock*> block_queue;
	std::hash_map<long long,CacheBlock*> cache;
	BD_LOCK queue_lock;
	BD_RWLOCK hash_lock;

	std::vector<std::string> hosts;
	std::vector<int> ports;
	int cache_id;
	BD_SOCKET controllisten;
	BD_SOCKET datalisten;

	class DSMCacheProtocal;
	DSMCacheProtocal* protocal;

	class DSMCacheProtocal
	{
	private:
		std::hash_map<long long,long long> directory;
		BD_RWLOCK dir_lock;
		typedef std::hash_map<long long,long long>::iterator dir_iterator;

		BD_SOCKET* controlsockets;
		BD_SOCKET* datasockets;
		BD_LOCK*   datasocketlocks;
		THREAD_ID* threads;
		DSMDirectoryCache* ths;
		int caches;
		enum CacheMessageKind
		{
			MsgReplyOK=1,
			MsgReplyBadAddress,
			MsgWriteMiss,
			MsgReadMiss,
			MsgWrite,
			MsgRenew,
			MsgWriteback,
		};

		struct Params
		{
			DSMCacheProtocal* ths;
			int target_id;
		};


#ifdef BD_ON_WINDOWS
		static DWORD __stdcall ListenSocketProc(void* param)
#else
		static void* ListenSocketProc(void* param)
#endif
		{
			DSMCacheProtocal* ths=(DSMCacheProtocal*)param;
			for(int i=0;i<ths->ths->cache_id;i++)
			{
				for(int j=0;j<2;j++)
				{
					sockaddr_in remoteAddr;
				#ifdef BD_ON_WINDOWS
					int nAddrlen = sizeof(remoteAddr);
				#else
					unsigned int nAddrlen = sizeof(remoteAddr);
				#endif
					BD_SOCKET mylisten= (j%2==0)?ths->ths->controllisten:ths->ths->datalisten;
					SOCKET sClient = accept((SOCKET)mylisten, (LPSOCKADDR)&remoteAddr, &nAddrlen);
					if(sClient == INVALID_SOCKET)
					{
						printf("cache socket accept error !");
						return 0;
					}
					BD_SOCKET sock=(BD_SOCKET)sClient;
					CacheHelloPackage pack;
					if(RcRecv(sock,&pack,sizeof(CacheHelloPackage))!=sizeof(CacheHelloPackage) || pack.magic!=CACHE_HELLO_MAGIC)
					{
						printf("cache socket handshake error !");
						return 0;
					}
					if(pack.cacheid>=ths->ths->cache_id)
					{
						printf("bad cache id %d!",pack.cacheid);
						return 0;
					}
					Params* param=new Params;
					param->target_id=pack.cacheid;
					param->ths=ths;
					if(j%2==0)
						ths->controlsockets[pack.cacheid]=sock;
					else
						ths->datasockets[pack.cacheid]=sock;

					if(j%2==0)
						ths->threads[pack.cacheid]=UaCreateThreadEx(CacheProtocalProc,param);
					CacheHelloPackage pack2={CACHE_HELLO_MAGIC,ths->ths->cache_id};
					RcSend(sock,&pack2,sizeof(pack2));

				}
			}
			return 0;
		}
#pragma pack(push)
#pragma pack(4)
		struct DataPack
		{
			CacheMessageKind kind;
			long long addr;
			SoVar buf[DSM_CACHE_BLOCK_SIZE];
		};
#pragma pack(pop)

		void ServerRenew(long long addr,int src_id,SoVar v);
		void ServerWrite(long long addr,int src_id,SoVar* buf);
		void ServerWriteback(long long addr,int src_id);
		CacheMessageKind ServerWriteMiss(long long addr,int src_id,SoVar v,SoVar* outbuf);
		CacheMessageKind ServerReadMiss(long long addr,int src_id,SoVar* outbuf);
#ifdef BD_ON_WINDOWS
		static DWORD __stdcall CacheProtocalProc(void* param)
#else
		static void* CacheProtocalProc(void* param)
#endif
		{
			init_memcached_this_thread();
			DSMCacheProtocal* ths=((Params*)param)->ths;
			int target_id=((Params*)param)->target_id;
			delete param;
			DataPack pack;
			for(;;)
			{
				if(RcRecv(ths->controlsockets[target_id],&pack,sizeof(pack))!=sizeof(pack))
				{
					printf("Cache server socket error %d\n",WSAGetLastError());
					//_BreakPoint;
					break;
				}
				switch(pack.kind)
				{
				case MsgReadMiss:
					ths->ServerReadMiss(pack.addr,target_id,NULL);
					break;
				case MsgWriteMiss:
					ths->ServerWriteMiss(pack.addr,target_id,pack.buf[0],NULL);
					break;
				case MsgWrite:
					ths->ServerWrite(pack.addr,target_id,pack.buf);
					break;
				case MsgRenew:
					ths->ServerRenew(pack.addr,target_id,pack.buf[0]);
					break;
				case MsgWriteback:
					ths->ServerWriteback(pack.addr,target_id);
					break;
				default:
					printf("Bad cache server message %d\n",pack.kind);
				}
			}
			return 0;
		}
	public:
		void Writeback(long long addr);
		void Write(long long addr,CacheBlock* blk);

		/*
		Send a write message and fetch the written block
		params:
			addr : the exact address of the miss
			v : the new value
			blk : the fetched block will be store here
		*/
		SoStatus WriteMiss(long long addr,SoVar v,CacheBlock* blk);
		SoStatus ReadMiss(long long addr,CacheBlock* blk);


		DSMCacheProtocal(DSMDirectoryCache* t) : ths(t)
		{
			caches=ths->hosts.size();
			controlsockets=new BD_SOCKET[caches];
			datasockets=new BD_SOCKET[caches];
			threads=new THREAD_ID[caches];
			datasocketlocks=new BD_LOCK[caches];
			for(int i=0;i<caches;i++)
			{
				UaInitLock(&datasocketlocks[i]);
			}
			UaInitRWLock(&dir_lock);
			THREAD_ID th=UaCreateThreadEx(ListenSocketProc,this);
			for(int i=ths->cache_id+1;i<caches;i++)
			{
				BD_SOCKET sock=RcConnect((char*)ths->hosts[i].c_str(),ths->ports[i]+1);
				if(sock==NULL)
				{
					printf("cache socket connect error %d!\n",i);
					_BreakPoint;
				}
				CacheHelloPackage pack={CACHE_HELLO_MAGIC,ths->cache_id};
				RcSend(sock,&pack,sizeof(pack));
				if(RcRecv(sock,&pack,sizeof(CacheHelloPackage))!=sizeof(CacheHelloPackage) || pack.magic!=CACHE_HELLO_MAGIC 
					||pack.cacheid!=i)
				{
					printf("cache socket handshake error %d !",i);
					_BreakPoint;
				}
				controlsockets[i]=sock;
				/////////////////////////////////////////////////////////////

				sock=RcConnect((char*)ths->hosts[i].c_str(),ths->ports[i]+2); //data sockets
				if(sock==NULL)
				{
					printf("cache socket connect error %d!\n",i);
					_BreakPoint;
				}
				CacheHelloPackage pack2={CACHE_HELLO_MAGIC,ths->cache_id};
				RcSend(sock,&pack2,sizeof(pack2));
				if(RcRecv(sock,&pack,sizeof(CacheHelloPackage))!=sizeof(CacheHelloPackage) || pack.magic!=CACHE_HELLO_MAGIC 
					||pack.cacheid!=i)
				{
					printf("cache socket handshake error %d !",i);
					_BreakPoint;
				}
				datasockets[i]=sock;
			}
			UaWaitForThread(th);
			for(int i=0;i<caches;i++)
			{
				if(i==ths->cache_id)
					continue;
				Params* param=new Params;
				param->target_id=i;
				param->ths=this;
				threads[i]=UaCreateThreadEx(CacheProtocalProc,param);
			}
			printf("LISTEN OK\n");
		}

		~DSMCacheProtocal()
		{
			for(int i=0;i<caches;i++)
			{
				if(i==ths->cache_id)
					continue;
				closesocket((SOCKET)controlsockets[i]);
				closesocket((SOCKET)datasockets[i]);
				UaKillLock(&datasocketlocks[i]);
				UaStopThread(threads[i]);
			}
			delete []controlsockets;
			delete []datasockets;
			delete []datasocketlocks;
			delete []threads;
			UaKillRWLock(&dir_lock);
		}
	};
	//end of class DSMCacheProtocal


	inline void mapput(long long key,CacheBlock* blk)
	{
		UaEnterWriteRWLock(&hash_lock);
		cache[key]=blk;
		UaLeaveWriteRWLock(&hash_lock);
	}

	/*
	return a cache block from free list. if no free block is 
	available, swap out a block. Then this function puts the
	new block to the cache, using the key "k".
	input: k - the key of the new block
	output: return val - new cache block
	        is_pending - if true, there is a prevoius pending
				block request of the same address. You should
				wait for the lock of the block until the block
				is ready.
				if false, the returned block is a new block,
				and the block's lock is held. RELEASE it when 
				the block is ready!!!!
	*/
	CacheBlock* getblock(long long k,bool& is_pending);

	inline void freeblock(CacheBlock* blk)
	{
		UaEnterWriteRWLock(&blk->lock);
		blk->key=DSM_CACHE_BAD_KEY;
		UaLeaveWriteRWLock(&blk->lock);

		UaEnterLock(&queue_lock);
		block_queue.push(blk);
		UaLeaveLock(&queue_lock);
	}

public:

	DSMDirectoryCache(SoStorage* back,std::vector<std::string> mhosts,std::vector<int> mports,int mcache_id,
		BD_SOCKET mcontrollisten,BD_SOCKET mdatalisten)
		: backend(back),hosts(mhosts),ports(mports),cache_id(mcache_id),controllisten(mcontrollisten),datalisten(mdatalisten)
	{
		#ifdef BD_DSM_STAT
			writes=0;
			whit=0;
			reads=0;
			rhit=0;
		#endif
		for (int i=0;i<DSM_CACHE_SIZE;i++)
		{
			block_cache[i].key=DSM_CACHE_BAD_KEY;
			UaInitRWLock(&block_cache[i].lock);
			block_queue.push(&block_cache[i]);
		}
		UaInitRWLock(&hash_lock);
		UaInitLock(&queue_lock);
		protocal=new DSMCacheProtocal(this);
	}

	~DSMDirectoryCache()
	{
		delete protocal;
		for (int i=0;i<DSM_CACHE_SIZE;i++)
		{
			UaKillRWLock(&block_cache[i].lock);
		}
		UaKillLock(&queue_lock);
		UaKillRWLock(&hash_lock);
	}
	
	SoStatus put(_uint key,int fldid,SoVar v);
	SoVar get(_uint key,int fldid);
};



#endif