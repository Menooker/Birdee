#include <stdio.h>
#include <string.h>
#include "..\include\MEM.h"
#include "..\include\DBG.h"
#include "dvm_pri.h"
#include "..\Birdee\Birdee\BdHashMap.h"
extern DVM_VirtualMachine* curdvm;

void
DVM_check_gc(DVM_VirtualMachine *dvm)
{
#if 0
    dvm_garbage_collect(dvm);
#endif
    if (dvm->heap.current_heap_size > dvm->heap.current_threshold) {
        /* fprintf(stderr, "garbage collecting..."); */
        dvm_garbage_collect(dvm);
        /* fprintf(stderr, "done.\n"); */

        dvm->heap.current_threshold
            = dvm->heap.current_heap_size + HEAP_THRESHOLD_SIZE;
    }
}

static DVM_ObjectRef
alloc_object(DVM_VirtualMachine *dvm, ObjectType type)
{
    DVM_ObjectRef ret;

    DVM_check_gc(dvm);
    ret.v_table = NULL;
    ret.data = MEM_malloc(sizeof(DVM_Object));
    dvm->heap.current_heap_size += sizeof(DVM_Object);
    ret.data->type = type;
    ret.data->marked = DVM_FALSE;
    ret.data->prev = NULL;
    ret.data->next = dvm->heap.header;
    dvm->heap.header = ret.data;
    if (ret.data->next) {
        ret.data->next->prev = ret.data;
    }

    return ret;
}

static void
add_ref_in_native_method(DVM_Context *context, DVM_ObjectRef *obj)
{
    RefInNativeFunc *new_ref;

    new_ref = MEM_malloc(sizeof(RefInNativeFunc));
    new_ref->object = *obj;
    new_ref->next = context->ref_in_native_method;
    context->ref_in_native_method = new_ref;
}

void
DVM_add_reference_to_context(DVM_Context *context, DVM_Value value)
{
    add_ref_in_native_method(context, &value.object);
}


DVM_ObjectRef ExLoadStaticVar(DVM_VirtualMachine *dvm, ExVarient *v)
{
    DVM_ObjectRef ret;
    ret = alloc_object(dvm, AUTOVAR_OBJECT);
    ret.v_table =NULL;//fix-me :(ergent) may be wrong  //dvm->string_v_table;
    ret.data->u.var.pobj = v;
    ret.data->u.var.is_literal = DVM_TRUE;
    return ret;
}


DVM_ObjectRef ExCreateVar(DVM_VirtualMachine *dvm,ExVarient* v)
{
    DVM_ObjectRef ret;
    ret = alloc_object(dvm, AUTOVAR_OBJECT);
    ret.v_table = NULL;//fix-me : urgent!!..dvm->string_v_table;
	if(!v)
		ret.data->u.var.pobj =(ExVarient*)  MEM_malloc(sizeof(ExVarient) );
	else
		ret.data->u.var.pobj =v;
	memset(ret.data->u.var.pobj,0,sizeof(ExVarient));
    dvm->heap.current_heap_size += sizeof(ExVarient);
    ret.data->u.var.is_literal = DVM_FALSE;
    return ret;
}

DVM_ObjectRef
dvm_literal_to_dvm_string_i(DVM_VirtualMachine *dvm, DVM_Char *str)
{
    DVM_ObjectRef ret;
	ret=RtlHashmapGet(curdvm->static_str_map,(BdIntPtr)str);
	if(ret.data )
	{
			return ret;
	}
    ret = alloc_object(dvm, STRING_OBJECT);
    ret.v_table = dvm->string_v_table;
    ret.data->u.string.string = str;
    ret.data->u.string.length = dvm_wcslen(str);
    ret.data->u.string.is_literal = DVM_TRUE;
	RtlHashmapPut(curdvm->static_str_map,(BdIntPtr)str,ret);
    return ret;
}

DVM_ObjectRef
dvm_create_dvm_string_i(DVM_VirtualMachine *dvm, DVM_Char *str)
{
    DVM_ObjectRef ret;
    int len;

    len = dvm_wcslen(str);

    ret = alloc_object(dvm, STRING_OBJECT);
    ret.v_table = dvm->string_v_table;
    ret.data->u.string.string = str;
    dvm->heap.current_heap_size += sizeof(DVM_Char) * (len + 1);
    ret.data->u.string.is_literal = DVM_FALSE;
    ret.data->u.string.length = len;

    return ret;
}

DVM_ObjectRef
DVM_create_dvm_string(DVM_VirtualMachine *dvm, DVM_Context *context,
                      DVM_Char *str)
{
    DVM_ObjectRef ret;

    ret = dvm_create_dvm_string_i(dvm, str);
    add_ref_in_native_method(context, &ret);

    return ret;
}

