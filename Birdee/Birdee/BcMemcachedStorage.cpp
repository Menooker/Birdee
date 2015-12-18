#include "BdSharedObj.h"
#include "BdMemcachedStorage.h"
#include <libmemcached/memcached.h>
#include <stdlib.h>

#ifdef BD_ON_WINDOWS
	#define atoll _atoi64
#endif
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

memcached_return memcached_put(memcached_st* memc,unsigned long long k,void* v,size_t len)
{
	char ch[17];
	sprintf(ch,"%016llx",k);
	memcached_return rc = memcached_set(memc, ch, 17, (char*)v,len,(time_t)0, (uint32_t)4096);
	return rc;
}


SoStorageMemcached::~SoStorageMemcached()
{
		//memcached_free(memc); //fix-me : unknown error at here
}

int SoStorageMemcached::getcounter(uint key,int fldid)
{
	char ch[17];
	sprintf(ch,"%016llx",MAKE64(key,fldid));
	size_t return_key_length=17;
	size_t return_value_length;
	uint32_t flags;
	memcached_return rc;
	char* return_value = memcached_get(memc, ch,return_key_length, &return_value_length, &flags, &rc);
	if(rc!=MEMCACHED_SUCCESS)
		throw 1;
	long long ret=atoll(return_value);
	return ret-offset;
}
void SoStorageMemcached::setcounter(uint key,int fldid,int n)
{
	char ch[17];
	sprintf(ch,"%016llx",MAKE64(key,fldid));
	size_t return_key_length=17;
	size_t return_value_length;
	uint32_t flags;
	memcached_return rc;

	char ch2[65];
	sprintf(ch2,"%lld",(long long)n+offset);
	rc = memcached_set(memc, ch,return_key_length,ch2,strlen(ch2),0, 0);
	if(rc!=MEMCACHED_SUCCESS)
		throw 1;
}

int SoStorageMemcached::inc(uint key,int fldid,int inc)
{
	char ch[17];
	sprintf(ch,"%016llx",MAKE64(key,fldid));
	uint64_t ret;
	memcached_return rc;
	if(inc>0)
		rc=memcached_increment(memc,ch,17,inc,&ret);
	else
		rc=memcached_decrement(memc,ch,17,-inc,&ret);
	if(rc!=MEMCACHED_SUCCESS)
		throw 1;
	return ret-offset;

}
int SoStorageMemcached::dec(uint key,int fldid,int dec)
{
	return inc(key,fldid,-dec);
}
SoStatus SoStorageMemcached::putstr(uint key,wchar_t* str,uint len)
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

SoStatus SoStorageMemcached::getstr(uint key,wchar_t** str,uint* len)
{
	long long k1,k2;
	k1=MAKE64(key,0);
	k2=MAKE64(key,1);
	char ch1[17],ch2[17];
	sprintf(ch1,"%016llx",k1);
	sprintf(ch2,"%016llx",k2);
	char *keys[]= {ch1,ch2};
	size_t key_length[]= {17,17};
	memcached_return rc;

	size_t return_key_length=17;
	size_t return_value_length;
	uint32_t flags;
	char* return_value = memcached_get(memc, ch1,return_key_length, &return_value_length, &flags, &rc);
	NodeValue* node;
	if(rc==MEMCACHED_SUCCESS)
	{
		SoType ty=*(SoType*) return_value;
		memcached_free2(return_value);
		if(ty!=SoString)
			return SoFail;

		return_value = memcached_get(memc, ch2,return_key_length, &return_value_length, &flags, &rc);
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

SoStatus SoStorageMemcached::put(uint key,int fldid,SoVar v)
{
	if(memcached_put(memc,MAKE64(key,fldid),&v,sizeof(v))==MEMCACHED_SUCCESS)
		return SoOK;
	return SoFail;
}

SoVar SoStorageMemcached::get(uint key,int fldid)
{
	SoVar ret;
	unsigned long long k=MAKE64(key,fldid);
	char* mret;
	size_t len;
	size_t flg;
	memcached_return rc;
	char ch[17];
	sprintf(ch,"%016llx",k);
	mret=memcached_get(memc,ch,17,&len,&flg,&rc);
	if (rc == MEMCACHED_SUCCESS) {
		ret=*(SoVar*)mret;
		memcached_free2(mret);
		return ret;
	}
	else
	{
		throw SO_KEY_NOT_FOUND;
	}
	return ret;

}

bool SoStorageMemcached::exists(uint key)//fix-me : improve
{
	size_t outlen;
	size_t flg;
	memcached_return rc;
	char ch[17];
	sprintf(ch,"%016llx",MAKE64(key,0));
	char* r= memcached_get(memc,ch,17,&outlen,&flg,&rc);
	if(rc==MEMCACHED_SUCCESS)
	{
		memcached_free2(r);
		return true;
	}
	return false;
}

SoStatus SoStorageMemcached::newobj(uint key,SoType tag,int fld_cnt,int flag)
{
	NodeValue nd;
	nd.tag=tag;
	nd.field_cnt=fld_cnt;
	nd.flag=flag;
	char ch[17];
	sprintf(ch,"%016llx",MAKE64(key,0));
	if(memcached_add(memc,ch,17,(char*)&nd,sizeof(nd),(time_t)0,0)==MEMCACHED_SUCCESS)
		return SoOK;
	return SoFail;
}
