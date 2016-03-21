
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
#define YYLAST   1013

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  109
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  102
/* YYNRULES -- Number of rules.  */
#define YYNRULES  286
/* YYNRULES -- Number of states.  */
#define YYNSTATES  619

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
     365,   370,   375,   382,   389,   393,   398,   402,   406,   411,
     413,   415,   417,   419,   421,   423,   425,   427,   429,   431,
     436,   441,   447,   454,   462,   466,   471,   476,   482,   487,
     493,   498,   504,   506,   509,   513,   516,   520,   521,   523,
     527,   530,   532,   534,   536,   538,   540,   542,   544,   546,
     548,   550,   552,   554,   556,   561,   568,   574,   582,   584,
     587,   592,   593,   596,   602,   604,   607,   611,   612,   615,
     617,   621,   626,   635,   644,   653,   654,   656,   660,   661,
     663,   667,   671,   677,   682,   686,   688,   691,   692,   698,
     702,   705,   712,   721,   727,   735,   736,   741,   744,   746,
     750,   754,   760,   764,   765,   766,   776,   777,   788,   789,
     798,   799,   809,   811,   814,   816,   818,   820,   822,   824,
     826,   827,   830,   832,   836,   838,   841,   843,   845,   847,
     850,   852,   855,   865,   874,   885,   895,   903,   910,   919,
     927,   928,   931,   932,   935,   937,   941,   949,   956,   965,
     973,   975,   977,   978,   981,   988,   995,  1002,  1010,  1018,
    1029,  1039,  1045,  1052,  1054,  1058,  1064,  1069,  1070,  1072,
    1073,  1075,  1076,  1079,  1082,  1083,  1089
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
       7,    27,   133,    28,    -1,     7,    27,   133,    30,   133,
      28,    -1,   145,    27,   133,    30,   133,    28,    -1,   144,
      53,     7,    -1,   144,    23,   131,    24,    -1,   144,    23,
      24,    -1,    23,   133,    24,    -1,   144,    87,   123,    88,
      -1,     3,    -1,     4,    -1,     5,    -1,     6,    -1,    50,
      -1,    51,    -1,    22,    -1,   146,    -1,    83,    -1,    84,
      -1,    73,    89,    23,    24,    -1,    73,     7,    23,    24,
      -1,    73,     7,    23,   131,    24,    -1,    73,     7,    53,
       7,    23,    24,    -1,    73,     7,    53,     7,    23,   131,
      24,    -1,    25,   151,    26,    -1,    25,   151,    31,    26,
      -1,    73,   118,   148,   207,    -1,    73,   118,   148,   150,
     207,    -1,    73,   119,   148,   207,    -1,    73,   119,   148,
     150,   207,    -1,    73,   122,   148,   207,    -1,    73,   122,
     148,   150,   207,    -1,   149,    -1,   148,   149,    -1,    27,
     133,    28,    -1,    27,    28,    -1,   150,    27,    28,    -1,
      -1,   134,    -1,   151,    31,   134,    -1,   133,    98,    -1,
     153,    -1,   157,    -1,   162,    -1,   163,    -1,   164,    -1,
     165,    -1,   167,    -1,   169,    -1,   170,    -1,   171,    -1,
     175,    -1,   176,    -1,    98,    -1,     9,   133,    95,   209,
      -1,     9,   133,    95,   209,    10,   209,    -1,     9,   133,
      95,   209,   154,    -1,     9,   133,    95,   209,   154,    10,
     209,    -1,   155,    -1,   154,   155,    -1,    11,   133,    95,
     209,    -1,    -1,     7,    30,    -1,    12,   133,    98,   158,
     160,    -1,   159,    -1,   158,   159,    -1,    13,   161,   209,
      -1,    -1,    14,   209,    -1,   134,    -1,   151,    31,   134,
      -1,   156,    15,   133,   209,    -1,   156,    17,   166,    29,
     166,    29,   166,   209,    -1,   156,    16,   177,    15,    23,
     133,    24,    98,    -1,   156,    18,    23,     7,    30,   133,
      24,   177,    -1,    -1,   133,    -1,    19,   166,    98,    -1,
      -1,     7,    -1,    20,   168,    98,    -1,    21,   168,    98,
      -1,    61,   209,   172,    63,   209,    -1,    61,   209,    63,
     177,    -1,    61,   209,   172,    -1,   173,    -1,   172,   173,
      -1,    -1,    62,   174,   123,     7,   209,    -1,    64,   133,
      98,    -1,    64,    98,    -1,    96,     7,    94,   206,   123,
      98,    -1,    96,     7,    94,   206,   123,    32,   133,    98,
      -1,    90,     7,    94,   123,    98,    -1,    90,     7,    94,
     123,    32,   133,    98,    -1,    -1,    25,   178,   132,    26,
      -1,    25,    26,    -1,     7,    -1,   179,    31,     7,    -1,
       7,    30,   119,    -1,   179,    31,     7,    30,   119,    -1,
      39,   179,    37,    -1,    -1,    -1,   206,   188,     7,   180,
     189,    98,   182,   191,    97,    -1,    -1,   206,   186,   188,
       7,   180,   189,    98,   183,   191,    97,    -1,    -1,   206,
     188,     7,   180,   189,    98,   184,    97,    -1,    -1,   206,
     186,   188,     7,   180,   189,    98,   185,    97,    -1,   187,
      -1,   186,   187,    -1,   199,    -1,    80,    -1,    81,    -1,
      82,    -1,    76,    -1,    77,    -1,    -1,    30,   190,    -1,
       7,    -1,   190,    31,     7,    -1,   192,    -1,   191,   192,
      -1,   193,    -1,   201,    -1,   194,    -1,   186,   194,    -1,
     198,    -1,   186,   198,    -1,    93,     7,    23,   130,    24,
      94,   123,   196,   209,    -1,    93,     7,    23,    24,    94,
     123,   196,   209,    -1,    99,    93,     7,    23,   130,    24,
      94,   123,   196,    98,    -1,    99,    93,     7,    23,    24,
      94,   123,   196,    98,    -1,   100,     7,    23,   130,    24,
     196,   209,    -1,   100,     7,    23,    24,   196,   209,    -1,
      99,   100,     7,    23,   130,    24,   196,    98,    -1,    99,
     100,     7,    23,    24,   196,    98,    -1,    -1,    31,   101,
      -1,    -1,    65,   197,    -1,     7,    -1,   197,    31,     7,
      -1,    85,     7,    23,   130,    24,   196,   209,    -1,    85,
       7,    23,    24,   196,   209,    -1,    99,    85,     7,    23,
     130,    24,   196,    98,    -1,    99,    85,     7,    23,    24,
     196,    98,    -1,    78,    -1,    79,    -1,    -1,    32,   133,
      -1,    96,     7,    94,   123,   200,    98,    -1,   186,     7,
      94,   123,   200,    98,    -1,    90,     7,    94,   123,   200,
      98,    -1,   186,    90,     7,    94,   123,   200,    98,    -1,
      90,   186,     7,    94,   123,   200,    98,    -1,    89,     7,
      23,   130,   195,    24,    94,   123,   196,    98,    -1,    89,
       7,    23,   195,    24,    94,   123,   196,    98,    -1,    91,
       7,    25,   204,    26,    -1,    91,     7,    25,   204,    31,
      26,    -1,     7,    -1,   204,    31,     7,    -1,    92,     7,
      32,   133,    98,    -1,    92,   123,     7,    98,    -1,    -1,
     105,    -1,    -1,   106,    -1,    -1,   103,    98,    -1,   104,
      98,    -1,    -1,    98,   208,   210,   132,    97,    -1,    98,
      97,    -1
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
     546,   550,   555,   560,   564,   568,   572,   576,   580,   584,
     585,   586,   587,   588,   592,   596,   600,   601,   605,   609,
     613,   617,   621,   625,   631,   635,   641,   645,   649,   653,
     658,   662,   668,   669,   675,   681,   685,   693,   696,   700,
     706,   710,   711,   712,   713,   714,   715,   716,   717,   718,
     719,   720,   721,   722,   728,   732,   737,   741,   747,   748,
     754,   761,   764,   770,   776,   777,   783,   790,   793,   799,
     803,   809,   815,   821,   827,   834,   837,   840,   847,   850,
     853,   859,   865,   869,   873,   879,   880,   887,   886,   896,
     900,   906,   910,   914,   918,   925,   924,   932,   939,   943,
     947,   951,   957,   962,   967,   965,   976,   974,   983,   982,
     992,   990,  1001,  1002,  1008,  1009,  1013,  1017,  1023,  1027,
    1034,  1037,  1043,  1047,  1053,  1054,  1060,  1061,  1064,  1068,
    1072,  1076,  1082,  1086,  1090,  1094,  1098,  1102,  1106,  1110,
    1117,  1120,  1127,  1130,  1136,  1140,  1146,  1150,  1154,  1158,
    1164,  1168,  1175,  1178,  1184,  1188,  1193,  1197,  1202,  1208,
    1212,  1218,  1222,  1228,  1232,  1238,  1242,  1249,  1252,  1259,
    1262,  1269,  1272,  1276,  1283,  1282,  1292
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
     145,   145,   145,   145,   146,   146,   147,   147,   147,   147,
     147,   147,   148,   148,   149,   150,   150,   151,   151,   151,
     152,   152,   152,   152,   152,   152,   152,   152,   152,   152,
     152,   152,   152,   152,   153,   153,   153,   153,   154,   154,
     155,   156,   156,   157,   158,   158,   159,   160,   160,   161,
     161,   162,   163,   164,   165,   166,   166,   167,   168,   168,
     169,   170,   171,   171,   171,   172,   172,   174,   173,   175,
     175,   176,   176,   176,   176,   178,   177,   177,   179,   179,
     179,   179,   180,   180,   182,   181,   183,   181,   184,   181,
     185,   181,   186,   186,   187,   187,   187,   187,   188,   188,
     189,   189,   190,   190,   191,   191,   192,   192,   193,   193,
     193,   193,   194,   194,   194,   194,   194,   194,   194,   194,
     195,   195,   196,   196,   197,   197,   198,   198,   198,   198,
     199,   199,   200,   200,   201,   201,   201,   201,   201,   202,
     202,   203,   203,   204,   204,   205,   205,   206,   206,   207,
     207,   208,   208,   208,   210,   209,   209
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
       2,     6,     8,     5,     7,     0,     4,     2,     1,     3,
       3,     5,     3,     0,     0,     9,     0,    10,     0,     8,
       0,     9,     1,     2,     1,     1,     1,     1,     1,     1,
       0,     2,     1,     3,     1,     2,     1,     1,     1,     2,
       1,     2,     9,     8,    10,     9,     7,     6,     8,     7,
       0,     2,     0,     2,     1,     3,     7,     6,     8,     7,
       1,     1,     0,     2,     6,     6,     6,     7,     7,    10,
       9,     5,     6,     1,     3,     5,     4,     0,     1,     0,
       1,     0,     2,     2,     0,     5,     2
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
       0,     0,     0,   163,     0,     0,   278,     3,    57,    17,
       0,    64,    66,    76,    78,    80,    83,    88,    91,    98,
     102,   106,   126,   107,    19,   151,     0,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,    18,    20,
      21,    22,     0,     0,     8,    10,     5,    15,     0,    11,
       0,     0,   172,   108,     0,     0,   186,     0,   189,     0,
       0,     0,   148,     0,    99,   102,   101,   100,   281,     0,
     200,     0,    31,    23,    24,    25,    26,    27,    28,    29,
      30,     0,     0,     0,     0,     0,     0,    31,    30,    38,
      40,   279,    39,    41,     0,     0,     0,     0,     0,     0,
       0,   150,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    68,
       0,    69,    70,    73,    74,    75,   103,   104,     0,     0,
      71,    72,     0,     0,     0,     0,   185,     0,   228,   229,
     260,   261,   225,   226,   227,     0,   222,     0,   224,    44,
      13,    16,     0,     0,     0,   187,   190,   191,   117,   134,
       0,   286,     0,     0,   284,   197,     0,   194,   195,   199,
       0,     0,     0,     0,     0,   279,   142,   279,   279,   250,
       0,     0,     0,     0,     0,   280,    36,     0,     0,     0,
     250,   277,     0,     0,   250,    65,    77,    79,    81,    82,
      84,    85,    86,    87,    89,    90,    92,    93,    94,    95,
      96,    97,   116,     0,    60,   114,    31,   105,     0,    67,
       0,     0,   205,     0,     0,     0,   223,     0,   213,     0,
     111,     0,   164,   147,   177,   174,   135,   149,   282,   283,
     171,     0,   193,     0,   196,   130,     0,    42,     0,     0,
     129,     0,     0,   143,   279,   136,   279,   138,   279,   140,
       0,     0,   250,     0,     0,   273,     0,    33,     0,    32,
      34,    35,   276,   250,     0,     0,   250,   250,   250,     0,
     115,     0,   118,   110,     0,   181,   207,   171,     0,   185,
       0,   213,     0,   230,    46,     0,     0,     0,   166,   168,
     148,     0,     0,     0,   175,   173,   171,    62,     0,   192,
     131,     0,    37,     0,   144,   145,     0,   137,   139,   141,
       0,   251,     0,     0,     0,     0,   203,   271,     0,   275,
       0,     0,     0,   250,     0,   250,     0,     0,   252,    61,
       0,   171,     0,     0,     0,   230,   208,     0,     0,     0,
     277,   112,   165,     0,     0,   169,     0,   176,   178,   285,
      63,     0,    43,   132,     0,   146,    58,     0,     0,     0,
       0,   274,   272,     0,     0,     0,   201,     0,     0,     0,
     252,   252,     0,     0,   113,   206,     0,   185,     0,     0,
       0,     0,   212,   232,   231,   214,    45,    47,    48,     0,
     167,   149,   198,   133,     0,     0,   252,   204,     0,   252,
       0,     0,     0,   252,     0,     0,   254,   253,    56,     0,
       0,     0,   216,    31,   210,   209,     0,     0,     0,   170,
      59,   252,     0,   252,     0,   202,     0,   252,     0,    52,
      55,     0,   183,   182,   184,     0,     0,     0,   233,     0,
       0,     0,     0,     0,     0,     0,     0,   234,   236,   238,
     240,   237,   219,     0,   270,     0,    54,   252,     0,    51,
     255,     0,   221,   211,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   239,   241,   215,   235,   269,
      53,     0,    50,   217,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    49,   252,     0,   262,     0,
       0,     0,   262,     0,     0,     0,   252,     0,   262,     0,
       0,   252,     0,     0,     0,   262,     0,     0,     0,   252,
       0,     0,     0,   252,     0,     0,   252,     0,   262,   257,
       0,   263,   266,     0,   252,     0,   264,     0,   252,     0,
       0,     0,   252,   247,     0,   265,     0,   256,   268,     0,
     252,   259,     0,   252,     0,   249,     0,   246,   267,   243,
       0,   258,     0,   252,   248,   242,   245,     0,   244
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,     6,    10,     7,     8,    47,   129,
     130,   131,   132,   133,   134,   288,    84,   269,   390,    48,
      49,   302,   253,   346,    50,    51,   172,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,   215,
     216,   294,   103,   347,    65,   338,   339,    66,    67,   274,
     275,   345,   342,    68,    69,    70,    71,    97,    72,    99,
      73,    74,    75,   207,   208,   281,    76,    77,   263,   327,
     387,   333,    78,   467,   485,   468,   486,   495,   186,   187,
     389,   434,   496,   497,   498,   499,   303,   423,   457,   500,
     188,   564,   501,    79,    80,   306,    81,    82,   226,   204,
     109,   280
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -395
static const yytype_int16 yypact[] =
{
      74,    44,    44,   426,   -78,    74,  -395,    -4,  -395,  -395,
     -25,    22,  -395,  -395,  -395,  -395,  -395,   294,  -395,   929,
     929,   929,   111,   111,  -395,   929,   929,   929,   929,  -395,
    -395,   929,    60,   773,    67,  -395,  -395,   120,   170,   178,
     231,   182,   190,  -395,   -13,   205,  -395,  -395,  -395,  -395,
     -10,  -395,   219,   235,   185,   269,   311,   562,  -395,  -395,
       7,   277,  -395,  -395,  -395,  -395,   299,  -395,  -395,  -395,
    -395,  -395,  -395,  -395,  -395,  -395,  -395,  -395,  -395,  -395,
    -395,  -395,   256,   283,  -395,  -395,    -4,  -395,   304,  -395,
     227,   929,  -395,   312,     2,    -9,   310,   250,  -395,   270,
     274,   137,  -395,    59,  -395,   155,  -395,  -395,   113,   320,
    -395,    -6,    31,  -395,  -395,  -395,  -395,  -395,  -395,  -395,
     337,   357,   357,   357,   364,   297,   380,   161,  -395,   392,
    -395,   308,   395,   396,   413,   401,   334,   429,   430,   416,
     929,  -395,   929,   929,   929,   929,   929,   929,   929,   929,
     929,   929,   929,   929,   929,   929,   929,   929,   785,  -395,
     443,  -395,  -395,  -395,  -395,  -395,  -395,  -395,   391,   391,
    -395,  -395,   929,   929,   929,   427,   929,   431,  -395,  -395,
    -395,  -395,  -395,  -395,  -395,   256,  -395,   446,  -395,  -395,
    -395,  -395,   265,    60,   442,  -395,  -395,  -395,  -395,  -395,
     825,  -395,   366,   367,  -395,  -395,   427,   327,  -395,  -395,
     837,   391,   459,   445,   929,   -15,  -395,   -15,   -15,    50,
     391,   460,   444,   929,   451,  -395,  -395,   453,   463,   372,
      50,   368,   448,   465,    50,  -395,   235,   185,   269,   269,
     311,   311,   311,   311,   562,   562,  -395,  -395,  -395,  -395,
    -395,  -395,  -395,   215,  -395,  -395,    92,  -395,   386,  -395,
     319,     0,   466,   478,   467,   488,  -395,   491,   468,   407,
    -395,   929,   383,   929,   387,  -395,  -395,  -395,  -395,  -395,
     721,   391,  -395,    60,  -395,  -395,   220,  -395,     6,   479,
    -395,   331,   877,  -395,   -11,  -395,   -11,  -395,   -11,  -395,
     412,   410,   481,   484,    14,  -395,   217,  -395,     1,  -395,
    -395,  -395,  -395,   481,   489,   391,    50,    50,   481,   490,
    -395,   929,  -395,  -395,   929,  -395,  -395,   721,   497,   929,
     493,   468,   514,   498,  -395,   336,    60,   929,   393,  -395,
     432,   496,    60,    60,  -395,  -395,   529,  -395,   522,  -395,
    -395,   391,  -395,   889,  -395,  -395,   511,  -395,  -395,  -395,
     391,  -395,     8,   516,   449,   929,  -395,  -395,    42,  -395,
     518,   452,    18,   481,   521,   481,   523,   536,   499,  -395,
     342,   625,   929,   524,   929,   498,   531,    45,   556,   470,
     108,  -395,  -395,     9,    60,  -395,   929,  -395,  -395,  -395,
    -395,    60,  -395,  -395,   223,  -395,  -395,   471,   472,   391,
       3,  -395,  -395,   475,   391,   929,  -395,   548,   494,   551,
     499,   499,   580,    60,  -395,  -395,   239,   929,   243,   500,
     584,   585,  -395,  -395,   564,   502,  -395,  -395,  -395,    60,
    -395,   503,  -395,  -395,   391,   391,   499,  -395,   391,   499,
       4,   517,   391,   499,   519,    60,  -395,   565,  -395,   520,
      60,   427,   525,  -395,  -395,   586,   607,   504,   526,  -395,
    -395,   499,   537,   499,    60,  -395,   391,   499,   538,  -395,
    -395,   608,  -395,  -395,  -395,   504,   527,   584,  -395,   613,
      62,   614,   631,    91,   632,   276,   404,  -395,  -395,  -395,
    -395,  -395,  -395,   542,  -395,    60,  -395,   499,   543,  -395,
    -395,   477,  -395,  -395,   619,   549,   179,   626,   558,   646,
     647,   648,   633,   563,   651,  -395,  -395,  -395,  -395,  -395,
    -395,   561,  -395,  -395,    29,   391,   566,    34,   391,   638,
     639,   640,    79,   391,   570,  -395,   499,   245,   634,   391,
     571,   247,   634,   121,   122,   123,   499,   255,   634,   391,
      60,   499,   661,   929,   572,   634,   391,   575,   573,   499,
     258,   578,   261,   499,   263,    60,   499,   581,   634,  -395,
      60,   310,  -395,   582,   499,   391,  -395,   583,   499,   391,
     579,   587,   499,  -395,    60,  -395,   589,  -395,  -395,    60,
     499,  -395,   590,   499,   391,  -395,   592,  -395,  -395,  -395,
      60,  -395,   593,   499,  -395,  -395,  -395,   594,  -395
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -395,  -395,  -395,  -395,   673,   680,   678,    10,  -395,   650,
     -31,  -395,  -395,   659,  -164,  -395,  -395,  -395,  -395,   305,
    -395,  -211,  -190,   369,   -19,    -8,  -395,  -395,   552,   554,
     262,   181,   259,    17,  -395,    80,  -395,  -395,  -395,   290,
     163,   200,   428,     5,  -395,  -395,   361,  -395,  -395,  -395,
     433,  -395,  -395,  -395,  -395,  -395,  -395,  -163,  -395,   677,
    -395,  -395,  -395,  -395,   495,  -395,  -395,  -395,  -195,  -395,
    -395,   373,   313,  -395,  -395,  -395,  -395,   -75,  -176,   528,
     321,  -395,   225,  -331,  -395,   210,  -192,  -394,  -395,   216,
    -395,  -303,  -395,  -395,  -395,  -395,  -395,   483,   -95,  -395,
    -183,  -395
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -221
static const yytype_int16 yytable[] =
{
      94,    95,    96,   122,   257,   258,   101,   185,    64,   266,
     272,   282,   292,   264,   111,   407,   356,    87,   102,   313,
     286,   140,   140,   318,    83,   140,   454,   455,    88,    90,
     158,   140,   140,   140,   140,   140,   300,   351,   314,   159,
     140,   300,   319,   352,   104,   106,   365,   287,   107,   411,
     415,     9,   472,   546,   210,   474,   304,   300,   550,   478,
     160,   161,   162,   163,   164,   165,   166,   167,   412,   515,
     211,     2,   192,    89,   112,    88,   431,   503,   325,   505,
     137,   301,   432,   508,   212,   199,   300,   138,   141,   194,
     200,   225,   209,   168,   169,   225,    87,   193,   108,   369,
     349,   447,   475,   556,   439,   373,   375,   105,   105,   361,
     363,   105,   366,   531,   170,   171,   416,   348,    98,   222,
     295,   370,   297,   299,   374,   376,   377,   124,   300,   300,
     300,   211,   235,   113,   114,   115,   116,   117,   118,   119,
     180,   181,   182,   183,   184,   569,   571,   573,     1,     2,
     254,   372,   560,   392,   260,   261,   120,    96,   108,   397,
     398,   198,   575,   404,   259,   528,   383,   580,   140,   246,
     247,   248,   249,   250,   251,   587,   519,   125,   158,   591,
     528,   417,   594,   419,   520,   126,   536,   402,   222,   135,
     599,   521,   277,   223,   602,   291,   406,   136,   606,   357,
     211,   358,   254,   359,   308,   436,   610,    44,   160,   612,
     201,   440,   139,    46,   166,   167,   202,   203,   442,   617,
     144,   145,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   127,   320,
     458,   168,   169,   367,   350,   446,   321,   443,   368,   568,
     449,   321,   335,   142,   321,   577,   469,   180,   181,   182,
     183,   184,   583,   459,   460,   340,   484,   461,   143,   561,
     140,   567,   480,   291,   140,   596,   562,   483,   562,   576,
     470,   471,   588,   523,   473,   590,   562,   592,   477,   562,
     189,   506,   562,   270,   562,   271,   140,   113,   114,   115,
     116,   117,   118,   119,   173,   380,   146,   147,   148,   149,
      96,   190,   507,   379,   174,   175,   176,   177,   393,   266,
     128,    91,   530,   547,    92,   191,   551,   240,   241,   242,
     243,   557,   178,   179,   180,   181,   182,   183,   184,    91,
     266,   140,   570,   572,   574,   254,   410,   323,   195,   324,
     140,   400,   150,   151,   180,   181,   182,   183,   184,   354,
     213,   489,   140,   426,   391,   428,   524,   140,   196,   491,
     424,   548,   197,   140,   552,   493,   494,   579,   293,   558,
     293,   293,   205,   206,   214,   565,   400,   219,   441,   205,
     283,   220,   593,   336,   337,   578,   450,   597,   256,   464,
     273,   343,   584,   394,   337,   221,   238,   239,    96,   244,
     245,   607,   217,   218,   225,   516,   609,   296,   298,   224,
     229,   600,   227,   228,   230,   603,    12,   615,   231,    13,
      14,    15,    16,    17,    18,    19,   232,   233,    20,   234,
     613,  -171,  -171,  -171,  -171,    21,    22,    23,    24,    25,
     255,    26,   262,   268,   265,   273,   513,   113,   114,   115,
     116,   117,   118,   119,   278,   279,   289,   305,    27,   290,
     312,   316,   307,    46,   322,    28,    29,    30,    31,   309,
     128,   310,   180,   181,   182,   183,   184,    32,   317,   489,
      33,   311,   326,   328,   490,   330,   329,   491,   331,    34,
     492,   527,   353,   493,   494,   334,   360,   332,   364,    35,
      36,   361,   362,   371,   378,    37,    38,    39,    40,    41,
     382,   386,    42,   384,    43,    44,    45,   396,   388,   401,
    -179,    46,    13,    14,    15,    16,    17,    18,    19,   405,
     408,    20,   413,   409,   581,   418,   414,   420,    21,    22,
      23,    24,    25,   427,    26,   180,   181,   182,   183,   184,
     421,   430,   489,   433,   422,   444,   445,   490,   435,   448,
     491,    27,   451,   492,   533,   453,   493,   494,    28,    29,
      30,    31,   180,   181,   182,   183,   184,   456,   452,   489,
      32,   463,   465,    33,   490,   466,   481,   491,   462,  -218,
     492,  -180,    34,   493,   494,   152,   153,   154,   155,   156,
     157,   476,    35,    36,   488,   510,   487,   479,   482,    38,
     514,   517,  -220,   502,   512,    42,   399,    43,    13,    14,
      15,    16,    17,    18,    19,   504,   509,    20,   518,   522,
     529,   532,   534,   535,    21,    22,    23,    24,    25,   537,
      26,   425,   538,   539,   540,   541,   542,   543,   544,   545,
     549,   553,   554,   555,   559,   566,   563,    27,   407,   585,
     582,   586,   589,   604,    28,    29,    30,    31,    85,   595,
     598,   601,    11,    86,   121,   605,    32,   608,   611,    33,
     614,   616,   618,   123,   236,   437,   381,   237,    34,   395,
     100,   341,   284,   438,   385,   525,   429,   344,    35,    36,
     511,   526,     0,   267,   315,    38,     0,     0,     0,     0,
       0,    42,     0,    43,    13,    14,    15,    16,    17,    18,
      19,     0,     0,    20,     0,     0,     0,     0,     0,     0,
      21,    22,    23,    24,    25,     0,    26,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    27,     0,     0,     0,     0,     0,     0,
      28,    29,    30,    31,     0,     0,    13,    14,    15,    16,
      93,    18,    32,     0,     0,    33,     0,     0,    13,    14,
      15,    16,    93,    18,    34,    24,    25,     0,    26,     0,
       0,     0,     0,     0,    35,    36,     0,    24,    25,   252,
      26,    38,     0,     0,     0,    27,     0,    42,     0,    43,
       0,     0,    28,    29,    30,    31,     0,    27,    13,    14,
      15,    16,    93,    18,    28,    29,    30,    31,     0,     0,
      13,    14,    15,    16,    93,    18,    34,    24,    25,     0,
      26,   276,     0,     0,     0,     0,    35,    36,    34,    24,
      25,   285,    26,     0,     0,     0,     0,    27,    35,    36,
       0,   110,     0,     0,    28,    29,    30,    31,     0,    27,
      13,    14,    15,    16,    93,    18,    28,    29,    30,    31,
       0,     0,    13,    14,    15,    16,    93,    18,    34,    24,
      25,     0,    26,     0,     0,   355,     0,     0,    35,    36,
      34,    24,    25,   403,    26,     0,     0,     0,     0,    27,
      35,    36,     0,     0,     0,     0,    28,    29,    30,    31,
       0,    27,    13,    14,    15,    16,    93,    18,    28,    29,
      30,    31,     0,     0,     0,     0,     0,     0,     0,     0,
      34,    24,    25,     0,    26,     0,     0,     0,     0,     0,
      35,    36,    34,     0,     0,     0,     0,     0,     0,     0,
       0,    27,    35,    36,     0,     0,     0,     0,    28,    29,
      30,    31,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    34,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    35,    36
};

static const yytype_int16 yycheck[] =
{
      19,    20,    21,    34,   168,   169,    25,    82,     3,   185,
     193,   206,    27,   176,    33,     7,    27,     7,    26,   230,
     210,    31,    31,   234,   102,    31,   420,   421,    53,     7,
      23,    31,    31,    31,    31,    31,     7,    31,   230,    32,
      31,     7,   234,    37,    27,    28,    32,   211,    31,     7,
      32,     7,   446,    24,    23,   449,   220,     7,    24,   453,
      53,    54,    55,    56,    57,    58,    59,    60,    26,     7,
      39,    75,    91,    98,     7,    53,    31,   471,   261,   473,
      93,    31,    37,   477,    53,    26,     7,   100,    98,    98,
      31,   106,    98,    86,    87,   106,    86,    95,    98,    98,
     283,    98,    98,    24,    95,   316,   317,    27,    28,   101,
     302,    31,    98,   507,   107,   108,    98,   281,     7,    27,
     215,   313,   217,   218,   316,   317,   318,     7,     7,     7,
       7,    39,   140,    66,    67,    68,    69,    70,    71,    72,
      78,    79,    80,    81,    82,    24,    24,    24,    74,    75,
     158,   315,   546,   336,   173,   174,    89,   176,    98,   342,
     343,    24,   556,   353,   172,   496,   329,   561,    31,   152,
     153,   154,   155,   156,   157,   569,    85,     7,    23,   573,
     511,   373,   576,   375,    93,     7,     7,   351,    27,     7,
     584,   100,   200,    32,   588,   214,   360,     7,   592,   294,
      39,   296,   210,   298,   223,    97,   600,    99,    53,   603,
      97,   394,     7,   105,    59,    60,   103,   104,   401,   613,
      35,    36,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,     7,    24,
     423,    86,    87,    26,    24,   409,    31,    24,    31,   552,
     414,    31,   271,    34,    31,   558,   439,    78,    79,    80,
      81,    82,   565,    24,   427,   273,   461,    24,    33,    24,
      31,    24,   455,   292,    31,   578,    31,   460,    31,    24,
     444,   445,    24,     7,   448,    24,    31,    24,   452,    31,
       7,   474,    31,    28,    31,    30,    31,    66,    67,    68,
      69,    70,    71,    72,    27,   324,    37,    38,    39,    40,
     329,     7,   476,   321,    15,    16,    17,    18,   337,   495,
      89,    27,   505,   534,    30,    98,   537,   146,   147,   148,
     149,   542,    76,    77,    78,    79,    80,    81,    82,    27,
     516,    31,   553,   554,   555,   353,   365,    28,    98,    30,
      31,   346,    41,    42,    78,    79,    80,    81,    82,    28,
      23,    85,    31,   382,    28,   384,    90,    31,    98,    93,
      28,   535,    98,    31,   538,    99,   100,   560,   215,   543,
     217,   218,    62,    63,    27,   549,   381,    23,   396,    62,
      63,    94,   575,    10,    11,   559,   415,   580,     7,   430,
      13,    14,   566,    10,    11,    25,   144,   145,   427,   150,
     151,   594,   122,   123,   106,   490,   599,   217,   218,    27,
       7,   585,    27,    27,    23,   589,     0,   610,    94,     3,
       4,     5,     6,     7,     8,     9,     7,     7,    12,    23,
     604,    15,    16,    17,    18,    19,    20,    21,    22,    23,
       7,    25,    25,     7,    23,    13,   487,    66,    67,    68,
      69,    70,    71,    72,    98,    98,     7,     7,    42,    24,
      98,    23,    28,   105,    88,    49,    50,    51,    52,    28,
      89,    28,    78,    79,    80,    81,    82,    61,    23,    85,
      64,    28,    26,    15,    90,     7,    29,    93,     7,    73,
      96,    97,    23,    99,   100,    98,    94,    39,    24,    83,
      84,   101,    31,    24,    24,    89,    90,    91,    92,    93,
      23,     7,    96,    30,    98,    99,   100,    31,    30,     7,
      98,   105,     3,     4,     5,     6,     7,     8,     9,    28,
      24,    12,    24,    94,   563,    24,    94,    24,    19,    20,
      21,    22,    23,    29,    25,    78,    79,    80,    81,    82,
      24,    30,    85,     7,    65,    94,    94,    90,    98,    94,
      93,    42,    24,    96,    97,    24,    99,   100,    49,    50,
      51,    52,    78,    79,    80,    81,    82,     7,    94,    85,
      61,     7,     7,    64,    90,    31,    31,    93,    98,    97,
      96,    98,    73,    99,   100,    43,    44,    45,    46,    47,
      48,    94,    83,    84,     7,     7,    30,    98,    98,    90,
       7,     7,    97,    97,    97,    96,    97,    98,     3,     4,
       5,     6,     7,     8,     9,    98,    98,    12,     7,     7,
      98,    98,    23,    94,    19,    20,    21,    22,    23,    23,
      25,    26,    94,     7,     7,     7,    23,    94,     7,    98,
      94,    23,    23,    23,    94,    94,    32,    42,     7,    94,
      98,    98,    94,    94,    49,    50,    51,    52,     5,    98,
      98,    98,     2,     5,    34,    98,    61,    98,    98,    64,
      98,    98,    98,    34,   142,   390,   327,   143,    73,   338,
      23,   273,   207,   390,   331,   495,   385,   274,    83,    84,
     485,   495,    -1,   185,   231,    90,    -1,    -1,    -1,    -1,
      -1,    96,    -1,    98,     3,     4,     5,     6,     7,     8,
       9,    -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    20,    21,    22,    23,    -1,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    50,    51,    52,    -1,    -1,     3,     4,     5,     6,
       7,     8,    61,    -1,    -1,    64,    -1,    -1,     3,     4,
       5,     6,     7,     8,    73,    22,    23,    -1,    25,    -1,
      -1,    -1,    -1,    -1,    83,    84,    -1,    22,    23,    24,
      25,    90,    -1,    -1,    -1,    42,    -1,    96,    -1,    98,
      -1,    -1,    49,    50,    51,    52,    -1,    42,     3,     4,
       5,     6,     7,     8,    49,    50,    51,    52,    -1,    -1,
       3,     4,     5,     6,     7,     8,    73,    22,    23,    -1,
      25,    26,    -1,    -1,    -1,    -1,    83,    84,    73,    22,
      23,    24,    25,    -1,    -1,    -1,    -1,    42,    83,    84,
      -1,    98,    -1,    -1,    49,    50,    51,    52,    -1,    42,
       3,     4,     5,     6,     7,     8,    49,    50,    51,    52,
      -1,    -1,     3,     4,     5,     6,     7,     8,    73,    22,
      23,    -1,    25,    -1,    -1,    28,    -1,    -1,    83,    84,
      73,    22,    23,    24,    25,    -1,    -1,    -1,    -1,    42,
      83,    84,    -1,    -1,    -1,    -1,    49,    50,    51,    52,
      -1,    42,     3,     4,     5,     6,     7,     8,    49,    50,
      51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      73,    22,    23,    -1,    25,    -1,    -1,    -1,    -1,    -1,
      83,    84,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    83,    84,    -1,    -1,    -1,    -1,    49,    50,
      51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    83,    84
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
      28,    30,   209,    13,   158,   159,    26,   134,    98,    98,
     210,   174,   177,    63,   173,    24,   131,   123,   124,     7,
      24,   133,    27,   149,   150,   207,   150,   207,   150,   207,
       7,    31,   130,   195,   123,     7,   204,    28,   133,    28,
      28,    28,    98,   130,   195,   206,    23,    23,   130,   195,
      24,    31,    88,    28,    30,   209,    26,   178,    15,    29,
       7,     7,    39,   180,    98,   133,    10,    11,   154,   155,
     134,   151,   161,    14,   159,   160,   132,   152,   123,   209,
      24,    31,    37,    23,    28,    28,    27,   207,   207,   207,
      94,   101,    31,   195,    24,    32,    98,    26,    31,    98,
     195,    24,   123,   130,   195,   130,   195,   195,    24,   134,
     133,   132,    23,   166,    30,   180,     7,   179,    30,   189,
     127,    28,   209,   133,    10,   155,    31,   209,   209,    97,
     152,     7,   123,    24,   131,    28,   123,     7,    24,    94,
     133,     7,    26,    24,    94,    32,    98,   195,    24,   195,
      24,    24,    65,   196,    28,    26,   133,    29,   133,   189,
      30,    31,    37,     7,   190,    98,    97,   128,   181,    95,
     209,   134,   209,    24,    94,    94,   123,    98,    94,   123,
     133,    24,    94,    24,   196,   196,     7,   197,   209,    24,
     166,    24,    98,     7,   119,     7,    31,   182,   184,   209,
     123,   123,   196,   123,   196,    98,    94,   123,   196,    98,
     209,    31,    98,   209,   177,   183,   185,    30,     7,    85,
      90,    93,    96,    99,   100,   186,   191,   192,   193,   194,
     198,   201,    97,   196,    98,   196,   209,   123,   196,    98,
       7,   191,    97,   119,     7,     7,   186,     7,     7,    85,
      93,   100,     7,     7,    90,   194,   198,    97,   192,    98,
     209,   196,    98,    97,    23,    94,     7,    23,    94,     7,
       7,     7,    23,    94,     7,    98,    24,   130,   123,    94,
      24,   130,   123,    23,    23,    23,    24,   130,   123,    94,
     196,    24,    31,    32,   200,   123,    94,    24,   200,    24,
     130,    24,   130,    24,   130,   196,    24,   200,   123,   209,
     196,   133,    98,   200,   123,    94,    98,   196,    24,    94,
      24,   196,    24,   209,   196,    98,   200,   209,    98,   196,
     123,    98,   196,   123,    94,    98,   196,   209,    98,   209,
     196,    98,   196,   123,    98,   209,    98,   196,    98
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
			Expression *identifier = dkc_create_identifier_expression((yyvsp[(1) - (6)].identifier));
			(yyval.expression) = dkc_create_slice_expression(identifier,(yyvsp[(3) - (6)].expression),(yyvsp[(5) - (6)].expression));
		}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 561 "diksam.y"
    {
			(yyval.expression) = dkc_create_slice_expression((yyvsp[(1) - (6)].expression),(yyvsp[(3) - (6)].expression),(yyvsp[(5) - (6)].expression));
		}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 565 "diksam.y"
    {
            (yyval.expression) = dkc_create_member_expression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].identifier));
        }
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 569 "diksam.y"
    {
            (yyval.expression) = dkc_create_function_call_expression((yyvsp[(1) - (4)].expression), (yyvsp[(3) - (4)].argument_list));
        }
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 573 "diksam.y"
    {
            (yyval.expression) = dkc_create_function_call_expression((yyvsp[(1) - (3)].expression), NULL);
        }
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 577 "diksam.y"
    {
            (yyval.expression) = (yyvsp[(2) - (3)].expression);
        }
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 581 "diksam.y"
    {
            (yyval.expression) = dkc_create_down_cast_expression((yyvsp[(1) - (4)].expression), (yyvsp[(3) - (4)].type_specifier));
        }
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 589 "diksam.y"
    {
            (yyval.expression) = dkc_create_boolean_expression(DVM_TRUE);
        }
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 593 "diksam.y"
    {
            (yyval.expression) = dkc_create_boolean_expression(DVM_FALSE);
        }
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 597 "diksam.y"
    {
            (yyval.expression) = dkc_create_null_expression();
        }
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 602 "diksam.y"
    {
            (yyval.expression) = dkc_create_this_expression();
        }
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 606 "diksam.y"
    {
            (yyval.expression) = dkc_create_super_expression();
        }
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 610 "diksam.y"
    {
			(yyval.expression) = dkc_create_new_delegate_expression();
		}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 614 "diksam.y"
    {
            (yyval.expression) = dkc_create_new_expression((yyvsp[(2) - (4)].identifier), NULL, NULL);
        }
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 618 "diksam.y"
    {
            (yyval.expression) = dkc_create_new_expression((yyvsp[(2) - (5)].identifier), NULL, (yyvsp[(4) - (5)].argument_list));
        }
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 622 "diksam.y"
    {
            (yyval.expression) = dkc_create_new_expression((yyvsp[(2) - (6)].identifier), (yyvsp[(4) - (6)].identifier), NULL);
        }
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 626 "diksam.y"
    {
            (yyval.expression) = dkc_create_new_expression((yyvsp[(2) - (7)].identifier), (yyvsp[(4) - (7)].identifier), (yyvsp[(6) - (7)].argument_list));
        }
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 632 "diksam.y"
    {
            (yyval.expression) = dkc_create_array_literal_expression((yyvsp[(2) - (3)].expression_list));
        }
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 636 "diksam.y"
    {
            (yyval.expression) = dkc_create_array_literal_expression((yyvsp[(2) - (4)].expression_list));
        }
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 642 "diksam.y"
    {
            (yyval.expression) = dkc_create_basic_array_creation((yyvsp[(2) - (4)].basic_type_specifier), (yyvsp[(3) - (4)].array_dimension), NULL,(yyvsp[(4) - (4)].intval));
        }
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 646 "diksam.y"
    {
            (yyval.expression) = dkc_create_basic_array_creation((yyvsp[(2) - (5)].basic_type_specifier), (yyvsp[(3) - (5)].array_dimension), (yyvsp[(4) - (5)].array_dimension),(yyvsp[(5) - (5)].intval));
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
#line 655 "diksam.y"
    {
            (yyval.expression) = dkc_create_class_array_creation((yyvsp[(2) - (5)].type_specifier), (yyvsp[(3) - (5)].array_dimension), (yyvsp[(4) - (5)].array_dimension),(yyvsp[(5) - (5)].intval));
        }
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 659 "diksam.y"
    {
            (yyval.expression) = dkc_create_class_array_creation((yyvsp[(2) - (4)].type_specifier), (yyvsp[(3) - (4)].array_dimension), NULL,(yyvsp[(4) - (4)].intval));
        }
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 663 "diksam.y"
    {
            (yyval.expression) = dkc_create_class_array_creation((yyvsp[(2) - (5)].type_specifier), (yyvsp[(3) - (5)].array_dimension), (yyvsp[(4) - (5)].array_dimension),(yyvsp[(5) - (5)].intval));
        }
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 670 "diksam.y"
    {
            (yyval.array_dimension) = dkc_chain_array_dimension((yyvsp[(1) - (2)].array_dimension), (yyvsp[(2) - (2)].array_dimension));
        }
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 676 "diksam.y"
    {
            (yyval.array_dimension) = dkc_create_array_dimension((yyvsp[(2) - (3)].expression));
        }
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 682 "diksam.y"
    {
            (yyval.array_dimension) = dkc_create_array_dimension(NULL);
        }
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 686 "diksam.y"
    {
            (yyval.array_dimension) = dkc_chain_array_dimension((yyvsp[(1) - (3)].array_dimension),
                                           dkc_create_array_dimension(NULL));
        }
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 693 "diksam.y"
    {
            (yyval.expression_list) = NULL;
        }
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 697 "diksam.y"
    {
            (yyval.expression_list) = dkc_create_expression_list((yyvsp[(1) - (1)].expression));
        }
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 701 "diksam.y"
    {
            (yyval.expression_list) = dkc_chain_expression_list((yyvsp[(1) - (3)].expression_list), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 707 "diksam.y"
    {
          (yyval.statement) = dkc_create_expression_statement((yyvsp[(1) - (2)].expression));
        }
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 723 "diksam.y"
    {/*empty line*/
			(yyval.statement)=0;
		}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 729 "diksam.y"
    {
            (yyval.statement) = dkc_create_if_statement((yyvsp[(2) - (4)].expression), (yyvsp[(4) - (4)].block), NULL, NULL);
        }
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 733 "diksam.y"
    {
			//printf("IF-ELSE %d\n",dkc_get_current_compiler()->current_line_number);
            (yyval.statement) = dkc_create_if_statement((yyvsp[(2) - (6)].expression), (yyvsp[(4) - (6)].block), NULL, (yyvsp[(6) - (6)].block));
        }
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 738 "diksam.y"
    {
            (yyval.statement) = dkc_create_if_statement((yyvsp[(2) - (5)].expression), (yyvsp[(4) - (5)].block), (yyvsp[(5) - (5)].elsif), NULL);
        }
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 742 "diksam.y"
    {
            (yyval.statement) = dkc_create_if_statement((yyvsp[(2) - (7)].expression), (yyvsp[(4) - (7)].block), (yyvsp[(5) - (7)].elsif), (yyvsp[(7) - (7)].block));
        }
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 749 "diksam.y"
    {
            (yyval.elsif) = dkc_chain_elsif_list((yyvsp[(1) - (2)].elsif), (yyvsp[(2) - (2)].elsif));
        }
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 755 "diksam.y"
    {
            (yyval.elsif) = dkc_create_elsif((yyvsp[(2) - (4)].expression), (yyvsp[(4) - (4)].block));
        }
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 761 "diksam.y"
    {
            (yyval.identifier) = NULL;
        }
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 765 "diksam.y"
    {
            (yyval.identifier) = (yyvsp[(1) - (2)].identifier);
        }
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 771 "diksam.y"
    {
            (yyval.statement) = dkc_create_switch_statement((yyvsp[(2) - (5)].expression), (yyvsp[(4) - (5)].case_list), (yyvsp[(5) - (5)].block));
        }
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 778 "diksam.y"
    {
            (yyval.case_list) = dkc_chain_case((yyvsp[(1) - (2)].case_list), (yyvsp[(2) - (2)].case_list));
        }
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 784 "diksam.y"
    {
            (yyval.case_list) = dkc_create_one_case((yyvsp[(2) - (3)].expression_list), (yyvsp[(3) - (3)].block));
        }
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 790 "diksam.y"
    {
            (yyval.block) = NULL;
        }
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 794 "diksam.y"
    {
            (yyval.block) = (yyvsp[(2) - (2)].block);
        }
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 800 "diksam.y"
    {
            (yyval.expression_list) = dkc_create_expression_list((yyvsp[(1) - (1)].expression));
        }
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 804 "diksam.y"
    {
            (yyval.expression_list) = dkc_chain_expression_list((yyvsp[(1) - (3)].expression_list), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 810 "diksam.y"
    {
            (yyval.statement) = dkc_create_while_statement((yyvsp[(1) - (4)].identifier), (yyvsp[(3) - (4)].expression), (yyvsp[(4) - (4)].block));
        }
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 816 "diksam.y"
    {
            (yyval.statement) = dkc_create_for_statement((yyvsp[(1) - (8)].identifier), (yyvsp[(3) - (8)].expression), (yyvsp[(5) - (8)].expression), (yyvsp[(7) - (8)].expression), (yyvsp[(8) - (8)].block));
        }
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 822 "diksam.y"
    {
            (yyval.statement) = dkc_create_do_while_statement((yyvsp[(1) - (8)].identifier), (yyvsp[(3) - (8)].block), (yyvsp[(6) - (8)].expression));
        }
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 828 "diksam.y"
    {
            (yyval.statement) = dkc_create_foreach_statement((yyvsp[(1) - (8)].identifier), (yyvsp[(4) - (8)].identifier), (yyvsp[(6) - (8)].expression), (yyvsp[(8) - (8)].block));
        }
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 834 "diksam.y"
    {
            (yyval.expression) = NULL;
        }
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 841 "diksam.y"
    {
            (yyval.statement) = dkc_create_return_statement((yyvsp[(2) - (3)].expression));
        }
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 847 "diksam.y"
    {
            (yyval.identifier) = NULL;
        }
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 854 "diksam.y"
    {
            (yyval.statement) = dkc_create_break_statement((yyvsp[(2) - (3)].identifier));
        }
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 860 "diksam.y"
    {
            (yyval.statement) = dkc_create_continue_statement((yyvsp[(2) - (3)].identifier));
        }
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 866 "diksam.y"
    {
            (yyval.statement) = dkc_create_try_statement((yyvsp[(2) - (5)].block), (yyvsp[(3) - (5)].catch_clause), (yyvsp[(5) - (5)].block));
        }
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 870 "diksam.y"
    {
            (yyval.statement) = dkc_create_try_statement((yyvsp[(2) - (4)].block), NULL, (yyvsp[(4) - (4)].block));
        }
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 874 "diksam.y"
    {
            (yyval.statement) = dkc_create_try_statement((yyvsp[(2) - (3)].block), (yyvsp[(3) - (3)].catch_clause), NULL);
        }
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 881 "diksam.y"
    {
            (yyval.catch_clause) = dkc_chain_catch_list((yyvsp[(1) - (2)].catch_clause), (yyvsp[(2) - (2)].catch_clause));
        }
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 887 "diksam.y"
    {
            (yyval.catch_clause) = dkc_start_catch_clause();
        }
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 891 "diksam.y"
    {
            (yyval.catch_clause) = dkc_end_catch_clause((yyvsp[(2) - (5)].catch_clause), (yyvsp[(3) - (5)].type_specifier), (yyvsp[(4) - (5)].identifier), (yyvsp[(5) - (5)].block));
        }
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 897 "diksam.y"
    {
            (yyval.statement) = dkc_create_throw_statement((yyvsp[(2) - (3)].expression));
        }
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 901 "diksam.y"
    {
            (yyval.statement) = dkc_create_throw_statement(NULL);
        }
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 907 "diksam.y"
    {
            (yyval.statement) = dkc_create_declaration_statement(DVM_FALSE, (yyvsp[(5) - (6)].type_specifier), (yyvsp[(2) - (6)].identifier), NULL,(yyvsp[(4) - (6)].intval));
        }
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 911 "diksam.y"
    {
            (yyval.statement) = dkc_create_declaration_statement(DVM_FALSE, (yyvsp[(5) - (8)].type_specifier), (yyvsp[(2) - (8)].identifier), (yyvsp[(7) - (8)].expression),(yyvsp[(4) - (8)].intval));
        }
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 915 "diksam.y"
    {
            (yyval.statement) = dkc_create_declaration_statement(DVM_FALSE, (yyvsp[(4) - (5)].type_specifier), (yyvsp[(2) - (5)].identifier), NULL,DVM_FALSE);
        }
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 919 "diksam.y"
    {
            (yyval.statement) = dkc_create_declaration_statement(DVM_TRUE, (yyvsp[(4) - (7)].type_specifier), (yyvsp[(2) - (7)].identifier), (yyvsp[(6) - (7)].expression),DVM_FALSE);
        }
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 925 "diksam.y"
    {
            (yyval.block) = dkc_open_block(0);
        }
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 929 "diksam.y"
    {
            (yyval.block) = dkc_close_block((yyvsp[(2) - (4)].block), (yyvsp[(3) - (4)].statement_list));
        }
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 933 "diksam.y"
    {
            Block *empty_block = dkc_open_block(0);
            (yyval.block) = dkc_close_block(empty_block, NULL);
        }
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 940 "diksam.y"
    {
            (yyval.template_def) = dkc_create_template_declare_list((yyvsp[(1) - (1)].identifier),NULL);
        }
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 944 "diksam.y"
    {
            (yyval.template_def) = dkc_chain_template_declare_list((yyvsp[(1) - (3)].template_def), (yyvsp[(3) - (3)].identifier),NULL);
        }
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 948 "diksam.y"
    {
            (yyval.template_def) = dkc_create_template_declare_list((yyvsp[(1) - (3)].identifier),(yyvsp[(3) - (3)].type_specifier));
        }
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 952 "diksam.y"
    {
            (yyval.template_def) = dkc_chain_template_declare_list((yyvsp[(1) - (5)].template_def), (yyvsp[(3) - (5)].identifier) ,(yyvsp[(5) - (5)].type_specifier));
        }
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 958 "diksam.y"
    {
			(yyval.template_def)=(yyvsp[(2) - (3)].template_def);
		}
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 962 "diksam.y"
    {(yyval.template_def)=NULL;}
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 967 "diksam.y"
    {
            dkc_start_class_definition((yyvsp[(1) - (6)].intval),NULL, (yyvsp[(2) - (6)].class_or_interface), (yyvsp[(3) - (6)].identifier),(yyvsp[(4) - (6)].template_def), (yyvsp[(5) - (6)].extends_list));
        }
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 971 "diksam.y"
    {
            dkc_class_define((yyvsp[(8) - (9)].member_declaration));
        }
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 976 "diksam.y"
    {
            dkc_start_class_definition((yyvsp[(1) - (7)].intval),&(yyvsp[(2) - (7)].class_or_member_modifier), (yyvsp[(3) - (7)].class_or_interface), (yyvsp[(4) - (7)].identifier),(yyvsp[(5) - (7)].template_def), (yyvsp[(6) - (7)].extends_list));
        }
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 979 "diksam.y"
    {
            dkc_class_define((yyvsp[(9) - (10)].member_declaration));
        }
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 983 "diksam.y"
    {
            dkc_start_class_definition((yyvsp[(1) - (6)].intval),NULL, (yyvsp[(2) - (6)].class_or_interface), (yyvsp[(3) - (6)].identifier),(yyvsp[(4) - (6)].template_def), (yyvsp[(5) - (6)].extends_list));
        }
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 987 "diksam.y"
    {
            dkc_class_define(NULL);
        }
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 992 "diksam.y"
    {
            dkc_start_class_definition((yyvsp[(1) - (7)].intval),&(yyvsp[(2) - (7)].class_or_member_modifier), (yyvsp[(3) - (7)].class_or_interface), (yyvsp[(4) - (7)].identifier),(yyvsp[(5) - (7)].template_def), (yyvsp[(6) - (7)].extends_list));
        }
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 996 "diksam.y"
    {
            dkc_class_define(NULL);
        }
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 1003 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_chain_class_or_member_modifier((yyvsp[(1) - (2)].class_or_member_modifier), (yyvsp[(2) - (2)].class_or_member_modifier));
        }
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 1010 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(VIRTUAL_MODIFIER);
        }
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 1014 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(OVERRIDE_MODIFIER);
        }
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 1018 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(ABSTRACT_MODIFIER);
        }
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 1024 "diksam.y"
    {
            (yyval.class_or_interface) = DVM_CLASS_DEFINITION;
        }
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 1028 "diksam.y"
    {
            (yyval.class_or_interface) = DVM_INTERFACE_DEFINITION;
        }
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 1034 "diksam.y"
    {
            (yyval.extends_list) = NULL;
        }
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 1038 "diksam.y"
    {
            (yyval.extends_list) = (yyvsp[(2) - (2)].extends_list);
        }
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 1044 "diksam.y"
    {
            (yyval.extends_list) = dkc_create_extends_list((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 1048 "diksam.y"
    {
            (yyval.extends_list) = dkc_chain_extends_list((yyvsp[(1) - (3)].extends_list), (yyvsp[(3) - (3)].identifier));
        }
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 1055 "diksam.y"
    {
            (yyval.member_declaration) = dkc_chain_member_declaration((yyvsp[(1) - (2)].member_declaration), (yyvsp[(2) - (2)].member_declaration));
        }
    break;

  case 238:

/* Line 1455 of yacc.c  */
#line 1065 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_method_member(NULL, (yyvsp[(1) - (1)].function_definition), DVM_FALSE);
        }
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 1069 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_method_member(&(yyvsp[(1) - (2)].class_or_member_modifier), (yyvsp[(2) - (2)].function_definition), DVM_FALSE);
        }
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 1073 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_method_member(NULL, (yyvsp[(1) - (1)].function_definition), DVM_TRUE);
        }
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 1077 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_method_member(&(yyvsp[(1) - (2)].class_or_member_modifier), (yyvsp[(2) - (2)].function_definition), DVM_TRUE);
        }
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 1083 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define((yyvsp[(7) - (9)].type_specifier), (yyvsp[(2) - (9)].identifier), (yyvsp[(4) - (9)].parameter_list), (yyvsp[(8) - (9)].exception_list), (yyvsp[(9) - (9)].block));
        }
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 1087 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define((yyvsp[(6) - (8)].type_specifier), (yyvsp[(2) - (8)].identifier), NULL, (yyvsp[(7) - (8)].exception_list), (yyvsp[(8) - (8)].block));
        }
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 1091 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define((yyvsp[(8) - (10)].type_specifier), (yyvsp[(3) - (10)].identifier), (yyvsp[(5) - (10)].parameter_list), (yyvsp[(9) - (10)].exception_list), NULL);
        }
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 1095 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define((yyvsp[(7) - (9)].type_specifier), (yyvsp[(3) - (9)].identifier), NULL, (yyvsp[(8) - (9)].exception_list), NULL);
        }
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 1099 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define(0, (yyvsp[(2) - (7)].identifier), (yyvsp[(4) - (7)].parameter_list), (yyvsp[(6) - (7)].exception_list), (yyvsp[(7) - (7)].block));
        }
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 1103 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define(0, (yyvsp[(2) - (6)].identifier), NULL, (yyvsp[(5) - (6)].exception_list), (yyvsp[(6) - (6)].block));
        }
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 1107 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define(0, (yyvsp[(3) - (8)].identifier), (yyvsp[(5) - (8)].parameter_list), (yyvsp[(7) - (8)].exception_list), NULL);
        }
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 1111 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define(0, (yyvsp[(3) - (7)].identifier), NULL, (yyvsp[(6) - (7)].exception_list), NULL);
        }
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 1117 "diksam.y"
    {
			(yyval.intval)=0;
		}
    break;

  case 251:

