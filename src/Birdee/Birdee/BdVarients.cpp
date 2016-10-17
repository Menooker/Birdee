#include "BdVarients.h"

#include "BdException.h"
#include <stdlib.h>
#include <string>
#include <string.h>
#include <wchar.h>
#include "hash_compatible.h"
#include "UnportableAPI.h"

using namespace std;

extern "C"
{
#include "dvm_pri.h"
#include "MEM.h"
//DVM_VirtualMachine_tag* curdvm;


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
	curthread->avstack[curthread->asp].p=0;
	curthread->asp++;
}

void AvPopContext()
{
	curthread->asp--;
	AvMap* pp=(AvMap*)curthread->avstack[curthread->asp].p;
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
	curthread->avstack[curthread->asp-1].p=newmap;

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
		_BreakPoint //fix-me
	}
}

void AvGeti()
{
	DVM_ObjectRef* v=&(curthread->stack.stack_pointer-1)->object ;
	ExVarient* va=v->data->u.var.pobj;
	if(AvDoGeti(va,&curthread->retvar.int_value))
	{
		ExSystemRaise(ExVarBadStringForNumber);
	}
	curthread->stack.stack_pointer--;curthread->stack.flg_sp--;
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
		_BreakPoint //fix-me
	}
}

void AvGetd()
{
	DVM_ObjectRef* v=&(curthread->stack.stack_pointer-1)->object ;
	ExVarient* va=v->data->u.var.pobj;
	if(AvDoGetd(va,&curthread->retvar.double_value))
	{
		ExSystemRaise(ExVarBadStringForNumber);
	}
	curthread->stack.stack_pointer--;curthread->stack.flg_sp--;
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
		_BreakPoint //fix-me
	}
}

void AvGets()
{
	DVM_ObjectRef* v=&(curthread->stack.stack_pointer-1)->object ;
	ExVarient* va=v->data->u.var.pobj;
	curthread->retvar.object =AvDoGets(va);
	curthread->stack.stack_pointer--;curthread->stack.flg_sp--;
}


void AvNewi()
{
	DVM_ObjectRef v=ExCreateVar(curdvm,0);
	BINT val=(curthread->stack.stack_pointer-1)->int_value  ;
	v.data->u.var.pobj->type=AV_INT;
	v.data->u.var.pobj->v.int_value=val;
	curthread->retvar.object=v;
	curthread->stack.stack_pointer-- ;curthread->stack.flg_sp--;
}

void AvNewd()
{
	DVM_ObjectRef v=ExCreateVar(curdvm,0);
	double val=(curthread->stack.stack_pointer-1)->double_value   ;
	v.data->u.var.pobj->type=AV_DOUBLE;
	v.data->u.var.pobj->v.double_value =val;
	curthread->retvar.object=v;
	curthread->stack.stack_pointer-- ;curthread->stack.flg_sp--;
}
void AvNews()
{
	DVM_ObjectRef v=ExCreateVar(curdvm,0);
	//DVM_ObjectRef val=(curthread->stack.stack_pointer-2)->object ;
	v.data->u.var.pobj->type = AV_STRING;
	v.data->u.var.pobj->v.object =(curthread->stack.stack_pointer-1)->object;
	curthread->retvar.object=v;
	curthread->stack.stack_pointer-- ;curthread->stack.flg_sp--;
}


void AvSeti()
{
	DVM_ObjectRef* v=&(curthread->stack.stack_pointer-1)->object ;
	BINT val=(curthread->stack.stack_pointer-2)->int_value  ;
	v->data->u.var.pobj->type=AV_INT;
	v->data->u.var.pobj->v.int_value=val;
	curthread->stack.stack_pointer-=2 ;curthread->stack.flg_sp-=2;
}

void AvSetd()
{
	DVM_ObjectRef* v=&(curthread->stack.stack_pointer-1)->object ;
	double val=(curthread->stack.stack_pointer-2)->double_value   ;
	v->data->u.var.pobj->type=AV_DOUBLE;
	v->data->u.var.pobj->v.double_value =val;
	curthread->stack.stack_pointer-=2 ;curthread->stack.flg_sp-=2;
}
void AvSets()
{
	DVM_ObjectRef* v=&(curthread->stack.stack_pointer-1)->object ;
	//DVM_ObjectRef val=(curthread->stack.stack_pointer-2)->object ;
	v->data->u.var.pobj->type = AV_STRING;
	v->data->u.var.pobj->v.object =(curthread->stack.stack_pointer-2)->object;
	curthread->stack.stack_pointer-=2 ;curthread->stack.flg_sp-=2;
}
void AvCopyVar()
{
	DVM_ObjectRef* v = &(curthread->stack.stack_pointer-1)->object ;
	ExVarient* src = (curthread->stack.stack_pointer-2)->object.data->u.var.pobj;
	*v->data->u.var.pobj = *src;
	curthread->stack.stack_pointer-=2 ;curthread->stack.flg_sp-=2;
}