DVM_ObjectRef
alloc_array(DVM_VirtualMachine *dvm, DVM_ArrayType type, int size)
{
    DVM_ObjectRef ret;

    ret = alloc_object(dvm, ARRAY_OBJECT);
    ret.data->u.barray.type = type;
    ret.data->u.barray.size = size;
    ret.data->u.barray.alloc_size = size;
    ret.v_table = dvm->array_v_table;

    return ret;
}

DVM_ObjectRef
dvm_create_array_int_i(DVM_VirtualMachine *dvm, int size)
{
    DVM_ObjectRef ret;
    int i;

    ret = alloc_array(dvm, INT_ARRAY, size);
    ret.data->u.barray.u.int_array = MEM_malloc(sizeof(int) * size);
    dvm->heap.current_heap_size += sizeof(int) * size;
    for (i = 0; i < size; i++) {
        ret.data->u.barray.u.int_array[i] = 0;
    }

    return ret;
}

DVM_ObjectRef
DVM_create_array_int(DVM_VirtualMachine *dvm,  DVM_Context *context,
                     int size)
{
    DVM_ObjectRef ret;

    ret = dvm_create_array_int_i(dvm, size);

    return ret;
}


DVM_ObjectRef
ExCreateVarArray(DVM_VirtualMachine *dvm, int size)
{
    DVM_ObjectRef ret;
    int i;

    ret = alloc_array(dvm, VARIENT_ARRAY, size);
    ret.data->u.barray.u.object = (DVM_ObjectRef*) MEM_malloc(sizeof(DVM_ObjectRef) * size);
    dvm->heap.current_heap_size += sizeof(DVM_ObjectRef) * size;
    for (i = 0; i < size; i++) {
        ret.data->u.barray.u.object [i] = ExCreateVar(dvm,0);
    }

    return ret;
}

DVM_ObjectRef
dvm_create_array_double_i(DVM_VirtualMachine *dvm, int size)
{
    DVM_ObjectRef ret;
    int i;

    ret = alloc_array(dvm, DOUBLE_ARRAY, size);
    ret.data->u.barray.u.double_array = MEM_malloc(sizeof(double) * size);
    dvm->heap.current_heap_size += sizeof(double) * size;
    for (i = 0; i < size; i++) {
        ret.data->u.barray.u.double_array[i] = 0.0;
    }


    return ret;
}

DVM_ObjectRef
DVM_create_array_double(DVM_VirtualMachine *dvm, DVM_Context *context,
                        int size)
{
    DVM_ObjectRef ret;

    ret = dvm_create_array_double_i(dvm, size);
    add_ref_in_native_method(context, &ret);

    return ret;
}

DVM_ObjectRef
dvm_create_array_object_i(DVM_VirtualMachine *dvm, int size)
{
    DVM_ObjectRef ret;
    int i;

    ret = alloc_array(dvm, OBJECT_ARRAY, size);
    ret.data->u.barray.u.object = MEM_malloc(sizeof(DVM_ObjectRef) * size);
    dvm->heap.current_heap_size += sizeof(DVM_ObjectRef) * size;
    for (i = 0; i < size; i++) {
        ret.data->u.barray.u.object[i] = dvm_null_object_ref;
    }

    return ret;
}

DVM_ObjectRef
DVM_create_array_object(DVM_VirtualMachine *dvm, DVM_Context *context,
                        int size)
{
    DVM_ObjectRef ret;

    ret = dvm_create_array_object_i(dvm, size);
    add_ref_in_native_method(context, &ret);

    return ret;
}

static void
initialize_fields(DVM_VirtualMachine *dvm, ExecClass *ec, DVM_ObjectRef obj)
{
    DVM_Value value;

    value.object = obj;
    dvm_push_object(dvm, value);

    dvm->current_executable = ec->executable;
    dvm->current_function = NULL;
    dvm->pc = 0;
    dvm_expand_stack(dvm, ec->dvm_class->field_initializer.need_stack_size);
    dvm_execute_i(dvm, NULL, ec->dvm_class->field_initializer.code,
                  ec->dvm_class->field_initializer.code_size, 0);

    dvm_pop_object(dvm);
}




DVM_ObjectRef
dvm_create_class_object_i(DVM_VirtualMachine *dvm, int class_index)
{
    ExecClass *ec;
    DVM_ObjectRef obj;
    int i;

    obj = alloc_object(dvm, CLASS_OBJECT);

    ec = dvm->bclass[class_index];
    
    obj.v_table = ec->class_table;

    obj.data->u.class_object.field_count = ec->field_count;
    obj.data->u.class_object.field
        = MEM_malloc(sizeof(DVM_Value) * ec->field_count);
    for (i = 0; i < ec->field_count; i++) {
        dvm_initialize_value(dvm,ec->field_type[i],
                             &obj.data->u.class_object.field[i]);
    }
    initialize_fields(dvm, ec, obj);

    return obj;
}

