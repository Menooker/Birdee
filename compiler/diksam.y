%{
#include <stdio.h>
#include "diksamc.h"
#define YYDEBUG 1
%}
%union {
    char                *identifier;
    PackageName         *package_name;
    RequireList         *require_list;
    RenameList          *rename_list;
    ParameterList       *parameter_list;
    ArgumentList        *argument_list;
    Expression          *expression;
    ExpressionList      *expression_list;
    Statement           *statement;
    StatementList       *statement_list;
    Block               *block;
    Elsif               *elsif;
    CaseList            *case_list;
    CatchClause         *catch_clause;
    AssignmentOperator  assignment_operator;
    TypeSpecifier       *type_specifier;
    DVM_BasicType       basic_type_specifier;
    ArrayDimension      *array_dimension;
    ClassOrMemberModifierList class_or_member_modifier;
    DVM_ClassOrInterface class_or_interface;
    ExtendsList         *extends_list;
    MemberDeclaration   *member_declaration;
    FunctionDefinition  *function_definition;
    ExceptionList       *exception_list;
    Enumerator          *enumerator;
	int					intval;
	TemplateTypes		*template;
	TemplateDeclare     *template_def;
}
%token <expression>     INT_LITERAL
%token <expression>     DOUBLE_LITERAL
%token <expression>     STRING_LITERAL
%token <expression>     REGEXP_LITERAL
%token <identifier>     IDENTIFIER
%token <identifier>     AUTOVAR
%token IF ELSE ELSIF SWITCH CASE DEFAULT_T WHILE DO_T FOR FOREACH
        RETURN_T BREAK CONTINUE NULL_T
        LP RP LC RC LB RB SEMICOLON COLON COMMA ASSIGN_T LOGICAL_AND LOGICAL_OR
        EQ NE GT GE LT LE ADD SUB MUL DIV MOD BIT_AND BIT_OR BIT_XOR BIT_NOT
        TRUE_T FALSE_T EXCLAMATION DOT
        ADD_ASSIGN_T SUB_ASSIGN_T MUL_ASSIGN_T DIV_ASSIGN_T MOD_ASSIGN_T
        INCREMENT DECREMENT TRY CATCH FINALLY THROW THROWS
        VOID_T BOOLEAN_T INT_T DOUBLE_T STRING_T VARIENT_T NATIVE_POINTER_T
        NEW REQUIRE RENAME
        CLASS_T INTERFACE_T PUBLIC_T PRIVATE_T VIRTUAL_T OVERRIDE_T
        ABSTRACT_T THIS_T SUPER_T CONSTRUCTOR INSTANCEOF
        DOWN_CAST_BEGIN DOWN_CAST_END DELEGATE FINAL ENUM CONST
		FUNCTION AS THEN DIM END CR DECLARE BSUB APOSTROPHE LIB UNSAFE SAFE SHARED
		ATM_ADD_ASSIGN_T ATM_SUB_ASSIGN_T 
%type   <intval> apostrophe
%type   <intval> unsafe
%type   <intval> shared
%type   <package_name> package_name
%type   <require_list> require_list require_declaration
%type   <rename_list> rename_list rename_declaration
%type   <parameter_list> parameter_list
%type   <argument_list> argument_list
%type   <expression> expression expression_opt
        assignment_expression logical_and_expression logical_or_expression
        equality_expression relational_expression
        additive_expression multiplicative_expression
        unary_expression postfix_expression primary_expression
        primary_no_new_array array_literal array_creation
        initializer_opt
%type   <expression_list> expression_list case_expression_list
%type   <statement> statement
        if_statement switch_statement
        while_statement for_statement do_while_statement foreach_statement
        return_statement break_statement continue_statement try_statement
        throw_statement declaration_statement
%type   <statement_list> statement_list
%type   <block> block default_opt myblock
%type   <elsif> elsif elsif_list
%type   <case_list> case_list one_case
%type   <catch_clause> catch_clause catch_list
%type   <assignment_operator> assignment_operator
%type   <identifier> identifier_opt label_opt
%type   <type_specifier> type_specifier identifier_type_specifier template_type_specifier
        array_type_specifier
%type   <basic_type_specifier> basic_type_specifier
%type   <array_dimension> dimension_expression dimension_expression_list
        dimension_list
%type   <class_or_member_modifier> class_or_member_modifier
        class_or_member_modifier_list access_modifier
%type   <class_or_interface> class_or_interface
%type   <extends_list> extends_list extends 
%type   <member_declaration> member_declaration member_declaration_list
        method_member field_member
%type   <function_definition> method_function_definition
        constructor_definition
