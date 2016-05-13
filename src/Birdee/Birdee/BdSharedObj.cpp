#include "BirdeeDef.h"
#include "BdExec.h"
#include "BdException.h"
#include "debug.h"
#include "hash_compatible.h"
#include "BdSharedObj.h"
#include "BdMemcachedStorage.h"
#include "UnportableAPI.h"
#include "BdParameters.h"
#include "BdDSMCache.h"
#include "BdRemoteControl.h"
#include "BdThread.h"

extern void ExCall(BINT index);

extern "C" DVM_ObjectRef dvm_literal_to_dvm_string_i(DVM_VirtualMachine *dvm, DVM_Char *str);


#define SoIsSharedObject(ref)  ((ref)->v_table && (ref)->v_table->exec_class && (ref)->v_table->exec_class->dvm_class->is_shared)
#define SoIsSharedArray(ref)  ((ref)->v_table==curdvm->global_array_v_table)

BD_RWLOCK gc_lock;
int gc_undergo=0;

inline bool SoIsMarked(int id,int round_id);

void SoThrowSetValueError()
{
	_BreakPoint
	//fix-me : implement me
}

void SoThrowGetValueError()
{
	_BreakPoint
	//fix-me : implement me
}

void SoThrowKeyError()
{
	_BreakPoint
	//fix-me : implement me
}



class SoStorageLocalTest : public SoStorage
{
private:

	std::hash_map<_uint64,DataNode> map;
public:
	SoStorageLocalTest(std::vector<std::string>& arr_mem_hosts,std::vector<int>& arr_mem_ports){};
	SoStorageLocalTest(){};

	int getsize(_uint key)
	{
		return map[key].cls.field_cnt;
	}

	int inc(_uint key,_uint fldid,int inc)
	{
		return UaAtomicInc((long*)&map[MAKE64(key,fldid)].var.vi,inc);
	}

	int dec(_uint key,_uint fldid,int dec)
	{
		return UaAtomicDec((long*)&map[MAKE64(key,fldid)].var.vi,dec);
	}

	SoStatus del(_uint key,unsigned int len)
	{
		for(_uint i=0;i<len;i++)
		{
			map.erase(MAKE64(key,i));
		}
		map.erase(MAKE64(key,0xFFFFFFFE));
		map.erase(MAKE64(key,0xFFFFFFFF));
		return SoOK;
	}

	int getcounter(_uint key,_uint fldid)
	{
		return atoi((char*)map[MAKE64(key,fldid)].string.str);
	}
	void setcounter(_uint key,_uint fldid,int n)
	{
		char* buf=(char*)malloc(65);
		sprintf(buf,"%d",n);
		DataNode nd;
		nd.tag=SoCounter;
		nd.string.str=(wchar_t*)buf;
		map[MAKE64(key,fldid)]=nd;
	}

	SoStatus putstr(_uint key,wchar_t* str,_uint len)
	{
		_uint64 k=MAKE64(key,1);
		DataNode nd;
		DataNode nd2;

		nd2.tag=SoString;
		nd.string.len=len;
		nd.string.str=str;

		map[MAKE64(key,1)]=nd;
		map[MAKE64(key,0)]=nd2;
		return SoOK;
	}

	SoStatus getstr(_uint key,wchar_t** str,_uint* len)
	{
		_uint64 k1,k2;
		k1=MAKE64(key,0);
		k2=MAKE64(key,1);
		if(map.find(k1)!=map.end())
		{
			if(map[k1].tag!=SoString)
				return SoFail;

			if(map.find(k2)!=map.end())
			{
				*len=map[k2].string.len;
				*str=map[k2].string.str;
				return SoOK;
			}
			else
				return SoKeyNotFound;
		}
		else
			return SoKeyNotFound;
	}

	SoStatus put(_uint key,_uint fldid,SoVar v)
	{
		map[MAKE64(key,fldid)].var=v;
		return SoOK;
	}

	SoVar get(_uint key,_uint fldid)
	{
		if(map.find(MAKE64(key,fldid))!=map.end())
			return map[MAKE64(key,fldid)].var;
		throw SO_KEY_NOT_FOUND;
	}

	SoStatus putchunk(_uint key,_uint fldid,_uint len,SoVar* buf)
	{
		_uint64 k=MAKE64(key,fldid);
		for (_uint i=0;i<len;i++)
		{
			map[k+i].var=buf[i];
		}
		return SoOK;
	}

	SoStatus getchunk(_uint key,_uint fldid,_uint len,double* buf)
	{
		_uint64 k=MAKE64(key,fldid);
		for (_uint i=0;i<len;i++)
		{
			if(map.find(k+i)!=map.end())
				buf[i]=map[k+i].var.vd;
			else
				buf[i]=0;
		}
		return SoOK;
	}
	SoStatus getchunk(_uint key,_uint fldid,_uint len,BINT* buf)
	{
		_uint64 k=MAKE64(key,fldid);
		for (_uint i=0;i<len;i++)
		{
			if(map.find(k+i)!=map.end())
				buf[i]=map[k+i].var.vi;
			else
				buf[i]=0;
		}
		return SoOK;
	}


	SoStatus getblock(_uint64 addr,SoVar* buf)
	{
		for (int i=0;i<DSM_CACHE_BLOCK_SIZE;i++)
		{
			if(map.find((addr & DSM_CACHE_HIGH_MASK_64)+i)!=map.end())
				buf[i]=map[(addr & DSM_CACHE_HIGH_MASK_64)+i].var;
			else
				buf[i].vd=0;
		}
		return SoOK;
	}

	bool exists(_uint key)
	{
		return map.find(MAKE64(key,0))!=map.end();
	}

