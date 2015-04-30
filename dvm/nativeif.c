#include <string.h>
#include "..\include\MEM.h"
#include "..\include\DBG.h"
#include "..\include\DVM_dev.h"
#include "dvm_pri.h"
#include "..\Birdee\Birdee\BdException.h"
extern DVM_ObjectRef ExCreateExceptionEx(DVM_VirtualMachine *dvm, char *class_name,BINT* clsindex,RuntimeError id, ...);
 DVM_ErrorStatus
check_array(DVM_VirtualMachine *dvm, DVM_ObjectRef barray, int index,
            DVM_Executable *exe, BFunction *func, int pc,
            DVM_ObjectRef *exception_p)
{
    if (barray.data == NULL) {
        *exception_p
            = ExCreateExceptionEx(dvm, DVM_NULL_POINTER_EXCEPTION_NAME,NULL, //fix-me : urgent! should set the class id!!!
                                   NULL_POINTER_ERR,
                                   DVM_MESSAGE_ARGUMENT_END);
        return DVM_ERROR;
    }
    if (index < 0 || index >= barray.data->u.barray.size) {
        *exception_p
            = ExCreateExceptionEx(dvm, ARRAY_INDEX_EXCEPTION_NAME,NULL,
                                   INDEX_OUT_OF_BOUNDS_ERR,
                                   DVM_INT_MESSAGE_ARGUMENT, "index", index,
                                   DVM_INT_MESSAGE_ARGUMENT, "size",
                                   barray.data->u.barray.size,
                                   DVM_MESSAGE_ARGUMENT_END);
        return DVM_ERROR;
    }
    return DVM_SUCCESS;
}

DVM_ErrorStatus
DVM_array_get_int(DVM_VirtualMachine *dvm, DVM_ObjectRef barray, int index,
                  int *value, DVM_ObjectRef *exception_p)
{
/*    DVM_ErrorStatus status;
    status = check_array(dvm, barray, index,
                         dvm->current_executable->executable,
                         dvm->current_function, dvm->pc, exception_p);
    if (status != DVM_SUCCESS) {
        return status;
    }

    *value = barray.data->u.barray.u.int_array[index];
	*/
	_BreakPoint()
	//abandoned
    return DVM_SUCCESS;
}

DVM_ErrorStatus
DVM_array_get_double(DVM_VirtualMachine *dvm, DVM_ObjectRef barray,
                     int index, double *value, DVM_ObjectRef *exception_p)
{
    DVM_ErrorStatus status;
	/*
    status = check_array(dvm, barray, index,
                         dvm->current_executable->executable,
                         dvm->current_function, dvm->pc, exception_p);
    if (status != DVM_SUCCESS) {
        return status;
    }

    *value = barray.data->u.barray.u.double_array[index];
	*/
	_BreakPoint()
	//abandoned
    return DVM_SUCCESS;
}

DVM_ErrorStatus
DVM_array_get_object(DVM_VirtualMachine *dvm, DVM_ObjectRef barray, int index,
                     DVM_ObjectRef *value, DVM_ObjectRef *exception_p)
{
 /*   DVM_ErrorStatus status;

    status = check_array(dvm, barray, index,
                         dvm->current_executable->executable,
                         dvm->current_function, dvm->pc, exception_p);
    if (status != DVM_SUCCESS) {
        return status;
    }

    *value = barray.data->u.barray.u.object[index];
	*/
	_BreakPoint()
	//abandoned
    return DVM_SUCCESS;
}

DVM_ErrorStatus
DVM_array_set_int(DVM_VirtualMachine *dvm, DVM_ObjectRef barray, int index,
                  int value, DVM_ObjectRef *exception_p)
{
/*    DVM_ErrorStatus status;

    status = check_array(dvm, barray, index,
                         dvm->current_executable->executable,
                         dvm->current_function, dvm->pc, exception_p);
    if (status != DVM_SUCCESS) {
        return status;
    }

    barray.data->u.barray.u.int_array[index] = value;
	*/
	_BreakPoint()
	//abandoned
    return DVM_SUCCESS;
}

