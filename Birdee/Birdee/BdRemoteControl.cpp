#include "BdRemoteControl.h"
#include <stdio.h>
#include "BirdeeDef.h"
#include "BdExec.h"
#include "BdException.h"
#include "BdParameters.h"
#include "Loader.h"
#include "debug.h"
#include <vector>
#include <time.h>
#include "BdThread.h"
#include <string>
#include <string.h>
#include "BdSharedObj.h"
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

enum RcCommand
{
	RcCmdClose=1,
	RcCmdCreateThread,
	RcCmdSuspendThread,
	RcCmdStopThread,
};
struct RcCommandPack
{
	RcCommand cmd;
	int param;
	int param2;
	union
	{
		struct
		{
			int param3;
			int param4;
		};
		long long param34;
	};
};
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

void RcThrowSocketError()
{
	_BreakPoint
}

void RcThrowSocketError(int err)
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
	return (BD_SOCKET)sclient;
}

BD_SOCKET RcListen(int port)
{
    SOCKET slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); //fix-me : need to close slisten?
    if(slisten == INVALID_SOCKET)
    {
        printf("socket error ! \n");
        return 0;
    }

    //��IP�Ͷ˿�
    sockaddr_in sin;
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

    //��ʼ����
    if(listen(slisten, 5) == SOCKET_ERROR)
    {
        printf("listen error !");
        return 0;
    }

    //ѭ����������
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
    printf("port %d accepted ��%s \n", port , inet_ntoa(remoteAddr.sin_addr));
	return (BD_SOCKET)sClient;
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

int node_class_index=-1;
void RcConnectNode(DVM_Value *args)
{
    DVM_Object  *ip;
    ip = args[1].object.data ;
    DBG_assert(ip->type == STRING_OBJECT, ("ip->type..%d", ip->type));
	char* buf=(char*)malloc(ip->u.string.length+1);
	wcstombs(buf,ip->u.string.string,ip->u.string.length+1);
	SOCKET s=(SOCKET)RcConnect(buf,args[0].int_value);
	free(buf);
	RcMasterHello((BD_SOCKET)s);
	if(s==0)
	{
		RcThrowSocketError();
	}
	if(node_class_index==-1)
		node_class_index=DVM_search_class(curdvm,"Remote", "RemoteNode");
	DVM_ObjectRef obj=dvm_create_class_object_i(curdvm,node_class_index);
	obj.data->u.class_object.field[0].object=args[1].object;
	obj.data->u.class_object.field[1].int_value=args[0].int_value;
	obj.data->u.class_object.field[2].int_value=(int)s; //fix-me : 64 bit?
	obj.data->u.class_object.field[3].int_value=DVM_FALSE; //closed
	obj.data->u.class_object.field[4].int_value=DVM_TRUE; //connected
	curthread->retvar.object = obj;

}


int RcSendCmd(BD_SOCKET s,RcCommandPack* cmd)
{
	int ret=RcSend(s,cmd,sizeof(RcCommandPack));
	if(ret==SOCKET_ERROR)
	{
#ifdef BD_ON_WINDOWS
		return WSAGetLastError();
#else
		return errno;
#endif
	}
	return 0;
}

void RcCloseNode(DVM_Value *args)
{
	DVM_ObjectRef obj=args->object;
	RcCommandPack cmd={RcCmdClose,0};
	int ret=RcSendCmd((BD_SOCKET)obj.data->u.class_object.field[2].int_value,&cmd);
	if(ret)
		RcThrowSocketError(ret);
	obj.data->u.class_object.field[3].int_value=DVM_TRUE; //closed
	obj.data->u.class_object.field[4].int_value=DVM_FALSE; //connected
}


