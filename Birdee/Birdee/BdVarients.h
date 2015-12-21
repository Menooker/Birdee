#ifndef _H_BIRDEE_VARIENTS
#define _H_BIRDEE_VARIENTS

/*typedef enum
{
	AV_INT=1,
	AV_DOUBLE,
	AV_STRING,
	AV_OBJECT
}AvType;*/
#include "BirdeeDef.h"
#include "DVM.h"


#ifdef __cplusplus
extern "C"
{
#endif


#define AvGetTopContext() (curthread->avstack[curthread->asp -1])
void AvPushNullContext();
void AvPopContext();
void AvGets();
void AvGetd();
void AvGeti();
void AvSeti();
void AvSetd();
void AvSets();
void AvNewi();
void AvNewd();
void AvNews();
void AvCopyVar();
void AvAdd();
void AvSub();
void AvMul();
void AvDiv();
void AvMod();
void AvCmp();
void AvGetVar(char* name);
void AvGetOrCreateVar(char* name);
void AvDisposeMainMap();
#ifdef __cplusplus
}
#endif

#endif
