#include "BirdeeDef.h"
#include "BdCompile.h"


extern "C"{
#include "..\..\include\DBG.h"
}

#define ConstInt(bit,i) ConstantInt::get(Type::getInt32Ty(context),APInt(bit,i))
#define ConstPointer(ty) llvm::ConstantPointerNull::get(ty)

#include "llvm/Analysis/Passes.h"
#include "llvm/Analysis/Verifier.h"
#include "llvm/ExecutionEngine/ExecutionEngine.h"
#include "llvm/ExecutionEngine/JIT.h"
#include "llvm/IR/DataLayout.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/DIBuilder.h"
#include "llvm/IR/Module.h"
#include "llvm/PassManager.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Transforms/Scalar.h"
#include "llvm/Bitcode/ReaderWriter.h"
#include "llvm/Support/MemoryBuffer.h"
#include "llvm/DebugInfo.h"

//#pragma comment(lib,"D:\\Menooker\\libLLVMlite\\libLLVMlite\\Debug\\libLLVMLite.lib")
#include <string>
#include <stack>
#include "hash_compatible.h"



using namespace llvm;

typedef std::hash_map<std::string,Value*> StrValueMap;
StrValueMap* strmap;
static Module *module;
static IRBuilder<> builder(getGlobalContext());
static LLVMContext& context=getGlobalContext();
static FunctionType *FT;
StructType *TyObjectRef;
Type* TypStack;
Type* TypInt;
Function* fLoadStringFromPool;
Function* fChainString;
Function* fCmpString;
Function* fCmpObject;// == ret:0; != ret:1
Value* zero=ConstantInt::get(Type::getInt32Ty(context),APInt(32,0));
Function *curfun;int curfun_param_cnt=0;
llvm::Instruction* IP;
llvm::DebugLoc * dbgloc;
BasicBlock * mainblock;
Function *fBoolToStr;
Function *fIntToStr;
Function *fDoubleToStr;
Function *fPushi=0;
Function *fPushd=0;
Function *fPusho=0;
Function *fInvoke;
Function *fCall;
Function *fDoInvoke;

Function *fArrayLiteral; // (type,cnt)
Function *fNewArray; // (type,cnt)
Function *fNewGlobalArray;
Function *fArrGeti; //obj,idx,(v)
Function *fArrGetd;
Function *fArrGeto;
Function *fArrGetCh;
Function *fArrPuti;
Function *fArrPutd;
Function *fArrPuto;

/*Function *fFldGeti; //obj,idx,(v)
Function *fFldGetd;
Function *fFldGeto;
Function *fFldPuti;
Function *fFldPutd;
Function *fFldPuto;*/
Function *fNew;
Function *fGetSuper;
Function *fGetVar;
Function *fGetOrCreateVar;
Function *fDownCast;
Function *fUpCast;
Function *fInstanceof;
Function *fInstanceof2;

Function *fArrBdChk;
Function *fPop;
Function *fArrAddr;
Function *fFldAddr;
Function *fArrAddrSafe;
Function *fFailure;
Function *fSetjmp;
Function *fPushException;
Function *fRaise;
Function *fLeaveTry;
Function *fNewDelegate;
Function *fInvokeDelegate;
Function *fSystemRaise;
Function *fReraise;

Function *fSharedSeti;
Function *fSharedSetd;
Function *fSharedSeto;
Function *fSharedSets;

Function *fSharedGeti;
Function *fSharedGetd;
Function *fSharedGeto;
Function *fSharedGets;
Function *fNewShared;
Function* fObjectRefPtr;

Function *fAtmInc;
Function *fAtmDec;
Function *fSharedInc;
Function *fSharedDec;


GlobalVariable* bpc;//parameter count //fix-me : release it!
GlobalVariable* bei;//exception index //fix-me : release it!
GlobalVariable* beo;//exception obj //fix-me : release it!
GlobalVariable* bsp;//stack top index //fix-me : release it!
GlobalVariable* arr_sp;//arr of object booleans //fix-me : release it!
//GlobalVariable* arr_is_pointer;//stack_value pointer indecator array //fix-me : release it!
GlobalVariable* bretvar;//return value//fix-me : release it!
GlobalVariable* pstatic;//static values//fix-me : release it!
GlobalVariable* m_id;//module id

BasicBlock* contiblock;
BasicBlock* loopblock;
BasicBlock* finallyblock;
int isInTry=0;


DIBuilder* dibuilder;
DIFile currentfile;
DICompileUnit* currentcompileunit;
DISubprogram currentdifunc;

#ifdef BD_MULTITHREAD
	#define THREAD_MODEL GlobalVariable::LocalDynamicTLSModel
	#define LINKAGE_TYPE GlobalVariable::WeakAnyLinkage
#else
	#define THREAD_MODEL GlobalVariable::NotThreadLocal
	#define LINKAGE_TYPE GlobalVariable::ExternalLinkage
#endif


class BcParameter{
public:
	Value* v;
	int violated;
	BcParameter()
	{
		v=0;
		violated=0;
	}
};

enum BcInlineFunctions
{
	FunArrAddr,
	FunPushi,
	FunPushd,
	FunPusho,
	FunPop,
	FunArrAddrSafe,
	FunFldAddr,
	FunMax
};



std::vector<BcParameter> bparameters;
Value* psta=0;
std::vector<BcParameter> bstatic;
std::hash_map<int ,Value*> barrays;

extern "C" int add_constant_pool(DVM_Executable *exe, DVM_ConstantPool *cp);
extern "C" int get_opcode_type_offset2(TypeSpecifier *type);
extern "C" int get_opcode_type_offset_shared(TypeSpecifier *type);
extern "C" int get_opcode_type_offset(TypeSpecifier *type);
Type* TypeSwitch[3];
Function* SharedPutSwitch[4];
Function* SharedGetSwitch[4];
//Function* ArrGet[3];Function* ArrPut[3];//Function* FldGet[3];Function* FldPut[3];
//Function* FunStoreStaicSwitch[3];

extern "C" int get_method_index(MemberExpression *member);
extern "C" int get_method_index_Ex(MemberExpression *member,int* outParamCnt);
Function* BcBuildPush(char* name,int isptr,Type* ty);
Function* GetArrAddr();
Function* GetFldAddr();
Value* cached_mid;

 int
get_opcode_type_offset3(int type)
{
    switch (type) {
    case DVM_VOID_TYPE:
        DBG_assert(0, ("basic_type is void"));
        break;
    case DVM_BOOLEAN_TYPE: /* FALLTHRU */
    case DVM_INT_TYPE: /* FALLTHRU */
    case DVM_ENUM_TYPE:
        return 0;
        break;
    case DVM_DOUBLE_TYPE:
        return 1;
        break;
    case DVM_STRING_TYPE: /* FALLTHRU */
    case DVM_NATIVE_POINTER_TYPE: /* FALLTHRU */
    case DVM_CLASS_TYPE: /* FALLTHRU */
	case DVM_VARIENT_TYPE:
    case DVM_DELEGATE_TYPE: /* FALLTHRU */
        return 2;
        break;
    case DVM_NULL_TYPE: /* FALLTHRU */
    case DVM_BASE_TYPE: /* FALLTHRU */
    case DVM_UNSPECIFIED_IDENTIFIER_TYPE: /* FALLTHRU */
    default:
        DBG_assert(0, ("basic_type..%d", type));
    }

    return 0;
}

extern "C" int isClassOfObject(ClassDefinition* cd);
static void do_check_abstract(ClassDefinition *super,ClassDefinition *chk,std::hash_map<std::string,int>& map)
{
	MemberDeclaration *member = NULL;
	MemberDeclaration *member_m = NULL;
	ExtendsList *extends_p;
	bool isObject=isClassOfObject(super);

	bool isInterface= (super->class_or_interface==DVM_INTERFACE_DEFINITION);
	for (member = super->member; member;member = member->next) {
		if (member->kind == METHOD_MEMBER &&
			(isInterface || (member->u.method.is_abstract && member->u.method.function_definition->block==NULL) )) {// if is interface or an unimplemented abstract
			if(map.find(member->u.method.function_definition->name)==map.end())
			{
				if(!isObject)
				{
					dkc_compile_error(chk->line_number,
						ABSTRACT_NOT_IMPLEMENTED_ERR,
						STRING_MESSAGE_ARGUMENT, "name",
						chk->name,
						STRING_MESSAGE_ARGUMENT, "member_name",
						member->u.method.function_definition->name,
						STRING_MESSAGE_ARGUMENT, "name2",
						super->name,
						MESSAGE_ARGUMENT_END);
				}
/*				else if(super==chk) //we only modify the first level
				{
					for (member_m = chk->member; member_m;member_m = member_m->next)//find the missing member
					{
						if( !strcmp(member_m->u.method.function_definition->name ,
							member->u.method.function_definition->name)

					}
				}*/

			}
		}
		if(member->kind == METHOD_MEMBER && member->u.method.is_override && member->u.method.function_definition->block) //if is implemented
		{
			map[member->u.method.function_definition->name]=1;
		}
	}

	if (super->super_class) {
        do_check_abstract(super->super_class,chk,map);
    }
    for (extends_p = super->interface_list; extends_p;
         extends_p = extends_p->next) {
		do_check_abstract(extends_p->class_definition,chk,map);
    }

}

extern "C" void check_all_abstract_is_implemented(ClassDefinition* to_chk)
{
	if(to_chk->is_abstract || to_chk->class_or_interface==DVM_INTERFACE_DEFINITION)
		return;
	std::hash_map<std::string,int> map;
	do_check_abstract(to_chk,to_chk,map);
}


bool isArrayAddressSet(int index,int isLocal)
{
	int cacheindex=index;
	if(index>=2000)
		DBG_panic(("too many parameters"));
	if(!isLocal)
		cacheindex+=2000;
	return barrays.find(cacheindex)!=barrays.end();
}

Value* GetArrayAddress(int index,int isLocal,int isParam=0)
{
	int cacheindex=index;
	if(index>=2000)
		DBG_panic(("too many parameters"));
	if(!isLocal)
		cacheindex+=2000;
	Value* v;
	if(barrays.find(cacheindex)==barrays.end())
	{
		IRBuilderBase::InsertPoint ip=builder.saveIP();
		builder.SetInsertPoint(mainblock->begin());
		//builder.SetInsertPoint(IP);
		//builder.SetCurrentDebugLocation (*dbgloc);
		v=builder.CreateAlloca(TyObjectRef->getPointerTo());
		builder.restoreIP(ip);
		if(isLocal)
		{


			if(isParam)
			{

				Value* addr=curfun->arg_begin();
				addr=builder.CreateGEP(addr,ConstInt(32,index));
				addr=builder.CreateLoad(addr);

				builder.CreateStore(builder.CreateCall(GetFldAddr(),addr),v);
			}
		}
		else
		{

			Value* vstatic=builder.CreateLoad(pstatic);
			Value* ptr=builder.CreateGEP(vstatic,ConstInt(32,index));
			vstatic=builder.CreateLoad(ptr);
			vstatic=builder.CreateCall(GetFldAddr(),vstatic);
			builder.CreateStore(vstatic,v);
		}
		barrays[cacheindex]=v;
		//builder.restoreIP(ip);
		return v;
	}
	else
		return barrays[cacheindex];
}

Value* GetStrValue(char* str)
{
	if(strmap->find(str)==strmap->end())
	{
		(*strmap)[str]=builder.CreateGlobalStringPtr(str);
	}
	return (*strmap)[str];
}

Function* GetPush(int ty)
{
	BcGetCurrentCompilerContext()->FunctionUse[FunPushi+ty]=1;
	switch(ty)
	{
	case 0:
		if(!fPushi)
		{
			fPushi=BcBuildPush("systemi!Pushi",0,Type::getInt32Ty(context));
		}
		return fPushi;
		break;
	case 1:
		if(!fPushd){
			fPushd=BcBuildPush("systemi!Pushd",0,Type::getDoubleTy(context));
		}
		return fPushd;
		break;
	case 2:
		if(!fPusho){
			fPusho=BcBuildPush("systemi!Pusho",1,TyObjectRef);
		}
		return fPusho;
		break;
	}

	return 0;
}

Value* BcBitToInt(Value* v)
{
	if(v->getType()->isIntegerTy(1))
		v=builder.CreateIntCast(v,Type::getInt32Ty(context),false);
	return v;
}


void SafeBr(BasicBlock* bt,BasicBlock* cont)
{
		if(builder.GetInsertBlock()->getInstList().empty() || !builder.GetInsertBlock()->getInstList().back().isTerminator())
			builder.CreateBr(cont);
}

void SwitchBlock(BasicBlock* bb)
{
	size_t count = bparameters.size();
	for (size_t i = 0; i < count; ++i)
	{
		bparameters[i].v=0;
		bparameters[i].violated=0;
	}
	count = bstatic.size();
	for (size_t i = 0; i < count; ++i)
	{
		bstatic[i].v=0;
		bstatic[i].violated=0;
	}
	psta=0;
	builder.SetInsertPoint(bb);
}

int BcBinaryExpressionType(Expression *left, Expression *right,int code)
{
    int offset;

    if ((left->kind == NULL_EXPRESSION && right->kind != NULL_EXPRESSION)
        || (left->kind != NULL_EXPRESSION && right->kind == NULL_EXPRESSION)) {
        offset = 2; /* object type */

    } else if ((code == EQ_EXPRESSION || code == NE_EXPRESSION)
               && dkc_is_string(left->type)) {
        offset = 3; /* string type */

    } else {
        offset = get_opcode_type_offset2(left->type);
    }

    return offset;
}
#ifndef BD_ON_GCC
#define SetThreadLocal(n) n->setThreadLocal(false)
#else
#define SetThreadLocal(n)
#endif
void BcSwitchContext(Module* M,Type* t)
{
	TyObjectRef=(llvm::StructType*)t;
	module=M;
	bpc=M->getGlobalVariable("bpc");SetThreadLocal(bpc);
	bei=M->getGlobalVariable("bei");SetThreadLocal(bei);
	beo=M->getGlobalVariable("beo");SetThreadLocal(beo);
	bsp=M->getGlobalVariable("bsp");SetThreadLocal(bsp);
	arr_sp=M->getGlobalVariable("arr_sp");SetThreadLocal(arr_sp);
	//arr_is_pointer=M->getGlobalVariable("arr_is_pointer");
	bretvar=M->getGlobalVariable("retvar");SetThreadLocal(bretvar);
	pstatic=M->getGlobalVariable("pstatic");
}

void BcBuildPop()
{
	BcGetCurrentCompilerContext()->FunctionUse[FunPop]=1;
	std::vector<Type*> Args2;
	Args2.push_back(Type::getInt32Ty(context));
	Type* ty2=Type::getVoidTy(context);
	FunctionType* FT8 = FunctionType::get(ty2,Args2, false);
	fPop=Function::Create(FT8, Function::ExternalLinkage ,"systemi!Pop", module);
	return ;
}
Function* BcBuildPopImp()
{
	BcGetCurrentCompilerContext()->FunctionUse[FunPop]=1;
	llvm::IRBuilderBase::InsertPoint IP=builder.saveIP();
	std::vector<Type*> Args2;
	Args2.push_back(Type::getInt32Ty(context));
	Type* ty2=Type::getVoidTy(context);
	FunctionType* FT8 = FunctionType::get(ty2,Args2, false);
	fPop=Function::Create(FT8, Function::LinkOnceAnyLinkage ,"systemi!PopImp", module);
	fPop->addFnAttr(llvm::Attribute::AlwaysInline);
	BasicBlock *BB = BasicBlock::Create(context, "entry",fPop);
	SwitchBlock(BB);
	Value* pbsp=builder.CreateLoad(bsp);
	Value* parr=builder.CreateLoad(arr_sp);
	Value* vbsp=builder.CreateLoad(pbsp);
	Value* varr=builder.CreateLoad(parr);

	Value* popcnt=builder.CreateSub(zero,fPop->arg_begin());
	builder.CreateStore(builder.CreateGEP(vbsp,popcnt),pbsp,true);
	builder.CreateStore(builder.CreateGEP(varr,popcnt),parr,true);
	builder.CreateRetVoid();
	builder.restoreIP(IP);
	return fPop;
}


