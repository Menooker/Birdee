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
#include "..\..\include\DVM.h"


#ifdef __cplusplus
extern "C"
{
#endif

void AvGets();
void AvGetd();
void AvGeti();
void AvSeti();
void AvSetd();
void AvSets();
void AvCopyVar();
void AvAdd();
void AvSub();
void AvMul();
void AvDiv();
void AvMod();
void AvCmp();
DVM_ObjectRef AvGetVar(char* name);
DVM_ObjectRef AvGetOrCreateVar(char* name);
void AvDisposeMap();
#ifdef __cplusplus
}
#endif

#endif