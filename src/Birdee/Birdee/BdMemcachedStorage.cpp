#include "BdSharedObj.h"
#include "BdMemcachedStorage.h"
#include <libmemcached/memcached.h>
#include <stdlib.h>

#ifdef BD_ON_WINDOWS
	#define atoll _atoi64
#endif
#ifdef BD_ON_LINUX
    #define memcached_free2 free
#endif


memcached_st * sto=NULL;
#pragma pack(4)
struct NodeValue
{
	SoType tag;
	int flag;
	union
	{
		SoVar var;
		struct
		{
			size_t len;
			wchar_t str[0];
		}string;

		size_t field_cnt;


		struct
		{
			SoType ty;
			size_t arr_cnt;
			SoVar arr[0];
		}barray;
	};
};

void set_memcached_this_thread(void* p)
{
		_memc=p;
}
void* init_memcached_this_thread()
{
        //_memc=(memcached_st*)memcached_create(NULL);
        if(sto)
            _memc=memcached_clone(memc,sto);
		else
			return NULL;
		return _memc;
}

void free_memcached(void* p)
{
	memcached_free((memcached_st*)p);
}
memcached_return memcached_put(memcached_st* memca,_uint64 k,void* v,size_t len)
{
	//char ch[17];
	//sprintf(ch,"%016llx",k);
	memcached_return rc = memcached_set(memca, (char*)&k, 8, (char*)v,len,(time_t)0, (uint32_t)0);
	return rc;
}


SoStorageMemcached::~SoStorageMemcached()
{
		//memcached_free(memc); //fix-me : unknown error at here
}


int SoStorageMemcached::getsize(_uint key)
{
	//char ch[17];
	//sprintf(ch,"%016llx",MAKE64(key,0));
	_uint64 k=MAKE64(key,0xFFFFFFFE);
	size_t return_key_length=8;
	size_t return_value_length;
	uint32_t flags;
	memcached_return rc;
	char* return_value = memcached_get(memc, (char*)&k,return_key_length, &return_value_length, &flags, &rc);
	if(rc!=MEMCACHED_SUCCESS)
		throw 1;
	NodeValue* node=(NodeValue*) return_value;
	return node->field_cnt;
}

int SoStorageMemcached::getcounter(_uint key,_uint fldid)
{
	//char ch[17];
	//sprintf(ch,"%016llx",MAKE64(key,fldid));
	_uint64 k=MAKE64(key,fldid);
	size_t return_key_length=8;
	size_t return_value_length;
	uint32_t flags;
	memcached_return rc;
	char* return_value = memcached_get(memc, (char*)&k,return_key_length, &return_value_length, &flags, &rc);
	if(rc!=MEMCACHED_SUCCESS)
		throw 1;
	_uint64 ret=atoll(return_value);
	return ret-offset;
}
void SoStorageMemcached::setcounter(_uint key,_uint fldid,int n)
{
	//char ch[17];
	//sprintf(ch,"%016llx",MAKE64(key,fldid));
	_uint64 k=MAKE64(key,fldid);
	size_t return_key_length=8;
	size_t return_value_length;
	uint32_t flags;
	memcached_return rc;

	char ch2[65];
	sprintf(ch2,"%lld",(_uint64)n+offset);
	rc = memcached_set(memc, (char*)&k,return_key_length,ch2,strlen(ch2),0, 0);
	if(rc!=MEMCACHED_SUCCESS)
		throw 1;
}

int SoStorageMemcached::inc(_uint key,_uint fldid,int inc)
{
	//char ch[17];
	//sprintf(ch,"%016llx",MAKE64(key,fldid));
	_uint64 k=MAKE64(key,fldid);
	uint64_t ret;
	memcached_return rc;
	if(inc>0)
		rc=memcached_increment(memc,(char*)&k,8,inc,&ret);
	else
		rc=memcached_decrement(memc,(char*)&k,8,-inc,&ret);
	if(rc!=MEMCACHED_SUCCESS)
		throw 1;
	return ret-offset;

}