Function* BcBuildArrPtrSafeImp(Type* ty)
{
	llvm::IRBuilderBase::InsertPoint IP=builder.saveIP();
	std::vector<Type*> Args2;
	Args2.push_back(TyObjectRef);
	Args2.push_back(Type::getInt32Ty(context));
	Type* ty2=ty->getPointerTo()->getPointerTo();
	FunctionType* FT8 = FunctionType::get(ty,Args2, false);
	Function* fArrAddr=Function::Create(FT8, Function::LinkOnceAnyLinkage  ,"systemi!ArrAddrSafeImp", module);
	fArrAddr->addFnAttr(llvm::Attribute::AlwaysInline);
	BasicBlock *BB = BasicBlock::Create(context, "entry",fArrAddr);
	SwitchBlock(BB);
	Value* p=builder.CreateAlloca(TyObjectRef);
	builder.CreateStore(fArrAddr->arg_begin(),p);
	Value* pp=builder.CreatePointerCast(builder.CreateStructGEP(p,0),ty2);
	Value* p1=builder.CreateLoad(pp);

	BasicBlock* ifNull=BasicBlock::Create(context,"",fArrAddr,0);
	BasicBlock* ifNotNull=BasicBlock::Create(context,"",fArrAddr,0);
	BasicBlock* ifOverLen=BasicBlock::Create(context,"",fArrAddr,0);
	BasicBlock* ifOk=BasicBlock::Create(context,"",fArrAddr,0);
	builder.CreateCondBr(builder.CreateIsNotNull(p1),ifNotNull,ifNull);

	builder.SetInsertPoint(ifNotNull);
	Value* len=builder.CreateGEP(builder.CreateBitCast(p1,Type::getInt32PtrTy(context)),ConstInt(32,1));
	len=builder.CreateLoad(len);
	Value* cond=builder.CreateAnd(builder.CreateICmpSLT(++fArrAddr->arg_begin(),len),
		builder.CreateICmpSGE(++fArrAddr->arg_begin(),zero));
	builder.CreateCondBr(cond,ifOk,ifOverLen);

	builder.SetInsertPoint(ifOverLen);
	builder.CreateCall(module->getFunction("system!SystemRaise"),ConstInt(32,2)); //raise ExArrayOverLengthErr
	builder.CreateRet(p);//ConstantPointerNull::get((PointerType*)ty));

	builder.SetInsertPoint(ifOk);
	builder.CreateRet(builder.CreateLoad(p1));

	builder.SetInsertPoint(ifNull);
	builder.CreateCall(module->getFunction("system!SystemRaise"),ConstInt(32,1)); //raise ExNullPointerErr
	builder.CreateRet(p);//;ConstantPointerNull::get((PointerType*)ty));
	builder.restoreIP(IP);
	return fArrAddr;
}

Function* BcBuildObjectRefPtrImp()
{
	llvm::IRBuilderBase::InsertPoint IP=builder.saveIP();
	std::vector<Type*> Args2;
	Args2.push_back(TyObjectRef);
	FunctionType* FT8 = FunctionType::get(Type::getInt32Ty(context),Args2, false);
	Function* fObjectRefPtr=Function::Create(FT8, Function::LinkOnceAnyLinkage  ,"systemi!ObjectRefPtrImp", module);
	fObjectRefPtr->addFnAttr(llvm::Attribute::AlwaysInline);
	BasicBlock *BB = BasicBlock::Create(context, "entry",fObjectRefPtr);
	SwitchBlock(BB);
	Value* p=builder.CreateAlloca(TyObjectRef);
	builder.CreateStore(fObjectRefPtr->arg_begin(),p);
	Value* pp=builder.CreatePointerCast(builder.CreateStructGEP(p,0),Type::getInt32PtrTy(context));
	Value* p1=builder.CreateLoad(pp);
	builder.CreateRet(p1);

	builder.restoreIP(IP);
	return fObjectRefPtr;
}


Function* BcBuildArrPtrImp(Type* ty)
{
	llvm::IRBuilderBase::InsertPoint IP=builder.saveIP();
	std::vector<Type*> Args2;
	Args2.push_back(TyObjectRef);
	Args2.push_back(Type::getInt32Ty(context));
	Type* ty2=ty->getPointerTo()->getPointerTo();
	FunctionType* FT8 = FunctionType::get(ty,Args2, false);
	Function* fArrAddr=Function::Create(FT8, Function::LinkOnceAnyLinkage  ,"systemi!ArrAddrImp", module);
	fArrAddr->addFnAttr(llvm::Attribute::AlwaysInline);
	BasicBlock *BB = BasicBlock::Create(context, "entry",fArrAddr);
	SwitchBlock(BB);
	Value* p=builder.CreateAlloca(TyObjectRef);
	builder.CreateStore(fArrAddr->arg_begin(),p);
	Value* pp=builder.CreatePointerCast(builder.CreateStructGEP(p,0),ty2);
	Value* p1=builder.CreateLoad(pp);
	builder.CreateRet(builder.CreateLoad(p1));

	builder.restoreIP(IP);
	return fArrAddr;
}

void BcBuildArrPtrSafe(Type* ty)
{
	BcGetCurrentCompilerContext()->FunctionUse[FunArrAddrSafe]=1;
	std::vector<Type*> Args2;
	Args2.push_back(TyObjectRef);
	Args2.push_back(Type::getInt32Ty(context));
	Type* ty2=ty->getPointerTo()->getPointerTo();
	FunctionType* FT8 = FunctionType::get(ty,Args2, false);
	fArrAddrSafe=Function::Create(FT8, Function::ExternalLinkage  ,"systemi!ArrAddrSafe", module);

	return ;
}

Function* BcBuildFldPtrImp(Type* ty)
{
	llvm::IRBuilderBase::InsertPoint IP=builder.saveIP();
	std::vector<Type*> Args2;
	Args2.push_back(TyObjectRef);
	Type* ty2=ty->getPointerTo()->getPointerTo();
	FunctionType* FT8 = FunctionType::get(ty,Args2, false);
	Function* fArrAddr=Function::Create(FT8, Function::LinkOnceAnyLinkage  ,"systemi!FldAddrImp", module);
	fArrAddr->addFnAttr(llvm::Attribute::AlwaysInline);
	BasicBlock *BB = BasicBlock::Create(context, "entry",fArrAddr);
	SwitchBlock(BB);
	Value* p=builder.CreateAlloca(TyObjectRef);
	builder.CreateStore(fArrAddr->arg_begin(),p);
	Value* pp=builder.CreatePointerCast(builder.CreateStructGEP(p,0),ty2);
	Value* p1=builder.CreateLoad(pp);
	BasicBlock* ifNull=BasicBlock::Create(context,"",fArrAddr,0);
	BasicBlock* ifOk=BasicBlock::Create(context,"",fArrAddr,0);
	builder.CreateCondBr(builder.CreateIsNotNull(p1),ifOk,ifNull);

	builder.SetInsertPoint(ifOk);
	builder.CreateRet(builder.CreateLoad(p1));

	builder.SetInsertPoint(ifNull);
	builder.CreateCall(module->getFunction("system!SystemRaise"),ConstInt(32,1)); //raise ExNullPointerErr
	builder.CreateRet(p);//ConstantPointerNull::get((PointerType*)ty));
	builder.restoreIP(IP);
	return fArrAddr;
}
void BcBuildFldPtr(Type* ty)
{
	BcGetCurrentCompilerContext()->FunctionUse[FunFldAddr]=1;
	std::vector<Type*> Args2;
	Args2.push_back(TyObjectRef);
	Type* ty2=ty->getPointerTo()->getPointerTo();
	FunctionType* FT8 = FunctionType::get(ty,Args2, false);
	fFldAddr=Function::Create(FT8, Function::ExternalLinkage  ,"systemi!FldAddr", module);

	return ;
}

void BcBuildObjectRefPtr()
{
	std::vector<Type*> Args2;
	Args2.push_back(TyObjectRef);
	FunctionType* FT8 = FunctionType::get(Type::getInt32Ty(context),Args2, false);
	fObjectRefPtr=Function::Create(FT8, Function::ExternalLinkage  ,"systemi!ObjectRefPtr", module);

	return ;
}

void BcBuildArrPtr(Type* ty)
{
	BcGetCurrentCompilerContext()->FunctionUse[FunArrAddr]=1;
	std::vector<Type*> Args2;
	Args2.push_back(TyObjectRef);
	Type* ty2=ty->getPointerTo()->getPointerTo();
	FunctionType* FT8 = FunctionType::get(ty,Args2, false);
	fArrAddr=Function::Create(FT8, Function::ExternalLinkage  ,"systemi!ArrAddr", module);

	return ;
}
void BcBuildArrBdChk()
{
	/*llvm::IRBuilderBase::InsertPoint IP=builder.saveIP();
	std::vector<Type*> Args2;
	Args2.push_back(TyObjectRef);
	FunctionType* FT8 = FunctionType::get(Type::getInt32Ty(context),Args2, false);
	fArrBdChk=Function::Create(FT8, Function::LinkOnceAnyLinkage ,"systemi!ArrBdChk", module);
	fArrBdChk->addFnAttr(llvm::Attribute::AlwaysInline);
	BasicBlock *BB = BasicBlock::Create(context, "entry",fArrBdChk);
	SwitchBlock(BB);
	Value* p=builder.CreateAlloca(TyObjectRef);
	builder.CreateStore(fArrBdChk->arg_begin(),p);
	Value* pp=builder.CreatePointerCast(builder.CreateStructGEP(p,0),ty2);
	Value* p1=builder.CreateLoad(pp);
	BasicBlock* ifNull=BasicBlock::Create(context,"",fArrBdChk,0);
	BasicBlock* ifOk=BasicBlock::Create(context,"",fArrBdChk,0);
	builder.CreateCondBr(builder.CreateIsNotNull(p1),ifOk,ifNull);

	builder.SetInsertPoint(ifOk);
	builder.CreateRet(builder.CreateLoad(p1));

	builder.SetInsertPoint(ifNull);
	builder.CreateRet(ConstantPointerNull::get((PointerType*)ty));


	builder.restoreIP(IP);
	return ;*/
}




Function* GetPop()
{
	if(!fPop)
	{
		BcBuildPop();
	}
	return fPop;
}

Function* GetArrAddrSafe()
{
	if(!fArrAddrSafe)
	{

		BcBuildArrPtrSafe(TyObjectRef->getPointerTo());
	}
	return fArrAddrSafe;

}

Function* GetFldAddr()
{
	if(!fFldAddr)
	{
		BcBuildFldPtr(TyObjectRef->getPointerTo());
	}
	return fFldAddr;

}

Function* GetArrAddr()
{
	if(!fArrAddr)
	{
		BcBuildArrBdChk();
		BcBuildArrPtr(TyObjectRef->getPointerTo());
	}
	return fArrAddr;

}

Function* GetObjrefPtr()
{
	if(!fObjectRefPtr)
	{
		BcBuildObjectRefPtr();
	}
	return fObjectRefPtr;

}


Function* BcBuildPush(char* name,int isptr,Type* ty)
{
	std::vector<Type*> Args2(1,ty);
	FunctionType* FT8 = FunctionType::get(Type::getVoidTy(context),Args2, false);
	Function* fret=Function::Create(FT8, Function::ExternalLinkage,name, module);

	return fret;
}

void BcBuildGetReg(Value* v,int index,Function* fGetReg)
{
	builder.CreateStore(builder.CreateBitCast(builder.CreateCall(fGetReg,ConstInt(32,index)),v->getType()->getPointerElementType()),v);
}

Function* BcBuildRegInit()
{
	std::vector<Type*> Args2(1,Type::getInt32Ty(context));
	FunctionType* FT8 = FunctionType::get(Type::getInt32PtrTy(context),Args2,false);
	Function* fGetReg=Function::Create(FT8, Function::ExternalLinkage,"system!GetReg", module);

	llvm::IRBuilderBase::InsertPoint IP=builder.saveIP();
	FT8 = FunctionType::get(Type::getVoidTy(context),false);
	Function* fret=Function::Create(FT8, Function::ExternalLinkage,"system!RegInit", module);
	BasicBlock *BB = BasicBlock::Create(context, "entry",fret);
	SwitchBlock(BB);

	BcBuildGetReg(bpc,0,fGetReg);
	BcBuildGetReg(bei,1,fGetReg);
	BcBuildGetReg(beo,2,fGetReg);
	BcBuildGetReg(bsp,3,fGetReg);
	BcBuildGetReg(arr_sp,4,fGetReg);
	BcBuildGetReg(bretvar,5,fGetReg);

	builder.CreateRetVoid();
	builder.restoreIP(IP);
	return fret;
}

Function* BcBuildPushImp(char* name,int isptr,Type* ty)
{
	llvm::IRBuilderBase::InsertPoint IP=builder.saveIP();
	std::vector<Type*> Args2(1,ty);
	FunctionType* FT8 = FunctionType::get(Type::getVoidTy(context),Args2, false);
	Function* fret=Function::Create(FT8, Function::LinkOnceAnyLinkage,name, module);
	fret->addFnAttr(llvm::Attribute::AlwaysInline);
	BasicBlock *BB = BasicBlock::Create(context, "entry",fret);
	SwitchBlock(BB);

	Value* pbsp=builder.CreateLoad(bsp);
	Value* parr=builder.CreateLoad(arr_sp);
	Value* vbsp=builder.CreateLoad(pbsp);
	Value* varr=builder.CreateLoad(parr);
	//Value* varr=builder.CreateLoad(arr_is_pointer);
	builder.CreateStore(ConstInt(32,isptr),varr);
	Value* re=builder.CreateBitCast(vbsp,ty->getPointerTo());
	builder.CreateStore(fret->arg_begin(),re);
	builder.CreateStore(builder.CreateGEP(vbsp,ConstantInt::get(context,APInt(32,1))),pbsp);
	builder.CreateStore(builder.CreateGEP(varr,ConstantInt::get(context,APInt(32,1))),parr);
	builder.CreateRetVoid();
	builder.restoreIP(IP);
	return fret;
}

Value* BcGenerateAutoVar(Expression *expr,Function* f)
{
	std::vector<Value*> args;
	args.push_back(GetStrValue(expr->u.identifier.name));//builder.CreateGlobalStringPtr(expr->u.identifier.name));
	return builder.CreateCall(f,args);
}



extern "C" void BcDumpModule()
{
	printf("================\n");
	module->dump();
}

extern "C" void BcBuildInlines(void* mod)
{
	return;//we do nothing
	module=(Module*) mod;
	bsp=module->getGlobalVariable("bsp");
	arr_sp=module->getGlobalVariable("arr_sp");
	//arr_is_pointer=module->getGlobalVariable("arr_is_pointer");
	for(int i=0;i<FunMax;i++)
	{
		if(BcGetCurrentCompilerContext()->FunctionUse[i])
		{
			switch(i)
			{
			case FunArrAddr:
				BcBuildArrPtrImp(TyObjectRef->getPointerTo());
				break;
			case FunPushi:
				BcBuildPushImp("systemi!PushiImp",0,Type::getInt32Ty(context));
				break;
			case FunPushd:
				BcBuildPushImp("systemi!PushdImp",0,Type::getDoubleTy(context));
				break;
			case FunPusho:
				BcBuildPushImp("systemi!PushoImp",1,TyObjectRef);
				break;
			case FunPop:
				BcBuildPopImp();
				break;
			case FunArrAddrSafe:
				BcBuildArrPtrSafeImp(TyObjectRef->getPointerTo());
				break;
			case FunFldAddr:
				BcBuildFldPtrImp(TyObjectRef->getPointerTo());
				break;
			}
		}
	}
}

extern "C" void BcFreeDIBuilder(void* db)
{
	DIBuilder* dibuilder=(DIBuilder*)db;
	dibuilder->finalize();
	delete dibuilder;
}

