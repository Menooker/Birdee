#ifndef _H_BIRDEE_DYNLDR
#define _H_BIRDEE_DYNLDR

#define BIRDEE_LIB_SUFFIX ("BDL")

#ifdef __cplusplus
extern "C"
{
#endif
#include "../../dvm/dvm_pri.h"

DVM_ExecutableItem* LdLoadPackage(DVM_VirtualMachine *dvm,char* libname,char* packagename);

#ifdef __cplusplus
}
#endif

#endif