extern "C" DVM_ObjectRef chain_string(DVM_VirtualMachine *dvm, DVM_ObjectRef str1, DVM_ObjectRef str2);
DVM_ObjectRef AvDoAdd(ExVarient* a,ExVarient* b)
{
	DVM_ObjectRef ret=ExCreateVar(curdvm,0);
	ExVarient* r=ret.data->u.var.pobj ;
	if( a->type == AV_OBJECT || b->type == AV_OBJECT)
	{
		_BreakPoint //fix-me
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

	ExVarient* rv = (curthread->stack.stack_pointer-1)->object.data->u.var.pobj;
	ExVarient* lv = (curthread->stack.stack_pointer-2)->object.data->u.var.pobj;
	curthread->retvar.object=AvDoAdd(lv,rv);
	curthread->stack.stack_pointer-=2 ;curthread->stack.flg_sp-=2;
}

DVM_ObjectRef AvDoSub(ExVarient* a,ExVarient* b)
{
	DVM_ObjectRef ret=ExCreateVar(curdvm,0);
	ExVarient* r=ret.data->u.var.pobj ;
	if( a->type == AV_OBJECT || b->type == AV_OBJECT)
	{
		_BreakPoint //fix-me
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
	ExVarient* rv = (curthread->stack.stack_pointer-1)->object.data->u.var.pobj;
	ExVarient* lv = (curthread->stack.stack_pointer-2)->object.data->u.var.pobj;
	curthread->retvar.object=AvDoSub(lv,rv);
	curthread->stack.stack_pointer-=2 ;curthread->stack.flg_sp-=2;
}

DVM_ObjectRef AvDoMul(ExVarient* a,ExVarient* b)
{
	DVM_ObjectRef ret=ExCreateVar(curdvm,0);
	ExVarient* r=ret.data->u.var.pobj ;
	if( a->type == AV_OBJECT || b->type == AV_OBJECT)
	{
		_BreakPoint //fix-me
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
	ExVarient* rv = (curthread->stack.stack_pointer-1)->object.data->u.var.pobj;
	ExVarient* lv = (curthread->stack.stack_pointer-2)->object.data->u.var.pobj;
	curthread->retvar.object=AvDoMul(lv,rv);
	curthread->stack.stack_pointer-=2 ;curthread->stack.flg_sp-=2;
}

DVM_ObjectRef AvDoDiv(ExVarient* a,ExVarient* b)
{
	DVM_ObjectRef ret=ExCreateVar(curdvm,0);
	ExVarient* r=ret.data->u.var.pobj ;
	if( a->type == AV_OBJECT || b->type == AV_OBJECT)
	{
		_BreakPoint //fix-me
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
	ExVarient* rv = (curthread->stack.stack_pointer-1)->object.data->u.var.pobj;
	ExVarient* lv = (curthread->stack.stack_pointer-2)->object.data->u.var.pobj;
	curthread->retvar.object=AvDoDiv(lv,rv);
	curthread->stack.stack_pointer-=2 ;curthread->stack.flg_sp-=2;
}

DVM_ObjectRef AvDoMod(ExVarient* a,ExVarient* b)
{
	DVM_ObjectRef ret=ExCreateVar(curdvm,0);
	ExVarient* r=ret.data->u.var.pobj ;
	if( a->type == AV_OBJECT || b->type == AV_OBJECT)
	{
		_BreakPoint //fix-me
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
	ExVarient* rv = (curthread->stack.stack_pointer-1)->object.data->u.var.pobj;
	ExVarient* lv = (curthread->stack.stack_pointer-2)->object.data->u.var.pobj;
	curthread->retvar.object=AvDoMod(lv,rv);
	curthread->stack.stack_pointer-=2 ;curthread->stack.flg_sp-=2;
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
		_BreakPoint //fix-me
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
	ExVarient* rv = (curthread->stack.stack_pointer-1)->object.data->u.var.pobj;
	ExVarient* lv = (curthread->stack.stack_pointer-2)->object.data->u.var.pobj;
	curthread->retvar.int_value=AvDoCmp(lv,rv);
	curthread->stack.stack_pointer-=2 ;curthread->stack.flg_sp-=2;
}

void AvGetOrCreateVar(char* name)
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
		    curthread->retvar.object=(*mp)[name];
			return ;
		}
		else
		{
			ret= ExLoadStaticVar(curdvm,(ExVarient*)MEM_malloc(sizeof(ExVarient*)));
			(*mp)[name]=ret;
			curthread->retvar.object=ret;
			return ;
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
        curthread->retvar.object=ret;
		return;
	}
	curthread->retvar.object=dvm_null_object_ref;

}

bool AvDoGetVar(char* name)
{
	if(*name=='#')
	{
		name++;
		AvMap* mp=(AvMap*)AvGetTopContext().p;
		if(mp != NULL)
		{
			if((*mp).find(name)!=(*mp).end())
			{
			    curthread->retvar.object= (*mp)[name];
				return true;
			}
		}
		//if no context or var not found
		return false;
	}
	else if(*name=='$')
	{
		name++;
		if(MainMap.find(name)!=MainMap.end())
		{
		    curthread->retvar.object=MainMap[name];
			return true;
		}
		else
		{
			return false;
		}

	}
	curthread->retvar.object= dvm_null_object_ref;
	return false;
}

void AvGetVar(char* name)
{
		if(!AvDoGetVar(name))
		{
			ExSystemRaise(ExVarUseBeforeSet);
		}
}


extern "C" void gc_mark(DVM_ObjectRef *ref);
void AvMarkObjects(BdThread* th)
{
	hash_map<string,DVM_ObjectRef>::iterator it;
	for(it=MainMap.begin();it!=MainMap.end();it++)
	{
		gc_mark(&it->second);

	}
	for(int i=0;i<curthread->asp ;i++)
	{
		AvMap* pp=(AvMap*)th->avstack[i].p;
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
