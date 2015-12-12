#ifndef _H_UNPORTABLE_API
#define _H_UNPORTABLE_API

#include "Conf.h"
	#ifdef BD_ON_WINDOWS
		#include <Windows.h>
		typedef void* THREAD_ID;
		#define BD_LOCK CRITICAL_SECTION

	#endif
	#undef min
	#undef max

#include <stdio.h>

#ifdef __cplusplus
extern "C"
{
#endif
	#include "../../dvm/dvm_pri.h"

	extern  thread_local BdThread* curthread;
	extern 	DVM_VirtualMachine* curdvm;
	extern DWORD dwTlsIndex; 
	typedef void (*UaTraceCallBack)(void* param,void* ebp,void* retaddr,void* calladdr);
	long UaSetBufferUnreadable(void* buf,size_t sz);
	void UaRestoreBufferStatus(void* buf,size_t sz,long st);
	void* UaGuardAlloc(size_t sz);
	void UaGuardFree(void* p);
	void  UaStackTrace(UaTraceCallBack cb,void* param);
	THREAD_ID UaCreateThread(BdThread* vm,int go,DVM_ObjectRef arg);
	THREAD_ID UaGetCurrentThread();
	void UaStopThread(THREAD_ID t);
	void UaSetCurVM(DVM_VirtualMachine* vm);
	void UaInitTls();
	void UaInitLock(BD_LOCK* lc);
	void UaKillLock(BD_LOCK* lc);
	void UaEnterLock(BD_LOCK* lc);
	void UaLeaveLock(BD_LOCK* lc);
	void UaSuspendThread(THREAD_ID id);
	void UaResumeThread(THREAD_ID id);
	void UaSleep(int ms);
#ifdef __cplusplus
}
#endif

#endif
