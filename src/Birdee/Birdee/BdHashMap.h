#ifndef _H_BIRDEE_HASHMAP
#define _H_BIRDEE_HASHMAP

#ifdef __cplusplus

extern "C"
{
#endif
#include "dvm_pri.h"

typedef struct _RtlHashMap RtlHashMap ;
void RtlHashmapPut(RtlHashMap* pmap,BdIntPtr name,DVM_ObjectRef v);
RtlHashMap* RtlCreateHashmap();
void RtlDisposeHashmap(RtlHashMap* p);
DVM_ObjectRef RtlHashmapGet(RtlHashMap* pmap,BdIntPtr key);

#ifdef __cplusplus
}
#endif

#endif
