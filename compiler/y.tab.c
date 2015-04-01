
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "diksam.y"

#include <stdio.h>
#include "diksamc.h"
#define YYDEBUG 1


/* Line 189 of yacc.c  */
#line 80 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT_LITERAL = 258,
     DOUBLE_LITERAL = 259,
     STRING_LITERAL = 260,
     REGEXP_LITERAL = 261,
     IDENTIFIER = 262,
     AUTOVAR = 263,
     IF = 264,
     ELSE = 265,
     ELSIF = 266,
     SWITCH = 267,
     CASE = 268,
     DEFAULT_T = 269,
     WHILE = 270,
     DO_T = 271,
     FOR = 272,
     FOREACH = 273,
     RETURN_T = 274,
     BREAK = 275,
     CONTINUE = 276,
     NULL_T = 277,
     LP = 278,
     RP = 279,
     LC = 280,
     RC = 281,
     LB = 282,
     RB = 283,
     SEMICOLON = 284,
     COLON = 285,
     COMMA = 286,
     ASSIGN_T = 287,
     LOGICAL_AND = 288,
     LOGICAL_OR = 289,
     EQ = 290,
     NE = 291,
     GT = 292,
     GE = 293,
     LT = 294,
     LE = 295,
     ADD = 296,
     SUB = 297,
     MUL = 298,
     DIV = 299,
     MOD = 300,
     BIT_AND = 301,
     BIT_OR = 302,
     BIT_XOR = 303,
     BIT_NOT = 304,
     TRUE_T = 305,
     FALSE_T = 306,
     EXCLAMATION = 307,
     DOT = 308,
     ADD_ASSIGN_T = 309,
     SUB_ASSIGN_T = 310,
     MUL_ASSIGN_T = 311,
     DIV_ASSIGN_T = 312,
     MOD_ASSIGN_T = 313,
     INCREMENT = 314,
     DECREMENT = 315,
     TRY = 316,
     CATCH = 317,
     FINALLY = 318,
     THROW = 319,
     THROWS = 320,
     VOID_T = 321,
     BOOLEAN_T = 322,
     INT_T = 323,
     DOUBLE_T = 324,
     STRING_T = 325,
     VARIENT_T = 326,
     NATIVE_POINTER_T = 327,
     NEW = 328,
     REQUIRE = 329,
     RENAME = 330,
     CLASS_T = 331,
     INTERFACE_T = 332,
     PUBLIC_T = 333,
     PRIVATE_T = 334,
     VIRTUAL_T = 335,
     OVERRIDE_T = 336,
     ABSTRACT_T = 337,
     THIS_T = 338,
     SUPER_T = 339,
     CONSTRUCTOR = 340,
     INSTANCEOF = 341,
     DOWN_CAST_BEGIN = 342,
     DOWN_CAST_END = 343,
     DELEGATE = 344,
     FINAL = 345,
     ENUM = 346,
     CONST = 347,
     FUNCTION = 348,
     AS = 349,
     THEN = 350,
     DIM = 351,
     END = 352,
     CR = 353,
     DECLARE = 354,
     BSUB = 355,
     APOSTROPHE = 356,
     LIB = 357,
     UNSAFE = 358,
     SAFE = 359
   };
#endif
/* Tokens.  */
#define INT_LITERAL 258
#define DOUBLE_LITERAL 259
#define STRING_LITERAL 260
#define REGEXP_LITERAL 261
#define IDENTIFIER 262
#define AUTOVAR 263
#define IF 264
#define ELSE 265
#define ELSIF 266
#define SWITCH 267
#define CASE 268
#define DEFAULT_T 269
#define WHILE 270
#define DO_T 271
#define FOR 272
#define FOREACH 273
#define RETURN_T 274
#define BREAK 275
#define CONTINUE 276
#define NULL_T 277
#define LP 278
#define RP 279
#define LC 280
#define RC 281
#define LB 282
#define RB 283
#define SEMICOLON 284
#define COLON 285
#define COMMA 286
#define ASSIGN_T 287
#define LOGICAL_AND 288
#define LOGICAL_OR 289
#define EQ 290
#define NE 291
#define GT 292
#define GE 293
#define LT 294
#define LE 295
#define ADD 296
#define SUB 297
#define MUL 298
#define DIV 299
#define MOD 300
#define BIT_AND 301
#define BIT_OR 302
#define BIT_XOR 303
#define BIT_NOT 304
#define TRUE_T 305
#define FALSE_T 306
#define EXCLAMATION 307
#define DOT 308
#define ADD_ASSIGN_T 309
#define SUB_ASSIGN_T 310
#define MUL_ASSIGN_T 311
#define DIV_ASSIGN_T 312
#define MOD_ASSIGN_T 313
#define INCREMENT 314
#define DECREMENT 315
#define TRY 316
#define CATCH 317
#define FINALLY 318
#define THROW 319
#define THROWS 320
#define VOID_T 321
#define BOOLEAN_T 322
#define INT_T 323
#define DOUBLE_T 324
#define STRING_T 325
#define VARIENT_T 326
#define NATIVE_POINTER_T 327
#define NEW 328
#define REQUIRE 329
#define RENAME 330
#define CLASS_T 331
#define INTERFACE_T 332
#define PUBLIC_T 333
#define PRIVATE_T 334
#define VIRTUAL_T 335
#define OVERRIDE_T 336
#define ABSTRACT_T 337
#define THIS_T 338
#define SUPER_T 339
#define CONSTRUCTOR 340
#define INSTANCEOF 341
#define DOWN_CAST_BEGIN 342
#define DOWN_CAST_END 343
#define DELEGATE 344
#define FINAL 345
#define ENUM 346
#define CONST 347
#define FUNCTION 348
#define AS 349
#define THEN 350
#define DIM 351
#define END 352
#define CR 353
#define DECLARE 354
#define BSUB 355
#define APOSTROPHE 356
#define LIB 357
#define UNSAFE 358
#define SAFE 359




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
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
	int					apost;
	TemplateTypes		*template;
	TemplateDeclare     *template_def;