DVM_ObjectRef
DVM_create_class_object(DVM_VirtualMachine *dvm, DVM_Context *context,
                        int class_index)
{
    DVM_ObjectRef ret;

    ret = dvm_create_class_object_i(dvm, class_index);
    add_ref_in_native_method(context, &ret);

    return ret;
}

static DVM_ObjectRef
create_native_pointer_i(DVM_VirtualMachine *dvm, void *pointer,
                            DVM_NativePointerInfo *info)
{
    DVM_ObjectRef ret;

    ret = alloc_object(dvm, NATIVE_POINTER_OBJECT);
    ret.data->u.native_pointer.pointer = pointer;
    ret.data->u.native_pointer.info = info;
    ret.v_table = NULL;

    return ret;
}

DVM_ObjectRef
DVM_create_native_pointer(DVM_VirtualMachine *dvm, DVM_Context *context,
                          void *pointer, DVM_NativePointerInfo *info)
{
    DVM_ObjectRef ret;

    ret = create_native_pointer_i(dvm, pointer, info);
    add_ref_in_native_method(context, &ret);

    return ret;
}

DVM_ObjectRef
dvm_create_delegate(DVM_VirtualMachine *dvm, DVM_ObjectRef object,
                    int index)
{
    DVM_ObjectRef ret;

    ret = alloc_object(dvm, DELEGATE_OBJECT);
    ret.data->u.delegate.object = object;
    ret.data->u.delegate.index = index;
    ret.v_table = NULL;

    return ret;
}

DVM_Boolean
is_reference_type(DVM_TypeSpecifier *type)
{
    if (((type->basic_type == DVM_STRING_TYPE
          || type->basic_type == DVM_CLASS_TYPE
          || type->basic_type == DVM_DELEGATE_TYPE
          || type->basic_type == DVM_NATIVE_POINTER_TYPE || type->basic_type==DVM_VARIENT_TYPE)
         && type->derive_count == 0)
        || (type->derive_count > 0
            && type->derive[0].tag == DVM_ARRAY_DERIVE)) {
        return DVM_TRUE;
    }
    return DVM_FALSE;
}

