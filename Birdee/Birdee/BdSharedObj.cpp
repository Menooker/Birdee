#include "BirdeeDef.h"
#include "BdExec.h"
#include "BdException.h"
#include "../../debug/debug.h"
#include "hash_compatible.h"
#include "BdSharedObj.h"
#include "BdMemcachedStorage.h"
#include "UnportableAPI.h"

extern void ExCall(BINT index);

extern "C" DVM_ObjectRef dvm_literal_to_dvm_string_i(DVM_VirtualMachine *dvm, DVM_Char *str);









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

	std::hash_map<long long,DataNode> map;
public:
	SoStorageLocalTest(char*){};
	SoStorageLocalTest(){};

	int inc(uint key,int fldid,int inc)
	{
		return UaAtomicInc((long*)&map[MAKE64(key,fldid)].var.vi,inc);
	}

	int dec(uint key,int fldid,int dec)
	{
		return UaAtomicDec((long*)&map[MAKE64(key,fldid)].var.vi,dec);
	}

	int getcounter(uint key,int fldid)
	{
		return atoi((char*)map[MAKE64(key,fldid)].string.str);
	}
	void setcounter(uint key,int fldid,int n)
	{
		char* buf=(char*)malloc(65);
		sprintf(buf,"%d",n);
		DataNode nd;
		nd.tag=SoCounter;
		nd.string.str=(wchar_t*)buf;
		map[MAKE64(key,fldid)]=nd;
	}

	SoStatus putstr(uint key,wchar_t* str,uint len)
	{
		long long k=MAKE64(key,1);
		DataNode nd;
		DataNode nd2;

		nd2.tag=SoString;
		nd.string.len=len;
		nd.string.str=str;

		map[MAKE64(key,1)]=nd;
		map[MAKE64(key,0)]=nd2;
		return SoOK;
	}

	SoStatus getstr(uint key,wchar_t** str,uint* len)
	{
		long long k1,k2;
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

	SoStatus put(uint key,int fldid,SoVar v)
	{
		map[MAKE64(key,fldid)].var=v;
		return SoOK;
	}

	SoVar get(uint key,int fldid)
	{
		if(map.find(MAKE64(key,fldid))!=map.end())
			return map[MAKE64(key,fldid)].var;
		throw SO_KEY_NOT_FOUND;
	}

	bool exists(uint key)
	{
		return map.find(MAKE64(key,0))!=map.end();
	}

	SoStatus newobj(uint key,SoType tag,int fld_cnt)
	{
		if(map.find(MAKE64(key,0))==map.end())
		{
			DataNode nd;
			nd.tag=tag;
			nd.cls.field_cnt=fld_cnt;
			map[MAKE64(key,0)]=nd;
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
		SoBackendMemcached,
	};
private:
	BackendType type;

public:
	SoStorageFactory(BackendType ty)
	{
		setType(ty);
	}
	SoStorageFactory* setType(BackendType ty)
	{
		type=ty;
		return this;
	}
	SoStorage* make()
	{
		switch(type)
		{
		case SoBackendTest:
			return new SoStorageLocalTest("127.0.0.1");
			break;
		case SoBackendMemcached:
			return new SoStorageMemcached("127.0.0.1");
		default:
			DBG_assert(0,("Var type is wrong %d\n",type));
		}
		return NULL;
	}
};

class SharedStorage
{
private:
	SoStorage* backend;
public:
	SharedStorage(SoStorageFactory::BackendType ty)
	{
		backend=SoStorageFactory(ty).make();
	}
	~SharedStorage()
	{
		delete backend;
	}
	SoStatus put(uint key,int fldid,SoVar v)
	{
		return backend->put(key,fldid,v);
	}

	SoVar get(uint key,int fldid)
	{
		SoVar ret;
		try
		{
			ret=backend->get(key,fldid);
			
		}
		catch (int &a)
		{
			if(a==SO_KEY_NOT_FOUND)
			{
				SoThrowKeyError();
			}
		}
		return ret;
	}

/*	SoStatus putvar(uint key,SoType tag,SoVar var)
	{
		DataNode node={tag,0};
		node.var=var;
		return backend->put(key,&node);
	};

	SoVar getvar(uint key)
	{
		SoVar ret;
		DataNode pnode=backend->get(key);
		DBG_assert(isVar(pnode.tag),("Var type is wrong %d\n",pnode.tag));
		return pnode.var;
	};
	*/
	SoStatus putstr(uint key,DVM_ObjectRef* s)
	{
		DataNode nd;
		nd.tag=SoString;
		wchar_t* str;
		uint len;
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

	SoStatus getstr(uint key,DVM_ObjectRef* outstr)
	{
		wchar_t* pstr;
		uint len=0;
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

	uint allockey(SoType tag,int fld_cnt)
	{
		
		//nd.tag=SoInvalid;
		uint key=0;

		for(int i=0;i<BD_MAX_SHARED_KEY_TRIES;i++)
		{
			key=rand();
			//uint randk=rand();
			//nd.var.vi=randk;
			if(backend->newobj(key,tag,fld_cnt)==SoOK)
			{
				break;
			}
		}
		if(key==0)
			throw SO_KEY_NOT_FOUND;
		return key;
	}
	uint newmodule(uint key,int cnt)
	{
		return backend->newobj(key,SoModule,cnt);
	}
	uint newobj(ExecClass* cls)
	{
		uint ret=allockey(SoObject,cls->field_count);
		if(ret==0)
			SoThrowKeyError();
		return ret;
	};

	uint newstr(DVM_ObjectRef* s)
	{
		uint ret=allockey(SoString,1);
		if(ret==0)
			SoThrowKeyError();
		putstr(ret,s);
		return ret;
	};

	int inc(uint key,int fldid,int inc)
	{
		try
		{
			return backend->inc(key,fldid,inc);
		}
		catch (int &a)
		{
			SoThrowSetValueError();
			return 0;
		}
	}

	int dec(uint key,int fldid,int dec)
	{
		try
		{
			return backend->dec(key,fldid,dec);
		}
		catch (int &a)
		{
			SoThrowSetValueError();
			return 0;
		}
	}

	void setcounter(uint key,int fldid,int n)
	{
		try
		{
			backend->setcounter(key,fldid,n);
		}
		catch (int &a)
		{
			SoThrowSetValueError();
		}
	}

	int getcounter(uint key,int fldid)
	{
		try
		{
			return backend->getcounter(key,fldid);
		}
		catch (int &a)
		{
			SoThrowSetValueError();
			return 0;
		}
	}
};

SharedStorage storage(SoStorageFactory::SoBackendMemcached);





inline uint TranslateKey(uint key)
{
	int id=curthread->current_executable->executable->id;
	if(key>=BD_MAX_SHARED_STATIC_PER_MODULE || id>=BD_MAX_SHARED_MODULES)
	{
		SoThrowKeyError();
	}
	return key+id*BD_MAX_SHARED_STATIC_PER_MODULE;
}

extern "C" BINT SoGeti(uint key,uint fldid)
{
	return storage.get(key,fldid).vi;
}

extern "C" double SoGetd(uint key,uint fldid)
{
	return storage.get(key,fldid).vd;
}

extern "C" DVM_ObjectRef SoGeto(uint key,uint fldid,int idx_in_exe)
{
	DVM_ObjectRef obj;
	int ret= storage.get(key,fldid).key;
	int class_index = curthread->current_executable->class_table[idx_in_exe];
    obj.v_table = curdvm->bclass[class_index]->class_table;
	obj.data=(DVM_Object*)ret;
	return obj;
}

extern "C" DVM_ObjectRef SoGets(uint key,uint fldid)
{
	DVM_ObjectRef ret;

	if(storage.getstr(storage.get(key,fldid).key,&ret)!=SoOK)
		SoThrowGetValueError();	
	return ret;
}

extern "C" void SoSeti(uint key,uint fldid,BINT v)
{
	SoVar var={v};
	if(storage.put(key,fldid,var)!=SoOK)
	{
		SoThrowGetValueError();
	}

}

extern "C" void SoSetd(uint key,uint fldid,double v)
{
	SoVar var={v};
	if(storage.put(key,fldid,var)!=SoOK)
	{
		SoThrowGetValueError();
	}
}

extern "C" void SoSeto(uint key,uint fldid,uint v)
{
	SoVar var={v};
	if(storage.put(key,fldid,var)!=SoOK)
	{
		SoThrowGetValueError();
	}
}

extern "C" void SoSets(uint key,uint fldid,DVM_ObjectRef v)
{
	SoVar var={storage.newstr(&v)};
	if(storage.put(key,fldid,var)!=SoOK)
	{
		SoThrowGetValueError();
	}
}

extern "C" void SoNewModule(uint key,int cnt)
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
	
	uint ret=storage.newobj(curdvm->bclass[class_index]);
	
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

extern "C" DVM_ObjectRef SoNew(int idx_in_exe,int methodid)
{
	int class_index = curthread->current_executable->class_table[idx_in_exe];
	return SoDoNew(class_index,methodid);
}

extern "C" void SoInc(DVM_Value* args)
{
	curthread->retvar.int_value = storage.inc((uint)args[1].object.data,32,args[0].int_value);
}

extern "C" void SoDec(DVM_Value* args)
{
	curthread->retvar.int_value = storage.dec((uint)args[1].object.data,32,args[0].int_value);
}

extern "C" void SoSetCounter(DVM_Value* args)
{
	storage.setcounter((uint)args[1].object.data,32,args[0].int_value);
}

extern "C" void SoGetCounter(DVM_Value* args)
{
	storage.getcounter((uint)args[1].object.data,32);
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



extern BdStatus CpDumpBuffer(void* pArr,BINT size,CPBuffer* pbuf);
extern BdStatus CpDumpStringW(wchar_t* p,CPBuffer* pbuf);
extern "C" int ExDoInstanceOf(DVM_ObjectRef* obj,BINT target_idx);

int clsSharedObj=-1;


/*
void SoDoDump(DVM_Object* obj,ExecClass* cls,CPBuffer* pbuf)
{

	CpDumpBuffer(&cls->class_index ,sizeof(cls->class_index),pbuf); //fix-me : class index may be different in different machines
	for(int i=0;i<cls->field_count;i++)
	{
		DVM_Boolean isobj=DVM_FALSE;
		if(cls->field_type[i]->derive==NULL)
		{
			switch(cls->field_type[i]->basic_type)
			{
			case DVM_BOOLEAN_TYPE:
			case DVM_INT_TYPE:
				CpDumpBuffer(&obj->u.class_object.field[i].int_value,sizeof(BINT),pbuf);
				break;
			case DVM_DOUBLE_TYPE:
				CpDumpBuffer(&obj->u.class_object.field[i].int_value,sizeof(BINT),pbuf);
				break;
			case DVM_STRING_TYPE:
				//CpDumpStringW(obj.data->u.class_object.field[i].object.data->u.string.string , pbuf);
				break;
			case DVM_CLASS_TYPE:
				if(clsSharedObj==-1)
				{
					clsSharedObj=DVM_search_class(curdvm,"lang.diksam","SharedObject");
					DBG_assert(clsSharedObj!=-1,("Cannot find SharedObject class!"));
				}
				if(!ExDoInstanceOf(&obj->u.class_object.field[i].object,clsSharedObj))
				{
					int clsid;
					ExCreateExceptionEx(curdvm,"ClassCastException",&clsid,CLASS_CAST_ERR,
						DVM_STRING_MESSAGE_ARGUMENT, "org",obj->u.class_object.field[i].object.v_table->exec_class->name ,
                                   DVM_STRING_MESSAGE_ARGUMENT, "target","SharedObj");
					ExRaiseException(clsid+1);
				}
				CpDumpBuffer(& obj->u.class_object.field[i].object.data->u.class_object.field[0].int_value,sizeof(BINT),pbuf);
				break;
			default:
				DBG_assert(0, ("Error Type %d", cls->field_type[i]->basic_type));	
			}
		}
		else if(cls->field_type[i]->derive->tag==DVM_ARRAY_DERIVE)
		{
			//int arrsz=0;
			//arrsz=cls->field_type[i]->derive_count;//check if it is right
			//ExSerializeArray(obj.data->u.class_object.field[i].object,args[0].object,cls->field_type[i]->basic_type,arrsz);
			DBG_assert(0, ("Error Derive %d"));	
		}
		else
		{
			DBG_assert(0, ("Error Derive %d"));	
		}


	}
}*/