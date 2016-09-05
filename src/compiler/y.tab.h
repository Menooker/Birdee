
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT_LITERAL = 258,
     DOUBLE_LITERAL = 259,
     FLOAT_LITERAL = 260,
     STRING_LITERAL = 261,
     REGEXP_LITERAL = 262,
     IDENTIFIER = 263,
     AUTOVAR = 264,
     IF = 265,
     ELSE = 266,
     ELSIF = 267,
     SWITCH = 268,
     CASE = 269,
     DEFAULT_T = 270,
     WHILE = 271,
     DO_T = 272,
     FOR = 273,
     FOREACH = 274,
     RETURN_T = 275,
     BREAK = 276,
     CONTINUE = 277,
     NULL_T = 278,
     LP = 279,
     RP = 280,
     LC = 281,
     RC = 282,
     LB = 283,
     RB = 284,
     SEMICOLON = 285,
     COLON = 286,
     COMMA = 287,
     ASSIGN_T = 288,
     LOGICAL_AND = 289,
     LOGICAL_OR = 290,
     EQ = 291,
     NE = 292,
     GT = 293,
     GE = 294,
     LT = 295,
     LE = 296,
     ADD = 297,
     SUB = 298,
     MUL = 299,
     DIV = 300,
     MOD = 301,
     BIT_AND = 302,
     BIT_OR = 303,
     BIT_XOR = 304,
     BIT_NOT = 305,
     TRUE_T = 306,
     FALSE_T = 307,
     EXCLAMATION = 308,
     DOT = 309,
     ADD_ASSIGN_T = 310,
     SUB_ASSIGN_T = 311,
     MUL_ASSIGN_T = 312,
     DIV_ASSIGN_T = 313,
     MOD_ASSIGN_T = 314,
     INCREMENT = 315,
     DECREMENT = 316,
     TRY = 317,
     CATCH = 318,
     FINALLY = 319,
     THROW = 320,
     THROWS = 321,
     VOID_T = 322,
     BOOLEAN_T = 323,
     INT_T = 324,
     DOUBLE_T = 325,
     STRING_T = 326,
     VARIENT_T = 327,
     FLOAT_T = 328,
     NATIVE_POINTER_T = 329,
     NEW = 330,
     REQUIRE = 331,
     RENAME = 332,
     CLASS_T = 333,
     INTERFACE_T = 334,
     PUBLIC_T = 335,
     PRIVATE_T = 336,
     VIRTUAL_T = 337,
     OVERRIDE_T = 338,
     ABSTRACT_T = 339,
     THIS_T = 340,
     SUPER_T = 341,
     CONSTRUCTOR = 342,
     INSTANCEOF = 343,
     DOWN_CAST_BEGIN = 344,
     DOWN_CAST_END = 345,
     DELEGATE = 346,
     FINAL = 347,
     ENUM = 348,
     CONST = 349,
     FUNCTION = 350,
     AS = 351,
     THEN = 352,
     DIM = 353,
     END = 354,
     CR = 355,
     DECLARE = 356,
     BSUB = 357,
     APOSTROPHE = 358,
     LIB = 359,
     UNSAFE = 360,
     SAFE = 361,
     SHARED = 362,
     GLOBAL = 363,
     VOLATILE = 364,
     ATM_ADD_ASSIGN_T = 365,
     ATM_SUB_ASSIGN_T = 366
   };
#endif
/* Tokens.  */
#define INT_LITERAL 258
#define DOUBLE_LITERAL 259
#define FLOAT_LITERAL 260
#define STRING_LITERAL 261
#define REGEXP_LITERAL 262
#define IDENTIFIER 263
#define AUTOVAR 264
#define IF 265
#define ELSE 266
#define ELSIF 267
#define SWITCH 268
#define CASE 269
#define DEFAULT_T 270
#define WHILE 271
#define DO_T 272
#define FOR 273
#define FOREACH 274
#define RETURN_T 275
#define BREAK 276
#define CONTINUE 277
#define NULL_T 278
#define LP 279
#define RP 280
#define LC 281
#define RC 282
#define LB 283
#define RB 284
#define SEMICOLON 285
#define COLON 286
#define COMMA 287
#define ASSIGN_T 288
#define LOGICAL_AND 289
#define LOGICAL_OR 290
#define EQ 291
#define NE 292
#define GT 293
#define GE 294
#define LT 295
#define LE 296
#define ADD 297
#define SUB 298
#define MUL 299
#define DIV 300
#define MOD 301
#define BIT_AND 302
#define BIT_OR 303
#define BIT_XOR 304
#define BIT_NOT 305
#define TRUE_T 306
#define FALSE_T 307
#define EXCLAMATION 308
#define DOT 309
#define ADD_ASSIGN_T 310
#define SUB_ASSIGN_T 311
#define MUL_ASSIGN_T 312
#define DIV_ASSIGN_T 313
#define MOD_ASSIGN_T 314
#define INCREMENT 315
#define DECREMENT 316
#define TRY 317
#define CATCH 318
#define FINALLY 319
#define THROW 320
#define THROWS 321
#define VOID_T 322
#define BOOLEAN_T 323
#define INT_T 324
#define DOUBLE_T 325
#define STRING_T 326
#define VARIENT_T 327
#define FLOAT_T 328
#define NATIVE_POINTER_T 329
#define NEW 330
#define REQUIRE 331
#define RENAME 332
#define CLASS_T 333
#define INTERFACE_T 334
#define PUBLIC_T 335
#define PRIVATE_T 336
#define VIRTUAL_T 337
#define OVERRIDE_T 338
#define ABSTRACT_T 339
#define THIS_T 340
#define SUPER_T 341
#define CONSTRUCTOR 342
#define INSTANCEOF 343
#define DOWN_CAST_BEGIN 344
#define DOWN_CAST_END 345
#define DELEGATE 346
#define FINAL 347
#define ENUM 348
#define CONST 349
#define FUNCTION 350
#define AS 351
#define THEN 352
#define DIM 353
#define END 354
#define CR 355
#define DECLARE 356
#define BSUB 357
#define APOSTROPHE 358
#define LIB 359
#define UNSAFE 360
#define SAFE 361
#define SHARED 362
#define GLOBAL 363
#define VOLATILE 364
#define ATM_ADD_ASSIGN_T 365
#define ATM_SUB_ASSIGN_T 366




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 6 "diksam.y"

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



/* Line 1676 of yacc.c  */
#line 307 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