%type   <exception_list> exception_list throws_clause
%type   <enumerator> enumerator_list
%type   <template> type_list
%type   <template_def> template_def_list template_list

%%
translation_unit
        : initial_declaration 
        | translation_unit definition_or_statement
        ;
initial_declaration
        : /* empty */
        {
            dkc_set_require_and_rename_list(NULL, NULL);
        }
        | require_list rename_list
        {
            dkc_set_require_and_rename_list($1, $2);
        }
        | require_list
        {
            dkc_set_require_and_rename_list($1, NULL);
        }
        | rename_list
        {
            dkc_set_require_and_rename_list(NULL, $1);
        }
		| initial_declaration lib_function
		{
            dkc_set_require_and_rename_list(NULL, NULL);
		}
        ;
require_list
        : require_declaration
        | require_list require_declaration
        {
            $$ = dkc_chain_require_list($1, $2);
        }
        ;
require_declaration
        : REQUIRE package_name CR
        {
            $$ = dkc_create_require_list($2);
        }
        ;
package_name
        : IDENTIFIER
        {
            $$ = dkc_create_package_name($1);
        }
        | package_name DOT IDENTIFIER
        {
            $$ = dkc_chain_package_name($1, $3);
        }
        ;
rename_list
        : rename_declaration
        | rename_list rename_declaration
        {
            $$ = dkc_chain_rename_list($1, $2);
        }
        ;
rename_declaration
        : RENAME package_name IDENTIFIER CR
        {
            $$ = dkc_create_rename_list($2, $3);
        }
        ;
definition_or_statement
        : function_definition
        | class_definition
        | statement
        {
            DKC_Compiler *compiler = dkc_get_current_compiler();

            compiler->statement_list
                = dkc_chain_statement_list(compiler->statement_list, $1);
        }
        | delegate_definition
        | enum_definition
        | const_definition
        ;
basic_type_specifier
        : VOID_T
        {
            $$ = DVM_VOID_TYPE;
        }
        | BOOLEAN_T
        {
            $$ = DVM_BOOLEAN_TYPE;
        }
        | INT_T
        {
            $$ = DVM_INT_TYPE;
        }
        | DOUBLE_T
        {
            $$ = DVM_DOUBLE_TYPE;
        }
        | STRING_T
        {
            $$ = DVM_STRING_TYPE;
        }
        | VARIENT_T
        {
            $$ = DVM_VARIENT_TYPE;
        }
        | NATIVE_POINTER_T
        {
            $$ = DVM_NATIVE_POINTER_TYPE;
        }
        | DELEGATE
        {
            $$ = DVM_DELEGATE_TYPE;
        }
        ;
identifier_type_specifier
        : IDENTIFIER
        {
            $$ = dkc_create_identifier_type_specifier($1);
        }
        ;
array_type_specifier
        : basic_type_specifier LB RB
        {
            TypeSpecifier *basic_type
                = dkc_create_type_specifier($1);
            $$ = dkc_create_array_type_specifier(basic_type);
        }
        | IDENTIFIER LB RB
        {
            TypeSpecifier *identifier_type
                = dkc_create_identifier_type_specifier($1);
            $$ = dkc_create_array_type_specifier(identifier_type);
        }
        | array_type_specifier LB RB
        {
            $$ = dkc_create_array_type_specifier($1);
        }
		| template_type_specifier LB RB
		{
			$$ = dkc_create_array_type_specifier($1);
		}
        ;
template_type_specifier
		: IDENTIFIER LT type_list GT
		{//fix-me : shift/reduce
			$$= dkc_create_template_type_specifier($1,$3);
		}
		;
type_specifier
        : basic_type_specifier
        {
                    $$ = dkc_create_type_specifier($1);
        }
        | array_type_specifier
        | identifier_type_specifier
		| template_type_specifier
        ;
type_list
		:
		type_specifier
		{
			$$=dkc_create_template_list($1);
		}
		| type_list COMMA type_specifier
        {
            $$ = dkc_chain_template_list($1, $3);
        }
		;
lib_function
		:
		LIB IDENTIFIER
		{   
			if(BcGetCurrentCompilerContext()->libname)
			{
				    dkc_compile_error(dkc_get_current_compiler()->current_line_number,
                      MULTIPLE_LIB_ERR,MESSAGE_ARGUMENT_END);
			}
			BcGetCurrentCompilerContext()->libname=$2;
			BcGetCurrentCompilerContext()->isLib=1;
		}
		CR lib_function_declaration_list END
		{
			BcGetCurrentCompilerContext()->isLib=0;
		}
		;
