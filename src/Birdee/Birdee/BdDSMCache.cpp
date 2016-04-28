#include "BdDSMCache.h"

#include "hash_compatible.h"
#include <time.h>
#include <assert.h>
#include <string.h>


using namespace std;

extern BD_RWLOCK gc_lock;
extern int gc_undergo;

#define ENTER_GC_LOCK() int local_gc_undergo=gc_undergo;\
	if(!local_gc_undergo)\
	{\
		UaEnterReadRWLock(&gc_lock);\
	}

#define LEAVE_GC_LOCK() if(!local_gc_undergo)\
	{\
		UaLeaveReadRWLock(&gc_lock);\
	}


	void DSMDirectoryCache::DSMCacheProtocal::ServerRenew(_uint64 addr,int src_id,SoVar v)
	{


		//	printf("renew : %lld[%lld]=%d\n",addr>>32,addr &0xffffffff,v.vi);

		UaEnterReadRWLock(&ths->hash_lock);
		hash_iterator itr=ths->cache.find(addr & DSM_CACHE_HIGH_MASK_64);
		bool found=(itr!=ths->cache.end());
		CacheBlock* blk=found?itr->second:NULL;
		UaLeaveReadRWLock(&ths->hash_lock);
		if(found)
		{
			if(UaTryEnterReadRWLock(&blk->lock))
			{
				if(blk->key== (addr & DSM_CACHE_HIGH_MASK_64))
					blk->cache[addr & DSM_CACHE_LOW_MASK]=v;
				else
					printf("Discard write changed key : [%lld->%lld]=%d->%d\n",addr &0xffffffff,blk->key,blk->cache[addr & DSM_CACHE_LOW_MASK],v.vi);
				UaLeaveReadRWLock(&blk->lock);
			}
			else
            {
                printf("Discard write : [%lld]=%d->%d\n",addr &0xffffffff,blk->cache[addr & DSM_CACHE_LOW_MASK],v.vi);
            }
			//printf("Renew!!! index=%llx,value=%d\n",addr ,v.vi);
		}
	}

	void DSMDirectoryCache::DSMCacheProtocal::ServerRenewChunk(_uint64 addr,int src_id,SoVar* v)
	{
		UaEnterReadRWLock(&ths->hash_lock);
		hash_iterator itr=ths->cache.find(addr & DSM_CACHE_HIGH_MASK_64);
		bool found=(itr!=ths->cache.end());
		CacheBlock* blk=found?itr->second:NULL;
		UaLeaveReadRWLock(&ths->hash_lock);
		if(found)
		{
			if(UaTryEnterReadRWLock(&blk->lock))
			{
				if(blk->key== (addr & DSM_CACHE_HIGH_MASK_64))
					memcpy(blk->cache,v,sizeof(SoVar)*DSM_CACHE_BLOCK_SIZE);
				else
					printf("Discard write changed key : [%lld->%lld]=%d->\n",addr &0xffffffff,blk->key,blk->cache[addr & DSM_CACHE_LOW_MASK]);
				UaLeaveReadRWLock(&blk->lock);
			}
			else
            {
                printf("Discard write : [%lld]=%d-\n",addr &0xffffffff,blk->cache[addr & DSM_CACHE_LOW_MASK]);
            }
			//printf("Renew!!! index=%llx,value=%d\n",addr ,v.vi);
		}
	}

	void DSMDirectoryCache::DSMCacheProtocal::ServerWriteChunk(_uint64 addr,int src_id,SoVar* v)
	{
		bool islocal= (src_id==ths->cache_id);
		_uint64 baddr=addr & DSM_CACHE_HIGH_MASK_64;
		if(!islocal &&  ((addr>>DSM_CACHE_BITS) % caches!=ths->cache_id))
		{
			//RcSend(datasockets[src_id],&status,sizeof(status));
			printf("Cache server bad address!!!%llx\n",addr);
			_BreakPoint;
			return;
		}
		//for(int i=0;i<DSM_CACHE_BLOCK_SIZE;i++)
		//{
		//	ths->backend->put(addr>>32,(addr & 0xffffffff)+i,v[i]);
		//}
		ths->backend->putchunk(addr>>32,(addr & 0xffffffff),DSM_CACHE_BLOCK_SIZE,v);

		//printf("WRITE!!!!! [%llx]=%d\n",addr,v.vi);
		UaEnterReadRWLock(&dir_lock);
		dir_iterator itr=directory.find(baddr);
		_uint64 old=0;
		if(itr!=directory.end())
		{
			old=itr->second;
		}
		if(old)
		{
			DataPack sendpack;
			sendpack.kind=MsgRenewChunk;
			sendpack.addr=addr;
			memcpy(sendpack.buf,v,sizeof(SoVar)*DSM_CACHE_BLOCK_SIZE);
			for(int i=0;i<caches;i++)
			{
				if((old & 1) && src_id!=i)
				{
					if(i==ths->cache_id)
					{
						ServerRenewChunk(addr,i,v);
					}
					else
					{
						RcSend(controlsockets[i],&sendpack,sizeof(sendpack));
					}
				}
				old=old>>1;
			}
		}
		if(!islocal)
		{
			ServerWriteReply reply={addr};
			RcSend(datasockets[src_id],&reply,sizeof(reply));
		}
		UaLeaveReadRWLock(&dir_lock);
	}

	void DSMDirectoryCache::DSMCacheProtocal::ServerWrite(_uint64 addr,int src_id,SoVar v)
	{
		bool islocal= (src_id==ths->cache_id);
		_uint64 baddr=addr & DSM_CACHE_HIGH_MASK_64;
		if(!islocal &&  ((addr>>DSM_CACHE_BITS) % caches!=ths->cache_id))
		{
			//RcSend(datasockets[src_id],&status,sizeof(status));
			printf("Cache server bad address!!!%llx\n",addr);
			_BreakPoint;
			return;
		}
		ths->backend->put(addr>>32,(addr & 0xffffffff),v);
		//printf("WRITE!!!!! [%llx]=%d\n",addr,v.vi);
		UaEnterReadRWLock(&dir_lock);
		dir_iterator itr=directory.find(baddr);
		_uint64 old=0;
		if(itr!=directory.end())
		{
			old=itr->second;
		}
		if(old)
		{
			DataPack sendpack;
			sendpack.kind=MsgRenew;
			sendpack.addr=addr;
			sendpack.buf[0]=v;
			for(int i=0;i<caches;i++)
			{
				if((old & 1) && src_id!=i)
				{
					if(i==ths->cache_id)
					{
						ServerRenew(addr,i,v);
					}
					else
					{
						RcSend(controlsockets[i],&sendpack,sizeof(sendpack));
					}
				}
				old=old>>1;
			}
		}
		if(!islocal)
		{
			ServerWriteReply reply={addr};
			RcSend(datasockets[src_id],&reply,sizeof(reply));
		}
		UaLeaveReadRWLock(&dir_lock);
	}

	void DSMDirectoryCache::DSMCacheProtocal::ServerWriteback(_uint64 addr,int src_id)
	{
		if(((addr>>DSM_CACHE_BITS) % caches!=ths->cache_id))
		{
			printf("Cache server bad address!!!%llx\n",addr);
			_BreakPoint;
		}
		UaEnterWriteRWLock(&dir_lock);
		dir_iterator itr=directory.find(addr);
		if(itr!=directory.end())
		{
			_uint64 old;
			old=itr->second;
			_uint64 newv = old & ~( ((_uint64)1)<< src_id);
			if(newv)
				directory[addr]=newv;
			else
				directory.erase(addr);
		}

		UaLeaveWriteRWLock(&dir_lock);

	}


	DSMDirectoryCache::DSMCacheProtocal::CacheMessageKind DSMDirectoryCache::DSMCacheProtocal::ServerWriteMiss(_uint64 addr,int src_id,SoVar v,SoVar* outbuf)
	{
		bool islocal= (src_id==ths->cache_id);
		_uint64 baddr=addr & DSM_CACHE_HIGH_MASK_64;
		CacheMessageKind status=MsgReplyOK;
		if(!islocal &&  ((addr>>DSM_CACHE_BITS) % caches!=ths->cache_id))
		{
			printf("Cache server bad address!!!%llx\n",addr);
			_BreakPoint;
		}

		ths->backend->put( addr>>32,(addr&0xffffffff),v);
		//printf("WRITE Miss!!!!! [%llx]=%d\n",addr,v.vi);

		UaEnterWriteRWLock(&dir_lock);
		dir_iterator itr=directory.find(baddr);
		_uint64 old=0;
		if(itr!=directory.end())
		{
			old=itr->second;
		}
		_uint64 newv = old | ( ((_uint64)1)<< src_id);
		directory[baddr]=newv;

		if(old)
		{
			DataPack sendpack;
			sendpack.kind=MsgRenew;
			sendpack.addr=addr;
			sendpack.buf[0]=v;
			for(int i=0;i<caches;i++)
			{
				if((old & 1) && src_id!=i)
				{
					if(i==ths->cache_id)
					{
						ServerRenew(addr,i,v);
					}
					else
					{
						RcSend(controlsockets[i],&sendpack,sizeof(sendpack));
					}
				}
				old=old>>1;
			}
		}

		////////////////////////////////////////////////////

		if(islocal)
		{
			if(ths->backend->getblock(baddr,outbuf)!=SoOK)
			{
				UaLeaveWriteRWLock(&dir_lock);
				return MsgReplyBadAddress;
			}
		}
		else
		{
			DataPack sendpack;
			sendpack.kind=MsgReplyOK;
			sendpack.addr=addr;
			if(ths->backend->getblock(baddr,sendpack.buf)!=SoOK)
			{
				sendpack.kind=MsgReplyBadAddress;
			}
			RcSend(datasockets[src_id],&sendpack,sizeof(sendpack));
		}
		UaLeaveWriteRWLock(&dir_lock);
		return status;
	}

	DSMDirectoryCache::DSMCacheProtocal::CacheMessageKind DSMDirectoryCache::DSMCacheProtocal::ServerReadMiss(_uint64 addr,int src_id,SoVar* outbuf)
	{
		bool islocal= (src_id==ths->cache_id);
		CacheMessageKind status=MsgReplyOK;
		if(!islocal &&  ((addr>>DSM_CACHE_BITS) % caches!=ths->cache_id))
		{
			printf("Cache server bad address!!!%llx\n",addr);
			_BreakPoint;
		}
		UaEnterWriteRWLock(&dir_lock);
		dir_iterator itr=directory.find(addr);
		_uint64 old=0;
		if(itr!=directory.end())
		{
			old=itr->second;
		}
		_uint64 newv = old | ( ((_uint64)1)<< src_id);
		directory[addr]=newv;

		if(islocal)
		{
			if(ths->backend->getblock(addr,outbuf)!=SoOK)
			{
				UaLeaveWriteRWLock(&dir_lock);
				return MsgReplyBadAddress;
			}
		}
		else
		{
			DataPack sendpack;
			sendpack.kind=MsgReplyOK;
			sendpack.addr=addr;
			if(ths->backend->getblock(addr,sendpack.buf)!=SoOK)
			{
				sendpack.kind=MsgReplyBadAddress;
			}
			RcSend(datasockets[src_id],&sendpack,sizeof(sendpack));
		}
		UaLeaveWriteRWLock(&dir_lock);

		return status;
	}


	void DSMDirectoryCache::DSMCacheProtocal::Writeback(_uint64 addr)
	{
		//printf("WriteBack %lld\n",addr);
		int target_cache_id=(addr>>DSM_CACHE_BITS) % caches;
		if(target_cache_id==ths->cache_id)
		{
			ServerWriteback(addr,ths->cache_id);
		}
		else
		{
			DataPack pack={MsgWriteback,addr};
			RcSend(controlsockets[target_cache_id],&pack,sizeof(pack));
		}
	}


	void DSMDirectoryCache::DSMCacheProtocal::WriteChunk(_uint64 addr,SoVar* v)
	{
		int target_cache_id=(addr>>DSM_CACHE_BITS) % caches;
		if(target_cache_id==ths->cache_id)
		{
			ServerWriteChunk(addr,ths->cache_id,v);
		}
		else
		{
			UaEnterLock(&datasocketlocks[target_cache_id]);
			DataPack pack={MsgWriteChunk,addr};
			memcpy(pack.buf,v,sizeof(SoVar)*DSM_CACHE_BLOCK_SIZE);
			RcSend(controlsockets[target_cache_id],&pack,sizeof(pack));
			ServerWriteReply reply;
			if(RcRecv(datasockets[target_cache_id],&reply,sizeof(reply))!=sizeof(reply))
            {
				UaLeaveLock(&datasocketlocks[target_cache_id]);
                printf("Write chunk receive error %d\n",RcSocketLastError());
                return;
            }
			if(reply.addr!=addr)
            {
                printf("Write return a bad address\n");
				_BreakPoint;
                return;
            }
			UaLeaveLock(&datasocketlocks[target_cache_id]);
		}
	}

	void DSMDirectoryCache::DSMCacheProtocal::Write(_uint64 addr,SoVar v)
	{
		int target_cache_id=(addr>>DSM_CACHE_BITS) % caches;
		if(target_cache_id==ths->cache_id)
		{
			ServerWrite(addr,ths->cache_id,v);
		}
		else
		{
			UaEnterLock(&datasocketlocks[target_cache_id]);
			DataPack pack={MsgWrite,addr};
			pack.buf[0]=v;
			RcSend(controlsockets[target_cache_id],&pack,sizeof(pack));
			ServerWriteReply reply;
			if(RcRecv(datasockets[target_cache_id],&reply,sizeof(reply))!=sizeof(reply))
            {
				UaLeaveLock(&datasocketlocks[target_cache_id]);
                printf("Write receive error %d\n",RcSocketLastError());
                return;
            }
			if(reply.addr!=addr)
            {
                printf("Write return a bad address\n");
				_BreakPoint;
                return;
            }
			UaLeaveLock(&datasocketlocks[target_cache_id]);
		}
	}


	SoStatus DSMDirectoryCache::DSMCacheProtocal::WriteMiss(_uint64 addr,SoVar v,CacheBlock* blk)
	{
		int target_cache_id=(addr>>DSM_CACHE_BITS) % caches;
		if(target_cache_id==ths->cache_id)
		{
			if(ServerWriteMiss(addr,ths->cache_id,v,blk->cache)!=MsgReplyOK)
				return SoFail;
		}
		else
		{
			DataPack pack={MsgWriteMiss,addr};
			pack.buf[0]=v;
			UaEnterLock(&datasocketlocks[target_cache_id]);
			RcSend(controlsockets[target_cache_id],&pack,sizeof(pack));
			if(RcRecv(datasockets[target_cache_id],&pack,sizeof(pack))!=sizeof(pack))
            {
				UaLeaveLock(&datasocketlocks[target_cache_id]);
                printf("Write miss receive error %d\n",RcSocketLastError());
                return SoFail;
            }
			UaLeaveLock(&datasocketlocks[target_cache_id]);
			if(pack.kind!=MsgReplyOK)
			{
				return SoFail;
			}
			if(pack.addr!=addr)
			{
				printf("Write miss return a bad addr\n");
				return SoFail;
			}
			memcpy(blk->cache,pack.buf,sizeof(blk->cache));
		}
		blk->key=addr & DSM_CACHE_HIGH_MASK_64;
		return SoOK;
	}


	SoStatus DSMDirectoryCache::DSMCacheProtocal::ReadMiss(_uint64 addr,CacheBlock* blk)
	{
		int target_cache_id=(addr>>DSM_CACHE_BITS) % caches;
		if(target_cache_id==ths->cache_id)
		{
			if(ServerReadMiss(addr,ths->cache_id,blk->cache)!=MsgReplyOK)
				return SoFail;
		}
		else
		{
			DataPack pack={MsgReadMiss,addr};
			UaEnterLock(&datasocketlocks[target_cache_id]);
			RcSend(controlsockets[target_cache_id],&pack,sizeof(pack));
			if(RcRecv(datasockets[target_cache_id],&pack,sizeof(pack))!=sizeof(pack))
            {
                printf("Read miss receive error %d\n",RcSocketLastError());
                return SoFail;
            }
			UaLeaveLock(&datasocketlocks[target_cache_id]);
			if(pack.kind!=MsgReplyOK)
				return SoFail;
			if(pack.addr!=addr)
			{
				printf("Read miss return a bad addr\n");
				_BreakPoint;
				return SoFail;
			}
			memcpy(blk->cache,pack.buf,sizeof(blk->cache));
		}
		blk->key=addr;
		return SoOK;
	}
