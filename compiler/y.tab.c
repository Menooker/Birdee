
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
     LIB = 357
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
#line 351 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 363 "y.tab.c"

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
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1099

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  103
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  94
/* YYNRULES -- Number of rules.  */
#define YYNRULES  260
/* YYNRULES -- Number of states.  */
#define YYNSTATES  569

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   357

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
      95,    96,    97,    98,    99,   100,   101,   102
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     9,    10,    13,    15,    17,    19,
      21,    24,    28,    30,    34,    36,    39,    44,    46,    48,
      50,    52,    54,    56,    58,    60,    62,    64,    66,    68,
      70,    72,    74,    78,    82,    86,    88,    90,    92,    93,
     100,   101,   104,   116,   127,   137,   146,   157,   167,   176,
     184,   186,   190,   196,   198,   202,   204,   207,   209,   213,
     215,   219,   221,   223,   225,   227,   229,   231,   233,   237,
     239,   243,   245,   249,   253,   255,   259,   263,   267,   271,
     273,   277,   281,   283,   287,   291,   295,   299,   303,   307,
     309,   312,   315,   318,   320,   323,   326,   330,   332,   334,
     336,   338,   343,   348,   352,   357,   361,   365,   370,   372,
     374,   376,   378,   380,   382,   384,   386,   388,   390,   395,
     400,   406,   413,   421,   425,   430,   434,   439,   443,   448,
     450,   453,   457,   460,   464,   465,   467,   471,   474,   476,
     478,   480,   482,   484,   486,   488,   490,   492,   494,   496,
     498,   500,   505,   512,   518,   526,   528,   531,   536,   537,
     540,   546,   548,   551,   555,   556,   559,   561,   565,   570,
     579,   588,   597,   598,   600,   604,   605,   607,   611,   615,
     621,   626,   630,   632,   635,   636,   642,   646,   649,   655,
     663,   669,   677,   678,   683,   686,   687,   695,   696,   705,
     706,   713,   714,   722,   724,   727,   729,   731,   733,   735,
     737,   739,   740,   743,   745,   749,   751,   754,   756,   758,
     760,   763,   765,   768,   778,   787,   798,   808,   816,   823,
     832,   840,   841,   844,   845,   848,   850,   854,   862,   869,
     878,   886,   888,   890,   891,   894,   901,   908,   915,   923,
     931,   942,   952,   958,   965,   967,   971,   977,   982,   983,
     988
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     104,     0,    -1,   105,   111,    -1,   104,   111,    -1,    -1,
     106,   109,    -1,   106,    -1,   109,    -1,   116,    -1,   107,
      -1,   106,   107,    -1,    74,   108,    98,    -1,     7,    -1,
     108,    53,     7,    -1,   110,    -1,   109,   110,    -1,    75,
     108,     7,    98,    -1,   120,    -1,   170,    -1,   143,    -1,
     191,    -1,   192,    -1,   194,    -1,    66,    -1,    67,    -1,
      68,    -1,    69,    -1,    70,    -1,    71,    -1,    72,    -1,
      89,    -1,     7,    -1,   112,    27,    28,    -1,     7,    27,
      28,    -1,   114,    27,    28,    -1,   112,    -1,   114,    -1,
     113,    -1,    -1,   102,     7,   117,    98,   118,    97,    -1,
      -1,   118,   119,    -1,    99,    93,     7,    23,   121,   184,
      24,    94,   115,   185,    98,    -1,    99,    93,     7,    23,
     184,    24,    94,   115,   185,    98,    -1,    99,   100,     7,
      23,   121,   184,    24,   185,    98,    -1,    99,   100,     7,
      23,   184,    24,   185,    98,    -1,    93,     7,    23,   121,
     184,    24,    94,   115,   185,   195,    -1,    93,     7,    23,
     184,    24,    94,   115,   185,   195,    -1,   100,     7,    23,
     121,   184,    24,   185,   195,    -1,   100,     7,    23,   184,
      24,   185,   195,    -1,   119,    -1,     7,    94,   115,    -1,
     121,    31,     7,    94,   115,    -1,   125,    -1,   122,    31,
     125,    -1,   143,    -1,   123,   143,    -1,   125,    -1,   124,
      31,   125,    -1,   127,    -1,   135,   126,   125,    -1,    32,
      -1,    54,    -1,    55,    -1,    56,    -1,    57,    -1,    58,
      -1,   128,    -1,   127,    34,   128,    -1,   129,    -1,   128,
      33,   129,    -1,   130,    -1,   129,    35,   130,    -1,   129,
      36,   130,    -1,   131,    -1,   130,    37,   131,    -1,   130,
      38,   131,    -1,   130,    39,   131,    -1,   130,    40,   131,
      -1,   132,    -1,   131,    41,   132,    -1,   131,    42,   132,
      -1,   133,    -1,   132,    43,   133,    -1,   132,    44,   133,
      -1,   132,    45,   133,    -1,   132,    46,   133,    -1,   132,
      47,   133,    -1,   132,    48,   133,    -1,   134,    -1,    42,
     133,    -1,    52,   133,    -1,    49,   133,    -1,   135,    -1,
     135,    59,    -1,   135,    60,    -1,   135,    86,   115,    -1,
     136,    -1,   138,    -1,     7,    -1,     8,    -1,   136,    27,
     124,    28,    -1,     7,    27,   124,    28,    -1,   135,    53,
       7,    -1,   135,    23,   122,    24,    -1,   135,    23,    24,
      -1,    23,   124,    24,    -1,   135,    87,   115,    88,    -1,
       3,    -1,     4,    -1,     5,    -1,     6,    -1,    50,    -1,
      51,    -1,    22,    -1,   137,    -1,    83,    -1,    84,    -1,
      73,    89,    23,    24,    -1,    73,     7,    23,    24,    -1,
      73,     7,    23,   122,    24,    -1,    73,     7,    53,     7,
      23,    24,    -1,    73,     7,    53,     7,    23,   122,    24,
      -1,    25,   142,    26,    -1,    25,   142,    31,    26,    -1,
      73,   112,   139,    -1,    73,   112,   139,   141,    -1,    73,
     113,   139,    -1,    73,   113,   139,   141,    -1,   140,    -1,
     139,   140,    -1,    27,   124,    28,    -1,    27,    28,    -1,
     141,    27,    28,    -1,    -1,   125,    -1,   142,    31,   125,
      -1,   124,    98,    -1,   144,    -1,   148,    -1,   153,    -1,
     154,    -1,   155,    -1,   156,    -1,   158,    -1,   160,    -1,
     161,    -1,   162,    -1,   166,    -1,   167,    -1,    98,    -1,
       9,   124,    95,   195,    -1,     9,   124,    95,   195,    10,
     195,    -1,     9,   124,    95,   195,   145,    -1,     9,   124,
      95,   195,   145,    10,   195,    -1,   146,    -1,   145,   146,
      -1,    11,   124,    95,   195,    -1,    -1,     7,    30,    -1,
      12,   124,    98,   149,   151,    -1,   150,    -1,   149,   150,
      -1,    13,   152,   195,    -1,    -1,    14,   195,    -1,   125,
      -1,   142,    31,   125,    -1,   147,    15,   124,   195,    -1,
     147,    17,   157,    29,   157,    29,   157,   195,    -1,   147,
      16,   168,    15,    23,   124,    24,    98,    -1,   147,    18,
      23,     7,    30,   124,    24,   168,    -1,    -1,   124,    -1,
      19,   157,    98,    -1,    -1,     7,    -1,    20,   159,    98,
      -1,    21,   159,    98,    -1,    61,   195,   163,    63,   195,
      -1,    61,   195,    63,   168,    -1,    61,   195,   163,    -1,
     164,    -1,   163,   164,    -1,    -1,    62,   165,   115,     7,
     195,    -1,    64,   124,    98,    -1,    64,    98,    -1,    96,
       7,    94,   115,    98,    -1,    96,     7,    94,   115,    32,
     124,    98,    -1,    90,     7,    94,   115,    98,    -1,    90,
       7,    94,   115,    32,   124,    98,    -1,    -1,    25,   169,
     123,    26,    -1,    25,    26,    -1,    -1,   177,     7,   178,
      98,   171,   180,    97,    -1,    -1,   175,   177,     7,   178,
      98,   172,   180,    97,    -1,    -1,   177,     7,   178,    98,
     173,    97,    -1,    -1,   175,   177,     7,   178,    98,   174,
      97,    -1,   176,    -1,   175,   176,    -1,   188,    -1,    80,
      -1,    81,    -1,    82,    -1,    76,    -1,    77,    -1,    -1,
      30,   179,    -1,     7,    -1,   179,    31,     7,    -1,   181,
      -1,   180,   181,    -1,   182,    -1,   190,    -1,   183,    -1,
     175,   183,    -1,   187,    -1,   175,   187,    -1,    93,     7,
      23,   121,    24,    94,   115,   185,   195,    -1,    93,     7,
      23,    24,    94,   115,   185,   195,    -1,    99,    93,     7,
      23,   121,    24,    94,   115,   185,    98,    -1,    99,    93,
       7,    23,    24,    94,   115,   185,    98,    -1,   100,     7,
      23,   121,    24,   185,   195,    -1,   100,     7,    23,    24,
     185,   195,    -1,    99,   100,     7,    23,   121,    24,   185,
      98,    -1,    99,   100,     7,    23,    24,   185,    98,    -1,
      -1,    31,   101,    -1,    -1,    65,   186,    -1,     7,    -1,
     186,    31,     7,    -1,    85,     7,    23,   121,    24,   185,
     195,    -1,    85,     7,    23,    24,   185,   195,    -1,    99,
      85,     7,    23,   121,    24,   185,    98,    -1,    99,    85,
       7,    23,    24,   185,    98,    -1,    78,    -1,    79,    -1,
      -1,    32,   124,    -1,    96,     7,    94,   115,   189,    98,
      -1,   175,     7,    94,   115,   189,    98,    -1,    90,     7,
      94,   115,   189,    98,    -1,   175,    90,     7,    94,   115,
     189,    98,    -1,    90,   175,     7,    94,   115,   189,    98,
      -1,    89,     7,    23,   121,   184,    24,    94,   115,   185,
      98,    -1,    89,     7,    23,   184,    24,    94,   115,   185,
      98,    -1,    91,     7,    25,   193,    26,    -1,    91,     7,
      25,   193,    31,    26,    -1,     7,    -1,   193,    31,     7,
      -1,    92,     7,    32,   124,    98,    -1,    92,   115,     7,
      98,    -1,    -1,    98,   196,   123,    97,    -1,    98,    97,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    96,    96,    97,   101,   104,   108,   112,   116,   122,
     123,   129,   135,   139,   145,   146,   152,   158,   159,   160,
     167,   168,   169,   172,   176,   180,   184,   188,   192,   196,
     200,   206,   212,   218,   224,   230,   234,   235,   240,   239,
     248,   251,   254,   258,   262,   266,   273,   277,   281,   285,
     289,   292,   296,   302,   306,   312,   316,   322,   323,   329,
     330,   336,   340,   344,   348,   352,   356,   362,   363,   369,
     370,   376,   377,   381,   387,   388,   392,   396,   400,   406,
     407,   411,   417,   418,   422,   426,   430,   434,   438,   444,
     445,   449,   453,   459,   460,   464,   468,   474,   475,   476,
     480,   486,   490,   495,   499,   503,   507,   511,   515,   516,
     517,   518,   519,   523,   527,   531,   532,   536,   540,   544,
     548,   552,   556,   562,   566,   572,   576,   580,   584,   591,
     592,   598,   604,   608,   616,   619,   623,   629,   633,   634,
     635,   636,   637,   638,   639,   640,   641,   642,   643,   644,
     645,   651,   655,   660,   664,   670,   671,   677,   684,   687,
     693,   699,   700,   706,   713,   716,   722,   726,   732,   738,
     744,   750,   757,   760,   763,   770,   773,   776,   782,   788,
     792,   796,   802,   803,   810,   809,   819,   823,   829,   833,
     837,   841,   848,   847,   855,   864,   862,   873,   871,   880,
     879,   889,   887,   898,   899,   905,   906,   910,   914,   920,
     924,   931,   934,   940,   944,   950,   951,   957,   958,   961,
     965,   969,   973,   979,   983,   987,   991,   995,   999,  1003,
    1007,  1014,  1017,  1024,  1027,  1033,  1037,  1043,  1047,  1051,
    1055,  1061,  1065,  1072,  1075,  1081,  1085,  1090,  1094,  1099,
    1105,  1109,  1115,  1119,  1125,  1129,  1135,  1139,  1146,  1145,
    1155
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
  "$accept", "translation_unit", "initial_declaration", "require_list",
  "require_declaration", "package_name", "rename_list",
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
  "enum_definition", "enumerator_list", "const_definition", "myblock",
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
     355,   356,   357
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   103,   104,   104,   105,   105,   105,   105,   105,   106,
     106,   107,   108,   108,   109,   109,   110,   111,   111,   111,
     111,   111,   111,   112,   112,   112,   112,   112,   112,   112,
     112,   113,   114,   114,   114,   115,   115,   115,   117,   116,
     118,   118,   119,   119,   119,   119,   120,   120,   120,   120,
     120,   121,   121,   122,   122,   123,   123,   124,   124,   125,
     125,   126,   126,   126,   126,   126,   126,   127,   127,   128,
     128,   129,   129,   129,   130,   130,   130,   130,   130,   131,
     131,   131,   132,   132,   132,   132,   132,   132,   132,   133,
     133,   133,   133,   134,   134,   134,   134,   135,   135,   135,
     135,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   137,   137,   138,   138,   138,   138,   139,
     139,   140,   141,   141,   142,   142,   142,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   144,   144,   144,   144,   145,   145,   146,   147,   147,
     148,   149,   149,   150,   151,   151,   152,   152,   153,   154,
     155,   156,   157,   157,   158,   159,   159,   160,   161,   162,
     162,   162,   163,   163,   165,   164,   166,   166,   167,   167,
     167,   167,   169,   168,   168,   171,   170,   172,   170,   173,
     170,   174,   170,   175,   175,   176,   176,   176,   176,   177,
     177,   178,   178,   179,   179,   180,   180,   181,   181,   182,
     182,   182,   182,   183,   183,   183,   183,   183,   183,   183,
     183,   184,   184,   185,   185,   186,   186,   187,   187,   187,
     187,   188,   188,   189,   189,   190,   190,   190,   190,   190,
     191,   191,   192,   192,   193,   193,   194,   194,   196,   195,
     195
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     0,     2,     1,     1,     1,     1,
       2,     3,     1,     3,     1,     2,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     1,     1,     1,     0,     6,
       0,     2,    11,    10,     9,     8,    10,     9,     8,     7,
       1,     3,     5,     1,     3,     1,     2,     1,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     3,     3,     1,
       2,     2,     2,     1,     2,     2,     3,     1,     1,     1,
       1,     4,     4,     3,     4,     3,     3,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       5,     6,     7,     3,     4,     3,     4,     3,     4,     1,
       2,     3,     2,     3,     0,     1,     3,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     6,     5,     7,     1,     2,     4,     0,     2,
       5,     1,     2,     3,     0,     2,     1,     3,     4,     8,
       8,     8,     0,     1,     3,     0,     1,     3,     3,     5,
       4,     3,     1,     2,     0,     5,     3,     2,     5,     7,
       5,     7,     0,     4,     2,     0,     7,     0,     8,     0,
       6,     0,     7,     1,     2,     1,     1,     1,     1,     1,
       1,     0,     2,     1,     3,     1,     2,     1,     1,     1,
       2,     1,     2,     9,     8,    10,     9,     7,     6,     8,
       7,     0,     2,     0,     2,     1,     3,     7,     6,     8,
       7,     1,     1,     0,     2,     6,     6,     6,     7,     7,
      10,     9,     5,     6,     1,     3,     5,     4,     0,     4,
       2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       4,     0,     0,     0,   158,   158,     6,     9,     7,    14,
       8,    12,     0,     0,    38,     1,   108,   109,   110,   111,
      99,   100,     0,     0,   172,   175,   175,   114,     0,   134,
       0,     0,   112,   113,     0,     0,     0,     0,   209,   210,
     241,   242,   206,   207,   208,   116,   117,     0,     0,     0,
       0,     0,     0,   150,     0,     0,     3,    50,    17,     0,
      57,    59,    67,    69,    71,    74,    79,    82,    89,    93,
      97,   115,    98,    19,   138,     0,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,    18,     0,   203,
       0,   205,    20,    21,    22,     2,    10,     5,    15,     0,
      11,     0,     0,     0,   159,    99,     0,     0,   173,     0,
     176,     0,     0,     0,   135,     0,    90,    93,    92,    91,
     258,     0,   187,     0,    31,    23,    24,    25,    26,    27,
      28,    29,    30,     0,     0,     0,     0,     0,    31,    30,
      35,    37,    36,     0,     0,     0,     0,     0,     0,     0,
     137,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    61,     0,
      62,    63,    64,    65,    66,    94,    95,     0,     0,     0,
       0,     0,     0,   172,     0,   204,     0,   211,    13,    16,
      40,     0,     0,     0,   174,   177,   178,   106,   123,     0,
     260,   158,   184,     0,   181,   182,   186,     0,     0,     0,
       0,   125,   129,   127,   231,     0,     0,     0,     0,     0,
       0,     0,   231,     0,     0,     0,   231,    58,    68,    70,
      72,    73,    75,    76,    77,    78,    80,    81,    83,    84,
      85,    86,    87,    88,   105,     0,    53,   103,    31,    96,
       0,    60,     0,     0,   192,     0,     0,     0,   211,     0,
       0,     0,   102,   151,   134,   164,   161,   124,   136,   158,
      55,     0,   180,     0,   183,   119,     0,     0,   118,     0,
       0,   130,   126,   128,     0,     0,   231,     0,     0,   254,
       0,    33,     0,    32,    34,   257,   231,     0,     0,   231,
     231,   231,     0,   104,     0,   107,   101,   168,   194,   158,
       0,   172,     0,     0,   213,   212,   195,    39,    41,     0,
       0,   153,   155,   135,     0,     0,     0,   162,   160,   259,
      56,     0,   179,   120,     0,   131,   132,     0,     0,   232,
       0,     0,     0,     0,   190,   252,     0,   256,     0,     0,
       0,   188,   231,     0,   231,     0,     0,   233,    54,   158,
       0,     0,     0,   197,     0,     0,     0,   152,     0,     0,
     156,     0,   163,   165,     0,   121,     0,   133,    51,     0,
       0,     0,     0,   255,   253,     0,     0,     0,     0,     0,
       0,   233,   233,     0,     0,   193,     0,   172,     0,     0,
       0,   214,     0,     0,     0,     0,     0,     0,     0,     0,
     215,   217,   219,   221,   218,   200,     0,   154,   136,   185,
     122,     0,     0,   233,   191,     0,   233,   189,     0,     0,
     233,     0,     0,   235,   234,    49,     0,     0,     0,     0,
     202,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   220,   222,   196,   216,   157,    52,   233,     0,
     233,     0,     0,   233,     0,    45,    48,     0,   170,   169,
     171,   198,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   251,     0,    47,   233,     0,    44,
     236,   233,     0,   243,     0,     0,     0,   243,     0,     0,
       0,   233,     0,   243,     0,   250,    46,     0,    43,     0,
     233,     0,     0,     0,   243,     0,     0,     0,   233,     0,
       0,     0,   233,     0,     0,   233,     0,   243,    42,   238,
       0,   244,   247,     0,   233,     0,   245,     0,   233,     0,
       0,     0,   233,   228,     0,   246,     0,   237,   249,     0,
     233,   240,     0,   233,     0,   230,     0,   227,   248,   224,
       0,   239,     0,   233,   229,   223,   226,     0,   225
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,     7,    12,     8,     9,    56,   140,
     141,   142,   143,    10,   102,   261,    57,    58,   286,   245,
     269,    59,    60,   179,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,   211,   212,   282,   115,
      73,    74,   321,   322,    75,    76,   265,   266,   328,   325,
      77,    78,    79,    80,   109,    81,   111,    82,    83,    84,
     204,   205,   271,    85,    86,   255,   309,    87,   365,   399,
     366,   400,   408,    89,    90,   260,   315,   409,   410,   411,
     412,   287,   394,   434,   413,    91,   513,   414,    92,    93,
     290,    94,   121,   201
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -460
static const yytype_int16 yypact[] =
{
     -26,    22,    22,    44,   419,   517,    74,  -460,   -58,  -460,
    -460,  -460,   -34,    27,  -460,  -460,  -460,  -460,  -460,  -460,
      88,  -460,  1015,  1015,  1015,    60,    60,  -460,  1015,  1015,
    1015,  1015,  -460,  -460,  1015,   -21,   859,    16,  -460,  -460,
    -460,  -460,  -460,  -460,  -460,  -460,  -460,   124,   153,   159,
      58,   207,   211,  -460,   -30,   216,  -460,  -460,  -460,    -6,
    -460,   143,   148,   193,   270,   215,   333,  -460,  -460,   398,
     173,  -460,  -460,  -460,  -460,   297,  -460,  -460,  -460,  -460,
    -460,  -460,  -460,  -460,  -460,  -460,  -460,  -460,   312,  -460,
     242,  -460,  -460,  -460,  -460,  -460,  -460,   -58,  -460,   254,
    -460,   112,   137,  1015,  -460,   246,     8,    -5,   248,   179,
    -460,   190,   199,    66,  -460,   113,  -460,   144,  -460,  -460,
     196,   218,  -460,    -4,    13,  -460,  -460,  -460,  -460,  -460,
    -460,  -460,   279,   289,   289,   299,   226,   301,   162,  -460,
     300,  -460,   306,   330,   316,   247,   335,   336,   321,  1015,
    -460,  1015,  1015,  1015,  1015,  1015,  1015,  1015,  1015,  1015,
    1015,  1015,  1015,  1015,  1015,  1015,  1015,   871,  -460,   339,
    -460,  -460,  -460,  -460,  -460,  -460,  -460,   171,   171,  1015,
    1015,  1015,   323,  1015,   332,  -460,   350,   328,  -460,  -460,
    -460,   167,   -21,   346,  -460,  -460,  -460,  -460,  -460,   911,
    -460,   807,  -460,   323,   228,  -460,  -460,   923,   356,   342,
    1015,   340,  -460,   340,    28,   171,   365,   345,  1015,   355,
     357,   276,    28,   171,   363,   372,    28,  -460,   148,   193,
     270,   270,   215,   215,   215,   215,   333,   333,  -460,  -460,
    -460,  -460,  -460,  -460,  -460,    92,  -460,  -460,   369,  -460,
     309,  -460,   217,     0,   373,   385,   391,   394,   328,   422,
     334,   170,  -460,   274,  1015,   287,  -460,  -460,  -460,   615,
    -460,   171,  -460,   -21,  -460,  -460,   141,   410,  -460,   222,
     963,  -460,   407,   407,   341,   344,   405,   413,    10,  -460,
     114,  -460,     1,  -460,  -460,  -460,   405,   423,    14,    28,
      28,   405,   424,  -460,  1015,  -460,  -460,  -460,  -460,   807,
     420,  1015,   416,   351,  -460,   428,   353,  -460,  -460,   -21,
    1015,   294,  -460,   362,   431,   -21,   -21,  -460,  -460,  -460,
    -460,   456,  -460,  -460,   975,  -460,  -460,   436,   171,  -460,
       9,   441,   378,  1015,  -460,  -460,    34,  -460,   442,   379,
    1015,  -460,   405,   443,   405,   450,   451,   411,  -460,   711,
    1015,   448,  1015,   381,   472,   563,   384,  -460,    19,   -21,
    -460,  1015,  -460,  -460,   -21,  -460,   152,  -460,  -460,   388,
     392,   171,     2,  -460,  -460,   393,   171,     6,   464,   395,
     467,   411,   411,   486,   -21,  -460,   156,  1015,   161,   563,
     397,  -460,   497,    55,   498,   499,    86,   500,   271,   465,
    -460,  -460,  -460,  -460,  -460,  -460,   -21,  -460,   415,  -460,
    -460,   171,   171,   411,  -460,   171,   411,  -460,   433,   171,
     411,   418,   -21,  -460,   483,  -460,   430,   -21,   323,   492,
    -460,   507,   437,   184,   509,   439,   527,   528,   534,   525,
     455,   544,  -460,  -460,  -460,  -460,  -460,  -460,   411,   454,
     411,   -21,   171,   411,   458,  -460,  -460,   546,  -460,  -460,
    -460,  -460,    33,   171,   460,    45,   171,   537,   540,   552,
      47,   171,   463,   478,  -460,   -21,  -460,   411,   481,  -460,
    -460,   411,   175,   548,   171,   489,   178,   548,    49,    54,
      65,   411,   189,   548,   171,  -460,  -460,   488,  -460,   -21,
     411,   577,  1015,   504,   548,   171,   493,   505,   411,   191,
     510,   195,   411,   203,   -21,   411,   513,   548,  -460,  -460,
     -21,   248,  -460,   514,   411,   171,  -460,   516,   411,   171,
     511,   530,   411,  -460,   -21,  -460,   531,  -460,  -460,   -21,
     411,  -460,   532,   411,   171,  -460,   533,  -460,  -460,  -460,
     -21,  -460,   535,   411,  -460,  -460,  -460,   541,  -460
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -460,  -460,  -460,  -460,   619,   624,   626,     5,   641,   610,
     612,  -460,  -170,  -460,  -460,  -460,   389,  -460,  -204,  -192,
     343,   -22,   -17,  -460,  -460,   503,   506,   165,   174,   176,
     -10,  -460,   252,  -460,  -460,  -460,   521,    61,   438,   396,
    -190,  -460,  -460,   347,  -460,  -460,  -460,   404,  -460,  -460,
    -460,  -460,  -460,  -460,  -173,  -460,   635,  -460,  -460,  -460,
    -460,   466,  -460,  -460,  -460,  -194,  -460,  -460,  -460,  -460,
    -460,  -460,    -1,   -83,   583,   414,  -460,   275,  -381,  -460,
     265,  -179,  -317,  -460,   267,  -460,  -459,  -460,  -460,  -460,
    -460,  -460,  -162,  -460
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -202
static const yytype_int16 yytable[] =
{
     106,   107,   108,    88,    88,   185,   113,   249,   250,   272,
     256,   270,   114,    98,   123,   276,   379,     2,   296,    99,
     116,   118,   301,   124,   119,   149,   149,   149,   455,    11,
     263,   149,   149,   149,   101,   284,   207,   149,   517,   149,
     284,   383,   343,   297,   526,   288,   350,   302,     1,     2,
     149,    14,   284,   298,   284,   533,   284,   491,   455,   285,
     384,   284,   442,   146,   100,   138,   208,   110,   546,   495,
     147,   501,   284,   518,   431,   432,     3,   120,   520,   330,
      99,   191,   125,   126,   127,   128,   129,   130,   131,   522,
     197,   307,   150,   193,   206,   352,   354,   149,   120,   347,
     424,   331,    98,   192,   427,   132,   459,   341,   344,   461,
     339,   332,   351,   464,   416,   103,   303,   348,   104,   270,
     353,   355,   356,   304,   125,   126,   127,   128,   129,   130,
     131,   135,   227,    40,    41,    42,    43,    44,   361,   198,
     345,   483,   376,   485,   199,   346,   488,   139,     1,     2,
     246,   238,   239,   240,   241,   242,   243,   367,   252,   253,
     136,   108,   251,   372,   373,   333,   137,   167,   378,   330,
     507,   446,   304,   388,   509,   390,   420,   151,   248,   447,
     436,   152,   268,   304,   524,   438,   448,   149,   279,   217,
     246,   474,   149,   530,   218,   262,   292,   169,   149,   510,
     180,   537,   516,   175,   176,   541,   511,   417,   544,   511,
     189,   423,   419,   525,   144,   538,   426,   549,   145,   540,
     511,   552,   511,   148,   437,   556,   511,   542,   153,   154,
     177,   178,   435,   560,   511,   190,   562,   125,   126,   127,
     128,   129,   130,   131,   470,   306,   567,   323,   149,   187,
     335,   457,   458,   149,   456,   460,   159,   160,   279,   463,
     139,   188,    40,    41,    42,    43,    44,   317,   492,    54,
     466,   496,   281,   103,   281,   469,   502,   194,   450,   149,
     202,   203,   117,   117,   319,   320,   117,   358,   195,   108,
     202,   273,   487,   200,   519,   521,   523,   196,   368,   486,
     264,   326,   209,   493,   369,   320,   497,   155,   156,   157,
     158,   503,   181,   182,   183,   184,   210,   246,   230,   231,
     215,   382,   214,   506,   514,   185,   216,   219,   387,   232,
     233,   234,   235,   220,   527,   236,   237,   221,   396,   222,
     398,   223,   224,   225,   226,   534,   247,   529,   254,    40,
      41,    42,    43,    44,   418,   257,   402,   258,   259,   264,
     185,   451,   543,   277,   404,   550,   278,   280,   547,   553,
     406,   407,   289,   291,   295,   108,   161,   162,   163,   164,
     165,   166,   557,   293,   563,   294,   299,   559,    38,    39,
      40,    41,    42,    43,    44,   300,   217,   305,   565,   308,
     310,   312,   443,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,    15,
     311,   167,    16,    17,    18,    19,    20,    21,    22,   314,
     168,    23,   316,   334,   337,   338,   340,   342,    24,    25,
      26,    27,    28,   360,    29,   339,   362,   349,   357,   363,
    -199,   169,   170,   171,   172,   173,   174,   175,   176,   364,
    -166,    30,   371,   374,   377,   380,   385,   389,    31,    32,
      33,    34,   381,   386,   391,   392,   393,   397,  -201,   401,
      35,   415,   421,    36,   177,   178,   422,   425,   428,   429,
     531,   430,    37,   433,   440,    38,    39,    40,    41,    42,
      43,    44,    45,    46,   441,   444,   445,   449,    47,    48,
      49,    50,    51,  -167,   467,    52,   465,    53,    54,    55,
      16,    17,    18,    19,    20,    21,    22,   462,   468,    23,
     472,   473,   475,   476,   477,   478,    24,    25,    26,    27,
      28,   479,    29,    40,    41,    42,    43,    44,   480,   481,
     402,   482,   484,   490,   494,   403,   489,   504,   404,    30,
     498,   405,   454,   499,   406,   407,    31,    32,    33,    34,
      40,    41,    42,    43,    44,   500,   505,   402,    35,   508,
     512,    36,   403,   515,   379,   404,   528,   535,   405,   471,
      37,   406,   407,    38,    39,    40,    41,    42,    43,    44,
      45,    46,   532,   536,   539,   554,    47,    48,    49,    50,
      51,   545,   548,    52,   551,    53,    54,    55,    16,    17,
      18,    19,    20,    21,    22,    96,    13,    23,   555,   558,
     561,   564,    97,   566,    24,    25,    26,    27,    28,   568,
      29,    40,    41,    42,    43,    44,    95,   133,   402,   134,
     318,   283,   359,   403,   228,   213,   404,    30,   229,   405,
     324,   112,   406,   407,    31,    32,    33,    34,   370,   327,
     274,   186,   313,   452,   439,   453,    35,     0,     0,    36,
       0,     0,     0,     0,     0,     0,     0,     0,    37,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    45,    46,
       0,     0,     0,     0,     0,    48,     0,     0,     0,     0,
       0,    52,   329,    53,    16,    17,    18,    19,    20,    21,
      22,     0,     0,    23,     0,     0,     0,     0,     0,     0,
      24,    25,    26,    27,    28,     0,    29,   395,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    30,     0,     0,     0,     0,     0,     0,
      31,    32,    33,    34,     0,     0,     0,     0,     0,     0,
       0,     0,    35,     0,     0,    36,     0,     0,     0,     0,
       0,     0,     0,     0,    37,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    45,    46,     0,     0,     0,     0,
       0,    48,     0,     0,     0,     0,     0,    52,     0,    53,
      16,    17,    18,    19,    20,    21,    22,     0,     0,    23,
       0,     0,     0,     0,     0,     0,    24,    25,    26,    27,
      28,     0,    29,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    30,
       0,     0,     0,     0,     0,     0,    31,    32,    33,    34,
       0,     0,    16,    17,    18,    19,   105,    21,    35,     0,
       0,    36,     0,     0,    16,    17,    18,    19,   105,    21,
      37,    27,    28,     0,    29,     0,     0,     0,     0,     0,
      45,    46,     0,    27,    28,   244,    29,    48,     0,     0,
       0,    30,     0,    52,     0,    53,     0,     0,    31,    32,
      33,    34,     0,    30,    16,    17,    18,    19,   105,    21,
      31,    32,    33,    34,     0,     0,    16,    17,    18,    19,
     105,    21,    37,    27,    28,     0,    29,   267,     0,     0,
       0,     0,    45,    46,    37,    27,    28,   275,    29,     0,
       0,     0,     0,    30,    45,    46,     0,   122,     0,     0,
      31,    32,    33,    34,     0,    30,    16,    17,    18,    19,
     105,    21,    31,    32,    33,    34,     0,     0,    16,    17,
      18,    19,   105,    21,    37,    27,    28,     0,    29,     0,
       0,   336,     0,     0,    45,    46,    37,    27,    28,   375,
      29,     0,     0,     0,     0,    30,    45,    46,     0,     0,
       0,     0,    31,    32,    33,    34,     0,    30,    16,    17,
      18,    19,   105,    21,    31,    32,    33,    34,     0,     0,
       0,     0,     0,     0,     0,     0,    37,    27,    28,     0,
      29,     0,     0,     0,     0,     0,    45,    46,    37,     0,
       0,     0,     0,     0,     0,     0,     0,    30,    45,    46,
       0,     0,     0,     0,    31,    32,    33,    34,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    37,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    45,    46
};

static const yytype_int16 yycheck[] =
{
      22,    23,    24,     4,     5,    88,    28,   177,   178,   203,
     183,   201,    29,     8,    36,   207,     7,    75,   222,    53,
      30,    31,   226,     7,    34,    31,    31,    31,   409,     7,
     192,    31,    31,    31,     7,     7,    23,    31,   497,    31,
       7,     7,    32,   222,   503,   215,    32,   226,    74,    75,
      31,     7,     7,   223,     7,   514,     7,    24,   439,    31,
      26,     7,     7,    93,    98,     7,    53,     7,   527,    24,
     100,    24,     7,    24,   391,   392,   102,    98,    24,   269,
      53,   103,    66,    67,    68,    69,    70,    71,    72,    24,
      24,   253,    98,    98,    98,   299,   300,    31,    98,    98,
      98,   271,    97,    95,    98,    89,   423,   286,    98,   426,
     101,   273,    98,   430,    95,    27,    24,   296,    30,   309,
     299,   300,   301,    31,    66,    67,    68,    69,    70,    71,
      72,     7,   149,    78,    79,    80,    81,    82,   311,    26,
      26,   458,   334,   460,    31,    31,   463,    89,    74,    75,
     167,   161,   162,   163,   164,   165,   166,   319,   180,   181,
       7,   183,   179,   325,   326,    24,     7,    23,   338,   359,
     487,    85,    31,   352,   491,   354,    24,    34,     7,    93,
      24,    33,   199,    31,   501,    24,   100,    31,   210,    27,
     207,     7,    31,   510,    32,    28,   218,    53,    31,    24,
      27,   518,    24,    59,    60,   522,    31,   369,   525,    31,
      98,   381,   374,    24,     7,    24,   386,   534,     7,    24,
      31,   538,    31,     7,   397,   542,    31,    24,    35,    36,
      86,    87,   394,   550,    31,    98,   553,    66,    67,    68,
      69,    70,    71,    72,   438,    28,   563,   264,    31,     7,
      28,   421,   422,    31,   416,   425,    41,    42,   280,   429,
      89,     7,    78,    79,    80,    81,    82,    97,   472,    99,
     432,   475,   211,    27,   213,   437,   480,    98,     7,    31,
      62,    63,    30,    31,    10,    11,    34,   304,    98,   311,
      62,    63,   462,    97,   498,   499,   500,    98,   320,   461,
      13,    14,    23,   473,    10,    11,   476,    37,    38,    39,
      40,   481,    15,    16,    17,    18,    27,   334,   153,   154,
      94,   343,    23,   485,   494,   408,    25,    27,   350,   155,
     156,   157,   158,    27,   504,   159,   160,     7,   360,    23,
     362,    94,     7,     7,    23,   515,     7,   509,    25,    78,
      79,    80,    81,    82,   371,    23,    85,     7,    30,    13,
     443,    90,   524,     7,    93,   535,    24,    27,   530,   539,
      99,   100,     7,    28,    98,   397,    43,    44,    45,    46,
      47,    48,   544,    28,   554,    28,    23,   549,    76,    77,
      78,    79,    80,    81,    82,    23,    27,    88,   560,    26,
      15,     7,   403,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,     0,
      29,    23,     3,     4,     5,     6,     7,     8,     9,     7,
      32,    12,    98,    23,    27,    94,    31,    24,    19,    20,
      21,    22,    23,    23,    25,   101,    30,    24,    24,    98,
      97,    53,    54,    55,    56,    57,    58,    59,    60,    31,
      98,    42,    31,     7,    28,    24,    24,    24,    49,    50,
      51,    52,    94,    94,    24,    24,    65,    29,    97,     7,
      61,    97,    94,    64,    86,    87,    94,    94,    24,    94,
     512,    24,    73,     7,    97,    76,    77,    78,    79,    80,
      81,    82,    83,    84,     7,     7,     7,     7,    89,    90,
      91,    92,    93,    98,    31,    96,    98,    98,    99,   100,
       3,     4,     5,     6,     7,     8,     9,    94,    98,    12,
      23,    94,    23,    94,     7,     7,    19,    20,    21,    22,
      23,     7,    25,    78,    79,    80,    81,    82,    23,    94,
      85,     7,    98,     7,    94,    90,    98,    94,    93,    42,
      23,    96,    97,    23,    99,   100,    49,    50,    51,    52,
      78,    79,    80,    81,    82,    23,    98,    85,    61,    98,
      32,    64,    90,    94,     7,    93,    98,    94,    96,    97,
      73,    99,   100,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    98,    98,    94,    94,    89,    90,    91,    92,
      93,    98,    98,    96,    98,    98,    99,   100,     3,     4,
       5,     6,     7,     8,     9,     6,     2,    12,    98,    98,
      98,    98,     6,    98,    19,    20,    21,    22,    23,    98,
      25,    78,    79,    80,    81,    82,     5,    37,    85,    37,
     261,   213,   309,    90,   151,   134,    93,    42,   152,    96,
     264,    26,    99,   100,    49,    50,    51,    52,   321,   265,
     204,    88,   258,   408,   399,   408,    61,    -1,    -1,    64,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,    84,
      -1,    -1,    -1,    -1,    -1,    90,    -1,    -1,    -1,    -1,
      -1,    96,    97,    98,     3,     4,     5,     6,     7,     8,
       9,    -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    20,    21,    22,    23,    -1,    25,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    61,    -1,    -1,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    83,    84,    -1,    -1,    -1,    -1,
      -1,    90,    -1,    -1,    -1,    -1,    -1,    96,    -1,    98,
       3,     4,     5,     6,     7,     8,     9,    -1,    -1,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    21,    22,
      23,    -1,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,
      -1,    -1,     3,     4,     5,     6,     7,     8,    61,    -1,
      -1,    64,    -1,    -1,     3,     4,     5,     6,     7,     8,
      73,    22,    23,    -1,    25,    -1,    -1,    -1,    -1,    -1,
      83,    84,    -1,    22,    23,    24,    25,    90,    -1,    -1,
      -1,    42,    -1,    96,    -1,    98,    -1,    -1,    49,    50,
      51,    52,    -1,    42,     3,     4,     5,     6,     7,     8,
      49,    50,    51,    52,    -1,    -1,     3,     4,     5,     6,
       7,     8,    73,    22,    23,    -1,    25,    26,    -1,    -1,
      -1,    -1,    83,    84,    73,    22,    23,    24,    25,    -1,
      -1,    -1,    -1,    42,    83,    84,    -1,    98,    -1,    -1,
      49,    50,    51,    52,    -1,    42,     3,     4,     5,     6,
       7,     8,    49,    50,    51,    52,    -1,    -1,     3,     4,
       5,     6,     7,     8,    73,    22,    23,    -1,    25,    -1,
      -1,    28,    -1,    -1,    83,    84,    73,    22,    23,    24,
      25,    -1,    -1,    -1,    -1,    42,    83,    84,    -1,    -1,
      -1,    -1,    49,    50,    51,    52,    -1,    42,     3,     4,
       5,     6,     7,     8,    49,    50,    51,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    22,    23,    -1,
      25,    -1,    -1,    -1,    -1,    -1,    83,    84,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    83,    84,
      -1,    -1,    -1,    -1,    49,    50,    51,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,    84
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    74,    75,   102,   104,   105,   106,   107,   109,   110,
     116,     7,   108,   108,     7,     0,     3,     4,     5,     6,
       7,     8,     9,    12,    19,    20,    21,    22,    23,    25,
      42,    49,    50,    51,    52,    61,    64,    73,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    89,    90,    91,
      92,    93,    96,    98,    99,   100,   111,   119,   120,   124,
     125,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   143,   144,   147,   148,   153,   154,   155,
     156,   158,   160,   161,   162,   166,   167,   170,   175,   176,
     177,   188,   191,   192,   194,   111,   107,   109,   110,    53,
      98,     7,   117,    27,    30,     7,   124,   124,   124,   157,
       7,   159,   159,   124,   125,   142,   133,   135,   133,   133,
      98,   195,    98,   124,     7,    66,    67,    68,    69,    70,
      71,    72,    89,   112,   113,     7,     7,     7,     7,    89,
     112,   113,   114,   115,     7,     7,    93,   100,     7,    31,
      98,    34,    33,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    23,    32,    53,
      54,    55,    56,    57,    58,    59,    60,    86,    87,   126,
      27,    15,    16,    17,    18,   176,   177,     7,     7,    98,
      98,   124,    95,    98,    98,    98,    98,    24,    26,    31,
      97,   196,    62,    63,   163,   164,    98,    23,    53,    23,
      27,   139,   140,   139,    23,    94,    25,    27,    32,    27,
      27,     7,    23,    94,     7,     7,    23,   125,   128,   129,
     130,   130,   131,   131,   131,   131,   132,   132,   133,   133,
     133,   133,   133,   133,    24,   122,   125,     7,     7,   115,
     115,   125,   124,   124,    25,   168,   157,    23,     7,    30,
     178,   118,    28,   195,    13,   149,   150,    26,   125,   123,
     143,   165,   168,    63,   164,    24,   122,     7,    24,   124,
      27,   140,   141,   141,     7,    31,   121,   184,   115,     7,
     193,    28,   124,    28,    28,    98,   121,   184,   115,    23,
      23,   121,   184,    24,    31,    88,    28,   195,    26,   169,
      15,    29,     7,   178,     7,   179,    98,    97,   119,    10,
      11,   145,   146,   125,   142,   152,    14,   150,   151,    97,
     143,   115,   195,    24,    23,    28,    28,    27,    94,   101,
      31,   184,    24,    32,    98,    26,    31,    98,   184,    24,
      32,    98,   121,   184,   121,   184,   184,    24,   125,   123,
      23,   157,    30,    98,    31,   171,   173,   195,   124,    10,
     146,    31,   195,   195,     7,    24,   122,    28,   115,     7,
      24,    94,   124,     7,    26,    24,    94,   124,   184,    24,
     184,    24,    24,    65,   185,    26,   124,    29,   124,   172,
     174,     7,    85,    90,    93,    96,    99,   100,   175,   180,
     181,   182,   183,   187,   190,    97,    95,   195,   125,   195,
      24,    94,    94,   115,    98,    94,   115,    98,    24,    94,
      24,   185,   185,     7,   186,   195,    24,   157,    24,   180,
      97,     7,     7,   175,     7,     7,    85,    93,   100,     7,
       7,    90,   183,   187,    97,   181,   195,   115,   115,   185,
     115,   185,    94,   115,   185,    98,   195,    31,    98,   195,
     168,    97,    23,    94,     7,    23,    94,     7,     7,     7,
      23,    94,     7,   185,    98,   185,   195,   115,   185,    98,
       7,    24,   121,   115,    94,    24,   121,   115,    23,    23,
      23,    24,   121,   115,    94,    98,   195,   185,    98,   185,
      24,    31,    32,   189,   115,    94,    24,   189,    24,   121,
      24,   121,    24,   121,   185,    24,   189,   115,    98,   195,
     185,   124,    98,   189,   115,    94,    98,   185,    24,    94,
      24,   185,    24,   195,   185,    98,   189,   195,    98,   185,
     115,    98,   185,   115,    94,    98,   185,   195,    98,   195,
     185,    98,   185,   115,    98,   195,    98,   185,    98
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
#line 101 "diksam.y"
    {
            dkc_set_require_and_rename_list(NULL, NULL);
        }
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 105 "diksam.y"
    {
            dkc_set_require_and_rename_list((yyvsp[(1) - (2)].require_list), (yyvsp[(2) - (2)].rename_list));
        }
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 109 "diksam.y"
    {
            dkc_set_require_and_rename_list((yyvsp[(1) - (1)].require_list), NULL);
        }
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 113 "diksam.y"
    {
            dkc_set_require_and_rename_list(NULL, (yyvsp[(1) - (1)].rename_list));
        }
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 117 "diksam.y"
    {
            dkc_set_require_and_rename_list(NULL, NULL);
		}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 124 "diksam.y"
    {
            (yyval.require_list) = dkc_chain_require_list((yyvsp[(1) - (2)].require_list), (yyvsp[(2) - (2)].require_list));
        }
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 130 "diksam.y"
    {
            (yyval.require_list) = dkc_create_require_list((yyvsp[(2) - (3)].package_name));
        }
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 136 "diksam.y"
    {
            (yyval.package_name) = dkc_create_package_name((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 140 "diksam.y"
    {
            (yyval.package_name) = dkc_chain_package_name((yyvsp[(1) - (3)].package_name), (yyvsp[(3) - (3)].identifier));
        }
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 147 "diksam.y"
    {
            (yyval.rename_list) = dkc_chain_rename_list((yyvsp[(1) - (2)].rename_list), (yyvsp[(2) - (2)].rename_list));
        }
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 153 "diksam.y"
    {
            (yyval.rename_list) = dkc_create_rename_list((yyvsp[(2) - (4)].package_name), (yyvsp[(3) - (4)].identifier));
        }
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 161 "diksam.y"
    {
            DKC_Compiler *compiler = dkc_get_current_compiler();

            compiler->statement_list
                = dkc_chain_statement_list(compiler->statement_list, (yyvsp[(1) - (1)].statement));
        }
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 173 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_VOID_TYPE;
        }
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 177 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_BOOLEAN_TYPE;
        }
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 181 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_INT_TYPE;
        }
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 185 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_DOUBLE_TYPE;
        }
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 189 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_STRING_TYPE;
        }
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 193 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_VARIENT_TYPE;
        }
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 197 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_NATIVE_POINTER_TYPE;
        }
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 201 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_DELEGATE_TYPE;
        }
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 207 "diksam.y"
    {
            (yyval.type_specifier) = dkc_create_identifier_type_specifier((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 213 "diksam.y"
    {
            TypeSpecifier *basic_type
                = dkc_create_type_specifier((yyvsp[(1) - (3)].basic_type_specifier));
            (yyval.type_specifier) = dkc_create_array_type_specifier(basic_type);
        }
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 219 "diksam.y"
    {
            TypeSpecifier *identifier_type
                = dkc_create_identifier_type_specifier((yyvsp[(1) - (3)].identifier));
            (yyval.type_specifier) = dkc_create_array_type_specifier(identifier_type);
        }
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 225 "diksam.y"
    {
            (yyval.type_specifier) = dkc_create_array_type_specifier((yyvsp[(1) - (3)].type_specifier));
        }
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 231 "diksam.y"
    {
                    (yyval.type_specifier) = dkc_create_type_specifier((yyvsp[(1) - (1)].basic_type_specifier));
        }
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 240 "diksam.y"
    {
			BcGetCurrentCompilerContext()->libname=(yyvsp[(2) - (2)].identifier);
		}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 244 "diksam.y"
    {
			BcGetCurrentCompilerContext()->libname=0;
		}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 255 "diksam.y"
    {
            dkc_function_define((yyvsp[(9) - (11)].type_specifier), (yyvsp[(3) - (11)].identifier), (yyvsp[(5) - (11)].parameter_list), (yyvsp[(10) - (11)].exception_list), NULL,(yyvsp[(6) - (11)].apost));
        }
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 259 "diksam.y"
    {
            dkc_function_define((yyvsp[(8) - (10)].type_specifier), (yyvsp[(3) - (10)].identifier), NULL, (yyvsp[(9) - (10)].exception_list), NULL,(yyvsp[(5) - (10)].apost));
        }
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 263 "diksam.y"
    {
            dkc_function_define(0, (yyvsp[(3) - (9)].identifier), (yyvsp[(5) - (9)].parameter_list), (yyvsp[(8) - (9)].exception_list), NULL,(yyvsp[(6) - (9)].apost));
        }
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 267 "diksam.y"
    {
			printf("lib:%s\n",BcGetCurrentCompilerContext()->libname);
            dkc_function_define(0, (yyvsp[(3) - (8)].identifier), NULL, (yyvsp[(7) - (8)].exception_list), NULL,(yyvsp[(5) - (8)].apost));
        }
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 274 "diksam.y"
    {
            dkc_function_define((yyvsp[(8) - (10)].type_specifier), (yyvsp[(2) - (10)].identifier), (yyvsp[(4) - (10)].parameter_list), (yyvsp[(9) - (10)].exception_list), (yyvsp[(10) - (10)].block),(yyvsp[(5) - (10)].apost));
        }
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 278 "diksam.y"
    {
            dkc_function_define((yyvsp[(7) - (9)].type_specifier), (yyvsp[(2) - (9)].identifier), NULL, (yyvsp[(8) - (9)].exception_list), (yyvsp[(9) - (9)].block),(yyvsp[(4) - (9)].apost));
        }
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 282 "diksam.y"
    { //modified
            dkc_function_define(0, (yyvsp[(2) - (8)].identifier), (yyvsp[(4) - (8)].parameter_list), (yyvsp[(7) - (8)].exception_list), (yyvsp[(8) - (8)].block),(yyvsp[(5) - (8)].apost));
        }
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 286 "diksam.y"
    {
            dkc_function_define(0, (yyvsp[(2) - (7)].identifier), NULL, (yyvsp[(6) - (7)].exception_list), (yyvsp[(7) - (7)].block),(yyvsp[(4) - (7)].apost));
        }
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 293 "diksam.y"
    {
            (yyval.parameter_list) = dkc_create_parameter((yyvsp[(3) - (3)].type_specifier), (yyvsp[(1) - (3)].identifier));
        }
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 297 "diksam.y"
    {
            (yyval.parameter_list) = dkc_chain_parameter((yyvsp[(1) - (5)].parameter_list), (yyvsp[(5) - (5)].type_specifier), (yyvsp[(3) - (5)].identifier));
        }
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 303 "diksam.y"
    {
            (yyval.argument_list) = dkc_create_argument_list((yyvsp[(1) - (1)].expression));
        }
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 307 "diksam.y"
    {
            (yyval.argument_list) = dkc_chain_argument_list((yyvsp[(1) - (3)].argument_list), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 313 "diksam.y"
    {
            (yyval.statement_list) = dkc_create_statement_list((yyvsp[(1) - (1)].statement));
        }
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 317 "diksam.y"
    {
            (yyval.statement_list) = dkc_chain_statement_list((yyvsp[(1) - (2)].statement_list), (yyvsp[(2) - (2)].statement));
        }
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 324 "diksam.y"
    {
            (yyval.expression) = dkc_create_comma_expression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 331 "diksam.y"
    {
            (yyval.expression) = dkc_create_assign_expression((yyvsp[(1) - (3)].expression), (yyvsp[(2) - (3)].assignment_operator), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 337 "diksam.y"
    {
            (yyval.assignment_operator) = NORMAL_ASSIGN;
        }
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 341 "diksam.y"
    {
            (yyval.assignment_operator) = ADD_ASSIGN;
        }
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 345 "diksam.y"
    {
            (yyval.assignment_operator) = SUB_ASSIGN;
        }
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 349 "diksam.y"
    {
            (yyval.assignment_operator) = MUL_ASSIGN;
        }
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 353 "diksam.y"
    {
            (yyval.assignment_operator) = DIV_ASSIGN;
        }
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 357 "diksam.y"
    {
            (yyval.assignment_operator) = MOD_ASSIGN;
        }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 364 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(LOGICAL_OR_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 371 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(LOGICAL_AND_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 378 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(EQ_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 382 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(NE_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 389 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(GT_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 393 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(GE_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 397 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(LT_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 401 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(LE_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 408 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(ADD_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 412 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(SUB_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 419 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(MUL_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 423 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(DIV_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 427 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(MOD_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 431 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(BIT_AND_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 435 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(BIT_OR_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 439 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(BIT_XOR_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 446 "diksam.y"
    {
            (yyval.expression) = dkc_create_minus_expression((yyvsp[(2) - (2)].expression));
        }
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 450 "diksam.y"
    {
            (yyval.expression) = dkc_create_logical_not_expression((yyvsp[(2) - (2)].expression));
        }
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 454 "diksam.y"
    {
            (yyval.expression) = dkc_create_bit_not_expression((yyvsp[(2) - (2)].expression));
        }
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 461 "diksam.y"
    {
            (yyval.expression) = dkc_create_incdec_expression((yyvsp[(1) - (2)].expression), INCREMENT_EXPRESSION);
        }
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 465 "diksam.y"
    {
            (yyval.expression) = dkc_create_incdec_expression((yyvsp[(1) - (2)].expression), DECREMENT_EXPRESSION);
        }
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 469 "diksam.y"
    {
            (yyval.expression) = dkc_create_instanceof_expression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].type_specifier));
        }
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 477 "diksam.y"
    {
            (yyval.expression) = dkc_create_identifier_expression((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 481 "diksam.y"
    {
			(yyval.expression)=BcCreateAutoExpression((yyvsp[(1) - (1)].identifier));
		}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 487 "diksam.y"
    {
            (yyval.expression) = dkc_create_index_expression((yyvsp[(1) - (4)].expression), (yyvsp[(3) - (4)].expression));
        }
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 491 "diksam.y"
    {
            Expression *identifier = dkc_create_identifier_expression((yyvsp[(1) - (4)].identifier));
            (yyval.expression) = dkc_create_index_expression(identifier, (yyvsp[(3) - (4)].expression));
        }
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 496 "diksam.y"
    {
            (yyval.expression) = dkc_create_member_expression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].identifier));
        }
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 500 "diksam.y"
    {
            (yyval.expression) = dkc_create_function_call_expression((yyvsp[(1) - (4)].expression), (yyvsp[(3) - (4)].argument_list));
        }
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 504 "diksam.y"
    {
            (yyval.expression) = dkc_create_function_call_expression((yyvsp[(1) - (3)].expression), NULL);
        }
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 508 "diksam.y"
    {
            (yyval.expression) = (yyvsp[(2) - (3)].expression);
        }
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 512 "diksam.y"
    {
            (yyval.expression) = dkc_create_down_cast_expression((yyvsp[(1) - (4)].expression), (yyvsp[(3) - (4)].type_specifier));
        }
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 520 "diksam.y"
    {
            (yyval.expression) = dkc_create_boolean_expression(DVM_TRUE);
        }
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 524 "diksam.y"
    {
            (yyval.expression) = dkc_create_boolean_expression(DVM_FALSE);
        }
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 528 "diksam.y"
    {
            (yyval.expression) = dkc_create_null_expression();
        }
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 533 "diksam.y"
    {
            (yyval.expression) = dkc_create_this_expression();
        }
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 537 "diksam.y"
    {
            (yyval.expression) = dkc_create_super_expression();
        }
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 541 "diksam.y"
    {
			(yyval.expression) = dkc_create_new_delegate_expression();
		}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 545 "diksam.y"
    {
            (yyval.expression) = dkc_create_new_expression((yyvsp[(2) - (4)].identifier), NULL, NULL);
        }
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 549 "diksam.y"
    {
            (yyval.expression) = dkc_create_new_expression((yyvsp[(2) - (5)].identifier), NULL, (yyvsp[(4) - (5)].argument_list));
        }
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 553 "diksam.y"
    {
            (yyval.expression) = dkc_create_new_expression((yyvsp[(2) - (6)].identifier), (yyvsp[(4) - (6)].identifier), NULL);
        }
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 557 "diksam.y"
    {
            (yyval.expression) = dkc_create_new_expression((yyvsp[(2) - (7)].identifier), (yyvsp[(4) - (7)].identifier), (yyvsp[(6) - (7)].argument_list));
        }
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 563 "diksam.y"
    {
            (yyval.expression) = dkc_create_array_literal_expression((yyvsp[(2) - (3)].expression_list));
        }
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 567 "diksam.y"
    {
            (yyval.expression) = dkc_create_array_literal_expression((yyvsp[(2) - (4)].expression_list));
        }
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 573 "diksam.y"
    {
            (yyval.expression) = dkc_create_basic_array_creation((yyvsp[(2) - (3)].basic_type_specifier), (yyvsp[(3) - (3)].array_dimension), NULL);
        }
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 577 "diksam.y"
    {
            (yyval.expression) = dkc_create_basic_array_creation((yyvsp[(2) - (4)].basic_type_specifier), (yyvsp[(3) - (4)].array_dimension), (yyvsp[(4) - (4)].array_dimension));
        }
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 581 "diksam.y"
    {
            (yyval.expression) = dkc_create_class_array_creation((yyvsp[(2) - (3)].type_specifier), (yyvsp[(3) - (3)].array_dimension), NULL);
        }
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 586 "diksam.y"
    {
            (yyval.expression) = dkc_create_class_array_creation((yyvsp[(2) - (4)].type_specifier), (yyvsp[(3) - (4)].array_dimension), (yyvsp[(4) - (4)].array_dimension));
        }
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 593 "diksam.y"
    {
            (yyval.array_dimension) = dkc_chain_array_dimension((yyvsp[(1) - (2)].array_dimension), (yyvsp[(2) - (2)].array_dimension));
        }
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 599 "diksam.y"
    {
            (yyval.array_dimension) = dkc_create_array_dimension((yyvsp[(2) - (3)].expression));
        }
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 605 "diksam.y"
    {
            (yyval.array_dimension) = dkc_create_array_dimension(NULL);
        }
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 609 "diksam.y"
    {
            (yyval.array_dimension) = dkc_chain_array_dimension((yyvsp[(1) - (3)].array_dimension),
                                           dkc_create_array_dimension(NULL));
        }
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 616 "diksam.y"
    {
            (yyval.expression_list) = NULL;
        }
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 620 "diksam.y"
    {
            (yyval.expression_list) = dkc_create_expression_list((yyvsp[(1) - (1)].expression));
        }
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 624 "diksam.y"
    {
            (yyval.expression_list) = dkc_chain_expression_list((yyvsp[(1) - (3)].expression_list), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 630 "diksam.y"
    {
          (yyval.statement) = dkc_create_expression_statement((yyvsp[(1) - (2)].expression));
        }
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 646 "diksam.y"
    {/*empty line*/
			(yyval.statement)=0;
		}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 652 "diksam.y"
    {
            (yyval.statement) = dkc_create_if_statement((yyvsp[(2) - (4)].expression), (yyvsp[(4) - (4)].block), NULL, NULL);
        }
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 656 "diksam.y"
    {
			//printf("IF-ELSE %d\n",dkc_get_current_compiler()->current_line_number);
            (yyval.statement) = dkc_create_if_statement((yyvsp[(2) - (6)].expression), (yyvsp[(4) - (6)].block), NULL, (yyvsp[(6) - (6)].block));
        }
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 661 "diksam.y"
    {
            (yyval.statement) = dkc_create_if_statement((yyvsp[(2) - (5)].expression), (yyvsp[(4) - (5)].block), (yyvsp[(5) - (5)].elsif), NULL);
        }
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 665 "diksam.y"
    {
            (yyval.statement) = dkc_create_if_statement((yyvsp[(2) - (7)].expression), (yyvsp[(4) - (7)].block), (yyvsp[(5) - (7)].elsif), (yyvsp[(7) - (7)].block));
        }
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 672 "diksam.y"
    {
            (yyval.elsif) = dkc_chain_elsif_list((yyvsp[(1) - (2)].elsif), (yyvsp[(2) - (2)].elsif));
        }
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 678 "diksam.y"
    {
            (yyval.elsif) = dkc_create_elsif((yyvsp[(2) - (4)].expression), (yyvsp[(4) - (4)].block));
        }
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 684 "diksam.y"
    {
            (yyval.identifier) = NULL;
        }
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 688 "diksam.y"
    {
            (yyval.identifier) = (yyvsp[(1) - (2)].identifier);
        }
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 694 "diksam.y"
    {
            (yyval.statement) = dkc_create_switch_statement((yyvsp[(2) - (5)].expression), (yyvsp[(4) - (5)].case_list), (yyvsp[(5) - (5)].block));
        }
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 701 "diksam.y"
    {
            (yyval.case_list) = dkc_chain_case((yyvsp[(1) - (2)].case_list), (yyvsp[(2) - (2)].case_list));
        }
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 707 "diksam.y"
    {
            (yyval.case_list) = dkc_create_one_case((yyvsp[(2) - (3)].expression_list), (yyvsp[(3) - (3)].block));
        }
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 713 "diksam.y"
    {
            (yyval.block) = NULL;
        }
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 717 "diksam.y"
    {
            (yyval.block) = (yyvsp[(2) - (2)].block);
        }
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 723 "diksam.y"
    {
            (yyval.expression_list) = dkc_create_expression_list((yyvsp[(1) - (1)].expression));
        }
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 727 "diksam.y"
    {
            (yyval.expression_list) = dkc_chain_expression_list((yyvsp[(1) - (3)].expression_list), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 733 "diksam.y"
    {
            (yyval.statement) = dkc_create_while_statement((yyvsp[(1) - (4)].identifier), (yyvsp[(3) - (4)].expression), (yyvsp[(4) - (4)].block));
        }
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 739 "diksam.y"
    {
            (yyval.statement) = dkc_create_for_statement((yyvsp[(1) - (8)].identifier), (yyvsp[(3) - (8)].expression), (yyvsp[(5) - (8)].expression), (yyvsp[(7) - (8)].expression), (yyvsp[(8) - (8)].block));
        }
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 745 "diksam.y"
    {
            (yyval.statement) = dkc_create_do_while_statement((yyvsp[(1) - (8)].identifier), (yyvsp[(3) - (8)].block), (yyvsp[(6) - (8)].expression));
        }
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 751 "diksam.y"
    {
            (yyval.statement) = dkc_create_foreach_statement((yyvsp[(1) - (8)].identifier), (yyvsp[(4) - (8)].identifier), (yyvsp[(6) - (8)].expression), (yyvsp[(8) - (8)].block));
        }
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 757 "diksam.y"
    {
            (yyval.expression) = NULL;
        }
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 764 "diksam.y"
    {
            (yyval.statement) = dkc_create_return_statement((yyvsp[(2) - (3)].expression));
        }
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 770 "diksam.y"
    {
            (yyval.identifier) = NULL;
        }
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 777 "diksam.y"
    {
            (yyval.statement) = dkc_create_break_statement((yyvsp[(2) - (3)].identifier));
        }
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 783 "diksam.y"
    {
            (yyval.statement) = dkc_create_continue_statement((yyvsp[(2) - (3)].identifier));
        }
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 789 "diksam.y"
    {
            (yyval.statement) = dkc_create_try_statement((yyvsp[(2) - (5)].block), (yyvsp[(3) - (5)].catch_clause), (yyvsp[(5) - (5)].block));
        }
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 793 "diksam.y"
    {
            (yyval.statement) = dkc_create_try_statement((yyvsp[(2) - (4)].block), NULL, (yyvsp[(4) - (4)].block));
        }
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 797 "diksam.y"
    {
            (yyval.statement) = dkc_create_try_statement((yyvsp[(2) - (3)].block), (yyvsp[(3) - (3)].catch_clause), NULL);
        }
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 804 "diksam.y"
    {
            (yyval.catch_clause) = dkc_chain_catch_list((yyvsp[(1) - (2)].catch_clause), (yyvsp[(2) - (2)].catch_clause));
        }
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 810 "diksam.y"
    {
            (yyval.catch_clause) = dkc_start_catch_clause();
        }
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 814 "diksam.y"
    {
            (yyval.catch_clause) = dkc_end_catch_clause((yyvsp[(2) - (5)].catch_clause), (yyvsp[(3) - (5)].type_specifier), (yyvsp[(4) - (5)].identifier), (yyvsp[(5) - (5)].block));
        }
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 820 "diksam.y"
    {
            (yyval.statement) = dkc_create_throw_statement((yyvsp[(2) - (3)].expression));
        }
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 824 "diksam.y"
    {
            (yyval.statement) = dkc_create_throw_statement(NULL);
        }
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 830 "diksam.y"
    {
            (yyval.statement) = dkc_create_declaration_statement(DVM_FALSE, (yyvsp[(4) - (5)].type_specifier), (yyvsp[(2) - (5)].identifier), NULL);
        }
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 834 "diksam.y"
    {
            (yyval.statement) = dkc_create_declaration_statement(DVM_FALSE, (yyvsp[(4) - (7)].type_specifier), (yyvsp[(2) - (7)].identifier), (yyvsp[(6) - (7)].expression));
        }
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 838 "diksam.y"
    {
            (yyval.statement) = dkc_create_declaration_statement(DVM_FALSE, (yyvsp[(4) - (5)].type_specifier), (yyvsp[(2) - (5)].identifier), NULL);
        }
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 842 "diksam.y"
    {
            (yyval.statement) = dkc_create_declaration_statement(DVM_TRUE, (yyvsp[(4) - (7)].type_specifier), (yyvsp[(2) - (7)].identifier), (yyvsp[(6) - (7)].expression));
        }
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 848 "diksam.y"
    {
            (yyval.block) = dkc_open_block();
        }
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 852 "diksam.y"
    {
            (yyval.block) = dkc_close_block((yyvsp[(2) - (4)].block), (yyvsp[(3) - (4)].statement_list));
        }
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 856 "diksam.y"
    {
            Block *empty_block = dkc_open_block();
            (yyval.block) = dkc_close_block(empty_block, NULL);
        }
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 864 "diksam.y"
    {
            dkc_start_class_definition(NULL, (yyvsp[(1) - (4)].class_or_interface), (yyvsp[(2) - (4)].identifier), (yyvsp[(3) - (4)].extends_list));
        }
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 868 "diksam.y"
    {
            dkc_class_define((yyvsp[(6) - (7)].member_declaration));
        }
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 873 "diksam.y"
    {
            dkc_start_class_definition(&(yyvsp[(1) - (5)].class_or_member_modifier), (yyvsp[(2) - (5)].class_or_interface), (yyvsp[(3) - (5)].identifier), (yyvsp[(4) - (5)].extends_list));
        }
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 876 "diksam.y"
    {
            dkc_class_define((yyvsp[(7) - (8)].member_declaration));
        }
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 880 "diksam.y"
    {
            dkc_start_class_definition(NULL, (yyvsp[(1) - (4)].class_or_interface), (yyvsp[(2) - (4)].identifier), (yyvsp[(3) - (4)].extends_list));
        }
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 884 "diksam.y"
    {
            dkc_class_define(NULL);
        }
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 889 "diksam.y"
    {
            dkc_start_class_definition(&(yyvsp[(1) - (5)].class_or_member_modifier), (yyvsp[(2) - (5)].class_or_interface), (yyvsp[(3) - (5)].identifier), (yyvsp[(4) - (5)].extends_list));
        }
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 893 "diksam.y"
    {
            dkc_class_define(NULL);
        }
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 900 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_chain_class_or_member_modifier((yyvsp[(1) - (2)].class_or_member_modifier), (yyvsp[(2) - (2)].class_or_member_modifier));
        }
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 907 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(VIRTUAL_MODIFIER);
        }
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 911 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(OVERRIDE_MODIFIER);
        }
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 915 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(ABSTRACT_MODIFIER);
        }
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 921 "diksam.y"
    {
            (yyval.class_or_interface) = DVM_CLASS_DEFINITION;
        }
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 925 "diksam.y"
    {
            (yyval.class_or_interface) = DVM_INTERFACE_DEFINITION;
        }
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 931 "diksam.y"
    {
            (yyval.extends_list) = NULL;
        }
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 935 "diksam.y"
    {
            (yyval.extends_list) = (yyvsp[(2) - (2)].extends_list);
        }
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 941 "diksam.y"
    {
            (yyval.extends_list) = dkc_create_extends_list((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 945 "diksam.y"
    {
            (yyval.extends_list) = dkc_chain_extends_list((yyvsp[(1) - (3)].extends_list), (yyvsp[(3) - (3)].identifier));
        }
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 952 "diksam.y"
    {
            (yyval.member_declaration) = dkc_chain_member_declaration((yyvsp[(1) - (2)].member_declaration), (yyvsp[(2) - (2)].member_declaration));
        }
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 962 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_method_member(NULL, (yyvsp[(1) - (1)].function_definition), DVM_FALSE);
        }
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 966 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_method_member(&(yyvsp[(1) - (2)].class_or_member_modifier), (yyvsp[(2) - (2)].function_definition), DVM_FALSE);
        }
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 970 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_method_member(NULL, (yyvsp[(1) - (1)].function_definition), DVM_TRUE);
        }
    break;

  case 222:

/* Line 1455 of yacc.c  */
#line 974 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_method_member(&(yyvsp[(1) - (2)].class_or_member_modifier), (yyvsp[(2) - (2)].function_definition), DVM_TRUE);
        }
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 980 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define((yyvsp[(7) - (9)].type_specifier), (yyvsp[(2) - (9)].identifier), (yyvsp[(4) - (9)].parameter_list), (yyvsp[(8) - (9)].exception_list), (yyvsp[(9) - (9)].block));
        }
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 984 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define((yyvsp[(6) - (8)].type_specifier), (yyvsp[(2) - (8)].identifier), NULL, (yyvsp[(7) - (8)].exception_list), (yyvsp[(8) - (8)].block));
        }
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 988 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define((yyvsp[(8) - (10)].type_specifier), (yyvsp[(3) - (10)].identifier), (yyvsp[(5) - (10)].parameter_list), (yyvsp[(9) - (10)].exception_list), NULL);
        }
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 992 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define((yyvsp[(7) - (9)].type_specifier), (yyvsp[(3) - (9)].identifier), NULL, (yyvsp[(8) - (9)].exception_list), NULL);
        }
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 996 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define(0, (yyvsp[(2) - (7)].identifier), (yyvsp[(4) - (7)].parameter_list), (yyvsp[(6) - (7)].exception_list), (yyvsp[(7) - (7)].block));
        }
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 1000 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define(0, (yyvsp[(2) - (6)].identifier), NULL, (yyvsp[(5) - (6)].exception_list), (yyvsp[(6) - (6)].block));
        }
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 1004 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define(0, (yyvsp[(3) - (8)].identifier), (yyvsp[(5) - (8)].parameter_list), (yyvsp[(7) - (8)].exception_list), NULL);
        }
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 1008 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define(0, (yyvsp[(3) - (7)].identifier), NULL, (yyvsp[(6) - (7)].exception_list), NULL);
        }
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 1014 "diksam.y"
    {
			(yyval.apost)=0;
		}
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 1018 "diksam.y"
    {
			(yyval.apost)=1;
		}
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 1024 "diksam.y"
    {
            (yyval.exception_list) = NULL;
        }
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 1028 "diksam.y"
    {
            (yyval.exception_list) = (yyvsp[(2) - (2)].exception_list);
        }
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 1034 "diksam.y"
    {
            (yyval.exception_list) = dkc_create_throws((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 1038 "diksam.y"
    {
            (yyval.exception_list) = dkc_chain_exception_list((yyvsp[(1) - (3)].exception_list), (yyvsp[(3) - (3)].identifier));
        }
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 1044 "diksam.y"
    {
            (yyval.function_definition) = dkc_constructor_function_define((yyvsp[(2) - (7)].identifier), (yyvsp[(4) - (7)].parameter_list), (yyvsp[(6) - (7)].exception_list), (yyvsp[(7) - (7)].block));
        }
    break;

  case 238:

/* Line 1455 of yacc.c  */
#line 1048 "diksam.y"
    {
            (yyval.function_definition) = dkc_constructor_function_define((yyvsp[(2) - (6)].identifier), NULL, (yyvsp[(5) - (6)].exception_list), (yyvsp[(6) - (6)].block));
        }
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 1052 "diksam.y"
    {
            (yyval.function_definition) = dkc_constructor_function_define((yyvsp[(3) - (8)].identifier), (yyvsp[(5) - (8)].parameter_list), (yyvsp[(7) - (8)].exception_list), NULL);
        }
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 1056 "diksam.y"
    {
            (yyval.function_definition) = dkc_constructor_function_define((yyvsp[(3) - (7)].identifier), NULL, (yyvsp[(6) - (7)].exception_list), NULL);
        }
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 1062 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(PUBLIC_MODIFIER);
        }
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 1066 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(PRIVATE_MODIFIER);
        }
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 1072 "diksam.y"
    {
            (yyval.expression) = NULL;
        }
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 1076 "diksam.y"
    {
            (yyval.expression) = (yyvsp[(2) - (2)].expression);
        }
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 1082 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(NULL, DVM_FALSE, (yyvsp[(4) - (6)].type_specifier), (yyvsp[(2) - (6)].identifier), (yyvsp[(5) - (6)].expression));
        }
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 1087 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(&(yyvsp[(1) - (6)].class_or_member_modifier), DVM_FALSE, (yyvsp[(4) - (6)].type_specifier), (yyvsp[(2) - (6)].identifier), (yyvsp[(5) - (6)].expression));
        }
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 1091 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(NULL, DVM_TRUE, (yyvsp[(4) - (6)].type_specifier), (yyvsp[(2) - (6)].identifier), (yyvsp[(5) - (6)].expression));
        }
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 1096 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(&(yyvsp[(1) - (7)].class_or_member_modifier), DVM_TRUE, (yyvsp[(5) - (7)].type_specifier), (yyvsp[(3) - (7)].identifier), (yyvsp[(6) - (7)].expression));
        }
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 1100 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(&(yyvsp[(2) - (7)].class_or_member_modifier), DVM_TRUE, (yyvsp[(5) - (7)].type_specifier), (yyvsp[(3) - (7)].identifier), (yyvsp[(6) - (7)].expression));
        }
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 1106 "diksam.y"
    {
            dkc_create_delegate_definition((yyvsp[(8) - (10)].type_specifier), (yyvsp[(2) - (10)].identifier), (yyvsp[(4) - (10)].parameter_list), (yyvsp[(9) - (10)].exception_list),(yyvsp[(5) - (10)].apost));
        }
    break;

  case 251:

/* Line 1455 of yacc.c  */
#line 1110 "diksam.y"
    {
            dkc_create_delegate_definition((yyvsp[(7) - (9)].type_specifier), (yyvsp[(2) - (9)].identifier), NULL, (yyvsp[(8) - (9)].exception_list),(yyvsp[(4) - (9)].apost));
        }
    break;

  case 252:

/* Line 1455 of yacc.c  */
#line 1116 "diksam.y"
    {
            dkc_create_enum_definition((yyvsp[(2) - (5)].identifier), (yyvsp[(4) - (5)].enumerator));
        }
    break;

  case 253:

/* Line 1455 of yacc.c  */
#line 1120 "diksam.y"
    {
            dkc_create_enum_definition((yyvsp[(2) - (6)].identifier), (yyvsp[(4) - (6)].enumerator));
        }
    break;

  case 254:

/* Line 1455 of yacc.c  */
#line 1126 "diksam.y"
    {
            (yyval.enumerator) = dkc_create_enumerator((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 255:

/* Line 1455 of yacc.c  */
#line 1130 "diksam.y"
    {
            (yyval.enumerator) = dkc_chain_enumerator((yyvsp[(1) - (3)].enumerator), (yyvsp[(3) - (3)].identifier));
        }
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 1136 "diksam.y"
    {
            dkc_create_const_definition(NULL, (yyvsp[(2) - (5)].identifier), (yyvsp[(4) - (5)].expression));
        }
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 1140 "diksam.y"
    {
            dkc_create_const_definition((yyvsp[(2) - (4)].type_specifier), (yyvsp[(3) - (4)].identifier), NULL);
        }
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 1146 "diksam.y"
    {
            (yyval.block) = dkc_open_block();
			//printf("E1 %d\n",dkc_get_current_compiler());
        }
    break;

  case 259:

/* Line 1455 of yacc.c  */
#line 1151 "diksam.y"
    {
            (yyval.block) = dkc_close_block((yyvsp[(2) - (4)].block), (yyvsp[(3) - (4)].statement_list));
			//printf("C1 %d\n",dkc_get_current_compiler()->current_line_number);
        }
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 1156 "diksam.y"
    {
            Block *empty_block = dkc_open_block();
            (yyval.block) = dkc_close_block(empty_block, NULL);
			//printf("C2 %d\n",dkc_get_current_compiler()->current_line_number);
        }
    break;



/* Line 1455 of yacc.c  */
#line 4070 "y.tab.c"
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
#line 1162 "diksam.y"


