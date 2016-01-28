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

BD_SOCKET RcConnect(char* ip,int port);
BD_SOCKET RcListen(int port);


inline int RcSend(BD_SOCKET s,void* data,size_t len)
{
	return send((SOCKET)s,(char*)data,len,0);
}

inline int RcRecv(BD_SOCKET s,void* data,size_t len)
{
	return recv((SOCKET)s,(char*)data,len, 0);
}

inline int RcCloseSocket(BD_SOCKET s)
{
	return closesocket((SOCKET)s);
}