//end of class DSMCacheProtocal





CacheBlock* DSMDirectoryCache::getblock(_uint64 k,bool& is_pending)
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
		CacheBlock* blk=itr->second;
		UaLeaveReadRWLock(&hash_lock);
		UaLeaveLock(&queue_lock);
		is_pending=true;
		return blk;
	}
	UaLeaveReadRWLock(&hash_lock);

	is_pending=false;
	CacheBlock* ret;
	if(block_queue.empty())
	{
		//if there is no free block,first find the oldest block not referenced
		unsigned long minlru=0xffffffff;
		int mini=-1;
		for(int i=0;i<DSM_CACHE_SIZE;i++)
		{
			if(block_cache[i].key!=DSM_CACHE_BAD_KEY && block_cache[i].lru<minlru)
			{
				minlru=block_cache[i].lru;
				mini=i;
			}
		}
		assert(mini!=-1);
		//acquire the control over the block and swap it out
		UaEnterWriteRWLock(&block_cache[mini].lock);

		_uint64 oldkey=block_cache[mini].key;
		block_cache[mini].key=DSM_CACHE_BAD_KEY;
		block_cache[mini].lru=0xffffffff;
		UaEnterWriteRWLock(&hash_lock);
		cache.erase(oldkey);
		cache[k]=&block_cache[mini];
		UaLeaveWriteRWLock(&hash_lock);

		//release the queue lock before time consuming operations
		UaLeaveLock(&queue_lock);

		//we don't release the block's lock here. we should release it when the block is finally ready
		protocal->Writeback(oldkey);

		ret=&block_cache[mini];
	}
	else
	{
		ret=block_queue.front();
		block_queue.pop();
		UaEnterWriteRWLock(&hash_lock);
		cache[k]=ret;
		UaLeaveWriteRWLock(&hash_lock);
		UaEnterWriteRWLock(&ret->lock);
		UaLeaveLock(&queue_lock);
	}

	return ret;
}

