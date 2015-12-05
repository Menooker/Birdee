#include "BdSharedObj.h"
#include <memcached.h>
/*

struct NodeValue
{
	SoType tag;
	union
	{
		SoVar var;
		struct 
		{
			size_t len;
			wchar_t str[0];
		}string;
		struct
		{
			size_t field_cnt;
			SoVar fields[0];
		}cls;

		struct
		{
			SoType ty;
			size_t arr_cnt;
			SoVar arr[0];
		}barray;
	};
};

class SoStorageMemcached : public SoStorage
{
private:

	memcached_st *memc;
    
public:
	SoStorageMemcached(char* host)
	{
		memcached_return rc;
		memcached_server_st *servers;
		memc = memcached_create(NULL);
		servers = memcached_server_list_append(NULL, host,11211, &rc);
		rc = memcached_server_push(memc, servers);
		memcached_server_free(servers);
	}

	SoStatus putstr(uint key,wchar_t* str,uint len)
	{
		DataNode nd;
		nd.tag=SoString;
		nd.string.len=len;
		nd.string.str=str;
		map[key]=nd;
		return SoOK;
	}

	SoStatus put(uint key,int fldid,SoVar v)
	{
		map[key].cls.fields[fldid]=v;
		return SoOK;
	}

	DataNode get(uint key,int fldid)
	{
		uint64_t k=key<<32 & fldid;
		char *keys[]= {(char*)&k};
		size_t key_length[]= {64};
		memcached_return rc;
		rc = memcached_mget(memc, (char**)keys, key_length, 1);

		char return_key[MEMCACHED_MAX_KEY];
		size_t return_key_length;
		char *return_value;
		size_t return_value_length;
		uint32_t flags;

		return_value = memcached_fetch(memc, return_key,
			&return_key_length, &return_value_length, &flags, &rc); //fix-me : need free return_value?
		if (rc == MEMCACHED_SUCCESS) {
			NodeValue* node=(NodeValue*)return_value;
			DataNode nd;
			nd.tag=node->tag;
			switch(nd.tag)
			{
				case 
			}
		}
		else
		{
			DataNode a;
			a.tag=SoInvalid;
			return a;
		}
	}

	bool exists(uint key)
	{
		return map.find(key)!=map.end();
	}

	SoStatus newobj(uint key,DataNode* nd)
	{
		if(map.find(key)==map.end())
		{
			if(nd->tag==SoObject || nd->tag==SoModule)
			{
				nd->cls.fields=(SoVar*)malloc(sizeof(SoVar)* nd->cls.field_cnt);
				memset(nd->cls.fields,0,sizeof(SoVar)* nd->cls.field_cnt);
				map[key]=*nd;
				return SoOK;
			}
			else
			{
				DBG_assert(nd->tag==SoString ,("Node type is wrong %d\n",nd->tag));
				map[key]=*nd;
				return SoOK;
			}
		}
		else
			return SoFail;
	}
};*/