extern "C" void* BcNewModule(char* name,char* path)
{
	if(!name)
		name="";
	strmap=new StrValueMap();  //fix-me : remember to delete
		///////////here we go with LLVM
	module = new Module(name, context); //fix-me : remember to delete it

	dibuilder=new DIBuilder(*module);
	llvm::StringRef str=path;
	size_t idx=0;
	while(idx!=StringRef::npos)
	{
		idx=str.find_first_of("\\",idx);
		char* s=(char*)str.data();
		s[idx]='/';
	}
	idx=str.find_last_of("/");
	StringRef dir,file;
	if(idx==StringRef::npos)
	{
		dir="";
		file=path;
	}
	else
	{
		dir=str.slice(0,idx);
		file=str.slice(idx+1,StringRef::npos);
	}
	if(file.empty())
		file="$unknown";
	dibuilder->createCompileUnit(dwarf::DW_LANG_lo_user+1,file,dir,"Birdee",false,"",0);
	module->addModuleFlag(Module::Warning, "Debug Info Version",DEBUG_METADATA_VERSION);
	currentfile=dibuilder->createFile(file,dir);
	fPushi=0;
	fPushd=0;
	fPusho=0;
	fArrAddr=0;
	fPop=0;

	fSharedSeti=0;
	fSharedSetd=0;
	fSharedSeto=0;
	fSharedSets=0;

	fSharedGeti=0;
	fSharedGetd=0;
	fSharedGeto=0;
	fSharedGets=0;
	fNewShared=0;
	fObjectRefPtr=0;
	//FldGet[0]=0;FldGet[1]=0;FldGet[2]=0;
	//FldPut[0]=0;FldPut[1]=0;FldPut[2]=0;
	SharedGetSwitch[0]=0;SharedGetSwitch[1]=0;SharedGetSwitch[2]=0;SharedGetSwitch[3]=0;
	SharedPutSwitch[0]=0;SharedPutSwitch[1]=0;SharedPutSwitch[2]=0;SharedPutSwitch[3]=0;
	//BcBuildArrPtr(Type::getInt32Ty(context)->getPointerTo());
	//builder.set

	std::vector<Type*> Args2(1,Type::getInt32Ty(context));
	FunctionType* FT2 = FunctionType::get(TyObjectRef,Args2, false);
	fLoadStringFromPool = Function::Create(FT2, Function::ExternalLinkage,"string!LoadStringFromPool", module);
	fDownCast=Function::Create(FT2, Function::ExternalLinkage,"system!DownCast", module);
	fUpCast=Function::Create(FT2, Function::ExternalLinkage,"system!UpCast", module);
	fNewDelegate = Function::Create(FT2, Function::ExternalLinkage,"system!NewDelegate", module);

	FunctionType* FT22 = FunctionType::get(Type::getInt1Ty(context),Args2, false);
	fInstanceof=Function::Create(FT22, Function::ExternalLinkage,"system!Instanceof", module);

	std::vector<Type*> Argsii(2,Type::getInt32Ty(context));
	FunctionType* FTbii = FunctionType::get(Type::getInt1Ty(context),Argsii, false);
	fInstanceof2=Function::Create(FTbii, Function::ExternalLinkage,"system!Instanceof2", module);

	std::vector<Type*> Args3(2,TyObjectRef);//temp : to del
	FunctionType* FT3 = FunctionType::get(TyObjectRef,Args3, false);//temp : to del
	FunctionType* FT32 = FunctionType::get(TyObjectRef, false);
	fChainString = Function::Create(FT32, Function::ExternalLinkage,"string!ChainString", module);

	std::vector<Type*> Args4(2,TyObjectRef);//temp : to del
	FunctionType* FT4 = FunctionType::get(Type::getInt32Ty(context), false);
	fCmpString = Function::Create(FT4, Function::ExternalLinkage,"string!CompareString", module);

	FunctionType* FT5 = FunctionType::get(Type::getInt32Ty(context), false);
	fCmpObject = Function::Create(FT5, Function::ExternalLinkage,"object!CompareObject", module);


	std::vector<Type*> Args2Int(2,Type::getInt32Ty(context));
	FunctionType* FTArr = FunctionType::get(TyObjectRef,Args2Int, false);
	fArrayLiteral = Function::Create(FTArr, Function::ExternalLinkage,"system!ArrayLiteral", module);
	fNewArray = Function::Create(FTArr, Function::ExternalLinkage,"system!NewArray", module);
	fNewGlobalArray = Function::Create(FTArr, Function::ExternalLinkage,"shared!NewArray", module);
	fNew = Function::Create(FTArr, Function::ExternalLinkage,"object!New", module);
	fNewShared = Function::Create(FTArr, Function::ExternalLinkage,"shared!New", module);

	FunctionType* nft = FunctionType::get(Type::getInt32PtrTy(context), false);
	fPushException = Function::Create(nft, Function::ExternalLinkage,"system!PushException", module);
	std::vector<Type*>ArgsPInt(1,Type::getInt32PtrTy(context));
	nft = FunctionType::get(Type::getInt32Ty(context),ArgsPInt, false);
	fSetjmp = Function::Create(nft, Function::ExternalLinkage,"system!Setjmp", module);
	nft = FunctionType::get(Type::getVoidTy(context),Args2, false);
	fRaise = Function::Create(nft, Function::ExternalLinkage,"system!Raise", module);
	fSystemRaise=Function::Create(nft, Function::ExternalLinkage,"system!SystemRaise", module);
	nft = FunctionType::get(Type::getVoidTy(context), false);
	fLeaveTry = Function::Create(nft, Function::ExternalLinkage,"system!LeaveTry", module);

	std::vector<Type*> ArgsObjInt;  ArgsObjInt.push_back(Type::getInt32Ty(context));
	nft = FunctionType::get(Type::getInt32Ty(context),ArgsObjInt, false);
	fArrGetCh = Function::Create(nft, Function::ExternalLinkage,"system!ArrGetCh", module);

/*	fArrGeti = Function::Create(nft, Function::ExternalLinkage,"system!ArrGeti", module);
	//fFldGeti = Function::Create(nft, Function::ExternalLinkage,"system!FldGeti", module);
	nft = FunctionType::get(Type::getDoubleTy(context),ArgsObjInt, false);
	fArrGetd = Function::Create(nft, Function::ExternalLinkage,"system!ArrGetd", module);
	//fFldGetd = Function::Create(nft, Function::ExternalLinkage,"system!FldGetd", module);
	nft = FunctionType::get(TyObjectRef,ArgsObjInt, false);
	fArrGeto = Function::Create(nft, Function::ExternalLinkage,"system!ArrGeto", module);
	//fFldGeto = Function::Create(nft, Function::ExternalLinkage,"system!FldGeto", module);
	//ArrGet[0]=fArrGeti;	ArrGet[1]=fArrGetd;ArrGet[2]=fArrGeto;
	//FldGet[0]=fFldGeti;	FldGet[1]=fFldGetd;FldGet[2]=fFldGeto;*/


	nft = FunctionType::get(Type::getVoidTy(context), false);
	fInvokeDelegate = Function::Create(nft, Function::ExternalLinkage,"system!InvokeDelegate", module);
	nft = FunctionType::get(TyObjectRef, false);
	fGetSuper = Function::Create(nft, Function::ExternalLinkage,"system!GetSuper", module);
	std::vector<Type*> ArgsOII;  ArgsOII.push_back(Type::getInt32Ty(context));ArgsOII.push_back(Type::getInt32Ty(context));
	nft = FunctionType::get(Type::getVoidTy(context),ArgsOII, false);
	fArrPuti = Function::Create(nft, Function::ExternalLinkage,"system!ArrPuti", module);
//	fArrPuti->setCallingConv(llvm::CallingConv::X86_FastCall  );

/*	//fFldPuti = Function::Create(nft, Function::ExternalLinkage,"system!FldPuti", module);
	std::vector<Type*> ArgsOID; ArgsOID.push_back(Type::getInt32Ty(context));ArgsOID.push_back(Type::getDoubleTy(context));
	nft = FunctionType::get(Type::getVoidTy(context),ArgsOID, false);
	fArrPutd = Function::Create(nft, Function::ExternalLinkage,"system!ArrPutd", module);
	//fFldPutd = Function::Create(nft, Function::ExternalLinkage,"system!FldPutd", module);
	std::vector<Type*> ArgsOIO;  ArgsOIO.push_back(Type::getInt32Ty(context));
	nft = FunctionType::get(Type::getVoidTy(context),ArgsOIO, false);
	fArrPuto = Function::Create(nft, Function::ExternalLinkage,"system!ArrPuto", module);
	//fFldPuto = Function::Create(nft, Function::ExternalLinkage,"system!FldPuto", module);
	ArrPut[0]=fArrPuti;	ArrPut[1]=fArrPutd;ArrPut[2]=fArrPuto;
	//FldPut[0]=fFldPuti;	FldPut[1]=fFldPutd;FldPut[2]=fFldPuto;*/

	nft = FunctionType::get(Type::getVoidTy(context), false);
	fFailure=Function::Create(nft, Function::ExternalLinkage,"system!Failure", module);
	fReraise=Function::Create(nft, Function::ExternalLinkage,"system!Reraise", module);

	std::vector<Type*> ArgSSI;	ArgSSI.push_back(Type::getInt32Ty(context));
	FT4 = FunctionType::get(TyObjectRef,ArgSSI, false);
	fIntToStr = Function::Create(FT4, Function::ExternalLinkage,"system!IntToStr", module);

	std::vector<Type*> ArgSSD;	ArgSSD.push_back(Type::getDoubleTy(context));
	FT4 = FunctionType::get(TyObjectRef,ArgSSD, false);
	fDoubleToStr = Function::Create(FT4, Function::ExternalLinkage,"system!DoubleToStr", module);

	std::vector<Type*> ArgSSB;	ArgSSB.push_back(Type::getInt32Ty(context));
	FT4 = FunctionType::get(TyObjectRef,ArgSSB, false);
	fBoolToStr = Function::Create(FT4, Function::ExternalLinkage,"system!BoolToStr", module);

	std::vector<Type*> ArgIpI;	ArgIpI.push_back(Type::getInt32PtrTy(context));ArgIpI.push_back(Type::getInt32Ty(context));
	FT4 = FunctionType::get(Type::getVoidTy(context),ArgIpI, false);
	fAtmInc = Function::Create(FT4, Function::ExternalLinkage,"system!AtmInc", module);
	fAtmDec = Function::Create(FT4, Function::ExternalLinkage,"system!AtmDec", module);
	//FunStoreStaicSwitch[0]=fStoreStaticInt;FunStoreStaicSwitch[1]=fStoreStaticDouble;FunStoreStaicSwitch[2]=fStoreStaticString;
	/*bpc=new GlobalVariable(*module,Type::getInt32Ty(context),false,GlobalValue::ExternalLinkage,0,"bpc");
	bei=new GlobalVariable(*module,Type::getInt32Ty(context),false,GlobalValue::ExternalLinkage,0,"bei");
	beo=new GlobalVariable(*module,TyObjectRef,false,GlobalValue::ExternalLinkage,0,"beo");
	bsp=new GlobalVariable(*module,TypStack,false,GlobalValue::ExternalLinkage ,0,"bsp");//bsp->setInitializer((Constant*)zero);
	arr_sp=new GlobalVariable(*module,Type::getInt32PtrTy(context),true,GlobalValue::ExternalLinkage,0,"arr_sp");
	bretvar=new GlobalVariable(*module,TyObjectRef,false,GlobalValue::ExternalLinkage,0,"retvar");
	pthis=new GlobalVariable(*module,TyObjectRef,false	,GlobalValue::ExternalLinkage,0,"pthis");
	pstatic=new GlobalVariable(*module,TypStack,true,GlobalValue::ExternalLinkage,0,"pstatic");*/
	//arr_is_pointer=new GlobalVariable(*module,Type::getInt32PtrTy(context),true,GlobalValue::ExternalLinkage,0,"arr_is_pointer");

	//fix-me : this is an awkward bypass of an LLVM bug on external-linkage TLS variables. Fix me when the llvm bug is fixed (or never).
	bpc=new GlobalVariable(*module,Type::getInt32PtrTy(context),false,LINKAGE_TYPE,
		ConstPointer(Type::getInt32PtrTy(context)),"bpc",0,THREAD_MODEL,0,true);
	bei=new GlobalVariable(*module,Type::getInt32PtrTy(context),false,LINKAGE_TYPE,
		ConstPointer(Type::getInt32PtrTy(context)),"bei",0,THREAD_MODEL,0,true);
	beo=new GlobalVariable(*module,TyObjectRef->getPointerTo(),false,LINKAGE_TYPE,
		ConstPointer((PointerType*)TypStack),"beo",0,THREAD_MODEL,0,true);
	bsp=new GlobalVariable(*module,TypStack->getPointerTo(),false,LINKAGE_TYPE,
		ConstPointer(TypStack->getPointerTo()),"bsp",0,THREAD_MODEL,0,true);
	arr_sp=new GlobalVariable(*module,Type::getInt32PtrTy(context)->getPointerTo(),false,LINKAGE_TYPE,
		ConstPointer(Type::getInt32PtrTy(context)->getPointerTo()),"arr_sp",0,THREAD_MODEL,0,true);
	bretvar=new GlobalVariable(*module,TypStack,false,LINKAGE_TYPE,
		ConstPointer((PointerType*)TypStack),"retvar",0,THREAD_MODEL,0,true);
	pstatic=new GlobalVariable(*module,TypStack,true,GlobalValue::ExternalLinkage,0,"pstatic"); //static variable is shared by all threads
	m_id=new GlobalVariable(*module,Type::getInt32Ty(context),true,GlobalValue::ExternalLinkage,0,"mid"); //module is is shared by all threads

	FunctionType* FTInvoke = FunctionType::get(Type::getVoidTy(context),Args2, false);
	fInvoke = Function::Create(FTInvoke, Function::ExternalLinkage,"system!Invoke", module);
	//fInvoke->setDoesNotAccessMemory(1);
	fCall = Function::Create(FTInvoke, Function::ExternalLinkage,"system!Call", module);
	fDoInvoke = Function::Create(FTInvoke, Function::ExternalLinkage,"system!DoInvoke", module);

	std::vector<Type*> ArgPStr;	ArgPStr.push_back(Type::getInt8PtrTy(context));
	nft= FunctionType::get(TyObjectRef,ArgPStr, false);
	fGetVar= Function::Create(nft, Function::ExternalLinkage,"autovar!get", module);
	fGetOrCreateVar= Function::Create(nft, Function::ExternalLinkage,"autovar!getorcreate", module);

	std::vector<Type*> mArg;	
	mArg.push_back(Type::getInt32Ty(context));mArg.push_back(Type::getInt32Ty(context));mArg.push_back(Type::getInt32Ty(context));
	nft=FunctionType::get(Type::getVoidTy(context),mArg, false);
	fSharedSeti=Function::Create(nft, Function::ExternalLinkage,"shared!seti", module);
	SharedPutSwitch[0]=fSharedSeti;
	fSharedSeto=Function::Create(nft, Function::ExternalLinkage,"shared!seto", module);
	SharedPutSwitch[2]=fSharedSeto;

	//fSharedInc=Function::Create(nft, Function::ExternalLinkage,"shared!inc", module);
	//fSharedDec=Function::Create(nft, Function::ExternalLinkage,"shared!dec", module);

	mArg.pop_back(); mArg.push_back(Type::getDoubleTy(context));
	nft=FunctionType::get(Type::getVoidTy(context),mArg, false);
	fSharedSetd=Function::Create(nft, Function::ExternalLinkage,"shared!setd", module);
	SharedPutSwitch[1]=fSharedSetd;

	mArg.pop_back(); mArg.push_back(TyObjectRef);
	nft=FunctionType::get(Type::getVoidTy(context),mArg, false);
	fSharedSets=Function::Create(nft, Function::ExternalLinkage,"shared!sets", module);
	SharedPutSwitch[3]=fSharedSets;


	mArg.pop_back();
	nft=FunctionType::get(Type::getInt32Ty(context),mArg, false);
	fSharedGeti=Function::Create(nft, Function::ExternalLinkage,"shared!geti", module);
	SharedGetSwitch[0]=fSharedGeti;

	nft=FunctionType::get(Type::getDoubleTy(context),mArg, false);
	fSharedGetd=Function::Create(nft, Function::ExternalLinkage,"shared!getd", module);
	SharedGetSwitch[1]=fSharedGetd;

	nft=FunctionType::get(TyObjectRef,mArg, false);
	fSharedGets=Function::Create(nft, Function::ExternalLinkage,"shared!gets", module);
	SharedGetSwitch[3]=fSharedGets;

	mArg.push_back(Type::getInt32Ty(context));
	nft=FunctionType::get(TyObjectRef,mArg, false);
	fSharedGeto=Function::Create(nft, Function::ExternalLinkage,"shared!geto", module);
	SharedGetSwitch[2]=fSharedGeto;

	if(!strcmp(name,"diksam.lang"))
	{
		//BcBuildArrPtrImp(TyObjectRef->getPointerTo());
		//module->dump();

		BcGetCurrentCompilerContext()->inline_module=module;

	}
	BcGetCurrentCompilerContext()->dibuilder=dibuilder;
	return module;
}


