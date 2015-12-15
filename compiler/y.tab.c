
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
     ATM_ADD_ASSIGN_T = 361,
     ATM_SUB_ASSIGN_T = 362
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
#define ATM_ADD_ASSIGN_T 361
#define ATM_SUB_ASSIGN_T 362




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
#line 363 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 375 "y.tab.c"

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
#define YYLAST   1046

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  108
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  100
/* YYNRULES -- Number of rules.  */
#define YYNRULES  281
/* YYNRULES -- Number of states.  */
#define YYNSTATES  604

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   362

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
     105,   106,   107
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    12,    14,    16,    19,
      21,    24,    28,    30,    34,    36,    39,    44,    46,    48,
      50,    52,    54,    56,    58,    60,    62,    64,    66,    68,
      70,    72,    74,    78,    82,    86,    90,    95,    97,    99,
     101,   103,   105,   109,   110,   117,   118,   121,   124,   136,
     147,   157,   166,   177,   187,   196,   204,   206,   210,   216,
     218,   222,   224,   227,   229,   233,   235,   239,   241,   243,
     245,   247,   249,   251,   253,   255,   257,   261,   263,   267,
     269,   273,   277,   279,   283,   287,   291,   295,   297,   301,
     305,   307,   311,   315,   319,   323,   327,   331,   333,   336,
     339,   342,   344,   347,   350,   354,   356,   358,   360,   362,
     367,   372,   376,   381,   385,   389,   394,   396,   398,   400,
     402,   404,   406,   408,   410,   412,   414,   419,   424,   430,
     437,   445,   449,   454,   458,   463,   467,   472,   476,   481,
     483,   486,   490,   493,   497,   498,   500,   504,   507,   509,
     511,   513,   515,   517,   519,   521,   523,   525,   527,   529,
     531,   533,   538,   545,   551,   559,   561,   564,   569,   570,
     573,   579,   581,   584,   588,   589,   592,   594,   598,   603,
     612,   621,   630,   631,   633,   637,   638,   640,   644,   648,
     654,   659,   663,   665,   668,   669,   675,   679,   682,   689,
     698,   704,   712,   713,   718,   721,   723,   727,   731,   737,
     741,   742,   743,   753,   754,   765,   766,   775,   776,   786,
     788,   791,   793,   795,   797,   799,   801,   803,   804,   807,
     809,   813,   815,   818,   820,   822,   824,   827,   829,   832,
     842,   851,   862,   872,   880,   887,   896,   904,   905,   908,
     909,   912,   914,   918,   926,   933,   942,   950,   952,   954,
     955,   958,   965,   972,   979,   987,   995,  1006,  1016,  1022,
    1029,  1031,  1035,  1041,  1046,  1047,  1049,  1050,  1053,  1056,
    1057,  1063
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     109,     0,    -1,   110,    -1,   109,   116,    -1,    -1,   111,
     114,    -1,   111,    -1,   114,    -1,   110,   123,    -1,   112,
      -1,   111,   112,    -1,    74,   113,    98,    -1,     7,    -1,
     113,    53,     7,    -1,   115,    -1,   114,   115,    -1,    75,
     113,     7,    98,    -1,   127,    -1,   179,    -1,   150,    -1,
     200,    -1,   201,    -1,   203,    -1,    66,    -1,    67,    -1,
      68,    -1,    69,    -1,    70,    -1,    71,    -1,    72,    -1,
      89,    -1,     7,    -1,   117,    27,    28,    -1,     7,    27,
      28,    -1,   119,    27,    28,    -1,   120,    27,    28,    -1,
       7,    39,   122,    37,    -1,   117,    -1,   119,    -1,   118,
      -1,   120,    -1,   121,    -1,   122,    31,   121,    -1,    -1,
     102,     7,   124,    98,   125,    97,    -1,    -1,   125,   126,
      -1,   125,   179,    -1,    99,    93,     7,    23,   128,   193,
      24,    94,   121,   194,    98,    -1,    99,    93,     7,    23,
     193,    24,    94,   121,   194,    98,    -1,    99,   100,     7,
      23,   128,   193,    24,   194,    98,    -1,    99,   100,     7,
      23,   193,    24,   194,    98,    -1,    93,     7,    23,   128,
     193,    24,    94,   121,   194,   206,    -1,    93,     7,    23,
     193,    24,    94,   121,   194,   206,    -1,   100,     7,    23,
     128,   193,    24,   194,   206,    -1,   100,     7,    23,   193,
      24,   194,   206,    -1,   126,    -1,     7,    94,   121,    -1,
     128,    31,     7,    94,   121,    -1,   132,    -1,   129,    31,
     132,    -1,   150,    -1,   130,   150,    -1,   132,    -1,   131,
      31,   132,    -1,   134,    -1,   142,   133,   132,    -1,    32,
      -1,    54,    -1,    55,    -1,   106,    -1,   107,    -1,    56,
      -1,    57,    -1,    58,    -1,   135,    -1,   134,    34,   135,
      -1,   136,    -1,   135,    33,   136,    -1,   137,    -1,   136,
      35,   137,    -1,   136,    36,   137,    -1,   138,    -1,   137,
      37,   138,    -1,   137,    38,   138,    -1,   137,    39,   138,
      -1,   137,    40,   138,    -1,   139,    -1,   138,    41,   139,
      -1,   138,    42,   139,    -1,   140,    -1,   139,    43,   140,
      -1,   139,    44,   140,    -1,   139,    45,   140,    -1,   139,
      46,   140,    -1,   139,    47,   140,    -1,   139,    48,   140,
      -1,   141,    -1,    42,   140,    -1,    52,   140,    -1,    49,
     140,    -1,   142,    -1,   142,    59,    -1,   142,    60,    -1,
     142,    86,   121,    -1,   143,    -1,   145,    -1,     7,    -1,
       8,    -1,   143,    27,   131,    28,    -1,     7,    27,   131,
      28,    -1,   142,    53,     7,    -1,   142,    23,   129,    24,
      -1,   142,    23,    24,    -1,    23,   131,    24,    -1,   142,
      87,   121,    88,    -1,     3,    -1,     4,    -1,     5,    -1,
       6,    -1,    50,    -1,    51,    -1,    22,    -1,   144,    -1,
      83,    -1,    84,    -1,    73,    89,    23,    24,    -1,    73,
       7,    23,    24,    -1,    73,     7,    23,   129,    24,    -1,
      73,     7,    53,     7,    23,    24,    -1,    73,     7,    53,
       7,    23,   129,    24,    -1,    25,   149,    26,    -1,    25,
     149,    31,    26,    -1,    73,   117,   146,    -1,    73,   117,
     146,   148,    -1,    73,   118,   146,    -1,    73,   118,   146,
     148,    -1,    73,   120,   146,    -1,    73,   120,   146,   148,
      -1,   147,    -1,   146,   147,    -1,    27,   131,    28,    -1,
      27,    28,    -1,   148,    27,    28,    -1,    -1,   132,    -1,
     149,    31,   132,    -1,   131,    98,    -1,   151,    -1,   155,
      -1,   160,    -1,   161,    -1,   162,    -1,   163,    -1,   165,
      -1,   167,    -1,   168,    -1,   169,    -1,   173,    -1,   174,
      -1,    98,    -1,     9,   131,    95,   206,    -1,     9,   131,
      95,   206,    10,   206,    -1,     9,   131,    95,   206,   152,
      -1,     9,   131,    95,   206,   152,    10,   206,    -1,   153,
      -1,   152,   153,    -1,    11,   131,    95,   206,    -1,    -1,
       7,    30,    -1,    12,   131,    98,   156,   158,    -1,   157,
      -1,   156,   157,    -1,    13,   159,   206,    -1,    -1,    14,
     206,    -1,   132,    -1,   149,    31,   132,    -1,   154,    15,
     131,   206,    -1,   154,    17,   164,    29,   164,    29,   164,
     206,    -1,   154,    16,   175,    15,    23,   131,    24,    98,
      -1,   154,    18,    23,     7,    30,   131,    24,   175,    -1,
      -1,   131,    -1,    19,   164,    98,    -1,    -1,     7,    -1,
      20,   166,    98,    -1,    21,   166,    98,    -1,    61,   206,
     170,    63,   206,    -1,    61,   206,    63,   175,    -1,    61,
     206,   170,    -1,   171,    -1,   170,   171,    -1,    -1,    62,
     172,   121,     7,   206,    -1,    64,   131,    98,    -1,    64,
      98,    -1,    96,     7,    94,   204,   121,    98,    -1,    96,
       7,    94,   204,   121,    32,   131,    98,    -1,    90,     7,
      94,   121,    98,    -1,    90,     7,    94,   121,    32,   131,
      98,    -1,    -1,    25,   176,   130,    26,    -1,    25,    26,
      -1,     7,    -1,   177,    31,     7,    -1,     7,    30,   118,
      -1,   177,    31,     7,    30,   118,    -1,    39,   177,    37,
      -1,    -1,    -1,   204,   186,     7,   178,   187,    98,   180,
     189,    97,    -1,    -1,   204,   184,   186,     7,   178,   187,
      98,   181,   189,    97,    -1,    -1,   204,   186,     7,   178,
     187,    98,   182,    97,    -1,    -1,   204,   184,   186,     7,
     178,   187,    98,   183,    97,    -1,   185,    -1,   184,   185,
      -1,   197,    -1,    80,    -1,    81,    -1,    82,    -1,    76,
      -1,    77,    -1,    -1,    30,   188,    -1,     7,    -1,   188,
      31,     7,    -1,   190,    -1,   189,   190,    -1,   191,    -1,
     199,    -1,   192,    -1,   184,   192,    -1,   196,    -1,   184,
     196,    -1,    93,     7,    23,   128,    24,    94,   121,   194,
     206,    -1,    93,     7,    23,    24,    94,   121,   194,   206,
      -1,    99,    93,     7,    23,   128,    24,    94,   121,   194,
      98,    -1,    99,    93,     7,    23,    24,    94,   121,   194,
      98,    -1,   100,     7,    23,   128,    24,   194,   206,    -1,
     100,     7,    23,    24,   194,   206,    -1,    99,   100,     7,
      23,   128,    24,   194,    98,    -1,    99,   100,     7,    23,
      24,   194,    98,    -1,    -1,    31,   101,    -1,    -1,    65,
     195,    -1,     7,    -1,   195,    31,     7,    -1,    85,     7,
      23,   128,    24,   194,   206,    -1,    85,     7,    23,    24,
     194,   206,    -1,    99,    85,     7,    23,   128,    24,   194,
      98,    -1,    99,    85,     7,    23,    24,   194,    98,    -1,
      78,    -1,    79,    -1,    -1,    32,   131,    -1,    96,     7,
      94,   121,   198,    98,    -1,   184,     7,    94,   121,   198,
      98,    -1,    90,     7,    94,   121,   198,    98,    -1,   184,
      90,     7,    94,   121,   198,    98,    -1,    90,   184,     7,
      94,   121,   198,    98,    -1,    89,     7,    23,   128,   193,
      24,    94,   121,   194,    98,    -1,    89,     7,    23,   193,
      24,    94,   121,   194,    98,    -1,    91,     7,    25,   202,
      26,    -1,    91,     7,    25,   202,    31,    26,    -1,     7,
      -1,   202,    31,     7,    -1,    92,     7,    32,   131,    98,
      -1,    92,   121,     7,    98,    -1,    -1,   105,    -1,    -1,
     103,    98,    -1,   104,    98,    -1,    -1,    98,   205,   207,
     130,    97,    -1,    98,    97,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   104,   104,   105,   109,   112,   116,   120,   124,   130,
     131,   137,   143,   147,   153,   154,   160,   166,   167,   168,
     175,   176,   177,   180,   184,   188,   192,   196,   200,   204,
     208,   214,   220,   226,   232,   236,   242,   248,   252,   253,
     254,   258,   262,   270,   269,   284,   287,   288,   291,   295,
     299,   303,   310,   314,   318,   322,   326,   329,   333,   339,
     343,   349,   353,   359,   360,   366,   367,   373,   377,   381,
     385,   389,   393,   397,   401,   407,   408,   414,   415,   421,
     422,   426,   432,   433,   437,   441,   445,   451,   452,   456,
     462,   463,   467,   471,   475,   479,   483,   489,   490,   494,
     498,   504,   505,   509,   513,   519,   520,   521,   525,   531,
     535,   540,   544,   548,   552,   556,   560,   561,   562,   563,
     564,   568,   572,   576,   577,   581,   585,   589,   593,   597,
     601,   607,   611,   617,   621,   625,   629,   634,   638,   644,
     645,   651,   657,   661,   669,   672,   676,   682,   686,   687,
     688,   689,   690,   691,   692,   693,   694,   695,   696,   697,
     698,   704,   708,   713,   717,   723,   724,   730,   737,   740,
     746,   752,   753,   759,   766,   769,   775,   779,   785,   791,
     797,   803,   810,   813,   816,   823,   826,   829,   835,   841,
     845,   849,   855,   856,   863,   862,   872,   876,   882,   886,
     890,   894,   901,   900,   908,   915,   919,   923,   927,   933,
     938,   943,   941,   952,   950,   959,   958,   968,   966,   977,
     978,   984,   985,   989,   993,   999,  1003,  1010,  1013,  1019,
    1023,  1029,  1030,  1036,  1037,  1040,  1044,  1048,  1052,  1058,
    1062,  1066,  1070,  1074,  1078,  1082,  1086,  1093,  1096,  1103,
    1106,  1112,  1116,  1122,  1126,  1130,  1134,  1140,  1144,  1151,
    1154,  1160,  1164,  1169,  1173,  1178,  1184,  1188,  1194,  1198,
    1204,  1208,  1214,  1218,  1225,  1228,  1235,  1238,  1242,  1249,
    1248,  1258
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
  "UNSAFE", "SAFE", "SHARED", "ATM_ADD_ASSIGN_T", "ATM_SUB_ASSIGN_T",
  "$accept", "translation_unit", "initial_declaration", "require_list",
  "require_declaration", "package_name", "rename_list",
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
  "const_definition", "shared", "unsafe", "myblock", "@8", 0
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
     355,   356,   357,   358,   359,   360,   361,   362
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   108,   109,   109,   110,   110,   110,   110,   110,   111,
     111,   112,   113,   113,   114,   114,   115,   116,   116,   116,
     116,   116,   116,   117,   117,   117,   117,   117,   117,   117,
     117,   118,   119,   119,   119,   119,   120,   121,   121,   121,
     121,   122,   122,   124,   123,   125,   125,   125,   126,   126,
     126,   126,   127,   127,   127,   127,   127,   128,   128,   129,
     129,   130,   130,   131,   131,   132,   132,   133,   133,   133,
     133,   133,   133,   133,   133,   134,   134,   135,   135,   136,
     136,   136,   137,   137,   137,   137,   137,   138,   138,   138,
     139,   139,   139,   139,   139,   139,   139,   140,   140,   140,
     140,   141,   141,   141,   141,   142,   142,   142,   142,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   144,   144,   145,   145,   145,   145,   145,   145,   146,
     146,   147,   148,   148,   149,   149,   149,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   151,   151,   151,   151,   152,   152,   153,   154,   154,
     155,   156,   156,   157,   158,   158,   159,   159,   160,   161,
     162,   163,   164,   164,   165,   166,   166,   167,   168,   169,
     169,   169,   170,   170,   172,   171,   173,   173,   174,   174,
     174,   174,   176,   175,   175,   177,   177,   177,   177,   178,
     178,   180,   179,   181,   179,   182,   179,   183,   179,   184,
     184,   185,   185,   185,   185,   186,   186,   187,   187,   188,
     188,   189,   189,   190,   190,   191,   191,   191,   191,   192,
     192,   192,   192,   192,   192,   192,   192,   193,   193,   194,
     194,   195,   195,   196,   196,   196,   196,   197,   197,   198,
     198,   199,   199,   199,   199,   199,   200,   200,   201,   201,
     202,   202,   203,   203,   204,   204,   205,   205,   205,   207,
     206,   206
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     2,     1,
       2,     3,     1,     3,     1,     2,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     3,     4,     1,     1,     1,
       1,     1,     3,     0,     6,     0,     2,     2,    11,    10,
       9,     8,    10,     9,     8,     7,     1,     3,     5,     1,
       3,     1,     2,     1,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     3,     3,     1,     2,     2,
       2,     1,     2,     2,     3,     1,     1,     1,     1,     4,
       4,     3,     4,     3,     3,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     5,     6,
       7,     3,     4,     3,     4,     3,     4,     3,     4,     1,
       2,     3,     2,     3,     0,     1,     3,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     6,     5,     7,     1,     2,     4,     0,     2,
       5,     1,     2,     3,     0,     2,     1,     3,     4,     8,
       8,     8,     0,     1,     3,     0,     1,     3,     3,     5,
       4,     3,     1,     2,     0,     5,     3,     2,     6,     8,
       5,     7,     0,     4,     2,     1,     3,     3,     5,     3,
       0,     0,     9,     0,    10,     0,     8,     0,     9,     1,
       2,     1,     1,     1,     1,     1,     1,     0,     2,     1,
       3,     1,     2,     1,     1,     1,     2,     1,     2,     9,
       8,    10,     9,     7,     6,     8,     7,     0,     2,     0,
       2,     1,     3,     7,     6,     8,     7,     1,     1,     0,
       2,     6,     6,     6,     7,     7,    10,     9,     5,     6,
       1,     3,     5,     4,     0,     1,     0,     2,     2,     0,
       5,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       4,     0,     0,   274,     2,     6,     9,     7,    14,    12,
       0,     0,     1,   116,   117,   118,   119,   107,   108,     0,
       0,   182,   185,   185,   122,     0,   144,     0,     0,   120,
     121,     0,     0,     0,     0,   124,   125,     0,     0,     0,
       0,     0,     0,   160,     0,     0,   275,     3,    56,    17,
       0,    63,    65,    75,    77,    79,    82,    87,    90,    97,
     101,   105,   123,   106,    19,   148,     0,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,    18,    20,
      21,    22,     0,     0,     8,    10,     5,    15,     0,    11,
       0,     0,   169,   107,     0,     0,   183,     0,   186,     0,
       0,     0,   145,     0,    98,   101,   100,    99,   276,     0,
     197,     0,    31,    23,    24,    25,    26,    27,    28,    29,
      30,     0,     0,     0,     0,     0,     0,    31,    30,    37,
      39,    38,    40,     0,     0,     0,     0,     0,     0,     0,
     147,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    67,     0,
      68,    69,    72,    73,    74,   102,   103,     0,     0,    70,
      71,     0,     0,     0,     0,   182,     0,   225,   226,   257,
     258,   222,   223,   224,     0,   219,     0,   221,    43,    13,
      16,     0,     0,     0,   184,   187,   188,   114,   131,     0,
     281,     0,     0,   279,   194,     0,   191,   192,   196,     0,
       0,     0,     0,     0,   133,   139,   135,   137,   247,     0,
       0,     0,     0,     0,     0,     0,     0,   247,   274,     0,
       0,   247,    64,    76,    78,    80,    81,    83,    84,    85,
      86,    88,    89,    91,    92,    93,    94,    95,    96,   113,
       0,    59,   111,    31,   104,     0,    66,     0,     0,   202,
       0,     0,     0,   220,     0,   210,     0,   110,   161,   144,
     174,   171,   132,   146,   277,   278,   168,     0,   190,     0,
     193,   127,     0,    41,     0,     0,   126,     0,     0,   140,
     134,   136,   138,     0,     0,   247,     0,     0,   270,     0,
      33,     0,    32,    34,    35,   273,   247,     0,     0,   247,
     247,   247,     0,   112,     0,   115,   109,   178,   204,   168,
       0,   182,     0,   210,     0,   227,    45,     0,     0,   163,
     165,   145,     0,     0,     0,   172,   170,   168,    61,     0,
     189,   128,     0,    36,     0,   141,   142,     0,     0,   248,
       0,     0,     0,     0,   200,   268,     0,   272,     0,     0,
       0,   247,     0,   247,     0,     0,   249,    60,   168,     0,
       0,     0,   227,   205,     0,     0,     0,   274,   162,     0,
       0,   166,     0,   173,   175,   280,    62,     0,    42,   129,
       0,   143,    57,     0,     0,     0,     0,   271,   269,     0,
       0,     0,   198,     0,     0,     0,   249,   249,     0,     0,
     203,     0,   182,     0,     0,     0,     0,   209,   229,   228,
     211,    44,    46,    47,     0,   164,   146,   195,   130,     0,
       0,   249,   201,     0,   249,     0,     0,     0,   249,     0,
       0,   251,   250,    55,     0,     0,     0,   213,    31,   207,
     206,     0,     0,     0,   167,    58,   249,     0,   249,     0,
     199,     0,   249,     0,    51,    54,     0,   180,   179,   181,
       0,     0,     0,   230,     0,     0,     0,     0,     0,     0,
       0,     0,   231,   233,   235,   237,   234,   216,     0,   267,
       0,    53,   249,     0,    50,   252,     0,   218,   208,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     236,   238,   212,   232,   266,    52,     0,    49,   214,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      48,   249,     0,   259,     0,     0,     0,   259,     0,     0,
       0,   249,     0,   259,     0,     0,   249,     0,     0,     0,
     259,     0,     0,     0,   249,     0,     0,     0,   249,     0,
       0,   249,     0,   259,   254,     0,   260,   263,     0,   249,
       0,   261,     0,   249,     0,     0,     0,   249,   244,     0,
     262,     0,   253,   265,     0,   249,   256,     0,   249,     0,
     246,     0,   243,   264,   240,     0,   255,     0,   249,   245,
     239,   242,     0,   241
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,     6,    10,     7,     8,    47,   129,
     130,   131,   132,   133,   284,    84,   266,   377,    48,    49,
     295,   250,   337,    50,    51,   171,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,   214,   215,
     290,   103,   338,    65,   329,   330,    66,    67,   270,   271,
     336,   333,    68,    69,    70,    71,    97,    72,    99,    73,
      74,    75,   206,   207,   277,    76,    77,   260,   319,   374,
     325,    78,   452,   470,   453,   471,   480,   185,   186,   376,
     419,   481,   482,   483,   484,   296,   409,   442,   485,   187,
     549,   486,    79,    80,   299,    81,    82,   203,   109,   276
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -405
static const yytype_int16 yypact[] =
{
      77,    31,    31,   459,   -61,    77,  -405,    -7,  -405,  -405,
     -27,    17,  -405,  -405,  -405,  -405,  -405,   136,  -405,   962,
     962,   962,   113,   113,  -405,   962,   962,   962,   962,  -405,
    -405,   962,    24,   806,   141,  -405,  -405,   127,   157,   186,
     219,   188,   198,  -405,    76,   227,  -405,  -405,  -405,  -405,
      -8,  -405,   239,   158,   184,   242,   234,   384,  -405,  -405,
      -5,   250,  -405,  -405,  -405,  -405,   322,  -405,  -405,  -405,
    -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,
    -405,  -405,   298,   264,  -405,  -405,    -7,  -405,   277,  -405,
     206,   962,  -405,   280,     2,    -3,   279,   229,  -405,   243,
     253,   137,  -405,   207,  -405,   114,  -405,  -405,    85,   197,
    -405,     1,    20,  -405,  -405,  -405,  -405,  -405,  -405,  -405,
     309,   285,   285,   285,   312,   231,   343,    86,  -405,   345,
    -405,   360,   362,   363,   367,   297,   385,   387,   372,   962,
    -405,   962,   962,   962,   962,   962,   962,   962,   962,   962,
     962,   962,   962,   962,   962,   962,   962,   818,  -405,   389,
    -405,  -405,  -405,  -405,  -405,  -405,  -405,   247,   247,  -405,
    -405,   962,   962,   962,   374,   962,   378,  -405,  -405,  -405,
    -405,  -405,  -405,  -405,   298,  -405,   390,  -405,  -405,  -405,
    -405,   218,    24,   391,  -405,  -405,  -405,  -405,  -405,   858,
    -405,   304,   307,  -405,  -405,   374,   258,  -405,  -405,   870,
     247,   399,   386,   962,   381,  -405,   381,   381,    27,   247,
     402,   388,   962,   392,   393,   395,   314,    27,   308,   396,
     401,    27,  -405,   158,   184,   242,   242,   234,   234,   234,
     234,   384,   384,  -405,  -405,  -405,  -405,  -405,  -405,  -405,
     153,  -405,  -405,    37,  -405,   326,  -405,   233,     8,   408,
     400,   406,   411,  -405,   418,   397,   339,  -405,   289,   962,
     335,  -405,  -405,  -405,  -405,  -405,   754,   247,  -405,    24,
    -405,  -405,   168,  -405,    43,   415,  -405,   237,   910,  -405,
     412,   412,   412,   346,   341,   429,   437,   -12,  -405,   232,
    -405,     9,  -405,  -405,  -405,  -405,   429,   445,   247,    27,
      27,   429,   446,  -405,   962,  -405,  -405,  -405,  -405,   754,
     449,   962,   443,   397,   476,   460,  -405,    24,   962,   348,
    -405,   398,   462,    24,    24,  -405,  -405,   562,  -405,   484,
    -405,  -405,   247,  -405,   922,  -405,  -405,   466,   247,  -405,
      10,   471,   404,   962,  -405,  -405,    39,  -405,   475,   423,
     -10,   429,   478,   429,   481,   494,   456,  -405,   658,   962,
     493,   962,   460,   495,   105,   519,   430,   -68,  -405,    13,
      24,  -405,   962,  -405,  -405,  -405,  -405,    24,  -405,  -405,
     173,  -405,  -405,   441,   442,   247,    11,  -405,  -405,   444,
     247,   962,  -405,   513,   447,   515,   456,   456,   533,    24,
    -405,   191,   962,   192,   448,   537,   538,  -405,  -405,   516,
     457,  -405,  -405,  -405,    24,  -405,   455,  -405,  -405,   247,
     247,   456,  -405,   247,   456,    14,   467,   247,   456,   458,
      24,  -405,   529,  -405,   464,    24,   374,   479,  -405,  -405,
     542,   556,   510,   480,  -405,  -405,   456,   477,   456,    24,
    -405,   247,   456,   482,  -405,  -405,   566,  -405,  -405,  -405,
     510,   489,   537,  -405,   571,   214,   572,   586,   -16,   587,
      50,   407,  -405,  -405,  -405,  -405,  -405,  -405,   498,  -405,
      24,  -405,   456,   499,  -405,  -405,   434,  -405,  -405,   575,
     505,   265,   578,   508,   598,   600,   601,   592,   522,   610,
    -405,  -405,  -405,  -405,  -405,  -405,   520,  -405,  -405,    54,
     247,   525,    55,   247,   597,   599,   602,    59,   247,   527,
    -405,   456,   200,   595,   247,   530,   204,   595,    68,   103,
     117,   456,   205,   595,   247,    24,   456,   621,   962,   531,
     595,   247,   536,   534,   456,   221,   539,   224,   456,   226,
      24,   456,   540,   595,  -405,    24,   279,  -405,   541,   456,
     247,  -405,   543,   456,   247,   546,   544,   456,  -405,    24,
    -405,   545,  -405,  -405,    24,   456,  -405,   549,   456,   247,
    -405,   550,  -405,  -405,  -405,    24,  -405,   551,   456,  -405,
    -405,  -405,   552,  -405
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -405,  -405,  -405,  -405,   626,   632,   631,    12,  -405,   603,
     -31,  -405,   617,  -163,  -405,  -405,  -405,  -405,   267,  -405,
    -216,  -197,   334,   -19,   -13,  -405,  -405,   514,   512,   220,
     208,   212,    88,  -405,   302,  -405,  -405,  -405,   244,   -36,
     169,   403,     5,  -405,  -405,   327,  -405,  -405,  -405,   405,
    -405,  -405,  -405,  -405,  -405,  -405,  -159,  -405,   634,  -405,
    -405,  -405,  -405,   463,  -405,  -405,  -405,  -195,  -405,  -405,
     350,   291,  -405,  -405,  -405,  -405,   -75,  -175,   487,   310,
    -405,   215,  -358,  -405,   194,  -206,  -371,  -405,   196,  -405,
    -404,  -405,  -405,  -405,  -405,  -405,   461,  -405,  -162,  -405
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -218
static const yytype_int16 yytable[] =
{
      94,    95,    96,   122,   254,   255,   101,   184,    64,   263,
     278,   306,   282,   102,   111,   311,   261,   393,   157,    87,
     353,   307,   401,   139,    90,   312,    88,   158,   139,   421,
     268,    44,   139,   139,   293,   439,   440,    46,     9,   139,
     139,    83,   139,   209,   139,   139,   397,   283,   159,   160,
     161,   162,   163,   164,   165,   166,   297,   508,   294,   210,
     457,   293,   293,   459,   221,   398,   293,   463,     2,   504,
      88,    89,   191,   211,   342,   293,   210,   505,   531,   535,
     343,   167,   168,   541,   506,   488,   354,   490,   402,   351,
     140,   493,   554,   361,   363,   193,   317,   192,    87,   208,
     358,   169,   170,   362,   364,   365,   108,   357,   424,   432,
     293,   349,   460,   221,   339,   104,   106,   340,   222,   107,
      98,   516,   108,   513,   293,   210,   232,   556,   179,   180,
     181,   182,   183,   553,   124,   474,   416,   157,   513,   562,
     509,   558,   417,   476,   251,   360,   568,   390,   112,   478,
     479,     1,     2,   257,   258,   403,    96,   405,   256,   581,
     545,   197,   370,    91,   125,   378,    92,   159,   139,   136,
     560,   383,   384,   165,   166,   565,   137,   313,   289,   388,
     289,   289,   200,   572,   314,   392,   273,   576,   201,   202,
     579,   142,   341,   126,   287,   134,   251,   428,   584,   314,
     167,   168,   587,   301,   314,   135,   591,   113,   114,   115,
     116,   117,   118,   119,   595,   444,   446,   597,   425,   143,
     144,   500,   139,   139,   546,   427,   127,   602,   552,   561,
     120,   547,   431,   198,   138,   547,   547,   434,   199,   243,
     244,   245,   246,   247,   248,   573,   267,   443,   575,   139,
     577,   469,   547,   445,   253,   547,   331,   547,   355,   204,
     205,   316,   454,   356,   139,   345,   455,   456,   139,   287,
     458,   188,   521,   141,   462,   149,   150,   172,   465,   145,
     146,   147,   148,   468,   189,   113,   114,   115,   116,   117,
     118,   119,   179,   180,   181,   182,   183,   491,   492,   327,
     328,   367,    96,   532,   190,   263,   536,    91,   128,   379,
     139,   542,   213,   113,   114,   115,   116,   117,   118,   119,
     204,   279,   555,   557,   559,   219,   263,   194,   515,   105,
     105,   251,   212,   105,   396,   218,   128,   173,   174,   175,
     176,   195,   386,   179,   180,   181,   182,   183,   269,   334,
     411,   196,   413,   237,   238,   239,   240,   533,   380,   328,
     537,   241,   242,   235,   236,   543,   216,   217,   220,   426,
     226,   550,   223,   386,   177,   178,   179,   180,   181,   182,
     183,   563,   435,   564,   449,   291,   292,   224,   569,   225,
     227,   228,   229,    96,   230,   231,   252,   265,   578,   259,
     501,   262,   274,   582,   269,   275,   285,   585,   288,   298,
     286,   588,   305,    46,   315,   320,   300,   592,   322,   309,
     302,   303,   594,   304,   310,   323,   598,   151,   152,   153,
     154,   155,   156,   600,   318,   321,   324,   326,   344,   347,
     348,   498,   349,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,    12,
     350,   352,    13,    14,    15,    16,    17,    18,    19,   359,
     366,    20,   369,   371,  -168,  -168,  -168,  -168,    21,    22,
      23,    24,    25,   373,    26,   179,   180,   181,   182,   183,
     375,   387,   474,   382,   391,   394,  -176,   475,   395,   399,
     476,    27,   404,   477,   512,   406,   478,   479,    28,    29,
      30,    31,   179,   180,   181,   182,   183,   400,   407,   474,
      32,   408,   412,    33,   475,   415,   418,   476,   420,   566,
     477,   518,    34,   478,   479,   429,   430,   436,   433,   438,
     441,   437,    35,    36,   448,   450,   447,   451,    37,    38,
      39,    40,    41,  -177,  -215,    42,   464,    43,    44,    45,
     466,   461,   467,   473,    46,    13,    14,    15,    16,    17,
      18,    19,   472,   495,    20,   489,  -217,   487,   499,   502,
     494,    21,    22,    23,    24,    25,   497,    26,   179,   180,
     181,   182,   183,   503,   507,   474,   514,   517,   519,   520,
     475,   522,   523,   476,    27,   524,   477,   525,   526,   478,
     479,    28,    29,    30,    31,   527,   528,   529,   530,   534,
     538,   544,   539,    32,   551,   540,    33,   548,   393,   567,
     570,    85,   571,   574,    11,    34,    86,   121,   580,   583,
     589,   586,   590,   593,   422,    35,    36,   596,   599,   601,
     603,   123,    38,   368,   234,   233,   381,   100,    42,   385,
      43,    13,    14,    15,    16,    17,    18,    19,   423,   280,
      20,   264,   332,   372,   510,   335,   511,    21,    22,    23,
      24,    25,   414,    26,   410,   496,     0,     0,     0,   308,
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
      24,    25,   249,    26,    38,     0,     0,     0,    27,     0,
      42,     0,    43,     0,     0,    28,    29,    30,    31,     0,
      27,    13,    14,    15,    16,    93,    18,    28,    29,    30,
      31,     0,     0,    13,    14,    15,    16,    93,    18,    34,
      24,    25,     0,    26,   272,     0,     0,     0,     0,    35,
      36,    34,    24,    25,   281,    26,     0,     0,     0,     0,
      27,    35,    36,     0,   110,     0,     0,    28,    29,    30,
      31,     0,    27,    13,    14,    15,    16,    93,    18,    28,
      29,    30,    31,     0,     0,    13,    14,    15,    16,    93,
      18,    34,    24,    25,     0,    26,     0,     0,   346,     0,
       0,    35,    36,    34,    24,    25,   389,    26,     0,     0,
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
      19,    20,    21,    34,   167,   168,    25,    82,     3,   184,
     205,   227,   209,    26,    33,   231,   175,     7,    23,     7,
      32,   227,    32,    31,     7,   231,    53,    32,    31,    97,
     192,    99,    31,    31,     7,   406,   407,   105,     7,    31,
      31,   102,    31,    23,    31,    31,     7,   210,    53,    54,
      55,    56,    57,    58,    59,    60,   219,     7,    31,    39,
     431,     7,     7,   434,    27,    26,     7,   438,    75,    85,
      53,    98,    91,    53,    31,     7,    39,    93,    24,    24,
      37,    86,    87,    24,   100,   456,    98,   458,    98,   295,
      98,   462,    24,   309,   310,    98,   258,    95,    86,    98,
     306,   106,   107,   309,   310,   311,    98,    98,    95,    98,
       7,   101,    98,    27,   277,    27,    28,   279,    32,    31,
       7,   492,    98,   481,     7,    39,   139,    24,    78,    79,
      80,    81,    82,   537,     7,    85,    31,    23,   496,   543,
      90,    24,    37,    93,   157,   308,   550,   344,     7,    99,
     100,    74,    75,   172,   173,   361,   175,   363,   171,   563,
     531,    24,   321,    27,     7,   327,    30,    53,    31,    93,
     541,   333,   334,    59,    60,   546,   100,    24,   214,   342,
     216,   217,    97,   554,    31,   348,   199,   558,   103,   104,
     561,    33,    24,     7,   213,     7,   209,    24,   569,    31,
      86,    87,   573,   222,    31,     7,   577,    66,    67,    68,
      69,    70,    71,    72,   585,    24,    24,   588,   380,    35,
      36,     7,    31,    31,    24,   387,     7,   598,    24,    24,
      89,    31,   395,    26,     7,    31,    31,   400,    31,   151,
     152,   153,   154,   155,   156,    24,    28,   409,    24,    31,
      24,   446,    31,   412,     7,    31,   269,    31,    26,    62,
      63,    28,   424,    31,    31,    28,   429,   430,    31,   288,
     433,     7,     7,    34,   437,    41,    42,    27,   440,    37,
      38,    39,    40,   445,     7,    66,    67,    68,    69,    70,
      71,    72,    78,    79,    80,    81,    82,   459,   461,    10,
      11,   314,   321,   519,    98,   480,   522,    27,    89,   328,
      31,   527,    27,    66,    67,    68,    69,    70,    71,    72,
      62,    63,   538,   539,   540,    94,   501,    98,   490,    27,
      28,   344,    23,    31,   353,    23,    89,    15,    16,    17,
      18,    98,   337,    78,    79,    80,    81,    82,    13,    14,
     369,    98,   371,   145,   146,   147,   148,   520,    10,    11,
     523,   149,   150,   143,   144,   528,   122,   123,    25,   382,
       7,   534,    27,   368,    76,    77,    78,    79,    80,    81,
      82,   544,   401,   545,   415,   216,   217,    27,   551,    27,
      23,    94,     7,   412,     7,    23,     7,     7,   560,    25,
     475,    23,    98,   565,    13,    98,     7,   570,    27,     7,
      24,   574,    98,   105,    88,    15,    28,   579,     7,    23,
      28,    28,   584,    28,    23,     7,   589,    43,    44,    45,
      46,    47,    48,   595,    26,    29,    39,    98,    23,    27,
      94,   472,   101,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,     0,
      31,    24,     3,     4,     5,     6,     7,     8,     9,    24,
      24,    12,    23,    30,    15,    16,    17,    18,    19,    20,
      21,    22,    23,     7,    25,    78,    79,    80,    81,    82,
      30,     7,    85,    31,    28,    24,    98,    90,    94,    24,
      93,    42,    24,    96,    97,    24,    99,   100,    49,    50,
      51,    52,    78,    79,    80,    81,    82,    94,    24,    85,
      61,    65,    29,    64,    90,    30,     7,    93,    98,   548,
      96,    97,    73,    99,   100,    94,    94,    24,    94,    24,
       7,    94,    83,    84,     7,     7,    98,    31,    89,    90,
      91,    92,    93,    98,    97,    96,    98,    98,    99,   100,
      31,    94,    98,     7,   105,     3,     4,     5,     6,     7,
       8,     9,    30,     7,    12,    98,    97,    97,     7,     7,
      98,    19,    20,    21,    22,    23,    97,    25,    78,    79,
      80,    81,    82,     7,     7,    85,    98,    98,    23,    94,
      90,    23,    94,    93,    42,     7,    96,     7,     7,    99,
     100,    49,    50,    51,    52,    23,    94,     7,    98,    94,
      23,    94,    23,    61,    94,    23,    64,    32,     7,    98,
      94,     5,    98,    94,     2,    73,     5,    34,    98,    98,
      94,    98,    98,    98,   377,    83,    84,    98,    98,    98,
      98,    34,    90,   319,   142,   141,   329,    23,    96,    97,
      98,     3,     4,     5,     6,     7,     8,     9,   377,   206,
      12,   184,   269,   323,   480,   270,   480,    19,    20,    21,
      22,    23,   372,    25,    26,   470,    -1,    -1,    -1,   228,
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
       0,    74,    75,   109,   110,   111,   112,   114,   115,     7,
     113,   113,     0,     3,     4,     5,     6,     7,     8,     9,
      12,    19,    20,    21,    22,    23,    25,    42,    49,    50,
      51,    52,    61,    64,    73,    83,    84,    89,    90,    91,
      92,    93,    96,    98,    99,   100,   105,   116,   126,   127,
     131,   132,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   150,   151,   154,   155,   160,   161,
     162,   163,   165,   167,   168,   169,   173,   174,   179,   200,
     201,   203,   204,   102,   123,   112,   114,   115,    53,    98,
       7,    27,    30,     7,   131,   131,   131,   164,     7,   166,
     166,   131,   132,   149,   140,   142,   140,   140,    98,   206,
      98,   131,     7,    66,    67,    68,    69,    70,    71,    72,
      89,   117,   118,   120,     7,     7,     7,     7,    89,   117,
     118,   119,   120,   121,     7,     7,    93,   100,     7,    31,
      98,    34,    33,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    23,    32,    53,
      54,    55,    56,    57,    58,    59,    60,    86,    87,   106,
     107,   133,    27,    15,    16,    17,    18,    76,    77,    78,
      79,    80,    81,    82,   184,   185,   186,   197,     7,     7,
      98,   131,    95,    98,    98,    98,    98,    24,    26,    31,
      97,   103,   104,   205,    62,    63,   170,   171,    98,    23,
      39,    53,    23,    27,   146,   147,   146,   146,    23,    94,
      25,    27,    32,    27,    27,    27,     7,    23,    94,     7,
       7,    23,   132,   135,   136,   137,   137,   138,   138,   138,
     138,   139,   139,   140,   140,   140,   140,   140,   140,    24,
     129,   132,     7,     7,   121,   121,   132,   131,   131,    25,
     175,   164,    23,   185,   186,     7,   124,    28,   206,    13,
     156,   157,    26,   132,    98,    98,   207,   172,   175,    63,
     171,    24,   129,   121,   122,     7,    24,   131,    27,   147,
     148,   148,   148,     7,    31,   128,   193,   121,     7,   202,
      28,   131,    28,    28,    28,    98,   128,   193,   204,    23,
      23,   128,   193,    24,    31,    88,    28,   206,    26,   176,
      15,    29,     7,     7,    39,   178,    98,    10,    11,   152,
     153,   132,   149,   159,    14,   157,   158,   130,   150,   121,
     206,    24,    31,    37,    23,    28,    28,    27,    94,   101,
      31,   193,    24,    32,    98,    26,    31,    98,   193,    24,
     121,   128,   193,   128,   193,   193,    24,   132,   130,    23,
     164,    30,   178,     7,   177,    30,   187,   125,   206,   131,
      10,   153,    31,   206,   206,    97,   150,     7,   121,    24,
     129,    28,   121,     7,    24,    94,   131,     7,    26,    24,
      94,    32,    98,   193,    24,   193,    24,    24,    65,   194,
      26,   131,    29,   131,   187,    30,    31,    37,     7,   188,
      98,    97,   126,   179,    95,   206,   132,   206,    24,    94,
      94,   121,    98,    94,   121,   131,    24,    94,    24,   194,
     194,     7,   195,   206,    24,   164,    24,    98,     7,   118,
       7,    31,   180,   182,   206,   121,   121,   194,   121,   194,
      98,    94,   121,   194,    98,   206,    31,    98,   206,   175,
     181,   183,    30,     7,    85,    90,    93,    96,    99,   100,
     184,   189,   190,   191,   192,   196,   199,    97,   194,    98,
     194,   206,   121,   194,    98,     7,   189,    97,   118,     7,
       7,   184,     7,     7,    85,    93,   100,     7,     7,    90,
     192,   196,    97,   190,    98,   206,   194,    98,    97,    23,
      94,     7,    23,    94,     7,     7,     7,    23,    94,     7,
      98,    24,   128,   121,    94,    24,   128,   121,    23,    23,
      23,    24,   128,   121,    94,   194,    24,    31,    32,   198,
     121,    94,    24,   198,    24,   128,    24,   128,    24,   128,
     194,    24,   198,   121,   206,   194,   131,    98,   198,   121,
      94,    98,   194,    24,    94,    24,   194,    24,   206,   194,
      98,   198,   206,    98,   194,   121,    98,   194,   121,    94,
      98,   194,   206,    98,   206,   194,    98,   194,   121,    98,
     206,    98,   194,    98
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
#line 109 "diksam.y"
    {
            dkc_set_require_and_rename_list(NULL, NULL);
        }
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 113 "diksam.y"
    {
            dkc_set_require_and_rename_list((yyvsp[(1) - (2)].require_list), (yyvsp[(2) - (2)].rename_list));
        }
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 117 "diksam.y"
    {
            dkc_set_require_and_rename_list((yyvsp[(1) - (1)].require_list), NULL);
        }
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 121 "diksam.y"
    {
            dkc_set_require_and_rename_list(NULL, (yyvsp[(1) - (1)].rename_list));
        }
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 125 "diksam.y"
    {
            dkc_set_require_and_rename_list(NULL, NULL);
		}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 132 "diksam.y"
    {
            (yyval.require_list) = dkc_chain_require_list((yyvsp[(1) - (2)].require_list), (yyvsp[(2) - (2)].require_list));
        }
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 138 "diksam.y"
    {
            (yyval.require_list) = dkc_create_require_list((yyvsp[(2) - (3)].package_name));
        }
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 144 "diksam.y"
    {
            (yyval.package_name) = dkc_create_package_name((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 148 "diksam.y"
    {
            (yyval.package_name) = dkc_chain_package_name((yyvsp[(1) - (3)].package_name), (yyvsp[(3) - (3)].identifier));
        }
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 155 "diksam.y"
    {
            (yyval.rename_list) = dkc_chain_rename_list((yyvsp[(1) - (2)].rename_list), (yyvsp[(2) - (2)].rename_list));
        }
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 161 "diksam.y"
    {
            (yyval.rename_list) = dkc_create_rename_list((yyvsp[(2) - (4)].package_name), (yyvsp[(3) - (4)].identifier));
        }
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 169 "diksam.y"
    {
            DKC_Compiler *compiler = dkc_get_current_compiler();

            compiler->statement_list
                = dkc_chain_statement_list(compiler->statement_list, (yyvsp[(1) - (1)].statement));
        }
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 181 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_VOID_TYPE;
        }
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 185 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_BOOLEAN_TYPE;
        }
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 189 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_INT_TYPE;
        }
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 193 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_DOUBLE_TYPE;
        }
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 197 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_STRING_TYPE;
        }
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 201 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_VARIENT_TYPE;
        }
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 205 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_NATIVE_POINTER_TYPE;
        }
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 209 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_DELEGATE_TYPE;
        }
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 215 "diksam.y"
    {
            (yyval.type_specifier) = dkc_create_identifier_type_specifier((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 221 "diksam.y"
    {
            TypeSpecifier *basic_type
                = dkc_create_type_specifier((yyvsp[(1) - (3)].basic_type_specifier));
            (yyval.type_specifier) = dkc_create_array_type_specifier(basic_type);
        }
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 227 "diksam.y"
    {
            TypeSpecifier *identifier_type
                = dkc_create_identifier_type_specifier((yyvsp[(1) - (3)].identifier));
            (yyval.type_specifier) = dkc_create_array_type_specifier(identifier_type);
        }
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 233 "diksam.y"
    {
            (yyval.type_specifier) = dkc_create_array_type_specifier((yyvsp[(1) - (3)].type_specifier));
        }
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 237 "diksam.y"
    {
			(yyval.type_specifier) = dkc_create_array_type_specifier((yyvsp[(1) - (3)].type_specifier));
		}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 243 "diksam.y"
    {//fix-me : shift/reduce
			(yyval.type_specifier)= dkc_create_template_type_specifier((yyvsp[(1) - (4)].identifier),(yyvsp[(3) - (4)].template));
		}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 249 "diksam.y"
    {
                    (yyval.type_specifier) = dkc_create_type_specifier((yyvsp[(1) - (1)].basic_type_specifier));
        }
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 259 "diksam.y"
    {
			(yyval.template)=dkc_create_template_list((yyvsp[(1) - (1)].type_specifier));
		}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 263 "diksam.y"
    {
            (yyval.template) = dkc_chain_template_list((yyvsp[(1) - (3)].template), (yyvsp[(3) - (3)].type_specifier));
        }
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 270 "diksam.y"
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

  case 44:

/* Line 1455 of yacc.c  */
#line 280 "diksam.y"
    {
			BcGetCurrentCompilerContext()->isLib=0;
		}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 292 "diksam.y"
    {
            dkc_function_define((yyvsp[(9) - (11)].type_specifier), (yyvsp[(3) - (11)].identifier), (yyvsp[(5) - (11)].parameter_list), (yyvsp[(10) - (11)].exception_list), NULL,(yyvsp[(6) - (11)].intval));
        }
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 296 "diksam.y"
    {
            dkc_function_define((yyvsp[(8) - (10)].type_specifier), (yyvsp[(3) - (10)].identifier), NULL, (yyvsp[(9) - (10)].exception_list), NULL,(yyvsp[(5) - (10)].intval));
        }
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 300 "diksam.y"
    {
            dkc_function_define(0, (yyvsp[(3) - (9)].identifier), (yyvsp[(5) - (9)].parameter_list), (yyvsp[(8) - (9)].exception_list), NULL,(yyvsp[(6) - (9)].intval));
        }
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 304 "diksam.y"
    {
			//printf("lib:%s\n",BcGetCurrentCompilerContext()->libname);
            dkc_function_define(0, (yyvsp[(3) - (8)].identifier), NULL, (yyvsp[(7) - (8)].exception_list), NULL,(yyvsp[(5) - (8)].intval));
        }
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 311 "diksam.y"
    {
            dkc_function_define((yyvsp[(8) - (10)].type_specifier), (yyvsp[(2) - (10)].identifier), (yyvsp[(4) - (10)].parameter_list), (yyvsp[(9) - (10)].exception_list), (yyvsp[(10) - (10)].block),(yyvsp[(5) - (10)].intval));
        }
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 315 "diksam.y"
    {
            dkc_function_define((yyvsp[(7) - (9)].type_specifier), (yyvsp[(2) - (9)].identifier), NULL, (yyvsp[(8) - (9)].exception_list), (yyvsp[(9) - (9)].block),(yyvsp[(4) - (9)].intval));
        }
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 319 "diksam.y"
    { //modified
            dkc_function_define(0, (yyvsp[(2) - (8)].identifier), (yyvsp[(4) - (8)].parameter_list), (yyvsp[(7) - (8)].exception_list), (yyvsp[(8) - (8)].block),(yyvsp[(5) - (8)].intval));
        }
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 323 "diksam.y"
    {
            dkc_function_define(0, (yyvsp[(2) - (7)].identifier), NULL, (yyvsp[(6) - (7)].exception_list), (yyvsp[(7) - (7)].block),(yyvsp[(4) - (7)].intval));
        }
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 330 "diksam.y"
    {
            (yyval.parameter_list) = dkc_create_parameter((yyvsp[(3) - (3)].type_specifier), (yyvsp[(1) - (3)].identifier));
        }
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 334 "diksam.y"
    {
            (yyval.parameter_list) = dkc_chain_parameter((yyvsp[(1) - (5)].parameter_list), (yyvsp[(5) - (5)].type_specifier), (yyvsp[(3) - (5)].identifier));
        }
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 340 "diksam.y"
    {
            (yyval.argument_list) = dkc_create_argument_list((yyvsp[(1) - (1)].expression));
        }
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 344 "diksam.y"
    {
            (yyval.argument_list) = dkc_chain_argument_list((yyvsp[(1) - (3)].argument_list), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 350 "diksam.y"
    {
            (yyval.statement_list) = dkc_create_statement_list((yyvsp[(1) - (1)].statement));
        }
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 354 "diksam.y"
    {
            (yyval.statement_list) = dkc_chain_statement_list((yyvsp[(1) - (2)].statement_list), (yyvsp[(2) - (2)].statement));
        }
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 361 "diksam.y"
    {
            (yyval.expression) = dkc_create_comma_expression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 368 "diksam.y"
    {
            (yyval.expression) = dkc_create_assign_expression((yyvsp[(1) - (3)].expression), (yyvsp[(2) - (3)].assignment_operator), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 374 "diksam.y"
    {
            (yyval.assignment_operator) = NORMAL_ASSIGN;
        }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 378 "diksam.y"
    {
            (yyval.assignment_operator) = ADD_ASSIGN;
        }
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 382 "diksam.y"
    {
            (yyval.assignment_operator) = SUB_ASSIGN;
        }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 386 "diksam.y"
    {
            (yyval.assignment_operator) = ATM_ADD_ASSIGN;
        }
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 390 "diksam.y"
    {
            (yyval.assignment_operator) = ATM_SUB_ASSIGN;
        }
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 394 "diksam.y"
    {
            (yyval.assignment_operator) = MUL_ASSIGN;
        }
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 398 "diksam.y"
    {
            (yyval.assignment_operator) = DIV_ASSIGN;
        }
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 402 "diksam.y"
    {
            (yyval.assignment_operator) = MOD_ASSIGN;
        }
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 409 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(LOGICAL_OR_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 416 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(LOGICAL_AND_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 423 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(EQ_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 427 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(NE_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 434 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(GT_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 438 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(GE_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 442 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(LT_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 446 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(LE_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 453 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(ADD_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 457 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(SUB_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 464 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(MUL_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 468 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(DIV_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 472 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(MOD_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 476 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(BIT_AND_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 480 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(BIT_OR_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 484 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(BIT_XOR_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 491 "diksam.y"
    {
            (yyval.expression) = dkc_create_minus_expression((yyvsp[(2) - (2)].expression));
        }
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 495 "diksam.y"
    {
            (yyval.expression) = dkc_create_logical_not_expression((yyvsp[(2) - (2)].expression));
        }
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 499 "diksam.y"
    {
            (yyval.expression) = dkc_create_bit_not_expression((yyvsp[(2) - (2)].expression));
        }
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 506 "diksam.y"
    {
            (yyval.expression) = dkc_create_incdec_expression((yyvsp[(1) - (2)].expression), INCREMENT_EXPRESSION);
        }
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 510 "diksam.y"
    {
            (yyval.expression) = dkc_create_incdec_expression((yyvsp[(1) - (2)].expression), DECREMENT_EXPRESSION);
        }
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 514 "diksam.y"
    {
            (yyval.expression) = dkc_create_instanceof_expression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].type_specifier));
        }
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 522 "diksam.y"
    {
            (yyval.expression) = dkc_create_identifier_expression((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 526 "diksam.y"
    {
			(yyval.expression)=BcCreateAutoExpression((yyvsp[(1) - (1)].identifier));
		}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 532 "diksam.y"
    {
            (yyval.expression) = dkc_create_index_expression((yyvsp[(1) - (4)].expression), (yyvsp[(3) - (4)].expression));
        }
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 536 "diksam.y"
    {
            Expression *identifier = dkc_create_identifier_expression((yyvsp[(1) - (4)].identifier));
            (yyval.expression) = dkc_create_index_expression(identifier, (yyvsp[(3) - (4)].expression));
        }
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 541 "diksam.y"
    {
            (yyval.expression) = dkc_create_member_expression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].identifier));
        }
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 545 "diksam.y"
    {
            (yyval.expression) = dkc_create_function_call_expression((yyvsp[(1) - (4)].expression), (yyvsp[(3) - (4)].argument_list));
        }
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 549 "diksam.y"
    {
            (yyval.expression) = dkc_create_function_call_expression((yyvsp[(1) - (3)].expression), NULL);
        }
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 553 "diksam.y"
    {
            (yyval.expression) = (yyvsp[(2) - (3)].expression);
        }
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 557 "diksam.y"
    {
            (yyval.expression) = dkc_create_down_cast_expression((yyvsp[(1) - (4)].expression), (yyvsp[(3) - (4)].type_specifier));
        }
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 565 "diksam.y"
    {
            (yyval.expression) = dkc_create_boolean_expression(DVM_TRUE);
        }
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 569 "diksam.y"
    {
            (yyval.expression) = dkc_create_boolean_expression(DVM_FALSE);
        }
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 573 "diksam.y"
    {
            (yyval.expression) = dkc_create_null_expression();
        }
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 578 "diksam.y"
    {
            (yyval.expression) = dkc_create_this_expression();
        }
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 582 "diksam.y"
    {
            (yyval.expression) = dkc_create_super_expression();
        }
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 586 "diksam.y"
    {
			(yyval.expression) = dkc_create_new_delegate_expression();
		}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 590 "diksam.y"
    {
            (yyval.expression) = dkc_create_new_expression((yyvsp[(2) - (4)].identifier), NULL, NULL);
        }
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 594 "diksam.y"
    {
            (yyval.expression) = dkc_create_new_expression((yyvsp[(2) - (5)].identifier), NULL, (yyvsp[(4) - (5)].argument_list));
        }
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 598 "diksam.y"
    {
            (yyval.expression) = dkc_create_new_expression((yyvsp[(2) - (6)].identifier), (yyvsp[(4) - (6)].identifier), NULL);
        }
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 602 "diksam.y"
    {
            (yyval.expression) = dkc_create_new_expression((yyvsp[(2) - (7)].identifier), (yyvsp[(4) - (7)].identifier), (yyvsp[(6) - (7)].argument_list));
        }
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 608 "diksam.y"
    {
            (yyval.expression) = dkc_create_array_literal_expression((yyvsp[(2) - (3)].expression_list));
        }
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 612 "diksam.y"
    {
            (yyval.expression) = dkc_create_array_literal_expression((yyvsp[(2) - (4)].expression_list));
        }
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 618 "diksam.y"
    {
            (yyval.expression) = dkc_create_basic_array_creation((yyvsp[(2) - (3)].basic_type_specifier), (yyvsp[(3) - (3)].array_dimension), NULL);
        }
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 622 "diksam.y"
    {
            (yyval.expression) = dkc_create_basic_array_creation((yyvsp[(2) - (4)].basic_type_specifier), (yyvsp[(3) - (4)].array_dimension), (yyvsp[(4) - (4)].array_dimension));
        }
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 626 "diksam.y"
    {
            (yyval.expression) = dkc_create_class_array_creation((yyvsp[(2) - (3)].type_specifier), (yyvsp[(3) - (3)].array_dimension), NULL);
        }
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 631 "diksam.y"
    {
            (yyval.expression) = dkc_create_class_array_creation((yyvsp[(2) - (4)].type_specifier), (yyvsp[(3) - (4)].array_dimension), (yyvsp[(4) - (4)].array_dimension));
        }
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 635 "diksam.y"
    {
            (yyval.expression) = dkc_create_class_array_creation((yyvsp[(2) - (3)].type_specifier), (yyvsp[(3) - (3)].array_dimension), NULL);
        }
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 639 "diksam.y"
    {
            (yyval.expression) = dkc_create_class_array_creation((yyvsp[(2) - (4)].type_specifier), (yyvsp[(3) - (4)].array_dimension), (yyvsp[(4) - (4)].array_dimension));
        }
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 646 "diksam.y"
    {
            (yyval.array_dimension) = dkc_chain_array_dimension((yyvsp[(1) - (2)].array_dimension), (yyvsp[(2) - (2)].array_dimension));
        }
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 652 "diksam.y"
    {
            (yyval.array_dimension) = dkc_create_array_dimension((yyvsp[(2) - (3)].expression));
        }
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 658 "diksam.y"
    {
            (yyval.array_dimension) = dkc_create_array_dimension(NULL);
        }
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 662 "diksam.y"
    {
            (yyval.array_dimension) = dkc_chain_array_dimension((yyvsp[(1) - (3)].array_dimension),
                                           dkc_create_array_dimension(NULL));
        }
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 669 "diksam.y"
    {
            (yyval.expression_list) = NULL;
        }
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 673 "diksam.y"
    {
            (yyval.expression_list) = dkc_create_expression_list((yyvsp[(1) - (1)].expression));
        }
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 677 "diksam.y"
    {
            (yyval.expression_list) = dkc_chain_expression_list((yyvsp[(1) - (3)].expression_list), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 683 "diksam.y"
    {
          (yyval.statement) = dkc_create_expression_statement((yyvsp[(1) - (2)].expression));
        }
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 699 "diksam.y"
    {/*empty line*/
			(yyval.statement)=0;
		}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 705 "diksam.y"
    {
            (yyval.statement) = dkc_create_if_statement((yyvsp[(2) - (4)].expression), (yyvsp[(4) - (4)].block), NULL, NULL);
        }
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 709 "diksam.y"
    {
			//printf("IF-ELSE %d\n",dkc_get_current_compiler()->current_line_number);
            (yyval.statement) = dkc_create_if_statement((yyvsp[(2) - (6)].expression), (yyvsp[(4) - (6)].block), NULL, (yyvsp[(6) - (6)].block));
        }
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 714 "diksam.y"
    {
            (yyval.statement) = dkc_create_if_statement((yyvsp[(2) - (5)].expression), (yyvsp[(4) - (5)].block), (yyvsp[(5) - (5)].elsif), NULL);
        }
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 718 "diksam.y"
    {
            (yyval.statement) = dkc_create_if_statement((yyvsp[(2) - (7)].expression), (yyvsp[(4) - (7)].block), (yyvsp[(5) - (7)].elsif), (yyvsp[(7) - (7)].block));
        }
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 725 "diksam.y"
    {
            (yyval.elsif) = dkc_chain_elsif_list((yyvsp[(1) - (2)].elsif), (yyvsp[(2) - (2)].elsif));
        }
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 731 "diksam.y"
    {
            (yyval.elsif) = dkc_create_elsif((yyvsp[(2) - (4)].expression), (yyvsp[(4) - (4)].block));
        }
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 737 "diksam.y"
    {
            (yyval.identifier) = NULL;
        }
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 741 "diksam.y"
    {
            (yyval.identifier) = (yyvsp[(1) - (2)].identifier);
        }
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 747 "diksam.y"
    {
            (yyval.statement) = dkc_create_switch_statement((yyvsp[(2) - (5)].expression), (yyvsp[(4) - (5)].case_list), (yyvsp[(5) - (5)].block));
        }
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 754 "diksam.y"
    {
            (yyval.case_list) = dkc_chain_case((yyvsp[(1) - (2)].case_list), (yyvsp[(2) - (2)].case_list));
        }
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 760 "diksam.y"
    {
            (yyval.case_list) = dkc_create_one_case((yyvsp[(2) - (3)].expression_list), (yyvsp[(3) - (3)].block));
        }
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 766 "diksam.y"
    {
            (yyval.block) = NULL;
        }
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 770 "diksam.y"
    {
            (yyval.block) = (yyvsp[(2) - (2)].block);
        }
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 776 "diksam.y"
    {
            (yyval.expression_list) = dkc_create_expression_list((yyvsp[(1) - (1)].expression));
        }
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 780 "diksam.y"
    {
            (yyval.expression_list) = dkc_chain_expression_list((yyvsp[(1) - (3)].expression_list), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 786 "diksam.y"
    {
            (yyval.statement) = dkc_create_while_statement((yyvsp[(1) - (4)].identifier), (yyvsp[(3) - (4)].expression), (yyvsp[(4) - (4)].block));
        }
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 792 "diksam.y"
    {
            (yyval.statement) = dkc_create_for_statement((yyvsp[(1) - (8)].identifier), (yyvsp[(3) - (8)].expression), (yyvsp[(5) - (8)].expression), (yyvsp[(7) - (8)].expression), (yyvsp[(8) - (8)].block));
        }
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 798 "diksam.y"
    {
            (yyval.statement) = dkc_create_do_while_statement((yyvsp[(1) - (8)].identifier), (yyvsp[(3) - (8)].block), (yyvsp[(6) - (8)].expression));
        }
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 804 "diksam.y"
    {
            (yyval.statement) = dkc_create_foreach_statement((yyvsp[(1) - (8)].identifier), (yyvsp[(4) - (8)].identifier), (yyvsp[(6) - (8)].expression), (yyvsp[(8) - (8)].block));
        }
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 810 "diksam.y"
    {
            (yyval.expression) = NULL;
        }
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 817 "diksam.y"
    {
            (yyval.statement) = dkc_create_return_statement((yyvsp[(2) - (3)].expression));
        }
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 823 "diksam.y"
    {
            (yyval.identifier) = NULL;
        }
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 830 "diksam.y"
    {
            (yyval.statement) = dkc_create_break_statement((yyvsp[(2) - (3)].identifier));
        }
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 836 "diksam.y"
    {
            (yyval.statement) = dkc_create_continue_statement((yyvsp[(2) - (3)].identifier));
        }
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 842 "diksam.y"
    {
            (yyval.statement) = dkc_create_try_statement((yyvsp[(2) - (5)].block), (yyvsp[(3) - (5)].catch_clause), (yyvsp[(5) - (5)].block));
        }
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 846 "diksam.y"
    {
            (yyval.statement) = dkc_create_try_statement((yyvsp[(2) - (4)].block), NULL, (yyvsp[(4) - (4)].block));
        }
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 850 "diksam.y"
    {
            (yyval.statement) = dkc_create_try_statement((yyvsp[(2) - (3)].block), (yyvsp[(3) - (3)].catch_clause), NULL);
        }
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 857 "diksam.y"
    {
            (yyval.catch_clause) = dkc_chain_catch_list((yyvsp[(1) - (2)].catch_clause), (yyvsp[(2) - (2)].catch_clause));
        }
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 863 "diksam.y"
    {
            (yyval.catch_clause) = dkc_start_catch_clause();
        }
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 867 "diksam.y"
    {
            (yyval.catch_clause) = dkc_end_catch_clause((yyvsp[(2) - (5)].catch_clause), (yyvsp[(3) - (5)].type_specifier), (yyvsp[(4) - (5)].identifier), (yyvsp[(5) - (5)].block));
        }
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 873 "diksam.y"
    {
            (yyval.statement) = dkc_create_throw_statement((yyvsp[(2) - (3)].expression));
        }
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 877 "diksam.y"
    {
            (yyval.statement) = dkc_create_throw_statement(NULL);
        }
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 883 "diksam.y"
    {
            (yyval.statement) = dkc_create_declaration_statement(DVM_FALSE, (yyvsp[(5) - (6)].type_specifier), (yyvsp[(2) - (6)].identifier), NULL,(yyvsp[(4) - (6)].intval));
        }
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 887 "diksam.y"
    {
            (yyval.statement) = dkc_create_declaration_statement(DVM_FALSE, (yyvsp[(5) - (8)].type_specifier), (yyvsp[(2) - (8)].identifier), (yyvsp[(7) - (8)].expression),(yyvsp[(4) - (8)].intval));
        }
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 891 "diksam.y"
    {
            (yyval.statement) = dkc_create_declaration_statement(DVM_FALSE, (yyvsp[(4) - (5)].type_specifier), (yyvsp[(2) - (5)].identifier), NULL,DVM_FALSE);
        }
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 895 "diksam.y"
    {
            (yyval.statement) = dkc_create_declaration_statement(DVM_TRUE, (yyvsp[(4) - (7)].type_specifier), (yyvsp[(2) - (7)].identifier), (yyvsp[(6) - (7)].expression),DVM_FALSE);
        }
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 901 "diksam.y"
    {
            (yyval.block) = dkc_open_block(0);
        }
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 905 "diksam.y"
    {
            (yyval.block) = dkc_close_block((yyvsp[(2) - (4)].block), (yyvsp[(3) - (4)].statement_list));
        }
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 909 "diksam.y"
    {
            Block *empty_block = dkc_open_block(0);
            (yyval.block) = dkc_close_block(empty_block, NULL);
        }
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 916 "diksam.y"
    {
            (yyval.template_def) = dkc_create_template_declare_list((yyvsp[(1) - (1)].identifier),NULL);
        }
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 920 "diksam.y"
    {
            (yyval.template_def) = dkc_chain_template_declare_list((yyvsp[(1) - (3)].template_def), (yyvsp[(3) - (3)].identifier),NULL);
        }
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 924 "diksam.y"
    {
            (yyval.template_def) = dkc_create_template_declare_list((yyvsp[(1) - (3)].identifier),(yyvsp[(3) - (3)].type_specifier));
        }
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 928 "diksam.y"
    {
            (yyval.template_def) = dkc_chain_template_declare_list((yyvsp[(1) - (5)].template_def), (yyvsp[(3) - (5)].identifier) ,(yyvsp[(5) - (5)].type_specifier));
        }
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 934 "diksam.y"
    {
			(yyval.template_def)=(yyvsp[(2) - (3)].template_def);
		}
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 938 "diksam.y"
    {(yyval.template_def)=NULL;}
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 943 "diksam.y"
    {
            dkc_start_class_definition((yyvsp[(1) - (6)].intval),NULL, (yyvsp[(2) - (6)].class_or_interface), (yyvsp[(3) - (6)].identifier),(yyvsp[(4) - (6)].template_def), (yyvsp[(5) - (6)].extends_list));
        }
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 947 "diksam.y"
    {
            dkc_class_define((yyvsp[(8) - (9)].member_declaration));
        }
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 952 "diksam.y"
    {
            dkc_start_class_definition((yyvsp[(1) - (7)].intval),&(yyvsp[(2) - (7)].class_or_member_modifier), (yyvsp[(3) - (7)].class_or_interface), (yyvsp[(4) - (7)].identifier),(yyvsp[(5) - (7)].template_def), (yyvsp[(6) - (7)].extends_list));
        }
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 955 "diksam.y"
    {
            dkc_class_define((yyvsp[(9) - (10)].member_declaration));
        }
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 959 "diksam.y"
    {
            dkc_start_class_definition((yyvsp[(1) - (6)].intval),NULL, (yyvsp[(2) - (6)].class_or_interface), (yyvsp[(3) - (6)].identifier),(yyvsp[(4) - (6)].template_def), (yyvsp[(5) - (6)].extends_list));
        }
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 963 "diksam.y"
    {
            dkc_class_define(NULL);
        }
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 968 "diksam.y"
    {
            dkc_start_class_definition((yyvsp[(1) - (7)].intval),&(yyvsp[(2) - (7)].class_or_member_modifier), (yyvsp[(3) - (7)].class_or_interface), (yyvsp[(4) - (7)].identifier),(yyvsp[(5) - (7)].template_def), (yyvsp[(6) - (7)].extends_list));
        }
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 972 "diksam.y"
    {
            dkc_class_define(NULL);
        }
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 979 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_chain_class_or_member_modifier((yyvsp[(1) - (2)].class_or_member_modifier), (yyvsp[(2) - (2)].class_or_member_modifier));
        }
    break;

  case 222:

/* Line 1455 of yacc.c  */
#line 986 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(VIRTUAL_MODIFIER);
        }
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 990 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(OVERRIDE_MODIFIER);
        }
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 994 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(ABSTRACT_MODIFIER);
        }
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 1000 "diksam.y"
    {
            (yyval.class_or_interface) = DVM_CLASS_DEFINITION;
        }
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 1004 "diksam.y"
    {
            (yyval.class_or_interface) = DVM_INTERFACE_DEFINITION;
        }
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 1010 "diksam.y"
    {
            (yyval.extends_list) = NULL;
        }
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 1014 "diksam.y"
    {
            (yyval.extends_list) = (yyvsp[(2) - (2)].extends_list);
        }
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 1020 "diksam.y"
    {
            (yyval.extends_list) = dkc_create_extends_list((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 1024 "diksam.y"
    {
            (yyval.extends_list) = dkc_chain_extends_list((yyvsp[(1) - (3)].extends_list), (yyvsp[(3) - (3)].identifier));
        }
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 1031 "diksam.y"
    {
            (yyval.member_declaration) = dkc_chain_member_declaration((yyvsp[(1) - (2)].member_declaration), (yyvsp[(2) - (2)].member_declaration));
        }
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 1041 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_method_member(NULL, (yyvsp[(1) - (1)].function_definition), DVM_FALSE);
        }
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 1045 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_method_member(&(yyvsp[(1) - (2)].class_or_member_modifier), (yyvsp[(2) - (2)].function_definition), DVM_FALSE);
        }
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 1049 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_method_member(NULL, (yyvsp[(1) - (1)].function_definition), DVM_TRUE);
        }
    break;

  case 238:

/* Line 1455 of yacc.c  */
#line 1053 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_method_member(&(yyvsp[(1) - (2)].class_or_member_modifier), (yyvsp[(2) - (2)].function_definition), DVM_TRUE);
        }
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 1059 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define((yyvsp[(7) - (9)].type_specifier), (yyvsp[(2) - (9)].identifier), (yyvsp[(4) - (9)].parameter_list), (yyvsp[(8) - (9)].exception_list), (yyvsp[(9) - (9)].block));
        }
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 1063 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define((yyvsp[(6) - (8)].type_specifier), (yyvsp[(2) - (8)].identifier), NULL, (yyvsp[(7) - (8)].exception_list), (yyvsp[(8) - (8)].block));
        }
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 1067 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define((yyvsp[(8) - (10)].type_specifier), (yyvsp[(3) - (10)].identifier), (yyvsp[(5) - (10)].parameter_list), (yyvsp[(9) - (10)].exception_list), NULL);
        }
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 1071 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define((yyvsp[(7) - (9)].type_specifier), (yyvsp[(3) - (9)].identifier), NULL, (yyvsp[(8) - (9)].exception_list), NULL);
        }
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 1075 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define(0, (yyvsp[(2) - (7)].identifier), (yyvsp[(4) - (7)].parameter_list), (yyvsp[(6) - (7)].exception_list), (yyvsp[(7) - (7)].block));
        }
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 1079 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define(0, (yyvsp[(2) - (6)].identifier), NULL, (yyvsp[(5) - (6)].exception_list), (yyvsp[(6) - (6)].block));
        }
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 1083 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define(0, (yyvsp[(3) - (8)].identifier), (yyvsp[(5) - (8)].parameter_list), (yyvsp[(7) - (8)].exception_list), NULL);
        }
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 1087 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define(0, (yyvsp[(3) - (7)].identifier), NULL, (yyvsp[(6) - (7)].exception_list), NULL);
        }
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 1093 "diksam.y"
    {
			(yyval.intval)=0;
		}
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 1097 "diksam.y"
    {
			(yyval.intval)=1;
		}
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 1103 "diksam.y"
    {
            (yyval.exception_list) = NULL;
        }
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 1107 "diksam.y"
    {
            (yyval.exception_list) = (yyvsp[(2) - (2)].exception_list);
        }
    break;

  case 251:

/* Line 1455 of yacc.c  */
#line 1113 "diksam.y"
    {
            (yyval.exception_list) = dkc_create_throws((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 252:

/* Line 1455 of yacc.c  */
#line 1117 "diksam.y"
    {
            (yyval.exception_list) = dkc_chain_exception_list((yyvsp[(1) - (3)].exception_list), (yyvsp[(3) - (3)].identifier));
        }
    break;

  case 253:

/* Line 1455 of yacc.c  */
#line 1123 "diksam.y"
    {
            (yyval.function_definition) = dkc_constructor_function_define((yyvsp[(2) - (7)].identifier), (yyvsp[(4) - (7)].parameter_list), (yyvsp[(6) - (7)].exception_list), (yyvsp[(7) - (7)].block));
        }
    break;

  case 254:

/* Line 1455 of yacc.c  */
#line 1127 "diksam.y"
    {
            (yyval.function_definition) = dkc_constructor_function_define((yyvsp[(2) - (6)].identifier), NULL, (yyvsp[(5) - (6)].exception_list), (yyvsp[(6) - (6)].block));
        }
    break;

  case 255:

/* Line 1455 of yacc.c  */
#line 1131 "diksam.y"
    {
            (yyval.function_definition) = dkc_constructor_function_define((yyvsp[(3) - (8)].identifier), (yyvsp[(5) - (8)].parameter_list), (yyvsp[(7) - (8)].exception_list), NULL);
        }
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 1135 "diksam.y"
    {
            (yyval.function_definition) = dkc_constructor_function_define((yyvsp[(3) - (7)].identifier), NULL, (yyvsp[(6) - (7)].exception_list), NULL);
        }
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 1141 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(PUBLIC_MODIFIER);
        }
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 1145 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(PRIVATE_MODIFIER);
        }
    break;

  case 259:

/* Line 1455 of yacc.c  */
#line 1151 "diksam.y"
    {
            (yyval.expression) = NULL;
        }
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 1155 "diksam.y"
    {
            (yyval.expression) = (yyvsp[(2) - (2)].expression);
        }
    break;

  case 261:

/* Line 1455 of yacc.c  */
#line 1161 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(NULL, DVM_FALSE, (yyvsp[(4) - (6)].type_specifier), (yyvsp[(2) - (6)].identifier), (yyvsp[(5) - (6)].expression));
        }
    break;

  case 262:

/* Line 1455 of yacc.c  */
#line 1166 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(&(yyvsp[(1) - (6)].class_or_member_modifier), DVM_FALSE, (yyvsp[(4) - (6)].type_specifier), (yyvsp[(2) - (6)].identifier), (yyvsp[(5) - (6)].expression));
        }
    break;

  case 263:

/* Line 1455 of yacc.c  */
#line 1170 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(NULL, DVM_TRUE, (yyvsp[(4) - (6)].type_specifier), (yyvsp[(2) - (6)].identifier), (yyvsp[(5) - (6)].expression));
        }
    break;

  case 264:

/* Line 1455 of yacc.c  */
#line 1175 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(&(yyvsp[(1) - (7)].class_or_member_modifier), DVM_TRUE, (yyvsp[(5) - (7)].type_specifier), (yyvsp[(3) - (7)].identifier), (yyvsp[(6) - (7)].expression));
        }
    break;

  case 265:

/* Line 1455 of yacc.c  */
#line 1179 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(&(yyvsp[(2) - (7)].class_or_member_modifier), DVM_TRUE, (yyvsp[(5) - (7)].type_specifier), (yyvsp[(3) - (7)].identifier), (yyvsp[(6) - (7)].expression));
        }
    break;

  case 266:

/* Line 1455 of yacc.c  */
#line 1185 "diksam.y"
    {
            dkc_create_delegate_definition((yyvsp[(8) - (10)].type_specifier), (yyvsp[(2) - (10)].identifier), (yyvsp[(4) - (10)].parameter_list), (yyvsp[(9) - (10)].exception_list),(yyvsp[(5) - (10)].intval));
        }
    break;

  case 267:

/* Line 1455 of yacc.c  */
#line 1189 "diksam.y"
    {
            dkc_create_delegate_definition((yyvsp[(7) - (9)].type_specifier), (yyvsp[(2) - (9)].identifier), NULL, (yyvsp[(8) - (9)].exception_list),(yyvsp[(4) - (9)].intval));
        }
    break;

  case 268:

/* Line 1455 of yacc.c  */
#line 1195 "diksam.y"
    {
            dkc_create_enum_definition((yyvsp[(2) - (5)].identifier), (yyvsp[(4) - (5)].enumerator));
        }
    break;

  case 269:

/* Line 1455 of yacc.c  */
#line 1199 "diksam.y"
    {
            dkc_create_enum_definition((yyvsp[(2) - (6)].identifier), (yyvsp[(4) - (6)].enumerator));
        }
    break;

  case 270:

/* Line 1455 of yacc.c  */
#line 1205 "diksam.y"
    {
            (yyval.enumerator) = dkc_create_enumerator((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 271:

/* Line 1455 of yacc.c  */
#line 1209 "diksam.y"
    {
            (yyval.enumerator) = dkc_chain_enumerator((yyvsp[(1) - (3)].enumerator), (yyvsp[(3) - (3)].identifier));
        }
    break;

  case 272:

/* Line 1455 of yacc.c  */
#line 1215 "diksam.y"
    {
            dkc_create_const_definition(NULL, (yyvsp[(2) - (5)].identifier), (yyvsp[(4) - (5)].expression));
        }
    break;

  case 273:

/* Line 1455 of yacc.c  */
#line 1219 "diksam.y"
    {
            dkc_create_const_definition((yyvsp[(2) - (4)].type_specifier), (yyvsp[(3) - (4)].identifier), NULL);
        }
    break;

  case 274:

/* Line 1455 of yacc.c  */
#line 1225 "diksam.y"
    {
			(yyval.intval)=0;
		}
    break;

  case 275:

/* Line 1455 of yacc.c  */
#line 1229 "diksam.y"
    {
			(yyval.intval)=1;
		}
    break;

  case 276:

/* Line 1455 of yacc.c  */
#line 1235 "diksam.y"
    {
			(yyval.intval)=0;
		}
    break;

  case 277:

/* Line 1455 of yacc.c  */
#line 1239 "diksam.y"
    {
			(yyval.intval)=1;
		}
    break;

  case 278:

/* Line 1455 of yacc.c  */
#line 1243 "diksam.y"
    {
			(yyval.intval)=-1;
		}
    break;

  case 279:

/* Line 1455 of yacc.c  */
#line 1249 "diksam.y"
    {
            (yyval.block) = dkc_open_block((yyvsp[(2) - (2)].intval));
			//printf("E1 %d\n",dkc_get_current_compiler());
        }
    break;

  case 280:

/* Line 1455 of yacc.c  */
#line 1254 "diksam.y"
    {
            (yyval.block) = dkc_close_block((yyvsp[(3) - (5)].block), (yyvsp[(4) - (5)].statement_list));
			//printf("C1 %d\n",dkc_get_current_compiler()->current_line_number);
        }
    break;

  case 281:

/* Line 1455 of yacc.c  */
#line 1259 "diksam.y"
    {
            Block *empty_block = dkc_open_block(0);
            (yyval.block) = dkc_close_block(empty_block, NULL);
			//printf("C2 %d\n",dkc_get_current_compiler()->current_line_number);
        }
    break;



/* Line 1455 of yacc.c  */
#line 4277 "y.tab.c"
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
#line 1265 "diksam.y"


