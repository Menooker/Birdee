
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
#line 371 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 383 "y.tab.c"

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
#define YYLAST   1117

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  112
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  103
/* YYNRULES -- Number of rules.  */
#define YYNRULES  290
/* YYNRULES -- Number of states.  */
#define YYNSTATES  623

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   366

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
     105,   106,   107,   108,   109,   110,   111
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    12,    14,    16,    19,
      21,    24,    28,    30,    34,    36,    39,    44,    46,    48,
      50,    52,    54,    56,    58,    60,    62,    64,    66,    68,
      70,    72,    74,    76,    80,    84,    88,    92,    95,   100,
     102,   104,   106,   108,   110,   114,   115,   122,   123,   126,
     129,   141,   152,   162,   171,   182,   192,   201,   209,   211,
     215,   221,   223,   227,   229,   232,   234,   238,   240,   244,
     246,   248,   250,   252,   254,   256,   258,   260,   262,   266,
     268,   272,   274,   278,   282,   284,   288,   292,   296,   300,
     302,   306,   310,   312,   316,   320,   324,   328,   332,   336,
     338,   341,   344,   347,   349,   352,   355,   359,   361,   363,
     365,   367,   372,   377,   384,   391,   395,   400,   404,   408,
     413,   415,   417,   419,   421,   423,   425,   427,   429,   431,
     433,   435,   440,   445,   451,   458,   466,   470,   475,   480,
     486,   491,   497,   502,   508,   510,   513,   517,   520,   524,
     525,   527,   531,   534,   536,   538,   540,   542,   544,   546,
     548,   550,   552,   554,   556,   558,   560,   565,   572,   578,
     586,   588,   591,   596,   597,   600,   606,   608,   611,   615,
     616,   619,   621,   625,   630,   639,   648,   657,   658,   660,
     664,   665,   667,   671,   675,   681,   686,   690,   692,   695,
     696,   702,   706,   709,   717,   727,   733,   741,   742,   747,
     750,   752,   756,   760,   766,   770,   771,   772,   782,   783,
     794,   795,   804,   805,   815,   817,   820,   822,   824,   826,
     828,   830,   832,   833,   836,   838,   842,   844,   847,   849,
     851,   853,   856,   858,   861,   871,   880,   891,   901,   909,
     916,   925,   933,   934,   937,   938,   941,   943,   947,   955,
     962,   971,   979,   981,   983,   984,   987,   994,  1001,  1008,
    1016,  1024,  1035,  1045,  1051,  1058,  1060,  1064,  1070,  1075,
    1076,  1078,  1079,  1081,  1082,  1084,  1085,  1088,  1091,  1092,
    1098
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     113,     0,    -1,   114,    -1,   113,   120,    -1,    -1,   115,
     118,    -1,   115,    -1,   118,    -1,   114,   128,    -1,   116,
      -1,   115,   116,    -1,    76,   117,   100,    -1,     8,    -1,
     117,    54,     8,    -1,   119,    -1,   118,   119,    -1,    77,
     117,     8,   100,    -1,   132,    -1,   184,    -1,   155,    -1,
     205,    -1,   206,    -1,   208,    -1,    67,    -1,    68,    -1,
      69,    -1,    70,    -1,    71,    -1,    72,    -1,    73,    -1,
      74,    -1,    91,    -1,     8,    -1,   121,    28,    29,    -1,
       8,    28,    29,    -1,   124,    28,    29,    -1,   125,    28,
      29,    -1,   123,   211,    -1,     8,    40,   127,    38,    -1,
     121,    -1,   124,    -1,   122,    -1,   125,    -1,   126,    -1,
     127,    32,   126,    -1,    -1,   104,     8,   129,   100,   130,
      99,    -1,    -1,   130,   131,    -1,   130,   184,    -1,   101,
      95,     8,    24,   133,   198,    25,    96,   126,   199,   100,
      -1,   101,    95,     8,    24,   198,    25,    96,   126,   199,
     100,    -1,   101,   102,     8,    24,   133,   198,    25,   199,
     100,    -1,   101,   102,     8,    24,   198,    25,   199,   100,
      -1,    95,     8,    24,   133,   198,    25,    96,   126,   199,
     213,    -1,    95,     8,    24,   198,    25,    96,   126,   199,
     213,    -1,   102,     8,    24,   133,   198,    25,   199,   213,
      -1,   102,     8,    24,   198,    25,   199,   213,    -1,   131,
      -1,     8,    96,   126,    -1,   133,    32,     8,    96,   126,
      -1,   137,    -1,   134,    32,   137,    -1,   155,    -1,   135,
     155,    -1,   137,    -1,   136,    32,   137,    -1,   139,    -1,
     147,   138,   137,    -1,    33,    -1,    55,    -1,    56,    -1,
     110,    -1,   111,    -1,    57,    -1,    58,    -1,    59,    -1,
     140,    -1,   139,    35,   140,    -1,   141,    -1,   140,    34,
     141,    -1,   142,    -1,   141,    36,   142,    -1,   141,    37,
     142,    -1,   143,    -1,   142,    38,   143,    -1,   142,    39,
     143,    -1,   142,    40,   143,    -1,   142,    41,   143,    -1,
     144,    -1,   143,    42,   144,    -1,   143,    43,   144,    -1,
     145,    -1,   144,    44,   145,    -1,   144,    45,   145,    -1,
     144,    46,   145,    -1,   144,    47,   145,    -1,   144,    48,
     145,    -1,   144,    49,   145,    -1,   146,    -1,    43,   145,
      -1,    53,   145,    -1,    50,   145,    -1,   147,    -1,   147,
      60,    -1,   147,    61,    -1,   147,    88,   126,    -1,   148,
      -1,   150,    -1,     8,    -1,     9,    -1,   148,    28,   136,
      29,    -1,     8,    28,   136,    29,    -1,     8,    28,   136,
      31,   136,    29,    -1,   148,    28,   136,    31,   136,    29,
      -1,   147,    54,     8,    -1,   147,    24,   134,    25,    -1,
     147,    24,    25,    -1,    24,   136,    25,    -1,   147,    89,
     126,    90,    -1,     3,    -1,     4,    -1,     5,    -1,     6,
      -1,     7,    -1,    51,    -1,    52,    -1,    23,    -1,   149,
      -1,    85,    -1,    86,    -1,    75,    91,    24,    25,    -1,
      75,     8,    24,    25,    -1,    75,     8,    24,   134,    25,
      -1,    75,     8,    54,     8,    24,    25,    -1,    75,     8,
      54,     8,    24,   134,    25,    -1,    26,   154,    27,    -1,
      26,   154,    32,    27,    -1,    75,   121,   151,   211,    -1,
      75,   121,   151,   153,   211,    -1,    75,   122,   151,   211,
      -1,    75,   122,   151,   153,   211,    -1,    75,   125,   151,
     211,    -1,    75,   125,   151,   153,   211,    -1,   152,    -1,
     151,   152,    -1,    28,   136,    29,    -1,    28,    29,    -1,
     153,    28,    29,    -1,    -1,   137,    -1,   154,    32,   137,
      -1,   136,   100,    -1,   156,    -1,   160,    -1,   165,    -1,
     166,    -1,   167,    -1,   168,    -1,   170,    -1,   172,    -1,
     173,    -1,   174,    -1,   178,    -1,   179,    -1,   100,    -1,
      10,   136,    97,   213,    -1,    10,   136,    97,   213,    11,
     213,    -1,    10,   136,    97,   213,   157,    -1,    10,   136,
      97,   213,   157,    11,   213,    -1,   158,    -1,   157,   158,
      -1,    12,   136,    97,   213,    -1,    -1,     8,    31,    -1,
      13,   136,   100,   161,   163,    -1,   162,    -1,   161,   162,
      -1,    14,   164,   213,    -1,    -1,    15,   213,    -1,   137,
      -1,   154,    32,   137,    -1,   159,    16,   136,   213,    -1,
     159,    18,   169,    30,   169,    30,   169,   213,    -1,   159,
      17,   180,    16,    24,   136,    25,   100,    -1,   159,    19,
      24,     8,    31,   136,    25,   180,    -1,    -1,   136,    -1,
      20,   169,   100,    -1,    -1,     8,    -1,    21,   171,   100,
      -1,    22,   171,   100,    -1,    62,   213,   175,    64,   213,
      -1,    62,   213,    64,   180,    -1,    62,   213,   175,    -1,
     176,    -1,   175,   176,    -1,    -1,    63,   177,   126,     8,
     213,    -1,    65,   136,   100,    -1,    65,   100,    -1,    98,
     210,     8,    96,   209,   126,   100,    -1,    98,   210,     8,
      96,   209,   126,    33,   136,   100,    -1,    92,     8,    96,
     126,   100,    -1,    92,     8,    96,   126,    33,   136,   100,
      -1,    -1,    26,   181,   135,    27,    -1,    26,    27,    -1,
       8,    -1,   182,    32,     8,    -1,     8,    31,   122,    -1,
     182,    32,     8,    31,   122,    -1,    40,   182,    38,    -1,
      -1,    -1,   209,   191,     8,   183,   192,   100,   185,   194,
      99,    -1,    -1,   209,   189,   191,     8,   183,   192,   100,
     186,   194,    99,    -1,    -1,   209,   191,     8,   183,   192,
     100,   187,    99,    -1,    -1,   209,   189,   191,     8,   183,
     192,   100,   188,    99,    -1,   190,    -1,   189,   190,    -1,
     202,    -1,    82,    -1,    83,    -1,    84,    -1,    78,    -1,
      79,    -1,    -1,    31,   193,    -1,     8,    -1,   193,    32,
       8,    -1,   195,    -1,   194,   195,    -1,   196,    -1,   204,
      -1,   197,    -1,   189,   197,    -1,   201,    -1,   189,   201,
      -1,    95,     8,    24,   133,    25,    96,   126,   199,   213,
      -1,    95,     8,    24,    25,    96,   126,   199,   213,    -1,
     101,    95,     8,    24,   133,    25,    96,   126,   199,   100,
      -1,   101,    95,     8,    24,    25,    96,   126,   199,   100,
      -1,   102,     8,    24,   133,    25,   199,   213,    -1,   102,
       8,    24,    25,   199,   213,    -1,   101,   102,     8,    24,
     133,    25,   199,   100,    -1,   101,   102,     8,    24,    25,
     199,   100,    -1,    -1,    32,   103,    -1,    -1,    66,   200,
      -1,     8,    -1,   200,    32,     8,    -1,    87,     8,    24,
     133,    25,   199,   213,    -1,    87,     8,    24,    25,   199,
     213,    -1,   101,    87,     8,    24,   133,    25,   199,   100,
      -1,   101,    87,     8,    24,    25,   199,   100,    -1,    80,
      -1,    81,    -1,    -1,    33,   136,    -1,    98,     8,    96,
     126,   203,   100,    -1,   189,     8,    96,   126,   203,   100,
      -1,    92,     8,    96,   126,   203,   100,    -1,   189,    92,
       8,    96,   126,   203,   100,    -1,    92,   189,     8,    96,
     126,   203,   100,    -1,    91,     8,    24,   133,   198,    25,
      96,   126,   199,   100,    -1,    91,     8,    24,   198,    25,
      96,   126,   199,   100,    -1,    93,     8,    26,   207,    27,
      -1,    93,     8,    26,   207,    32,    27,    -1,     8,    -1,
     207,    32,     8,    -1,    94,     8,    33,   136,   100,    -1,
      94,   126,     8,   100,    -1,    -1,   107,    -1,    -1,   109,
      -1,    -1,   108,    -1,    -1,   105,   100,    -1,   106,   100,
      -1,    -1,   100,   212,   214,   135,    99,    -1,   100,    99,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   107,   107,   108,   112,   115,   119,   123,   127,   133,
     134,   140,   146,   150,   156,   157,   163,   169,   170,   171,
     178,   179,   180,   183,   187,   191,   195,   199,   203,   207,
     211,   215,   221,   227,   233,   239,   243,   249,   263,   269,
     273,   274,   275,   279,   283,   291,   290,   305,   308,   309,
     312,   316,   320,   324,   331,   335,   339,   343,   347,   350,
     354,   360,   364,   370,   374,   380,   381,   387,   388,   394,
     398,   402,   406,   410,   414,   418,   422,   428,   429,   435,
     436,   442,   443,   447,   453,   454,   458,   462,   466,   472,
     473,   477,   483,   484,   488,   492,   496,   500,   504,   510,
     511,   515,   519,   525,   526,   530,   534,   540,   541,   542,
     546,   552,   556,   561,   566,   570,   574,   578,   582,   586,
     590,   591,   592,   593,   594,   595,   599,   603,   607,   608,
     612,   616,   620,   624,   628,   632,   638,   642,   648,   652,
     656,   660,   665,   669,   675,   676,   682,   688,   692,   700,
     703,   707,   713,   717,   718,   719,   720,   721,   722,   723,
     724,   725,   726,   727,   728,   729,   735,   739,   744,   748,
     754,   755,   761,   768,   771,   777,   783,   784,   790,   797,
     800,   806,   810,   816,   822,   828,   834,   841,   844,   847,
     854,   857,   860,   866,   872,   876,   880,   886,   887,   894,
     893,   903,   907,   913,   917,   921,   925,   932,   931,   939,
     946,   950,   954,   958,   964,   969,   974,   972,   983,   981,
     990,   989,   999,   997,  1008,  1009,  1015,  1016,  1020,  1024,
    1030,  1034,  1041,  1044,  1050,  1054,  1060,  1061,  1067,  1068,
    1071,  1075,  1079,  1083,  1089,  1093,  1097,  1101,  1105,  1109,
    1113,  1117,  1124,  1127,  1134,  1137,  1143,  1147,  1153,  1157,
    1161,  1165,  1171,  1175,  1182,  1185,  1191,  1195,  1200,  1204,
    1209,  1215,  1219,  1225,  1229,  1235,  1239,  1245,  1249,  1256,
    1259,  1266,  1269,  1276,  1279,  1286,  1289,  1293,  1300,  1299,
    1309
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT_LITERAL", "DOUBLE_LITERAL",
  "FLOAT_LITERAL", "STRING_LITERAL", "REGEXP_LITERAL", "IDENTIFIER",
  "AUTOVAR", "IF", "ELSE", "ELSIF", "SWITCH", "CASE", "DEFAULT_T", "WHILE",
  "DO_T", "FOR", "FOREACH", "RETURN_T", "BREAK", "CONTINUE", "NULL_T",
  "LP", "RP", "LC", "RC", "LB", "RB", "SEMICOLON", "COLON", "COMMA",
  "ASSIGN_T", "LOGICAL_AND", "LOGICAL_OR", "EQ", "NE", "GT", "GE", "LT",
  "LE", "ADD", "SUB", "MUL", "DIV", "MOD", "BIT_AND", "BIT_OR", "BIT_XOR",
  "BIT_NOT", "TRUE_T", "FALSE_T", "EXCLAMATION", "DOT", "ADD_ASSIGN_T",
  "SUB_ASSIGN_T", "MUL_ASSIGN_T", "DIV_ASSIGN_T", "MOD_ASSIGN_T",
  "INCREMENT", "DECREMENT", "TRY", "CATCH", "FINALLY", "THROW", "THROWS",
  "VOID_T", "BOOLEAN_T", "INT_T", "DOUBLE_T", "STRING_T", "VARIENT_T",
  "FLOAT_T", "NATIVE_POINTER_T", "NEW", "REQUIRE", "RENAME", "CLASS_T",
  "INTERFACE_T", "PUBLIC_T", "PRIVATE_T", "VIRTUAL_T", "OVERRIDE_T",
  "ABSTRACT_T", "THIS_T", "SUPER_T", "CONSTRUCTOR", "INSTANCEOF",
  "DOWN_CAST_BEGIN", "DOWN_CAST_END", "DELEGATE", "FINAL", "ENUM", "CONST",
  "FUNCTION", "AS", "THEN", "DIM", "END", "CR", "DECLARE", "BSUB",
  "APOSTROPHE", "LIB", "UNSAFE", "SAFE", "SHARED", "GLOBAL", "VOLATILE",
  "ATM_ADD_ASSIGN_T", "ATM_SUB_ASSIGN_T", "$accept", "translation_unit",
  "initial_declaration", "require_list", "require_declaration",
  "package_name", "rename_list", "rename_declaration",
  "definition_or_statement", "basic_type_specifier",
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
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   112,   113,   113,   114,   114,   114,   114,   114,   115,
     115,   116,   117,   117,   118,   118,   119,   120,   120,   120,
     120,   120,   120,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   122,   123,   123,   123,   123,   124,   125,   126,
     126,   126,   126,   127,   127,   129,   128,   130,   130,   130,
     131,   131,   131,   131,   132,   132,   132,   132,   132,   133,
     133,   134,   134,   135,   135,   136,   136,   137,   137,   138,
     138,   138,   138,   138,   138,   138,   138,   139,   139,   140,
     140,   141,   141,   141,   142,   142,   142,   142,   142,   143,
     143,   143,   144,   144,   144,   144,   144,   144,   144,   145,
     145,   145,   145,   146,   146,   146,   146,   147,   147,   147,
     147,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   149,   149,   150,   150,
     150,   150,   150,   150,   151,   151,   152,   153,   153,   154,
     154,   154,   155,   155,   155,   155,   155,   155,   155,   155,
     155,   155,   155,   155,   155,   155,   156,   156,   156,   156,
     157,   157,   158,   159,   159,   160,   161,   161,   162,   163,
     163,   164,   164,   165,   166,   167,   168,   169,   169,   170,
     171,   171,   172,   173,   174,   174,   174,   175,   175,   177,
     176,   178,   178,   179,   179,   179,   179,   181,   180,   180,
     182,   182,   182,   182,   183,   183,   185,   184,   186,   184,
     187,   184,   188,   184,   189,   189,   190,   190,   190,   190,
     191,   191,   192,   192,   193,   193,   194,   194,   195,   195,
     196,   196,   196,   196,   197,   197,   197,   197,   197,   197,
     197,   197,   198,   198,   199,   199,   200,   200,   201,   201,
     201,   201,   202,   202,   203,   203,   204,   204,   204,   204,
     204,   205,   205,   206,   206,   207,   207,   208,   208,   209,
     209,   210,   210,   211,   211,   212,   212,   212,   214,   213,
     213
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     2,     1,
       2,     3,     1,     3,     1,     2,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     3,     3,     2,     4,     1,
       1,     1,     1,     1,     3,     0,     6,     0,     2,     2,
      11,    10,     9,     8,    10,     9,     8,     7,     1,     3,
       5,     1,     3,     1,     2,     1,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     3,     3,     1,
       2,     2,     2,     1,     2,     2,     3,     1,     1,     1,
       1,     4,     4,     6,     6,     3,     4,     3,     3,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     5,     6,     7,     3,     4,     4,     5,
       4,     5,     4,     5,     1,     2,     3,     2,     3,     0,
       1,     3,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     6,     5,     7,
       1,     2,     4,     0,     2,     5,     1,     2,     3,     0,
       2,     1,     3,     4,     8,     8,     8,     0,     1,     3,
       0,     1,     3,     3,     5,     4,     3,     1,     2,     0,
       5,     3,     2,     7,     9,     5,     7,     0,     4,     2,
       1,     3,     3,     5,     3,     0,     0,     9,     0,    10,
       0,     8,     0,     9,     1,     2,     1,     1,     1,     1,
       1,     1,     0,     2,     1,     3,     1,     2,     1,     1,
       1,     2,     1,     2,     9,     8,    10,     9,     7,     6,
       8,     7,     0,     2,     0,     2,     1,     3,     7,     6,
       8,     7,     1,     1,     0,     2,     6,     6,     6,     7,
       7,    10,     9,     5,     6,     1,     3,     5,     4,     0,
       1,     0,     1,     0,     1,     0,     2,     2,     0,     5,
       2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       4,     0,     0,   279,     2,     6,     9,     7,    14,    12,
       0,     0,     1,   120,   121,   122,   123,   124,   109,   110,
       0,     0,   187,   190,   190,   127,     0,   149,     0,     0,
     125,   126,     0,     0,     0,     0,   129,   130,     0,     0,
       0,     0,     0,   281,   165,     0,     0,   280,     3,    58,
      17,     0,    65,    67,    77,    79,    81,    84,    89,    92,
      99,   103,   107,   128,   108,    19,   153,     0,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,    18,
      20,    21,    22,     0,     0,     8,    10,     5,    15,     0,
      11,     0,     0,   174,   109,     0,     0,   188,     0,   191,
       0,     0,     0,   150,     0,   100,   103,   102,   101,   285,
       0,   202,     0,    32,    23,    24,    25,    26,    27,    28,
      29,    30,    31,     0,     0,     0,     0,     0,     0,    32,
      31,    39,    41,   283,    40,    42,     0,     0,   282,     0,
       0,     0,     0,     0,   152,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    69,     0,    70,    71,    74,    75,    76,   104,
     105,     0,     0,    72,    73,     0,     0,     0,     0,   187,
       0,   230,   231,   262,   263,   227,   228,   229,     0,   224,
       0,   226,    45,    13,    16,     0,     0,     0,   189,   192,
     193,   118,   136,     0,   290,     0,     0,   288,   199,     0,
     196,   197,   201,     0,     0,     0,     0,     0,   283,   144,
     283,   283,   252,     0,     0,     0,     0,     0,   284,    37,
       0,     0,     0,   252,     0,     0,     0,   252,    66,    78,
      80,    82,    83,    85,    86,    87,    88,    90,    91,    93,
      94,    95,    96,    97,    98,   117,     0,    61,   115,    32,
     106,     0,    68,     0,     0,   207,     0,     0,     0,   225,
       0,   215,     0,   112,     0,   166,   149,   179,   176,   137,
     151,   286,   287,   173,     0,   195,     0,   198,   132,     0,
      43,     0,     0,   131,     0,     0,   145,   283,   138,   283,
     140,   283,   142,     0,     0,   252,     0,     0,   275,     0,
      34,     0,    33,    35,    36,   278,   252,     0,   279,   252,
     252,   252,     0,   116,     0,   119,   111,     0,   183,   209,
     173,     0,   187,     0,   215,     0,   232,    47,     0,     0,
       0,   168,   170,   150,     0,     0,     0,   177,   175,   173,
      63,     0,   194,   133,     0,    38,     0,   146,   147,     0,
     139,   141,   143,     0,   253,     0,     0,     0,     0,   205,
     273,     0,   277,     0,     0,     0,   252,     0,   252,     0,
       0,   254,    62,     0,   173,     0,     0,     0,   232,   210,
       0,     0,     0,   279,   113,   167,     0,     0,   171,     0,
     178,   180,   289,    64,     0,    44,   134,     0,   148,    59,
       0,     0,     0,     0,   276,   274,     0,     0,     0,     0,
       0,     0,   254,   254,     0,     0,   114,   208,     0,   187,
       0,     0,     0,     0,   214,   234,   233,   216,    46,    48,
      49,     0,   169,   151,   200,   135,     0,     0,   254,   206,
       0,   254,     0,   203,     0,     0,   254,     0,     0,   256,
     255,    57,     0,     0,     0,   218,    32,   212,   211,     0,
       0,     0,   172,    60,   254,     0,   254,     0,     0,     0,
     254,     0,    53,    56,     0,   185,   184,   186,     0,     0,
       0,   235,     0,     0,     0,     0,     0,     0,     0,     0,
     236,   238,   240,   242,   239,   221,     0,   272,     0,    55,
     204,   254,     0,    52,   257,     0,   223,   213,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   241,
     243,   217,   237,   271,    54,     0,    51,   219,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    50,
     254,     0,   264,     0,     0,     0,   264,     0,     0,     0,
     254,     0,   264,     0,     0,   254,     0,     0,     0,   264,
       0,     0,     0,   254,     0,     0,     0,   254,     0,     0,
     254,     0,   264,   259,     0,   265,   268,     0,   254,     0,
     266,     0,   254,     0,     0,     0,   254,   249,     0,   267,
       0,   258,   270,     0,   254,   261,     0,   254,     0,   251,
       0,   248,   269,   245,     0,   260,     0,   254,   250,   244,
     247,     0,   246
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,     6,    10,     7,     8,    48,   131,
     132,   133,   134,   135,   136,   291,    85,   272,   393,    49,
      50,   305,   256,   349,    51,    52,   175,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,   218,
     219,   297,   104,   350,    66,   341,   342,    67,    68,   277,
     278,   348,   345,    69,    70,    71,    72,    98,    73,   100,
      74,    75,    76,   210,   211,   284,    77,    78,   266,   330,
     390,   336,    79,   470,   488,   471,   489,   498,   189,   190,
     392,   436,   499,   500,   501,   502,   306,   425,   460,   503,
     191,   568,   504,    80,    81,   309,    82,    83,   139,   229,
     207,   110,   283
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -502
static const yytype_int16 yypact[] =
{
     170,    36,    36,   475,   -58,   170,  -502,   -29,  -502,  -502,
     -31,    28,  -502,  -502,  -502,  -502,  -502,  -502,    61,  -502,
    1031,  1031,  1031,    54,    54,  -502,  1031,  1031,  1031,  1031,
    -502,  -502,  1031,   -16,   807,   232,  -502,  -502,    85,   105,
     140,   261,   176,    94,  -502,    24,   214,  -502,  -502,  -502,
    -502,   -12,  -502,   178,   171,   280,   239,   254,   458,  -502,
    -502,    19,   196,  -502,  -502,  -502,  -502,   345,  -502,  -502,
    -502,  -502,  -502,  -502,  -502,  -502,  -502,  -502,  -502,  -502,
    -502,  -502,  -502,   369,   251,  -502,  -502,   -29,  -502,   255,
    -502,   198,  1031,  -502,   265,     0,   -10,   282,   222,  -502,
     227,   244,   155,  -502,   156,  -502,   121,  -502,  -502,    48,
     316,  -502,    -6,    16,  -502,  -502,  -502,  -502,  -502,  -502,
    -502,  -502,   312,   319,   319,   319,   342,   272,   348,   193,
    -502,   354,  -502,   277,   375,   382,   407,   400,  -502,   419,
     420,   425,   412,  1031,  -502,  1031,  1031,  1031,  1031,  1031,
    1031,  1031,  1031,  1031,  1031,  1031,  1031,  1031,  1031,  1031,
    1031,   506,  -502,   431,  -502,  -502,  -502,  -502,  -502,  -502,
    -502,   286,   286,  -502,  -502,  1031,  1031,  1031,   416,  1031,
     421,  -502,  -502,  -502,  -502,  -502,  -502,  -502,   369,  -502,
     435,  -502,  -502,  -502,  -502,   120,   -16,   440,  -502,  -502,
    -502,  -502,  -502,   882,  -502,   355,   356,  -502,  -502,   416,
     334,  -502,  -502,   894,   286,   449,   451,  1031,    -4,  -502,
      -4,    -4,    21,   286,   469,   457,  1031,   460,  -502,  -502,
     461,   471,   387,    21,   423,   484,   492,    21,  -502,   171,
     280,   239,   239,   254,   254,   254,   254,   458,   458,  -502,
    -502,  -502,  -502,  -502,  -502,  -502,   182,  -502,  -502,   133,
    -502,   427,  -502,   256,    -5,   493,   505,   494,   514,  -502,
     515,   495,   433,  -502,  1031,   313,  1031,   335,  -502,  -502,
    -502,  -502,  -502,   776,   286,  -502,   -16,  -502,  -502,   200,
    -502,   226,   510,  -502,   242,   947,  -502,    -3,  -502,    -3,
    -502,    -3,  -502,   442,   436,   504,   516,   -15,  -502,   240,
    -502,    31,  -502,  -502,  -502,  -502,   504,   517,   437,    21,
      21,   504,   518,  -502,  1031,  -502,  -502,  1031,  -502,  -502,
     776,   521,  1031,   520,   495,   538,   522,  -502,   252,   -16,
    1031,   390,  -502,   448,   523,   -16,   -16,  -502,  -502,   580,
    -502,   544,  -502,  -502,   286,  -502,   978,  -502,  -502,   525,
    -502,  -502,  -502,   286,  -502,    13,   537,   467,  1031,  -502,
    -502,    37,  -502,   539,   476,   286,   504,   540,   504,   546,
     549,   512,  -502,   260,   678,  1031,   550,  1031,   522,   548,
     238,   586,   496,    97,  -502,  -502,     9,   -16,  -502,  1031,
    -502,  -502,  -502,  -502,   -16,  -502,  -502,   203,  -502,  -502,
     499,   501,   286,    34,  -502,  -502,   502,   286,    27,   574,
     509,   587,   512,   512,   605,   -16,  -502,  -502,   205,  1031,
     209,   524,   607,   608,  -502,  -502,   585,   519,  -502,  -502,
    -502,   -16,  -502,   534,  -502,  -502,   286,   286,   512,  -502,
     286,   512,  1031,  -502,   531,   286,   512,   535,   -16,  -502,
     588,  -502,   536,   -16,   416,   541,  -502,  -502,   590,   629,
     289,   542,  -502,  -502,   512,   543,   512,   -16,    35,   286,
     512,   547,  -502,  -502,   630,  -502,  -502,  -502,   289,   545,
     607,  -502,   631,    57,   638,   640,    99,   641,    41,   339,
    -502,  -502,  -502,  -502,  -502,  -502,   551,  -502,   -16,  -502,
    -502,   512,   552,  -502,  -502,   527,  -502,  -502,   626,   557,
     136,   632,   558,   649,   650,   651,   636,   565,   654,  -502,
    -502,  -502,  -502,  -502,  -502,   563,  -502,  -502,    22,   286,
     568,    46,   286,   643,   644,   645,   154,   286,   575,  -502,
     512,   213,   637,   286,   577,   218,   637,   164,   166,   168,
     512,   219,   637,   286,   -16,   512,   666,  1031,   576,   637,
     286,   579,   589,   512,   224,   581,   230,   512,   236,   -16,
     512,   592,   637,  -502,   -16,   282,  -502,   593,   512,   286,
    -502,   594,   512,   286,   599,   596,   512,  -502,   -16,  -502,
     597,  -502,  -502,   -16,   512,  -502,   603,   512,   286,  -502,
     606,  -502,  -502,  -502,   -16,  -502,   609,   512,  -502,  -502,
    -502,   610,  -502
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -502,  -502,  -502,  -502,   685,   705,   703,    30,  -502,   676,
     -32,  -502,  -502,   677,  -164,  -502,  -502,  -502,  -502,   320,
    -502,  -220,  -201,   384,   -20,   -11,  -502,  -502,   570,   571,
     257,   243,   259,    10,  -502,   314,  -502,  -502,  -502,   283,
      90,   197,   443,     2,  -502,  -502,   377,  -502,  -502,  -502,
     439,  -502,  -502,  -502,  -502,  -502,  -502,  -169,  -502,   696,
    -502,  -502,  -502,  -502,   513,  -502,  -502,  -502,  -198,  -502,
    -502,   388,   331,  -502,  -502,  -502,  -502,   -79,  -179,   553,
     337,  -502,   245,  -464,  -502,   228,  -218,  -365,  -502,   229,
    -502,  -501,  -502,  -502,  -502,  -502,  -502,   414,  -502,  -187,
    -502,  -168,  -502
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -223
static const yytype_int16 yytable[] =
{
      95,    96,    97,   124,   188,    65,   102,   260,   261,   269,
     267,   285,   289,   316,   112,   317,   103,   321,   368,   322,
     143,   410,   143,    89,   295,   359,   143,   143,   275,   303,
     303,   298,   143,   300,   302,   532,    91,    88,   105,   107,
     213,   143,   108,   161,     9,   414,    84,   550,     2,   527,
     290,   532,   162,   304,   303,   572,   214,   457,   458,   307,
     452,   581,    99,   143,   415,   519,   143,   143,   587,    90,
     215,   554,   195,   163,   164,   165,   166,   167,   168,   169,
     170,   600,    89,   475,   109,   369,   477,   366,   144,    92,
     197,   481,    93,   126,   212,   109,   328,   196,   373,   376,
     378,   377,   379,   380,   228,   228,   441,   171,   172,   506,
     360,   508,   361,   127,   362,   512,   364,    88,   352,   140,
     351,   183,   184,   185,   186,   187,   141,   453,   492,   173,
     174,   372,   238,   528,   449,   510,   494,   183,   184,   185,
     186,   187,   496,   497,   540,   161,   535,   204,   128,   273,
     257,   274,   143,   205,   206,   407,   263,   264,   419,    97,
     421,   225,   303,   386,   262,   249,   250,   251,   252,   253,
     254,   395,   303,   214,   303,   163,   303,   400,   401,   560,
     201,   169,   170,   202,   137,   564,   523,   143,   203,   573,
     405,   575,   280,   577,   524,   579,   438,   294,    45,   409,
     584,   525,   257,   138,    47,   146,   311,   323,   591,   171,
     172,   418,   595,   145,   324,   598,   183,   184,   185,   186,
     187,   225,   142,   603,   176,   353,   226,   606,   445,   442,
     462,   610,   324,   214,   464,   324,   444,   143,   565,   614,
     113,   143,   616,   571,   580,   566,     1,     2,   448,   592,
     566,   566,   621,   451,   338,   594,   566,   461,   354,   192,
     463,   596,   566,   193,   355,   343,   487,   370,   566,   129,
     433,   357,   371,   472,   143,   294,   434,   149,   150,   151,
     152,   394,   473,   474,   143,   326,   476,   327,   143,   426,
     483,   480,   143,    92,   259,   486,   153,   154,   194,   114,
     115,   116,   117,   118,   119,   120,   121,   383,   296,   509,
     296,   296,    97,   382,   143,   511,   147,   148,   551,   269,
     396,   555,   198,   122,   339,   340,   561,   199,   114,   115,
     116,   117,   118,   119,   120,   121,   216,   574,   576,   578,
     534,   269,   106,   106,   200,   257,   106,   217,   413,   276,
     346,   403,   130,   114,   115,   116,   117,   118,   119,   120,
     121,   177,   178,   179,   180,   428,   222,   430,   223,   183,
     184,   185,   186,   187,   224,   552,   492,   130,   556,   208,
     209,   493,   227,   562,   494,   228,   403,   495,   443,   569,
     496,   497,   243,   244,   245,   246,   583,   208,   286,   582,
     467,   397,   340,   230,   241,   242,   588,   220,   221,    97,
     231,   597,   247,   248,   520,   232,   601,   299,   301,   183,
     184,   185,   186,   187,   233,   604,   492,   234,   235,   607,
     611,   493,   478,   236,   494,   613,   237,   495,   531,   258,
     496,   497,   265,   271,   617,   268,   619,   181,   182,   183,
     184,   185,   186,   187,   276,   281,   282,   292,   517,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,    12,   293,   308,    13,    14,
      15,    16,    17,    18,    19,    20,   310,   315,    21,   312,
     313,  -173,  -173,  -173,  -173,    22,    23,    24,    25,    26,
     314,    27,   155,   156,   157,   158,   159,   160,   319,    13,
      14,    15,    16,    17,    94,    19,   320,   325,    28,   318,
     329,   331,   333,   334,   332,    29,    30,    31,    32,    25,
      26,   255,    27,   337,   356,   335,   365,    33,   363,   364,
      34,   367,   374,   381,    47,   385,   389,   585,  -181,    28,
      35,   387,   404,   391,   408,   399,    29,    30,    31,    32,
      36,    37,   411,   412,   416,   420,    38,    39,    40,    41,
      42,   422,   417,    43,   423,    44,    45,    46,   424,   432,
     429,    35,    47,    13,    14,    15,    16,    17,    18,    19,
      20,    36,    37,    21,   435,   446,   437,   447,   450,   454,
      22,    23,    24,    25,    26,   455,    27,   183,   184,   185,
     186,   187,   456,   459,   492,   466,   468,   469,  -220,   493,
     484,   490,   494,    28,   465,   495,   537,   479,   496,   497,
      29,    30,    31,    32,  -182,   482,   485,   491,   514,   518,
    -222,   505,    33,   507,   516,    34,   521,   513,   522,   526,
     538,   533,   536,   539,   542,    35,   541,   543,   544,   545,
     546,   547,   548,   549,   553,    36,    37,   557,   558,   559,
     567,   563,    39,   570,   410,   589,   586,   593,    43,   402,
      44,    13,    14,    15,    16,    17,    18,    19,    20,   590,
      86,    21,   599,   602,   605,   608,   609,   612,    22,    23,
      24,    25,    26,   615,    27,   427,   618,    11,    87,   620,
     622,   123,   125,   439,   384,   239,   347,   240,   398,   344,
     101,    28,   388,   287,   440,   431,   529,   530,    29,    30,
      31,    32,   375,   515,     0,     0,     0,     0,     0,     0,
      33,   270,     0,    34,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    35,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    36,    37,     0,     0,     0,     0,     0,
      39,     0,     0,     0,     0,     0,    43,     0,    44,    13,
      14,    15,    16,    17,    18,    19,    20,     0,     0,    21,
       0,     0,     0,     0,     0,     0,    22,    23,    24,    25,
      26,     0,    27,     0,     0,     0,     0,     0,     0,     0,
      13,    14,    15,    16,    17,    94,    19,     0,     0,    28,
       0,     0,     0,     0,     0,     0,    29,    30,    31,    32,
      25,    26,     0,    27,     0,     0,     0,     0,    33,     0,
       0,    34,     0,     0,     0,     0,     0,     0,     0,     0,
      28,    35,     0,     0,     0,     0,     0,    29,    30,    31,
      32,    36,    37,     0,     0,     0,     0,     0,    39,     0,
       0,     0,     0,     0,    43,     0,    44,     0,     0,     0,
       0,     0,    35,     0,     0,    13,    14,    15,    16,    17,
      94,    19,    36,    37,     0,     0,     0,    13,    14,    15,
      16,    17,    94,    19,     0,    25,    26,   111,    27,   279,
       0,     0,     0,     0,     0,     0,     0,    25,    26,   288,
      27,     0,     0,     0,     0,    28,     0,     0,     0,     0,
       0,     0,    29,    30,    31,    32,     0,    28,     0,     0,
       0,     0,     0,     0,    29,    30,    31,    32,     0,     0,
      13,    14,    15,    16,    17,    94,    19,    35,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    36,    37,    35,
      25,    26,     0,    27,     0,     0,   358,     0,     0,    36,
      37,    13,    14,    15,    16,    17,    94,    19,     0,     0,
      28,     0,     0,     0,     0,     0,     0,    29,    30,    31,
      32,    25,    26,   406,    27,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    28,    35,     0,     0,     0,     0,     0,    29,    30,
      31,    32,    36,    37,    13,    14,    15,    16,    17,    94,
      19,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    35,    25,    26,     0,    27,     0,     0,
       0,     0,     0,    36,    37,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    28,     0,     0,     0,     0,     0,
       0,    29,    30,    31,    32,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    35,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    36,    37
};

static const yytype_int16 yycheck[] =
{
      20,    21,    22,    35,    83,     3,    26,   171,   172,   188,
     179,   209,   213,   233,    34,   233,    27,   237,    33,   237,
      32,     8,    32,    54,    28,    28,    32,    32,   196,     8,
       8,   218,    32,   220,   221,   499,     8,     7,    28,    29,
      24,    32,    32,    24,     8,     8,   104,    25,    77,     8,
     214,   515,    33,    32,     8,   556,    40,   422,   423,   223,
      33,   562,     8,    32,    27,     8,    32,    32,   569,   100,
      54,    25,    92,    54,    55,    56,    57,    58,    59,    60,
      61,   582,    54,   448,   100,   100,   451,   305,   100,    28,
     100,   456,    31,     8,   100,   100,   264,    97,   316,   319,
     320,   319,   320,   321,   108,   108,    97,    88,    89,   474,
     297,   476,   299,     8,   301,   480,   103,    87,   286,    95,
     284,    80,    81,    82,    83,    84,   102,   100,    87,   110,
     111,   100,   143,    92,   100,   100,    95,    80,    81,    82,
      83,    84,   101,   102,     8,    24,   511,    99,     8,    29,
     161,    31,    32,   105,   106,   356,   176,   177,   376,   179,
     378,    28,     8,   332,   175,   155,   156,   157,   158,   159,
     160,   339,     8,    40,     8,    54,     8,   345,   346,    25,
      25,    60,    61,    27,     8,   550,    87,    32,    32,    25,
     354,    25,   203,    25,    95,   560,    99,   217,   101,   363,
     565,   102,   213,   109,   107,    34,   226,    25,   573,    88,
      89,   375,   577,    35,    32,   580,    80,    81,    82,    83,
      84,    28,     8,   588,    28,    25,    33,   592,    25,   397,
      25,   596,    32,    40,    25,    32,   404,    32,    25,   604,
       8,    32,   607,    25,    25,    32,    76,    77,   412,    25,
      32,    32,   617,   417,   274,    25,    32,   425,    32,     8,
     429,    25,    32,     8,    38,   276,   464,    27,    32,     8,
      32,    29,    32,   441,    32,   295,    38,    38,    39,    40,
      41,    29,   446,   447,    32,    29,   450,    31,    32,    29,
     458,   455,    32,    28,     8,   463,    42,    43,   100,    67,
      68,    69,    70,    71,    72,    73,    74,   327,   218,   477,
     220,   221,   332,   324,    32,   479,    36,    37,   538,   498,
     340,   541,   100,    91,    11,    12,   546,   100,    67,    68,
      69,    70,    71,    72,    73,    74,    24,   557,   558,   559,
     508,   520,    28,    29,   100,   356,    32,    28,   368,    14,
      15,   349,    91,    67,    68,    69,    70,    71,    72,    73,
      74,    16,    17,    18,    19,   385,    24,   387,    96,    80,
      81,    82,    83,    84,    26,   539,    87,    91,   542,    63,
      64,    92,    28,   547,    95,   108,   384,    98,   399,   553,
     101,   102,   149,   150,   151,   152,   564,    63,    64,   563,
     432,    11,    12,    28,   147,   148,   570,   124,   125,   429,
      28,   579,   153,   154,   493,     8,   584,   220,   221,    80,
      81,    82,    83,    84,    24,   589,    87,     8,     8,   593,
     598,    92,   452,     8,    95,   603,    24,    98,    99,     8,
     101,   102,    26,     8,   608,    24,   614,    78,    79,    80,
      81,    82,    83,    84,    14,   100,   100,     8,   490,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,     0,    25,     8,     3,     4,
       5,     6,     7,     8,     9,    10,    29,   100,    13,    29,
      29,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      29,    26,    44,    45,    46,    47,    48,    49,    24,     3,
       4,     5,     6,     7,     8,     9,    24,    90,    43,    96,
      27,    16,     8,     8,    30,    50,    51,    52,    53,    23,
      24,    25,    26,   100,    24,    40,    32,    62,    96,   103,
      65,    25,    25,    25,   107,    24,     8,   567,   100,    43,
      75,    31,     8,    31,    29,    32,    50,    51,    52,    53,
      85,    86,    25,    96,    25,    25,    91,    92,    93,    94,
      95,    25,    96,    98,    25,   100,   101,   102,    66,    31,
      30,    75,   107,     3,     4,     5,     6,     7,     8,     9,
      10,    85,    86,    13,     8,    96,   100,    96,    96,    25,
      20,    21,    22,    23,    24,    96,    26,    80,    81,    82,
      83,    84,    25,     8,    87,     8,     8,    32,    99,    92,
      32,    31,    95,    43,   100,    98,    99,    96,   101,   102,
      50,    51,    52,    53,   100,   100,   100,     8,     8,     8,
      99,    99,    62,   100,    99,    65,     8,   100,     8,     8,
      24,   100,   100,    96,    96,    75,    24,     8,     8,     8,
      24,    96,     8,   100,    96,    85,    86,    24,    24,    24,
      33,    96,    92,    96,     8,    96,   100,    96,    98,    99,
     100,     3,     4,     5,     6,     7,     8,     9,    10,   100,
       5,    13,   100,   100,   100,    96,   100,   100,    20,    21,
      22,    23,    24,   100,    26,    27,   100,     2,     5,   100,
     100,    35,    35,   393,   330,   145,   277,   146,   341,   276,
      24,    43,   334,   210,   393,   388,   498,   498,    50,    51,
      52,    53,   318,   488,    -1,    -1,    -1,    -1,    -1,    -1,
      62,   188,    -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    85,    86,    -1,    -1,    -1,    -1,    -1,
      92,    -1,    -1,    -1,    -1,    -1,    98,    -1,   100,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    -1,    -1,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,    53,
      23,    24,    -1,    26,    -1,    -1,    -1,    -1,    62,    -1,
      -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    75,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,
      53,    85,    86,    -1,    -1,    -1,    -1,    -1,    92,    -1,
      -1,    -1,    -1,    -1,    98,    -1,   100,    -1,    -1,    -1,
      -1,    -1,    75,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    85,    86,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,     9,    -1,    23,    24,   100,    26,    27,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,    25,
      26,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    51,    52,    53,    -1,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    51,    52,    53,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    75,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    75,
      23,    24,    -1,    26,    -1,    -1,    29,    -1,    -1,    85,
      86,     3,     4,     5,     6,     7,     8,     9,    -1,    -1,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,
      53,    23,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    75,    -1,    -1,    -1,    -1,    -1,    50,    51,
      52,    53,    85,    86,     3,     4,     5,     6,     7,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    23,    24,    -1,    26,    -1,    -1,
      -1,    -1,    -1,    85,    86,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    51,    52,    53,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    86
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    76,    77,   113,   114,   115,   116,   118,   119,     8,
     117,   117,     0,     3,     4,     5,     6,     7,     8,     9,
      10,    13,    20,    21,    22,    23,    24,    26,    43,    50,
      51,    52,    53,    62,    65,    75,    85,    86,    91,    92,
      93,    94,    95,    98,   100,   101,   102,   107,   120,   131,
     132,   136,   137,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   155,   156,   159,   160,   165,
     166,   167,   168,   170,   172,   173,   174,   178,   179,   184,
     205,   206,   208,   209,   104,   128,   116,   118,   119,    54,
     100,     8,    28,    31,     8,   136,   136,   136,   169,     8,
     171,   171,   136,   137,   154,   145,   147,   145,   145,   100,
     213,   100,   136,     8,    67,    68,    69,    70,    71,    72,
      73,    74,    91,   121,   122,   125,     8,     8,     8,     8,
      91,   121,   122,   123,   124,   125,   126,     8,   109,   210,
      95,   102,     8,    32,   100,    35,    34,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    24,    33,    54,    55,    56,    57,    58,    59,    60,
      61,    88,    89,   110,   111,   138,    28,    16,    17,    18,
      19,    78,    79,    80,    81,    82,    83,    84,   189,   190,
     191,   202,     8,     8,   100,   136,    97,   100,   100,   100,
     100,    25,    27,    32,    99,   105,   106,   212,    63,    64,
     175,   176,   100,    24,    40,    54,    24,    28,   151,   152,
     151,   151,    24,    96,    26,    28,    33,    28,   108,   211,
      28,    28,     8,    24,     8,     8,     8,    24,   137,   140,
     141,   142,   142,   143,   143,   143,   143,   144,   144,   145,
     145,   145,   145,   145,   145,    25,   134,   137,     8,     8,
     126,   126,   137,   136,   136,    26,   180,   169,    24,   190,
     191,     8,   129,    29,    31,   213,    14,   161,   162,    27,
     137,   100,   100,   214,   177,   180,    64,   176,    25,   134,
     126,   127,     8,    25,   136,    28,   152,   153,   211,   153,
     211,   153,   211,     8,    32,   133,   198,   126,     8,   207,
      29,   136,    29,    29,    29,   100,   133,   198,    96,    24,
      24,   133,   198,    25,    32,    90,    29,    31,   213,    27,
     181,    16,    30,     8,     8,    40,   183,   100,   136,    11,
      12,   157,   158,   137,   154,   164,    15,   162,   163,   135,
     155,   126,   213,    25,    32,    38,    24,    29,    29,    28,
     211,   211,   211,    96,   103,    32,   198,    25,    33,   100,
      27,    32,   100,   198,    25,   209,   133,   198,   133,   198,
     198,    25,   137,   136,   135,    24,   169,    31,   183,     8,
     182,    31,   192,   130,    29,   213,   136,    11,   158,    32,
     213,   213,    99,   155,     8,   126,    25,   134,    29,   126,
       8,    25,    96,   136,     8,    27,    25,    96,   126,   198,
      25,   198,    25,    25,    66,   199,    29,    27,   136,    30,
     136,   192,    31,    32,    38,     8,   193,   100,    99,   131,
     184,    97,   213,   137,   213,    25,    96,    96,   126,   100,
      96,   126,    33,   100,    25,    96,    25,   199,   199,     8,
     200,   213,    25,   169,    25,   100,     8,   122,     8,    32,
     185,   187,   213,   126,   126,   199,   126,   199,   136,    96,
     126,   199,   100,   213,    32,   100,   213,   180,   186,   188,
      31,     8,    87,    92,    95,    98,   101,   102,   189,   194,
     195,   196,   197,   201,   204,    99,   199,   100,   199,   213,
     100,   126,   199,   100,     8,   194,    99,   122,     8,     8,
     189,     8,     8,    87,    95,   102,     8,     8,    92,   197,
     201,    99,   195,   100,   213,   199,   100,    99,    24,    96,
       8,    24,    96,     8,     8,     8,    24,    96,     8,   100,
      25,   133,   126,    96,    25,   133,   126,    24,    24,    24,
      25,   133,   126,    96,   199,    25,    32,    33,   203,   126,
      96,    25,   203,    25,   133,    25,   133,    25,   133,   199,
      25,   203,   126,   213,   199,   136,   100,   203,   126,    96,
     100,   199,    25,    96,    25,   199,    25,   213,   199,   100,
     203,   213,   100,   199,   126,   100,   199,   126,    96,   100,
     199,   213,   100,   213,   199,   100,   199,   126,   100,   213,
     100,   199,   100
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
#line 112 "diksam.y"
    {
            dkc_set_require_and_rename_list(NULL, NULL);
        }
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 116 "diksam.y"
    {
            dkc_set_require_and_rename_list((yyvsp[(1) - (2)].require_list), (yyvsp[(2) - (2)].rename_list));
        }
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 120 "diksam.y"
    {
            dkc_set_require_and_rename_list((yyvsp[(1) - (1)].require_list), NULL);
        }
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 124 "diksam.y"
    {
            dkc_set_require_and_rename_list(NULL, (yyvsp[(1) - (1)].rename_list));
        }
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 128 "diksam.y"
    {
            //dkc_set_require_and_rename_list(NULL, NULL);
		}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 135 "diksam.y"
    {
            (yyval.require_list) = dkc_chain_require_list((yyvsp[(1) - (2)].require_list), (yyvsp[(2) - (2)].require_list));
        }
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 141 "diksam.y"
    {
            (yyval.require_list) = dkc_create_require_list((yyvsp[(2) - (3)].package_name));
        }
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 147 "diksam.y"
    {
            (yyval.package_name) = dkc_create_package_name((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 151 "diksam.y"
    {
            (yyval.package_name) = dkc_chain_package_name((yyvsp[(1) - (3)].package_name), (yyvsp[(3) - (3)].identifier));
        }
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 158 "diksam.y"
    {
            (yyval.rename_list) = dkc_chain_rename_list((yyvsp[(1) - (2)].rename_list), (yyvsp[(2) - (2)].rename_list));
        }
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 164 "diksam.y"
    {
            (yyval.rename_list) = dkc_create_rename_list((yyvsp[(2) - (4)].package_name), (yyvsp[(3) - (4)].identifier));
        }
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 172 "diksam.y"
    {
            DKC_Compiler *compiler = dkc_get_current_compiler();

            compiler->statement_list
                = dkc_chain_statement_list(compiler->statement_list, (yyvsp[(1) - (1)].statement));
        }
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 184 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_VOID_TYPE;
        }
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 188 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_BOOLEAN_TYPE;
        }
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 192 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_INT_TYPE;
        }
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 196 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_DOUBLE_TYPE;
        }
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 200 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_STRING_TYPE;
        }
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 204 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_VARIENT_TYPE;
        }
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 208 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_FLOAT_TYPE;
        }
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 212 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_NATIVE_POINTER_TYPE;
        }
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 216 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_DELEGATE_TYPE;
        }
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 222 "diksam.y"
    {
            (yyval.type_specifier) = dkc_create_identifier_type_specifier((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 228 "diksam.y"
    {
            TypeSpecifier *basic_type
                = dkc_create_type_specifier((yyvsp[(1) - (3)].basic_type_specifier));
            (yyval.type_specifier) = dkc_create_array_type_specifier(basic_type,0);
        }
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 234 "diksam.y"
    {
            TypeSpecifier *identifier_type
                = dkc_create_identifier_type_specifier((yyvsp[(1) - (3)].identifier));
            (yyval.type_specifier) = dkc_create_array_type_specifier(identifier_type,0);
        }
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 240 "diksam.y"
    {
            (yyval.type_specifier) = dkc_create_array_type_specifier((yyvsp[(1) - (3)].type_specifier),0);
        }
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 244 "diksam.y"
    {
			(yyval.type_specifier) = dkc_create_array_type_specifier((yyvsp[(1) - (3)].type_specifier),0);
		}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 250 "diksam.y"
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

  case 38:

/* Line 1455 of yacc.c  */
#line 264 "diksam.y"
    {//fix-me : shift/reduce
			(yyval.type_specifier)= dkc_create_template_type_specifier((yyvsp[(1) - (4)].identifier),(yyvsp[(3) - (4)].template));
		}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 270 "diksam.y"
    {
                    (yyval.type_specifier) = dkc_create_type_specifier((yyvsp[(1) - (1)].basic_type_specifier));
        }
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 280 "diksam.y"
    {
			(yyval.template)=dkc_create_template_list((yyvsp[(1) - (1)].type_specifier));
		}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 284 "diksam.y"
    {
            (yyval.template) = dkc_chain_template_list((yyvsp[(1) - (3)].template), (yyvsp[(3) - (3)].type_specifier));
        }
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 291 "diksam.y"
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

  case 46:

/* Line 1455 of yacc.c  */
#line 301 "diksam.y"
    {
			BcGetCurrentCompilerContext()->isLib=0;
		}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 313 "diksam.y"
    {
            dkc_function_define((yyvsp[(9) - (11)].type_specifier), (yyvsp[(3) - (11)].identifier), (yyvsp[(5) - (11)].parameter_list), (yyvsp[(10) - (11)].exception_list), NULL,(yyvsp[(6) - (11)].intval));
        }
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 317 "diksam.y"
    {
            dkc_function_define((yyvsp[(8) - (10)].type_specifier), (yyvsp[(3) - (10)].identifier), NULL, (yyvsp[(9) - (10)].exception_list), NULL,(yyvsp[(5) - (10)].intval));
        }
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 321 "diksam.y"
    {
            dkc_function_define(0, (yyvsp[(3) - (9)].identifier), (yyvsp[(5) - (9)].parameter_list), (yyvsp[(8) - (9)].exception_list), NULL,(yyvsp[(6) - (9)].intval));
        }
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 325 "diksam.y"
    {
			//printf("lib:%s\n",BcGetCurrentCompilerContext()->libname);
            dkc_function_define(0, (yyvsp[(3) - (8)].identifier), NULL, (yyvsp[(7) - (8)].exception_list), NULL,(yyvsp[(5) - (8)].intval));
        }
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 332 "diksam.y"
    {
            dkc_function_define((yyvsp[(8) - (10)].type_specifier), (yyvsp[(2) - (10)].identifier), (yyvsp[(4) - (10)].parameter_list), (yyvsp[(9) - (10)].exception_list), (yyvsp[(10) - (10)].block),(yyvsp[(5) - (10)].intval));
        }
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 336 "diksam.y"
    {
            dkc_function_define((yyvsp[(7) - (9)].type_specifier), (yyvsp[(2) - (9)].identifier), NULL, (yyvsp[(8) - (9)].exception_list), (yyvsp[(9) - (9)].block),(yyvsp[(4) - (9)].intval));
        }
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 340 "diksam.y"
    { //modified
            dkc_function_define(0, (yyvsp[(2) - (8)].identifier), (yyvsp[(4) - (8)].parameter_list), (yyvsp[(7) - (8)].exception_list), (yyvsp[(8) - (8)].block),(yyvsp[(5) - (8)].intval));
        }
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 344 "diksam.y"
    {
            dkc_function_define(0, (yyvsp[(2) - (7)].identifier), NULL, (yyvsp[(6) - (7)].exception_list), (yyvsp[(7) - (7)].block),(yyvsp[(4) - (7)].intval));
        }
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 351 "diksam.y"
    {
            (yyval.parameter_list) = dkc_create_parameter((yyvsp[(3) - (3)].type_specifier), (yyvsp[(1) - (3)].identifier));
        }
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 355 "diksam.y"
    {
            (yyval.parameter_list) = dkc_chain_parameter((yyvsp[(1) - (5)].parameter_list), (yyvsp[(5) - (5)].type_specifier), (yyvsp[(3) - (5)].identifier));
        }
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 361 "diksam.y"
    {
            (yyval.argument_list) = dkc_create_argument_list((yyvsp[(1) - (1)].expression));
        }
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 365 "diksam.y"
    {
            (yyval.argument_list) = dkc_chain_argument_list((yyvsp[(1) - (3)].argument_list), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 371 "diksam.y"
    {
            (yyval.statement_list) = dkc_create_statement_list((yyvsp[(1) - (1)].statement));
        }
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 375 "diksam.y"
    {
            (yyval.statement_list) = dkc_chain_statement_list((yyvsp[(1) - (2)].statement_list), (yyvsp[(2) - (2)].statement));
        }
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 382 "diksam.y"
    {
            (yyval.expression) = dkc_create_comma_expression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 389 "diksam.y"
    {
            (yyval.expression) = dkc_create_assign_expression((yyvsp[(1) - (3)].expression), (yyvsp[(2) - (3)].assignment_operator), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 395 "diksam.y"
    {
            (yyval.assignment_operator) = NORMAL_ASSIGN;
        }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 399 "diksam.y"
    {
            (yyval.assignment_operator) = ADD_ASSIGN;
        }
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 403 "diksam.y"
    {
            (yyval.assignment_operator) = SUB_ASSIGN;
        }
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 407 "diksam.y"
    {
            (yyval.assignment_operator) = ATM_ADD_ASSIGN;
        }
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 411 "diksam.y"
    {
            (yyval.assignment_operator) = ATM_SUB_ASSIGN;
        }
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 415 "diksam.y"
    {
            (yyval.assignment_operator) = MUL_ASSIGN;
        }
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 419 "diksam.y"
    {
            (yyval.assignment_operator) = DIV_ASSIGN;
        }
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 423 "diksam.y"
    {
            (yyval.assignment_operator) = MOD_ASSIGN;
        }
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 430 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(LOGICAL_OR_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 437 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(LOGICAL_AND_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 444 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(EQ_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 448 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(NE_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 455 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(GT_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 459 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(GE_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 463 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(LT_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 467 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(LE_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 474 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(ADD_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 478 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(SUB_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 485 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(MUL_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 489 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(DIV_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 493 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(MOD_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 497 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(BIT_AND_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 501 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(BIT_OR_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 505 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(BIT_XOR_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 512 "diksam.y"
    {
            (yyval.expression) = dkc_create_minus_expression((yyvsp[(2) - (2)].expression));
        }
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 516 "diksam.y"
    {
            (yyval.expression) = dkc_create_logical_not_expression((yyvsp[(2) - (2)].expression));
        }
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 520 "diksam.y"
    {
            (yyval.expression) = dkc_create_bit_not_expression((yyvsp[(2) - (2)].expression));
        }
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 527 "diksam.y"
    {
            (yyval.expression) = dkc_create_incdec_expression((yyvsp[(1) - (2)].expression), INCREMENT_EXPRESSION);
        }
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 531 "diksam.y"
    {
            (yyval.expression) = dkc_create_incdec_expression((yyvsp[(1) - (2)].expression), DECREMENT_EXPRESSION);
        }
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 535 "diksam.y"
    {
            (yyval.expression) = dkc_create_instanceof_expression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].type_specifier));
        }
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 543 "diksam.y"
    {
            (yyval.expression) = dkc_create_identifier_expression((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 547 "diksam.y"
    {
			(yyval.expression)=BcCreateAutoExpression((yyvsp[(1) - (1)].identifier));
		}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 553 "diksam.y"
    {
            (yyval.expression) = dkc_create_index_expression((yyvsp[(1) - (4)].expression), (yyvsp[(3) - (4)].expression));
        }
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 557 "diksam.y"
    {
            Expression *identifier = dkc_create_identifier_expression((yyvsp[(1) - (4)].identifier));
            (yyval.expression) = dkc_create_index_expression(identifier, (yyvsp[(3) - (4)].expression));
        }
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 562 "diksam.y"
    {
			Expression *identifier = dkc_create_identifier_expression((yyvsp[(1) - (6)].identifier));
			(yyval.expression) = dkc_create_slice_expression(identifier,(yyvsp[(3) - (6)].expression),(yyvsp[(5) - (6)].expression));
		}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 567 "diksam.y"
    {
			(yyval.expression) = dkc_create_slice_expression((yyvsp[(1) - (6)].expression),(yyvsp[(3) - (6)].expression),(yyvsp[(5) - (6)].expression));
		}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 571 "diksam.y"
    {
            (yyval.expression) = dkc_create_member_expression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].identifier));
        }
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 575 "diksam.y"
    {
            (yyval.expression) = dkc_create_function_call_expression((yyvsp[(1) - (4)].expression), (yyvsp[(3) - (4)].argument_list));
        }
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 579 "diksam.y"
    {
            (yyval.expression) = dkc_create_function_call_expression((yyvsp[(1) - (3)].expression), NULL);
        }
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 583 "diksam.y"
    {
            (yyval.expression) = (yyvsp[(2) - (3)].expression);
        }
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 587 "diksam.y"
    {
            (yyval.expression) = dkc_create_down_cast_expression((yyvsp[(1) - (4)].expression), (yyvsp[(3) - (4)].type_specifier));
        }
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 596 "diksam.y"
    {
            (yyval.expression) = dkc_create_boolean_expression(DVM_TRUE);
        }
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 600 "diksam.y"
    {
            (yyval.expression) = dkc_create_boolean_expression(DVM_FALSE);
        }
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 604 "diksam.y"
    {
            (yyval.expression) = dkc_create_null_expression();
        }
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 609 "diksam.y"
    {
            (yyval.expression) = dkc_create_this_expression();
        }
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 613 "diksam.y"
    {
            (yyval.expression) = dkc_create_super_expression();
        }
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 617 "diksam.y"
    {
			(yyval.expression) = dkc_create_new_delegate_expression();
		}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 621 "diksam.y"
    {
            (yyval.expression) = dkc_create_new_expression((yyvsp[(2) - (4)].identifier), NULL, NULL);
        }
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 625 "diksam.y"
    {
            (yyval.expression) = dkc_create_new_expression((yyvsp[(2) - (5)].identifier), NULL, (yyvsp[(4) - (5)].argument_list));
        }
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 629 "diksam.y"
    {
            (yyval.expression) = dkc_create_new_expression((yyvsp[(2) - (6)].identifier), (yyvsp[(4) - (6)].identifier), NULL);
        }
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 633 "diksam.y"
    {
            (yyval.expression) = dkc_create_new_expression((yyvsp[(2) - (7)].identifier), (yyvsp[(4) - (7)].identifier), (yyvsp[(6) - (7)].argument_list));
        }
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 639 "diksam.y"
    {
            (yyval.expression) = dkc_create_array_literal_expression((yyvsp[(2) - (3)].expression_list));
        }
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 643 "diksam.y"
    {
            (yyval.expression) = dkc_create_array_literal_expression((yyvsp[(2) - (4)].expression_list));
        }
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 649 "diksam.y"
    {
            (yyval.expression) = dkc_create_basic_array_creation((yyvsp[(2) - (4)].basic_type_specifier), (yyvsp[(3) - (4)].array_dimension), NULL,(yyvsp[(4) - (4)].intval));
        }
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 653 "diksam.y"
    {
            (yyval.expression) = dkc_create_basic_array_creation((yyvsp[(2) - (5)].basic_type_specifier), (yyvsp[(3) - (5)].array_dimension), (yyvsp[(4) - (5)].array_dimension),(yyvsp[(5) - (5)].intval));
        }
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 657 "diksam.y"
    {
            (yyval.expression) = dkc_create_class_array_creation((yyvsp[(2) - (4)].type_specifier), (yyvsp[(3) - (4)].array_dimension), NULL,(yyvsp[(4) - (4)].intval));
        }
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 662 "diksam.y"
    {
            (yyval.expression) = dkc_create_class_array_creation((yyvsp[(2) - (5)].type_specifier), (yyvsp[(3) - (5)].array_dimension), (yyvsp[(4) - (5)].array_dimension),(yyvsp[(5) - (5)].intval));
        }
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 666 "diksam.y"
    {
            (yyval.expression) = dkc_create_class_array_creation((yyvsp[(2) - (4)].type_specifier), (yyvsp[(3) - (4)].array_dimension), NULL,(yyvsp[(4) - (4)].intval));
        }
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 670 "diksam.y"
    {
            (yyval.expression) = dkc_create_class_array_creation((yyvsp[(2) - (5)].type_specifier), (yyvsp[(3) - (5)].array_dimension), (yyvsp[(4) - (5)].array_dimension),(yyvsp[(5) - (5)].intval));
        }
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 677 "diksam.y"
    {
            (yyval.array_dimension) = dkc_chain_array_dimension((yyvsp[(1) - (2)].array_dimension), (yyvsp[(2) - (2)].array_dimension));
        }
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 683 "diksam.y"
    {
            (yyval.array_dimension) = dkc_create_array_dimension((yyvsp[(2) - (3)].expression));
        }
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 689 "diksam.y"
    {
            (yyval.array_dimension) = dkc_create_array_dimension(NULL);
        }
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 693 "diksam.y"
    {
            (yyval.array_dimension) = dkc_chain_array_dimension((yyvsp[(1) - (3)].array_dimension),
                                           dkc_create_array_dimension(NULL));
        }
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 700 "diksam.y"
    {
            (yyval.expression_list) = NULL;
        }
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 704 "diksam.y"
    {
            (yyval.expression_list) = dkc_create_expression_list((yyvsp[(1) - (1)].expression));
        }
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 708 "diksam.y"
    {
            (yyval.expression_list) = dkc_chain_expression_list((yyvsp[(1) - (3)].expression_list), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 714 "diksam.y"
    {
          (yyval.statement) = dkc_create_expression_statement((yyvsp[(1) - (2)].expression));
        }
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 730 "diksam.y"
    {/*empty line*/
			(yyval.statement)=0;
		}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 736 "diksam.y"
    {
            (yyval.statement) = dkc_create_if_statement((yyvsp[(2) - (4)].expression), (yyvsp[(4) - (4)].block), NULL, NULL);
        }
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 740 "diksam.y"
    {
			//printf("IF-ELSE %d\n",dkc_get_current_compiler()->current_line_number);
            (yyval.statement) = dkc_create_if_statement((yyvsp[(2) - (6)].expression), (yyvsp[(4) - (6)].block), NULL, (yyvsp[(6) - (6)].block));
        }
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 745 "diksam.y"
    {
            (yyval.statement) = dkc_create_if_statement((yyvsp[(2) - (5)].expression), (yyvsp[(4) - (5)].block), (yyvsp[(5) - (5)].elsif), NULL);
        }
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 749 "diksam.y"
    {
            (yyval.statement) = dkc_create_if_statement((yyvsp[(2) - (7)].expression), (yyvsp[(4) - (7)].block), (yyvsp[(5) - (7)].elsif), (yyvsp[(7) - (7)].block));
        }
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 756 "diksam.y"
    {
            (yyval.elsif) = dkc_chain_elsif_list((yyvsp[(1) - (2)].elsif), (yyvsp[(2) - (2)].elsif));
        }
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 762 "diksam.y"
    {
            (yyval.elsif) = dkc_create_elsif((yyvsp[(2) - (4)].expression), (yyvsp[(4) - (4)].block));
        }
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 768 "diksam.y"
    {
            (yyval.identifier) = NULL;
        }
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 772 "diksam.y"
    {
            (yyval.identifier) = (yyvsp[(1) - (2)].identifier);
        }
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 778 "diksam.y"
    {
            (yyval.statement) = dkc_create_switch_statement((yyvsp[(2) - (5)].expression), (yyvsp[(4) - (5)].case_list), (yyvsp[(5) - (5)].block));
        }
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 785 "diksam.y"
    {
            (yyval.case_list) = dkc_chain_case((yyvsp[(1) - (2)].case_list), (yyvsp[(2) - (2)].case_list));
        }
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 791 "diksam.y"
    {
            (yyval.case_list) = dkc_create_one_case((yyvsp[(2) - (3)].expression_list), (yyvsp[(3) - (3)].block));
        }
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 797 "diksam.y"
    {
            (yyval.block) = NULL;
        }
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 801 "diksam.y"
    {
            (yyval.block) = (yyvsp[(2) - (2)].block);
        }
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 807 "diksam.y"
    {
            (yyval.expression_list) = dkc_create_expression_list((yyvsp[(1) - (1)].expression));
        }
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 811 "diksam.y"
    {
            (yyval.expression_list) = dkc_chain_expression_list((yyvsp[(1) - (3)].expression_list), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 817 "diksam.y"
    {
            (yyval.statement) = dkc_create_while_statement((yyvsp[(1) - (4)].identifier), (yyvsp[(3) - (4)].expression), (yyvsp[(4) - (4)].block));
        }
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 823 "diksam.y"
    {
            (yyval.statement) = dkc_create_for_statement((yyvsp[(1) - (8)].identifier), (yyvsp[(3) - (8)].expression), (yyvsp[(5) - (8)].expression), (yyvsp[(7) - (8)].expression), (yyvsp[(8) - (8)].block));
        }
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 829 "diksam.y"
    {
            (yyval.statement) = dkc_create_do_while_statement((yyvsp[(1) - (8)].identifier), (yyvsp[(3) - (8)].block), (yyvsp[(6) - (8)].expression));
        }
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 835 "diksam.y"
    {
            (yyval.statement) = dkc_create_foreach_statement((yyvsp[(1) - (8)].identifier), (yyvsp[(4) - (8)].identifier), (yyvsp[(6) - (8)].expression), (yyvsp[(8) - (8)].block));
        }
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 841 "diksam.y"
    {
            (yyval.expression) = NULL;
        }
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 848 "diksam.y"
    {
            (yyval.statement) = dkc_create_return_statement((yyvsp[(2) - (3)].expression));
        }
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 854 "diksam.y"
    {
            (yyval.identifier) = NULL;
        }
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 861 "diksam.y"
    {
            (yyval.statement) = dkc_create_break_statement((yyvsp[(2) - (3)].identifier));
        }
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 867 "diksam.y"
    {
            (yyval.statement) = dkc_create_continue_statement((yyvsp[(2) - (3)].identifier));
        }
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 873 "diksam.y"
    {
            (yyval.statement) = dkc_create_try_statement((yyvsp[(2) - (5)].block), (yyvsp[(3) - (5)].catch_clause), (yyvsp[(5) - (5)].block));
        }
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 877 "diksam.y"
    {
            (yyval.statement) = dkc_create_try_statement((yyvsp[(2) - (4)].block), NULL, (yyvsp[(4) - (4)].block));
        }
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 881 "diksam.y"
    {
            (yyval.statement) = dkc_create_try_statement((yyvsp[(2) - (3)].block), (yyvsp[(3) - (3)].catch_clause), NULL);
        }
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 888 "diksam.y"
    {
            (yyval.catch_clause) = dkc_chain_catch_list((yyvsp[(1) - (2)].catch_clause), (yyvsp[(2) - (2)].catch_clause));
        }
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 894 "diksam.y"
    {
            (yyval.catch_clause) = dkc_start_catch_clause();
        }
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 898 "diksam.y"
    {
            (yyval.catch_clause) = dkc_end_catch_clause((yyvsp[(2) - (5)].catch_clause), (yyvsp[(3) - (5)].type_specifier), (yyvsp[(4) - (5)].identifier), (yyvsp[(5) - (5)].block));
        }
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 904 "diksam.y"
    {
            (yyval.statement) = dkc_create_throw_statement((yyvsp[(2) - (3)].expression));
        }
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 908 "diksam.y"
    {
            (yyval.statement) = dkc_create_throw_statement(NULL);
        }
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 914 "diksam.y"
    {
            (yyval.statement) = dkc_create_declaration_statement(DVM_FALSE, (yyvsp[(6) - (7)].type_specifier), (yyvsp[(3) - (7)].identifier), NULL,(yyvsp[(5) - (7)].intval),(yyvsp[(2) - (7)].intval));
        }
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 918 "diksam.y"
    {
            (yyval.statement) = dkc_create_declaration_statement(DVM_FALSE, (yyvsp[(6) - (9)].type_specifier), (yyvsp[(3) - (9)].identifier), (yyvsp[(8) - (9)].expression),(yyvsp[(5) - (9)].intval),(yyvsp[(2) - (9)].intval));
        }
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 922 "diksam.y"
    {
            (yyval.statement) = dkc_create_declaration_statement(DVM_FALSE, (yyvsp[(4) - (5)].type_specifier), (yyvsp[(2) - (5)].identifier), NULL,DVM_FALSE,DVM_FALSE);
        }
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 926 "diksam.y"
    {
            (yyval.statement) = dkc_create_declaration_statement(DVM_TRUE, (yyvsp[(4) - (7)].type_specifier), (yyvsp[(2) - (7)].identifier), (yyvsp[(6) - (7)].expression),DVM_FALSE,DVM_FALSE);
        }
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 932 "diksam.y"
    {
            (yyval.block) = dkc_open_block(0);
        }
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 936 "diksam.y"
    {
            (yyval.block) = dkc_close_block((yyvsp[(2) - (4)].block), (yyvsp[(3) - (4)].statement_list));
        }
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 940 "diksam.y"
    {
            Block *empty_block = dkc_open_block(0);
            (yyval.block) = dkc_close_block(empty_block, NULL);
        }
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 947 "diksam.y"
    {
            (yyval.template_def) = dkc_create_template_declare_list((yyvsp[(1) - (1)].identifier),NULL);
        }
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 951 "diksam.y"
    {
            (yyval.template_def) = dkc_chain_template_declare_list((yyvsp[(1) - (3)].template_def), (yyvsp[(3) - (3)].identifier),NULL);
        }
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 955 "diksam.y"
    {
            (yyval.template_def) = dkc_create_template_declare_list((yyvsp[(1) - (3)].identifier),(yyvsp[(3) - (3)].type_specifier));
        }
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 959 "diksam.y"
    {
            (yyval.template_def) = dkc_chain_template_declare_list((yyvsp[(1) - (5)].template_def), (yyvsp[(3) - (5)].identifier) ,(yyvsp[(5) - (5)].type_specifier));
        }
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 965 "diksam.y"
    {
			(yyval.template_def)=(yyvsp[(2) - (3)].template_def);
		}
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 969 "diksam.y"
    {(yyval.template_def)=NULL;}
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
            dkc_class_define((yyvsp[(8) - (9)].member_declaration));
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
#line 986 "diksam.y"
    {
            dkc_class_define((yyvsp[(9) - (10)].member_declaration));
        }
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 990 "diksam.y"
    {
            dkc_start_class_definition((yyvsp[(1) - (6)].intval),NULL, (yyvsp[(2) - (6)].class_or_interface), (yyvsp[(3) - (6)].identifier),(yyvsp[(4) - (6)].template_def), (yyvsp[(5) - (6)].extends_list));
        }
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 994 "diksam.y"
    {
            dkc_class_define(NULL);
        }
    break;

  case 222:

/* Line 1455 of yacc.c  */
#line 999 "diksam.y"
    {
            dkc_start_class_definition((yyvsp[(1) - (7)].intval),&(yyvsp[(2) - (7)].class_or_member_modifier), (yyvsp[(3) - (7)].class_or_interface), (yyvsp[(4) - (7)].identifier),(yyvsp[(5) - (7)].template_def), (yyvsp[(6) - (7)].extends_list));
        }
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 1003 "diksam.y"
    {
            dkc_class_define(NULL);
        }
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 1010 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_chain_class_or_member_modifier((yyvsp[(1) - (2)].class_or_member_modifier), (yyvsp[(2) - (2)].class_or_member_modifier));
        }
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 1017 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(VIRTUAL_MODIFIER);
        }
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 1021 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(OVERRIDE_MODIFIER);
        }
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 1025 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(ABSTRACT_MODIFIER);
        }
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 1031 "diksam.y"
    {
            (yyval.class_or_interface) = DVM_CLASS_DEFINITION;
        }
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 1035 "diksam.y"
    {
            (yyval.class_or_interface) = DVM_INTERFACE_DEFINITION;
        }
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 1041 "diksam.y"
    {
            (yyval.extends_list) = NULL;
        }
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 1045 "diksam.y"
    {
            (yyval.extends_list) = (yyvsp[(2) - (2)].extends_list);
        }
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 1051 "diksam.y"
    {
            (yyval.extends_list) = dkc_create_extends_list((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 1055 "diksam.y"
    {
            (yyval.extends_list) = dkc_chain_extends_list((yyvsp[(1) - (3)].extends_list), (yyvsp[(3) - (3)].identifier));
        }
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 1062 "diksam.y"
    {
            (yyval.member_declaration) = dkc_chain_member_declaration((yyvsp[(1) - (2)].member_declaration), (yyvsp[(2) - (2)].member_declaration));
        }
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 1072 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_method_member(NULL, (yyvsp[(1) - (1)].function_definition), DVM_FALSE);
        }
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 1076 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_method_member(&(yyvsp[(1) - (2)].class_or_member_modifier), (yyvsp[(2) - (2)].function_definition), DVM_FALSE);
        }
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 1080 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_method_member(NULL, (yyvsp[(1) - (1)].function_definition), DVM_TRUE);
        }
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 1084 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_method_member(&(yyvsp[(1) - (2)].class_or_member_modifier), (yyvsp[(2) - (2)].function_definition), DVM_TRUE);
        }
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 1090 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define((yyvsp[(7) - (9)].type_specifier), (yyvsp[(2) - (9)].identifier), (yyvsp[(4) - (9)].parameter_list), (yyvsp[(8) - (9)].exception_list), (yyvsp[(9) - (9)].block));
        }
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 1094 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define((yyvsp[(6) - (8)].type_specifier), (yyvsp[(2) - (8)].identifier), NULL, (yyvsp[(7) - (8)].exception_list), (yyvsp[(8) - (8)].block));
        }
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 1098 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define((yyvsp[(8) - (10)].type_specifier), (yyvsp[(3) - (10)].identifier), (yyvsp[(5) - (10)].parameter_list), (yyvsp[(9) - (10)].exception_list), NULL);
        }
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 1102 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define((yyvsp[(7) - (9)].type_specifier), (yyvsp[(3) - (9)].identifier), NULL, (yyvsp[(8) - (9)].exception_list), NULL);
        }
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 1106 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define(0, (yyvsp[(2) - (7)].identifier), (yyvsp[(4) - (7)].parameter_list), (yyvsp[(6) - (7)].exception_list), (yyvsp[(7) - (7)].block));
        }
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 1110 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define(0, (yyvsp[(2) - (6)].identifier), NULL, (yyvsp[(5) - (6)].exception_list), (yyvsp[(6) - (6)].block));
        }
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 1114 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define(0, (yyvsp[(3) - (8)].identifier), (yyvsp[(5) - (8)].parameter_list), (yyvsp[(7) - (8)].exception_list), NULL);
        }
    break;

  case 251:

/* Line 1455 of yacc.c  */
#line 1118 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define(0, (yyvsp[(3) - (7)].identifier), NULL, (yyvsp[(6) - (7)].exception_list), NULL);
        }
    break;

  case 252:

/* Line 1455 of yacc.c  */
#line 1124 "diksam.y"
    {
			(yyval.intval)=0;
		}
    break;

  case 253:

/* Line 1455 of yacc.c  */
#line 1128 "diksam.y"
    {
			(yyval.intval)=1;
		}
    break;

  case 254:

/* Line 1455 of yacc.c  */
#line 1134 "diksam.y"
    {
            (yyval.exception_list) = NULL;
        }
    break;

  case 255:

/* Line 1455 of yacc.c  */
#line 1138 "diksam.y"
    {
            (yyval.exception_list) = (yyvsp[(2) - (2)].exception_list);
        }
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 1144 "diksam.y"
    {
            (yyval.exception_list) = dkc_create_throws((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 1148 "diksam.y"
    {
            (yyval.exception_list) = dkc_chain_exception_list((yyvsp[(1) - (3)].exception_list), (yyvsp[(3) - (3)].identifier));
        }
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 1154 "diksam.y"
    {
            (yyval.function_definition) = dkc_constructor_function_define((yyvsp[(2) - (7)].identifier), (yyvsp[(4) - (7)].parameter_list), (yyvsp[(6) - (7)].exception_list), (yyvsp[(7) - (7)].block));
        }
    break;

  case 259:

/* Line 1455 of yacc.c  */
#line 1158 "diksam.y"
    {
            (yyval.function_definition) = dkc_constructor_function_define((yyvsp[(2) - (6)].identifier), NULL, (yyvsp[(5) - (6)].exception_list), (yyvsp[(6) - (6)].block));
        }
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 1162 "diksam.y"
    {
            (yyval.function_definition) = dkc_constructor_function_define((yyvsp[(3) - (8)].identifier), (yyvsp[(5) - (8)].parameter_list), (yyvsp[(7) - (8)].exception_list), NULL);
        }
    break;

  case 261:

/* Line 1455 of yacc.c  */
#line 1166 "diksam.y"
    {
            (yyval.function_definition) = dkc_constructor_function_define((yyvsp[(3) - (7)].identifier), NULL, (yyvsp[(6) - (7)].exception_list), NULL);
        }
    break;

  case 262:

/* Line 1455 of yacc.c  */
#line 1172 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(PUBLIC_MODIFIER);
        }
    break;

  case 263:

/* Line 1455 of yacc.c  */
#line 1176 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(PRIVATE_MODIFIER);
        }
    break;

  case 264:

/* Line 1455 of yacc.c  */
#line 1182 "diksam.y"
    {
            (yyval.expression) = NULL;
        }
    break;

  case 265:

/* Line 1455 of yacc.c  */
#line 1186 "diksam.y"
    {
            (yyval.expression) = (yyvsp[(2) - (2)].expression);
        }
    break;

  case 266:

/* Line 1455 of yacc.c  */
#line 1192 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(NULL, DVM_FALSE, (yyvsp[(4) - (6)].type_specifier), (yyvsp[(2) - (6)].identifier), (yyvsp[(5) - (6)].expression));
        }
    break;

  case 267:

/* Line 1455 of yacc.c  */
#line 1197 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(&(yyvsp[(1) - (6)].class_or_member_modifier), DVM_FALSE, (yyvsp[(4) - (6)].type_specifier), (yyvsp[(2) - (6)].identifier), (yyvsp[(5) - (6)].expression));
        }
    break;

  case 268:

/* Line 1455 of yacc.c  */
#line 1201 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(NULL, DVM_TRUE, (yyvsp[(4) - (6)].type_specifier), (yyvsp[(2) - (6)].identifier), (yyvsp[(5) - (6)].expression));
        }
    break;

  case 269:

/* Line 1455 of yacc.c  */
#line 1206 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(&(yyvsp[(1) - (7)].class_or_member_modifier), DVM_TRUE, (yyvsp[(5) - (7)].type_specifier), (yyvsp[(3) - (7)].identifier), (yyvsp[(6) - (7)].expression));
        }
    break;

  case 270:

/* Line 1455 of yacc.c  */
#line 1210 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(&(yyvsp[(2) - (7)].class_or_member_modifier), DVM_TRUE, (yyvsp[(5) - (7)].type_specifier), (yyvsp[(3) - (7)].identifier), (yyvsp[(6) - (7)].expression));
        }
    break;

  case 271:

/* Line 1455 of yacc.c  */
#line 1216 "diksam.y"
    {
            dkc_create_delegate_definition((yyvsp[(8) - (10)].type_specifier), (yyvsp[(2) - (10)].identifier), (yyvsp[(4) - (10)].parameter_list), (yyvsp[(9) - (10)].exception_list),(yyvsp[(5) - (10)].intval));
        }
    break;

  case 272:

/* Line 1455 of yacc.c  */
#line 1220 "diksam.y"
    {
            dkc_create_delegate_definition((yyvsp[(7) - (9)].type_specifier), (yyvsp[(2) - (9)].identifier), NULL, (yyvsp[(8) - (9)].exception_list),(yyvsp[(4) - (9)].intval));
        }
    break;

  case 273:

/* Line 1455 of yacc.c  */
#line 1226 "diksam.y"
    {
            dkc_create_enum_definition((yyvsp[(2) - (5)].identifier), (yyvsp[(4) - (5)].enumerator));
        }
    break;

  case 274:

/* Line 1455 of yacc.c  */
#line 1230 "diksam.y"
    {
            dkc_create_enum_definition((yyvsp[(2) - (6)].identifier), (yyvsp[(4) - (6)].enumerator));
        }
    break;

  case 275:

/* Line 1455 of yacc.c  */
#line 1236 "diksam.y"
    {
            (yyval.enumerator) = dkc_create_enumerator((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 276:

/* Line 1455 of yacc.c  */
#line 1240 "diksam.y"
    {
            (yyval.enumerator) = dkc_chain_enumerator((yyvsp[(1) - (3)].enumerator), (yyvsp[(3) - (3)].identifier));
        }
    break;

  case 277:

/* Line 1455 of yacc.c  */
#line 1246 "diksam.y"
    {
            dkc_create_const_definition(NULL, (yyvsp[(2) - (5)].identifier), (yyvsp[(4) - (5)].expression));
        }
    break;

  case 278:

/* Line 1455 of yacc.c  */
#line 1250 "diksam.y"
    {
            dkc_create_const_definition((yyvsp[(2) - (4)].type_specifier), (yyvsp[(3) - (4)].identifier), NULL);
        }
    break;

  case 279:

/* Line 1455 of yacc.c  */
#line 1256 "diksam.y"
    {
			(yyval.intval)=0;
		}
    break;

  case 280:

/* Line 1455 of yacc.c  */
#line 1260 "diksam.y"
    {
			(yyval.intval)=1;
		}
    break;

  case 281:

/* Line 1455 of yacc.c  */
#line 1266 "diksam.y"
    {
			(yyval.intval)=0;
		}
    break;

  case 282:

/* Line 1455 of yacc.c  */
#line 1270 "diksam.y"
    {
			(yyval.intval)=1;
		}
    break;

  case 283:

/* Line 1455 of yacc.c  */
#line 1276 "diksam.y"
    {
			(yyval.intval)=0;
		}
    break;

  case 284:

/* Line 1455 of yacc.c  */
#line 1280 "diksam.y"
    {
			(yyval.intval)=1;
		}
    break;

  case 285:

/* Line 1455 of yacc.c  */
#line 1286 "diksam.y"
    {
			(yyval.intval)=0;
		}
    break;

  case 286:

/* Line 1455 of yacc.c  */
#line 1290 "diksam.y"
    {
			(yyval.intval)=1;
		}
    break;

  case 287:

/* Line 1455 of yacc.c  */
#line 1294 "diksam.y"
    {
			(yyval.intval)=-1;
		}
    break;

  case 288:

/* Line 1455 of yacc.c  */
#line 1300 "diksam.y"
    {
            (yyval.block) = dkc_open_block((yyvsp[(2) - (2)].intval));
			//printf("E1 %d\n",dkc_get_current_compiler());
        }
    break;

  case 289:

/* Line 1455 of yacc.c  */
#line 1305 "diksam.y"
    {
            (yyval.block) = dkc_close_block((yyvsp[(3) - (5)].block), (yyvsp[(4) - (5)].statement_list));
			//printf("C1 %d\n",dkc_get_current_compiler()->current_line_number);
        }
    break;

  case 290:

/* Line 1455 of yacc.c  */
#line 1310 "diksam.y"
    {
            Block *empty_block = dkc_open_block(0);
            (yyval.block) = dkc_close_block(empty_block, NULL);
			//printf("C2 %d\n",dkc_get_current_compiler()->current_line_number);
        }
    break;



/* Line 1455 of yacc.c  */
#line 4400 "y.tab.c"
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
#line 1316 "diksam.y"


