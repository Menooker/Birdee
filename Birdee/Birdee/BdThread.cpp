#include "BdThread.h"
#include "BdSharedObj.h"
#include "BdParameters.h"
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
				UaResumeThread(th->tid,th);
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


//#ifdef BD_ON_WINDOWS
	extern "C" void init_memcached_this_thread();
//#endif

	extern "C" int idx_remote_thread;

	void ThThreadStub(BdThread* param)
	{
//#ifdef BD_ON_WINDOWS
		init_memcached_this_thread();
//#endif
		curthread=param;
        if(param->thread_obj_id)
		{
			if(idx_remote_thread==-1)
				idx_remote_thread  = DVM_search_class(curdvm,"Remote","RemoteThread");
			param->stack.stack_pointer->object.data=(DVM_Object*)param->thread_obj_id;
			param->stack.stack_pointer->object.v_table=curdvm->bclass[idx_remote_thread]->class_table;
			*param->stack.flg_sp = DVM_TRUE;
			param->stack.stack_pointer ++; param->stack.flg_sp++;
		}

		param->stack.stack_pointer->object=param->new_obj;  *param->stack.flg_sp = DVM_TRUE;
		param->stack.stack_pointer ++; param->stack.flg_sp++;


		//param->tid=(void*)UaGetCurrentThread();
		ExInitThreadInAllModules();
		ExDoInvoke(param->main);
		printf("Thread exits. Stack check: %d\n",curthread->stack.stack_pointer-curthread->stack.stack);
		ThRemoveThreadFromList(param);
		if(param->thread_obj_id)
			SoSeti(param->thread_obj_id,1,RC_THREAD_DEAD);
		ExFreeThread(param);
	}

	int ThDoCreateThread(int func,DVM_ObjectRef arg,unsigned int thread_object_id)
	{
        if(curdvm->function[func]->pfun==ExLoadFunction)
            ExDoLoadFunction(func);
		BdThread* th=ExCreateThread();
		th->main=func;
		th->thread_obj_id=thread_object_id;
		ThAddThreadToList(th);
		th->tid=UaCreateThread(th,1,arg);
		return (int)th;
	}

    void ThSuspendThread(DVM_Value* args)
    {
        BdThread* th=(BdThread*)args[0].int_value;
        UaSuspendThread(th->tid);
    }

    void ThResumeThread(DVM_Value* args)
    {
        BdThread* th=(BdThread*)args[0].int_value;
        UaResumeThread(th->tid,th);
    }

	void ThCreateThread(DVM_Value* args)
	{
		DVM_ObjectRef del_obj=args[2].object;
		DVM_Boolean run=(DVM_Boolean)args[1].int_value;
		DVM_ObjectRef arg=args[0].object;
		curthread->stack.stack_pointer-=3 ;curthread->stack.flg_sp-=3;
		if(parameters.debug)
			ExSystemRaise(ExMultiThreadNotSupported);
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
		curthread->retvar.int_value=ThDoCreateThread(func_idx,arg,0);
	}


}
