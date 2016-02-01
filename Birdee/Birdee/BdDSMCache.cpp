#include "BdSharedObj.h"
#include "hash_compatible.h"
#include <time.h>
#include <queue>
#include <assert.h>
#include <BdSocket.h>

#define DSM_CACHE_SIZE 2048

using namespace std;

#define CACHE_HELLO_MAGIC (0x2e3a4f01)

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
	//no cache on atomic counters and strings
	virtual SoStatus put(_uint key,int fldid,SoVar v)=0;
	virtual SoVar get(_uint key,int fldid)=0;
};

#define FLD_HIGH_MASK (0xfffffff0)
#define FLD_LOW_MASK (0x0000000f)
#define A_BAD_KEY (0x000000000000000f)

class DirectoryDSMCache:DSMCache
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

	typedef hash_map<long long,CacheBlock*>::iterator hash_iterator;
	CacheBlock block_cache[DSM_CACHE_SIZE];
	queue<CacheBlock*> block_queue;
	hash_map<long long,CacheBlock*> cache;
	BD_LOCK queue_lock;
	BD_RWLOCK hash_lock;

	vector<string> hosts;
	vector<int> ports;
	int cache_id;
	BD_SOCKET controllisten;
	BD_SOCKET datalisten;

	class DSMCacheProtocal
	{
	private:
		hash_map<long long,long long> directory;
		BD_RWLOCK dir_lock;
		typedef hash_map<long long,long long>::iterator dir_iterator;

		BD_SOCKET* controlsockets;
		BD_SOCKET* datasockets;
		BD_LOCK*   datasocketlocks;
		THREAD_ID* threads;
		DirectoryDSMCache* ths;
		int caches;
		enum CacheMessageKind
		{
			DSMReadMiss=1,
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
						ths->threads[pack.cacheid]=UaCreateThreadEx(CacheProtocalProc,param);
					CacheHelloPackage pack={CACHE_HELLO_MAGIC,ths->ths->cache_id};
					RcSend(sock,&pack,sizeof(pack));
					if(j%2==0)
						ths->controlsockets[pack.cacheid]=sock;
					else
						ths->datasockets[pack.cacheid]=sock;
				}
			}
			return 0;
		}


		enum ServerReplyKind
		{
			ReplyOK=1,
			ReplyBadAddress,
		};
#pragma pack(push)
#pragma pack(4)
		struct ServerReply
		{
			ServerReplyKind status;
		};
#pragma pack(pop)

		#ifdef BD_ON_WINDOWS
		static DWORD __stdcall CacheProtocalProc(void* param)
#else
		static void* CacheProtocalProc(void* param)
