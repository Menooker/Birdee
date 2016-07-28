#include "Dumper.h"
#include "DVM.h"
#include "MEM.h"
#include <string.h>
#include "llvm/Bitcode/ReaderWriter.h"
#include "llvm/Support/MemoryBuffer.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/Module.h"
#include "llvm/Analysis/Verifier.h"
#include "BdParameters.h"

using namespace llvm;

#define CpDumpVar(a,p) CpDumpBuffer((&a),sizeof((a)),(p))
extern int isPackageInBuiltIn(char* packagename);


class buffer_ostream : public raw_ostream {
  CPBuffer* pbuf;
  virtual void write_impl(const char *Ptr, size_t Size) {
	CpDumpBuffer((void*)Ptr, Size,pbuf);
  }
  virtual uint64_t current_pos()const { return pbuf->len; }  LLVM_OVERRIDE;

public:
  buffer_ostream(CPBuffer* p)  {pbuf=p;this->SetUnbuffered();}
  ~buffer_ostream(){}
};

#ifdef BD_ON_LINUX
#include <iconv.h>
void conv_wcs4_2_wsc2(wchar_t* src,size_t sz_src,char* dest, size_t sz_dest)
{
    size_t result;
    iconv_t env;
    //env = iconv_open("UCS-4-INTERNAL","UCS-2-INTERNAL");
    env = iconv_open("UTF-16","WCHAR_T");
    if (env==(iconv_t)-1)
    {
	env = iconv_open("UCS-2","WCHAR_T");
	if(env==(iconv_t)-1)
	{
		env = iconv_open("UCS2","WCHAR_T");
		if(env==(iconv_t)-1)
		{
        		printf("iconv_open error %d\n",errno);
        		return ;
		}
	}
    }

    result = iconv(env, (char**)&src, &sz_src, (char**)&dest, &sz_dest);
    if (result==(size_t)-1)
    {
        printf("UTF32 -> WCHAR_T conv error %d\n",errno) ;
        return ;
    }
    iconv_close(env);
}
#endif