extern "C" void BcInitLLVMCompiler()
{

    ///////////
	//Create the ObjectRef type (used in stack)
	TypInt=Type::getInt32Ty(context)->getPointerTo();
#ifdef BD_ON_X86
	std::vector<Type*> types(2,Type::getInt32Ty(context));//TypInt);
#else
	_BreakPoint;
#endif
	ArrayRef<Type*> typesRef(types);
	TyObjectRef = StructType::create(context,typesRef,"Stack");

	TypStack=TyObjectRef->getPointerTo();
    ///////////
	//Create the function type
	std::vector<Type*> ArgTys;
	ArgTys.push_back(TyObjectRef->getPointerTo());// it is actually DVM_Value
	//ArgTys.push_back(Type::getInt32Ty(context));
	FT = FunctionType::get(Type::getVoidTy(context),ArgTys, false);

	TypeSwitch[0]=Type::getInt32PtrTy(context);TypeSwitch[1]=Type::getDoublePtrTy(context);TypeSwitch[2]=TypStack;
	///////////////////
}

Value* BcGenerateStringExpression(DVM_Executable *cf, Expression *expr)
{
    DVM_ConstantPool cp;
    int cp_idx;

    cp.tag = DVM_CONSTANT_STRING;
    cp.u.c_string = expr->u.string_value;
    cp_idx = add_constant_pool(cf, &cp);
	std::vector<Value*> args(1,ConstantInt::get(context,APInt(32,cp_idx)));
	return builder.CreateCall(fLoadStringFromPool,args);
    //generate_code(ob, expr->line_number, DVM_PUSH_STRING, cp_idx);
}

Value* BcBinaryDouble(int kind,Value* lv,Value* rv)
{
	switch(kind)
	{
    case ADD_EXPRESSION:
		return builder.CreateFAdd(lv,rv);
        break;
    case SUB_EXPRESSION:
		return builder.CreateFSub(lv,rv);
        break;
    case MUL_EXPRESSION:
		return builder.CreateFMul(lv,rv);
        break;
    case DIV_EXPRESSION:
		return builder.CreateFDiv(lv,rv);
        break;
    case MOD_EXPRESSION:
		return builder.CreateFRem(lv,rv);
    case EQ_EXPRESSION:
		return builder.CreateFCmpOEQ(lv,rv);
        break;
    case NE_EXPRESSION:
		return builder.CreateFCmpONE(lv,rv);
        break;
    case GT_EXPRESSION:
		return builder.CreateFCmpOGT(lv,rv);
        break;
    case GE_EXPRESSION:
		return builder.CreateFCmpOGE(lv,rv);
        break;
    case LT_EXPRESSION:
		return builder.CreateFCmpOLT(lv,rv);
        break;
    case LE_EXPRESSION:
		return builder.CreateFCmpOLE(lv,rv);
        break;
	}
	return 0;
}

Value* BcBinaryInt(int kind,Value* lv,Value* rv)
{
	lv=BcBitToInt(lv);
	rv=BcBitToInt(rv);
	switch(kind)
	{
    case ADD_EXPRESSION:
		return builder.CreateAdd(lv,rv);
        break;
    case SUB_EXPRESSION:
		//lv->getType()->dump();
		//rv->getType()->dump();
		return builder.CreateSub(lv,rv);
        break;
    case MUL_EXPRESSION:
		return builder.CreateMul(lv,rv);
        break;
    case DIV_EXPRESSION:
		return builder.CreateSDiv(lv,rv);
        break;
    case MOD_EXPRESSION:
		return builder.CreateSRem(lv,rv);
    case EQ_EXPRESSION:
        return builder.CreateICmpEQ(lv,rv);
        break;
    case NE_EXPRESSION:
		return builder.CreateICmpNE(lv,rv);
        break;
    case GT_EXPRESSION:
		return builder.CreateICmpSGT(lv,rv);
        break;
    case GE_EXPRESSION:
		return builder.CreateICmpSGE(lv,rv);
        break;
    case LT_EXPRESSION:
		return builder.CreateICmpSLT(lv,rv);
        break;
    case LE_EXPRESSION:
		return builder.CreateICmpSLE(lv,rv);
        break;
	}
	return 0;
}

Value* BcBinaryObject(int kind,Value* lv,Value* rv)
{
	//std::vector<Value*> arg;
	//arg.push_back(lv);arg.push_back(rv);

	Value* t;
	switch(kind)
	{
	case EQ_EXPRESSION:
		t=builder.CreateCall(fCmpObject);
		return builder.CreateICmpEQ(t,zero);
	case NE_EXPRESSION:
		t=builder.CreateCall(fCmpObject);
		return builder.CreateICmpNE(t,zero);
	default:
         DBG_assert(0, ("Binary Op for object not supported..%d\n",kind ));
	}
	return 0;
}

Value* BcBinaryString(int kind,Value* lv,Value* rv)
{
	//std::vector<Value*> arg;
	//arg.push_back(lv);arg.push_back(rv);


	Value* t;
	switch(kind)
	{
	case ADD_EXPRESSION:
		return builder.CreateCall(fChainString);
	case EQ_EXPRESSION:
		t=builder.CreateCall(fCmpString);
		return builder.CreateICmpEQ(t,zero);
	case NE_EXPRESSION:
		t=builder.CreateCall(fCmpString);
		return builder.CreateICmpNE(t,zero);
    case GT_EXPRESSION:
		t=builder.CreateCall(fCmpString);
		return builder.CreateICmpSGT(t,zero);
    case GE_EXPRESSION:
		t=builder.CreateCall(fCmpString);
		return builder.CreateICmpSGE(t,zero);
    case LT_EXPRESSION:
		t=builder.CreateCall(fCmpString);
		return builder.CreateICmpSLT(t,zero);
    case LE_EXPRESSION:
		t=builder.CreateCall(fCmpString);
		return builder.CreateICmpSLE(t,zero);
	default:
         DBG_assert(0, ("Binary Op for string not supported..%d\n",kind ));
	}
	return 0;
}

Value* BcGenerateBinaryExpressionEx(DVM_Executable *exe, Block *block,Expression *left,Expression *right,int kind)
{

	int ty=BcBinaryExpressionType(left,right,kind);
	bool shouldpush= (ty==2 || ty==3 || ty==4); // if str or obj, we should push it to the stack right after the expression

	Value* lv=BcGenerateExpression(exe, block, left);
	if(shouldpush)
		builder.CreateCall(GetPush(2),lv);

    Value* rv=BcGenerateExpression(exe, block, right);
	if(shouldpush)
		builder.CreateCall(GetPush(2),rv);

	switch(ty)
	{
	case 3://string
		return BcBinaryString(kind,lv,rv);
	case 0://int
		return BcBinaryInt(kind,lv,rv);
	case 1://Double
		return BcBinaryDouble(kind,lv,rv);
	case 2://fix-me : obj : here to add operator overrider
		return BcBinaryObject(kind,lv,rv);
	case 4:
		switch(kind)
		{
		case ADD_EXPRESSION:
		case SUB_EXPRESSION:
		case MUL_EXPRESSION:
		case DIV_EXPRESSION:
		case MOD_EXPRESSION:
			builder.CreateCall(fDoInvoke,ConstInt(32,BdNFunAddVar+kind-ADD_EXPRESSION));
			return builder.CreateLoad(builder.CreateLoad(bretvar));
			break;
		}
		builder.CreateCall(fDoInvoke,ConstInt(32,BdNFunCmpVar));
		Value* result=builder.CreateLoad(builder.CreateBitCast(builder.CreateLoad(bretvar),Type::getInt32PtrTy(context)));
		switch(kind)
		{
		case EQ_EXPRESSION:
			return builder.CreateICmpEQ(result,zero);
			break;
		case NE_EXPRESSION:
			return builder.CreateICmpNE(result,zero);
			break;
		case GT_EXPRESSION:
			return builder.CreateICmpSGT(result,zero);
			break;
		case GE_EXPRESSION:
			return builder.CreateICmpSGE(result,zero);
			break;
		case LT_EXPRESSION:
			return builder.CreateICmpSLT(result,zero);
			break;
		case LE_EXPRESSION:
			return builder.CreateICmpSLE(result,zero);
			break;

		default:
			DBG_panic(("bad default. kind..%d", kind));
		}
	}
	return 0;
}

Value* BcGenerateBinaryExpression(DVM_Executable *exe, Block *block,
                           Expression *expr)
{
	return BcGenerateBinaryExpressionEx(exe,block,expr->u.binary_expression.left,expr->u.binary_expression.right,expr->kind );
}

Value* BcGetVarValue(Declaration *decl, int line_number)
{
	Value* t1;

    if (decl->is_local) {
		BcParameter& p=bparameters[decl->variable_index];
		if(!p.v)
		{
			switch(get_opcode_type_offset(decl->type))
			{
			case 2://var is string or obj
				t1=builder.CreateGEP(curfun->arg_begin(),ConstantInt::get(Type::getInt32Ty(context),APInt(32,decl->variable_index)));
				p.v=builder.CreateLoad(t1); //pointer variable should not use 'registers'?
				return p.v;
			case 0:
				t1=builder.CreateGEP(curfun->arg_begin(),ConstantInt::get(Type::getInt32Ty(context),APInt(32,decl->variable_index)));
				p.v=builder.CreateLoad(builder.CreateBitCast(t1,Type::getInt32PtrTy(context)));
				return p.v;
			case 1:
				t1=builder.CreateGEP(curfun->arg_begin(),ConstantInt::get(Type::getInt32Ty(context),APInt(32,decl->variable_index)));
				p.v=builder.CreateLoad(builder.CreateBitCast(t1,Type::getDoublePtrTy(context)));
				return p.v;
			}
		}
		else
		{
			return p.v;
		}
    } else {
		if(decl->is_shared)
		{//if the variable is a shared var
			if(!cached_mid)
				cached_mid=builder.CreateLoad(m_id);
			int ty=get_opcode_type_offset_shared(decl->type);
			switch(ty)
			{
			case 2: //object
				return builder.CreateCall3(SharedGetSwitch[ty],
					cached_mid,ConstInt(32,decl->variable_index),ConstInt(32,decl->type->u.class_ref.class_index));
				break;
			case 4: //array
				return builder.CreateCall3(SharedGetSwitch[2],
					cached_mid,ConstInt(32,decl->variable_index),ConstInt(32,-1));
				break;
			default:
				return builder.CreateCall2(SharedGetSwitch[ty],
					cached_mid,ConstInt(32,decl->variable_index));
			}
		}
		else
		{
			BcParameter& ps=bstatic[decl->variable_index];
			if(!ps.v)
			{
				//if(!psta)
				psta=builder.CreateGEP(builder.CreateLoad(pstatic),ConstInt(32,decl->variable_index));
				Value* p2=builder.CreateBitCast(psta,TypeSwitch[get_opcode_type_offset(decl->type)]);
				p2=builder.CreateLoad(p2);
				//ps.v = (get_opcode_type_offset(decl->type)==2)? 0:p2;//pointer variable should not use 'registers'?
				ps.v=p2;
				return p2;
			}
			else
			{
				return ps.v;
			}
		}
    }
}

Value* BcGenerateIdentifierExpression(DVM_Executable *exe, Block *block,Expression *expr)
{
    switch (expr->u.identifier.kind) {
    case VARIABLE_IDENTIFIER:
        return BcGetVarValue(expr->u.identifier.u.declaration, expr->line_number);
        break;
    case FUNCTION_IDENTIFIER:
		return ConstInt(32,expr->u.identifier.u.function.function_index);
		//DBG_panic(("FUNCTION_IDENTIFIER not implemented.."));
        break;
    case CONSTANT_IDENTIFIER:
/*        generate_code(ob, expr->line_number,
                      DVM_PUSH_CONSTANT_INT
                      + get_opcode_type_offset(expr->u.identifier.u.constant
                                               .constant_definition->type),
                      expr->u.identifier.u.constant.constant_index);*/
		_BreakPoint;           //fix-me : not implemented
        break;
    default:
        DBG_panic(("bad default. kind..%d", expr->u.identifier.kind));
    }
}

int BcGeneratePushArgument(DVM_Executable *exe, Block *block,ArgumentList *arg_list)
{
	int arg_cnt=0;
    ArgumentList *arg_pos;
	std::stack<Expression*> stk; //use a stack to reverse the order of arguments
    for (arg_pos = arg_list; arg_pos; arg_pos = arg_pos->next) {
		arg_cnt++;
		stk.push(arg_pos->expression);
    }
	while(!stk.empty())
	{
		Value* v=BcGenerateExpression(exe,block,stk.top());
		v=BcBitToInt(v);
		v->getType()->dump();
		int a=get_opcode_type_offset(stk.top()->type);
		builder.CreateCall(GetPush(get_opcode_type_offset(stk.top()->type)),v);
		stk.pop();
	}
	return arg_cnt;
}

Value* BcGenerateMethodCall(DVM_Executable *exe, Block *block,Expression *expr)
{
    int method_index,popcnt=-1;
    MemberExpression *member;
	FunctionCallExpression *fce = &expr->u.function_call_expression;

    member = &fce->function->u.member_expression;
    method_index = get_method_index_Ex(member,&popcnt); //param_cnt => popcnt
	popcnt=BcGeneratePushArgument(exe, block,fce->argument)-popcnt;
    Value* obj= BcGenerateExpression(exe, block,fce->function->u.member_expression.expression);
	/*Value* _pthis=builder.CreateLoad(pthis);
	Value* oldthis=builder.CreateLoad(_pthis);
	builder.CreateStore(obj,_pthis);*/
	builder.CreateCall(GetPush(2),obj);
	if(popcnt)
		builder.CreateStore(ConstInt(32,popcnt),builder.CreateLoad(bpc)); //set param_count register //fix-me : no need for bpc?
	builder.CreateCall(fCall,ConstInt(32,method_index));
	//builder.CreateStore(oldthis,_pthis);

	DBG_assert((popcnt>=0),("Pop count < 0"));
	if(fce->function->type->basic_type!=DVM_VOID_TYPE) //
		return builder.CreateLoad(builder.CreateBitCast(builder.CreateLoad(bretvar),TypeSwitch[get_opcode_type_offset3(expr->type->basic_type )]));//check-me : get_opcode_type_offset???
	else
		return 0;
    //generate_code(ob, expr->line_number, DVM_PUSH_METHOD, method_index);
    //generate_code(ob, expr->line_number, DVM_INVOKE);
}


Value* BcGenerateCallExpression(DVM_Executable *exe, Block *block, Expression *expr)
{
	FunctionCallExpression *fce = &expr->u.function_call_expression;
	int popcnt,param_cnt;
	int isDele=dkc_is_delegate(fce->function->type);
	TypeSpecifier* rtype;
    if (fce->function->kind == MEMBER_EXPRESSION
        && ((dkc_is_array(fce->function->u.member_expression.expression->type)
             || dkc_is_string(fce->function->u.member_expression.expression
                              ->type))
            || (fce->function->u.member_expression.declaration->kind
                == METHOD_MEMBER))) {
        return BcGenerateMethodCall(exe, block, expr);
    }
	if(isDele)
	{
		rtype=fce->function->u.identifier.u.declaration->type->u.delegate_ref.delegate_definition->type;
		param_cnt=fce->function->u.identifier.u.declaration->type->u.delegate_ref.delegate_definition->param_cnt ;
	}
	else
	{
		rtype=fce->function->u.identifier.u.function.function_definition->type;
		param_cnt=fce->function->u.identifier.u.function.function_definition->param_cnt;
	}
    popcnt=BcGeneratePushArgument(exe, block, fce->argument)-param_cnt;
    Value* fid=BcGenerateExpression(exe, block, fce->function);

	std::vector<Value*> md(1,ConstInt(32,expr->line_number));

	if(popcnt)
		builder.CreateStore(ConstInt(32,popcnt),builder.CreateLoad(bpc)); //set param_count register

	//fid->getType()->dump();
	if(isDele)
	{
		builder.CreateCall(GetPush(2),fid);
		builder.CreateCall(fInvokeDelegate);
	}
	else
		builder.CreateCall(fInvoke,fid)->setDebugLoc(DebugLoc::get(expr->line_number,0,currentdifunc));//->setMetadata("Dbg",MDNode::get(context,md));//generate_code(ob, expr->line_number, DVM_INVOKE);
	DBG_assert((popcnt>=0),("Pop count < 0"));
	if(popcnt)
	{
		builder.CreateCall(GetPop(),ConstInt(32,popcnt));
		//Value* newsp=builder.CreateSub(builder.CreateLoad(bsp),ConstInt(32,popcnt));
		//builder.CreateStore(newsp,bsp); //bsp += ....
	}
	if(rtype->basic_type==DVM_BOOLEAN_TYPE)
		return builder.CreateIsNotNull(builder.CreateLoad(builder.CreateBitCast(builder.CreateLoad(bretvar),TypeSwitch[get_opcode_type_offset(rtype)])));
	if(rtype->basic_type!=DVM_VOID_TYPE) //
		return builder.CreateLoad(builder.CreateBitCast(builder.CreateLoad(bretvar),TypeSwitch[get_opcode_type_offset(rtype)]));
	else
		return 0;

}



