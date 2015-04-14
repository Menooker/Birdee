#ifndef _H_UNPORTABLE_API
#define _H_UNPORTABLE_API

#include "Conf.h"
#include <stdio.h>

#ifdef BD_ON_WINDOWS
#include <Windows.h>
#define THREAD_ID HANDLE
#define curdvm ((DVM_VirtualMachine*)TlsGetValue(TLS_MINIMUM_AVAILABLE+1))
#endif

#ifdef __cplusplus
extern "C"
{
#endif
	#include "../../dvm/dvm_pri.h"
	typedef void (*UaTraceCallBack)(void* param,void* ebp,void* retaddr,void* calladdr);
	long UaSetBufferUnreadable(void* buf,size_t sz);
	void UaRestoreBufferStatus(void* buf,size_t sz,long st);
	void* UaGuardAlloc(size_t sz);
	void UaGuardFree(void* p);
	void  UaStackTrace(UaTraceCallBack cb,void* param);
	THREAD_ID UaCreateThread(DVM_VirtualMachine* vm);
	void UaSetCurVM(DVM_VirtualMachine* vm);
#ifdef __cplusplus
}
#endif

#endif
