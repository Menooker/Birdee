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
#include "UnportableAPI.h"
#include "hash_compatible.h"
#include <queue>

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
	RcCmdDoneGC,
	RcCmdWakeSync,
	RcCmdEnterBarrier,
	RcCmdEnterSemaphore,
	RcCmdLeaveSemaphore,
};

enum RcDataCommand
{
	RcDataHello=1,
	RcDataAccumulate,
	RcDataAccumulatePartialDone,
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
		_uint64 param34;
	};
};
struct RcDataPack
{
	uint32 cmd;
	uint32 size;
	_uint64 id;
	uint32 datatype;
	int32 param0;
	union
	{
		struct
		{
			int32 param1;
			int32 param2;
		};
		_uint64 param12;
	};
	char buf[0];
};

#pragma pack(pop)

#ifndef BD_ON_VC
#pragma ms_struct off
#endif


int self_node_id;
SOCKET direct_sockets[BD_MAX_NODE_NUM]={0};
int num_nodes;
//Variables for Master node
int global_gc=0;
std::vector<SOCKET> slavenodes;
THREAD_ID MasterListenThread=0;
THREAD_ID MasterDataThread=0;
BD_EVENT master_mark_done;
BD_LOCK master_bar_lock;
BD_LOCK master_data_lock;
//-------------------------

//Variables for Slave node
SOCKET masternode;
SOCKET masterdatanode;
//-------------------------

BD_EVENT gc_event;

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

void RcCloseDirectLinks()
{
	for(int i=0;i<BD_MAX_NODE_NUM;i++)
	{
		if(direct_sockets[i])
		{
			RcCloseSocket(direct_sockets[i]);
			direct_sockets[i]=NULL;
		}
	}
}

int node_class_index=-1;

int RcMasterHello(SOCKET s,std::vector<std::string>& hosts,std::vector<int>& ports,std::vector<std::string>& memhosts,std::vector<int>& memports,int node_id);