void BcGenerateSaveToIdentifier(Declaration *decl, Value* v, int line_number,int vartype)
{
	int ty=get_opcode_type_offset(decl->type);
    if (decl->is_local) {

		Value* t1=builder.CreateGEP(curfun->arg_begin(),ConstInt(32,decl->variable_index));
		if(vartype==-1)
		{

			if(dkc_is_var(decl->type) )
			{
				builder.CreateCall(GetPush(2),v);
				builder.CreateCall(GetPush(2),builder.CreateLoad(t1));
				builder.CreateCall(fDoInvoke,ConstInt(32,BdNFunCopyVar));
			}
			else
			{
				//if(get_opcode_type_offset(decl->type)!=2)
				//{
				bparameters[decl->variable_index].v=v;
				bparameters[decl->variable_index].violated=1;
				//}

				builder.CreateStore(BcBitToInt(v),builder.CreateBitCast(t1,TypeSwitch[ty]));
				if(dkc_is_array(decl->type))//Full_arr_chk
				{
					if(isArrayAddressSet(decl->variable_index,1))
					{
						Value* addr=builder.CreateCall(GetFldAddr(),v);
						builder.CreateStore(addr,GetArrayAddress(decl->variable_index,1,decl->is_param));
					}
					else
						GetArrayAddress(decl->variable_index,1,decl->is_param);
				}
			}
		}
		else
		{
			builder.CreateCall(GetPush(vartype),v);
			builder.CreateCall(GetPush(2),builder.CreateLoad(t1));
			builder.CreateCall(fDoInvoke,ConstInt(32,BdNFunIntVar+vartype));
		}
        return ;
    }
	else
	{//if it is a static variable
		if(decl->is_shared)
		{
			if(!cached_mid)
				cached_mid=builder.CreateLoad(m_id);
			int ty=get_opcode_type_offset_shared(decl->type);
			if(ty==2 || ty==4)
			{
				v=builder.CreateCall(GetObjrefPtr(),v);
				ty=2;
			}
			builder.CreateCall3(SharedPutSwitch[ty],
				cached_mid,ConstInt(32,decl->variable_index),v);
		}
		else
		{// if it is not shared
			Value* p=builder.CreateGEP(builder.CreateLoad(pstatic),ConstInt(32,decl->variable_index));
			if(vartype==-1)
			{
				Value* p2=builder.CreateBitCast(p,TypeSwitch[get_opcode_type_offset(decl->type)]);
				if(dkc_is_var(decl->type) )
				{
					builder.CreateCall(GetPush(2),v);
					builder.CreateCall(GetPush(2),builder.CreateLoad(p2));
					builder.CreateCall(fDoInvoke,ConstInt(32,BdNFunCopyVar));
				}
				else
				{
					//if(get_opcode_type_offset(decl->type)!=2)
					//{
					bstatic[decl->variable_index].v=v;
					bstatic[decl->variable_index].violated=1;
					//}
					builder.CreateStore(v,p2);
					if(dkc_is_array(decl->type) && !decl->type->derive->u.array_d.is_global) //Full_arr_chk
					{
						if(isArrayAddressSet(decl->variable_index,0))
						{
							Value* addr=builder.CreateCall(GetFldAddr(),v);
							builder.CreateStore(addr,GetArrayAddress(decl->variable_index,0));
						}
						else
							GetArrayAddress(decl->variable_index,0);
					}//*/
				}
			}
			else
			{
				builder.CreateCall(GetPush(vartype),v);
				builder.CreateCall(GetPush(2),builder.CreateLoad(p));
				builder.CreateCall(fDoInvoke,ConstInt(32,BdNFunIntVar+vartype));
			}
			return;
		}
    }
}


void BcGenerateSaveToMember(DVM_Executable *exe, Block *block,Expression *expr,Value* v,int ty=-1)
{
    MemberDeclaration *member;

    member = expr->u.member_expression.declaration;
    if (member->kind == METHOD_MEMBER) {
        dkc_compile_error(expr->line_number, ASSIGN_TO_METHOD_ERR,
                          STRING_MESSAGE_ARGUMENT, "member_name",
                          member->u.method.function_definition->name,
                          MESSAGE_ARGUMENT_END);
    }
	Value* obj=BcGenerateExpression(exe, block, expr->u.member_expression.expression);
	ExpressionKind kind=expr->u.member_expression.expression->kind;
	bool needpush=false;
	Value* ret;
	if(kind!=IDENTIFIER_EXPRESSION && kind!=MEMBER_EXPRESSION && kind!=INDEX_EXPRESSION && kind!=THIS_EXPRESSION)
	{
		needpush=true;
		builder.CreateCall(GetPush(2),obj);
	}
	if(ty==-1)
	{
/*		std::vector<Value*> arg;
		arg.push_back(ConstInt(32,member->u.field.field_index));
		int mty=get_opcode_type_offset(member->u.field.type);
		if(mty==2)
		{
			builder.CreateCall(GetPush(2),v);
		}
		else
		{
			arg.push_back(v);
		}
		builder.CreateCall(GetPush(2),BcGenerateExpression(exe, block, expr->u.member_expression.expression));
		builder.CreateCall(FldPut[mty],arg);*/

		int mty=get_opcode_type_offset(expr->type); //fix-me : code size optmization here
		if(mty==2)
		{
			builder.CreateCall(GetPush(2),v);
		}
		
		
		if(expr->u.member_expression.expression->type->u.class_ref.class_definition->is_shared)
		{//shared var
			obj=builder.CreateCall(GetObjrefPtr(),obj);
			int ty2=mty;
			if(mty==2)
			{
				if(expr->type->basic_type==DVM_STRING_TYPE)
					ty2=3;
				else
					v=builder.CreateCall(GetObjrefPtr(),v);
			}
			builder.CreateCall3(SharedPutSwitch[ty2],obj,ConstInt(32,member->u.field.field_index),v);
		}
		else
		{
			Value* fld=builder.CreateCall(GetFldAddr(),obj);
			fld=builder.CreateBitCast(builder.CreateGEP(fld,ConstInt(32,member->u.field.field_index)),TypeSwitch[mty]);
			builder.CreateStore(v,fld);
		}
		if(mty==2)
			builder.CreateCall(GetPop(),ConstInt(32,1));

	}
	else
	{
		/*std::vector<Value*> arg;
		builder.CreateCall(GetPush(2),BcGenerateExpression(exe, block, expr->u.member_expression.expression));
		arg.push_back(ConstInt(32,member->u.field.field_index));
		Value* to=builder.CreateCall(FldGet[2],arg);*/
		
		Value* fld=builder.CreateCall(GetFldAddr(),obj);
		fld=builder.CreateBitCast(builder.CreateGEP(fld,ConstInt(32,member->u.field.field_index)),TypeSwitch[get_opcode_type_offset(expr->type)]);
		Value* to= builder.CreateLoad(fld);
		builder.CreateCall(GetPush(ty),v);
		builder.CreateCall(GetPush(2),to);
		builder.CreateCall(fDoInvoke,ConstInt(32,BdNFunIntVar+ty));
	}
	if(needpush)
		builder.CreateCall(GetPop(),ConstInt(32,1));
}


Value* BcGenerateIndexExpression(DVM_Executable *exe, Block *block,Expression *expr);
void BcGenerateSaveToLvalue(DVM_Executable *exe, Block *block,Expression *expr,Value* v,int ty=-1)
{
    if (expr->kind == IDENTIFIER_EXPRESSION) {

		BcGenerateSaveToIdentifier(expr->u.identifier.u.declaration,v, expr->line_number,ty);

    }
	else if(expr->kind ==AUTOVAR_EXPRESSION)
	{
		Value* to=BcGenerateAutoVar(expr,fGetOrCreateVar);
		if(ty==-1)
		{
			builder.CreateCall(GetPush(2),v);
			builder.CreateCall(GetPush(2),to);
			builder.CreateCall(fDoInvoke,ConstInt(32,BdNFunCopyVar));
		}
		else
		{
			builder.CreateCall(GetPush(ty),v);
			builder.CreateCall(GetPush(2),to);
			builder.CreateCall(fDoInvoke,ConstInt(32,BdNFunIntVar+ty));
		}

	}
	else if (expr->kind == INDEX_EXPRESSION) {
		if(ty==-1)
		{
			int myty=get_opcode_type_offset(expr->type);
			if(myty==2)
				builder.CreateCall(GetPush(2),v);
			Value* arr=BcGenerateExpression(exe, block, expr->u.index_expression.barray);

			ExpressionKind kind=expr->u.index_expression.barray->kind;
			bool needpush=false;
			Value* ret;
			if(kind!=IDENTIFIER_EXPRESSION && kind!=MEMBER_EXPRESSION && kind!=INDEX_EXPRESSION && kind!=THIS_EXPRESSION)
			{
				needpush=true;
				builder.CreateCall(GetPush(2),arr);
			}
			Value* idx=BcGenerateExpression(exe, block, expr->u.index_expression.index);
			Declaration* decl=0;
			if(	expr->u.index_expression.barray->kind ==IDENTIFIER_EXPRESSION)
				decl=expr->u.index_expression.barray->u.identifier.u.declaration;


			/*std::vector<Value*> arg;
			buidler.CreateCall(GetPush(2),arr);arg.push_back(idx);arg.push_back(v);
			builder.CreateCall(ArrPut[get_opcode_type_offset(expr->type)],arg);//*/
			//Value* p=builder.CreatePointerCast(builder.CreateCall(GetArrAddr(),arr),TypeSwitch[get_opcode_type_offset(expr->type)]);
			//int array_cache_index=expr->u.index_expression.barray->u.identifier.u.declaration->variable_index+(expr->u.index_expression.barray->u.identifier.u.declaration->is_local)?0:2000;
			if(expr->u.index_expression.barray->type->derive->u.array_d.is_global)
			{
				int vty=get_opcode_type_offset_shared(expr->type);
				if(vty==2 || vty==4)
				{
					v=builder.CreateCall(GetObjrefPtr(),v);
					vty=2;
				}
				builder.CreateCall3(SharedPutSwitch[vty],
					builder.CreateCall(GetObjrefPtr(),arr),idx,v);
			}
			else
			{
				Value* p;
				if(block && block->unsafe)
				{
					if(decl) ////Full_arr_chk
					{
						p=builder.CreatePointerCast( builder.CreateLoad(GetArrayAddress(decl->variable_index,decl->is_local,decl->is_param)),
							TypeSwitch[myty]);
					}
					else
						p=builder.CreatePointerCast(builder.CreateCall(GetArrAddr(),arr),TypeSwitch[myty]);//*/
				}
				else
					p=builder.CreatePointerCast(builder.CreateCall2(GetArrAddrSafe(),arr,idx),TypeSwitch[myty]);
				//p=builder.CreatePointerCast(builder.CreateCall(GetArrAddr(),arr),TypeSwitch[get_opcode_type_offset(expr->type)]);
				builder.CreateStore(v,builder.CreateGEP(p,idx));
			}
			if(myty==2)
				builder.CreateCall(GetPop(),ConstInt(32,1+(needpush?1:0)));
			else
			{
				if(needpush)
					builder.CreateCall(GetPop(),ConstInt(32,1));
			}
		}
		else
		{
/*			Value* arr=BcGenerateExpression(exe, block, expr->u.index_expression.barray);
			Value* idx=BcGenerateExpression(exe, block, expr->u.index_expression.index);
			std::vector<Value*> arg;
			arg.push_back(idx);
			builder.CreateCall(GetPush(2),arr);
			Value* to=builder.CreateCall(ArrGet[2],arg);
			builder.CreateCall(GetPush(ty),v);
			builder.CreateCall(GetPush(2),to);
			builder.CreateCall(fDoInvoke,ConstInt(32,BdNFunIntVar+ty));*/
			_BreakPoint;
		}

    } else {

        DBG_assert(expr->kind == MEMBER_EXPRESSION,
                   ("expr->kind..%d", expr->kind));
		BcGenerateSaveToMember(exe, block, expr,v,ty);
    }
}

void BcGenerateAtomicExpression(DVM_Executable* exe,Block *block,Expression *left,Expression *right,int isInc)
{
	Value* t1;
	Value* ptr;
	Value* r=BcGenerateExpression(exe,block,right);
	if(left->type->derive!=NULL || left->type->basic_type!=DVM_INT_TYPE)
	{
		        dkc_compile_error(left->line_number,
                          MATH_TYPE_MISMATCH_ERR,
                          MESSAGE_ARGUMENT_END);
	}
	if(left->kind==MEMBER_EXPRESSION)
	{
		MemberDeclaration *member;
		member = left->u.member_expression.declaration;
		if (member->kind == METHOD_MEMBER) {
			dkc_compile_error(left->line_number, ASSIGN_TO_METHOD_ERR,
							  STRING_MESSAGE_ARGUMENT, "member_name",
							  member->u.method.function_definition->name,
							  MESSAGE_ARGUMENT_END);
		}
		Value* obj=BcGenerateExpression(exe, block, left->u.member_expression.expression);

		ExpressionKind kind=left->u.member_expression.expression->kind;
		bool needpush=false;
		if(kind!=IDENTIFIER_EXPRESSION && kind!=MEMBER_EXPRESSION && kind!=INDEX_EXPRESSION && kind!=THIS_EXPRESSION)
		{
			needpush=true;
			builder.CreateCall(GetPush(2),obj);
		}

		if(left->u.member_expression.expression->type->u.class_ref.class_definition->is_shared)
		{
/*			Value* id=builder.CreateCall(GetObjrefPtr(),obj);
			if(isInc)
				builder.CreateCall3(fSharedInc,id,ConstInt(32,member->u.field.field_index),r);
			else
				builder.CreateCall3(fSharedDec,id,ConstInt(32,member->u.field.field_index),r);*/
			dkc_compile_error(left->line_number,MATH_TYPE_MISMATCH_ERR,MESSAGE_ARGUMENT_END);
		}
		else
		{
			Value* fld=builder.CreateCall(GetFldAddr(),obj);
			ptr=builder.CreateBitCast(builder.CreateGEP(fld,ConstInt(32,member->u.field.field_index)),Type::getInt32PtrTy(context));
			if(isInc)
				builder.CreateCall2(fAtmInc,ptr,r);
			else
				builder.CreateCall2(fAtmDec,ptr,r);
		}
		if(needpush)
			builder.CreateCall(GetPop(),ConstInt(32,1));

	}
	else if(left->kind==IDENTIFIER_EXPRESSION)
	{
		DBG_assert(left->u.identifier.kind==VARIABLE_IDENTIFIER,("Bad identifier expression kind"));
		Declaration* decl=left->u.identifier.u.declaration;
		if(decl->is_local)
		{
			t1=builder.CreateGEP(curfun->arg_begin(),ConstantInt::get(Type::getInt32Ty(context),APInt(32,decl->variable_index)));
			ptr=builder.CreateBitCast(t1,Type::getInt32PtrTy(context));
			if(isInc)
				builder.CreateCall2(fAtmInc,ptr,r);
			else
				builder.CreateCall2(fAtmDec,ptr,r);
			BcParameter& p=bparameters[decl->variable_index];
			if(p.v)//fix-me : optimize here! We now must read back.
			{
				p.v=builder.CreateLoad(ptr);
			}
		}
		else
		{
			if(decl->is_shared)
			{
/*				if(!cached_mid)
					cached_mid=builder.CreateLoad(m_id);
				if(isInc)
					builder.CreateCall3(fSharedInc,cached_mid,ConstInt(32,decl->variable_index),r);
				else
					builder.CreateCall3(fSharedDec,cached_mid,ConstInt(32,decl->variable_index),r);*/
				dkc_compile_error(left->line_number,MATH_TYPE_MISMATCH_ERR,MESSAGE_ARGUMENT_END);
			}
			else
			{
				
				t1=builder.CreateGEP(builder.CreateLoad(pstatic),ConstInt(32,decl->variable_index));
				ptr=builder.CreateBitCast(t1,Type::getInt32PtrTy(context));
				if(isInc)
					builder.CreateCall2(fAtmInc,ptr,r);
				else
					builder.CreateCall2(fAtmDec,ptr,r);			
				BcParameter& ps=bstatic[decl->variable_index];
				if(ps.v)//fix-me : optimize here! We now must read back.
				{
					ps.v=builder.CreateLoad(ptr);
				}

			}
		}
	}
	else  if(left->kind==INDEX_EXPRESSION)
	{
		_BreakPoint;//fix-me
	}
	else 
	{
		DBG_assert(0, ("Bad kind\n"));
	}
}

