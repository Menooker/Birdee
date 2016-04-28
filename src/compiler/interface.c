#include <string.h>
#include "MEM.h"
#include "DBG.h"
#include "diksamc.h"
#include "BirdeeDef.h"
#include "BdParameters.h"

#define UTF_8_SOURCE

static CompilerList *st_compiler_list = NULL;
extern BuiltinScript dkc_builtin_script[];
TypeSpecifier* pVoidType ;

typedef struct {
    char *name;
    DVM_BasicType type;
} BuiltInMethodParameter;

typedef struct {
    char *name;
    DVM_BasicType return_type;
    BuiltInMethodParameter *parameter;
    int parameter_count;
} BuiltInMethod;

typedef struct {
    char *name;
    BuiltInMethod *method;
    int method_count;
	int is_shared;
} BuiltInClass;

static BuiltInMethodParameter st_object_equals_arg[] = {
    {"obj", DVM_UNSPECIFIED_IDENTIFIER_TYPE}
};

static BuiltInMethodParameter st_array_resize_arg[] = {
    {"new_size", DVM_INT_TYPE}
};
static BuiltInMethodParameter st_array_insert_arg[] = {
    {"index", DVM_INT_TYPE},
    {"new_item", DVM_BASE_TYPE}
};
static BuiltInMethodParameter st_array_remove_arg[] = {
    {"index", DVM_INT_TYPE}
};
static BuiltInMethodParameter st_array_add_arg[] = {
    {"new_item", DVM_BASE_TYPE}
};

static BuiltInMethod st_array_method[] = {
	{"hash", DVM_INT_TYPE, NULL, 0},
	{"equals", DVM_BOOLEAN_TYPE, st_object_equals_arg,ARRAY_SIZE(st_object_equals_arg) },
	{"tostr", DVM_STRING_TYPE, NULL, 0},
    {ARRAY_METHOD_SIZE, DVM_INT_TYPE, NULL, 0},
    {ARRAY_METHOD_RESIZE, DVM_VOID_TYPE, st_array_resize_arg,
     ARRAY_SIZE(st_array_resize_arg)},
    {ARRAY_METHOD_INSERT, DVM_VOID_TYPE, st_array_insert_arg,
     ARRAY_SIZE(st_array_insert_arg)},
    {ARRAY_METHOD_REMOVE, DVM_VOID_TYPE, st_array_remove_arg,
     ARRAY_SIZE(st_array_remove_arg)},
    {ARRAY_METHOD_ADD, DVM_VOID_TYPE, st_array_add_arg,
     ARRAY_SIZE(st_array_add_arg)},
};

static BuiltInMethodParameter st_string_substr_arg[] = {
    {"start", DVM_INT_TYPE},
    {"length", DVM_INT_TYPE}
};

static BuiltInMethod st_string_method[] = {
	{"hash", DVM_INT_TYPE, NULL, 0},
	{"equals", DVM_BOOLEAN_TYPE, st_object_equals_arg,ARRAY_SIZE(st_object_equals_arg) },
	{"tostr", DVM_STRING_TYPE, NULL, 0},
    {"length", DVM_INT_TYPE, NULL, 0},
    {"substr", DVM_STRING_TYPE, st_string_substr_arg,
     ARRAY_SIZE(st_string_substr_arg)},
};

static BuiltInMethod st_object_method[] = {
	{"hash", DVM_INT_TYPE, NULL, 0},
	{"equals", DVM_BOOLEAN_TYPE, st_object_equals_arg,ARRAY_SIZE(st_object_equals_arg) },
	{"tostr", DVM_STRING_TYPE, NULL, 0},
};


static BuiltInClass st_builtin_class[]={
	{"Object",st_object_method,ARRAY_SIZE(st_object_method),0},
};

