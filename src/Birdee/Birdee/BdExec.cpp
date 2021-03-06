#include "BirdeeDef.h"
#include "BdExec.h"
#include "BdException.h"
#include "BdArrayCache.h"
#include "llvm/Analysis/Passes.h"
#include "llvm/Analysis/Verifier.h"
#include "llvm/ExecutionEngine/ExecutionEngine.h"
#include "llvm/ExecutionEngine/JIT.h"
#include "llvm/IR/DataLayout.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/PassManager.h"
#include "llvm/Support/Host.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Transforms/Scalar.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/Bitcode/ReaderWriter.h"
#include "llvm/Support/MemoryBuffer.h"
#include "llvm/Transforms/Instrumentation.h"
#include "llvm/Transforms/Vectorize.h"
#include "stdarg.h"
#include <setjmp.h>
using namespace llvm;
#include "BdVarients.h"
#include <time.h>
#include <list>
#include "Loader.h"
#include <stdlib.h>
#include <setjmp.h>
#include "BdMCJIT.h"
#include "llvm/Support/DynamicLibrary.h"
#include "BdParameters.h"
#include "llvm/Support/Debug.h"
#ifdef BD_ON_LINUX
#include <sys/time.h>
#endif

llvm::Function* BcBuildFldPtrImp(llvm::Type *);
llvm::Function* BcBuildArrPtrImp(llvm::Type *);
llvm::Function* BcBuildArrPtrSafeImp(llvm::Type *);
llvm::Function* BcBuildPushImp(char* name,int isptr,Type* ty);
llvm::Function* BcBuildPopImp();
llvm::Function* BcBuildRegInit();
llvm::Function* BcBuildObjectRefPtrImp();
void BcSwitchContext(Module* M,Type* t);


extern "C"{
#include "DBG.h"
//#include "DVM.h"
#include "dvm_pri.h"
}

#define _is_pointer_type(type) \
  ((type)->basic_type == DVM_STRING_TYPE \
   || (type)->basic_type == DVM_CLASS_TYPE \
   || (type)->basic_type == DVM_NULL_TYPE \
   || (type)->basic_type == DVM_DELEGATE_TYPE \
   || ((type)->derive_count > 0 \
       && (type)->derive[0].tag == DVM_ARRAY_DERIVE))

//extern "C" DVM_VirtualMachine *curdvm;
extern "C" DVM_ObjectRef chain_string(DVM_VirtualMachine*,DVM_ObjectRef,DVM_ObjectRef);
#define is_null_pointer(obj) (((obj)->data == NULL))

#include "UnportableAPI.h"
#include "BdThread.h"
#include "BdSharedObj.h"
thread_local BdThread* curthread;
thread_local void *_memc;
thread_local int* cur_prep_regs[8]; // current dvm for ExPrepareModule
extern "C"
{
	DVM_VirtualMachine* curdvm;
}

BdVMFunction ExDoLoadFunction(int p1)
{
    DVM_Executable* exe=curdvm->function[p1]->u.diksam_f.executable->executable;
	ExecutableEntry* ee=curdvm->function[p1]->u.diksam_f.executable;
    Module* m=(Module*)exe->module.mod;
	Function* f=m->getFunction(curdvm->function[p1]->u.diksam_f.executable->executable->function[curdvm->function[p1]->u.diksam_f.index].name);
	//FunctionPassManager* pm=(FunctionPassManager*)exe->module.pass;
	//pm->run(*f);
	MCJITHelper* engine=(MCJITHelper*)(curdvm->exe_engine);
	BdVMFunction FPtr =(BdVMFunction) engine->getPointerToFunction(f);
	curdvm->function[p1]->pfun=FPtr;
	return FPtr;
}

extern "C" void ExLoadFunction(void* args,...)
{
	va_list pvar;
	va_start(pvar, args);
	BINT p1=va_arg(pvar, BINT);
	/*if(curdvm->function[p1]->l)
	{

	}*/
	BdVMFunction FPtr =ExDoLoadFunction(p1);
	FPtr(args);
	va_end(pvar);

}

DVM_ObjectRef ExUpCast(BINT index)
{
			DVM_ObjectRef obj=(curthread->stack.stack_pointer-1)->object;
			DVM_ObjectRef ret=obj;
			curthread->stack.stack_pointer-- ;curthread->stack.flg_sp--;
	        if (is_null_pointer(&obj)) {
                ExNullPointerException();
            } else {
                ret.v_table
                    = obj.v_table->exec_class->interface_v_table[index];
            }
			return ret;
}



DVM_Boolean
ExInstanceofImp(DVM_VirtualMachine *dvm, DVM_ObjectRef *obj,
                   int target_idx,
                   DVM_Boolean *is_interface, int *interface_idx)
{
    ExecClass *pos;
    int i;

    for (pos = obj->v_table->exec_class->super_class; pos;
         pos = pos->super_class) {
        if (pos->class_index == target_idx) {
            *is_interface = DVM_FALSE;
            return DVM_TRUE;
        }
    }

    for (i = 0; i < obj->v_table->exec_class->interface_count; i++) {
        if (obj->v_table->exec_class->binterface[i]->class_index
            == target_idx) {
            *is_interface = DVM_TRUE;
            *interface_idx = i;
            return DVM_TRUE;
        }
    }
    return DVM_FALSE;
}


DVM_ErrorStatus
ExCheckDownCast(DVM_VirtualMachine *dvm, DVM_ObjectRef *obj, int target_idx,
                DVM_Boolean *is_same_class,
                DVM_Boolean *is_interface, int *interface_index)
{
	if(obj->data->type!=CLASS_OBJECT)
		return DVM_ERROR;
    if (obj->v_table->exec_class->class_index == target_idx) {
        *is_same_class = DVM_TRUE;
        return DVM_SUCCESS;
    }
    *is_same_class = DVM_FALSE;

    if (!ExInstanceofImp(dvm, obj, target_idx,
                            is_interface, interface_index)) {
        return DVM_ERROR;
    }

    return DVM_SUCCESS;
}

void ExDownCast(BINT index)
{
			DVM_ObjectRef obj=(curthread->stack.stack_pointer-1)->object;
			curthread->stack.stack_pointer-- ;curthread->stack.flg_sp--;

            DVM_Boolean is_same_class;
            DVM_Boolean is_interface;
            int interface_idx;
            DVM_ErrorStatus status;
			int classid;
            do {
                if (is_null_pointer(&obj)) {
                    ExNullPointerException();
                }
                status = ExCheckDownCast(curdvm, &obj, index,
                                         &is_same_class,
                                         &is_interface, &interface_idx);
                if (status != DVM_SUCCESS) {
					char* name;
					if(obj.data->type==CLASS_OBJECT)
						name=obj.v_table->exec_class->name;
					else
						name="BuiltInObject";
                    curthread->current_exception= ExCreateExceptionEx(curdvm,
                                               CLASS_CAST_EXCEPTION_NAME,
											   &classid,
                                               CLASS_CAST_ERR,
                                               DVM_STRING_MESSAGE_ARGUMENT,
                                               "org",
                                               name,
                                               DVM_STRING_MESSAGE_ARGUMENT,
                                               "target",
											   curdvm->bclass[curthread->current_executable->class_table[index]]->name,
                                               DVM_MESSAGE_ARGUMENT_END);
                    ExRaiseException(classid+1);
                    break;
                }
                if (!is_same_class) {
                    if (is_interface) {
                        obj.v_table
                            = obj.v_table->exec_class
                            ->interface_v_table[interface_idx];
                    } else {
                        obj.v_table = obj.v_table->exec_class->class_table;
                    }
                }

            } while (0);
			curthread->retvar.object= obj;
}

void ExGetSuper()
{
			DVM_ObjectRef obj=(curthread->stack.stack_pointer-1)->object;
			curthread->stack.stack_pointer-- ;curthread->stack.flg_sp--;
	        ExecClass *this_class;
            DVM_ObjectRef ret;
            this_class = obj.v_table->exec_class;
			ret.data=obj.data;
            ret.v_table = this_class->super_class->class_table;
			curthread->retvar.object= ret;
}

void ExArraySize(DVM_Value *args)
{
    DVM_Object *barray;
    barray = args->object.data ;
    DBG_assert(barray->type == ARRAY_OBJECT, ("barray->type..%d", barray->type));

    curthread->retvar.int_value = barray->u.barray.size;

}
void ExStringLength(DVM_Value *args)
{
    DVM_Object *barray;
    barray = args->object.data ;
    DBG_assert(barray->type == STRING_OBJECT, ("barray->type..%d", barray->type));
    curthread->retvar.int_value = barray->u.string.length;

}

BINT BKDRHash(char *str,size_t len)
{
    size_t hash = 0;
	for(_uint i=0;i<len; i++,str++)
    {
		size_t ch=*str;
        hash = hash * 131 + ch;
    }
    return hash;
}


void ExObjectHash(DVM_Value *args)
{
    DVM_Object *barray;
    barray = args->object.data ;
    DBG_assert(barray->type == CLASS_OBJECT, ("barray->type..%d", barray->type));
	curthread->retvar.int_value= BKDRHash((char*)barray->u.class_object.field,barray->u.class_object.field_count * sizeof(barray->u.class_object.field[0]));
}

void ExObjectEquals(DVM_Value *args) //fix-me : add null check to all these functions
{
    DVM_Object *bobj, *bthis;
    bobj = args->object.data ;
	bthis = args[1].object.data ;
    DBG_assert(bthis->type == CLASS_OBJECT, ("bthis->type..%d", bthis->type));
	if(bobj->type != CLASS_OBJECT || args[1].object.v_table->exec_class != args->object.v_table->exec_class)
	{
		curthread->retvar.int_value=DVM_FALSE;
		return;
	}

	curthread->retvar.int_value = memcmp(bthis->u.class_object.field,
		bobj->u.class_object.field,bthis->u.class_object.field_count * sizeof(bthis->u.class_object.field[0]))?DVM_FALSE:DVM_TRUE;
}