lib_function_declaration_list
		:
		
		|lib_function_declaration_list function_declaration
		|lib_function_declaration_list class_definition
		;
function_declaration
		: DECLARE FUNCTION IDENTIFIER LP parameter_list apostrophe RP AS type_specifier throws_clause CR
        {
            dkc_function_define($9, $3, $5, $10, NULL,$6);
        }
        | DECLARE FUNCTION IDENTIFIER LP apostrophe RP AS type_specifier throws_clause CR
        {
            dkc_function_define($8, $3, NULL, $9, NULL,$5);
        }
		| DECLARE BSUB IDENTIFIER LP parameter_list apostrophe RP  throws_clause CR
        {
            dkc_function_define(0, $3, $5, $8, NULL,$6);
        }
        | DECLARE BSUB IDENTIFIER LP apostrophe RP  throws_clause CR
        {
			//printf("lib:%s\n",BcGetCurrentCompilerContext()->libname);
            dkc_function_define(0, $3, NULL, $7, NULL,$5);
        }
		;
function_definition
        : FUNCTION IDENTIFIER LP parameter_list apostrophe  RP AS type_specifier throws_clause myblock
        {
            dkc_function_define($8, $2, $4, $9, $10,$5);
        }
        | FUNCTION  IDENTIFIER LP apostrophe RP AS type_specifier throws_clause myblock
        {
            dkc_function_define($7, $2, NULL, $8, $9,$4);
        }
		|BSUB IDENTIFIER LP parameter_list apostrophe RP throws_clause myblock
        { //modified
            dkc_function_define(0, $2, $4, $7, $8,$5);
        }
        | BSUB  IDENTIFIER LP apostrophe RP  throws_clause myblock
        {
            dkc_function_define(0, $2, NULL, $6, $7,$4);
        }
        | function_declaration
        ;
parameter_list
        : IDENTIFIER AS type_specifier
        {
            $$ = dkc_create_parameter($3, $1);
        }
        | parameter_list COMMA IDENTIFIER AS type_specifier
        {
            $$ = dkc_chain_parameter($1, $5, $3);
        }
        ;
argument_list
        : assignment_expression
        {
            $$ = dkc_create_argument_list($1);
        }
        | argument_list COMMA assignment_expression
        {
            $$ = dkc_chain_argument_list($1, $3);
        }
        ;
statement_list
        : statement
        {
            $$ = dkc_create_statement_list($1);
        }
        | statement_list statement
        {
            $$ = dkc_chain_statement_list($1, $2);
        }
        ;
expression
        : assignment_expression
        | expression COMMA assignment_expression
        {
            $$ = dkc_create_comma_expression($1, $3);
        }
        ;
assignment_expression
        : logical_or_expression
        | primary_expression assignment_operator assignment_expression
        {
            $$ = dkc_create_assign_expression($1, $2, $3);
        }
        ;
assignment_operator
        : ASSIGN_T
        {
            $$ = NORMAL_ASSIGN;
        }
        | ADD_ASSIGN_T
        {
            $$ = ADD_ASSIGN;
        }
        | SUB_ASSIGN_T
        {
            $$ = SUB_ASSIGN;
        }
		| ATM_ADD_ASSIGN_T
        {
            $$ = ATM_ADD_ASSIGN;
        }
        | ATM_SUB_ASSIGN_T
        {
            $$ = ATM_SUB_ASSIGN;
        }
        | MUL_ASSIGN_T
        {
            $$ = MUL_ASSIGN;
        }
        | DIV_ASSIGN_T
        {
            $$ = DIV_ASSIGN;
        }
        | MOD_ASSIGN_T
        {
            $$ = MOD_ASSIGN;
        }
        ;
logical_or_expression
        : logical_and_expression
        | logical_or_expression LOGICAL_OR logical_and_expression
        {
            $$ = dkc_create_binary_expression(LOGICAL_OR_EXPRESSION, $1, $3);
        }
        ;
logical_and_expression
        : equality_expression
        | logical_and_expression LOGICAL_AND equality_expression
        {
            $$ = dkc_create_binary_expression(LOGICAL_AND_EXPRESSION, $1, $3);
        }
        ;
equality_expression
        : relational_expression
        | equality_expression EQ relational_expression
        {
            $$ = dkc_create_binary_expression(EQ_EXPRESSION, $1, $3);
        }
        | equality_expression NE relational_expression
        {
            $$ = dkc_create_binary_expression(NE_EXPRESSION, $1, $3);
        }
        ;
