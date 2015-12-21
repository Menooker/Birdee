#include "BirdeeDef.h"
#include "BdExec.h"
#include "BdException.h"
#include "debug.h"
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

	int getsize(_uint key)
	{
		return map[key].cls.field_cnt;
	}

	int inc(_uint key,int fldid,int inc)
	{
		return UaAtomicInc((long*)&map[MAKE64(key,fldid)].var.vi,inc);
	}

	int dec(_uint key,int fldid,int dec)
	{
		return UaAtomicDec((long*)&map[MAKE64(key,fldid)].var.vi,dec);
	}

	int getcounter(_uint key,int fldid)
	{
		return atoi((char*)map[MAKE64(key,fldid)].string.str);
	}
	void setcounter(_uint key,int fldid,int n)
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

	SoStatus getstr(_uint key,wchar_t** str,_uint* len)
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

	SoStatus put(_uint key,int fldid,SoVar v)
	{
		map[MAKE64(key,fldid)].var=v;
		return SoOK;
	}

	SoVar get(_uint key,int fldid)
	{
		if(map.find(MAKE64(key,fldid))!=map.end())
			return map[MAKE64(key,fldid)].var;
		throw SO_KEY_NOT_FOUND;
	}

	bool exists(_uint key)
	{
		return map.find(MAKE64(key,0))!=map.end();
	}

	SoStatus newobj(_uint key,SoType tag,int fld_cnt,int flag)
	{
		if(map.find(MAKE64(key,0))==map.end())
		{
			DataNode nd;
			nd.tag=tag;
			nd.flag=flag;
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
	SoStatus put(_uint key,int fldid,SoVar v)
	{
		return backend->put(key,fldid,v);
	}

	SoVar get(_uint key,int fldid)
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

/*	SoStatus putvar(_uint key,SoType tag,SoVar var)
	{
		DataNode node={tag,0};
		node.var=var;
		return backend->put(key,&node);
	};

	SoVar getvar(_uint key)
	{
		SoVar ret;
		DataNode pnode=backend->get(key);
		DBG_assert(isVar(pnode.tag),("Var type is wrong %d\n",pnode.tag));
		return pnode.var;
	};
	*/
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

	_uint allockey(SoType tag,int fld_cnt)
	{
		return allockey(tag,fld_cnt,0);
	}
	_uint allockey(SoType tag,int fld_cnt,int flag)
	{
		//nd.tag=SoInvalid;
		_uint key=0;

		for(int i=0;i<BD_MAX_SHARED_KEY_TRIES;i++)
		{
			key=rand();
			//_uint randk=rand();
			//nd.var.vi=randk;
			if(backend->newobj(key,tag,fld_cnt,0)==SoOK)
			{
				break;
			}
		}
		if(key==0)
			throw SO_KEY_NOT_FOUND;
		return key;
	}
	_uint newmodule(_uint key,int cnt)
	{
		return backend->newobj(key,SoModule,cnt,0);
	}
	_uint newobj(ExecClass* cls)
	{
		_uint ret=allockey(SoObject,cls->field_count);
		if(ret==0)
			SoThrowKeyError();
		return ret;
	};
	_uint newarray(int size, int isobj)
	{
		_uint ret=allockey(SoArray,size,isobj);
		if(ret==0)
			SoThrowKeyError();
		return ret;
	};
	_uint newstr(DVM_ObjectRef* s)
	{
		_uint ret=allockey(SoString,1);
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
		catch (int &a)
		{
			SoThrowKeyError();
			return 0;
		}
	};

	int inc(_uint key,int fldid,int inc)
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

	int dec(_uint key,int fldid,int dec)
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

	void setcounter(_uint key,int fldid,int n)
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

	int getcounter(_uint key,int fldid)
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





inline _uint TranslateKey(_uint key)
{
	int id=curthread->current_executable->executable->id;
	if(key>=BD_MAX_SHARED_STATIC_PER_MODULE || id>=BD_MAX_SHARED_MODULES)
	{
		SoThrowKeyError();
	}
	return key+id*BD_MAX_SHARED_STATIC_PER_MODULE;
}

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
		obj.v_table=curdvm->array_v_table;
	obj.data=(DVM_Object*)ret;
	curthread->retvar.object=obj;
	return ;
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
	SoVar var={v};
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
    DVM_ObjectRef exception_dummy;
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
			ret = storage.newarray(size,0);
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
        ret = storage.newarray(size,1);
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

DVM_ObjectRef SoCreateArray(DVM_VirtualMachine *dvm, int dim, DVM_TypeSpecifier *type)
{
    DVM_ObjectRef ret;
	ret.data= (DVM_Object*)SoDoCreateArray(dvm, dim, 0, type);
	ret.v_table = dvm->array_v_table;//fix-me :
    curthread->stack.stack_pointer -= dim; curthread->stack.flg_sp -=dim;
	return ret;
}


void SoNewArray(BINT ty,BINT dim)
{
    DVM_TypeSpecifier *type
		= &curthread->current_executable->executable->type_specifier[ty];
    curthread->retvar.object= SoCreateArray(curdvm, dim, type);
    return;
}

extern "C" void SoGlobalArrBoundaryCheck(BINT arr,BINT idx)
{
	if(idx>=storage.getsize(arr))
	{
		ExSystemRaise(ExArrayIndexOutOfBoundErr);
	}
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