	SoStatus getinfo(_uint key,SoType& tag,int& fld_cnt,int& flag)
	{
		if(map.find(MAKE64(key,0xFFFFFFFE))==map.end())
		{
			tag=map[MAKE64(key,0xFFFFFFFE)].tag;
			flag=map[MAKE64(key,0xFFFFFFFE)].flag;
			fld_cnt=map[MAKE64(key,0xFFFFFFFE)].cls.field_cnt;
			return SoOK;
		}
		else
			return SoFail;
	}

	SoStatus newobj(_uint key,SoType tag,int fld_cnt,int flag)
	{
		if(map.find(MAKE64(key,0xFFFFFFFE))==map.end())
		{
			DataNode nd;
			nd.tag=tag;
			nd.flag=flag;
			nd.cls.field_cnt=fld_cnt;
			map[MAKE64(key,0xFFFFFFFE)]=nd;
			return SoOK;
		}
		else
			return SoFail;
	}
};

static bool isVar(SoType s)
{
	return (s>=SoInt && s<=SoString);
}


class SoStorageFactory
{
public:
	enum BackendType
	{
		SoBackendTest,
		SoBackendChunkMemcached,
		SoBackendMemcached,
	};
	enum CacheType
	{
		SoNoCache,
		SoWriteThroughCache,
	};
private:
	BackendType type;
	CacheType cachetype;
public:
	SoStorageFactory(BackendType ty,CacheType cty)
	{
		setType(ty,cty);
	}
	SoStorageFactory* setType(BackendType ty,CacheType cty)
	{
		type=ty;
		cachetype=cty;
		return this;
	}
	SoStorage* make(std::vector<std::string>& arr_mem_hosts,std::vector<int>& arr_mem_ports)
	{
		switch(type)
		{
		case SoBackendTest:
			return new SoStorageLocalTest(arr_mem_hosts, arr_mem_ports);
		case SoBackendChunkMemcached:
			return new SoStorageChunkMemcached(arr_mem_hosts, arr_mem_ports);
		case SoBackendMemcached:
			return new SoStorageMemcached(arr_mem_hosts, arr_mem_ports);
		default:
			DBG_assert(0,("Var type is wrong %d\n",type));
		}
		return NULL;
	}

	DSMCache* makecache(SoStorage* storage,std::vector<std::string>& arr_hosts,std::vector<int>& arr_ports,
		int mcache_id,SOCKET mcontrollisten,SOCKET mdatalisten)
	{
		switch(cachetype)
		{
		case SoNoCache:
			return new DSMNoCache(storage);
			break;
		case SoWriteThroughCache:
			return new DSMDirectoryCache(storage,arr_hosts,arr_ports,mcache_id,mcontrollisten,mdatalisten);
		default:
			DBG_assert(0,("Var type is wrong %d\n",type));
		}
		return NULL;
	}

};


extern "C" void* init_memcached_this_thread();

class SharedStorage;
SharedStorage* pstorage=NULL;
#define storage (*pstorage)

class SharedStorage
{
public:
	struct ObjectData
	{
		int key;
		unsigned int len;
	};
private:
	SoStorage* backend;
	DSMCache* cache;
	SOCKET controllisten; // the control socket for cache, managed by SharedStorage
	SOCKET datalisten; //the data socket for cache, managed by SharedStorage
	THREAD_ID thread_sweep;

	static BD_EVENT event_sweep_start;
	static BD_EVENT event_sweep_done;
	static std::vector<ObjectData> gc_obj;

	BD_LOCK obj_list_lock;
	std::vector<ObjectData> allocated_obj;


	static THREAD_PROC(SweepProc,param)
	{
		init_memcached_this_thread();
		int round_id=1;
		for(;;)
		{
			UaWaitForEvent(&event_sweep_start);
			UaResetEvent(&event_sweep_start);
			std::vector<ObjectData>::iterator itr;
			for(itr=gc_obj.begin();itr!=gc_obj.end();itr++)
			{
				if(!SoIsMarked(itr->key,round_id))
				{
					printf("GC delete object %d\n",itr->key);
					storage.del(itr->key,itr->len);
				}
			}
			UaSetEvent(&event_sweep_done);
			round_id++;
		}
		return NULL;
	}


	void TriggerGC()
	{
		if(backend->inc(0xFFFFFFFF,1,1)==1)
		{
			//if the current thread is the first to trigger GC
			int rid=storage.inc(0xFFFFFFFF,2,1);
			printf("GC Triggered, round_id=%d\n",rid);
			RcTriggerGC(rid);
			SoLocalGC(rid);
			SoSendMarkDone();
			RcWaitForGCMarkCompletion();
		}
	}

public:
	/*
		params :
		arr_mem_hosts,arr_mem_ports : the list of memory server's hosts and ports
		arr_hosts,arr_ports : the lists of node's host and ports, the port arr_ports[i]+1 is the
			cache control port for node[i], and the port arr_ports[i]+2 is the cache data port
			for node[i]
		int mcache_id the node_id for the current node
	*/
	SharedStorage(SoStorageFactory::BackendType ty,SoStorageFactory::CacheType cachety,std::vector<std::string>& arr_mem_hosts,std::vector<int>& arr_mem_ports,
		std::vector<std::string>& arr_hosts,std::vector<int>& arr_ports,int node_id)
	{
		controllisten=RcCreateListen(arr_ports[node_id]+1);
		if(!controllisten)
			_BreakPoint;
		datalisten=RcCreateListen(arr_ports[node_id]+2);
		if(!datalisten)
			_BreakPoint;
		SoStorageFactory factory(ty,cachety);
		backend=factory.make(arr_mem_hosts, arr_mem_ports);
		cache=factory.makecache(backend,arr_hosts,arr_ports,node_id,controllisten,datalisten);
		if(curdvm->is_master)
		{
			//the round of GC triggered
			this->setcounter(0xFFFFFFFF,2,0);
			this->setcounter(0xFFFFFFFF,0,BD_DSM_GC_THRESHOLD);
			//the count of the threads triggering the current turn of GC
			this->setcounter(0xFFFFFFFF,1,0);
		}
		UaInitRWLock(&gc_lock);
		UaInitEvent(&event_sweep_start,0);
		UaInitEvent(&event_sweep_done,1);
		thread_sweep=UaCreateThreadEx(SweepProc,NULL);
		UaInitLock(&obj_list_lock);
	}
	~SharedStorage()
	{
		UaKillRWLock(&gc_lock);
		closesocket(controllisten);
		closesocket(datalisten);
		delete backend;
		delete cache;
		UaKillEvent(&event_sweep_start);
		UaKillEvent(&event_sweep_done);
		UaStopThread(thread_sweep);
		UaCloseThread(thread_sweep);
		UaKillLock(&obj_list_lock);
	}