int SoStorageMemcached::dec(_uint key,_uint fldid,int dec)
{
	return inc(key,fldid,-dec);
}
SoStatus SoStorageMemcached::putstr(_uint key,wchar_t* str,_uint len)
{
	size_t sz=sizeof(NodeValue)+(len+1)*sizeof(wchar_t);
	NodeValue* nd=(NodeValue*)malloc(sz);

	nd->string.len=len;
	wcsncpy(nd->string.str,str,len+1);

	SoType ty=SoString;
	if(memcached_put(memc,MAKE64(key,0),&ty,sizeof(SoType))==MEMCACHED_SUCCESS)
	{
		if(memcached_put(memc,MAKE64(key,1),nd,sz)==MEMCACHED_SUCCESS)
		{
			free(nd);
			return SoOK;
		}
	}
	free(nd);
	return SoFail;
}

SoStatus SoStorageMemcached::getstr(_uint key,wchar_t** str,_uint* len)
{
	_uint64 k1,k2;
	k1=MAKE64(key,0);
	k2=MAKE64(key,1);
	//sprintf(ch1,"%016llx",k1);
	//sprintf(ch2,"%016llx",k2);
	char *keys[]= {(char*)&k1,(char*)&k2};
	size_t key_length[]= {8,8};
	memcached_return rc;

	size_t return_key_length=8;
	size_t return_value_length;
	uint32_t flags;
	char* return_value = memcached_get(memc, (char*)&k1,return_key_length, &return_value_length, &flags, &rc);
	NodeValue* node;
	if(rc==MEMCACHED_SUCCESS)
	{
		SoType ty=*(SoType*) return_value;
		memcached_free2(return_value);
		if(ty!=SoString)
			return SoFail;

		return_value = memcached_get(memc, (char*)&k2,return_key_length, &return_value_length, &flags, &rc);
		if(rc==MEMCACHED_SUCCESS)
		{
			node=(NodeValue*) return_value;
			if(node->string.len)
			{
				*str=wcsdup(node->string.str);
			}
			else
			{
				*str=NULL;
			}
			memcached_free2(return_value);
			*len=node->string.len;
			return SoOK;
		}
		else
			return SoKeyNotFound;
	}
	else
		return SoKeyNotFound;
}

SoStatus SoStorageMemcached::put(_uint key,_uint fldid,SoVar v)
{
	memcached_return rc=memcached_put(memc,MAKE64(key,fldid),&v,sizeof(v));
	if(rc==MEMCACHED_SUCCESS)
		return SoOK;
	return SoFail;
}

SoVar SoStorageMemcached::get(_uint key,_uint fldid)
{
	SoVar ret;
	_uint64 k=MAKE64(key,fldid);
	char* mret;

	size_t len;
#ifdef BD_ON_X64
	uint32_t flg;
#else
	size_t flg;
#endif
	memcached_return rc;
//	char ch[17];
//	sprintf(ch,"%016llx",k);
    mret=memcached_get(memc,(char*)&k,8,&len,&flg,&rc);
    if (rc == MEMCACHED_SUCCESS) {
        ret=*(SoVar*)mret;
        memcached_free2(mret);
        return ret;
    }
    else
    {
        //printf("Memc Error:%d",memc->cached_errno);
        throw SO_KEY_NOT_FOUND;
    }


	return ret;

}

bool SoStorageMemcached::exists(_uint key)//fix-me : improve
{
	size_t outlen;
#ifdef BD_ON_X64
	uint32_t flg;
#else
	size_t flg;
#endif
	memcached_return rc;
	//char ch[17];
	//sprintf(ch,"%016llx",MAKE64(key,0));
	_uint64 k=MAKE64(key,0xFFFFFFFE);
	char* r= memcached_get(memc,(char*)&k,8,&outlen,&flg,&rc);
	if(rc==MEMCACHED_SUCCESS)
	{
		memcached_free2(r);
		return true;
	}
	return false;
}

