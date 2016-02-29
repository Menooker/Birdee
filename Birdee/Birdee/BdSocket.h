#include "BirdeeDef.h"
#ifdef BD_ON_WINDOWS
	#include <WinSock.h>
	#pragma comment(lib, "WS2_32")
#endif
#ifdef BD_ON_LINUX
    #include <arpa/inet.h>
    #include <sys/socket.h>
    #include <errno.h>
    #define SOCKET int
    #define INVALID_SOCKET (-1)
    #define SOCKET_ERROR (-1)
    #define closesocket close
    typedef sockaddr* LPSOCKADDR;
#endif


#ifdef __cplusplus
extern "C"
{
#endif
void RcSetTCPNoDelay(SOCKET fd);
SOCKET RcConnect(char* ip,int port);
SOCKET RcListen(int port);
SOCKET RcCreateListen(int port);
#ifdef __cplusplus
}
#endif

inline int RcSend(SOCKET s,void* data,size_t len)
{
	return send((SOCKET)s,(char*)data,len,0);
}

inline int RcRecv(SOCKET s,void* data,size_t len)
{
	return recv((SOCKET)s,(char*)data,len, 0);
}

inline int RcCloseSocket(SOCKET s)
{
	return closesocket((SOCKET)s);
}