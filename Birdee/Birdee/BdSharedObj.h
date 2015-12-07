#ifndef _H_BIRDEE_SHARED_OBJ
#define _H_BIRDEE_SHARED_OBJ

#ifdef __cplusplus
extern "C"
{
#endif
#include "BdExec.h"

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
	SoModule,
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

BINT SoGeti(uint key,uint fldid);
double SoGetd(uint key,uint fldid);
DVM_ObjectRef SoGeto(uint key,uint fldid,int idx_in_exe);
DVM_ObjectRef SoGets(uint key,uint fldid);
void SoSeti(uint key,uint fldid,BINT v);
void SoSetd(uint key,uint fldid,double v);
void SoSeto(uint key,uint fldid,uint v);
void SoSets(uint key,uint fldid,DVM_ObjectRef v);
void SoNewModule(uint key,int cnt);
DVM_ObjectRef SoNew(int idx_in_exe,int methodid);

#define MAKE64(a,b) (unsigned long long)( ((unsigned long long)a)<<32 | (unsigned long long)b)


#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
#define SO_KEY_NOT_FOUND 1
class SoStorage
{
public:
	SoStorage(){};
	SoStorage(char*){};
	virtual inline ~SoStorage(){};
	virtual SoStatus putstr(uint key,wchar_t* str,uint len)=0;
	virtual SoStatus put(uint key,int fldid,SoVar v)=0;
	virtual SoVar get(uint key,int fldid)=0;
	virtual SoStatus getstr(uint key,wchar_t** str,uint* len)=0;
	virtual bool exists(uint key)=0;
	virtual SoStatus newobj(uint key,SoType tag,int fld_cnt)=0;
};
#endif

#endif