void ExObjectTostr(DVM_Value *args)
{
    DVM_Object  *bthis;
    bthis = args->object.data ;
    DBG_assert(bthis->type == CLASS_OBJECT, ("bthis->type..%d", bthis->type));

	char buf[LINE_BUF_SIZE];
    DVM_Char *wc_str;
    sprintf(buf, "Object@%x", bthis); //fix-me : unsafe
    wc_str = dvm_mbstowcs_alloc(curthread, buf);
	curthread->retvar.object =  dvm_create_dvm_string_i(curdvm, wc_str);
}


BINT ExGetArrayTypeSize(DVM_ArrayType type)
{
	BINT size;
	switch(type)
	{
	case INT_ARRAY :
	case FUNCTION_INDEX_ARRAY:
		size=sizeof(BINT);
		break;
	case DOUBLE_ARRAY:
		size=sizeof(double);
		break;
	case OBJECT_ARRAY:
	case VARIENT_ARRAY:
		size=sizeof(DVM_ObjectRef);
		break;
	default:
		size=0;
	}
	return size;
}

void ExExp(DVM_Value *args)
{
	curthread->retvar.double_value=exp(args->double_value);
}

void ExSqrt(DVM_Value *args)
{
	curthread->retvar.double_value=sqrt(args->double_value);
}

void ExCSVReaderReadDouble(DVM_Value *args)
{
	DVM_ObjectRef ths=args[0].object;
	FILE* f=(FILE*)ths.data->u.class_object.field[1].int_value;
	double ret;
	fscanf(f,"%lf",&ret);
	curthread->retvar.double_value=ret;
}

void ExCSVReaderInit(DVM_Value *args)
{
	DVM_ObjectRef ths=args[1].object;
	ths.data->u.class_object.field[0].object=args[0].object;
	char buf[255];
	char* str;
	wcstombs(buf,args[0].object.data->u.string.string,255);
	if(args[0].object.data->u.string.length>=254)
		printf("Warning : file name %ws too long\n",args[0].object.data->u.string.string);
	if(buf[0]==-17 && buf[1]==-69 && buf[2]==-65)
		str=buf+3;
    else
		str=buf;
	FILE* f=fopen(str,"r");
	if(!f)
		printf("Warning : Failed to open %s\n",str);
	ths.data->u.class_object.field[1].int_value=(int)f;
}

void ExCSVReaderReadLine(DVM_Value *args)
{
	DVM_ObjectRef ths=args[2].object;
	DVM_ObjectRef arr=args[1].object;
	int idx=args[0].int_value;
	int len=arr.data->u.barray.size;
	double* parr=arr.data->u.barray.u.double_array;
	FILE* f=(FILE*)ths.data->u.class_object.field[1].int_value;
	if(f==NULL)
	{
		curthread->retvar.int_value=-1;
		return;
	}
	char buf[2048];
	int cnt=0;
	buf[0]=0;
	char* st;
	_uint lagacy=0;
	char* last;
	for(;;)
	{
		st=buf+lagacy;
		fgets(st,2048-lagacy,f);
		char *p=st;
		last=buf;
		while(*p)
		{
			if(*p==',')
			{
				*p=0;
				if(idx+cnt>len)
				{
					curthread->retvar.int_value=-1;
					return;
				}
				parr[idx+cnt]=atof(last);
				cnt++;
				last=p+1;
			}
			p++;
		}
		if(p<=buf || *(p-1)=='\n' || feof(f))
		{
			break;
		}
		lagacy=2047-(last-buf);
		memmove(buf,last,lagacy);
	}
	if(idx+cnt>len)
	{
		curthread->retvar.int_value=-1;
		return;
	}
	parr[idx+cnt]=atof(last);
	cnt++;
	curthread->retvar.int_value=cnt;
}


void ExCSVReaderReadLineString(DVM_Value *args)
{
	DVM_ObjectRef ths=args[2].object;
	DVM_ObjectRef arr=args[1].object;
	int idx=args[0].int_value;
	int len=arr.data->u.barray.size;
	DVM_ObjectRef* parr=arr.data->u.barray.u.object;
	FILE* f=(FILE*)ths.data->u.class_object.field[1].int_value;
	if(f==NULL)
	{
		curthread->retvar.int_value=-1;
		return;
	}
	wchar_t buf[2048];
	int cnt=0;
	buf[0]=0;
	wchar_t* st;
	_uint lagacy=0;
	wchar_t* last;
	for(;;)
	{
		st=buf+lagacy;
		fgetws(st,2048-lagacy,f);
		wchar_t *p=st;
		last=buf;
		while(*p)
		{
			if(*p==',')
			{
				*p=0;
				if(idx+cnt>len)
				{
					curthread->retvar.int_value=-1;
					return;
				}
				DVM_Char* newbuf=(DVM_Char*)MEM_malloc(sizeof(DVM_Char)*(wcslen(last)+1));
				wcscpy(newbuf,last);
				parr[idx+cnt]=dvm_create_dvm_string_i(curdvm,newbuf);
				cnt++;
				last=p+1;
			}
			p++;
		}
		if(p<=buf || *(p-1)=='\n' || feof(f))
		{
			break;
		}
		lagacy=2047-(last-buf);
		memmove(buf,last,lagacy*sizeof(wchar_t));
	}
	if(idx+cnt>len)
	{
		curthread->retvar.int_value=-1;
		return;
	}
	DVM_Char* newbuf=(DVM_Char*)MEM_malloc(sizeof(DVM_Char)*(wcslen(last)+1));
	wcscpy(newbuf,last);
	parr[idx+cnt]=dvm_create_dvm_string_i(curdvm,newbuf);
	cnt++;
	curthread->retvar.int_value=cnt;
}

void ExCSVReaderSkip(DVM_Value *args)
{
	DVM_ObjectRef ths=args[1].object;
	int lines=args[0].int_value;
	FILE* f=(FILE*)ths.data->u.class_object.field[1].int_value;
	if(f==NULL)
	{
		curthread->retvar.int_value=-1;
		return;
	}
	char buf[2048];
	buf[0]=0;
	for(int i=0;i<lines;i++)
	{
		for(;;)
		{
			buf[2046]=0;
			fgets(buf,2048,f);
			if(feof(f) || buf[2046]==0 || buf[2046]=='\n')
				break;
		}
	}

}

void ExCSVReaderClose(DVM_Value *args)
{
	DVM_ObjectRef ths=args[0].object;
	FILE* f=(FILE*)ths.data->u.class_object.field[1].int_value;
	if(f)
		fclose(f);
	ths.data->u.class_object.field[1].int_value=0;
}

void ExCSVReaderReset(DVM_Value *args)
{
	DVM_ObjectRef ths=args[0].object;
	FILE* f=(FILE*)ths.data->u.class_object.field[1].int_value;
	if(f)
		rewind(f);
	ths.data->u.class_object.field[1].int_value=0;
}

void ExArrayHash(DVM_Value *args)
{
    DVM_Object *barray;
    barray = args->object.data ;
    DBG_assert(barray->type == ARRAY_OBJECT, ("barray->type..%d", barray->type));
	BINT size=ExGetArrayTypeSize(barray->u.barray.type);
	curthread->retvar.int_value= BKDRHash((char*)barray->u.barray.u.double_array ,barray->u.barray.size * size);
}

void ExArrayEquals(DVM_Value *args)
{
    DVM_Object *bobj, *bthis;
    bobj = args->object.data ;
    if(bobj->type != ARRAY_OBJECT)
	{
		curthread->retvar.int_value=DVM_FALSE;
		return;
	}
    bthis = args[1].object.data ;
    DBG_assert(bthis->type == ARRAY_OBJECT, ("bthis->type..%d", bthis->type));
	if(bobj->u.barray.type==bthis->u.barray.type && bobj->u.barray.size==bthis->u.barray.size)
	{
		BINT size=ExGetArrayTypeSize(bobj->u.barray.type);
		curthread->retvar.int_value = memcmp(bobj->u.barray.u.double_array,bthis->u.barray.u.double_array,size*bobj->u.barray.size)?DVM_FALSE:DVM_TRUE;
	}
	else
		curthread->retvar.int_value =DVM_FALSE;
}

void ExArrayTostr(DVM_Value *args)
{
    DVM_Object  *bthis;
    bthis = args->object.data ;
    DBG_assert(bthis->type == ARRAY_OBJECT, ("bthis->type..%d", bthis->type));

	char buf[LINE_BUF_SIZE];
    DVM_Char *wc_str;
    sprintf(buf, "Array@%x", bthis); //improve-me : print the contents
    wc_str = dvm_mbstowcs_alloc(curthread, buf);
	curthread->retvar.object =  dvm_create_dvm_string_i(curdvm, wc_str);
}


void ExStringHash(DVM_Value *args)
{
    DVM_Object *barray;
    barray = args->object.data ;
    DBG_assert(barray->type == STRING_OBJECT, ("barray->type..%d", barray->type));
	curthread->retvar.int_value= BKDRHash((char*)barray->u.string.string,barray->u.string.length * sizeof(barray->u.string.string[0]));
}

void ExStringEquals(DVM_Value *args)
{
    DVM_Object *bobj, *bthis;
    bobj = args->object.data ;
    if(bobj->type != STRING_OBJECT)
	{
		curthread->retvar.int_value=DVM_FALSE;
		return;
	}
    bthis = args[1].object.data ;
    DBG_assert(bthis->type == STRING_OBJECT, ("bthis->type..%d", bthis->type));
	curthread->retvar.int_value = dvm_wcscmp(bthis->u.string.string,bobj->u.string.string)?DVM_FALSE:DVM_TRUE;
}