DVM_ErrorStatus
DVM_array_set_double(DVM_VirtualMachine *dvm, DVM_ObjectRef barray, int index,
                     double value, DVM_ObjectRef *exception_p)
{
/*    DVM_ErrorStatus status;

    status = check_array(dvm, barray, index,
                         dvm->current_executable->executable,
                         dvm->current_function, dvm->pc, exception_p);
    if (status != DVM_SUCCESS) {
        return status;
    }

    barray.data->u.barray.u.double_array[index] = value;
	*/
	_BreakPoint()
	//abandoned
    return DVM_SUCCESS;
}

DVM_ErrorStatus
DVM_array_set_object(DVM_VirtualMachine *dvm, DVM_ObjectRef barray, int index,
                     DVM_ObjectRef value, DVM_ObjectRef *exception_p)
{
/*    DVM_ErrorStatus status;

    status = check_array(dvm, barray, index,
                         dvm->current_executable->executable,
                         dvm->current_function, dvm->pc, exception_p);
    if (status != DVM_SUCCESS) {
        return status;
    }
*/
    barray.data->u.barray.u.object[index] = value;
	
    return DVM_SUCCESS;
}

int
DVM_array_size(DVM_VirtualMachine *dvm, DVM_Object *barray)
{
    return barray->u.barray.size;
}

/* This function doesn't update barray->u.barray.size.
 */
static void
resize_array(DVM_VirtualMachine *dvm, DVM_Object *barray, int new_size)
{
    int new_alloc_size;
    DVM_Boolean need_realloc;

    DBG_assert(barray->type == ARRAY_OBJECT, ("barray->type..%d", barray->type));

    if (new_size > barray->u.barray.alloc_size) {
        new_alloc_size = barray->u.barray.alloc_size * 2;
        if (new_alloc_size < new_size) {
            new_alloc_size = new_size + ARRAY_ALLOC_SIZE;
        } else if (new_alloc_size - barray->u.barray.alloc_size
                   > ARRAY_ALLOC_SIZE) {
            new_alloc_size = barray->u.barray.alloc_size + ARRAY_ALLOC_SIZE;
        }
        need_realloc = DVM_TRUE;
    } else if (barray->u.barray.alloc_size - new_size > ARRAY_ALLOC_SIZE) {
        new_alloc_size = new_size;
        need_realloc = DVM_TRUE;
    } else {
        need_realloc = DVM_FALSE;
    }
    if (need_realloc) {
        DVM_check_gc(dvm);
        switch (barray->u.barray.type) {
        case INT_ARRAY:
            barray->u.barray.u.int_array
                = MEM_realloc(barray->u.barray.u.int_array,
                              new_alloc_size * sizeof(int));
            dvm->heap.current_heap_size
                += (new_alloc_size - barray->u.barray.alloc_size)
                * sizeof(int);
            break;
        case DOUBLE_ARRAY:
            barray->u.barray.u.double_array
                = MEM_realloc(barray->u.barray.u.double_array,
                              new_alloc_size * sizeof(double));
            dvm->heap.current_heap_size
                += (new_alloc_size - barray->u.barray.alloc_size)
                * sizeof(double);
            break;
        case OBJECT_ARRAY:
            barray->u.barray.u.object
                = MEM_realloc(barray->u.barray.u.object,
                              new_alloc_size * sizeof(DVM_ObjectRef));
            dvm->heap.current_heap_size
                += (new_alloc_size - barray->u.barray.alloc_size)
                * sizeof(DVM_ObjectRef);
            break;
        case FUNCTION_INDEX_ARRAY:
        default:
            DBG_panic(("barray->u.barray.type..%d", barray->u.barray.type));
        }
        barray->u.barray.alloc_size = new_alloc_size;
    }
}

void
DVM_array_resize(DVM_VirtualMachine *dvm, DVM_Object *barray, int new_size)
{
    int i;    

    resize_array(dvm, barray, new_size);

    switch (barray->u.barray.type) {
    case INT_ARRAY:
        for (i = barray->u.barray.size; i < new_size; i++) {
            barray->u.barray.u.int_array[i] = 0;
        }
        break;
    case DOUBLE_ARRAY:
        for (i = barray->u.barray.size; i < new_size; i++) {
            barray->u.barray.u.double_array[i] = 0;
        }
        break;
    case OBJECT_ARRAY:
        for (i = barray->u.barray.size; i < new_size; i++) {
            barray->u.barray.u.object[i] = dvm_null_object_ref;
        }
        break;
    case FUNCTION_INDEX_ARRAY:
    default:
        DBG_panic(("barray->u.barray.type..%d", barray->u.barray.type));
    }

    barray->u.barray.size = new_size;
}

