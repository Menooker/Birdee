#ifndef _H_BIRDEE_LOADER
#define _H_BIRDEE_LOADER
#include "BirdeeDef.h"
#include "DKC.h"

#ifdef __cplusplus
extern "C"
{
#endif
BdStatus LdLoadCode(char* path,DVM_ExecutableList* exelist );
BINT LdExecutable(DVM_Executable* exe,FILE* f);

#ifdef __cplusplus
}
#endif

#endif