int RcDoConnectNode(DVM_ObjectRef host,int port,DVM_ObjectRef* out,int node_id,
	std::vector<std::string>& hosts,std::vector<int>& ports,std::vector<std::string>& memhosts,std::vector<int>& memports)
{
	SOCKET s=(SOCKET)RcConnect((char*)hosts[node_id].c_str(),port);
	if(s==0 || RcMasterHello((SOCKET)s,hosts,ports, memhosts, memports,node_id))
		return 1;
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
struct MasterDataParam
{
	SOCKET port;
};
static THREAD_PROC(RcMasterListen,param);
static THREAD_PROC(RcMasterData,param);
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
		if(buf[0]==-17 && buf[1]==-69 && buf[2]==-65)
            memhosts.push_back(std::string(buf+3));
        else
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
		if(buf[0]==-17 && buf[1]==-69 && buf[2]==-65)
            hosts.push_back(std::string(buf+3));
        else
            hosts.push_back(std::string(buf));
		ports.push_back(port->u.barray.u.int_array[i]);
	}
	if(!MasterDataThread)
	{
		MasterDataParam* para=new MasterDataParam;
		para->port=RcCreateListen(localport);
		self_node_id=0;
		num_nodes=ip->u.barray.size+1;
		MasterDataThread=UaCreateThreadEx(RcMasterData,para); //fix-me : Remember to close the thread
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
			UaStopThread(MasterDataThread);
			UaCloseThread(MasterDataThread);
			MasterDataThread=NULL;
			RcThrowSocketError();
			return;
		}
		//if create node success
		arr.data->u.barray.u.object[i]=obj;
	}

	if(!MasterListenThread)
	{
		UaInitEvent(&gc_event,0);
		UaInitEvent(&master_mark_done,0);
		UaInitLock(&master_bar_lock);
		UaInitLock(&master_data_lock);
		MasterListenThread=UaCreateThreadEx(RcMasterListen,NULL); //fix-me : Remember to close the thread
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

void RcBarrierMsg(int src,_uint b_id,_uint64 thread_id);
void RcEnterBarrier(DVM_Value *args)
{
	_uint bid=(_uint)args[1].object.data;
	UaResetEvent(&curthread->remote_event);
	if(curdvm->is_master)
	{
		RcBarrierMsg(-1,bid,(_uint64)curthread);
	}
	else
	{
		RcCommandPack cmd;
		cmd.cmd=RcCmdEnterBarrier;
		cmd.param=bid;
		cmd.param34=(_uint64)curthread;
		RcSend(masternode,&cmd,sizeof(cmd));
	}
	curthread->retvar.int_value=UaWaitForEventEx(&curthread->remote_event,args[0].int_value);

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

void RcBeforeGC()
{
	UaResetEvent(&gc_event);
}

void RcContinueFromGC();
void RcDoWakeThread(_uint64 thread_id);
void RcSlaveMainLoop(char* path,SOCKET s,std::vector<std::string>& hosts,std::vector<int>& ports,std::vector<std::string>& mem_hosts,std::vector<int>& mem_ports,int node_id)
{
	DVM_VirtualMachine *dvm;
	BdStatus status;
	DVM_ObjectRef paramvar;
	DVM_ExecutableList* plist=(DVM_ExecutableList*)MEM_malloc(sizeof(DVM_ExecutableList));

	masternode=s;
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
			case RcCmdDoGC:
				printf("slave receives GC Triggered signal, round_id=%d\n",cmd.param);
				RcBeforeGC();
				SoLocalGC(cmd.param);
				cmd.cmd=RcCmdDoneGC;
				RcSend(s,&cmd,sizeof(cmd));
				printf("This node mark done\n");
				break;
			case RcCmdDoneGC:
				printf("slave receives GC continue signal\n");
				RcContinueFromGC();
				ThResumeTheWorld();
				break;
			case RcCmdWakeSync:
				//printf("slave receives wake signal\n");
				RcDoWakeThread(cmd.param34);
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

SOCKET RcTryConnect(char* ip,int port,int node_id)
{	
	SOCKET ret;
	for(int i=0;i<3;i++)
	{
		ret=RcConnect(ip,port);
		if(ret)
			break;
		UaSleep(500);
	}
	if(!ret)
		return 0;
	RcCommandPack cmd;
	cmd.cmd=RcDataHello;
	cmd.param=node_id;
	RcSend(ret,&cmd,sizeof(cmd));
	return ret;
}

void RcSlave(int port)
{
	printf("port %d waiting for connections...\n",port);
	SOCKET slisten=RcCreateListen(port);
	SOCKET s=RcAccept(slisten);
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

		self_node_id=mi.node_id;
		num_nodes=mi.num_nodes;
		MasterDataParam* para=new MasterDataParam;
		para->port=slisten;
		UaInitLock(&master_data_lock);
		MasterDataThread=UaCreateThreadEx(RcMasterData,para); //fix-me : Remember to close the thread
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

		for(_uint i=0;i<mi.mod_cnt;i++)
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
		direct_sockets[mi.node_id-1]=RcTryConnect((char*)hosts[0].c_str(),ports[0],mi.node_id);
		if(!direct_sockets[mi.node_id-1])
		{
			printf("Failed to directly connect to master node\n");
			goto ERR;
		}
		for(int i=1;i<mi.node_id;i++)
		{
			direct_sockets[i-1]=RcTryConnect((char*)hosts[i].c_str(),ports[i],mi.node_id);
			if(!direct_sockets[i-1])
			{
				printf("Failed to directly connect to node %d\n",i);
				goto ERR;
			}
		}
		masterdatanode=direct_sockets[mi.node_id-1];
		RcSlaveMainLoop(mainmod,s,hosts,ports,memhosts,memports,mi.node_id);
	}
	else
	{
ERR:
		printf("Hand shaking error! %d %d\n",err,err2);
		
	}
	RcCloseSocket(s);
	RcCloseDirectLinks();
	UaStopThread(MasterDataThread);
	UaCloseThread(MasterDataThread);
	UaKillLock(&master_data_lock);
	MasterDataThread=NULL;
}

/*
Broadcast GC message and trigger GC's mark phase
Only called on master
param: src - the source of the message (index of
		"slavenodes", -1 represents the master)
		round_id - the round number of the current GC
*/
void RcBroadcastGC(int src,int round_id)
{
	RcCommandPack sendcmd;
	if(global_gc)
	{
		printf("Global GC already on! Duplicate GC message received.\n");
		return;
	}
	global_gc=1;
	sendcmd.cmd=RcCmdDoGC;
	sendcmd.param=round_id;
	for(int j=0;j<src;j++)
	{
		RcSend(slavenodes[j],&sendcmd,sizeof(sendcmd));
	}
	//skip i, because "i" is the source of the GC message
	for(_uint j=src+1;j<slavenodes.size();j++)
	{
		RcSend(slavenodes[j],&sendcmd,sizeof(sendcmd));
	}
}


/*
Set the GC mark completion event
*/
void RcContinueFromGC()
{
	UaSetEvent(&gc_event);
}


void SoSendMarkDone()
{
	if(curdvm->is_master)
	{
		UaSetEvent(&master_mark_done);
	}
	else
	{
		RcCommandPack cmd;
		cmd.cmd=RcCmdDoneGC;
		RcSend(masternode,&cmd,sizeof(cmd));
	}
}


/*
Wait for the GC mark completion event, called by the thread triggering
GC
*/
void RcWaitForGCMarkCompletion()
{
	UaWaitForEvent(&gc_event);
	UaResetEvent(&gc_event);
}

/*
Tells other nodes to StopTheWorld and do GC mark
Can be called on master and slave
*/
void RcTriggerGC(int round_id)
{
	RcBeforeGC();
	if(curdvm->is_master)
	{
		RcBroadcastGC(-1,round_id);
	}
	else
	{
		RcCommandPack cmd;
		cmd.cmd=RcCmdTriggerGC;
		cmd.param=round_id;
		RcSend(masternode,&cmd,sizeof(cmd));
	}

}

//////////////////////////////////////////////////
// for Sync code
//////////////////////////////////////////////////

//fix-me : Delete the sync node when GC!
struct SyncThreadNode
{
	int machine;
	_uint64 thread_id;
};
struct SyncNode
{
	int val;
	int data;
	union
	{
		std::vector<SyncThreadNode>* waitlist;
		std::queue<SyncThreadNode>* waitqueue;
	};
};
class DataSyncNode
{
public:
	int master_node_cnt;
	int val;
	int data;
	std::vector<SyncThreadNode>* waitlist;
	int total_size;
	_uint base;
	void* buf;
	uint32 size;
	_uint outarray;
	DataSyncNode(uint32 aid)
	{
		data=0;
		size=0;
		data=SoGeti(aid,0);
		val=0;
		master_node_cnt=0;
		waitlist=new std::vector<SyncThreadNode>;
		int sz=SoGeti(aid,1);
		total_size=sz;
		outarray=SoGeti(aid,2);
		if(sz <= 1024*1024*128)
		{
			int blocks= (sz % DSM_CACHE_BLOCK_SIZE==0) ? sz/DSM_CACHE_BLOCK_SIZE: sz/DSM_CACHE_BLOCK_SIZE+1;
			blocks= (blocks % num_nodes==0) ? blocks/num_nodes: blocks/num_nodes+1;
			size=blocks*DSM_CACHE_BLOCK_SIZE;
			buf=malloc(size * sizeof(double));
			if(blocks*DSM_CACHE_BLOCK_SIZE*(self_node_id+1)>sz)
			{
				size= sz-blocks*self_node_id*DSM_CACHE_BLOCK_SIZE;
				if(size<0)
					size=0;
			}
			base=blocks*self_node_id*DSM_CACHE_BLOCK_SIZE;
			//printf("===========\nnode->size =%d\nnode->base=%d\n==============\n",size,base);
			memset(buf,0,size * sizeof(double));
		}
		else
		{
			printf("Bad data buffer size\n");
		}
	}
	~DataSyncNode()
	{
		if(waitlist)
			delete waitlist;
		free(buf);
	}
};
std::hash_map<_uint,SyncNode*> sync_data;
std::hash_map<_uint,DataSyncNode*> data_data;
typedef std::hash_map<_uint,SyncNode*>::iterator sync_itr;
typedef std::hash_map<_uint,DataSyncNode*>::iterator data_itr;


/*
Do the actual wake-up
*/
void RcDoWakeThread(_uint64 thread_id)
{
	BdThread* th=(BdThread*)thread_id;
	bool found=false;
	UaEnterLock(&curdvm->thread_lock);
	BdThread* t=curdvm->mainvm;
	while(t) //first make sure the thread is alive
	{
		if(t==th)
		{
			found=true;
			break;
		}
		t=t->next;
	}
	if(found)
		UaSetEvent(&th->remote_event);
	UaLeaveLock(&curdvm->thread_lock);

}

/*
Wake up a remote thread from sync. Called on master
*/
void RcWakeRemoteThread(int dest,_uint64 thread_id)
{
	//printf("Wake %d.%d\n",dest,thread_id);
	if(dest==-1)
	{
		RcDoWakeThread(thread_id);
		return;
	}
	RcCommandPack cmd;
	cmd.cmd=RcCmdWakeSync;
	cmd.param34=thread_id;
	RcSend(slavenodes[dest],&cmd,sizeof(cmd));
}

/*
Process the barrier message, may call the nodes to
continue, called on master
param: src - the source of the message (index of
		"slavenodes", -1 represents the master)
		b_id - barrier id
*/
void RcBarrierMsg(int src,_uint b_id,_uint64 thread_id)
{
	UaEnterLock(&master_bar_lock);
	sync_itr itr=sync_data.find(b_id);
	SyncNode* node;
	if(itr==sync_data.end())
	{
		node=new SyncNode;
		node->data=0;
		node->data=SoGeti(b_id,0);
		node->val=0;
		node->waitlist=new std::vector<SyncThreadNode>;
		sync_data[b_id]=node;
	}
	else
	{
		node=itr->second;
	}
	node->val++;
	if(node->val>=node->data)
	{
		node->val=0;
		RcWakeRemoteThread(src,thread_id);
		for(_uint i=0;i<node->waitlist->size();i++)
		{
			SyncThreadNode& th=(*node->waitlist)[i];
			RcWakeRemoteThread(th.machine,th.thread_id);
		}
		node->waitlist->clear();
	}
	else
	{
		SyncThreadNode th={src,thread_id};
		node->waitlist->push_back(th);
	}
	UaLeaveLock(&master_bar_lock);
}

/*
Process the semaphore message, may call the nodes to
continue, called on master
param: src - the source of the message (index of
		"slavenodes", -1 represents the master)
		b_id - semaphore id
*/
void RcSemaphoreMsg(int src,_uint b_id,_uint64 thread_id)
{
	UaEnterLock(&master_bar_lock);
	sync_itr itr=sync_data.find(b_id);
	SyncNode* node;
	if(itr==sync_data.end())
	{
		node=new SyncNode;
		node->data=0;
		node->data=SoGeti(b_id,0);
		node->val=node->data;
		node->waitqueue=new std::queue<SyncThreadNode>;
		sync_data[b_id]=node;
	}
	else
	{
		node=itr->second;
	}
	node->val--;
	if(node->val>=0)
	{
		RcWakeRemoteThread(src,thread_id);
	}
	else
	{
		SyncThreadNode th={src,thread_id};
		node->waitqueue->push(th);
	}
	UaLeaveLock(&master_bar_lock);
}

/*
Process the semaphore release message, may call the nodes to
continue, called on master
param: src - the source of the message (index of
		"slavenodes", -1 represents the master)
		b_id - semaphore id
*/
void RcSemaphoreLeaveMsg(int src,_uint b_id,_uint64 thread_id)
{
	UaEnterLock(&master_bar_lock);
	sync_itr itr=sync_data.find(b_id);
	SyncNode* node;
	if(itr==sync_data.end())
	{
		node=new SyncNode;
		node->data=0;
		node->data=SoGeti(b_id,0);
		node->val=node->data;
		node->waitqueue=new std::queue<SyncThreadNode>;
		sync_data[b_id]=node;
	}
	else
	{
		node=itr->second;
	}
	node->val++;
	if(node->val<=0)
	{
		SyncThreadNode& th=node->waitqueue->front();
		RcWakeRemoteThread(th.machine,th.thread_id);
		node->waitqueue->pop();
	}
	UaLeaveLock(&master_bar_lock);
}


void RcEnterSemaphore(DVM_Value *args)
{
	_uint bid=(_uint)args[1].object.data;
	UaResetEvent(&curthread->remote_event);
	if(curdvm->is_master)
	{
		RcSemaphoreMsg(-1,bid,(_uint64)curthread);
	}
	else
	{
		RcCommandPack cmd;
		cmd.cmd=RcCmdEnterSemaphore;
		cmd.param=bid;
		cmd.param34=(_uint64)curthread;
		RcSend(masternode,&cmd,sizeof(cmd));
	}
	curthread->retvar.int_value=UaWaitForEventEx(&curthread->remote_event,args[0].int_value);
}

void RcLeaveSemaphore(DVM_Value *args)
{
	_uint bid=(_uint)args[0].object.data;
	if(curdvm->is_master)
	{
		RcSemaphoreLeaveMsg(-1,bid,(_uint64)curthread);
	}
	else
	{
		RcCommandPack cmd;
		cmd.cmd=RcCmdLeaveSemaphore;
		cmd.param=bid;
		cmd.param34=(_uint64)curthread;
		RcSend(masternode,&cmd,sizeof(cmd));
	}
}

extern "C" void* init_memcached_this_thread();
void set_memcached_this_thread(void* p);
void free_memcached(void* p);
struct ThreadParam
{
	int round_id;
};

static THREAD_PROC(RcMasterGCProc,param)
{
	ThreadParam* p=(ThreadParam*)param;
	void* memc=init_memcached_this_thread();
	SoLocalGC(p->round_id);
	free_memcached(memc);
	return 0;
}

static THREAD_PROC(RcMasterListen,param)
{
	int n=slavenodes.size();
	int maxfd;
	fd_set readfds;
	RcCommandPack cmd;
	RcCommandPack sendcmd;
	int gc_state[BD_MAX_NODE_NUM]={0};
	THREAD_ID gc_thread=0;
	ThreadParam params;
	if(n>0)
        maxfd=slavenodes[0];
#ifdef BD_ON_LINUX
	for(int i=1;i<n;i++)
	{
        if(slavenodes[i]>maxfd)
            maxfd=slavenodes[i];
	}
	maxfd++;
#endif
	void* memc=NULL;
	for(;;)
	{
		FD_ZERO(&readfds);
		for(int i=0;i<n;i++)
		{
			FD_SET(slavenodes[i],&readfds);
		}
		if(SOCKET_ERROR == select(maxfd,&readfds,NULL,NULL,NULL))
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
					return 0;
				}
				switch(cmd.cmd)
				{
				case RcCmdTriggerGC:
					printf("GC triggered by Node %d\n",i);
					RcBeforeGC();
					params.round_id=cmd.param;
					gc_thread=UaCreateThreadEx(RcMasterGCProc,(void*)&params);
					RcBroadcastGC(i,cmd.param);
					break;
				case RcCmdDoneGC:
					printf("Node %d mark done\n",i);
					if(!global_gc)
					{
						printf("Global GC not yet on, but GC message received.\n");
						goto NEXT;
					}
					gc_state[i]=1;
					//check if all nodes mark done
					int ok;
					ok=1;
					for(int j=0;j<n;j++)
					{
						if(!gc_state[j])
						{
							ok=0;
							break;
						}
					}
					//if done tell all nodes to continue
					if(ok)
					{
						if(gc_thread)
						{
							UaJoinThread(gc_thread);
							UaCloseThread(gc_thread);
							gc_thread=0;
						}
						else
						{
							UaWaitForEvent(&master_mark_done);
							UaResetEvent(&master_mark_done);
						}
						memset(gc_state,0,sizeof(gc_state));
						global_gc=0;
						if(!memc)
							memc=init_memcached_this_thread();
						SoInitGCState();
						printf("All mark done, call to continue\n");
						for(int j=0;j<n;j++)
						{
							sendcmd.cmd=RcCmdDoneGC;
							RcSend(slavenodes[j],&sendcmd,sizeof(sendcmd));
						}
						RcContinueFromGC();
						ThResumeTheWorld();
					}
					break;
				case RcCmdEnterBarrier:
					if(!memc)
						memc=init_memcached_this_thread();
					RcBarrierMsg(i,cmd.param,cmd.param34);
					break;
				case RcCmdEnterSemaphore:
					if(!memc)
						memc=init_memcached_this_thread();
					RcSemaphoreMsg(i,cmd.param,cmd.param34);
					break;
				case RcCmdLeaveSemaphore:
					if(!memc)
						memc=init_memcached_this_thread();
					RcSemaphoreLeaveMsg(i,cmd.param,cmd.param34);
					break;
				default:
					printf("Bad command %d!\n");
				}
			}
NEXT:
			int dummy;
		}

	}
	return 0;
}



