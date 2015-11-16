#ifndef _H_BIRDEE_DYNLDR
#define _H_BIRDEE_DYNLDR

#ifdef __cplusplus
extern "C"
{
#endif
#include "BdExec.h"

BINT SoGeti(uint key);
double SoGetd(uint key);
BINT SoGeto(uint key);
DVM_ObjectRef SoGets(uint key);
void SoSeti(uint key,BINT v);
void SoSetd(uint key,double v);
void SoSeto(uint key,uint v);
void SoSets(uint key,DVM_ObjectRef v);

#ifdef __cplusplus
}
#endif

#endif