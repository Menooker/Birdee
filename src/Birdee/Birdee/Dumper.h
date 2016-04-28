#include "BirdeeDef.h"
#ifndef _H_DUMPER
#define _HDUMPER

#include "DKC.h"
#ifdef __cplusplus
extern "C"
{
#endif
BdStatus CpDumpBuffer(void* pArr,BINT size,CPBuffer* pbuf);
void CpDisplayBuffer(CPBuffer* p,int s);
BdStatus CpSaveCodeToFile(char* path,DVM_ExecutableList* exelist );
BINT CpDumpExecutable(DVM_Executable* exe,FILE* f);

#ifdef __cplusplus
}
#endif
#endif