/* Line 1455 of yacc.c  */
#line 1121 "diksam.y"
    {
			(yyval.intval)=1;
		}
    break;

  case 252:

/* Line 1455 of yacc.c  */
#line 1127 "diksam.y"
    {
            (yyval.exception_list) = NULL;
        }
    break;

  case 253:

/* Line 1455 of yacc.c  */
#line 1131 "diksam.y"
    {
            (yyval.exception_list) = (yyvsp[(2) - (2)].exception_list);
        }
    break;

  case 254:

/* Line 1455 of yacc.c  */
#line 1137 "diksam.y"
    {
            (yyval.exception_list) = dkc_create_throws((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 255:

/* Line 1455 of yacc.c  */
#line 1141 "diksam.y"
    {
            (yyval.exception_list) = dkc_chain_exception_list((yyvsp[(1) - (3)].exception_list), (yyvsp[(3) - (3)].identifier));
        }
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 1147 "diksam.y"
    {
            (yyval.function_definition) = dkc_constructor_function_define((yyvsp[(2) - (7)].identifier), (yyvsp[(4) - (7)].parameter_list), (yyvsp[(6) - (7)].exception_list), (yyvsp[(7) - (7)].block));
        }
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 1151 "diksam.y"
    {
            (yyval.function_definition) = dkc_constructor_function_define((yyvsp[(2) - (6)].identifier), NULL, (yyvsp[(5) - (6)].exception_list), (yyvsp[(6) - (6)].block));
        }
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 1155 "diksam.y"
    {
            (yyval.function_definition) = dkc_constructor_function_define((yyvsp[(3) - (8)].identifier), (yyvsp[(5) - (8)].parameter_list), (yyvsp[(7) - (8)].exception_list), NULL);
        }
    break;

  case 259:

/* Line 1455 of yacc.c  */
#line 1159 "diksam.y"
    {
            (yyval.function_definition) = dkc_constructor_function_define((yyvsp[(3) - (7)].identifier), NULL, (yyvsp[(6) - (7)].exception_list), NULL);
        }
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 1165 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(PUBLIC_MODIFIER);
        }
    break;

  case 261:

/* Line 1455 of yacc.c  */
#line 1169 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(PRIVATE_MODIFIER);
        }
    break;

  case 262:

/* Line 1455 of yacc.c  */
#line 1175 "diksam.y"
    {
            (yyval.expression) = NULL;
        }
    break;

  case 263:

/* Line 1455 of yacc.c  */
#line 1179 "diksam.y"
    {
            (yyval.expression) = (yyvsp[(2) - (2)].expression);
        }
    break;

  case 264:

/* Line 1455 of yacc.c  */
#line 1185 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(NULL, DVM_FALSE, (yyvsp[(4) - (6)].type_specifier), (yyvsp[(2) - (6)].identifier), (yyvsp[(5) - (6)].expression));
        }
    break;

  case 265:

