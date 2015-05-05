#include "UnportableAPI.h"
#include "BirdeeDef.h"
#include <stdio.h>
#ifdef BD_ON_WINDOWS
#include <Windows.h>
#endif

extern "C"
{
thread_local BdThread* curthread;

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

#if (defined(BD_ON_GCC) & defined(BD_ON_X86))
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

	THREAD_ID UaCreateThread(BdThread* vm,int go,DVM_ObjectRef arg)
	{
		vm->new_obj=arg;
		HANDLE h=CreateThread(0,0,UaThreadStub,vm,go?0:CREATE_SUSPENDED,0);
		return h;
	}

	void UaSuspendThread(THREAD_ID id)
	{
		SuspendThread(id);
	}

	void UaResumeThread(THREAD_ID id)
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
	typedef void(__stdcall *ptDbgBreakPoint)(void);
	ptDbgBreakPoint _DbgBreakPoint = (ptDbgBreakPoint)GetProcAddress(GetModuleHandleW(L"NTDLL.DLL"), "DbgBreakPoint");
#endif //BD_ON_VC | BD_ON_X86
	void UaBreakPoint()
	{
#if  defined(BD_ON_VC) & defined(BD_ON_X86)
		_BreakPoint() //only X86 version of MSVC compiler support inline asm
#else
        _BreakPoint()
		//DbgBreakPoint may spoil the stack trace....try to avoid it
		//_DbgBreakPoint();//assume _DbgBreakPoint!=null, if it does equals null, it's still a 'break point' ^_^
#endif //BD_ON_VC & BD_ON_X86
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


	void UaGuardFree(void* p)
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
#endif //BD_ON_WINDOWS
}