Value* BcGenerateAssignExpression(DVM_Executable *exe, Block *block,
                           Expression *expr, DVM_Boolean is_toplevel)
{
	Value *retv;
	int kind;
	int ty=-1;
	if(expr->u.assign_expression.boperator!=NORMAL_ASSIGN)
	{
		switch (expr->u.assign_expression.boperator) {
		case ADD_ASSIGN:
			kind=ADD_EXPRESSION;
			break;
		case SUB_ASSIGN:
			kind=SUB_EXPRESSION;
			break;
		case MUL_ASSIGN:
			kind=MUL_EXPRESSION;
			break;
		case DIV_ASSIGN:
			kind=DIV_EXPRESSION;
			break;
		case MOD_ASSIGN:
			kind=MOD_EXPRESSION;
			break;
		case ATM_ADD_ASSIGN:
			BcGenerateAtomicExpression(exe,block,expr->u.assign_expression.left,expr->u.assign_expression.operand,1);
			return NULL;
			break;
		case ATM_SUB_ASSIGN:
			BcGenerateAtomicExpression(exe,block,expr->u.assign_expression.left,expr->u.assign_expression.operand,0);
			return NULL;
			break;
		default:
			DBG_assert(0, ("operator..%d\n", expr->u.assign_expression.boperator));
		}
		retv=BcGenerateBinaryExpressionEx(exe,block,expr->u.assign_expression.left,expr->u.assign_expression.operand,kind);
	}
	else
	{
		Expression* op=expr->u.assign_expression.operand;
		if(op->kind==CAST_EXPRESSION && (op->u.cast.type==INT_TO_VAR_CAST || op->u.cast.type==STRING_TO_VAR_CAST
			|| op->u.cast.type==DOUBLE_TO_VAR_CAST) )
		{
			retv=BcGenerateExpression(exe,block,op->u.cast.operand);
			ty=op->u.cast.type - INT_TO_VAR_CAST;

		}
		else
		{
			retv=BcGenerateExpression(exe,block,expr->u.assign_expression.operand);
		}
	}

    BcGenerateSaveToLvalue(exe, block,expr->u.assign_expression.left,retv,ty);
	return retv;
}


Value* BcGenerateIncDecExpression(DVM_Executable *exe, Block *block,Expression *expr, ExpressionKind kind,DVM_Boolean is_toplevel)
{
    Value* v= BcGenerateExpression(exe, block, expr->u.inc_dec.operand);
	if(dkc_is_var(expr->u.inc_dec.operand->type))
	{
		builder.CreateCall(GetPush(2),v);
		builder.CreateCall(fDoInvoke,ConstInt(32,BdNFunVarInt));
		v=builder.CreateLoad(builder.CreatePointerCast(builder.CreateLoad(bretvar),Type::getInt32PtrTy(context)));
	}
	Value* retv;
    if (kind == INCREMENT_EXPRESSION) {
		retv=builder.CreateAdd(v,ConstInt(32,1));
		//BcGenerateSaveToLvalue(exe,block,expr->u.inc_dec.operand,retv,dkc_is_var(expr->u.inc_dec.operand->type));
    } else {
        DBG_assert(kind == DECREMENT_EXPRESSION, ("kind..%d\n", kind));
        retv=builder.CreateAdd(v,ConstInt(32,-1));
		//BcGenerateSaveToLvalue(exe,block,expr->u.inc_dec.operand,retv,dkc_is_var(expr->u.inc_dec.operand->type));
    }
    /*if (!is_toplevel) {
        generate_code(ob, expr->line_number, DVM_DUPLICATE);
    }*///check-me : no need for these codes?
    BcGenerateSaveToLvalue(exe, block,expr->u.inc_dec.operand, retv,dkc_is_var(expr->u.inc_dec.operand->type)?0:-1);
	return retv;
}


Value* BcGenerateCastExpression(DVM_Executable *exe, Block *block,Expression *expr)
{
	Value* v;
	if(expr->u.cast.type==FUNCTION_TO_DELEGATE_CAST)
	{
		if (expr->u.cast.operand->kind == IDENTIFIER_EXPRESSION) {
            return builder.CreateCall(fNewDelegate,ConstInt(32,expr->u.cast.operand->u.identifier.u.function.function_index));
        } else {
             //Method's delegate is generated in generate_member_expression().
            _BreakPoint;
            DBG_assert(expr->u.cast.operand->kind == MEMBER_EXPRESSION,
                       ("kind..%d", expr->u.cast.operand->kind));
            //generate_expression(exe, block, expr->u.cast.operand, ob);
        }
	}
	v=BcGenerateExpression(exe, block, expr->u.cast.operand);
    switch (expr->u.cast.type) {
    case INT_TO_DOUBLE_CAST:
		return builder.CreateSIToFP(v,Type::getDoubleTy(context));
        break;
    case DOUBLE_TO_INT_CAST:
        return builder.CreateFPToSI(v,Type::getInt32Ty(context));
        break;
    case BOOLEAN_TO_STRING_CAST:
        return builder.CreateCall(fBoolToStr,builder.CreateIntCast(v,Type::getInt32Ty(context),true));
        break;
    case INT_TO_STRING_CAST:
		return builder.CreateCall(fIntToStr,v);
        break;
    case DOUBLE_TO_STRING_CAST:
		return builder.CreateCall(fDoubleToStr,v);
        break;
	case VAR_TO_INT_CAST:
	case VAR_TO_DOUBLE_CAST:
	case VAR_TO_STRING_CAST:
		builder.CreateCall(GetPush(2),v);
		builder.CreateCall(fDoInvoke,ConstInt(32,BdNFunVarInt+(expr->u.cast.type-VAR_TO_INT_CAST)));
		return builder.CreateLoad(builder.CreateBitCast(builder.CreateLoad(bretvar),TypeSwitch[expr->u.cast.type-VAR_TO_INT_CAST]));
		break;
	case INT_TO_VAR_CAST:
	case DOUBLE_TO_VAR_CAST:
	case STRING_TO_VAR_CAST:
		builder.CreateCall(GetPush(get_opcode_type_offset(expr->u.cast.operand->type)),v);

		builder.CreateCall(fDoInvoke,ConstInt(32,BdNFunNewIntVar+(expr->u.cast.type-INT_TO_VAR_CAST)));
		return builder.CreateLoad(builder.CreateBitCast(builder.CreateLoad(bretvar),TypStack));
		break;
    case ENUM_TO_STRING_CAST:
		_BreakPoint; //fix-me : not implemented
        break;

    default:
        DBG_assert(0, ("expr->u.cast.type..%d", expr->u.cast.type));
    }
}


Value* BcGenerateArrayLiteralExpression(DVM_Executable *exe, Block *block,Expression *expr)
{
    ExpressionList *pos;
    int count;

    DBG_assert(expr->type->derive
               && expr->type->derive->tag == ARRAY_DERIVE,
               ("barray literal is not barray."));

    count = 0;
    for (pos = expr->u.array_literal; pos; pos = pos->next) {
        builder.CreateCall(GetPush(0),BcGenerateExpression(exe, block, pos->expression));
        count++;
    }
    DBG_assert(count > 0, ("empty barray literal"));
    std::vector<Value*> arg;
	arg.push_back(ConstInt(32,get_opcode_type_offset(expr->u.array_literal->expression->type)));
	arg.push_back(ConstInt(32,count));
    return builder.CreateCall(fArrayLiteral,arg);
}

extern "C" int add_type_specifier(TypeSpecifier *src, DVM_Executable *exe);
Value* BcGenerateArrayCreationExpression(DVM_Executable *exe, Block *block,Expression *expr)
{
    int index;
    TypeSpecifier type;
    ArrayDimension *dim_pos;
    int dim_count;

    index = add_type_specifier(expr->type, exe);

    DBG_assert(expr->type->derive->tag == ARRAY_DERIVE,
               ("expr->type->derive->tag..%d", expr->type->derive->tag));

    type.basic_type = expr->type->basic_type;
    type.derive = expr->type->derive;

    dim_count = 0;
    for (dim_pos = expr->u.array_creation.dimension;
         dim_pos; dim_pos = dim_pos->next) {
        if (dim_pos->expression == NULL)
            break;

        builder.CreateCall(GetPush(0),BcGenerateExpression(exe, block, dim_pos->expression));
        dim_count++;
    }
    std::vector<Value*> arg;
	arg.push_back(ConstInt(32,index));
	arg.push_back(ConstInt(32,dim_count));
	if(expr->type->derive->u.array_d.is_global)
		return builder.CreateCall(fNewGlobalArray,arg);
	else
		return builder.CreateCall(fNewArray,arg);
    //generate_code(ob, expr->line_number, DVM_NEW_ARRAY, dim_count, index);
}

Value* BcGenerateIndexExpression(DVM_Executable *exe, Block *block,Expression *expr)
{
    Value* arr;
    Value* idx;

    if (dkc_is_string(expr->u.index_expression.barray->type)) {
		arr=BcGenerateExpression(exe, block, expr->u.index_expression.barray);
		builder.CreateCall(GetPush(2),arr);
		idx=BcGenerateExpression(exe, block, expr->u.index_expression.index);
        return builder.CreateCall(fArrGetCh,idx);
    } else {
		int myty=get_opcode_type_offset(expr->type);

		arr=BcGenerateExpression(exe, block, expr->u.index_expression.barray);
		if(expr->u.index_expression.barray->kind !=IDENTIFIER_EXPRESSION) //if the array is a variable, no need to push
			builder.CreateCall(GetPush(2),arr);
		idx=BcGenerateExpression(exe, block, expr->u.index_expression.index);
		//Value* p=builder.CreatePointerCast(builder.CreateCall(GetArrAddr(),arr),TypeSwitch[get_opcode_type_offset(expr->type)]);
		//int array_cache_index=expr->u.index_expression.barray->u.identifier.u.declaration->variable_index+(expr->u.index_expression.barray->u.identifier.u.declaration->is_local)?0:2000;
		
		Value* p;
		if(expr->u.index_expression.barray->type->derive->u.array_d.is_global)
		{
			Value* obj=builder.CreateCall(GetObjrefPtr(),arr);
			int ty=get_opcode_type_offset_shared(expr->type);

			switch(ty)
			{
			case 2: //object
				p= builder.CreateCall3(SharedGetSwitch[ty],obj,idx,
					ConstInt(32,expr->type->u.class_ref.class_index));
				break;
			case 4: //array
				p= builder.CreateCall3(SharedGetSwitch[2],obj,idx,
					ConstInt(32,-1));
				break;
			default:
				p= builder.CreateCall2(SharedGetSwitch[ty],obj,idx);
			}	
		}
		else
		{
			if(block && block->unsafe)
			{
				Declaration* decl=0;///Full_arr_chk
				if(	expr->u.index_expression.barray->kind ==IDENTIFIER_EXPRESSION)
						decl=expr->u.index_expression.barray->u.identifier.u.declaration;
				if(decl)
				{
					p=builder.CreatePointerCast( builder.CreateLoad(GetArrayAddress(decl->variable_index,decl->is_local,decl->is_param)),
						TypeSwitch[myty]);

				}
				else
					p=builder.CreatePointerCast(builder.CreateCall(GetArrAddr(),arr),TypeSwitch[myty]);//*/
			}
			else
				p=builder.CreatePointerCast(builder.CreateCall2(GetArrAddrSafe(),arr,idx),TypeSwitch[myty]);
		}
		if(expr->u.index_expression.barray->kind !=IDENTIFIER_EXPRESSION)
			builder.CreateCall(GetPop(),ConstInt(32,1));
		if(expr->u.index_expression.barray->type->derive->u.array_d.is_global)
			return p;
		return builder.CreateLoad(builder.CreateInBoundsGEP(p,idx));
        //return builder.CreateCall(ArrGet[get_opcode_type_offset(expr->type)],arg);
    }
}



Value* BcGenerateMemberExpression(DVM_Executable *exe, Block *block,Expression *expr)
{
    MemberDeclaration *member;
    int method_index;

    member = expr->u.member_expression.declaration;

    if (dkc_is_array(expr->u.member_expression.expression->type)
        || dkc_is_string(expr->u.member_expression.expression->type)
        || dkc_is_var(expr->u.member_expression.expression->type)
        || member->kind == METHOD_MEMBER) {

        /*method_index = get_method_index(&expr->u.member_expression);
        Value* obj=BcGenerateExpression(exe, block,expr->u.member_expression.expression);
		builder.CreateCall(fPusho,obj);
        return ConstInt(32,method_index);*/
		_BreakPoint; //delegate for member//fix-me
    } else {
        DBG_assert(member->kind == FIELD_MEMBER,
                   ("member->u.kind..%d", member->kind));
/*		std::vector<Value*> arg;
		builder.CreateCall(GetPush(2),BcGenerateExpression(exe, block, expr->u.member_expression.expression));
		arg.push_back(ConstInt(32,member->u.field.field_index));
		return builder.CreateCall(FldGet[get_opcode_type_offset(expr->type)],arg);*/
		Value* obj=BcGenerateExpression(exe, block, expr->u.member_expression.expression);
		ExpressionKind kind=expr->u.member_expression.expression->kind;
		bool needpush=false;
		Value* ret;
		if(kind!=IDENTIFIER_EXPRESSION && kind!=MEMBER_EXPRESSION && kind!=INDEX_EXPRESSION && kind!=THIS_EXPRESSION)
		{
			needpush=true;
			builder.CreateCall(GetPush(2),obj);
		}
		if(expr->u.member_expression.expression->type->u.class_ref.class_definition->is_shared)
		{//shared var
			obj=builder.CreateCall(GetObjrefPtr(),obj);
			int ty=get_opcode_type_offset_shared(expr->type);

			switch(ty)
			{
			case 2: //object
				ret= builder.CreateCall3(SharedGetSwitch[ty],obj,ConstInt(32,member->u.field.field_index),
					ConstInt(32,expr->type->u.class_ref.class_index));
				break;
			case 4: //array
				ret= builder.CreateCall3(SharedGetSwitch[2],obj,ConstInt(32,member->u.field.field_index),
					ConstInt(32,-1));
				break;
			default:
				ret= builder.CreateCall2(SharedGetSwitch[ty],obj,ConstInt(32,member->u.field.field_index));
			}				
		}
		else
		{
			Value* fld=builder.CreateCall(GetFldAddr(),obj);
			fld=builder.CreateBitCast(builder.CreateGEP(fld,ConstInt(32,member->u.field.field_index)),TypeSwitch[get_opcode_type_offset(expr->type)]);
			ret= builder.CreateLoad(fld);
		}
		if(needpush)
			builder.CreateCall(GetPop(),ConstInt(32,1));
		return ret;
    }
}

extern "C" int count_parameter(ParameterList *src);
Value* BcGenerateNew(DVM_Executable *exe, Block *block,Expression *expr)
{

	if(expr->u.new_e.isDelegate)
	{
		return builder.CreateCall(fNewDelegate,ConstInt(32,-1));
	}
    int param_count;

    param_count = count_parameter(expr->u.new_e.method_declaration
                                  ->u.method.function_definition->parameter);
	BcGeneratePushArgument(exe, block, expr->u.new_e.argument);
	std::vector<Value*> arg;
	arg.push_back(ConstInt(32,expr->u.new_e.class_index));
	arg.push_back(ConstInt(32,expr->u.new_e.method_declaration->u.method.method_index));
	Value* v;
	if(expr->u.new_e.class_definition->is_shared)
		v=builder.CreateCall(fNewShared,arg);
	else
		v=builder.CreateCall(fNew,arg);
    return v;
    //generate_code(ob, expr->line_number, DVM_DUPLICATE_OFFSET,param_count); // check-me : wtf?


    /*generate_code(ob, expr->line_number, DVM_INVOKE);
    generate_code(ob, expr->line_number, DVM_POP);*/
}


Value* BcGenerateThisExpression(DVM_Executable *exe, Block *block,Expression *expr)
{
	return builder.CreateLoad(builder.CreateGEP(curfun->arg_begin(),ConstInt(32,curfun_param_cnt)));
}

Value* BcGenerateNull(DVM_Executable *exe, Expression *expr)
{
    return ConstantAggregateZero::get(TyObjectRef);//ConstantStruct::get(TyObjectRef,arg);
}