relational_expression
        : additive_expression
        | relational_expression GT additive_expression
        {
            $$ = dkc_create_binary_expression(GT_EXPRESSION, $1, $3);
        }
        | relational_expression GE additive_expression
        {
            $$ = dkc_create_binary_expression(GE_EXPRESSION, $1, $3);
        }
        | relational_expression LT additive_expression
        {
            $$ = dkc_create_binary_expression(LT_EXPRESSION, $1, $3);
        }
        | relational_expression LE additive_expression
        {
            $$ = dkc_create_binary_expression(LE_EXPRESSION, $1, $3);
        }
        ;
additive_expression
        : multiplicative_expression
        | additive_expression ADD multiplicative_expression
        {
            $$ = dkc_create_binary_expression(ADD_EXPRESSION, $1, $3);
        }
        | additive_expression SUB multiplicative_expression
        {
            $$ = dkc_create_binary_expression(SUB_EXPRESSION, $1, $3);
        }
        ;
multiplicative_expression
        : unary_expression
        | multiplicative_expression MUL unary_expression
        {
            $$ = dkc_create_binary_expression(MUL_EXPRESSION, $1, $3);
        }
        | multiplicative_expression DIV unary_expression
        {
            $$ = dkc_create_binary_expression(DIV_EXPRESSION, $1, $3);
        }
        | multiplicative_expression MOD unary_expression
        {
            $$ = dkc_create_binary_expression(MOD_EXPRESSION, $1, $3);
        }
        | multiplicative_expression BIT_AND unary_expression
        {
            $$ = dkc_create_binary_expression(BIT_AND_EXPRESSION, $1, $3);
        }
        | multiplicative_expression BIT_OR unary_expression
        {
            $$ = dkc_create_binary_expression(BIT_OR_EXPRESSION, $1, $3);
        }
        | multiplicative_expression BIT_XOR unary_expression
        {
            $$ = dkc_create_binary_expression(BIT_XOR_EXPRESSION, $1, $3);
        }
        ;
unary_expression
        : postfix_expression
        | SUB unary_expression
        {
            $$ = dkc_create_minus_expression($2);
        }
        | EXCLAMATION unary_expression
        {
            $$ = dkc_create_logical_not_expression($2);
        }
        | BIT_NOT unary_expression
        {
            $$ = dkc_create_bit_not_expression($2);
        }
        ;
postfix_expression
        : primary_expression
        | primary_expression INCREMENT
        {
            $$ = dkc_create_incdec_expression($1, INCREMENT_EXPRESSION);
        }
        | primary_expression DECREMENT
        {
            $$ = dkc_create_incdec_expression($1, DECREMENT_EXPRESSION);
        }
        | primary_expression INSTANCEOF type_specifier
        {
            $$ = dkc_create_instanceof_expression($1, $3);
        }
        ;
primary_expression
        : primary_no_new_array
        | array_creation
        | IDENTIFIER
        {
            $$ = dkc_create_identifier_expression($1);
        }
		| AUTOVAR
		{
			$$=BcCreateAutoExpression($1);
		}
        ;
primary_no_new_array
        : primary_no_new_array LB expression RB
        {
            $$ = dkc_create_index_expression($1, $3);
        }
        | IDENTIFIER LB expression RB
        {
            Expression *identifier = dkc_create_identifier_expression($1);
            $$ = dkc_create_index_expression(identifier, $3);
        }
        | primary_expression DOT IDENTIFIER
        {
            $$ = dkc_create_member_expression($1, $3);
        }
        | primary_expression LP argument_list RP
        {
            $$ = dkc_create_function_call_expression($1, $3);
        }
        | primary_expression LP RP
        {
            $$ = dkc_create_function_call_expression($1, NULL);
        }
        | LP expression RP
        {
            $$ = $2;
        }
        | primary_expression DOWN_CAST_BEGIN type_specifier DOWN_CAST_END
        {
            $$ = dkc_create_down_cast_expression($1, $3);
        }
        | INT_LITERAL
        | DOUBLE_LITERAL
        | STRING_LITERAL
        | REGEXP_LITERAL
        | TRUE_T
        {
            $$ = dkc_create_boolean_expression(DVM_TRUE);
        }
        | FALSE_T
        {
            $$ = dkc_create_boolean_expression(DVM_FALSE);
        }
        | NULL_T
        {
            $$ = dkc_create_null_expression();
        }
        | array_literal
        | THIS_T
        {
            $$ = dkc_create_this_expression();
        }
        | SUPER_T
        {
            $$ = dkc_create_super_expression();
        }
		| NEW DELEGATE LP RP
		{
			$$ = dkc_create_new_delegate_expression();
		}
        | NEW IDENTIFIER LP RP
        {
            $$ = dkc_create_new_expression($2, NULL, NULL);
        }
        | NEW IDENTIFIER LP argument_list RP
        {
            $$ = dkc_create_new_expression($2, NULL, $4);
        }
        | NEW IDENTIFIER DOT IDENTIFIER LP RP
        {
            $$ = dkc_create_new_expression($2, $4, NULL);
        }
        | NEW IDENTIFIER DOT IDENTIFIER LP argument_list RP
        {
            $$ = dkc_create_new_expression($2, $4, $6);
        }
        ;
