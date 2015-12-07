#ifndef _H_REMOTE_CONTROL
#define _H_REMOTE_CONTROL
#include "BdExec.h"
#ifdef __cplusplus
extern "C"
{
#endif

BD_SOCKET RcConnect(char* ip,int port);
BD_SOCKET RcListen(int port);
void RcConnectNode(DVM_Value *args);
void RcCreateThread(DVM_Value *args);
int RcSendModule(BD_SOCKET s,char* path);
int RcRecvModule(BD_SOCKET s,char* name,size_t len,char* path);
void RcSlave(int port);
int RcMasterHello(BD_SOCKET s);
void RcCloseNode(DVM_Value *args);
#ifdef __cplusplus
}
#endif

#endif