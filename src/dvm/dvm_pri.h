#ifndef dvm_pri_H_INCLUDED
#define dvm_pri_H_INCLUDED

#include "DVM_code.h"
#include "DVM_dev.h"
#include "share_dvm.h"
#include "BdException.h"
#include "BirdeeDef.h"
#include "BdHashMap.h"
#include "UnportableAPI.h"

#include <stdarg.h>

#define ExHeapFreedType 0xfeeeaeee
typedef struct _RtlHashMap mRtlHashMap ;
#define STACK_ALLOC_SIZE (PAGE_SIZE)
#define HEAP_THRESHOLD_SIZE     (1024 * 1024)
#define ARRAY_ALLOC_SIZE (256)
#define NULL_STRING (L"null")
#define TRUE_STRING (L"true")
#define FALSE_STRING (L"false")
#define BUILT_IN_METHOD_PACKAGE_NAME ("$built_in")

#define NO_LINE_NUMBER_PC (-1)
#define FUNCTION_NOT_FOUND (-1)
#define ENUM_NOT_FOUND (-1)
#define CONSTANT_NOT_FOUND (-1)
#define FIELD_NOT_FOUND (-1)
#define CALL_FROM_NATIVE (-1)

#define MESSAGE_ARGUMENT_MAX    (256)
#define LINE_BUF_SIZE (1024)

#define GET_2BYTE_INT(p) (((p)[0] << 8) + (p)[1])
#define SET_2BYTE_INT(p, value) \
  (((p)[0] = (value) >> 8), ((p)[1] = value & 0xff))

#define is_pointer_type(type) \
  ((type)->basic_type == DVM_STRING_TYPE \
   || (type)->basic_type == DVM_CLASS_TYPE \
   || (type)->basic_type == DVM_NULL_TYPE \
   || (type)->basic_type == DVM_DELEGATE_TYPE \
   || ((type)->derive_count > 0 \
       && (type)->derive[0].tag == DVM_ARRAY_DERIVE))

#define is_object_null(obj) ((obj).data == NULL)

typedef enum {
    BAD_MULTIBYTE_CHARACTER_ERR = 1,
    FUNCTION_NOT_FOUND_ERR,
    FUNCTION_MULTIPLE_DEFINE_ERR,
    INDEX_OUT_OF_BOUNDS_ERR,
    DIVISION_BY_ZERO_ERR,
    NULL_POINTER_ERR,
    LOAD_FILE_NOT_FOUND_ERR,
    LOAD_FILE_ERR,
    CLASS_MULTIPLE_DEFINE_ERR,
    CLASS_NOT_FOUND_ERR,
    CLASS_CAST_ERR,
    ENUM_MULTIPLE_DEFINE_ERR,
    CONSTANT_MULTIPLE_DEFINE_ERR,
    DYNAMIC_LOAD_WITHOUT_PACKAGE_ERR,
	ECT_CLASS_NOT_LOADED_ERR,
    RUNTIME_ERROR_COUNT_PLUS_1
} RuntimeError;

typedef struct {
    DVM_Char    *string;
} VString;

typedef enum {
    NATIVE_FUNCTION,
    DIKSAM_FUNCTION
} FunctionKind;

typedef struct {
    DVM_NativeFunctionProc *proc;
    int arg_count;
    DVM_Boolean is_method;
    DVM_Boolean return_pointer;
} NativeFunction;

typedef struct ExecutableEntry_tag ExecutableEntry;

typedef struct {
    ExecutableEntry     *executable;
    int                 index;
} DiksamFunction;



typedef struct {
    char                *package_name;
    char                *name;
    FunctionKind        kind;
    DVM_Boolean         is_implemented;
    DVM_Boolean         is_method;
    union {
        NativeFunction native_f;
        DiksamFunction diksam_f;
    } u;
	//BdVMFunction pfun;
	int param_cnt;
	int local_cnt;
	DVM_LocalVariable *localvars;
	DVM_LocalVariable *params;
	BdVMFunction pfun;
} BFunction;

typedef struct {
    BFunction    *caller;
    int         caller_address;
    int         base;
} CallInfo;

#define revalue_up_align(val)   ((val) ? (((val) - 1) / sizeof(DVM_Value) + 1)\
                                 : 0)
#define CALL_INFO_ALIGN_SIZE    (revalue_up_align(sizeof(CallInfo)))

typedef union {
    CallInfo    s;
    DVM_Value   u[CALL_INFO_ALIGN_SIZE];
} CallInfoUnion;

