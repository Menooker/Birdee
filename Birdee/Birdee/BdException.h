#ifndef _H_BIRDEE_EXCEPTION
#define _H_BIRDEE_EXCEPTION

#include <setjmp.h>
#include "BirdeeDef.h"
#include "../../include/DVM.h"

typedef struct
{
	jmp_buf buf;
}ExJumpBuf,*PExJumpBuf;
typedef struct {
    ExJumpBuf jmpbuf;
	DVM_ObjectRef ths;
	DVM_ObjectRef cur_exception;
	void* exe;
	int asp;
} ExExceptionItem,*PExExceptionItem;



#ifdef __cplusplus
extern "C"
{
#endif

ExJumpBuf*  ExPushJumpBuffer();
void ExUncaughtException();
void ExRaiseException(BINT eindex);
void ExLeaveTry();
void ExNullPointerException();
void ExStackTrace(DVM_ObjectRef e);

#ifdef __cplusplus
}
#endif

enum ExExceptions{
	ExVarStringOpNotSupported=1,
	ExVarUseBeforeSet,
	ExVarBadStringForNumber,
	ExBadParameterType,
	ExFunctionNotFound,
	ExBadParameterNum,
	ExBadFunctionIndex
};

#endif