void ExStringTostr(DVM_Value *args)
{
    DVM_Object  *bthis;
    bthis = args->object.data ;
    DBG_assert(bthis->type == STRING_OBJECT, ("bthis->type..%d", bthis->type));
	curthread->retvar = *args;
}

void ExStringSubstr(DVM_Value *args)
{
	DVM_Value ret={0};
    DVM_Object *str;
    int pos;
    int len;
    int org_len;

    pos = args[1].int_value;
    len = args[0].int_value;
    str = args[2].object.data;
    DBG_assert(str->type == STRING_OBJECT,
               ("str->type..%d", str->type));

    org_len = DVM_string_length(curdvm, str);

    if (pos < 0 || pos >= org_len) {
        ExRaiseNativeException(curdvm,
                          DVM_DIKSAM_DEFAULT_PACKAGE,
                          STRING_INDEX_EXCEPTION_NAME,
                          STRING_POS_OUT_OF_BOUNDS_ERR,
                          DVM_INT_MESSAGE_ARGUMENT, "len", org_len,
                          DVM_INT_MESSAGE_ARGUMENT, "pos", pos,
                          DVM_MESSAGE_ARGUMENT_END);
        curthread->retvar.object=dvm_null_object_ref;
		return;
    }
    if (len < 0 || pos + len > org_len) {
        ExRaiseNativeException(curdvm,
                          DVM_DIKSAM_DEFAULT_PACKAGE,
                          STRING_INDEX_EXCEPTION_NAME,
                          STRING_SUBSTR_LEN_ERR,
                          DVM_INT_MESSAGE_ARGUMENT, "len", len,
                          DVM_MESSAGE_ARGUMENT_END);
		curthread->retvar.object=dvm_null_object_ref;
        return;
    }
    curthread->retvar = DVM_string_substr(curdvm, str, pos, len);
}

DVM_Char inputbuffer[255];
void ExGets()
{
	fgetws(inputbuffer,sizeof(inputbuffer)/sizeof(DVM_Char),stdin);
	DVM_Char* buf=(DVM_Char*)MEM_malloc(sizeof(DVM_Char)*(wcslen(inputbuffer)+1));
	wcscpy(buf,inputbuffer);
	curthread->retvar.object= dvm_create_dvm_string_i(curdvm,buf);
}

void ExLoadStringFromPool(BINT index)
{
	DVM_Executable* exe=curthread->current_executable->executable;
	DVM_ObjectRef ret;
    ret= dvm_literal_to_dvm_string_i(curdvm,exe->constant_pool[index].u.c_string);
    curthread->retvar.object=ret;
	return ;
}
void ExChainString()
{
	DVM_Value* sp=curthread->stack.stack_pointer-1;
	DVM_ObjectRef ret= chain_string(curdvm,(sp-1)->object,sp->object);
	curthread->stack.stack_pointer-=2 ;curthread->stack.flg_sp-=2;
	curthread->retvar.object=ret;
	return ;
}

BINT ExCompareString()
{
	DVM_Value* sp=curthread->stack.stack_pointer-1;
	BINT ret= dvm_wcscmp((sp-1)->object.data->u.string.string,sp->object.data->u.string.string);
	curthread->stack.stack_pointer-=2 ;curthread->stack.flg_sp-=2;
	return ret;
}

BINT ExCompareObject() //fix-me : there is another cmp after this call. May improve efficiency
{
	DVM_Value* sp=curthread->stack.stack_pointer-1;
	BINT ret=((sp-1)->object.data!=sp->object.data);
	return ret; //check-me
}

void ExBoolToStr(BINT v)
{
	curthread->retvar.object= dvm_literal_to_dvm_string_i(curdvm,(DVM_Char*) (v ? TRUE_STRING: FALSE_STRING));
}

void ExIntToStr(BINT v)
{
    char buf[LINE_BUF_SIZE];
    DVM_Char *wc_str;
    sprintf(buf, "%d", v);
    wc_str = dvm_mbstowcs_alloc(curthread, buf);
    curthread->retvar.object= dvm_create_dvm_string_i(curdvm, wc_str);
}

void ExDoubleToStr(double v)
{
    char buf[LINE_BUF_SIZE];
    DVM_Char *wc_str;
    sprintf(buf, "%lf", v);
    wc_str = dvm_mbstowcs_alloc(curthread, buf);
    curthread->retvar.object= dvm_create_dvm_string_i(curdvm, wc_str);
}

void ExNewDelegate(BINT index)
{
            int dvm_index;
            DVM_ObjectRef mdelegate;

            dvm_index = index==-1?-1:curthread->current_executable->function_table[index];
            mdelegate = dvm_create_delegate(curdvm, dvm_null_object_ref,
                                           dvm_index);
			curthread->retvar.object= mdelegate;
}

void BcInitLocalVar(BdThread *dvm,DVM_VirtualMachine* vm,BFunction *func, int from_sp)
{
    int i;
    int sp_idx;

	for (i = 0, sp_idx = from_sp; i < func->local_cnt;
         i++, sp_idx++) {
        dvm->stack.pointer_flags[sp_idx] = DVM_FALSE;
    }

    for (i = 0, sp_idx = from_sp; i < func->local_cnt;
         i++, sp_idx++) {
        dvm_initialize_value(vm,func->localvars[i].type,
                             &dvm->stack.stack[sp_idx]);
		if (_is_pointer_type(func->localvars[i].type)) {
            dvm->stack.pointer_flags[sp_idx] = DVM_TRUE;
        }
    }
}


int SafeStrcmp(char* a,char* b)
{
	if(!a)
	{
		if(!b)
			return 0;
		if(b)
			return 1;
	}
	if(!b)
	{
		return 1;
	}
	return strcmp(a,b);
}

BINT ExFindFunctionByName(char* mod,char* fun)
{
	int i;
	if(!mod)
		mod=curdvm->top_level->executable->package_name;
	for(i=0;i<curdvm->function_count;i++)
	{
		if(!SafeStrcmp(curdvm->function[i]->package_name ,mod) && !strcmp(curdvm->function[i]->name  ,fun))
			return i;
	}
	return -1;
}

char* ExConvertAndAllocWchar(wchar_t* WStr)
{

		return dvm_wcstombs_alloc(WStr);
}




void ExGetClock(DVM_Value* v)
{
#ifdef BD_ON_WINDOWS
	curthread->retvar.int_value=clock()/(CLOCKS_PER_SEC/1000);
#else
    struct timeval t;
    gettimeofday(&t,NULL);
    curthread->retvar.int_value=t.tv_sec*1000+t.tv_usec/1000;
#endif
}






extern "C" void  ExDoInvoke(BINT transindex)
{
	DVM_Value* oldsp=curthread->stack.stack_pointer;
	DVM_Boolean* old_arrsp=curthread->stack.flg_sp;
	DVM_Value* base;
	BFunction* bf=curdvm->function[transindex];
	//DVM_Function* df=&bf->u.diksam_f.executable->executable->function[bf->u.diksam_f.index];

	if (!bf->is_implemented) {

		_BreakPoint

    }
	//dvm_expand_stack(curdvm,bf->local_cnt);

	base=oldsp - bf->param_cnt-(int)bf->is_method;
	ExecutableEntry * ee=curthread->current_executable;
    if(bf->u.diksam_f.executable)
		curthread->current_executable = bf->u.diksam_f.executable;


	curthread->stack.stack_pointer += bf->local_cnt ;	curthread->stack.flg_sp+=bf->local_cnt ;
    BcInitLocalVar(curthread,curdvm, bf,((char*)oldsp-(char*)curthread->stack.stack)/sizeof(DVM_Value));
	AvPushNullContext();
	bf->pfun(base,transindex);
	AvPopContext();
	curthread->stack.stack_pointer=base; curthread->stack.flg_sp=old_arrsp - bf->param_cnt-(int)bf->is_method;
	curthread->current_executable=ee;
}


int ExGetStackType(int index)
{
	if(curthread->stack.pointer_flags[index])
	{
		if(curthread->stack.stack[index].object.data==NULL)
			return ExTypeNull;
		return curthread->stack.stack[index].object.data->type - STRING_OBJECT + ExTypeString;
	}
	else
		return ExTypeNum;
}

int GetExType(DVM_TypeSpecifier *type)
{
    if (type->derive != NULL && type->derive_count>0) {
        DBG_assert(type->derive->tag = DVM_ARRAY_DERIVE,
                   ("type->derive->tag..%d", type->derive->tag));
        return ExTypeArray;
    }

    switch (type->basic_type) {
    case DVM_VOID_TYPE:
        DBG_assert(0, ("basic_type is void"));
        break;
    case DVM_BOOLEAN_TYPE: /* FALLTHRU */
    case DVM_INT_TYPE: /* FALLTHRU */
    case DVM_ENUM_TYPE:
        return ExTypeNum;
        break;
    case DVM_DOUBLE_TYPE:
        return ExTypeNum;
        break;
    case DVM_STRING_TYPE:
		return ExTypeString;
		break;
	case DVM_VARIENT_TYPE:
		return ExTypeAutoVar;
		break;
    case DVM_NATIVE_POINTER_TYPE: /* FALLTHRU */
		return ExTypePtr;
    case DVM_CLASS_TYPE: /* FALLTHRU */
		return ExTypeClsObj;
    case DVM_DELEGATE_TYPE: /* FALLTHRU */
        return ExTypeDelegate;;
        break;
    case DVM_NULL_TYPE: /* FALLTHRU */
        return ExTypeNull;
        break;
    case DVM_BASE_TYPE: /* FALLTHRU */
    case DVM_UNSPECIFIED_IDENTIFIER_TYPE: /* FALLTHRU */
    default:
        DBG_assert(0, ("basic_type..%d", type->basic_type));
    }

    return 0;
}


