%option   caseless
%{
#undef YY_INPUT
#define YY_INPUT(buf, result, max_size) (result = my_yyinput(buf, max_size))
#include <stdio.h>
#include <string.h>
#include "DBG.h"
#include "diksamc.h"
#include "y.tab.h"

#ifdef __cplusplus
extern "C"
{
#endif

static int
file_input(char *buf, int max_size)
{
    int ch;
    int len;

    if (feof(yyin))
        return 0;

    for (len = 0; len < max_size; len++) {
        ch = getc(yyin);
        if (ch == EOF)
            break;
        buf[len] = ch;
    }
    return len;
}

static char **st_source_string;
static int st_current_source_line;
static int st_current_char_index;
static int isInSwitch=0;

void
dkc_set_source_string(char **source)
{
    st_source_string = source;
    st_current_source_line = 0;
    st_current_char_index = 0;
}

static int
string_input(char *buf, int max_size)
{
    int len;

    if (st_source_string[st_current_source_line] == NULL)
        return 0;

    while (st_source_string[st_current_source_line][st_current_char_index]
        == '\0') {
        st_current_source_line++;
        st_current_char_index = 0;
        if (st_source_string[st_current_source_line] == NULL)
            return 0;
    }

    if (st_source_string[st_current_source_line] == NULL)
        return 0;

    len = smaller(strlen(st_source_string[st_current_source_line])
                  - st_current_char_index,
                  max_size-1);//modified
	buf[max_size-1]=0;   //modified
    strncpy(buf,
            &st_source_string[st_current_source_line][st_current_char_index],
            len+1);//modified
    st_current_char_index += len;
	/*len=strlen("function print(str as string) as void end\n");
	strncpy(buf,"function print(str as string) as void end\n",len+1);*/
	//printf("STR INPUT:\n%s{END}",buf);
    return len;
}

static int
my_yyinput(char *buf, int max_size)
{
    int result;

    switch (dkc_get_current_compiler()->input_mode) {
    case FILE_INPUT_MODE:
        result = file_input(buf, max_size);
        break;
    case STRING_INPUT_MODE:
        result = string_input(buf, max_size);
        break;
    default:
        DBG_panic(("bad default. input_mode..%d\n",
                   dkc_get_current_compiler()->input_mode));
    }

    return result;
}


int
yywrap(void)
{
    return 1;
}

static void
increment_line_number(void)
{
    dkc_get_current_compiler()->current_line_number++;
}

static void
increment_line_number_int(int i)
{
    dkc_get_current_compiler()->current_line_number+=i;
}

DVM_Boolean st_character_literal_state;

#ifdef __cplusplus
}
#endif

%}
%start C_COMMENT CC_COMMENT STRING_LITERAL_STATE SHIFT_JIS_2ND_CHAR CHK_END_BLOCK
%%
<INITIAL>"if"           return IF;
<INITIAL>"else"         return ELSE;
<INITIAL>"elseif"       return ELSIF;
<INITIAL>"select"       {isInSwitch=1; return SWITCH;}
<INITIAL>"select case"  {isInSwitch=1; return SWITCH;}
<INITIAL>"case"         return CASE;
<INITIAL>"default"      return DEFAULT_T;
<INITIAL>"while"        return WHILE;
<INITIAL>"do"           return DO_T;
<INITIAL>"for"          return FOR;
<INITIAL>"foreach"      return FOREACH;
<INITIAL>"return"       return RETURN_T;
<INITIAL>"break"        return BREAK;
<INITIAL>"continue"     return CONTINUE;
<INITIAL>"null"         return NULL_T;
<INITIAL>"true"         return TRUE_T;
<INITIAL>"false"        return FALSE_T;
<INITIAL>"try"          return TRY;
<INITIAL>"catch"        return CATCH;
<INITIAL>"finally"      return FINALLY;
<INITIAL>"throw"        return THROW;
<INITIAL>"throws"       return THROWS;
<INITIAL>"boolean"      return BOOLEAN_T;
<INITIAL>"void"         return VOID_T;
<INITIAL>"int"          return INT_T;
<INITIAL>"double"       return DOUBLE_T;
<INITIAL>"string"       return STRING_T;
<INITIAL>"var"			return VARIENT_T;
<INITIAL>"float"		return FLOAT_T;
<INITIAL>"native_pointer"       return NATIVE_POINTER_T;
<INITIAL>"new"          return NEW;
<INITIAL>"require"      return REQUIRE;
<INITIAL>"rename"       return RENAME;
<INITIAL>"class"        return CLASS_T;
<INITIAL>"interface"    return INTERFACE_T;
<INITIAL>"public"       return PUBLIC_T;
<INITIAL>"private"      return PRIVATE_T;
<INITIAL>"virtual"      return VIRTUAL_T;
<INITIAL>"override"     return OVERRIDE_T;
<INITIAL>"abstract"     return ABSTRACT_T;
<INITIAL>"this"         return THIS_T;
<INITIAL>"super"        return SUPER_T;
<INITIAL>"constructor"  return CONSTRUCTOR;
<INITIAL>"instanceof"   return INSTANCEOF;
<INITIAL>"delegate"     return DELEGATE;
<INITIAL>"enum"         return ENUM;
<INITIAL>"final"        return FINAL;
<INITIAL>"const"        return CONST;
<INITIAL>"("            return LP;
<INITIAL>")"            return RP;
<INITIAL>"..."          return APOSTROPHE;
<INITIAL>"unsafe"          return UNSAFE;
<INITIAL>"safe"          return SAFE;
<INITIAL>"shared"        return SHARED;
<INITIAL>"global"        return GLOBAL;
<INITIAL>"volatile"      return VOLATILE;