array_literal
        : LC expression_list RC
        {
            $$ = dkc_create_array_literal_expression($2);
        }
        | LC expression_list COMMA RC
        {
            $$ = dkc_create_array_literal_expression($2);
        }
        ;
array_creation
        : NEW basic_type_specifier dimension_expression_list
        {
            $$ = dkc_create_basic_array_creation($2, $3, NULL);
        }
        | NEW basic_type_specifier dimension_expression_list dimension_list
        {
            $$ = dkc_create_basic_array_creation($2, $3, $4);
        }
        | NEW identifier_type_specifier dimension_expression_list
        {
            $$ = dkc_create_class_array_creation($2, $3, NULL);
        }
        | NEW identifier_type_specifier dimension_expression_list
            dimension_list
        {
            $$ = dkc_create_class_array_creation($2, $3, $4);
        }
		| NEW template_type_specifier dimension_expression_list
        {
            $$ = dkc_create_class_array_creation($2, $3, NULL);
        }
		| NEW template_type_specifier dimension_expression_list dimension_list
        {
            $$ = dkc_create_class_array_creation($2, $3, $4);
        }
        ;
dimension_expression_list
        : dimension_expression
        | dimension_expression_list dimension_expression
        {
            $$ = dkc_chain_array_dimension($1, $2);
        }
        ;
dimension_expression
        : LB expression RB
        {
            $$ = dkc_create_array_dimension($2);
        }
        ;
dimension_list
        : LB RB
        {
            $$ = dkc_create_array_dimension(NULL);
        }
        | dimension_list LB RB
        {
            $$ = dkc_chain_array_dimension($1,
                                           dkc_create_array_dimension(NULL));
        }
        ;
expression_list
        : /* empty */
        {
            $$ = NULL;
        }
        | assignment_expression
        {
            $$ = dkc_create_expression_list($1);
        }
        | expression_list COMMA assignment_expression
        {
            $$ = dkc_chain_expression_list($1, $3);
        }
        ;
statement
        : expression CR
        {
          $$ = dkc_create_expression_statement($1);
        }
        | if_statement
        | switch_statement
        | while_statement
        | for_statement
        | do_while_statement
        | foreach_statement
        | return_statement
        | break_statement
        | continue_statement
        | try_statement
        | throw_statement
        | declaration_statement
		| CR
		{/*empty line*/
			$$=0;
		}
        ;
if_statement
        : IF expression THEN myblock
        {
            $$ = dkc_create_if_statement($2, $4, NULL, NULL);
        }
        | IF expression THEN myblock ELSE myblock
        {
			//printf("IF-ELSE %d\n",dkc_get_current_compiler()->current_line_number);
            $$ = dkc_create_if_statement($2, $4, NULL, $6);
        }
        | IF expression THEN myblock elsif_list
        {
            $$ = dkc_create_if_statement($2, $4, $5, NULL);
        }
        | IF expression THEN myblock elsif_list ELSE myblock
        {
            $$ = dkc_create_if_statement($2, $4, $5, $7);
        }
        ;
elsif_list
        : elsif
        | elsif_list elsif
        {
            $$ = dkc_chain_elsif_list($1, $2);
        }
        ;
elsif
        : ELSIF  expression THEN myblock
        {
            $$ = dkc_create_elsif($2, $4);
        }
        ;
label_opt
        : /* empty */
        {
            $$ = NULL;
        }
        | IDENTIFIER COLON
        {
            $$ = $1;
        }
        ;
switch_statement
        : SWITCH  expression   CR case_list default_opt 
        {
            $$ = dkc_create_switch_statement($2, $4, $5);
        }
        ;
case_list
        : one_case
        | case_list one_case
        {
            $$ = dkc_chain_case($1, $2);
        }
        ;
one_case
        : CASE case_expression_list myblock
        {
            $$ = dkc_create_one_case($2, $3);
        }
        ;
default_opt
        : /* empty */
        {
            $$ = NULL;
        }
        | DEFAULT_T myblock
        {
            $$ = $2;
        }
        ;
case_expression_list
        : assignment_expression
        {
            $$ = dkc_create_expression_list($1);
        }
        | expression_list COMMA assignment_expression
        {
            $$ = dkc_chain_expression_list($1, $3);
        }
        ;
