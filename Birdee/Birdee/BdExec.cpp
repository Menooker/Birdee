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
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Transforms/Scalar.h"
#include "llvm/Bitcode/ReaderWriter.h"
#include "llvm/Support/MemoryBuffer.h"
#include "llvm/Transforms/Instrumentation.h"
#include "stdarg.h"
#include <setjmp.h>
using namespace llvm;
#include "BdVarients.h"
#include <time.h>
#include <list>
#include "Loader.h"

extern "C"{
#include "..\..\include\DBG.h"
//#include "..\..\include\DVM.h"
#include "..\..\DVM\DVM_pri.h"
}

#define _is_pointer_type(type) \
  ((type)->basic_type == DVM_STRING_TYPE \
   || (type)->basic_type == DVM_CLASS_TYPE \
   || (type)->basic_type == DVM_NULL_TYPE \
   || (type)->basic_type == DVM_DELEGATE_TYPE \
   || ((type)->derive_count > 0 \
       && (type)->derive[0].tag == DVM_ARRAY_DERIVE))

extern "C" DVM_VirtualMachine *curdvm;
extern "C" DVM_ObjectRef chain_string(DVM_VirtualMachine*,DVM_ObjectRef,DVM_ObjectRef);
#define is_null_pointer(obj) (((obj)->data == NULL))




extern "C" void ExLoadFunction(void* args,...)
{
	va_list pvar;
	va_start(pvar, args);
	BINT p1=va_arg(pvar, BINT);
	/*if(curdvm->function[p1]->l)
	{

	}*/
	DVM_Executable* exe=curdvm->function[p1]->u.diksam_f.executable->executable;
	ExecutableEntry* ee=curdvm->function[p1]->u.diksam_f.executable;
	Module* m=(Module*)exe->module.mod;
	Function* f=m->getFunction(curdvm->function[p1]->u.diksam_f.executable->executable->function[curdvm->function[p1]->u.diksam_f.index].name);
	FunctionPassManager* pm=(FunctionPassManager*)exe->module.pass;
	pm->run(*f);
	ExecutionEngine* engine=(ExecutionEngine*)(curdvm->exe_engine);
	BdVMFunction FPtr =(BdVMFunction) engine->getPointerToFunction(f);
	curdvm->function[p1]->pfun=FPtr;
	FPtr(args);
	va_end(pvar);

}


DVM_ObjectRef ExGetSuper(DVM_ObjectRef obj)
{

	        ExecClass *this_class;
            DVM_ObjectRef ret;
            this_class = obj.v_table->exec_class;
			ret.data=obj.data;
            ret.v_table = this_class->super_class->class_table;
			return ret;
}

DVM_ObjectRef ExLoadStringFromPool(BINT index)
{
	DVM_Executable* exe=curdvm->current_executable->executable;
    return dvm_literal_to_dvm_string_i(curdvm,exe->constant_pool[index].u.c_string);
}
DVM_ObjectRef ExChainString(DVM_ObjectRef a,DVM_ObjectRef b)
{
	return chain_string(curdvm,a,b);
}

BINT ExCompareString(DVM_ObjectRef a,DVM_ObjectRef b)
{
	return dvm_wcscmp(a.data->u.string.string,b.data->u.string.string); //check-me
}

BINT ExCompareObject(DVM_ObjectRef a,DVM_ObjectRef b) //fix-me : there is an another cmp after this call. May improve efficiency
{
	return (a.data!=b.data); //check-me
}

DVM_ObjectRef ExBoolToStr(BINT v)
{
	return dvm_literal_to_dvm_string_i(curdvm, v ? TRUE_STRING: FALSE_STRING);
}

DVM_ObjectRef ExIntToStr(BINT v)
{
    char buf[LINE_BUF_SIZE];
    DVM_Char *wc_str;
    sprintf(buf, "%d", v);
    wc_str = dvm_mbstowcs_alloc(curdvm, buf);
    return dvm_create_dvm_string_i(curdvm, wc_str);
}

