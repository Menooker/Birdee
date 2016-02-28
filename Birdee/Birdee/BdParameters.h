#ifndef _H_BIRDEE_PARAMETERS
#define _H_BIRDEE_PARAMETERS

struct BdParameters
{
	char RemoteModulePath[255];
	int isLib;
	int isSyslib;
	int need_disasm;
	int debug;
	int asm2file;
	char AsmPath[255];
	//int memport;
	//char memip[255];
};
#ifdef __cplusplus
extern "C"
{
#endif

extern struct BdParameters parameters;

#ifdef __cplusplus
}
#endif
#endif