/*
// returns the Basic type of the Array and writes the deepth of the array to pdeepth
int ExGetArrayTypeFromValue(DVM_Value* v,int* pdeepth)
{
	*pdeepth=0;
	DVM_Object* obj=v->object.data;
	while(obj->type==ARRAY_OBJECT) //if the current value is an array
	{
		*pdeepth++;
		if(obj->u.barray.type==OBJECT_ARRAY)
		{
			obj
		}
	}
}*/

//checks if the arguments in the stack is compatable with the parameters
// returns 1 for ok , 0 for incompatable
int ExCheckArgument(int index,DVM_Value* v)
{
	int base=((unsigned)v-(unsigned)curthread->stack.stack)/sizeof(DVM_Value);
	int ta,tp;
	BFunction* bf=curdvm->function[index];
	if(curthread->bpc < bf->param_cnt)
		ExSystemRaise(ExBadParameterNum);
	for(int i=0;i<bf->param_cnt;i++)
	{
		ta=ExGetStackType(base-i-1);
		tp=GetExType(bf->params[i].type);
		if(ta==tp)
		{
			if(ta==ExTypeArray)
			{
				//if(v[-i-1].object.data->u.barray.type
			}
			continue; //fix-me : check array type
		}
		if(ta==ExTypeNull)
		{
			if (tp==ExTypeNum || tp==ExTypeAutoVar)
				return 0;
			continue;
		}
		return 0;

	}
	return 1;
	//GetExType(bf->params->type)
}

void  ExGetFunction(DVM_Value* v)
{
	if( !is_null_pointer(&(v)->object) && (v)->object.data->type==STRING_OBJECT)
	{
		int popnum=0;
		char* mod;
		if(is_null_pointer(&(v+1)->object))
			mod=0;
		else if((v+1)->object.data->type==STRING_OBJECT )
			mod=ExConvertAndAllocWchar((v+1)->object.data->u.string.string);
		else
			ExSystemRaise(ExBadParameterType);
		char* fun=ExConvertAndAllocWchar((v)->object.data->u.string.string);
		#ifdef BD_ON_LINUX
		int index=ExFindFunctionByName(mod+3,fun+3);
		#else
		int index=ExFindFunctionByName(mod,fun);
		#endif
		if(mod)
			free(mod);
		free(fun);
		if(index==-1)
			ExSystemRaise(ExFunctionNotFound);
        if(is_null_pointer(&(v+2)->object))
			ExNullPointerException();
		(v+2)->object.data->u.delegate.index=index;//fix-me : check arguments
	}
	else
	{
		ExSystemRaise(ExBadParameterType);
	}
}

void  ExSleep(DVM_Value* v)
{
	UaSleep(v->int_value);
}
void  ExRand(DVM_Value* v)
{
	curthread->retvar.int_value=rand() % v->int_value ;
}

void  ExInvokeByName(DVM_Value* v)
{
	if( !is_null_pointer(&(v)->object) && (v)->object.data->type==STRING_OBJECT)
	{
		int bpc,popnum=0;
		char* mod=0;
		if(is_null_pointer(&(v+1)->object))
			mod=0;
		else if((v+1)->object.data->type==STRING_OBJECT )
			mod=ExConvertAndAllocWchar((v+1)->object.data->u.string.string);
		else
			ExSystemRaise(ExBadParameterType);
		char* fun=ExConvertAndAllocWchar((v)->object.data->u.string.string);
		int index=ExFindFunctionByName(mod,fun);
		if(mod)
			free(mod);
		free(fun);
		if(index==-1)
			ExSystemRaise(ExFunctionNotFound);
		if(!ExCheckArgument(index,v))
			ExSystemRaise(ExBadParameterNum);

		bpc=curthread->bpc;
		if(curdvm->function[index]->param_cnt != bpc)
		{
			popnum=bpc-curdvm->function[index]->param_cnt;
			curthread->bpc=popnum;
		}
		DVM_Value* oldsp=curthread->stack.stack_pointer;
		DVM_Boolean* flgsp=curthread->stack.flg_sp;
		int base=((unsigned)v-(unsigned)curthread->stack.stack)/sizeof(DVM_Value);
		curthread->stack.stack_pointer+= bpc; curthread->stack.flg_sp+=bpc;
		for(int i=0;i<bpc;i++)
		{
			*(oldsp+i)=v[i-bpc];
			*(flgsp+i)=curthread->stack.pointer_flags[base+i-bpc];
		}
		ExDoInvoke(index);
		if(popnum)
		{
			curthread->stack.stack_pointer-=popnum;curthread->stack.flg_sp-=popnum;
		}
	}
	else
	{
		ExSystemRaise(ExBadParameterType);
	}
}


void ExInvoke(BINT index)
{

	int transindex=curthread->current_executable->function_table[index];
	ExDoInvoke(transindex);
}
void ExCall(BINT index)
{
	int rindex=0;
	DVM_ObjectRef obj = (curthread->stack.stack_pointer-1)->object ;
            if (is_null_pointer(&obj)) {
                ExNullPointerException();

            } else {
				rindex=obj.v_table->table[index].index;
                ExDoInvoke(rindex);
            }
}

void ExRegisterNativeFunction(char* name,void* func,int argc,DVM_Boolean is_method)
{
	DVM_add_native_function(curdvm,"Native",name,(BdVMFunction)func,argc,is_method);
}
#ifdef BD_ON_LINUX
#include <dlfcn.h>
#endif
typedef int (*InitFunc)(void*);
void ExLoadNativeLibrary(DVM_Value* v)
{
	char path[255];
	char* mypath;
	wcstombs(path,v->object.data->u.string.string,255);
	if(v->object.data->u.string.length>=254)
			printf("Warning : Lib path %ws too long\n",v->object.data->u.string.string);
    if(path[0]==-17 && path[1]==-69 && path[2]==-65)
        mypath=path+3;
    else
        mypath=path;
	int success;
	#ifndef BD_ON_LINUX
	llvm::sys::DynamicLibrary lib=llvm::sys::DynamicLibrary::getPermanentLibrary(path);
	success=lib.isValid();
	#else
	void* handle = dlopen(mypath, RTLD_LAZY);
	success= (handle!=NULL);
	#endif

	if(success)
	{
    	#ifndef BD_ON_LINUX
		InitFunc func=(InitFunc)lib.getAddressOfSymbol("BirdeeLibInit");
		#else
		InitFunc func=(InitFunc)dlsym(handle, "BirdeeLibInit");
		#endif
		if(func)
			success= !func((void*)ExRegisterNativeFunction);
		else
			success=0;
	}
	curthread->retvar.int_value=success;
}

extern "C" void ExInitExeEngine()
{

	InitializeNativeTarget();
	InitializeNativeTargetAsmPrinter();
	InitializeNativeTargetAsmParser();
	//DebugFlag=true;
	//setCurrentDebugType("loop-vectorize");
}


extern "C" BdThread* ExCreateThread()
{
	BdThread* th=(BdThread*)MEM_malloc(sizeof(BdThread));
    th->stack.alloc_size = sizeof(DVM_Value) * (STACK_ALLOC_SIZE);
    th->stack.stack =(DVM_Value*) UaGuardAlloc(sizeof(DVM_Value) * (STACK_ALLOC_SIZE));//MEM_malloc(sizeof(DVM_Value) * (STACK_ALLOC_SIZE+2));//modified
	th->stack.stack_pointer=th->stack.stack;
	th->esp=0;
	th->estack=(PExExceptionItem)UaGuardAlloc(sizeof(ExExceptionItem)*1024);
	th->e_alloc_size=sizeof(ExExceptionItem)*1024;
	th->asp=0;
	th->avstack=(AutoVarContext*)UaGuardAlloc(sizeof(AutoVarContext)*1024);
	th->av_alloc_size=sizeof(AutoVarContext)*1024;
    th->stack.pointer_flags=(DVM_Boolean*) MEM_malloc(sizeof(DVM_Boolean) * STACK_ALLOC_SIZE);
	th->stack.flg_sp=th->stack.pointer_flags;

    th->current_executable = NULL;
    th->current_exception = dvm_null_object_ref;
	th->new_obj=dvm_null_object_ref;
	th->main=NULL;
	th->next=NULL;
	th->tid=NULL;
	th->prv=NULL;
	th->thread_obj_id=0;
#ifdef BD_ON_LINUX
    sem_init(&th->suspend_lock,0,0);
	th->prepared=0;
#endif
	UaInitEvent(&th->remote_event,0);
	return th;
}

extern "C" BdThread* ExFreeThread(BdThread* t)
{
	UaGuardFree(t->stack.stack,t->stack.alloc_size);
	UaGuardFree(t->avstack,t->av_alloc_size);
	UaGuardFree(t->estack,t->e_alloc_size);
    MEM_free(t->stack.pointer_flags);
#ifdef BD_ON_LINUX
    sem_destroy(&t->suspend_lock);
#endif
	UaKillEvent(&t->remote_event);
	UaCloseThread(t->tid);
	BdThread* r=t->next;
	MEM_free(t);
	return r;
}

extern "C" void ExSetCurrentDVM(DVM_VirtualMachine *dvm)
{
	UaSetCurVM(dvm);
	curthread=dvm->mainvm;
	//curdvm=dvm;
}