DVM_ObjectRef ExDoubleToStr(double v)
{
    char buf[LINE_BUF_SIZE];
    DVM_Char *wc_str;
    sprintf(buf, "%lf", v);
    wc_str = dvm_mbstowcs_alloc(curdvm, buf);
    return dvm_create_dvm_string_i(curdvm, wc_str);
}

DVM_ObjectRef ExNewDelegate(BINT index)
{
            int dvm_index;
            DVM_ObjectRef mdelegate;

            dvm_index = index==-1?-1:curdvm->current_executable->function_table[index];
            mdelegate = dvm_create_delegate(curdvm, dvm_null_object_ref,
                                           dvm_index);
			return mdelegate;
}

void BcInitLocalVar(DVM_VirtualMachine *dvm,BFunction *func, int from_sp)
{
    int i;
    int sp_idx;

	for (i = 0, sp_idx = from_sp; i < func->local_cnt;
         i++, sp_idx++) {
        dvm->stack.pointer_flags[sp_idx] = DVM_FALSE;
    }

    for (i = 0, sp_idx = from_sp; i < func->local_cnt;
         i++, sp_idx++) {
        dvm_initialize_value(dvm,func->localvars[i].type,
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
		
		size_t len = wcslen(WStr) + 1;
		size_t converted = 0;
		char *CStr;
		CStr=(char*)malloc(len*sizeof(char));
		wcstombs_s(&converted, CStr, len, WStr, _TRUNCATE);
		return CStr;
}


void ExGetClock(DVM_Value* v)
{
	curdvm->retvar.int_value=clock()*1000/CLOCKS_PER_SEC;
}


void  ExDoInvoke(BINT transindex)
{
	int oldsp=curdvm->stack.stack_pointer;
	DVM_Value* base;
	BFunction* bf=curdvm->function[transindex];
	//DVM_Function* df=&bf->u.diksam_f.executable->executable->function[bf->u.diksam_f.index];
	
	if (!bf->is_implemented) {
		__asm int 3
    }
	//dvm_expand_stack(curdvm,bf->local_cnt);

	base=&curdvm->stack.stack[curdvm->stack.stack_pointer - bf->param_cnt];
	ExecutableEntry * ee=curdvm->current_executable;
    if(bf->u.diksam_f.executable)
		curdvm->current_executable = bf->u.diksam_f.executable;
/*    if (bf->is_method) {
        base--; // for this 
    }*/

	curdvm->stack.stack_pointer += bf->local_cnt ;
    BcInitLocalVar(curdvm, bf,oldsp);
	bf->pfun(base,transindex);
	curdvm->stack.stack_pointer=oldsp - bf->param_cnt;
	curdvm->current_executable=ee;
}


int ExGetStackType(int index)
{
	if(curdvm->stack.pointer_flags[index])
	{
		if(curdvm->stack.stack[index].object.data==NULL)
			return ExTypeNull;
		return curdvm->stack.stack[index].object.data->type - STRING_OBJECT + ExTypeString;
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
	int base=((unsigned)v-(unsigned)curdvm->stack.stack)/sizeof(DVM_Value);
	int ta,tp;
	BFunction* bf=curdvm->function[index];
	if(curdvm->bpc < bf->param_cnt)
		ExRaiseException(ExBadParameterNum);
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
		int bpc,popnum=0;
		char* mod;
		if(is_null_pointer(&(v+1)->object))
			mod=0;
		else if((v+1)->object.data->type==STRING_OBJECT )
			mod=ExConvertAndAllocWchar((v+1)->object.data->u.string.string);
		else
			ExRaiseException(ExBadParameterType);
		char* fun=ExConvertAndAllocWchar((v)->object.data->u.string.string);
		int index=ExFindFunctionByName(mod,fun);
		if(mod)
			free(mod);
		free(fun);
		if(index==-1)
			ExRaiseException(ExFunctionNotFound);
        if(is_null_pointer(&(v+2)->object))
			ExNullPointerException();
		(v+2)->object.data->u.delegate.index=index;//fix-me : check arguments
	}
	else
	{
		ExRaiseException(ExBadParameterType);
	}
}


void  ExRand(DVM_Value* v)
{
	curdvm->retvar.int_value=rand() % v->int_value ;
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
			ExRaiseException(ExBadParameterType);
		char* fun=ExConvertAndAllocWchar((v)->object.data->u.string.string);
		int index=ExFindFunctionByName(mod,fun);
		if(mod)
			free(mod);
		free(fun);
		if(index==-1)
			ExRaiseException(ExFunctionNotFound);
		if(!ExCheckArgument(index,v))
			ExRaiseException(ExBadParameterNum);

		bpc=curdvm->bpc;
		if(curdvm->function[index]->param_cnt != bpc)
		{
			popnum=bpc-curdvm->function[index]->param_cnt;
			curdvm->bpc=popnum;
		}
		int oldsp=curdvm->stack.stack_pointer;
		int base=((unsigned)v-(unsigned)curdvm->stack.stack)/sizeof(DVM_Value);
		curdvm->stack.stack_pointer+= bpc;
		for(int i=0;i<bpc;i++)
		{
			curdvm->stack.stack[oldsp+i]=v[i-bpc];
			curdvm->stack.pointer_flags[oldsp+i]=curdvm->stack.pointer_flags[base+i-bpc];
		}
		ExDoInvoke(index);
		if(popnum)
			curdvm->stack.stack_pointer-=popnum;
	}
	else
	{
		ExRaiseException(ExBadParameterType);
	}
}


void ExInvoke(BINT index)
{	

	int transindex=curdvm->current_executable->function_table[index];
	ExDoInvoke(transindex);
}
void ExCall(BINT index)
{
	int rindex=0;
            DVM_ObjectRef obj = curdvm->ths ;
            if (is_null_pointer(&obj)) {
                ExNullPointerException();

            } else {
				rindex=obj.v_table->table[index].index;
                ExDoInvoke(rindex);
            }
}

extern "C" void ExInitExeEngine()
{


	InitializeNativeTarget();
}

extern "C" void ExSetCurrentDVM(DVM_VirtualMachine *dvm)
{
	curdvm=dvm;
}

	extern "C" int hit;
	extern "C" int miss;
extern "C" void ExGoMain()
{
	srand((unsigned)time(NULL));
	DVM_Executable* exe=curdvm->top_level->executable;
	curdvm->current_executable =curdvm->top_level;
	ExecutionEngine* eng =(ExecutionEngine*)curdvm->exe_engine;
	Module* m=(Module*)exe->module.mod;
	BdVMFunction FPtr =(BdVMFunction) eng->getPointerToFunction(m->getFunction("system!main"));
	FPtr(curdvm->stack.stack);
	//m->dump();
	printf("h=%d m=%d",hit,miss);
}


//#define BD_Arr_Cache
#define BD_No_Arr_Bound_Chk
void  ExArrPuti(DVM_ObjectRef barray,BINT index,int value)
{
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
                __asm int 3 //fix-me
            }
#endif
#endif
}