while_statement
        : label_opt WHILE  expression myblock
        {
            $$ = dkc_create_while_statement($1, $3, $4);
        }
        ;
for_statement
        : label_opt FOR expression_opt SEMICOLON expression_opt SEMICOLON expression_opt myblock
        {
            $$ = dkc_create_for_statement($1, $3, $5, $7, $8);
        }
        ;
do_while_statement
        : label_opt DO_T block WHILE LP expression RP CR //fix-me : unimplemented
        {
            $$ = dkc_create_do_while_statement($1, $3, $6);
        }
        ;
foreach_statement
        : label_opt FOREACH LP IDENTIFIER COLON expression RP block //fix-me : unimplemented
        {
            $$ = dkc_create_foreach_statement($1, $4, $6, $8);
        }
        ;
expression_opt
        : /* empty */
        {
            $$ = NULL;
        }
        | expression
        ;
return_statement
        : RETURN_T expression_opt CR
        {
            $$ = dkc_create_return_statement($2);
        }
        ;
identifier_opt
        : /* empty */
        {
            $$ = NULL;
        }
        | IDENTIFIER
        ;
break_statement 
        : BREAK identifier_opt CR
        {
            $$ = dkc_create_break_statement($2);
        }
        ;
continue_statement
        : CONTINUE identifier_opt CR
        {
            $$ = dkc_create_continue_statement($2);
        }
        ;
try_statement
        : TRY myblock catch_list FINALLY  myblock
        {
            $$ = dkc_create_try_statement($2, $3, $5);
        }
        | TRY myblock FINALLY block
        {
            $$ = dkc_create_try_statement($2, NULL, $4);
        }
        | TRY myblock catch_list
        {
            $$ = dkc_create_try_statement($2, $3, NULL);
        }
        ;
catch_list
        : catch_clause
        | catch_list catch_clause
        {
            $$ = dkc_chain_catch_list($1, $2);
        }
        ;
catch_clause
        : CATCH
        {
            $<catch_clause>$ = dkc_start_catch_clause();
        }
           type_specifier IDENTIFIER  myblock
        {
            $<catch_clause>$ = dkc_end_catch_clause($<catch_clause>2, $3, $4, $5);
        }
        ;
throw_statement
        : THROW expression CR
        {
            $$ = dkc_create_throw_statement($2);
        }
        | THROW CR
        {
            $$ = dkc_create_throw_statement(NULL);
        }
        ;
declaration_statement
        : DIM  IDENTIFIER AS shared type_specifier CR
        {
            $$ = dkc_create_declaration_statement(DVM_FALSE, $5, $2, NULL,$4);
        }
        | DIM  IDENTIFIER AS shared type_specifier ASSIGN_T expression CR
        {
            $$ = dkc_create_declaration_statement(DVM_FALSE, $5, $2, $7,$4);
        }
        |  FINAL IDENTIFIER AS type_specifier CR
        {
            $$ = dkc_create_declaration_statement(DVM_FALSE, $4, $2, NULL,DVM_FALSE);
        }
        | FINAL  IDENTIFIER AS type_specifier ASSIGN_T expression CR
        {
            $$ = dkc_create_declaration_statement(DVM_TRUE, $4, $2, $6,DVM_FALSE);
        }
        ;
block
        : LC
        {
            $<block>$ = dkc_open_block(0);
        }
          statement_list RC
        {
            $<block>$ = dkc_close_block($<block>2, $3);
        }
        | LC RC
        {
            Block *empty_block = dkc_open_block(0);
            $<block>$ = dkc_close_block(empty_block, NULL);
        }
        ;
template_def_list
        : IDENTIFIER
        {
            $$ = dkc_create_template_declare_list($1,NULL);
        }
        | template_def_list COMMA IDENTIFIER
        {
            $$ = dkc_chain_template_declare_list($1, $3,NULL);
        }
		|IDENTIFIER COLON identifier_type_specifier
        {
            $$ = dkc_create_template_declare_list($1,$3);
        }
        | template_def_list COMMA IDENTIFIER COLON identifier_type_specifier
        {
            $$ = dkc_chain_template_declare_list($1, $3 ,$5);
        }
        ;
template_list
		: LT template_def_list GT 
		{
			$$=$2;
		}
		|
		{$$=NULL;}
		;
