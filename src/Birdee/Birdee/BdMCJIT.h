#ifndef _H_BIRDEE_BCMCJIT
#define _H_BIRDEE_BCMCJIT
#include "BirdeeDef.h"

#include "llvm/IR/LegacyPassManager.h"
#include "llvm/ExecutionEngine/ExecutionEngine.h"
#include "llvm/ExecutionEngine/MCJIT.h"
#include "llvm/ExecutionEngine/ObjectCache.h"
#include "llvm/ExecutionEngine/SectionMemoryManager.h"
#include "llvm/IR/DataLayout.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"

#include "llvm/IRReader/IRReader.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/Path.h"
#include "llvm/Support/SourceMgr.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Transforms/Scalar.h"
#include <cctype>
#include <cstdio>
#include <map>
#include <string>
#include <vector>

using namespace llvm;

//===----------------------------------------------------------------------===//
// Helper class for execution engine abstraction
//===----------------------------------------------------------------------===//

class BaseHelper
{
public:
  BaseHelper() {}
  virtual ~BaseHelper() {}

  virtual Function *getFunction(const std::string FnName) = 0;
  //virtual Module *getModuleForNewFunction() = 0;
  virtual void *getPointerToFunction(Function* F) = 0;
  virtual void *getPointerToNamedFunction(const std::string &Name) = 0;
  virtual void closeCurrentModule() = 0;
  virtual void runFPM(Function &F) = 0;
  //virtual void dump();
};
class MCJITHelper;
class HelpingMemoryManager : public SectionMemoryManager
{
  HelpingMemoryManager(const HelpingMemoryManager&) LLVM_DELETED_FUNCTION;
  void operator=(const HelpingMemoryManager&) LLVM_DELETED_FUNCTION;

public:
  HelpingMemoryManager(MCJITHelper *Helper,Module* M) : MasterHelper(Helper),Mod(M) {}
  virtual ~HelpingMemoryManager() {}

  /// This method returns the address of the specified function.
  /// Our implementation will attempt to find functions in other
  /// modules associated with the MCJITHelper to cross link functions
  /// from one generated module to another.
  ///
  /// If \p AbortOnFailure is false and no function with the given name is
  /// found, this function returns a null pointer. Otherwise, it prints a
  /// message to stderr and aborts.
  virtual void *getPointerToNamedFunction(const std::string &Name,
                                          bool AbortOnFailure = true);

  virtual uint64_t getSymbolAddress(const std::string &Name);
private:
	Module* Mod;
  MCJITHelper *MasterHelper;
};

class MCJITHelper //: public BaseHelper
{
public:

  MCJITHelper(Module* M,bool useMCJIT) : mUseMC(useMCJIT), CurrentModule(NULL),OurFPM(NULL) {

  }
  ~MCJITHelper();
	ExecutionEngine* getEngine(Module* m)
	{
		return this->EngineMap[m];
	}
  Function *getFunction(const std::string FnName);
  //Module *getModuleForNewFunction();
  void *getPointerToFunction(Function* F);
  void *getPointerToNamedFunction(const std::string &Name);
  void *getPointerToGlobalVariable(const std::string &Name,Module *const m);
  void *getPointerToNamedFunctionForModule(const std::string &Name,Module *const m);
  void closeCurrentModule();
  virtual void runFPM(Function &F) {} // Not needed, see compileModule
  void dump();
  void addGlobalMapping(const std::string& Name,void*);
  llvm::legacy::PassManager* getPassManager(Module* M);

  ExecutionEngine *compileModule(Module *M);
  typedef std::vector<Module*> ModuleVector;
  ModuleVector  Modules;
  std::map<Module *, ExecutionEngine *> EngineMap;
private:
  llvm::legacy::PassManager* OurFPM;
  bool mUseMC;
 // MCJITObjectCache OurObjectCache;
  ExecutionEngine* EE;
  //LLVMContext  &Context;

  std::map<std::string, void *> GlobalMap;


  Module       *CurrentModule;
};




#endif