SoStatus SoStorageMemcached::getinfo(_uint key,SoType& tag,int& fld_cnt,int& flag)
{
	NodeValue* pnd;
	_uint64 k=MAKE64(key,0xFFFFFFFE);
	char* mret;
	size_t len;
#ifdef BD_ON_X64
	uint32_t flg;
#else
	size_t flg;
#endif
	memcached_return rc;
//	char ch[17];
//	sprintf(ch,"%016llx",k);
    mret=memcached_get(memc,(char*)&k,8,&len,&flg,&rc);
    if (rc == MEMCACHED_SUCCESS) {
        pnd=(NodeValue*)mret;
		tag=pnd->tag;
		fld_cnt=pnd->field_cnt;
		flag=pnd->flag;
        memcached_free2(mret);
        return SoOK;
    }
    else
    {
        //printf("Error:%d",memc->cached_errno);
		return SoFail;
    }
}

SoStatus SoStorageMemcached::newobj(_uint key,SoType tag,int fld_cnt,int flag)
{
	NodeValue nd;
	nd.tag=tag;
	nd.field_cnt=fld_cnt;
	nd.flag=flag;
	//char ch[17];
	//sprintf(ch,"%016llx",MAKE64(key,0));
	_uint64 k=MAKE64(key,0xFFFFFFFE);
	SoVar v;
	v.vi=0;
	if(memcached_add(memc,(char*)&k,8,(char*)&nd,sizeof(nd),(time_t)0,0)==MEMCACHED_SUCCESS)
	{
		if(memcached_put(memc,MAKE64(key,0xFFFFFFFF),&v,sizeof(v))!=MEMCACHED_SUCCESS)
			_BreakPoint;
		return SoOK;
	}
	return SoFail;
}

static SoStatus fetchchunk(_uint64 k,_uint len)
{
	typedef char* _PCHAR;
	char** keys=new _PCHAR[len];
	size_t* key_length=new size_t[len];
	_uint64* maddr=new _uint64[len];

	for (_uint i=0;i<len;i++)
	{
		maddr[i]= k+i;
		keys[i]=(char*) &maddr[i];
		key_length[i]=8;
	}

    memcached_return rc = memcached_mget(memc, (char**)keys, key_length, len);
	delete []keys;
	delete []key_length;
	delete []maddr;
	return (rc==MEMCACHED_SUCCESS)?SoOK:SoFail;
}
SoStatus SoStorageMemcached::getchunk(_uint key,_uint fldid,_uint len,BINT* buf)
{
	_uint64 k=MAKE64(key,fldid);
	_uint offset;
	SoStatus ret;
	for(offset=0;offset<len;offset+=15040)
	{
		memcached_result_st results_obj;
		memcached_result_st* results;
		results= memcached_result_create(memc, &results_obj);
		_uint mylen=offset+15040<len?15040:len-offset;
		memset(buf+offset,0,sizeof(double)*mylen);

		memcached_return rc;
		ret=fetchchunk(k+offset,mylen);
		while ((results= memcached_fetch_result(memc, &results_obj, &rc)))
		{
			if(rc == MEMCACHED_SUCCESS)
			{
				_uint64* pkey;
				SoVar* pvalue;
				pkey=(_uint64*)memcached_result_key_value(results);
				pvalue=(SoVar*)memcached_result_value(results);
				//printf("read [%llx]=%d\n",*pkey,pvalue->vi);
				buf[ (*pkey) - k ]= pvalue->vi;
			}
		}
		memcached_result_free(&results_obj);
	}
	return ret;
}