#define idx2nodeid(aaa) ((aaa==self_node_id)?0:aaa)
#define nodeid2idx(aaa) ((aaa==0)?self_node_id-1:aaa-1)

template<typename T>
SoStatus SoPutChunk(_uint key,_uint fldid,_uint len,T* v);


void RcAccumulatePartialDoneMsg(int src,uint32 aid,bool locked)
{
	if(!locked)
		UaEnterLock(&master_data_lock);
	data_itr itr=data_data.find(aid);
	DataSyncNode* node;
	if(itr==data_data.end())
	{
		node=new DataSyncNode(aid);
		data_data[aid]=node;
	}
	else
	{
		node=itr->second;
	}

	node->master_node_cnt++;
	if(node->master_node_cnt>=num_nodes)
	{
		for(_uint i=0;i<node->waitlist->size();i++)
		{
			SyncThreadNode& th=(*node->waitlist)[i];
			RcWakeRemoteThread(th.machine,th.thread_id);
		}
		node->master_node_cnt=0;
		node->waitlist->clear();
	}
	if(!locked)
		UaLeaveLock(&master_data_lock);
}

template <typename T>
void RcAccumulateMsg(int src,uint32 aid,_uint64 thread_id,_uint offset,_uint size,T* data)
{
	UaEnterLock(&master_data_lock);
	data_itr itr=data_data.find(aid);
	DataSyncNode* node;
	if(itr==data_data.end())
	{
		node=new DataSyncNode(aid);
		data_data[aid]=node;
	}
	else
	{
		node=itr->second;
	}
	double* sum=(double*)node->buf;
	if( offset<node->base || offset+size > node->base + node->size )
	{
		printf("Accumulation buffer overflow src=%d offset=%d size=%d\n",src,offset,size);
	}
	else
	{
		for(_uint i=0;i<size;i++)
		{
			sum[i+ offset - node->base]+=data[i];
		}
	}
	if(thread_id)
	{
		node->val++;
		if(self_node_id==0)
		{
			SyncThreadNode th={src,thread_id};
			node->waitlist->push_back(th);
		}
		if(node->val>=node->data)
		{
			double* ppp=(double*)node->buf;
			if(node->size)
				SoPutChunk(node->outarray,node->base,node->size,(double*)node->buf);
			node->val=0;
			memset(node->buf,0,node->size * sizeof(double));
			if(self_node_id==0)
			{
				RcAccumulatePartialDoneMsg(-1,aid,true);
			}
			else
			{
				RcDataPack cmd;
				cmd.cmd=RcDataAccumulatePartialDone;
				cmd.id=aid;
				cmd.size=0;
				RcSend(masterdatanode,&cmd,sizeof(cmd));
			}
		}
	}
	UaLeaveLock(&master_data_lock);
}


