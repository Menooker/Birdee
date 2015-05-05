#include "BdThread.h"

extern "C"
{
	void ThPauseTheWorld()
	{
		BdThread* self=curthread,*th;
		UaEnterLock(&curdvm->thread_lock);
		th=curdvm->mainvm;
		while(th)
		{
			if(th!=self)
				UaSuspendThread(th->tid);
			th=th->next;
		}
		UaLeaveLock(&curdvm->thread_lock);
	}

	void ThResumeTheWorld()
	{
		BdThread* self=curthread,*th;
		UaEnterLock(&curdvm->thread_lock);
		th=curdvm->mainvm;
		while(th)
		{
			if(th!=self)
				UaResumeThread(th->tid);
			th=th->next;
		}
		UaLeaveLock(&curdvm->thread_lock);
	}

	void ThAddThreadToList(BdThread* t)
	{
		UaEnterLock(&curdvm->thread_lock);
		BdThread* head=curdvm->mainvm->next;
		if(head)
			head->prv=t;
		t->next=head;
		t->prv=curdvm->mainvm;
		curdvm->mainvm->next=t;
		UaLeaveLock(&curdvm->thread_lock);
	}

	void ThRemoveThreadFromList(BdThread* t)
	{
		UaEnterLock(&curdvm->thread_lock);
		BdThread* nxt=t->next;
		if(nxt)
			nxt->prv=t->prv;
		t->prv->next=nxt;
		UaLeaveLock(&curdvm->thread_lock);
	}

	void ThStopAllThreads()
	{
		UaEnterLock(&curdvm->thread_lock);
		BdThread* t=curdvm->mainvm->next;
		while(t)
		{
			UaStopThread(t->tid);
			t=t->next;
		}
		UaLeaveLock(&curdvm->thread_lock);
	}

	void ThThreadStub(BdThread* param)
	{

		curthread=param;
		param->stack.stack_pointer->object=param->new_obj;  *param->stack.flg_sp = DVM_TRUE;
		param->stack.stack_pointer ++; param->stack.flg_sp++;
		//param->tid=(void*)UaGetCurrentThread();
		ExInitThreadInAllModules();
		ExDoInvoke(param->main);
		printf("Thread exits. Stack check: %d\n",curthread->stack.stack_pointer-curthread->stack.stack);
		ThRemoveThreadFromList(param);
		ExFreeThread(param);
	}

	void ThCreateThread(DVM_Value* args)
	{
		DVM_ObjectRef del_obj=args[2].object;
		DVM_Boolean run=(DVM_Boolean)args[1].int_value;
		DVM_ObjectRef arg=args[0].object;
		curthread->stack.stack_pointer-=3 ;curthread->stack.flg_sp-=3;
#ifndef BD_ON_GCC
		ExSystemRaise(ExMultiThreadNotSupported);
#endif
		BINT func_idx;
		if(del_obj.data==NULL)
			ExNullPointerException();
		if(del_obj.data->u.delegate.index<0)
			ExSystemRaise(ExBadFunctionIndex);
		if (del_obj.data->u.delegate.object.data==NULL) {
			func_idx = del_obj.data->u.delegate.index;
		} else {
			ExSystemRaise(ExBadFunctionIndex);
		}

		BdThread* th=ExCreateThread();
		th->main=func_idx;
		ThAddThreadToList(th);
		th->tid=UaCreateThread(th,1,arg);
		curthread->retvar.int_value=(BINT)th->tid;
	}


}