int idx_remote_thread=-1;
int method_remote_thread=-1;
void RcCreateThread(DVM_Value *args)
{
	int idx= args[1].object.data->u.delegate.index;

	if(idx_remote_thread==-1)
		idx_remote_thread  = DVM_search_class(curdvm,"Remote","RemoteThread");
	if(method_remote_thread==-1)
		method_remote_thread = ExGetMethodIndex(curdvm->bclass[idx_remote_thread],"initialize");

	DVM_ObjectRef ret=SoDoNew(idx_remote_thread,method_remote_thread);
	RcCommandPack cmd={RcCmdCreateThread,idx,args[0].int_value};
	cmd.param3=(int)ret.data;
	SoSeti((_uint)ret.data,1,RC_THREAD_CREATING);//set the state
	DVM_ObjectRef obj=args[2].object;
	int sret=RcSendCmd((BD_SOCKET)obj.data->u.class_object.field[2].int_value,&cmd);
	if(sret)
		RcThrowSocketError(sret);
	curthread->retvar.object=ret;
	return ;
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
	else
		found++;
	size_t nlen=strlen(found)+1;
	FileHeader fh={RC_MAGIC_FILE_HEADER,len,nlen};
	RcSend(s,&fh,sizeof(fh));
	RcSend(s,found,nlen);

	char buf[1024];
	size_t expect_s;
	while(len>0)
	{
		expect_s=(sizeof(buf)>len)? len : sizeof(buf);
		if(fread(buf,expect_s,1,f)!=1)
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
	printf("Receiving %s size=%d\n",name,len);
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
	printf("Received %s\n",name);
	fclose(f);
	return 0;
}

void RcSlaveMainLoop(char* path,BD_SOCKET s)
{
	DVM_ExecutableList *list;
	DVM_VirtualMachine *dvm;
	BdStatus status;
	DVM_ObjectRef paramvar;
	DVM_ExecutableList* plist=(DVM_ExecutableList*)MEM_malloc(sizeof(DVM_ExecutableList));
	plist->list=0;plist->top_level=0;

	dvm = DVM_create_virtual_machine();
	ExInitEngine();
	status=LdLoadCode(path,plist);
	if(status)
	{
		printf("ERROR Loading Code %d\n",status);
		goto ERR;
	}
	else
	{
		DVM_set_executable(dvm, plist); //modified
		dvm->mainvm->current_executable = dvm->top_level;
		ExSetCurrentDVM(dvm);
		dvm->is_master=0;
		srand((unsigned)time(NULL));
		DVM_Executable* exe=curdvm->top_level->executable;
		curthread->current_executable =curdvm->top_level;
		for(;;)
		{
			RcCommandPack cmd;
			int ret = RcRecv(s,&cmd,sizeof(cmd));
			if(ret!=sizeof(cmd))
			{
				printf("Socket error!\n");
				break;
			}
			switch(cmd.cmd)
			{
			case RcCmdClose:
				printf("Closing!\n");
				goto CLOSE;
				break;
			case RcCmdCreateThread:
				SoSeti(cmd.param3,1,RC_THREAD_RUNNING);//set the state
				paramvar=ExCreateVar(curdvm,NULL);
				paramvar.data->u.var.pobj->type=AV_INT;
				paramvar.data->u.var.pobj->v.int_value=cmd.param2;
#ifdef BD_ON_VC
				curthread->stack.stack_pointer->object=paramvar;
				curthread->stack.stack_pointer++;
				*curthread->stack.flg_sp=DVM_TRUE;
				curthread->stack.flg_sp++;
				ExDoInvoke(cmd.param);
				SoSeti(cmd.param3,1,RC_THREAD_DEAD);//set the state
#else
				ThDoCreateThread(cmd.param,paramvar,cmd.param3);
#endif
				break;
			default:
				printf("Unknown command %d\n",cmd.cmd);
			}
		}
CLOSE:
		MEM_check_all_blocks();
		MEM_dump_blocks(stdout);
	}
	ThStopAllThreads();
ERR:
	DVM_dispose_virtual_machine(dvm);
	DVM_dispose_executable_list(plist); //*/
	return;
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
	int err=0,err2=0;
	if(cnt==sizeof(mi) && mi.magic==RC_MAGIC_MASTER)
	{
		char path[255];
		char mainmod[255];
		err=1;
		if(mi.mod_cnt<=0)
			goto ERR;
		printf("Module file count %d\n",mi.mod_cnt);
		for(int i=0;i<mi.mod_cnt;i++)
		{
			FileHeader fh;
			cnt=RcRecv(s,&fh,sizeof(fh));
			err=2;
			if(cnt!=sizeof(fh) || fh.magic!=RC_MAGIC_FILE_HEADER)
				goto ERR;
			char* name =(char*)malloc(fh.name_len);
			cnt=RcRecv(s,name,fh.name_len);
			if(cnt!=fh.name_len)
			{
			    err=3;
				free(name);
				goto ERR;
			}
			name[fh.name_len-1]=0;
			err2=RcRecvModule(s,name,fh.size,path);
			if(err2!=0)
			{
			    err=4;
				free(name);
				goto ERR;
			}
			if(i==0)
				strncpy(mainmod,path,255);

		}
		printf("All modules received, waiting for command");
		RcSlaveMainLoop(mainmod,s);
	}
	else
	{
ERR:
		printf("Hand shaking error! %d %d\n",err,err2);
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
	MasterInfo mi={RC_MAGIC_MASTER,LoadedModFiles.size()};
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