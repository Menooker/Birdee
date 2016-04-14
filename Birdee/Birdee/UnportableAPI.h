#ifndef _H_UNPORTABLE_API
#define _H_UNPORTABLE_API

#include "Conf.h"
	#ifdef BD_ON_WINDOWS
		#include <Windows.h>
		#include <WinBase.h>
		typedef void* THREAD_ID;
		#define BD_LOCK CRITICAL_SECTION
		#define BD_EVENT HANDLE
		#define BD_RWLOCK SRWLOCK
		typedef DWORD (__stdcall *UaThreadProc)(PVOID p);
    #else
        #include <unistd.h>
        #include <pthread.h>
        #include <semaphore.h>
        #define BD_LOCK pthread_spinlock_t
		typedef struct  {
			pthread_mutex_t mutex;
			pthread_cond_t cond;
			int triggered;
		}BD_EVENT;
		#define BD_RWLOCK pthread_rwlock_t
        typedef pthread_t THREAD_ID;
		typedef void* (*UaThreadProc)(void* p);
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
	void UaSuspendThread(THREAD_ID id,BdThread* th);
	void UaResumeThread(THREAD_ID id,BdThread* th);
	void UaSleep(int ms);
	int UaAtomicInc(long* ptr,long inc);
	int UaAtomicDec(long* ptr,long dec);
	THREAD_ID UaCreateThreadEx(UaThreadProc proc,void* param);
	void UaWaitForThread(THREAD_ID th);
	void UaInitEvent(BD_EVENT* pevent,int state);
	#ifdef BD_ON_WINDOWS
        #ifdef BD_ON_GCC
typedef struct{void* PTR;} SRWLOCK, *PSRWLOCK;

#define SRWLOCK_INIT RTL_SRWLOCK_INIT

WINBASEAPI
VOID
WINAPI
InitializeSRWLock (
     PSRWLOCK SRWLock
     );

WINBASEAPI
VOID
WINAPI
ReleaseSRWLockExclusive (
     PSRWLOCK SRWLock
     );

WINBASEAPI
VOID
WINAPI
ReleaseSRWLockShared (
     PSRWLOCK SRWLock
     );

WINBASEAPI
VOID
WINAPI
AcquireSRWLockExclusive (
     PSRWLOCK SRWLock
     );

WINBASEAPI
VOID
WINAPI
AcquireSRWLockShared (
     PSRWLOCK SRWLock
     );

WINBASEAPI
BOOLEAN
WINAPI
TryAcquireSRWLockExclusive (
    PSRWLOCK SRWLock
    );

WINBASEAPI
BOOLEAN
WINAPI
TryAcquireSRWLockShared (
    PSRWLOCK SRWLock
    );

        #endif
        #define UaPrepareThread()
		#define UaInitRWLock(a) InitializeSRWLock(a)
		#define UaEnterWriteRWLock(a) AcquireSRWLockExclusive(a)
		#define UaLeaveWriteRWLock(a) ReleaseSRWLockExclusive(a)
		#define UaEnterReadRWLock(a) AcquireSRWLockShared(a)
		#define UaTryEnterWriteRWLock(a) TryAcquireSRWLockExclusive(a)
		#define UaTryEnterReadRWLock(a) TryAcquireSRWLockShared(a)
		#define UaLeaveReadRWLock(a) ReleaseSRWLockShared(a)
		#define UaKillRWLock(a)
		#define UaKillEvent(a) CloseHandle(*a)
		#define UaSetEvent(a) SetEvent(*a)
		#define UaResetEvent(a) ResetEvent(*a)
		#define UaWaitForEvent(a) WaitForSingleObject(*a,-1)
		#define UaWaitForEventEx(a,t) WaitForSingleObject(*a,t)
		#define UaCloseThread(a) CloseHandle(a)
		#define UaJoinThread(a) WaitForSingleObject(a,-1)
    #else
        void UaPrepareThread();
		#define UaInitRWLock(a) pthread_rwlock_init(a,NULL)
		#define UaEnterWriteRWLock(a) pthread_rwlock_wrlock(a)
		#define UaLeaveWriteRWLock(a) pthread_rwlock_unlock(a)
		#define UaEnterReadRWLock(a) pthread_rwlock_rdlock(a)
		#define UaTryEnterWriteRWLock(a) pthread_rwlock_trywrlock(a)
		#define UaTryEnterReadRWLock(a) pthread_rwlock_tryrdlock(a)
		#define UaLeaveReadRWLock(a) pthread_rwlock_unlock(a)
		#define UaKillRWLock(a) pthread_rwlock_destroy(a)
		void UaKillEvent(BD_EVENT* ev);
		void UaSetEvent(BD_EVENT* ev);
		void UaResetEvent(BD_EVENT* ev);
		void UaWaitForEvent(BD_EVENT* ev);
		int UaWaitForEventEx(BD_EVENT* ev,int timeout);
		#define UaCloseThread(a)
		#define UaJoinThread(a) pthread_join(a,NULL)
    #endif
#ifdef __cplusplus
}
#endif

#endif
