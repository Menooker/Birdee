#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "..\Birdee\Birdee\stdafx.h"
#include "..\include\DKC.h"
#include "..\include\DVM.h"
#include "..\include\MEM.h"



#include "..\Birdee\Birdee\Dumper.h"
#include "..\Birdee\Birdee\Loader.h"
#include "..\Birdee\Birdee\BdParameters.h"


struct BdParameters parameters;
void ExInitEngine();
void BcInitLLVMCompiler();
int ExExec(char* path);
void RcSlave(int port);

int compile(char* path)
{
	DKC_Compiler *compiler;
    FILE *fp;
    DVM_ExecutableList *list;
	//argv[1]="..\\..\\compiler\\test\\test.dkm";
	fp = fopen(path, "r");
	if (fp == NULL) {
		fprintf(stderr, "%s not found.\n", path);
		return 1;
	}
	BcInitLLVMCompiler();
    compiler = DKC_create_compiler();
    list = DKC_compile(compiler, fp, path);

	DKC_dispose_compiler(compiler);
	CpSaveCodeToFile("123.bde",list);
	DVM_dispose_executable_list(list);
	return 0;
}

int
main(int argc, char* argv[])
{

    /*if (argc < 2) {
        fprintf(stderr, "usage:%s filename arg1, arg2, ...", argv[0]);
        exit(1);
    }*/
	unsigned int len;
	setlocale(LC_CTYPE, "");
	if(argc<2)
		goto BAD_PARAM;
	if(argv[1][0]=='-')
	{
		switch (argv[1][1])
		{
		case 'c':
			if(argc<3)
				goto BAD_PARAM;
			if(compile(argv[2]))
			{
				printf("Error when opening input file\n");
				return 1;
			}
			break;
		case 'e':
			if(argc<3)
				goto BAD_PARAM;
			if(compile(argv[2]))
			{
				printf("Error when opening input file\n");
				return 1;
			}
			printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
			ExExec("123.bde");
			break;
		case 's':
			if(argc<4)
				goto BAD_PARAM;

			len=strlen(argv[3]);
			if(len>sizeof(parameters.RemoteModulePath)-2)
			{
				printf("Path too long\n");
				return 1;
			}
			strncpy(parameters.RemoteModulePath,argv[3],sizeof(parameters.RemoteModulePath)-2);
			if(parameters.RemoteModulePath[len-1]!='/' && parameters.RemoteModulePath[len-1]!='\\')
			{
				parameters.RemoteModulePath[len]='/';
				parameters.RemoteModulePath[len+1]=0;
			}

			RcSlave(atoi(argv[2]));
			break;
		default:
			goto BAD_PARAM;
		}
	}
	else
		goto BAD_PARAM;
	//fix-me : free pVoidType by dispose_type_specifier
    return 0;
BAD_PARAM:
	printf("Bad parameters\n");
	return 1;
}
	/*
int
main2(int argc, char **argv)
{
    DKC_Compiler *compiler;
    FILE *fp;
    DVM_ExecutableList *list;
    DVM_VirtualMachine *dvm;
	BdStatus status;
	DVM_ExecutableList* plist=(DVM_ExecutableList*)MEM_malloc(sizeof(DVM_ExecutableList));
	plist->list=0;plist->top_level=0;
    /*if (argc < 2) {
        fprintf(stderr, "usage:%s filename arg1, arg2, ...", argv[0]);
        exit(1);
    }

	argv[1]="..\\..\\compiler\\test\\test.dkm";
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "%s not found.\n", argv[1]);
        exit(1);
    }

    setlocale(LC_CTYPE, "");


    compiler = DKC_create_compiler();
    list = DKC_compile(compiler, fp, argv[1]);
    //
    DKC_dispose_compiler(compiler);


	dvm = DVM_create_virtual_machine();
	DVM_set_executable(dvm, list);
		DVM_execute(dvm);
		MEM_check_all_blocks();
		MEM_dump_blocks(stdout);
		DVM_dispose_executable_list(list);
	DVM_dispose_virtual_machine(dvm);

    return 0;
}*/
