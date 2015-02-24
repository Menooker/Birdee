
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



/* Line 214 of yacc.c  */
#line 355 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 367 "y.tab.c"

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
#define YYLAST   1005

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  105
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  95
/* YYNRULES -- Number of rules.  */
#define YYNRULES  264
/* YYNRULES -- Number of states.  */
#define YYNSTATES  574

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
      70,    72,    74,    78,    82,    86,    88,    90,    92,    93,
     100,   101,   104,   107,   119,   130,   140,   149,   160,   170,
     179,   187,   189,   193,   199,   201,   205,   207,   210,   212,
     216,   218,   222,   224,   226,   228,   230,   232,   234,   236,
     240,   242,   246,   248,   252,   256,   258,   262,   266,   270,
     274,   276,   280,   284,   286,   290,   294,   298,   302,   306,
     310,   312,   315,   318,   321,   323,   326,   329,   333,   335,
     337,   339,   341,   346,   351,   355,   360,   364,   368,   373,
     375,   377,   379,   381,   383,   385,   387,   389,   391,   393,
     398,   403,   409,   416,   424,   428,   433,   437,   442,   446,
     451,   453,   456,   460,   463,   467,   468,   470,   474,   477,
     479,   481,   483,   485,   487,   489,   491,   493,   495,   497,
     499,   501,   503,   508,   515,   521,   529,   531,   534,   539,
     540,   543,   549,   551,   554,   558,   559,   562,   564,   568,
     573,   582,   591,   600,   601,   603,   607,   608,   610,   614,
     618,   624,   629,   633,   635,   638,   639,   645,   649,   652,
     658,   666,   672,   680,   681,   686,   689,   690,   698,   699,
     708,   709,   716,   717,   725,   727,   730,   732,   734,   736,
     738,   740,   742,   743,   746,   748,   752,   754,   757,   759,
     761,   763,   766,   768,   771,   781,   790,   801,   811,   819,
     826,   835,   843,   844,   847,   848,   851,   853,   857,   865,
     872,   881,   889,   891,   893,   894,   897,   904,   911,   918,
     926,   934,   945,   955,   961,   968,   970,   974,   980,   985,
     986,   989,   992,   993,   999
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     106,     0,    -1,   107,    -1,   106,   113,    -1,    -1,   108,
     111,    -1,   108,    -1,   111,    -1,   107,   118,    -1,   109,
      -1,   108,   109,    -1,    74,   110,    98,    -1,     7,    -1,
     110,    53,     7,    -1,   112,    -1,   111,   112,    -1,    75,
     110,     7,    98,    -1,   122,    -1,   172,    -1,   145,    -1,
     193,    -1,   194,    -1,   196,    -1,    66,    -1,    67,    -1,
      68,    -1,    69,    -1,    70,    -1,    71,    -1,    72,    -1,
      89,    -1,     7,    -1,   114,    27,    28,    -1,     7,    27,
      28,    -1,   116,    27,    28,    -1,   114,    -1,   116,    -1,
     115,    -1,    -1,   102,     7,   119,    98,   120,    97,    -1,
      -1,   120,   121,    -1,   120,   172,    -1,    99,    93,     7,
      23,   123,   186,    24,    94,   117,   187,    98,    -1,    99,
      93,     7,    23,   186,    24,    94,   117,   187,    98,    -1,
      99,   100,     7,    23,   123,   186,    24,   187,    98,    -1,
      99,   100,     7,    23,   186,    24,   187,    98,    -1,    93,
       7,    23,   123,   186,    24,    94,   117,   187,   198,    -1,
      93,     7,    23,   186,    24,    94,   117,   187,   198,    -1,
     100,     7,    23,   123,   186,    24,   187,   198,    -1,   100,
       7,    23,   186,    24,   187,   198,    -1,   121,    -1,     7,
      94,   117,    -1,   123,    31,     7,    94,   117,    -1,   127,
      -1,   124,    31,   127,    -1,   145,    -1,   125,   145,    -1,
     127,    -1,   126,    31,   127,    -1,   129,    -1,   137,   128,
     127,    -1,    32,    -1,    54,    -1,    55,    -1,    56,    -1,
      57,    -1,    58,    -1,   130,    -1,   129,    34,   130,    -1,
     131,    -1,   130,    33,   131,    -1,   132,    -1,   131,    35,
     132,    -1,   131,    36,   132,    -1,   133,    -1,   132,    37,
     133,    -1,   132,    38,   133,    -1,   132,    39,   133,    -1,
     132,    40,   133,    -1,   134,    -1,   133,    41,   134,    -1,
     133,    42,   134,    -1,   135,    -1,   134,    43,   135,    -1,
     134,    44,   135,    -1,   134,    45,   135,    -1,   134,    46,
     135,    -1,   134,    47,   135,    -1,   134,    48,   135,    -1,
     136,    -1,    42,   135,    -1,    52,   135,    -1,    49,   135,
      -1,   137,    -1,   137,    59,    -1,   137,    60,    -1,   137,
      86,   117,    -1,   138,    -1,   140,    -1,     7,    -1,     8,
      -1,   138,    27,   126,    28,    -1,     7,    27,   126,    28,
      -1,   137,    53,     7,    -1,   137,    23,   124,    24,    -1,
     137,    23,    24,    -1,    23,   126,    24,    -1,   137,    87,
     117,    88,    -1,     3,    -1,     4,    -1,     5,    -1,     6,
      -1,    50,    -1,    51,    -1,    22,    -1,   139,    -1,    83,
      -1,    84,    -1,    73,    89,    23,    24,    -1,    73,     7,
      23,    24,    -1,    73,     7,    23,   124,    24,    -1,    73,
       7,    53,     7,    23,    24,    -1,    73,     7,    53,     7,
      23,   124,    24,    -1,    25,   144,    26,    -1,    25,   144,
      31,    26,    -1,    73,   114,   141,    -1,    73,   114,   141,
     143,    -1,    73,   115,   141,    -1,    73,   115,   141,   143,
      -1,   142,    -1,   141,   142,    -1,    27,   126,    28,    -1,
      27,    28,    -1,   143,    27,    28,    -1,    -1,   127,    -1,
     144,    31,   127,    -1,   126,    98,    -1,   146,    -1,   150,
      -1,   155,    -1,   156,    -1,   157,    -1,   158,    -1,   160,
      -1,   162,    -1,   163,    -1,   164,    -1,   168,    -1,   169,
      -1,    98,    -1,     9,   126,    95,   198,    -1,     9,   126,
      95,   198,    10,   198,    -1,     9,   126,    95,   198,   147,
      -1,     9,   126,    95,   198,   147,    10,   198,    -1,   148,
      -1,   147,   148,    -1,    11,   126,    95,   198,    -1,    -1,
       7,    30,    -1,    12,   126,    98,   151,   153,    -1,   152,
      -1,   151,   152,    -1,    13,   154,   198,    -1,    -1,    14,
     198,    -1,   127,    -1,   144,    31,   127,    -1,   149,    15,
     126,   198,    -1,   149,    17,   159,    29,   159,    29,   159,
     198,    -1,   149,    16,   170,    15,    23,   126,    24,    98,
      -1,   149,    18,    23,     7,    30,   126,    24,   170,    -1,
      -1,   126,    -1,    19,   159,    98,    -1,    -1,     7,    -1,
      20,   161,    98,    -1,    21,   161,    98,    -1,    61,   198,
     165,    63,   198,    -1,    61,   198,    63,   170,    -1,    61,
     198,   165,    -1,   166,    -1,   165,   166,    -1,    -1,    62,
     167,   117,     7,   198,    -1,    64,   126,    98,    -1,    64,
      98,    -1,    96,     7,    94,   117,    98,    -1,    96,     7,
      94,   117,    32,   126,    98,    -1,    90,     7,    94,   117,
      98,    -1,    90,     7,    94,   117,    32,   126,    98,    -1,
      -1,    25,   171,   125,    26,    -1,    25,    26,    -1,    -1,
     179,     7,   180,    98,   173,   182,    97,    -1,    -1,   177,
     179,     7,   180,    98,   174,   182,    97,    -1,    -1,   179,
       7,   180,    98,   175,    97,    -1,    -1,   177,   179,     7,
     180,    98,   176,    97,    -1,   178,    -1,   177,   178,    -1,
     190,    -1,    80,    -1,    81,    -1,    82,    -1,    76,    -1,
      77,    -1,    -1,    30,   181,    -1,     7,    -1,   181,    31,
       7,    -1,   183,    -1,   182,   183,    -1,   184,    -1,   192,
      -1,   185,    -1,   177,   185,    -1,   189,    -1,   177,   189,
      -1,    93,     7,    23,   123,    24,    94,   117,   187,   198,
      -1,    93,     7,    23,    24,    94,   117,   187,   198,    -1,
      99,    93,     7,    23,   123,    24,    94,   117,   187,    98,
      -1,    99,    93,     7,    23,    24,    94,   117,   187,    98,
      -1,   100,     7,    23,   123,    24,   187,   198,    -1,   100,
       7,    23,    24,   187,   198,    -1,    99,   100,     7,    23,
     123,    24,   187,    98,    -1,    99,   100,     7,    23,    24,
     187,    98,    -1,    -1,    31,   101,    -1,    -1,    65,   188,
      -1,     7,    -1,   188,    31,     7,    -1,    85,     7,    23,
     123,    24,   187,   198,    -1,    85,     7,    23,    24,   187,
     198,    -1,    99,    85,     7,    23,   123,    24,   187,    98,
      -1,    99,    85,     7,    23,    24,   187,    98,    -1,    78,
      -1,    79,    -1,    -1,    32,   126,    -1,    96,     7,    94,
     117,   191,    98,    -1,   177,     7,    94,   117,   191,    98,
      -1,    90,     7,    94,   117,   191,    98,    -1,   177,    90,
       7,    94,   117,   191,    98,    -1,    90,   177,     7,    94,
     117,   191,    98,    -1,    89,     7,    23,   123,   186,    24,
      94,   117,   187,    98,    -1,    89,     7,    23,   186,    24,
      94,   117,   187,    98,    -1,    91,     7,    25,   195,    26,
      -1,    91,     7,    25,   195,    31,    26,    -1,     7,    -1,
     195,    31,     7,    -1,    92,     7,    32,   126,    98,    -1,
      92,   117,     7,    98,    -1,    -1,   103,    98,    -1,   104,
      98,    -1,    -1,    98,   197,   199,   125,    97,    -1,    98,
      97,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    97,    97,    98,   102,   105,   109,   113,   117,   123,
     124,   130,   136,   140,   146,   147,   153,   159,   160,   161,
     168,   169,   170,   173,   177,   181,   185,   189,   193,   197,
     201,   207,   213,   219,   225,   231,   235,   236,   241,   240,
     255,   258,   259,   262,   266,   270,   274,   281,   285,   289,
     293,   297,   300,   304,   310,   314,   320,   324,   330,   331,
     337,   338,   344,   348,   352,   356,   360,   364,   370,   371,
     377,   378,   384,   385,   389,   395,   396,   400,   404,   408,
     414,   415,   419,   425,   426,   430,   434,   438,   442,   446,
     452,   453,   457,   461,   467,   468,   472,   476,   482,   483,
     484,   488,   494,   498,   503,   507,   511,   515,   519,   523,
     524,   525,   526,   527,   531,   535,   539,   540,   544,   548,
     552,   556,   560,   564,   570,   574,   580,   584,   588,   592,
     599,   600,   606,   612,   616,   624,   627,   631,   637,   641,
     642,   643,   644,   645,   646,   647,   648,   649,   650,   651,
     652,   653,   659,   663,   668,   672,   678,   679,   685,   692,
     695,   701,   707,   708,   714,   721,   724,   730,   734,   740,
     746,   752,   758,   765,   768,   771,   778,   781,   784,   790,
     796,   800,   804,   810,   811,   818,   817,   827,   831,   837,
     841,   845,   849,   856,   855,   863,   872,   870,   881,   879,
     888,   887,   897,   895,   906,   907,   913,   914,   918,   922,
     928,   932,   939,   942,   948,   952,   958,   959,   965,   966,
     969,   973,   977,   981,   987,   991,   995,   999,  1003,  1007,
    1011,  1015,  1022,  1025,  1032,  1035,  1041,  1045,  1051,  1055,
    1059,  1063,  1069,  1073,  1080,  1083,  1089,  1093,  1098,  1102,
    1107,  1113,  1117,  1123,  1127,  1133,  1137,  1143,  1147,  1154,
    1157,  1161,  1168,  1167,  1177
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
  "identifier_type_specifier", "array_type_specifier", "type_specifier",
  "lib_function", "$@1", "lib_function_declaration_list",
  "function_declaration", "function_definition", "parameter_list",
  "argument_list", "statement_list", "expression", "assignment_expression",
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
  "block", "@3", "class_definition", "$@4", "$@5", "$@6", "$@7",
  "class_or_member_modifier_list", "class_or_member_modifier",
  "class_or_interface", "extends", "extends_list",
  "member_declaration_list", "member_declaration", "method_member",
  "method_function_definition", "apostrophe", "throws_clause",
  "exception_list", "constructor_definition", "access_modifier",
  "initializer_opt", "field_member", "delegate_definition",
  "enum_definition", "enumerator_list", "const_definition", "unsafe",
  "myblock", "@8", 0
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
     114,   115,   116,   116,   116,   117,   117,   117,   119,   118,
     120,   120,   120,   121,   121,   121,   121,   122,   122,   122,
     122,   122,   123,   123,   124,   124,   125,   125,   126,   126,
     127,   127,   128,   128,   128,   128,   128,   128,   129,   129,
     130,   130,   131,   131,   131,   132,   132,   132,   132,   132,
     133,   133,   133,   134,   134,   134,   134,   134,   134,   134,
     135,   135,   135,   135,   136,   136,   136,   136,   137,   137,
     137,   137,   138,   138,   138,   138,   138,   138,   138,   138,
     138,   138,   138,   138,   138,   138,   138,   138,   138,   138,
     138,   138,   138,   138,   139,   139,   140,   140,   140,   140,
     141,   141,   142,   143,   143,   144,   144,   144,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     145,   145,   146,   146,   146,   146,   147,   147,   148,   149,
     149,   150,   151,   151,   152,   153,   153,   154,   154,   155,
     156,   157,   158,   159,   159,   160,   161,   161,   162,   163,
     164,   164,   164,   165,   165,   167,   166,   168,   168,   169,
     169,   169,   169,   171,   170,   170,   173,   172,   174,   172,
     175,   172,   176,   172,   177,   177,   178,   178,   178,   178,
     179,   179,   180,   180,   181,   181,   182,   182,   183,   183,
     184,   184,   184,   184,   185,   185,   185,   185,   185,   185,
     185,   185,   186,   186,   187,   187,   188,   188,   189,   189,
     189,   189,   190,   190,   191,   191,   192,   192,   192,   192,
     192,   193,   193,   194,   194,   195,   195,   196,   196,   197,
     197,   197,   199,   198,   198
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     2,     1,
       2,     3,     1,     3,     1,     2,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     1,     1,     1,     0,     6,
       0,     2,     2,    11,    10,     9,     8,    10,     9,     8,
       7,     1,     3,     5,     1,     3,     1,     2,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     3,     3,
       1,     2,     2,     2,     1,     2,     2,     3,     1,     1,
       1,     1,     4,     4,     3,     4,     3,     3,     4,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     5,     6,     7,     3,     4,     3,     4,     3,     4,
       1,     2,     3,     2,     3,     0,     1,     3,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     6,     5,     7,     1,     2,     4,     0,
       2,     5,     1,     2,     3,     0,     2,     1,     3,     4,
       8,     8,     8,     0,     1,     3,     0,     1,     3,     3,
       5,     4,     3,     1,     2,     0,     5,     3,     2,     5,
       7,     5,     7,     0,     4,     2,     0,     7,     0,     8,
       0,     6,     0,     7,     1,     2,     1,     1,     1,     1,
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
       4,     0,     0,   159,     2,     6,     9,     7,    14,    12,
       0,     0,     1,   109,   110,   111,   112,   100,   101,     0,
       0,   173,   176,   176,   115,     0,   135,     0,     0,   113,
     114,     0,     0,     0,     0,   210,   211,   242,   243,   207,
     208,   209,   117,   118,     0,     0,     0,     0,     0,     0,
     151,     0,     0,     3,    51,    17,     0,    58,    60,    68,
      70,    72,    75,    80,    83,    90,    94,    98,   116,    99,
      19,   139,     0,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,    18,     0,   204,     0,   206,    20,
      21,    22,     0,     8,    10,     5,    15,     0,    11,     0,
       0,   160,   100,     0,     0,   174,     0,   177,     0,     0,
       0,   136,     0,    91,    94,    93,    92,   259,     0,   188,
       0,    31,    23,    24,    25,    26,    27,    28,    29,    30,
       0,     0,     0,     0,     0,    31,    30,    35,    37,    36,
       0,     0,     0,     0,     0,     0,     0,   138,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    62,     0,    63,    64,    65,
      66,    67,    95,    96,     0,     0,     0,     0,     0,     0,
     173,     0,   205,     0,   212,    38,    13,    16,     0,     0,
       0,   175,   178,   179,   107,   124,     0,   264,     0,     0,
     262,   185,     0,   182,   183,   187,     0,     0,     0,     0,
     126,   130,   128,   232,     0,     0,     0,     0,     0,     0,
       0,   232,     0,     0,     0,   232,    59,    69,    71,    73,
      74,    76,    77,    78,    79,    81,    82,    84,    85,    86,
      87,    88,    89,   106,     0,    54,   104,    31,    97,     0,
      61,     0,     0,   193,     0,     0,     0,   212,     0,     0,
       0,   103,   152,   135,   165,   162,   125,   137,   260,   261,
     159,     0,   181,     0,   184,   120,     0,     0,   119,     0,
       0,   131,   127,   129,     0,     0,   232,     0,     0,   255,
       0,    33,     0,    32,    34,   258,   232,     0,     0,   232,
     232,   232,     0,   105,     0,   108,   102,   169,   195,   159,
       0,   173,     0,     0,   214,   213,   196,    40,     0,     0,
     154,   156,   136,     0,     0,     0,   163,   161,   159,    56,
       0,   180,   121,     0,   132,   133,     0,     0,   233,     0,
       0,     0,     0,   191,   253,     0,   257,     0,     0,     0,
     189,   232,     0,   232,     0,     0,   234,    55,   159,     0,
       0,     0,   198,     0,     0,     0,     0,   153,     0,     0,
     157,     0,   164,   166,   263,    57,     0,   122,     0,   134,
      52,     0,     0,     0,     0,   256,   254,     0,     0,     0,
       0,     0,     0,   234,   234,     0,     0,   194,     0,   173,
       0,     0,     0,   215,     0,     0,     0,     0,     0,     0,
       0,     0,   216,   218,   220,   222,   219,   201,    39,    41,
      42,     0,   155,   137,   186,   123,     0,     0,   234,   192,
       0,   234,   190,     0,     0,   234,     0,     0,   236,   235,
      50,     0,     0,     0,     0,   203,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   221,   223,   197,
     217,   158,    53,   234,     0,   234,     0,     0,   234,     0,
      46,    49,     0,   171,   170,   172,   199,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   252,
       0,    48,   234,     0,    45,   237,   234,     0,   244,     0,
       0,     0,   244,     0,     0,     0,   234,     0,   244,     0,
     251,    47,     0,    44,     0,   234,     0,     0,     0,   244,
       0,     0,     0,   234,     0,     0,     0,   234,     0,     0,
     234,     0,   244,    43,   239,     0,   245,   248,     0,   234,
       0,   246,     0,   234,     0,     0,     0,   234,   229,     0,
     247,     0,   238,   250,     0,   234,   241,     0,   234,     0,
     231,     0,   228,   249,   225,     0,   240,     0,   234,   230,
     224,   227,     0,   226
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,     6,    10,     7,     8,    53,   137,
     138,   139,   140,    93,   260,   366,    54,    55,   286,   244,
     328,    56,    57,   176,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,   210,   211,   282,   112,
     329,    71,   320,   321,    72,    73,   264,   265,   327,   324,
      74,    75,    76,    77,   106,    78,   108,    79,    80,    81,
     203,   204,   271,    82,    83,   254,   309,    84,   364,   401,
     365,   402,   410,    86,    87,   259,   315,   411,   412,   413,
     414,   287,   396,   439,   415,    88,   518,   416,    89,    90,
     290,    91,   200,   118,   270
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -475
static const yytype_int16 yypact[] =
{
     113,    34,    34,   423,   -52,   113,  -475,    41,  -475,  -475,
     -35,    19,  -475,  -475,  -475,  -475,  -475,     8,  -475,   921,
     921,   921,   127,   127,  -475,   921,   921,   921,   921,  -475,
    -475,   921,    46,   765,    71,  -475,  -475,  -475,  -475,  -475,
    -475,  -475,  -475,  -475,   146,   169,   193,   173,   207,   223,
    -475,   -29,   231,  -475,  -475,  -475,   -12,  -475,   214,   235,
     201,   297,   174,   347,  -475,  -475,   402,   236,  -475,  -475,
    -475,  -475,   360,  -475,  -475,  -475,  -475,  -475,  -475,  -475,
    -475,  -475,  -475,  -475,  -475,   275,  -475,   266,  -475,  -475,
    -475,  -475,   283,  -475,  -475,    41,  -475,   289,  -475,   211,
     921,  -475,   287,    -8,    11,   286,   228,  -475,   229,   233,
      49,  -475,    88,  -475,   172,  -475,  -475,   -67,   192,  -475,
      17,     6,  -475,  -475,  -475,  -475,  -475,  -475,  -475,   296,
     301,   301,   315,   247,   318,   197,  -475,   317,  -475,   320,
     338,   325,   265,   342,   353,   340,   921,  -475,   921,   921,
     921,   921,   921,   921,   921,   921,   921,   921,   921,   921,
     921,   921,   921,   921,   777,  -475,   357,  -475,  -475,  -475,
    -475,  -475,  -475,  -475,   210,   210,   921,   921,   921,   343,
     921,   346,  -475,   358,   349,  -475,  -475,  -475,   124,    46,
     359,  -475,  -475,  -475,  -475,  -475,   817,  -475,   290,   298,
    -475,  -475,   343,   209,  -475,  -475,   829,   366,   363,   921,
     371,  -475,   371,    24,   210,   392,   372,   921,   373,   374,
     305,    24,   210,   381,   399,    24,  -475,   235,   201,   297,
     297,   174,   174,   174,   174,   347,   347,  -475,  -475,  -475,
    -475,  -475,  -475,  -475,    51,  -475,  -475,   397,  -475,   345,
    -475,   137,    22,   410,   422,   409,   432,   349,   433,   351,
     352,  -475,   255,   921,   270,  -475,  -475,  -475,  -475,  -475,
     713,   210,  -475,    46,  -475,  -475,   160,   418,  -475,   218,
     869,  -475,   420,   420,   369,   350,   421,   429,   -15,  -475,
     221,  -475,    23,  -475,  -475,  -475,   421,   430,    30,    24,
      24,   421,   440,  -475,   921,  -475,  -475,  -475,  -475,   713,
     443,   921,   437,   370,  -475,   438,   379,  -475,    46,   921,
     277,  -475,   380,   439,    46,    46,  -475,  -475,   521,  -475,
     464,  -475,  -475,   881,  -475,  -475,   449,   210,  -475,     5,
     455,   386,   921,  -475,  -475,    39,  -475,   457,   388,   921,
    -475,   421,   459,   421,   461,   462,   425,  -475,   617,   921,
     463,   921,   394,   486,   225,   398,   477,  -475,    -7,    46,
    -475,   921,  -475,  -475,  -475,  -475,    46,  -475,   161,  -475,
    -475,   400,   403,   210,    25,  -475,  -475,   414,   210,    26,
     485,   416,   487,   425,   425,   510,    46,  -475,   165,   921,
     175,   225,   434,  -475,   511,    13,   513,   525,   -24,   527,
      18,   499,  -475,  -475,  -475,  -475,  -475,  -475,  -475,  -475,
    -475,    46,  -475,   441,  -475,  -475,   210,   210,   425,  -475,
     210,   425,  -475,   442,   210,   425,   447,    46,  -475,   504,
    -475,   450,    46,   343,   592,  -475,   514,   444,   141,   524,
     456,   542,   544,   545,   537,   467,   555,  -475,  -475,  -475,
    -475,  -475,  -475,   425,   466,   425,    46,   210,   425,   468,
    -475,  -475,   558,  -475,  -475,  -475,  -475,    42,   210,   473,
      61,   210,   546,   552,   560,   106,   210,   474,   488,  -475,
      46,  -475,   425,   489,  -475,  -475,   425,   178,   556,   210,
     496,   179,   556,   122,   125,   157,   425,   180,   556,   210,
    -475,  -475,   493,  -475,    46,   425,   586,   921,   502,   556,
     210,   503,   505,   425,   181,   507,   202,   425,   203,    46,
     425,   508,   556,  -475,  -475,    46,   286,  -475,   509,   425,
     210,  -475,   512,   425,   210,   515,   516,   425,  -475,    46,
    -475,   517,  -475,  -475,    46,   425,  -475,   518,   425,   210,
    -475,   529,  -475,  -475,  -475,    46,  -475,   530,   425,  -475,
    -475,  -475,   532,  -475
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -475,  -475,  -475,  -475,   597,   606,   607,    15,  -475,   579,
     598,  -475,  -170,  -475,  -475,  -475,   267,  -475,  -210,  -197,
     322,   -19,   -13,  -475,  -475,   497,   492,   151,   230,   156,
      12,  -475,   258,  -475,  -475,  -475,   519,  -133,   435,   383,
       4,  -475,  -475,   314,  -475,  -475,  -475,   384,  -475,  -475,
    -475,  -475,  -475,  -475,  -164,  -475,   612,  -475,  -475,  -475,
    -475,   446,  -475,  -475,  -475,  -192,  -475,   278,  -475,  -475,
    -475,  -475,     0,   -77,   566,   395,  -475,   252,  -384,  -475,
     244,  -174,  -361,  -475,   245,  -475,  -474,  -475,  -475,  -475,
    -475,  -475,  -475,  -168,  -475
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -203
static const yytype_int16 yytable[] =
{
     103,   104,   105,    85,   248,   249,   110,    70,   182,   276,
     272,   296,   381,   111,   120,   301,   255,   342,    97,   146,
     447,   262,    96,   146,   146,   455,    99,   460,   522,   206,
     197,   284,   436,   437,   531,   100,   198,   199,   101,   113,
     115,     9,   146,   116,   288,   538,   385,   297,   146,   284,
      92,   302,   298,   146,   146,   285,   146,   146,   551,   207,
     460,   451,   349,    98,   143,   386,   496,   464,   284,   452,
     466,   144,    97,   194,   469,   303,   453,   281,   121,   281,
     146,   188,   304,   343,   307,   500,   147,   189,   421,   351,
     353,    37,    38,    39,    40,    41,    37,    38,    39,    40,
      41,   330,   488,   404,   490,   331,   338,   493,   456,   190,
      96,   406,   340,   284,   195,   205,     2,   408,   409,   196,
     117,   346,   347,   429,   432,   352,   354,   355,   350,   284,
     506,   512,   284,   226,   107,   514,   378,   122,   123,   124,
     125,   126,   127,   128,   117,   529,   523,   360,   479,   525,
     367,   245,   261,   132,   535,   146,   372,   373,   251,   252,
     129,   105,   542,   250,   284,   306,   546,   380,   146,   549,
     237,   238,   239,   240,   241,   242,   133,   390,   554,   392,
     135,   527,   557,   267,   332,   425,   561,     1,     2,   441,
     279,   304,   304,   245,   565,   164,   146,   567,   292,   443,
     134,   422,   515,   521,   530,   543,   146,   572,   424,   516,
     516,   516,   516,   428,   141,   156,   157,   247,   431,    37,
      38,    39,    40,    41,   216,   166,   545,   547,   440,   217,
     142,   172,   173,   516,   516,   442,   150,   151,   145,   122,
     123,   124,   125,   126,   127,   128,   334,   344,   148,   146,
     322,   475,   345,   461,   201,   202,   462,   463,   174,   175,
     465,   279,   136,   177,   468,   318,   319,   497,   149,   471,
     501,   201,   273,   184,   474,   507,   122,   123,   124,   125,
     126,   127,   128,   263,   325,   114,   114,   369,   319,   114,
     185,   357,   105,   524,   526,   528,   186,   492,   491,   136,
     368,   229,   230,    37,    38,    39,    40,    41,   498,   187,
     404,   502,   235,   236,   100,   405,   508,   146,   406,   208,
     245,   407,   511,   384,   408,   409,   191,   192,   209,   519,
     389,   193,   375,   182,   152,   153,   154,   155,   213,   532,
     398,   214,   400,   215,   218,   220,   534,   219,   221,   223,
     539,    35,    36,    37,    38,    39,    40,    41,   423,   222,
     224,   548,   375,   225,   246,   257,    85,   552,   253,   256,
     555,   182,   263,   277,   558,   178,   179,   180,   181,   258,
     105,   562,   231,   232,   233,   234,   564,   278,   268,   568,
     158,   159,   160,   161,   162,   163,   269,   570,   280,   289,
     291,   293,   294,   295,   299,   448,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   300,    12,   216,   164,    13,    14,    15,    16,
      17,    18,    19,   305,   165,    20,   308,   310,   311,   312,
     314,   333,    21,    22,    23,    24,    25,   336,    26,   316,
     317,   338,   339,   341,   348,   166,   167,   168,   169,   170,
     171,   172,   173,   337,   356,    27,   359,   361,   362,   363,
     371,   376,    28,    29,    30,    31,  -200,   379,  -167,   382,
     383,   387,   388,   391,    32,   393,   394,    33,   174,   175,
     395,  -202,   399,   403,   426,   417,    34,   427,   536,    35,
      36,    37,    38,    39,    40,    41,    42,    43,   430,   433,
     434,   435,    44,    45,    46,    47,    48,   438,   446,    49,
     449,    50,    51,    52,    13,    14,    15,    16,    17,    18,
      19,   445,   450,    20,   454,   472,   467,   477,   478,  -168,
      21,    22,    23,    24,    25,   470,    26,   480,   473,   482,
     481,   483,   484,    35,    36,    37,    38,    39,    40,    41,
     485,   486,   487,    27,   489,   495,   494,   499,   509,   503,
      28,    29,    30,    31,   418,   504,    51,    37,    38,    39,
      40,    41,    32,   505,   404,    33,   510,   513,   517,   405,
     520,   533,   406,   381,    34,   407,   459,   540,   408,   409,
     537,   544,    94,   541,    42,    43,   550,   553,    11,   559,
     556,    45,    95,   130,   560,   563,   566,    49,   374,    50,
      13,    14,    15,    16,    17,    18,    19,   569,   571,    20,
     573,   358,   131,   419,   370,   109,    21,    22,    23,    24,
      25,   228,    26,   397,   420,   227,   323,   283,   326,   274,
     212,   183,   313,   444,   457,   458,     0,     0,     0,    27,
       0,     0,     0,     0,     0,     0,    28,    29,    30,    31,
      37,    38,    39,    40,    41,     0,     0,   404,    32,     0,
       0,    33,   405,     0,     0,   406,     0,     0,   407,   476,
      34,   408,   409,     0,     0,     0,     0,     0,     0,     0,
      42,    43,     0,     0,     0,     0,     0,    45,     0,     0,
       0,     0,     0,    49,     0,    50,    13,    14,    15,    16,
      17,    18,    19,     0,     0,    20,     0,     0,     0,     0,
       0,     0,    21,    22,    23,    24,    25,     0,    26,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    27,     0,     0,     0,     0,
       0,     0,    28,    29,    30,    31,     0,     0,    13,    14,
      15,    16,   102,    18,    32,     0,     0,    33,     0,     0,
      13,    14,    15,    16,   102,    18,    34,    24,    25,     0,
      26,     0,     0,     0,     0,     0,    42,    43,     0,    24,
      25,   243,    26,    45,     0,     0,     0,    27,     0,    49,
       0,    50,     0,     0,    28,    29,    30,    31,     0,    27,
      13,    14,    15,    16,   102,    18,    28,    29,    30,    31,
       0,     0,    13,    14,    15,    16,   102,    18,    34,    24,
      25,     0,    26,   266,     0,     0,     0,     0,    42,    43,
      34,    24,    25,   275,    26,     0,     0,     0,     0,    27,
      42,    43,     0,   119,     0,     0,    28,    29,    30,    31,
       0,    27,    13,    14,    15,    16,   102,    18,    28,    29,
      30,    31,     0,     0,    13,    14,    15,    16,   102,    18,
      34,    24,    25,     0,    26,     0,     0,   335,     0,     0,
      42,    43,    34,    24,    25,   377,    26,     0,     0,     0,
       0,    27,    42,    43,     0,     0,     0,     0,    28,    29,
      30,    31,     0,    27,    13,    14,    15,    16,   102,    18,
      28,    29,    30,    31,     0,     0,     0,     0,     0,     0,
       0,     0,    34,    24,    25,     0,    26,     0,     0,     0,
       0,     0,    42,    43,    34,     0,     0,     0,     0,     0,
       0,     0,     0,    27,    42,    43,     0,     0,     0,     0,
      28,    29,    30,    31,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    34,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    42,    43
};

static const yytype_int16 yycheck[] =
{
      19,    20,    21,     3,   174,   175,    25,     3,    85,   206,
     202,   221,     7,    26,    33,   225,   180,    32,    53,    31,
       7,   189,     7,    31,    31,     7,     7,   411,   502,    23,
      97,     7,   393,   394,   508,    27,   103,   104,    30,    27,
      28,     7,    31,    31,   214,   519,     7,   221,    31,     7,
     102,   225,   222,    31,    31,    31,    31,    31,   532,    53,
     444,    85,    32,    98,    93,    26,    24,   428,     7,    93,
     431,   100,    53,    24,   435,    24,   100,   210,     7,   212,
      31,   100,    31,    98,   252,    24,    98,    95,    95,   299,
     300,    78,    79,    80,    81,    82,    78,    79,    80,    81,
      82,   271,   463,    85,   465,   273,   101,   468,    90,    98,
      95,    93,   286,     7,    26,    98,    75,    99,   100,    31,
      98,    98,   296,    98,    98,   299,   300,   301,    98,     7,
      24,   492,     7,   146,     7,   496,   333,    66,    67,    68,
      69,    70,    71,    72,    98,   506,    24,   311,     7,    24,
     318,   164,    28,     7,   515,    31,   324,   325,   177,   178,
      89,   180,   523,   176,     7,    28,   527,   337,    31,   530,
     158,   159,   160,   161,   162,   163,     7,   351,   539,   353,
       7,    24,   543,   196,    24,    24,   547,    74,    75,    24,
     209,    31,    31,   206,   555,    23,    31,   558,   217,    24,
       7,   369,    24,    24,    24,    24,    31,   568,   376,    31,
      31,    31,    31,   383,     7,    41,    42,     7,   388,    78,
      79,    80,    81,    82,    27,    53,    24,    24,   396,    32,
       7,    59,    60,    31,    31,   399,    35,    36,     7,    66,
      67,    68,    69,    70,    71,    72,    28,    26,    34,    31,
     263,   443,    31,   421,    62,    63,   426,   427,    86,    87,
     430,   280,    89,    27,   434,    10,    11,   477,    33,   437,
     480,    62,    63,     7,   442,   485,    66,    67,    68,    69,
      70,    71,    72,    13,    14,    27,    28,    10,    11,    31,
       7,   304,   311,   503,   504,   505,     7,   467,   466,    89,
     319,   150,   151,    78,    79,    80,    81,    82,   478,    98,
      85,   481,   156,   157,    27,    90,   486,    31,    93,    23,
     333,    96,   490,   342,    99,   100,    98,    98,    27,   499,
     349,    98,   328,   410,    37,    38,    39,    40,    23,   509,
     359,    94,   361,    25,    27,     7,   514,    27,    23,     7,
     520,    76,    77,    78,    79,    80,    81,    82,   371,    94,
       7,   529,   358,    23,     7,     7,   366,   535,    25,    23,
     540,   448,    13,     7,   544,    15,    16,    17,    18,    30,
     399,   549,   152,   153,   154,   155,   554,    24,    98,   559,
      43,    44,    45,    46,    47,    48,    98,   565,    27,     7,
      28,    28,    28,    98,    23,   405,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,    23,     0,    27,    23,     3,     4,     5,     6,
       7,     8,     9,    88,    32,    12,    26,    15,    29,     7,
       7,    23,    19,    20,    21,    22,    23,    27,    25,    98,
      98,   101,    31,    24,    24,    53,    54,    55,    56,    57,
      58,    59,    60,    94,    24,    42,    23,    30,    98,    31,
      31,     7,    49,    50,    51,    52,    97,    28,    98,    24,
      94,    24,    94,    24,    61,    24,    24,    64,    86,    87,
      65,    97,    29,     7,    94,    97,    73,    94,   517,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    94,    24,
      94,    24,    89,    90,    91,    92,    93,     7,     7,    96,
       7,    98,    99,   100,     3,     4,     5,     6,     7,     8,
       9,    97,     7,    12,     7,    31,    94,    23,    94,    98,
      19,    20,    21,    22,    23,    98,    25,    23,    98,     7,
      94,     7,     7,    76,    77,    78,    79,    80,    81,    82,
      23,    94,     7,    42,    98,     7,    98,    94,    94,    23,
      49,    50,    51,    52,    97,    23,    99,    78,    79,    80,
      81,    82,    61,    23,    85,    64,    98,    98,    32,    90,
      94,    98,    93,     7,    73,    96,    97,    94,    99,   100,
      98,    94,     5,    98,    83,    84,    98,    98,     2,    94,
      98,    90,     5,    34,    98,    98,    98,    96,    97,    98,
       3,     4,     5,     6,     7,     8,     9,    98,    98,    12,
      98,   309,    34,   366,   320,    23,    19,    20,    21,    22,
      23,   149,    25,    26,   366,   148,   263,   212,   264,   203,
     131,    85,   257,   401,   410,   410,    -1,    -1,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,
      78,    79,    80,    81,    82,    -1,    -1,    85,    61,    -1,
      -1,    64,    90,    -1,    -1,    93,    -1,    -1,    96,    97,
      73,    99,   100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      83,    84,    -1,    -1,    -1,    -1,    -1,    90,    -1,    -1,
      -1,    -1,    -1,    96,    -1,    98,     3,     4,     5,     6,
       7,     8,     9,    -1,    -1,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    19,    20,    21,    22,    23,    -1,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    50,    51,    52,    -1,    -1,     3,     4,
       5,     6,     7,     8,    61,    -1,    -1,    64,    -1,    -1,
       3,     4,     5,     6,     7,     8,    73,    22,    23,    -1,
      25,    -1,    -1,    -1,    -1,    -1,    83,    84,    -1,    22,
      23,    24,    25,    90,    -1,    -1,    -1,    42,    -1,    96,
      -1,    98,    -1,    -1,    49,    50,    51,    52,    -1,    42,
       3,     4,     5,     6,     7,     8,    49,    50,    51,    52,
      -1,    -1,     3,     4,     5,     6,     7,     8,    73,    22,
      23,    -1,    25,    26,    -1,    -1,    -1,    -1,    83,    84,
      73,    22,    23,    24,    25,    -1,    -1,    -1,    -1,    42,
      83,    84,    -1,    98,    -1,    -1,    49,    50,    51,    52,
      -1,    42,     3,     4,     5,     6,     7,     8,    49,    50,
      51,    52,    -1,    -1,     3,     4,     5,     6,     7,     8,
      73,    22,    23,    -1,    25,    -1,    -1,    28,    -1,    -1,
      83,    84,    73,    22,    23,    24,    25,    -1,    -1,    -1,
      -1,    42,    83,    84,    -1,    -1,    -1,    -1,    49,    50,
      51,    52,    -1,    42,     3,     4,     5,     6,     7,     8,
      49,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    22,    23,    -1,    25,    -1,    -1,    -1,
      -1,    -1,    83,    84,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    83,    84,    -1,    -1,    -1,    -1,
      49,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    83,    84
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
      98,    99,   100,   113,   121,   122,   126,   127,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     145,   146,   149,   150,   155,   156,   157,   158,   160,   162,
     163,   164,   168,   169,   172,   177,   178,   179,   190,   193,
     194,   196,   102,   118,   109,   111,   112,    53,    98,     7,
      27,    30,     7,   126,   126,   126,   159,     7,   161,   161,
     126,   127,   144,   135,   137,   135,   135,    98,   198,    98,
     126,     7,    66,    67,    68,    69,    70,    71,    72,    89,
     114,   115,     7,     7,     7,     7,    89,   114,   115,   116,
     117,     7,     7,    93,   100,     7,    31,    98,    34,    33,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    23,    32,    53,    54,    55,    56,
      57,    58,    59,    60,    86,    87,   128,    27,    15,    16,
      17,    18,   178,   179,     7,     7,     7,    98,   126,    95,
      98,    98,    98,    98,    24,    26,    31,    97,   103,   104,
     197,    62,    63,   165,   166,    98,    23,    53,    23,    27,
     141,   142,   141,    23,    94,    25,    27,    32,    27,    27,
       7,    23,    94,     7,     7,    23,   127,   130,   131,   132,
     132,   133,   133,   133,   133,   134,   134,   135,   135,   135,
     135,   135,   135,    24,   124,   127,     7,     7,   117,   117,
     127,   126,   126,    25,   170,   159,    23,     7,    30,   180,
     119,    28,   198,    13,   151,   152,    26,   127,    98,    98,
     199,   167,   170,    63,   166,    24,   124,     7,    24,   126,
      27,   142,   143,   143,     7,    31,   123,   186,   117,     7,
     195,    28,   126,    28,    28,    98,   123,   186,   117,    23,
      23,   123,   186,    24,    31,    88,    28,   198,    26,   171,
      15,    29,     7,   180,     7,   181,    98,    98,    10,    11,
     147,   148,   127,   144,   154,    14,   152,   153,   125,   145,
     117,   198,    24,    23,    28,    28,    27,    94,   101,    31,
     186,    24,    32,    98,    26,    31,    98,   186,    24,    32,
      98,   123,   186,   123,   186,   186,    24,   127,   125,    23,
     159,    30,    98,    31,   173,   175,   120,   198,   126,    10,
     148,    31,   198,   198,    97,   145,     7,    24,   124,    28,
     117,     7,    24,    94,   126,     7,    26,    24,    94,   126,
     186,    24,   186,    24,    24,    65,   187,    26,   126,    29,
     126,   174,   176,     7,    85,    90,    93,    96,    99,   100,
     177,   182,   183,   184,   185,   189,   192,    97,    97,   121,
     172,    95,   198,   127,   198,    24,    94,    94,   117,    98,
      94,   117,    98,    24,    94,    24,   187,   187,     7,   188,
     198,    24,   159,    24,   182,    97,     7,     7,   177,     7,
       7,    85,    93,   100,     7,     7,    90,   185,   189,    97,
     183,   198,   117,   117,   187,   117,   187,    94,   117,   187,
      98,   198,    31,    98,   198,   170,    97,    23,    94,     7,
      23,    94,     7,     7,     7,    23,    94,     7,   187,    98,
     187,   198,   117,   187,    98,     7,    24,   123,   117,    94,
      24,   123,   117,    23,    23,    23,    24,   123,   117,    94,
      98,   198,   187,    98,   187,    24,    31,    32,   191,   117,
      94,    24,   191,    24,   123,    24,   123,    24,   123,   187,
      24,   191,   117,    98,   198,   187,   126,    98,   191,   117,
      94,    98,   187,    24,    94,    24,   187,    24,   198,   187,
      98,   191,   198,    98,   187,   117,    98,   187,   117,    94,
      98,   187,   198,    98,   198,   187,    98,   187,   117,    98,
     198,    98,   187,    98
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
#line 102 "diksam.y"
    {
            dkc_set_require_and_rename_list(NULL, NULL);
        }
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 106 "diksam.y"
    {
            dkc_set_require_and_rename_list((yyvsp[(1) - (2)].require_list), (yyvsp[(2) - (2)].rename_list));
        }
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 110 "diksam.y"
    {
            dkc_set_require_and_rename_list((yyvsp[(1) - (1)].require_list), NULL);
        }
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 114 "diksam.y"
    {
            dkc_set_require_and_rename_list(NULL, (yyvsp[(1) - (1)].rename_list));
        }
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 118 "diksam.y"
    {
            dkc_set_require_and_rename_list(NULL, NULL);
		}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 125 "diksam.y"
    {
            (yyval.require_list) = dkc_chain_require_list((yyvsp[(1) - (2)].require_list), (yyvsp[(2) - (2)].require_list));
        }
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 131 "diksam.y"
    {
            (yyval.require_list) = dkc_create_require_list((yyvsp[(2) - (3)].package_name));
        }
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 137 "diksam.y"
    {
            (yyval.package_name) = dkc_create_package_name((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 141 "diksam.y"
    {
            (yyval.package_name) = dkc_chain_package_name((yyvsp[(1) - (3)].package_name), (yyvsp[(3) - (3)].identifier));
        }
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 148 "diksam.y"
    {
            (yyval.rename_list) = dkc_chain_rename_list((yyvsp[(1) - (2)].rename_list), (yyvsp[(2) - (2)].rename_list));
        }
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 154 "diksam.y"
    {
            (yyval.rename_list) = dkc_create_rename_list((yyvsp[(2) - (4)].package_name), (yyvsp[(3) - (4)].identifier));
        }
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 162 "diksam.y"
    {
            DKC_Compiler *compiler = dkc_get_current_compiler();

            compiler->statement_list
                = dkc_chain_statement_list(compiler->statement_list, (yyvsp[(1) - (1)].statement));
        }
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 174 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_VOID_TYPE;
        }
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 178 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_BOOLEAN_TYPE;
        }
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 182 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_INT_TYPE;
        }
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 186 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_DOUBLE_TYPE;
        }
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 190 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_STRING_TYPE;
        }
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 194 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_VARIENT_TYPE;
        }
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 198 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_NATIVE_POINTER_TYPE;
        }
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 202 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_DELEGATE_TYPE;
        }
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 208 "diksam.y"
    {
            (yyval.type_specifier) = dkc_create_identifier_type_specifier((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 214 "diksam.y"
    {
            TypeSpecifier *basic_type
                = dkc_create_type_specifier((yyvsp[(1) - (3)].basic_type_specifier));
            (yyval.type_specifier) = dkc_create_array_type_specifier(basic_type);
        }
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 220 "diksam.y"
    {
            TypeSpecifier *identifier_type
                = dkc_create_identifier_type_specifier((yyvsp[(1) - (3)].identifier));
            (yyval.type_specifier) = dkc_create_array_type_specifier(identifier_type);
        }
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 226 "diksam.y"
    {
            (yyval.type_specifier) = dkc_create_array_type_specifier((yyvsp[(1) - (3)].type_specifier));
        }
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 232 "diksam.y"
    {
                    (yyval.type_specifier) = dkc_create_type_specifier((yyvsp[(1) - (1)].basic_type_specifier));
        }
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 241 "diksam.y"
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

  case 39:

/* Line 1455 of yacc.c  */
#line 251 "diksam.y"
    {
			BcGetCurrentCompilerContext()->isLib=0;
		}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 263 "diksam.y"
    {
            dkc_function_define((yyvsp[(9) - (11)].type_specifier), (yyvsp[(3) - (11)].identifier), (yyvsp[(5) - (11)].parameter_list), (yyvsp[(10) - (11)].exception_list), NULL,(yyvsp[(6) - (11)].apost));
        }
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 267 "diksam.y"
    {
            dkc_function_define((yyvsp[(8) - (10)].type_specifier), (yyvsp[(3) - (10)].identifier), NULL, (yyvsp[(9) - (10)].exception_list), NULL,(yyvsp[(5) - (10)].apost));
        }
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 271 "diksam.y"
    {
            dkc_function_define(0, (yyvsp[(3) - (9)].identifier), (yyvsp[(5) - (9)].parameter_list), (yyvsp[(8) - (9)].exception_list), NULL,(yyvsp[(6) - (9)].apost));
        }
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 275 "diksam.y"
    {
			//printf("lib:%s\n",BcGetCurrentCompilerContext()->libname);
            dkc_function_define(0, (yyvsp[(3) - (8)].identifier), NULL, (yyvsp[(7) - (8)].exception_list), NULL,(yyvsp[(5) - (8)].apost));
        }
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 282 "diksam.y"
    {
            dkc_function_define((yyvsp[(8) - (10)].type_specifier), (yyvsp[(2) - (10)].identifier), (yyvsp[(4) - (10)].parameter_list), (yyvsp[(9) - (10)].exception_list), (yyvsp[(10) - (10)].block),(yyvsp[(5) - (10)].apost));
        }
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 286 "diksam.y"
    {
            dkc_function_define((yyvsp[(7) - (9)].type_specifier), (yyvsp[(2) - (9)].identifier), NULL, (yyvsp[(8) - (9)].exception_list), (yyvsp[(9) - (9)].block),(yyvsp[(4) - (9)].apost));
        }
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 290 "diksam.y"
    { //modified
            dkc_function_define(0, (yyvsp[(2) - (8)].identifier), (yyvsp[(4) - (8)].parameter_list), (yyvsp[(7) - (8)].exception_list), (yyvsp[(8) - (8)].block),(yyvsp[(5) - (8)].apost));
        }
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 294 "diksam.y"
    {
            dkc_function_define(0, (yyvsp[(2) - (7)].identifier), NULL, (yyvsp[(6) - (7)].exception_list), (yyvsp[(7) - (7)].block),(yyvsp[(4) - (7)].apost));
        }
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 301 "diksam.y"
    {
            (yyval.parameter_list) = dkc_create_parameter((yyvsp[(3) - (3)].type_specifier), (yyvsp[(1) - (3)].identifier));
        }
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 305 "diksam.y"
    {
            (yyval.parameter_list) = dkc_chain_parameter((yyvsp[(1) - (5)].parameter_list), (yyvsp[(5) - (5)].type_specifier), (yyvsp[(3) - (5)].identifier));
        }
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 311 "diksam.y"
    {
            (yyval.argument_list) = dkc_create_argument_list((yyvsp[(1) - (1)].expression));
        }
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 315 "diksam.y"
    {
            (yyval.argument_list) = dkc_chain_argument_list((yyvsp[(1) - (3)].argument_list), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 321 "diksam.y"
    {
            (yyval.statement_list) = dkc_create_statement_list((yyvsp[(1) - (1)].statement));
        }
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 325 "diksam.y"
    {
            (yyval.statement_list) = dkc_chain_statement_list((yyvsp[(1) - (2)].statement_list), (yyvsp[(2) - (2)].statement));
        }
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 332 "diksam.y"
    {
            (yyval.expression) = dkc_create_comma_expression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 339 "diksam.y"
    {
            (yyval.expression) = dkc_create_assign_expression((yyvsp[(1) - (3)].expression), (yyvsp[(2) - (3)].assignment_operator), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 345 "diksam.y"
    {
            (yyval.assignment_operator) = NORMAL_ASSIGN;
        }
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 349 "diksam.y"
    {
            (yyval.assignment_operator) = ADD_ASSIGN;
        }
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 353 "diksam.y"
    {
            (yyval.assignment_operator) = SUB_ASSIGN;
        }
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 357 "diksam.y"
    {
            (yyval.assignment_operator) = MUL_ASSIGN;
        }
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 361 "diksam.y"
    {
            (yyval.assignment_operator) = DIV_ASSIGN;
        }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 365 "diksam.y"
    {
            (yyval.assignment_operator) = MOD_ASSIGN;
        }
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 372 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(LOGICAL_OR_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 379 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(LOGICAL_AND_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 386 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(EQ_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 390 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(NE_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 397 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(GT_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 401 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(GE_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 405 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(LT_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 409 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(LE_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 416 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(ADD_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 420 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(SUB_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 427 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(MUL_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 431 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(DIV_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 435 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(MOD_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 439 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(BIT_AND_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 443 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(BIT_OR_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 447 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(BIT_XOR_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 454 "diksam.y"
    {
            (yyval.expression) = dkc_create_minus_expression((yyvsp[(2) - (2)].expression));
        }
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 458 "diksam.y"
    {
            (yyval.expression) = dkc_create_logical_not_expression((yyvsp[(2) - (2)].expression));
        }
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 462 "diksam.y"
    {
            (yyval.expression) = dkc_create_bit_not_expression((yyvsp[(2) - (2)].expression));
        }
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 469 "diksam.y"
    {
            (yyval.expression) = dkc_create_incdec_expression((yyvsp[(1) - (2)].expression), INCREMENT_EXPRESSION);
        }
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 473 "diksam.y"
    {
            (yyval.expression) = dkc_create_incdec_expression((yyvsp[(1) - (2)].expression), DECREMENT_EXPRESSION);
        }
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 477 "diksam.y"
    {
            (yyval.expression) = dkc_create_instanceof_expression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].type_specifier));
        }
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 485 "diksam.y"
    {
            (yyval.expression) = dkc_create_identifier_expression((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 489 "diksam.y"
    {
			(yyval.expression)=BcCreateAutoExpression((yyvsp[(1) - (1)].identifier));
		}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 495 "diksam.y"
    {
            (yyval.expression) = dkc_create_index_expression((yyvsp[(1) - (4)].expression), (yyvsp[(3) - (4)].expression));
        }
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 499 "diksam.y"
    {
            Expression *identifier = dkc_create_identifier_expression((yyvsp[(1) - (4)].identifier));
            (yyval.expression) = dkc_create_index_expression(identifier, (yyvsp[(3) - (4)].expression));
        }
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 504 "diksam.y"
    {
            (yyval.expression) = dkc_create_member_expression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].identifier));
        }
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 508 "diksam.y"
    {
            (yyval.expression) = dkc_create_function_call_expression((yyvsp[(1) - (4)].expression), (yyvsp[(3) - (4)].argument_list));
        }
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 512 "diksam.y"
    {
            (yyval.expression) = dkc_create_function_call_expression((yyvsp[(1) - (3)].expression), NULL);
        }
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 516 "diksam.y"
    {
            (yyval.expression) = (yyvsp[(2) - (3)].expression);
        }
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 520 "diksam.y"
    {
            (yyval.expression) = dkc_create_down_cast_expression((yyvsp[(1) - (4)].expression), (yyvsp[(3) - (4)].type_specifier));
        }
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 528 "diksam.y"
    {
            (yyval.expression) = dkc_create_boolean_expression(DVM_TRUE);
        }
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 532 "diksam.y"
    {
            (yyval.expression) = dkc_create_boolean_expression(DVM_FALSE);
        }
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 536 "diksam.y"
    {
            (yyval.expression) = dkc_create_null_expression();
        }
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 541 "diksam.y"
    {
            (yyval.expression) = dkc_create_this_expression();
        }
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 545 "diksam.y"
    {
            (yyval.expression) = dkc_create_super_expression();
        }
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 549 "diksam.y"
    {
			(yyval.expression) = dkc_create_new_delegate_expression();
		}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 553 "diksam.y"
    {
            (yyval.expression) = dkc_create_new_expression((yyvsp[(2) - (4)].identifier), NULL, NULL);
        }
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 557 "diksam.y"
    {
            (yyval.expression) = dkc_create_new_expression((yyvsp[(2) - (5)].identifier), NULL, (yyvsp[(4) - (5)].argument_list));
        }
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 561 "diksam.y"
    {
            (yyval.expression) = dkc_create_new_expression((yyvsp[(2) - (6)].identifier), (yyvsp[(4) - (6)].identifier), NULL);
        }
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 565 "diksam.y"
    {
            (yyval.expression) = dkc_create_new_expression((yyvsp[(2) - (7)].identifier), (yyvsp[(4) - (7)].identifier), (yyvsp[(6) - (7)].argument_list));
        }
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 571 "diksam.y"
    {
            (yyval.expression) = dkc_create_array_literal_expression((yyvsp[(2) - (3)].expression_list));
        }
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 575 "diksam.y"
    {
            (yyval.expression) = dkc_create_array_literal_expression((yyvsp[(2) - (4)].expression_list));
        }
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 581 "diksam.y"
    {
            (yyval.expression) = dkc_create_basic_array_creation((yyvsp[(2) - (3)].basic_type_specifier), (yyvsp[(3) - (3)].array_dimension), NULL);
        }
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 585 "diksam.y"
    {
            (yyval.expression) = dkc_create_basic_array_creation((yyvsp[(2) - (4)].basic_type_specifier), (yyvsp[(3) - (4)].array_dimension), (yyvsp[(4) - (4)].array_dimension));
        }
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 589 "diksam.y"
    {
            (yyval.expression) = dkc_create_class_array_creation((yyvsp[(2) - (3)].type_specifier), (yyvsp[(3) - (3)].array_dimension), NULL);
        }
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 594 "diksam.y"
    {
            (yyval.expression) = dkc_create_class_array_creation((yyvsp[(2) - (4)].type_specifier), (yyvsp[(3) - (4)].array_dimension), (yyvsp[(4) - (4)].array_dimension));
        }
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 601 "diksam.y"
    {
            (yyval.array_dimension) = dkc_chain_array_dimension((yyvsp[(1) - (2)].array_dimension), (yyvsp[(2) - (2)].array_dimension));
        }
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 607 "diksam.y"
    {
            (yyval.array_dimension) = dkc_create_array_dimension((yyvsp[(2) - (3)].expression));
        }
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 613 "diksam.y"
    {
            (yyval.array_dimension) = dkc_create_array_dimension(NULL);
        }
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 617 "diksam.y"
    {
            (yyval.array_dimension) = dkc_chain_array_dimension((yyvsp[(1) - (3)].array_dimension),
                                           dkc_create_array_dimension(NULL));
        }
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 624 "diksam.y"
    {
            (yyval.expression_list) = NULL;
        }
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 628 "diksam.y"
    {
            (yyval.expression_list) = dkc_create_expression_list((yyvsp[(1) - (1)].expression));
        }
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 632 "diksam.y"
    {
            (yyval.expression_list) = dkc_chain_expression_list((yyvsp[(1) - (3)].expression_list), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 638 "diksam.y"
    {
          (yyval.statement) = dkc_create_expression_statement((yyvsp[(1) - (2)].expression));
        }
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 654 "diksam.y"
    {/*empty line*/
			(yyval.statement)=0;
		}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 660 "diksam.y"
    {
            (yyval.statement) = dkc_create_if_statement((yyvsp[(2) - (4)].expression), (yyvsp[(4) - (4)].block), NULL, NULL);
        }
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 664 "diksam.y"
    {
			//printf("IF-ELSE %d\n",dkc_get_current_compiler()->current_line_number);
            (yyval.statement) = dkc_create_if_statement((yyvsp[(2) - (6)].expression), (yyvsp[(4) - (6)].block), NULL, (yyvsp[(6) - (6)].block));
        }
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 669 "diksam.y"
    {
            (yyval.statement) = dkc_create_if_statement((yyvsp[(2) - (5)].expression), (yyvsp[(4) - (5)].block), (yyvsp[(5) - (5)].elsif), NULL);
        }
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 673 "diksam.y"
    {
            (yyval.statement) = dkc_create_if_statement((yyvsp[(2) - (7)].expression), (yyvsp[(4) - (7)].block), (yyvsp[(5) - (7)].elsif), (yyvsp[(7) - (7)].block));
        }
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 680 "diksam.y"
    {
            (yyval.elsif) = dkc_chain_elsif_list((yyvsp[(1) - (2)].elsif), (yyvsp[(2) - (2)].elsif));
        }
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 686 "diksam.y"
    {
            (yyval.elsif) = dkc_create_elsif((yyvsp[(2) - (4)].expression), (yyvsp[(4) - (4)].block));
        }
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 692 "diksam.y"
    {
            (yyval.identifier) = NULL;
        }
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 696 "diksam.y"
    {
            (yyval.identifier) = (yyvsp[(1) - (2)].identifier);
        }
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 702 "diksam.y"
    {
            (yyval.statement) = dkc_create_switch_statement((yyvsp[(2) - (5)].expression), (yyvsp[(4) - (5)].case_list), (yyvsp[(5) - (5)].block));
        }
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 709 "diksam.y"
    {
            (yyval.case_list) = dkc_chain_case((yyvsp[(1) - (2)].case_list), (yyvsp[(2) - (2)].case_list));
        }
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 715 "diksam.y"
    {
            (yyval.case_list) = dkc_create_one_case((yyvsp[(2) - (3)].expression_list), (yyvsp[(3) - (3)].block));
        }
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 721 "diksam.y"
    {
            (yyval.block) = NULL;
        }
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 725 "diksam.y"
    {
            (yyval.block) = (yyvsp[(2) - (2)].block);
        }
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 731 "diksam.y"
    {
            (yyval.expression_list) = dkc_create_expression_list((yyvsp[(1) - (1)].expression));
        }
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 735 "diksam.y"
    {
            (yyval.expression_list) = dkc_chain_expression_list((yyvsp[(1) - (3)].expression_list), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 741 "diksam.y"
    {
            (yyval.statement) = dkc_create_while_statement((yyvsp[(1) - (4)].identifier), (yyvsp[(3) - (4)].expression), (yyvsp[(4) - (4)].block));
        }
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 747 "diksam.y"
    {
            (yyval.statement) = dkc_create_for_statement((yyvsp[(1) - (8)].identifier), (yyvsp[(3) - (8)].expression), (yyvsp[(5) - (8)].expression), (yyvsp[(7) - (8)].expression), (yyvsp[(8) - (8)].block));
        }
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 753 "diksam.y"
    {
            (yyval.statement) = dkc_create_do_while_statement((yyvsp[(1) - (8)].identifier), (yyvsp[(3) - (8)].block), (yyvsp[(6) - (8)].expression));
        }
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 759 "diksam.y"
    {
            (yyval.statement) = dkc_create_foreach_statement((yyvsp[(1) - (8)].identifier), (yyvsp[(4) - (8)].identifier), (yyvsp[(6) - (8)].expression), (yyvsp[(8) - (8)].block));
        }
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 765 "diksam.y"
    {
            (yyval.expression) = NULL;
        }
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 772 "diksam.y"
    {
            (yyval.statement) = dkc_create_return_statement((yyvsp[(2) - (3)].expression));
        }
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 778 "diksam.y"
    {
            (yyval.identifier) = NULL;
        }
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 785 "diksam.y"
    {
            (yyval.statement) = dkc_create_break_statement((yyvsp[(2) - (3)].identifier));
        }
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 791 "diksam.y"
    {
            (yyval.statement) = dkc_create_continue_statement((yyvsp[(2) - (3)].identifier));
        }
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 797 "diksam.y"
    {
            (yyval.statement) = dkc_create_try_statement((yyvsp[(2) - (5)].block), (yyvsp[(3) - (5)].catch_clause), (yyvsp[(5) - (5)].block));
        }
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 801 "diksam.y"
    {
            (yyval.statement) = dkc_create_try_statement((yyvsp[(2) - (4)].block), NULL, (yyvsp[(4) - (4)].block));
        }
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 805 "diksam.y"
    {
            (yyval.statement) = dkc_create_try_statement((yyvsp[(2) - (3)].block), (yyvsp[(3) - (3)].catch_clause), NULL);
        }
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 812 "diksam.y"
    {
            (yyval.catch_clause) = dkc_chain_catch_list((yyvsp[(1) - (2)].catch_clause), (yyvsp[(2) - (2)].catch_clause));
        }
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 818 "diksam.y"
    {
            (yyval.catch_clause) = dkc_start_catch_clause();
        }
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 822 "diksam.y"
    {
            (yyval.catch_clause) = dkc_end_catch_clause((yyvsp[(2) - (5)].catch_clause), (yyvsp[(3) - (5)].type_specifier), (yyvsp[(4) - (5)].identifier), (yyvsp[(5) - (5)].block));
        }
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 828 "diksam.y"
    {
            (yyval.statement) = dkc_create_throw_statement((yyvsp[(2) - (3)].expression));
        }
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 832 "diksam.y"
    {
            (yyval.statement) = dkc_create_throw_statement(NULL);
        }
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 838 "diksam.y"
    {
            (yyval.statement) = dkc_create_declaration_statement(DVM_FALSE, (yyvsp[(4) - (5)].type_specifier), (yyvsp[(2) - (5)].identifier), NULL);
        }
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 842 "diksam.y"
    {
            (yyval.statement) = dkc_create_declaration_statement(DVM_FALSE, (yyvsp[(4) - (7)].type_specifier), (yyvsp[(2) - (7)].identifier), (yyvsp[(6) - (7)].expression));
        }
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 846 "diksam.y"
    {
            (yyval.statement) = dkc_create_declaration_statement(DVM_FALSE, (yyvsp[(4) - (5)].type_specifier), (yyvsp[(2) - (5)].identifier), NULL);
        }
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 850 "diksam.y"
    {
            (yyval.statement) = dkc_create_declaration_statement(DVM_TRUE, (yyvsp[(4) - (7)].type_specifier), (yyvsp[(2) - (7)].identifier), (yyvsp[(6) - (7)].expression));
        }
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 856 "diksam.y"
    {
            (yyval.block) = dkc_open_block(0);
        }
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 860 "diksam.y"
    {
            (yyval.block) = dkc_close_block((yyvsp[(2) - (4)].block), (yyvsp[(3) - (4)].statement_list));
        }
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 864 "diksam.y"
    {
            Block *empty_block = dkc_open_block(0);
            (yyval.block) = dkc_close_block(empty_block, NULL);
        }
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 872 "diksam.y"
    {
            dkc_start_class_definition(NULL, (yyvsp[(1) - (4)].class_or_interface), (yyvsp[(2) - (4)].identifier), (yyvsp[(3) - (4)].extends_list));
        }
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 876 "diksam.y"
    {
            dkc_class_define((yyvsp[(6) - (7)].member_declaration));
        }
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 881 "diksam.y"
    {
            dkc_start_class_definition(&(yyvsp[(1) - (5)].class_or_member_modifier), (yyvsp[(2) - (5)].class_or_interface), (yyvsp[(3) - (5)].identifier), (yyvsp[(4) - (5)].extends_list));
        }
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 884 "diksam.y"
    {
            dkc_class_define((yyvsp[(7) - (8)].member_declaration));
        }
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 888 "diksam.y"
    {
            dkc_start_class_definition(NULL, (yyvsp[(1) - (4)].class_or_interface), (yyvsp[(2) - (4)].identifier), (yyvsp[(3) - (4)].extends_list));
        }
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 892 "diksam.y"
    {
            dkc_class_define(NULL);
        }
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 897 "diksam.y"
    {
            dkc_start_class_definition(&(yyvsp[(1) - (5)].class_or_member_modifier), (yyvsp[(2) - (5)].class_or_interface), (yyvsp[(3) - (5)].identifier), (yyvsp[(4) - (5)].extends_list));
        }
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 901 "diksam.y"
    {
            dkc_class_define(NULL);
        }
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 908 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_chain_class_or_member_modifier((yyvsp[(1) - (2)].class_or_member_modifier), (yyvsp[(2) - (2)].class_or_member_modifier));
        }
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 915 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(VIRTUAL_MODIFIER);
        }
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 919 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(OVERRIDE_MODIFIER);
        }
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 923 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(ABSTRACT_MODIFIER);
        }
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 929 "diksam.y"
    {
            (yyval.class_or_interface) = DVM_CLASS_DEFINITION;
        }
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 933 "diksam.y"
    {
            (yyval.class_or_interface) = DVM_INTERFACE_DEFINITION;
        }
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 939 "diksam.y"
    {
            (yyval.extends_list) = NULL;
        }
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 943 "diksam.y"
    {
            (yyval.extends_list) = (yyvsp[(2) - (2)].extends_list);
        }
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 949 "diksam.y"
    {
            (yyval.extends_list) = dkc_create_extends_list((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 953 "diksam.y"
    {
            (yyval.extends_list) = dkc_chain_extends_list((yyvsp[(1) - (3)].extends_list), (yyvsp[(3) - (3)].identifier));
        }
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 960 "diksam.y"
    {
            (yyval.member_declaration) = dkc_chain_member_declaration((yyvsp[(1) - (2)].member_declaration), (yyvsp[(2) - (2)].member_declaration));
        }
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 970 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_method_member(NULL, (yyvsp[(1) - (1)].function_definition), DVM_FALSE);
        }
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 974 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_method_member(&(yyvsp[(1) - (2)].class_or_member_modifier), (yyvsp[(2) - (2)].function_definition), DVM_FALSE);
        }
    break;

  case 222:

/* Line 1455 of yacc.c  */
#line 978 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_method_member(NULL, (yyvsp[(1) - (1)].function_definition), DVM_TRUE);
        }
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 982 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_method_member(&(yyvsp[(1) - (2)].class_or_member_modifier), (yyvsp[(2) - (2)].function_definition), DVM_TRUE);
        }
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 988 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define((yyvsp[(7) - (9)].type_specifier), (yyvsp[(2) - (9)].identifier), (yyvsp[(4) - (9)].parameter_list), (yyvsp[(8) - (9)].exception_list), (yyvsp[(9) - (9)].block));
        }
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 992 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define((yyvsp[(6) - (8)].type_specifier), (yyvsp[(2) - (8)].identifier), NULL, (yyvsp[(7) - (8)].exception_list), (yyvsp[(8) - (8)].block));
        }
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 996 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define((yyvsp[(8) - (10)].type_specifier), (yyvsp[(3) - (10)].identifier), (yyvsp[(5) - (10)].parameter_list), (yyvsp[(9) - (10)].exception_list), NULL);
        }
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 1000 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define((yyvsp[(7) - (9)].type_specifier), (yyvsp[(3) - (9)].identifier), NULL, (yyvsp[(8) - (9)].exception_list), NULL);
        }
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 1004 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define(0, (yyvsp[(2) - (7)].identifier), (yyvsp[(4) - (7)].parameter_list), (yyvsp[(6) - (7)].exception_list), (yyvsp[(7) - (7)].block));
        }
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 1008 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define(0, (yyvsp[(2) - (6)].identifier), NULL, (yyvsp[(5) - (6)].exception_list), (yyvsp[(6) - (6)].block));
        }
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 1012 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define(0, (yyvsp[(3) - (8)].identifier), (yyvsp[(5) - (8)].parameter_list), (yyvsp[(7) - (8)].exception_list), NULL);
        }
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 1016 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define(0, (yyvsp[(3) - (7)].identifier), NULL, (yyvsp[(6) - (7)].exception_list), NULL);
        }
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 1022 "diksam.y"
    {
			(yyval.apost)=0;
		}
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 1026 "diksam.y"
    {
			(yyval.apost)=1;
		}
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 1032 "diksam.y"
    {
            (yyval.exception_list) = NULL;
        }
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 1036 "diksam.y"
    {
            (yyval.exception_list) = (yyvsp[(2) - (2)].exception_list);
        }
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 1042 "diksam.y"
    {
            (yyval.exception_list) = dkc_create_throws((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 1046 "diksam.y"
    {
            (yyval.exception_list) = dkc_chain_exception_list((yyvsp[(1) - (3)].exception_list), (yyvsp[(3) - (3)].identifier));
        }
    break;

  case 238:

/* Line 1455 of yacc.c  */
#line 1052 "diksam.y"
    {
            (yyval.function_definition) = dkc_constructor_function_define((yyvsp[(2) - (7)].identifier), (yyvsp[(4) - (7)].parameter_list), (yyvsp[(6) - (7)].exception_list), (yyvsp[(7) - (7)].block));
        }
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 1056 "diksam.y"
    {
            (yyval.function_definition) = dkc_constructor_function_define((yyvsp[(2) - (6)].identifier), NULL, (yyvsp[(5) - (6)].exception_list), (yyvsp[(6) - (6)].block));
        }
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 1060 "diksam.y"
    {
            (yyval.function_definition) = dkc_constructor_function_define((yyvsp[(3) - (8)].identifier), (yyvsp[(5) - (8)].parameter_list), (yyvsp[(7) - (8)].exception_list), NULL);
        }
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 1064 "diksam.y"
    {
            (yyval.function_definition) = dkc_constructor_function_define((yyvsp[(3) - (7)].identifier), NULL, (yyvsp[(6) - (7)].exception_list), NULL);
        }
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 1070 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(PUBLIC_MODIFIER);
        }
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 1074 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(PRIVATE_MODIFIER);
        }
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 1080 "diksam.y"
    {
            (yyval.expression) = NULL;
        }
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 1084 "diksam.y"
    {
            (yyval.expression) = (yyvsp[(2) - (2)].expression);
        }
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 1090 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(NULL, DVM_FALSE, (yyvsp[(4) - (6)].type_specifier), (yyvsp[(2) - (6)].identifier), (yyvsp[(5) - (6)].expression));
        }
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 1095 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(&(yyvsp[(1) - (6)].class_or_member_modifier), DVM_FALSE, (yyvsp[(4) - (6)].type_specifier), (yyvsp[(2) - (6)].identifier), (yyvsp[(5) - (6)].expression));
        }
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 1099 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(NULL, DVM_TRUE, (yyvsp[(4) - (6)].type_specifier), (yyvsp[(2) - (6)].identifier), (yyvsp[(5) - (6)].expression));
        }
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 1104 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(&(yyvsp[(1) - (7)].class_or_member_modifier), DVM_TRUE, (yyvsp[(5) - (7)].type_specifier), (yyvsp[(3) - (7)].identifier), (yyvsp[(6) - (7)].expression));
        }
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 1108 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(&(yyvsp[(2) - (7)].class_or_member_modifier), DVM_TRUE, (yyvsp[(5) - (7)].type_specifier), (yyvsp[(3) - (7)].identifier), (yyvsp[(6) - (7)].expression));
        }
    break;

  case 251:

/* Line 1455 of yacc.c  */
#line 1114 "diksam.y"
    {
            dkc_create_delegate_definition((yyvsp[(8) - (10)].type_specifier), (yyvsp[(2) - (10)].identifier), (yyvsp[(4) - (10)].parameter_list), (yyvsp[(9) - (10)].exception_list),(yyvsp[(5) - (10)].apost));
        }
    break;

  case 252:

/* Line 1455 of yacc.c  */
#line 1118 "diksam.y"
    {
            dkc_create_delegate_definition((yyvsp[(7) - (9)].type_specifier), (yyvsp[(2) - (9)].identifier), NULL, (yyvsp[(8) - (9)].exception_list),(yyvsp[(4) - (9)].apost));
        }
    break;

  case 253:

/* Line 1455 of yacc.c  */
#line 1124 "diksam.y"
    {
            dkc_create_enum_definition((yyvsp[(2) - (5)].identifier), (yyvsp[(4) - (5)].enumerator));
        }
    break;

  case 254:

/* Line 1455 of yacc.c  */
#line 1128 "diksam.y"
    {
            dkc_create_enum_definition((yyvsp[(2) - (6)].identifier), (yyvsp[(4) - (6)].enumerator));
        }
    break;

  case 255:

/* Line 1455 of yacc.c  */
#line 1134 "diksam.y"
    {
            (yyval.enumerator) = dkc_create_enumerator((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 1138 "diksam.y"
    {
            (yyval.enumerator) = dkc_chain_enumerator((yyvsp[(1) - (3)].enumerator), (yyvsp[(3) - (3)].identifier));
        }
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 1144 "diksam.y"
    {
            dkc_create_const_definition(NULL, (yyvsp[(2) - (5)].identifier), (yyvsp[(4) - (5)].expression));
        }
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 1148 "diksam.y"
    {
            dkc_create_const_definition((yyvsp[(2) - (4)].type_specifier), (yyvsp[(3) - (4)].identifier), NULL);
        }
    break;

  case 259:

/* Line 1455 of yacc.c  */
#line 1154 "diksam.y"
    {
			(yyval.apost)=0;
		}
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 1158 "diksam.y"
    {
			(yyval.apost)=1;
		}
    break;

  case 261:

/* Line 1455 of yacc.c  */
#line 1162 "diksam.y"
    {
			(yyval.apost)=-1;
		}
    break;

  case 262:

/* Line 1455 of yacc.c  */
#line 1168 "diksam.y"
    {
            (yyval.block) = dkc_open_block((yyvsp[(2) - (2)].apost));
			//printf("E1 %d\n",dkc_get_current_compiler());
        }
    break;

  case 263:

/* Line 1455 of yacc.c  */
#line 1173 "diksam.y"
    {
            (yyval.block) = dkc_close_block((yyvsp[(3) - (5)].block), (yyvsp[(4) - (5)].statement_list));
			//printf("C1 %d\n",dkc_get_current_compiler()->current_line_number);
        }
    break;

  case 264:

/* Line 1455 of yacc.c  */
#line 1178 "diksam.y"
    {
            Block *empty_block = dkc_open_block(0);
            (yyval.block) = dkc_close_block(empty_block, NULL);
			//printf("C2 %d\n",dkc_get_current_compiler()->current_line_number);
        }
    break;



/* Line 1455 of yacc.c  */
#line 4093 "y.tab.c"
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
#line 1184 "diksam.y"


