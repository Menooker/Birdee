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
#include "BdSocket.h"

#define RC_MAGIC_FILE_HEADER 0xea12ff08
#define RC_MAGIC_MASTER 0x12345edf
#define RC_MAGIC_SLAVE 0x33450f0e

extern "C" std::vector<std::string> LoadedModFiles; //@BdLoader.cpp
#ifndef BD_ON_VC
#pragma ms_struct on
#endif
struct MasterInfo
{
	int32 magic;
	uint32 mod_cnt;
	int32 num_mem_server;
	int32 num_nodes;
	int32 node_id;
	int32 localport;
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
	RcCmdTriggerGC,
	RcCmdDoGC,
};

#pragma pack(push)
#pragma pack(4)
struct RcCommandPack
{
	uint32 cmd;
	int32 param;
	int32 param2;
	union
	{
		struct
		{
			int32 param3;
			int32 param4;
		};
		long long param34;
	};
};
#pragma pack(pop)

#ifndef BD_ON_VC
#pragma ms_struct off
#endif


void RcThrowInvalidParametersError()
{
	_BreakPoint
}
void RcThrowSocketError()
{
	_BreakPoint
}

void RcThrowSocketError(int err)
{
	_BreakPoint
}



int node_class_index=-1;
std::vector<SOCKET> slavenodes;
int RcMasterHello(SOCKET s,std::vector<std::string>& hosts,std::vector<int>& ports,std::vector<std::string>& memhosts,std::vector<int>& memports,int node_id);

int RcDoConnectNode(DVM_ObjectRef host,int port,DVM_ObjectRef* out,int node_id,
	std::vector<std::string>& hosts,std::vector<int>& ports,std::vector<std::string>& memhosts,std::vector<int>& memports)
{
	SOCKET s=(SOCKET)RcConnect((char*)hosts[node_id].c_str(),port);
	if(s==0 || RcMasterHello((SOCKET)s,hosts,ports, memhosts, memports,node_id))
	{
		return 1;
	}
	slavenodes.push_back(s);
	DVM_ObjectRef obj=dvm_create_class_object_i(curdvm,node_class_index);
	obj.data->u.class_object.field[0].object = host;
	obj.data->u.class_object.field[1].int_value=port;
	obj.data->u.class_object.field[2].int_value=(int)s; //fix-me : 64 bit?
	obj.data->u.class_object.field[3].int_value=DVM_FALSE; //closed
	obj.data->u.class_object.field[4].int_value=DVM_TRUE; //connected

	*out=obj;
	return 0;
}

int RcSendCmd(SOCKET s,RcCommandPack* cmd);
void RcConnectNode(DVM_Value *args)
{
    DVM_Object  *ip,*port,*memhost,*memport;
	DVM_ObjectRef arr,obj;
	int localport;
	slavenodes.clear();
	localport = args[4].int_value ;

    ip = args[3].object.data ;
    DBG_assert(ip->type == ARRAY_OBJECT, ("ip->type..%d", ip->type));

	port = args[2].object.data ;
    DBG_assert(port->type == ARRAY_OBJECT, ("port->type..%d", port->type));

	memhost = args[1].object.data ;
    DBG_assert(memhost->type == ARRAY_OBJECT, ("memhost->type..%d", memhost->type));

	memport = args[0].object.data ;
    DBG_assert(memport->type == ARRAY_OBJECT, ("memport->type..%d", memport->type));

	if(node_class_index==-1)
		node_class_index=DVM_search_class(curdvm,"Remote", "RemoteNode");

	if( ip->u.barray.size!=port->u.barray.size)
	{
		 RcThrowInvalidParametersError();
		 return;
	}

	arr = dvm_create_array_object_i(curdvm, ip->u.barray.size);
	curthread->stack.stack_pointer->object=arr;
	curthread->stack.stack_pointer++;

	std::vector<std::string> memhosts;
	std::vector<int> memports;
	std::vector<std::string> hosts;
	std::vector<int> ports;
	char buf[255];
	for(int i=0;i<memhost->u.barray.size;i++)
	{
	    wcstombs(buf,memhost->u.barray.u.object[i].data->u.string.string,255);
		if(memhost->u.barray.u.object[i].data->u.string.length>=254)
			printf("Warning : host name %ws too long\n",memhost->u.barray.u.object[i].data->u.string.string);
		memhosts.push_back(std::string(buf));
		memports.push_back(memport->u.barray.u.int_array[i]);
	}

	hosts.push_back("");
	ports.push_back(localport);
	for(int i=0;i<ip->u.barray.size;i++)
	{
	    wcstombs(buf,ip->u.barray.u.object[i].data->u.string.string,255);
		if(ip->u.barray.u.object[i].data->u.string.length>=254)
			printf("Warning : host name %ws too long\n",ip->u.barray.u.object[i].data->u.string.string);
		hosts.push_back(std::string(buf));
		ports.push_back(port->u.barray.u.int_array[i]);
	}
	for(int i=0;i<ip->u.barray.size;i++)
	{
		if(RcDoConnectNode(ip->u.barray.u.object[i],port->u.barray.u.int_array[i],&obj,i+1,hosts,ports,memhosts,memports))
		{
			for(int j=0;j<i;j++)//if one node fails, roll back all nodes
			{
				RcCommandPack cmd={RcCmdClose,0};
				DVM_Object *node=arr.data->u.barray.u.object[j].data;
				int ret=RcSendCmd((SOCKET)node->u.class_object.field[2].int_value,&cmd);
				node->u.class_object.field[3].int_value=DVM_TRUE; //closed
				node->u.class_object.field[4].int_value=DVM_FALSE; //connected
			}
			RcThrowSocketError();
			return;
		}
		//if create node success
		arr.data->u.barray.u.object[i]=obj;
	}


	SoInitStorage(memhosts,memports,hosts,ports,0);
	curthread->retvar.object = arr;
}


