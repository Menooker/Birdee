#ifndef _H_BIRDEE_DYNLDR
#define _H_BIRDEE_DYNLDR

#ifdef __cplusplus
extern "C"
{
#endif
#include "BdExec.h"

BINT SoGeti(uint key,uint fldid);
double SoGetd(uint key,uint fldid);
BINT SoGeto(uint key,uint fldid);
DVM_ObjectRef SoGets(uint key,uint fldid);
void SoSeti(uint key,uint fldid,BINT v);
void SoSetd(uint key,uint fldid,double v);
void SoSeto(uint key,uint fldid,uint v);
void SoSets(uint key,uint fldid,DVM_ObjectRef v);
void SoNewModule(uint key,int cnt);
uint SoNew(int idx_in_exe,int methodid);

#ifdef __cplusplus
}
#endif

#endif