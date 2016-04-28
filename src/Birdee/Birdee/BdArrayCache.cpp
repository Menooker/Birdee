#include "BdArrayCache.h"
extern "C"{
#include "DBG.h"
//#include "DVM.h"
#include "dvm_pri.h"

	int hit=0;
int miss=0;
}
#include "BdExec.h"
#define AcHashSize 0x2000
#define AcMaskHigh (AcHashSize-1) //13 bits ->8k
#define AcMaskLow 0x3FF //11 bits -> 64

//#define AcMakeKey(d,i) ( ( ((BdIntPtr)d << 10) |  ((BdIntPtr)i & AcMaskLow)) & AcMaskHigh )
#define AcMakeKey(d,i) (  ((BdIntPtr)d ^  (BdIntPtr)i ) & AcMaskHigh )
typedef struct
{
	void* v;
	void* data;
	BINT index;
}AcCache;

AcCache Cache[AcHashSize]={0};



//Check if the array is good to access. May raise an exception
void ExCheckArray(DVM_VirtualMachine *dvm, DVM_ObjectRef barray, int index)
{
/*	BINT eindex;
    if (barray.data == NULL) {

        dvm->current_exception = ExCreateExceptionEx(dvm, DVM_NULL_POINTER_EXCEPTION_NAME,&eindex,
                                   NULL_POINTER_ERR,
                                   DVM_MESSAGE_ARGUMENT_END);
		ExRaiseException(eindex+1);
        return ;
    }
    if (index < 0 || index >= barray.data->u.barray.size) {
        dvm->current_exception  = ExCreateExceptionEx(dvm, ARRAY_INDEX_EXCEPTION_NAME,&eindex,
                                   INDEX_OUT_OF_BOUNDS_ERR,
                                   DVM_INT_MESSAGE_ARGUMENT, "index", index,
                                   DVM_INT_MESSAGE_ARGUMENT, "size",
                                   barray.data->u.barray.size,
                                   DVM_MESSAGE_ARGUMENT_END);
		ExRaiseException(eindex+1);
        return ;
    }
*/
	_BreakPoint
}

forceinline BINT*  AcGetPtri(DVM_VirtualMachine *dvm,DVM_ObjectRef barray,BINT index)
{
	//int s=AcMakeKey(barray.data ,index);

	AcCache* c = Cache + AcMakeKey(barray.data ,index);

	if(c->data==barray.data && c->index==index )
	{
		hit++;
		return (BINT*)c->v;
	}
	miss++;
    ExCheckArray(dvm, barray, index);
	BINT* ret;
	ret=&barray.data->u.barray.u.int_array[index];
	c->data=barray.data;
	c->index=index;
	c->v=ret;
    return ret;
}