void RcAccumulate(DVM_Value *args)
{
	_uint bid=(_uint)args[2].object.data;
	DVM_Array* arr=&args[1].object.data->u.barray;
	int is_double=0;
	if(arr->type==FLOAT_ARRAY)
		is_double=0;
	else if(arr->type==DOUBLE_ARRAY)
		is_double=1;
	else
		printf("Array type Error!\n");
	size_t sz_type=is_double?sizeof(double):sizeof(float);
	UaResetEvent(&curthread->remote_event);
	int blocks= (arr->size % DSM_CACHE_BLOCK_SIZE==0) ? arr->size/DSM_CACHE_BLOCK_SIZE: arr->size/DSM_CACHE_BLOCK_SIZE+1;
	blocks= (blocks % num_nodes==0) ? blocks/num_nodes: blocks/num_nodes+1;
	int send_idx[BD_MAX_NODE_NUM];
	int send_size[BD_MAX_NODE_NUM];
	RcDataPack* cmd;
	char buf[sizeof(RcDataPack)+BD_DATA_PROCESS_SIZE];
	cmd=(RcDataPack*)buf;
	cmd->cmd=RcDataAccumulate;
	cmd->id=bid;	
	for(int i=0;i<num_nodes;i++)
	{
		send_idx[i]=i*blocks*DSM_CACHE_BLOCK_SIZE;
		if(blocks*DSM_CACHE_BLOCK_SIZE+send_idx[i]>arr->size)
			send_size[i]=arr->size;
		else
			send_size[i]=send_idx[i]+blocks*DSM_CACHE_BLOCK_SIZE;
	}
	bool done=false;
	while(!done)
	{
		done=true;
		for(int i=0;i<num_nodes;i++)
		{
			if(send_idx[i]<send_size[i])
			{
				if(i==self_node_id)
				{
					if(is_double)
						RcAccumulateMsg(i-1,bid,(_uint64)curthread,send_idx[i],send_size[i]-send_idx[i],arr->u.double_array+send_idx[i]);
					else
						RcAccumulateMsg(i-1,bid,(_uint64)curthread,send_idx[i],send_size[i]-send_idx[i],arr->u.float_array+send_idx[i]);
					send_idx[i]=send_size[i];
					continue;
				}
				int send_idx_size;
				if(send_idx[i]+BD_DATA_PROCESS_SIZE/sz_type > send_size[i])
					send_idx_size = send_size[i]-send_idx[i];
				else
					send_idx_size = BD_DATA_PROCESS_SIZE/sz_type;
				memcpy(cmd->buf,(char*)arr->u.double_array+send_idx[i]*sz_type,send_idx_size*sz_type);
				cmd->param0=send_idx[i];
				cmd->size=send_idx_size*sz_type;
				cmd->datatype=is_double;
				send_idx[i]+=send_idx_size;
				if(send_idx[i] == send_size[i])
				{
					cmd->param12=(_uint64)curthread;
				}
				else
				{
					cmd->param12=0;
					done=false;
				}
				//printf("Send partition to %d, offset=%d len=%d\n",nodeid2idx(i),cmd->param0,send_idx_size);
				RcSend(direct_sockets[nodeid2idx(i)],cmd,sizeof(RcDataPack)+cmd->size);
			}
		}
	}
	curthread->retvar.int_value=UaWaitForEventEx(&curthread->remote_event,args[0].int_value);

}


