#ifndef _H_BIRDEE_EXEC
#define _H_BIRDEE_EXEC


enum ExValueType
{
	ExTypeNull,
	ExTypeNum,
    ExTypeString,
    ExTypeArray,
    ExTypeClsObj,
    ExTypePtr,
    ExTypeDelegate,
	ExTypeAutoVar,
};

#ifdef __cplusplus
extern "C"
{
#endif
#include "..\..\include\DVM.h"
#include "..\..\include\MEM.h"
#include "..\..\dvm\dvm_pri.h"
//#include "..\..\compiler\diksamc.h"
typedef struct ExecutableEntry_tag sExecutableEntry;
typedef struct ExecutableEntry_tag sExecutableEntry;
void* ExPrepareModule(struct LLVM_Data* mod,DVM_VirtualMachine *dvm,sExecutableEntry* ee);
void ExLoadFunction(void* args,...);
void ExInitExeEngine();
void ExSetCurrentDVM(DVM_VirtualMachine *dvm);
void ExGoMain();
void  ExInvokeByName(DVM_Value* v);
void  ExGetFunction(DVM_Value* v);
void  ExRand(DVM_Value* v);
void ExGetClock(DVM_Value* v);
void ExGets();
DVM_ObjectRef ExCreateExceptionEx(DVM_VirtualMachine *dvm, char *class_name,BINT* clsindex,RuntimeError id, ...);
void ExFreeMCJIT(void* p);
#ifdef __cplusplus
}
#endif



#endif