SoStatus DSMDirectoryCache::peek(_uint key,_uint fldid,SoVar* out)
{
	_uint64 k=MAKE64(key,fldid);
	ENTER_GC_LOCK();
	UaEnterReadRWLock(&hash_lock);
	hash_iterator itr=cache.find(k);
	bool found=(itr!=cache.end());
	CacheBlock* foundblock=found?itr->second:NULL;
	UaLeaveReadRWLock(&hash_lock);

	if(found)
	{
		UaEnterReadRWLock(&foundblock->lock);
		if(foundblock->key!=k) //in case that the block is swapped out and reused
		{
			UaLeaveReadRWLock(&foundblock->lock);
			LEAVE_GC_LOCK();
			goto MISS;
		}
		memcpy(out,foundblock->cache,sizeof(foundblock->cache));
		UaLeaveReadRWLock(&foundblock->lock);
		LEAVE_GC_LOCK();
		return SoOK;
	}
	MISS:
	return backend->getblock(k,out);
}

SoStatus DSMDirectoryCache::put(_uint okey,_uint fldid,SoVar v)
{
#ifdef BD_DSM_STAT
	writes++;
#endif
	_uint64 k=MAKE64(okey,fldid & DSM_CACHE_HIGH_MASK);
	ENTER_GC_LOCK();
	UaEnterReadRWLock(&hash_lock);
	hash_iterator itr=cache.find(k);
	bool found=(itr!=cache.end());
	CacheBlock* foundblock=found?itr->second:NULL;
	UaLeaveReadRWLock(&hash_lock);

	if(found)
	{
		UaEnterReadRWLock(&foundblock->lock);
		if(foundblock->key!=k) //in case that the block is swapped out and reused
		{
			UaLeaveReadRWLock(&foundblock->lock);
			goto MISS;
		}
#ifdef BD_DSM_STAT
		whit++;
#endif
		foundblock->lru=clock();
		foundblock->cache[fldid & DSM_CACHE_LOW_MASK]=v;
		protocal->Write(MAKE64(okey,fldid),v);
		UaLeaveReadRWLock(&foundblock->lock);
		LEAVE_GC_LOCK();
		return SoOK;
	}
MISS:
	bool is_pending;
	CacheBlock* blk=getblock(k,is_pending);
	if(is_pending)
	{
		UaEnterReadRWLock(&blk->lock);
		if(blk->key!=k) //in case that the block is swapped out and reused AGAIN!
		{
			UaLeaveReadRWLock(&blk->lock);
			goto MISS;
		}
		blk->lru=clock();
		blk->cache[fldid & DSM_CACHE_LOW_MASK]=v;
		protocal->Write(MAKE64(okey,fldid),v);
		UaLeaveReadRWLock(&blk->lock);
		LEAVE_GC_LOCK();
		return SoOK;
	}
	else
	{
		protocal->WriteMiss(MAKE64(okey,fldid),v,blk);
		blk->lru=clock();
		if(blk->key!=k)
		{
			printf("Write Miss key error");
			_BreakPoint;
		}
		//blk->cache[fldid & DSM_CACHE_LOW_MASK]=v;
		UaLeaveWriteRWLock(&blk->lock);
		LEAVE_GC_LOCK();
		return SoOK;
	}
}

