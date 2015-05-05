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
#ifdef __cplusplus
}
#endif

#endif