void
DVM_array_insert(DVM_VirtualMachine *dvm, DVM_Object *barray, int pos,
                 DVM_Value value)
{
    resize_array(dvm, barray, barray->u.barray.size + 1);

    switch (barray->u.barray.type) {
    case INT_ARRAY:
        memmove(&barray->u.barray.u.int_array[pos+1],
                &barray->u.barray.u.int_array[pos],
                sizeof(int) * (barray->u.barray.size - pos));
        barray->u.barray.u.int_array[pos] = value.int_value;
        break;
    case DOUBLE_ARRAY:
        memmove(&barray->u.barray.u.double_array[pos+1],
                &barray->u.barray.u.double_array[pos],
                sizeof(double) * (barray->u.barray.size - pos));
        barray->u.barray.u.double_array[pos] = value.double_value;
        break;
    case OBJECT_ARRAY:
        memmove(&barray->u.barray.u.object[pos+1],
                &barray->u.barray.u.object[pos],
                sizeof(DVM_ObjectRef) * (barray->u.barray.size - pos));
        barray->u.barray.u.object[pos] = value.object;
        break;
    case FUNCTION_INDEX_ARRAY:
    default:
        DBG_panic(("barray->u.barray.type..%d", barray->u.barray.type));
    }

    barray->u.barray.size++;
}

void
DVM_array_remove(DVM_VirtualMachine *dvm, DVM_Object *barray, int pos)
{

    switch (barray->u.barray.type) {
    case INT_ARRAY:
        memmove(&barray->u.barray.u.int_array[pos],
                &barray->u.barray.u.int_array[pos+1],
                sizeof(int) * (barray->u.barray.size - pos - 1));
        break;
    case DOUBLE_ARRAY:
        memmove(&barray->u.barray.u.double_array[pos],
                &barray->u.barray.u.double_array[pos+1],
                sizeof(double) * (barray->u.barray.size - pos - 1));
        break;
    case OBJECT_ARRAY:
        memmove(&barray->u.barray.u.object[pos],
                &barray->u.barray.u.object[pos+1],
                sizeof(DVM_ObjectRef) * (barray->u.barray.size - pos - 1));
        break;
    case FUNCTION_INDEX_ARRAY:
    default:
        DBG_panic(("barray->u.barray.type..%d", barray->u.barray.type));
    }

    resize_array(dvm, barray, barray->u.barray.size - 1);
    barray->u.barray.size--;
}

int
DVM_string_length(DVM_VirtualMachine *dvm, DVM_Object *string)
{
    return dvm_wcslen(string->u.string.string);
}

DVM_Char *
DVM_string_get_string(DVM_VirtualMachine *dvm, DVM_Object *string)
{
    return string->u.string.string;
}

static DVM_ErrorStatus
check_string_index(DVM_VirtualMachine *dvm, DVM_ObjectRef str, int index, DVM_ObjectRef *exception_p)
{
    if (is_object_null(str)) {
        *exception_p
            = ExCreateExceptionEx(dvm, DVM_NULL_POINTER_EXCEPTION_NAME,NULL,
                                   NULL_POINTER_ERR,
                                   DVM_MESSAGE_ARGUMENT_END);
        return DVM_ERROR;
    }
    if (index < 0 || index >= str.data->u.string.length) {
        *exception_p
            = ExCreateExceptionEx(dvm, STRING_INDEX_EXCEPTION_NAME,NULL,
                                   INDEX_OUT_OF_BOUNDS_ERR,
                                   DVM_INT_MESSAGE_ARGUMENT, "index", index,
                                   DVM_INT_MESSAGE_ARGUMENT, "size",
                                   str.data->u.string.length,
                                   DVM_MESSAGE_ARGUMENT_END);
        return DVM_ERROR;
    }
    return DVM_SUCCESS;
}