static FunctionDefinition *
create_built_in_method(DKC_Compiler* compiler,BuiltInMethod *src, int method_count)
{
    int i;
    int param_idx;
    ParameterList *param_list;
    FunctionDefinition *fd_array;

    fd_array = dkc_malloc(sizeof(FunctionDefinition) * method_count);
	memset(fd_array,0,sizeof(FunctionDefinition) * method_count);
    for (i = 0; i < method_count; i++) {
        fd_array[i].name = src[i].name;
        fd_array[i].type = dkc_alloc_type_specifier(src[i].return_type);
        param_list = NULL;
        for (param_idx = 0; param_idx < src[i].parameter_count; param_idx++) {
            TypeSpecifier *type
                = dkc_alloc_type_specifier(src[i].parameter[param_idx].type);
			if(src[i].parameter[param_idx].type==DVM_UNSPECIFIED_IDENTIFIER_TYPE)
			{
				/*type->u.class_ref.class_definition=compiler->class_definition_list;
				type->u.class_ref.class_index=0;
				type->u.class_ref.tylist=NULL;*/
				type->identifier="Object";
			}
            if (param_list) {
                param_list
                    = dkc_chain_parameter(param_list, type,
                                          src[i].parameter[param_idx].name);
            } else {
                param_list
                    = dkc_create_parameter(type,
                                           src[i].parameter[param_idx].name);
            }
        }
		fd_array[i].param_cnt=src[i].parameter_count;
        fd_array[i].parameter = param_list;
        fd_array[i].throws = NULL;
    }
    return fd_array;
}

static void
create_built_in_class(DKC_Compiler* compiler,BuiltInClass *src, int cls_count,ClassDefinition** out)
{
	int i,j;
	ClassDefinition* cd,*ret;
	FunctionDefinition* fd;
	MemberDeclaration* md;
	PackageName* pn;
	ClassDefinition* last=NULL;
	MemberDeclaration** mnext;

	pn=(PackageName*)dkc_malloc(sizeof(PackageName));
	pn->name="diksam"; //"diksam.lang"
	pn->next=(PackageName*)dkc_malloc(sizeof(PackageName));
	pn->next->name="lang";
	pn->next->next=NULL;


	for(i=0;i<cls_count;i++)
	{
		cd=(ClassDefinition*)dkc_malloc(sizeof(ClassDefinition));
		*out=cd;
		cd->access_modifier=DVM_PUBLIC_ACCESS;
		cd->class_or_interface=DVM_INTERFACE_DEFINITION;
		cd->extends=NULL;
		cd->interface_list=NULL;
		cd->is_abstract=DVM_TRUE;
		cd->line_number=0;
		cd->checked=0;
		cd->is_shared=src[i].is_shared;

		mnext=&cd->member;
		for(j=0;j<src->method_count;j++)
		{
			md=(MemberDeclaration*)dkc_malloc(sizeof(MemberDeclaration));
			*mnext=md;
			md->access_modifier=DVM_PUBLIC_ACCESS;
			md->kind=METHOD_MEMBER;
			md->line_number=0;
			md->u.method.function_definition=create_built_in_method(compiler,&src->method[j],1);
			md->u.method.is_abstract=DVM_TRUE;md->u.method.is_virtual=DVM_TRUE;
			md->u.method.is_override=DVM_FALSE;md->u.method.is_constructor=DVM_FALSE;
			md->u.method.method_index=j;
			mnext=&md->next;
		}
		*mnext=NULL;
		cd->name=src->name;
		cd->templates=NULL;
		cd->super_class=NULL;
		cd->package_name=pn;
		out=&cd->next;
	}
	*out=NULL;
	return;
}

