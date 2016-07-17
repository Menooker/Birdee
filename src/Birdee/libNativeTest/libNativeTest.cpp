// libNativeTest.cpp : 定义 DLL 应用程序的导出函数。
//

#ifdef _WIN32
#include <Windows.h>
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT __attribute__ ((visibility("default")))
#endif
#include "dvm_pri.h"
#include "DVM.h"
#include <stdio.h>
extern "C"
{
typedef void (*pExRegisterNativeFunction)(const char* name,void* func,int argc,int is_method);


void WinMessageBox(DVM_Value* v)
{
#ifdef _WIN32
	MessageBoxW(NULL,v[1].object.data->u.string.string,v[0].object.data->u.string.string,64);
#else
	printf("============\nTitle:%ls\n%ls\n=============\n",v[1].object.data->u.string.string,v[0].object.data->u.string.string);
#endif
}

DLL_EXPORT int BirdeeLibInit(pExRegisterNativeFunction ExRegisterNativeFunction )
{
	ExRegisterNativeFunction("MsgBox",(void*)WinMessageBox,2,0);
	printf("DLL Loaded\n");
	return 0;
}
}

