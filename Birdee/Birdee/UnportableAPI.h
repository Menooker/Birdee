#ifndef _H_UNPORTABLE_API
#define _H_UNPORTABLE_API

#include "Conf.h"
	#ifdef BD_ON_WINDOWS
		#include <Windows.h>
		typedef void* THREAD_ID;
		#define BD_LOCK CRITICAL_SECTION
		typedef DWORD (__stdcall *UaThreadProc)(PVOID p);
    #else
        #include <unistd.h>
        #include <pthread.h>
        #include <semaphore.h>
        #define BD_LOCK pthread_spinlock_t
        typedef pthread_t THREAD_ID;
		typedef (void*) (*UaThreadProc)(void* p);
	#endif

	#undef min
	#undef max

#include <stdio.h>

#ifdef __cplusplus
extern "C"
{
#endif
	#include "dvm_pri.h"
    #define TRIM_TO_PAGE(a) ((a/PAGE_SIZE + (a % PAGE_SIZE == 0 ? 0:1) )* PAGE_SIZE)
	extern  thread_local BdThread* curthread;
	extern 	DVM_VirtualMachine* curdvm;
	typedef void (*UaTraceCallBack)(void* param,void* ebp,void* retaddr,void* calladdr);
	long UaSetBufferUnreadable(void* buf,size_t sz);
	void UaRestoreBufferStatus(void* buf,size_t sz,long st);
	void* UaGuardAlloc(size_t sz);
	void UaGuardFree(void* p,size_t sz);
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
	void UaResumeThread(THREAD_ID id,BdThread* th);
	void UaSleep(int ms);
	int UaAtomicInc(long* ptr,long inc);
	int UaAtomicDec(long* ptr,long dec);
	THREAD_ID UaCreateThreadEx(UaThreadProc proc,void* param);
	void UaWaitForThread(THREAD_ID th);
	#ifdef BD_ON_WINDOWS
        #define UaPrepareThread()
		#define BD_RWLOCK SRWLOCK
		#define UaInitRWLock(a) InitializeSRWLock(a)
		#define UaEnterWriteRWLock(a) AcquireSRWLockExclusive(a)
		#define UaLeaveWriteRWLock(a) ReleaseSRWLockExclusive(a)
		#define UaEnterReadRWLock(a) AcquireSRWLockShared(a)
		#define UaLeaveReadRWLock(a) ReleaseSRWLockShared(a)
		#define UaKillRWLock(a) 
    #else
        void UaPrepareThread();
    #endif
#ifdef __cplusplus
}
#endif

#endif