DKC_Compiler *
DKC_create_compiler(void)
{
    MEM_Storage storage;
    DKC_Compiler *compiler;
    DKC_Compiler *compiler_backup;

    compiler_backup = dkc_get_current_compiler();

    storage = MEM_open_storage(0);
    compiler = MEM_storage_malloc(storage,
                                  sizeof(struct DKC_Compiler_tag));
    dkc_set_current_compiler(compiler);
    compiler->compile_storage = storage;
    compiler->package_name = NULL;
    compiler->source_suffix = DKM_SOURCE;
    compiler->require_list = NULL;
    compiler->rename_list = NULL;
    compiler->function_list = NULL;
    compiler->dvm_function_count = 0;
    compiler->dvm_function = NULL;
    compiler->dvm_enum_count = 0;
    compiler->dvm_enum = NULL;
    compiler->dvm_constant_count = 0;
    compiler->dvm_constant = NULL;
    compiler->dvm_class_count = 0;
    compiler->dvm_class = NULL;
    compiler->declaration_list = NULL;
    compiler->statement_list = NULL;
    compiler->class_definition_list = NULL;
    compiler->delegate_definition_list = NULL;
    compiler->enum_definition_list = NULL;
    compiler->constant_definition_list = NULL;
    compiler->current_block = NULL;
    compiler->current_line_number = 1;
    compiler->current_class_definition = NULL;
    compiler->current_catch_clause = NULL;
    compiler->input_mode = FILE_INPUT_MODE;
    compiler->required_list = NULL;


    compiler->array_method_count = ARRAY_SIZE(st_array_method);
    compiler->array_method
        = create_built_in_method(compiler,st_array_method,
                                 ARRAY_SIZE(st_array_method));
    compiler->string_method_count = ARRAY_SIZE(st_string_method);
    compiler->string_method
        = create_built_in_method(compiler,st_string_method,
                                 ARRAY_SIZE(st_string_method));


#ifdef EUC_SOURCE
    compiler->source_encoding = EUC_ENCODING;
#else
#ifdef SHIFT_JIS_SOURCE
    compiler->source_encoding = SHIFT_JIS_ENCODING;
#else
#ifdef UTF_8_SOURCE
    compiler->source_encoding = UTF_8_ENCODING;
#else
    DBG_panic(("source encoding is not defined.\n"));
#endif
#endif
#endif

    dkc_set_current_compiler(compiler_backup);

    return compiler;
}

static CompilerList *
add_compiler_to_list(CompilerList *list, DKC_Compiler *compiler)
{
    CompilerList *pos;
    CompilerList *new_item;

    new_item = MEM_malloc(sizeof(CompilerList));
    new_item->compiler = compiler;
    new_item->next = NULL;

    if (list == NULL) {
        return new_item;
    }
    for (pos = list; pos->next; pos = pos->next)
        ;
    pos->next = new_item;

    return list;
}

static DKC_Compiler *
search_compiler(CompilerList *list, PackageName *package_name)
{
    CompilerList *pos;

    for (pos = list; pos; pos = pos->next) {
        if (dkc_compare_package_name(pos->compiler->package_name,
                                     package_name))
            break;
    }

    if (pos) {
        return pos->compiler;
    } else {
        return NULL;
    }
}
static DKC_Compiler *
search_compiler_by_path(CompilerList *list, char *path)//modified
{
    CompilerList *pos;

    for (pos = list; pos; pos = pos->next) {
		if(pos->compiler->path && !strcmp(pos->compiler->path,path))
		{
			break;
		}
    }

    if (pos) {
        return pos->compiler;
    } else {
        return NULL;
    }
}
static DVM_Boolean
search_buitin_source(char *package_name, SourceSuffix suffix,
                     SourceInput *input)
{
    int i;

    for (i = 0; dkc_builtin_script[i].source_string != NULL; i++) {
        if (dvm_compare_string(package_name,
                               dkc_builtin_script[i].package_name)
            && dkc_builtin_script[i].suffix == suffix) {
            input->input_mode = STRING_INPUT_MODE;
            input->u.string.lines = dkc_builtin_script[i].source_string;
            return DVM_TRUE;
        }
    }
    return DVM_FALSE;
}

static void
make_search_path(int line_number, PackageName *package_name, char *buf)
{
    PackageName *pos;
    int len = 0;
    int prev_len = 0;
    int suffix_len;

    suffix_len = strlen(DIKSAM_REQUIRE_SUFFIX);
    buf[0] = '\0';
    for (pos = package_name; pos; pos = pos->next) {
        prev_len = len;
        len += strlen(pos->name);
        if (len > FILENAME_MAX - (2 + suffix_len)) {
            dkc_compile_error(line_number,
                              PACKAGE_NAME_TOO_LONG_ERR,
                              MESSAGE_ARGUMENT_END);
        }
        strcpy(&buf[prev_len], pos->name);
        if (pos->next) {
            buf[strlen(buf)] = FILE_SEPARATOR;
            len++;
        }
    }
    strcpy(&buf[len], DIKSAM_REQUIRE_SUFFIX);
}

