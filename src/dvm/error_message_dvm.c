﻿#include <string.h>
#include "dvm_pri.h"

DVM_ErrorDefinition dvm_error_message_format[] = {
    {L"dummy"},
    {L"不正确的多字节字符。"},
    {L"找不到函数$(name)。"},
    {L"重复定义了函数$(package)#$(name)。"},
    {L"数组下标越界。数组大小为$(size)，访问的下标为[$(index)]。"},
    {L"整数值不能被0除。"},
    {L"引用了null。"},
    {L"没有找到要加载的文件$(file)"},
    {L"加载文件时发生错误($(status))。"},
    {L"重复定义了类$(package)#$(name)。"},
    {L"没有找到类$(name)。"},
    {L"对象的类型为$(org)。"
     L"不能向下转型为$(target)。"},
    {L"重复定义了枚举类型$(package)#$(name)。"},
    {L"重复定义了字面量$(package)#$(name)。"},
    {L"由于函数$(name)没有指定包，不能动态加载。"},
    {L"Object类没有被加载。"},
    {L"dummy"}
};

DVM_ErrorDefinition dvm_native_error_message_format[] = {
    {L"数组下标越界。尝试为大小为$(size)的数组insert元素到$(pos)"},
    {L"数组下标越界。尝试为大小为$(size)的数组remove元素$(pos)"},
    {L"指定的位置超出字符串长度。"
     L"为长度为$(len)的字符串指定了$(pos)。"},
    {L"字符串substr()的第二个参数(截取字符串的长度)超出范围($(len))。"},
    {L"传递给fopen的第1个参数为null。"},
    {L"传递给fopen的第2个参数为null。"},
    {L"传递给fgets文件指针为null。"},
    {L"fgets的参数类型错误。"},
    {L"传递给fgets文件指针无效。"
     L"文件可能已经关闭。"},
    {L"fgets读取的多字节字符串不能转换为内部表达式。"},
    {L"fputs第2个参数文件指针为null。"},
    {L"fputs的参数类型错误。"},
    {L"传递给fputs的文件指针无效"
     L"文件可能已经关闭。"},
    {L"fclose的参数为null。"},
    {L"fclose的参数类型错误。"},
    {L"传递给fclose的文件指针无效。"
     L"可能已经关闭。"},
    {L"parse_int()的参数为null。"},
    {L"parse_int()格式化错误。字符串:「$(str)」"},
    {L"parse_double()的参数为null。"},
    {L"parse_double()格式化错误。字符串:「$(str)」"},
};