int RcSendCmd(SOCKET s,RcCommandPack* cmd)
{
	int ret=RcSend(s,cmd,sizeof(RcCommandPack));
	if(ret==SOCKET_ERROR)
	{
#ifdef BD_ON_WINDOWS
		return RcSocketLastError();
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
	int ret=RcSendCmd((SOCKET)obj.data->u.class_object.field[2].int_value,&cmd);
	if(ret)
		RcThrowSocketError(ret);
	obj.data->u.class_object.field[3].int_value=DVM_TRUE; //closed
	obj.data->u.class_object.field[4].int_value=DVM_FALSE; //connected
}


extern "C" int idx_remote_thread=-1;
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
	printf("thread obj id=%d %d\n",cmd.param3,sizeof(RcCommandPack));
	DVM_ObjectRef obj=args[2].object;
	int sret=RcSendCmd((SOCKET)obj.data->u.class_object.field[2].int_value,&cmd);
	if(sret)
		RcThrowSocketError(sret);
	curthread->retvar.object=ret;
	return ;
}


int RcSendModule(SOCKET s,char* path)
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

int RcRecvModule(SOCKET s,char* name,size_t len,char* path)
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

void RcSlaveMainLoop(char* path,SOCKET s,std::vector<std::string>& hosts,std::vector<int>& ports,std::vector<std::string>& mem_hosts,std::vector<int>& mem_ports,int node_id)
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
		SoInitStorage(mem_hosts,mem_ports,hosts,ports,node_id);
		ExCallInit();
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
		#ifdef BD_DSM_STAT
		SoPrintStat();
		#endif
		MEM_check_all_blocks();
		MEM_dump_blocks(stdout);
	}
	ThStopAllThreads();
ERR:
	DVM_dispose_virtual_machine(dvm);
	DVM_dispose_executable_list(plist); //*/
	return;
}

void get_peer_ip_port(SOCKET fd, std::string& ip, int& port)
{
   
    // discovery client information
    struct sockaddr_in addr;
#ifdef BD_ON_WINDOWS
    int addrlen = sizeof(addr);
#else
	size_t addrlen = sizeof(addr);
#endif
    if(getpeername((SOCKET)fd, (struct sockaddr*)&addr, &addrlen) == -1){
        fprintf(stderr,"discovery client information failed, fd=%d, errno=%d(%#x).\n", fd, errno, errno);        
        return;
    }
	port = ntohs(addr.sin_port); 
	ip=inet_ntoa(addr.sin_addr);
	
    return;
}


