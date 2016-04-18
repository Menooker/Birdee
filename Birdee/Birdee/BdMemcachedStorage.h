#ifndef _H_BIRDEE_MEMCACHED
#define _H_BIRDEE_MEMCACHED
#include "BdSharedObj.h"
#include <libmemcached/memcached.h>

#define memc ((memcached_st *)_memc)
extern thread_local void *_memc;
class SoStorageMemcached;
extern memcached_st * sto;

extern "C" void* init_memcached_this_thread();


class SoStorageMemcached : public SoStorage
{
private:
	int offset;

#ifndef BD_ON_WINDOWS
	//memcached_st *memc;
#endif
public:
	SoStatus getblock(_uint64 addr,SoVar* buf);
	SoStatus putstr(_uint key,wchar_t* str,_uint len);
	SoStatus put(_uint key,_uint fldid,SoVar v);
	SoVar get(_uint key,_uint fldid);
	SoStatus getstr(_uint key,wchar_t** str,_uint* len);
	bool exists(_uint key);
	SoStatus newobj(_uint key,SoType tag,int fld_cnt,int flag);
	SoStatus getinfo(_uint key,SoType& tag,int& fld_cnt,int& flag);
	int inc(_uint key,_uint fldid,int inc);
	int dec(_uint key,_uint fldid,int dec);
	int getcounter(_uint key,_uint fldid);
	void setcounter(_uint key,_uint fldid,int n);
	int getsize(_uint key);
	SoStatus getchunk(_uint key,_uint fldid,_uint len,double* buf);
	SoStatus getchunk(_uint key,_uint fldid,_uint len,BINT* buf);
	SoStatus del(_uint key,unsigned int len);
	SoStatus putchunk(_uint key,_uint fldid,_uint len,SoVar* buf);
	~SoStorageMemcached();

    memcached_st *main_memc;
//#ifdef BD_ON_WINDOWS
	std::vector<std::string> mem_hosts;
	std::vector<int> mem_ports;
	//std::vector<memcached_st *> clients;
	SoStorageMemcached(std::vector<std::string>& arr_mem_hosts,std::vector<int>& arr_mem_ports)
	{
		offset=2147483647;
		mem_hosts=arr_mem_hosts;
		mem_ports=arr_mem_ports;
        memcached_return rc;
		memcached_server_st *servers;
        _memc=(memcached_st*)memcached_create(NULL);
		sto=memc;
		memcached_behavior_set((memcached_st*)_memc, MEMCACHED_BEHAVIOR_BINARY_PROTOCOL, 1);

/*#ifndef BD_ON_WINDOWS
		memcached_behavior_set((memcached_st*)_memc, MEMCACHED_BEHAVIOR_NO_BLOCK, 1);
		memcached_behavior_set((memcached_st*)_memc, MEMCACHED_BEHAVIOR_NOREPLY, 1);
		memcached_behavior_set((memcached_st*)_memc, MEMCACHED_BEHAVIOR_TCP_KEEPALIVE, 1);
#endif*/
//		memc->call_malloc=(memcached_malloc_function)malloc;
//		memc->call_free=(memcached_free_function)free;
//		memc->call_realloc=(memcached_realloc_function)realloc;
		servers=NULL;
		for(_uint i=0;i<mem_hosts.size();i++)
		{
			servers = memcached_server_list_append(servers, mem_hosts[i].c_str(),mem_ports[i], &rc);
		}

		rc = memcached_server_push((memcached_st*)_memc, servers);
		memcached_server_free(servers);
		main_memc=memc;
	}

};



class SoStorageChunkMemcached : public SoStorageMemcached
{
public:
	SoStatus getblock(_uint64 addr,SoVar* buf);
	SoStatus put(_uint key,_uint fldid,SoVar v);
	SoVar get(_uint key,_uint fldid);
	SoStatus getchunk(_uint key,_uint fldid,_uint len,double* buf);
	SoStatus getchunk(_uint key,_uint fldid,_uint len,BINT* buf);
	SoStatus putchunk(_uint key,_uint fldid,_uint len,SoVar* buf);
	~SoStorageChunkMemcached(){}

	SoStorageChunkMemcached(std::vector<std::string>& arr_mem_hosts,std::vector<int>& arr_mem_ports):SoStorageMemcached(arr_mem_hosts,arr_mem_ports)
	{
		
	}
};


#endif