<INITIAL>"{"          {return LC;}
<INITIAL>"}"          {return RC;}
<INITIAL>[\n]+          {increment_line_number_int(yyleng);  BEGIN CHK_END_BLOCK;  return CR;}
<INITIAL>"["            return LB;
<INITIAL>"]"            return RB;
<INITIAL>";"            return SEMICOLON;
<INITIAL>":"            return COLON;
<INITIAL>","            return COMMA;
<INITIAL>"&&"           return LOGICAL_AND;
<INITIAL>"||"           return LOGICAL_OR;
<INITIAL>"="            return ASSIGN_T;
<INITIAL>"=="           return EQ;
<INITIAL>"!="           return NE;
<INITIAL>">"            return GT;
<INITIAL>">="           return GE;
<INITIAL>"<"            return LT;
<INITIAL>"<="           return LE;
<INITIAL>"+"            return ADD;
<INITIAL>"-"            return SUB;
<INITIAL>"*"            return MUL;
<INITIAL>"/"            return DIV;
<INITIAL>"%"            return MOD;
<INITIAL>"&"            return BIT_AND;
<INITIAL>"|"            return BIT_OR;
<INITIAL>"^"            return BIT_XOR;
<INITIAL>"~"            return BIT_NOT;
<INITIAL>"+="           return ADD_ASSIGN_T;
<INITIAL>"-="           return SUB_ASSIGN_T;
<INITIAL>"@+="          return ATM_ADD_ASSIGN_T;
<INITIAL>"@-="          return ATM_SUB_ASSIGN_T;
<INITIAL>"*="           return MUL_ASSIGN_T;
<INITIAL>"/="           return DIV_ASSIGN_T;
<INITIAL>"%="           return MOD_ASSIGN_T;
<INITIAL>"++"           return INCREMENT;
<INITIAL>"--"           return DECREMENT;
<INITIAL>"!"            return EXCLAMATION;
<INITIAL>"."            return DOT;
<INITIAL>"::"           return DOWN_CAST_BEGIN;
<INITIAL>":>"           return DOWN_CAST_END;
<INITIAL>"as"           return AS;
<INITIAL>"then"         return THEN;
<INITIAL>"function"     return FUNCTION;
<INITIAL>"sub"          return BSUB;
<INITIAL>"dim"          return DIM;
<INITIAL>"declare"      return DECLARE;
<INITIAL>"lib"			return LIB;
<INITIAL>"end\n"        {increment_line_number(); BEGIN CHK_END_BLOCK; return END;}//