static THREAD_PROC(RcMasterData,param)
{
	MasterDataParam* par=(MasterDataParam*)param;
	int n=num_nodes-1;
	SOCKET slisten=par->port;
	delete par;
	int maxfd=0;
	fd_set readfds;
	RcDataPack cmd;
	char buf[BD_DATA_PROCESS_SIZE];
	for(int i=self_node_id;i<n;i++)
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
			printf("Data socket accept error ! %d",RcSocketLastError());
			return 0;
		};
		RcCommandPack pack;
		if(RcRecv(sClient,&pack,sizeof(RcCommandPack))!=sizeof(RcCommandPack) || pack.cmd!=RcDataHello)
		{
			printf("Data socket handshake error !");
			return 0;
		}
		direct_sockets[pack.param-1]=sClient;
	}
	int connect_done=0;
	while(connect_done==0)
	{
		connect_done=1;
		for(int i=0;i<self_node_id;i++)
		{
			if(!direct_sockets[i])
			{
				connect_done=0;
				UaSleep(50);
				break;
			}
		}
	}
	printf("Data connection ok\n");
	if(n>0)
        maxfd=direct_sockets[0];
#ifdef BD_ON_LINUX
	for(int i=1;i<n;i++)
	{
        if(direct_sockets[i]>maxfd)
            maxfd=direct_sockets[i];
	}
	maxfd++;