/* Line 1455 of yacc.c  */
#line 1190 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(&(yyvsp[(1) - (6)].class_or_member_modifier), DVM_FALSE, (yyvsp[(4) - (6)].type_specifier), (yyvsp[(2) - (6)].identifier), (yyvsp[(5) - (6)].expression));
        }
    break;

  case 266:

/* Line 1455 of yacc.c  */
#line 1194 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(NULL, DVM_TRUE, (yyvsp[(4) - (6)].type_specifier), (yyvsp[(2) - (6)].identifier), (yyvsp[(5) - (6)].expression));
        }
    break;

  case 267:

/* Line 1455 of yacc.c  */
#line 1199 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(&(yyvsp[(1) - (7)].class_or_member_modifier), DVM_TRUE, (yyvsp[(5) - (7)].type_specifier), (yyvsp[(3) - (7)].identifier), (yyvsp[(6) - (7)].expression));
        }
    break;

  case 268:

/* Line 1455 of yacc.c  */
#line 1203 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(&(yyvsp[(2) - (7)].class_or_member_modifier), DVM_TRUE, (yyvsp[(5) - (7)].type_specifier), (yyvsp[(3) - (7)].identifier), (yyvsp[(6) - (7)].expression));
        }
    break;

  case 269:

/* Line 1455 of yacc.c  */
#line 1209 "diksam.y"
    {
            dkc_create_delegate_definition((yyvsp[(8) - (10)].type_specifier), (yyvsp[(2) - (10)].identifier), (yyvsp[(4) - (10)].parameter_list), (yyvsp[(9) - (10)].exception_list),(yyvsp[(5) - (10)].intval));
        }
    break;

  case 270:

