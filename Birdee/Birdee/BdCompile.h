#ifndef _H_BIRDEE_COMPILE
#define _H_BIRDEE_COMPILE

#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/Analysis/Passes.h"
#include "llvm/Analysis/Verifier.h"
#include "llvm/ExecutionEngine/ExecutionEngine.h"
#include "llvm/ExecutionEngine/JIT.h"
#include "llvm/IR/DataLayout.h"
#include "llvm/IR/Module.h"
#include "llvm/PassManager.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Transforms/Scalar.h"
#include "llvm/Bitcode/ReaderWriter.h"
#include "llvm/Support/MemoryBuffer.h"


#ifdef __cplusplus
extern "C"
{
#endif

#include "..\..\include\MEM.h"
#include "..\..\compiler\diksamc.h"


#ifdef __cplusplus
}
#endif
extern "C" void* BcNewModule(char* name);
llvm::Function * BcGenerateFunction(DVM_Executable *exe,  FunctionDefinition * src,char* clsname);
llvm::Value* BcGenerateExpression(DVM_Executable *exe,Block *current_block,Expression *expr);
llvm::Function* BcGenerateFunctionEx(DVM_Executable *exe, char* name,Block* block,StatementList* statement_list,int needret,char* clsname,int local_var_cnt);
extern "C" void BcDumpModule();
extern "C" void BcGenerateFieldInitializer(DVM_Executable *exe,ClassDefinition *cd, DVM_Class *dvm_class);

llvm::Function* BcBuildFldPtrImp(llvm::Type *);
llvm::Function* BcBuildArrPtrImp(llvm::Type *);
llvm::Function* BcBuildArrPtrSafeImp(llvm::Type *);
llvm::Function* BcBuildPushImp(char* name,int isptr,llvm::Type* ty);
llvm::Function* BcBuildPopImp();
void BcSwitchContext(llvm::Module* M);
#endif