typedef struct {
    BINT         alloc_size;
    DVM_Value   *stack_pointer;
    DVM_Value   *stack;
	DVM_Boolean *flg_sp;
    DVM_Boolean *pointer_flags;
} Stack;

typedef enum {
    STRING_OBJECT = 1,
    ARRAY_OBJECT,
    CLASS_OBJECT,
    NATIVE_POINTER_OBJECT,
    DELEGATE_OBJECT,
	AUTOVAR_OBJECT,
    OBJECT_TYPE_COUNT_PLUS_1
} ObjectType;

struct DVM_String_tag {
    DVM_Boolean is_literal;
    int         length;
    DVM_Char    *string;
};

typedef enum
{
	AV_INT=1,
	AV_DOUBLE,
	AV_STRING,
	AV_OBJECT
}AvType;
struct ExVarient_tag{
	AvType type;
	DVM_Value v;
};
struct ExVarientObj_tag{
    DVM_Boolean is_literal;
	struct ExVarient_tag* pobj;
};

typedef enum {
    INT_ARRAY = 1,
    DOUBLE_ARRAY,
    OBJECT_ARRAY,
	VARIENT_ARRAY,
    FUNCTION_INDEX_ARRAY
} DVM_ArrayType;

struct DVM_Array_tag {
    union {
        int             *int_array;
        double          *double_array;
        DVM_ObjectRef   *object;
        int             *function_index;
    } u;
	int         size;
	BINT* truebuffer;
    DVM_ArrayType   type;

    int         alloc_size;

};

typedef struct {
	DVM_Value   *field;
    int         field_count;
} DVM_ClassObject;

typedef struct {
    void                        *pointer;
    DVM_NativePointerInfo       *info;
} NativePointer;

typedef struct {
    DVM_ObjectRef       object;
    int                 index; /* if object is null, function index,
                                  else, method index*/
} Delegate;

struct DVM_Object_tag {
    union {
		ExVarientObj	var;
        DVM_String      string;
        DVM_Array       barray;
        DVM_ClassObject class_object;
        NativePointer   native_pointer;
        Delegate        delegate;
    } u;
    ObjectType  type;
    unsigned int        marked:1;

    struct DVM_Object_tag *prev;
    struct DVM_Object_tag *next;
};

typedef struct {
    int         current_heap_size;
    int         current_threshold;
	BD_LOCK		lock;
    DVM_Object  *header;
} Heap;

typedef struct {
    int         variable_count;
    DVM_Value   *variable;
} Static;

typedef struct ExecClass_tag {
    DVM_Class           *dvm_class;
    ExecutableEntry     *executable;
    char                *package_name;
    char                *name;
    DVM_Boolean         is_implemented;
    int                 class_index;
    struct ExecClass_tag *super_class;
    DVM_VTable          *class_table;
    int                 interface_count;
    struct ExecClass_tag **binterface;
    DVM_VTable          **interface_v_table;
    int                 field_count;
    DVM_TypeSpecifier   **field_type;
} ExecClass;

typedef struct {
    char        *name;
    int         index;
} VTableItem;

struct DVM_VTable_tag {
    ExecClass   *exec_class;
    int         table_size;
    VTableItem  *table;
};

struct ExecutableEntry_tag {
    DVM_Executable *executable;
    int         *function_table;
    int         *class_table;
    int         *enum_table;
    int         *constant_table;
    Static      static_v;
    struct ExecutableEntry_tag *next;
};

typedef struct {
    char        *package_name;
    char        *name;
    DVM_Boolean is_defined;
    DVM_Enum    *dvm_enum;
} Enum;

typedef struct {
    char        *package_name;
    char        *name;
    DVM_Boolean is_defined;
    DVM_Value   value;
} DVME_Constant;

struct _BdThread {
	DVM_Value   retvar;
    Stack       stack;
    ExecutableEntry     *current_executable;
    DVM_ObjectRef current_exception;
	DVM_ObjectRef		new_obj;
	BINT				exception_index;
	BINT				bpc;
	PExExceptionItem	estack;
	BINT				esp;
	unsigned int     e_alloc_size;
	PAutoVarContext     avstack;
	BINT				asp;
	unsigned int     av_alloc_size;
	THREAD_ID				tid;
	BINT				main;
	unsigned int		thread_obj_id;
#ifdef BD_ON_LINUX
    sem_t   suspend_lock;
	int	prepared;
#endif
	BD_EVENT remote_event;
	struct _BdThread* next;
	struct _BdThread* prv;
};
struct DVM_VirtualMachine_tag {

