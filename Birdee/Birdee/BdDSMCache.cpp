#include "BdDSMCache.h"

#include "hash_compatible.h"
#include <time.h>
#include <assert.h>



using namespace std;







	void DSMDirectoryCache::DSMCacheProtocal::ServerRenew(long long addr,int src_id,SoVar v)
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
					blk->cache[addr & DSM_CACHE_LOW_MASK]=v;
				UaLeaveReadRWLock(&blk->lock);
			}
			//printf("Renew!!! index=%llx,value=%d\n",addr ,v.vi);
		}
	}


	void DSMDirectoryCache::DSMCacheProtocal::ServerWrite(long long addr,int src_id,SoVar* buf)
	{
		bool islocal= (src_id==ths->cache_id);
		long long baddr=addr & DSM_CACHE_HIGH_MASK_64;
		if(!islocal &&  ((addr>>DSM_CACHE_BITS) % caches!=ths->cache_id))
		{
			//RcSend(datasockets[src_id],&status,sizeof(status));
			printf("Cache server bad address!!!%llx\n",addr);
			_BreakPoint;
			return;
		}
		SoVar v=buf[addr & DSM_CACHE_LOW_MASK];
		ths->backend->put(addr>>32,(addr & 0xffffffff),v);
		//printf("WRITE!!!!! [%llx]=%d\n",addr,v.vi); 
		UaEnterReadRWLock(&dir_lock);
		dir_iterator itr=directory.find(baddr);
		long long old=0;
		if(itr!=directory.end())
		{
			old=itr->second;
		}
		if(old)
		{
			DataPack sendpack;
			sendpack.kind=MsgRenew;
			sendpack.addr=addr;
			sendpack.buf[0]=buf[addr & DSM_CACHE_LOW_MASK];
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
		UaLeaveReadRWLock(&dir_lock);
	}

	void DSMDirectoryCache::DSMCacheProtocal::ServerWriteback(long long addr,int src_id)
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
			long long old;
			old=itr->second;
			long long newv = old & ~( ((long long)1)<< src_id);
			if(newv)
				directory[addr]=newv;
			else
				directory.erase(addr);
		}

		UaLeaveWriteRWLock(&dir_lock);
			
	}


	DSMDirectoryCache::DSMCacheProtocal::CacheMessageKind DSMDirectoryCache::DSMCacheProtocal::ServerWriteMiss(long long addr,int src_id,SoVar v,SoVar* outbuf)
	{
		bool islocal= (src_id==ths->cache_id);
		long long baddr=addr & DSM_CACHE_HIGH_MASK_64;
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
		long long old=0;
		if(itr!=directory.end())
		{
			old=itr->second;
		}
		long long newv = old | ( ((long long)1)<< src_id);
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


		UaLeaveWriteRWLock(&dir_lock);

		////////////////////////////////////////////////////

		if(islocal)
		{
			if(ths->backend->getblock(baddr,outbuf)!=SoOK)
				return MsgReplyBadAddress; 
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
			
		return status;
	}

	DSMDirectoryCache::DSMCacheProtocal::CacheMessageKind DSMDirectoryCache::DSMCacheProtocal::ServerReadMiss(long long addr,int src_id,SoVar* outbuf)
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
		long long old=0;
		if(itr!=directory.end())
		{
			old=itr->second;
		}
		long long newv = old | ( ((long long)1)<< src_id);
		directory[addr]=newv;
		UaLeaveWriteRWLock(&dir_lock);
			
		if(islocal)
		{
			if(ths->backend->getblock(addr,outbuf)!=SoOK)
				return MsgReplyBadAddress; 
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
			
		return status;
	}


	void DSMDirectoryCache::DSMCacheProtocal::Writeback(long long addr)
	{
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


	void DSMDirectoryCache::DSMCacheProtocal::Write(long long addr,CacheBlock* blk)
	{
		int target_cache_id=(addr>>DSM_CACHE_BITS) % caches;
		if(target_cache_id==ths->cache_id)
		{
			ServerWrite(addr,ths->cache_id,blk->cache);
		}
		else
		{
			DataPack pack={MsgWrite,addr};
			memcpy(pack.buf,blk->cache,sizeof(pack.buf));
			RcSend(controlsockets[target_cache_id],&pack,sizeof(pack));
		}
	}


	SoStatus DSMDirectoryCache::DSMCacheProtocal::WriteMiss(long long addr,SoVar v,CacheBlock* blk)
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
			RcRecv(datasockets[target_cache_id],&pack,sizeof(pack));
			UaLeaveLock(&datasocketlocks[target_cache_id]);
			if(pack.kind!=MsgReplyOK)
				return SoFail;
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


	SoStatus DSMDirectoryCache::DSMCacheProtocal::ReadMiss(long long addr,CacheBlock* blk)
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
			RcRecv(datasockets[target_cache_id],&pack,sizeof(pack));
			UaLeaveLock(&datasocketlocks[target_cache_id]);
			if(pack.kind!=MsgReplyOK)
				return SoFail;
			if(pack.addr!=addr)
			{
				printf("Read miss return a bad addr\n");
				return SoFail;
			}
			memcpy(blk->cache,pack.buf,sizeof(blk->cache));
		}
		blk->key=addr;
		return SoOK;
	}
//end of class DSMCacheProtocal




	
CacheBlock* DSMDirectoryCache::getblock(long long k,bool& is_pending)
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
		long minlru=MAXLONG;
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

		long long oldkey=block_cache[mini].key;
		block_cache[mini].key=DSM_CACHE_BAD_KEY;

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
	
SoStatus DSMDirectoryCache::put(_uint okey,int fldid,SoVar v)
{
#ifdef BD_DSM_STAT
	writes++;
#endif
	long long k=MAKE64(okey,fldid & DSM_CACHE_HIGH_MASK);
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
		protocal->Write(MAKE64(okey,fldid),foundblock);
		UaLeaveReadRWLock(&foundblock->lock);
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
		protocal->Write(MAKE64(okey,fldid),blk);
		UaLeaveReadRWLock(&blk->lock);
		return SoOK;
	}
	else
	{
		protocal->WriteMiss(MAKE64(okey,fldid),v,blk);
		blk->lru=clock();
		//blk->cache[fldid & DSM_CACHE_LOW_MASK]=v;
		UaLeaveWriteRWLock(&blk->lock);
		return SoOK;
	}
}

SoVar DSMDirectoryCache::get(_uint okey,int fldid)
{
	SoVar ret;
#ifdef BD_DSM_STAT
	reads++;
#endif
	long long k=MAKE64(okey,fldid & DSM_CACHE_HIGH_MASK);
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
		return ret;
	}
	else
	{
		protocal->ReadMiss(k,blk);
		blk->lru=clock();
		ret= blk->cache[fldid & DSM_CACHE_LOW_MASK];
		UaLeaveWriteRWLock(&blk->lock);
		return ret;
	}
}