/* Line 1455 of yacc.c  */
#line 1213 "diksam.y"
    {
            dkc_create_delegate_definition((yyvsp[(7) - (9)].type_specifier), (yyvsp[(2) - (9)].identifier), NULL, (yyvsp[(8) - (9)].exception_list),(yyvsp[(4) - (9)].intval));
        }
    break;

  case 271:

/* Line 1455 of yacc.c  */
#line 1219 "diksam.y"
    {
            dkc_create_enum_definition((yyvsp[(2) - (5)].identifier), (yyvsp[(4) - (5)].enumerator));
        }
    break;

  case 272:

/* Line 1455 of yacc.c  */
#line 1223 "diksam.y"
    {
            dkc_create_enum_definition((yyvsp[(2) - (6)].identifier), (yyvsp[(4) - (6)].enumerator));
        }
    break;

  case 273:

/* Line 1455 of yacc.c  */
#line 1229 "diksam.y"
    {
            (yyval.enumerator) = dkc_create_enumerator((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 274:

/* Line 1455 of yacc.c  */
#line 1233 "diksam.y"
    {
            (yyval.enumerator) = dkc_chain_enumerator((yyvsp[(1) - (3)].enumerator), (yyvsp[(3) - (3)].identifier));
        }
    break;

  case 275:

/* Line 1455 of yacc.c  */
#line 1239 "diksam.y"
    {
            dkc_create_const_definition(NULL, (yyvsp[(2) - (5)].identifier), (yyvsp[(4) - (5)].expression));
        }
    break;

  case 276:

/* Line 1455 of yacc.c  */
#line 1243 "diksam.y"
    {
            dkc_create_const_definition((yyvsp[(2) - (4)].type_specifier), (yyvsp[(3) - (4)].identifier), NULL);
        }
    break;

  case 277:

/* Line 1455 of yacc.c  */
#line 1249 "diksam.y"
    {
			(yyval.intval)=0;
		}
    break;

  case 278:

/* Line 1455 of yacc.c  */
#line 1253 "diksam.y"
    {
			(yyval.intval)=1;
		}
    break;

  case 279:

/* Line 1455 of yacc.c  */
#line 1259 "diksam.y"
    {
			(yyval.intval)=0;
		}
    break;

  case 280:

/* Line 1455 of yacc.c  */
#line 1263 "diksam.y"
    {
			(yyval.intval)=1;
		}
    break;

  case 281:

/* Line 1455 of yacc.c  */
#line 1269 "diksam.y"
    {
			(yyval.intval)=0;
		}
    break;

  case 282:

/* Line 1455 of yacc.c  */
#line 1273 "diksam.y"
    {
			(yyval.intval)=1;
		}
    break;

  case 283:

/* Line 1455 of yacc.c  */
#line 1277 "diksam.y"
    {
			(yyval.intval)=-1;
		}
    break;

  case 284:

/* Line 1455 of yacc.c  */
#line 1283 "diksam.y"
    {
            (yyval.block) = dkc_open_block((yyvsp[(2) - (2)].intval));
			//printf("E1 %d\n",dkc_get_current_compiler());
        }
    break;

  case 285:

/* Line 1455 of yacc.c  */
#line 1288 "diksam.y"
    {
            (yyval.block) = dkc_close_block((yyvsp[(3) - (5)].block), (yyvsp[(4) - (5)].statement_list));
			//printf("C1 %d\n",dkc_get_current_compiler()->current_line_number);
        }
    break;

  case 286:

/* Line 1455 of yacc.c  */
#line 1293 "diksam.y"
    {
            Block *empty_block = dkc_open_block(0);
            (yyval.block) = dkc_close_block(empty_block, NULL);
			//printf("C2 %d\n",dkc_get_current_compiler()->current_line_number);
        }
    break;



/* Line 1455 of yacc.c  */
#line 4336 "y.tab.c"
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
#line 1299 "diksam.y"