	inline void del(int key,unsigned int len)
	{
		backend->del(key,len);
	}
	inline void wait_for_sweep()
	{
		UaWaitForEvent(&event_sweep_done);
		UaResetEvent(&event_sweep_done);
	}

	inline void sweep()
	{
		gc_obj=allocated_obj;
		UaSetEvent(&event_sweep_start);
	}

	template<typename T>
	SoStatus put_chunk(_uint key,_uint fldid,_uint len,T* v)
	{
		return cache->put_chunk(key,fldid,len,v);
	}

	template<typename T>
	SoStatus get_chunk(_uint key,_uint fldid,_uint len,T* v)
	{
		return cache->get_chunk(key,fldid,len,v);
	}

	SoStatus getinfo(_uint key,SoType& tag,int& fld_cnt,int& flag)
	{
		return backend->getinfo(key,tag,fld_cnt,flag);
	}

	//directly put a value into backend
	SoStatus directput(_uint key,int fldid,SoVar v)
	{
		return backend->put(key,fldid,v);
	}

	SoStatus vput(_uint key,int fldid,SoVar v)
	{
		return backend->put(key,fldid,v);
	}

	SoStatus put(_uint key,int fldid,SoVar v)
	{
		return cache->put(key,fldid,v);
	}

	SoStatus peek(_uint key,int fldid,SoVar* out)
	{
		return cache->peek(key,fldid,out);
	}

	/*
	Get integer without throwing an error. Directly get from backend!
	Returns "vdefault" if an exception occurs.
	*/
	int get_with_default(_uint key,_uint fldid,int vdefault)
	{
		try
		{
			return backend->get(key,fldid).vi;

		}
		catch (int a)
		{
			return vdefault;
		}
	}

	SoVar vget(_uint key,int fldid)
	{
		SoVar ret;
		try
		{
			ret=backend->get(key,fldid);

		}
		catch (int a)
		{
			SoThrowKeyError();
		}
		return ret;
	}


	SoVar get(_uint key,int fldid)
	{
		SoVar ret;
		try
		{
			ret=cache->get(key,fldid);

		}
		catch (int a)
		{
			SoThrowKeyError();
		}
		return ret;
	}

	void print_stat()
	{
		long writes,whit,reads,rhit;
		cache->get_stat(writes,whit,reads,rhit);
		printf("Write Stats %d/%d=%f\n",whit,writes,1.0*whit/writes);
		printf("Read Stats %d/%d=%f\n",rhit,reads,1.0*rhit/reads);
		printf("Overall Stats %d/%d=%f\n",whit+rhit,writes+reads,1.0*(whit+rhit)/(writes+reads));
	}

	SoStatus putstr(_uint key,DVM_ObjectRef* s)
	{
		DataNode nd;
		nd.tag=SoString;
		wchar_t* str;
		_uint len;
		if(s->data)
		{
			len=s->data->u.string.length;
			str=s->data->u.string.string;
		}
		else
		{
			len=0;
			str=NULL;
		}
		return backend->putstr(key,str,len);
	}

	SoStatus getstr(_uint key,DVM_ObjectRef* outstr)
	{
		wchar_t* pstr;
		_uint len=0;
		SoStatus ret=backend->getstr(key,&pstr,&len);
		if(ret!=SoOK)
			return ret;
		if(len==0) //fix-me : specical for null
		{
			outstr->data=NULL;
			outstr->v_table=NULL;
		}
		else
			*outstr=dvm_literal_to_dvm_string_i(curdvm,pstr);
		return SoOK;
	}

