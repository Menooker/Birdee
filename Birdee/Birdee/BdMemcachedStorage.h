#ifndef _H_BIRDEE_MEMCACHED
#define _H_BIRDEE_MEMCACHED
#include "BdSharedObj.h"
#include <libmemcached/memcached.h>

class SoStorageMemcached : public SoStorage
{
private:
	int offset;
	memcached_st *memc;
public:

	SoStatus putstr(_uint key,wchar_t* str,_uint len);
	SoStatus put(_uint key,int fldid,SoVar v);
	SoVar get(_uint key,int fldid);
	SoStatus getstr(_uint key,wchar_t** str,_uint* len);
	bool exists(_uint key);
	SoStatus newobj(_uint key,SoType tag,int fld_cnt,int flag);
	int inc(_uint key,int fldid,int inc);
	int dec(_uint key,int fldid,int dec);
	int getcounter(_uint key,int fldid);
	void setcounter(_uint key,int fldid,int n);
	int getsize(_uint key);
	~SoStorageMemcached();
	SoStorageMemcached(std::list<std::string>& arr_mem_hosts,std::list<int>& arr_mem_ports)
	{
		offset=2147483647;
		memcached_return rc;
		memcached_server_st *servers;
		memc = memcached_create(NULL);
		memcached_behavior_set(memc, MEMCACHED_BEHAVIOR_BINARY_PROTOCOL, 1);
		//memcached_behavior_set(memc, MEMCACHED_BEHAVIOR_SUPPORT_CAS, 1);
//		memc->call_malloc=(memcached_malloc_function)malloc;
//		memc->call_free=(memcached_free_function)free;
//		memc->call_realloc=(memcached_realloc_function)realloc;
		char buf[255];
		servers=NULL;
		for(int i=0;i<arr_mem_hosts->u.barray.size;i++)
		{
			if(sprintf_s(buf,254,"%ws",arr_mem_hosts->u.barray.u.object[i].data->u.string.string)>=254)
				printf("Warning : host name %ws too long\n",arr_mem_hosts->u.barray.u.object[i].data->u.string.string);
			servers = memcached_server_list_append(servers, buf,arr_mem_hosts->u.barray.u.int_array[i], &rc);
		}		 

		rc = memcached_server_push(memc, servers);
		memcached_server_free(servers);
	}
};


#endif
