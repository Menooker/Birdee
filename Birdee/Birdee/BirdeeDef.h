#include "Conf.h"
#ifndef _H_BIRDEE_DEF
#define _H_BIRDEE_DEF

#ifdef BD_ON_X86
	#ifdef BD_ON_VC
		typedef unsigned long BdIntPtr; // vc + x86
	#endif
#endif
#ifdef BD_ON_VC // for MSVC
	#define forceinline __forceinline
#elif defined BD_ON_GCC // for gcc on Linux/Apple OS X
	#define forceinline __inline__ __attribute__((always_inline))
#else
	#define forceinline
#endif

#define _CRT_SECURE_NO_WARNINGS
#define BD_STACK_DEEPTH 2048


typedef int BINT ; //fix-me : consider gcc?

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

#endif