extern "C"
{
BINT MAGIC_END=0x11FFAE86;
char ValidCheckStr[11]="@Birdee641";
BINT FUN_MAGIC=0xEEE123AA;


void CpDisplayBuffer(CPBuffer* p,int s)
{
	int i;
	int len=s ? p->bufsize : p->len;
	printf("=============%d\n",len);
	for(i=0;i<len;i+=4)
	{
		printf("%8x ",*(int*)(p->p+i));
	}
	printf("=============\n");
}

BdStatus CpSaveCodeToFile(char* path,DVM_ExecutableList* exelist )
{
	FILE* f=fopen(path,"wb+");
	DVM_ExecutableItem* pCur;
	BINT sz=0,index;
	//fix-me:check file ok?

	for(pCur=exelist->list;pCur;pCur=pCur->next)//modified
	{
		if(exelist->top_level==pCur->executable)
			index=sz;
		sz++;
	}
	if(parameters.isLib)
		sz--;

	fwrite(ValidCheckStr,sizeof(ValidCheckStr),1,f);
	fwrite(&sz,sizeof(sz),1,f);
	fwrite(&index,sizeof(index),1,f);
	printf("MAIN:%s\n",exelist->top_level->path);
	for(pCur=exelist->list;pCur;pCur=pCur->next)//modified
	{
		//printf("INCLUDE:%s\n",pCur->executable->path);
		if(parameters.isLib && pCur->executable->package_name && !strcmp(pCur->executable->package_name,"diksam.lang"))
			continue;
		sz=CpDumpExecutable(pCur->executable,f);
		printf("sz: %d\n",sz);
	}
	fclose(f);
	return BdSuccess;
}

void* brealloc(void* p, size_t size)
{
	void* ret=realloc(p,  size);
	if(!ret)
	{

			printf("Error! Error realloc\n");
			_BreakPoint
	}
	return ret;
}
void* bmalloc( size_t size)
{
	void* ret=malloc(size);
	if(!ret)
	{
			printf("Error! Error realloc\n");
			_BreakPoint
	}
	return ret;
}
BdStatus CpDumpBuffer(void* pArr,BINT size,CPBuffer* pbuf)
{
	if(size + pbuf->len > pbuf->bufsize)
	{
		//printf("---------------------------------------\n");
		pbuf->p=(char*)brealloc(pbuf->p,size+pbuf->len+1024);
		pbuf->bufsize=size+pbuf->len+1024;
	}
	memcpy(pbuf->p + pbuf->len, pArr,size);
	pbuf->len+=size;
	return BdSuccess;
}

BdStatus CpDumpString(char* p,CPBuffer* pbuf)
{
	BdStatus ret;
	BINT len;
	if(!p)
	{
		ret=0;
		ret=CpDumpBuffer(&ret,sizeof(BINT),pbuf);
		return ret;
	}
	else
	{
		len=strlen(p)+1;
		CpDumpBuffer(&len,sizeof(BINT),pbuf);
		ret=CpDumpBuffer(p,len,pbuf);
		return ret;
	}

}

BdStatus CpDumpStringW(wchar_t* p,CPBuffer* pbuf)
{
	BdStatus ret;
	BINT len;
	if(!p)
	{
		ret=0;
		ret=CpDumpBuffer(&ret,sizeof(BINT),pbuf);
		return ret;
	}
	else
	{
#ifdef BD_ON_LINUX
        size_t len_src=(wcslen(p)+1)*sizeof(wchar_t);
        size_t len_dest=len_src/2+2;
        char* bufchar=(char*)malloc(len_dest);
        conv_wcs4_2_wsc2(p,len_src,bufchar,len_dest);
        CpDumpBuffer(&len_dest,sizeof(BINT),pbuf);
		ret=CpDumpBuffer(bufchar,len_dest,pbuf);
        free(bufchar);
#else
		len=(wcslen(p)+1)*sizeof(wchar_t);
		CpDumpBuffer(&len,sizeof(BINT),pbuf);
		ret=CpDumpBuffer(p,len,pbuf);
#endif
		return ret;
	}

}

BdStatus CpDumpTypeSpecifier(DVM_TypeSpecifier* type,CPBuffer* pbuf)
{
	CpDumpBuffer(&type->basic_type,sizeof(type->basic_type),pbuf);
	CpDumpBuffer(&type->u,sizeof(type->u),pbuf);
	CpDumpBuffer(&type->derive_count,sizeof(type->derive_count),pbuf);
	if(type->derive_count)
		CpDumpBuffer(type->derive,sizeof(DVM_TypeDerive)*type->derive_count,pbuf);
	return BdSuccess;
}



BdStatus CpDumpVariable(void* v,CPBuffer* pbuf)
{
	DVM_Variable* var=(DVM_Variable*)v;
	CpDumpString(var->name,pbuf);
	CpDumpTypeSpecifier(var->type,pbuf);

	return BdSuccess;
}

BdStatus CpDumpCodeBlock(DVM_CodeBlock* blk,CPBuffer* pbuf)
{
	int i;
/*	CpDumpVar(blk->code_size,pbuf);
	CpDumpBuffer(blk->code,blk->code_size,pbuf);
	CpDumpVar(blk->line_number_size,pbuf);
	CpDumpBuffer(blk->line_number,sizeof(DVM_LineNumber)*blk->line_number_size,pbuf);
	//printf("tr:%d\n",blk->try_size);
	CpDumpVar(blk->try_size,pbuf);
	//printf("chk:%d\n",*(int*)(pbuf->p+pbuf->len-4));
	for(i=0;i<blk->try_size;i++)
	{
		CpDumpVar(blk->blktry->finally_end_pc,pbuf);
		CpDumpVar(blk->blktry->finally_start_pc,pbuf);
		CpDumpVar(blk->blktry->try_end_pc,pbuf);
		CpDumpVar(blk->blktry->try_start_pc,pbuf);
		CpDumpVar(blk->blktry->catch_count,pbuf);
		CpDumpBuffer(blk->blktry->catch_clause,sizeof(DVM_CatchClause)*blk->blktry->catch_count,pbuf);

	}*/
	return BdSuccess;
}

BdStatus CpDumpFunction(DVM_Function* func,CPBuffer* pbuf)
{
	int i;
/*	int inbuiltin=isPackageInBuiltIn(func->package_name);
	if(!func->is_implemented && !inbuiltin)
	{
		printf("Function %s not implemented!\n",func->name);
		exit(1);
	}*/
	CpDumpVar(FUN_MAGIC,pbuf);
	CpDumpVar(func->is_implemented,pbuf);
	CpDumpString(func->package_name,pbuf);
	CpDumpString(func->name,pbuf);
	CpDumpVar(func->isLib,pbuf);
	CpDumpTypeSpecifier(func->type,pbuf);
	CpDumpBuffer(&func->local_variable_count,sizeof(func->local_variable_count),pbuf);
	for(i=0;i<func->local_variable_count;i++)
	{
		CpDumpVariable(&func->local_variable[i],pbuf);
	}
	CpDumpBuffer(&func->parameter_count,sizeof(func->parameter_count),pbuf);
	for(i=0;i<func->parameter_count;i++)
	{
		CpDumpVariable(&func->parameter[i],pbuf);
	}
	CpDumpBuffer(&func->is_method,sizeof(func->is_method),pbuf);
	if(func->is_implemented)
		CpDumpCodeBlock(&func->code_block,pbuf);
	CpDumpVar(FUN_MAGIC,pbuf);
	return BdSuccess;
}

int CpFindTypeIndex(DVM_Executable* exe,DVM_TypeSpecifier* type)
{
	int i;
	i=((char*)type-(char*)exe->type_specifier)/sizeof(DVM_TypeSpecifier);
	if(i>exe->type_specifier_count || i<0)
	{
		printf("Invalid DVM_TypeSpecifier");
		_BreakPoint
		exit(1);
	}
	return i;
}

BdStatus CpDumpClassIdentifier(DVM_ClassIdentifier* clsid,CPBuffer* pbuf)
{
	if(!clsid)
	{
		BINT s=0;
		CpDumpVar(s,pbuf);
		CpDumpVar(s,pbuf);

	}
	else
	{
		CpDumpString(clsid->name,pbuf);
		CpDumpString(clsid->package_name,pbuf);
	}
	return BdSuccess;
}

BdStatus CpDumpField(DVM_Field* field,CPBuffer* pbuf)
{
	CpDumpString(field->name,pbuf);
	CpDumpVar(field->access_modifier,pbuf);
	CpDumpTypeSpecifier(field->type,pbuf);
	return BdSuccess;
}

BdStatus CpDumpMethod(DVM_Method* method,CPBuffer* pbuf)
{
	CpDumpString(method->name,pbuf);
	CpDumpVar(method->access_modifier,pbuf);
	CpDumpVar(method->is_abstract,pbuf);
	CpDumpVar(method->is_override,pbuf);
	CpDumpVar(method->is_virtual,pbuf);
	return BdSuccess;
}

BdStatus CpDumpClass(DVM_Class* cls,CPBuffer* pbuf)
{
	int i;
	/*if(!cls->is_implemented)
	{
		printf("Class %s not implemented!\n",cls->name);
		exit(1);
	}	*/
	CpDumpVar(cls->is_implemented,pbuf);
	CpDumpVar(cls->is_abstract,pbuf);
	CpDumpVar(cls->access_modifier,pbuf);
	CpDumpVar(cls->class_or_interface,pbuf);
	CpDumpString(cls->package_name,pbuf);
	CpDumpString(cls->name,pbuf);
	CpDumpClassIdentifier(cls->super_class,pbuf);

	CpDumpVar(cls->interface_count,pbuf);
	for(i=0;i<cls->interface_count;i++)
	{
		CpDumpClassIdentifier(&cls->interface_[i],pbuf);
	}

	CpDumpVar(cls->field_count,pbuf);
	for(i=0;i<cls->field_count;i++)
	{
		CpDumpField(&cls->field[i],pbuf);
	}

	CpDumpVar(cls->method_count,pbuf);
	for(i=0;i<cls->method_count;i++)
	{
		CpDumpMethod(&cls->method[i],pbuf);
	}
	CpDumpVar(cls->is_shared,pbuf);
	if(cls->is_implemented)
		CpDumpCodeBlock(&cls->field_initializer,pbuf);

	return BdSuccess;
}


BdStatus CpDumpEnum(DVM_Enum* benum,CPBuffer* pbuf)
{
	int i;
	CpDumpVar(benum->is_defined,pbuf);
	CpDumpString(benum->name,pbuf);
	CpDumpString(benum->package_name,pbuf);
	CpDumpVar(benum->enumerator_count,pbuf);
	for(i=0;i<benum->enumerator_count;i++)
	{
		CpDumpString(benum->enumerator[i],pbuf);
	}
	return BdSuccess;
}

BdStatus CpDumpConstant(DVM_Constant* con,CPBuffer* pbuf)
{
	CpDumpVar(con->is_defined,pbuf);
	CpDumpString(con->name,pbuf);
	CpDumpString(con->package_name,pbuf);
	CpDumpTypeSpecifier(con->type,pbuf);
	return BdSuccess;
}

extern "C" void dump_function(DVM_Executable *exe, int function_count, DVM_Function *function);
BINT CpDumpExecutable(DVM_Executable* exe,FILE* f)
{
	//dump_function(exe,exe->function_count,exe->function);
	int i;
	CPBuffer buf={(char*)bmalloc(1024*4),1024*4,8};
	//the first 4 bytes represents the size of the Executable
	buf.p[7]=19;buf.p[6]=23;buf.p[5]=10; //magic number for executable
	CpDumpString(exe->package_name,&buf);
	CpDumpBuffer(&exe->is_required,sizeof(BINT),&buf);
	CpDumpString(exe->path,&buf);
	CpDumpString(exe->libname ,&buf);
	CpDumpBuffer(&exe->constant_pool_count,sizeof(exe->constant_pool_count),&buf);
	for(i=0;i<exe->constant_pool_count;i++)
	{
		CpDumpVar(exe->constant_pool[i].tag,&buf);
		if(exe->constant_pool[i].tag!=DVM_CONSTANT_STRING)
		{
			CpDumpVar(exe->constant_pool[i].u,&buf);
		}
		else
		{
			CpDumpStringW(exe->constant_pool[i].u.c_string,&buf);
		}
	}

	CpDumpBuffer(&exe->type_specifier_count,sizeof(exe->type_specifier_count),&buf);
	for(i=0;i<exe->type_specifier_count;i++)
	{
		CpDumpTypeSpecifier(&exe->type_specifier[i],&buf);
	}

	CpDumpBuffer(&exe->global_variable_count,sizeof(exe->global_variable_count),&buf);
	for(i=0;i<exe->global_variable_count;i++)
	{
		CpDumpVariable(&exe->global_variable[i],&buf);
	}

	CpDumpBuffer(&exe->shared_global_variable_count,sizeof(exe->shared_global_variable_count),&buf);
	for(i=0;i<exe->shared_global_variable_count;i++)
	{
		CpDumpVariable(&exe->shared_global_variable[i],&buf);
	}

	CpDumpBuffer(&exe->function_count,sizeof(exe->function_count),&buf);
	for(i=0;i<exe->function_count;i++)
	{

		CpDumpFunction(&exe->function[i],&buf);
	}

	CpDumpVar(exe->class_count,&buf);
	for(i=0;i<exe->class_count;i++)
	{
		CpDumpClass(&exe->class_definition[i],&buf);
	}

	CpDumpVar(exe->enum_count,&buf);
	for(i=0;i<exe->enum_count;i++)
	{
		CpDumpEnum(&exe->enum_definition[i],&buf);
	}

	int dummy=0;
	CpDumpVar(dummy,&buf); //not dump contant yet
	/*CpDumpVar(exe->constant_pool_count,&buf);
	for(i=0;i<exe->constant_count;i++)
	{
		CpDumpConstant(&exe->constant_definition[i],&buf);
	}*/

	CpDumpCodeBlock(&exe->top_level,&buf);
	CpDumpCodeBlock(&exe->constant_initializer,&buf);

	//write llvm IR
	Module* md=(Module*)exe->module.mod;

	if(	llvm::verifyModule(*md))
		throw BdDamagedModule;
	buffer_ostream os(&buf);
	WriteBitcodeToFile(md,os);
	CpDumpVar(MAGIC_END,&buf);

	BINT* sz=(BINT*)(buf.p);
	*sz=buf.len;
	i=*sz;
	int ret=fwrite(buf.p,buf.len,1,f);
	//CpDisplayBuffer(&buf,0);
	if(ret!=1)
	{
		printf("%d",ret);
		_BreakPoint
	}
	free(buf.p);
	return i;
	//exe->
}

}