#endif

	void* memc=NULL;
	for(;;)
	{
		FD_ZERO(&readfds);
		for(int i=0;i<n;i++)
		{
			FD_SET(direct_sockets[i],&readfds);
		}
		if(SOCKET_ERROR == select(maxfd,&readfds,NULL,NULL,NULL))
		{
			printf("Data Select Error!%d\n",RcSocketLastError());
			break;
		}
		for(int i=0;i<n;i++)
		{
			if (FD_ISSET(direct_sockets[i],&readfds))
			{
				if(RcRecv(direct_sockets[i],&cmd,sizeof(cmd))!=sizeof(cmd))
				{
					printf("Data Socket recv Error! %d\n",RcSocketLastError());
					return 0;
				}
				if(cmd.size>BD_DATA_PROCESS_SIZE)
				{
					goto ERR;
				}
				int rec=0;
				int torec=cmd.size;
				while(torec>0)
				{
					int inc=RcRecv(direct_sockets[i],(char*)buf+rec,torec);
					if(inc<=0)
					{
						printf("Data socket closed %d\n",RcSocketLastError());
						return 0;
					}
					torec-=inc;
					rec+=inc;
				}
				switch(cmd.cmd)
				{
				case RcDataAccumulate:
					if(!memc)
						memc=init_memcached_this_thread();
					if(cmd.datatype==1)
						RcAccumulateMsg(idx2nodeid(i),cmd.id,cmd.param12,cmd.param0,cmd.size/sizeof(double),(double*)buf);
					else if(cmd.datatype==0)
						RcAccumulateMsg(idx2nodeid(i),cmd.id,cmd.param12,cmd.param0,cmd.size/sizeof(float),(float*)buf);
					else
						printf("Bad data type\n");
					break;
				case RcDataAccumulatePartialDone:
					if(self_node_id==0)
						RcAccumulatePartialDoneMsg(i,cmd.id,false);
					else
						printf("Error! Slave node received a control message!\n");
					break;
				default:
					printf("Bad command %d!\n");
				}
			}
NEXT:
			int dummy;
		}

	}
	return 0;
