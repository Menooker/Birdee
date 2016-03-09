#ifndef _H_REMOTE_CONTROL
#define _H_REMOTE_CONTROL
#include "BdExec.h"
#ifdef __cplusplus
extern "C"
{
#endif

SOCKET RcConnect(char* ip,int port);
SOCKET RcListen(int port);
void RcConnectNode(DVM_Value *args);
void RcCreateThread(DVM_Value *args);
int RcSendModule(SOCKET s,char* path);
int RcRecvModule(SOCKET s,char* name,size_t len,char* path);
void RcSlave(int port);
void RcCloseNode(DVM_Value *args);
inline void RcWaitForGCMarkCompletion();
inline void RcTriggerGC();
#ifdef __cplusplus
}
#endif

#endif