<CHK_END_BLOCK><<EOF>>  BEGIN INITIAL;
<CHK_END_BLOCK>[\n]+          {increment_line_number_int(yyleng);}
<CHK_END_BLOCK>[ \t] ;
<CHK_END_BLOCK>"catch" {
		yyless(0);
		BEGIN INITIAL;
        return END;
		};
<CHK_END_BLOCK>"default" {
		yyless(0);
		BEGIN INITIAL;
        return END;
		};
<CHK_END_BLOCK>"case" {
		yyless(0);
		BEGIN INITIAL;
		if(isInSwitch){
			isInSwitch=0;
		}
		else{
			return END;
		}
		};
<CHK_END_BLOCK>"finally" {
		yyless(0);
		BEGIN INITIAL;
        return END;
		};
<CHK_END_BLOCK>"else" {
		//printf("ELSE BLOCK END %d\n",dkc_get_current_compiler()->current_line_number);
		yyless(0);
		BEGIN INITIAL;
        return END;
		};
<CHK_END_BLOCK>"elseif" {
		yyless(0);
		BEGIN INITIAL;
        return END;
		};
<CHK_END_BLOCK>. {
		//printf("PASS @%d %s\n", dkc_get_current_compiler()->current_line_number,yytext);
		yyless(0);
		BEGIN INITIAL;

		};
