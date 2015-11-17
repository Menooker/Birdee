#include "BirdeeDef.h"
#include "BdExec.h"
#include "BdException.h"
#include "../../debug/debug.h"
#include "hash_compatible.h"
extern void ExCall(BINT index);

extern "C" DVM_ObjectRef dvm_literal_to_dvm_string_i(DVM_VirtualMachine *dvm, DVM_Char *str);

enum SoStatus
{
	SoOK,
	SoUnknown,
	SoKeyNotFound,
	SoFail,
};

enum SoType
{
	SoInvalid,
	SoInt,
	SoDouble,
	SoString,
	SoObject,
	SoArray
};




union SoVar 
{
	BINT vi;
	double vd;
	uint key;
};
struct DataNode
{
	SoType tag;
	union
	{
		SoVar var;
		struct 
		{
			wchar_t* str;
			size_t len;
		}string;
		struct
		{
			//uint clsid;
			SoVar* fields;
			size_t field_cnt;
		}cls;

		struct
		{
			SoType ty;
			SoVar* arr;
			size_t arr_cnt;
		}barray;
	};
		

};
class SoStorage
{
public:
	virtual SoStatus put(uint key,DataNode* nd)=0;
	virtual DataNode get(uint key)=0;
	virtual bool exists(uint key)=0;
	virtual SoStatus newobj(uint key,DataNode* nd)=0;
};


void SoThrowSetValueError()
{
	//fix-me : implement me
}

void SoThrowGetValueError()
{
	//fix-me : implement me
}

void SoThrowKeyError()
{
	//fix-me : implement me
}

class SoStorageLocalTest : public SoStorage
{
private:

	std::hash_map<uint,DataNode> map;
public:
	SoStatus put(uint key,DataNode* nd)
	{
		map[key]=*nd;
		return SoOK;
	}
	DataNode get(uint key)
	{
		if(map.find(key)!=map.end())
			return map[key];
		else
		{
			DataNode a;
			a.tag=SoInvalid;
			return a;
		}
	}

	bool exists(uint key)
	{
		return map.find(key)!=map.end();
	}

	SoStatus newobj(uint key,DataNode* nd)
	{
		DBG_assert(nd->tag==SoObject,("Node type is wrong %d\n",nd->tag));
		if(map.find(key)==map.end())
		{
			nd->cls.fields=(SoVar*)malloc(sizeof(SoVar)* nd->cls.field_cnt);
			map[key]=*nd;
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
		SoBackendDHT,
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
			return new SoStorageLocalTest();
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
	SoStatus put(uint key,SoType tag,SoVar* buf,size_t sz)
	{
		DataNode node={tag,0};

		node.cls.fields=(SoVar*)malloc(sz*sizeof(SoVar));
		memcpy(node.cls.fields,buf,sz*sizeof(SoVar));
		node.cls.field_cnt=sz;
		
		return backend->put(key,&node);
	}

	SoVar get(uint key,int fldid)
	{
		DataNode pnode=backend->get(key);
		DBG_assert(pnode.tag==SoObject,("Var type is wrong %d\n",pnode.tag));
	    return pnode.cls.fields[fldid];
	}

	SoStatus putvar(uint key,SoType tag,SoVar var)
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

	SoStatus putstr(uint key,DVM_ObjectRef* s)
	{
		DataNode nd;
		nd.tag=SoString;
		if(s->data)
		{
			nd.string.len=s->data->u.string.length;
			nd.string.str=s->data->u.string.string;
		}
		else
		{
			nd.string.len=0;
			nd.string.str=NULL;
		}
		return backend->put(key,&nd);
	}

	SoStatus getstr(uint key,DVM_ObjectRef* outstr)
	{
		DataNode nd=backend->get(key);
		if(nd.tag!=SoString)
			return SoUnknown;
		if(!nd.string.str)
		{
			outstr->data=NULL;
			outstr->v_table=NULL;
		}
		else
			*outstr=dvm_literal_to_dvm_string_i(curdvm,nd.string.str);
		return SoOK;
	}

	uint allockey(DataNode* nd)
	{
		
		//nd.tag=SoInvalid;
		uint key=0;

		for(int i=0;i<BD_MAX_SHARED_KEY_TRIES;i++)
		{
			key=rand();
			//uint randk=rand();
			//nd.var.vi=randk;
			if(!backend->exists(key))//fix-me : may conflict
			{
				backend->newobj(key,nd);
				break;
			}
		}
		return key;
	}

	uint newobj(ExecClass* cls)
	{
		DataNode nd;
		nd.tag=SoObject;
		nd.cls.field_cnt=cls->field_count;
		uint ret=allockey(&nd);
		if(!ret)
			SoThrowKeyError();
		return ret;
	};
};

SharedStorage storage(SoStorageFactory::SoBackendTest);





inline uint TranslateKey(uint key)
{
	int id=curthread->current_executable->executable->id;
	if(key>=BD_MAX_SHARED_STATIC_PER_MODULE || id>=BD_MAX_SHARED_MODULES)
	{
		SoThrowKeyError();
	}
	return key+id*BD_MAX_SHARED_STATIC_PER_MODULE;
}

extern "C" BINT SoGeti(uint key)
{
	return storage.getvar(TranslateKey(key)).vi;
}

extern "C" double SoGetd(uint key)
{
	return storage.getvar(TranslateKey(key)).vd;
}

extern "C" BINT SoGeto(uint key)
{
	return storage.getvar(TranslateKey(key)).key;
}

extern "C" DVM_ObjectRef SoGets(uint key)
{
	DVM_ObjectRef ret;
	if(!storage.getstr(TranslateKey(key),&ret)==SoOK)
		SoThrowGetValueError();	
	return ret;
}

extern "C" void SoSeti(uint key,BINT v)
{
	SoVar var={v};
	if(storage.putvar(TranslateKey(key),SoInt,var)!=SoOK)
	{
		SoThrowGetValueError();
	}

}

extern "C" void SoSetd(uint key,double v)
{
	SoVar var={v};
	if(storage.putvar(TranslateKey(key),SoDouble,var)!=SoOK)
	{
		SoThrowGetValueError();
	}
}

extern "C" void SoSeto(uint key,uint v)
{
	SoVar var={v};
	if(storage.putvar(TranslateKey(key),SoObject,var)!=SoOK)
	{
		SoThrowGetValueError();
	}
}

extern "C" void SoSets(uint key,DVM_ObjectRef v)
{
	if(storage.putstr(TranslateKey(key),&v)!=SoOK)
	{
		SoThrowGetValueError();
	}
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