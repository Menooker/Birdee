#include "BdMCJIT.h"
#include "BdParameters.h"

#include "llvm/Analysis/Passes.h"
#include "llvm/Analysis/Verifier.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/PassManager.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
using namespace llvm;

//===----------------------------------------------------------------------===//
// Quick and dirty hack
//===----------------------------------------------------------------------===//

// FIXME: Obviously we can do better than this
std::string GenerateUniqueName(const char *root)
{
  static int i = 0;
  char s[16];
  sprintf(s, "%s%d", root, i++);
  std::string S = s;
  return S;
}


/*
//===----------------------------------------------------------------------===//
// MCJIT object cache class
//===----------------------------------------------------------------------===//

class MCJITObjectCache : public ObjectCache {
public:
  MCJITObjectCache() {
    // Set IR cache directory
    sys::fs::current_path(CacheDir);
    sys::path::append(CacheDir, "toy_object_cache");
  }

  virtual ~MCJITObjectCache() {
  }

  virtual void notifyObjectCompiled(const Module *M, const MemoryBuffer *Obj) {
    // Get the ModuleID
    const std::string ModuleID = M->getModuleIdentifier();

    // If we've flagged this as an IR file, cache it
    if (0 == ModuleID.compare(0, 3, "IR:")) {
      std::string IRFileName = ModuleID.substr(3);
      SmallString<128>IRCacheFile = CacheDir;
      sys::path::append(IRCacheFile, IRFileName);
      if (!sys::fs::exists(CacheDir.str()) && sys::fs::create_directory(CacheDir.str())) {
        fprintf(stderr, "Unable to create cache directory\n");
        return;
      }
      std::string ErrStr;
      raw_fd_ostream IRObjectFile(IRCacheFile.c_str(), ErrStr, raw_fd_ostream::F_Binary);
      IRObjectFile << Obj->getBuffer();
    }
  }

  // MCJIT will call this function before compiling any module
  // MCJIT takes ownership of both the MemoryBuffer object and the memory
  // to which it refers.
  virtual MemoryBuffer* getObject(const Module* M) {
    // Get the ModuleID
    const std::string ModuleID = M->getModuleIdentifier();

    // If we've flagged this as an IR file, cache it
    if (0 == ModuleID.compare(0, 3, "IR:")) {
      std::string IRFileName = ModuleID.substr(3);
      SmallString<128> IRCacheFile = CacheDir;
      sys::path::append(IRCacheFile, IRFileName);
      if (!sys::fs::exists(IRCacheFile.str())) {
        // This file isn't in our cache
        return NULL;
      }
      std::unique_ptr<MemoryBuffer> IRObjectBuffer;
      MemoryBuffer::getFile(IRCacheFile.c_str(), IRObjectBuffer, -1, false);
      // MCJIT will want to write into this buffer, and we don't want that
      // because the file has probably just been mmapped.  Instead we make
      // a copy.  The filed-based buffer will be released when it goes
      // out of scope.
      return MemoryBuffer::getMemBufferCopy(IRObjectBuffer->getBuffer());
    }

    return NULL;
  }

private:
  SmallString<128> CacheDir;
};

*/



//===----------------------------------------------------------------------===//
// MCJIT helper class
//===----------------------------------------------------------------------===//


uint64_t HelpingMemoryManager::getSymbolAddress(const std::string &Name)
{
	return (uint64_t)getPointerToNamedFunction(Name,true);
}
void *HelpingMemoryManager::getPointerToNamedFunction(const std::string &Name,
                                        bool AbortOnFailure)
{

  // Try the standard symbol resolution first, but ask it not to abort.
  void *pfn = (void*)RTDyldMemoryManager::getSymbolAddress(Name);
  if (pfn)
    return pfn;
  pfn=MasterHelper->getPointerToGlobalVariable(Name,Mod);
  if(pfn)
	  return pfn;

  pfn = MasterHelper->getPointerToNamedFunctionForModule(Name,Mod);
  if (!pfn && AbortOnFailure)
    report_fatal_error("Program used external function '" + Name +
                        "' which could not be resolved!");
  return pfn;
}