    BFunction    **function;
    int         function_count;
    ExecClass   **bclass;
    int         class_count;
    Enum        **enums;
    int         enum_count;
    DVME_Constant    **constant;
    int         constant_count;
    DVM_ExecutableList  *executable_list;
	int			executable_count;
    ExecutableEntry     *executable_entry;
    ExecutableEntry     *top_level;
    DVM_VTable  *array_v_table;
	DVM_VTable  *global_array_v_table;
    DVM_VTable  *string_v_table;
    DVM_Context *current_context;
    DVM_Context *free_context;
	LLVMPExeEngine		exe_engine;
	mRtlHashMap*			static_str_map;
	Heap heap;
	BD_LOCK thread_lock;
	struct _BdThread* mainvm;
	DVM_Class* classObject;
	int is_master;
};

typedef struct RefInNativeFunc_tag {
    DVM_ObjectRef  object;
    struct RefInNativeFunc_tag *next;
} RefInNativeFunc;

struct DVM_Context_tag {
    RefInNativeFunc     *ref_in_native_method;
    struct DVM_Context_tag *next;
};

/* execute.c */
void
dvm_expand_stack(DVM_VirtualMachine *dvm, int need_stack_size);
DVM_ObjectRef
dvm_create_exception(DVM_VirtualMachine *dvm, char *class_name,
                     RuntimeError id, ...);
DVM_Value
dvm_execute_i(DVM_VirtualMachine *dvm, BFunction *func,
              DVM_Byte *code, int code_size, int base);
void dvm_push_object(DVM_VirtualMachine *dvm, DVM_Value value);
DVM_Value dvm_pop_object(DVM_VirtualMachine *dvm);

/* heap.c */
DVM_ObjectRef
dvm_literal_to_dvm_string_i(DVM_VirtualMachine *inter, DVM_Char *str);
DVM_ObjectRef
dvm_create_dvm_string_i(DVM_VirtualMachine *dvm, DVM_Char *str);
DVM_ObjectRef dvm_create_array_int_i(DVM_VirtualMachine *dvm, int size);
DVM_ObjectRef dvm_create_array_double_i(DVM_VirtualMachine *dvm, int size);
DVM_ObjectRef ExCreateVarArray(DVM_VirtualMachine *dvm, int size);
DVM_ObjectRef dvm_create_array_object_i(DVM_VirtualMachine *dvm, int size);
DVM_ObjectRef dvm_create_class_object_i(DVM_VirtualMachine *dvm,
                                        int class_index);
DVM_ObjectRef dvm_create_delegate(DVM_VirtualMachine *dvm,
                                  DVM_ObjectRef object, int index);
void dvm_garbage_collect(DVM_VirtualMachine *dvm);
/* native.c */
void dvm_add_native_functions(DVM_VirtualMachine *dvm);
/* load.c*/
int dvm_search_function(DVM_VirtualMachine *dvm,
                        char *package_name, char *name);
void dvm_dynamic_load(DVM_VirtualMachine *dvm,
                      DVM_Executable *caller_exe, BFunction *caller, int pc,
                      BFunction *func);
/* util.c */
void dvm_vstr_clear(VString *v);
void dvm_vstr_append_string(VString *v, DVM_Char *str);
void dvm_vstr_append_character(VString *v, DVM_Char ch);
void dvm_initialize_value(DVM_VirtualMachine* dvm,DVM_TypeSpecifier *type, DVM_Value *value);

/* error.c */
void dvm_error_i(DVM_Executable *exe, BFunction *func,
                 int pc, RuntimeError id, ...);
//void dvm_error_n(DVM_VirtualMachine *dvm, RuntimeError id, ...);
int dvm_conv_pc_to_line_number(DVM_Executable *exe, BFunction *func, int pc);
void dvm_format_message(DVM_ErrorDefinition *error_definition,
                        int id, VString *message, va_list ap);
#ifdef DKM_WINDOWS
/* windows.c */
void dvm_add_windows_native_functions(DVM_VirtualMachine *dvm);
#endif /* DKM_WINDOWS */

extern OpcodeInfo dvm_opcode_info[];
extern DVM_ObjectRef dvm_null_object_ref;
extern DVM_ErrorDefinition dvm_error_message_format[];

#endif /* dvm_pri_H_INCLUDED */
