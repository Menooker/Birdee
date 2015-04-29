
#include "BirdeeDef.h"
#include "BdException.h"
#include "BdVarients.h"
#include "UnportableAPI.h"
#include <stdio.h>
#include <string.h>

extern "C"
{
#include "..\..\dvm\dvm_pri.h"
}

//typedef struct DVM_VirtualMachine_tag sDVM_VirtualMachine;
//extern "C" DVM_VirtualMachine_tag *curdvm;

#define BD_FLOOR(a,b) (a/b+ (a%b ? 1:0))
//#define JUMPBUF_CNT (BD_FLOOR(sizeof(ExJumpBuf),sizeof(DVM_Value)))
extern void ExCall(BINT index);
extern "C" void ExDoInvoke(BINT index);

extern "C"
{

	struct TraceParams
	{
		int cls_trace_index;
		int line_number_index;
		int function_name_index;
		int stack_trace_index;
		DVM_Object* stack_trace_array;
	};
extern DVM_ObjectRef AvPrintf(wchar_t* str,...);
void TraceCallBack(void* param,void* ebp,void* retaddr,void* calladdr)
{	
	BINT id=*(int*)((char*)ebp+8);
	if(calladdr==ExDoInvoke)
	{
		//printf("%s!%s\n",curdvm->function[id]->package_name,curdvm->function[id]->name);
		TraceParams* p=(TraceParams*)param; 
		DVM_Object* stack_trace_array=p->stack_trace_array ; 
		int array_size = DVM_array_size(curdvm, stack_trace_array);
		DVM_ObjectRef stack_trace = dvm_create_class_object_i(curdvm, p->cls_trace_index );
		stack_trace.data->u.class_object.field[p->line_number_index].int_value= (int)retaddr;
		stack_trace.data->u.class_object.field[p->function_name_index].object=  AvPrintf(L"%S!%S",curdvm->function[id]->package_name,curdvm->function[id]->name);
		DVM_Value value;
		value.object = stack_trace;
		DVM_array_insert(curdvm, stack_trace_array, array_size, value);
	}
}




void ExStackTrace(DVM_ObjectRef e)
{

    int array_size;
    int file_name_index;

    DVM_Char *wc_str;
    char *func_name;
    int func_name_index;

	TraceParams para;
    para.cls_trace_index  = DVM_search_class(curdvm,
                                   "Exceptions",
                                   DIKSAM_STACK_TRACE_CLASS);

    para.stack_trace_index = DVM_get_field_index(curdvm, e,"stack_trace");
    para.line_number_index  = 0;//DVM_get_field_index(curdvm, stack_trace, "line_number");
	para.function_name_index = 2;
    para.stack_trace_array = e.data->u.class_object.field[para.stack_trace_index].object.data;
	UaStackTrace(TraceCallBack,&para);


/*    file_name_index
        = DVM_get_field_index(dvm, stack_trace, "file_name");
    wc_str = dvm_mbstowcs_alloc(dvm, exe->path);
    stack_trace.data->u.class_object.field[file_name_index].object
        = dvm_create_dvm_string_i(dvm, wc_str);

    func_name_index
        = DVM_get_field_index(dvm, stack_trace, "function_name");
    if (func) {
        func_name = exe->function[func->u.diksam_f.index].name;
    } else {
        func_name = "top level";
    }
    wc_str = dvm_mbstowcs_alloc(dvm, func_name);
    stack_trace.data->u.class_object.field[func_name_index].object
        = dvm_create_dvm_string_i(dvm, wc_str);*/





}


inline ExExceptionItem*  ExTopJumpBuffer()
{
	if(curthread->esp>0)
	{
		return &(curthread->estack[curthread->esp-1]);
	}
	ExUncaughtException();
	return 0;
}
#define ExPopJumpBuffer() do{curthread->esp-=1;if(curthread->esp<0)ExUncaughtException();}while(0)
#define ExEnterTry() setjmp(ExPushJumpBuffer()->buf)

ExJumpBuf*  ExPushJumpBuffer()
{
	PExExceptionItem ret=(PExExceptionItem)&curthread->estack[curthread->esp];
	ret->exe=curthread->current_executable ;
	ret->ths=curthread->ths;
	ret->cur_exception=curthread->current_exception;
	ret->asp=curthread->asp;
	curthread->esp+=1;
	return &ret->jmpbuf;
}

void ExLeaveTry()
{
	ExPopJumpBuffer();
}


int
EXE_search_class(DVM_Executable *dvm, char *package_name, char *name)
{
    int i;

    for (i = 0; i < dvm->class_count; i++) {
        if (dvm_compare_package_name(dvm->class_definition[i].package_name,
                                     package_name)
            && !strcmp(dvm->class_definition[i].name, name)) {
            return i;
        }
    }
    /*dvm_error_i(NULL, NULL, NO_LINE_NUMBER_PC, CLASS_NOT_FOUND_ERR,
                DVM_STRING_MESSAGE_ARGUMENT, "name", name,
                DVM_MESSAGE_ARGUMENT_END);*/
    return -2; /* make compiler happy */
}




DVM_ObjectRef
ExCreateExceptionEx(DVM_VirtualMachine *dvm, char *class_name,BINT* clsindex,
                     RuntimeError id, ...)
{
    int class_index;
    DVM_ObjectRef obj;
    VString     message;
    va_list     ap;
    int message_index;
    int stack_trace_index;

    va_start(ap, id); 
	if(curthread->esp <=0)
	{
		printf("Uncaught exception : %s",class_name);
		_BreakPoint();
	}
	ExecutableEntry * exe=(ExecutableEntry *)ExTopJumpBuffer()->exe ;
    class_index = DVM_search_class(curdvm  , "Exceptions",
                                   class_name);

	//for(int i=0;i<=exe->class_table;
	if(clsindex)
	{
		*clsindex=	EXE_search_class(exe->executable , "Exceptions",class_name);
	}
    obj = dvm_create_class_object_i(dvm, class_index);



    dvm_format_message(dvm_error_message_format, (int)id, &message, ap);
    va_end(ap);

    message_index
        = DVM_get_field_index(dvm, obj, "message");
	if(message_index==FIELD_NOT_FOUND)
	{
		printf("exception field not found in : %s",class_name);
		_BreakPoint();
	}
    obj.data->u.class_object.field[message_index].object
        = dvm_create_dvm_string_i(dvm, message.string);

    stack_trace_index
        = DVM_get_field_index(dvm, obj, "stack_trace");
    obj.data->u.class_object.field[stack_trace_index].object
        = dvm_create_array_object_i(dvm, 0);
	ExStackTrace(obj);

    return obj;
}

void ExNullPointerException()
{
	BINT index;
	curthread->current_exception=ExCreateExceptionEx(curdvm,DVM_NULL_POINTER_EXCEPTION_NAME,&index, NULL_POINTER_ERR, DVM_MESSAGE_ARGUMENT_END);
	ExRaiseException(index+1);
}

extern "C" int ExDoInstanceOf(DVM_ObjectRef* obj,BINT target_idx);
void ExUncaughtException()
{
	printf("UncaughtException %d\n",curthread->exception_index);
	if(curthread->current_exception.data  && ExDoInstanceOf(&curthread->current_exception,DVM_search_class(curdvm,"Exceptions","Exception")))
	{
		printf("%s\n",curthread->current_exception.v_table->exec_class->name );
	}

	_BreakPoint()
	//exit(1);
}

void ExReraiseException()
{

	PExExceptionItem pit=ExTopJumpBuffer();
	curthread->current_executable=(ExecutableEntry*)pit->exe ;
	curthread->ths=pit->ths;
	if(pit->asp>curthread->asp)
	{
		//bad asp
		_BreakPoint()
	}
	while(pit->asp<curthread->asp)
	{
		AvPopContext();
	}
	//curdvm->current_exception =pit->cur_exception;
	ExJumpBuf mybuf=pit->jmpbuf;
	ExPopJumpBuffer();
	longjmp(mybuf.buf ,curthread->exception_index);
}

void ExRaiseException(BINT eindex)
{
	curthread->exception_index=eindex;
	PExExceptionItem pit=ExTopJumpBuffer();
	curthread->current_executable=(ExecutableEntry*)pit->exe ;
	curthread->ths=pit->ths;
	if(pit->asp>curthread->asp)
	{
		//bad asp
		_BreakPoint()
	}
	while(pit->asp<curthread->asp)
	{
		AvPopContext();
	}
	//curdvm->current_exception =pit->cur_exception;
	ExJumpBuf mybuf=pit->jmpbuf;
	ExPopJumpBuffer();
	longjmp(mybuf.buf ,eindex);
}
void ExArrayOutOfBoundException()
{
	BINT eindex;
        curthread->current_exception  = ExCreateExceptionEx(curdvm, ARRAY_INDEX_EXCEPTION_NAME,&eindex,
                                   INDEX_OUT_OF_BOUNDS_ERR,
                                   DVM_INT_MESSAGE_ARGUMENT, "index", -1,
                                   DVM_INT_MESSAGE_ARGUMENT, "size",
                                   0,
                                   DVM_MESSAGE_ARGUMENT_END);
		ExRaiseException(eindex+1);
}

void ExSystemRaise(ExExceptions e)
{
	if(e<ExLastSystemError)
	{
		switch(e)
		{
		case ExNullPointerErr:
			ExNullPointerException();
			break;
		case ExArrayIndexOutOfBoundErr:
			ExArrayOutOfBoundException();
			break;
		}
	}
	_BreakPoint()
}

extern DVM_ErrorDefinition dvm_native_error_message_format[];
void ExRaiseNativeException(DVM_VirtualMachine *dvm, char *package_name, char *class_name, int id, ...)
{

    int class_index;
    DVM_ObjectRef obj;
    VString     message;
    va_list     ap;
    int message_index;
    int stack_trace_index;

    va_start(ap, id); 
	if(curthread->esp <=0)
	{
		printf("Uncaught exception : %s",class_name);
		_BreakPoint();
	}
	ExecutableEntry * exe=(ExecutableEntry *)ExTopJumpBuffer()->exe ;
    class_index = DVM_search_class(curdvm  , "Exceptions",
                                   class_name);

	//for(int i=0;i<=exe->class_table;
	int clsindex;
	clsindex=	EXE_search_class(exe->executable , "Exceptions",class_name);
	
    obj = dvm_create_class_object_i(dvm, class_index);
	curthread->current_exception=obj;


    dvm_format_message(dvm_native_error_message_format, (int)id, &message, ap);
    va_end(ap);

    message_index
        = DVM_get_field_index(dvm, obj, "message");
	if(message_index==FIELD_NOT_FOUND)
	{
		printf("exception field not found in : %s",class_name);
		_BreakPoint();
	}
    obj.data->u.class_object.field[message_index].object
        = dvm_create_dvm_string_i(dvm, message.string);

    stack_trace_index
        = DVM_get_field_index(dvm, obj, "stack_trace");
    obj.data->u.class_object.field[stack_trace_index].object
        = dvm_create_array_object_i(dvm, 0);
	ExStackTrace(obj);

    ExRaiseException(clsindex+1);
}




}