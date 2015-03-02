#ifndef _H_UNPORTABLE_API
#define _H_UNPORTABLE_API

#include "Conf.h"
#include <stdio.h>


#ifdef __cplusplus
extern "C"
{
#endif
	typedef void (*UaTraceCallBack)(void* param,void* ebp,void* retaddr,void* calladdr);
	long UaSetBufferUnreadable(void* buf,size_t sz);
	void UaRestoreBufferStatus(void* buf,size_t sz,long st);
	void* UaGuardAlloc(size_t sz);
	void UaGuardFree(void* p);
	void  UaStackTrace(UaTraceCallBack cb,void* param);
#ifdef __cplusplus
}
#endif

#endif
