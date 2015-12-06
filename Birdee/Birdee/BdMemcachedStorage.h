#ifndef _H_BIRDEE_MEMCACHED
#define _H_BIRDEE_MEMCACHED
#include "BdSharedObj.h"
#include <memcached.h>

class SoStorageMemcached : public SoStorage
{
private:

	memcached_st *memc;
public:

	SoStatus putstr(uint key,wchar_t* str,uint len);
	SoStatus put(uint key,int fldid,SoVar v);
	SoVar get(uint key,int fldid);
	SoStatus getstr(uint key,wchar_t** str,uint* len);
	bool exists(uint key);
	SoStatus newobj(uint key,SoType tag,int fld_cnt);

	~SoStorageMemcached();
	SoStorageMemcached(char* host)
	{
		memcached_return rc;
		memcached_server_st *servers;
		memc = memcached_create(NULL);
		servers = memcached_server_list_append(NULL, host,11211, &rc);
		rc = memcached_server_push(memc, servers);
		memcached_server_free(servers);
	}
};


#endif