SoVar DSMDirectoryCache::get(_uint okey,_uint fldid)
{
	SoVar ret;
#ifdef BD_DSM_STAT
	reads++;
#endif
	_uint64 k=MAKE64(okey,fldid & DSM_CACHE_HIGH_MASK);
	ENTER_GC_LOCK();
	UaEnterReadRWLock(&hash_lock);
	hash_iterator itr=cache.find(k);
	bool found=(itr!=cache.end());
	CacheBlock* foundblock=found?itr->second:NULL;
	UaLeaveReadRWLock(&hash_lock);

	if(found)
	{
		UaEnterReadRWLock(&foundblock->lock);
		if(foundblock->key!=k) //in case that the block is swapped out and reused
		{
			UaLeaveReadRWLock(&foundblock->lock);
			goto MISS;
		}
#ifdef BD_DSM_STAT
		rhit++;
#endif
		foundblock->lru=clock();
		ret= foundblock->cache[fldid & DSM_CACHE_LOW_MASK];
		UaLeaveReadRWLock(&foundblock->lock);
		LEAVE_GC_LOCK();
		return ret;
	}
MISS:
	bool is_pending;
	CacheBlock* blk=getblock(k,is_pending);
	if(is_pending)
	{
		UaEnterReadRWLock(&blk->lock);
		if(blk->key!=k) //in case that the block is swapped out and reused AGAIN!
		{
			UaLeaveReadRWLock(&blk->lock);
			goto MISS;
		}
		blk->lru=clock();
		ret= blk->cache[fldid & DSM_CACHE_LOW_MASK];
		UaLeaveReadRWLock(&blk->lock);
		LEAVE_GC_LOCK();
		return ret;
	}
	else
	{
		protocal->ReadMiss(k,blk);
		blk->lru=clock();
		if(blk->key!=k)
		{
			printf("Write Miss key error");
			_BreakPoint;
		}
		ret= blk->cache[fldid & DSM_CACHE_LOW_MASK];
		UaLeaveWriteRWLock(&blk->lock);
		LEAVE_GC_LOCK();
		return ret;
	}
}

