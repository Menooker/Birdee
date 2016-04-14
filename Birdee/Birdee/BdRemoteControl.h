#ifndef _H_REMOTE_CONTROL
#define _H_REMOTE_CONTROL
#include "BdExec.h"
#include "BdSocket.h"
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
void RcWaitForGCMarkCompletion();
void RcTriggerGC(int round_id);
void RcEnterBarrier(DVM_Value *args);
#ifdef __cplusplus
}
#endif

#endif
