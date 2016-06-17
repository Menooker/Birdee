// libNativeTest.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "DVM.h"
#include <Windows.h>
#include "dvm_pri.h"
typedef void (*pExRegisterNativeFunction)(char* name,void* func,int argc,int is_method);


void WinMessageBox(DVM_Value* v)
{
	MessageBoxW(NULL,v[1].object.data->u.string.string,v[0].object.data->u.string.string,64);
}

__declspec(dllexport) int BirdeeLibInit(pExRegisterNativeFunction ExRegisterNativeFunction )
{
	ExRegisterNativeFunction("MsgBox",WinMessageBox,2,0);
	return 0;
}