#endif
		{
			DSMCacheProtocal* ths=((Params*)param)->ths;
			int target_id=((Params*)param)->target_id;
			delete ths;
			
		}


		ServerReplyKind ServerReadMiss(long long addr,int src_id,void* outbuf)
		{
			bool islocal= (src_id==ths->cache_id);
			ServerReplyKind status;
			if(islocal &&  ((addr>>4) % caches!=ths->cache_id))
			{
				status=ReplyBadAddress;
				RcSend((BD_SOCKET)outbuf,&status,sizeof(status));
				return status;
			}
			UaEnterWriteRWLock(&dir_lock);
			dir_iterator itr=directory.find(addr);
			long long old=0;
			if(itr!=directory.end())
			{
				old=itr->second;
			}
			old |= ( ((long long)1)<< src_id);
			directory[addr]=old;
			UaLeaveWriteRWLock(&dir_lock);
		}

	public:

		SoStatus ReadMiss(long long addr,CacheBlock* blk)
		{
			int target_cache_id=(addr>>4) % caches;
			ServerReplyKind rep;
			if(target_cache_id==ths->cache_id)
				rep=ServerReadMiss(addr,ths->cache_id,blk);
			else
			{

			}
		}

		DSMCacheProtocal(DirectoryDSMCache* t) : ths(t)
		{
			caches=ths->hosts.size();
			controlsockets=new BD_SOCKET[caches];
			datasockets=new BD_SOCKET[caches];
			threads=new THREAD_ID[caches];
			datasocketlocks=new BD_LOCK[caches];
			for(int i=0;i<caches;i++)
				UaInitLock(&datasocketlocks[i]);
			UaInitRWLock(&dir_lock);
			THREAD_ID th=UaCreateThreadEx(ListenSocketProc,ths);
			for(int i=ths->cache_id+1;i<caches;i++)
			{
				Params* param=new Params;
				param->target_id=ths->cache_id;
				param->ths=this;
				threads[i]=UaCreateThreadEx(CacheProtocalProc,param);
				BD_SOCKET sock=RcConnect((char*)ths->hosts[i].c_str(),ths->ports[i]);
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

				sock=RcConnect((char*)ths->hosts[i].c_str(),ths->ports[i]+1); //data sockets
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
	}protocal;
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
	inline CacheBlock* getblock(long long k,bool& is_pending)
	{
		UaEnterLock(&queue_lock);

		UaEnterReadRWLock(&hash_lock);
		hash_iterator itr=cache.find(k);
		if(itr!=cache.end()) 
		{
			/*if a pending block is already in the cache,
			we just return the new block.
			(which means another block request for the same address
			has already sent) 
			*/
			UaLeaveReadRWLock(&hash_lock);
			UaLeaveLock(&queue_lock);
			is_pending=true;
			return itr->second;
		}
		UaLeaveReadRWLock(&hash_lock);

		is_pending=false;
		CacheBlock* ret;
		if(block_queue.empty())
		{
			//if there is no free block,first find the oldest block not referenced
			long minlru=MAXLONG;
			int mini=-1;
			for(int i=0;i<DSM_CACHE_SIZE;i++)
			{
				if(block_cache[i].key!=A_BAD_KEY && block_cache[i].lru<minlru)
				{
					minlru=block_cache[i].lru;
					mini=i;
				}
			}

			assert(mini!=-1);
			//acquire the control over the block and swap it out
			UaEnterWriteRWLock(&block_cache[mini].lock);

			long long oldkey=block_cache[mini].key;
			block_cache[mini].key=A_BAD_KEY;

			UaEnterWriteRWLock(&hash_lock);
			cache.erase(block_cache[mini].key);
			cache[k]=&block_cache[mini];
			UaLeaveWriteRWLock(&hash_lock);

			//release the queue lock before time consuming operations
			UaLeaveLock(&queue_lock);

			//we don't release the block's lock here. we should release it when the block is finally ready
			writeback(oldkey,&block_cache[mini]);
			
			ret=&block_cache[mini];
		}
		else
		{
			ret=block_queue.front();
			block_queue.pop();
			UaEnterWriteRWLock(&hash_lock);
			cache[k]=ret;
			UaLeaveWriteRWLock(&hash_lock);
			UaLeaveLock(&queue_lock);
		}
		
		return ret;
	}

	inline void freeblock(CacheBlock* blk)
	{
		UaEnterWriteRWLock(&blk->lock);
		blk->key=A_BAD_KEY;
		UaLeaveWriteRWLock(&blk->lock);

		UaEnterLock(&queue_lock);
		block_queue.push(blk);
		UaLeaveLock(&queue_lock);
	}

public:
	DirectoryDSMCache(SoStorage* back) : backend(back)
	{
		#ifdef BD_DSM_STAT
			writes=0;
			whit=0;
			reads=0;
			rhit=0;
		#endif
		for (int i=0;i<DSM_CACHE_SIZE;i++)
		{
			block_cache[i].key=A_BAD_KEY;
			UaInitRWLock(&block_cache[i].lock);
			block_queue.push(&block_cache[i]);
		}
		UaInitRWLock(&hash_lock);
		UaInitLock(&queue_lock);
	}

	~DirectoryDSMCache()
	{
		for (int i=0;i<DSM_CACHE_SIZE;i++)
		{
			UaKillRWLock(&block_cache[i].lock);
		}
		UaKillLock(&queue_lock);
		UaKillRWLock(&hash_lock);
	}
	
	SoStatus put(_uint key,int fldid,SoVar v)
	{
#ifdef BD_DSM_STAT
		writes++;
#endif
		long long k=MAKE64(key,fldid & FLD_HIGH_MASK);
		UaEnterReadRWLock(&hash_lock);
		hash_iterator itr=cache.find(key);
		bool found=(itr!=cache.end());
		UaLeaveReadRWLock(&hash_lock);
		
		if(found)
		{
			UaEnterReadRWLock(&itr->second->lock);
			if(itr->second->key!=key) //in case that the block is swapped out and reused
			{
				UaLeaveReadRWLock(&itr->second->lock);
				goto MISS;
			}
#ifdef BD_DSM_STAT
			whit++;
#endif
			itr->second->lru=clock();
			itr->second->cache[fldid & FLD_LOW_MASK]=v;
			invalidate(k);
			UaLeaveReadRWLock(&itr->second->lock);
			return SoOK;
		}
MISS:
		bool is_pending;
		CacheBlock* blk=getblock(k,is_pending);
		if(is_pending)
		{
			UaEnterReadRWLock(&blk->lock);
			if(blk->key!=key) //in case that the block is swapped out and reused AGAIN!
			{
				UaLeaveReadRWLock(&blk->lock);
				goto MISS;
			}
			blk->lru=clock();
			blk->cache[fldid & FLD_LOW_MASK]=v;
			invalidate(k);
			UaLeaveReadRWLock(&blk->lock);
			return SoOK;
		}
		else
		{
			writemiss(k,blk);
			blk->lru=clock();
			blk->cache[fldid & FLD_LOW_MASK]=v;
			UaLeaveWriteRWLock(&blk->lock);
			return SoOK;
		}
	}

	SoVar get(_uint key,int fldid)
	{
		SoVar ret;
#ifdef BD_DSM_STAT
		reads++;
#endif
		long long k=MAKE64(key,fldid & FLD_HIGH_MASK);
		UaEnterReadRWLock(&hash_lock);
		hash_iterator itr=cache.find(key);
		bool found=(itr!=cache.end());
		UaLeaveReadRWLock(&hash_lock);
		
		if(found)
		{
			UaEnterReadRWLock(&itr->second->lock);
			if(itr->second->key!=key) //in case that the block is swapped out and reused
			{
				UaLeaveReadRWLock(&itr->second->lock);
				goto MISS;
			}
#ifdef BD_DSM_STAT
			rhit++;
#endif
			itr->second->lru=clock();
			ret= itr->second->cache[fldid & FLD_LOW_MASK];
			UaLeaveReadRWLock(&itr->second->lock);
			return ret;
		}
MISS:
		bool is_pending;
		CacheBlock* blk=getblock(k,is_pending);
		if(is_pending)
		{
			UaEnterReadRWLock(&blk->lock);
			if(blk->key!=key) //in case that the block is swapped out and reused AGAIN!
			{
				UaLeaveReadRWLock(&blk->lock);
				goto MISS;
			}
			blk->lru=clock();
			ret= blk->cache[fldid & FLD_LOW_MASK];
			UaLeaveReadRWLock(&blk->lock);
			return ret;
		}
		else
		{
			readmiss(k,blk);
			blk->lru=clock();
			ret= blk->cache[fldid & FLD_LOW_MASK];
			UaLeaveWriteRWLock(&blk->lock);
			return ret;
		}
	}


};