	/*_uint allockey(SoType tag,int fld_cnt)
	{
		return allockey(tag,fld_cnt,0);
	}*/
	_uint allockey(SoType tag,int fld_cnt,int flag)
	{
		//nd.tag=SoInvalid;
		UaEnterReadRWLock(&gc_lock);
		_uint key=0;

		for(int i=0;i<BD_MAX_SHARED_KEY_TRIES;i++)
		{
			while(key<BD_MAX_SHARED_MODULES)
				key=rand();
			//_uint randk=rand();
			//nd.var.vi=randk;
			if(backend->newobj(key,tag,fld_cnt,flag)==SoOK)
			{
				break;
			}
		}
		if(key==0)
		{
			UaLeaveReadRWLock(&gc_lock);
			throw SO_KEY_NOT_FOUND;
		}
		if(tag==SoObject || tag== SoArray)
		{
			UaEnterLock(&obj_list_lock);
			ObjectData data={key,fld_cnt};
			allocated_obj.push_back(data);
			UaLeaveLock(&obj_list_lock);
			backend->dec(0xFFFFFFFF,0,fld_cnt);
		}
		UaLeaveReadRWLock(&gc_lock);
		printf("new key: %d\n",key);
		return key;
	}
	_uint newmodule(_uint key,int cnt)
	{
		return backend->newobj(key,SoModule,cnt,0);
	}
	_uint newobj(ExecClass* cls)
	{
		if(backend->getcounter(0xFFFFFFFF,0) - cls->field_count<=0)
		{
			TriggerGC();
		}
		_uint ret=allockey(SoObject,cls->field_count,cls->class_index);
		if(ret==0)
			SoThrowKeyError();
		return ret;
	};
	_uint newarray(int size, int dim)
	{
		if(backend->getcounter(0xFFFFFFFF,0) - size<=0)
		{
			TriggerGC();
		}
		_uint ret=allockey(SoArray,size,dim);
		if(ret==0)
			SoThrowKeyError();
		return ret;
	};
	_uint newstr(DVM_ObjectRef* s)
	{
		_uint ret=allockey(SoString,1,-1);
		if(ret==0)
			SoThrowKeyError();
		putstr(ret,s);
		return ret;
	};


	_uint getsize(_uint id)
	{
		try
		{
			return backend->getsize(id);
		}
		catch (int a)
		{
			SoThrowKeyError();
			return 0;
		}
	};

	/*
	Atomic increase. Returns the increased result.
	*/
	int inc(_uint key,int fldid,int inc)
	{
		try
		{
			return backend->inc(key,fldid,inc);
		}
		catch (int a)
		{
			SoThrowSetValueError();
			return 0;
		}
	}

	/*
	Atomic decrease. Returns the decreased result.
	*/
	int dec(_uint key,int fldid,int dec)
	{
		try
		{
			return backend->dec(key,fldid,dec);
		}
		catch (int a)
		{
			SoThrowSetValueError();
			return 0;
		}
	}

	void setcounter(_uint key,int fldid,int n)
	{
		try
		{
			backend->setcounter(key,fldid,n);
		}
		catch (int a)
		{
			SoThrowSetValueError();
		}
	}

	int getcounter(_uint key,int fldid)
	{
		try
		{
			return backend->getcounter(key,fldid);
		}
		catch (int a)
		{
			SoThrowSetValueError();
			return 0;
		}
	}
};
BD_EVENT SharedStorage::event_sweep_start;
BD_EVENT SharedStorage::event_sweep_done;
std::vector<SharedStorage::ObjectData> SharedStorage::gc_obj;

extern std::hash_map<std::string,ExecutableEntry*> LoadedMods;
void SoInitStorage(std::vector<std::string>& arr_mem_hosts,std::vector<int>& arr_mem_ports,
	std::vector<std::string>& arr_hosts,std::vector<int>& arr_ports,int node_id)
{
	SoStorageFactory::CacheType cachety;
	if(parameters.nocache)
		cachety=SoStorageFactory::SoNoCache;
	else
		cachety=SoStorageFactory::SoWriteThroughCache;
	SoStorageFactory::BackendType memty;
	switch(parameters.mem_backend)
	{
	case 0:
		memty=SoStorageFactory::SoBackendChunkMemcached;
		break;
	case 1:
		memty=SoStorageFactory::SoBackendMemcached;
		break;
	}
	pstorage=new SharedStorage(memty,cachety,arr_mem_hosts,arr_mem_ports,
		arr_hosts,arr_ports,node_id);
	if(curdvm->is_master)
	{
		for( ExecutableEntry* ee=curdvm->executable_entry;ee;ee=ee->next)
		{
			SoNewModule(ee->executable->id,ee->executable->shared_global_variable_count);
		}
	}
}

extern "C" void SoKillStorage()
{
	if(pstorage)
		delete pstorage;
}

inline _uint TranslateKey(_uint key)
{
	int id=curthread->current_executable->executable->id;
	if(key>=BD_MAX_SHARED_STATIC_PER_MODULE || id>=BD_MAX_SHARED_MODULES)
	{
		SoThrowKeyError();
	}
	return key+id*BD_MAX_SHARED_STATIC_PER_MODULE;
}

#ifdef BD_DSM_STAT
void SoPrintStat()
{
	if(pstorage)
		pstorage->print_stat();
}
#endif

extern "C" BINT SoGeti(_uint key,_uint fldid)
{
	return storage.get(key,fldid).vi;
}

extern "C" double SoGetd(_uint key,_uint fldid)
{
	return storage.get(key,fldid).vd;
}

extern "C" void SoGeto(_uint key,_uint fldid,int idx_in_exe)
{
	DVM_ObjectRef obj;
	int ret= storage.get(key,fldid).key;
	if(idx_in_exe!=-1)
	{
		int class_index = curthread->current_executable->class_table[idx_in_exe];
		obj.v_table = curdvm->bclass[class_index]->class_table;
	}
	else
		obj.v_table=curdvm->global_array_v_table;
	obj.data=(DVM_Object*)ret;
	curthread->retvar.object=obj;
	return ;
}

extern "C" BINT SovGeti(_uint key,_uint fldid)
{
	return storage.vget(key,fldid).vi;
}

extern "C" double SovGetd(_uint key,_uint fldid)
{
	return storage.vget(key,fldid).vd;
}

extern "C" void SoGets(_uint key,_uint fldid)
{
	DVM_ObjectRef ret;

	if(storage.getstr(storage.get(key,fldid).key,&ret)!=SoOK)
		SoThrowGetValueError();
    curthread->retvar.object=ret;
	return;
}

