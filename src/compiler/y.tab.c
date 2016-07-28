
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
     SAFE = 359,
     SHARED = 360,
     GLOBAL = 361,
     VOLATILE = 362,
     ATM_ADD_ASSIGN_T = 363,
     ATM_SUB_ASSIGN_T = 364
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
#define SHARED 360
#define GLOBAL 361
#define VOLATILE 362
#define ATM_ADD_ASSIGN_T 363
#define ATM_SUB_ASSIGN_T 364




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
	int					intval;
	TemplateTypes		*template;
	TemplateDeclare     *template_def;



/* Line 214 of yacc.c  */
#line 367 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 379 "y.tab.c"

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
#define YYLAST   1021

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  110
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  103
/* YYNRULES -- Number of rules.  */
#define YYNRULES  288
/* YYNRULES -- Number of states.  */
#define YYNSTATES  621

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   364

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
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    12,    14,    16,    19,
      21,    24,    28,    30,    34,    36,    39,    44,    46,    48,
      50,    52,    54,    56,    58,    60,    62,    64,    66,    68,
      70,    72,    74,    78,    82,    86,    90,    93,    98,   100,
     102,   104,   106,   108,   112,   113,   120,   121,   124,   127,
     139,   150,   160,   169,   180,   190,   199,   207,   209,   213,
     219,   221,   225,   227,   230,   232,   236,   238,   242,   244,
     246,   248,   250,   252,   254,   256,   258,   260,   264,   266,
     270,   272,   276,   280,   282,   286,   290,   294,   298,   300,
     304,   308,   310,   314,   318,   322,   326,   330,   334,   336,
     339,   342,   345,   347,   350,   353,   357,   359,   361,   363,
     365,   370,   375,   382,   389,   393,   398,   402,   406,   411,
     413,   415,   417,   419,   421,   423,   425,   427,   429,   431,
     436,   441,   447,   454,   462,   466,   471,   476,   482,   487,
     493,   498,   504,   506,   509,   513,   516,   520,   521,   523,
     527,   530,   532,   534,   536,   538,   540,   542,   544,   546,
     548,   550,   552,   554,   556,   561,   568,   574,   582,   584,
     587,   592,   593,   596,   602,   604,   607,   611,   612,   615,
     617,   621,   626,   635,   644,   653,   654,   656,   660,   661,
     663,   667,   671,   677,   682,   686,   688,   691,   692,   698,
     702,   705,   713,   723,   729,   737,   738,   743,   746,   748,
     752,   756,   762,   766,   767,   768,   778,   779,   790,   791,
     800,   801,   811,   813,   816,   818,   820,   822,   824,   826,
     828,   829,   832,   834,   838,   840,   843,   845,   847,   849,
     852,   854,   857,   867,   876,   887,   897,   905,   912,   921,
     929,   930,   933,   934,   937,   939,   943,   951,   958,   967,
     975,   977,   979,   980,   983,   990,   997,  1004,  1012,  1020,
    1031,  1041,  1047,  1054,  1056,  1060,  1066,  1071,  1072,  1074,
    1075,  1077,  1078,  1080,  1081,  1084,  1087,  1088,  1094
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     111,     0,    -1,   112,    -1,   111,   118,    -1,    -1,   113,
     116,    -1,   113,    -1,   116,    -1,   112,   126,    -1,   114,
      -1,   113,   114,    -1,    74,   115,    98,    -1,     7,    -1,
     115,    53,     7,    -1,   117,    -1,   116,   117,    -1,    75,
     115,     7,    98,    -1,   130,    -1,   182,    -1,   153,    -1,
     203,    -1,   204,    -1,   206,    -1,    66,    -1,    67,    -1,
      68,    -1,    69,    -1,    70,    -1,    71,    -1,    72,    -1,
      89,    -1,     7,    -1,   119,    27,    28,    -1,     7,    27,
      28,    -1,   122,    27,    28,    -1,   123,    27,    28,    -1,
     121,   209,    -1,     7,    39,   125,    37,    -1,   119,    -1,
     122,    -1,   120,    -1,   123,    -1,   124,    -1,   125,    31,
     124,    -1,    -1,   102,     7,   127,    98,   128,    97,    -1,
      -1,   128,   129,    -1,   128,   182,    -1,    99,    93,     7,
      23,   131,   196,    24,    94,   124,   197,    98,    -1,    99,
      93,     7,    23,   196,    24,    94,   124,   197,    98,    -1,
      99,   100,     7,    23,   131,   196,    24,   197,    98,    -1,
      99,   100,     7,    23,   196,    24,   197,    98,    -1,    93,
       7,    23,   131,   196,    24,    94,   124,   197,   211,    -1,
      93,     7,    23,   196,    24,    94,   124,   197,   211,    -1,
     100,     7,    23,   131,   196,    24,   197,   211,    -1,   100,
       7,    23,   196,    24,   197,   211,    -1,   129,    -1,     7,
      94,   124,    -1,   131,    31,     7,    94,   124,    -1,   135,
      -1,   132,    31,   135,    -1,   153,    -1,   133,   153,    -1,
     135,    -1,   134,    31,   135,    -1,   137,    -1,   145,   136,
     135,    -1,    32,    -1,    54,    -1,    55,    -1,   108,    -1,
     109,    -1,    56,    -1,    57,    -1,    58,    -1,   138,    -1,
     137,    34,   138,    -1,   139,    -1,   138,    33,   139,    -1,
     140,    -1,   139,    35,   140,    -1,   139,    36,   140,    -1,
     141,    -1,   140,    37,   141,    -1,   140,    38,   141,    -1,
     140,    39,   141,    -1,   140,    40,   141,    -1,   142,    -1,
     141,    41,   142,    -1,   141,    42,   142,    -1,   143,    -1,
     142,    43,   143,    -1,   142,    44,   143,    -1,   142,    45,
     143,    -1,   142,    46,   143,    -1,   142,    47,   143,    -1,
     142,    48,   143,    -1,   144,    -1,    42,   143,    -1,    52,
     143,    -1,    49,   143,    -1,   145,    -1,   145,    59,    -1,
     145,    60,    -1,   145,    86,   124,    -1,   146,    -1,   148,
      -1,     7,    -1,     8,    -1,   146,    27,   134,    28,    -1,
       7,    27,   134,    28,    -1,     7,    27,   134,    30,   134,
      28,    -1,   146,    27,   134,    30,   134,    28,    -1,   145,
      53,     7,    -1,   145,    23,   132,    24,    -1,   145,    23,
      24,    -1,    23,   134,    24,    -1,   145,    87,   124,    88,
      -1,     3,    -1,     4,    -1,     5,    -1,     6,    -1,    50,
      -1,    51,    -1,    22,    -1,   147,    -1,    83,    -1,    84,
      -1,    73,    89,    23,    24,    -1,    73,     7,    23,    24,
      -1,    73,     7,    23,   132,    24,    -1,    73,     7,    53,
       7,    23,    24,    -1,    73,     7,    53,     7,    23,   132,
      24,    -1,    25,   152,    26,    -1,    25,   152,    31,    26,
      -1,    73,   119,   149,   209,    -1,    73,   119,   149,   151,
     209,    -1,    73,   120,   149,   209,    -1,    73,   120,   149,
     151,   209,    -1,    73,   123,   149,   209,    -1,    73,   123,
     149,   151,   209,    -1,   150,    -1,   149,   150,    -1,    27,
     134,    28,    -1,    27,    28,    -1,   151,    27,    28,    -1,
      -1,   135,    -1,   152,    31,   135,    -1,   134,    98,    -1,
     154,    -1,   158,    -1,   163,    -1,   164,    -1,   165,    -1,
     166,    -1,   168,    -1,   170,    -1,   171,    -1,   172,    -1,
     176,    -1,   177,    -1,    98,    -1,     9,   134,    95,   211,
      -1,     9,   134,    95,   211,    10,   211,    -1,     9,   134,
      95,   211,   155,    -1,     9,   134,    95,   211,   155,    10,
     211,    -1,   156,    -1,   155,   156,    -1,    11,   134,    95,
     211,    -1,    -1,     7,    30,    -1,    12,   134,    98,   159,
     161,    -1,   160,    -1,   159,   160,    -1,    13,   162,   211,
      -1,    -1,    14,   211,    -1,   135,    -1,   152,    31,   135,
      -1,   157,    15,   134,   211,    -1,   157,    17,   167,    29,
     167,    29,   167,   211,    -1,   157,    16,   178,    15,    23,
     134,    24,    98,    -1,   157,    18,    23,     7,    30,   134,
      24,   178,    -1,    -1,   134,    -1,    19,   167,    98,    -1,
      -1,     7,    -1,    20,   169,    98,    -1,    21,   169,    98,
      -1,    61,   211,   173,    63,   211,    -1,    61,   211,    63,
     178,    -1,    61,   211,   173,    -1,   174,    -1,   173,   174,
      -1,    -1,    62,   175,   124,     7,   211,    -1,    64,   134,
      98,    -1,    64,    98,    -1,    96,   208,     7,    94,   207,
     124,    98,    -1,    96,   208,     7,    94,   207,   124,    32,
     134,    98,    -1,    90,     7,    94,   124,    98,    -1,    90,
       7,    94,   124,    32,   134,    98,    -1,    -1,    25,   179,
     133,    26,    -1,    25,    26,    -1,     7,    -1,   180,    31,
       7,    -1,     7,    30,   120,    -1,   180,    31,     7,    30,
     120,    -1,    39,   180,    37,    -1,    -1,    -1,   207,   189,
       7,   181,   190,    98,   183,   192,    97,    -1,    -1,   207,
     187,   189,     7,   181,   190,    98,   184,   192,    97,    -1,
      -1,   207,   189,     7,   181,   190,    98,   185,    97,    -1,
      -1,   207,   187,   189,     7,   181,   190,    98,   186,    97,
      -1,   188,    -1,   187,   188,    -1,   200,    -1,    80,    -1,
      81,    -1,    82,    -1,    76,    -1,    77,    -1,    -1,    30,
     191,    -1,     7,    -1,   191,    31,     7,    -1,   193,    -1,
     192,   193,    -1,   194,    -1,   202,    -1,   195,    -1,   187,
     195,    -1,   199,    -1,   187,   199,    -1,    93,     7,    23,
     131,    24,    94,   124,   197,   211,    -1,    93,     7,    23,
      24,    94,   124,   197,   211,    -1,    99,    93,     7,    23,
     131,    24,    94,   124,   197,    98,    -1,    99,    93,     7,
      23,    24,    94,   124,   197,    98,    -1,   100,     7,    23,
     131,    24,   197,   211,    -1,   100,     7,    23,    24,   197,
     211,    -1,    99,   100,     7,    23,   131,    24,   197,    98,
      -1,    99,   100,     7,    23,    24,   197,    98,    -1,    -1,
      31,   101,    -1,    -1,    65,   198,    -1,     7,    -1,   198,
      31,     7,    -1,    85,     7,    23,   131,    24,   197,   211,
      -1,    85,     7,    23,    24,   197,   211,    -1,    99,    85,
       7,    23,   131,    24,   197,    98,    -1,    99,    85,     7,
      23,    24,   197,    98,    -1,    78,    -1,    79,    -1,    -1,
      32,   134,    -1,    96,     7,    94,   124,   201,    98,    -1,
     187,     7,    94,   124,   201,    98,    -1,    90,     7,    94,
     124,   201,    98,    -1,   187,    90,     7,    94,   124,   201,
      98,    -1,    90,   187,     7,    94,   124,   201,    98,    -1,
      89,     7,    23,   131,   196,    24,    94,   124,   197,    98,
      -1,    89,     7,    23,   196,    24,    94,   124,   197,    98,
      -1,    91,     7,    25,   205,    26,    -1,    91,     7,    25,
     205,    31,    26,    -1,     7,    -1,   205,    31,     7,    -1,
      92,     7,    32,   134,    98,    -1,    92,   124,     7,    98,
      -1,    -1,   105,    -1,    -1,   107,    -1,    -1,   106,    -1,
      -1,   103,    98,    -1,   104,    98,    -1,    -1,    98,   210,
     212,   133,    97,    -1,    98,    97,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   106,   106,   107,   111,   114,   118,   122,   126,   132,
     133,   139,   145,   149,   155,   156,   162,   168,   169,   170,
     177,   178,   179,   182,   186,   190,   194,   198,   202,   206,
     210,   216,   222,   228,   234,   238,   244,   258,   264,   268,
     269,   270,   274,   278,   286,   285,   300,   303,   304,   307,
     311,   315,   319,   326,   330,   334,   338,   342,   345,   349,
     355,   359,   365,   369,   375,   376,   382,   383,   389,   393,
     397,   401,   405,   409,   413,   417,   423,   424,   430,   431,
     437,   438,   442,   448,   449,   453,   457,   461,   467,   468,
     472,   478,   479,   483,   487,   491,   495,   499,   505,   506,
     510,   514,   520,   521,   525,   529,   535,   536,   537,   541,
     547,   551,   556,   561,   565,   569,   573,   577,   581,   585,
     586,   587,   588,   589,   593,   597,   601,   602,   606,   610,
     614,   618,   622,   626,   632,   636,   642,   646,   650,   654,
     659,   663,   669,   670,   676,   682,   686,   694,   697,   701,
     707,   711,   712,   713,   714,   715,   716,   717,   718,   719,
     720,   721,   722,   723,   729,   733,   738,   742,   748,   749,
     755,   762,   765,   771,   777,   778,   784,   791,   794,   800,
     804,   810,   816,   822,   828,   835,   838,   841,   848,   851,
     854,   860,   866,   870,   874,   880,   881,   888,   887,   897,
     901,   907,   911,   915,   919,   926,   925,   933,   940,   944,
     948,   952,   958,   963,   968,   966,   977,   975,   984,   983,
     993,   991,  1002,  1003,  1009,  1010,  1014,  1018,  1024,  1028,
    1035,  1038,  1044,  1048,  1054,  1055,  1061,  1062,  1065,  1069,
    1073,  1077,  1083,  1087,  1091,  1095,  1099,  1103,  1107,  1111,
    1118,  1121,  1128,  1131,  1137,  1141,  1147,  1151,  1155,  1159,
    1165,  1169,  1176,  1179,  1185,  1189,  1194,  1198,  1203,  1209,
    1213,  1219,  1223,  1229,  1233,  1239,  1243,  1250,  1253,  1260,
    1263,  1270,  1273,  1280,  1283,  1287,  1294,  1293,  1303
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
  "UNSAFE", "SAFE", "SHARED", "GLOBAL", "VOLATILE", "ATM_ADD_ASSIGN_T",
  "ATM_SUB_ASSIGN_T", "$accept", "translation_unit", "initial_declaration",
  "require_list", "require_declaration", "package_name", "rename_list",
  "rename_declaration", "definition_or_statement", "basic_type_specifier",
  "identifier_type_specifier", "array_type_specifier_sub",
  "array_type_specifier", "template_type_specifier", "type_specifier",
  "type_list", "lib_function", "$@1", "lib_function_declaration_list",
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
  "block", "@3", "template_def_list", "template_list", "class_definition",
  "$@4", "$@5", "$@6", "$@7", "class_or_member_modifier_list",
  "class_or_member_modifier", "class_or_interface", "extends",
  "extends_list", "member_declaration_list", "member_declaration",
  "method_member", "method_function_definition", "apostrophe",
  "throws_clause", "exception_list", "constructor_definition",
  "access_modifier", "initializer_opt", "field_member",
  "delegate_definition", "enum_definition", "enumerator_list",
  "const_definition", "shared", "volatile", "global", "unsafe", "myblock",
  "@8", 0
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
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   110,   111,   111,   112,   112,   112,   112,   112,   113,
     113,   114,   115,   115,   116,   116,   117,   118,   118,   118,
     118,   118,   118,   119,   119,   119,   119,   119,   119,   119,
     119,   120,   121,   121,   121,   121,   122,   123,   124,   124,
     124,   124,   125,   125,   127,   126,   128,   128,   128,   129,
     129,   129,   129,   130,   130,   130,   130,   130,   131,   131,
     132,   132,   133,   133,   134,   134,   135,   135,   136,   136,
     136,   136,   136,   136,   136,   136,   137,   137,   138,   138,
     139,   139,   139,   140,   140,   140,   140,   140,   141,   141,
     141,   142,   142,   142,   142,   142,   142,   142,   143,   143,
     143,   143,   144,   144,   144,   144,   145,   145,   145,   145,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   146,   147,   147,   148,   148,   148,   148,
     148,   148,   149,   149,   150,   151,   151,   152,   152,   152,
     153,   153,   153,   153,   153,   153,   153,   153,   153,   153,
     153,   153,   153,   153,   154,   154,   154,   154,   155,   155,
     156,   157,   157,   158,   159,   159,   160,   161,   161,   162,
     162,   163,   164,   165,   166,   167,   167,   168,   169,   169,
     170,   171,   172,   172,   172,   173,   173,   175,   174,   176,
     176,   177,   177,   177,   177,   179,   178,   178,   180,   180,
     180,   180,   181,   181,   183,   182,   184,   182,   185,   182,
     186,   182,   187,   187,   188,   188,   188,   188,   189,   189,
     190,   190,   191,   191,   192,   192,   193,   193,   194,   194,
     194,   194,   195,   195,   195,   195,   195,   195,   195,   195,
     196,   196,   197,   197,   198,   198,   199,   199,   199,   199,
     200,   200,   201,   201,   202,   202,   202,   202,   202,   203,
     203,   204,   204,   205,   205,   206,   206,   207,   207,   208,
     208,   209,   209,   210,   210,   210,   212,   211,   211
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     2,     1,
       2,     3,     1,     3,     1,     2,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     3,     2,     4,     1,     1,
       1,     1,     1,     3,     0,     6,     0,     2,     2,    11,
      10,     9,     8,    10,     9,     8,     7,     1,     3,     5,
       1,     3,     1,     2,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     3,     3,     1,     2,
       2,     2,     1,     2,     2,     3,     1,     1,     1,     1,
       4,     4,     6,     6,     3,     4,     3,     3,     4,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     5,     6,     7,     3,     4,     4,     5,     4,     5,
       4,     5,     1,     2,     3,     2,     3,     0,     1,     3,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     6,     5,     7,     1,     2,
       4,     0,     2,     5,     1,     2,     3,     0,     2,     1,
       3,     4,     8,     8,     8,     0,     1,     3,     0,     1,
       3,     3,     5,     4,     3,     1,     2,     0,     5,     3,
       2,     7,     9,     5,     7,     0,     4,     2,     1,     3,
       3,     5,     3,     0,     0,     9,     0,    10,     0,     8,
       0,     9,     1,     2,     1,     1,     1,     1,     1,     1,
       0,     2,     1,     3,     1,     2,     1,     1,     1,     2,
       1,     2,     9,     8,    10,     9,     7,     6,     8,     7,
       0,     2,     0,     2,     1,     3,     7,     6,     8,     7,
       1,     1,     0,     2,     6,     6,     6,     7,     7,    10,
       9,     5,     6,     1,     3,     5,     4,     0,     1,     0,
       1,     0,     1,     0,     2,     2,     0,     5,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       4,     0,     0,   277,     2,     6,     9,     7,    14,    12,
       0,     0,     1,   119,   120,   121,   122,   108,   109,     0,
       0,   185,   188,   188,   125,     0,   147,     0,     0,   123,
     124,     0,     0,     0,     0,   127,   128,     0,     0,     0,
       0,     0,   279,   163,     0,     0,   278,     3,    57,    17,
       0,    64,    66,    76,    78,    80,    83,    88,    91,    98,
     102,   106,   126,   107,    19,   151,     0,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,    18,    20,
      21,    22,     0,     0,     8,    10,     5,    15,     0,    11,
       0,     0,   172,   108,     0,     0,   186,     0,   189,     0,
       0,     0,   148,     0,    99,   102,   101,   100,   283,     0,
     200,     0,    31,    23,    24,    25,    26,    27,    28,    29,
      30,     0,     0,     0,     0,     0,     0,    31,    30,    38,
      40,   281,    39,    41,     0,     0,   280,     0,     0,     0,
       0,     0,   150,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      68,     0,    69,    70,    73,    74,    75,   103,   104,     0,
       0,    71,    72,     0,     0,     0,     0,   185,     0,   228,
     229,   260,   261,   225,   226,   227,     0,   222,     0,   224,
      44,    13,    16,     0,     0,     0,   187,   190,   191,   117,
     134,     0,   288,     0,     0,   286,   197,     0,   194,   195,
     199,     0,     0,     0,     0,     0,   281,   142,   281,   281,
     250,     0,     0,     0,     0,     0,   282,    36,     0,     0,
       0,   250,     0,     0,     0,   250,    65,    77,    79,    81,
      82,    84,    85,    86,    87,    89,    90,    92,    93,    94,
      95,    96,    97,   116,     0,    60,   114,    31,   105,     0,
      67,     0,     0,   205,     0,     0,     0,   223,     0,   213,
       0,   111,     0,   164,   147,   177,   174,   135,   149,   284,
     285,   171,     0,   193,     0,   196,   130,     0,    42,     0,
       0,   129,     0,     0,   143,   281,   136,   281,   138,   281,
     140,     0,     0,   250,     0,     0,   273,     0,    33,     0,
      32,    34,    35,   276,   250,     0,   277,   250,   250,   250,
       0,   115,     0,   118,   110,     0,   181,   207,   171,     0,
     185,     0,   213,     0,   230,    46,     0,     0,     0,   166,
     168,   148,     0,     0,     0,   175,   173,   171,    62,     0,
     192,   131,     0,    37,     0,   144,   145,     0,   137,   139,
     141,     0,   251,     0,     0,     0,     0,   203,   271,     0,
     275,     0,     0,     0,   250,     0,   250,     0,     0,   252,
      61,     0,   171,     0,     0,     0,   230,   208,     0,     0,
       0,   277,   112,   165,     0,     0,   169,     0,   176,   178,
     287,    63,     0,    43,   132,     0,   146,    58,     0,     0,
       0,     0,   274,   272,     0,     0,     0,     0,     0,     0,
     252,   252,     0,     0,   113,   206,     0,   185,     0,     0,
       0,     0,   212,   232,   231,   214,    45,    47,    48,     0,
     167,   149,   198,   133,     0,     0,   252,   204,     0,   252,
       0,   201,     0,     0,   252,     0,     0,   254,   253,    56,
       0,     0,     0,   216,    31,   210,   209,     0,     0,     0,
     170,    59,   252,     0,   252,     0,     0,     0,   252,     0,
      52,    55,     0,   183,   182,   184,     0,     0,     0,   233,
       0,     0,     0,     0,     0,     0,     0,     0,   234,   236,
     238,   240,   237,   219,     0,   270,     0,    54,   202,   252,
       0,    51,   255,     0,   221,   211,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   239,   241,   215,
     235,   269,    53,     0,    50,   217,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    49,   252,     0,
     262,     0,     0,     0,   262,     0,     0,     0,   252,     0,
     262,     0,     0,   252,     0,     0,     0,   262,     0,     0,
       0,   252,     0,     0,     0,   252,     0,     0,   252,     0,
     262,   257,     0,   263,   266,     0,   252,     0,   264,     0,
     252,     0,     0,     0,   252,   247,     0,   265,     0,   256,
     268,     0,   252,   259,     0,   252,     0,   249,     0,   246,
     267,   243,     0,   258,     0,   252,   248,   242,   245,     0,
     244
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,     6,    10,     7,     8,    47,   129,
     130,   131,   132,   133,   134,   289,    84,   270,   391,    48,
      49,   303,   254,   347,    50,    51,   173,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,   216,
     217,   295,   103,   348,    65,   339,   340,    66,    67,   275,
     276,   346,   343,    68,    69,    70,    71,    97,    72,    99,
      73,    74,    75,   208,   209,   282,    76,    77,   264,   328,
     388,   334,    78,   468,   486,   469,   487,   496,   187,   188,
     390,   434,   497,   498,   499,   500,   304,   423,   458,   501,
     189,   566,   502,    79,    80,   307,    81,    82,   137,   227,
     205,   109,   281
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -462
static const yytype_int16 yypact[] =
{
      88,    41,    41,   474,   -73,    88,  -462,   -36,  -462,  -462,
     -29,    15,  -462,  -462,  -462,  -462,  -462,   206,  -462,   937,
     937,   937,    70,    70,  -462,   937,   937,   937,   937,  -462,
    -462,   937,   -56,   352,    26,  -462,  -462,   127,   131,   171,
     175,   188,   115,  -462,   101,   201,  -462,  -462,  -462,  -462,
     -18,  -462,   118,   219,   154,   270,   248,   375,  -462,  -462,
     244,   205,  -462,  -462,  -462,  -462,   309,  -462,  -462,  -462,
    -462,  -462,  -462,  -462,  -462,  -462,  -462,  -462,  -462,  -462,
    -462,  -462,   291,   227,  -462,  -462,   -36,  -462,   266,  -462,
     173,   937,  -462,   242,    27,   -10,   254,   177,  -462,   198,
     214,    51,  -462,    12,  -462,   128,  -462,  -462,   100,   287,
    -462,    -8,    11,  -462,  -462,  -462,  -462,  -462,  -462,  -462,
     271,   278,   278,   278,   295,   235,   296,   145,  -462,   305,
    -462,   232,   317,   321,   347,   340,  -462,   358,   374,   378,
     364,   937,  -462,   937,   937,   937,   937,   937,   937,   937,
     937,   937,   937,   937,   937,   937,   937,   937,   937,   821,
    -462,   390,  -462,  -462,  -462,  -462,  -462,  -462,  -462,   439,
     439,  -462,  -462,   937,   937,   937,   386,   937,   393,  -462,
    -462,  -462,  -462,  -462,  -462,  -462,   291,  -462,   417,  -462,
    -462,  -462,  -462,   361,   -56,   414,  -462,  -462,  -462,  -462,
    -462,   873,  -462,   331,   336,  -462,  -462,   386,   299,  -462,
    -462,   833,   439,   431,   423,   937,    -7,  -462,    -7,    -7,
      30,   439,   441,   421,   937,   424,  -462,  -462,   425,   426,
     353,    30,   362,   432,   453,    30,  -462,   219,   154,   270,
     270,   248,   248,   248,   248,   375,   375,  -462,  -462,  -462,
    -462,  -462,  -462,  -462,   185,  -462,  -462,   108,  -462,   387,
    -462,   409,    14,   458,   470,   459,   480,  -462,   491,   461,
     403,  -462,   937,   385,   937,   392,  -462,  -462,  -462,  -462,
    -462,   769,   439,  -462,   -56,  -462,  -462,   193,  -462,    54,
     479,  -462,    45,   885,  -462,    -1,  -462,    -1,  -462,    -1,
    -462,   410,   402,   481,   489,    22,  -462,   149,  -462,    18,
    -462,  -462,  -462,  -462,   481,   490,   412,    30,    30,   481,
     494,  -462,   937,  -462,  -462,   937,  -462,  -462,   769,   492,
     937,   497,   461,   512,   499,  -462,   220,   -56,   937,   399,
    -462,   422,   505,   -56,   -56,  -462,  -462,   577,  -462,   514,
    -462,  -462,   439,  -462,   925,  -462,  -462,   511,  -462,  -462,
    -462,   439,  -462,     9,   498,   446,   937,  -462,  -462,    39,
    -462,   517,   449,   439,   481,   520,   481,   526,   529,   495,
    -462,   286,   673,   937,   527,   937,   499,   524,   111,   548,
     463,    44,  -462,  -462,    28,   -56,  -462,   937,  -462,  -462,
    -462,  -462,   -56,  -462,  -462,   195,  -462,  -462,   465,   468,
     439,    31,  -462,  -462,   475,   439,    35,   544,   477,   551,
     495,   495,   569,   -56,  -462,  -462,   196,   937,   199,   493,
     570,   571,  -462,  -462,   556,   496,  -462,  -462,  -462,   -56,
    -462,   503,  -462,  -462,   439,   439,   495,  -462,   439,   495,
     937,  -462,   500,   439,   495,   510,   -56,  -462,   557,  -462,
     513,   -56,   386,   515,  -462,  -462,   560,   585,   552,   516,
    -462,  -462,   495,   518,   495,   -56,    32,   439,   495,   519,
    -462,  -462,   588,  -462,  -462,  -462,   552,   523,   570,  -462,
     602,   178,   607,   616,   -14,   628,    46,   452,  -462,  -462,
    -462,  -462,  -462,  -462,   538,  -462,   -56,  -462,  -462,   495,
     541,  -462,  -462,   525,  -462,  -462,   617,   549,   200,   621,
     553,   639,   642,   646,   631,   561,   649,  -462,  -462,  -462,
    -462,  -462,  -462,   559,  -462,  -462,    23,   439,   564,    50,
     439,   636,   640,   641,    59,   439,   568,  -462,   495,   204,
     633,   439,   572,   207,   633,    63,   130,   133,   495,   237,
     633,   439,   -56,   495,   661,   937,   573,   633,   439,   575,
     574,   495,   239,   576,   262,   495,   264,   -56,   495,   586,
     633,  -462,   -56,   254,  -462,   589,   495,   439,  -462,   590,
     495,   439,   592,   591,   495,  -462,   -56,  -462,   593,  -462,
    -462,   -56,   495,  -462,   599,   495,   439,  -462,   603,  -462,
    -462,  -462,   -56,  -462,   604,   495,  -462,  -462,  -462,   605,
    -462
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -462,  -462,  -462,  -462,   678,   688,   695,    25,  -462,   670,
     -31,  -462,  -462,   671,  -161,  -462,  -462,  -462,  -462,   316,
    -462,  -216,  -193,   380,   -19,    -9,  -462,  -462,   563,   565,
     269,   186,   281,    13,  -462,   315,  -462,  -462,  -462,   319,
     164,   225,   436,     4,  -462,  -462,   372,  -462,  -462,  -462,
     437,  -462,  -462,  -462,  -462,  -462,  -462,  -165,  -462,   690,
    -462,  -462,  -462,  -462,   506,  -462,  -462,  -462,  -196,  -462,
    -462,   384,   326,  -462,  -462,  -462,  -462,   -78,  -181,   532,
     333,  -462,   234,  -461,  -462,   230,  -200,  -365,  -462,   231,
    -462,  -381,  -462,  -462,  -462,  -462,  -462,   405,  -462,  -191,
    -462,  -184,  -462
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -221
static const yytype_int16 yytable[] =
{
      94,    95,    96,   122,   186,   267,   101,    64,   258,   259,
     273,   283,   265,   141,   111,   314,   408,   102,   287,   319,
     293,   141,    90,   141,    88,   296,   357,   298,   300,    83,
     301,   315,    87,   112,   211,   320,   530,   301,   200,     2,
     104,   106,   108,   201,   107,   141,   412,   548,     9,   141,
     212,   288,   530,   525,   366,   455,   456,   301,   141,   141,
     305,   302,   141,   141,   213,   413,   301,   450,    88,    89,
     301,   521,   193,   355,   552,   199,   141,    98,   326,   522,
     142,   473,   141,   558,   475,   352,   523,   571,   195,   479,
     210,   353,   113,   114,   115,   116,   117,   118,   119,   226,
     350,   374,   376,   364,   358,   226,   359,   504,   360,   506,
     362,    87,   108,   510,   371,   120,   370,   375,   377,   378,
     367,   349,   194,   439,   181,   182,   183,   184,   185,   447,
     508,   490,   236,   451,   124,   223,   526,   301,   125,   492,
     301,   436,   431,    44,   533,   494,   495,   212,   432,    46,
     255,   159,   143,   393,   573,   261,   262,   575,    96,   398,
     399,   405,     1,     2,   260,   384,   247,   248,   249,   250,
     251,   252,   223,   570,   417,   368,   419,   224,   126,   579,
     369,   161,   127,   562,   212,   517,   585,   167,   168,   145,
     146,   403,   278,   577,   138,   135,   292,   202,   582,   598,
     407,   139,   255,   203,   204,   309,   589,   538,   140,   321,
     593,   440,   416,   596,   169,   170,   322,   351,   442,   443,
     460,   601,   136,   462,   322,   604,   322,   141,   563,   608,
     141,   569,   174,    91,   190,   564,    92,   612,   564,   459,
     614,   113,   114,   115,   116,   117,   118,   119,   392,   446,
     619,   141,   144,   336,   449,   470,   181,   182,   183,   184,
     185,   578,   461,   590,   128,   341,   485,   159,   564,    91,
     564,   192,   481,   191,   292,   196,   160,   484,   181,   182,
     183,   184,   185,   471,   472,   141,   592,   474,   594,   151,
     152,   507,   478,   564,   214,   564,   197,   161,   162,   163,
     164,   165,   166,   167,   168,   215,   381,   147,   148,   149,
     150,    96,   198,   380,   424,   267,   509,   141,   220,   394,
     549,   222,   532,   553,   175,   176,   177,   178,   559,   221,
     169,   170,   225,   241,   242,   243,   244,   267,   226,   572,
     574,   576,   105,   105,   228,   255,   105,   411,   229,   206,
     207,   401,   171,   172,   230,    13,    14,    15,    16,    93,
      18,   206,   284,   231,   426,   232,   428,   179,   180,   181,
     182,   183,   184,   185,    24,    25,   550,    26,   581,   554,
     294,   233,   294,   294,   560,   234,   401,   235,   441,   271,
     567,   272,   141,   595,    27,   337,   338,   256,   599,   465,
     580,    28,    29,    30,    31,   274,   344,   586,    96,   395,
     338,   263,   609,   518,   239,   240,   266,   611,   153,   154,
     155,   156,   157,   158,   269,    34,   602,   274,   617,   279,
     605,   476,   245,   246,   280,    35,    36,   324,   290,   325,
     141,   218,   219,   297,   299,   615,   257,   291,   306,   308,
     110,   313,   310,   311,   312,   317,   316,   515,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,    12,   323,   318,    13,    14,    15,
      16,    17,    18,    19,   327,   329,    20,   331,   330,  -171,
    -171,  -171,  -171,    21,    22,    23,    24,    25,   332,    26,
     333,   335,   354,   362,   361,   113,   114,   115,   116,   117,
     118,   119,   363,   365,   372,   383,    27,    46,   379,   387,
    -179,   402,   409,    28,    29,    30,    31,   385,   128,   389,
     181,   182,   183,   184,   185,    32,   397,   490,    33,   406,
     410,   414,   491,   415,   418,   492,   583,    34,   493,   529,
     420,   494,   495,   421,   430,   433,   427,    35,    36,   444,
     422,   435,   445,    37,    38,    39,    40,    41,   452,   448,
      42,   453,    43,    44,    45,   454,   457,   464,   466,    46,
      13,    14,    15,    16,    17,    18,    19,   467,   482,    20,
     488,   463,   489,  -218,   477,   512,    21,    22,    23,    24,
      25,  -180,    26,   181,   182,   183,   184,   185,   480,   516,
     490,   483,  -220,   503,   519,   491,   505,   511,   492,    27,
     514,   493,   535,   520,   494,   495,    28,    29,    30,    31,
     181,   182,   183,   184,   185,   524,   531,   490,    32,   534,
     536,    33,   491,   537,   539,   492,   541,   540,   493,   542,
      34,   494,   495,   543,   544,   545,   546,   547,   551,   555,
      35,    36,   561,   556,   557,   565,   568,    38,   408,   587,
     591,   584,   588,    42,   400,    43,    13,    14,    15,    16,
      17,    18,    19,    85,   597,    20,   606,   600,   603,   607,
      11,   610,    21,    22,    23,    24,    25,   613,    26,   425,
      86,   616,   618,   620,   121,   123,   237,   437,   382,   238,
     342,   396,   345,   100,   285,    27,   386,   438,   268,   429,
     513,   373,    28,    29,    30,    31,   527,   528,     0,     0,
       0,     0,     0,     0,    32,     0,     0,    33,     0,     0,
       0,     0,     0,     0,     0,     0,    34,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    35,    36,     0,     0,
       0,     0,     0,    38,     0,     0,     0,     0,     0,    42,
       0,    43,    13,    14,    15,    16,    17,    18,    19,     0,
       0,    20,     0,     0,     0,     0,     0,     0,    21,    22,
      23,    24,    25,     0,    26,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    27,     0,     0,     0,     0,     0,     0,    28,    29,
      30,    31,     0,     0,    13,    14,    15,    16,    93,    18,
      32,     0,     0,    33,     0,     0,    13,    14,    15,    16,
      93,    18,    34,    24,    25,   253,    26,     0,     0,     0,
       0,     0,    35,    36,     0,    24,    25,   286,    26,    38,
       0,     0,     0,    27,     0,    42,     0,    43,     0,     0,
      28,    29,    30,    31,     0,    27,    13,    14,    15,    16,
      93,    18,    28,    29,    30,    31,     0,     0,    13,    14,
      15,    16,    93,    18,    34,    24,    25,     0,    26,   277,
       0,     0,     0,     0,    35,    36,    34,    24,    25,     0,
      26,     0,     0,   356,     0,    27,    35,    36,     0,     0,
       0,     0,    28,    29,    30,    31,     0,    27,    13,    14,
      15,    16,    93,    18,    28,    29,    30,    31,     0,     0,
      13,    14,    15,    16,    93,    18,    34,    24,    25,   404,
      26,     0,     0,     0,     0,     0,    35,    36,    34,    24,
      25,     0,    26,     0,     0,     0,     0,    27,    35,    36,
       0,     0,     0,     0,    28,    29,    30,    31,     0,    27,
       0,     0,     0,     0,     0,     0,    28,    29,    30,    31,
       0,     0,     0,     0,     0,     0,     0,     0,    34,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    35,    36,
      34,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      35,    36
};

static const yytype_int16 yycheck[] =
{
      19,    20,    21,    34,    82,   186,    25,     3,   169,   170,
     194,   207,   177,    31,    33,   231,     7,    26,   211,   235,
      27,    31,     7,    31,    53,   216,    27,   218,   219,   102,
       7,   231,     7,     7,    23,   235,   497,     7,    26,    75,
      27,    28,    98,    31,    31,    31,     7,    24,     7,    31,
      39,   212,   513,     7,    32,   420,   421,     7,    31,    31,
     221,    31,    31,    31,    53,    26,     7,    32,    53,    98,
       7,    85,    91,    28,    24,    24,    31,     7,   262,    93,
      98,   446,    31,    24,   449,    31,   100,    24,    98,   454,
      98,    37,    66,    67,    68,    69,    70,    71,    72,   106,
     284,   317,   318,   303,   295,   106,   297,   472,   299,   474,
     101,    86,    98,   478,   314,    89,    98,   317,   318,   319,
      98,   282,    95,    95,    78,    79,    80,    81,    82,    98,
      98,    85,   141,    98,     7,    27,    90,     7,     7,    93,
       7,    97,    31,    99,   509,    99,   100,    39,    37,   105,
     159,    23,    34,   337,    24,   174,   175,    24,   177,   343,
     344,   354,    74,    75,   173,   330,   153,   154,   155,   156,
     157,   158,    27,   554,   374,    26,   376,    32,     7,   560,
      31,    53,     7,   548,    39,     7,   567,    59,    60,    35,
      36,   352,   201,   558,    93,     7,   215,    97,   563,   580,
     361,   100,   211,   103,   104,   224,   571,     7,     7,    24,
     575,   395,   373,   578,    86,    87,    31,    24,   402,    24,
      24,   586,   107,    24,    31,   590,    31,    31,    24,   594,
      31,    24,    27,    27,     7,    31,    30,   602,    31,   423,
     605,    66,    67,    68,    69,    70,    71,    72,    28,   410,
     615,    31,    33,   272,   415,   439,    78,    79,    80,    81,
      82,    24,   427,    24,    89,   274,   462,    23,    31,    27,
      31,    98,   456,     7,   293,    98,    32,   461,    78,    79,
      80,    81,    82,   444,   445,    31,    24,   448,    24,    41,
      42,   475,   453,    31,    23,    31,    98,    53,    54,    55,
      56,    57,    58,    59,    60,    27,   325,    37,    38,    39,
      40,   330,    98,   322,    28,   496,   477,    31,    23,   338,
     536,    25,   506,   539,    15,    16,    17,    18,   544,    94,
      86,    87,    27,   147,   148,   149,   150,   518,   106,   555,
     556,   557,    27,    28,    27,   354,    31,   366,    27,    62,
      63,   347,   108,   109,     7,     3,     4,     5,     6,     7,
       8,    62,    63,    23,   383,     7,   385,    76,    77,    78,
      79,    80,    81,    82,    22,    23,   537,    25,   562,   540,
     216,     7,   218,   219,   545,     7,   382,    23,   397,    28,
     551,    30,    31,   577,    42,    10,    11,     7,   582,   430,
     561,    49,    50,    51,    52,    13,    14,   568,   427,    10,
      11,    25,   596,   491,   145,   146,    23,   601,    43,    44,
      45,    46,    47,    48,     7,    73,   587,    13,   612,    98,
     591,   450,   151,   152,    98,    83,    84,    28,     7,    30,
      31,   122,   123,   218,   219,   606,     7,    24,     7,    28,
      98,    98,    28,    28,    28,    23,    94,   488,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,     0,    88,    23,     3,     4,     5,
       6,     7,     8,     9,    26,    15,    12,     7,    29,    15,
      16,    17,    18,    19,    20,    21,    22,    23,     7,    25,
      39,    98,    23,   101,    94,    66,    67,    68,    69,    70,
      71,    72,    31,    24,    24,    23,    42,   105,    24,     7,
      98,     7,    24,    49,    50,    51,    52,    30,    89,    30,
      78,    79,    80,    81,    82,    61,    31,    85,    64,    28,
      94,    24,    90,    94,    24,    93,   565,    73,    96,    97,
      24,    99,   100,    24,    30,     7,    29,    83,    84,    94,
      65,    98,    94,    89,    90,    91,    92,    93,    24,    94,
      96,    94,    98,    99,   100,    24,     7,     7,     7,   105,
       3,     4,     5,     6,     7,     8,     9,    31,    31,    12,
      30,    98,     7,    97,    94,     7,    19,    20,    21,    22,
      23,    98,    25,    78,    79,    80,    81,    82,    98,     7,
      85,    98,    97,    97,     7,    90,    98,    98,    93,    42,
      97,    96,    97,     7,    99,   100,    49,    50,    51,    52,
      78,    79,    80,    81,    82,     7,    98,    85,    61,    98,
      23,    64,    90,    94,    23,    93,     7,    94,    96,     7,
      73,    99,   100,     7,    23,    94,     7,    98,    94,    23,
      83,    84,    94,    23,    23,    32,    94,    90,     7,    94,
      94,    98,    98,    96,    97,    98,     3,     4,     5,     6,
       7,     8,     9,     5,    98,    12,    94,    98,    98,    98,
       2,    98,    19,    20,    21,    22,    23,    98,    25,    26,
       5,    98,    98,    98,    34,    34,   143,   391,   328,   144,
     274,   339,   275,    23,   208,    42,   332,   391,   186,   386,
     486,   316,    49,    50,    51,    52,   496,   496,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    -1,    -1,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    83,    84,    -1,    -1,
      -1,    -1,    -1,    90,    -1,    -1,    -1,    -1,    -1,    96,
      -1,    98,     3,     4,     5,     6,     7,     8,     9,    -1,
      -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,
      21,    22,    23,    -1,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,
      51,    52,    -1,    -1,     3,     4,     5,     6,     7,     8,
      61,    -1,    -1,    64,    -1,    -1,     3,     4,     5,     6,
       7,     8,    73,    22,    23,    24,    25,    -1,    -1,    -1,
      -1,    -1,    83,    84,    -1,    22,    23,    24,    25,    90,
      -1,    -1,    -1,    42,    -1,    96,    -1,    98,    -1,    -1,
      49,    50,    51,    52,    -1,    42,     3,     4,     5,     6,
       7,     8,    49,    50,    51,    52,    -1,    -1,     3,     4,
       5,     6,     7,     8,    73,    22,    23,    -1,    25,    26,
      -1,    -1,    -1,    -1,    83,    84,    73,    22,    23,    -1,
      25,    -1,    -1,    28,    -1,    42,    83,    84,    -1,    -1,
      -1,    -1,    49,    50,    51,    52,    -1,    42,     3,     4,
       5,     6,     7,     8,    49,    50,    51,    52,    -1,    -1,
       3,     4,     5,     6,     7,     8,    73,    22,    23,    24,
      25,    -1,    -1,    -1,    -1,    -1,    83,    84,    73,    22,
      23,    -1,    25,    -1,    -1,    -1,    -1,    42,    83,    84,
      -1,    -1,    -1,    -1,    49,    50,    51,    52,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,    84,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      83,    84
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    74,    75,   111,   112,   113,   114,   116,   117,     7,
     115,   115,     0,     3,     4,     5,     6,     7,     8,     9,
      12,    19,    20,    21,    22,    23,    25,    42,    49,    50,
      51,    52,    61,    64,    73,    83,    84,    89,    90,    91,
      92,    93,    96,    98,    99,   100,   105,   118,   129,   130,
     134,   135,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   153,   154,   157,   158,   163,   164,
     165,   166,   168,   170,   171,   172,   176,   177,   182,   203,
     204,   206,   207,   102,   126,   114,   116,   117,    53,    98,
       7,    27,    30,     7,   134,   134,   134,   167,     7,   169,
     169,   134,   135,   152,   143,   145,   143,   143,    98,   211,
      98,   134,     7,    66,    67,    68,    69,    70,    71,    72,
      89,   119,   120,   123,     7,     7,     7,     7,    89,   119,
     120,   121,   122,   123,   124,     7,   107,   208,    93,   100,
       7,    31,    98,    34,    33,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    23,
      32,    53,    54,    55,    56,    57,    58,    59,    60,    86,
      87,   108,   109,   136,    27,    15,    16,    17,    18,    76,
      77,    78,    79,    80,    81,    82,   187,   188,   189,   200,
       7,     7,    98,   134,    95,    98,    98,    98,    98,    24,
      26,    31,    97,   103,   104,   210,    62,    63,   173,   174,
      98,    23,    39,    53,    23,    27,   149,   150,   149,   149,
      23,    94,    25,    27,    32,    27,   106,   209,    27,    27,
       7,    23,     7,     7,     7,    23,   135,   138,   139,   140,
     140,   141,   141,   141,   141,   142,   142,   143,   143,   143,
     143,   143,   143,    24,   132,   135,     7,     7,   124,   124,
     135,   134,   134,    25,   178,   167,    23,   188,   189,     7,
     127,    28,    30,   211,    13,   159,   160,    26,   135,    98,
      98,   212,   175,   178,    63,   174,    24,   132,   124,   125,
       7,    24,   134,    27,   150,   151,   209,   151,   209,   151,
     209,     7,    31,   131,   196,   124,     7,   205,    28,   134,
      28,    28,    28,    98,   131,   196,    94,    23,    23,   131,
     196,    24,    31,    88,    28,    30,   211,    26,   179,    15,
      29,     7,     7,    39,   181,    98,   134,    10,    11,   155,
     156,   135,   152,   162,    14,   160,   161,   133,   153,   124,
     211,    24,    31,    37,    23,    28,    28,    27,   209,   209,
     209,    94,   101,    31,   196,    24,    32,    98,    26,    31,
      98,   196,    24,   207,   131,   196,   131,   196,   196,    24,
     135,   134,   133,    23,   167,    30,   181,     7,   180,    30,
     190,   128,    28,   211,   134,    10,   156,    31,   211,   211,
      97,   153,     7,   124,    24,   132,    28,   124,     7,    24,
      94,   134,     7,    26,    24,    94,   124,   196,    24,   196,
      24,    24,    65,   197,    28,    26,   134,    29,   134,   190,
      30,    31,    37,     7,   191,    98,    97,   129,   182,    95,
     211,   135,   211,    24,    94,    94,   124,    98,    94,   124,
      32,    98,    24,    94,    24,   197,   197,     7,   198,   211,
      24,   167,    24,    98,     7,   120,     7,    31,   183,   185,
     211,   124,   124,   197,   124,   197,   134,    94,   124,   197,
      98,   211,    31,    98,   211,   178,   184,   186,    30,     7,
      85,    90,    93,    96,    99,   100,   187,   192,   193,   194,
     195,   199,   202,    97,   197,    98,   197,   211,    98,   124,
     197,    98,     7,   192,    97,   120,     7,     7,   187,     7,
       7,    85,    93,   100,     7,     7,    90,   195,   199,    97,
     193,    98,   211,   197,    98,    97,    23,    94,     7,    23,
      94,     7,     7,     7,    23,    94,     7,    98,    24,   131,
     124,    94,    24,   131,   124,    23,    23,    23,    24,   131,
     124,    94,   197,    24,    31,    32,   201,   124,    94,    24,
     201,    24,   131,    24,   131,    24,   131,   197,    24,   201,
     124,   211,   197,   134,    98,   201,   124,    94,    98,   197,
      24,    94,    24,   197,    24,   211,   197,    98,   201,   211,
      98,   197,   124,    98,   197,   124,    94,    98,   197,   211,
      98,   211,   197,    98,   197,   124,    98,   211,    98,   197,
      98
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
#line 111 "diksam.y"
    {
            dkc_set_require_and_rename_list(NULL, NULL);
        }
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 115 "diksam.y"
    {
            dkc_set_require_and_rename_list((yyvsp[(1) - (2)].require_list), (yyvsp[(2) - (2)].rename_list));
        }
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 119 "diksam.y"
    {
            dkc_set_require_and_rename_list((yyvsp[(1) - (1)].require_list), NULL);
        }
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 123 "diksam.y"
    {
            dkc_set_require_and_rename_list(NULL, (yyvsp[(1) - (1)].rename_list));
        }
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 127 "diksam.y"
    {
            //dkc_set_require_and_rename_list(NULL, NULL);
		}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 134 "diksam.y"
    {
            (yyval.require_list) = dkc_chain_require_list((yyvsp[(1) - (2)].require_list), (yyvsp[(2) - (2)].require_list));
        }
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 140 "diksam.y"
    {
            (yyval.require_list) = dkc_create_require_list((yyvsp[(2) - (3)].package_name));
        }
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 146 "diksam.y"
    {
            (yyval.package_name) = dkc_create_package_name((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 150 "diksam.y"
    {
            (yyval.package_name) = dkc_chain_package_name((yyvsp[(1) - (3)].package_name), (yyvsp[(3) - (3)].identifier));
        }
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 157 "diksam.y"
    {
            (yyval.rename_list) = dkc_chain_rename_list((yyvsp[(1) - (2)].rename_list), (yyvsp[(2) - (2)].rename_list));
        }
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 163 "diksam.y"
    {
            (yyval.rename_list) = dkc_create_rename_list((yyvsp[(2) - (4)].package_name), (yyvsp[(3) - (4)].identifier));
        }
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 171 "diksam.y"
    {
            DKC_Compiler *compiler = dkc_get_current_compiler();

            compiler->statement_list
                = dkc_chain_statement_list(compiler->statement_list, (yyvsp[(1) - (1)].statement));
        }
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 183 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_VOID_TYPE;
        }
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 187 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_BOOLEAN_TYPE;
        }
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 191 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_INT_TYPE;
        }
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 195 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_DOUBLE_TYPE;
        }
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 199 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_STRING_TYPE;
        }
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 203 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_VARIENT_TYPE;
        }
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 207 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_NATIVE_POINTER_TYPE;
        }
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 211 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_DELEGATE_TYPE;
        }
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 217 "diksam.y"
    {
            (yyval.type_specifier) = dkc_create_identifier_type_specifier((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 223 "diksam.y"
    {
            TypeSpecifier *basic_type
                = dkc_create_type_specifier((yyvsp[(1) - (3)].basic_type_specifier));
            (yyval.type_specifier) = dkc_create_array_type_specifier(basic_type,0);
        }
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 229 "diksam.y"
    {
            TypeSpecifier *identifier_type
                = dkc_create_identifier_type_specifier((yyvsp[(1) - (3)].identifier));
            (yyval.type_specifier) = dkc_create_array_type_specifier(identifier_type,0);
        }
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 235 "diksam.y"
    {
            (yyval.type_specifier) = dkc_create_array_type_specifier((yyvsp[(1) - (3)].type_specifier),0);
        }
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 239 "diksam.y"
    {
			(yyval.type_specifier) = dkc_create_array_type_specifier((yyvsp[(1) - (3)].type_specifier),0);
		}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 245 "diksam.y"
    {
			if((yyvsp[(2) - (2)].intval)==1)
			{
				TypeDerive *derive_p;
				for (derive_p = (yyvsp[(1) - (2)].type_specifier)->derive; derive_p != NULL;
					derive_p = derive_p->next)
				{
					derive_p->u.array_d.is_global=1;
				}
			}
			(yyval.type_specifier)=(yyvsp[(1) - (2)].type_specifier);
		}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 259 "diksam.y"
    {//fix-me : shift/reduce
			(yyval.type_specifier)= dkc_create_template_type_specifier((yyvsp[(1) - (4)].identifier),(yyvsp[(3) - (4)].template));
		}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 265 "diksam.y"
    {
                    (yyval.type_specifier) = dkc_create_type_specifier((yyvsp[(1) - (1)].basic_type_specifier));
        }
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 275 "diksam.y"
    {
			(yyval.template)=dkc_create_template_list((yyvsp[(1) - (1)].type_specifier));
		}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 279 "diksam.y"
    {
            (yyval.template) = dkc_chain_template_list((yyvsp[(1) - (3)].template), (yyvsp[(3) - (3)].type_specifier));
        }
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 286 "diksam.y"
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

  case 45:

/* Line 1455 of yacc.c  */
#line 296 "diksam.y"
    {
			BcGetCurrentCompilerContext()->isLib=0;
		}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 308 "diksam.y"
    {
            dkc_function_define((yyvsp[(9) - (11)].type_specifier), (yyvsp[(3) - (11)].identifier), (yyvsp[(5) - (11)].parameter_list), (yyvsp[(10) - (11)].exception_list), NULL,(yyvsp[(6) - (11)].intval));
        }
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 312 "diksam.y"
    {
            dkc_function_define((yyvsp[(8) - (10)].type_specifier), (yyvsp[(3) - (10)].identifier), NULL, (yyvsp[(9) - (10)].exception_list), NULL,(yyvsp[(5) - (10)].intval));
        }
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 316 "diksam.y"
    {
            dkc_function_define(0, (yyvsp[(3) - (9)].identifier), (yyvsp[(5) - (9)].parameter_list), (yyvsp[(8) - (9)].exception_list), NULL,(yyvsp[(6) - (9)].intval));
        }
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 320 "diksam.y"
    {
			//printf("lib:%s\n",BcGetCurrentCompilerContext()->libname);
            dkc_function_define(0, (yyvsp[(3) - (8)].identifier), NULL, (yyvsp[(7) - (8)].exception_list), NULL,(yyvsp[(5) - (8)].intval));
        }
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 327 "diksam.y"
    {
            dkc_function_define((yyvsp[(8) - (10)].type_specifier), (yyvsp[(2) - (10)].identifier), (yyvsp[(4) - (10)].parameter_list), (yyvsp[(9) - (10)].exception_list), (yyvsp[(10) - (10)].block),(yyvsp[(5) - (10)].intval));
        }
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 331 "diksam.y"
    {
            dkc_function_define((yyvsp[(7) - (9)].type_specifier), (yyvsp[(2) - (9)].identifier), NULL, (yyvsp[(8) - (9)].exception_list), (yyvsp[(9) - (9)].block),(yyvsp[(4) - (9)].intval));
        }
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 335 "diksam.y"
    { //modified
            dkc_function_define(0, (yyvsp[(2) - (8)].identifier), (yyvsp[(4) - (8)].parameter_list), (yyvsp[(7) - (8)].exception_list), (yyvsp[(8) - (8)].block),(yyvsp[(5) - (8)].intval));
        }
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 339 "diksam.y"
    {
            dkc_function_define(0, (yyvsp[(2) - (7)].identifier), NULL, (yyvsp[(6) - (7)].exception_list), (yyvsp[(7) - (7)].block),(yyvsp[(4) - (7)].intval));
        }
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 346 "diksam.y"
    {
            (yyval.parameter_list) = dkc_create_parameter((yyvsp[(3) - (3)].type_specifier), (yyvsp[(1) - (3)].identifier));
        }
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 350 "diksam.y"
    {
            (yyval.parameter_list) = dkc_chain_parameter((yyvsp[(1) - (5)].parameter_list), (yyvsp[(5) - (5)].type_specifier), (yyvsp[(3) - (5)].identifier));
        }
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 356 "diksam.y"
    {
            (yyval.argument_list) = dkc_create_argument_list((yyvsp[(1) - (1)].expression));
        }
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 360 "diksam.y"
    {
            (yyval.argument_list) = dkc_chain_argument_list((yyvsp[(1) - (3)].argument_list), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 366 "diksam.y"
    {
            (yyval.statement_list) = dkc_create_statement_list((yyvsp[(1) - (1)].statement));
        }
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 370 "diksam.y"
    {
            (yyval.statement_list) = dkc_chain_statement_list((yyvsp[(1) - (2)].statement_list), (yyvsp[(2) - (2)].statement));
        }
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 377 "diksam.y"
    {
            (yyval.expression) = dkc_create_comma_expression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 384 "diksam.y"
    {
            (yyval.expression) = dkc_create_assign_expression((yyvsp[(1) - (3)].expression), (yyvsp[(2) - (3)].assignment_operator), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 390 "diksam.y"
    {
            (yyval.assignment_operator) = NORMAL_ASSIGN;
        }
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 394 "diksam.y"
    {
            (yyval.assignment_operator) = ADD_ASSIGN;
        }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 398 "diksam.y"
    {
            (yyval.assignment_operator) = SUB_ASSIGN;
        }
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 402 "diksam.y"
    {
            (yyval.assignment_operator) = ATM_ADD_ASSIGN;
        }
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 406 "diksam.y"
    {
            (yyval.assignment_operator) = ATM_SUB_ASSIGN;
        }
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 410 "diksam.y"
    {
            (yyval.assignment_operator) = MUL_ASSIGN;
        }
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 414 "diksam.y"
    {
            (yyval.assignment_operator) = DIV_ASSIGN;
        }
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 418 "diksam.y"
    {
            (yyval.assignment_operator) = MOD_ASSIGN;
        }
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 425 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(LOGICAL_OR_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 432 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(LOGICAL_AND_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 439 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(EQ_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 443 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(NE_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 450 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(GT_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 454 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(GE_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 458 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(LT_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 462 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(LE_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 469 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(ADD_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 473 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(SUB_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 480 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(MUL_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 484 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(DIV_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 488 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(MOD_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 492 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(BIT_AND_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 496 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(BIT_OR_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 500 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(BIT_XOR_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 507 "diksam.y"
    {
            (yyval.expression) = dkc_create_minus_expression((yyvsp[(2) - (2)].expression));
        }
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 511 "diksam.y"
    {
            (yyval.expression) = dkc_create_logical_not_expression((yyvsp[(2) - (2)].expression));
        }
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 515 "diksam.y"
    {
            (yyval.expression) = dkc_create_bit_not_expression((yyvsp[(2) - (2)].expression));
        }
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 522 "diksam.y"
    {
            (yyval.expression) = dkc_create_incdec_expression((yyvsp[(1) - (2)].expression), INCREMENT_EXPRESSION);
        }
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 526 "diksam.y"
    {
            (yyval.expression) = dkc_create_incdec_expression((yyvsp[(1) - (2)].expression), DECREMENT_EXPRESSION);
        }
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 530 "diksam.y"
    {
            (yyval.expression) = dkc_create_instanceof_expression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].type_specifier));
        }
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 538 "diksam.y"
    {
            (yyval.expression) = dkc_create_identifier_expression((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 542 "diksam.y"
    {
			(yyval.expression)=BcCreateAutoExpression((yyvsp[(1) - (1)].identifier));
		}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 548 "diksam.y"
    {
            (yyval.expression) = dkc_create_index_expression((yyvsp[(1) - (4)].expression), (yyvsp[(3) - (4)].expression));
        }
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 552 "diksam.y"
    {
            Expression *identifier = dkc_create_identifier_expression((yyvsp[(1) - (4)].identifier));
            (yyval.expression) = dkc_create_index_expression(identifier, (yyvsp[(3) - (4)].expression));
        }
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 557 "diksam.y"
    {
			Expression *identifier = dkc_create_identifier_expression((yyvsp[(1) - (6)].identifier));
			(yyval.expression) = dkc_create_slice_expression(identifier,(yyvsp[(3) - (6)].expression),(yyvsp[(5) - (6)].expression));
		}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 562 "diksam.y"
    {
			(yyval.expression) = dkc_create_slice_expression((yyvsp[(1) - (6)].expression),(yyvsp[(3) - (6)].expression),(yyvsp[(5) - (6)].expression));
		}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 566 "diksam.y"
    {
            (yyval.expression) = dkc_create_member_expression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].identifier));
        }
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 570 "diksam.y"
    {
            (yyval.expression) = dkc_create_function_call_expression((yyvsp[(1) - (4)].expression), (yyvsp[(3) - (4)].argument_list));
        }
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 574 "diksam.y"
    {
            (yyval.expression) = dkc_create_function_call_expression((yyvsp[(1) - (3)].expression), NULL);
        }
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 578 "diksam.y"
    {
            (yyval.expression) = (yyvsp[(2) - (3)].expression);
        }
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 582 "diksam.y"
    {
            (yyval.expression) = dkc_create_down_cast_expression((yyvsp[(1) - (4)].expression), (yyvsp[(3) - (4)].type_specifier));
        }
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 590 "diksam.y"
    {
            (yyval.expression) = dkc_create_boolean_expression(DVM_TRUE);
        }
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 594 "diksam.y"
    {
            (yyval.expression) = dkc_create_boolean_expression(DVM_FALSE);
        }
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 598 "diksam.y"
    {
            (yyval.expression) = dkc_create_null_expression();
        }
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 603 "diksam.y"
    {
            (yyval.expression) = dkc_create_this_expression();
        }
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 607 "diksam.y"
    {
            (yyval.expression) = dkc_create_super_expression();
        }
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 611 "diksam.y"
    {
			(yyval.expression) = dkc_create_new_delegate_expression();
		}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 615 "diksam.y"
    {
            (yyval.expression) = dkc_create_new_expression((yyvsp[(2) - (4)].identifier), NULL, NULL);
        }
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 619 "diksam.y"
    {
            (yyval.expression) = dkc_create_new_expression((yyvsp[(2) - (5)].identifier), NULL, (yyvsp[(4) - (5)].argument_list));
        }
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 623 "diksam.y"
    {
            (yyval.expression) = dkc_create_new_expression((yyvsp[(2) - (6)].identifier), (yyvsp[(4) - (6)].identifier), NULL);
        }
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 627 "diksam.y"
    {
            (yyval.expression) = dkc_create_new_expression((yyvsp[(2) - (7)].identifier), (yyvsp[(4) - (7)].identifier), (yyvsp[(6) - (7)].argument_list));
        }
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 633 "diksam.y"
    {
            (yyval.expression) = dkc_create_array_literal_expression((yyvsp[(2) - (3)].expression_list));
        }
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 637 "diksam.y"
    {
            (yyval.expression) = dkc_create_array_literal_expression((yyvsp[(2) - (4)].expression_list));
        }
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 643 "diksam.y"
    {
            (yyval.expression) = dkc_create_basic_array_creation((yyvsp[(2) - (4)].basic_type_specifier), (yyvsp[(3) - (4)].array_dimension), NULL,(yyvsp[(4) - (4)].intval));
        }
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 647 "diksam.y"
    {
            (yyval.expression) = dkc_create_basic_array_creation((yyvsp[(2) - (5)].basic_type_specifier), (yyvsp[(3) - (5)].array_dimension), (yyvsp[(4) - (5)].array_dimension),(yyvsp[(5) - (5)].intval));
        }
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 651 "diksam.y"
    {
            (yyval.expression) = dkc_create_class_array_creation((yyvsp[(2) - (4)].type_specifier), (yyvsp[(3) - (4)].array_dimension), NULL,(yyvsp[(4) - (4)].intval));
        }
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 656 "diksam.y"
    {
            (yyval.expression) = dkc_create_class_array_creation((yyvsp[(2) - (5)].type_specifier), (yyvsp[(3) - (5)].array_dimension), (yyvsp[(4) - (5)].array_dimension),(yyvsp[(5) - (5)].intval));
        }
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 660 "diksam.y"
    {
            (yyval.expression) = dkc_create_class_array_creation((yyvsp[(2) - (4)].type_specifier), (yyvsp[(3) - (4)].array_dimension), NULL,(yyvsp[(4) - (4)].intval));
        }
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 664 "diksam.y"
    {
            (yyval.expression) = dkc_create_class_array_creation((yyvsp[(2) - (5)].type_specifier), (yyvsp[(3) - (5)].array_dimension), (yyvsp[(4) - (5)].array_dimension),(yyvsp[(5) - (5)].intval));
        }
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 671 "diksam.y"
    {
            (yyval.array_dimension) = dkc_chain_array_dimension((yyvsp[(1) - (2)].array_dimension), (yyvsp[(2) - (2)].array_dimension));
        }
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 677 "diksam.y"
    {
            (yyval.array_dimension) = dkc_create_array_dimension((yyvsp[(2) - (3)].expression));
        }
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 683 "diksam.y"
    {
            (yyval.array_dimension) = dkc_create_array_dimension(NULL);
        }
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 687 "diksam.y"
    {
            (yyval.array_dimension) = dkc_chain_array_dimension((yyvsp[(1) - (3)].array_dimension),
                                           dkc_create_array_dimension(NULL));
        }
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 694 "diksam.y"
    {
            (yyval.expression_list) = NULL;
        }
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 698 "diksam.y"
    {
            (yyval.expression_list) = dkc_create_expression_list((yyvsp[(1) - (1)].expression));
        }
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 702 "diksam.y"
    {
            (yyval.expression_list) = dkc_chain_expression_list((yyvsp[(1) - (3)].expression_list), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 708 "diksam.y"
    {
          (yyval.statement) = dkc_create_expression_statement((yyvsp[(1) - (2)].expression));
        }
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 724 "diksam.y"
    {/*empty line*/
			(yyval.statement)=0;
		}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 730 "diksam.y"
    {
            (yyval.statement) = dkc_create_if_statement((yyvsp[(2) - (4)].expression), (yyvsp[(4) - (4)].block), NULL, NULL);
        }
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 734 "diksam.y"
    {
			//printf("IF-ELSE %d\n",dkc_get_current_compiler()->current_line_number);
            (yyval.statement) = dkc_create_if_statement((yyvsp[(2) - (6)].expression), (yyvsp[(4) - (6)].block), NULL, (yyvsp[(6) - (6)].block));
        }
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 739 "diksam.y"
    {
            (yyval.statement) = dkc_create_if_statement((yyvsp[(2) - (5)].expression), (yyvsp[(4) - (5)].block), (yyvsp[(5) - (5)].elsif), NULL);
        }
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 743 "diksam.y"
    {
            (yyval.statement) = dkc_create_if_statement((yyvsp[(2) - (7)].expression), (yyvsp[(4) - (7)].block), (yyvsp[(5) - (7)].elsif), (yyvsp[(7) - (7)].block));
        }
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 750 "diksam.y"
    {
            (yyval.elsif) = dkc_chain_elsif_list((yyvsp[(1) - (2)].elsif), (yyvsp[(2) - (2)].elsif));
        }
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 756 "diksam.y"
    {
            (yyval.elsif) = dkc_create_elsif((yyvsp[(2) - (4)].expression), (yyvsp[(4) - (4)].block));
        }
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 762 "diksam.y"
    {
            (yyval.identifier) = NULL;
        }
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 766 "diksam.y"
    {
            (yyval.identifier) = (yyvsp[(1) - (2)].identifier);
        }
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 772 "diksam.y"
    {
            (yyval.statement) = dkc_create_switch_statement((yyvsp[(2) - (5)].expression), (yyvsp[(4) - (5)].case_list), (yyvsp[(5) - (5)].block));
        }
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 779 "diksam.y"
    {
            (yyval.case_list) = dkc_chain_case((yyvsp[(1) - (2)].case_list), (yyvsp[(2) - (2)].case_list));
        }
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 785 "diksam.y"
    {
            (yyval.case_list) = dkc_create_one_case((yyvsp[(2) - (3)].expression_list), (yyvsp[(3) - (3)].block));
        }
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 791 "diksam.y"
    {
            (yyval.block) = NULL;
        }
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 795 "diksam.y"
    {
            (yyval.block) = (yyvsp[(2) - (2)].block);
        }
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 801 "diksam.y"
    {
            (yyval.expression_list) = dkc_create_expression_list((yyvsp[(1) - (1)].expression));
        }
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 805 "diksam.y"
    {
            (yyval.expression_list) = dkc_chain_expression_list((yyvsp[(1) - (3)].expression_list), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 811 "diksam.y"
    {
            (yyval.statement) = dkc_create_while_statement((yyvsp[(1) - (4)].identifier), (yyvsp[(3) - (4)].expression), (yyvsp[(4) - (4)].block));
        }
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 817 "diksam.y"
    {
            (yyval.statement) = dkc_create_for_statement((yyvsp[(1) - (8)].identifier), (yyvsp[(3) - (8)].expression), (yyvsp[(5) - (8)].expression), (yyvsp[(7) - (8)].expression), (yyvsp[(8) - (8)].block));
        }
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 823 "diksam.y"
    {
            (yyval.statement) = dkc_create_do_while_statement((yyvsp[(1) - (8)].identifier), (yyvsp[(3) - (8)].block), (yyvsp[(6) - (8)].expression));
        }
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 829 "diksam.y"
    {
            (yyval.statement) = dkc_create_foreach_statement((yyvsp[(1) - (8)].identifier), (yyvsp[(4) - (8)].identifier), (yyvsp[(6) - (8)].expression), (yyvsp[(8) - (8)].block));
        }
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 835 "diksam.y"
    {
            (yyval.expression) = NULL;
        }
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 842 "diksam.y"
    {
            (yyval.statement) = dkc_create_return_statement((yyvsp[(2) - (3)].expression));
        }
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 848 "diksam.y"
    {
            (yyval.identifier) = NULL;
        }
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 855 "diksam.y"
    {
            (yyval.statement) = dkc_create_break_statement((yyvsp[(2) - (3)].identifier));
        }
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 861 "diksam.y"
    {
            (yyval.statement) = dkc_create_continue_statement((yyvsp[(2) - (3)].identifier));
        }
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 867 "diksam.y"
    {
            (yyval.statement) = dkc_create_try_statement((yyvsp[(2) - (5)].block), (yyvsp[(3) - (5)].catch_clause), (yyvsp[(5) - (5)].block));
        }
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 871 "diksam.y"
    {
            (yyval.statement) = dkc_create_try_statement((yyvsp[(2) - (4)].block), NULL, (yyvsp[(4) - (4)].block));
        }
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 875 "diksam.y"
    {
            (yyval.statement) = dkc_create_try_statement((yyvsp[(2) - (3)].block), (yyvsp[(3) - (3)].catch_clause), NULL);
        }
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 882 "diksam.y"
    {
            (yyval.catch_clause) = dkc_chain_catch_list((yyvsp[(1) - (2)].catch_clause), (yyvsp[(2) - (2)].catch_clause));
        }
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 888 "diksam.y"
    {
            (yyval.catch_clause) = dkc_start_catch_clause();
        }
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 892 "diksam.y"
    {
            (yyval.catch_clause) = dkc_end_catch_clause((yyvsp[(2) - (5)].catch_clause), (yyvsp[(3) - (5)].type_specifier), (yyvsp[(4) - (5)].identifier), (yyvsp[(5) - (5)].block));
        }
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 898 "diksam.y"
    {
            (yyval.statement) = dkc_create_throw_statement((yyvsp[(2) - (3)].expression));
        }
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 902 "diksam.y"
    {
            (yyval.statement) = dkc_create_throw_statement(NULL);
        }
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 908 "diksam.y"
    {
            (yyval.statement) = dkc_create_declaration_statement(DVM_FALSE, (yyvsp[(6) - (7)].type_specifier), (yyvsp[(3) - (7)].identifier), NULL,(yyvsp[(5) - (7)].intval),(yyvsp[(2) - (7)].intval));
        }
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 912 "diksam.y"
    {
            (yyval.statement) = dkc_create_declaration_statement(DVM_FALSE, (yyvsp[(6) - (9)].type_specifier), (yyvsp[(3) - (9)].identifier), (yyvsp[(8) - (9)].expression),(yyvsp[(5) - (9)].intval),(yyvsp[(2) - (9)].intval));
        }
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 916 "diksam.y"
    {
            (yyval.statement) = dkc_create_declaration_statement(DVM_FALSE, (yyvsp[(4) - (5)].type_specifier), (yyvsp[(2) - (5)].identifier), NULL,DVM_FALSE,DVM_FALSE);
        }
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 920 "diksam.y"
    {
            (yyval.statement) = dkc_create_declaration_statement(DVM_TRUE, (yyvsp[(4) - (7)].type_specifier), (yyvsp[(2) - (7)].identifier), (yyvsp[(6) - (7)].expression),DVM_FALSE,DVM_FALSE);
        }
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 926 "diksam.y"
    {
            (yyval.block) = dkc_open_block(0);
        }
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 930 "diksam.y"
    {
            (yyval.block) = dkc_close_block((yyvsp[(2) - (4)].block), (yyvsp[(3) - (4)].statement_list));
        }
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 934 "diksam.y"
    {
            Block *empty_block = dkc_open_block(0);
            (yyval.block) = dkc_close_block(empty_block, NULL);
        }
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 941 "diksam.y"
    {
            (yyval.template_def) = dkc_create_template_declare_list((yyvsp[(1) - (1)].identifier),NULL);
        }
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 945 "diksam.y"
    {
            (yyval.template_def) = dkc_chain_template_declare_list((yyvsp[(1) - (3)].template_def), (yyvsp[(3) - (3)].identifier),NULL);
        }
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 949 "diksam.y"
    {
            (yyval.template_def) = dkc_create_template_declare_list((yyvsp[(1) - (3)].identifier),(yyvsp[(3) - (3)].type_specifier));
        }
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 953 "diksam.y"
    {
            (yyval.template_def) = dkc_chain_template_declare_list((yyvsp[(1) - (5)].template_def), (yyvsp[(3) - (5)].identifier) ,(yyvsp[(5) - (5)].type_specifier));
        }
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 959 "diksam.y"
    {
			(yyval.template_def)=(yyvsp[(2) - (3)].template_def);
		}
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 963 "diksam.y"
    {(yyval.template_def)=NULL;}
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 968 "diksam.y"
    {
            dkc_start_class_definition((yyvsp[(1) - (6)].intval),NULL, (yyvsp[(2) - (6)].class_or_interface), (yyvsp[(3) - (6)].identifier),(yyvsp[(4) - (6)].template_def), (yyvsp[(5) - (6)].extends_list));
        }
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 972 "diksam.y"
    {
            dkc_class_define((yyvsp[(8) - (9)].member_declaration));
        }
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 977 "diksam.y"
    {
            dkc_start_class_definition((yyvsp[(1) - (7)].intval),&(yyvsp[(2) - (7)].class_or_member_modifier), (yyvsp[(3) - (7)].class_or_interface), (yyvsp[(4) - (7)].identifier),(yyvsp[(5) - (7)].template_def), (yyvsp[(6) - (7)].extends_list));
        }
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 980 "diksam.y"
    {
            dkc_class_define((yyvsp[(9) - (10)].member_declaration));
        }
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 984 "diksam.y"
    {
            dkc_start_class_definition((yyvsp[(1) - (6)].intval),NULL, (yyvsp[(2) - (6)].class_or_interface), (yyvsp[(3) - (6)].identifier),(yyvsp[(4) - (6)].template_def), (yyvsp[(5) - (6)].extends_list));
        }
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 988 "diksam.y"
    {
            dkc_class_define(NULL);
        }
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 993 "diksam.y"
    {
            dkc_start_class_definition((yyvsp[(1) - (7)].intval),&(yyvsp[(2) - (7)].class_or_member_modifier), (yyvsp[(3) - (7)].class_or_interface), (yyvsp[(4) - (7)].identifier),(yyvsp[(5) - (7)].template_def), (yyvsp[(6) - (7)].extends_list));
        }
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 997 "diksam.y"
    {
            dkc_class_define(NULL);
        }
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 1004 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_chain_class_or_member_modifier((yyvsp[(1) - (2)].class_or_member_modifier), (yyvsp[(2) - (2)].class_or_member_modifier));
        }
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 1011 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(VIRTUAL_MODIFIER);
        }
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 1015 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(OVERRIDE_MODIFIER);
        }
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 1019 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(ABSTRACT_MODIFIER);
        }
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 1025 "diksam.y"
    {
            (yyval.class_or_interface) = DVM_CLASS_DEFINITION;
        }
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 1029 "diksam.y"
    {
            (yyval.class_or_interface) = DVM_INTERFACE_DEFINITION;
        }
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 1035 "diksam.y"
    {
            (yyval.extends_list) = NULL;
        }
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 1039 "diksam.y"
    {
            (yyval.extends_list) = (yyvsp[(2) - (2)].extends_list);
        }
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 1045 "diksam.y"
    {
            (yyval.extends_list) = dkc_create_extends_list((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 1049 "diksam.y"
    {
            (yyval.extends_list) = dkc_chain_extends_list((yyvsp[(1) - (3)].extends_list), (yyvsp[(3) - (3)].identifier));
        }
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 1056 "diksam.y"
    {
            (yyval.member_declaration) = dkc_chain_member_declaration((yyvsp[(1) - (2)].member_declaration), (yyvsp[(2) - (2)].member_declaration));
        }
    break;

  case 238:

/* Line 1455 of yacc.c  */
#line 1066 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_method_member(NULL, (yyvsp[(1) - (1)].function_definition), DVM_FALSE);
        }
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 1070 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_method_member(&(yyvsp[(1) - (2)].class_or_member_modifier), (yyvsp[(2) - (2)].function_definition), DVM_FALSE);
        }
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 1074 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_method_member(NULL, (yyvsp[(1) - (1)].function_definition), DVM_TRUE);
        }
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 1078 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_method_member(&(yyvsp[(1) - (2)].class_or_member_modifier), (yyvsp[(2) - (2)].function_definition), DVM_TRUE);
        }
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 1084 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define((yyvsp[(7) - (9)].type_specifier), (yyvsp[(2) - (9)].identifier), (yyvsp[(4) - (9)].parameter_list), (yyvsp[(8) - (9)].exception_list), (yyvsp[(9) - (9)].block));
        }
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 1088 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define((yyvsp[(6) - (8)].type_specifier), (yyvsp[(2) - (8)].identifier), NULL, (yyvsp[(7) - (8)].exception_list), (yyvsp[(8) - (8)].block));
        }
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 1092 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define((yyvsp[(8) - (10)].type_specifier), (yyvsp[(3) - (10)].identifier), (yyvsp[(5) - (10)].parameter_list), (yyvsp[(9) - (10)].exception_list), NULL);
        }
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 1096 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define((yyvsp[(7) - (9)].type_specifier), (yyvsp[(3) - (9)].identifier), NULL, (yyvsp[(8) - (9)].exception_list), NULL);
        }
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 1100 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define(0, (yyvsp[(2) - (7)].identifier), (yyvsp[(4) - (7)].parameter_list), (yyvsp[(6) - (7)].exception_list), (yyvsp[(7) - (7)].block));
        }
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 1104 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define(0, (yyvsp[(2) - (6)].identifier), NULL, (yyvsp[(5) - (6)].exception_list), (yyvsp[(6) - (6)].block));
        }
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 1108 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define(0, (yyvsp[(3) - (8)].identifier), (yyvsp[(5) - (8)].parameter_list), (yyvsp[(7) - (8)].exception_list), NULL);
        }
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 1112 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define(0, (yyvsp[(3) - (7)].identifier), NULL, (yyvsp[(6) - (7)].exception_list), NULL);
        }
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 1118 "diksam.y"
    {
			(yyval.intval)=0;
		}
    break;

  case 251:

/* Line 1455 of yacc.c  */
#line 1122 "diksam.y"
    {
			(yyval.intval)=1;
		}
    break;

  case 252:

/* Line 1455 of yacc.c  */
#line 1128 "diksam.y"
    {
            (yyval.exception_list) = NULL;
        }
    break;

  case 253:

/* Line 1455 of yacc.c  */
#line 1132 "diksam.y"
    {
            (yyval.exception_list) = (yyvsp[(2) - (2)].exception_list);
        }
    break;

  case 254:

/* Line 1455 of yacc.c  */
#line 1138 "diksam.y"
    {
            (yyval.exception_list) = dkc_create_throws((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 255:

/* Line 1455 of yacc.c  */
#line 1142 "diksam.y"
    {
            (yyval.exception_list) = dkc_chain_exception_list((yyvsp[(1) - (3)].exception_list), (yyvsp[(3) - (3)].identifier));
        }
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 1148 "diksam.y"
    {
            (yyval.function_definition) = dkc_constructor_function_define((yyvsp[(2) - (7)].identifier), (yyvsp[(4) - (7)].parameter_list), (yyvsp[(6) - (7)].exception_list), (yyvsp[(7) - (7)].block));
        }
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 1152 "diksam.y"
    {
            (yyval.function_definition) = dkc_constructor_function_define((yyvsp[(2) - (6)].identifier), NULL, (yyvsp[(5) - (6)].exception_list), (yyvsp[(6) - (6)].block));
        }
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 1156 "diksam.y"
    {
            (yyval.function_definition) = dkc_constructor_function_define((yyvsp[(3) - (8)].identifier), (yyvsp[(5) - (8)].parameter_list), (yyvsp[(7) - (8)].exception_list), NULL);
        }
    break;

  case 259:

/* Line 1455 of yacc.c  */
#line 1160 "diksam.y"
    {
            (yyval.function_definition) = dkc_constructor_function_define((yyvsp[(3) - (7)].identifier), NULL, (yyvsp[(6) - (7)].exception_list), NULL);
        }
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 1166 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(PUBLIC_MODIFIER);
        }
    break;

  case 261:

/* Line 1455 of yacc.c  */
#line 1170 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(PRIVATE_MODIFIER);
        }
    break;

  case 262:

/* Line 1455 of yacc.c  */
#line 1176 "diksam.y"
    {
            (yyval.expression) = NULL;
        }
    break;

  case 263:

/* Line 1455 of yacc.c  */
#line 1180 "diksam.y"
    {
            (yyval.expression) = (yyvsp[(2) - (2)].expression);
        }
    break;

  case 264:

/* Line 1455 of yacc.c  */
#line 1186 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(NULL, DVM_FALSE, (yyvsp[(4) - (6)].type_specifier), (yyvsp[(2) - (6)].identifier), (yyvsp[(5) - (6)].expression));
        }
    break;

  case 265:

/* Line 1455 of yacc.c  */
#line 1191 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(&(yyvsp[(1) - (6)].class_or_member_modifier), DVM_FALSE, (yyvsp[(4) - (6)].type_specifier), (yyvsp[(2) - (6)].identifier), (yyvsp[(5) - (6)].expression));
        }
    break;

  case 266:

/* Line 1455 of yacc.c  */
#line 1195 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(NULL, DVM_TRUE, (yyvsp[(4) - (6)].type_specifier), (yyvsp[(2) - (6)].identifier), (yyvsp[(5) - (6)].expression));
        }
    break;

  case 267:

/* Line 1455 of yacc.c  */
#line 1200 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(&(yyvsp[(1) - (7)].class_or_member_modifier), DVM_TRUE, (yyvsp[(5) - (7)].type_specifier), (yyvsp[(3) - (7)].identifier), (yyvsp[(6) - (7)].expression));
        }
    break;

  case 268:

/* Line 1455 of yacc.c  */
#line 1204 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(&(yyvsp[(2) - (7)].class_or_member_modifier), DVM_TRUE, (yyvsp[(5) - (7)].type_specifier), (yyvsp[(3) - (7)].identifier), (yyvsp[(6) - (7)].expression));
        }
    break;

  case 269:

/* Line 1455 of yacc.c  */
#line 1210 "diksam.y"
    {
            dkc_create_delegate_definition((yyvsp[(8) - (10)].type_specifier), (yyvsp[(2) - (10)].identifier), (yyvsp[(4) - (10)].parameter_list), (yyvsp[(9) - (10)].exception_list),(yyvsp[(5) - (10)].intval));
        }
    break;

  case 270:

/* Line 1455 of yacc.c  */
#line 1214 "diksam.y"
    {
            dkc_create_delegate_definition((yyvsp[(7) - (9)].type_specifier), (yyvsp[(2) - (9)].identifier), NULL, (yyvsp[(8) - (9)].exception_list),(yyvsp[(4) - (9)].intval));
        }
    break;

  case 271:

/* Line 1455 of yacc.c  */
#line 1220 "diksam.y"
    {
            dkc_create_enum_definition((yyvsp[(2) - (5)].identifier), (yyvsp[(4) - (5)].enumerator));
        }
    break;

  case 272:

/* Line 1455 of yacc.c  */
#line 1224 "diksam.y"
    {
            dkc_create_enum_definition((yyvsp[(2) - (6)].identifier), (yyvsp[(4) - (6)].enumerator));
        }
    break;

  case 273:

/* Line 1455 of yacc.c  */
#line 1230 "diksam.y"
    {
            (yyval.enumerator) = dkc_create_enumerator((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 274:

/* Line 1455 of yacc.c  */
#line 1234 "diksam.y"
    {
            (yyval.enumerator) = dkc_chain_enumerator((yyvsp[(1) - (3)].enumerator), (yyvsp[(3) - (3)].identifier));
        }
    break;

  case 275:

/* Line 1455 of yacc.c  */
#line 1240 "diksam.y"
    {
            dkc_create_const_definition(NULL, (yyvsp[(2) - (5)].identifier), (yyvsp[(4) - (5)].expression));
        }
    break;

  case 276:

/* Line 1455 of yacc.c  */
#line 1244 "diksam.y"
    {
            dkc_create_const_definition((yyvsp[(2) - (4)].type_specifier), (yyvsp[(3) - (4)].identifier), NULL);
        }
    break;

  case 277:

/* Line 1455 of yacc.c  */
#line 1250 "diksam.y"
    {
			(yyval.intval)=0;
		}
    break;

  case 278:

/* Line 1455 of yacc.c  */
#line 1254 "diksam.y"
    {
			(yyval.intval)=1;
		}
    break;

  case 279:

/* Line 1455 of yacc.c  */
#line 1260 "diksam.y"
    {
			(yyval.intval)=0;
		}
    break;

  case 280:

/* Line 1455 of yacc.c  */
#line 1264 "diksam.y"
    {
			(yyval.intval)=1;
		}
    break;

  case 281:

/* Line 1455 of yacc.c  */
#line 1270 "diksam.y"
    {
			(yyval.intval)=0;
		}
    break;

  case 282:

/* Line 1455 of yacc.c  */
#line 1274 "diksam.y"
    {
			(yyval.intval)=1;
		}
    break;

  case 283:

/* Line 1455 of yacc.c  */
#line 1280 "diksam.y"
    {
			(yyval.intval)=0;
		}
    break;

  case 284:

/* Line 1455 of yacc.c  */
#line 1284 "diksam.y"
    {
			(yyval.intval)=1;
		}
    break;

  case 285:

/* Line 1455 of yacc.c  */
#line 1288 "diksam.y"
    {
			(yyval.intval)=-1;
		}
    break;

  case 286:

/* Line 1455 of yacc.c  */
#line 1294 "diksam.y"
    {
            (yyval.block) = dkc_open_block((yyvsp[(2) - (2)].intval));
			//printf("E1 %d\n",dkc_get_current_compiler());
        }
    break;

  case 287:

/* Line 1455 of yacc.c  */
#line 1299 "diksam.y"
    {
            (yyval.block) = dkc_close_block((yyvsp[(3) - (5)].block), (yyvsp[(4) - (5)].statement_list));
			//printf("C1 %d\n",dkc_get_current_compiler()->current_line_number);
        }
    break;

  case 288:

/* Line 1455 of yacc.c  */
#line 1304 "diksam.y"
    {
            Block *empty_block = dkc_open_block(0);
            (yyval.block) = dkc_close_block(empty_block, NULL);
			//printf("C2 %d\n",dkc_get_current_compiler()->current_line_number);
        }
    break;



/* Line 1455 of yacc.c  */
#line 4362 "y.tab.c"
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
#line 1310 "diksam.y"