/* Line 214 of yacc.c  */
#line 357 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 369 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1044

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  105
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  99
/* YYNRULES -- Number of rules.  */
#define YYNRULES  274
/* YYNRULES -- Number of states.  */
#define YYNSTATES  594

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   359

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    12,    14,    16,    19,
      21,    24,    28,    30,    34,    36,    39,    44,    46,    48,
      50,    52,    54,    56,    58,    60,    62,    64,    66,    68,
      70,    72,    74,    78,    82,    86,    91,    93,    95,    97,
      99,   101,   105,   106,   113,   114,   117,   120,   132,   143,
     153,   162,   173,   183,   192,   200,   202,   206,   212,   214,
     218,   220,   223,   225,   229,   231,   235,   237,   239,   241,
     243,   245,   247,   249,   253,   255,   259,   261,   265,   269,
     271,   275,   279,   283,   287,   289,   293,   297,   299,   303,
     307,   311,   315,   319,   323,   325,   328,   331,   334,   336,
     339,   342,   346,   348,   350,   352,   354,   359,   364,   368,
     373,   377,   381,   386,   388,   390,   392,   394,   396,   398,
     400,   402,   404,   406,   411,   416,   422,   429,   437,   441,
     446,   450,   455,   459,   464,   466,   469,   473,   476,   480,
     481,   483,   487,   490,   492,   494,   496,   498,   500,   502,
     504,   506,   508,   510,   512,   514,   516,   521,   528,   534,
     542,   544,   547,   552,   553,   556,   562,   564,   567,   571,
     572,   575,   577,   581,   586,   595,   604,   613,   614,   616,
     620,   621,   623,   627,   631,   637,   642,   646,   648,   651,
     652,   658,   662,   665,   671,   679,   685,   693,   694,   699,
     702,   704,   708,   712,   718,   722,   723,   724,   733,   734,
     744,   745,   753,   754,   763,   765,   768,   770,   772,   774,
     776,   778,   780,   781,   784,   786,   790,   792,   795,   797,
     799,   801,   804,   806,   809,   819,   828,   839,   849,   857,
     864,   873,   881,   882,   885,   886,   889,   891,   895,   903,
     910,   919,   927,   929,   931,   932,   935,   942,   949,   956,
     964,   972,   983,   993,   999,  1006,  1008,  1012,  1018,  1023,
    1024,  1027,  1030,  1031,  1037
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     106,     0,    -1,   107,    -1,   106,   113,    -1,    -1,   108,
     111,    -1,   108,    -1,   111,    -1,   107,   120,    -1,   109,
      -1,   108,   109,    -1,    74,   110,    98,    -1,     7,    -1,
     110,    53,     7,    -1,   112,    -1,   111,   112,    -1,    75,
     110,     7,    98,    -1,   124,    -1,   176,    -1,   147,    -1,
     197,    -1,   198,    -1,   200,    -1,    66,    -1,    67,    -1,
      68,    -1,    69,    -1,    70,    -1,    71,    -1,    72,    -1,
      89,    -1,     7,    -1,   114,    27,    28,    -1,     7,    27,
      28,    -1,   116,    27,    28,    -1,     7,    39,   119,    37,
      -1,   114,    -1,   116,    -1,   115,    -1,   117,    -1,   118,
      -1,   119,    31,   118,    -1,    -1,   102,     7,   121,    98,
     122,    97,    -1,    -1,   122,   123,    -1,   122,   176,    -1,
      99,    93,     7,    23,   125,   190,    24,    94,   118,   191,
      98,    -1,    99,    93,     7,    23,   190,    24,    94,   118,
     191,    98,    -1,    99,   100,     7,    23,   125,   190,    24,
     191,    98,    -1,    99,   100,     7,    23,   190,    24,   191,
      98,    -1,    93,     7,    23,   125,   190,    24,    94,   118,
     191,   202,    -1,    93,     7,    23,   190,    24,    94,   118,
     191,   202,    -1,   100,     7,    23,   125,   190,    24,   191,
     202,    -1,   100,     7,    23,   190,    24,   191,   202,    -1,
     123,    -1,     7,    94,   118,    -1,   125,    31,     7,    94,
     118,    -1,   129,    -1,   126,    31,   129,    -1,   147,    -1,
     127,   147,    -1,   129,    -1,   128,    31,   129,    -1,   131,
      -1,   139,   130,   129,    -1,    32,    -1,    54,    -1,    55,
      -1,    56,    -1,    57,    -1,    58,    -1,   132,    -1,   131,
      34,   132,    -1,   133,    -1,   132,    33,   133,    -1,   134,
      -1,   133,    35,   134,    -1,   133,    36,   134,    -1,   135,
      -1,   134,    37,   135,    -1,   134,    38,   135,    -1,   134,
      39,   135,    -1,   134,    40,   135,    -1,   136,    -1,   135,
      41,   136,    -1,   135,    42,   136,    -1,   137,    -1,   136,
      43,   137,    -1,   136,    44,   137,    -1,   136,    45,   137,
      -1,   136,    46,   137,    -1,   136,    47,   137,    -1,   136,
      48,   137,    -1,   138,    -1,    42,   137,    -1,    52,   137,
      -1,    49,   137,    -1,   139,    -1,   139,    59,    -1,   139,
      60,    -1,   139,    86,   118,    -1,   140,    -1,   142,    -1,
       7,    -1,     8,    -1,   140,    27,   128,    28,    -1,     7,
      27,   128,    28,    -1,   139,    53,     7,    -1,   139,    23,
     126,    24,    -1,   139,    23,    24,    -1,    23,   128,    24,
      -1,   139,    87,   118,    88,    -1,     3,    -1,     4,    -1,
       5,    -1,     6,    -1,    50,    -1,    51,    -1,    22,    -1,
     141,    -1,    83,    -1,    84,    -1,    73,    89,    23,    24,
      -1,    73,     7,    23,    24,    -1,    73,     7,    23,   126,
      24,    -1,    73,     7,    53,     7,    23,    24,    -1,    73,
       7,    53,     7,    23,   126,    24,    -1,    25,   146,    26,
      -1,    25,   146,    31,    26,    -1,    73,   114,   143,    -1,
      73,   114,   143,   145,    -1,    73,   115,   143,    -1,    73,
     115,   143,   145,    -1,   144,    -1,   143,   144,    -1,    27,
     128,    28,    -1,    27,    28,    -1,   145,    27,    28,    -1,
      -1,   129,    -1,   146,    31,   129,    -1,   128,    98,    -1,
     148,    -1,   152,    -1,   157,    -1,   158,    -1,   159,    -1,
     160,    -1,   162,    -1,   164,    -1,   165,    -1,   166,    -1,
     170,    -1,   171,    -1,    98,    -1,     9,   128,    95,   202,
      -1,     9,   128,    95,   202,    10,   202,    -1,     9,   128,
      95,   202,   149,    -1,     9,   128,    95,   202,   149,    10,
     202,    -1,   150,    -1,   149,   150,    -1,    11,   128,    95,
     202,    -1,    -1,     7,    30,    -1,    12,   128,    98,   153,
     155,    -1,   154,    -1,   153,   154,    -1,    13,   156,   202,
      -1,    -1,    14,   202,    -1,   129,    -1,   146,    31,   129,
      -1,   151,    15,   128,   202,    -1,   151,    17,   161,    29,
     161,    29,   161,   202,    -1,   151,    16,   172,    15,    23,
     128,    24,    98,    -1,   151,    18,    23,     7,    30,   128,
      24,   172,    -1,    -1,   128,    -1,    19,   161,    98,    -1,
      -1,     7,    -1,    20,   163,    98,    -1,    21,   163,    98,
      -1,    61,   202,   167,    63,   202,    -1,    61,   202,    63,
     172,    -1,    61,   202,   167,    -1,   168,    -1,   167,   168,
      -1,    -1,    62,   169,   118,     7,   202,    -1,    64,   128,
      98,    -1,    64,    98,    -1,    96,     7,    94,   118,    98,
      -1,    96,     7,    94,   118,    32,   128,    98,    -1,    90,
       7,    94,   118,    98,    -1,    90,     7,    94,   118,    32,
     128,    98,    -1,    -1,    25,   173,   127,    26,    -1,    25,
      26,    -1,     7,    -1,   174,    31,     7,    -1,     7,    30,
     115,    -1,   174,    31,     7,    30,   115,    -1,    39,   174,
      37,    -1,    -1,    -1,   183,     7,   175,   184,    98,   177,
     186,    97,    -1,    -1,   181,   183,     7,   175,   184,    98,
     178,   186,    97,    -1,    -1,   183,     7,   175,   184,    98,
     179,    97,    -1,    -1,   181,   183,     7,   175,   184,    98,
     180,    97,    -1,   182,    -1,   181,   182,    -1,   194,    -1,
      80,    -1,    81,    -1,    82,    -1,    76,    -1,    77,    -1,
      -1,    30,   185,    -1,     7,    -1,   185,    31,     7,    -1,
     187,    -1,   186,   187,    -1,   188,    -1,   196,    -1,   189,
      -1,   181,   189,    -1,   193,    -1,   181,   193,    -1,    93,
       7,    23,   125,    24,    94,   118,   191,   202,    -1,    93,
       7,    23,    24,    94,   118,   191,   202,    -1,    99,    93,
       7,    23,   125,    24,    94,   118,   191,    98,    -1,    99,
      93,     7,    23,    24,    94,   118,   191,    98,    -1,   100,
       7,    23,   125,    24,   191,   202,    -1,   100,     7,    23,
      24,   191,   202,    -1,    99,   100,     7,    23,   125,    24,
     191,    98,    -1,    99,   100,     7,    23,    24,   191,    98,
      -1,    -1,    31,   101,    -1,    -1,    65,   192,    -1,     7,
      -1,   192,    31,     7,    -1,    85,     7,    23,   125,    24,
     191,   202,    -1,    85,     7,    23,    24,   191,   202,    -1,
      99,    85,     7,    23,   125,    24,   191,    98,    -1,    99,
      85,     7,    23,    24,   191,    98,    -1,    78,    -1,    79,
      -1,    -1,    32,   128,    -1,    96,     7,    94,   118,   195,
      98,    -1,   181,     7,    94,   118,   195,    98,    -1,    90,
       7,    94,   118,   195,    98,    -1,   181,    90,     7,    94,
     118,   195,    98,    -1,    90,   181,     7,    94,   118,   195,
      98,    -1,    89,     7,    23,   125,   190,    24,    94,   118,
     191,    98,    -1,    89,     7,    23,   190,    24,    94,   118,
     191,    98,    -1,    91,     7,    25,   199,    26,    -1,    91,
       7,    25,   199,    31,    26,    -1,     7,    -1,   199,    31,
       7,    -1,    92,     7,    32,   128,    98,    -1,    92,   118,
       7,    98,    -1,    -1,   103,    98,    -1,   104,    98,    -1,
      -1,    98,   201,   203,   127,    97,    -1,    98,    97,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   102,   102,   103,   107,   110,   114,   118,   122,   128,
     129,   135,   141,   145,   151,   152,   158,   164,   165,   166,
     173,   174,   175,   178,   182,   186,   190,   194,   198,   202,
     206,   212,   218,   224,   230,   236,   242,   246,   247,   248,
     252,   256,   264,   263,   278,   281,   282,   285,   289,   293,
     297,   304,   308,   312,   316,   320,   323,   327,   333,   337,
     343,   347,   353,   354,   360,   361,   367,   371,   375,   379,
     383,   387,   393,   394,   400,   401,   407,   408,   412,   418,
     419,   423,   427,   431,   437,   438,   442,   448,   449,   453,
     457,   461,   465,   469,   475,   476,   480,   484,   490,   491,
     495,   499,   505,   506,   507,   511,   517,   521,   526,   530,
     534,   538,   542,   546,   547,   548,   549,   550,   554,   558,
     562,   563,   567,   571,   575,   579,   583,   587,   593,   597,
     603,   607,   611,   615,   622,   623,   629,   635,   639,   647,
     650,   654,   660,   664,   665,   666,   667,   668,   669,   670,
     671,   672,   673,   674,   675,   676,   682,   686,   691,   695,
     701,   702,   708,   715,   718,   724,   730,   731,   737,   744,
     747,   753,   757,   763,   769,   775,   781,   788,   791,   794,
     801,   804,   807,   813,   819,   823,   827,   833,   834,   841,
     840,   850,   854,   860,   864,   868,   872,   879,   878,   886,
     893,   897,   901,   905,   911,   916,   921,   919,   930,   928,
     937,   936,   946,   944,   955,   956,   962,   963,   967,   971,
     977,   981,   988,   991,   997,  1001,  1007,  1008,  1014,  1015,
    1018,  1022,  1026,  1030,  1036,  1040,  1044,  1048,  1052,  1056,
    1060,  1064,  1071,  1074,  1081,  1084,  1090,  1094,  1100,  1104,
    1108,  1112,  1118,  1122,  1129,  1132,  1138,  1142,  1147,  1151,
    1156,  1162,  1166,  1172,  1176,  1182,  1186,  1192,  1196,  1203,
    1206,  1210,  1217,  1216,  1226
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT_LITERAL", "DOUBLE_LITERAL",
  "STRING_LITERAL", "REGEXP_LITERAL", "IDENTIFIER", "AUTOVAR", "IF",
  "ELSE", "ELSIF", "SWITCH", "CASE", "DEFAULT_T", "WHILE", "DO_T", "FOR",
  "FOREACH", "RETURN_T", "BREAK", "CONTINUE", "NULL_T", "LP", "RP", "LC",
  "RC", "LB", "RB", "SEMICOLON", "COLON", "COMMA", "ASSIGN_T",
  "LOGICAL_AND", "LOGICAL_OR", "EQ", "NE", "GT", "GE", "LT", "LE", "ADD",
  "SUB", "MUL", "DIV", "MOD", "BIT_AND", "BIT_OR", "BIT_XOR", "BIT_NOT",
  "TRUE_T", "FALSE_T", "EXCLAMATION", "DOT", "ADD_ASSIGN_T",
  "SUB_ASSIGN_T", "MUL_ASSIGN_T", "DIV_ASSIGN_T", "MOD_ASSIGN_T",
  "INCREMENT", "DECREMENT", "TRY", "CATCH", "FINALLY", "THROW", "THROWS",
  "VOID_T", "BOOLEAN_T", "INT_T", "DOUBLE_T", "STRING_T", "VARIENT_T",
  "NATIVE_POINTER_T", "NEW", "REQUIRE", "RENAME", "CLASS_T", "INTERFACE_T",
  "PUBLIC_T", "PRIVATE_T", "VIRTUAL_T", "OVERRIDE_T", "ABSTRACT_T",
  "THIS_T", "SUPER_T", "CONSTRUCTOR", "INSTANCEOF", "DOWN_CAST_BEGIN",
  "DOWN_CAST_END", "DELEGATE", "FINAL", "ENUM", "CONST", "FUNCTION", "AS",
  "THEN", "DIM", "END", "CR", "DECLARE", "BSUB", "APOSTROPHE", "LIB",
  "UNSAFE", "SAFE", "$accept", "translation_unit", "initial_declaration",
  "require_list", "require_declaration", "package_name", "rename_list",
  "rename_declaration", "definition_or_statement", "basic_type_specifier",
  "identifier_type_specifier", "array_type_specifier",
  "template_type_specifier", "type_specifier", "type_list", "lib_function",
  "$@1", "lib_function_declaration_list", "function_declaration",
  "function_definition", "parameter_list", "argument_list",
  "statement_list", "expression", "assignment_expression",
  "assignment_operator", "logical_or_expression", "logical_and_expression",
  "equality_expression", "relational_expression", "additive_expression",
  "multiplicative_expression", "unary_expression", "postfix_expression",
  "primary_expression", "primary_no_new_array", "array_literal",
  "array_creation", "dimension_expression_list", "dimension_expression",
  "dimension_list", "expression_list", "statement", "if_statement",
  "elsif_list", "elsif", "label_opt", "switch_statement", "case_list",
  "one_case", "default_opt", "case_expression_list", "while_statement",
  "for_statement", "do_while_statement", "foreach_statement",
  "expression_opt", "return_statement", "identifier_opt",
  "break_statement", "continue_statement", "try_statement", "catch_list",
  "catch_clause", "@2", "throw_statement", "declaration_statement",
  "block", "@3", "template_def_list", "template_list", "class_definition",
  "$@4", "$@5", "$@6", "$@7", "class_or_member_modifier_list",
  "class_or_member_modifier", "class_or_interface", "extends",
  "extends_list", "member_declaration_list", "member_declaration",
  "method_member", "method_function_definition", "apostrophe",
  "throws_clause", "exception_list", "constructor_definition",
  "access_modifier", "initializer_opt", "field_member",
  "delegate_definition", "enum_definition", "enumerator_list",
  "const_definition", "unsafe", "myblock", "@8", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   105,   106,   106,   107,   107,   107,   107,   107,   108,
     108,   109,   110,   110,   111,   111,   112,   113,   113,   113,
     113,   113,   113,   114,   114,   114,   114,   114,   114,   114,
     114,   115,   116,   116,   116,   117,   118,   118,   118,   118,
     119,   119,   121,   120,   122,   122,   122,   123,   123,   123,
     123,   124,   124,   124,   124,   124,   125,   125,   126,   126,
     127,   127,   128,   128,   129,   129,   130,   130,   130,   130,
     130,   130,   131,   131,   132,   132,   133,   133,   133,   134,
     134,   134,   134,   134,   135,   135,   135,   136,   136,   136,
     136,   136,   136,   136,   137,   137,   137,   137,   138,   138,
     138,   138,   139,   139,   139,   139,   140,   140,   140,   140,
     140,   140,   140,   140,   140,   140,   140,   140,   140,   140,
     140,   140,   140,   140,   140,   140,   140,   140,   141,   141,
     142,   142,   142,   142,   143,   143,   144,   145,   145,   146,
     146,   146,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   148,   148,   148,   148,
     149,   149,   150,   151,   151,   152,   153,   153,   154,   155,
     155,   156,   156,   157,   158,   159,   160,   161,   161,   162,
     163,   163,   164,   165,   166,   166,   166,   167,   167,   169,
     168,   170,   170,   171,   171,   171,   171,   173,   172,   172,
     174,   174,   174,   174,   175,   175,   177,   176,   178,   176,
     179,   176,   180,   176,   181,   181,   182,   182,   182,   182,
     183,   183,   184,   184,   185,   185,   186,   186,   187,   187,
     188,   188,   188,   188,   189,   189,   189,   189,   189,   189,
     189,   189,   190,   190,   191,   191,   192,   192,   193,   193,
     193,   193,   194,   194,   195,   195,   196,   196,   196,   196,
     196,   197,   197,   198,   198,   199,   199,   200,   200,   201,
     201,   201,   203,   202,   202
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     2,     1,
       2,     3,     1,     3,     1,     2,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     4,     1,     1,     1,     1,
       1,     3,     0,     6,     0,     2,     2,    11,    10,     9,
       8,    10,     9,     8,     7,     1,     3,     5,     1,     3,
       1,     2,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     3,     3,     1,     2,     2,     2,     1,     2,
       2,     3,     1,     1,     1,     1,     4,     4,     3,     4,
       3,     3,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     5,     6,     7,     3,     4,
       3,     4,     3,     4,     1,     2,     3,     2,     3,     0,
       1,     3,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     6,     5,     7,
       1,     2,     4,     0,     2,     5,     1,     2,     3,     0,
       2,     1,     3,     4,     8,     8,     8,     0,     1,     3,
       0,     1,     3,     3,     5,     4,     3,     1,     2,     0,
       5,     3,     2,     5,     7,     5,     7,     0,     4,     2,
       1,     3,     3,     5,     3,     0,     0,     8,     0,     9,
       0,     7,     0,     8,     1,     2,     1,     1,     1,     1,
       1,     1,     0,     2,     1,     3,     1,     2,     1,     1,
       1,     2,     1,     2,     9,     8,    10,     9,     7,     6,
       8,     7,     0,     2,     0,     2,     1,     3,     7,     6,
       8,     7,     1,     1,     0,     2,     6,     6,     6,     7,
       7,    10,     9,     5,     6,     1,     3,     5,     4,     0,
       2,     2,     0,     5,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       4,     0,     0,   163,     2,     6,     9,     7,    14,    12,
       0,     0,     1,   113,   114,   115,   116,   104,   105,     0,
       0,   177,   180,   180,   119,     0,   139,     0,     0,   117,
     118,     0,     0,     0,     0,   220,   221,   252,   253,   217,
     218,   219,   121,   122,     0,     0,     0,     0,     0,     0,
     155,     0,     0,     3,    55,    17,     0,    62,    64,    72,
      74,    76,    79,    84,    87,    94,    98,   102,   120,   103,
      19,   143,     0,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,    18,     0,   214,     0,   216,    20,
      21,    22,     0,     8,    10,     5,    15,     0,    11,     0,
       0,   164,   104,     0,     0,   178,     0,   181,     0,     0,
       0,   140,     0,    95,    98,    97,    96,   269,     0,   192,
       0,    31,    23,    24,    25,    26,    27,    28,    29,    30,
       0,     0,     0,     0,     0,    31,    30,    36,    38,    37,
      39,     0,     0,     0,     0,     0,     0,     0,   142,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    66,     0,    67,    68,
      69,    70,    71,    99,   100,     0,     0,     0,     0,     0,
       0,   177,     0,   215,     0,   205,    42,    13,    16,     0,
       0,     0,   179,   182,   183,   111,   128,     0,   274,     0,
       0,   272,   189,     0,   186,   187,   191,     0,     0,     0,
       0,   130,   134,   132,   242,     0,     0,     0,     0,     0,
       0,     0,     0,   242,     0,     0,     0,   242,    63,    73,
      75,    77,    78,    80,    81,    82,    83,    85,    86,    88,
      89,    90,    91,    92,    93,   110,     0,    58,   108,    31,
     101,     0,    65,     0,     0,   197,     0,     0,     0,   205,
       0,   222,     0,   107,   156,   139,   169,   166,   129,   141,
     270,   271,   163,     0,   185,     0,   188,   124,     0,     0,
     123,     0,     0,   135,   131,   133,     0,     0,   242,     0,
       0,   265,     0,    33,     0,    40,     0,    32,    34,   268,
     242,     0,     0,   242,   242,   242,     0,   109,     0,   112,
     106,   173,   199,   163,     0,   177,     0,   222,   200,     0,
       0,     0,    44,     0,     0,   158,   160,   140,     0,     0,
       0,   167,   165,   163,    60,     0,   184,   125,     0,   136,
     137,     0,     0,   243,     0,     0,     0,     0,   195,   263,
       0,   267,     0,    35,     0,     0,     0,   193,   242,     0,
     242,     0,     0,   244,    59,   163,     0,     0,     0,     0,
       0,     0,   204,   224,   223,   206,     0,   157,     0,     0,
     161,     0,   168,   170,   273,    61,     0,   126,     0,   138,
      56,     0,     0,     0,     0,   266,   264,    41,     0,     0,
       0,     0,     0,     0,   244,   244,     0,     0,   198,     0,
     177,     0,   208,    31,   202,   201,     0,     0,     0,    43,
      45,    46,     0,   159,   141,   190,   127,     0,     0,   244,
     196,     0,   244,   194,     0,     0,   244,     0,     0,   246,
     245,    54,     0,     0,     0,     0,     0,     0,   225,     0,
       0,     0,     0,     0,     0,     0,     0,   226,   228,   230,
     232,   229,   211,   162,    57,   244,     0,   244,     0,     0,
     244,     0,    50,    53,     0,   175,   174,   176,     0,   213,
     203,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   231,   233,   207,   227,     0,   262,     0,    52,
     244,     0,    49,   247,   209,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   261,    51,     0,    48,
     244,     0,   254,     0,     0,     0,   254,     0,     0,     0,
     244,     0,   254,     0,    47,     0,   244,     0,     0,     0,
     254,     0,     0,     0,   244,     0,     0,     0,   244,     0,
       0,   244,     0,   254,   249,     0,   255,   258,     0,   244,
       0,   256,     0,   244,     0,     0,     0,   244,   239,     0,
     257,     0,   248,   260,     0,   244,   251,     0,   244,     0,
     241,     0,   238,   259,   235,     0,   250,     0,   244,   240,
     234,   237,     0,   236
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,     6,    10,     7,     8,    53,   137,
     138,   139,   140,   141,   296,    93,   262,   376,    54,    55,
     288,   246,   333,    56,    57,   177,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,   211,   212,
     284,   112,   334,    71,   325,   326,    72,    73,   266,   267,
     332,   329,    74,    75,    76,    77,   106,    78,   108,    79,
      80,    81,   204,   205,   273,    82,    83,   256,   313,   319,
     261,    84,   417,   445,   418,   446,   455,    86,    87,   321,
     374,   456,   457,   458,   459,   289,   407,   440,   460,    88,
     539,   461,    89,    90,   292,    91,   201,   118,   272
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -501
static const yytype_int16 yypact[] =
{
      61,    53,    53,   502,   -38,    61,  -501,     3,  -501,  -501,
     -28,    23,  -501,  -501,  -501,  -501,  -501,   148,  -501,   960,
     960,   960,    99,    99,  -501,   960,   960,   960,   960,  -501,
    -501,   960,   -23,   358,   222,  -501,  -501,  -501,  -501,  -501,
    -501,  -501,  -501,  -501,   120,   130,   151,   377,   183,   185,
    -501,   -59,   193,  -501,  -501,  -501,   -16,  -501,   189,   144,
     249,   275,   259,   389,  -501,  -501,   223,   225,  -501,  -501,
    -501,  -501,   309,  -501,  -501,  -501,  -501,  -501,  -501,  -501,
    -501,  -501,  -501,  -501,  -501,   348,  -501,   262,  -501,  -501,
    -501,  -501,   266,  -501,  -501,     3,  -501,   268,  -501,   158,
     960,  -501,   270,    12,     7,   255,   205,  -501,   210,   235,
      15,  -501,    48,  -501,   110,  -501,  -501,    68,   256,  -501,
      16,    10,  -501,  -501,  -501,  -501,  -501,  -501,  -501,   293,
     315,   315,   297,   254,   325,   195,  -501,   332,  -501,   340,
    -501,   361,   356,   292,   380,   383,   369,   960,  -501,   960,
     960,   960,   960,   960,   960,   960,   960,   960,   960,   960,
     960,   960,   960,   960,   960,   844,  -501,   387,  -501,  -501,
    -501,  -501,  -501,  -501,  -501,   391,   391,   960,   960,   960,
     370,   960,   373,  -501,   392,   363,  -501,  -501,  -501,   239,
     -23,   393,  -501,  -501,  -501,  -501,  -501,   896,  -501,   307,
     313,  -501,  -501,   370,   273,  -501,  -501,   856,   405,   390,
     960,   386,  -501,   386,    20,   391,   408,   394,   960,   391,
     410,   411,   321,    20,   391,   398,   417,    20,  -501,   144,
     249,   275,   275,   259,   259,   259,   259,   389,   389,  -501,
    -501,  -501,  -501,  -501,  -501,  -501,   114,  -501,  -501,   137,
    -501,   364,  -501,   243,    18,   425,   439,   426,   457,   363,
     458,   437,   371,  -501,   328,   960,   331,  -501,  -501,  -501,
    -501,  -501,   792,   391,  -501,   -23,  -501,  -501,   170,   445,
    -501,   267,   908,  -501,   443,   443,   378,   374,   440,   450,
      -3,  -501,   228,  -501,    19,  -501,   216,  -501,  -501,  -501,
     440,   452,    30,    20,    20,   440,   453,  -501,   960,  -501,
    -501,  -501,  -501,   792,   455,   960,   449,   437,   451,   229,
     475,   388,  -501,   -23,   960,   342,  -501,   395,   454,   -23,
     -23,  -501,  -501,   600,  -501,   480,  -501,  -501,   948,  -501,
    -501,   456,   391,  -501,    17,   464,   396,   960,  -501,  -501,
      29,  -501,   391,  -501,   467,   400,   960,  -501,   440,   468,
     440,   471,   472,   433,  -501,   696,   960,   470,   960,   402,
     496,   506,  -501,  -501,   484,   420,   105,  -501,    14,   -23,
    -501,   960,  -501,  -501,  -501,  -501,   -23,  -501,   200,  -501,
    -501,   424,   432,   391,    26,  -501,  -501,  -501,   435,   391,
      27,   508,   436,   509,   433,   433,   527,   -23,  -501,   201,
     960,   204,   438,  -501,  -501,   507,   529,   -13,   441,  -501,
    -501,  -501,   -23,  -501,   442,  -501,  -501,   391,   391,   433,
    -501,   391,   433,  -501,   448,   391,   433,   447,   -23,  -501,
     512,  -501,   462,   -23,   370,   -13,   474,   496,  -501,   532,
      11,   539,   540,    95,   541,    41,   477,  -501,  -501,  -501,
    -501,  -501,  -501,  -501,  -501,   433,   463,   433,   -23,   391,
     433,   466,  -501,  -501,   542,  -501,  -501,  -501,   548,  -501,
    -501,   545,   478,    21,   546,   493,   543,   558,   581,   566,
     503,   583,  -501,  -501,  -501,  -501,   498,  -501,   -23,  -501,
     433,   501,  -501,  -501,  -501,    47,   391,   516,   108,   391,
     588,   590,   591,   122,   391,   521,  -501,  -501,   518,  -501,
     433,   209,   585,   391,   524,   213,   585,   123,   143,   150,
     433,   214,   585,   391,  -501,   -23,   433,   617,   960,   533,
     585,   391,   538,   536,   433,   218,   549,   219,   433,   227,
     -23,   433,   537,   585,  -501,   -23,   255,  -501,   555,   433,
     391,  -501,   556,   433,   391,   552,   557,   433,  -501,   -23,
    -501,   559,  -501,  -501,   -23,   433,  -501,   560,   433,   391,
    -501,   561,  -501,  -501,  -501,   -23,  -501,   562,   433,  -501,
    -501,  -501,   564,  -501
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -501,  -501,  -501,  -501,   631,   635,   634,     9,  -501,   606,
     -30,  -501,  -501,  -163,  -501,  -501,  -501,  -501,   280,  -501,
    -206,  -199,   350,   -19,    -4,  -501,  -501,   517,   515,   220,
     176,   198,    -8,  -501,    57,  -501,  -501,  -501,   544,  -169,
     459,   403,     8,  -501,  -501,   344,  -501,  -501,  -501,   401,
    -501,  -501,  -501,  -501,  -501,  -501,  -171,  -501,   647,  -501,
    -501,  -501,  -501,   473,  -501,  -501,  -501,  -196,  -501,  -501,
     412,   298,  -501,  -501,  -501,  -501,     0,   -80,   593,   359,
    -501,   234,  -419,  -501,   226,  -192,   -47,  -501,   230,  -501,
    -500,  -501,  -501,  -501,  -501,  -501,  -501,  -181,  -501
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -213
static const yytype_int16 yytable[] =
{
     103,   104,   105,    85,   131,   183,   110,   274,   278,   264,
     257,    70,   250,   251,   120,   147,    96,   300,   482,   113,
     115,   305,   111,   116,   391,    97,   543,   286,   507,   347,
      99,   301,   552,   207,   144,   306,   395,   495,   147,   195,
     558,   145,   283,   147,   283,   147,   147,   147,   490,   147,
     147,   287,   290,   571,   286,   396,   295,   147,   147,   495,
       9,   302,   356,   208,    92,    37,    38,    39,    40,    41,
      98,   520,   449,   311,   196,   117,    97,   450,     2,   197,
     451,   189,   148,   452,   114,   114,   453,   454,   114,    37,
      38,    39,    40,    41,   336,   348,   345,   358,   360,    37,
      38,    39,    40,    41,    96,   191,   107,   190,   354,   422,
     335,   359,   361,   362,   206,   286,   117,   351,   343,    37,
      38,    39,    40,    41,   430,   433,   449,   132,   357,   286,
     286,   491,   524,   165,   451,     1,     2,   133,   307,   388,
     453,   454,   377,   228,   367,   308,   530,   544,   382,   383,
     286,   239,   240,   241,   242,   243,   244,   286,   134,   253,
     254,   247,   105,   167,   217,   198,   401,   546,   403,   173,
     174,   199,   200,   252,   548,   100,   219,   150,   101,   390,
     486,    35,    36,    37,    38,    39,    40,    41,   487,   397,
     142,   281,   143,   269,   337,   488,   175,   176,   423,   294,
     146,   308,   419,   247,    51,   425,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   217,   149,   426,   442,   441,   218,   444,   121,
     429,   308,   147,   536,   219,   147,   432,   542,   551,   443,
     537,   463,   563,   565,   537,   537,   165,   352,   477,   537,
     537,   567,   178,   353,   349,   166,   188,   473,   537,   350,
     371,   327,   476,   281,   464,   465,   372,   263,   467,   185,
     147,   310,   470,   186,   147,   187,   167,   168,   169,   170,
     171,   172,   173,   174,   151,   152,   147,   499,   122,   123,
     124,   125,   126,   127,   128,   339,   105,   100,   147,   521,
     157,   158,   525,   192,   364,   378,   500,   531,   193,   175,
     176,   129,   153,   154,   155,   156,   209,   517,   202,   203,
     214,   545,   547,   549,   179,   180,   181,   182,   394,   233,
     234,   235,   236,   194,   247,   202,   275,   400,   323,   324,
     414,   385,   210,   522,   265,   330,   526,   409,   215,   411,
     216,   532,   379,   324,   554,   237,   238,   437,   438,   220,
     540,    13,    14,    15,    16,   102,    18,   221,   222,   568,
     553,   231,   232,   385,   572,   183,    85,   424,   559,   223,
      24,    25,   466,    26,   135,   468,   224,   225,   582,   471,
     226,   105,   227,   584,   248,   255,   258,   575,   249,   259,
      27,   578,   260,   183,   590,   270,   265,    28,    29,    30,
      31,   271,   279,   282,   280,   291,   588,   480,   496,   299,
     498,   303,   293,   501,    35,    36,    37,    38,    39,    40,
      41,    34,   159,   160,   161,   162,   163,   164,   297,   298,
     304,    42,    43,   122,   123,   124,   125,   126,   127,   128,
     483,   312,   309,   518,   314,   315,   119,   122,   123,   124,
     125,   126,   127,   128,   316,   318,   136,   320,   338,   322,
     341,   344,   342,   535,   346,   343,   355,   363,   366,   368,
     136,   370,   373,   550,   389,   381,   375,   386,   392,   555,
     393,   398,   402,  -171,   399,   404,   405,   562,   406,   410,
     412,   566,    12,   413,   569,    13,    14,    15,    16,    17,
      18,    19,   574,   415,    20,   416,   577,  -210,   427,   556,
     581,    21,    22,    23,    24,    25,   428,    26,   585,   431,
     435,   587,   434,   436,   439,  -212,   448,   447,   462,   481,
    -172,   592,   469,   474,    27,   472,   484,   485,   489,   503,
     510,    28,    29,    30,    31,    37,    38,    39,    40,    41,
     475,   497,   449,    32,   502,   511,    33,   450,   505,   508,
     451,   479,   506,   452,   494,    34,   453,   454,    35,    36,
      37,    38,    39,    40,    41,    42,    43,   509,   512,   513,
     515,    44,    45,    46,    47,    48,   516,   514,    49,   519,
      50,    51,    52,    13,    14,    15,    16,    17,    18,    19,
     523,   527,    20,   528,   529,   533,   534,   538,   541,    21,
      22,    23,    24,    25,   391,    26,    37,    38,    39,    40,
      41,   557,   560,   449,   561,   570,    94,    11,   450,    95,
     130,   451,    27,   564,   452,   504,   579,   453,   454,    28,
      29,    30,    31,   573,   576,   580,   420,   583,   586,   589,
     591,    32,   593,   365,    33,   230,   229,   331,   328,   380,
     109,   317,   285,    34,   421,   213,   369,   276,   184,   478,
       0,   492,     0,    42,    43,   493,     0,     0,     0,     0,
      45,     0,     0,     0,     0,     0,    49,   384,    50,    13,
      14,    15,    16,    17,    18,    19,     0,     0,    20,     0,
       0,     0,     0,     0,     0,    21,    22,    23,    24,    25,
       0,    26,   408,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    27,     0,
       0,     0,     0,     0,     0,    28,    29,    30,    31,     0,
       0,     0,     0,     0,     0,     0,     0,    32,     0,     0,
      33,     0,     0,     0,     0,     0,     0,     0,     0,    34,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    42,
      43,     0,     0,     0,     0,     0,    45,     0,     0,     0,
       0,     0,    49,     0,    50,    13,    14,    15,    16,    17,
      18,    19,     0,     0,    20,     0,     0,     0,     0,     0,
       0,    21,    22,    23,    24,    25,     0,    26,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    27,     0,     0,     0,     0,     0,
       0,    28,    29,    30,    31,     0,     0,    13,    14,    15,
      16,   102,    18,    32,     0,     0,    33,     0,     0,    13,
      14,    15,    16,   102,    18,    34,    24,    25,   245,    26,
       0,     0,     0,     0,     0,    42,    43,     0,    24,    25,
     277,    26,    45,     0,     0,     0,    27,     0,    49,     0,
      50,     0,     0,    28,    29,    30,    31,     0,    27,    13,
      14,    15,    16,   102,    18,    28,    29,    30,    31,     0,
       0,    13,    14,    15,    16,   102,    18,    34,    24,    25,
       0,    26,   268,     0,     0,     0,     0,    42,    43,    34,
      24,    25,     0,    26,     0,     0,   340,     0,    27,    42,
      43,     0,     0,     0,     0,    28,    29,    30,    31,     0,
      27,    13,    14,    15,    16,   102,    18,    28,    29,    30,
      31,     0,     0,    13,    14,    15,    16,   102,    18,    34,
      24,    25,   387,    26,     0,     0,     0,     0,     0,    42,
      43,    34,    24,    25,     0,    26,     0,     0,     0,     0,
      27,    42,    43,     0,     0,     0,     0,    28,    29,    30,
      31,     0,    27,     0,     0,     0,     0,     0,     0,    28,
      29,    30,    31,     0,     0,     0,     0,     0,     0,     0,
       0,    34,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    42,    43,    34,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    42,    43
};

static const yytype_int16 yycheck[] =
{
      19,    20,    21,     3,    34,    85,    25,   203,   207,   190,
     181,     3,   175,   176,    33,    31,     7,   223,     7,    27,
      28,   227,    26,    31,     7,    53,   526,     7,     7,    32,
       7,   223,   532,    23,    93,   227,     7,   456,    31,    24,
     540,   100,   211,    31,   213,    31,    31,    31,     7,    31,
      31,    31,   215,   553,     7,    26,   219,    31,    31,   478,
       7,   224,    32,    53,   102,    78,    79,    80,    81,    82,
      98,    24,    85,   254,    26,    98,    53,    90,    75,    31,
      93,   100,    98,    96,    27,    28,    99,   100,    31,    78,
      79,    80,    81,    82,   275,    98,   288,   303,   304,    78,
      79,    80,    81,    82,    95,    98,     7,    95,   300,    95,
     273,   303,   304,   305,    98,     7,    98,    98,   101,    78,
      79,    80,    81,    82,    98,    98,    85,     7,    98,     7,
       7,    90,    24,    23,    93,    74,    75,     7,    24,   338,
      99,   100,   323,   147,   315,    31,    24,    24,   329,   330,
       7,   159,   160,   161,   162,   163,   164,     7,     7,   178,
     179,   165,   181,    53,    27,    97,   358,    24,   360,    59,
      60,   103,   104,   177,    24,    27,    39,    33,    30,   342,
      85,    76,    77,    78,    79,    80,    81,    82,    93,   352,
       7,   210,     7,   197,    24,   100,    86,    87,   379,   218,
       7,    31,    97,   207,    99,   386,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,    27,    34,    24,    24,   407,    32,    24,     7,
     393,    31,    31,    24,    39,    31,   399,    24,    24,   410,
      31,   422,    24,    24,    31,    31,    23,    31,   444,    31,
      31,    24,    27,    37,    26,    32,    98,   438,    31,    31,
      31,   265,   443,   282,   427,   428,    37,    28,   431,     7,
      31,    28,   435,     7,    31,     7,    53,    54,    55,    56,
      57,    58,    59,    60,    35,    36,    31,   468,    66,    67,
      68,    69,    70,    71,    72,    28,   315,    27,    31,   505,
      41,    42,   508,    98,   308,   324,   469,   513,    98,    86,
      87,    89,    37,    38,    39,    40,    23,   498,    62,    63,
      23,   527,   528,   529,    15,    16,    17,    18,   347,   153,
     154,   155,   156,    98,   338,    62,    63,   356,    10,    11,
     370,   333,    27,   506,    13,    14,   509,   366,    94,   368,
      25,   514,    10,    11,   535,   157,   158,   404,   405,    27,
     523,     3,     4,     5,     6,     7,     8,    27,     7,   550,
     533,   151,   152,   365,   555,   455,   376,   381,   541,    23,
      22,    23,   429,    25,     7,   432,    94,     7,   569,   436,
       7,   410,    23,   574,     7,    25,    23,   560,     7,     7,
      42,   564,    39,   483,   585,    98,    13,    49,    50,    51,
      52,    98,     7,    27,    24,     7,   579,   447,   465,    98,
     467,    23,    28,   470,    76,    77,    78,    79,    80,    81,
      82,    73,    43,    44,    45,    46,    47,    48,    28,    28,
      23,    83,    84,    66,    67,    68,    69,    70,    71,    72,
     450,    26,    88,   500,    15,    29,    98,    66,    67,    68,
      69,    70,    71,    72,     7,     7,    89,    30,    23,    98,
      27,    31,    94,   520,    24,   101,    24,    24,    23,    30,
      89,    30,     7,   530,    28,    31,    98,     7,    24,   536,
      94,    24,    24,    98,    94,    24,    24,   544,    65,    29,
      98,   548,     0,     7,   551,     3,     4,     5,     6,     7,
       8,     9,   559,     7,    12,    31,   563,    97,    94,   538,
     567,    19,    20,    21,    22,    23,    94,    25,   575,    94,
      94,   578,    24,    24,     7,    97,     7,    30,    97,     7,
      98,   588,    94,    31,    42,    98,     7,     7,     7,     7,
       7,    49,    50,    51,    52,    78,    79,    80,    81,    82,
      98,    98,    85,    61,    98,     7,    64,    90,    23,    23,
      93,    97,    94,    96,    97,    73,    99,   100,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    94,     7,    23,
       7,    89,    90,    91,    92,    93,    98,    94,    96,    98,
      98,    99,   100,     3,     4,     5,     6,     7,     8,     9,
      94,    23,    12,    23,    23,    94,    98,    32,    94,    19,
      20,    21,    22,    23,     7,    25,    78,    79,    80,    81,
      82,    98,    94,    85,    98,    98,     5,     2,    90,     5,
      34,    93,    42,    94,    96,    97,    94,    99,   100,    49,
      50,    51,    52,    98,    98,    98,   376,    98,    98,    98,
      98,    61,    98,   313,    64,   150,   149,   266,   265,   325,
      23,   259,   213,    73,   376,   131,   317,   204,    85,   445,
      -1,   455,    -1,    83,    84,   455,    -1,    -1,    -1,    -1,
      90,    -1,    -1,    -1,    -1,    -1,    96,    97,    98,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    19,    20,    21,    22,    23,
      -1,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,
      64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,
      84,    -1,    -1,    -1,    -1,    -1,    90,    -1,    -1,    -1,
      -1,    -1,    96,    -1,    98,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    20,    21,    22,    23,    -1,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    50,    51,    52,    -1,    -1,     3,     4,     5,
       6,     7,     8,    61,    -1,    -1,    64,    -1,    -1,     3,
       4,     5,     6,     7,     8,    73,    22,    23,    24,    25,
      -1,    -1,    -1,    -1,    -1,    83,    84,    -1,    22,    23,
      24,    25,    90,    -1,    -1,    -1,    42,    -1,    96,    -1,
      98,    -1,    -1,    49,    50,    51,    52,    -1,    42,     3,
       4,     5,     6,     7,     8,    49,    50,    51,    52,    -1,
      -1,     3,     4,     5,     6,     7,     8,    73,    22,    23,
      -1,    25,    26,    -1,    -1,    -1,    -1,    83,    84,    73,
      22,    23,    -1,    25,    -1,    -1,    28,    -1,    42,    83,
      84,    -1,    -1,    -1,    -1,    49,    50,    51,    52,    -1,
      42,     3,     4,     5,     6,     7,     8,    49,    50,    51,
      52,    -1,    -1,     3,     4,     5,     6,     7,     8,    73,
      22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,    83,
      84,    73,    22,    23,    -1,    25,    -1,    -1,    -1,    -1,
      42,    83,    84,    -1,    -1,    -1,    -1,    49,    50,    51,
      52,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      50,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    83,    84,    73,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    83,    84
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    74,    75,   106,   107,   108,   109,   111,   112,     7,
     110,   110,     0,     3,     4,     5,     6,     7,     8,     9,
      12,    19,    20,    21,    22,    23,    25,    42,    49,    50,
      51,    52,    61,    64,    73,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    89,    90,    91,    92,    93,    96,
      98,    99,   100,   113,   123,   124,   128,   129,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     147,   148,   151,   152,   157,   158,   159,   160,   162,   164,
     165,   166,   170,   171,   176,   181,   182,   183,   194,   197,
     198,   200,   102,   120,   109,   111,   112,    53,    98,     7,
      27,    30,     7,   128,   128,   128,   161,     7,   163,   163,
     128,   129,   146,   137,   139,   137,   137,    98,   202,    98,
     128,     7,    66,    67,    68,    69,    70,    71,    72,    89,
     114,   115,     7,     7,     7,     7,    89,   114,   115,   116,
     117,   118,     7,     7,    93,   100,     7,    31,    98,    34,
      33,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    23,    32,    53,    54,    55,
      56,    57,    58,    59,    60,    86,    87,   130,    27,    15,
      16,    17,    18,   182,   183,     7,     7,     7,    98,   128,
      95,    98,    98,    98,    98,    24,    26,    31,    97,   103,
     104,   201,    62,    63,   167,   168,    98,    23,    53,    23,
      27,   143,   144,   143,    23,    94,    25,    27,    32,    39,
      27,    27,     7,    23,    94,     7,     7,    23,   129,   132,
     133,   134,   134,   135,   135,   135,   135,   136,   136,   137,
     137,   137,   137,   137,   137,    24,   126,   129,     7,     7,
     118,   118,   129,   128,   128,    25,   172,   161,    23,     7,
      39,   175,   121,    28,   202,    13,   153,   154,    26,   129,
      98,    98,   203,   169,   172,    63,   168,    24,   126,     7,
      24,   128,    27,   144,   145,   145,     7,    31,   125,   190,
     118,     7,   199,    28,   128,   118,   119,    28,    28,    98,
     125,   190,   118,    23,    23,   125,   190,    24,    31,    88,
      28,   202,    26,   173,    15,    29,     7,   175,     7,   174,
      30,   184,    98,    10,    11,   149,   150,   129,   146,   156,
      14,   154,   155,   127,   147,   118,   202,    24,    23,    28,
      28,    27,    94,   101,    31,   190,    24,    32,    98,    26,
      31,    98,    31,    37,   190,    24,    32,    98,   125,   190,
     125,   190,   190,    24,   129,   127,    23,   161,    30,   184,
      30,    31,    37,     7,   185,    98,   122,   202,   128,    10,
     150,    31,   202,   202,    97,   147,     7,    24,   126,    28,
     118,     7,    24,    94,   128,     7,    26,   118,    24,    94,
     128,   190,    24,   190,    24,    24,    65,   191,    26,   128,
      29,   128,    98,     7,   115,     7,    31,   177,   179,    97,
     123,   176,    95,   202,   129,   202,    24,    94,    94,   118,
      98,    94,   118,    98,    24,    94,    24,   191,   191,     7,
     192,   202,    24,   161,    24,   178,   180,    30,     7,    85,
      90,    93,    96,    99,   100,   181,   186,   187,   188,   189,
     193,   196,    97,   202,   118,   118,   191,   118,   191,    94,
     118,   191,    98,   202,    31,    98,   202,   172,   186,    97,
     115,     7,     7,   181,     7,     7,    85,    93,   100,     7,
       7,    90,   189,   193,    97,   187,   191,    98,   191,   202,
     118,   191,    98,     7,    97,    23,    94,     7,    23,    94,
       7,     7,     7,    23,    94,     7,    98,   202,   191,    98,
      24,   125,   118,    94,    24,   125,   118,    23,    23,    23,
      24,   125,   118,    94,    98,   191,    24,    31,    32,   195,
     118,    94,    24,   195,    24,   125,    24,   125,    24,   125,
     191,    24,   195,   118,   202,   191,   128,    98,   195,   118,
      94,    98,   191,    24,    94,    24,   191,    24,   202,   191,
      98,   195,   202,    98,   191,   118,    98,   191,   118,    94,
      98,   191,   202,    98,   202,   191,    98,   191,   118,    98,
     202,    98,   191,    98
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 4:

/* Line 1455 of yacc.c  */
#line 107 "diksam.y"
    {
            dkc_set_require_and_rename_list(NULL, NULL);
        }
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 111 "diksam.y"
    {
            dkc_set_require_and_rename_list((yyvsp[(1) - (2)].require_list), (yyvsp[(2) - (2)].rename_list));
        }
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 115 "diksam.y"
    {
            dkc_set_require_and_rename_list((yyvsp[(1) - (1)].require_list), NULL);
        }
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 119 "diksam.y"
    {
            dkc_set_require_and_rename_list(NULL, (yyvsp[(1) - (1)].rename_list));
        }
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 123 "diksam.y"
    {
            dkc_set_require_and_rename_list(NULL, NULL);
		}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 130 "diksam.y"
    {
            (yyval.require_list) = dkc_chain_require_list((yyvsp[(1) - (2)].require_list), (yyvsp[(2) - (2)].require_list));
        }
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 136 "diksam.y"
    {
            (yyval.require_list) = dkc_create_require_list((yyvsp[(2) - (3)].package_name));
        }
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 142 "diksam.y"
    {
            (yyval.package_name) = dkc_create_package_name((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 146 "diksam.y"
    {
            (yyval.package_name) = dkc_chain_package_name((yyvsp[(1) - (3)].package_name), (yyvsp[(3) - (3)].identifier));
        }
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 153 "diksam.y"
    {
            (yyval.rename_list) = dkc_chain_rename_list((yyvsp[(1) - (2)].rename_list), (yyvsp[(2) - (2)].rename_list));
        }
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 159 "diksam.y"
    {
            (yyval.rename_list) = dkc_create_rename_list((yyvsp[(2) - (4)].package_name), (yyvsp[(3) - (4)].identifier));
        }
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 167 "diksam.y"
    {
            DKC_Compiler *compiler = dkc_get_current_compiler();

            compiler->statement_list
                = dkc_chain_statement_list(compiler->statement_list, (yyvsp[(1) - (1)].statement));
        }
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 179 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_VOID_TYPE;
        }
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 183 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_BOOLEAN_TYPE;
        }
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 187 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_INT_TYPE;
        }
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 191 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_DOUBLE_TYPE;
        }
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 195 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_STRING_TYPE;
        }
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 199 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_VARIENT_TYPE;
        }
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 203 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_NATIVE_POINTER_TYPE;
        }
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 207 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_DELEGATE_TYPE;
        }
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 213 "diksam.y"
    {
            (yyval.type_specifier) = dkc_create_identifier_type_specifier((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 219 "diksam.y"
    {
            TypeSpecifier *basic_type
                = dkc_create_type_specifier((yyvsp[(1) - (3)].basic_type_specifier));
            (yyval.type_specifier) = dkc_create_array_type_specifier(basic_type);
        }
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 225 "diksam.y"
    {
            TypeSpecifier *identifier_type
                = dkc_create_identifier_type_specifier((yyvsp[(1) - (3)].identifier));
            (yyval.type_specifier) = dkc_create_array_type_specifier(identifier_type);
        }
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 231 "diksam.y"
    {
            (yyval.type_specifier) = dkc_create_array_type_specifier((yyvsp[(1) - (3)].type_specifier));
        }
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 237 "diksam.y"
    {//fix-me : shift/reduce
			(yyval.type_specifier)= dkc_create_template_type_specifier((yyvsp[(1) - (4)].identifier),(yyvsp[(3) - (4)].template));
		}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 243 "diksam.y"
    {
                    (yyval.type_specifier) = dkc_create_type_specifier((yyvsp[(1) - (1)].basic_type_specifier));
        }
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 253 "diksam.y"
    {
			(yyval.template)=dkc_create_template_list((yyvsp[(1) - (1)].type_specifier));
		}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 257 "diksam.y"
    {
            (yyval.template) = dkc_chain_template_list((yyvsp[(1) - (3)].template), (yyvsp[(3) - (3)].type_specifier));
        }
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 264 "diksam.y"
    {   
			if(BcGetCurrentCompilerContext()->libname)
			{
				    dkc_compile_error(dkc_get_current_compiler()->current_line_number,
                      MULTIPLE_LIB_ERR,MESSAGE_ARGUMENT_END);
			}
			BcGetCurrentCompilerContext()->libname=(yyvsp[(2) - (2)].identifier);
			BcGetCurrentCompilerContext()->isLib=1;
		}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 274 "diksam.y"
    {
			BcGetCurrentCompilerContext()->isLib=0;
		}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 286 "diksam.y"
    {
            dkc_function_define((yyvsp[(9) - (11)].type_specifier), (yyvsp[(3) - (11)].identifier), (yyvsp[(5) - (11)].parameter_list), (yyvsp[(10) - (11)].exception_list), NULL,(yyvsp[(6) - (11)].apost));
        }
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 290 "diksam.y"
    {
            dkc_function_define((yyvsp[(8) - (10)].type_specifier), (yyvsp[(3) - (10)].identifier), NULL, (yyvsp[(9) - (10)].exception_list), NULL,(yyvsp[(5) - (10)].apost));
        }
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 294 "diksam.y"
    {
            dkc_function_define(0, (yyvsp[(3) - (9)].identifier), (yyvsp[(5) - (9)].parameter_list), (yyvsp[(8) - (9)].exception_list), NULL,(yyvsp[(6) - (9)].apost));
        }
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 298 "diksam.y"
    {
			//printf("lib:%s\n",BcGetCurrentCompilerContext()->libname);
            dkc_function_define(0, (yyvsp[(3) - (8)].identifier), NULL, (yyvsp[(7) - (8)].exception_list), NULL,(yyvsp[(5) - (8)].apost));
        }
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 305 "diksam.y"
    {
            dkc_function_define((yyvsp[(8) - (10)].type_specifier), (yyvsp[(2) - (10)].identifier), (yyvsp[(4) - (10)].parameter_list), (yyvsp[(9) - (10)].exception_list), (yyvsp[(10) - (10)].block),(yyvsp[(5) - (10)].apost));
        }
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 309 "diksam.y"
    {
            dkc_function_define((yyvsp[(7) - (9)].type_specifier), (yyvsp[(2) - (9)].identifier), NULL, (yyvsp[(8) - (9)].exception_list), (yyvsp[(9) - (9)].block),(yyvsp[(4) - (9)].apost));
        }
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 313 "diksam.y"
    { //modified
            dkc_function_define(0, (yyvsp[(2) - (8)].identifier), (yyvsp[(4) - (8)].parameter_list), (yyvsp[(7) - (8)].exception_list), (yyvsp[(8) - (8)].block),(yyvsp[(5) - (8)].apost));
        }
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 317 "diksam.y"
    {
            dkc_function_define(0, (yyvsp[(2) - (7)].identifier), NULL, (yyvsp[(6) - (7)].exception_list), (yyvsp[(7) - (7)].block),(yyvsp[(4) - (7)].apost));
        }
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 324 "diksam.y"
    {
            (yyval.parameter_list) = dkc_create_parameter((yyvsp[(3) - (3)].type_specifier), (yyvsp[(1) - (3)].identifier));
        }
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 328 "diksam.y"
    {
            (yyval.parameter_list) = dkc_chain_parameter((yyvsp[(1) - (5)].parameter_list), (yyvsp[(5) - (5)].type_specifier), (yyvsp[(3) - (5)].identifier));
        }
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 334 "diksam.y"
    {
            (yyval.argument_list) = dkc_create_argument_list((yyvsp[(1) - (1)].expression));
        }
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 338 "diksam.y"
    {
            (yyval.argument_list) = dkc_chain_argument_list((yyvsp[(1) - (3)].argument_list), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 344 "diksam.y"
    {
            (yyval.statement_list) = dkc_create_statement_list((yyvsp[(1) - (1)].statement));
        }
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 348 "diksam.y"
    {
            (yyval.statement_list) = dkc_chain_statement_list((yyvsp[(1) - (2)].statement_list), (yyvsp[(2) - (2)].statement));
        }
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 355 "diksam.y"
    {
            (yyval.expression) = dkc_create_comma_expression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 362 "diksam.y"
    {
            (yyval.expression) = dkc_create_assign_expression((yyvsp[(1) - (3)].expression), (yyvsp[(2) - (3)].assignment_operator), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 368 "diksam.y"
    {
            (yyval.assignment_operator) = NORMAL_ASSIGN;
        }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 372 "diksam.y"
    {
            (yyval.assignment_operator) = ADD_ASSIGN;
        }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 376 "diksam.y"
    {
            (yyval.assignment_operator) = SUB_ASSIGN;
        }
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 380 "diksam.y"
    {
            (yyval.assignment_operator) = MUL_ASSIGN;
        }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 384 "diksam.y"
    {
            (yyval.assignment_operator) = DIV_ASSIGN;
        }
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 388 "diksam.y"
    {
            (yyval.assignment_operator) = MOD_ASSIGN;
        }
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 395 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(LOGICAL_OR_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 402 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(LOGICAL_AND_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 409 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(EQ_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 413 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(NE_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 420 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(GT_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 424 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(GE_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 428 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(LT_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 432 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(LE_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 439 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(ADD_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 443 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(SUB_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 450 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(MUL_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 454 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(DIV_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 458 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(MOD_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 462 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(BIT_AND_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 466 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(BIT_OR_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 470 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(BIT_XOR_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 477 "diksam.y"
    {
            (yyval.expression) = dkc_create_minus_expression((yyvsp[(2) - (2)].expression));
        }
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 481 "diksam.y"
    {
            (yyval.expression) = dkc_create_logical_not_expression((yyvsp[(2) - (2)].expression));
        }
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 485 "diksam.y"
    {
            (yyval.expression) = dkc_create_bit_not_expression((yyvsp[(2) - (2)].expression));
        }
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 492 "diksam.y"
    {
            (yyval.expression) = dkc_create_incdec_expression((yyvsp[(1) - (2)].expression), INCREMENT_EXPRESSION);
        }
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 496 "diksam.y"
    {
            (yyval.expression) = dkc_create_incdec_expression((yyvsp[(1) - (2)].expression), DECREMENT_EXPRESSION);
        }
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 500 "diksam.y"
    {
            (yyval.expression) = dkc_create_instanceof_expression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].type_specifier));
        }
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 508 "diksam.y"
    {
            (yyval.expression) = dkc_create_identifier_expression((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 512 "diksam.y"
    {
			(yyval.expression)=BcCreateAutoExpression((yyvsp[(1) - (1)].identifier));
		}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 518 "diksam.y"
    {
            (yyval.expression) = dkc_create_index_expression((yyvsp[(1) - (4)].expression), (yyvsp[(3) - (4)].expression));
        }
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 522 "diksam.y"
    {
            Expression *identifier = dkc_create_identifier_expression((yyvsp[(1) - (4)].identifier));
            (yyval.expression) = dkc_create_index_expression(identifier, (yyvsp[(3) - (4)].expression));
        }
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 527 "diksam.y"
    {
            (yyval.expression) = dkc_create_member_expression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].identifier));
        }
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 531 "diksam.y"
    {
            (yyval.expression) = dkc_create_function_call_expression((yyvsp[(1) - (4)].expression), (yyvsp[(3) - (4)].argument_list));
        }
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 535 "diksam.y"
    {
            (yyval.expression) = dkc_create_function_call_expression((yyvsp[(1) - (3)].expression), NULL);
        }
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 539 "diksam.y"
    {
            (yyval.expression) = (yyvsp[(2) - (3)].expression);
        }
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 543 "diksam.y"
    {
            (yyval.expression) = dkc_create_down_cast_expression((yyvsp[(1) - (4)].expression), (yyvsp[(3) - (4)].type_specifier));
        }
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 551 "diksam.y"
    {
            (yyval.expression) = dkc_create_boolean_expression(DVM_TRUE);
        }
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 555 "diksam.y"
    {
            (yyval.expression) = dkc_create_boolean_expression(DVM_FALSE);
        }
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 559 "diksam.y"
    {
            (yyval.expression) = dkc_create_null_expression();
        }
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 564 "diksam.y"
    {
            (yyval.expression) = dkc_create_this_expression();
        }
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 568 "diksam.y"
    {
            (yyval.expression) = dkc_create_super_expression();
        }
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 572 "diksam.y"
    {
			(yyval.expression) = dkc_create_new_delegate_expression();
		}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 576 "diksam.y"
    {
            (yyval.expression) = dkc_create_new_expression((yyvsp[(2) - (4)].identifier), NULL, NULL);
        }
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 580 "diksam.y"
    {
            (yyval.expression) = dkc_create_new_expression((yyvsp[(2) - (5)].identifier), NULL, (yyvsp[(4) - (5)].argument_list));
        }
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 584 "diksam.y"
    {
            (yyval.expression) = dkc_create_new_expression((yyvsp[(2) - (6)].identifier), (yyvsp[(4) - (6)].identifier), NULL);
        }
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 588 "diksam.y"
    {
            (yyval.expression) = dkc_create_new_expression((yyvsp[(2) - (7)].identifier), (yyvsp[(4) - (7)].identifier), (yyvsp[(6) - (7)].argument_list));
        }
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 594 "diksam.y"
    {
            (yyval.expression) = dkc_create_array_literal_expression((yyvsp[(2) - (3)].expression_list));
        }
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 598 "diksam.y"
    {
            (yyval.expression) = dkc_create_array_literal_expression((yyvsp[(2) - (4)].expression_list));
        }
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 604 "diksam.y"
    {
            (yyval.expression) = dkc_create_basic_array_creation((yyvsp[(2) - (3)].basic_type_specifier), (yyvsp[(3) - (3)].array_dimension), NULL);
        }
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 608 "diksam.y"
    {
            (yyval.expression) = dkc_create_basic_array_creation((yyvsp[(2) - (4)].basic_type_specifier), (yyvsp[(3) - (4)].array_dimension), (yyvsp[(4) - (4)].array_dimension));
        }
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 612 "diksam.y"
    {
            (yyval.expression) = dkc_create_class_array_creation((yyvsp[(2) - (3)].type_specifier), (yyvsp[(3) - (3)].array_dimension), NULL);
        }
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 617 "diksam.y"
    {
            (yyval.expression) = dkc_create_class_array_creation((yyvsp[(2) - (4)].type_specifier), (yyvsp[(3) - (4)].array_dimension), (yyvsp[(4) - (4)].array_dimension));
        }
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 624 "diksam.y"
    {
            (yyval.array_dimension) = dkc_chain_array_dimension((yyvsp[(1) - (2)].array_dimension), (yyvsp[(2) - (2)].array_dimension));
        }
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 630 "diksam.y"
    {
            (yyval.array_dimension) = dkc_create_array_dimension((yyvsp[(2) - (3)].expression));
        }
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 636 "diksam.y"
    {
            (yyval.array_dimension) = dkc_create_array_dimension(NULL);
        }
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 640 "diksam.y"
    {
            (yyval.array_dimension) = dkc_chain_array_dimension((yyvsp[(1) - (3)].array_dimension),
                                           dkc_create_array_dimension(NULL));
        }
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 647 "diksam.y"
    {
            (yyval.expression_list) = NULL;
        }
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 651 "diksam.y"
    {
            (yyval.expression_list) = dkc_create_expression_list((yyvsp[(1) - (1)].expression));
        }
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 655 "diksam.y"
    {
            (yyval.expression_list) = dkc_chain_expression_list((yyvsp[(1) - (3)].expression_list), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 661 "diksam.y"
    {
          (yyval.statement) = dkc_create_expression_statement((yyvsp[(1) - (2)].expression));
        }
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 677 "diksam.y"
    {/*empty line*/
			(yyval.statement)=0;
		}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 683 "diksam.y"
    {
            (yyval.statement) = dkc_create_if_statement((yyvsp[(2) - (4)].expression), (yyvsp[(4) - (4)].block), NULL, NULL);
        }
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 687 "diksam.y"
    {
			//printf("IF-ELSE %d\n",dkc_get_current_compiler()->current_line_number);
            (yyval.statement) = dkc_create_if_statement((yyvsp[(2) - (6)].expression), (yyvsp[(4) - (6)].block), NULL, (yyvsp[(6) - (6)].block));
        }
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 692 "diksam.y"
    {
            (yyval.statement) = dkc_create_if_statement((yyvsp[(2) - (5)].expression), (yyvsp[(4) - (5)].block), (yyvsp[(5) - (5)].elsif), NULL);
        }
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 696 "diksam.y"
    {
            (yyval.statement) = dkc_create_if_statement((yyvsp[(2) - (7)].expression), (yyvsp[(4) - (7)].block), (yyvsp[(5) - (7)].elsif), (yyvsp[(7) - (7)].block));
        }
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 703 "diksam.y"
    {
            (yyval.elsif) = dkc_chain_elsif_list((yyvsp[(1) - (2)].elsif), (yyvsp[(2) - (2)].elsif));
        }
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 709 "diksam.y"
    {
            (yyval.elsif) = dkc_create_elsif((yyvsp[(2) - (4)].expression), (yyvsp[(4) - (4)].block));
        }
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 715 "diksam.y"
    {
            (yyval.identifier) = NULL;
        }
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 719 "diksam.y"
    {
            (yyval.identifier) = (yyvsp[(1) - (2)].identifier);
        }
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 725 "diksam.y"
    {
            (yyval.statement) = dkc_create_switch_statement((yyvsp[(2) - (5)].expression), (yyvsp[(4) - (5)].case_list), (yyvsp[(5) - (5)].block));
        }
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 732 "diksam.y"
    {
            (yyval.case_list) = dkc_chain_case((yyvsp[(1) - (2)].case_list), (yyvsp[(2) - (2)].case_list));
        }
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 738 "diksam.y"
    {
            (yyval.case_list) = dkc_create_one_case((yyvsp[(2) - (3)].expression_list), (yyvsp[(3) - (3)].block));
        }
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 744 "diksam.y"
    {
            (yyval.block) = NULL;
        }
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 748 "diksam.y"
    {
            (yyval.block) = (yyvsp[(2) - (2)].block);
        }
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 754 "diksam.y"
    {
            (yyval.expression_list) = dkc_create_expression_list((yyvsp[(1) - (1)].expression));
        }
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 758 "diksam.y"
    {
            (yyval.expression_list) = dkc_chain_expression_list((yyvsp[(1) - (3)].expression_list), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 764 "diksam.y"
    {
            (yyval.statement) = dkc_create_while_statement((yyvsp[(1) - (4)].identifier), (yyvsp[(3) - (4)].expression), (yyvsp[(4) - (4)].block));
        }
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 770 "diksam.y"
    {
            (yyval.statement) = dkc_create_for_statement((yyvsp[(1) - (8)].identifier), (yyvsp[(3) - (8)].expression), (yyvsp[(5) - (8)].expression), (yyvsp[(7) - (8)].expression), (yyvsp[(8) - (8)].block));
        }
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 776 "diksam.y"
    {
            (yyval.statement) = dkc_create_do_while_statement((yyvsp[(1) - (8)].identifier), (yyvsp[(3) - (8)].block), (yyvsp[(6) - (8)].expression));
        }
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 782 "diksam.y"
    {
            (yyval.statement) = dkc_create_foreach_statement((yyvsp[(1) - (8)].identifier), (yyvsp[(4) - (8)].identifier), (yyvsp[(6) - (8)].expression), (yyvsp[(8) - (8)].block));
        }
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 788 "diksam.y"
    {
            (yyval.expression) = NULL;
        }
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 795 "diksam.y"
    {
            (yyval.statement) = dkc_create_return_statement((yyvsp[(2) - (3)].expression));
        }
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 801 "diksam.y"
    {
            (yyval.identifier) = NULL;
        }
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 808 "diksam.y"
    {
            (yyval.statement) = dkc_create_break_statement((yyvsp[(2) - (3)].identifier));
        }
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 814 "diksam.y"
    {
            (yyval.statement) = dkc_create_continue_statement((yyvsp[(2) - (3)].identifier));
        }
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 820 "diksam.y"
    {
            (yyval.statement) = dkc_create_try_statement((yyvsp[(2) - (5)].block), (yyvsp[(3) - (5)].catch_clause), (yyvsp[(5) - (5)].block));
        }
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 824 "diksam.y"
    {
            (yyval.statement) = dkc_create_try_statement((yyvsp[(2) - (4)].block), NULL, (yyvsp[(4) - (4)].block));
        }
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 828 "diksam.y"
    {
            (yyval.statement) = dkc_create_try_statement((yyvsp[(2) - (3)].block), (yyvsp[(3) - (3)].catch_clause), NULL);
        }
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 835 "diksam.y"
    {
            (yyval.catch_clause) = dkc_chain_catch_list((yyvsp[(1) - (2)].catch_clause), (yyvsp[(2) - (2)].catch_clause));
        }
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 841 "diksam.y"
    {
            (yyval.catch_clause) = dkc_start_catch_clause();
        }
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 845 "diksam.y"
    {
            (yyval.catch_clause) = dkc_end_catch_clause((yyvsp[(2) - (5)].catch_clause), (yyvsp[(3) - (5)].type_specifier), (yyvsp[(4) - (5)].identifier), (yyvsp[(5) - (5)].block));
        }
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 851 "diksam.y"
    {
            (yyval.statement) = dkc_create_throw_statement((yyvsp[(2) - (3)].expression));
        }
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 855 "diksam.y"
    {
            (yyval.statement) = dkc_create_throw_statement(NULL);
        }
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 861 "diksam.y"
    {
            (yyval.statement) = dkc_create_declaration_statement(DVM_FALSE, (yyvsp[(4) - (5)].type_specifier), (yyvsp[(2) - (5)].identifier), NULL);
        }
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 865 "diksam.y"
    {
            (yyval.statement) = dkc_create_declaration_statement(DVM_FALSE, (yyvsp[(4) - (7)].type_specifier), (yyvsp[(2) - (7)].identifier), (yyvsp[(6) - (7)].expression));
        }
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 869 "diksam.y"
    {
            (yyval.statement) = dkc_create_declaration_statement(DVM_FALSE, (yyvsp[(4) - (5)].type_specifier), (yyvsp[(2) - (5)].identifier), NULL);
        }
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 873 "diksam.y"
    {
            (yyval.statement) = dkc_create_declaration_statement(DVM_TRUE, (yyvsp[(4) - (7)].type_specifier), (yyvsp[(2) - (7)].identifier), (yyvsp[(6) - (7)].expression));
        }
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 879 "diksam.y"
    {
            (yyval.block) = dkc_open_block(0);
        }
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 883 "diksam.y"
    {
            (yyval.block) = dkc_close_block((yyvsp[(2) - (4)].block), (yyvsp[(3) - (4)].statement_list));
        }
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 887 "diksam.y"
    {
            Block *empty_block = dkc_open_block(0);
            (yyval.block) = dkc_close_block(empty_block, NULL);
        }
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 894 "diksam.y"
    {
            (yyval.template_def) = dkc_create_template_declare_list((yyvsp[(1) - (1)].identifier),NULL);
        }
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 898 "diksam.y"
    {
            (yyval.template_def) = dkc_chain_template_declare_list((yyvsp[(1) - (3)].template_def), (yyvsp[(3) - (3)].identifier),NULL);
        }
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 902 "diksam.y"
    {
            (yyval.template_def) = dkc_create_template_declare_list((yyvsp[(1) - (3)].identifier),(yyvsp[(3) - (3)].type_specifier));
        }
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 906 "diksam.y"
    {
            (yyval.template_def) = dkc_chain_template_declare_list((yyvsp[(1) - (5)].template_def), (yyvsp[(3) - (5)].identifier) ,(yyvsp[(5) - (5)].type_specifier));
        }
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 912 "diksam.y"
    {
			(yyval.template_def)=(yyvsp[(2) - (3)].template_def);
		}
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 916 "diksam.y"
    {(yyval.template_def)=NULL;}
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 921 "diksam.y"
    {
            dkc_start_class_definition(NULL, (yyvsp[(1) - (5)].class_or_interface), (yyvsp[(2) - (5)].identifier),(yyvsp[(3) - (5)].template_def), (yyvsp[(4) - (5)].extends_list));
        }
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 925 "diksam.y"
    {
            dkc_class_define((yyvsp[(7) - (8)].member_declaration));
        }
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 930 "diksam.y"
    {
            dkc_start_class_definition(&(yyvsp[(1) - (6)].class_or_member_modifier), (yyvsp[(2) - (6)].class_or_interface), (yyvsp[(3) - (6)].identifier),(yyvsp[(4) - (6)].template_def), (yyvsp[(5) - (6)].extends_list));
        }
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 933 "diksam.y"
    {
            dkc_class_define((yyvsp[(8) - (9)].member_declaration));
        }
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 937 "diksam.y"
    {
            dkc_start_class_definition(NULL, (yyvsp[(1) - (5)].class_or_interface), (yyvsp[(2) - (5)].identifier),(yyvsp[(3) - (5)].template_def), (yyvsp[(4) - (5)].extends_list));
        }
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 941 "diksam.y"
    {
            dkc_class_define(NULL);
        }
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 946 "diksam.y"
    {
            dkc_start_class_definition(&(yyvsp[(1) - (6)].class_or_member_modifier), (yyvsp[(2) - (6)].class_or_interface), (yyvsp[(3) - (6)].identifier),(yyvsp[(4) - (6)].template_def), (yyvsp[(5) - (6)].extends_list));
        }
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 950 "diksam.y"
    {
            dkc_class_define(NULL);
        }
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 957 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_chain_class_or_member_modifier((yyvsp[(1) - (2)].class_or_member_modifier), (yyvsp[(2) - (2)].class_or_member_modifier));
        }
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 964 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(VIRTUAL_MODIFIER);
        }
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 968 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(OVERRIDE_MODIFIER);
        }
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 972 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(ABSTRACT_MODIFIER);
        }
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 978 "diksam.y"
    {
            (yyval.class_or_interface) = DVM_CLASS_DEFINITION;
        }
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 982 "diksam.y"
    {
            (yyval.class_or_interface) = DVM_INTERFACE_DEFINITION;
        }
    break;

  case 222:

/* Line 1455 of yacc.c  */
#line 988 "diksam.y"
    {
            (yyval.extends_list) = NULL;
        }
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 992 "diksam.y"
    {
            (yyval.extends_list) = (yyvsp[(2) - (2)].extends_list);
        }
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 998 "diksam.y"
    {
            (yyval.extends_list) = dkc_create_extends_list((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 1002 "diksam.y"
    {
            (yyval.extends_list) = dkc_chain_extends_list((yyvsp[(1) - (3)].extends_list), (yyvsp[(3) - (3)].identifier));
        }
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 1009 "diksam.y"
    {
            (yyval.member_declaration) = dkc_chain_member_declaration((yyvsp[(1) - (2)].member_declaration), (yyvsp[(2) - (2)].member_declaration));
        }
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 1019 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_method_member(NULL, (yyvsp[(1) - (1)].function_definition), DVM_FALSE);
        }
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 1023 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_method_member(&(yyvsp[(1) - (2)].class_or_member_modifier), (yyvsp[(2) - (2)].function_definition), DVM_FALSE);
        }
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 1027 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_method_member(NULL, (yyvsp[(1) - (1)].function_definition), DVM_TRUE);
        }
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 1031 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_method_member(&(yyvsp[(1) - (2)].class_or_member_modifier), (yyvsp[(2) - (2)].function_definition), DVM_TRUE);
        }
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 1037 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define((yyvsp[(7) - (9)].type_specifier), (yyvsp[(2) - (9)].identifier), (yyvsp[(4) - (9)].parameter_list), (yyvsp[(8) - (9)].exception_list), (yyvsp[(9) - (9)].block));
        }
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 1041 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define((yyvsp[(6) - (8)].type_specifier), (yyvsp[(2) - (8)].identifier), NULL, (yyvsp[(7) - (8)].exception_list), (yyvsp[(8) - (8)].block));
        }
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 1045 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define((yyvsp[(8) - (10)].type_specifier), (yyvsp[(3) - (10)].identifier), (yyvsp[(5) - (10)].parameter_list), (yyvsp[(9) - (10)].exception_list), NULL);
        }
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 1049 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define((yyvsp[(7) - (9)].type_specifier), (yyvsp[(3) - (9)].identifier), NULL, (yyvsp[(8) - (9)].exception_list), NULL);
        }
    break;

  case 238:

/* Line 1455 of yacc.c  */
#line 1053 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define(0, (yyvsp[(2) - (7)].identifier), (yyvsp[(4) - (7)].parameter_list), (yyvsp[(6) - (7)].exception_list), (yyvsp[(7) - (7)].block));
        }
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 1057 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define(0, (yyvsp[(2) - (6)].identifier), NULL, (yyvsp[(5) - (6)].exception_list), (yyvsp[(6) - (6)].block));
        }
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 1061 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define(0, (yyvsp[(3) - (8)].identifier), (yyvsp[(5) - (8)].parameter_list), (yyvsp[(7) - (8)].exception_list), NULL);
        }
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 1065 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define(0, (yyvsp[(3) - (7)].identifier), NULL, (yyvsp[(6) - (7)].exception_list), NULL);
        }
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 1071 "diksam.y"
    {
			(yyval.apost)=0;
		}
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 1075 "diksam.y"
    {
			(yyval.apost)=1;
		}
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 1081 "diksam.y"
    {
            (yyval.exception_list) = NULL;
        }
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 1085 "diksam.y"
    {
            (yyval.exception_list) = (yyvsp[(2) - (2)].exception_list);
        }
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 1091 "diksam.y"
    {
            (yyval.exception_list) = dkc_create_throws((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 1095 "diksam.y"
    {
            (yyval.exception_list) = dkc_chain_exception_list((yyvsp[(1) - (3)].exception_list), (yyvsp[(3) - (3)].identifier));
        }
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 1101 "diksam.y"
    {
            (yyval.function_definition) = dkc_constructor_function_define((yyvsp[(2) - (7)].identifier), (yyvsp[(4) - (7)].parameter_list), (yyvsp[(6) - (7)].exception_list), (yyvsp[(7) - (7)].block));
        }
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 1105 "diksam.y"
    {
            (yyval.function_definition) = dkc_constructor_function_define((yyvsp[(2) - (6)].identifier), NULL, (yyvsp[(5) - (6)].exception_list), (yyvsp[(6) - (6)].block));
        }
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 1109 "diksam.y"
    {
            (yyval.function_definition) = dkc_constructor_function_define((yyvsp[(3) - (8)].identifier), (yyvsp[(5) - (8)].parameter_list), (yyvsp[(7) - (8)].exception_list), NULL);
        }
    break;

  case 251:

/* Line 1455 of yacc.c  */
#line 1113 "diksam.y"
    {
            (yyval.function_definition) = dkc_constructor_function_define((yyvsp[(3) - (7)].identifier), NULL, (yyvsp[(6) - (7)].exception_list), NULL);
        }
    break;

  case 252:

/* Line 1455 of yacc.c  */
#line 1119 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(PUBLIC_MODIFIER);
        }
    break;

  case 253:

/* Line 1455 of yacc.c  */
#line 1123 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(PRIVATE_MODIFIER);
        }
    break;

  case 254:

/* Line 1455 of yacc.c  */
#line 1129 "diksam.y"
    {
            (yyval.expression) = NULL;
        }
    break;

  case 255:

/* Line 1455 of yacc.c  */
#line 1133 "diksam.y"
    {
            (yyval.expression) = (yyvsp[(2) - (2)].expression);
        }
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 1139 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(NULL, DVM_FALSE, (yyvsp[(4) - (6)].type_specifier), (yyvsp[(2) - (6)].identifier), (yyvsp[(5) - (6)].expression));
        }
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 1144 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(&(yyvsp[(1) - (6)].class_or_member_modifier), DVM_FALSE, (yyvsp[(4) - (6)].type_specifier), (yyvsp[(2) - (6)].identifier), (yyvsp[(5) - (6)].expression));
        }
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 1148 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(NULL, DVM_TRUE, (yyvsp[(4) - (6)].type_specifier), (yyvsp[(2) - (6)].identifier), (yyvsp[(5) - (6)].expression));
        }
    break;

  case 259:

/* Line 1455 of yacc.c  */
#line 1153 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(&(yyvsp[(1) - (7)].class_or_member_modifier), DVM_TRUE, (yyvsp[(5) - (7)].type_specifier), (yyvsp[(3) - (7)].identifier), (yyvsp[(6) - (7)].expression));
        }
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 1157 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(&(yyvsp[(2) - (7)].class_or_member_modifier), DVM_TRUE, (yyvsp[(5) - (7)].type_specifier), (yyvsp[(3) - (7)].identifier), (yyvsp[(6) - (7)].expression));
        }
    break;

  case 261:

/* Line 1455 of yacc.c  */
#line 1163 "diksam.y"
    {
            dkc_create_delegate_definition((yyvsp[(8) - (10)].type_specifier), (yyvsp[(2) - (10)].identifier), (yyvsp[(4) - (10)].parameter_list), (yyvsp[(9) - (10)].exception_list),(yyvsp[(5) - (10)].apost));
        }
    break;

  case 262:

/* Line 1455 of yacc.c  */
#line 1167 "diksam.y"
    {
            dkc_create_delegate_definition((yyvsp[(7) - (9)].type_specifier), (yyvsp[(2) - (9)].identifier), NULL, (yyvsp[(8) - (9)].exception_list),(yyvsp[(4) - (9)].apost));
        }
    break;

  case 263:

/* Line 1455 of yacc.c  */
#line 1173 "diksam.y"
    {
            dkc_create_enum_definition((yyvsp[(2) - (5)].identifier), (yyvsp[(4) - (5)].enumerator));
        }
    break;

  case 264:

/* Line 1455 of yacc.c  */
#line 1177 "diksam.y"
    {
            dkc_create_enum_definition((yyvsp[(2) - (6)].identifier), (yyvsp[(4) - (6)].enumerator));
        }
    break;

  case 265:

/* Line 1455 of yacc.c  */
#line 1183 "diksam.y"
    {
            (yyval.enumerator) = dkc_create_enumerator((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 266:

/* Line 1455 of yacc.c  */
#line 1187 "diksam.y"
    {
            (yyval.enumerator) = dkc_chain_enumerator((yyvsp[(1) - (3)].enumerator), (yyvsp[(3) - (3)].identifier));
        }
    break;

  case 267:

/* Line 1455 of yacc.c  */
#line 1193 "diksam.y"
    {
            dkc_create_const_definition(NULL, (yyvsp[(2) - (5)].identifier), (yyvsp[(4) - (5)].expression));
        }
    break;

  case 268:

/* Line 1455 of yacc.c  */
#line 1197 "diksam.y"
    {
            dkc_create_const_definition((yyvsp[(2) - (4)].type_specifier), (yyvsp[(3) - (4)].identifier), NULL);
        }
    break;

  case 269:

/* Line 1455 of yacc.c  */
#line 1203 "diksam.y"
    {
			(yyval.apost)=0;
		}
    break;

  case 270:

/* Line 1455 of yacc.c  */
#line 1207 "diksam.y"
    {
			(yyval.apost)=1;
		}
    break;

  case 271:

/* Line 1455 of yacc.c  */
#line 1211 "diksam.y"
    {
			(yyval.apost)=-1;
		}
    break;

  case 272:

/* Line 1455 of yacc.c  */
#line 1217 "diksam.y"
    {
            (yyval.block) = dkc_open_block((yyvsp[(2) - (2)].apost));
			//printf("E1 %d\n",dkc_get_current_compiler());
        }
    break;

  case 273:

/* Line 1455 of yacc.c  */
#line 1222 "diksam.y"
    {
            (yyval.block) = dkc_close_block((yyvsp[(3) - (5)].block), (yyvsp[(4) - (5)].statement_list));
			//printf("C1 %d\n",dkc_get_current_compiler()->current_line_number);
        }
    break;

  case 274:

/* Line 1455 of yacc.c  */
#line 1227 "diksam.y"
    {
            Block *empty_block = dkc_open_block(0);
            (yyval.block) = dkc_close_block(empty_block, NULL);
			//printf("C2 %d\n",dkc_get_current_compiler()->current_line_number);
        }
    break;



/* Line 1455 of yacc.c  */
#line 4196 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 1233 "diksam.y"


