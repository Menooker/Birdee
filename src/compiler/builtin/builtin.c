#include <stdio.h>
#include "diksamc.h"


char *st_diksam_lang_dkh_text[] = {
	"dim args as string[]\n",
	"declare function print(str as string) as void \n\n",
	"declare sub Invoke(pac as string,name as string,...)\n",
	"declare sub GetFunction(del as delegate,pac as string,name as string)\n",
	"declare sub BreakPoint()\n",
	"declare function GetClock() as int\n",
	"declare function gets() as string\n",
	"delegate thread_proc(arg as var) as int\n",
	"declare function CreateThread(proc as thread_proc,run_now as boolean,arg as var) as int\n",
	"declare sub SuspendThread(tid as int)\n",
	"declare sub ResumeThread(tid as int)\n",
	"declare sub JoinThread(tid as int)\n",
	"declare sub Sleep(ms as int)\n",
    "sub println(str as string) \n",
    "    print(str )\n",
	"	print( \"\\n\")\n",
    "end\n",
	"public class CSVReader\n",
	"	public _path as string\n",
	"	dim fd as int\n",
	"	public declare constructor initialize(path as string)\n",
	"	public declare function ReadLine(arr as double[],idx as int) as int\n",
	"	public declare function ReadLineString(arr as string[],idx as int) as int\n",
	"	public declare sub Reset()\n",
	"	public declare sub Close()\n",
	"	public declare sub Skip(lines as int)\n",
	"	public declare function ReadDouble() as double\n",
	"end\n",
	"declare function LoadNativeLibrary(path as string) as boolean\n",
	"function GetArgs() as string[]\n",
	"	return args\n",
	"end\n",

/*	"shared public class RemoteThread\n",
	"	public final tid as int\n",
	"	dim state as int\n",
	"	public function getState() as int\n",
	"		return state\n",
	"	end\n",
	"	public function Join(timeout as int,maxinterval as int) as boolean\n",
	"		dim t as int\n",
	"		dim itv as int=8\n",
	"		for t=0 ; state!=3 ;\n",
	"			if  timeout!=-1 && t>timeout then\n",
	"				return false\n",
	"			end\n",
	"			itv=itv*2\n",
	"			if itv>maxinterval then\n",
	"				itv=16\n",
	"			end\n",
	"			t+=itv\n",
	"			Sleep(itv)\n",
	"		end\n",
	"		println(\"@\"+ t +\"-\"+ itv)\n",
	"		return true\n",
	"	end\n",
	"	//public declare sub Pause()\n",
	"	//public declare sub Stop()\n",
	"end\n",
	"declare function ConnectNode(host as String,port as int) as RemoteNode\n",*/
    /*"class StackTrace \n",
    "    public line_number as int\n",
    "    dim file_name as string\n",
    "    dim function_name as string\n",
    "end\n",
    "\n",
    "abstract public class Exception \n",
    "    public message as string\n",
    "    public stack_trace as StackTrace[]\n",
    "    public sub print_stack_trace() \n",
    "	 dim i as int\n",
    "	 println(\"Exception occured. \" + this.message + \"\\nStack Trace:\" )\n",
	"    for i=0;i<this.stack_trace.size();i++\n",
	"		println(this.stack_trace[i].function_name)\n",
	"	 end\n",
    "    end\n",
    "    public virtual constructor initialize() \n",
    "\tthis.stack_trace = new StackTrace[0]\n",
    "    end\n",
    "end\n",
    "\n",
    "abstract public class BugException : Exception \n",
    "end\n",
    "\n",
    "abstract public class RuntimeException : Exception \n",
    "end\n",
    "\n",
    "public class NullPointerException : BugException \n",
    "end\n",
    "\n",
    "public class ArrayIndexOutOfBoundsException : BugException \n",
    "end\n",
    "\n",
    "public class StringIndexOutOfBoundsException : BugException \n",
    "end\n",
    "\n",
    "public class DivisionByZeroException : RuntimeException \n",
    "end\n",
    "\n",
    "public class MultibyteCharacterConvertionException : RuntimeException \n",
    "end\n",
    "\n",
    "public class ClassCastException : BugException \n",
    "end\n",
    "\n",
    "public abstract class ApplicationException : Exception \n",
    "end\n",
    "\n",
    "public class NumberFormatException : ApplicationException \n",
    "end\n",//*/
	0}; //"declare function log10(z as double) as double\n\n"