Value* BcGenerateSuper(DVM_Executable *exe, Block *block,Expression *expr)
{
    builder.CreateCall(GetPush(2),BcGenerateThisExpression(exe,block,expr));
	return builder.CreateCall(fGetSuper);
}




Value* BcGenerateExpression(DVM_Executable *exe,Block *current_block,Expression *expr) //fix-me : implement line-numbers
{
	Value* lv,*rv;		Value* va;
	int i;
	if(expr->kind <=15 && expr->kind >=13 )
	{
		lv=BcGenerateExpression(exe,current_block,expr->u.binary_expression.left);
		rv=BcGenerateExpression(exe,current_block,expr->u.binary_expression.right);
	}
    switch (expr->kind) {
    case BOOLEAN_EXPRESSION:
        return ConstantInt::get(context,APInt(1,expr->u.boolean_value ? 1:0));
        break;
    case INT_EXPRESSION:
		return ConstantInt::get(context,APInt(32,expr->u.int_value));
        break;
    case DOUBLE_EXPRESSION:
		return ConstantFP::get(context,APFloat(expr->u.double_value));
        break;
    case STRING_EXPRESSION:
        return BcGenerateStringExpression(exe,expr);
        break;
    case ADD_EXPRESSION:
    case SUB_EXPRESSION:
    case MUL_EXPRESSION:
    case DIV_EXPRESSION:
    case MOD_EXPRESSION:
    case EQ_EXPRESSION:
    case NE_EXPRESSION:
    case GT_EXPRESSION:
    case GE_EXPRESSION:
    case LT_EXPRESSION:
    case LE_EXPRESSION:
        return BcGenerateBinaryExpression(exe,current_block,expr);
        break;
	case LOGICAL_AND_EXPRESSION:
		lv=BcGenerateExpression(exe,current_block,expr->u.binary_expression.left);
		BasicBlock* logic_true;
		BasicBlock* logic_conti;
		//logic_true=BasicBlock::Create(context,"log_t",curfun);
		logic_true=BasicBlock::Create(context,"and_t",curfun);
		logic_conti=BasicBlock::Create(context,"and_conti",curfun);
		BasicBlock* if_f;if_f=BasicBlock::Create(context,"and_nxt",curfun,logic_true);
		BasicBlock* oldbb;oldbb=builder.GetInsertBlock();
		builder.CreateCondBr(lv,if_f,logic_conti);

		builder.SetInsertPoint(logic_true);
		builder.CreateBr(logic_conti);

		builder.SetInsertPoint(if_f);
		rv=BcGenerateExpression(exe,current_block,expr->u.binary_expression.right);
		BasicBlock* bif_f;bif_f=builder.GetInsertBlock();
		builder.CreateCondBr(rv,logic_true,logic_conti);

		builder.SetInsertPoint(logic_conti);

		logic_conti=0;
		PHINode* v;v=builder.CreatePHI(Type::getInt1Ty(context),3);
		v->addIncoming(ConstantInt::get(Type::getInt1Ty(context),APInt(1,0)),oldbb);
		v->addIncoming(ConstantInt::get(Type::getInt1Ty(context),APInt(1,1)),logic_true);
		v->addIncoming(ConstantInt::get(Type::getInt1Ty(context),APInt(1,0)),bif_f);
		return v;
		break;
    case BIT_AND_EXPRESSION:
		return builder.CreateAnd(BcBitToInt(lv),BcBitToInt(rv));
	case LOGICAL_OR_EXPRESSION:
		lv=BcGenerateExpression(exe,current_block,expr->u.binary_expression.left);
		BasicBlock* logic_false2;
		BasicBlock* logic_conti2;
		//logic_true=BasicBlock::Create(context,"log_t",curfun);
		logic_false2=BasicBlock::Create(context,"or_f",curfun);
		logic_conti2=BasicBlock::Create(context,"or_conti",curfun);
		BasicBlock* if_f2;if_f2=BasicBlock::Create(context,"or_nxt",curfun,logic_false2);
		BasicBlock* oldbb2;oldbb2=builder.GetInsertBlock();

		builder.CreateCondBr(lv,logic_conti2,if_f2);

		builder.SetInsertPoint(logic_false2);
		builder.CreateBr(logic_conti2);

		builder.SetInsertPoint(if_f2);
		rv=BcGenerateExpression(exe,current_block,expr->u.binary_expression.right);
		BasicBlock* bif_f2;bif_f2=builder.GetInsertBlock();
		builder.CreateCondBr(rv,logic_conti2,logic_false2);

		builder.SetInsertPoint(logic_conti2);

		logic_conti=0;
		PHINode* v2;v2=builder.CreatePHI(Type::getInt1Ty(context),3);
		v2->addIncoming(ConstantInt::get(Type::getInt1Ty(context),APInt(1,1)),oldbb2);
		v2->addIncoming(ConstantInt::get(Type::getInt1Ty(context),APInt(1,0)),logic_false2);
		v2->addIncoming(ConstantInt::get(Type::getInt1Ty(context),APInt(1,1)),bif_f2);
		return v2;


		break;
	case BIT_OR_EXPRESSION:

		return builder.CreateOr(BcBitToInt(lv),BcBitToInt(rv));
    case BIT_XOR_EXPRESSION:
		return builder.CreateXor(BcBitToInt(lv),BcBitToInt(rv));
    case MINUS_EXPRESSION:
        lv=BcGenerateExpression(exe, current_block, expr->u.minus_expression);
		i=get_opcode_type_offset2(expr->type);
		if(i==0)
			return builder.CreateNeg(lv);
		else if (i==1)
			return builder.CreateFNeg(lv);
		else
		{	_BreakPoint;
			return 0;
		}
        break;
	case LOGICAL_NOT_EXPRESSION://fix-me : logic op not implemented
    case BIT_NOT_EXPRESSION:
        lv=BcGenerateExpression(exe, current_block, expr->u.bit_not);
		return builder.CreateNot(lv);
        break;
    /*
    case LOGICAL_NOT_EXPRESSION:
        generate_expression(exe, current_block, expr->u.logical_not, ob);
        generate_code(ob, expr->line_number, DVM_LOGICAL_NOT);
        break;*/
    case COMMA_EXPRESSION:
        lv=BcGenerateExpression(exe, current_block, expr->u.comma.left);
        BcGenerateExpression(exe, current_block, expr->u.comma.right);
		return lv;
        break;
	//case AUTOVAR_EXPRESSION:

    case IDENTIFIER_EXPRESSION:
        return BcGenerateIdentifierExpression(exe, current_block,expr);
        break;
    case FUNCTION_CALL_EXPRESSION:
        return BcGenerateCallExpression(exe, current_block,expr);
        break;
    case ASSIGN_EXPRESSION:
        return BcGenerateAssignExpression(exe, current_block, expr, DVM_FALSE);
        break;
    case INCREMENT_EXPRESSION:  /* FALLTHRU */
    case DECREMENT_EXPRESSION:
        return BcGenerateIncDecExpression(exe, current_block, expr, expr->kind, DVM_FALSE);
        break;
    case CAST_EXPRESSION:
        return BcGenerateCastExpression(exe, current_block, expr);
        break;
    case ARRAY_LITERAL_EXPRESSION:
        return BcGenerateArrayLiteralExpression(exe, current_block, expr);
        break;
    case ARRAY_CREATION_EXPRESSION:
        return BcGenerateArrayCreationExpression(exe, current_block, expr);
        break;
    case INDEX_EXPRESSION:
        return BcGenerateIndexExpression(exe, current_block, expr);
        break;
    case MEMBER_EXPRESSION:     //fix-me : class and barray
        return BcGenerateMemberExpression(exe, current_block, expr);
        break;
    case NEW_EXPRESSION:
        return BcGenerateNew(exe, current_block, expr);
        break;
    case THIS_EXPRESSION:
        return BcGenerateThisExpression(exe, current_block, expr);
        break;
	case AUTOVAR_EXPRESSION:
		return BcGenerateAutoVar(expr,fGetVar);
		break;
    case NULL_EXPRESSION:
        return BcGenerateNull(exe, expr);
        break;

    case SUPER_EXPRESSION:
        return BcGenerateSuper(exe, current_block, expr);
        break;
    case DOWN_CAST_EXPRESSION:
		va = BcGenerateExpression(exe, current_block, expr->u.down_cast.operand);
		builder.CreateCall(GetPush(2),va);
        return builder.CreateCall(fDownCast,ConstInt(32,expr->u.down_cast.type->u.class_ref.class_index));
        break;
    case UP_CAST_EXPRESSION:
		va = BcGenerateExpression(exe, current_block, expr->u.up_cast.operand);
		builder.CreateCall(GetPush(2),va);
		return builder.CreateCall(fUpCast,ConstInt(32,expr->u.up_cast.interface_index));
        break;

    case INSTANCEOF_EXPRESSION:
		va=BcGenerateExpression(exe, current_block, expr->u.instanceof.operand);
		builder.CreateCall(GetPush(2),va);
		if(expr->u.instanceof.type->basic_type==DVM_CLASS_TYPE)
			return builder.CreateCall(fInstanceof,ConstInt(32,expr->u.instanceof.type->u.class_ref.class_index));
		else
		{
			if(expr->u.instanceof.type->basic_type==DVM_STRING_TYPE)
			{
				return builder.CreateCall2(fInstanceof2,ConstInt(32,0),ConstInt(32,0));
			}
			else if(expr->u.instanceof.type->derive)
			{
				int level=0;
				for(TypeDerive* dr=expr->u.instanceof.type->derive;dr;dr=dr->next,level++)
				{
					if(dr->tag!=ARRAY_DERIVE)
						break;
				}
				if(level)
					return builder.CreateCall2(fInstanceof2,ConstInt(32,expr->u.instanceof.type->basic_type-DVM_BOOLEAN_TYPE+1),ConstInt(32,level));
			}
			else
				DBG_assert(0, ("expr->kind..%d", expr->kind));
		}
        break;
/*    case ENUMERATOR_EXPRESSION:
        generate_int_expression(exe, expr->line_number,
                                expr->u.enumerator.enumerator->value,
                                ob);
        break;*/


    case EXPRESSION_KIND_COUNT_PLUS_1:  /* FALLTHRU */
    default:
        DBG_assert(0, ("expr->kind..%d", expr->kind));
    }
}


void BcGenerateExpressionStatement(DVM_Executable *cf, Block *block,Expression *expr)
{

    if (expr->kind == ASSIGN_EXPRESSION) {
        BcGenerateAssignExpression(cf, block, expr, DVM_TRUE);
    } else if (expr->kind == INCREMENT_EXPRESSION
               || expr->kind == DECREMENT_EXPRESSION) {
        BcGenerateIncDecExpression(cf, block, expr, expr->kind,DVM_TRUE);
    } else {
        BcGenerateExpression(cf, block, expr);
        //generate_code(ob, expr->line_number, DVM_POP);
    }
}


llvm::BasicBlock* BcGenerateBlock(DVM_Executable *cf,Block* current_block,StatementList* statement_list,llvm::BasicBlock* blk);
void BcGenerateIfStatement(DVM_Executable *exe, Block *block,Statement *statement)
{

    IfStatement *if_s = &statement->u.if_s;
    Elsif *elsif;

	BasicBlock* bt,* bf,*cont,*elt;
	bt=BasicBlock::Create(context, "if_t",curfun);
	bf=BasicBlock::Create(context, "if_f",curfun);
	cont=BasicBlock::Create(context, "cont",curfun);
    Value* v=BcGenerateExpression(exe, block, if_s->condition);

	if(v->getType()->isIntegerTy(32))
		v=builder.CreateIntCast(v,Type::getInt1Ty(context),true);

	builder.CreateCondBr(v,bt,bf);

	SwitchBlock(bt);
    BcGenerateBlock(exe, if_s->then_block,if_s->then_block->statement_list,bt);
	SafeBr(bt,cont);


	int i=0;char buf[10];

    for (elsif = if_s->elsif_list; elsif; elsif = elsif->next) {
		SwitchBlock(bf);
		i++;sprintf_s(buf,10,"%d",i);
		elt=BasicBlock::Create(context, StringRef("else_t")+buf,curfun,cont);
		bf=BasicBlock::Create(context, StringRef("else_f")+buf,curfun,cont); //for the next elsif
        v=BcGenerateExpression(exe, block, elsif->condition);
        builder.CreateCondBr(v,elt,bf);
		SwitchBlock(elt);
        BcGenerateBlock(exe, elsif->block,elsif->block->statement_list,elt);
		SafeBr(elt,cont);
    }
    if (if_s->else_block) {
		SwitchBlock(bf);
        BcGenerateBlock(exe, if_s->else_block,if_s->else_block->statement_list,bf);
		SafeBr(bf,cont);
    }
	else
	{
		SwitchBlock(bf);
		builder.CreateBr(cont);
	}
	SwitchBlock(cont);
	return ;
}

void BcGenerateReturnStatement(DVM_Executable *exe, Block *block,Statement *statement)
{
    DKC_Compiler *compiler = dkc_get_current_compiler();
    Block       *block_p;

    DBG_assert(statement->u.return_s.return_value != NULL,
               ("return value is null."));

    for (block_p = block; block_p; block_p = block_p->outer_block) {
        if (block_p->type == TRY_CLAUSE_BLOCK
            || block_p->type == CATCH_CLAUSE_BLOCK) {
            builder.CreateCall(fLeaveTry); //fix-me : finally
        }
    }
    Value* v=BcGenerateExpression(exe, block, statement->u.return_s.return_value);
	const DebugLoc& dl= DebugLoc::get(statement->line_number,0,currentdifunc);
	Instruction* inst=builder.CreateLoad(bretvar);
	inst->setDebugLoc(dl);

	//printf("%d",v->getType()->getTypeID());
	inst=builder.CreateStore(v,builder.CreateBitCast(inst,v->getType()->getPointerTo()));
	//dl=DebugLoc::get(statement->line_number,0,currentfile);
	inst->setDebugLoc(dl);
	//dl=&DebugLoc::get(statement->line_number,0,currentfile);
	builder.CreateRetVoid()->setDebugLoc(dl);
	//BasicBlock* bcon=BasicBlock::Create(context,"dummy",curfun);
	//SwitchBlock(bcon);
	//generate_code(ob, statement->line_number, DVM_RETURN);
}


void BcGenerateInitializer(DVM_Executable *exe, Block *block,Statement *statement)
{
    Declaration *decl = statement->u.declaration_s;
    if (decl->initializer == NULL)
        return;

    Value* v=BcGenerateExpression(exe, block, decl->initializer);
    BcGenerateSaveToIdentifier(decl,v, statement->line_number,-1);
}