void ExArrPutd(DVM_ObjectRef barray,BINT index,double value)
{
            DVM_ErrorStatus status;
            DVM_ObjectRef exception;
            status = DVM_array_set_double(curdvm, barray, index, value, &exception);
            if (status == DVM_SUCCESS) {
                return;
            } else {
                __asm int 3 //fix-me
            }
}

void ExArrPuto(DVM_ObjectRef barray,BINT index,DVM_ObjectRef value)
{
            DVM_ErrorStatus status;
            DVM_ObjectRef exception;
            status = DVM_array_set_object(curdvm, barray, index, value, &exception);
            if (status == DVM_SUCCESS) {
                return;
            } else {
                __asm int 3 //fix-me
            }
}

BINT ExArrGetCh(DVM_ObjectRef str,BINT index)
{
            DVM_ErrorStatus status;
            DVM_ObjectRef exception;
            DVM_Char ch;
            status = DVM_string_get_character(curdvm, str, index,
                                              &ch, &exception);
            if (status == DVM_SUCCESS) {
                return ch;
            } else {
                 __asm int 3 //fix-me
            }
            return 0;
}

DVM_ObjectRef ExArrGeto(DVM_ObjectRef barray,BINT index)
{
            DVM_ObjectRef object;
            DVM_ErrorStatus status;
            DVM_ObjectRef exception;
            status = DVM_array_get_object(curdvm, barray, index,
                                          &object, &exception);
            if (status == DVM_SUCCESS) {
                return object;
            } else {
                 __asm int 3 //fix-me
            }
			return object;
}