extern "C" void SoSeti(_uint key,_uint fldid,BINT v)
{
	SoVar var={v};
	if(storage.put(key,fldid,var)!=SoOK)
	{
		SoThrowGetValueError();
	}

}

extern "C" void SoSetd(_uint key,_uint fldid,double v)
{
	SoVar var;
	var.vd=v;
	if(storage.put(key,fldid,var)!=SoOK)
	{
		SoThrowGetValueError();
	}
}

extern "C" void SoSeto(_uint key,_uint fldid,_uint v)
{
	SoVar var={v};
	if(storage.put(key,fldid,var)!=SoOK)
	{
		SoThrowGetValueError();
	}
}

extern "C" void SovSeti(_uint key,_uint fldid,BINT v)
{
	SoVar var={v};
	if(storage.vput(key,fldid,var)!=SoOK)
	{
		SoThrowGetValueError();
	}

}

extern "C" void SovSetd(_uint key,_uint fldid,double v)
{
	SoVar var;
	var.vd=v;
	if(storage.vput(key,fldid,var)!=SoOK)
	{
		SoThrowGetValueError();
	}
}

extern "C" void SoSets(_uint key,_uint fldid,DVM_ObjectRef v)
{
	SoVar var={storage.newstr(&v)};
	if(storage.put(key,fldid,var)!=SoOK)
	{
		SoThrowGetValueError();
	}
}

extern "C" void SoNewModule(_uint key,int cnt)
{
	if(storage.newmodule(key,cnt)!=SoOK)
	{
		//SoThrowKeyError();
	}
}

extern "C" DVM_ObjectRef SoDoNew(int class_index,int methodid)
{
	ExecClass *ec;
    DVM_ObjectRef obj;

	_uint ret=storage.newobj(curdvm->bclass[class_index]);

	if(ret==0)
		SoThrowKeyError();

	ec = curdvm->bclass[class_index];
    obj.v_table = ec->class_table;
	obj.data=(DVM_Object*)ret;

	curthread->stack.stack_pointer->object=obj;
	*curthread->stack.flg_sp=DVM_TRUE;
	curthread->stack.stack_pointer++; curthread->stack.flg_sp++;
	ExCall(methodid);
	return obj;
}

extern "C" void SoNew(int idx_in_exe,int methodid)
{
	int class_index = curthread->current_executable->class_table[idx_in_exe];
	curthread->retvar.object= SoDoNew(class_index,methodid);
}


int SoDoCreateArray(DVM_VirtualMachine *dvm, int dim, int dim_index,
                 DVM_TypeSpecifier *type)
{
    int ret;
    int size;
    int i;
	//fix-me : should use curthread?
	size = (curthread->stack.stack_pointer-dim)->int_value;

    if (dim_index == type->derive_count-1) {
        switch (type->basic_type) {
        case DVM_VOID_TYPE:
            DBG_panic(("creating void barray"));
            break;
        case DVM_BOOLEAN_TYPE: /* FALLTHRU */
        case DVM_INT_TYPE:
        case DVM_ENUM_TYPE:
        case DVM_DOUBLE_TYPE:
			ret = storage.newarray(size,1);
            break;
		case DVM_CLASS_TYPE:
        case DVM_STRING_TYPE: /* FALLTHRU */
            ret = storage.newarray(size,1);
            break;
		case DVM_VARIENT_TYPE:
		case DVM_NATIVE_POINTER_TYPE:
        case DVM_DELEGATE_TYPE:
        case DVM_NULL_TYPE: /* FALLTHRU */
        case DVM_BASE_TYPE: /* FALLTHRU */
        case DVM_UNSPECIFIED_IDENTIFIER_TYPE: /* FALLTHRU */
        default:
            DBG_assert(0, ("type->basic_type..%d\n", type->basic_type));
            break;
        }
    } else if (type->derive[dim_index].tag == DVM_FUNCTION_DERIVE) {
        DBG_panic(("BFunction type in barray literal.\n"));
    } else {
        ret = storage.newarray(size,dim-dim_index);
        if (dim_index < dim - 1) {
			curthread->stack.stack_pointer->object.data=(DVM_Object*)ret;
			curthread->stack.stack_pointer->object.v_table=dvm->array_v_table; //fix-me
			*curthread->stack.flg_sp=DVM_TRUE;
            curthread->stack.stack_pointer++;curthread->stack.flg_sp++;
            for (i = 0; i < size; i++) {
                int child;
                child = SoDoCreateArray(dvm, dim, dim_index+1, type);
                SoSeto( ret, i, child);
            }
            curthread->stack.stack_pointer--;curthread->stack.flg_sp--;
        }
    }
    return ret;
}


void SoArraySize(DVM_Value *args)
{
	DBG_assert(args->object.v_table==curdvm->global_array_v_table, ("Bad type"));
	curthread->retvar.int_value=storage.getsize((int)args->object.data);
}

void SoArrayTostr(DVM_Value *args)
{
    DVM_Object  *bthis;
    bthis = args->object.data ;
	DBG_assert(args->object.v_table==curdvm->global_array_v_table, ("Bad type"));

	char buf[LINE_BUF_SIZE];
    DVM_Char *wc_str;
    sprintf(buf, "GlobalArray@%x", bthis); //improve-me : print the contents
    wc_str = dvm_mbstowcs_alloc(curthread, buf);
	curthread->retvar.object =  dvm_create_dvm_string_i(curdvm, wc_str);
}


void SoArrayUnimplementedStub(DVM_Value *args)
{
    _BreakPoint;
}

