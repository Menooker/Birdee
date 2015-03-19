#include "BdVarients.h"

#include "BdException.h"
#include <stdlib.h>
#include <string>
#include "hash_compatible.h"


using namespace std;

extern "C"
{
#include "../../dvm/dvm_pri.h"
#include "../../include/MEM.h"
DVM_VirtualMachine_tag* curdvm;


typedef hash_map<string,DVM_ObjectRef> AvMap;
AvMap MainMap;


void AvDisposeMap(AvMap* mp)
{
	/*hash_map<string,DVM_ObjectRef>::iterator it;
	for(it=(*mp).begin();it!=(*mp).end();it++)
	{
		MEM_free(it->second.data);
	}*/
}

void AvPushNullContext()
{
	curdvm->avstack[curdvm->asp].p=0;
	curdvm->asp++;
}

void AvPopContext()
{
	curdvm->asp--;
	AvMap* pp=(AvMap*)curdvm->avstack[curdvm->asp].p;
	if(pp)
	{
		AvDisposeMap(pp);//fix-me : should we disopse the Varients here or let GC do the clean work?
		pp->~ hash_map<string,DVM_ObjectRef>();
		MEM_free(pp);
	}
}

void AvPutContext()
{
	AvMap* newmap=(AvMap*)MEM_malloc(sizeof(AvMap));

	newmap=new(newmap)AvMap(); //check-me
	curdvm->avstack[curdvm->asp-1].p=newmap;

}



BdStatus AvDoGeti(ExVarient* va,BINT* ret)
{
	int s;
	switch(va->type)
	{
	case AV_INT:
		*ret= va->v.int_value;
		return BdSuccess;
		break;
	case AV_DOUBLE:
		*ret= (int)(va->v.double_value);
		return BdSuccess;
		break;
	case AV_STRING:
		s=swscanf_s(va->v.object.data->u.string.string,L"%d",ret);
		return  s? BdSuccess:BdStringNotNumber;
		break;
	case AV_OBJECT:
		_BreakPoint() //fix-me
	}
}

void AvGeti()
{
	DVM_ObjectRef* v=&curdvm->stack.stack[curdvm->stack.stack_pointer-1].object ;
	ExVarient* va=v->data->u.var.pobj;
	if(AvDoGeti(va,&curdvm->retvar.int_value))
	{
		ExSystemRaise(ExVarBadStringForNumber);
	}
	curdvm->stack.stack_pointer--;
}

BdStatus AvDoGetd(ExVarient* va,double* ret)
{
	int s;
	switch(va->type)
	{
	case AV_INT:
		*ret= (double)va->v.int_value;
		return BdSuccess;
		break;
	case AV_DOUBLE:
		*ret= va->v.double_value;
		return BdSuccess;
		break;
	case AV_STRING:
		s=swscanf_s(va->v.object.data->u.string.string,L"%lf",ret);
		return  s? BdSuccess:BdStringNotNumber;
		break;
	case AV_OBJECT:
		_BreakPoint() //fix-me
	}
}

void AvGetd()
{
	DVM_ObjectRef* v=&curdvm->stack.stack[curdvm->stack.stack_pointer-1].object ;
	ExVarient* va=v->data->u.var.pobj;
	if(AvDoGetd(va,&curdvm->retvar.double_value))
	{
		ExSystemRaise(ExVarBadStringForNumber);
	}
	curdvm->stack.stack_pointer--;
}

DVM_ObjectRef AvPrintf(wchar_t* str,...)
{
	va_list pvar;
	va_start(pvar, str);
	int bufsize=30;
    DVM_Char* result =(DVM_Char*) MEM_malloc(sizeof(DVM_Char) * (30));
	while(vswprintf_s(result,30,str,pvar)==-1) //find a proper size
	{
		bufsize+=30;
		result =(DVM_Char*) MEM_realloc(result,sizeof(DVM_Char) * bufsize);
	}
    return dvm_create_dvm_string_i(curdvm, result);
}

DVM_ObjectRef AvDoGets(ExVarient* va)
{
	//dvm_create_dvm_string_i
	switch(va->type)
	{
	case AV_INT:
		return AvPrintf(L"%d",va->v.int_value);
		break;
	case AV_DOUBLE:
		return AvPrintf(L"%lf",va->v.double_value);
		break;
	case AV_STRING:
		return  (va->v.object);
		break;
	case AV_OBJECT:
		_BreakPoint() //fix-me
	}
}

void AvGets()
{
	DVM_ObjectRef* v=&curdvm->stack.stack[curdvm->stack.stack_pointer-1].object ;
	ExVarient* va=v->data->u.var.pobj;
	curdvm->retvar.object =AvDoGets(va);
	curdvm->stack.stack_pointer--;
}


void AvSeti()
{
	DVM_ObjectRef* v=&curdvm->stack.stack[curdvm->stack.stack_pointer-1].object ;
	BINT val=curdvm->stack.stack[curdvm->stack.stack_pointer-2].int_value  ;
	v->data->u.var.pobj->type=AV_INT;
	v->data->u.var.pobj->v.int_value=val;
	curdvm->stack.stack_pointer-=2;
}

void AvSetd()
{
	DVM_ObjectRef* v=&curdvm->stack.stack[curdvm->stack.stack_pointer-1].object ;
	double val=curdvm->stack.stack[curdvm->stack.stack_pointer-2].double_value   ;
	v->data->u.var.pobj->type=AV_DOUBLE;
	v->data->u.var.pobj->v.double_value =val;
	curdvm->stack.stack_pointer-=2;
}
void AvSets()
{
	DVM_ObjectRef* v=&curdvm->stack.stack[curdvm->stack.stack_pointer-1].object ;
	//DVM_ObjectRef val=curdvm->stack.stack[curdvm->stack.stack_pointer-2].object ;
	v->data->u.var.pobj->type = AV_STRING;
	v->data->u.var.pobj->v.object =curdvm->stack.stack[curdvm->stack.stack_pointer-2].object;
	curdvm->stack.stack_pointer-=2;
}
void AvCopyVar()
{
	DVM_ObjectRef* v = &curdvm->stack.stack[curdvm->stack.stack_pointer-1].object ;
	ExVarient* src = curdvm->stack.stack[curdvm->stack.stack_pointer-2].object.data->u.var.pobj;
	*v->data->u.var.pobj = *src;
	curdvm->stack.stack_pointer-=2;
}


extern "C" DVM_ObjectRef chain_string(DVM_VirtualMachine *dvm, DVM_ObjectRef str1, DVM_ObjectRef str2);
DVM_ObjectRef AvDoAdd(ExVarient* a,ExVarient* b)
{
	DVM_ObjectRef ret=ExCreateVar(curdvm,0);
	ExVarient* r=ret.data->u.var.pobj ;
	if( a->type == AV_OBJECT || b->type == AV_OBJECT)
	{
		_BreakPoint() //fix-me
	}
	if(a->type == AV_INT )
	{
		switch(b->type )
		{
		case AV_INT:
			r->type=AV_INT;
			r->v.int_value=a->v.int_value+b->v.int_value;
			return ret;
		case AV_DOUBLE:
			r->type=AV_DOUBLE;
			r->v.double_value =a->v.int_value+b->v.double_value;
			return ret;
		case AV_STRING:
			r->type=AV_STRING;
			r->v.object  =AvPrintf(L"%d%s",a->v.int_value,b->v.object.data->u.string.string);
			return ret;
		}
	}
	if(a->type == AV_DOUBLE )
	{
		switch(b->type )
		{
		case AV_INT:
			r->type=AV_DOUBLE;
			r->v.double_value =a->v.double_value+b->v.int_value;
			return ret;
		case AV_DOUBLE:
			r->type=AV_DOUBLE;
			r->v.double_value =a->v.double_value+b->v.double_value;
			return ret;
		case AV_STRING:
			r->type=AV_STRING;
			r->v.object  =AvPrintf(L"%lf%s",a->v.double_value,b->v.object.data->u.string.string);
			return ret;
		}
	}
	if(a->type == AV_STRING )
	{
		r->type=AV_STRING;
		r->v.object  = chain_string(curdvm,a->v.object,AvDoGets(b));
		return ret;
	}
}
void AvAdd()
{

	ExVarient* rv = curdvm->stack.stack[curdvm->stack.stack_pointer-1].object.data->u.var.pobj;
	ExVarient* lv = curdvm->stack.stack[curdvm->stack.stack_pointer-2].object.data->u.var.pobj;
	curdvm->retvar.object=AvDoAdd(lv,rv);
	curdvm->stack.stack_pointer-=2;
}

DVM_ObjectRef AvDoSub(ExVarient* a,ExVarient* b)
{
	DVM_ObjectRef ret=ExCreateVar(curdvm,0);
	ExVarient* r=ret.data->u.var.pobj ;
	if( a->type == AV_OBJECT || b->type == AV_OBJECT)
	{
		_BreakPoint() //fix-me
	}
	if(a->type == AV_INT )
	{
		switch(b->type )
		{
		case AV_INT:
			r->type=AV_INT;
			r->v.int_value=a->v.int_value-b->v.int_value;
			return ret;
		case AV_DOUBLE:
			r->type=AV_DOUBLE;
			r->v.double_value =a->v.int_value-b->v.double_value;
			return ret;
		case AV_STRING:
			ExSystemRaise(ExVarStringOpNotSupported);
			return ret;
		}
	}
	if(a->type == AV_DOUBLE )
	{
		switch(b->type )
		{
		case AV_INT:
			r->type=AV_DOUBLE;
			r->v.double_value =a->v.double_value-b->v.int_value;
			return ret;
		case AV_DOUBLE:
			r->type=AV_DOUBLE;
			r->v.double_value =a->v.double_value-b->v.double_value;
			return ret;
		case AV_STRING:
			ExSystemRaise(ExVarStringOpNotSupported);
			return ret;
		}
	}
	if(a->type == AV_STRING )
	{
		ExSystemRaise(ExVarStringOpNotSupported);
		return ret;
	}
}
void AvSub()
{
	ExVarient* rv = curdvm->stack.stack[curdvm->stack.stack_pointer-1].object.data->u.var.pobj;
	ExVarient* lv = curdvm->stack.stack[curdvm->stack.stack_pointer-2].object.data->u.var.pobj;
	curdvm->retvar.object=AvDoSub(lv,rv);
	curdvm->stack.stack_pointer-=2;
}

DVM_ObjectRef AvDoMul(ExVarient* a,ExVarient* b)
{
	DVM_ObjectRef ret=ExCreateVar(curdvm,0);
	ExVarient* r=ret.data->u.var.pobj ;
	if( a->type == AV_OBJECT || b->type == AV_OBJECT)
	{
		_BreakPoint() //fix-me
	}
	if(a->type == AV_INT )
	{
		switch(b->type )
		{
		case AV_INT:
			r->type=AV_INT;
			r->v.int_value=a->v.int_value*b->v.int_value;
			return ret;
		case AV_DOUBLE:
			r->type=AV_DOUBLE;
			r->v.double_value =a->v.int_value*b->v.double_value;
			return ret;
		case AV_STRING:
			ExSystemRaise(ExVarStringOpNotSupported);
			return ret;
		}
	}
	if(a->type == AV_DOUBLE )
	{
		switch(b->type )
		{
		case AV_INT:
			r->type=AV_DOUBLE;
			r->v.double_value =a->v.double_value*b->v.int_value;
			return ret;
		case AV_DOUBLE:
			r->type=AV_DOUBLE;
			r->v.double_value =a->v.double_value*b->v.double_value;
			return ret;
		case AV_STRING:
			ExSystemRaise(ExVarStringOpNotSupported);
			return ret;
		}
	}
	if(a->type == AV_STRING )
	{
		ExSystemRaise(ExVarStringOpNotSupported);
		return ret;
	}
}
void AvMul()
{
	ExVarient* rv = curdvm->stack.stack[curdvm->stack.stack_pointer-1].object.data->u.var.pobj;
	ExVarient* lv = curdvm->stack.stack[curdvm->stack.stack_pointer-2].object.data->u.var.pobj;
	curdvm->retvar.object=AvDoMul(lv,rv);
	curdvm->stack.stack_pointer-=2;
}

DVM_ObjectRef AvDoDiv(ExVarient* a,ExVarient* b)
{
	DVM_ObjectRef ret=ExCreateVar(curdvm,0);
	ExVarient* r=ret.data->u.var.pobj ;
	if( a->type == AV_OBJECT || b->type == AV_OBJECT)
	{
		_BreakPoint() //fix-me
	}
	if(a->type == AV_INT )
	{
		switch(b->type )
		{
		case AV_INT:
			r->type=AV_INT;
			r->v.int_value=a->v.int_value/b->v.int_value;
			return ret;
		case AV_DOUBLE:
			r->type=AV_DOUBLE;
			r->v.double_value =a->v.int_value/b->v.double_value;
			return ret;
		case AV_STRING:
			ExSystemRaise(ExVarStringOpNotSupported);
			return ret;
		}
	}
	if(a->type == AV_DOUBLE )
	{
		switch(b->type )
		{
		case AV_INT:
			r->type=AV_DOUBLE;
			r->v.double_value =a->v.double_value/b->v.int_value;
			return ret;
		case AV_DOUBLE:
			r->type=AV_DOUBLE;
			r->v.double_value =a->v.double_value/b->v.double_value;
			return ret;
		case AV_STRING:
			ExSystemRaise(ExVarStringOpNotSupported);
			return ret;
		}
	}
	if(a->type == AV_STRING )
	{
		ExSystemRaise(ExVarStringOpNotSupported);
		return ret;
	}
}
void AvDiv()
{
	ExVarient* rv = curdvm->stack.stack[curdvm->stack.stack_pointer-1].object.data->u.var.pobj;
	ExVarient* lv = curdvm->stack.stack[curdvm->stack.stack_pointer-2].object.data->u.var.pobj;
	curdvm->retvar.object=AvDoDiv(lv,rv);
	curdvm->stack.stack_pointer-=2;
}

DVM_ObjectRef AvDoMod(ExVarient* a,ExVarient* b)
{
	DVM_ObjectRef ret=ExCreateVar(curdvm,0);
	ExVarient* r=ret.data->u.var.pobj ;
	if( a->type == AV_OBJECT || b->type == AV_OBJECT)
	{
		_BreakPoint() //fix-me
	}
	if(a->type == AV_INT )
	{
		switch(b->type )
		{
		case AV_INT:
			r->type=AV_INT;
			r->v.int_value=a->v.int_value%b->v.int_value;
			return ret;
		case AV_DOUBLE:
			r->type=AV_DOUBLE;
			r->v.double_value =a->v.int_value%(int)b->v.double_value;
			return ret;
		case AV_STRING:
			ExSystemRaise(ExVarStringOpNotSupported);
			return ret;
		}
	}
	if(a->type == AV_DOUBLE )
	{
		switch(b->type )
		{
		case AV_INT:
			r->type=AV_DOUBLE;
			r->v.double_value =(int)a->v.double_value%b->v.int_value;
			return ret;
		case AV_DOUBLE:
			r->type=AV_DOUBLE;
			r->v.double_value =(int)a->v.double_value%(int)b->v.double_value;
			return ret;
		case AV_STRING:
			ExSystemRaise(ExVarStringOpNotSupported);
			return ret;
		}
	}
	if(a->type == AV_STRING )
	{
		ExSystemRaise(ExVarStringOpNotSupported);
		return ret;
	}
}
void AvMod()
{
	ExVarient* rv = curdvm->stack.stack[curdvm->stack.stack_pointer-1].object.data->u.var.pobj;
	ExVarient* lv = curdvm->stack.stack[curdvm->stack.stack_pointer-2].object.data->u.var.pobj;
	curdvm->retvar.object=AvDoMod(lv,rv);
	curdvm->stack.stack_pointer-=2;
}

BINT AvCmpDouble(double d)
{
			if(d>0)
				return  1;
			else if (d<0)
				return -1;
			else
				return 0;
}

BINT AvDoCmp(ExVarient* a,ExVarient* b)
{
	BINT ret=0;
	if( a->type == AV_OBJECT || b->type == AV_OBJECT)
	{
		_BreakPoint() //fix-me
	}
	if(a->type == AV_INT )
	{
		switch(b->type )
		{
		case AV_INT:
			return  a->v.int_value-b->v.int_value;
		case AV_DOUBLE:
			return AvCmpDouble((double)a->v.int_value-b->v.double_value);
		case AV_STRING:
			ExSystemRaise(ExVarStringOpNotSupported);
			return ret;
		}
	}
	if(a->type == AV_DOUBLE )
	{
		switch(b->type )
		{
		case AV_INT:
			return AvCmpDouble(a->v.double_value - (double)b->v.int_value);
		case AV_DOUBLE:
			return AvCmpDouble(a->v.double_value-b->v.double_value);
		case AV_STRING:
			ExSystemRaise(ExVarStringOpNotSupported);
			return ret;
		}
	}
	if(a->type == AV_STRING )
	{
		if(b->type ==AV_STRING)
			return dvm_wcscmp(a->v.object.data->u.string.string,b->v.object.data->u.string.string);
		ExSystemRaise(ExVarStringOpNotSupported);
	}
}
void AvCmp()
{
	ExVarient* rv = curdvm->stack.stack[curdvm->stack.stack_pointer-1].object.data->u.var.pobj;
	ExVarient* lv = curdvm->stack.stack[curdvm->stack.stack_pointer-2].object.data->u.var.pobj;
	curdvm->retvar.int_value=AvDoCmp(lv,rv);
	curdvm->stack.stack_pointer-=2;
}

DVM_ObjectRef AvGetOrCreateVar(char* name)
{
	DVM_ObjectRef ret;
	if(*name=='#')
	{
		name++;
		AvMap* mp=(AvMap*)AvGetTopContext().p;
		if(mp == NULL)
		{
			AvPutContext();
			mp=(AvMap*)AvGetTopContext().p;
		}
		if((*mp).find(name)!=(*mp).end())
		{
			return (*mp)[name];
		}
		else
		{
			ret= ExLoadStaticVar(curdvm,(ExVarient*)MEM_malloc(sizeof(ExVarient*)));
			(*mp)[name]=ret;
			return ret;
		}
	}
	else if(*name=='$')
	{
		name++;
		if(MainMap.find(name)==MainMap.end())
		{
			ret= ExLoadStaticVar(curdvm,(ExVarient*)MEM_malloc(sizeof(ExVarient*)));
			MainMap[name]=ret;
		}
		else
			ret=MainMap[name];
		return ret;
	}
	return dvm_null_object_ref;

}



DVM_ObjectRef AvGetVar(char* name)
{
	if(*name=='#')
	{
		name++;
		AvMap* mp=(AvMap*)AvGetTopContext().p;
		if(mp != NULL)
		{
			if((*mp).find(name)!=(*mp).end())
			{
				return (*mp)[name];
			}
		}
		//if no context or var not found
		ExSystemRaise(ExVarUseBeforeSet);
	}
	else if(*name=='$')
	{
		name++;
		if(MainMap.find(name)!=MainMap.end())
		{
			return MainMap[name];
		}
		else
		{
			ExSystemRaise(ExVarUseBeforeSet);
		}
	}
	return dvm_null_object_ref;
}


extern "C" void gc_mark(DVM_ObjectRef *ref);
void AvMarkObjects()
{
	hash_map<string,DVM_ObjectRef>::iterator it;
	for(it=MainMap.begin();it!=MainMap.end();it++)
	{
		gc_mark(&it->second);

	}
	for(int i=0;i<curdvm->asp ;i++)
	{
		AvMap* pp=(AvMap*)curdvm->avstack[i].p;
		if(pp)
		{
			for(it=(*pp).begin();it!=(*pp).end();it++)
			{
				gc_mark(&it->second);

			}
		}
	}
}

/*
void AvSetVar(char* name,DVM_ObjectRef v)
{
	if(MainMap.find(name)!=MainMap.end())
	{
		MainMap[name]=(ExVarient*)MEM_malloc(sizeof(ExVarient*));
	}
	*MainMap[name]=*v.data->u.var.pobj;
}*/



void AvDisposeMainMap()
{
	AvDisposeMap(&MainMap);
}

}