ERR:
	printf("Data connection internal error\n");
	return 0;
}


void RcBeforeClose()
{
	
	if(MasterListenThread)
	{
		UaKillEvent(&gc_event);
		UaStopThread(MasterListenThread);
		UaCloseThread(MasterListenThread);
		UaStopThread(MasterDataThread);
		UaCloseThread(MasterDataThread);
		MasterListenThread=NULL;
		MasterDataThread=NULL;
		RcCloseDirectLinks();
		for(int i=0;i<slavenodes.size();i++)
		{
			RcCloseSocket(slavenodes[i]);
		}
		slavenodes.clear();
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



/*
struct mrevent {
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    bool triggered;
};

void mrevent_init(struct mrevent *ev) {
    pthread_mutex_init(&ev->mutex, 0);
    pthread_cond_init(&ev->cond, 0);
    ev->triggered = false;
}

void mrevent_trigger(struct mrevent *ev) {
    pthread_mutex_lock(&ev->mutex);
    ev->triggered = true;
    pthread_cond_signal(&ev->cond);
    pthread_mutex_unlock(&ev->mutex);
}

void mrevent_reset(struct mrevent *ev) {
    pthread_mutex_lock(&ev->mutex);
    ev->triggered = false;
    pthread_mutex_unlock(&ev->mutex);
}

void mrevent_wait(struct mrevent *ev) {
     pthread_mutex_lock(&ev->mutex);
     while (!ev->triggered)
         pthread_cond_wait(&ev->cond, &ev->mutex);
     pthread_mutex_unlock(&ev->mutex);
}
*/