void SoArrayEquals(DVM_Value *args)
{
    DVM_Object *bobj, *bthis;
    bobj = args->object.data ;
	if(args->object.v_table!=curdvm->global_array_v_table)
	{
		curthread->retvar.int_value=DVM_FALSE;
		return;
	}
    bthis = args[1].object.data ;
    DBG_assert(bthis->type == ARRAY_OBJECT, ("bthis->type..%d", bthis->type));
	curthread->retvar.int_value = (bobj!=bthis)?DVM_FALSE:DVM_TRUE;
}



DVM_ObjectRef SoCreateArray(DVM_VirtualMachine *dvm, int dim, DVM_TypeSpecifier *type)
{
    DVM_ObjectRef ret;
	ret.data= (DVM_Object*)SoDoCreateArray(dvm, dim, 0, type);
	ret.v_table = dvm->global_array_v_table;
    curthread->stack.stack_pointer -= dim; curthread->stack.flg_sp -=dim;
	return ret;
}

void SoNewArray(BINT ty,BINT dim)
{
    DVM_TypeSpecifier *type
		= &curthread->current_executable->executable->type_specifier[ty];
    curthread->retvar.object= SoCreateArray(curdvm, dim, type);
	//printf("Array id=%d\n",curthread->retvar.object.data);
    return;
}

extern "C" void SoGlobalArrBoundaryCheck(BINT arr,BINT idx)
{
	if(idx>=storage.getsize(arr))
	{
		ExSystemRaise(ExArrayIndexOutOfBoundErr);
	}
}

extern "C" int SoGlobalArrGetSize(BINT arr)
{
	return storage.getsize(arr);
}


extern "C" void SoInc(DVM_Value* args)
{
	curthread->retvar.int_value = storage.inc((_uint)args[1].object.data,32,args[0].int_value);
}

extern "C" void SoDec(DVM_Value* args)
{
	curthread->retvar.int_value = storage.dec((_uint)args[1].object.data,32,args[0].int_value);
}

extern "C" void SoSetCounter(DVM_Value* args)
{
	storage.setcounter((_uint)args[1].object.data,32,args[0].int_value);
}

extern "C" void SoGetCounter(DVM_Value* args)
{
	curthread->retvar.int_value = storage.getcounter((_uint)args[0].object.data,32);
}

enum OutBufferMethod
{
	BufferWriteBool,
	BufferWriteInt,
	BufferWriteDouble,
	BufferWriteString,
};

void ExCallWriteObjBuffer(DVM_Value* val,DVM_Boolean isobj,DVM_ObjectRef buf,int idx)
{
	*curthread->stack.stack_pointer=*val; //fix-me : what if GC happens here?
	curthread->stack.stack_pointer++;
	*curthread->stack.flg_sp=isobj;
	curthread->stack.flg_sp++;

	curthread->stack.stack_pointer->object=buf;
	curthread->stack.stack_pointer++;
	*curthread->stack.flg_sp=DVM_TRUE;
	curthread->stack.flg_sp++;
	ExCall(idx);
}

void SoInitGCState()
{
	//the remaining space of distributed heap size before next GC
	storage.setcounter(0xFFFFFFFF,0,BD_DSM_GC_THRESHOLD);
	//the count of the threads triggering the current turn of GC
	storage.setcounter(0xFFFFFFFF,1,0);
}

/*
the cache for the global GC mark table. It holds all
object id which is known by this node to be marked.
*/
std::hash_map<int,int> gc_mark_map;

inline bool SoIsMarked(int id,int round_id)
{
	std::hash_map<int,int>::iterator itr=gc_mark_map.find(id);
	if(itr!=gc_mark_map.end())
	{
		return true;
	}
	int mark=storage.get_with_default(id,0xFFFFFFFF,0);
	if(mark>=round_id)
	{
		gc_mark_map[id]=1;
		return true;
	}
	else
	{
		return false;
	}
}


/*
Make a mark on the object. Return if the object is already marked
*/
inline bool SoSetMark(int id,int round_id)
{
	printf("======Set mark %d,rid=%d\n",id,round_id);
	std::hash_map<int,int>::iterator itr=gc_mark_map.find(id);
	if(itr!=gc_mark_map.end())
	{
		return true;
	}

	if(storage.get_with_default(id,0xFFFFFFFF,0)>=round_id)
	{
		gc_mark_map[id]=1;
		return true;
	}
	else
	{
		SoVar v;
		v.vi=round_id;
		storage.directput(id,0xFFFFFFFF,v);
		gc_mark_map[id]=1;
		return false;
	}

}

#define UNKNOWN_CLASS_INDEX (-1)
#define BASIC_CLASS_INDEX (-2)



/*
Mark the object and its fields.
The parameters:
	class_idx - the class index of the object, set to UNKNOWN_CLASS_INDEX if it is unknown
Return the class index of the object. The return value is useful if class index is unkonwn.
*/
int SoMarkObject(int id,int round_id,int class_idx);

