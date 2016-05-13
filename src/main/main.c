#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "stdafx.h"
#include "DKC.h"
#include "DVM.h"
#include "MEM.h"



#include "Dumper.h"
#include "Loader.h"
#include "BdParameters.h"


struct BdParameters parameters={0};
void ExInitEngine();
void BcInitLLVMCompiler();
void SoKillStorage();
int ExExec(char* path);
void RcSlave(int port);


extern void BcOpenOutputFile(char* path);
extern void BcCloseOutputFile();

int compile(char* path,char* outpath)
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

	if(parameters.asm2file)
		BcOpenOutputFile(parameters.AsmPath);
    list = DKC_compile(compiler, fp, path);

	DKC_dispose_compiler(compiler);
	CpSaveCodeToFile(outpath,list);
	DVM_dispose_executable_list(list);
	BcCloseOutputFile();
	return 0;
}


int ParseCompilationParameters(int cur_arg,int argc,char* argv[])
{
	for(;cur_arg<argc;cur_arg++)
	{
		if(!strcmp(argv[cur_arg],"-disasm"))
		{
			parameters.need_disasm=1;
		}
		else if(!strcmp(argv[cur_arg],"-asm2file"))
		{
			if(argc-cur_arg<=1)
				return 1;
			parameters.asm2file=1;
			if(strlen(argv[cur_arg+1])>=255)
			{
				printf("Path too long\n");
				return 1;
			}
			strncpy(parameters.AsmPath,argv[cur_arg+1],255);
			cur_arg++;
		}
	}
	return 0;
}

int ParseExecutionParameters(int cur_arg,int argc,char* argv[])
{
	for(;cur_arg<argc;cur_arg++)
	{
		if(!strcmp(argv[cur_arg],"-debug"))
		{
			parameters.debug=1;
		}
		else if(!strcmp(argv[cur_arg],"-nocache"))
		{
			parameters.nocache=1;
		}
		else if(!strcmp(argv[cur_arg],"-opt"))
		{
			if(cur_arg+1<argc)
			{
				parameters.optmization=atoi(argv[cur_arg+1]);
				if(parameters.optmization<0 || parameters.optmization>3)
				{
					printf("opt level should be between 0 and 3\n");
					return 1;
				}
				cur_arg++;
			}
			else
			{
				printf("No operand found after \'-opt\'\n");
				return 1;
			}
		}
		else if(!strcmp(argv[cur_arg],"-mem"))
		{
			if(cur_arg+1<argc)
			{
				if(!strcmp(argv[cur_arg+1],"cmemcached"))
				{
					parameters.mem_backend=0;
				}
				else if(!strcmp(argv[cur_arg+1],"memcached"))
				{
					parameters.mem_backend=1;
				}
				else
				{
					printf("unknown memory backend %s\n",argv[cur_arg+1]);
				}
			}
			else
			{
				printf("No operand found after \'-mem\'\n");
				return 1;
			}
		}
	}
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

	parameters.isLib=0;
	parameters.isSyslib=0;
	parameters.optmization=2;

	setlocale(LC_CTYPE, "");
	if(argc<2)
		goto BAD_PARAM;
	if(argv[1][0]=='-')
	{
		switch (argv[1][1])
		{
		case 'l':
			parameters.isLib=1;
			if(argv[1][2]=='s')
				parameters.isSyslib=1;
			if(argc<4)
				goto BAD_PARAM;
			if(ParseCompilationParameters(4,argc,argv))
				goto BAD_PARAM;
			if(compile(argv[2],argv[3]))
			{
				printf("Error when opening input file\n");
				return 1;
			}
			break;
		case 'c':
			if(argc<4)
				goto BAD_PARAM;
			if(ParseCompilationParameters(4,argc,argv))
				goto BAD_PARAM;
			if(compile(argv[2],argv[3]))
			{
				printf("Error when opening input file\n");
				return 1;
			}
			break;
		case 'e':
			if(argc<4)
				goto BAD_PARAM;
			if(ParseCompilationParameters(4,argc,argv))
				goto BAD_PARAM;
			if(ParseExecutionParameters(4,argc,argv))
				goto BAD_PARAM;
			if(compile(argv[2],argv[3]))
			{
				printf("Error when opening input file\n");
				return 1;
			}
			printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
			ExExec(argv[3]);
			SoKillStorage();
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
			if(ParseExecutionParameters(4,argc,argv))
				goto BAD_PARAM;
			RcSlave(atoi(argv[2]));
			SoKillStorage();
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
