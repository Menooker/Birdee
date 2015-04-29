#include "BdThread.h"

extern "C"
{

	void ThAddThreadToList(BdThread* t)
	{//fix-me : @thread lock the curdvm?
		BdThread* head=curdvm->mainvm->next;
		if(head)
			head->prv=t;
		t->next=head;
		t->prv=curdvm->mainvm;
		curdvm->mainvm->next=t;
	}

	void ThRemoveThreadFromList(BdThread* t)
	{//fix-me : @thread lock the curdvm?
		BdThread* nxt=t->next;
		if(nxt)
			nxt->prv=t->prv;
		t->prv->next=nxt;
	}

	void ThThreadStub(BdThread* param)
	{

		curthread=param;
		param->tid=(void*)UaGetCurrentThread();
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
		curthread->retvar.int_value=(BINT)UaCreateThread(th,1);
	}


}