MCJITHelper::~MCJITHelper()
{
  // Walk the vector of modules.
  ModuleVector::iterator it, end;
  for (it = Modules.begin(), end = Modules.end();
       it != end; ++it) {
    // See if we have an execution engine for this module.
    std::map<Module*, ExecutionEngine*>::iterator mapIt = EngineMap.find(*it);
    // If we have an EE, the EE owns the module so just delete the EE.
    if (mapIt != EngineMap.end()) {
      delete mapIt->second;
    } else {
      // Otherwise, we still own the module.  Delete it now.
      delete *it;
    }
  }
  //delete EE;
}


void OptimizeMod(ExecutionEngine * EE,Module* M)
{
	llvm::legacy::FunctionPassManager *FPM = 0;

	// Create a FPM for this module
	FPM = new llvm::legacy::FunctionPassManager(M);

	// Set up the optimizer pipeline.  Start with registering info about how the
	// target lays out data structures.
	FPM->add(new DataLayout(*EE->getDataLayout()));
	// Provide basic AliasAnalysis support for GVN.
	FPM->add(createBasicAliasAnalysisPass());
	// Promote allocas to registers.
	FPM->add(createPromoteMemoryToRegisterPass());
	// Do simple "peephole" optimizations and bit-twiddling optzns.
	//FPM->add(createInstructionCombiningPass());
	// Reassociate expressions.
	FPM->add(createReassociatePass());
	// Eliminate Common SubExpressions.
	FPM->add(createGVNPass());
	// Simplify the control flow graph (deleting unreachable blocks, etc).
	FPM->add(createCFGSimplificationPass());

	FPM->doInitialization();

	// For each function in the module
	Module::iterator it;
	Module::iterator end = M->end();
	for (it = M->begin(); it != end; ++it) {
		// Run the FPM on this function
		FPM->run(*it);
	}

	delete FPM;
  //}

  EE->finalizeObject();

}


Function *MCJITHelper::getFunction(const std::string FnName)
{
  ModuleVector::iterator begin = Modules.begin();
  ModuleVector::iterator end = Modules.end();
  ModuleVector::iterator it;
  for (it = begin; it != end; ++it) {
    Function *F = (*it)->getFunction(FnName);
    if (F) {
      if (*it == CurrentModule)
          return F;

      assert(CurrentModule != NULL);

      // This function is in a module that has already been JITed.
      // We just need a prototype for external linkage.
      Function *PF = CurrentModule->getFunction(FnName);
      if (PF && !PF->empty()) {
        //Error("redefinition of function across modules");
        _BreakPoint
		  return 0;
      }

      // If we don't have a prototype yet, create one.
      if (!PF)
        PF = Function::Create(F->getFunctionType(),
                                      Function::ExternalLinkage,
                                      FnName,
                                      CurrentModule);
      return PF;
    }
  }
  return NULL;
}
/*
Module *MCJITHelper::getModuleForNewFunction() {
  // If we have a Module that hasn't been JITed, use that.
  if (CurrentModule)
    return CurrentModule;

  // Otherwise create a new Module.
  std::string ModName = GenerateUniqueName("mcjit_module_");
  Module *M = new Module(ModName, Context);
  Modules.push_back(M);
  CurrentModule = M;

  return M;
}
*/

void MCJITHelper::addGlobalMapping(const std::string& Name,void* p)
{
	if(mUseMC)
	{
		GlobalMap[Name]=p;
	}
}

ExecutionEngine *MCJITHelper::compileModule(Module *M) {



  std::string ErrStr;
  EngineBuilder eb(M);
  TargetMachine* tm=eb.selectTarget();
  tm->setMCUseDwarfDirectory(true);
  tm->setMCUseLoc(true);
  tm->Options.NoFramePointerElim=1;
  tm->setOptLevel((CodeGenOpt::Level)(CodeGenOpt::None+parameters.optmization));
  eb.setUseMCJIT(this->mUseMC)
    .setErrorStr(&ErrStr)
	.setOptLevel((CodeGenOpt::Level)(CodeGenOpt::None+parameters.optmization));



  if(mUseMC)
  {
		eb.setMCJITMemoryManager(new HelpingMemoryManager(this,M));
  }

  ExecutionEngine *NewEngine =eb.create();

  if (!NewEngine) {
    fprintf(stderr, "Could not create ExecutionEngine: %s\n", ErrStr.c_str());
    exit(1);
  }




  // Store this engine
  EngineMap[M] = NewEngine;
  Modules.push_back(M);
  return NewEngine;
}



