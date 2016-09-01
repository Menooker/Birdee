#include "BdSocket.h"
#include <stdio.h>
#include <string.h>
//fix-me : close all sockets when closing the dvm
//fix-me : close the sockets when GC
#ifdef BD_ON_WINDOWS
int RcWinsockStartup()
{
    WORD sockVersion = MAKEWORD(2,2);
    WSADATA wsaData;
    if(WSAStartup(sockVersion, &wsaData)!=0)
    {
        return 1;
    }
	return 0;
}
//called when initialized
int RcStartipRet=RcWinsockStartup();
#endif


void RcSetTCPNoDelay(SOCKET fd)
{
    int enable = 1;
    setsockopt(fd, IPPROTO_TCP, TCP_NODELAY, (const char*)&enable, sizeof(enable));
}

SOCKET RcConnect(char* ip,int port)
{
	SOCKET sclient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(sclient == INVALID_SOCKET)
	{
		return NULL;
	}

	sockaddr_in serAddr;
	memset(&serAddr,0,sizeof(serAddr));
	serAddr.sin_family = AF_INET;
	serAddr.sin_port = htons(port);
#ifdef BD_ON_WINDOWS
	serAddr.sin_addr.S_un.S_addr = inet_addr(ip);
#else
    serAddr.sin_addr.s_addr = inet_addr(ip);
#endif
	if (connect(sclient, (sockaddr *)&serAddr, sizeof(serAddr)) == SOCKET_ERROR)
	{
		closesocket(sclient);
		return NULL;
	}
	return (SOCKET)sclient;
}

SOCKET RcCreateListen(int port)
{
    SOCKET slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    int reuse = 1;
    if (setsockopt(slisten, SOL_SOCKET, SO_REUSEADDR, (const char*)&reuse, sizeof(reuse)) < 0)
        perror("setsockopt(SO_REUSEADDR) failed");

#ifdef SO_REUSEPORT
	reuse = 1;
    if (setsockopt(slisten, SOL_SOCKET, SO_REUSEPORT, (const char*)&reuse, sizeof(reuse)) < 0) 
        perror("setsockopt(SO_REUSEPORT) failed");
#endif
    if(slisten == INVALID_SOCKET)
    {
        printf("socket error ! \n");
        return 0;
    }

    //绑定IP和端口
    sockaddr_in sin;
	memset(&sin,0,sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(port);
#ifdef BD_ON_WINDOWS
    sin.sin_addr.S_un.S_addr = INADDR_ANY;
#else
    sin.sin_addr.s_addr = INADDR_ANY;
#endif
    if(bind(slisten, (LPSOCKADDR)&sin, sizeof(sin)) == SOCKET_ERROR)
    {
        printf("bind error !");
		return 0;
    }

    //开始监听
    if(listen(slisten, 5) == SOCKET_ERROR)
    {
        printf("listen error !");
        return 0;
    }
	return (SOCKET)slisten;
}

SOCKET RcListen(int port)
{
    SOCKET slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    int reuse = 1;
    if (setsockopt(slisten, SOL_SOCKET, SO_REUSEADDR, (const char*)&reuse, sizeof(reuse)) < 0)
        perror("setsockopt(SO_REUSEADDR) failed");

#ifdef SO_REUSEPORT
	reuse = 1;
    if (setsockopt(slisten, SOL_SOCKET, SO_REUSEPORT, (const char*)&reuse, sizeof(reuse)) < 0) 
        perror("setsockopt(SO_REUSEPORT) failed");
#endif
    if(slisten == INVALID_SOCKET)
    {
        printf("socket error ! \n");
        return 0;
    }

    //绑定IP和端口
    sockaddr_in sin;
	memset(&sin,0,sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(port);
#ifdef BD_ON_WINDOWS
    sin.sin_addr.S_un.S_addr = INADDR_ANY;
#else
    sin.sin_addr.s_addr = INADDR_ANY;
#endif
    if(bind(slisten, (LPSOCKADDR)&sin, sizeof(sin)) == SOCKET_ERROR)
    {
        printf("bind error !");
		return 0;
    }

    //开始监听
    if(listen(slisten, 5) == SOCKET_ERROR)
    {
        printf("listen error !");
        return 0;
    }

    //循环接收数据
    sockaddr_in remoteAddr;
#ifdef BD_ON_WINDOWS
    int nAddrlen = sizeof(remoteAddr);
#else
	unsigned int nAddrlen = sizeof(remoteAddr);
#endif
    printf("port %d waiting for connections...\n",port);
    SOCKET sClient = accept(slisten, (LPSOCKADDR)&remoteAddr, &nAddrlen);
    if(sClient == INVALID_SOCKET)
    {
        printf("accept error !");
        return 0;
    }
    printf("port %d accepted ：%s \n", port , inet_ntoa(remoteAddr.sin_addr));
	closesocket(slisten);
	return (SOCKET)sClient;
}

SOCKET RcAccept(SOCKET slisten)
{
    sockaddr_in remoteAddr;
#ifdef BD_ON_WINDOWS
    int nAddrlen = sizeof(remoteAddr);
#else
	unsigned int nAddrlen = sizeof(remoteAddr);
#endif
    SOCKET sClient = accept(slisten, (LPSOCKADDR)&remoteAddr, &nAddrlen);
    if(sClient == INVALID_SOCKET)
    {
        printf("accept error !");
        return 0;
    }
	return (SOCKET)sClient;
}