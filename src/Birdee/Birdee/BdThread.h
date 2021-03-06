#ifndef _H_BIRDEE_THREAD
#define _H_BIRDEE_THREAD

#include "Conf.h"
#include "BdExec.h"
#include "UnportableAPI.h"

#ifdef __cplusplus
extern "C"
{
#endif
	void ThStopAllThreads();
	void ThCreateThread(DVM_Value* args);
	void ThPauseTheWorld();
	void ThResumeTheWorld();
	int ThDoCreateThread(int func,DVM_ObjectRef arg,unsigned int thread_object_id);
	void ThSuspendThread(DVM_Value* args);
	void ThResumeThread(DVM_Value* args);
	void ThJoinThread(DVM_Value* args);
#ifdef __cplusplus
}
#endif

#endif