CacheBlock* DSMDirectoryCache::find_block(_uint64 k)
{
	UaEnterReadRWLock(&hash_lock);
	hash_iterator itr=cache.find(k);
	bool found=(itr!=cache.end());
	CacheBlock* foundblock=found?itr->second:NULL;
	UaLeaveReadRWLock(&hash_lock);

	if(found)
	{
		UaEnterReadRWLock(&foundblock->lock);
		if(foundblock->key!=k) //in case that the block is swapped out and reused
		{
			UaLeaveReadRWLock(&foundblock->lock);
			return NULL;
		}
		foundblock->lru=clock();

		return foundblock;
	}
	return NULL;
}

SoStatus DSMDirectoryCache::put_chunk(_uint okey,_uint fldid,_uint len,double* v)
{
	_uint64 k=MAKE64(okey,fldid);
	_uint64 k_start,k_end,k_tail;

	k_tail=k+len;
	if(k & DSM_CACHE_LOW_MASK_64)
		k_start= (k & DSM_CACHE_HIGH_MASK_64) + DSM_CACHE_BLOCK_SIZE;
	else
		k_start=k;

	k_end= k_tail & DSM_CACHE_HIGH_MASK_64;
	SoStatus ret;
	CacheBlock* foundblock=NULL;
	ENTER_GC_LOCK();
	SoVar var[DSM_CACHE_BLOCK_SIZE];
	SoVar* buf;
	_uint idx=0,j;
	_uint64 i;

	for(i=k;i<k_start && i<k_tail;i++)
	{
		//printf("PUT %llx=%d\n",i,v[idx]);
		var[0].vd=v[idx];
		if(put(okey,i & 0xFFFFFFFF,var[0])!=SoOK)
			ret=SoFail;
		idx++;
	}

	for(i=k_start;i<k_end;i+=DSM_CACHE_BLOCK_SIZE)
	{
		foundblock=find_block(i);
		if(foundblock)
			buf=foundblock->cache;
		else
			buf=var;
		for(j=0;j<DSM_CACHE_BLOCK_SIZE;j++)
		{
			buf[j].vd=v[idx];
			idx++;
		}
		protocal->WriteChunk(i,buf);
		if(foundblock)
			UaLeaveReadRWLock(&foundblock->lock);

	}
	if(idx<len)
	{
		for(i=k_end;i<k_tail;i++)
		{
			//printf("PUT %llx=%d\n",i,v[idx]);
			var[0].vd=v[idx];
			if(put(okey,i & 0xFFFFFFFF,var[0])!=SoOK)
				ret=SoFail;
			idx++;
		}
	}
	LEAVE_GC_LOCK();
	return ret;
}


