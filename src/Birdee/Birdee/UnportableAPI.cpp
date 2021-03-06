#include "UnportableAPI.h"
#include "BirdeeDef.h"
#include <stdio.h>
#ifdef BD_ON_WINDOWS
    #include <Windows.h>
#else
    #include <sys/mman.h>
    #include <signal.h>
    #include <sys/time.h>
#endif
#include <stdlib.h>
extern "C" thread_local BdThread* curthread;
extern "C"
{

#ifndef BD_ON_WINDOWS
int PAGE_SIZE=getpagesize();
#endif

#ifdef BD_ON_VC
#ifdef BD_ON_X86
void __stdcall _UaStackTrace(int StackBase, int ebp, int esp,UaTraceCallBack cb,void* param)
{
    int limit = 30, retaddr, calladdr;
    while ((ebp > esp) && (ebp < StackBase) && (limit--)) {
        retaddr = *(int *)(ebp + 4);
        calladdr = 0;
        __try {
            //if (*(unsigned char *)(retaddr - 5) == 0xe8) {
                calladdr = *(int *)(retaddr - 4) + retaddr;
            //}
        } __except (EXCEPTION_EXECUTE_HANDLER) {
        }
       cb(param,(void*) ebp, (void*)retaddr, (void*)calladdr);
        ebp = *(int *)ebp;
    }

}


void  UaStackTrace(UaTraceCallBack cb,void* param)
{
    // iceboy's stack trace
    __asm {
		push param
		push cb
        push esp
        push ebp
        push fs:[0x4]        ; StackBase
        call _UaStackTrace
    }
	return;
}
#endif
#endif

#if (defined(BD_ON_GCC) || defined(BD_ON_X64))
void  UaStackTrace(UaTraceCallBack cb,void* param){};
#endif


#ifdef BD_ON_WINDOWS
	DWORD dwTlsIndex;

	void UaInitTls()
	{
		dwTlsIndex = TlsAlloc();
		if(dwTlsIndex==TLS_OUT_OF_INDEXES)
		{
			fprintf(stderr,"TLS out of indexes");
			exit(0);
		}
	}

	extern void ThThreadStub(BdThread*);
	DWORD __stdcall UaThreadStub(PVOID p)
	{
		ThThreadStub((BdThread*)p);
		return 0;
	}

    void UaInitEvent(BD_EVENT* pevent,int state)
    {
        *pevent=CreateEvent(NULL,TRUE,state?TRUE:FALSE,NULL);
    }

	THREAD_ID UaGetCurrentThread()
	{
		return GetCurrentThread();
	}

	void UaStopThread(THREAD_ID t)
	{
		TerminateThread(t,1024);
	}

	void UaSetCurVM(DVM_VirtualMachine_tag* vm)
	{
		curdvm=vm;
		//TlsSetValue(dwTlsIndex,vm);
	}

	THREAD_ID UaCreateThreadEx(UaThreadProc proc,void* param)
	{
		HANDLE h=CreateThread(0,0,proc,param,0,0);
		return h;
	}

	void UaWaitForThread(THREAD_ID th)
	{
		WaitForSingleObject(th,-1);
	}

	THREAD_ID UaCreateThread(BdThread* vm,int go,DVM_ObjectRef arg)
	{
		vm->new_obj=arg;
		HANDLE h=CreateThread(0,0,UaThreadStub,vm,go?0:CREATE_SUSPENDED,0);
		return h;
	}

	void UaSuspendThread(THREAD_ID id,BdThread* th)
	{
		SuspendThread(id);
	}

	void UaResumeThread(THREAD_ID id,BdThread* th)
	{
		ResumeThread(id);
	}
	void UaInitLock(BD_LOCK* lc)
	{
		InitializeCriticalSection(lc);
	}

	void UaKillLock(BD_LOCK* lc)
	{
		DeleteCriticalSection(lc);
	}

	void UaEnterLock(BD_LOCK* lc)
	{
		EnterCriticalSection(lc);
	}

	void UaLeaveLock(BD_LOCK* lc)
	{
		LeaveCriticalSection(lc);
	}

#if (defined(BD_ON_GCC) & defined(BD_ON_X86))
	ptDbgBreakPoint _DbgBreakPoint = (ptDbgBreakPoint)GetProcAddress(GetModuleHandleW(L"NTDLL.DLL"), "DbgBreakPoint");
#endif //BD_ON_VC | BD_ON_X86
	void UaBreakPoint()
	{
#if  defined(BD_ON_VC) & defined(BD_ON_X86)
		_BreakPoint //only X86 version of MSVC compiler support inline asm
#else
        _BreakPoint
		//DbgBreakPoint may spoil the stack trace....try to avoid it
		//_DbgBreakPoint();//assume _DbgBreakPoint!=null, if it does equals null, it's still a 'break point' ^_^
#endif //BD_ON_VC & BD_ON_X86
	}

	int UaAtomicInc(long* ptr,long inc)
	{
		return InterlockedExchangeAdd(ptr,inc);
	}

	int UaAtomicDec(long* ptr,long dec)
	{
		return InterlockedExchangeAdd(ptr,-dec);
	}

	void UaSleep(int ms)
	{
		Sleep(ms);
	}
	void* UaGuardAlloc(size_t sz)
	{

		size_t pages=sz/PAGE_SIZE;
		if(sz%PAGE_SIZE!=0)
			pages++;
		//printf("ps:%d %d\n",pages,sz);

		void *p = VirtualAlloc(NULL,(pages+1)*PAGE_SIZE,MEM_COMMIT,PAGE_READWRITE);
		if(!p)
		{
			printf("Error when alloc!");
			exit(1);
		}
		UaSetBufferUnreadable((char*)p + pages*PAGE_SIZE,PAGE_SIZE);
		return p;

	}


	void UaGuardFree(void* p,size_t sz)
	{

		VirtualFree(p,0,MEM_RELEASE);
		return ;

	}

	long UaSetBufferUnreadable(void* buf,size_t sz)
	{

		DWORD dold;
		VirtualProtect(buf,sz,PAGE_NOACCESS,&dold);
		return dold;

	}

	void UaRestoreBufferStatus(void* buf,size_t sz,long st)
	{

		DWORD dold;
		VirtualProtect(buf,sz,st,&dold);
		return ;

	}
#else
    //for linux
    void thread1_suspend(int dummy)
    {
        sem_wait(&curthread->suspend_lock);
    }

    void UaPrepareThread()
    {
  	    sigset_t set;
        sigemptyset(&set);
        sigaddset(&set, SIGUSR1);
	    pthread_sigmask(SIG_UNBLOCK,&set,NULL);
        signal(SIGUSR1, thread1_suspend);
    }

	extern void ThThreadStub(BdThread*);
	void* UaThreadStub(void* p)
	{
        UaPrepareThread();
		ThThreadStub((BdThread*)p);
		pthread_exit(NULL);
		return 0;
	}



	THREAD_ID UaGetCurrentThread()
	{
		return pthread_self();
	}

	void UaStopThread(THREAD_ID t)
	{
        pthread_cancel(t);//fix-me : check if it is suspended?
	}

	void UaSetCurVM(DVM_VirtualMachine_tag* vm)
	{
		curdvm=vm;
		//TlsSetValue(dwTlsIndex,vm);
	}

    THREAD_ID UaCreateThreadEx(UaThreadProc proc,void* param)
    {
 		THREAD_ID id;
        pthread_create(&id,NULL,proc,param);
        return id;
    }

	THREAD_ID UaCreateThread(BdThread* vm,int go,DVM_ObjectRef arg)
	{
		vm->new_obj=arg;
		THREAD_ID id;
        pthread_create(&id,NULL,UaThreadStub,vm);
        return id;
	}

	void UaSuspendThread(THREAD_ID id,BdThread* th)
	{
		while(!th->prepared)
			;
		pthread_kill(id, SIGUSR1);
	}

	void UaResumeThread(THREAD_ID id,BdThread* th)
	{
		sem_post(&th->suspend_lock);
    }
	void UaInitLock(BD_LOCK* lc)
	{
		pthread_spin_init(lc,PTHREAD_PROCESS_PRIVATE);
	}

	void UaKillLock(BD_LOCK* lc)
	{
		pthread_spin_destroy(lc);
	}

	void UaEnterLock(BD_LOCK* lc)
	{
		pthread_spin_lock(lc);
	}

	void UaLeaveLock(BD_LOCK* lc)
	{
		pthread_spin_unlock(lc);
	}

	void UaBreakPoint()
	{
        _BreakPoint
	}

	int UaAtomicInc(long* ptr,long inc)
	{
		return __sync_add_and_fetch(ptr,inc);
	}

	int UaAtomicDec(long* ptr,long dec)
	{
		return __sync_add_and_fetch(ptr,-dec);
	}

	void UaSleep(int ms)
	{
		usleep(ms*1000);
	}
	void* UaGuardAlloc(size_t sz)
	{

		size_t pages=sz/PAGE_SIZE;
		if(sz%PAGE_SIZE!=0)
			pages++;
        void* p=mmap(NULL, (pages+1)*PAGE_SIZE,PROT_READ | PROT_WRITE, MAP_ANON | MAP_SHARED, 0,0);
        if(p==(void *)-1)
        {
            printf("Error when alloc!");
			exit(1);
        }
		UaSetBufferUnreadable((char*)p + pages*PAGE_SIZE,PAGE_SIZE);
		return p;

	}


	void UaGuardFree(void* p,size_t sz)
	{

		munmap(p,TRIM_TO_PAGE(sz)+PAGE_SIZE);
		return ;

	}

	long UaSetBufferUnreadable(void* buf,size_t sz)
	{

		mprotect(buf,sz,PROT_NONE);
		return 0;

	}

	void UaRestoreBufferStatus(void* buf,size_t sz,long st)
	{
		return ;
	}



	void UaInitEvent(BD_EVENT* ev,int state) {
		pthread_mutex_init(&ev->mutex, 0);
		pthread_cond_init(&ev->cond, 0);
		ev->triggered = state;
	}

	void UaSetEvent(BD_EVENT* ev) {
		pthread_mutex_lock(&ev->mutex);
		ev->triggered = 1;
		pthread_cond_broadcast(&ev->cond);
		pthread_mutex_unlock(&ev->mutex);
	}

	void UaResetEvent(BD_EVENT* ev) {
		pthread_mutex_lock(&ev->mutex);
		ev->triggered = 0;
		pthread_mutex_unlock(&ev->mutex);
	}

	void UaWaitForEvent(BD_EVENT* ev) {
		 pthread_mutex_lock(&ev->mutex);
		 while (!ev->triggered)
			 pthread_cond_wait(&ev->cond, &ev->mutex);
		 pthread_mutex_unlock(&ev->mutex);
	}

	int UaWaitForEventEx(BD_EVENT* ev,int timeout) {
		if(timeout<0)
		{
			UaWaitForEvent(ev);
			return 0;
		}
		struct timespec timeToWait;
		struct timeval now;
		int rt;

		gettimeofday(&now,NULL);
		timeToWait.tv_sec = now.tv_sec;
        timeToWait.tv_nsec = (now.tv_usec+1000UL*timeout)*1000UL;
		 pthread_mutex_lock(&ev->mutex);
		 while (!ev->triggered)
		 {
			 rt=pthread_cond_timedwait(&ev->cond, &ev->mutex,&timeToWait);
			 if(!rt)
				 break;
		 }
		 pthread_mutex_unlock(&ev->mutex);
		 return rt;
	}

	void UaKillEvent(BD_EVENT* ev) {
		pthread_mutex_destroy(&ev->mutex);
		pthread_cond_destroy(&ev->cond);
	}


#endif //BD_ON_WINDOWS
}