static void
make_search_path_impl(char *package_name, char *buf)
{
    int suffix_len;
    int package_len;
    int i;

	if(package_name==0)
	{
		buf[0]=0;
		return ;
	}
    suffix_len = strlen(DIKSAM_IMPLEMENTATION_SUFFIX);
    package_len = strlen(package_name);

    DBG_assert(package_len <= FILENAME_MAX - (2 + suffix_len),
               ("package name is too long(%s)", package_name));

    for (i = 0; package_name[i] != '\0'; i++) {
        if (package_name[i] == '.') {
            buf[i] = FILE_SEPARATOR;
        } else {
            buf[i] = package_name[i];
        }
    }
    buf[i] = '\0';
    strcat(buf, DIKSAM_IMPLEMENTATION_SUFFIX);
}

static void
get_require_input(RequireList *req, char *found_path,
                  SourceInput *source_input)
{
    char *search_path;
    char search_file[FILENAME_MAX];
    FILE *fp;
    char *package_name;
    SearchFileStatus status;

    package_name = dkc_package_name_to_string(req->package_name);
    if (search_buitin_source(package_name, DKH_SOURCE, source_input)) {
        MEM_free(package_name);
        found_path[0] = '\0';
        return;
    }
    MEM_free(package_name);

    search_path = getenv("DKH_LOAD_SEARCH_PATH");
    if (search_path == NULL) {
        search_path = ".";
    }
    make_search_path(req->line_number, req->package_name, search_file);

    status = dvm_search_file(search_path, search_file, found_path, &fp);

    if (status != SEARCH_FILE_SUCCESS) {
        if (status == SEARCH_FILE_NOT_FOUND) {
            dkc_compile_error(req->line_number,
                              REQUIRE_FILE_NOT_FOUND_ERR,
                              STRING_MESSAGE_ARGUMENT, "file", search_file,
                              MESSAGE_ARGUMENT_END);
        } else {
            dkc_compile_error(req->line_number,
                              REQUIRE_FILE_ERR,
                              INT_MESSAGE_ARGUMENT, "status", (int)status,
                              MESSAGE_ARGUMENT_END);
        }
    }
    source_input->input_mode = FILE_INPUT_MODE;
    source_input->u.file.fp = fp;
}

DVM_Boolean
add_exe_to_list(DVM_Executable *exe, DVM_ExecutableList *list) //modified : "static" removed
{
    DVM_ExecutableItem *new_item;
    DVM_ExecutableItem *pos;
    DVM_ExecutableItem *tail;

    for (pos = list->list; pos; pos = pos->next) {
        if (dvm_compare_package_name(pos->executable->package_name,
                                     exe->package_name)
            && pos->executable->is_required == exe->is_required) {
            return DVM_FALSE;
        }
        tail = pos;
    }

    new_item = MEM_malloc(sizeof(DVM_ExecutableItem));
    new_item->executable = exe;
    new_item->next = NULL;

    if (list->list == NULL) {
        list->list = new_item;
    } else {
        tail->next = new_item;
    }

    return DVM_TRUE;
}

static char* findfilename(DKC_Compiler *compiler,char* path)
{
	char* finda;
	char* findb;
	char* found;
	char* dot;
	char* ret;
	finda=strrchr(path,'/');
	findb=strrchr(path,'\\');
	if(finda>findb)
		found=finda;
	else
		found=findb;
	if(!found)
		found=path;
	else
		found++;
	dot=found;
	while(*dot)
	{
		if(*dot=='.')
			break;
		dot++;
	}
	ret=MEM_storage_malloc(compiler->compile_storage,dot-found+1);
	strncpy(ret,found,dot-found);
	ret[dot-found]=0;
	return ret;

}

static void
set_path_to_compiler(DKC_Compiler *compiler, char *path)
{
	PackageName *nm;
    compiler->path = MEM_storage_malloc(compiler->compile_storage,
                                        strlen(path) + 1);
    strcpy(compiler->path, path);
	if(path && path[0]!=0)
	{
		nm=MEM_storage_malloc(compiler->compile_storage,sizeof(PackageName));
		nm->name=findfilename(compiler,path);
		nm->next=NULL;
		compiler->package_name=nm;
	}

}

