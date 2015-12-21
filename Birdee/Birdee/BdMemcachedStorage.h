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
	SoStorageMemcached(char* host)
	{
		offset=2147483647;
		memcached_return rc;
		memcached_server_st *servers;
		memc = memcached_create(NULL);
		memcached_behavior_set(memc, MEMCACHED_BEHAVIOR_BINARY_PROTOCOL, 1);
		memcached_behavior_set(memc, MEMCACHED_BEHAVIOR_SUPPORT_CAS, 1);
//		memc->call_malloc=(memcached_malloc_function)malloc;
//		memc->call_free=(memcached_free_function)free;
//		memc->call_realloc=(memcached_realloc_function)realloc;
		servers = memcached_server_list_append(NULL, host,11211, &rc);
		rc = memcached_server_push(memc, servers);
		memcached_server_free(servers);
	}
};


#endif