extern "C" void ExCallInit()
{
	int fn=dvm_search_function(curdvm,curdvm->top_level->executable->package_name,"RemoteInitialize" );
	if(fn==FUNCTION_NOT_FOUND)
		return;
	if(curdvm->function[fn]->param_cnt!=0)
	{
		printf("Bad signature of function \'RemoteInitialize\'\n");
		return;
	}
    UaPrepareThread();
	DVM_Executable* exe=curdvm->top_level->executable;
	curthread->current_executable =curdvm->top_level;
	AvPushNullContext();
	MCJITHelper* eng =(MCJITHelper*)curdvm->exe_engine;
	Module* m=(Module*)exe->module.mod;
	BdVMFunction FPtr =(BdVMFunction) eng->getPointerToFunction(m->getFunction("RemoteInitialize"));
	if(FPtr)
		FPtr(curthread->stack.stack);
}


void ExSetArgs()
{
	DVM_ObjectRef arr=dvm_create_array_object_i(curdvm,parameters.argc);
	for(int i=0;i<parameters.argc;i++)
	{
		DVM_Char* wc_str = dvm_mbstowcs_alloc(curthread, parameters.argv[i]);
		arr.data->u.barray.u.object[i]= dvm_create_dvm_string_i(curdvm,wc_str);
	}
	for(ExecutableEntry* lst=curdvm->executable_entry;lst!=NULL;lst=lst->next)
	{
		if(!strcmp(lst->executable->package_name,"diksam.lang"))
		{
			lst->static_v.variable[0].object=arr; //the args is hard coded as the first global variable of the built-in module
			break;
		}
	}
}

extern "C" void ExGoMain()
{
    UaPrepareThread();
	srand((unsigned)time(NULL));
	DVM_Executable* exe=curdvm->top_level->executable;
	curthread->current_executable =curdvm->top_level;
	AvPushNullContext();
	ExSetArgs();
	MCJITHelper* eng =(MCJITHelper*)curdvm->exe_engine;
	Module* m=(Module*)exe->module.mod;
	BdVMFunction FPtr =(BdVMFunction) eng->getPointerToFunction(m->getFunction("system!main"));
	FPtr(curthread->stack.stack);
	ThStopAllThreads();
    //_BreakPoint


}


//#define BD_Arr_Cache
#define BD_No_Arr_Bound_Chk
void  ExArrPuti(BINT index,int value)
{
			DVM_ObjectRef barray=(curthread->stack.stack_pointer-1)->object;
			curthread->stack.stack_pointer-- ;curthread->stack.flg_sp--;
	//barray.data->u.barray.u.int_array[index]=value;
#ifdef BD_Arr_Cache
            BINT* int_value;
            int_value =AcGetPtri(curdvm,barray,index);
			*int_value=value;//*/
#else
#ifdef BD_No_Arr_Bound_Chk
	barray.data->u.barray.u.int_array [index]=value;
#else
	        DVM_ErrorStatus status;
            DVM_ObjectRef exception;
            status = DVM_array_set_int(curdvm, barray, index, value, &exception);
            if (status == DVM_SUCCESS) {
                return;
            } else {
                _BreakPoint //fix-me
            }
#endif
#endif
}

void ExArrPutd(BINT index,double value)
{
			DVM_ObjectRef barray=(curthread->stack.stack_pointer-1)->object;
			curthread->stack.stack_pointer-- ;curthread->stack.flg_sp--;
            DVM_ErrorStatus status;
            DVM_ObjectRef exception;
            status = DVM_array_set_double(curdvm, barray, index, value, &exception);
            if (status == DVM_SUCCESS) {
                return;
            } else {
                _BreakPoint //fix-me
            }
}

void ExArrPuto(BINT index)
{
			DVM_ObjectRef value=(curthread->stack.stack_pointer-2)->object;
			DVM_ObjectRef barray=(curthread->stack.stack_pointer-1)->object;
			curthread->stack.stack_pointer-=2 ;curthread->stack.flg_sp-=2;
            DVM_ErrorStatus status;
            DVM_ObjectRef exception;
            status = DVM_array_set_object(curdvm, barray, index, value, &exception);
            if (status == DVM_SUCCESS) {
                return;
            } else {
                _BreakPoint //fix-me
            }
}

BINT ExArrGetCh(BINT index)
{
			DVM_ObjectRef str=(curthread->stack.stack_pointer-1)->object;
			curthread->stack.stack_pointer-- ;curthread->stack.flg_sp--;
            DVM_ErrorStatus status;
            DVM_ObjectRef exception;
            DVM_Char ch;
            status = DVM_string_get_character(curdvm, str, index,
                                              &ch, &exception);

            if (status == DVM_SUCCESS) {
                return ch;
            } else {
                 _BreakPoint //fix-me
            }

            return 0;
}

DVM_ObjectRef ExArrGeto(BINT index)
{
			DVM_ObjectRef barray=(curthread->stack.stack_pointer-1)->object;
			curthread->stack.stack_pointer-- ;curthread->stack.flg_sp--;
            DVM_ObjectRef object;
            DVM_ErrorStatus status;
            DVM_ObjectRef exception;
            status = DVM_array_get_object(curdvm, barray, index,
                                          &object, &exception);
            if (status == DVM_SUCCESS) {
                return object;
            } else {
                 _BreakPoint //fix-me
            }

			return object;
}

double ExArrGetd(BINT index)
{
			DVM_ObjectRef barray=(curthread->stack.stack_pointer-1)->object;
			curthread->stack.stack_pointer-- ;curthread->stack.flg_sp--;
            double double_value;
            DVM_ErrorStatus status;
            DVM_ObjectRef exception;

            status = DVM_array_get_double(curdvm, barray, index,
                                          &double_value, &exception);
            if (status == DVM_SUCCESS) {
                return double_value;
            } else {
               _BreakPoint //fix-me
            }

			return 0;
}


BINT ExArrGeti(BINT index)
{
			DVM_ObjectRef barray=(curthread->stack.stack_pointer-1)->object;
			curthread->stack.stack_pointer-- ;curthread->stack.flg_sp--;
	//return barray.data->u.barray.u.int_array[index];
#ifdef BD_Arr_Cache
            BINT* int_value;
            int_value =AcGetPtri(curdvm,barray,index);
			return *int_value;//*/
#else
#ifdef BD_No_Arr_Bound_Chk
	return barray.data->u.barray.u.int_array [index];
#else
			int int_value;
            DVM_ErrorStatus status;
            DVM_ObjectRef exception;

            status = DVM_array_get_int(curdvm, barray, index,
                                          &int_value, &exception);
            if (status == DVM_SUCCESS) {
                return int_value;
            } else {
               _BreakPoint //fix-me
            }
			return 0;
#endif
#endif
}

BINT ExFldGeti(BINT index)
{
			DVM_ObjectRef obj=(curthread->stack.stack_pointer-1)->object;
			curthread->stack.stack_pointer-- ;curthread->stack.flg_sp--;
            if (is_null_pointer(&obj)) {
                ExNullPointerException();
            } else {
                return obj.data->u.class_object.field[index].int_value;
            }
            return 0;
}

double ExFldGetd(BINT index)
{
			DVM_ObjectRef obj=(curthread->stack.stack_pointer-1)->object;
			curthread->stack.stack_pointer-- ;curthread->stack.flg_sp--;
            if (is_null_pointer(&obj)) {
                ExNullPointerException();
            } else {
                return obj.data->u.class_object.field[index].double_value ;
            }
            return 0;
}

DVM_ObjectRef ExFldGeto(BINT index)
{
			DVM_ObjectRef obj=(curthread->stack.stack_pointer-1)->object;
			curthread->stack.stack_pointer-- ;curthread->stack.flg_sp--;
            if (is_null_pointer(&obj)) {
                ExNullPointerException();
            } else {
				return obj.data->u.class_object.field[index].object ;
            }

	return dvm_null_object_ref;

}
void ExFldPuti(BINT index,int value)
{
			DVM_ObjectRef obj=(curthread->stack.stack_pointer-1)->object;
			curthread->stack.stack_pointer-- ;curthread->stack.flg_sp--;
            if (is_null_pointer(&obj)) {
                ExNullPointerException();
            } else {
                obj.data->u.class_object.field[index].int_value=value;
            }
}
void ExFldPutd(BINT index,double value)
{
			DVM_ObjectRef obj=(curthread->stack.stack_pointer-1)->object;
			curthread->stack.stack_pointer-- ;curthread->stack.flg_sp--;
            if (is_null_pointer(&obj)) {
                ExNullPointerException();
            } else {
                obj.data->u.class_object.field[index].double_value =value;
            }
}
void ExFldPuto(BINT index)
{
			DVM_ObjectRef value=(curthread->stack.stack_pointer-2)->object;
			DVM_ObjectRef obj=(curthread->stack.stack_pointer-1)->object;
			curthread->stack.stack_pointer-- ;curthread->stack.flg_sp--;
            if (is_null_pointer(&obj)) {
                ExNullPointerException();
            } else {
                obj.data->u.class_object.field[index].object  =value;
            }
}
extern "C" DVM_ObjectRef create_array(DVM_VirtualMachine *dvm, int dim, DVM_TypeSpecifier *type);
extern "C" DVM_ObjectRef create_array_literal_int(DVM_VirtualMachine *dvm, int size);
extern "C" DVM_ObjectRef create_array_literal_double(DVM_VirtualMachine *dvm, int size);
extern "C" DVM_ObjectRef create_array_literal_object(DVM_VirtualMachine *dvm, int size);
void ExNewArray(BINT ty,BINT dim)
{
            DVM_TypeSpecifier *type
				= &curthread->current_executable->executable->type_specifier[ty];
            DVM_ObjectRef barray;
            barray = create_array(curdvm, dim, type);
            curthread->stack.stack_pointer -= dim; curthread->stack.flg_sp -=dim;
            curthread->retvar.object= barray;
}

