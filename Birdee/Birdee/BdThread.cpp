#include "BdThread.h"

extern "C"
{

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
		//UaEnterLock(&curdvm->thread_lock);
		BdThread* t=curdvm->mainvm->next;
		while(t)
		{
			UaStopThread(t->tid);
			t=t->next;
		}
		//UaLeaveLock(&curdvm->thread_lock);
	}

	void ThThreadStub(BdThread* param)
	{

		curthread=param;
		//param->tid=(void*)UaGetCurrentThread();
		ExInitThreadInAllModules();
		ExDoInvoke(param->main);
		printf("Thread exits. Stack check: %d\n",curthread->stack.stack_pointer-curthread->stack.stack);
		ThRemoveThreadFromList(param);
		ExFreeThread(param);
	}

	void ThCreateThread()
	{
		DVM_ObjectRef del_obj=(curthread->stack.stack_pointer-1)->object;
		curthread->stack.stack_pointer-- ;curthread->stack.flg_sp--;
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
		th->tid=UaCreateThread(th,1);
		curthread->retvar.int_value=(BINT)th->tid;
	}


}