SoStatus SoStorageMemcached::getchunk(_uint key,_uint fldid,_uint len,double* buf)
{
	_uint64 k=MAKE64(key,fldid);
	_uint offset;
	SoStatus ret;
	for(offset=0;offset<len;offset+=15040)
	{
		memcached_result_st results_obj;
		memcached_result_st* results;
		results= memcached_result_create(memc, &results_obj);
		_uint mylen=offset+15040<len?15040:len-offset;
		memset(buf+offset,0,sizeof(double)*mylen);

		memcached_return rc;
		ret=fetchchunk(k+offset,mylen);
		while ((results= memcached_fetch_result(memc, &results_obj, &rc)))
		{
			if(rc == MEMCACHED_SUCCESS)
			{
				_uint64* pkey;
				SoVar* pvalue;
				pkey=(_uint64*)memcached_result_key_value(results);
				pvalue=(SoVar*)memcached_result_value(results);
				//printf("read [%llx]=%d\n",*pkey,pvalue->vi);
				buf[ (*pkey) - k ]= pvalue->vd;
			}
		}
		memcached_result_free(&results_obj);
	}
	return ret;
}

SoStatus SoStorageMemcached::putchunk(_uint key,_uint fldid,_uint len,SoVar* buf)
{
	_uint k=fldid;
	SoStatus ret=SoOK;
	for(_uint i=0;i<len;i++,k++)
	{
		if(put(key,k,buf[i])!=SoOK)
			ret=SoFail;
	}
	return ret;
}

SoStatus SoStorageMemcached::getblock(_uint64 addr,SoVar* buf)
{
	char* keys[DSM_CACHE_BLOCK_SIZE];
	size_t key_length[DSM_CACHE_BLOCK_SIZE];
	_uint64 maddr[DSM_CACHE_BLOCK_SIZE];
	for (int i=0;i<DSM_CACHE_BLOCK_SIZE;i++)
	{
		maddr[i]= (addr & DSM_CACHE_HIGH_MASK_64)+i;
		keys[i]=(char*) &maddr[i];
		key_length[i]=8;
	}
	memcached_result_st results_obj;
	memcached_result_st* results;
	results= memcached_result_create(memc, &results_obj);

	memset(buf,0,sizeof(SoVar)*DSM_CACHE_BLOCK_SIZE);
    memcached_return rc = memcached_mget(memc, (char**)keys, key_length, DSM_CACHE_BLOCK_SIZE);

	SoStatus ret= (rc==MEMCACHED_SUCCESS)?SoOK:SoFail;
	while ((results= memcached_fetch_result(memc, &results_obj, &rc)))
	{

		if(rc == MEMCACHED_SUCCESS)
		{
			_uint64* pkey;
			SoVar* pvalue;
			pkey=(_uint64*)memcached_result_key_value(results);
			pvalue=(SoVar*)memcached_result_value(results);
			//printf("read [%llx]=%d\n",*pkey,pvalue->vi);
			buf[ (*pkey) & DSM_CACHE_LOW_MASK_64]= *pvalue;
		}
	}
	memcached_result_free(&results_obj);
	return ret;
}


SoStatus SoStorageMemcached::del(_uint key,unsigned int len)
{
	_uint64 k;
	for(_uint i=0;i<len;i++)
	{
		k=MAKE64(key,i);
		memcached_delete(memc,(char*)&k,8,0);
	}
	k=(MAKE64(key,0xFFFFFFFE));
	memcached_delete(memc,(char*)&k,8,0);
	k=(MAKE64(key,0xFFFFFFFF));
	memcached_delete(memc,(char*)&k,8,0);
	return SoOK;
}

/////////////////////////////////////////////////////////////////
//SoStorageChunkMemcached
/////////////////////////////////////////////////////////////////
SoStatus SoStorageChunkMemcached::put(_uint key,_uint fldid,SoVar v)
{
	return putchunk(key,fldid,1,&v);
}

SoVar SoStorageChunkMemcached::get(_uint key,_uint fldid)
{
	_uint64 k=MAKE64(key,fldid);
	SoVar buf[DSM_CACHE_BLOCK_SIZE];
	getblock(k,buf);

	return buf[k & DSM_CACHE_LOW_MASK_64];

}



