#ifndef PUBLIC_DVM_CODE_H_INCLUDED
#define PUBLIC_DVM_CODE_H_INCLUDED
#include <stdio.h>
#include <wchar.h>
#include "DVM.h"


#ifdef __cplusplus

extern "C"

{

#endif

typedef void* LLVMPFun;
typedef void* LLVMPModule;
typedef void* LLVMPExeEngine;

typedef enum {
    DVM_VOID_TYPE,
    DVM_BOOLEAN_TYPE,
    DVM_INT_TYPE,
    DVM_DOUBLE_TYPE,
    DVM_FLOAT_TYPE,
    DVM_STRING_TYPE,
    DVM_CLASS_TYPE,
    DVM_DELEGATE_TYPE,
    DVM_ENUM_TYPE,
    DVM_NULL_TYPE,
    DVM_NATIVE_POINTER_TYPE,
    DVM_BASE_TYPE,
	DVM_VARIENT_TYPE,
	DVM_TEMPLATE_TYPE,
    DVM_UNSPECIFIED_IDENTIFIER_TYPE
} DVM_BasicType;

typedef struct DVM_TypeSpecifier_tag DVM_TypeSpecifier;

typedef struct {
    char                *name;
    DVM_TypeSpecifier   *type;
} DVM_LocalVariable;

typedef enum {
    DVM_FUNCTION_DERIVE,
    DVM_ARRAY_DERIVE
} DVM_DeriveTag;

typedef struct {
    int                 parameter_count;
    DVM_LocalVariable   *parameter;
} DVM_FunctionDerive;

typedef struct {
    int dummy; /* make compiler happy */
} DVM_ArrayDerive;

typedef struct DVM_TypeDerive_tag {
    DVM_DeriveTag       tag;
    union {
        DVM_FunctionDerive      function_d;
    } u;
} DVM_TypeDerive;

struct DVM_TypeSpecifier_tag {
    DVM_BasicType       basic_type;
    union {
        struct {
            int index;
        } class_t;
        struct {
            int dummy;
        } delegate_t;
        struct {
            int index;
        } enum_t;
    } u;
    int                 derive_count;
    DVM_TypeDerive      *derive;
};

typedef wchar_t DVM_Char;
typedef unsigned char DVM_Byte;

typedef enum {
    DVM_PUSH_INT_1BYTE = 1,
    DVM_PUSH_INT_2BYTE,
    DVM_PUSH_INT,
    DVM_PUSH_DOUBLE_0,
    DVM_PUSH_DOUBLE_1,
    DVM_PUSH_DOUBLE,
    DVM_PUSH_STRING,
    DVM_PUSH_NULL,
    /**********/
    DVM_PUSH_STACK_INT,
    DVM_PUSH_STACK_DOUBLE,
    DVM_PUSH_STACK_OBJECT,
    DVM_POP_STACK_INT,
    DVM_POP_STACK_DOUBLE,
    DVM_POP_STACK_OBJECT,
    /**********/
    DVM_PUSH_STATIC_INT,
    DVM_PUSH_STATIC_DOUBLE,
    DVM_PUSH_STATIC_OBJECT,
    DVM_POP_STATIC_INT,
    DVM_POP_STATIC_DOUBLE,
    DVM_POP_STATIC_OBJECT,
    /**********/
    DVM_PUSH_CONSTANT_INT,
    DVM_PUSH_CONSTANT_DOUBLE,
    DVM_PUSH_CONSTANT_OBJECT,
    DVM_POP_CONSTANT_INT,
    DVM_POP_CONSTANT_DOUBLE,
    DVM_POP_CONSTANT_OBJECT,
    /**********/
    DVM_PUSH_ARRAY_INT,
    DVM_PUSH_ARRAY_DOUBLE,
    DVM_PUSH_ARRAY_OBJECT,
    DVM_POP_ARRAY_INT,
    DVM_POP_ARRAY_DOUBLE,
    DVM_POP_ARRAY_OBJECT,
    /**********/
    DVM_PUSH_CHARACTER_IN_STRING,
    /**********/
    DVM_PUSH_FIELD_INT,
    DVM_PUSH_FIELD_DOUBLE,
    DVM_PUSH_FIELD_OBJECT,
    DVM_POP_FIELD_INT,
    DVM_POP_FIELD_DOUBLE,
    DVM_POP_FIELD_OBJECT,
    /**********/
    DVM_ADD_INT,
    DVM_ADD_DOUBLE,
    DVM_ADD_STRING,
    DVM_SUB_INT,
    DVM_SUB_DOUBLE,
    DVM_MUL_INT,
    DVM_MUL_DOUBLE,
    DVM_DIV_INT,
    DVM_DIV_DOUBLE,
    DVM_MOD_INT,
    DVM_MOD_DOUBLE,
    DVM_BIT_AND,
    DVM_BIT_OR,
    DVM_BIT_XOR,
    DVM_MINUS_INT,
    DVM_MINUS_DOUBLE,
    DVM_BIT_NOT,
    DVM_INCREMENT,
    DVM_DECREMENT,
    DVM_CAST_INT_TO_DOUBLE,
    DVM_CAST_DOUBLE_TO_INT,
    DVM_CAST_BOOLEAN_TO_STRING,
    DVM_CAST_INT_TO_STRING,
    DVM_CAST_DOUBLE_TO_STRING,
    DVM_CAST_ENUM_TO_STRING,
    DVM_UP_CAST,
    DVM_DOWN_CAST,
    DVM_EQ_INT,
    DVM_EQ_DOUBLE,
    DVM_EQ_OBJECT,
    DVM_EQ_STRING,
    DVM_GT_INT,
    DVM_GT_DOUBLE,
    DVM_GT_STRING,
    DVM_GE_INT,
    DVM_GE_DOUBLE,
    DVM_GE_STRING,
    DVM_LT_INT,
    DVM_LT_DOUBLE,
    DVM_LT_STRING,
    DVM_LE_INT,
    DVM_LE_DOUBLE,
    DVM_LE_STRING,
    DVM_NE_INT,
    DVM_NE_DOUBLE,
    DVM_NE_OBJECT,
    DVM_NE_STRING,
    DVM_LOGICAL_AND,
    DVM_LOGICAL_OR,
    DVM_LOGICAL_NOT,
    DVM_POP,
    DVM_DUPLICATE,
    DVM_DUPLICATE_OFFSET,
    DVM_JUMP,
    DVM_JUMP_IF_TRUE,
    DVM_JUMP_IF_FALSE,
    /**********/
    DVM_PUSH_FUNCTION,
    DVM_PUSH_METHOD,
    DVM_PUSH_DELEGATE,
    DVM_PUSH_METHOD_DELEGATE,
    DVM_INVOKE,
    DVM_INVOKE_DELEGATE,
    DVM_RETURN,
    /**********/
    DVM_NEW,
    DVM_NEW_ARRAY,
    DVM_NEW_ARRAY_LITERAL_INT,
    DVM_NEW_ARRAY_LITERAL_DOUBLE,
    DVM_NEW_ARRAY_LITERAL_OBJECT,
    DVM_SUPER,
    DVM_INSTANCEOF,
    DVM_THROW,
    DVM_RETHROW,
    DVM_GO_FINALLY,
    DVM_FINALLY_END
} DVM_Opcode;

typedef enum {
    DVM_CONSTANT_INT,
    DVM_CONSTANT_DOUBLE,
    DVM_CONSTANT_STRING
} DVM_ConstantPoolTag;

typedef struct {
    DVM_ConstantPoolTag tag;
    union {
        int     c_int;
        double  c_double;
        DVM_Char *c_string;
    } u;
} DVM_ConstantPool;

typedef struct {
    char                *name;
    DVM_TypeSpecifier   *type;
} DVM_Variable;

typedef struct {
    int line_number;
    int start_pc;
    int pc_count;
} DVM_LineNumber;

typedef struct {
    int class_index;
    int start_pc;
    int end_pc;
} DVM_CatchClause;

typedef struct {
    int                 try_start_pc;
    int                 try_end_pc;
    int                 catch_count;
    DVM_CatchClause     *catch_clause;
    int                 finally_start_pc;
    int                 finally_end_pc;
} DVM_Try;

typedef struct {
    int                 code_size;
    DVM_Byte            *code;
    int                 line_number_size;
    DVM_LineNumber      *line_number;
    int                 try_size;
    DVM_Try             *blktry;
    int                 need_stack_size;
} DVM_CodeBlock;

typedef struct {
    DVM_TypeSpecifier   *type;
    char                *package_name;
    char                *name;
    int                 parameter_count;
    DVM_LocalVariable   *parameter;
    DVM_Boolean         is_implemented;
    DVM_Boolean         is_method;
    int                 local_variable_count;
    DVM_LocalVariable   *local_variable;
    DVM_CodeBlock       code_block;
	DVM_Boolean			isLib;
	//LLVMPFun		    pllvmfun; //modified
} DVM_Function;

typedef enum {
    DVM_FILE_ACCESS,
    DVM_PUBLIC_ACCESS,
    dvm_priVATE_ACCESS
} DVM_AccessModifier;

typedef struct {
    DVM_AccessModifier  access_modifier;
    char                *name;
    DVM_TypeSpecifier   *type;
} DVM_Field;

typedef struct {
    DVM_AccessModifier  access_modifier;
    DVM_Boolean         is_abstract;
    DVM_Boolean         is_virtual;
    DVM_Boolean         is_override;
    char                *name;
} DVM_Method;

typedef enum {
    DVM_CLASS_DEFINITION,
    DVM_INTERFACE_DEFINITION
} DVM_ClassOrInterface;

typedef struct {
    char *package_name;
    char *name;
} DVM_ClassIdentifier;

typedef struct {
    DVM_Boolean                 is_abstract;
    DVM_AccessModifier          access_modifier;
    DVM_ClassOrInterface        class_or_interface;
    char                        *package_name;
    char                        *name;
    DVM_Boolean                 is_implemented;
    DVM_ClassIdentifier         *super_class;
    int                         interface_count;
    DVM_ClassIdentifier         *interface_;
    int                         field_count;
    DVM_Field                   *field;
    int                         method_count;
    DVM_Method                  *method;
    DVM_CodeBlock               field_initializer;
	int							is_shared;
} DVM_Class;

typedef struct {
    char        *package_name;
    char        *name;
    DVM_Boolean is_defined;
    int         enumerator_count;
    char        **enumerator;
} DVM_Enum;

typedef struct {
    DVM_TypeSpecifier *type;
    char        *package_name;
    char        *name;
    DVM_Boolean is_defined;
} DVM_Constant;

struct LLVM_Data
{
	void* mod;
	void* pass;
};
struct DVM_Executable_tag {
    char                *package_name;
    DVM_Boolean         is_required;
    char                *path;
    int                 constant_pool_count;
    DVM_ConstantPool    *constant_pool;
    int                 global_variable_count;
    DVM_Variable        *global_variable;
    int                 shared_global_variable_count;
    DVM_Variable        *shared_global_variable;
    int                 function_count;
    DVM_Function        *function;
    int                 type_specifier_count;
    DVM_TypeSpecifier   *type_specifier;
    int                 class_count;
    DVM_Class           *class_definition;
    int                 enum_count;
    DVM_Enum            *enum_definition;
    int                 constant_count;
    DVM_Constant        *constant_definition;
    DVM_CodeBlock       top_level;
    DVM_CodeBlock       constant_initializer;
	struct LLVM_Data			module; //modified //it is actually llvm::Module
	struct LLVM_Data			inline_module; //modified //it is actually llvm::Module
	int					isDyn;
	char*				libname;
	int					id;

};

typedef struct DVM_ExecutableItem_tag {
    DVM_Executable *executable;
    struct DVM_ExecutableItem_tag *next;
} DVM_ExecutableItem;

struct DVM_ExecutableList_tag {
    DVM_Executable      *top_level;
    DVM_ExecutableItem  *list;
};


#ifdef __cplusplus

}

#endif

#endif /* PUBLIC_DVM_CODE_H_INCLUDED */