void
gc_mark(DVM_ObjectRef *ref)
{
    int i;

    if (ref->data == NULL)
        return;

    if (ref->data->marked)
        return;

    ref->data->marked = DVM_TRUE;

    if (ref->data->type == ARRAY_OBJECT
        && ref->data->u.barray.type == OBJECT_ARRAY) {
        for (i = 0; i < ref->data->u.barray.size; i++) {
            gc_mark(&ref->data->u.barray.u.object[i]);
        }
    }
	else if (ref->data->type == CLASS_OBJECT) {
        ExecClass *ec = ref->v_table->exec_class;
        for (i = 0; i < ec->field_count; i++) {
#if 0
            if (ec->field_type[i]->basic_type == DVM_STRING_TYPE
                || ec->field_type[i]->basic_type == DVM_CLASS_TYPE
                || (ec->field_type[i]->derive_count > 0
                    && ec->field_type[i]->derive[0].tag == DVM_ARRAY_DERIVE)) {
#endif
            if (is_reference_type(ec->field_type[i])) {
                gc_mark(&ref->data->u.class_object.field[i].object);
            }
        }
    } else if (ref->data->type == DELEGATE_OBJECT) {
        gc_mark(&ref->data->u.delegate.object);
    }
	else if(ref->data->type==AUTOVAR_OBJECT)
	{//fix-me : implement object/array reference for Varient Type
		if(ref->data->u.var.pobj->type>AV_DOUBLE)
		{
			gc_mark(&ref->data->u.var.pobj->v.object);
		}
	}

}

static void
gc_mark_ref_in_native_method(DVM_Context *context)
{
    RefInNativeFunc *ref;

    if (context == NULL)
        return;

    for (ref = context->ref_in_native_method; ref; ref = ref->next) {
        gc_mark(&ref->object);
    }
}

static void
gc_reset_mark(DVM_Object *obj)
{
    obj->marked = DVM_FALSE;
}

extern void AvMarkObjects();
static void
gc_mark_objects(DVM_VirtualMachine *dvm)
{
    DVM_Object *obj;
    ExecutableEntry *ee_pos;
    int i;
    DVM_Context *context_pos;

    for (obj = dvm->heap.header; obj; obj = obj->next) {
        gc_reset_mark(obj);
    }

    for (ee_pos = dvm->executable_entry; ee_pos; ee_pos = ee_pos->next) {
        for (i = 0; i < ee_pos->static_v.variable_count; i++) {
            if (is_reference_type(ee_pos->executable
                                  ->global_variable[i].type)) {
                gc_mark(&ee_pos->static_v.variable[i].object);
            }
        }
    }

    for (i = 0; i < dvm->stack.stack_pointer; i++) {
        if (dvm->stack.pointer_flags[i]) {
            gc_mark(&dvm->stack.stack[i].object);
        }
    }
    gc_mark(&dvm->current_exception);
    for (context_pos = dvm->current_context; context_pos;
         context_pos = context_pos->next) {
        gc_mark_ref_in_native_method(context_pos);
    }
    for (context_pos = dvm->free_context; context_pos;
         context_pos = context_pos->next) {
        gc_mark_ref_in_native_method(context_pos);
    }
	AvMarkObjects();
}

static DVM_Boolean
gc_dispose_object(DVM_VirtualMachine *dvm, DVM_Object *obj)
{
    DVM_Boolean call_finalizer = DVM_FALSE;

    switch (obj->type) {
    case STRING_OBJECT:
        if (!obj->u.string.is_literal) {
            dvm->heap.current_heap_size
                -= sizeof(DVM_Char) * (dvm_wcslen(obj->u.string.string) + 1);
            MEM_free(obj->u.string.string);
        }
		else
		{	
			if(curdvm->static_str_map)
				RtlHashmapPut(curdvm->static_str_map,(BdIntPtr)obj->u.string.string,dvm_null_object_ref);
		}
        break;
	case AUTOVAR_OBJECT:
		if(!obj->u.var.is_literal)
		{
			dvm->heap.current_heap_size-=sizeof(ExVarient);
			MEM_free(obj->u.var.pobj);
		}
		break;
    case ARRAY_OBJECT:
        switch (obj->u.barray.type) {
        case INT_ARRAY:
            dvm->heap.current_heap_size
                -= sizeof(int) * obj->u.barray.alloc_size;
            MEM_free(obj->u.barray.u.int_array);
            break;
        case DOUBLE_ARRAY:
            dvm->heap.current_heap_size
                -= sizeof(double) * obj->u.barray.alloc_size;
            MEM_free(obj->u.barray.u.double_array);
            break;
        case OBJECT_ARRAY:
            dvm->heap.current_heap_size
                -= sizeof(DVM_Object*) * obj->u.barray.alloc_size;
            MEM_free(obj->u.barray.u.object);
            break;
		case VARIENT_ARRAY:
			_BreakPoint()//fix-me
			break;
        case FUNCTION_INDEX_ARRAY:
            dvm->heap.current_heap_size
                -= sizeof(int) * obj->u.barray.alloc_size;
            MEM_free(obj->u.barray.u.function_index);
        default:
            DBG_assert(0, ("barray.type..%d", obj->u.barray.type));
        }
        break;
    case CLASS_OBJECT:
        dvm->heap.current_heap_size
            -= sizeof(DVM_Value) * obj->u.class_object.field_count;
        MEM_free(obj->u.class_object.field);
        break;
    case NATIVE_POINTER_OBJECT:
        if (obj->u.native_pointer.info->finalizer) {
            obj->u.native_pointer.info->finalizer(dvm, obj);
            call_finalizer = DVM_TRUE;
        }
        break;

    case DELEGATE_OBJECT:
        break;
    case OBJECT_TYPE_COUNT_PLUS_1:
    default:
        DBG_assert(0, ("bad type..%d\n", obj->type));
    }
    dvm->heap.current_heap_size -= sizeof(DVM_Object);
	obj->type = ExHeapFreedType;
    MEM_free(obj);

    return call_finalizer;
}

static DVM_Boolean
gc_sweep_objects(DVM_VirtualMachine *dvm)
{
    DVM_Object *obj;
    DVM_Object *tmp;
    DVM_Boolean call_finalizer = DVM_FALSE;

    for (obj = dvm->heap.header; obj; ) {
        if (!obj->marked) {
            if (obj->prev) {
                obj->prev->next = obj->next;
            } else {
                dvm->heap.header = obj->next;
            }
            if (obj->next) {
                obj->next->prev = obj->prev;
            }
            tmp = obj->next;
            if (gc_dispose_object(dvm, obj)) {
                call_finalizer = DVM_TRUE;
            }
            obj = tmp;
        } else {
            obj = obj->next;
        }
    }
    return call_finalizer;
}

void
dvm_garbage_collect(DVM_VirtualMachine *dvm)
{
    DVM_Boolean call_finalizer;
    do {
        gc_mark_objects(dvm);
        call_finalizer = gc_sweep_objects(dvm);
    } while(call_finalizer);
}