void ExArrayLiteral(BINT ty,BINT size)
{
            DVM_ObjectRef barray;
			switch(ty)
			{
			case 0:
				barray = create_array_literal_int(curdvm, size);
				break;
			case 1:
				barray = create_array_literal_double(curdvm, size);
				break;
			case 2:
				barray = create_array_literal_object(curdvm, size);
				break;
			default:
				DBG_assert(0, ("Bad type %d\n",ty));
			}

            curthread->stack.stack_pointer -= size; curthread->stack.flg_sp -=size;
            curthread->retvar.object= barray;
}

void ExNew(BINT idx_in_exe,BINT methodid)
{
	int class_index = curthread->current_executable->class_table[idx_in_exe];
    DVM_ObjectRef ret= dvm_create_class_object_i(curdvm, class_index);
	curthread->stack.stack_pointer->object=ret;
	*curthread->stack.flg_sp=DVM_TRUE;
	curthread->stack.stack_pointer++; curthread->stack.flg_sp++;
	ExCall(methodid);
	curthread->retvar.object= ret;
}

void ExFailure()
{
	printf("UncaughtException %d\n",curthread->exception_index);
	_BreakPoint
}



typedef void (*ExServiceProc)(void);
ExServiceProc ExServiceTable[]={
	ExFailure,
};
#define ExServiceCount (sizeof(ExServiceTable)/sizeof(ExServiceProc))
void ExServiceDispatcher(BINT index)
{
	if(index<ExServiceCount && index>0)
	{
		ExServiceTable[index]();
	}
}


extern "C" DVM_Boolean check_instanceof(DVM_VirtualMachine *dvm, DVM_ObjectRef *obj,int target_idx);
extern "C" int ExDoInstanceOf(DVM_ObjectRef* obj,BINT target_idx)
{
            if (obj->v_table->exec_class->class_index == target_idx) {
                return 1;
            }
			else {
                return check_instanceof(curdvm, obj, target_idx);
            }
}


DVM_Boolean ExInstanceof2(BINT index,BINT level)//In llvm, the return value is a bit!
{
			DVM_ObjectRef obj=(curthread->stack.stack_pointer-1)->object;
			DVM_Boolean ret=DVM_FALSE;
			curthread->stack.stack_pointer-- ;curthread->stack.flg_sp--;
	        if (is_null_pointer(&obj)) {
                ExNullPointerException();
            } else {
				if(obj.data->type==STRING_OBJECT && index==0)
					return DVM_TRUE;
				else
				{
					if(obj.data->type!=ARRAY_OBJECT)
						return DVM_FALSE;
					else //fix-me : ergent!! should check the level and type of the array
						return DVM_TRUE;
				}
            }
			return DVM_FALSE;
}

DVM_Boolean ExInstanceof(BINT index)//In llvm, the return value is a bit!
{
			DVM_ObjectRef obj=(curthread->stack.stack_pointer-1)->object;
			DVM_Boolean ret=DVM_FALSE;
			curthread->stack.stack_pointer-- ;curthread->stack.flg_sp--;
			index=curthread->current_executable->class_table[index];
	        if (is_null_pointer(&obj)) {
                ExNullPointerException();
            } else {
				if(obj.data->type!=CLASS_OBJECT)
					ret=DVM_FALSE;
				else
					ret = (DVM_Boolean) ExDoInstanceOf(&obj,index);
            }
			return ret;
}
void ExInvokeDelegate()
{
	DVM_ObjectRef del_obj=(curthread->stack.stack_pointer-1)->object;
	curthread->stack.stack_pointer-- ;curthread->stack.flg_sp--;
    int func_idx;
	if(is_null_pointer(&del_obj))
		ExNullPointerException();
    if(del_obj.data->u.delegate.index<0)
		ExSystemRaise(ExBadFunctionIndex);
    if (is_null_pointer(&del_obj.data->u.delegate.object)) {
        func_idx = del_obj.data->u.delegate.index;
    } else {
        func_idx
            = (del_obj.data->u.delegate.object.v_table
               ->table[del_obj.data->u.delegate.index].index);
    }

	ExDoInvoke(func_idx);
}


void InitOptimizer(PassManager& OurFPM,ExecutionEngine* TheExecutionEngine,Module* M)
{
	EngineBuilder eb(M);
	TargetMachine* tm=eb.selectTarget();
	OurFPM.add(new DataLayout(*TheExecutionEngine->getDataLayout()));
	tm->addAnalysisPasses(OurFPM);
	// Set up the optimizer pipeline.  Start with registering info about how the
	// target lays out data structures.
	//OurFPM.add(new DataLayout(*TheExecutionEngine->getDataLayout()));
	/*// Provide basic AliasAnalysis support for GVN.
	OurFPM.add(createBasicAliasAnalysisPass());
	
	// Do simple "peephole" optimizations and bit-twiddling optzns.
	//OurFPM.add(createInstructionCombiningPass());
	// Reassociate expressions.
	OurFPM.add(createReassociatePass());
	// Eliminate Common SubExpressions.
	OurFPM.add(createGVNPass());
	// Simplify the control flow graph (deleting unreachable blocks, etc).
	OurFPM.add(createCFGSimplificationPass());
	//OurFPM.add(createBoundsCheckingPass());
	
	OurFPM.add(createPromoteMemoryToRegisterPass());
	OurFPM.add(createDependenceAnalysisPass());
	OurFPM.add(createScalarEvolutionAliasAnalysisPass());
	OurFPM.add(createLoopVectorizePass());
	//OurFPM.add(createSLPVectorizerPass());
	*/
  PassManagerBuilder Builder;
  Builder.OptLevel = parameters.optmization;
  Builder.LoopVectorize=true;
  Builder.SLPVectorize=true;
  Builder.DisableUnrollLoops=false;
  OurFPM.add(createPromoteMemoryToRegisterPass());
  Builder.populateModulePassManager(OurFPM);
  
  //OurFPM.add(createLoopVectorizePass());
	//OurFPM.doInitialization();
  OurFPM.run(*M);
  /*
	Module::iterator it;
	Module::iterator end = M->end();
	for (it = M->begin(); it != end; ++it) {
		// Run the FPM on this function
		printf("%s",(*it).getName());
		OurFPM.run(*it);
	}*/
	TheExecutionEngine->finalizeObject();
	//M->dump();

}
//*/
//void ExReplaceInlineFunctions(Module* m,Module* inline_mod);
void ExReplaceInlineFunctions(Module* m);
int* ExGetReg(BdThread* th,BINT i)
{
    switch(i)
    {
    case 0:
     	return (int*)&th->bpc;
    case 1:
        return (int*)&th->exception_index;
	case 2:
        return (int*)&th->current_exception;
    case 3:
        return (int*)&th->stack.stack_pointer;
    case 4:
        return (int*)&th->stack.flg_sp;
    case 5:
        return (int*)&th->retvar;
    }

	return NULL;;
}


extern "C" void ExInitRegArray(BdThread* t)
{
	cur_prep_regs[0]=(int*)&t->bpc;                 cur_prep_regs[1]=(int*)&t->exception_index;
	cur_prep_regs[2]=(int*)&t->current_exception;  cur_prep_regs[3]=(int*)&t->stack.stack_pointer;
	cur_prep_regs[4]=(int*)&t->stack.flg_sp;       cur_prep_regs[5]=(int*)&t->retvar;
}

//Init thread's reg in one module.
extern "C" void ExInitThread(BdThread* t,void* mod,void* eng)
{

	Module* m=(Module*)mod;
	ExecutionEngine* e=(ExecutionEngine*)eng;
	void(*RegInit)(BdThread*);
	RegInit=(void(*)(BdThread*))e->getPointerToFunction(m->getFunction("system!RegInit"));
	RegInit(t);
}

//Init thread's reg in all modules. Used in threads other than the main thread
//should be called in the new thread
extern "C" void ExInitThreadInAllModules()
{
	ExInitRegArray(curthread);
	MCJITHelper* MCJIT=(MCJITHelper*) curdvm->exe_engine;
	MCJITHelper::ModuleVector::iterator it, end;
	for (it = MCJIT->Modules.begin(), end = MCJIT->Modules.end();it != end; ++it) {
		std::map<Module*, ExecutionEngine*>::iterator mapIt = MCJIT->EngineMap.find(*it);
		if (mapIt != MCJIT->EngineMap.end())
		{
			ExInitThread(curthread,mapIt->first,mapIt->second);
		}
		else
		{
			_BreakPoint
		}
	}
}


