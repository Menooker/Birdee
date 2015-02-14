﻿#include <string.h>
#include "diksamc.h"

ErrorDefinition dkc_error_message_format[] = {
    {"dummy"},
    {"在($(token))附近发生语法错误"},
    {"不正确的字符($(bad_char))"},
    {"函数名重复($(name))"},
    {"不正确的多字节字符。"},
    {"预期外的宽字符串。"},
    {"数组元素不能标识为final。"},
    {"复合赋值运算符不能用于final值"},
    {"函数的参数名重复($(name))。"},
    {"变量名$(name)重复。"},
    {"找不到变量或函数$(name)。"},
    {"$(name)是函数名，但没有函数调用的()。"},
    {"不能强制转型为派生类型。"},
    {"不能将$(src)转型为$(dest)。"},
    {"算数运算符的操作数类型不正确。"},
    {"比较运算符的操作数类型不正确。"},
    {"逻辑and/or运算符的操作数类型不正确。"},
    {"减法运算符的操作数类型不正确。"},
    {"逻辑非运算符的操作数类型不正确。"},
    {"自增/自减运算符的操作数类型不正确。"},
    {"函数调用运算符的操作数不是函数名。"},
    {"找不到函数$(name)。"},
    {"函数的参数数量错误。"},
    {"赋值运算符的左边不是一个左边值。"},
    {"标签$(label)不存在。"},
    {"数组字面量必须至少有一个元素"},
    {"下标运算符[]的左边不是数组类型"},
    {"数组的下标不是int。"},
    {"数组的大小不是int。"},
    {"整数值不能被0除。"},
    {"package名称过长"},
    {"被require的文件不存在($(file))"},
    {"require时发生错误($(status))。"},
    {"同一个源文件中重复require了同一个包。"},
    {"rename后的名称必须指定package。"},
    {"重复声明了abstract。"},
    {"重复声明了访问修饰符。"},
    {"重复声明了override。"},
    {"重复声明了virtual。"},
    {"该类型不能使用成员运算符。"},
    {"在类型$(class_name)中不存在成员$(member_name)。"},
    {"成员$(member_name)是private的，不能访问。"},
    {"没有实现abstract方法。"},
    {"必须实现非abstract方法。"},
    {"不能继承多个类。"},
    {"Diksam中不能继承非abstract的类"
     "(类$(name)不是abstract类)。"},
    {"不能对abstract类($(name))使用new。"},
    {"void类型的函数不能有返回值。"},
    {"没有找到类$(name)。"},
    {"成员$(member_name)被声明为构造方法。并不是方法。"},
    {"用来new的方法$(member_name)并不是构造方法。"},
    {"不能调用字段$(member_name)"},
    {"尝试为方法$(member_name)赋值。"},
    {"不能覆盖非virtual方法$(name)。"},
    {"覆盖方法时必须使用override关键字($(name))。"},
    {"在abstract类中，存在非abstract方法$(method_name)。"},
    {"在没有超类的类中使用了super。"},
    {"方法调用以外不能使用super。"},
    {"不能引用super的字段。"},
    {"$(name)是字段，不能覆盖。"},
    {"重复的字段名$(name)。"},
    {"数组中没有$(name)方法。"},
    {"数组中没有$(name)方法。"},
    {"instanceof的操作数必须是引用类型。"},
    {"instanceof的右边的类型必须是引用类型。"},
    {"instanceof的目标必须是类。"},
    {"instanceof语句一直为真。"},
    {"instanceof语句一直为假。"},
    {"因为Diksam的接口间没有父子关系"
     "instanceof语句一直为假。"},
    {"向下转型的源类型必须是类。"},
    {"向下转型的目标类型必须是类。"},
    {"不需要进行向下转型。"},
    {"尝试将父类转换为子类。"},
    {"尝试转换没有继承关系的类。"},
    {"因为Diksam的接口间没有父子关系"
     "不能向下转型。"},
    {"不能catch类以外的类型。"},
    {"catch到的类$(class_name)不是Exception的子类。"},
    {"不能throw类以外的类型。"},
    {"throw的类$(class_name)不是Exception的子类。"},
    {"catch之外不能出现没有操作数的throw。"},
    {"$(statement_name)语句不能卸载finally块中。"},
    {"找不到throws中声明的$(name)。"},
    {"throws中声明的$(name)不是Exception的子类。"},
    {"在throws块中声明的异常$(name)，必须在内部catch。"},
    {"不能require文件本身。"},
    {"if语句的条件表达式不是boolean型。"},
    {"while语句的条件表达式不是boolean型。"},
    {"for语句的条件表达式不是boolean型。"},
    {"do while语句的条件表达式不是boolean型。"},
    {"case块的表达式的类型不一致"},
    {"$(name)为final变量。不能赋值。"},
    {"$(name)为final字段。不能赋值。"},
    {"final变量$(name)没有初始化。"},
    {"被覆盖的方法$(name)的访问修饰符必须比超类的更严格。"},
    {"方法或函数$(name)的参数数量错误。"},
    {"方法或函数$(func_name)的第$(index)个参数"
	 "$(param_name)的类型错误。"},
    {"方法或函数$(name)的返回值类型错误。"},
    {"方法或函数$(func_name)描述的throws中含有不恰当的异常$(exception_name)。"},
    {"不能直接调用构造方法。"},
    {"找不到类型名$(name)。"},
    {"枚举类型$(type_name)中没有$(enumerator_name)。"},
    {"Diksam的接口之间不能继承（至今为止）。"},
    {"不能从包外访问成员$(member_name)。"},
    {"不能从包外访问类$(class_name)。"},
    {"不能在类外使用this。"},
    {"不能在类外使用super。"},
    {"~运算符的操作数必须是int。"},
    {"双目bite运算符的操作数必须是int或者boolean。"},
    {"在C样式的注释中终止了文件。"},
    {"在字符串字面量中终止了文件。"},
    {"字符字面量中包含了2个以上的字符。"},
	{"使用了一个以上的lib块"},
    {"dummy"}
};
