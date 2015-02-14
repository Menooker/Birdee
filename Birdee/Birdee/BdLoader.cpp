#include "Loader.h"


#include "llvm/Bitcode/ReaderWriter.h"
#include "llvm/Support/MemoryBuffer.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "../../include/DVM.h"
#include "../../include/MEM.h"
#include <string.h>
#include <string>
using namespace llvm;

extern int isPackageInBuiltIn(char* packagename);
#define LdReadVar(a,f) fread(&a,sizeof(a),1,f)
#define isBadLength(a) (a<0 || a>200000)
#define LdLoadVar(a,p) LdLoadBuffer(&a,sizeof(a),p)
#define LdAlloc(l,T) ((T*)(MEM_malloc(l*sizeof(T))))
#define LdArray(l,addr,T,p) do{LdLoadVar(l,p);addr=LdAlloc(l,T);}while(0)
extern "C"
{
extern BINT FUN_MAGIC;
extern BINT MAGIC_END;
extern char ValidCheckStr[11];
extern DVM_Boolean add_exe_to_list(DVM_Executable *exe, DVM_ExecutableList *list);
extern void dvm_dispose_executable(DVM_Executable *exe);
void* bmalloc( size_t size);
//static DVM_Executable *alloc_executable(PackageName *package_name);
void CpDisplayBuffer(CPBuffer* p,int s);

BdStatus LdLoadCode(char* path,DVM_ExecutableList* exelist )
{
	FILE* f=fopen(path,"rb");
	BINT sz=0,index;
	char MagicHead[11];
	int i;
	DVM_Executable* exe;
	BdStatus status;
	//fix-me:check file ok?
	fread(MagicHead,11,1,f);
	if(MagicHead[10] || strcmp(MagicHead,ValidCheckStr))
	{
		fclose(f);
		return BdBadMagicNum;
	}
	LdReadVar(sz,f); 
	LdReadVar(index,f);

	exe = (DVM_Executable*)MEM_malloc(sizeof(DVM_Executable)*sz);
	memset(exe,0,sizeof(DVM_Executable)*sz);

	//printf("sz:%d\n",sz);
	for(i=0;i<sz;i++)//modified
	{
		//printf("INCLUDE:%d\n",i);
		try
		{
			status=LdExecutable(&exe[i],f);
			if(status!=0)
			{
				printf("Error %d\n",status);
				fclose(f);
				return status;
			}
			if(!add_exe_to_list(&exe[i], exelist))
			{
				dvm_dispose_executable(&exe[i]);
				fclose(f);
				return BdDuplicatePackageName;
			}
			if(index==i)
				exelist->top_level=&exe[i];
		}
		catch(BdStatus &s)
		{
			printf("Error %d\n",s);
			return s;
		}
	}
	fclose(f);
	return BdSuccess;
}

BdStatus LdLoadBuffer(void* p,BINT len,CPBuffer* pbuf)
{
	if(pbuf->len + len > pbuf->bufsize)
	{
		throw BdEndOfBuffer;
		return BdEndOfBuffer;
	}
	memcpy(p,pbuf->p + pbuf->len,len);
	pbuf->len+=len;
	return BdSuccess;
}


BdStatus LdString(char** p,CPBuffer* pbuf)
{
	BINT len;
	LdLoadVar(len,pbuf);
	if(len<0 || len >30000)
	{
		throw BdBadLength;
		return BdBadLength;
	}
	if(!len)
	{
		*p=0;
	}
	else
	{
		*p=(char*)MEM_malloc(len);
		LdLoadBuffer(*p,len,pbuf);
	}
	return BdSuccess;
}

BdStatus LdStringW(wchar_t** p,CPBuffer* pbuf)
{
	BdStatus ret;
	BINT len;
	LdLoadVar(len,pbuf);
	if(len<0 || len >30000)
	{
		return BdBadLength;
	}
	if(!len)
	{
		*p=0;
	}
	else
	{
		*p=(wchar_t*)MEM_malloc(len*sizeof(wchar_t));
		LdLoadBuffer(*p,len,pbuf);
	}
	return BdSuccess;
}

BdStatus LdTypeSpecifier(DVM_TypeSpecifier* type,CPBuffer* pbuf)
{
	LdLoadVar(type->basic_type,pbuf);
	LdLoadVar(type->u,pbuf);
	LdLoadVar(type->derive_count,pbuf);
	type->derive=LdAlloc(type->derive_count,DVM_TypeDerive);
	if(type->derive_count)
		LdLoadBuffer(type->derive,sizeof(DVM_TypeDerive)*type->derive_count,pbuf);
	return BdSuccess;
}



BdStatus LdVariable(void* v,CPBuffer* pbuf)
{
	DVM_Variable* var=(DVM_Variable*)v;
	LdString(&var->name,pbuf);
	var->type=LdAlloc(1,DVM_TypeSpecifier);
	LdTypeSpecifier(var->type,pbuf);

	return BdSuccess;
}

BdStatus LdCodeBlock(DVM_CodeBlock* blk,CPBuffer* pbuf)
{
	int i;
/*	LdArray(blk->code_size,blk->code,DVM_Byte,pbuf);
	LdLoadBuffer(blk->code,blk->code_size,pbuf);
	LdArray(blk->line_number_size,blk->line_number,DVM_LineNumber,pbuf);
	//printf("wcd:%x\n",blk->line_number_size);
	LdLoadBuffer(blk->line_number,sizeof(DVM_LineNumber)*blk->line_number_size,pbuf);
	LdArray(blk->try_size,blk->blktry,DVM_Try,pbuf);
	//printf("wtr:%x\n",blk->try_size);
	for(i=0;i<blk->try_size;i++)
	{
		LdLoadVar(blk->blktry->finally_end_pc,pbuf);
		LdLoadVar(blk->blktry->finally_start_pc,pbuf);
		LdLoadVar(blk->blktry->try_end_pc,pbuf);
		LdLoadVar(blk->blktry->try_start_pc,pbuf);
		LdArray(blk->blktry->catch_count,blk->blktry->catch_clause,DVM_CatchClause,pbuf);
		LdLoadBuffer(blk->blktry->catch_clause,sizeof(DVM_CatchClause)*blk->blktry->catch_count,pbuf);
		
	}*/
	return BdSuccess;
}

BdStatus LdFunction(DVM_Function* func,CPBuffer* pbuf)
{
	BINT i;
/*	int inbuiltin=isPackageInBuiltIn(func->package_name);
	if(!func->is_implemented && !inbuiltin)
	{
		printf("Function %s not implemented!\n",func->name);
		exit(1);
	}*/
	LdLoadVar(i,pbuf);
	if(i!=FUN_MAGIC)
		throw BdBadMagicNum;
	LdLoadVar(func->is_implemented,pbuf);
	LdString(&func->package_name,pbuf);
	LdString(&func->name,pbuf);
	LdLoadVar(func->isLib,pbuf);
	func->type=LdAlloc(1,DVM_TypeSpecifier);
	LdTypeSpecifier(func->type,pbuf);
	LdArray(func->local_variable_count,func->local_variable,DVM_LocalVariable,pbuf);
	for(i=0;i<func->local_variable_count;i++)
	{
		LdVariable(&func->local_variable[i],pbuf);
	}
	LdArray(func->parameter_count,func->parameter,DVM_LocalVariable,pbuf);
	for(i=0;i<func->parameter_count;i++)
	{
		LdVariable(&func->parameter[i],pbuf);
	}
	LdLoadVar(func->is_method,pbuf);
	if(func->is_implemented)
		LdCodeBlock(&func->code_block,pbuf);
	LdLoadVar(i,pbuf);
	if(i!=FUN_MAGIC)
	{
		__asm int 3
		throw BdBadMagicNum;
	}
	return BdSuccess;
}



BdStatus LdClassIdentifier(DVM_ClassIdentifier* clsid,CPBuffer* pbuf)
{
	LdString(&clsid->name,pbuf);
	LdString(&clsid->package_name,pbuf);
	if(clsid->name==0 && clsid->package_name==0)
		return BdShouldDispose;
	return BdSuccess;
}

BdStatus LdField(DVM_Field* field,CPBuffer* pbuf)
{
	LdString(&field->name,pbuf);
	LdLoadVar(field->access_modifier,pbuf);
	field->type=LdAlloc(1,DVM_TypeSpecifier);
	LdTypeSpecifier(field->type,pbuf);
	return BdSuccess;
}

BdStatus LdMethod(DVM_Method* method,CPBuffer* pbuf)
{
	LdString(&method->name,pbuf);
	LdLoadVar(method->access_modifier,pbuf);
	LdLoadVar(method->is_abstract,pbuf);
	LdLoadVar(method->is_override,pbuf);
	LdLoadVar(method->is_virtual,pbuf);
	return BdSuccess;
}

BdStatus LdClass(DVM_Class* cls,CPBuffer* pbuf)
{
	int i;
	/*if(!cls->is_implemented)
	{
		printf("Class %s not implemented!\n",cls->name);
		exit(1);
	}	*/
	LdLoadVar(cls->is_implemented,pbuf);
	LdLoadVar(cls->is_abstract,pbuf);
	LdLoadVar(cls->access_modifier,pbuf);
	LdLoadVar(cls->class_or_interface,pbuf);
	LdString(&cls->package_name,pbuf);
	LdString(&cls->name,pbuf);
	cls->super_class=LdAlloc(1,DVM_ClassIdentifier);
	if(LdClassIdentifier(cls->super_class,pbuf)==BdShouldDispose)
	{
		MEM_free(cls->super_class);
		cls->super_class=0;
	}

	LdArray(cls->interface_count,cls->interface_,DVM_ClassIdentifier,pbuf);
	for(i=0;i<cls->interface_count;i++)
	{
		if(LdClassIdentifier(&cls->interface_[i],pbuf)==BdShouldDispose)
			throw BdShouldDispose;
	}

	LdArray(cls->field_count,cls->field,DVM_Field,pbuf);
	for(i=0;i<cls->field_count;i++)
	{
		LdField(&cls->field[i],pbuf);
	}

	LdArray(cls->method_count,cls->method,DVM_Method,pbuf);
	for(i=0;i<cls->method_count;i++)
	{
		LdMethod(&cls->method[i],pbuf);
	}

	if(cls->is_implemented)
		LdCodeBlock(&cls->field_initializer,pbuf);

	return BdSuccess;
}


BdStatus LdEnum(DVM_Enum* benum,CPBuffer* pbuf)
{
	int i;
	LdLoadVar(benum->is_defined,pbuf);
	LdString(&benum->name,pbuf);
	LdString(&benum->package_name,pbuf);
	LdArray(benum->enumerator_count,benum->enumerator,char*,pbuf);
	for(i=0;i<benum->enumerator_count;i++)
	{
		LdString(&benum->enumerator[i],pbuf);
	}
	return BdSuccess;
}

BdStatus LdConstant(DVM_Constant* con,CPBuffer* pbuf)
{
	LdLoadVar(con->is_defined,pbuf);
	LdString(&con->name,pbuf);
	LdString(&con->package_name,pbuf);
	con->type=LdAlloc(1,DVM_TypeSpecifier);
	LdTypeSpecifier(con->type,pbuf);
	return BdSuccess;
}


BINT LdExecutable(DVM_Executable* exe,FILE* f)
{
	int i;
	BINT sz;
	CPBuffer buf;

	LdReadVar(sz,f);
	buf.len=0;
	buf.bufsize=sz-sizeof(sz);
	if(isBadLength(buf.bufsize))
	{
		return BdBadLength;
	}
	//printf("exe len %d\n",sz);
	buf.p=(char*)bmalloc(buf.bufsize);
	if(fread(buf.p,buf.bufsize,1,f)!=1)
	{
		free(buf.p);
		throw BdEndOfBuffer;
	}

	LdLoadVar(i,&buf);
	if(buf.p[3]!=19 || buf.p[2]!=23 || buf.p[1]!=10)//magic number for executable
	{
		return BdBadMagicNum;
	}
	//CpDisplayBuffer(&buf,1);

	LdString(&exe->package_name,&buf);
	LdLoadVar(exe->is_required,&buf);
	LdString(&exe->path,&buf);
	LdString(&exe->libname ,&buf);
	LdArray(exe->constant_pool_count,exe->constant_pool,DVM_ConstantPool,&buf);
	for(i=0;i<exe->constant_pool_count;i++)
	{
		LdLoadVar(exe->constant_pool[i].tag,&buf);
		if(exe->constant_pool[i].tag!=DVM_CONSTANT_STRING)
		{
			LdLoadVar(exe->constant_pool[i].u,&buf);
		}
		else
		{
			LdStringW(&exe->constant_pool[i].u.c_string,&buf);
		}
	}	

	LdArray(exe->type_specifier_count,exe->type_specifier,DVM_TypeSpecifier,&buf);
	for(i=0;i<exe->type_specifier_count;i++)
	{
		LdTypeSpecifier(&exe->type_specifier[i],&buf);
	}

	LdArray(exe->global_variable_count,exe->global_variable,DVM_Variable,&buf);
	for(i=0;i<exe->global_variable_count;i++)
	{
		LdVariable(&exe->global_variable[i],&buf);
	}

	LdArray(exe->function_count,exe->function,DVM_Function,&buf);
	for(i=0;i<exe->function_count;i++)
	{
		LdFunction(&exe->function[i],&buf);
	}

	LdArray(exe->class_count,exe->class_definition,DVM_Class,&buf);
	for(i=0;i<exe->class_count;i++)
	{
		LdClass(&exe->class_definition[i],&buf);
	}

	LdArray(exe->enum_count,exe->enum_definition,DVM_Enum,&buf);
	for(i=0;i<exe->enum_count;i++)
	{
		LdEnum(&exe->enum_definition[i],&buf);
	}

	LdArray(exe->constant_pool_count,exe->constant_definition,DVM_Constant,&buf);
	for(i=0;i<exe->constant_count;i++)
	{
		LdConstant(&exe->constant_definition[i],&buf);
	}

	LdCodeBlock(&exe->top_level,&buf);
	LdCodeBlock(&exe->constant_initializer,&buf);


	std::string ErrStr;
	Module *m=ParseBitcodeFile(MemoryBuffer::getMemBuffer(StringRef(buf.p + buf.len,buf.bufsize - buf.len - sizeof(BINT)),"D",false),getGlobalContext(),&ErrStr);
	if(!m){
		printf("Could not module: %s\n", ErrStr.c_str());
		system("pause");
		exit(1);
	}
	exe->module.mod=m;
	buf.len = buf.bufsize - sizeof(BINT);

	BINT magic_chk;
	LdLoadVar(magic_chk,&buf);
	if(magic_chk!=MAGIC_END)
	{
		dvm_dispose_executable(exe);
		__asm int 3
		return BdBadMagicNum;
	}
	printf("sz:%d\n",sz);
	free(buf.p);
	return BdSuccess;
	//exe->
}

}