void *MCJITHelper::getPointerToFunction(Function* F)
{
	std::map<Module*, ExecutionEngine*>::iterator eeIt = EngineMap.find(F->getParent());
	if (eeIt != EngineMap.end()) {
		void *P = eeIt->second->getPointerToFunction(F);
		if (P)
			return P;
	}

	return NULL;
}
/*
{

  // Look for this function in an existing module
  ModuleVector::iterator begin = Modules.begin();
  ModuleVector::iterator end = Modules.end();
  ModuleVector::iterator it;
  std::string FnName = F->getName();
  for (it = begin; it != end; ++it) {
    Function *MF = (*it)->getFunction(FnName);
    if (MF == F) {
      std::map<Module*, ExecutionEngine*>::iterator eeIt = EngineMap.find(*it);
      if (eeIt != EngineMap.end()) {
        void *P = eeIt->second->getPointerToFunction(F);
        if (P)
          return P;
      } else {
        ExecutionEngine *EE = compileModule(*it);
        void *P = EE->getPointerToFunction(F);
        if (P)
          return P;
      }
    }
  }
  return NULL;
}*/

void MCJITHelper::closeCurrentModule() {
    // If we have an open module (and we should), pack it up
  if (CurrentModule) {
    CurrentModule = NULL;
  }
}

void *MCJITHelper::getPointerToGlobalVariable(const std::string &Name,Module *const m)
{
	std::map<Module*, ExecutionEngine*>::iterator eeIt = EngineMap.find(m);
	if(eeIt==EngineMap.end())
	{
		return NULL;
	}
	const GlobalVariable* v=m->getGlobalVariable(Name);
	void* P;
	if(v)
	{
		P=(void*)eeIt->second->getPointerToGlobal(v);
		if(P)
			return P;
	}
	return NULL;
}


void *MCJITHelper::getPointerToNamedFunctionForModule(const std::string &Name,Module *const m)
{
	if(GlobalMap.find(Name)!=GlobalMap.end())
	{
		return GlobalMap[Name];
	}

    Function *F = m->getFunction(Name);
	std::map<Module*, ExecutionEngine*>::iterator eeIt = EngineMap.find(m);
	void* P;
    if (F && !F->empty() ) {

      if (eeIt != EngineMap.end()) {

        P = eeIt->second->getPointerToFunction(F);
        if (P)
          return P;

      }
	}

	return NULL;
}

void *MCJITHelper::getPointerToNamedFunction(const std::string &Name)
{
	if(GlobalMap.find(Name)!=GlobalMap.end())
	{
		return GlobalMap[Name];
	}
  // Look for the functions in our modules, compiling only as necessary
  ModuleVector::iterator begin = Modules.begin();
  ModuleVector::iterator end = Modules.end();
  ModuleVector::iterator it;
  for (it = begin; it != end; ++it) {
    Function *F = (*it)->getFunction(Name);
	std::map<Module*, ExecutionEngine*>::iterator eeIt = EngineMap.find(*it);
	void* P;
    if (F && !F->empty() ) {

      if (eeIt != EngineMap.end()) {

        P = eeIt->second->getPointerToFunction(F);
        if (P)
          return P;

      } else {
        ExecutionEngine *EE = compileModule(*it);
        void *P = EE->getPointerToFunction(F);
        if (P)
          return P;
      }
    }

  }
  return NULL;
}

void MCJITHelper::dump()
{
  ModuleVector::iterator begin = Modules.begin();
  ModuleVector::iterator end = Modules.end();
  ModuleVector::iterator it;
  for (it = begin; it != end; ++it)
    (*it)->dump();
}
