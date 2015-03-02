#include "BdHashMap.h"
#include "Conf.h"
#ifdef BD_ON_GCC
#include <ext/hash_map>
namespace std
{
using namespace __gnu_cxx;
}
#else
#include <hash_map>
#endif
#include <string>
using namespace std;

extern "C"
{

#include "../../include/MEM.h"

}


#ifdef BD_USE_STL_HASH_MAP
typedef hash_map<BdIntPtr,DVM_ObjectRef> RtlHashMapImp;
#endif
struct _RtlHashMap
{
	RtlHashMapImp hash;
};

RtlHashMap* RtlCreateHashmap()
{
	_RtlHashMap* newmap=(_RtlHashMap*)MEM_malloc(sizeof(_RtlHashMap));
	new(&newmap->hash)RtlHashMapImp(); //check-me
	return newmap;
}

void RtlDisposeHashmap(RtlHashMap* p)
{
	p->hash.~RtlHashMapImp();
	MEM_free(p);
}

void RtlHashmapPut(RtlHashMap* pmap,BdIntPtr key,DVM_ObjectRef v)
{
	pmap->hash[key]=v;
}

DVM_ObjectRef RtlHashmapGet(RtlHashMap* pmap,BdIntPtr key)
{
#ifdef BD_USE_STL_HASH_MAP
	if(pmap->hash.find(key)!=pmap->hash.end())
	{
		return pmap->hash[key];
	}
	else
		return dvm_null_object_ref;
#endif
}