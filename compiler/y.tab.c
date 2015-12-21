
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
     ATM_ADD_ASSIGN_T = 362,
     ATM_SUB_ASSIGN_T = 363
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
#define ATM_ADD_ASSIGN_T 362
#define ATM_SUB_ASSIGN_T 363




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
#line 365 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 377 "y.tab.c"

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
#define YYLAST   1056

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  109
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  102
/* YYNRULES -- Number of rules.  */
#define YYNRULES  284
/* YYNRULES -- Number of states.  */
#define YYNSTATES  613

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   363

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
     105,   106,   107,   108
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
     365,   370,   375,   379,   384,   388,   392,   397,   399,   401,
     403,   405,   407,   409,   411,   413,   415,   417,   422,   427,
     433,   440,   448,   452,   457,   462,   468,   473,   479,   484,
     490,   492,   495,   499,   502,   506,   507,   509,   513,   516,
     518,   520,   522,   524,   526,   528,   530,   532,   534,   536,
     538,   540,   542,   547,   554,   560,   568,   570,   573,   578,
     579,   582,   588,   590,   593,   597,   598,   601,   603,   607,
     612,   621,   630,   639,   640,   642,   646,   647,   649,   653,
     657,   663,   668,   672,   674,   677,   678,   684,   688,   691,
     698,   707,   713,   721,   722,   727,   730,   732,   736,   740,
     746,   750,   751,   752,   762,   763,   774,   775,   784,   785,
     795,   797,   800,   802,   804,   806,   808,   810,   812,   813,
     816,   818,   822,   824,   827,   829,   831,   833,   836,   838,
     841,   851,   860,   871,   881,   889,   896,   905,   913,   914,
     917,   918,   921,   923,   927,   935,   942,   951,   959,   961,
     963,   964,   967,   974,   981,   988,   996,  1004,  1015,  1025,
    1031,  1038,  1040,  1044,  1050,  1055,  1056,  1058,  1059,  1061,
    1062,  1065,  1068,  1069,  1075
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     110,     0,    -1,   111,    -1,   110,   117,    -1,    -1,   112,
     115,    -1,   112,    -1,   115,    -1,   111,   125,    -1,   113,
      -1,   112,   113,    -1,    74,   114,    98,    -1,     7,    -1,
     114,    53,     7,    -1,   116,    -1,   115,   116,    -1,    75,
     114,     7,    98,    -1,   129,    -1,   181,    -1,   152,    -1,
     202,    -1,   203,    -1,   205,    -1,    66,    -1,    67,    -1,
      68,    -1,    69,    -1,    70,    -1,    71,    -1,    72,    -1,
      89,    -1,     7,    -1,   118,    27,    28,    -1,     7,    27,
      28,    -1,   121,    27,    28,    -1,   122,    27,    28,    -1,
     120,   207,    -1,     7,    39,   124,    37,    -1,   118,    -1,
     121,    -1,   119,    -1,   122,    -1,   123,    -1,   124,    31,
     123,    -1,    -1,   102,     7,   126,    98,   127,    97,    -1,
      -1,   127,   128,    -1,   127,   181,    -1,    99,    93,     7,
      23,   130,   195,    24,    94,   123,   196,    98,    -1,    99,
      93,     7,    23,   195,    24,    94,   123,   196,    98,    -1,
      99,   100,     7,    23,   130,   195,    24,   196,    98,    -1,
      99,   100,     7,    23,   195,    24,   196,    98,    -1,    93,
       7,    23,   130,   195,    24,    94,   123,   196,   209,    -1,
      93,     7,    23,   195,    24,    94,   123,   196,   209,    -1,
     100,     7,    23,   130,   195,    24,   196,   209,    -1,   100,
       7,    23,   195,    24,   196,   209,    -1,   128,    -1,     7,
      94,   123,    -1,   130,    31,     7,    94,   123,    -1,   134,
      -1,   131,    31,   134,    -1,   152,    -1,   132,   152,    -1,
     134,    -1,   133,    31,   134,    -1,   136,    -1,   144,   135,
     134,    -1,    32,    -1,    54,    -1,    55,    -1,   107,    -1,
     108,    -1,    56,    -1,    57,    -1,    58,    -1,   137,    -1,
     136,    34,   137,    -1,   138,    -1,   137,    33,   138,    -1,
     139,    -1,   138,    35,   139,    -1,   138,    36,   139,    -1,
     140,    -1,   139,    37,   140,    -1,   139,    38,   140,    -1,
     139,    39,   140,    -1,   139,    40,   140,    -1,   141,    -1,
     140,    41,   141,    -1,   140,    42,   141,    -1,   142,    -1,
     141,    43,   142,    -1,   141,    44,   142,    -1,   141,    45,
     142,    -1,   141,    46,   142,    -1,   141,    47,   142,    -1,
     141,    48,   142,    -1,   143,    -1,    42,   142,    -1,    52,
     142,    -1,    49,   142,    -1,   144,    -1,   144,    59,    -1,
     144,    60,    -1,   144,    86,   123,    -1,   145,    -1,   147,
      -1,     7,    -1,     8,    -1,   145,    27,   133,    28,    -1,
       7,    27,   133,    28,    -1,   144,    53,     7,    -1,   144,
      23,   131,    24,    -1,   144,    23,    24,    -1,    23,   133,
      24,    -1,   144,    87,   123,    88,    -1,     3,    -1,     4,
      -1,     5,    -1,     6,    -1,    50,    -1,    51,    -1,    22,
      -1,   146,    -1,    83,    -1,    84,    -1,    73,    89,    23,
      24,    -1,    73,     7,    23,    24,    -1,    73,     7,    23,
     131,    24,    -1,    73,     7,    53,     7,    23,    24,    -1,
      73,     7,    53,     7,    23,   131,    24,    -1,    25,   151,
      26,    -1,    25,   151,    31,    26,    -1,    73,   118,   148,
     207,    -1,    73,   118,   148,   150,   207,    -1,    73,   119,
     148,   207,    -1,    73,   119,   148,   150,   207,    -1,    73,
     122,   148,   207,    -1,    73,   122,   148,   150,   207,    -1,
     149,    -1,   148,   149,    -1,    27,   133,    28,    -1,    27,
      28,    -1,   150,    27,    28,    -1,    -1,   134,    -1,   151,
      31,   134,    -1,   133,    98,    -1,   153,    -1,   157,    -1,
     162,    -1,   163,    -1,   164,    -1,   165,    -1,   167,    -1,
     169,    -1,   170,    -1,   171,    -1,   175,    -1,   176,    -1,
      98,    -1,     9,   133,    95,   209,    -1,     9,   133,    95,
     209,    10,   209,    -1,     9,   133,    95,   209,   154,    -1,
       9,   133,    95,   209,   154,    10,   209,    -1,   155,    -1,
     154,   155,    -1,    11,   133,    95,   209,    -1,    -1,     7,
      30,    -1,    12,   133,    98,   158,   160,    -1,   159,    -1,
     158,   159,    -1,    13,   161,   209,    -1,    -1,    14,   209,
      -1,   134,    -1,   151,    31,   134,    -1,   156,    15,   133,
     209,    -1,   156,    17,   166,    29,   166,    29,   166,   209,
      -1,   156,    16,   177,    15,    23,   133,    24,    98,    -1,
     156,    18,    23,     7,    30,   133,    24,   177,    -1,    -1,
     133,    -1,    19,   166,    98,    -1,    -1,     7,    -1,    20,
     168,    98,    -1,    21,   168,    98,    -1,    61,   209,   172,
      63,   209,    -1,    61,   209,    63,   177,    -1,    61,   209,
     172,    -1,   173,    -1,   172,   173,    -1,    -1,    62,   174,
     123,     7,   209,    -1,    64,   133,    98,    -1,    64,    98,
      -1,    96,     7,    94,   206,   123,    98,    -1,    96,     7,
      94,   206,   123,    32,   133,    98,    -1,    90,     7,    94,
     123,    98,    -1,    90,     7,    94,   123,    32,   133,    98,
      -1,    -1,    25,   178,   132,    26,    -1,    25,    26,    -1,
       7,    -1,   179,    31,     7,    -1,     7,    30,   119,    -1,
     179,    31,     7,    30,   119,    -1,    39,   179,    37,    -1,
      -1,    -1,   206,   188,     7,   180,   189,    98,   182,   191,
      97,    -1,    -1,   206,   186,   188,     7,   180,   189,    98,
     183,   191,    97,    -1,    -1,   206,   188,     7,   180,   189,
      98,   184,    97,    -1,    -1,   206,   186,   188,     7,   180,
     189,    98,   185,    97,    -1,   187,    -1,   186,   187,    -1,
     199,    -1,    80,    -1,    81,    -1,    82,    -1,    76,    -1,
      77,    -1,    -1,    30,   190,    -1,     7,    -1,   190,    31,
       7,    -1,   192,    -1,   191,   192,    -1,   193,    -1,   201,
      -1,   194,    -1,   186,   194,    -1,   198,    -1,   186,   198,
      -1,    93,     7,    23,   130,    24,    94,   123,   196,   209,
      -1,    93,     7,    23,    24,    94,   123,   196,   209,    -1,
      99,    93,     7,    23,   130,    24,    94,   123,   196,    98,
      -1,    99,    93,     7,    23,    24,    94,   123,   196,    98,
      -1,   100,     7,    23,   130,    24,   196,   209,    -1,   100,
       7,    23,    24,   196,   209,    -1,    99,   100,     7,    23,
     130,    24,   196,    98,    -1,    99,   100,     7,    23,    24,
     196,    98,    -1,    -1,    31,   101,    -1,    -1,    65,   197,
      -1,     7,    -1,   197,    31,     7,    -1,    85,     7,    23,
     130,    24,   196,   209,    -1,    85,     7,    23,    24,   196,
     209,    -1,    99,    85,     7,    23,   130,    24,   196,    98,
      -1,    99,    85,     7,    23,    24,   196,    98,    -1,    78,
      -1,    79,    -1,    -1,    32,   133,    -1,    96,     7,    94,
     123,   200,    98,    -1,   186,     7,    94,   123,   200,    98,
      -1,    90,     7,    94,   123,   200,    98,    -1,   186,    90,
       7,    94,   123,   200,    98,    -1,    90,   186,     7,    94,
     123,   200,    98,    -1,    89,     7,    23,   130,   195,    24,
      94,   123,   196,    98,    -1,    89,     7,    23,   195,    24,
      94,   123,   196,    98,    -1,    91,     7,    25,   204,    26,
      -1,    91,     7,    25,   204,    31,    26,    -1,     7,    -1,
     204,    31,     7,    -1,    92,     7,    32,   133,    98,    -1,
      92,   123,     7,    98,    -1,    -1,   105,    -1,    -1,   106,
      -1,    -1,   103,    98,    -1,   104,    98,    -1,    -1,    98,
     208,   210,   132,    97,    -1,    98,    97,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   105,   105,   106,   110,   113,   117,   121,   125,   131,
     132,   138,   144,   148,   154,   155,   161,   167,   168,   169,
     176,   177,   178,   181,   185,   189,   193,   197,   201,   205,
     209,   215,   221,   227,   233,   237,   243,   257,   263,   267,
     268,   269,   273,   277,   285,   284,   299,   302,   303,   306,
     310,   314,   318,   325,   329,   333,   337,   341,   344,   348,
     354,   358,   364,   368,   374,   375,   381,   382,   388,   392,
     396,   400,   404,   408,   412,   416,   422,   423,   429,   430,
     436,   437,   441,   447,   448,   452,   456,   460,   466,   467,
     471,   477,   478,   482,   486,   490,   494,   498,   504,   505,
     509,   513,   519,   520,   524,   528,   534,   535,   536,   540,
     546,   550,   555,   559,   563,   567,   571,   575,   576,   577,
     578,   579,   583,   587,   591,   592,   596,   600,   604,   608,
     612,   616,   622,   626,   632,   636,   640,   644,   649,   653,
     659,   660,   666,   672,   676,   684,   687,   691,   697,   701,
     702,   703,   704,   705,   706,   707,   708,   709,   710,   711,
     712,   713,   719,   723,   728,   732,   738,   739,   745,   752,
     755,   761,   767,   768,   774,   781,   784,   790,   794,   800,
     806,   812,   818,   825,   828,   831,   838,   841,   844,   850,
     856,   860,   864,   870,   871,   878,   877,   887,   891,   897,
     901,   905,   909,   916,   915,   923,   930,   934,   938,   942,
     948,   953,   958,   956,   967,   965,   974,   973,   983,   981,
     992,   993,   999,  1000,  1004,  1008,  1014,  1018,  1025,  1028,
    1034,  1038,  1044,  1045,  1051,  1052,  1055,  1059,  1063,  1067,
    1073,  1077,  1081,  1085,  1089,  1093,  1097,  1101,  1108,  1111,
    1118,  1121,  1127,  1131,  1137,  1141,  1145,  1149,  1155,  1159,
    1166,  1169,  1175,  1179,  1184,  1188,  1193,  1199,  1203,  1209,
    1213,  1219,  1223,  1229,  1233,  1240,  1243,  1250,  1253,  1260,
    1263,  1267,  1274,  1273,  1283
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
  "UNSAFE", "SAFE", "SHARED", "GLOBAL", "ATM_ADD_ASSIGN_T",
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
  "const_definition", "shared", "global", "unsafe", "myblock", "@8", 0
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
     355,   356,   357,   358,   359,   360,   361,   362,   363
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   109,   110,   110,   111,   111,   111,   111,   111,   112,
     112,   113,   114,   114,   115,   115,   116,   117,   117,   117,
     117,   117,   117,   118,   118,   118,   118,   118,   118,   118,
     118,   119,   120,   120,   120,   120,   121,   122,   123,   123,
     123,   123,   124,   124,   126,   125,   127,   127,   127,   128,
     128,   128,   128,   129,   129,   129,   129,   129,   130,   130,
     131,   131,   132,   132,   133,   133,   134,   134,   135,   135,
     135,   135,   135,   135,   135,   135,   136,   136,   137,   137,
     138,   138,   138,   139,   139,   139,   139,   139,   140,   140,
     140,   141,   141,   141,   141,   141,   141,   141,   142,   142,
     142,   142,   143,   143,   143,   143,   144,   144,   144,   144,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     145,   145,   146,   146,   147,   147,   147,   147,   147,   147,
     148,   148,   149,   150,   150,   151,   151,   151,   152,   152,
     152,   152,   152,   152,   152,   152,   152,   152,   152,   152,
     152,   152,   153,   153,   153,   153,   154,   154,   155,   156,
     156,   157,   158,   158,   159,   160,   160,   161,   161,   162,
     163,   164,   165,   166,   166,   167,   168,   168,   169,   170,
     171,   171,   171,   172,   172,   174,   173,   175,   175,   176,
     176,   176,   176,   178,   177,   177,   179,   179,   179,   179,
     180,   180,   182,   181,   183,   181,   184,   181,   185,   181,
     186,   186,   187,   187,   187,   187,   188,   188,   189,   189,
     190,   190,   191,   191,   192,   192,   193,   193,   193,   193,
     194,   194,   194,   194,   194,   194,   194,   194,   195,   195,
     196,   196,   197,   197,   198,   198,   198,   198,   199,   199,
     200,   200,   201,   201,   201,   201,   201,   202,   202,   203,
     203,   204,   204,   205,   205,   206,   206,   207,   207,   208,
     208,   208,   210,   209,   209
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
       4,     4,     3,     4,     3,     3,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     5,
       6,     7,     3,     4,     4,     5,     4,     5,     4,     5,
       1,     2,     3,     2,     3,     0,     1,     3,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     6,     5,     7,     1,     2,     4,     0,
       2,     5,     1,     2,     3,     0,     2,     1,     3,     4,
       8,     8,     8,     0,     1,     3,     0,     1,     3,     3,
       5,     4,     3,     1,     2,     0,     5,     3,     2,     6,
       8,     5,     7,     0,     4,     2,     1,     3,     3,     5,
       3,     0,     0,     9,     0,    10,     0,     8,     0,     9,
       1,     2,     1,     1,     1,     1,     1,     1,     0,     2,
       1,     3,     1,     2,     1,     1,     1,     2,     1,     2,
       9,     8,    10,     9,     7,     6,     8,     7,     0,     2,
       0,     2,     1,     3,     7,     6,     8,     7,     1,     1,
       0,     2,     6,     6,     6,     7,     7,    10,     9,     5,
       6,     1,     3,     5,     4,     0,     1,     0,     1,     0,
       2,     2,     0,     5,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       4,     0,     0,   275,     2,     6,     9,     7,    14,    12,
       0,     0,     1,   117,   118,   119,   120,   108,   109,     0,
       0,   183,   186,   186,   123,     0,   145,     0,     0,   121,
     122,     0,     0,     0,     0,   125,   126,     0,     0,     0,
       0,     0,     0,   161,     0,     0,   276,     3,    57,    17,
       0,    64,    66,    76,    78,    80,    83,    88,    91,    98,
     102,   106,   124,   107,    19,   149,     0,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,    18,    20,
      21,    22,     0,     0,     8,    10,     5,    15,     0,    11,
       0,     0,   170,   108,     0,     0,   184,     0,   187,     0,
       0,     0,   146,     0,    99,   102,   101,   100,   279,     0,
     198,     0,    31,    23,    24,    25,    26,    27,    28,    29,
      30,     0,     0,     0,     0,     0,     0,    31,    30,    38,
      40,   277,    39,    41,     0,     0,     0,     0,     0,     0,
       0,   148,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    68,
       0,    69,    70,    73,    74,    75,   103,   104,     0,     0,
      71,    72,     0,     0,     0,     0,   183,     0,   226,   227,
     258,   259,   223,   224,   225,     0,   220,     0,   222,    44,
      13,    16,     0,     0,     0,   185,   188,   189,   115,   132,
       0,   284,     0,     0,   282,   195,     0,   192,   193,   197,
       0,     0,     0,     0,     0,   277,   140,   277,   277,   248,
       0,     0,     0,     0,     0,   278,    36,     0,     0,     0,
     248,   275,     0,     0,   248,    65,    77,    79,    81,    82,
      84,    85,    86,    87,    89,    90,    92,    93,    94,    95,
      96,    97,   114,     0,    60,   112,    31,   105,     0,    67,
       0,     0,   203,     0,     0,     0,   221,     0,   211,     0,
     111,   162,   145,   175,   172,   133,   147,   280,   281,   169,
       0,   191,     0,   194,   128,     0,    42,     0,     0,   127,
       0,     0,   141,   277,   134,   277,   136,   277,   138,     0,
       0,   248,     0,     0,   271,     0,    33,     0,    32,    34,
      35,   274,   248,     0,     0,   248,   248,   248,     0,   113,
       0,   116,   110,   179,   205,   169,     0,   183,     0,   211,
       0,   228,    46,     0,     0,   164,   166,   146,     0,     0,
       0,   173,   171,   169,    62,     0,   190,   129,     0,    37,
       0,   142,   143,     0,   135,   137,   139,     0,   249,     0,
       0,     0,     0,   201,   269,     0,   273,     0,     0,     0,
     248,     0,   248,     0,     0,   250,    61,   169,     0,     0,
       0,   228,   206,     0,     0,     0,   275,   163,     0,     0,
     167,     0,   174,   176,   283,    63,     0,    43,   130,     0,
     144,    58,     0,     0,     0,     0,   272,   270,     0,     0,
       0,   199,     0,     0,     0,   250,   250,     0,     0,   204,
       0,   183,     0,     0,     0,     0,   210,   230,   229,   212,
      45,    47,    48,     0,   165,   147,   196,   131,     0,     0,
     250,   202,     0,   250,     0,     0,     0,   250,     0,     0,
     252,   251,    56,     0,     0,     0,   214,    31,   208,   207,
       0,     0,     0,   168,    59,   250,     0,   250,     0,   200,
       0,   250,     0,    52,    55,     0,   181,   180,   182,     0,
       0,     0,   231,     0,     0,     0,     0,     0,     0,     0,
       0,   232,   234,   236,   238,   235,   217,     0,   268,     0,
      54,   250,     0,    51,   253,     0,   219,   209,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   237,
     239,   213,   233,   267,    53,     0,    50,   215,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    49,
     250,     0,   260,     0,     0,     0,   260,     0,     0,     0,
     250,     0,   260,     0,     0,   250,     0,     0,     0,   260,
       0,     0,     0,   250,     0,     0,     0,   250,     0,     0,
     250,     0,   260,   255,     0,   261,   264,     0,   250,     0,
     262,     0,   250,     0,     0,     0,   250,   245,     0,   263,
       0,   254,   266,     0,   250,   257,     0,   250,     0,   247,
       0,   244,   265,   241,     0,   256,     0,   250,   246,   240,
     243,     0,   242
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,     6,    10,     7,     8,    47,   129,
     130,   131,   132,   133,   134,   287,    84,   269,   386,    48,
      49,   301,   253,   343,    50,    51,   172,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,   215,
     216,   293,   103,   344,    65,   335,   336,    66,    67,   273,
     274,   342,   339,    68,    69,    70,    71,    97,    72,    99,
      73,    74,    75,   207,   208,   280,    76,    77,   263,   325,
     383,   331,    78,   461,   479,   462,   480,   489,   186,   187,
     385,   428,   490,   491,   492,   493,   302,   418,   451,   494,
     188,   558,   495,    79,    80,   305,    81,    82,   226,   204,
     109,   279
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -503
static const yytype_int16 yypact[] =
{
      94,    87,    87,   469,   -68,    94,  -503,    47,  -503,  -503,
     -24,    12,  -503,  -503,  -503,  -503,  -503,    96,  -503,   972,
     972,   972,   142,   142,  -503,   972,   972,   972,   972,  -503,
    -503,   972,    53,   816,   283,  -503,  -503,   171,   185,   194,
     360,   200,   210,  -503,   -22,   231,  -503,  -503,  -503,  -503,
      -7,  -503,   188,   193,   297,   230,   269,   275,  -503,  -503,
     176,   244,  -503,  -503,  -503,  -503,   286,  -503,  -503,  -503,
    -503,  -503,  -503,  -503,  -503,  -503,  -503,  -503,  -503,  -503,
    -503,  -503,   216,   236,  -503,  -503,    47,  -503,   251,  -503,
     191,   972,  -503,   264,     0,     6,   225,   201,  -503,   207,
     260,   146,  -503,    22,  -503,   165,  -503,  -503,    99,   273,
    -503,     8,    15,  -503,  -503,  -503,  -503,  -503,  -503,  -503,
     291,   289,   289,   289,   337,   268,   341,   121,  -503,   342,
    -503,   274,   354,   356,   377,   362,   293,   381,   383,   369,
     972,  -503,   972,   972,   972,   972,   972,   972,   972,   972,
     972,   972,   972,   972,   972,   972,   972,   972,   828,  -503,
     387,  -503,  -503,  -503,  -503,  -503,  -503,  -503,   433,   433,
    -503,  -503,   972,   972,   972,   370,   972,   374,  -503,  -503,
    -503,  -503,  -503,  -503,  -503,   216,  -503,   391,  -503,  -503,
    -503,  -503,   158,    53,   386,  -503,  -503,  -503,  -503,  -503,
     868,  -503,   302,   305,  -503,  -503,   370,   278,  -503,  -503,
     880,   433,   397,   384,   972,    -6,  -503,    -6,    -6,    36,
     433,   398,   379,   972,   382,  -503,  -503,   385,   388,   313,
      36,   307,   394,   395,    36,  -503,   193,   297,   230,   230,
     269,   269,   269,   269,   275,   275,  -503,  -503,  -503,  -503,
    -503,  -503,  -503,   149,  -503,  -503,   137,  -503,   326,  -503,
     248,     9,   396,   406,   404,   416,  -503,   417,   399,   339,
    -503,   334,   972,   333,  -503,  -503,  -503,  -503,  -503,   764,
     433,  -503,    53,  -503,  -503,   192,  -503,    14,   412,  -503,
     249,   920,  -503,    -1,  -503,    -1,  -503,    -1,  -503,   345,
     340,   411,   419,   -14,  -503,   174,  -503,    11,  -503,  -503,
    -503,  -503,   411,   420,   433,    36,    36,   411,   421,  -503,
     972,  -503,  -503,  -503,  -503,   764,   423,   972,   418,   399,
     440,   422,  -503,    53,   972,   346,  -503,   353,   439,    53,
      53,  -503,  -503,   572,  -503,   464,  -503,  -503,   433,  -503,
     932,  -503,  -503,   451,  -503,  -503,  -503,   433,  -503,    10,
     456,   389,   972,  -503,  -503,    34,  -503,   458,   401,   -10,
     411,   472,   411,   473,   474,   428,  -503,   668,   972,   477,
     972,   422,   478,    45,   500,   414,    86,  -503,     4,    53,
    -503,   972,  -503,  -503,  -503,  -503,    53,  -503,  -503,   196,
    -503,  -503,   415,   429,   433,    27,  -503,  -503,   430,   433,
     972,  -503,   486,   437,   489,   428,   428,   507,    53,  -503,
     213,   972,   215,   436,   508,   509,  -503,  -503,   504,   442,
    -503,  -503,  -503,    53,  -503,   438,  -503,  -503,   433,   433,
     428,  -503,   433,   428,    30,   454,   433,   428,   443,    53,
    -503,   514,  -503,   452,    53,   370,   457,  -503,  -503,   487,
     542,   547,   459,  -503,  -503,   428,   453,   428,    53,  -503,
     433,   428,   465,  -503,  -503,   548,  -503,  -503,  -503,   547,
     460,   508,  -503,   557,    55,   559,   563,    81,   564,    39,
     447,  -503,  -503,  -503,  -503,  -503,  -503,   475,  -503,    53,
    -503,   428,   484,  -503,  -503,   520,  -503,  -503,   549,   491,
      62,   560,   492,   580,   581,   582,   567,   502,   596,  -503,
    -503,  -503,  -503,  -503,  -503,   506,  -503,  -503,    42,   433,
     512,    56,   433,   584,   585,   586,    57,   433,   517,  -503,
     428,   217,   583,   433,   518,   218,   583,    66,    68,   123,
     428,   223,   583,   433,    53,   428,   611,   972,   532,   583,
     433,   537,   536,   428,   229,   541,   233,   428,   242,    53,
     428,   540,   583,  -503,    53,   225,  -503,   543,   428,   433,
    -503,   544,   428,   433,   545,   546,   428,  -503,    53,  -503,
     550,  -503,  -503,    53,   428,  -503,   551,   428,   433,  -503,
     552,  -503,  -503,  -503,    53,  -503,   553,   428,  -503,  -503,
    -503,   554,  -503
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -503,  -503,  -503,  -503,   648,   652,   653,    29,  -503,   623,
     -31,  -503,  -503,   625,  -164,  -503,  -503,  -503,  -503,   277,
    -503,  -219,  -187,   335,   -19,   -13,  -503,  -503,   519,   521,
     219,   178,   220,    58,  -503,   311,  -503,  -503,  -503,   252,
      70,   159,   393,     5,  -503,  -503,   331,  -503,  -503,  -503,
     405,  -503,  -503,  -503,  -503,  -503,  -503,  -166,  -503,   644,
    -503,  -503,  -503,  -503,   476,  -503,  -503,  -503,  -194,  -503,
    -503,   350,   295,  -503,  -503,  -503,  -503,   -75,  -176,   497,
     303,  -503,   206,  -359,  -503,   197,  -214,  -388,  -503,   203,
    -503,  -502,  -503,  -503,  -503,  -503,  -503,   466,  -185,  -503,
    -168,  -503
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -219
static const yytype_int16 yytable[] =
{
      94,    95,    96,   122,   257,   258,   101,   185,    64,   266,
     264,   312,   281,   102,   111,   317,   313,   402,   362,    90,
     318,   291,   410,   285,   140,   271,   353,   448,   449,    88,
     294,   140,   296,   298,    83,   140,    87,   140,   210,   140,
     140,   406,   140,   299,   562,   348,   517,   286,   199,   299,
     571,   349,   466,   200,   211,   468,   303,   577,   140,   472,
     407,   140,   509,   299,   299,    88,   540,   300,   212,   530,
     590,   137,   192,   299,    89,   299,   425,   497,   138,   499,
     544,   550,   426,   502,   363,   104,   106,   360,   411,   107,
     563,   141,   565,   323,     9,   193,   370,   372,   367,   433,
     225,   371,   373,   374,   194,   225,   209,   108,   354,   366,
     355,   358,   356,   525,   346,    87,   345,   180,   181,   182,
     183,   184,     2,    91,   483,   441,    92,   235,   469,   518,
     299,   522,   485,   180,   181,   182,   183,   184,   487,   488,
     180,   181,   182,   183,   184,   254,   522,   567,   222,    98,
     369,   108,   554,   223,   260,   261,   412,    96,   414,   259,
     211,   379,   569,   399,   222,   387,   513,   574,     1,     2,
     198,   392,   393,   319,   514,   581,   211,   140,   124,   585,
     320,   515,   588,   430,   397,    44,   270,   276,   158,   140,
     593,    46,   125,   401,   596,   290,   201,   254,   600,   158,
     364,   126,   202,   203,   307,   365,   604,   135,   159,   606,
     246,   247,   248,   249,   250,   251,   347,   136,   160,   611,
     437,   434,   142,   320,   166,   167,   143,   320,   436,   160,
     161,   162,   163,   164,   165,   166,   167,   453,   139,   455,
     440,   555,   561,   189,   140,   443,   140,   570,   556,   556,
     452,   168,   169,   582,   556,   454,   140,   584,   190,   337,
     556,   478,   168,   169,   556,   463,   586,   146,   147,   148,
     149,   173,   290,   556,   464,   465,   322,   351,   467,   140,
     140,   474,   471,   170,   171,   292,   477,   292,   292,   191,
     112,    91,   178,   179,   180,   181,   182,   183,   184,   195,
     500,   174,   175,   176,   177,   196,   501,   376,    96,   541,
     150,   151,   545,   266,   213,   388,   214,   551,   152,   153,
     154,   155,   156,   157,   240,   241,   242,   243,   564,   566,
     568,   524,   144,   145,   266,   205,   206,   254,   105,   105,
     205,   282,   105,   405,   333,   334,   272,   340,   395,   113,
     114,   115,   116,   117,   118,   119,   389,   334,   197,   420,
     219,   422,   220,   238,   239,   542,   221,   127,   546,   224,
     244,   245,   120,   552,   217,   218,   295,   297,   435,   559,
     225,   227,   395,   228,   229,   230,   573,   231,   232,   572,
     233,   444,   234,   458,   255,   262,   578,   265,   268,   272,
     277,   587,    96,   278,   288,   304,   591,   306,   289,   510,
     308,   311,    46,   309,   321,   594,   310,   315,   316,   597,
     601,   326,   324,   328,   329,   603,   113,   114,   115,   116,
     117,   118,   119,   327,   607,   350,   609,   332,   330,   357,
     256,   358,   359,   361,   368,   375,   378,   382,   380,   128,
     507,  -177,   384,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,    12,
     391,   396,    13,    14,    15,    16,    17,    18,    19,   400,
     403,    20,   408,   404,  -169,  -169,  -169,  -169,    21,    22,
      23,    24,    25,   417,    26,   409,   413,   415,   416,   113,
     114,   115,   116,   117,   118,   119,   421,   427,   424,   438,
     445,    27,   429,   447,   450,   457,   459,   481,    28,    29,
      30,    31,   128,   439,   442,   180,   181,   182,   183,   184,
      32,   446,   483,    33,   456,   460,  -178,   484,   575,  -216,
     485,   473,    34,   486,   521,   475,   487,   488,   470,   482,
     476,   498,    35,    36,  -218,   504,   496,   506,    37,    38,
      39,    40,    41,   503,   508,    42,   511,    43,    44,    45,
     512,   516,   528,   523,    46,    13,    14,    15,    16,    17,
      18,    19,   526,   531,    20,   529,   532,   533,   534,   535,
     536,    21,    22,    23,    24,    25,   537,    26,   180,   181,
     182,   183,   184,   538,   539,   483,   543,   547,   548,   549,
     484,   553,   560,   485,    27,   557,   486,   527,   402,   487,
     488,    28,    29,    30,    31,   180,   181,   182,   183,   184,
     576,   579,   483,    32,   580,   583,    33,   484,   589,   598,
     485,   592,   595,   486,   599,    34,   487,   488,   602,   605,
     608,   610,   612,    85,    11,    35,    36,   121,    86,   123,
     377,   236,    38,   431,   237,   338,   390,   100,    42,   394,
      43,    13,    14,    15,    16,    17,    18,    19,   341,   381,
      20,   432,   267,   283,   423,   505,   519,    21,    22,    23,
      24,    25,   520,    26,   419,     0,     0,   314,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      27,     0,     0,     0,     0,     0,     0,    28,    29,    30,
      31,     0,     0,     0,     0,     0,     0,     0,     0,    32,
       0,     0,    33,     0,     0,     0,     0,     0,     0,     0,
       0,    34,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    35,    36,     0,     0,     0,     0,     0,    38,     0,
       0,     0,     0,     0,    42,     0,    43,    13,    14,    15,
      16,    17,    18,    19,     0,     0,    20,     0,     0,     0,
       0,     0,     0,    21,    22,    23,    24,    25,     0,    26,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    27,     0,     0,     0,
       0,     0,     0,    28,    29,    30,    31,     0,     0,    13,
      14,    15,    16,    93,    18,    32,     0,     0,    33,     0,
       0,    13,    14,    15,    16,    93,    18,    34,    24,    25,
       0,    26,     0,     0,     0,     0,     0,    35,    36,     0,
      24,    25,   252,    26,    38,     0,     0,     0,    27,     0,
      42,     0,    43,     0,     0,    28,    29,    30,    31,     0,
      27,    13,    14,    15,    16,    93,    18,    28,    29,    30,
      31,     0,     0,    13,    14,    15,    16,    93,    18,    34,
      24,    25,     0,    26,   275,     0,     0,     0,     0,    35,
      36,    34,    24,    25,   284,    26,     0,     0,     0,     0,
      27,    35,    36,     0,   110,     0,     0,    28,    29,    30,
      31,     0,    27,    13,    14,    15,    16,    93,    18,    28,
      29,    30,    31,     0,     0,    13,    14,    15,    16,    93,
      18,    34,    24,    25,     0,    26,     0,     0,   352,     0,
       0,    35,    36,    34,    24,    25,   398,    26,     0,     0,
       0,     0,    27,    35,    36,     0,     0,     0,     0,    28,
      29,    30,    31,     0,    27,    13,    14,    15,    16,    93,
      18,    28,    29,    30,    31,     0,     0,     0,     0,     0,
       0,     0,     0,    34,    24,    25,     0,    26,     0,     0,
       0,     0,     0,    35,    36,    34,     0,     0,     0,     0,
       0,     0,     0,     0,    27,    35,    36,     0,     0,     0,
       0,    28,    29,    30,    31,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    34,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    35,    36
};

static const yytype_int16 yycheck[] =
{
      19,    20,    21,    34,   168,   169,    25,    82,     3,   185,
     176,   230,   206,    26,    33,   234,   230,     7,    32,     7,
     234,    27,    32,   210,    31,   193,    27,   415,   416,    53,
     215,    31,   217,   218,   102,    31,     7,    31,    23,    31,
      31,     7,    31,     7,   546,    31,     7,   211,    26,     7,
     552,    37,   440,    31,    39,   443,   220,   559,    31,   447,
      26,    31,     7,     7,     7,    53,    24,    31,    53,     7,
     572,    93,    91,     7,    98,     7,    31,   465,   100,   467,
      24,    24,    37,   471,    98,    27,    28,   301,    98,    31,
      24,    98,    24,   261,     7,    95,   315,   316,   312,    95,
     106,   315,   316,   317,    98,   106,    98,    98,   293,    98,
     295,   101,   297,   501,   282,    86,   280,    78,    79,    80,
      81,    82,    75,    27,    85,    98,    30,   140,    98,    90,
       7,   490,    93,    78,    79,    80,    81,    82,    99,   100,
      78,    79,    80,    81,    82,   158,   505,    24,    27,     7,
     314,    98,   540,    32,   173,   174,   370,   176,   372,   172,
      39,   327,   550,   350,    27,   333,    85,   555,    74,    75,
      24,   339,   340,    24,    93,   563,    39,    31,     7,   567,
      31,   100,   570,    97,   348,    99,    28,   200,    23,    31,
     578,   105,     7,   357,   582,   214,    97,   210,   586,    23,
      26,     7,   103,   104,   223,    31,   594,     7,    32,   597,
     152,   153,   154,   155,   156,   157,    24,     7,    53,   607,
      24,   389,    34,    31,    59,    60,    33,    31,   396,    53,
      54,    55,    56,    57,    58,    59,    60,    24,     7,    24,
     404,    24,    24,     7,    31,   409,    31,    24,    31,    31,
     418,    86,    87,    24,    31,   421,    31,    24,     7,   272,
      31,   455,    86,    87,    31,   433,    24,    37,    38,    39,
      40,    27,   291,    31,   438,   439,    28,    28,   442,    31,
      31,   449,   446,   107,   108,   215,   454,   217,   218,    98,
       7,    27,    76,    77,    78,    79,    80,    81,    82,    98,
     468,    15,    16,    17,    18,    98,   470,   320,   327,   528,
      41,    42,   531,   489,    23,   334,    27,   536,    43,    44,
      45,    46,    47,    48,   146,   147,   148,   149,   547,   548,
     549,   499,    35,    36,   510,    62,    63,   350,    27,    28,
      62,    63,    31,   362,    10,    11,    13,    14,   343,    66,
      67,    68,    69,    70,    71,    72,    10,    11,    98,   378,
      23,   380,    94,   144,   145,   529,    25,     7,   532,    27,
     150,   151,    89,   537,   122,   123,   217,   218,   391,   543,
     106,    27,   377,    27,     7,    23,   554,    94,     7,   553,
       7,   410,    23,   424,     7,    25,   560,    23,     7,    13,
      98,   569,   421,    98,     7,     7,   574,    28,    24,   484,
      28,    98,   105,    28,    88,   579,    28,    23,    23,   583,
     588,    15,    26,     7,     7,   593,    66,    67,    68,    69,
      70,    71,    72,    29,   598,    23,   604,    98,    39,    94,
       7,   101,    31,    24,    24,    24,    23,     7,    30,    89,
     481,    98,    30,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,     0,
      31,     7,     3,     4,     5,     6,     7,     8,     9,    28,
      24,    12,    24,    94,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    65,    25,    94,    24,    24,    24,    66,
      67,    68,    69,    70,    71,    72,    29,     7,    30,    94,
      24,    42,    98,    24,     7,     7,     7,    30,    49,    50,
      51,    52,    89,    94,    94,    78,    79,    80,    81,    82,
      61,    94,    85,    64,    98,    31,    98,    90,   557,    97,
      93,    98,    73,    96,    97,    31,    99,   100,    94,     7,
      98,    98,    83,    84,    97,     7,    97,    97,    89,    90,
      91,    92,    93,    98,     7,    96,     7,    98,    99,   100,
       7,     7,    23,    98,   105,     3,     4,     5,     6,     7,
       8,     9,    98,    23,    12,    94,    94,     7,     7,     7,
      23,    19,    20,    21,    22,    23,    94,    25,    78,    79,
      80,    81,    82,     7,    98,    85,    94,    23,    23,    23,
      90,    94,    94,    93,    42,    32,    96,    97,     7,    99,
     100,    49,    50,    51,    52,    78,    79,    80,    81,    82,
      98,    94,    85,    61,    98,    94,    64,    90,    98,    94,
      93,    98,    98,    96,    98,    73,    99,   100,    98,    98,
      98,    98,    98,     5,     2,    83,    84,    34,     5,    34,
     325,   142,    90,   386,   143,   272,   335,    23,    96,    97,
      98,     3,     4,     5,     6,     7,     8,     9,   273,   329,
      12,   386,   185,   207,   381,   479,   489,    19,    20,    21,
      22,    23,   489,    25,    26,    -1,    -1,   231,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,
      -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    83,    84,    -1,    -1,    -1,    -1,    -1,    90,    -1,
      -1,    -1,    -1,    -1,    96,    -1,    98,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    19,    20,    21,    22,    23,    -1,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    50,    51,    52,    -1,    -1,     3,
       4,     5,     6,     7,     8,    61,    -1,    -1,    64,    -1,
      -1,     3,     4,     5,     6,     7,     8,    73,    22,    23,
      -1,    25,    -1,    -1,    -1,    -1,    -1,    83,    84,    -1,
      22,    23,    24,    25,    90,    -1,    -1,    -1,    42,    -1,
      96,    -1,    98,    -1,    -1,    49,    50,    51,    52,    -1,
      42,     3,     4,     5,     6,     7,     8,    49,    50,    51,
      52,    -1,    -1,     3,     4,     5,     6,     7,     8,    73,
      22,    23,    -1,    25,    26,    -1,    -1,    -1,    -1,    83,
      84,    73,    22,    23,    24,    25,    -1,    -1,    -1,    -1,
      42,    83,    84,    -1,    98,    -1,    -1,    49,    50,    51,
      52,    -1,    42,     3,     4,     5,     6,     7,     8,    49,
      50,    51,    52,    -1,    -1,     3,     4,     5,     6,     7,
       8,    73,    22,    23,    -1,    25,    -1,    -1,    28,    -1,
      -1,    83,    84,    73,    22,    23,    24,    25,    -1,    -1,
      -1,    -1,    42,    83,    84,    -1,    -1,    -1,    -1,    49,
      50,    51,    52,    -1,    42,     3,     4,     5,     6,     7,
       8,    49,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    73,    22,    23,    -1,    25,    -1,    -1,
      -1,    -1,    -1,    83,    84,    73,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    83,    84,    -1,    -1,    -1,
      -1,    49,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    83,    84
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    74,    75,   110,   111,   112,   113,   115,   116,     7,
     114,   114,     0,     3,     4,     5,     6,     7,     8,     9,
      12,    19,    20,    21,    22,    23,    25,    42,    49,    50,
      51,    52,    61,    64,    73,    83,    84,    89,    90,    91,
      92,    93,    96,    98,    99,   100,   105,   117,   128,   129,
     133,   134,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   152,   153,   156,   157,   162,   163,
     164,   165,   167,   169,   170,   171,   175,   176,   181,   202,
     203,   205,   206,   102,   125,   113,   115,   116,    53,    98,
       7,    27,    30,     7,   133,   133,   133,   166,     7,   168,
     168,   133,   134,   151,   142,   144,   142,   142,    98,   209,
      98,   133,     7,    66,    67,    68,    69,    70,    71,    72,
      89,   118,   119,   122,     7,     7,     7,     7,    89,   118,
     119,   120,   121,   122,   123,     7,     7,    93,   100,     7,
      31,    98,    34,    33,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    23,    32,
      53,    54,    55,    56,    57,    58,    59,    60,    86,    87,
     107,   108,   135,    27,    15,    16,    17,    18,    76,    77,
      78,    79,    80,    81,    82,   186,   187,   188,   199,     7,
       7,    98,   133,    95,    98,    98,    98,    98,    24,    26,
      31,    97,   103,   104,   208,    62,    63,   172,   173,    98,
      23,    39,    53,    23,    27,   148,   149,   148,   148,    23,
      94,    25,    27,    32,    27,   106,   207,    27,    27,     7,
      23,    94,     7,     7,    23,   134,   137,   138,   139,   139,
     140,   140,   140,   140,   141,   141,   142,   142,   142,   142,
     142,   142,    24,   131,   134,     7,     7,   123,   123,   134,
     133,   133,    25,   177,   166,    23,   187,   188,     7,   126,
      28,   209,    13,   158,   159,    26,   134,    98,    98,   210,
     174,   177,    63,   173,    24,   131,   123,   124,     7,    24,
     133,    27,   149,   150,   207,   150,   207,   150,   207,     7,
      31,   130,   195,   123,     7,   204,    28,   133,    28,    28,
      28,    98,   130,   195,   206,    23,    23,   130,   195,    24,
      31,    88,    28,   209,    26,   178,    15,    29,     7,     7,
      39,   180,    98,    10,    11,   154,   155,   134,   151,   161,
      14,   159,   160,   132,   152,   123,   209,    24,    31,    37,
      23,    28,    28,    27,   207,   207,   207,    94,   101,    31,
     195,    24,    32,    98,    26,    31,    98,   195,    24,   123,
     130,   195,   130,   195,   195,    24,   134,   132,    23,   166,
      30,   180,     7,   179,    30,   189,   127,   209,   133,    10,
     155,    31,   209,   209,    97,   152,     7,   123,    24,   131,
      28,   123,     7,    24,    94,   133,     7,    26,    24,    94,
      32,    98,   195,    24,   195,    24,    24,    65,   196,    26,
     133,    29,   133,   189,    30,    31,    37,     7,   190,    98,
      97,   128,   181,    95,   209,   134,   209,    24,    94,    94,
     123,    98,    94,   123,   133,    24,    94,    24,   196,   196,
       7,   197,   209,    24,   166,    24,    98,     7,   119,     7,
      31,   182,   184,   209,   123,   123,   196,   123,   196,    98,
      94,   123,   196,    98,   209,    31,    98,   209,   177,   183,
     185,    30,     7,    85,    90,    93,    96,    99,   100,   186,
     191,   192,   193,   194,   198,   201,    97,   196,    98,   196,
     209,   123,   196,    98,     7,   191,    97,   119,     7,     7,
     186,     7,     7,    85,    93,   100,     7,     7,    90,   194,
     198,    97,   192,    98,   209,   196,    98,    97,    23,    94,
       7,    23,    94,     7,     7,     7,    23,    94,     7,    98,
      24,   130,   123,    94,    24,   130,   123,    23,    23,    23,
      24,   130,   123,    94,   196,    24,    31,    32,   200,   123,
      94,    24,   200,    24,   130,    24,   130,    24,   130,   196,
      24,   200,   123,   209,   196,   133,    98,   200,   123,    94,
      98,   196,    24,    94,    24,   196,    24,   209,   196,    98,
     200,   209,    98,   196,   123,    98,   196,   123,    94,    98,
     196,   209,    98,   209,   196,    98,   196,   123,    98,   209,
      98,   196,    98
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
#line 110 "diksam.y"
    {
            dkc_set_require_and_rename_list(NULL, NULL);
        }
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 114 "diksam.y"
    {
            dkc_set_require_and_rename_list((yyvsp[(1) - (2)].require_list), (yyvsp[(2) - (2)].rename_list));
        }
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 118 "diksam.y"
    {
            dkc_set_require_and_rename_list((yyvsp[(1) - (1)].require_list), NULL);
        }
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 122 "diksam.y"
    {
            dkc_set_require_and_rename_list(NULL, (yyvsp[(1) - (1)].rename_list));
        }
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 126 "diksam.y"
    {
            dkc_set_require_and_rename_list(NULL, NULL);
		}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 133 "diksam.y"
    {
            (yyval.require_list) = dkc_chain_require_list((yyvsp[(1) - (2)].require_list), (yyvsp[(2) - (2)].require_list));
        }
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 139 "diksam.y"
    {
            (yyval.require_list) = dkc_create_require_list((yyvsp[(2) - (3)].package_name));
        }
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 145 "diksam.y"
    {
            (yyval.package_name) = dkc_create_package_name((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 149 "diksam.y"
    {
            (yyval.package_name) = dkc_chain_package_name((yyvsp[(1) - (3)].package_name), (yyvsp[(3) - (3)].identifier));
        }
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 156 "diksam.y"
    {
            (yyval.rename_list) = dkc_chain_rename_list((yyvsp[(1) - (2)].rename_list), (yyvsp[(2) - (2)].rename_list));
        }
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 162 "diksam.y"
    {
            (yyval.rename_list) = dkc_create_rename_list((yyvsp[(2) - (4)].package_name), (yyvsp[(3) - (4)].identifier));
        }
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 170 "diksam.y"
    {
            DKC_Compiler *compiler = dkc_get_current_compiler();

            compiler->statement_list
                = dkc_chain_statement_list(compiler->statement_list, (yyvsp[(1) - (1)].statement));
        }
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 182 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_VOID_TYPE;
        }
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 186 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_BOOLEAN_TYPE;
        }
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 190 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_INT_TYPE;
        }
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 194 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_DOUBLE_TYPE;
        }
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 198 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_STRING_TYPE;
        }
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 202 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_VARIENT_TYPE;
        }
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 206 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_NATIVE_POINTER_TYPE;
        }
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 210 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_DELEGATE_TYPE;
        }
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 216 "diksam.y"
    {
            (yyval.type_specifier) = dkc_create_identifier_type_specifier((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 222 "diksam.y"
    {
            TypeSpecifier *basic_type
                = dkc_create_type_specifier((yyvsp[(1) - (3)].basic_type_specifier));
            (yyval.type_specifier) = dkc_create_array_type_specifier(basic_type,0);
        }
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 228 "diksam.y"
    {
            TypeSpecifier *identifier_type
                = dkc_create_identifier_type_specifier((yyvsp[(1) - (3)].identifier));
            (yyval.type_specifier) = dkc_create_array_type_specifier(identifier_type,0);
        }
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 234 "diksam.y"
    {
            (yyval.type_specifier) = dkc_create_array_type_specifier((yyvsp[(1) - (3)].type_specifier),0);
        }
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 238 "diksam.y"
    {
			(yyval.type_specifier) = dkc_create_array_type_specifier((yyvsp[(1) - (3)].type_specifier),0);
		}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 244 "diksam.y"
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
#line 258 "diksam.y"
    {//fix-me : shift/reduce
			(yyval.type_specifier)= dkc_create_template_type_specifier((yyvsp[(1) - (4)].identifier),(yyvsp[(3) - (4)].template));
		}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 264 "diksam.y"
    {
                    (yyval.type_specifier) = dkc_create_type_specifier((yyvsp[(1) - (1)].basic_type_specifier));
        }
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 274 "diksam.y"
    {
			(yyval.template)=dkc_create_template_list((yyvsp[(1) - (1)].type_specifier));
		}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 278 "diksam.y"
    {
            (yyval.template) = dkc_chain_template_list((yyvsp[(1) - (3)].template), (yyvsp[(3) - (3)].type_specifier));
        }
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 285 "diksam.y"
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
#line 295 "diksam.y"
    {
			BcGetCurrentCompilerContext()->isLib=0;
		}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 307 "diksam.y"
    {
            dkc_function_define((yyvsp[(9) - (11)].type_specifier), (yyvsp[(3) - (11)].identifier), (yyvsp[(5) - (11)].parameter_list), (yyvsp[(10) - (11)].exception_list), NULL,(yyvsp[(6) - (11)].intval));
        }
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 311 "diksam.y"
    {
            dkc_function_define((yyvsp[(8) - (10)].type_specifier), (yyvsp[(3) - (10)].identifier), NULL, (yyvsp[(9) - (10)].exception_list), NULL,(yyvsp[(5) - (10)].intval));
        }
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 315 "diksam.y"
    {
            dkc_function_define(0, (yyvsp[(3) - (9)].identifier), (yyvsp[(5) - (9)].parameter_list), (yyvsp[(8) - (9)].exception_list), NULL,(yyvsp[(6) - (9)].intval));
        }
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 319 "diksam.y"
    {
			//printf("lib:%s\n",BcGetCurrentCompilerContext()->libname);
            dkc_function_define(0, (yyvsp[(3) - (8)].identifier), NULL, (yyvsp[(7) - (8)].exception_list), NULL,(yyvsp[(5) - (8)].intval));
        }
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 326 "diksam.y"
    {
            dkc_function_define((yyvsp[(8) - (10)].type_specifier), (yyvsp[(2) - (10)].identifier), (yyvsp[(4) - (10)].parameter_list), (yyvsp[(9) - (10)].exception_list), (yyvsp[(10) - (10)].block),(yyvsp[(5) - (10)].intval));
        }
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 330 "diksam.y"
    {
            dkc_function_define((yyvsp[(7) - (9)].type_specifier), (yyvsp[(2) - (9)].identifier), NULL, (yyvsp[(8) - (9)].exception_list), (yyvsp[(9) - (9)].block),(yyvsp[(4) - (9)].intval));
        }
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 334 "diksam.y"
    { //modified
            dkc_function_define(0, (yyvsp[(2) - (8)].identifier), (yyvsp[(4) - (8)].parameter_list), (yyvsp[(7) - (8)].exception_list), (yyvsp[(8) - (8)].block),(yyvsp[(5) - (8)].intval));
        }
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 338 "diksam.y"
    {
            dkc_function_define(0, (yyvsp[(2) - (7)].identifier), NULL, (yyvsp[(6) - (7)].exception_list), (yyvsp[(7) - (7)].block),(yyvsp[(4) - (7)].intval));
        }
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 345 "diksam.y"
    {
            (yyval.parameter_list) = dkc_create_parameter((yyvsp[(3) - (3)].type_specifier), (yyvsp[(1) - (3)].identifier));
        }
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 349 "diksam.y"
    {
            (yyval.parameter_list) = dkc_chain_parameter((yyvsp[(1) - (5)].parameter_list), (yyvsp[(5) - (5)].type_specifier), (yyvsp[(3) - (5)].identifier));
        }
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 355 "diksam.y"
    {
            (yyval.argument_list) = dkc_create_argument_list((yyvsp[(1) - (1)].expression));
        }
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 359 "diksam.y"
    {
            (yyval.argument_list) = dkc_chain_argument_list((yyvsp[(1) - (3)].argument_list), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 365 "diksam.y"
    {
            (yyval.statement_list) = dkc_create_statement_list((yyvsp[(1) - (1)].statement));
        }
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 369 "diksam.y"
    {
            (yyval.statement_list) = dkc_chain_statement_list((yyvsp[(1) - (2)].statement_list), (yyvsp[(2) - (2)].statement));
        }
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 376 "diksam.y"
    {
            (yyval.expression) = dkc_create_comma_expression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 383 "diksam.y"
    {
            (yyval.expression) = dkc_create_assign_expression((yyvsp[(1) - (3)].expression), (yyvsp[(2) - (3)].assignment_operator), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 389 "diksam.y"
    {
            (yyval.assignment_operator) = NORMAL_ASSIGN;
        }
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 393 "diksam.y"
    {
            (yyval.assignment_operator) = ADD_ASSIGN;
        }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 397 "diksam.y"
    {
            (yyval.assignment_operator) = SUB_ASSIGN;
        }
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 401 "diksam.y"
    {
            (yyval.assignment_operator) = ATM_ADD_ASSIGN;
        }
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 405 "diksam.y"
    {
            (yyval.assignment_operator) = ATM_SUB_ASSIGN;
        }
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 409 "diksam.y"
    {
            (yyval.assignment_operator) = MUL_ASSIGN;
        }
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 413 "diksam.y"
    {
            (yyval.assignment_operator) = DIV_ASSIGN;
        }
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 417 "diksam.y"
    {
            (yyval.assignment_operator) = MOD_ASSIGN;
        }
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 424 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(LOGICAL_OR_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 431 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(LOGICAL_AND_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 438 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(EQ_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 442 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(NE_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 449 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(GT_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 453 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(GE_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 457 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(LT_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 461 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(LE_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 468 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(ADD_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 472 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(SUB_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 479 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(MUL_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 483 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(DIV_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 487 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(MOD_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 491 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(BIT_AND_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 495 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(BIT_OR_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 499 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(BIT_XOR_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 506 "diksam.y"
    {
            (yyval.expression) = dkc_create_minus_expression((yyvsp[(2) - (2)].expression));
        }
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 510 "diksam.y"
    {
            (yyval.expression) = dkc_create_logical_not_expression((yyvsp[(2) - (2)].expression));
        }
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 514 "diksam.y"
    {
            (yyval.expression) = dkc_create_bit_not_expression((yyvsp[(2) - (2)].expression));
        }
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 521 "diksam.y"
    {
            (yyval.expression) = dkc_create_incdec_expression((yyvsp[(1) - (2)].expression), INCREMENT_EXPRESSION);
        }
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 525 "diksam.y"
    {
            (yyval.expression) = dkc_create_incdec_expression((yyvsp[(1) - (2)].expression), DECREMENT_EXPRESSION);
        }
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 529 "diksam.y"
    {
            (yyval.expression) = dkc_create_instanceof_expression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].type_specifier));
        }
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 537 "diksam.y"
    {
            (yyval.expression) = dkc_create_identifier_expression((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 541 "diksam.y"
    {
			(yyval.expression)=BcCreateAutoExpression((yyvsp[(1) - (1)].identifier));
		}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 547 "diksam.y"
    {
            (yyval.expression) = dkc_create_index_expression((yyvsp[(1) - (4)].expression), (yyvsp[(3) - (4)].expression));
        }
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 551 "diksam.y"
    {
            Expression *identifier = dkc_create_identifier_expression((yyvsp[(1) - (4)].identifier));
            (yyval.expression) = dkc_create_index_expression(identifier, (yyvsp[(3) - (4)].expression));
        }
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 556 "diksam.y"
    {
            (yyval.expression) = dkc_create_member_expression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].identifier));
        }
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 560 "diksam.y"
    {
            (yyval.expression) = dkc_create_function_call_expression((yyvsp[(1) - (4)].expression), (yyvsp[(3) - (4)].argument_list));
        }
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 564 "diksam.y"
    {
            (yyval.expression) = dkc_create_function_call_expression((yyvsp[(1) - (3)].expression), NULL);
        }
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 568 "diksam.y"
    {
            (yyval.expression) = (yyvsp[(2) - (3)].expression);
        }
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 572 "diksam.y"
    {
            (yyval.expression) = dkc_create_down_cast_expression((yyvsp[(1) - (4)].expression), (yyvsp[(3) - (4)].type_specifier));
        }
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 580 "diksam.y"
    {
            (yyval.expression) = dkc_create_boolean_expression(DVM_TRUE);
        }
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 584 "diksam.y"
    {
            (yyval.expression) = dkc_create_boolean_expression(DVM_FALSE);
        }
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 588 "diksam.y"
    {
            (yyval.expression) = dkc_create_null_expression();
        }
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 593 "diksam.y"
    {
            (yyval.expression) = dkc_create_this_expression();
        }
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 597 "diksam.y"
    {
            (yyval.expression) = dkc_create_super_expression();
        }
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 601 "diksam.y"
    {
			(yyval.expression) = dkc_create_new_delegate_expression();
		}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 605 "diksam.y"
    {
            (yyval.expression) = dkc_create_new_expression((yyvsp[(2) - (4)].identifier), NULL, NULL);
        }
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 609 "diksam.y"
    {
            (yyval.expression) = dkc_create_new_expression((yyvsp[(2) - (5)].identifier), NULL, (yyvsp[(4) - (5)].argument_list));
        }
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 613 "diksam.y"
    {
            (yyval.expression) = dkc_create_new_expression((yyvsp[(2) - (6)].identifier), (yyvsp[(4) - (6)].identifier), NULL);
        }
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 617 "diksam.y"
    {
            (yyval.expression) = dkc_create_new_expression((yyvsp[(2) - (7)].identifier), (yyvsp[(4) - (7)].identifier), (yyvsp[(6) - (7)].argument_list));
        }
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 623 "diksam.y"
    {
            (yyval.expression) = dkc_create_array_literal_expression((yyvsp[(2) - (3)].expression_list));
        }
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 627 "diksam.y"
    {
            (yyval.expression) = dkc_create_array_literal_expression((yyvsp[(2) - (4)].expression_list));
        }
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 633 "diksam.y"
    {
            (yyval.expression) = dkc_create_basic_array_creation((yyvsp[(2) - (4)].basic_type_specifier), (yyvsp[(3) - (4)].array_dimension), NULL,(yyvsp[(4) - (4)].intval));
        }
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 637 "diksam.y"
    {
            (yyval.expression) = dkc_create_basic_array_creation((yyvsp[(2) - (5)].basic_type_specifier), (yyvsp[(3) - (5)].array_dimension), (yyvsp[(4) - (5)].array_dimension),(yyvsp[(5) - (5)].intval));
        }
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 641 "diksam.y"
    {
            (yyval.expression) = dkc_create_class_array_creation((yyvsp[(2) - (4)].type_specifier), (yyvsp[(3) - (4)].array_dimension), NULL,(yyvsp[(4) - (4)].intval));
        }
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 646 "diksam.y"
    {
            (yyval.expression) = dkc_create_class_array_creation((yyvsp[(2) - (5)].type_specifier), (yyvsp[(3) - (5)].array_dimension), (yyvsp[(4) - (5)].array_dimension),(yyvsp[(5) - (5)].intval));
        }
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 650 "diksam.y"
    {
            (yyval.expression) = dkc_create_class_array_creation((yyvsp[(2) - (4)].type_specifier), (yyvsp[(3) - (4)].array_dimension), NULL,(yyvsp[(4) - (4)].intval));
        }
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 654 "diksam.y"
    {
            (yyval.expression) = dkc_create_class_array_creation((yyvsp[(2) - (5)].type_specifier), (yyvsp[(3) - (5)].array_dimension), (yyvsp[(4) - (5)].array_dimension),(yyvsp[(5) - (5)].intval));
        }
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 661 "diksam.y"
    {
            (yyval.array_dimension) = dkc_chain_array_dimension((yyvsp[(1) - (2)].array_dimension), (yyvsp[(2) - (2)].array_dimension));
        }
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 667 "diksam.y"
    {
            (yyval.array_dimension) = dkc_create_array_dimension((yyvsp[(2) - (3)].expression));
        }
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 673 "diksam.y"
    {
            (yyval.array_dimension) = dkc_create_array_dimension(NULL);
        }
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 677 "diksam.y"
    {
            (yyval.array_dimension) = dkc_chain_array_dimension((yyvsp[(1) - (3)].array_dimension),
                                           dkc_create_array_dimension(NULL));
        }
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 684 "diksam.y"
    {
            (yyval.expression_list) = NULL;
        }
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 688 "diksam.y"
    {
            (yyval.expression_list) = dkc_create_expression_list((yyvsp[(1) - (1)].expression));
        }
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 692 "diksam.y"
    {
            (yyval.expression_list) = dkc_chain_expression_list((yyvsp[(1) - (3)].expression_list), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 698 "diksam.y"
    {
          (yyval.statement) = dkc_create_expression_statement((yyvsp[(1) - (2)].expression));
        }
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 714 "diksam.y"
    {/*empty line*/
			(yyval.statement)=0;
		}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 720 "diksam.y"
    {
            (yyval.statement) = dkc_create_if_statement((yyvsp[(2) - (4)].expression), (yyvsp[(4) - (4)].block), NULL, NULL);
        }
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 724 "diksam.y"
    {
			//printf("IF-ELSE %d\n",dkc_get_current_compiler()->current_line_number);
            (yyval.statement) = dkc_create_if_statement((yyvsp[(2) - (6)].expression), (yyvsp[(4) - (6)].block), NULL, (yyvsp[(6) - (6)].block));
        }
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 729 "diksam.y"
    {
            (yyval.statement) = dkc_create_if_statement((yyvsp[(2) - (5)].expression), (yyvsp[(4) - (5)].block), (yyvsp[(5) - (5)].elsif), NULL);
        }
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 733 "diksam.y"
    {
            (yyval.statement) = dkc_create_if_statement((yyvsp[(2) - (7)].expression), (yyvsp[(4) - (7)].block), (yyvsp[(5) - (7)].elsif), (yyvsp[(7) - (7)].block));
        }
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 740 "diksam.y"
    {
            (yyval.elsif) = dkc_chain_elsif_list((yyvsp[(1) - (2)].elsif), (yyvsp[(2) - (2)].elsif));
        }
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 746 "diksam.y"
    {
            (yyval.elsif) = dkc_create_elsif((yyvsp[(2) - (4)].expression), (yyvsp[(4) - (4)].block));
        }
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 752 "diksam.y"
    {
            (yyval.identifier) = NULL;
        }
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 756 "diksam.y"
    {
            (yyval.identifier) = (yyvsp[(1) - (2)].identifier);
        }
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 762 "diksam.y"
    {
            (yyval.statement) = dkc_create_switch_statement((yyvsp[(2) - (5)].expression), (yyvsp[(4) - (5)].case_list), (yyvsp[(5) - (5)].block));
        }
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 769 "diksam.y"
    {
            (yyval.case_list) = dkc_chain_case((yyvsp[(1) - (2)].case_list), (yyvsp[(2) - (2)].case_list));
        }
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 775 "diksam.y"
    {
            (yyval.case_list) = dkc_create_one_case((yyvsp[(2) - (3)].expression_list), (yyvsp[(3) - (3)].block));
        }
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 781 "diksam.y"
    {
            (yyval.block) = NULL;
        }
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 785 "diksam.y"
    {
            (yyval.block) = (yyvsp[(2) - (2)].block);
        }
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 791 "diksam.y"
    {
            (yyval.expression_list) = dkc_create_expression_list((yyvsp[(1) - (1)].expression));
        }
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 795 "diksam.y"
    {
            (yyval.expression_list) = dkc_chain_expression_list((yyvsp[(1) - (3)].expression_list), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 801 "diksam.y"
    {
            (yyval.statement) = dkc_create_while_statement((yyvsp[(1) - (4)].identifier), (yyvsp[(3) - (4)].expression), (yyvsp[(4) - (4)].block));
        }
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 807 "diksam.y"
    {
            (yyval.statement) = dkc_create_for_statement((yyvsp[(1) - (8)].identifier), (yyvsp[(3) - (8)].expression), (yyvsp[(5) - (8)].expression), (yyvsp[(7) - (8)].expression), (yyvsp[(8) - (8)].block));
        }
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 813 "diksam.y"
    {
            (yyval.statement) = dkc_create_do_while_statement((yyvsp[(1) - (8)].identifier), (yyvsp[(3) - (8)].block), (yyvsp[(6) - (8)].expression));
        }
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 819 "diksam.y"
    {
            (yyval.statement) = dkc_create_foreach_statement((yyvsp[(1) - (8)].identifier), (yyvsp[(4) - (8)].identifier), (yyvsp[(6) - (8)].expression), (yyvsp[(8) - (8)].block));
        }
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 825 "diksam.y"
    {
            (yyval.expression) = NULL;
        }
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 832 "diksam.y"
    {
            (yyval.statement) = dkc_create_return_statement((yyvsp[(2) - (3)].expression));
        }
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 838 "diksam.y"
    {
            (yyval.identifier) = NULL;
        }
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 845 "diksam.y"
    {
            (yyval.statement) = dkc_create_break_statement((yyvsp[(2) - (3)].identifier));
        }
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 851 "diksam.y"
    {
            (yyval.statement) = dkc_create_continue_statement((yyvsp[(2) - (3)].identifier));
        }
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 857 "diksam.y"
    {
            (yyval.statement) = dkc_create_try_statement((yyvsp[(2) - (5)].block), (yyvsp[(3) - (5)].catch_clause), (yyvsp[(5) - (5)].block));
        }
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 861 "diksam.y"
    {
            (yyval.statement) = dkc_create_try_statement((yyvsp[(2) - (4)].block), NULL, (yyvsp[(4) - (4)].block));
        }
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 865 "diksam.y"
    {
            (yyval.statement) = dkc_create_try_statement((yyvsp[(2) - (3)].block), (yyvsp[(3) - (3)].catch_clause), NULL);
        }
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 872 "diksam.y"
    {
            (yyval.catch_clause) = dkc_chain_catch_list((yyvsp[(1) - (2)].catch_clause), (yyvsp[(2) - (2)].catch_clause));
        }
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 878 "diksam.y"
    {
            (yyval.catch_clause) = dkc_start_catch_clause();
        }
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 882 "diksam.y"
    {
            (yyval.catch_clause) = dkc_end_catch_clause((yyvsp[(2) - (5)].catch_clause), (yyvsp[(3) - (5)].type_specifier), (yyvsp[(4) - (5)].identifier), (yyvsp[(5) - (5)].block));
        }
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 888 "diksam.y"
    {
            (yyval.statement) = dkc_create_throw_statement((yyvsp[(2) - (3)].expression));
        }
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 892 "diksam.y"
    {
            (yyval.statement) = dkc_create_throw_statement(NULL);
        }
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 898 "diksam.y"
    {
            (yyval.statement) = dkc_create_declaration_statement(DVM_FALSE, (yyvsp[(5) - (6)].type_specifier), (yyvsp[(2) - (6)].identifier), NULL,(yyvsp[(4) - (6)].intval));
        }
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 902 "diksam.y"
    {
            (yyval.statement) = dkc_create_declaration_statement(DVM_FALSE, (yyvsp[(5) - (8)].type_specifier), (yyvsp[(2) - (8)].identifier), (yyvsp[(7) - (8)].expression),(yyvsp[(4) - (8)].intval));
        }
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 906 "diksam.y"
    {
            (yyval.statement) = dkc_create_declaration_statement(DVM_FALSE, (yyvsp[(4) - (5)].type_specifier), (yyvsp[(2) - (5)].identifier), NULL,DVM_FALSE);
        }
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 910 "diksam.y"
    {
            (yyval.statement) = dkc_create_declaration_statement(DVM_TRUE, (yyvsp[(4) - (7)].type_specifier), (yyvsp[(2) - (7)].identifier), (yyvsp[(6) - (7)].expression),DVM_FALSE);
        }
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 916 "diksam.y"
    {
            (yyval.block) = dkc_open_block(0);
        }
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 920 "diksam.y"
    {
            (yyval.block) = dkc_close_block((yyvsp[(2) - (4)].block), (yyvsp[(3) - (4)].statement_list));
        }
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 924 "diksam.y"
    {
            Block *empty_block = dkc_open_block(0);
            (yyval.block) = dkc_close_block(empty_block, NULL);
        }
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 931 "diksam.y"
    {
            (yyval.template_def) = dkc_create_template_declare_list((yyvsp[(1) - (1)].identifier),NULL);
        }
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 935 "diksam.y"
    {
            (yyval.template_def) = dkc_chain_template_declare_list((yyvsp[(1) - (3)].template_def), (yyvsp[(3) - (3)].identifier),NULL);
        }
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 939 "diksam.y"
    {
            (yyval.template_def) = dkc_create_template_declare_list((yyvsp[(1) - (3)].identifier),(yyvsp[(3) - (3)].type_specifier));
        }
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 943 "diksam.y"
    {
            (yyval.template_def) = dkc_chain_template_declare_list((yyvsp[(1) - (5)].template_def), (yyvsp[(3) - (5)].identifier) ,(yyvsp[(5) - (5)].type_specifier));
        }
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 949 "diksam.y"
    {
			(yyval.template_def)=(yyvsp[(2) - (3)].template_def);
		}
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 953 "diksam.y"
    {(yyval.template_def)=NULL;}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 958 "diksam.y"
    {
            dkc_start_class_definition((yyvsp[(1) - (6)].intval),NULL, (yyvsp[(2) - (6)].class_or_interface), (yyvsp[(3) - (6)].identifier),(yyvsp[(4) - (6)].template_def), (yyvsp[(5) - (6)].extends_list));
        }
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 962 "diksam.y"
    {
            dkc_class_define((yyvsp[(8) - (9)].member_declaration));
        }
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 967 "diksam.y"
    {
            dkc_start_class_definition((yyvsp[(1) - (7)].intval),&(yyvsp[(2) - (7)].class_or_member_modifier), (yyvsp[(3) - (7)].class_or_interface), (yyvsp[(4) - (7)].identifier),(yyvsp[(5) - (7)].template_def), (yyvsp[(6) - (7)].extends_list));
        }
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 970 "diksam.y"
    {
            dkc_class_define((yyvsp[(9) - (10)].member_declaration));
        }
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 974 "diksam.y"
    {
            dkc_start_class_definition((yyvsp[(1) - (6)].intval),NULL, (yyvsp[(2) - (6)].class_or_interface), (yyvsp[(3) - (6)].identifier),(yyvsp[(4) - (6)].template_def), (yyvsp[(5) - (6)].extends_list));
        }
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 978 "diksam.y"
    {
            dkc_class_define(NULL);
        }
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 983 "diksam.y"
    {
            dkc_start_class_definition((yyvsp[(1) - (7)].intval),&(yyvsp[(2) - (7)].class_or_member_modifier), (yyvsp[(3) - (7)].class_or_interface), (yyvsp[(4) - (7)].identifier),(yyvsp[(5) - (7)].template_def), (yyvsp[(6) - (7)].extends_list));
        }
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 987 "diksam.y"
    {
            dkc_class_define(NULL);
        }
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 994 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_chain_class_or_member_modifier((yyvsp[(1) - (2)].class_or_member_modifier), (yyvsp[(2) - (2)].class_or_member_modifier));
        }
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 1001 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(VIRTUAL_MODIFIER);
        }
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 1005 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(OVERRIDE_MODIFIER);
        }
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 1009 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(ABSTRACT_MODIFIER);
        }
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 1015 "diksam.y"
    {
            (yyval.class_or_interface) = DVM_CLASS_DEFINITION;
        }
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 1019 "diksam.y"
    {
            (yyval.class_or_interface) = DVM_INTERFACE_DEFINITION;
        }
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 1025 "diksam.y"
    {
            (yyval.extends_list) = NULL;
        }
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 1029 "diksam.y"
    {
            (yyval.extends_list) = (yyvsp[(2) - (2)].extends_list);
        }
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 1035 "diksam.y"
    {
            (yyval.extends_list) = dkc_create_extends_list((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 1039 "diksam.y"
    {
            (yyval.extends_list) = dkc_chain_extends_list((yyvsp[(1) - (3)].extends_list), (yyvsp[(3) - (3)].identifier));
        }
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 1046 "diksam.y"
    {
            (yyval.member_declaration) = dkc_chain_member_declaration((yyvsp[(1) - (2)].member_declaration), (yyvsp[(2) - (2)].member_declaration));
        }
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 1056 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_method_member(NULL, (yyvsp[(1) - (1)].function_definition), DVM_FALSE);
        }
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 1060 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_method_member(&(yyvsp[(1) - (2)].class_or_member_modifier), (yyvsp[(2) - (2)].function_definition), DVM_FALSE);
        }
    break;

  case 238:

/* Line 1455 of yacc.c  */
#line 1064 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_method_member(NULL, (yyvsp[(1) - (1)].function_definition), DVM_TRUE);
        }
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 1068 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_method_member(&(yyvsp[(1) - (2)].class_or_member_modifier), (yyvsp[(2) - (2)].function_definition), DVM_TRUE);
        }
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 1074 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define((yyvsp[(7) - (9)].type_specifier), (yyvsp[(2) - (9)].identifier), (yyvsp[(4) - (9)].parameter_list), (yyvsp[(8) - (9)].exception_list), (yyvsp[(9) - (9)].block));
        }
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 1078 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define((yyvsp[(6) - (8)].type_specifier), (yyvsp[(2) - (8)].identifier), NULL, (yyvsp[(7) - (8)].exception_list), (yyvsp[(8) - (8)].block));
        }
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 1082 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define((yyvsp[(8) - (10)].type_specifier), (yyvsp[(3) - (10)].identifier), (yyvsp[(5) - (10)].parameter_list), (yyvsp[(9) - (10)].exception_list), NULL);
        }
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 1086 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define((yyvsp[(7) - (9)].type_specifier), (yyvsp[(3) - (9)].identifier), NULL, (yyvsp[(8) - (9)].exception_list), NULL);
        }
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 1090 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define(0, (yyvsp[(2) - (7)].identifier), (yyvsp[(4) - (7)].parameter_list), (yyvsp[(6) - (7)].exception_list), (yyvsp[(7) - (7)].block));
        }
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 1094 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define(0, (yyvsp[(2) - (6)].identifier), NULL, (yyvsp[(5) - (6)].exception_list), (yyvsp[(6) - (6)].block));
        }
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 1098 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define(0, (yyvsp[(3) - (8)].identifier), (yyvsp[(5) - (8)].parameter_list), (yyvsp[(7) - (8)].exception_list), NULL);
        }
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 1102 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define(0, (yyvsp[(3) - (7)].identifier), NULL, (yyvsp[(6) - (7)].exception_list), NULL);
        }
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 1108 "diksam.y"
    {
			(yyval.intval)=0;
		}
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 1112 "diksam.y"
    {
			(yyval.intval)=1;
		}
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 1118 "diksam.y"
    {
            (yyval.exception_list) = NULL;
        }
    break;

  case 251:

/* Line 1455 of yacc.c  */
#line 1122 "diksam.y"
    {
            (yyval.exception_list) = (yyvsp[(2) - (2)].exception_list);
        }
    break;

  case 252:

/* Line 1455 of yacc.c  */
#line 1128 "diksam.y"
    {
            (yyval.exception_list) = dkc_create_throws((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 253:

/* Line 1455 of yacc.c  */
#line 1132 "diksam.y"
    {
            (yyval.exception_list) = dkc_chain_exception_list((yyvsp[(1) - (3)].exception_list), (yyvsp[(3) - (3)].identifier));
        }
    break;

  case 254:

/* Line 1455 of yacc.c  */
#line 1138 "diksam.y"
    {
            (yyval.function_definition) = dkc_constructor_function_define((yyvsp[(2) - (7)].identifier), (yyvsp[(4) - (7)].parameter_list), (yyvsp[(6) - (7)].exception_list), (yyvsp[(7) - (7)].block));
        }
    break;

  case 255:

/* Line 1455 of yacc.c  */
#line 1142 "diksam.y"
    {
            (yyval.function_definition) = dkc_constructor_function_define((yyvsp[(2) - (6)].identifier), NULL, (yyvsp[(5) - (6)].exception_list), (yyvsp[(6) - (6)].block));
        }
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 1146 "diksam.y"
    {
            (yyval.function_definition) = dkc_constructor_function_define((yyvsp[(3) - (8)].identifier), (yyvsp[(5) - (8)].parameter_list), (yyvsp[(7) - (8)].exception_list), NULL);
        }
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 1150 "diksam.y"
    {
            (yyval.function_definition) = dkc_constructor_function_define((yyvsp[(3) - (7)].identifier), NULL, (yyvsp[(6) - (7)].exception_list), NULL);
        }
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 1156 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(PUBLIC_MODIFIER);
        }
    break;

  case 259:

/* Line 1455 of yacc.c  */
#line 1160 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(PRIVATE_MODIFIER);
        }
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 1166 "diksam.y"
    {
            (yyval.expression) = NULL;
        }
    break;

  case 261:

/* Line 1455 of yacc.c  */
#line 1170 "diksam.y"
    {
            (yyval.expression) = (yyvsp[(2) - (2)].expression);
        }
    break;

  case 262:

/* Line 1455 of yacc.c  */
#line 1176 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(NULL, DVM_FALSE, (yyvsp[(4) - (6)].type_specifier), (yyvsp[(2) - (6)].identifier), (yyvsp[(5) - (6)].expression));
        }
    break;

  case 263:

/* Line 1455 of yacc.c  */
#line 1181 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(&(yyvsp[(1) - (6)].class_or_member_modifier), DVM_FALSE, (yyvsp[(4) - (6)].type_specifier), (yyvsp[(2) - (6)].identifier), (yyvsp[(5) - (6)].expression));
        }
    break;

  case 264:

/* Line 1455 of yacc.c  */
#line 1185 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(NULL, DVM_TRUE, (yyvsp[(4) - (6)].type_specifier), (yyvsp[(2) - (6)].identifier), (yyvsp[(5) - (6)].expression));
        }
    break;

  case 265:

/* Line 1455 of yacc.c  */
#line 1190 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(&(yyvsp[(1) - (7)].class_or_member_modifier), DVM_TRUE, (yyvsp[(5) - (7)].type_specifier), (yyvsp[(3) - (7)].identifier), (yyvsp[(6) - (7)].expression));
        }
    break;

  case 266:

/* Line 1455 of yacc.c  */
#line 1194 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(&(yyvsp[(2) - (7)].class_or_member_modifier), DVM_TRUE, (yyvsp[(5) - (7)].type_specifier), (yyvsp[(3) - (7)].identifier), (yyvsp[(6) - (7)].expression));
        }
    break;

  case 267:

/* Line 1455 of yacc.c  */
#line 1200 "diksam.y"
    {
            dkc_create_delegate_definition((yyvsp[(8) - (10)].type_specifier), (yyvsp[(2) - (10)].identifier), (yyvsp[(4) - (10)].parameter_list), (yyvsp[(9) - (10)].exception_list),(yyvsp[(5) - (10)].intval));
        }
    break;

  case 268:

/* Line 1455 of yacc.c  */
#line 1204 "diksam.y"
    {
            dkc_create_delegate_definition((yyvsp[(7) - (9)].type_specifier), (yyvsp[(2) - (9)].identifier), NULL, (yyvsp[(8) - (9)].exception_list),(yyvsp[(4) - (9)].intval));
        }
    break;

  case 269:

/* Line 1455 of yacc.c  */
#line 1210 "diksam.y"
    {
            dkc_create_enum_definition((yyvsp[(2) - (5)].identifier), (yyvsp[(4) - (5)].enumerator));
        }
    break;

  case 270:

/* Line 1455 of yacc.c  */
#line 1214 "diksam.y"
    {
            dkc_create_enum_definition((yyvsp[(2) - (6)].identifier), (yyvsp[(4) - (6)].enumerator));
        }
    break;

  case 271:

/* Line 1455 of yacc.c  */
#line 1220 "diksam.y"
    {
            (yyval.enumerator) = dkc_create_enumerator((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 272:

/* Line 1455 of yacc.c  */
#line 1224 "diksam.y"
    {
            (yyval.enumerator) = dkc_chain_enumerator((yyvsp[(1) - (3)].enumerator), (yyvsp[(3) - (3)].identifier));
        }
    break;

  case 273:

/* Line 1455 of yacc.c  */
#line 1230 "diksam.y"
    {
            dkc_create_const_definition(NULL, (yyvsp[(2) - (5)].identifier), (yyvsp[(4) - (5)].expression));
        }
    break;

  case 274:

/* Line 1455 of yacc.c  */
#line 1234 "diksam.y"
    {
            dkc_create_const_definition((yyvsp[(2) - (4)].type_specifier), (yyvsp[(3) - (4)].identifier), NULL);
        }
    break;

  case 275:

/* Line 1455 of yacc.c  */
#line 1240 "diksam.y"
    {
			(yyval.intval)=0;
		}
    break;

  case 276:

/* Line 1455 of yacc.c  */
#line 1244 "diksam.y"
    {
			(yyval.intval)=1;
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
#line 1268 "diksam.y"
    {
			(yyval.intval)=-1;
		}
    break;

  case 282:

/* Line 1455 of yacc.c  */
#line 1274 "diksam.y"
    {
            (yyval.block) = dkc_open_block((yyvsp[(2) - (2)].intval));
			//printf("E1 %d\n",dkc_get_current_compiler());
        }
    break;

  case 283:

/* Line 1455 of yacc.c  */
#line 1279 "diksam.y"
    {
            (yyval.block) = dkc_close_block((yyvsp[(3) - (5)].block), (yyvsp[(4) - (5)].statement_list));
			//printf("C1 %d\n",dkc_get_current_compiler()->current_line_number);
        }
    break;

  case 284:

/* Line 1455 of yacc.c  */
#line 1284 "diksam.y"
    {
            Block *empty_block = dkc_open_block(0);
            (yyval.block) = dkc_close_block(empty_block, NULL);
			//printf("C2 %d\n",dkc_get_current_compiler()->current_line_number);
        }
    break;



/* Line 1455 of yacc.c  */
#line 4323 "y.tab.c"
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
#line 1290 "diksam.y"