static DVM_Executable *
do_compile(DKC_Compiler *compiler, DVM_ExecutableList *list,
           char *path, DVM_Boolean is_required)
{
    extern FILE *yyin;
    extern int yyparse(void);
    RequireList *req_pos;
    DKC_Compiler *req_comp;
    DVM_Executable *exe;
    DVM_Executable *req_exe;
    char found_path[FILENAME_MAX];
    DKC_Compiler *compiler_backup;
    SourceInput source_input;

    compiler_backup = dkc_get_current_compiler();
    dkc_set_current_compiler(compiler);
    if (yyparse()) {
        fprintf(stderr, "Error ! Error ! Error !\n");
        exit(1);
    }

    for (req_pos = compiler->require_list; req_pos;
         req_pos = req_pos->next) {
        req_comp = search_compiler(st_compiler_list, req_pos->package_name);
        if (req_comp) {
            compiler->required_list
                = add_compiler_to_list(compiler->required_list, req_comp);
            continue;
        }
        req_comp = DKC_create_compiler();
		if(req_pos->package_name && !strcmp(req_pos->package_name->name,"diksam")
			&& req_pos->package_name->next && !strcmp(req_pos->package_name->next->name,"lang")
			&& req_pos->package_name->next->next==NULL)
		{
			create_built_in_class(req_comp,st_builtin_class,ARRAY_SIZE(st_builtin_class),&req_comp->class_definition_list);
		}
        // BUGBUG req_comp references parent compiler's MEM_storage
        req_comp->package_name = req_pos->package_name;
        req_comp->source_suffix = DKH_SOURCE;

        compiler->required_list
            = add_compiler_to_list(compiler->required_list, req_comp);
        st_compiler_list = add_compiler_to_list(st_compiler_list, req_comp);

        get_require_input(req_pos, found_path, &source_input);
        set_path_to_compiler(req_comp, found_path);
        req_comp->input_mode = source_input.input_mode;
        if (source_input.input_mode == FILE_INPUT_MODE) {
            yyin = source_input.u.file.fp;
        } else {
            dkc_set_source_string(source_input.u.string.lines);
        }
		//printf("req:%s\n",found_path);
        req_exe = do_compile(req_comp, list, found_path, DVM_TRUE);
    }
	 //fix-me*/
    dkc_fix_tree(compiler);
    exe = dkc_generate(compiler);
    if (path) {
        exe->path = MEM_strdup(path);
    } else {
        exe->path = NULL;
    }
    // dvm_disassemble(exe);

	exe->libname=BcGetCurrentCompilerContext()->libname?MEM_strdup(BcGetCurrentCompilerContext()->libname):0;
	BcGetCurrentCompilerContext()->libname=0;

    exe->is_required = is_required;
    if (!add_exe_to_list(exe, list)) {
        dvm_dispose_executable(exe);
    }

    dkc_set_current_compiler(compiler_backup);

    return exe;
}

static void
dispose_compiler_list(void)
{
    CompilerList *temp;

    while (st_compiler_list) {
        temp = st_compiler_list;
        st_compiler_list = temp->next;
        MEM_free(temp);
    }
}

int isPackageInBuiltIn(char* packagename)//modified
{
	BuiltinScript* pScr=dkc_builtin_script;
	if(!packagename)
		return 0;
	while(pScr->package_name && pScr->source_string)
	{
		if(!strcmp(packagename,pScr->package_name))
			return 1;
		pScr++;
	}
	return 0;
}


static PackageName *
_string_to_package_name(DKC_Compiler *compiler, char *str);

SearchFileStatus
get_dynamic_load_input(char *package_name, char *found_path,
                       char *search_file, SourceInput *source_input);
SearchFileStatus
dkc_dynamic_compile2(DKC_Compiler *compiler, char *package_name,
                    DVM_ExecutableList *list,
                    char *search_file) //modified
{
	//extern  PackageName *string_to_package_name(char *package_name, char *found_path);
    SearchFileStatus status;
    extern FILE *yyin;
    DVM_Executable *exe;
    SourceInput source_input;
    char found_path[FILENAME_MAX];

    status = get_dynamic_load_input(package_name, found_path,
                                    search_file, &source_input);
    if (status != SEARCH_FILE_SUCCESS) {
        return status;
    }


	if(search_compiler_by_path(st_compiler_list,found_path))
	{
		DKC_dispose_compiler(compiler);
		return SEARCH_FILE_SUCCESS;//fix-me
	}
	add_compiler_to_list(st_compiler_list,compiler);
    compiler->package_name = _string_to_package_name(compiler, package_name);
    set_path_to_compiler(compiler, found_path);

    compiler->input_mode = source_input.input_mode;
    if (source_input.input_mode == FILE_INPUT_MODE) {
        yyin = source_input.u.file.fp;
    } else {
        dkc_set_source_string(source_input.u.string.lines);
    }
    exe = do_compile(compiler, list, found_path, DVM_FALSE);

    //dispose_compiler_list();
    //dkc_reset_string_literal_buffer();

    return SEARCH_FILE_SUCCESS;
}


