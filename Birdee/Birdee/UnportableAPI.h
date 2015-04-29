#ifndef _H_UNPORTABLE_API
#define _H_UNPORTABLE_API

#include "Conf.h"
#include <stdio.h>



#ifdef __cplusplus
extern "C"
{
#endif
	#include "../../dvm/dvm_pri.h"
	#ifdef BD_ON_WINDOWS
	#include <Windows.h>
	#define THREAD_ID HANDLE
	//#define curdvm ((DVM_VirtualMachine*)TlsGetValue(dwTlsIndex))
	
	#endif
	extern  thread_local BdThread* curthread;
	extern 	DVM_VirtualMachine* curdvm;
	extern DWORD dwTlsIndex; 
	typedef void (*UaTraceCallBack)(void* param,void* ebp,void* retaddr,void* calladdr);
	long UaSetBufferUnreadable(void* buf,size_t sz);
	void UaRestoreBufferStatus(void* buf,size_t sz,long st);
	void* UaGuardAlloc(size_t sz);
	void UaGuardFree(void* p);
	void  UaStackTrace(UaTraceCallBack cb,void* param);
	THREAD_ID UaCreateThread(BdThread* vm,int go);
	THREAD_ID UaGetCurrentThread();
	void UaStopThread(THREAD_ID t);
	void UaSetCurVM(DVM_VirtualMachine* vm);
	void UaInitTls();


#ifdef __cplusplus
}
#endif

#endif
