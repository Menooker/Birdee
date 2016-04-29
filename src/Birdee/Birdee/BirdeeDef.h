#include "Conf.h"
#ifndef _H_BIRDEE_DEF
#define _H_BIRDEE_DEF
typedef void (*BdVMFunction)(void *args, ...);
typedef int int32;
typedef unsigned int uint32;
#ifdef BD_ON_X86
	#ifdef BD_ON_VC
		typedef int BINT ;
		typedef unsigned long BdIntPtr; // vc + x86
		typedef unsigned long _uint; // vc + x86
		typedef unsigned long long _uint64; // vc + x86
	#endif
	#ifdef BD_ON_GCC
		#define sprintf_s snprintf
		#define sprintf_s snprintf
		#define swscanf_s swscanf
		#ifdef BD_ON_LINUX
		#define vswprintf_s vswprintf
		#else
		#define vswprintf_s vsnwprintf
		#endif
		typedef int BINT ;
		typedef unsigned long _uint;
		typedef unsigned long long _uint64;
		typedef unsigned long BdIntPtr; // gcc + x86
	#endif
#else
	#ifdef BD_ON_VC
		typedef int BINT ;
		typedef unsigned long long BdIntPtr; // vc + x64
		typedef unsigned long _uint; // vc + x64
		typedef unsigned long long _uint64; // vc + x64
	#endif
#endif
#ifdef BD_ON_VC // for MSVC
	#define forceinline __forceinline
	#define thread_local __declspec (thread)
#elif defined BD_ON_GCC // for gcc on Linux/Apple OS X
	#define forceinline __inline__ __attribute__((always_inline))
	#define thread_local __thread
#else
	#define forceinline
#endif

#define _CRT_SECURE_NO_WARNINGS
#define BD_STACK_DEEPTH 2048


#ifdef BD_ON_WINDOWS
		#define THREAD_PROC(name,param) DWORD __stdcall name(void* param)
#else
		#define THREAD_PROC(name,param) void* name(void* param)
#endif

typedef long BdStatus ;
#define BdSuccess 0
#define BdInsufficientSpace 1
#define BdBadMagicNum 2
#define BdDuplicatePackageName 3
#define BdBadLength 4
#define BdEndOfBuffer 5
#define BdShouldDispose 6
#define BdStringNotNumber 7
#define BdDamagedModule 8
#define BdFileNotFound 9
typedef struct
{
	char* p;
	BINT bufsize;
	BINT len;
}CPBuffer;
typedef struct
{
	char* p;
	BINT len;
}BdString;

enum NativeFunctionList
{
BdNFunVarInt=0,
BdNFunVarDouble,
BdNFunVarString,
BdNFunIntVar,
BdNFunDoubleVar,
BdNFunStringVar,
BdNFunNewIntVar,
BdNFunNewDoubleVar,
BdNFunNewStringVar,
BdNFunCopyVar,
BdNFunAddVar,
BdNFunSubVar,
BdNFunMulVar,
BdNFunDivVar,
BdNFunModVar,
BdNFunCmpVar,
BdNFunInvoke,
BdNFunGetFunction,
};

typedef void(__stdcall *ptDbgBreakPoint)(void);
#ifdef BD_ON_VC
	
	#ifdef BD_ON_X86
		#define _BreakPoint __asm int 3
	#else
		//#include <Windows.h>
		#ifdef __cplusplus
			extern "C"
		#endif 
		ptDbgBreakPoint DbgBreakPoint;
		#define _BreakPoint DbgBreakPoint();
	#endif
#else
#define _BreakPoint __asm__("int $3");
#endif

#endif
