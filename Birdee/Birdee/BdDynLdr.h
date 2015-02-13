#ifndef _H_BIRDEE_DYNLDR
#define _H_BIRDEE_DYNLDR

#define BIRDEE_LIB_SUFFIX (".bdl")

#ifdef __cplusplus
extern "C"
{
#endif
#include "../../dvm/dvm_pri.h"

DVM_ExecutableItem* LdLoadPackage(DVM_VirtualMachine *dvm,char* libname,char* packagename);
ExecutableEntry* LdGetLoadedModule(char* name);
ExecutableEntry* LdPushModule(char* name,ExecutableEntry* ee);
ExecutableEntry* LdGetLoadedRequiredModule(char* name);
ExecutableEntry* LdPushRequiredModule(char* name,ExecutableEntry* ee);

#ifdef __cplusplus
}
#endif

#endif