extern void BcBuildInlines(void* mod);
DVM_ExecutableList *
DKC_compile(DKC_Compiler *compiler, FILE *fp, char *path)
{

    extern FILE *yyin;
    DVM_ExecutableList *list;
    DVM_Executable *exe;
	int fcnt,i;
	DVM_ExecutableItem* pCur;PackageName packagename={0,0};DKC_Compiler* newcomp;char search_file[260];SearchFileStatus status;//modified
	DKC_Compiler* back_compiler;
	char* tmp;

	back_compiler = dkc_get_current_compiler();
	dkc_set_current_compiler(compiler);
	dkc_set_current_compiler(back_compiler);

    DBG_assert(st_compiler_list == NULL,
               ("st_compiler_list != NULL(%p)", st_compiler_list));
    set_path_to_compiler(compiler, path);
    compiler->input_mode = FILE_INPUT_MODE;

    yyin = fp;

    list = MEM_malloc(sizeof(DVM_ExecutableList));
    list->list = NULL;


    exe = do_compile(compiler, list, NULL, DVM_FALSE);
    exe->path = MEM_strdup(path);
    list->top_level = exe;

	BcBuildInlines(BcGetCurrentCompilerContext()->inline_module);
	for(pCur=list->list;pCur;pCur=pCur->next)//modified
	{
		fcnt=pCur->executable->function_count;
		pCur->executable->inline_module.mod=BcGetCurrentCompilerContext()->inline_module;
		for(i=0;i<fcnt;i++)
		{
			if(!pCur->executable->function[i].isLib  && !pCur->executable->function[i].is_implemented
				&& !isPackageInBuiltIn(pCur->executable->function[i].package_name) && parameters.isSyslib==0)
			{

				/*newcomp=DKC_create_compiler();
				status=dkc_dynamic_compile2(newcomp,pCur->executable->function[i].package_name,list,search_file);
				if (status != SEARCH_FILE_SUCCESS) {
						printf("ERROR %d\n",status);
				}*/
				printf("Warning : Function %s.%s not implemented.\n",pCur->executable->function[i].package_name,pCur->executable->function[i].name);
			}
		}
		fcnt=pCur->executable->function_count;
		if(pCur->executable->function && pCur->executable->class_definition)
		{
			for(i=0;i<pCur->executable->class_count;i++)
			{
				if(pCur->executable->class_definition[i].package_name && !pCur->executable->class_definition[i].is_implemented  && !isPackageInBuiltIn(pCur->executable->class_definition[i].package_name))
				{
					/*//fix-me : check cls.superclass & interface ?
					newcomp=DKC_create_compiler();
					status=dkc_dynamic_compile2(newcomp,pCur->executable->function[i].package_name,list,search_file);
					if (status != SEARCH_FILE_SUCCESS) {
							printf("ERROR %d\n",status);
					}*/
					printf("Warning : Class %s.%s not implemented.\n",pCur->executable->class_definition[i].package_name,pCur->executable->class_definition[i].name);
				}
			}
		}
	}
    //dvm_disassemble(exe);

    dispose_compiler_list();
    dkc_reset_string_literal_buffer();

    return list;
}

PackageName *
create_one_package_name(DKC_Compiler *compiler,
                        char *str, int start_idx, int to_idx)
{
    PackageName *pn;
    int i;

    MEM_Storage storage = compiler->compile_storage;
    pn = MEM_storage_malloc(storage, sizeof(PackageName));
    pn->name = MEM_storage_malloc(storage, to_idx - start_idx + 1);

    for (i = 0; i < to_idx - start_idx; i++) {
        pn->name[i] = str[start_idx + i];
    }
    pn->name[i] = '\0';
    pn->next = NULL;

    return pn;
}

