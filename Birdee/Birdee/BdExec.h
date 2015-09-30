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

typedef enum {
    INSERT_INDEX_OUT_OF_BOUNDS_ERR,
    REMOVE_INDEX_OUT_OF_BOUNDS_ERR,
    STRING_POS_OUT_OF_BOUNDS_ERR,
    STRING_SUBSTR_LEN_ERR,
    FOPEN_1ST_ARG_NULL_ERR,
    FOPEN_2ND_ARG_NULL_ERR,
    FGETS_ARG_NULL_ERR,
    FGETS_FP_BAD_TYPE_ERR,
    FGETS_FP_INVALID_ERR,
    FGETS_BAD_MULTIBYTE_CHARACTER_ERR,
    FPUTS_2ND_ARG_NULL_ERR,
    FPUTS_FP_BAD_TYPE_ERR,
    FPUTS_FP_INVALID_ERR,
    FCLOSE_ARG_NULL_ERR,
    FCLOSE_FP_BAD_TYPE_ERR,
    FCLOSE_FP_INVALID_ERR,
    PARSE_INT_ARG_NULL_ERR,
    PARSE_INT_FORMAT_ERR,
    PARSE_DOUBLE_ARG_NULL_ERR,
    PARSE_DOUBLE_FORMAT_ERR,
    NATIVE_RUNTIME_ERROR_COUNT_PLUS_1
} NativeRuntimeError;

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
void ExInitThread(BdThread* t,void* mod,void *eng);
void ExLoadFunction(void* args,...);
void ExInitExeEngine();
void ExSetCurrentDVM(DVM_VirtualMachine *dvm);
void ExGoMain();
void  ExInvokeByName(DVM_Value* v);
void  ExGetFunction(DVM_Value* v);
void  ExRand(DVM_Value* v);
void ExGetClock(DVM_Value* v);
void ExGets();
void ExArraySize(DVM_Value *args);
void ExStringLength(DVM_Value *args);
DVM_ObjectRef ExCreateExceptionEx(DVM_VirtualMachine *dvm, char *class_name,BINT* clsindex,RuntimeError id, ...);
void ExFreeMCJIT(void* p);
void ExStringSubstr(DVM_Value *args);
void ExStringHash(DVM_Value *args);
void ExStringEquals(DVM_Value *args);
void ExStringTostr(DVM_Value *args);
void ExObjectHash(DVM_Value *args);
void ExObjectEquals(DVM_Value *args);
void ExObjectTostr(DVM_Value *args);
void ExArrayHash(DVM_Value *args);
void ExArrayEquals(DVM_Value *args);
void ExArrayTostr(DVM_Value *args);

void ExInitEngine();
BdThread* ExFreeThread(BdThread* t);
BdThread* ExCreateThread();
void ExInitRegArray(BdThread* t);
void ExInitThreadInAllModules();
void  ExDoInvoke(BINT transindex);
#ifdef __cplusplus
}
#endif



#endif