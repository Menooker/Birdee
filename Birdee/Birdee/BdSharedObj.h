#ifndef _H_BIRDEE_SHARED_OBJ
#define _H_BIRDEE_SHARED_OBJ
#include "BdExec.h"
#include "UnportableAPI.h"
#ifdef __cplusplus
extern "C"
{
#endif

#define DSM_CACHE_BITS 4
#define DSM_CACHE_BLOCK_SIZE (1<<DSM_CACHE_BITS)
#define DSM_CACHE_HIGH_MASK (0xffffffff >> DSM_CACHE_BITS << DSM_CACHE_BITS)
#define DSM_CACHE_LOW_MASK (~DSM_CACHE_HIGH_MASK)
#define DSM_CACHE_HIGH_MASK_64 ((long long)0xffffffffffffffff >> DSM_CACHE_BITS << DSM_CACHE_BITS)
#define DSM_CACHE_LOW_MASK_64 (~DSM_CACHE_HIGH_MASK_64)
#define DSM_CACHE_BAD_KEY  ((long long) DSM_CACHE_LOW_MASK)
#define DSM_CACHE_SIZE 1024

#define RC_THREAD_CREATING 0
#define RC_THREAD_RUNNING 1
#define RC_THREAD_PAUSED 2
#define RC_THREAD_DEAD 3

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
	SoArray,
	SoCounter,
};

union SoVar
{
	BINT vi;
	double vd;
	_uint key;
};



struct DataNode
{
	SoType tag;
	int flag;
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
			//_uint clsid;
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

struct CacheBlock
{
	SoVar cache[1<<DSM_CACHE_BITS];
	unsigned long lru;
	long long key;
	BD_RWLOCK lock;
};

BINT SoGeti(_uint key,_uint fldid);
double SoGetd(_uint key,_uint fldid);
void SoGeto(_uint key,_uint fldid,int idx_in_exe);
void SoGets(_uint key,_uint fldid);
void SoSeti(_uint key,_uint fldid,BINT v);
void SoSetd(_uint key,_uint fldid,double v);
void SoSeto(_uint key,_uint fldid,_uint v);
void SoSets(_uint key,_uint fldid,DVM_ObjectRef v);
void SoNewModule(_uint key,int cnt);
DVM_ObjectRef SoDoNew(int class_index,int methodid);
void SoNew(int idx_in_exe,int methodid);
void SoInc(DVM_Value* args);
void SoDec(DVM_Value* args);
void SoSetCounter(DVM_Value* args);
void SoGetCounter(DVM_Value* args);
void SoNewArray(BINT ty,BINT dim);
void SoGlobalArrBoundaryCheck(BINT arr,BINT idx);
void SoKillStorage();

void SoArraySize(DVM_Value *args);
void SoArrayTostr(DVM_Value *args);
void SoArrayUnimplementedStub(DVM_Value *args);
void SoArrayEquals(DVM_Value *args);

#ifdef BD_DSM_STAT
void SoPrintStat();
#endif
void SoInitGCState();
void SoLocalGC(int round_id);
#define MAKE64(a,b) (unsigned long long)( ((unsigned long long)a)<<32 | (unsigned long long)b)


#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
#include <string>
#include <vector>
void SoInitStorage(std::vector<std::string>& arr_mem_hosts,std::vector<int>& arr_mem_ports,
	std::vector<std::string>& arr_hosts,std::vector<int>& arr_ports,int node_id);

#define SO_KEY_NOT_FOUND 1
class SoStorage
{
public:
	SoStorage(){};
	SoStorage(std::vector<std::string>& ,std::vector<int>&){};
	virtual inline ~SoStorage(){};
	virtual SoStatus putstr(_uint key,wchar_t* str,_uint len)=0;
	virtual SoStatus put(_uint key,int fldid,SoVar v)=0;
	virtual SoVar get(_uint key,int fldid)=0;
	virtual int inc(_uint key,int fldid,int inc)=0;
	virtual int dec(_uint key,int fldid,int dec)=0;
	virtual int getcounter(_uint key,int fldid)=0;
	virtual void setcounter(_uint key,int fldid,int n)=0;
	virtual SoStatus getstr(_uint key,wchar_t** str,_uint* len)=0;
	virtual bool exists(_uint key)=0;
	virtual SoStatus newobj(_uint key,SoType tag,int fld_cnt,int flag)=0;
	virtual SoStatus getinfo(_uint key,SoType& tag,int& fld_cnt,int& flag)=0;
	virtual int getsize(_uint key)=0;
	virtual SoStatus getblock(long long addr,SoVar* buf)=0;
	virtual SoStatus del(_uint key,unsigned int len)=0;
};
#endif

#endif