<INITIAL>[#$][A-Za-z_][A-Za-z_0-9]* {
    yylval.identifier = dkc_create_identifier(yytext);
    return AUTOVAR;
}
<INITIAL>[A-Za-z_][A-Za-z_0-9]* {
    yylval.identifier = dkc_create_identifier(yytext);
    return IDENTIFIER;
}
<INITIAL>[1-9][0-9]* {
    Expression  *expression = dkc_alloc_expression(INT_EXPRESSION);
    sscanf(yytext, "%d", &expression->u.int_value);
    yylval.expression = expression;
    return INT_LITERAL;
}
<INITIAL>"0"[xX][0-9a-fA-F]+ {
    Expression  *expression = dkc_alloc_expression(INT_EXPRESSION);
    sscanf(yytext, "%x", &expression->u.int_value);
    yylval.expression = expression;
    return INT_LITERAL;
}
<INITIAL>"0" {
    Expression  *expression = dkc_alloc_expression(INT_EXPRESSION);
    expression->u.int_value = 0;
    yylval.expression = expression;
    return INT_LITERAL;
}
<INITIAL>[0-9]+\.[0-9]+(f) {
    Expression  *expression = dkc_alloc_expression(FLOAT_EXPRESSION);
    sscanf(yytext, "%lf", &expression->u.double_value);
    yylval.expression = expression;
    return FLOAT_LITERAL;
}
<INITIAL>[0-9]+\.[0-9]+(d) {
    Expression  *expression = dkc_alloc_expression(DOUBLE_EXPRESSION);
    sscanf(yytext, "%lf", &expression->u.double_value);
    yylval.expression = expression;
    return DOUBLE_LITERAL;
}
<INITIAL>[0-9]+\.[0-9]+ {
    Expression  *expression = dkc_alloc_expression(DOUBLE_EXPRESSION);
    sscanf(yytext, "%lf", &expression->u.double_value);
    yylval.expression = expression;
    return DOUBLE_LITERAL;
}
<INITIAL>\" {
    dkc_open_string_literal();
    st_character_literal_state = DVM_FALSE;
    BEGIN STRING_LITERAL_STATE;
}
<INITIAL>\' {
    dkc_open_string_literal();
    st_character_literal_state = DVM_TRUE;
    BEGIN STRING_LITERAL_STATE;
}
<INITIAL>[ \t] ;
<INITIAL>[\r\n] {increment_line_number_int(yyleng);BEGIN CHK_END_BLOCK;}
<INITIAL>"/*"     BEGIN C_COMMENT;
<INITIAL>"//"     BEGIN CC_COMMENT;
<INITIAL>.      {
    dkc_compile_error(dkc_get_current_compiler()->current_line_number,
                      CHARACTER_INVALID_ERR,
                      CHARACTER_MESSAGE_ARGUMENT, "bad_char", yytext[0],
                      MESSAGE_ARGUMENT_END);
}
<C_COMMENT>\n     {increment_line_number();}
<C_COMMENT>"*/"     {
    BEGIN INITIAL;
}
<C_COMMENT><<EOF>> {
    dkc_compile_error(dkc_get_current_compiler()->current_line_number,
                      EOF_IN_C_COMMENT_ERR,
                      MESSAGE_ARGUMENT_END);
}
<C_COMMENT>.      ;
<CC_COMMENT>\n  {
    increment_line_number();
	BEGIN CHK_END_BLOCK;
    //BEGIN INITIAL;
}
<CC_COMMENT><<EOF>>   BEGIN INITIAL;
<CC_COMMENT>.   ;
<STRING_LITERAL_STATE>\"        {
    if (st_character_literal_state) {
        dkc_add_string_literal('\"');
    } else {
        Expression *expression = dkc_alloc_expression(STRING_EXPRESSION);
        expression->u.string_value = dkc_close_string_literal();
        yylval.expression = expression;
        BEGIN INITIAL;
        return STRING_LITERAL;
    }
}
<STRING_LITERAL_STATE>\'        {
    if (st_character_literal_state) {
        Expression *expression = dkc_alloc_expression(INT_EXPRESSION);
        expression->u.int_value = dkc_close_character_literal();
        yylval.expression = expression;
        BEGIN INITIAL;
        return INT_LITERAL;
    } else {
        dkc_add_string_literal('\'');
    }
}
<STRING_LITERAL_STATE>\n        {
    dkc_add_string_literal('\n');
    increment_line_number();
}
<STRING_LITERAL_STATE>\\\"      dkc_add_string_literal('"');
<STRING_LITERAL_STATE>\\n       dkc_add_string_literal('\n');
<STRING_LITERAL_STATE>\\t       dkc_add_string_literal('\t');
<STRING_LITERAL_STATE>\\\\      dkc_add_string_literal('\\');
<STRING_LITERAL_STATE>[\x81-\x9f\xe0-\xef][\x40-\x7e\x80-\xfc] {
  dkc_add_string_literal(yytext[0]);
  dkc_add_string_literal(yytext[1]);
}
<STRING_LITERAL_STATE><<EOF>>   {
    dkc_compile_error(dkc_get_current_compiler()->current_line_number,
                      EOF_IN_STRING_LITERAL_ERR,
                      MESSAGE_ARGUMENT_END);
}
<STRING_LITERAL_STATE>.         {
    Encoding enc = dkc_get_current_compiler()->source_encoding;
    dkc_add_string_literal(yytext[0]);
    if (enc == SHIFT_JIS_ENCODING
        && ((((unsigned char*)yytext)[0] >= 0x81
             && ((unsigned char*)yytext)[0] <= 0x9e)
            || (((unsigned char*)yytext)[0] >= 0xe0
                && ((unsigned char*)yytext)[0] <= 0xef))) {
        BEGIN SHIFT_JIS_2ND_CHAR;
    }
}
<SHIFT_JIS_2ND_CHAR>. {
    dkc_add_string_literal(yytext[0]);
    BEGIN STRING_LITERAL_STATE;
}



%%