static SoStatus fetchchunk2(_uint64 k,_uint len)
{
	_uint true_len=len/DSM_CACHE_BLOCK_SIZE + ((len%DSM_CACHE_BLOCK_SIZE)?1:0);
	typedef char* _PCHAR;
	char** keys=new _PCHAR[true_len];
	size_t* key_length=new size_t[true_len];
	_uint64* maddr=new _uint64[true_len];

	for (_uint i=0;i<true_len;i++)
	{
		maddr[i]= k+i;
		keys[i]=(char*) &maddr[i];
		key_length[i]=8;
	}

    memcached_return rc = memcached_mget(memc, (char**)keys, key_length, true_len);
	delete []keys;
	delete []key_length;
	delete []maddr;
	return (rc==MEMCACHED_SUCCESS)?SoOK:SoFail;
}




SoStatus SoStorageChunkMemcached::putchunk(_uint key,_uint fldid,_uint len,SoVar* buf)
{
	_uint k=fldid;
	_uint k_start,k_end,k_tail;

	k_tail=k+len;
	if(k & DSM_CACHE_LOW_MASK)
		k_start= (k & DSM_CACHE_HIGH_MASK) + DSM_CACHE_BLOCK_SIZE;
	else
		k_start=k;

	k_end= k_tail & DSM_CACHE_HIGH_MASK;
	SoStatus ret=SoOK;
	SoVar var[DSM_CACHE_BLOCK_SIZE];
	_uint idx=0;
	_uint i=k;

	if(k<k_start)
	{
		getblock(MAKE64(key,k),var);
		for(i=k;i<k_start && i<k_tail;i++)
		{
			var[i & DSM_CACHE_LOW_MASK]=buf[idx];
			idx++;
		}
		memcached_return rc=memcached_put(memc,MAKE64(key,k/DSM_CACHE_BLOCK_SIZE),var,sizeof(SoVar)*DSM_CACHE_BLOCK_SIZE);
		if(rc!=MEMCACHED_SUCCESS)
			ret= SoFail;
	}


	for(i=k_start;i<k_end;i+=DSM_CACHE_BLOCK_SIZE)
	{
		memcached_return rc=memcached_put(memc,MAKE64(key,i/DSM_CACHE_BLOCK_SIZE),buf + idx,sizeof(SoVar)*DSM_CACHE_BLOCK_SIZE);
		if(rc!=MEMCACHED_SUCCESS)
			ret= SoFail;
		idx+=DSM_CACHE_BLOCK_SIZE;
	}
	if(idx<len && k_end!=k_tail)
	{
		int kkk=k_end/DSM_CACHE_BLOCK_SIZE;
		getblock(MAKE64(key,k_end),var);
		for(;i<k_tail;i++)
		{
			var[i & DSM_CACHE_LOW_MASK]=buf[idx];
			idx++;
		}
		memcached_return rc=memcached_put(memc,MAKE64(key,k_end/DSM_CACHE_BLOCK_SIZE),var,sizeof(SoVar)*DSM_CACHE_BLOCK_SIZE);
		if(rc!=MEMCACHED_SUCCESS)
			ret= SoFail;
	}
	return ret;
}