double ExArrGetd(DVM_ObjectRef barray,BINT index)
{
            double double_value;
            DVM_ErrorStatus status;
            DVM_ObjectRef exception;

            status = DVM_array_get_double(curdvm, barray, index,
                                          &double_value, &exception);
            if (status == DVM_SUCCESS) {
                return double_value;
            } else {
               __asm int 3 //fix-me
            }
			return 0;
}


BINT ExArrGeti(DVM_ObjectRef barray,BINT index)
{
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
               __asm int 3 //fix-me
            }
			return 0;
#endif
#endif
}

BINT ExFldGeti(DVM_ObjectRef obj,BINT index)
{
            if (is_null_pointer(&obj)) {
                ExNullPointerException();
            } else {
                return obj.data->u.class_object.field[index].int_value;
            }
            return 0;
}

double ExFldGetd(DVM_ObjectRef obj,BINT index)
{
            if (is_null_pointer(&obj)) {
                ExNullPointerException();
            } else {
                return obj.data->u.class_object.field[index].double_value ;
            }
            return 0;
}

DVM_ObjectRef ExFldGeto(DVM_ObjectRef obj,BINT index)
{
            if (is_null_pointer(&obj)) {
                ExNullPointerException();
            } else {
				return obj.data->u.class_object.field[index].object ;
            }
            
}
void ExFldPuti(DVM_ObjectRef obj,BINT index,int value)
{

            if (is_null_pointer(&obj)) {
                ExNullPointerException();
            } else {
                obj.data->u.class_object.field[index].int_value=value;
            }
}
void ExFldPutd(DVM_ObjectRef obj,BINT index,double value)
{

            if (is_null_pointer(&obj)) {
                ExNullPointerException();
            } else {
                obj.data->u.class_object.field[index].double_value =value;
            }
}
void ExFldPuto(DVM_ObjectRef obj,BINT index,DVM_ObjectRef value)
{

            if (is_null_pointer(&obj)) {
                ExNullPointerException();
            } else {
                obj.data->u.class_object.field[index].object  =value;
            }
}
extern "C" DVM_ObjectRef create_array(DVM_VirtualMachine *dvm, int dim, DVM_TypeSpecifier *type);
extern "C" DVM_ObjectRef create_array_literal_int(DVM_VirtualMachine *dvm, int size);
DVM_ObjectRef ExNewArray(BINT ty,BINT dim)
{
            DVM_TypeSpecifier *type
				= &curdvm->current_executable->executable->type_specifier[ty];
            DVM_ObjectRef barray;
            barray = create_array(curdvm, dim, type);
            curdvm->stack.stack_pointer -= dim;
            return barray;
}

DVM_ObjectRef ExArrayLiteral(BINT ty,BINT size)
{
            DVM_ObjectRef barray;
            barray = create_array_literal_int(curdvm, size);
            curdvm->stack.stack_pointer -= size;
            return barray;
}

DVM_ObjectRef ExNew(BINT idx_in_exe,BINT methodid)
{
	int class_index = curdvm->current_executable->class_table[idx_in_exe];
    DVM_ObjectRef ret= dvm_create_class_object_i(curdvm, class_index);
	DVM_ObjectRef oldthis=curdvm->ths;
	curdvm->ths=ret;
	ExCall(methodid);
	curdvm->ths=oldthis;
	return ret;
}