static PackageName *
_string_to_package_name(DKC_Compiler *compiler, char *str)
{
    int start_idx;
    int i;
    PackageName *pn;
    PackageName *top;
    PackageName *tail = NULL;

    for (start_idx = i = 0; str[i] != '\0'; i++) {
        if (str[i] == '.') {
            pn = create_one_package_name(compiler, str, start_idx, i);
            start_idx = i + 1;
            if (tail) {
                tail->next = pn;
            } else {
                top = pn;
            }
            tail = pn;
        }
    }
    pn = create_one_package_name(compiler, str, start_idx, i);
    if (tail) {
        tail->next = pn;
    } else {
        top = pn;
    }

    return top;
}

SearchFileStatus
get_dynamic_load_input(char *package_name, char *found_path,
                       char *search_file, SourceInput *source_input)
{
    SearchFileStatus status;
    char *search_path;
    FILE *fp;

    if (search_buitin_source(package_name, DKM_SOURCE, source_input)) {
        found_path[0] = '\0';
        return SEARCH_FILE_SUCCESS;
    }

    search_path = getenv("DKH_LOAD_SEARCH_PATH");
    if (search_path == NULL) {
        search_path = ".";
    }
    make_search_path_impl(package_name, search_file);
    status = dvm_search_file(search_path, search_file, found_path, &fp);

    if (status != SEARCH_FILE_SUCCESS) {
        return status;
    }
    source_input->input_mode = FILE_INPUT_MODE;
    source_input->u.file.fp = fp;

    return SEARCH_FILE_SUCCESS;
}




SearchFileStatus
dkc_dynamic_compile(DKC_Compiler *compiler, char *package_name,
                    DVM_ExecutableList *list, DVM_ExecutableItem **add_top,
                    char *search_file)
{
    SearchFileStatus status;
    extern FILE *yyin;
    DVM_ExecutableItem *tail;
    DVM_Executable *exe;
    SourceInput source_input;
    char found_path[FILENAME_MAX];

	_BreakPoint
    status = get_dynamic_load_input(package_name, found_path,
                                    search_file, &source_input);
    if (status != SEARCH_FILE_SUCCESS) {
        return status;
    }
    DBG_assert(st_compiler_list == NULL,
               ("st_compiler_list != NULL(%p)", st_compiler_list));

    for (tail = list->list; tail->next; tail = tail->next)
        ;

    compiler->package_name = _string_to_package_name(compiler, package_name);
    set_path_to_compiler(compiler, found_path);

    compiler->input_mode = source_input.input_mode;
    if (source_input.input_mode == FILE_INPUT_MODE) {
        yyin = source_input.u.file.fp;
    } else {
        dkc_set_source_string(source_input.u.string.lines);
    }
    exe = do_compile(compiler, list, found_path, DVM_FALSE);

    dispose_compiler_list();
    dkc_reset_string_literal_buffer();

    *add_top = tail->next;

    return SEARCH_FILE_SUCCESS;
}

static CompilerList *
traversal_compiler(CompilerList *list, DKC_Compiler *compiler)
{
    CompilerList *list_pos;
    CompilerList *req_pos;

    for (list_pos = list; list_pos; list_pos = list_pos->next) {
        if (list_pos->compiler == compiler)
            break;
    }
    if (list_pos == NULL) {
        list = add_compiler_to_list(list, compiler);
    }
    for (req_pos = compiler->required_list; req_pos; req_pos = req_pos->next) {
        list = traversal_compiler(list, req_pos->compiler);
    }

    return list;
}

void
DKC_dispose_compiler(DKC_Compiler *compiler)
{
    CompilerList *list = NULL;
    CompilerList *pos;
    FunctionDefinition *fd_pos;
    CompilerList *temp;

    list = traversal_compiler(list, compiler);

    for (pos = list; pos; ) {
        for (fd_pos = pos->compiler->function_list; fd_pos;
             fd_pos = fd_pos->next) {
            MEM_free(fd_pos->local_variable);
        }
        while (pos->compiler->required_list) {
            temp = pos->compiler->required_list;
            pos->compiler->required_list = temp->next;
            MEM_free(temp);
        }
        MEM_dispose_storage(pos->compiler->compile_storage);
        temp = pos->next;
        MEM_free(pos);
        pos = temp;
    }
}