class_definition
        : shared class_or_interface IDENTIFIER template_list
          extends CR
        {
            dkc_start_class_definition($1,NULL, $2, $3,$4, $5);
        }
          member_declaration_list END
        {
            dkc_class_define($8);
        }
        | shared class_or_member_modifier_list class_or_interface IDENTIFIER template_list
          extends CR
        {
            dkc_start_class_definition($1,&$2, $3, $4,$5, $6);
        } member_declaration_list END
        {
            dkc_class_define($9);
        }
        | shared class_or_interface IDENTIFIER template_list extends CR
        {
            dkc_start_class_definition($1,NULL, $2, $3,$4, $5);
        }
          END
        {
            dkc_class_define(NULL);
        }
        | shared class_or_member_modifier_list class_or_interface IDENTIFIER template_list
          extends CR
        {
            dkc_start_class_definition($1,&$2, $3, $4,$5, $6);
        }
          END
        {
            dkc_class_define(NULL);
        }
        ;
class_or_member_modifier_list
        : class_or_member_modifier
        | class_or_member_modifier_list class_or_member_modifier
        {
            $$ = dkc_chain_class_or_member_modifier($1, $2);
        }
        ;
class_or_member_modifier
        : access_modifier
        | VIRTUAL_T
        {
            $$ = dkc_create_class_or_member_modifier(VIRTUAL_MODIFIER);
        }
        | OVERRIDE_T
        {
            $$ = dkc_create_class_or_member_modifier(OVERRIDE_MODIFIER);
        }
        | ABSTRACT_T
        {
            $$ = dkc_create_class_or_member_modifier(ABSTRACT_MODIFIER);
        }
        ;
class_or_interface
        : CLASS_T
        {
            $$ = DVM_CLASS_DEFINITION;
        }
        | INTERFACE_T
        {
            $$ = DVM_INTERFACE_DEFINITION;
        }
        ;
extends
        : /* empty */
        {
            $$ = NULL;
        }
        | COLON extends_list
        {
            $$ = $2;
        }
        ;
extends_list
        : IDENTIFIER
        {
            $$ = dkc_create_extends_list($1);
        }
        | extends_list COMMA IDENTIFIER
        {
            $$ = dkc_chain_extends_list($1, $3);
        }
        ;
member_declaration_list
        : member_declaration
        | member_declaration_list member_declaration
        {
            $$ = dkc_chain_member_declaration($1, $2);
        }
        ;
member_declaration
        : method_member
        | field_member
        ;
method_member
        : method_function_definition
        {
            $$ = dkc_create_method_member(NULL, $1, DVM_FALSE);
        }
        | class_or_member_modifier_list method_function_definition
        {
            $$ = dkc_create_method_member(&$1, $2, DVM_FALSE);
        }
        | constructor_definition
        {
            $$ = dkc_create_method_member(NULL, $1, DVM_TRUE);
        }
        | class_or_member_modifier_list constructor_definition
        {
            $$ = dkc_create_method_member(&$1, $2, DVM_TRUE);
        }
        ;
method_function_definition
        : FUNCTION IDENTIFIER LP parameter_list RP AS type_specifier throws_clause myblock
        {
            $$ = dkc_method_function_define($7, $2, $4, $8, $9);
        }
        | FUNCTION IDENTIFIER  LP RP AS type_specifier throws_clause myblock
        {
            $$ = dkc_method_function_define($6, $2, NULL, $7, $8);
        }
        | DECLARE FUNCTION IDENTIFIER LP parameter_list RP AS type_specifier throws_clause CR
        {
            $$ = dkc_method_function_define($8, $3, $5, $9, NULL);
        }
        | DECLARE FUNCTION IDENTIFIER LP RP AS type_specifier throws_clause CR
        {
            $$ = dkc_method_function_define($7, $3, NULL, $8, NULL);
        }
		| BSUB IDENTIFIER LP parameter_list RP  throws_clause myblock
        {
            $$ = dkc_method_function_define(0, $2, $4, $6, $7);
        }
        | BSUB IDENTIFIER  LP RP  throws_clause myblock
        {
            $$ = dkc_method_function_define(0, $2, NULL, $5, $6);
        }
        | DECLARE BSUB IDENTIFIER LP parameter_list RP  throws_clause CR
        {
            $$ = dkc_method_function_define(0, $3, $5, $7, NULL);
        }
        | DECLARE BSUB IDENTIFIER LP RP  throws_clause CR
        {
            $$ = dkc_method_function_define(0, $3, NULL, $6, NULL);
        }
        ;
apostrophe
		: //empty
		{
			$$=0;
		}
		|COMMA APOSTROPHE
		{
			$$=1;
		}
		;
throws_clause //fix-me : exception needs to check
        : /* empty */
        {
            $$ = NULL;
        }
        | THROWS exception_list
        {
            $$ = $2;
        }
        ;