void BcGenerateTryStatement(DVM_Executable *exe, Block *block,Statement *statement,llvm::BasicBlock* blk)
{
    TryStatement *try_s = &statement->u.try_s;
    CatchClause *catch_pos;
    DVM_Try dvm_try;
    int catch_count = 0;
    int catch_index;
    DVM_CatchClause *dvm_catch;
    int after_finally_label;
    int finally_label_backup;

    for (catch_pos = try_s->catch_clause; catch_pos;
         catch_pos = catch_pos->next) {
        catch_count++;
    }

	Function*  curf=curfun;
	FunctionType* FT8 = FunctionType::get(Type::getVoidTy(context), true);
	//Function* fret=Function::Create(FT8, Function::ExternalLinkage ,"", module);
	BasicBlock *btry = BasicBlock::Create(context,"try",curfun);
//	BasicBlock *bexc = BasicBlock::Create(context,"exception",curfun);
	BasicBlock *bnor = BasicBlock::Create(context,"normal",curfun);

	BasicBlock *bfin = BasicBlock::Create(context,"finally",curfun);
	BasicBlock *bfail = BasicBlock::Create(context,"fail",curfun);
	BasicBlock *bcont = BasicBlock::Create(context,"conti",curfun);//fix-me : may be improved
	BasicBlock *bcatch;

	Value* pbsp=builder.CreateLoad(bsp);
	Value* oldsp=builder.CreateLoad(pbsp);

	Value* pIsNor=builder.CreateAlloca(Type::getInt1Ty(context) );
	builder.CreateStore(ConstantInt::get(Type::getInt1Ty(context),APInt(1,0)),pIsNor);
	Value* pitem=builder.CreateCall(fPushException);
	Value* vindex=builder.CreateCall(fSetjmp,pitem);
	llvm::SwitchInst* sw= builder.CreateSwitch(vindex,bfail,catch_count+1);
	sw->addCase((ConstantInt*)zero,btry);
	sw->setDefaultDest(bfin);
	//builder.CreateBr(btry);

    for (catch_pos = try_s->catch_clause, catch_index = 0;
         catch_pos;
         catch_pos = catch_pos->next, catch_index++) {
        //dvm_catch[catch_index].class_index = catch_pos->type->u.class_ref.class_index;
		bcatch=BasicBlock::Create(context,StringRef("catch"),curfun,bnor);
		sw->addCase((ConstantInt*)ConstInt(32,catch_pos->type->u.class_ref.class_index+1),bcatch);
		SwitchBlock(bcatch);
		Value* excep=builder.CreateLoad(builder.CreateLoad(beo));
        BcGenerateSaveToIdentifier(catch_pos->variable_declaration,excep,catch_pos->line_number,-1);
        BcGenerateBlock(exe, catch_pos->block,catch_pos->block->statement_list, bcatch);
		if(bcatch->getInstList().empty() || !bcatch->getInstList().back().isTerminator())
		{
			builder.CreateStore(oldsp,pbsp);
			builder.CreateBr(bnor);
		}

    }



	SwitchBlock(btry);
	isInTry=1;
    BcGenerateBlock(exe, try_s->try_block,
                            try_s->try_block->statement_list, btry);
	if(btry->getInstList().empty() || !btry->getInstList().back().isTerminator())
	{
		builder.CreateCall(fLeaveTry);
		builder.CreateBr(bnor);
	}
	isInTry=0;

	SwitchBlock(bnor);
	builder.CreateStore(ConstantInt::get(Type::getInt1Ty(context),APInt(1,1)),pIsNor);
	builder.CreateBr(bfin);

	SwitchBlock(bfin);
    if (try_s->finally_block) {
        BcGenerateBlock(exe, try_s->finally_block, try_s->finally_block->statement_list,bnor);
    }
	if(bfin->getInstList().empty() || !bfin->getInstList().back().isTerminator())
		builder.CreateCondBr(builder.CreateLoad(pIsNor),bcont,bfail);

	SwitchBlock(bfail);
	builder.CreateCall(fReraise);
	builder.CreateRetVoid();
	//builder.CreateUnreachable();

	SwitchBlock(bcont);

}

void BcGenerateThrowStatement(DVM_Executable *exe, Block *block,Statement *statement)
{
	Value* v;
    if (statement->u.throw_s.exception) {
        v = BcGenerateExpression(exe, block, statement->u.throw_s.exception);
		builder.CreateStore(zero,builder.CreateLoad(bei));
		builder.CreateStore(v,builder.CreateLoad(beo));
		builder.CreateCall (fRaise,ConstInt(32,statement->u.throw_s.exception->type->u.class_ref.class_index+1));
        //generate_code(ob, statement->line_number, DVM_THROW);
    } else {
        //generate_identifier(statement->u.throw_s.variable_declaration, ob,
        //                    statement->line_number);
        //generate_code(ob, statement->line_number, DVM_RETHROW);
		_BreakPoint;
    }
}


void BcGenerateSwitchStatement(DVM_Executable *exe, Block *block,
                          Statement *statement)
{
    SwitchStatement *switch_s = &statement->u.switch_s;
    CaseList *case_pos;
    ExpressionList *expr_pos;
    int offset;
    int case_start_label;
    int next_case_label;
    int end_label;
    int line_number;
	int cnt=0;
	for (case_pos = switch_s->case_list; case_pos;case_pos = case_pos->next)
	{
		cnt++;
	}
    Value* v=BcGenerateExpression(exe, block, switch_s->expression);
	BasicBlock* bb=BasicBlock::Create(context,"default",curfun);
	BasicBlock* bcon=BasicBlock::Create(context,"conti",curfun);
    SwitchInst* sw=builder.CreateSwitch(v,bb,cnt,0);

    for (case_pos = switch_s->case_list; case_pos;case_pos = case_pos->next)
	{
		BasicBlock* cas=BasicBlock::Create(context,"",curfun,bb);
        for (expr_pos = case_pos->expression_list; expr_pos;expr_pos = expr_pos->next)
		{
			sw->addCase((ConstantInt*)BcGenerateExpression(exe, block, expr_pos->expression),cas); //fix-me : string/obj support
            line_number = expr_pos->expression->line_number;
        }
        SwitchBlock(cas);
        BcGenerateBlock(exe, case_pos->block,case_pos->block->statement_list, cas);
        SafeBr(cas,bcon);
    }
    SwitchBlock(bb);
    if (switch_s->default_block) {
        BcGenerateBlock(exe, switch_s->default_block,switch_s->default_block->statement_list, bb);
    }
	SafeBr(bb,bcon);
    SwitchBlock(bcon);
}

void BcGenerateForStatement(DVM_Executable *exe, Block *block,Statement *statement,BasicBlock* blk)
{
    int loop_label;
    ForStatement *for_s = &statement->u.for_s;
	BasicBlock* bcond=BasicBlock::Create(context,"cond",curfun);
	BasicBlock* bb=BasicBlock::Create(context,"for",curfun);
	BasicBlock* bpost=BasicBlock::Create(context,"post",curfun);
	BasicBlock* bcon=BasicBlock::Create(context,"conti",curfun);


	BasicBlock* oldcontiblk=contiblock;
	BasicBlock* oldloopblk=loopblock;
	contiblock = bcon;
	loopblock = bpost;
    if (for_s->init) {
        BcGenerateExpressionStatement(exe, block, for_s->init);
    }

	builder.CreateBr(bcond);
	SwitchBlock(bcond);

		//for_s->block->parent.statement.break_label = get_label(ob);
    //for_s->block->parent.statement.continue_label = get_label(ob);
	Value* cond;
    if (for_s->condition) {

        cond = BcGenerateExpression(exe, block, for_s->condition);
        builder.CreateCondBr(cond,bb,bcon);
    }
	else
	{
		builder.CreateBr(bb);		//still writing the old block
	}

	SwitchBlock(bb);
    BcGenerateBlock(exe, for_s->block, for_s->block->statement_list,blk);
    //set_label(ob, for_s->block->parent.statement.continue_label);
	SafeBr(bb,bpost);

	SwitchBlock(bpost);
    if (for_s->post) {
        BcGenerateExpressionStatement(exe, block, for_s->post);
    }
	builder.CreateBr(bcond);

	SwitchBlock(bcon);

	contiblock=oldcontiblk;
	loopblock=oldloopblk;
    //set_label(ob, for_s->block->parent.statement.break_label);
}




void BcGenerateBreak(DVM_Executable *exe, Block *block,Statement *statement)
{
    BreakStatement *break_s = &statement->u.break_s;
    Block       *block_p;
    DVM_Boolean finally_flag = DVM_FALSE;

    for (block_p = block; block_p; block_p = block_p->outer_block) {
        if (block_p->type == TRY_CLAUSE_BLOCK
            || block_p->type == CATCH_CLAUSE_BLOCK) {
            finally_flag = DVM_TRUE;
        }
        if (block_p->type != WHILE_STATEMENT_BLOCK
            && block_p->type != FOR_STATEMENT_BLOCK
            && block_p->type != DO_WHILE_STATEMENT_BLOCK)
            continue;

        if (break_s->label == NULL) {
            break;
        }

        if (block_p->type == WHILE_STATEMENT_BLOCK) {
            if (block_p->parent.statement.statement->u.while_s.label == NULL)
                continue;

            if (!strcmp(break_s->label,
                        block_p->parent.statement.statement
                        ->u.while_s.label)) {
                break;
            }
        } else if (block_p->type == FOR_STATEMENT_BLOCK) {
            if (block_p->parent.statement.statement->u.for_s.label == NULL)
                continue;

            if (!strcmp(break_s->label,
                        block_p->parent.statement.statement
                        ->u.for_s.label)) {
                break;
            }
        } else if (block_p->type == DO_WHILE_STATEMENT_BLOCK) {
            if (block_p->parent.statement.statement->u.do_while_s.label
                == NULL)
                continue;

            if (!strcmp(break_s->label,
                        block_p->parent.statement.statement
                        ->u.do_while_s.label)) {
                break;
            }
        }
    }
    if (block_p == NULL) {
        dkc_compile_error(statement->line_number,
                          LABEL_NOT_FOUND_ERR,
                          STRING_MESSAGE_ARGUMENT, "label", break_s->label,
                          MESSAGE_ARGUMENT_END);
    }

    if (finally_flag) {
		builder.CreateCall(fLeaveTry);
        //fix-me : goto finally?//SafeBr(0,finallyblock);
    }
    SafeBr(0,contiblock);

}


void BcGenerateContinue(DVM_Executable *exe, Block *block,Statement *statement)
{
    ContinueStatement *continue_s = &statement->u.continue_s;
    Block       *block_p;
    DVM_Boolean finally_flag = DVM_FALSE;

    for (block_p = block; block_p; block_p = block_p->outer_block) {
        if (block_p->type == TRY_CLAUSE_BLOCK
            || block_p->type == CATCH_CLAUSE_BLOCK) {
            finally_flag = DVM_TRUE;
        }
        if (block_p->type != WHILE_STATEMENT_BLOCK
            && block_p->type != FOR_STATEMENT_BLOCK
            && block_p->type != DO_WHILE_STATEMENT_BLOCK)
            continue;

        if (continue_s->label == NULL) {
            break;
        }

        if (block_p->type == WHILE_STATEMENT_BLOCK) {
            if (block_p->parent.statement.statement->u.while_s.label == NULL)
                continue;

            if (!strcmp(continue_s->label,
                        block_p->parent.statement.statement
                        ->u.while_s.label)) {
                break;
            }
        } else if (block_p->type == FOR_STATEMENT_BLOCK) {
            if (block_p->parent.statement.statement->u.for_s.label == NULL)
                continue;

            if (!strcmp(continue_s->label,
                        block_p->parent.statement.statement
                        ->u.for_s.label)) {
                break;
            }
        } else if (block_p->type == DO_WHILE_STATEMENT_BLOCK) {
            if (block_p->parent.statement.statement->u.do_while_s.label
                == NULL)
                continue;

            if (!strcmp(continue_s->label,
                        block_p->parent.statement.statement
                        ->u.do_while_s.label)) {
                break;
            }
        }
    }
    if (block_p == NULL) {
        dkc_compile_error(statement->line_number,
                          LABEL_NOT_FOUND_ERR,
                          STRING_MESSAGE_ARGUMENT, "label", continue_s->label,
                          MESSAGE_ARGUMENT_END);
    }
    if (finally_flag) {
		builder.CreateCall(fLeaveTry); //check-me : need?
        //fix-me : goto finally?//SafeBr(0,finallyblock);
    }
    SafeBr(0,loopblock);
}


llvm::BasicBlock* BcGenerateBlock(DVM_Executable *cf,Block* current_block,StatementList* statement_list,llvm::BasicBlock* blk)
{
	StatementList *pos;
    for (pos = statement_list; pos; pos = pos->next) {
        switch (pos->statement->type) {
        case EXPRESSION_STATEMENT:
            BcGenerateExpressionStatement(cf, current_block,
                                          pos->statement->u.expression_s);
            break;
		case RETURN_STATEMENT:
            BcGenerateReturnStatement(cf, current_block, pos->statement);
            break;
        case DECLARATION_STATEMENT:
            BcGenerateInitializer(cf, current_block,pos->statement);
            break;
        case IF_STATEMENT:
            BcGenerateIfStatement(cf, current_block, pos->statement);
            break;
        case TRY_STATEMENT:
            BcGenerateTryStatement(cf, current_block, pos->statement, blk);
            break;
        case THROW_STATEMENT:
            BcGenerateThrowStatement(cf, current_block, pos->statement);
            break;
        case SWITCH_STATEMENT:
            BcGenerateSwitchStatement(cf, current_block, pos->statement);
            break;
        case FOR_STATEMENT:
            BcGenerateForStatement(cf, current_block, pos->statement, blk);
            break;
        case BREAK_STATEMENT:
            BcGenerateBreak(cf, current_block, pos->statement);
            break;
        case CONTINUE_STATEMENT:
            BcGenerateContinue(cf, current_block,pos->statement);
            break;
 /*       case WHILE_STATEMENT:
            generate_while_statement(exe, current_block, pos->statement, ob);
            break;

        case DO_WHILE_STATEMENT:
            generate_do_while_statement(exe, current_block,
                                        pos->statement, ob);
            break;
        case FOREACH_STATEMENT:
            break;



	*/
        case STATEMENT_TYPE_COUNT_PLUS_1: /* FALLTHRU */
        default:
            DBG_assert(0, ("pos->statement->type..", pos->statement->type));
        }
    }
	return blk;
}

llvm::Function* BcGenerateFunctionEx(DVM_Executable *exe, char* name,Block* block,StatementList* statement_list,int needret,char* clsname,int local_var_cnt,int line)
{
	bparameters.clear();
	bparameters.resize(local_var_cnt+1);
	bstatic.clear();
	bstatic.resize(100); //fix-me : get the number of static
	barrays.clear();
	cached_mid=NULL;
	//block->parent
	//bparameters.shrink_to_fit();
	Function *retf = Function::Create(FT, Function::ExternalLinkage,name, module);

	currentdifunc=dibuilder->createFunction(currentfile,name,StringRef(),currentfile,line,//fdsdfsdfasdfadsf
		dibuilder->createSubroutineType(currentfile,DIArray())
		,true,true,line,DIDescriptor::FlagPrototyped,false,retf);
	curfun=retf;
	BasicBlock *BB = BasicBlock::Create(context, "",retf);
	SwitchBlock(BB);

	IP=BB->begin();
	//dbgloc=&builder.getCurrentDebugLocation();
	mainblock=BB;

	if(clsname)
	{
		Function* f=module->getFunction(std::string(clsname)+"!init");
		if(!f)
			DBG_panic(("Couldn't find %s's init function\n",clsname));
		builder.CreateCall(f);
	}
	BcGenerateBlock(exe,block,statement_list,BB);
	if(needret)
		builder.CreateRetVoid();

	cached_mid=NULL;
	return retf;
}


llvm::Function* BcGenerateFunction(DVM_Executable *exe, FunctionDefinition * src,char* clsname)
{
	char buf[512];
	curfun_param_cnt=src->param_cnt;
	if(clsname)
	{
		if(sprintf_s(buf,512,"%s#%s",clsname,src->name )==-1)
			DBG_panic(("Function name too long"));
		if(stricmp(src->name,"initialize"))
			clsname=0;
		return BcGenerateFunctionEx(exe,buf,src->block,src->block->statement_list,0,clsname,src->local_variable_count,src->end_line_number);
	}
	else
	{
		return BcGenerateFunctionEx(exe,src->name ,src->block,src->block->statement_list,0,0,src->local_variable_count,src->end_line_number);
	}
}


extern "C" void BcGenerateFieldInitializer(DVM_Executable *exe,ClassDefinition *cd, DVM_Class *dvm_class)
{
 	FunctionType* FT8 = FunctionType::get(Type::getVoidTy(context), true);
	Function* fret=Function::Create(FT8, Function::LinkOnceAnyLinkage,StringRef(cd->name)+"!init", module);
	BasicBlock *BB = BasicBlock::Create(context,"",fret);
	SwitchBlock(BB);

    ClassDefinition *cd_pos;
    MemberDeclaration *member_pos;
	Value* v,*ths;
    for (cd_pos = cd; cd_pos; cd_pos = cd_pos->super_class) {
        for (member_pos = cd_pos->member; member_pos;
             member_pos = member_pos->next) {
            if (member_pos->kind != FIELD_MEMBER)
                continue;

            if (member_pos->u.field.initializer) {
/*				std::vector<Value*>arg;
				builder.CreateCall(GetPush(2),(builder.CreateLoad(pthis)));
				arg.push_back(ConstInt(32,member_pos->u.field.field_index));
				arg.push_back(BcGenerateExpression(exe, NULL, member_pos->u.field.initializer));
                builder.CreateCall(FldPut[get_opcode_type_offset(member_pos->u.field.type)],arg);*/
				int mty=get_opcode_type_offset(member_pos->u.field.type); //fix-me : code size optmization here
				Value* vv=BcGenerateExpression(exe, NULL, member_pos->u.field.initializer);
				Value* obj=BcGenerateThisExpression(exe,NULL,NULL);
				Value* fld=builder.CreateCall(GetFldAddr(),obj);
				fld=builder.CreateBitCast(builder.CreateGEP(fld,ConstInt(32,member_pos->u.field.field_index)),TypeSwitch[mty]);
				builder.CreateStore(vv,fld);
            }
        }
    }
	builder.CreateRetVoid();
    //copy_opcode_buf(&dvm_class->field_initializer, &ob);
}