SoStatus do_getchunk(_uint key,_uint fldid,_uint len,BINT* buf)
{
	_uint64 k=MAKE64(key,fldid/DSM_CACHE_BLOCK_SIZE);
	memcached_result_st results_obj;
	memcached_result_st* results;
	results= memcached_result_create(memc, &results_obj);
	memset(buf,0,sizeof(BINT)*len);

	_uint offset=fldid % DSM_CACHE_BLOCK_SIZE;
	memcached_return rc;
	SoStatus ret=fetchchunk2(k,len + offset);
	while ((results= memcached_fetch_result(memc, &results_obj, &rc)))
	{
		if(rc == MEMCACHED_SUCCESS)
		{
			_uint64* pkey;
			SoVar* pvalue;
			pkey=(_uint64*)memcached_result_key_value(results);
			pvalue=(SoVar*)memcached_result_value(results);
			_uint idx=(*pkey) - k;
			_uint i= (idx == 0)?offset:0;
			_uint j= idx*DSM_CACHE_BLOCK_SIZE+i -offset;
			for(;i<DSM_CACHE_BLOCK_SIZE,j<len;i++,j++)
			{
				buf[j]= pvalue[i].vi;
			}
		}
	}
	memcached_result_free(&results_obj);
	return ret;
}
SoStatus do_getchunk(_uint key,_uint fldid,_uint len,double* buf)
{
	_uint64 k=MAKE64(key,fldid/DSM_CACHE_BLOCK_SIZE);
	memcached_result_st results_obj;
	memcached_result_st* results;
	results= memcached_result_create(memc, &results_obj);
	memset(buf,0,sizeof(double)*len);

	_uint offset=fldid % DSM_CACHE_BLOCK_SIZE;
	memcached_return rc;
	SoStatus ret=fetchchunk2(k,len + offset);
	while ((results= memcached_fetch_result(memc, &results_obj, &rc)))
	{
		if(rc == MEMCACHED_SUCCESS)
		{
			_uint64* pkey;
			SoVar* pvalue;
			pkey=(_uint64*)memcached_result_key_value(results);
			pvalue=(SoVar*)memcached_result_value(results);
			_uint idx=(*pkey) - k;
			_uint i= (idx == 0)?offset:0;
			_uint j= idx*DSM_CACHE_BLOCK_SIZE+i -offset;
			for(;i<DSM_CACHE_BLOCK_SIZE && j<len;i++,j++)
			{
				buf[j]= pvalue[i].vd;
			}
		}
	}
	memcached_result_free(&results_obj);
	return ret;
}

template <typename T>
SoStatus splited_getchunk(_uint key,_uint fldid,_uint len,T* buf)
{
	_uint l=fldid;
	if(len>=15040)
	{
		_uint limit=fldid+len-15040;
		for(;l<limit;l+=15040)
		{
			if (do_getchunk(key,l,15040,buf+(l-fldid))!=SoOK)
				return SoFail;
		}
	}
	_uint remain=fldid+len-l;
	if(remain)
		return do_getchunk(key,l,remain,buf+(l-fldid));
	else
		return SoOK;
}

SoStatus SoStorageChunkMemcached::getchunk(_uint key,_uint fldid,_uint len,double* buf)
{
	return splited_getchunk(key,fldid,len,buf);
}
SoStatus SoStorageChunkMemcached::getchunk(_uint key,_uint fldid,_uint len,BINT* buf)
{
	return splited_getchunk(key,fldid,len,buf);
}



SoStatus SoStorageChunkMemcached::getblock(_uint64 addr,SoVar* buf)
{
	_uint64 k=(addr & 0xffffffff00000000) | ((addr & 0xffffffff)/DSM_CACHE_BLOCK_SIZE);
	memcached_result_st results_obj;
	memcached_result_st* results;
	results= memcached_result_create(memc, &results_obj);
	memset(buf,0,sizeof(SoVar)*DSM_CACHE_BLOCK_SIZE);

	memcached_return rc;
	SoStatus ret=fetchchunk2(k,DSM_CACHE_BLOCK_SIZE);
	while ((results= memcached_fetch_result(memc, &results_obj, &rc)))
	{
		if(rc == MEMCACHED_SUCCESS)
		{
			_uint64* pkey;
			SoVar* pvalue;
			pkey=(_uint64*)memcached_result_key_value(results);
			pvalue=(SoVar*)memcached_result_value(results);
			for(_uint i= 0;i<DSM_CACHE_BLOCK_SIZE;i++)
			{
				buf[i]= pvalue[i];
			}
		}
	}
	memcached_result_free(&results_obj);
	return ret;
}