exception_list
        : IDENTIFIER
        {
            $$ = dkc_create_throws($1);
        }
        | exception_list COMMA IDENTIFIER
        {
            $$ = dkc_chain_exception_list($1, $3);
        }
        ;
constructor_definition
        : CONSTRUCTOR IDENTIFIER LP parameter_list RP throws_clause myblock
        {
            $$ = dkc_constructor_function_define($2, $4, $6, $7);
        }
        | CONSTRUCTOR IDENTIFIER LP RP throws_clause myblock
        {
            $$ = dkc_constructor_function_define($2, NULL, $5, $6);
        }
        | DECLARE CONSTRUCTOR IDENTIFIER LP parameter_list RP throws_clause CR
        {
            $$ = dkc_constructor_function_define($3, $5, $7, NULL);
        }
        | DECLARE CONSTRUCTOR IDENTIFIER LP RP throws_clause CR
        {
            $$ = dkc_constructor_function_define($3, NULL, $6, NULL);
        }
        ;
access_modifier
        : PUBLIC_T
        {
            $$ = dkc_create_class_or_member_modifier(PUBLIC_MODIFIER);
        }
        | PRIVATE_T
        {
            $$ = dkc_create_class_or_member_modifier(PRIVATE_MODIFIER);
        }
        ;
initializer_opt
        : /* empty */
        {
            $$ = NULL;
        }
        | ASSIGN_T expression
        {
            $$ = $2;
        }
        ;
field_member
        : DIM IDENTIFIER AS type_specifier  initializer_opt CR
        {
            $$ = dkc_create_field_member(NULL, DVM_FALSE, $4, $2, $5);
        }
        | class_or_member_modifier_list IDENTIFIER AS type_specifier
           initializer_opt CR
        {
            $$ = dkc_create_field_member(&$1, DVM_FALSE, $4, $2, $5);
        }
        | FINAL IDENTIFIER AS type_specifier  initializer_opt CR
        {
            $$ = dkc_create_field_member(NULL, DVM_TRUE, $4, $2, $5);
        }
        | class_or_member_modifier_list
          FINAL IDENTIFIER AS type_specifier initializer_opt CR
        {
            $$ = dkc_create_field_member(&$1, DVM_TRUE, $5, $3, $6);
        }
        | FINAL class_or_member_modifier_list IDENTIFIER AS type_specifier initializer_opt CR
        {
            $$ = dkc_create_field_member(&$2, DVM_TRUE, $5, $3, $6);
        }
        ;
delegate_definition
        : DELEGATE  IDENTIFIER LP parameter_list apostrophe RP AS type_specifier throws_clause CR
        {
            dkc_create_delegate_definition($8, $2, $4, $9,$5);
        }
        | DELEGATE  IDENTIFIER LP apostrophe RP AS type_specifier throws_clause CR
        {
            dkc_create_delegate_definition($7, $2, NULL, $8,$4);
        }
        ;
enum_definition
        : ENUM IDENTIFIER LC enumerator_list RC
        {
            dkc_create_enum_definition($2, $4);
        }
        | ENUM IDENTIFIER LC enumerator_list COMMA RC
        {
            dkc_create_enum_definition($2, $4);
        }
        ;
enumerator_list
        : IDENTIFIER
        {
            $$ = dkc_create_enumerator($1);
        }
        | enumerator_list COMMA IDENTIFIER
        {
            $$ = dkc_chain_enumerator($1, $3);
        }
        ;
const_definition
        : CONST IDENTIFIER ASSIGN_T expression CR
        {
            dkc_create_const_definition(NULL, $2, $4);
        }
        | CONST type_specifier IDENTIFIER CR
        {
            dkc_create_const_definition($2, $3, NULL);
        }
        ;
shared
		: //empty
		{
			$$=0;
		}
		| SHARED
		{
			$$=1;
		}
		;
unsafe
		: //empty
		{
			$$=0;
		}
		| UNSAFE CR
		{
			$$=1;
		}
		| SAFE CR
		{
			$$=-1;
		}
		;
myblock
        : CR  unsafe
        {
            $<block>$ = dkc_open_block($2);
			//printf("E1 %d\n",dkc_get_current_compiler());
        }
          statement_list END 
        {
            $<block>$ = dkc_close_block($<block>3, $4);
			//printf("C1 %d\n",dkc_get_current_compiler()->current_line_number);
        }
        | CR END 
        {
            Block *empty_block = dkc_open_block(0);
            $<block>$ = dkc_close_block(empty_block, NULL);
			//printf("C2 %d\n",dkc_get_current_compiler()->current_line_number);
        }
        ;
%%
