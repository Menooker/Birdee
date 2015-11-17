#include <stdio.h>
#include <locale.h>
#include "..\Birdee\Birdee\stdafx.h"
#include "..\include\DKC.h"
#include "..\include\DVM.h"
#include "..\include\MEM.h"


#include "..\Birdee\Birdee\Dumper.h"
#include "..\Birdee\Birdee\Loader.h"
void ExInitEngine();
void BcInitLLVMCompiler();
int
main(int argc, char* argv[])
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
    }*/
	BcInitLLVMCompiler();
	argv[1]="..\\..\\compiler\\test\\test.dkm";
    //argv[1]="D:\\Menooker\\Birdee\\Build0\\diksam_book_0_1\\compiler\\test\\test.dkm";
	fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "%s not found.\n", argv[1]);
        exit(1);
    }

    setlocale(LC_CTYPE, "");

	dvm = DVM_create_virtual_machine();
    compiler = DKC_create_compiler();
    list = DKC_compile(compiler, fp, argv[1]);
    //DVM_set_executable(dvm, list);
	//DVM_execute(dvm);

	DKC_dispose_compiler(compiler);
	CpSaveCodeToFile("123.bde",list);
	DVM_dispose_executable_list(list);
	//fix-me : free pVoidType by dispose_type_specifier
	printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");

	ExInitEngine();
	status=LdLoadCode("123.bde",plist);
	if(status)
		printf("ERROR Loading Code %d\n",status);
	else
	{
		DVM_set_executable(dvm, plist); //modified
		DVM_execute(dvm);
		MEM_check_all_blocks();
		MEM_dump_blocks(stdout);
	}
	DVM_dispose_virtual_machine(dvm);
	DVM_dispose_executable_list(plist); //*/
    return 0;
}
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
    }*/

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
}