/*{
    "void print(string str);\n",

    "\n",
    "public class File {\n",
    "    native_pointer fp;\n",
    "    constructor initialize(native_pointer fp) {\n",
    "\tthis.fp = fp;\n",
    "    }\n",
    "}\n",
    "\n",
    "File fopen(string file_name, string mode);\n",
    "string fgets(File file);\n",
    "void fputs(string str, File file);\n",
    "void fclose(File file);\n",
    "\n",
    "double to_double(int int_value) {\n",
    "    return int_value;\n",
    "}\n",
    "\n",
    "int to_int(double double_value) {\n",
    "    return double_value;\n",
    "}\n",
    "\n",
    "int parse_int(string str) throws NumberFormatException;\n",
    "double parse_double(string str) throws NumberFormatException;\n",
    "\n",
    "void exit(int status);\n",
    "void randomize();\n",
    "int random(int range);\n",
    "\n",
    "class StackTrace {\n",
    "    int\tline_number;\n",
    "    string file_name;\n",
    "    string function_name;\n",
    "}\n",
    "\n",
    "abstract public class Exception {\n",
    "    public string message;\n",
    "    public StackTrace[] stack_trace;\n",
    "    public void print_stack_trace() {\n",
    "\tint i;\n",
    "\tprintln(\"Exception occured. \" + this.message);\n",
    "\tfor (i = 0; i < this.stack_trace.size(); i++) {\n",
    "\t    println(\"\\tat \" \n",
    "\t\t    + this.stack_trace[i].function_name\n",
    "\t\t    + \"(\" + this.stack_trace[i].file_name\n",
    "\t\t    + \":\" + this.stack_trace[i].line_number + \")\");\n",
    "\t}\n",
    "    }\n",
    "    public virtual constructor initialize() {\n",
    "\tthis.stack_trace = new StackTrace[0];\n",
    "    }\n",
    "}\n",
    "\n",
    "abstract public class BugException : Exception {\n",
    "}\n",
    "\n",
    "abstract public class RuntimeException : Exception {\n",
    "}\n",
    "\n",
    "public class NullPointerException : BugException {\n",
    "}\n",
    "\n",
    "public class ArrayIndexOutOfBoundsException : BugException {\n",
    "}\n",
    "\n",
    "public class StringIndexOutOfBoundsException : BugException {\n",
    "}\n",
    "\n",
    "public class DivisionByZeroException : RuntimeException {\n",
    "}\n",
    "\n",
    "public class MultibyteCharacterConvertionException : RuntimeException {\n",
    "}\n",
    "\n",
    "public class ClassCastException : BugException {\n",
    "}\n",
    "\n",
    "public abstract class ApplicationException : Exception {\n",
    "}\n",
    "\n",
    "public class NumberFormatException : ApplicationException {\n",
    "}\n",
    "\n",
    "delegate int HogeDelegate(int value);\n",
    "\n",
    "// BUGBUG for test routine\n",
    "void test_native(HogeDelegate dele);\n",
    "\n",
    "void foo_file(File file) {\n",
    "}\n",
    NULL
};*/
char *st_diksam_lang_dkm_text[] ={"require diksam.lang;\n",
	"sub println(str as string) \n",
    "    print(str + \"\\n\")\n",
    "end\n",
	0};/* {

    "\n",
    "native_pointer __fopen(string file_name, string mode);\n",
    "string __fgets(native_pointer fp);\n",
    "void __fputs(string str, native_pointer fp);\n",
    "void __fclose(native_pointer fp);\n",
    "\n",
    "File fopen(string file_name, string mode) {\n",
    "    native_pointer fp = __fopen(file_name, mode);\n",
    "    if (fp == null) {\n",
    "\treturn null;\n",
    "    } else {\n",
    "\treturn new File(fp);\n",
    "    }\n",
    "}\n",
    "\n",
    "string fgets(File file) {\n",
    "    return __fgets(file.fp);\n",
    "}\n",
    "\n",
    "void fputs(string str, File file) {\n",
    "    __fputs(str, file.fp);\n",
    "}\n",
    "\n",
    "void fclose(File file) {\n",
    "    __fclose(file.fp);\n",
    "}\n",
    NULL
};*/
char *st_diksam_math_dkh_text[] ={
	"declare function exp(v as double) as double\n",
	"declare function rand(max as int) as int\n\n",
	0
	};/* {
    "double fabs(double z);\n",
    "double pow(double z, double x);\n",
    "double fmod(double number, double divisor);\n",
    "double ceil(double z);\n",
    "double floor(double z);\n",
    "double sqrt(double z);\n",
    "double exp(double z);\n",
    "double log10(double z);\n",
    "double log(double z);\n",
    "double sin(double radian);\n",
    "double cos(double radian);\n",
    "double tan(double radian);\n",
    "double asin(double arg);\n",
    "double acos(double arg);\n",
    "double atan(double arg);\n",
    "double atan2(double num, double den);\n",
    "double sinh(double value);\n",
    "double cosh(double value);\n",
    "double tanh(double value);\n",
    NULL
};*/

BuiltinScript dkc_builtin_script[] = {
    {"diksam.lang", DKH_SOURCE, st_diksam_lang_dkh_text},
    //{"diksam.lang", DKM_SOURCE, st_diksam_lang_dkm_text},
    {"math", DKH_SOURCE, st_diksam_math_dkh_text},
    {NULL, DKM_SOURCE, NULL}
};