void SetNoThreadLocal(Module* m,char* name,ExecutionEngine* TheExecutionEngine,int idx)
{
	GlobalVariable* global=m->getGlobalVariable(name);
	global->setThreadLocalMode(GlobalVariable::NotThreadLocal);
	global->setThreadLocal(false);
	global->setLinkage(GlobalVariable::ExternalLinkage);
	TheExecutionEngine->addGlobalMapping(global,&(cur_prep_regs[idx]));
}
extern "C" void* ExPrepareModule(struct LLVM_Data* mod,DVM_VirtualMachine *dvm,ExecutableEntry* ee)
{
	//if(ee->executable->is_required)
	//	return 0;
	Module* m=(Module*)mod->mod;

	ExReplaceInlineFunctions(m);
	//ExReplaceInlineFunctions(m,(Module*)ee->executable->inline_module.mod);
	std::string ErrStr;
	//ExecutionEngine* TheExecutionEngine;
	MCJITHelper* MCJIT;
	if(dvm->exe_engine)
	{
		MCJIT=(MCJITHelper*) dvm->exe_engine;

	}
	else
	{
		if(parameters.debug)
			MCJIT= new MCJITHelper(m,true);
		else
			MCJIT= new MCJITHelper(m,false);
		dvm->exe_engine=MCJIT;
	}
	ExecutionEngine* TheExecutionEngine=MCJIT->compileModule(m);
	if(parameters.debug)
	{
		SetNoThreadLocal(m,"bpc",TheExecutionEngine,0);
		SetNoThreadLocal(m,"bei",TheExecutionEngine,1);
		SetNoThreadLocal(m,"beo",TheExecutionEngine,2);
		SetNoThreadLocal(m,"bsp",TheExecutionEngine,3);
		SetNoThreadLocal(m,"arr_sp",TheExecutionEngine,4);
		SetNoThreadLocal(m,"retvar",TheExecutionEngine,5);
	}
	GlobalVariable* vglobal=m->getGlobalVariable("pstatic"); //static variable are shared
	TheExecutionEngine->addGlobalMapping(vglobal,&(ee->static_v.variable));
	vglobal=m->getGlobalVariable("mid"); //module id are shared
	TheExecutionEngine->addGlobalMapping(vglobal,&(ee->executable->id));

	Function *f; //fix-me : For MCJIT ,TheExecutionEngine->addGlobalMapping is not needed
	f=m->getFunction("system!GetReg");
	TheExecutionEngine->addGlobalMapping(f,(void*)ExGetReg);
	MCJIT->addGlobalMapping("system!GetReg",(void*)ExGetReg);

	f=m->getFunction("string!LoadStringFromPool");
	TheExecutionEngine->addGlobalMapping(f,(void*)ExLoadStringFromPool);
	MCJIT->addGlobalMapping("string!LoadStringFromPool",(void*)ExLoadStringFromPool);

	f=m->getFunction("string!ChainString");
	TheExecutionEngine->addGlobalMapping(f,(void*)ExChainString);
	MCJIT->addGlobalMapping("string!ChainString",(void*)ExChainString);

	f=m->getFunction("string!CompareString");
	TheExecutionEngine->addGlobalMapping(f,(void*)ExCompareString);
	MCJIT->addGlobalMapping("string!CompareString",(void*)ExCompareString);

	f=m->getFunction("object!CompareObject");
	TheExecutionEngine->addGlobalMapping(f,(void*)ExCompareObject);
	MCJIT->addGlobalMapping("object!CompareObject",(void*)ExCompareObject);
	f=m->getFunction("system!IntToStr");
	TheExecutionEngine->addGlobalMapping(f,(void*)ExIntToStr);
	MCJIT->addGlobalMapping("system!IntToStr",(void*)ExIntToStr);
	f=m->getFunction("system!BoolToStr");
	TheExecutionEngine->addGlobalMapping(f,(void*)ExBoolToStr);
	MCJIT->addGlobalMapping("system!BoolToStr",(void*)ExBoolToStr);
	f=m->getFunction("system!DoubleToStr");
	TheExecutionEngine->addGlobalMapping(f,(void*)ExDoubleToStr);
	MCJIT->addGlobalMapping("system!DoubleToStr",(void*)ExDoubleToStr);
	f=m->getFunction("system!NewDelegate");
	TheExecutionEngine->addGlobalMapping(f,(void*)ExNewDelegate);
	MCJIT->addGlobalMapping("system!NewDelegate",(void*)ExNewDelegate);
	f=m->getFunction("system!InvokeDelegate");
	TheExecutionEngine->addGlobalMapping(f,(void*)ExInvokeDelegate);
	MCJIT->addGlobalMapping("system!InvokeDelegate",(void*)ExInvokeDelegate);
	f=m->getFunction("system!GetSuper");
	TheExecutionEngine->addGlobalMapping(f,(void*)ExGetSuper);
	MCJIT->addGlobalMapping("system!GetSuper",(void*)ExGetSuper);
	f=m->getFunction("system!DownCast");
	TheExecutionEngine->addGlobalMapping(f,(void*)ExDownCast);
	MCJIT->addGlobalMapping("system!DownCast",(void*)ExDownCast);
	f=m->getFunction("system!UpCast");
	TheExecutionEngine->addGlobalMapping(f,(void*)ExUpCast);
	MCJIT->addGlobalMapping("system!UpCast",(void*)ExUpCast);
	f=m->getFunction("system!Instanceof");
	TheExecutionEngine->addGlobalMapping(f,(void*)ExInstanceof);
	MCJIT->addGlobalMapping("system!Instanceof",(void*)ExInstanceof);
	f=m->getFunction("system!Instanceof2");
	TheExecutionEngine->addGlobalMapping(f,(void*)ExInstanceof2);
	MCJIT->addGlobalMapping("system!Instanceof2",(void*)ExInstanceof2);
	/*f=m->getFunction("system!ArrGeti");
	TheExecutionEngine->addGlobalMapping(f,ExArrGeti);
	f=m->getFunction("system!ArrGetd");
	TheExecutionEngine->addGlobalMapping(f,ExArrGetd);
	f=m->getFunction("system!ArrGeto");
	TheExecutionEngine->addGlobalMapping(f,ExArrGeto);*/
	f=m->getFunction("system!ArrGetCh");
	TheExecutionEngine->addGlobalMapping(f,(void*)ExArrGetCh);
	MCJIT->addGlobalMapping("system!ArrGetCh",(void*)ExArrGetCh);
	/*f=m->getFunction("system!ArrPuti");
	TheExecutionEngine->addGlobalMapping(f,ExArrPuti);
	f=m->getFunction("system!ArrPutd");
	TheExecutionEngine->addGlobalMapping(f,ExArrPutd);
	f=m->getFunction("system!ArrPuto");
	TheExecutionEngine->addGlobalMapping(f,ExArrPuto);*/

	f=m->getFunction("system!SystemRaise");
	TheExecutionEngine->addGlobalMapping(f,(void*)ExSystemRaise);
	MCJIT->addGlobalMapping("system!SystemRaise",(void*)ExSystemRaise);
	/*f=m->getFunction("system!FldGeti");
	TheExecutionEngine->addGlobalMapping(f,ExFldGeti);
	f=m->getFunction("system!FldGetd");
	TheExecutionEngine->addGlobalMapping(f,ExFldGetd);
	f=m->getFunction("system!FldGeto");
	TheExecutionEngine->addGlobalMapping(f,ExFldGeto);
	f=m->getFunction("system!FldPuti");
	TheExecutionEngine->addGlobalMapping(f,ExFldPuti);
	f=m->getFunction("system!FldPutd");
	TheExecutionEngine->addGlobalMapping(f,ExFldPutd);
	f=m->getFunction("system!FldPuto");
	TheExecutionEngine->addGlobalMapping(f,ExFldPuto);*/

	f=m->getFunction("system!ArrayLiteral");
	TheExecutionEngine->addGlobalMapping(f,(void*)ExArrayLiteral);
	MCJIT->addGlobalMapping("system!ArrayLiteral",(void*)ExArrayLiteral);
	f=m->getFunction("system!NewArray");
	TheExecutionEngine->addGlobalMapping(f,(void*)ExNewArray);
	MCJIT->addGlobalMapping("system!NewArray",(void*)ExNewArray);
	f=m->getFunction("object!New");
	TheExecutionEngine->addGlobalMapping(f,(void*)ExNew);
	MCJIT->addGlobalMapping("object!New",(void*)ExNew);
	f=m->getFunction("system!Invoke");
	TheExecutionEngine->addGlobalMapping(f,(void*)ExInvoke);
	MCJIT->addGlobalMapping("system!Invoke",(void*)ExInvoke);
	f=m->getFunction("system!Call");
	TheExecutionEngine->addGlobalMapping(f,(void*)ExCall);
	MCJIT->addGlobalMapping("system!Call",(void*)ExCall);
	f=m->getFunction("system!Failure");
	TheExecutionEngine->addGlobalMapping(f,(void*)ExFailure);
	MCJIT->addGlobalMapping("system!Failure",(void*)ExFailure);
	f=m->getFunction("system!Reraise");
	TheExecutionEngine->addGlobalMapping(f,(void*)ExReraiseException);
	MCJIT->addGlobalMapping("system!Reraise",(void*)ExReraiseException);
	f=m->getFunction("system!PushException");
	TheExecutionEngine->addGlobalMapping(f,(void*)ExPushJumpBuffer);
	MCJIT->addGlobalMapping("system!PushException",(void*)ExPushJumpBuffer);
	f=m->getFunction("system!Raise");
	TheExecutionEngine->addGlobalMapping(f,(void*)ExRaiseException);
	MCJIT->addGlobalMapping("system!Raise",(void*)ExRaiseException);
	f=m->getFunction("system!Setjmp");
#ifdef BD_ON_GCC
	TheExecutionEngine->addGlobalMapping(f,(void*)_setjmp);
	MCJIT->addGlobalMapping("system!Setjmp",(void*)_setjmp);
#else
	TheExecutionEngine->addGlobalMapping(f,(void*)setjmp);
	MCJIT->addGlobalMapping("system!Setjmp",(void*)setjmp);
#endif
	f=m->getFunction("system!LeaveTry");
	TheExecutionEngine->addGlobalMapping(f,(void*)ExLeaveTry);
	MCJIT->addGlobalMapping("system!LeaveTry",(void*)ExLeaveTry);
	f=m->getFunction("system!DoInvoke");
	TheExecutionEngine->addGlobalMapping(f,(void*)ExDoInvoke);
	MCJIT->addGlobalMapping("system!DoInvoke",(void*)ExDoInvoke);
	f=m->getFunction("autovar!get");
	TheExecutionEngine->addGlobalMapping(f,(void*)AvGetVar);
	MCJIT->addGlobalMapping("autovar!get",(void*)AvGetVar);
	f=m->getFunction("autovar!getorcreate");
	TheExecutionEngine->addGlobalMapping(f,(void*)AvGetOrCreateVar);
	MCJIT->addGlobalMapping("autovar!getorcreate",(void*)AvGetOrCreateVar);

	f=m->getFunction("shared!geti");
	TheExecutionEngine->addGlobalMapping(f,(void*)SoGeti);
	MCJIT->addGlobalMapping("shared!geti",(void*)SoGeti);
	f=m->getFunction("shared!getd");
	TheExecutionEngine->addGlobalMapping(f,(void*)SoGetd);
	MCJIT->addGlobalMapping("shared!getd",(void*)SoGetd);
	f=m->getFunction("shared!geto");
	TheExecutionEngine->addGlobalMapping(f,(void*)SoGeto);
	MCJIT->addGlobalMapping("shared!geto",(void*)SoGeto);
	f=m->getFunction("shared!gets");
	TheExecutionEngine->addGlobalMapping(f,(void*)SoGets);
	MCJIT->addGlobalMapping("shared!gets",(void*)SoGets);

	f=m->getFunction("shared!seti");
	TheExecutionEngine->addGlobalMapping(f,(void*)SoSeti);
	MCJIT->addGlobalMapping("shared!seti",(void*)SoSeti);
	f=m->getFunction("shared!setd");
	TheExecutionEngine->addGlobalMapping(f,(void*)SoSetd);
	MCJIT->addGlobalMapping("shared!setd",(void*)SoSetd);
	f=m->getFunction("shared!seto");
	TheExecutionEngine->addGlobalMapping(f,(void*)SoSeto);
	MCJIT->addGlobalMapping("shared!seto",(void*)SoSeto);
	f=m->getFunction("shared!sets");
	TheExecutionEngine->addGlobalMapping(f,(void*)SoSets);
	MCJIT->addGlobalMapping("shared!sets",(void*)SoSets);
	f=m->getFunction("shared!New");
	TheExecutionEngine->addGlobalMapping(f,(void*)SoNew);
	MCJIT->addGlobalMapping("shared!New",(void*)SoNew);

	f=m->getFunction("shared!NewArray");
	TheExecutionEngine->addGlobalMapping(f,(void*)SoNewArray);
	MCJIT->addGlobalMapping("shared!NewArray",(void*)SoNewArray);

	f=m->getFunction("shared!GlobalArrBoundaryCheck");
	TheExecutionEngine->addGlobalMapping(f,(void*)SoGlobalArrBoundaryCheck);
	MCJIT->addGlobalMapping("shared!GlobalArrBoundaryCheck",(void*)SoGlobalArrBoundaryCheck);

	f=m->getFunction("system!AtmInc");
	if(f){TheExecutionEngine->addGlobalMapping(f,(void*)UaAtomicInc);
	MCJIT->addGlobalMapping("system!AtmInc",(void*)UaAtomicInc);}

	f=m->getFunction("system!AtmDec");
	if(f){TheExecutionEngine->addGlobalMapping(f,(void*)UaAtomicDec);
	MCJIT->addGlobalMapping("system!AtmDec",(void*)UaAtomicDec);}

	f=m->getFunction("system!CopyArray");
	if(f){TheExecutionEngine->addGlobalMapping(f,(void*)SoCopyArray);
	MCJIT->addGlobalMapping("system!CopyArray",(void*)SoCopyArray);}

	f=m->getFunction("shared!vgeti");
	TheExecutionEngine->addGlobalMapping(f,(void*)SovGeti);
	MCJIT->addGlobalMapping("shared!vgeti",(void*)SovGeti);
	f=m->getFunction("shared!vgetd");
	TheExecutionEngine->addGlobalMapping(f,(void*)SovGetd);
	MCJIT->addGlobalMapping("shared!vgetd",(void*)SovGetd);

	f=m->getFunction("shared!vseti");
	TheExecutionEngine->addGlobalMapping(f,(void*)SovSeti);
	MCJIT->addGlobalMapping("shared!vseti",(void*)SovSeti);
	f=m->getFunction("shared!vsetd");
	TheExecutionEngine->addGlobalMapping(f,(void*)SovSetd);
	MCJIT->addGlobalMapping("shared!vsetd",(void*)SovSetd);

/*	f=m->getFunction("shared!inc");
	if(f){TheExecutionEngine->addGlobalMapping(f,(void*)SoInc);
	MCJIT->addGlobalMapping("shared!inc",(void*)SoInc);}

	f=m->getFunction("shared!dec");
	if(f){TheExecutionEngine->addGlobalMapping(f,(void*)SoDec);
	MCJIT->addGlobalMapping("shared!dec",(void*)SoDec);}*/

			//OurFPM.doInitialization();
	MCJIT->getPassManager(m)->run(*m);
		/*
		Module::iterator it;
		Module::iterator end = M->end();
		for (it = M->begin(); it != end; ++it) {
			// Run the FPM on this function
			printf("%s",(*it).getName());
			OurFPM.run(*it);
		}*/
	TheExecutionEngine->finalizeObject();
	return TheExecutionEngine;
}