SoStatus DSMDirectoryCache::put_chunk(_uint okey,_uint fldid,_uint len,BINT* v)
{
	_uint64 k=MAKE64(okey,fldid);
	_uint64 k_start,k_end,k_tail;

	k_tail=k+len;
	if(k & DSM_CACHE_LOW_MASK_64)
		k_start= (k & DSM_CACHE_HIGH_MASK_64) + DSM_CACHE_BLOCK_SIZE;
	else
		k_start=k;

	k_end= k_tail & DSM_CACHE_HIGH_MASK_64;
	SoStatus ret;
	CacheBlock* foundblock=NULL;
	ENTER_GC_LOCK();
	SoVar var[DSM_CACHE_BLOCK_SIZE];
	SoVar* buf;
	_uint idx=0,j;
	_uint64 i;

	for(i=k;i<k_start && i<k_tail;i++)
	{
		//printf("PUT %llx=%d\n",i,v[idx]);
		var[0].vi=v[idx];
		if(put(okey,i & 0xFFFFFFFF,var[0])!=SoOK)
			ret=SoFail;
		idx++;
	}

	for(i=k_start;i<k_end;i+=DSM_CACHE_BLOCK_SIZE)
	{
		foundblock=find_block(i);
		if(foundblock)
			buf=foundblock->cache;
		else
			buf=var;
		for(j=0;j<DSM_CACHE_BLOCK_SIZE;j++)
		{
			buf[j].vi=v[idx];
			idx++;
		}
		protocal->WriteChunk(i,buf);
		if(foundblock)
			UaLeaveReadRWLock(&foundblock->lock);

	}
	if(idx<len)
	{
		for(i=k_end;i<k_tail;i++)
		{
			//printf("PUT %llx=%d\n",i,v[idx]);
			var[0].vi=v[idx];
			if(put(okey,i & 0xFFFFFFFF,var[0])!=SoOK)
				ret=SoFail;
			idx++;
		}
	}
	LEAVE_GC_LOCK();
	return ret;
}