/*
Mark the array and its contents.
The parameters:
	dimension - it is of no use, just for checking.
	class_idx - the class index of the contents, set to UNKNOWN_CLASS_INDEX if it is unknown
Return the class index of the array's content.The return value is useful if class index is
unkonwn.
*/
int SoMarkArray(int id,int round_id,int dimension,int class_idx)
{
	DBG_assert(dimension>=1,("Bad dimension %d, expecting >=1",dimension));
	if(SoSetMark(id,round_id))
	{
		return class_idx;
	}
	if(dimension==1 && class_idx==BASIC_CLASS_INDEX)
		return BASIC_CLASS_INDEX;
	SoType tag;
	int fld_cnt,flag;
	if(storage.getinfo(id,tag,fld_cnt,flag)!=SoOK)
	{
		_BreakPoint;
	}
	DBG_assert(tag==SoArray,("Bad tag %d, expecting SoArray",tag));
	if(dimension!=-1)
	{
		DBG_assert(dimension==flag,("Bad dimension %d, expecting local dim=%d",flag,dimension));
	}
	else
		dimension=flag;

	SoVar datablock[DSM_CACHE_BLOCK_SIZE];
	for(int i=0;i<fld_cnt;i++)
	{
		if(i%DSM_CACHE_BLOCK_SIZE==0)
		{
			if(storage.peek(id,i,datablock)!=SoOK)
			{
				printf("Peek error\n");
			}
		}
		int subkey=datablock[i%DSM_CACHE_BLOCK_SIZE].key;
		if(subkey!=0)
		{
			if(dimension==1)
				class_idx=SoMarkObject(subkey,round_id,class_idx);
			else
				class_idx=SoMarkArray(subkey,round_id,dimension-1,class_idx);
		}
	}
	return class_idx;
}

int SoMarkObject(int id,int round_id,int class_idx)
{
	if(SoSetMark(id,round_id))
	{
		return class_idx;
	}
	if(class_idx==UNKNOWN_CLASS_INDEX)
	{
		SoType tag;
		int fld_cnt;
		if(storage.getinfo(id,tag,fld_cnt,class_idx)!=SoOK)
		{
			_BreakPoint;
		}
		if(class_idx<0 || class_idx>=curdvm->class_count)
		{
			printf("GC found an object with a bad class flag\n");
			_BreakPoint;
		}
	}
    ExecClass *ec = curdvm->bclass[class_idx];
	SoVar datablock[DSM_CACHE_BLOCK_SIZE];
	int datablock_idx=-100;
    for (int i = 0; i < ec->field_count; i++) {
		if(ec->field_type[i]->basic_type == DVM_CLASS_TYPE && ec->field_type[i]->derive_count==0)
		{
			if(i-datablock_idx>=DSM_CACHE_BLOCK_SIZE)
			{
				//if the fetched block is not what we want
				datablock_idx=i>>DSM_CACHE_BITS<<DSM_CACHE_BITS;
				if(storage.peek(id,datablock_idx,datablock)!=SoOK)
				{
					printf("Peek error\n");
				}
			}
			if(datablock[i%DSM_CACHE_BLOCK_SIZE].key!=0)
			{
				SoMarkObject(datablock[i%DSM_CACHE_BLOCK_SIZE].key,round_id,UNKNOWN_CLASS_INDEX);
			}
		}
		else if(ec->field_type[i]->derive_count > 0
			&& ec->field_type[i]->derive[0].tag == DVM_ARRAY_DERIVE)
		{
			if(i-datablock_idx>=DSM_CACHE_BLOCK_SIZE)
			{
				datablock_idx=i>>DSM_CACHE_BITS<<DSM_CACHE_BITS;
				if(storage.peek(id,datablock_idx,datablock)!=SoOK)
				{
					printf("Peek error\n");
				}
			}
			if(datablock[i%DSM_CACHE_BLOCK_SIZE].key!=0)
			{
				int cls_idx;
				if(ec->field_type[i]->basic_type == DVM_CLASS_TYPE)
					cls_idx=UNKNOWN_CLASS_INDEX;
				else
					cls_idx=BASIC_CLASS_INDEX;
				SoMarkArray(datablock[i%DSM_CACHE_BLOCK_SIZE].key,round_id,ec->field_type[i]->derive_count,cls_idx);
			}
		}
    }
	return class_idx;
}


void SoMark(DVM_ObjectRef *obj,ExecutableEntry *ee_pos,DVM_TypeSpecifier* type,int round_id)
{
	int id=(int)obj->data;
	if(!id)
		return;
	if (SoIsSharedObject(obj))
	{
		SoMarkObject(id,round_id,UNKNOWN_CLASS_INDEX);
    }
	else if(SoIsSharedArray(obj))
	{
		int cls_idx;
		if(type->basic_type == DVM_CLASS_TYPE)
			cls_idx=ee_pos->class_table[type->u.class_t.index];
		else
			cls_idx=-1;
		SoMarkArray(id,round_id,type->derive_count,cls_idx);
	}
}