extern "C" void ExFreeMCJIT(void* p)
{
	MCJITHelper* h=(MCJITHelper*)p;
	delete h;
}

extern "C" void ExInitEngine()
{
#ifdef BD_ON_WINDOWS
	UaInitTls();
#endif
}

void replaceAllUsesWith(Value* ths,Value *New) {


  // Notify all ValueHandles (if present) that this value is going away.
  if (ths->hasValueHandle())
    ValueHandleBase::ValueIsRAUWd(ths, New);

  while (!ths->use_empty()) {
    Use &U = ths->use_begin().getUse();
    // Must handle Constants specially, we cannot call replaceUsesOfWith on a
    // constant because they are uniqued.
    if (Constant *C = dyn_cast<Constant>(U.getUser())) {
      if (!isa<GlobalValue>(C)) {
        C->replaceUsesOfWithOnConstant(ths, New, &U);
        continue;
      }
    }

    U.set(New);
  }

  if (BasicBlock *BB = dyn_cast<BasicBlock>(ths))
    BB->replaceSuccessorsPhiUsesWith(cast<BasicBlock>(New));
}
void ExReplaceInlineFunctions(Module* m)
{

	Type* TyO=m->getGlobalVariable("bsp")->getType()->getPointerElementType()->getPointerElementType()->getPointerElementType();
	//TyO->dump();
	BcSwitchContext(m,TyO);
	Function* f;
	f=m->getFunction("systemi!ArrAddr");
	if(f)
	{
		Type* voidp=f->getFunctionType()->getReturnType();
		replaceAllUsesWith(f,BcBuildArrPtrImp(voidp));
	}
	f=m->getFunction("systemi!Pushi");
	if(f)
	{
		replaceAllUsesWith(f,BcBuildPushImp("systemi!PushiImp",0,Type::getInt32Ty(llvm::getGlobalContext())));
	}
	f=m->getFunction("systemi!Pusho");
	if(f)
	{
		replaceAllUsesWith(f,BcBuildPushImp("systemi!PushoImp",1,TyO));
	}
	f=m->getFunction("systemi!Pushd");
	if(f)
	{
		replaceAllUsesWith(f,BcBuildPushImp("systemi!PushdImp",0,Type::getDoubleTy(llvm::getGlobalContext())));
	}
	f=m->getFunction("systemi!ArrAddrSafe");
	if(f)
	{
		Type* voidp=f->getFunctionType()->getReturnType();
		replaceAllUsesWith(f,BcBuildArrPtrSafeImp(voidp));
	}
	f=m->getFunction("systemi!FldAddr");
	if(f)
	{
		Type* voidp=f->getFunctionType()->getReturnType();
		replaceAllUsesWith(f,BcBuildFldPtrImp(voidp));
	}
	f=m->getFunction("systemi!Pop");
	if(f)
	{
		replaceAllUsesWith(f,BcBuildPopImp());
	}
	f=m->getFunction("systemi!ObjectRefPtr");
	if(f)
	{
		replaceAllUsesWith(f,BcBuildObjectRefPtrImp());
	}

	BcBuildRegInit();
}


int ExExec(char* path)
{
    DVM_VirtualMachine *dvm;
	BdStatus status;
	DVM_ExecutableList* plist=(DVM_ExecutableList*)MEM_malloc(sizeof(DVM_ExecutableList));
	plist->list=0;plist->top_level=0;

	dvm = DVM_create_virtual_machine();
	ExInitEngine();
	status=LdLoadCode(path,plist);
	if(status)
	{
		printf("ERROR Loading Code %d\n",status);
		goto ERR;
	}
	else
	{
		ExSetCurrentDVM(dvm);
		DVM_set_executable(dvm, plist); //modified
		DVM_execute(dvm);
		MEM_check_all_blocks();
		MEM_dump_blocks(stdout);
	}
ERR:
	DVM_dispose_virtual_machine(dvm);
	DVM_dispose_executable_list(plist); //*/
	return status;
}


static int ExDoGetMethodIndex(ExecClass *ec, char *method_name, int *super_count)
{
    int i;
    int index;

    if (ec->super_class) {
        index = ExDoGetMethodIndex(ec->super_class, method_name, super_count);
        if (index != FIELD_NOT_FOUND) {
            return index;
        }
    }
    for (i = 0; i < ec->dvm_class->method_count; i++) {
		if (!strcmp(ec->dvm_class->method[i].name, method_name)) {
            return i + *super_count;
        }
    }
    *super_count += ec->dvm_class->method_count;

    return FIELD_NOT_FOUND;
}


int ExGetMethodIndex(ExecClass *ec, char *method_name)
{
	int tmp=0;
	return ExDoGetMethodIndex(ec,method_name,&tmp);
}