void ExFailure()
{
	printf("UncaughtException %d\n",curdvm->exception_index);
	__asm int 3
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


void ExInvokeDelegate(DVM_ObjectRef del_obj)
{
    int func_idx;
	if(is_null_pointer(&del_obj))
		ExNullPointerException();
    if(del_obj.data->u.delegate.index<0)
		ExRaiseException(ExBadFunctionIndex);
    if (is_null_pointer(&del_obj.data->u.delegate.object)) {
        func_idx = del_obj.data->u.delegate.index;
    } else {
        func_idx
            = (del_obj.data->u.delegate.object.v_table
               ->table[del_obj.data->u.delegate.index].index);
    }

	ExDoInvoke(func_idx);
}


void InitOptimizer(FunctionPassManager& OurFPM,ExecutionEngine* TheExecutionEngine)
{


	// Set up the optimizer pipeline.  Start with registering info about how the
	// target lays out data structures.
	OurFPM.add(new DataLayout(*TheExecutionEngine->getDataLayout()));
	// Provide basic AliasAnalysis support for GVN.
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
	OurFPM.doInitialization();
}
//*/
extern "C" void* ExPrepareModule(struct LLVM_Data* mod,DVM_VirtualMachine *dvm,ExecutableEntry* ee)
{
	Module* m=(Module*)mod->mod;
	FunctionPassManager* pm=new FunctionPassManager(m);
	mod->pass=pm;

	std::string ErrStr;
	ExecutionEngine* TheExecutionEngine;
	if(dvm->exe_engine)
	{
		TheExecutionEngine=(ExecutionEngine*) dvm->exe_engine;
		TheExecutionEngine->addModule(m);
	}
	else
	{
		EngineBuilder& eb= EngineBuilder(m);
		TargetMachine* tm= eb.selectTarget();
		tm->Options.NoFramePointerElim=1;
		tm->setOptLevel(llvm::CodeGenOpt::Default );
		//printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n%d",tm->getOptLevel());
		TheExecutionEngine=	 eb.setErrorStr(&ErrStr).create(tm);
		if (!TheExecutionEngine) {
			printf("Could not create ExecutionEngine: %s\n", ErrStr.c_str());
			exit(1);
		}
		dvm->exe_engine=TheExecutionEngine;
	}

	InitOptimizer(*pm,TheExecutionEngine);

	GlobalVariable* vglobal=m->getGlobalVariable("bpc");
	TheExecutionEngine->addGlobalMapping(vglobal,&(dvm->bpc));
	vglobal=m->getGlobalVariable("bei");
	TheExecutionEngine->addGlobalMapping(vglobal,&(dvm->exception_index ));
	vglobal=m->getGlobalVariable("beo");
	TheExecutionEngine->addGlobalMapping(vglobal,&(dvm->current_exception));	
	vglobal=m->getGlobalVariable("bsp");
	TheExecutionEngine->addGlobalMapping(vglobal,&(dvm->stack.stack_pointer));
	vglobal=m->getGlobalVariable("bbp");
	TheExecutionEngine->addGlobalMapping(vglobal,&(dvm->stack.stack));
	vglobal=m->getGlobalVariable("arr_is_pointer");
	TheExecutionEngine->addGlobalMapping(vglobal,&(dvm->stack.pointer_flags));
	vglobal=m->getGlobalVariable("retvar");
	TheExecutionEngine->addGlobalMapping(vglobal,&(dvm->retvar));
	vglobal=m->getGlobalVariable("pstatic");
	TheExecutionEngine->addGlobalMapping(vglobal,&(ee->static_v.variable)); 
	vglobal=m->getGlobalVariable("pthis");
	TheExecutionEngine->addGlobalMapping(vglobal,&(dvm->ths));	

	Function *f;
	f=m->getFunction("string!LoadStringFromPool");
	TheExecutionEngine->addGlobalMapping(f,ExLoadStringFromPool);

	f=m->getFunction("string!ChainString");
	TheExecutionEngine->addGlobalMapping(f,ExChainString);

	f=m->getFunction("string!CompareString");
	TheExecutionEngine->addGlobalMapping(f,ExCompareString);

	f=m->getFunction("object!CompareObject");
	TheExecutionEngine->addGlobalMapping(f,ExCompareObject);
	f=m->getFunction("system!IntToStr");
	TheExecutionEngine->addGlobalMapping(f,ExIntToStr);
	f=m->getFunction("system!BoolToStr");
	TheExecutionEngine->addGlobalMapping(f,ExBoolToStr);
	f=m->getFunction("system!DoubleToStr");
	TheExecutionEngine->addGlobalMapping(f,ExDoubleToStr);
	f=m->getFunction("system!NewDelegate");
	TheExecutionEngine->addGlobalMapping(f,ExNewDelegate);
	f=m->getFunction("system!InvokeDelegate");
	TheExecutionEngine->addGlobalMapping(f,ExInvokeDelegate);

	f=m->getFunction("system!GetSuper");
	TheExecutionEngine->addGlobalMapping(f,ExGetSuper);
	f=m->getFunction("system!ArrGeti");
	TheExecutionEngine->addGlobalMapping(f,ExArrGeti);
	f=m->getFunction("system!ArrGetd");
	TheExecutionEngine->addGlobalMapping(f,ExArrGetd);
	f=m->getFunction("system!ArrGeto");
	TheExecutionEngine->addGlobalMapping(f,ExArrGeto);
	f=m->getFunction("system!ArrGetCh");
	TheExecutionEngine->addGlobalMapping(f,ExArrGetCh);
	f=m->getFunction("system!ArrPuti");
	TheExecutionEngine->addGlobalMapping(f,ExArrPuti);
	f=m->getFunction("system!ArrPutd");
	TheExecutionEngine->addGlobalMapping(f,ExArrPutd);
	f=m->getFunction("system!ArrPuto");
	TheExecutionEngine->addGlobalMapping(f,ExArrPuto);

	f=m->getFunction("system!FldGeti");
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
	TheExecutionEngine->addGlobalMapping(f,ExFldPuto);

	f=m->getFunction("system!ArrayLiteral");
	TheExecutionEngine->addGlobalMapping(f,ExArrayLiteral);
	f=m->getFunction("system!NewArray");
	TheExecutionEngine->addGlobalMapping(f,ExNewArray);
	f=m->getFunction("object!New");
	TheExecutionEngine->addGlobalMapping(f,ExNew);
	f=m->getFunction("system!Invoke");
	TheExecutionEngine->addGlobalMapping(f,ExInvoke);
	f=m->getFunction("system!Call");
	TheExecutionEngine->addGlobalMapping(f,ExCall);
	f=m->getFunction("system!Failure");
	TheExecutionEngine->addGlobalMapping(f,ExFailure);
	f=m->getFunction("system!PushException");
	TheExecutionEngine->addGlobalMapping(f,ExPushJumpBuffer);
	f=m->getFunction("system!Raise");
	TheExecutionEngine->addGlobalMapping(f,ExRaiseException);
	f=m->getFunction("system!Setjmp");
	TheExecutionEngine->addGlobalMapping(f,setjmp);
	f=m->getFunction("system!LeaveTry");
	TheExecutionEngine->addGlobalMapping(f,ExLeaveTry);
	f=m->getFunction("system!DoInvoke");
	TheExecutionEngine->addGlobalMapping(f,ExDoInvoke);
	f=m->getFunction("autovar!get");
	TheExecutionEngine->addGlobalMapping(f,AvGetVar);
	f=m->getFunction("autovar!getorcreate");
	TheExecutionEngine->addGlobalMapping(f,AvGetOrCreateVar);
	/*ext=m->getFunction("ext");
	bbp=m->getGlobalVariable("bbp");
	TheExecutionEngine->addGlobalMapping(ext,aaa);
	TheExecutionEngine->addGlobalMapping(bsp,&a);
	TheExecutionEngine->addGlobalMapping(bbp,&ps);
	F=m->getFunction("HEHE");
//	__asm int 3
	void *FPtr = TheExecutionEngine->getPointerToFunction(F);
	typedef int (*ptFun)(int);
	ptFun p=(ptFun)FPtr;
	*/
	return TheExecutionEngine;
}