void RcSlave(int port)
{
	SOCKET s=RcListen(port);
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
		printf("Node count %d\n",mi.num_nodes);
		printf("Memory server count %d\n",mi.num_mem_server);

		char buf[255];

		printf("Host list :\n");
		std::vector<std::string> hosts;
		std::vector<int> ports;

		std::string master;
		int masterport;
		get_peer_ip_port(s,master,masterport);

		hosts.push_back(master);
		ports.push_back(mi.localport);
		printf("Master = %s:%d\n",master.c_str(),mi.localport);

		for(int i=1;i<mi.num_nodes;i++)
		{
			uint32 len,port;
			err=5;
			if(RcRecv(s,&len,sizeof(len))!=sizeof(len))
				goto ERR;
			if(len>255)
			{
				err=6;
				goto ERR;
			}
			if(RcRecv(s,buf,len)!=len)
			{
				err=7;
				goto ERR;
			}
			if(RcRecv(s,&port,sizeof(port))!=sizeof(port))
			{
				err=8;
				goto ERR;
			}
			hosts.push_back(std::string(buf));
			ports.push_back(port);
			printf("%s:%d\n",buf,port);
		}

		printf("Memory server list :\n");
		std::vector<std::string> memhosts;
		std::vector<int> memports;
		for(int i=0;i<mi.num_mem_server;i++)
		{
			uint32 len,port;
			err=5;
			if(RcRecv(s,&len,sizeof(len))!=sizeof(len))
				goto ERR;
			if(len>255)
			{
				err=6;
				goto ERR;
			}
			if(RcRecv(s,buf,len)!=len)
			{
				err=7;
				goto ERR;
			}
			if(RcRecv(s,&port,sizeof(port))!=sizeof(port))
			{
				err=8;
				goto ERR;
			}
			memhosts.push_back(std::string(buf));
			memports.push_back(port);
			printf("%s:%d\n",buf,port);
		}

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
		RcSlaveMainLoop(mainmod,s,hosts,ports,memhosts,memports,mi.node_id);
	}
	else
	{
ERR:
		printf("Hand shaking error! %d %d\n",err,err2);
		RcCloseSocket(s);
	}
}


void RcTriggerGarbageCollection()
{

}

int RcMasterListen()
{
	int n=slavenodes.size();
	fd_set readfds;
	RcCommandPack cmd;
	for(;;)
	{
		FD_ZERO(&readfds);
		for(int i=0;i<n;i++)
		{
			FD_SET(slavenodes[i],&readfds);
		}
		if(SOCKET_ERROR == select(n,&readfds,NULL,NULL,NULL))
		{
			printf("Select Error!%d\n",RcSocketLastError());
			break;
		}
		for(int i=0;i<n;i++)
		{
			if (FD_ISSET(slavenodes[i],&readfds))
			{
				if(RcRecv(slavenodes[i],&cmd,sizeof(cmd))!=sizeof(cmd))
				{
					printf("Socket recv Error! %d\n",RcSocketLastError());
					break;
				}
				switch(cmd.cmd)
				{
				case RcCmdTriggerGC:

					break;
				default:
					printf("Bad command %d!\n");
				}
			}
		}

	}
}

int RcMasterHello(SOCKET s,std::vector<std::string>& hosts,std::vector<int>& ports,std::vector<std::string>& memhosts,std::vector<int>& memports,int node_id)
{
	SlaveInfo si;
	int mem_cnt;
	mem_cnt=memhosts.size();
	int host_cnt=hosts.size();
	if(RcRecv(s,&si,sizeof(si))!=sizeof(si))
	{
		return 1;
	}
	if(si.magic!=RC_MAGIC_SLAVE)
	{
		return 2;
	}
	MasterInfo mi={RC_MAGIC_MASTER,LoadedModFiles.size(),mem_cnt,host_cnt,node_id,ports[0]};
	RcSend(s,&mi,sizeof(mi));

	for(int i=1;i<host_cnt;i++)
	{
	    
		uint32 sendl=hosts[i].size()+1;
		if(sendl>255)
		{
			sendl=255;
			hosts[i][254]=0;
		}
		RcSend(s,&sendl,sizeof(sendl));
		RcSend(s,(char*)hosts[i].c_str(),sendl);
		sendl=ports[i];
		RcSend(s,&sendl,sizeof(sendl));
	}

	for(int i=0;i<mem_cnt;i++)
	{
	    
		uint32 sendl=memhosts[i].size()+1;
		if(sendl>255)
		{
			sendl=255;
			memhosts[i][254]=0;
		}
		RcSend(s,&sendl,sizeof(sendl));
		RcSend(s,(char*)memhosts[i].c_str(),sendl);
		sendl=memports[i];
		RcSend(s,&sendl,sizeof(sendl));
	}

	std::vector<std::string>::iterator itr;
	for(itr=LoadedModFiles.begin();itr!=LoadedModFiles.end();itr++)
	{
		int ret=RcSendModule(s,(char*) (*itr).c_str());
		if(ret)
			return ret+3;
	}

	return 0;
}