DVM_ErrorStatus
DVM_string_get_character(DVM_VirtualMachine *dvm, DVM_ObjectRef string,
                         int index, DVM_Char *ch, DVM_ObjectRef *exception_p)
{
    DVM_ErrorStatus status;
    status = check_string_index(dvm, string, index, exception_p);
    if (status != DVM_SUCCESS) {
        return status;
    }
    *ch = string.data->u.string.string[index];

    return DVM_SUCCESS;
}

DVM_Value
DVM_string_substr(DVM_VirtualMachine *dvm, DVM_Object *str,
                  int pos, int len)
{
    DVM_Char *new_str;
    DVM_Value ret;

    new_str = MEM_malloc(sizeof(DVM_Char) * (len+1));
    dvm_wcsncpy(new_str, str->u.string.string + pos, len);
    new_str[len] = L'\0';
    ret.object = dvm_create_dvm_string_i(dvm, new_str);

    return ret;
}

static int
get_field_index_sub(ExecClass *ec, char *field_name, int *super_count)
{
    int i;
    int index;

    if (ec->super_class) {
        index = get_field_index_sub(ec->super_class, field_name, super_count);
        if (index != FIELD_NOT_FOUND) {
            return index;
        }
    }
    for (i = 0; i < ec->dvm_class->field_count; i++) {
        if (!strcmp(ec->dvm_class->field[i].name, field_name)) {
            return i + *super_count;
        }
    }
    *super_count += ec->dvm_class->field_count;

    return FIELD_NOT_FOUND;
}

int
DVM_get_field_index(DVM_VirtualMachine *dvm, DVM_ObjectRef obj,
                    char *field_name)
{
    int super_count = 0;

    return get_field_index_sub(obj.v_table->exec_class, field_name,
                               &super_count);
}

DVM_Value
DVM_get_field(DVM_ObjectRef obj, int index)
{
    return obj.data->u.class_object.field[index];
}

void
DVM_set_field(DVM_ObjectRef obj, int index, DVM_Value value)
{
    obj.data->u.class_object.field[index] = value;
}

void *
DVM_object_get_native_pointer(DVM_Object *obj)
{
    DBG_assert(obj->type == NATIVE_POINTER_OBJECT,
               ("obj->type..%d\n", obj->type));
    return obj->u.native_pointer.pointer;
}

DVM_Boolean
DVM_check_native_pointer_type(DVM_Object *native_pointer,
                              DVM_NativePointerInfo *info)
{
    return native_pointer->u.native_pointer.info == info;
}


void
DVM_object_set_native_pointer(DVM_Object *obj, void *p)
{
    DBG_assert(obj->type == NATIVE_POINTER_OBJECT,
               ("obj->type..%d\n", obj->type));
    obj->u.native_pointer.pointer = p;
}

void
DVM_set_exception(DVM_VirtualMachine *dvm, DVM_Context *context,
                  DVM_NativeLibInfo *lib_info,
                  char *package_name, char *class_name,
                  int error_id, ...)
{
 /*   int class_index;
    DVM_ObjectRef obj;
    VString     message;
    va_list     ap;
    int message_index;
    int stack_trace_index;

    va_start(ap, error_id);
    class_index = DVM_search_class(dvm, package_name, class_name);
    obj = DVM_create_class_object(dvm, context, class_index);

    dvm_format_message(lib_info->message_format, error_id,
                       &message, ap);
    va_end(ap);

    message_index
        = DVM_get_field_index(dvm, obj, "message");
    obj.data->u.class_object.field[message_index].object
        = dvm_create_dvm_string_i(dvm, message.string);

    stack_trace_index
        = DVM_get_field_index(dvm, obj, "stack_trace");
    obj.data->u.class_object.field[stack_trace_index].object
        = dvm_create_array_object_i(dvm, 0);

    dvm->current_exception = obj;
	*/
	_BreakPoint()
	//abandoned
}

void
DVM_set_null(DVM_Value *value)
{
    value->object.v_table = NULL;
    value->object.data = NULL;
}

DVM_ObjectRef
DVM_up_cast(DVM_ObjectRef obj, int target_index)
{
    DVM_ObjectRef ret;

    ret = obj;
    ret.v_table = obj.v_table->exec_class->interface_v_table[target_index];

    return ret;
}

