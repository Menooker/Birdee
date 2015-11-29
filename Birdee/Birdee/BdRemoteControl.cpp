#include "BdRemoteControl.h"
#include <stdio.h>
#include "BirdeeDef.h"
#include "BdExec.h"
#include "BdException.h"
#include "BdParameters.h"
#include "Loader.h"
#include "../../debug/debug.h"
#include <vector>
#ifdef BD_ON_WINDOWS
	#include <WinSock.h>
	#pragma comment(lib, "WS2_32") 
#else
	int a[-1];
#endif

#define RC_MAGIC_FILE_HEADER 0xea12ff08
#define RC_MAGIC_MASTER 0x12345edf
#define RC_MAGIC_SLAVE 0x33450f0e

extern "C" std::vector<std::string> LoadedModFiles; //@BdLoader.cpp

struct MasterInfo
{
	int32 magic; 
	uint32 mod_cnt;
};

struct FileHeader
{
	int32 magic;
	uint32 size;
	uint32 name_len; //size of the name, including \0
};

struct SlaveInfo
{
	int magic;
};

//fix-me : close all sockets when closing the dvm
//fix-me : close the sockets when GC

void RcThrowSocketError()
{
	_BreakPoint
}

BD_SOCKET RcConnect(char* ip,int port)
{
	SOCKET sclient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(sclient == INVALID_SOCKET)
	{
		return NULL;
	}

	sockaddr_in serAddr;
	serAddr.sin_family = AF_INET;
	serAddr.sin_port = htons(port);
	serAddr.sin_addr.S_un.S_addr = inet_addr(ip); 
	if (connect(sclient, (sockaddr *)&serAddr, sizeof(serAddr)) == SOCKET_ERROR)
	{
		closesocket(sclient);
		return NULL;
	}
	return (BD_SOCKET)sclient;
}

BD_SOCKET RcListen(int port)
{
    SOCKET slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); //fix-me : need to close slisten?
    if(slisten == INVALID_SOCKET)
    {
        printf("socket error !");
        return 0;
    }

    //绑定IP和端口
    sockaddr_in sin;
    sin.sin_family = AF_INET;
    sin.sin_port = htons(port);
    sin.sin_addr.S_un.S_addr = INADDR_ANY; 
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
    int nAddrlen = sizeof(remoteAddr);
    printf("port %d waiting for connections...\n",port);
    SOCKET sClient = accept(slisten, (SOCKADDR *)&remoteAddr, &nAddrlen);
    if(sClient == INVALID_SOCKET)
    {
        printf("accept error !");
        return 0;
    }
    printf("port %d accepted ：%s \n", port , inet_ntoa(remoteAddr.sin_addr));
	return (BD_SOCKET)sClient;
}

int node_class_index=-1;
void RcConnectNode(DVM_Value *args)
{
    DVM_Object  *ip;
    ip = args[0].object.data ;
    DBG_assert(ip->type == STRING_OBJECT, ("ip->type..%d", ip->type));	
	char* buf=(char*)malloc(ip->u.string.length+1);
	wcstombs(buf,ip->u.string.string,ip->u.string.length+1);
	SOCKET s=(SOCKET)RcConnect(buf,args[1].int_value);

	free(buf);
	if(s==0)
	{
		RcThrowSocketError();
	}
	if(node_class_index==-1)
		node_class_index=DVM_search_class(curdvm,"diksam.lang", "RemoteNode");
	DVM_ObjectRef obj=dvm_create_class_object_i(curdvm,node_class_index);
	obj.data->u.class_object.field[0].object=args[0].object;
	obj.data->u.class_object.field[1].int_value=args[1].int_value;
	obj.data->u.class_object.field[2].int_value=(int)s; //fix-me : 64 bit?
	curthread->retvar.object = obj; 
	
}


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



int RcSendModule(BD_SOCKET s,char* path)
{
	FILE* f=fopen(path,"rb");
	if(!f)
		return 1;
	fseek(f,0L,SEEK_END);
	long len=ftell(f);
	fseek(f,0L,SEEK_SET);
	
	char* finda=strrchr(path,'/');
	char* findb=strrchr(path,'\\');
	char* found;
	if(finda>findb)
		found=finda;
	else
		found=findb;
	if(!found)
		found=path;
	size_t nlen=strlen(path)+1;
	FileHeader fh={RC_MAGIC_FILE_HEADER,len,nlen};
	RcSend(s,&fh,sizeof(fh));
	RcSend(s,found,nlen);

	char buf[1024];
	size_t expect_s;
	while(len>0)
	{
		expect_s=(sizeof(buf)>len)? len : sizeof(buf);
		if(fread(buf,expect_s,1,f)!=expect_s)
		{
			fclose(f);
			return 2;
		}
		RcSend(s,buf,expect_s);
		len-=expect_s;
	}
	fclose(f);
	return 0;
}

int RcRecvModule(BD_SOCKET s,char* name,size_t len,char* path)
{
	size_t remaining=len;
	int buflen;
	char buf[1024];

	size_t lenp=strlen(parameters.RemoteModulePath)+strlen(name);
	if(lenp>255)
		return 2;
	strcpy(path,parameters.RemoteModulePath);
	strcat(path,name);
	FILE* f=fopen(path,"wb+");
	if(!f)
		return 3;
	while(remaining>0)
	{
		buflen = RcRecv(s, buf, ( remaining>sizeof(buf) ) ? sizeof(buf):remaining);
		if(buflen <= 0)
		{
			return 1;
		}
		fwrite(buf,buflen,1,f);
		remaining-=buflen;
	}
	fclose(f);
}

void RcSlave(int port)
{
	BD_SOCKET s=RcListen(port);
	printf("Waiting for hand shaking...\n");
	MasterInfo mi;
	SlaveInfo si;
	si.magic=RC_MAGIC_SLAVE;
	RcSend(s,&si,sizeof(si));
	int cnt=RcRecv(s,&mi,sizeof(mi));
	if(cnt==sizeof(mi) && mi.magic!=RC_MAGIC_MASTER)
	{
		char path[255];
		char mainmod[255];
		if(mi.mod_cnt<=0)
			goto ERR;
		for(int i=0;i<mi.mod_cnt;i++)
		{
			FileHeader fh;
			cnt=RcRecv(s,&fh,sizeof(fh));
			if(cnt!=sizeof(fh) || fh.magic!=RC_MAGIC_FILE_HEADER)
				goto ERR;
			char* name =(char*)malloc(fh.name_len);
			cnt=RcRecv(s,name,fh.name_len);
			if(cnt!=fh.name_len)
			{
				free(name);
				goto ERR;
			}
			name[fh.name_len-1]=0;
			if(RcRecvModule(s,name,fh.size,path)!=0)
			{
				free(name);
				goto ERR;
			}
			if(i==0)
				strncpy(mainmod,path,255);
		}
	}
	else
	{
ERR:
		printf("Hand shaking error!\n");
		RcCloseSocket(s);
	}
}

int RcMasterHello(BD_SOCKET s)
{
	SlaveInfo si;
	if(RcRecv(s,&si,sizeof(si))!=sizeof(si))
	{
		return 1;
	}
	if(si.magic!=RC_MAGIC_SLAVE)
	{
		return 2;
	}
	MasterInfo mi={RC_MAGIC_MASTER,1};
	RcSend(s,&mi,sizeof(mi));
	std::vector<std::string>::iterator itr;
	for(itr=LoadedModFiles.begin();itr!=LoadedModFiles.end();itr++)
	{
		int ret=RcSendModule(s,(char*) (*itr).c_str());
		if(ret)
			return ret+3;
	}

	return 0;
}