void SoLocalGC(int round_id)
{
	DVM_ObjectRef *obj;
    ExecutableEntry *ee_pos;
	int i;
	BdThread* th;
	SoVar datablock[DSM_CACHE_BLOCK_SIZE];
	int datablock_idx=-100;

	//wait for the last sweep to be done
	storage.wait_for_sweep();

	gc_mark_map.clear();

	UaEnterWriteRWLock(&gc_lock);
	gc_undergo=1;

	ThPauseTheWorld();

    for (ee_pos = curdvm->executable_entry; ee_pos; ee_pos = ee_pos->next) {
        for (i = 0; i < ee_pos->static_v.variable_count; i++) {
			obj=&ee_pos->static_v.variable[i].object;
			SoMark(obj,ee_pos,ee_pos->executable->global_variable[i].type,round_id);
        }

		for (i = 0; i < ee_pos->executable->shared_global_variable_count; i++) {
			DVM_TypeSpecifier* type=ee_pos->executable->shared_global_variable[i].type;
			if (type->basic_type==DVM_CLASS_TYPE
				&& type->derive_count==0)
			{
				///////////fetch the data block
				if(i-datablock_idx>=DSM_CACHE_BLOCK_SIZE)
				{
					datablock_idx=i>>DSM_CACHE_BITS<<DSM_CACHE_BITS;
					if(storage.peek(ee_pos->executable->id,datablock_idx,datablock)!=SoOK)
					{
						printf("Peek error\n");
					}
				}
				////////////////
				if(datablock[i%DSM_CACHE_BLOCK_SIZE].key!=0)
				{
					SoMarkObject(datablock[i%DSM_CACHE_BLOCK_SIZE].key,round_id,UNKNOWN_CLASS_INDEX);
				}
            }
			else if(type->derive_count > 0
				&& type->derive[0].tag == DVM_ARRAY_DERIVE)
			{
				///////////fetch the data block
				if(i-datablock_idx>=DSM_CACHE_BLOCK_SIZE)
				{
					datablock_idx=i>>DSM_CACHE_BITS<<DSM_CACHE_BITS;
					if(storage.peek(ee_pos->executable->id,datablock_idx,datablock)!=SoOK)
					{
						printf("Peek error\n");
					}
				}
				////////////////
				if(datablock[i%DSM_CACHE_BLOCK_SIZE].key!=0)
				{
					int cls_idx;
					if(type->basic_type == DVM_CLASS_TYPE)
						cls_idx=UNKNOWN_CLASS_INDEX;
					else
						cls_idx=BASIC_CLASS_INDEX;
					SoMarkArray(datablock[i%DSM_CACHE_BLOCK_SIZE].key,round_id,type->derive_count,cls_idx);
				}
			}
        }
    }

	UaEnterLock(&curdvm->thread_lock);
	th=curdvm->mainvm;
	DVM_Value* j;
	while(th)
	{
		for (i = 0, j= th->stack.stack; j < th->stack.stack_pointer; j++, i++) {
			if (th->stack.pointer_flags[i]) {
				if(j->object.data)
				{
					if (SoIsSharedObject(&j->object))
					{
						SoMarkObject((int)j->object.data,round_id,UNKNOWN_CLASS_INDEX);
					}
					else if(SoIsSharedArray(&j->object))
					{
						SoMarkArray((int)j->object.data,round_id,-1,UNKNOWN_CLASS_INDEX);
					}
				}
			}
		}
		th=th->next;
	}
	UaLeaveLock(&curdvm->thread_lock);

	gc_undergo=0;
	UaLeaveWriteRWLock(&gc_lock);

	storage.sweep();
}

template<typename T>
SoStatus SoPutChunk(_uint key,_uint fldid,_uint len,T* v)
{
	return storage.put_chunk(key,fldid,len,v);
}

template<typename T>
SoStatus SoGetChunk(_uint key,_uint fldid,_uint len,T* v)
{
	return storage.get_chunk(key,fldid,len,v);
}


extern "C" void SoCopyArray(BINT dstart,BINT dend,BINT sstart,BINT s_end,BINT ty,BINT unsafe)
{
	DVM_ObjectRef* dest=&(curthread->stack.stack_pointer-2)->object;
	DVM_ObjectRef* src=&(curthread->stack.stack_pointer-1)->object;
	if(!dest->data || !src->data)
		ExNullPointerException();
	int len1=dend-dstart;
	int len2=s_end-sstart;

	if(dstart<0 || dend<0 || sstart<0 || s_end<0
		|| dstart>=dend || sstart>=s_end || len1!=len2)
		ExArrayOutOfBoundException();
	int dest_global,src_global;
	if(dest->v_table==curdvm->global_array_v_table)
		dest_global=1;
	else if(dest->v_table==curdvm->array_v_table)
		dest_global=0;
	else
	{
		printf("CopyArray encounters an unkown type\n");
		_BreakPoint;
	}

	if(src->v_table==curdvm->global_array_v_table)
		src_global=1;
	else if(src->v_table==curdvm->array_v_table)
		src_global=0;
	else
	{
		printf("CopyArray encounters an unkown type\n");
		_BreakPoint;
	}
	if(!unsafe)
	{
		int len;
		if(!dest_global)
			len=dest->data->u.barray.size;
		else
			len=SoGlobalArrGetSize((int)dest->data);
		if(dstart>=len || dend>len)
			ExArrayOutOfBoundException();

		if(!src_global)
			len=src->data->u.barray.size;
		else
			len=SoGlobalArrGetSize((int)src->data);
		if(sstart>=len || s_end>len)
			ExArrayOutOfBoundException();
	}
	unsigned int sz;
	switch(ty)
	{
	case 0:
		sz=sizeof(int);
		break;
	case 1:
		sz=sizeof(double);
		break;
	case 2:
		sz=sizeof(DVM_ObjectRef);
		break;
	}
	if(!dest_global )
	{//if dest is local
		if(!src_global)
		{
			char* vdest=(char*)dest->data->u.barray.u.int_array + dstart * sz;
			char* vsrc= (char*)src->data->u.barray.u.int_array + sstart * sz;
			memcpy(vdest,vsrc,sz*len1);
		}
		else
		{
			if(ty==0)
				SoGetChunk((_uint)src->data,sstart,len1,dest->data->u.barray.u.int_array + dstart);
			else
				SoGetChunk((_uint)src->data,sstart,len1,dest->data->u.barray.u.double_array + dstart);
		}
	}
	else
	{//if dest is global
		if(!src_global)
		{
			if(ty==0)
				SoPutChunk((_uint)dest->data,dstart,len1,src->data->u.barray.u.int_array + sstart);
			else
				SoPutChunk((_uint)dest->data,dstart,len1,src->data->u.barray.u.double_array + sstart);
		}
		else
		{

		}
	}
	curthread->stack.stack_pointer-=2;
	curthread->stack.flg_sp-=2;
}
