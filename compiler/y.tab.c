
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



/* Line 214 of yacc.c  */
#line 356 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 368 "y.tab.c"

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
#define YYLAST   1045

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  105
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  98
/* YYNRULES -- Number of rules.  */
#define YYNRULES  270
/* YYNRULES -- Number of states.  */
#define YYNSTATES  586

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
     702,   706,   707,   708,   717,   718,   728,   729,   737,   738,
     747,   749,   752,   754,   756,   758,   760,   762,   764,   765,
     768,   770,   774,   776,   779,   781,   783,   785,   788,   790,
     793,   803,   812,   823,   833,   841,   848,   857,   865,   866,
     869,   870,   873,   875,   879,   887,   894,   903,   911,   913,
     915,   916,   919,   926,   933,   940,   948,   956,   967,   977,
     983,   990,   992,   996,  1002,  1007,  1008,  1011,  1014,  1015,
    1021
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     106,     0,    -1,   107,    -1,   106,   113,    -1,    -1,   108,
     111,    -1,   108,    -1,   111,    -1,   107,   120,    -1,   109,
      -1,   108,   109,    -1,    74,   110,    98,    -1,     7,    -1,
     110,    53,     7,    -1,   112,    -1,   111,   112,    -1,    75,
     110,     7,    98,    -1,   124,    -1,   175,    -1,   147,    -1,
     196,    -1,   197,    -1,   199,    -1,    66,    -1,    67,    -1,
      68,    -1,    69,    -1,    70,    -1,    71,    -1,    72,    -1,
      89,    -1,     7,    -1,   114,    27,    28,    -1,     7,    27,
      28,    -1,   116,    27,    28,    -1,     7,    39,   119,    37,
      -1,   114,    -1,   116,    -1,   115,    -1,   117,    -1,   118,
      -1,   119,    31,   118,    -1,    -1,   102,     7,   121,    98,
     122,    97,    -1,    -1,   122,   123,    -1,   122,   175,    -1,
      99,    93,     7,    23,   125,   189,    24,    94,   118,   190,
      98,    -1,    99,    93,     7,    23,   189,    24,    94,   118,
     190,    98,    -1,    99,   100,     7,    23,   125,   189,    24,
     190,    98,    -1,    99,   100,     7,    23,   189,    24,   190,
      98,    -1,    93,     7,    23,   125,   189,    24,    94,   118,
     190,   201,    -1,    93,     7,    23,   189,    24,    94,   118,
     190,   201,    -1,   100,     7,    23,   125,   189,    24,   190,
     201,    -1,   100,     7,    23,   189,    24,   190,   201,    -1,
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
     170,    -1,   171,    -1,    98,    -1,     9,   128,    95,   201,
      -1,     9,   128,    95,   201,    10,   201,    -1,     9,   128,
      95,   201,   149,    -1,     9,   128,    95,   201,   149,    10,
     201,    -1,   150,    -1,   149,   150,    -1,    11,   128,    95,
     201,    -1,    -1,     7,    30,    -1,    12,   128,    98,   153,
     155,    -1,   154,    -1,   153,   154,    -1,    13,   156,   201,
      -1,    -1,    14,   201,    -1,   129,    -1,   146,    31,   129,
      -1,   151,    15,   128,   201,    -1,   151,    17,   161,    29,
     161,    29,   161,   201,    -1,   151,    16,   172,    15,    23,
     128,    24,    98,    -1,   151,    18,    23,     7,    30,   128,
      24,   172,    -1,    -1,   128,    -1,    19,   161,    98,    -1,
      -1,     7,    -1,    20,   163,    98,    -1,    21,   163,    98,
      -1,    61,   201,   167,    63,   201,    -1,    61,   201,    63,
     172,    -1,    61,   201,   167,    -1,   168,    -1,   167,   168,
      -1,    -1,    62,   169,   118,     7,   201,    -1,    64,   128,
      98,    -1,    64,    98,    -1,    96,     7,    94,   118,    98,
      -1,    96,     7,    94,   118,    32,   128,    98,    -1,    90,
       7,    94,   118,    98,    -1,    90,     7,    94,   118,    32,
     128,    98,    -1,    -1,    25,   173,   127,    26,    -1,    25,
      26,    -1,    39,   184,    37,    -1,    -1,    -1,   182,     7,
     174,   183,    98,   176,   185,    97,    -1,    -1,   180,   182,
       7,   174,   183,    98,   177,   185,    97,    -1,    -1,   182,
       7,   174,   183,    98,   178,    97,    -1,    -1,   180,   182,
       7,   174,   183,    98,   179,    97,    -1,   181,    -1,   180,
     181,    -1,   193,    -1,    80,    -1,    81,    -1,    82,    -1,
      76,    -1,    77,    -1,    -1,    30,   184,    -1,     7,    -1,
     184,    31,     7,    -1,   186,    -1,   185,   186,    -1,   187,
      -1,   195,    -1,   188,    -1,   180,   188,    -1,   192,    -1,
     180,   192,    -1,    93,     7,    23,   125,    24,    94,   118,
     190,   201,    -1,    93,     7,    23,    24,    94,   118,   190,
     201,    -1,    99,    93,     7,    23,   125,    24,    94,   118,
     190,    98,    -1,    99,    93,     7,    23,    24,    94,   118,
     190,    98,    -1,   100,     7,    23,   125,    24,   190,   201,
      -1,   100,     7,    23,    24,   190,   201,    -1,    99,   100,
       7,    23,   125,    24,   190,    98,    -1,    99,   100,     7,
      23,    24,   190,    98,    -1,    -1,    31,   101,    -1,    -1,
      65,   191,    -1,     7,    -1,   191,    31,     7,    -1,    85,
       7,    23,   125,    24,   190,   201,    -1,    85,     7,    23,
      24,   190,   201,    -1,    99,    85,     7,    23,   125,    24,
     190,    98,    -1,    99,    85,     7,    23,    24,   190,    98,
      -1,    78,    -1,    79,    -1,    -1,    32,   128,    -1,    96,
       7,    94,   118,   194,    98,    -1,   180,     7,    94,   118,
     194,    98,    -1,    90,     7,    94,   118,   194,    98,    -1,
     180,    90,     7,    94,   118,   194,    98,    -1,    90,   180,
       7,    94,   118,   194,    98,    -1,    89,     7,    23,   125,
     189,    24,    94,   118,   190,    98,    -1,    89,     7,    23,
     189,    24,    94,   118,   190,    98,    -1,    91,     7,    25,
     198,    26,    -1,    91,     7,    25,   198,    31,    26,    -1,
       7,    -1,   198,    31,     7,    -1,    92,     7,    32,   128,
      98,    -1,    92,   118,     7,    98,    -1,    -1,   103,    98,
      -1,   104,    98,    -1,    -1,    98,   200,   202,   127,    97,
      -1,    98,    97,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   100,   100,   101,   105,   108,   112,   116,   120,   126,
     127,   133,   139,   143,   149,   150,   156,   162,   163,   164,
     171,   172,   173,   176,   180,   184,   188,   192,   196,   200,
     204,   210,   216,   222,   228,   234,   240,   244,   245,   246,
     250,   254,   262,   261,   276,   279,   280,   283,   287,   291,
     295,   302,   306,   310,   314,   318,   321,   325,   331,   335,
     341,   345,   351,   352,   358,   359,   365,   369,   373,   377,
     381,   385,   391,   392,   398,   399,   405,   406,   410,   416,
     417,   421,   425,   429,   435,   436,   440,   446,   447,   451,
     455,   459,   463,   467,   473,   474,   478,   482,   488,   489,
     493,   497,   503,   504,   505,   509,   515,   519,   524,   528,
     532,   536,   540,   544,   545,   546,   547,   548,   552,   556,
     560,   561,   565,   569,   573,   577,   581,   585,   591,   595,
     601,   605,   609,   613,   620,   621,   627,   633,   637,   645,
     648,   652,   658,   662,   663,   664,   665,   666,   667,   668,
     669,   670,   671,   672,   673,   674,   680,   684,   689,   693,
     699,   700,   706,   713,   716,   722,   728,   729,   735,   742,
     745,   751,   755,   761,   767,   773,   779,   786,   789,   792,
     799,   802,   805,   811,   817,   821,   825,   831,   832,   839,
     838,   848,   852,   858,   862,   866,   870,   877,   876,   884,
     892,   897,   902,   900,   911,   909,   918,   917,   927,   925,
     936,   937,   943,   944,   948,   952,   958,   962,   969,   972,
     978,   982,   988,   989,   995,   996,   999,  1003,  1007,  1011,
    1017,  1021,  1025,  1029,  1033,  1037,  1041,  1045,  1052,  1055,
    1062,  1065,  1071,  1075,  1081,  1085,  1089,  1093,  1099,  1103,
    1110,  1113,  1119,  1123,  1128,  1132,  1137,  1143,  1147,  1153,
    1157,  1163,  1167,  1173,  1177,  1184,  1187,  1191,  1198,  1197,
    1207
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
  "block", "@3", "template_list", "class_definition", "$@4", "$@5", "$@6",
  "$@7", "class_or_member_modifier_list", "class_or_member_modifier",
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
     174,   174,   176,   175,   177,   175,   178,   175,   179,   175,
     180,   180,   181,   181,   181,   181,   182,   182,   183,   183,
     184,   184,   185,   185,   186,   186,   187,   187,   187,   187,
     188,   188,   188,   188,   188,   188,   188,   188,   189,   189,
     190,   190,   191,   191,   192,   192,   192,   192,   193,   193,
     194,   194,   195,   195,   195,   195,   195,   196,   196,   197,
     197,   198,   198,   199,   199,   200,   200,   200,   202,   201,
     201
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
       3,     0,     0,     8,     0,     9,     0,     7,     0,     8,
       1,     2,     1,     1,     1,     1,     1,     1,     0,     2,
       1,     3,     1,     2,     1,     1,     1,     2,     1,     2,
       9,     8,    10,     9,     7,     6,     8,     7,     0,     2,
       0,     2,     1,     3,     7,     6,     8,     7,     1,     1,
       0,     2,     6,     6,     6,     7,     7,    10,     9,     5,
       6,     1,     3,     5,     4,     0,     2,     2,     0,     5,
       2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       4,     0,     0,   163,     2,     6,     9,     7,    14,    12,
       0,     0,     1,   113,   114,   115,   116,   104,   105,     0,
       0,   177,   180,   180,   119,     0,   139,     0,     0,   117,
     118,     0,     0,     0,     0,   216,   217,   248,   249,   213,
     214,   215,   121,   122,     0,     0,     0,     0,     0,     0,
     155,     0,     0,     3,    55,    17,     0,    62,    64,    72,
      74,    76,    79,    84,    87,    94,    98,   102,   120,   103,
      19,   143,     0,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,    18,     0,   210,     0,   212,    20,
      21,    22,     0,     8,    10,     5,    15,     0,    11,     0,
       0,   164,   104,     0,     0,   178,     0,   181,     0,     0,
       0,   140,     0,    95,    98,    97,    96,   265,     0,   192,
       0,    31,    23,    24,    25,    26,    27,    28,    29,    30,
       0,     0,     0,     0,     0,    31,    30,    36,    38,    37,
      39,     0,     0,     0,     0,     0,     0,     0,   142,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    66,     0,    67,    68,
      69,    70,    71,    99,   100,     0,     0,     0,     0,     0,
       0,   177,     0,   211,     0,   201,    42,    13,    16,     0,
       0,     0,   179,   182,   183,   111,   128,     0,   270,     0,
       0,   268,   189,     0,   186,   187,   191,     0,     0,     0,
       0,   130,   134,   132,   238,     0,     0,     0,     0,     0,
       0,     0,     0,   238,     0,     0,     0,   238,    63,    73,
      75,    77,    78,    80,    81,    82,    83,    85,    86,    88,
      89,    90,    91,    92,    93,   110,     0,    58,   108,    31,
     101,     0,    65,     0,     0,   197,     0,     0,     0,   201,
       0,   218,     0,   107,   156,   139,   169,   166,   129,   141,
     266,   267,   163,     0,   185,     0,   188,   124,     0,     0,
     123,     0,     0,   135,   131,   133,     0,     0,   238,     0,
       0,   261,     0,    33,     0,    40,     0,    32,    34,   264,
     238,     0,     0,   238,   238,   238,     0,   109,     0,   112,
     106,   173,   199,   163,     0,   177,     0,   218,   220,     0,
       0,     0,    44,     0,     0,   158,   160,   140,     0,     0,
       0,   167,   165,   163,    60,     0,   184,   125,     0,   136,
     137,     0,     0,   239,     0,     0,     0,     0,   195,   259,
       0,   263,     0,    35,     0,     0,     0,   193,   238,     0,
     238,     0,     0,   240,    59,   163,     0,     0,     0,     0,
       0,   200,   219,   202,     0,   157,     0,     0,   161,     0,
     168,   170,   269,    61,     0,   126,     0,   138,    56,     0,
       0,     0,     0,   262,   260,    41,     0,     0,     0,     0,
       0,     0,   240,   240,     0,     0,   198,     0,   177,     0,
     204,   221,     0,     0,    43,    45,    46,     0,   159,   141,
     190,   127,     0,     0,   240,   196,     0,   240,   194,     0,
       0,   240,     0,     0,   242,   241,    54,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     222,   224,   226,   228,   225,   207,   162,    57,   240,     0,
     240,     0,     0,   240,     0,    50,    53,     0,   175,   174,
     176,     0,   209,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   227,   229,   203,   223,     0,   258,
       0,    52,   240,     0,    49,   243,   205,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   257,    51,
       0,    48,   240,     0,   250,     0,     0,     0,   250,     0,
       0,     0,   240,     0,   250,     0,    47,     0,   240,     0,
       0,     0,   250,     0,     0,     0,   240,     0,     0,     0,
     240,     0,     0,   240,     0,   250,   245,     0,   251,   254,
       0,   240,     0,   252,     0,   240,     0,     0,     0,   240,
     235,     0,   253,     0,   244,   256,     0,   240,   247,     0,
     240,     0,   237,     0,   234,   255,   231,     0,   246,     0,
     240,   236,   230,   233,     0,   232
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,     6,    10,     7,     8,    53,   137,
     138,   139,   140,   141,   296,    93,   262,   374,    54,    55,
     288,   246,   333,    56,    57,   177,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,   211,   212,
     284,   112,   334,    71,   325,   326,    72,    73,   266,   267,
     332,   329,    74,    75,    76,    77,   106,    78,   108,    79,
      80,    81,   204,   205,   273,    82,    83,   256,   313,   261,
      84,   412,   440,   413,   441,   448,    86,    87,   321,   319,
     449,   450,   451,   452,   289,   405,   435,   453,    88,   531,
     454,    89,    90,   292,    91,   201,   118,   272
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -478
static const yytype_int16 yypact[] =
{
     179,    31,    31,   463,   -39,   179,  -478,    -4,  -478,  -478,
     -29,     9,  -478,  -478,  -478,  -478,  -478,    12,  -478,   961,
     961,   961,    79,    79,  -478,   961,   961,   961,   961,  -478,
    -478,   961,   -22,   805,   208,  -478,  -478,  -478,  -478,  -478,
    -478,  -478,  -478,  -478,   108,   122,   136,   297,   148,   162,
    -478,   -27,   186,  -478,  -478,  -478,   -18,  -478,   117,   169,
     182,   209,   215,   267,  -478,  -478,   442,   210,  -478,  -478,
    -478,  -478,   266,  -478,  -478,  -478,  -478,  -478,  -478,  -478,
    -478,  -478,  -478,  -478,  -478,   189,  -478,   207,  -478,  -478,
    -478,  -478,   225,  -478,  -478,    -4,  -478,   235,  -478,   152,
     961,  -478,   233,    14,   -11,   231,   166,  -478,   174,   192,
      99,  -478,    69,  -478,   144,  -478,  -478,    45,   224,  -478,
      -9,     7,  -478,  -478,  -478,  -478,  -478,  -478,  -478,   269,
     268,   268,   277,   212,   291,    38,  -478,   302,  -478,   307,
    -478,   329,   315,   254,   343,   344,   330,   961,  -478,   961,
     961,   961,   961,   961,   961,   961,   961,   961,   961,   961,
     961,   961,   961,   961,   961,   817,  -478,   345,  -478,  -478,
    -478,  -478,  -478,  -478,  -478,   338,   338,   961,   961,   961,
     348,   961,   352,  -478,   370,   340,  -478,  -478,  -478,   146,
     -22,   367,  -478,  -478,  -478,  -478,  -478,   857,  -478,   284,
     286,  -478,  -478,   348,   236,  -478,  -478,   869,   380,   364,
     961,   363,  -478,   363,    28,   338,   384,   365,   961,   338,
     366,   368,   294,    28,   338,   372,   376,    28,  -478,   169,
     182,   209,   209,   215,   215,   215,   215,   267,   267,  -478,
    -478,  -478,  -478,  -478,  -478,  -478,   132,  -478,  -478,     4,
    -478,   313,  -478,   170,    -8,   385,   387,   383,   406,   340,
     407,   386,   317,  -478,   292,   961,   305,  -478,  -478,  -478,
    -478,  -478,   753,   338,  -478,   -22,  -478,  -478,   133,   395,
    -478,   185,   909,  -478,   392,   392,   326,   320,   393,   399,
       5,  -478,   157,  -478,    -5,  -478,    87,  -478,  -478,  -478,
     393,   401,    22,    28,    28,   393,   402,  -478,   961,  -478,
    -478,  -478,  -478,   753,   405,   961,   400,   386,  -478,   141,
     407,   331,  -478,   -22,   961,   310,  -478,   333,   403,   -22,
     -22,  -478,  -478,   561,  -478,   425,  -478,  -478,   921,  -478,
    -478,   408,   338,  -478,    11,   411,   346,   961,  -478,  -478,
      25,  -478,   338,  -478,   413,   347,   961,  -478,   393,   414,
     393,   415,   418,   396,  -478,   657,   961,   431,   961,   375,
     455,  -478,   433,   379,   279,  -478,    19,   -22,  -478,   961,
    -478,  -478,  -478,  -478,   -22,  -478,   142,  -478,  -478,   397,
     398,   338,    -2,  -478,  -478,  -478,   409,   338,     3,   453,
     410,   454,   396,   396,   472,   -22,  -478,   151,   961,   163,
     390,  -478,   632,   412,  -478,  -478,  -478,   -22,  -478,   382,
    -478,  -478,   338,   338,   396,  -478,   338,   396,  -478,   416,
     338,   396,   391,   -22,  -478,   450,  -478,   419,   -22,   348,
     632,   421,   483,    54,   486,   487,   -21,   499,    26,   509,
    -478,  -478,  -478,  -478,  -478,  -478,  -478,  -478,   396,   422,
     396,   -22,   338,   396,   423,  -478,  -478,   500,  -478,  -478,
    -478,   536,  -478,   485,   428,   143,   493,   429,   512,   518,
     519,   507,   437,   525,  -478,  -478,  -478,  -478,   435,  -478,
     -22,  -478,   396,   436,  -478,  -478,  -478,    33,   338,   441,
      60,   338,   514,   515,   526,   114,   338,   456,  -478,  -478,
     459,  -478,   396,   165,   516,   338,   457,   188,   516,   115,
     120,   121,   396,   203,   516,   338,  -478,   -22,   396,   551,
     961,   462,   516,   338,   477,   474,   396,   204,   480,   205,
     396,   214,   -22,   396,   478,   516,  -478,   -22,   231,  -478,
     479,   396,   338,  -478,   481,   396,   338,   484,   494,   396,
    -478,   -22,  -478,   495,  -478,  -478,   -22,   396,  -478,   497,
     396,   338,  -478,   498,  -478,  -478,  -478,   -22,  -478,   502,
     396,  -478,  -478,  -478,   503,  -478
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -478,  -478,  -478,  -478,   570,   583,   592,    18,  -478,   564,
     573,  -478,  -478,  -171,  -478,  -478,  -478,  -478,   230,  -478,
    -212,  -197,   306,   -19,    -7,  -478,  -478,   471,   473,   173,
     187,   175,    47,  -478,   295,  -478,  -478,  -478,   496,    30,
     417,   359,     6,  -478,  -478,   303,  -478,  -478,  -478,   371,
    -478,  -478,  -478,  -478,  -478,  -478,  -169,  -478,   608,  -478,
    -478,  -478,  -478,   434,  -478,  -478,  -478,  -195,  -478,   381,
     265,  -478,  -478,  -478,  -478,     0,   -78,   556,   325,   323,
     206,  -413,  -478,   199,  -206,  -375,  -478,   200,  -478,  -477,
    -478,  -478,  -478,  -478,  -478,  -478,  -144,  -478
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -209
static const yytype_int16 yytable[] =
{
     103,   104,   105,    85,   250,   251,   110,   183,   274,    70,
     278,   300,   257,   147,   120,   305,    99,   301,   389,   111,
     147,   306,   147,   147,    97,    96,   147,   432,   433,   147,
     207,   217,   393,   482,   147,   286,   487,   347,     9,   100,
     286,   535,   101,   219,   290,   147,   264,   544,   295,   459,
     147,   394,   461,   302,   356,   550,   464,   512,   487,   287,
     208,   474,    97,    92,   478,   217,   144,   286,   563,    98,
     218,     2,   479,   145,   113,   115,   117,   219,   116,   480,
     148,   189,   345,   488,   516,   490,   107,   191,   493,   206,
     117,   358,   360,   351,   354,   196,   425,   359,   361,   362,
     197,   428,   335,   348,    37,    38,    39,    40,    41,   190,
     311,   442,   343,    96,   417,   132,   483,   510,   352,   444,
     357,   286,   286,   195,   353,   446,   447,   286,   286,   133,
     147,   336,    37,    38,    39,    40,    41,   527,   522,   536,
     228,   386,   198,   134,   538,   540,   367,   542,   199,   200,
     499,   149,   399,   547,   401,   142,   307,   337,   247,   253,
     254,   554,   105,   308,   308,   558,   421,   165,   561,   143,
     252,   388,   370,   308,   263,   437,   566,   147,   371,   375,
     569,   395,   147,   349,   573,   380,   381,   439,   350,   528,
     269,   281,   577,   146,   147,   579,   529,   167,   310,   294,
     247,   147,   150,   173,   174,   584,   239,   240,   241,   242,
     243,   244,   534,   339,   185,   121,   147,   151,   152,   529,
     424,    37,    38,    39,    40,    41,   427,   543,   555,   557,
     175,   176,   186,   418,   529,   529,   529,   178,   559,   438,
     420,   283,   187,   283,   470,   529,   153,   154,   155,   156,
     188,   457,   458,     1,     2,   460,   157,   158,   327,   463,
     100,   436,   147,   281,   192,    35,    36,    37,    38,    39,
      40,    41,   193,   456,   122,   123,   124,   125,   126,   127,
     128,   179,   180,   181,   182,   513,   202,   203,   517,   466,
     194,   492,   209,   523,   469,   210,   105,   129,   202,   275,
     214,   364,   323,   324,   135,   376,   215,   537,   539,   541,
     159,   160,   161,   162,   163,   164,   216,   491,   265,   330,
     377,   324,   114,   114,   231,   232,   114,   514,   392,   220,
     518,   247,   237,   238,   221,   524,   222,   398,   223,   383,
     233,   234,   235,   236,   532,   249,   509,   407,   224,   409,
     225,   226,   248,   227,   545,    35,    36,    37,    38,    39,
      40,    41,   551,   122,   123,   124,   125,   126,   127,   128,
     183,   383,   419,   255,    85,   258,   414,   259,    51,   260,
     265,   567,   270,   546,   271,   570,   136,   279,   280,   105,
     282,   291,   299,   293,   297,   303,   298,   183,   560,   304,
     580,   309,   314,   564,   122,   123,   124,   125,   126,   127,
     128,   312,   315,   316,   318,   322,   320,   574,   338,   341,
     342,   343,   576,   346,   344,   355,   363,   136,   366,   373,
     368,  -171,   384,   582,   379,   390,   387,   396,   400,   402,
     391,   397,   403,   475,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     408,   404,   411,    12,   370,   165,    13,    14,    15,    16,
      17,    18,    19,   410,   166,    20,  -206,   429,   431,   434,
    -172,   467,    21,    22,    23,    24,    25,  -208,    26,   465,
     473,   422,   423,   476,   477,   167,   168,   169,   170,   171,
     172,   173,   174,   426,   430,    27,   481,   495,   497,   455,
     462,   548,    28,    29,    30,    31,   500,   468,   472,   502,
     489,   494,   498,   501,    32,   503,   504,    33,   175,   176,
     505,   506,   507,   508,   511,   515,    34,   519,   520,    35,
      36,    37,    38,    39,    40,    41,    42,    43,   530,   521,
     525,   533,    44,    45,    46,    47,    48,   526,   389,    49,
     549,    50,    51,    52,    13,    14,    15,    16,    17,    18,
      19,   552,   553,    20,   556,    94,   562,   565,   571,   568,
      21,    22,    23,    24,    25,    11,    26,    37,    38,    39,
      40,    41,   572,   575,   442,   578,   581,    95,   130,   443,
     583,   585,   444,    27,   415,   445,   486,   131,   446,   447,
      28,    29,    30,    31,    37,    38,    39,    40,    41,   365,
     229,   442,    32,   230,   328,    33,   443,   213,   378,   444,
     285,   109,   445,   496,    34,   446,   447,   331,   276,   416,
     317,   184,   369,   372,    42,    43,   471,   484,   485,     0,
       0,    45,     0,     0,     0,     0,     0,    49,   382,    50,
      13,    14,    15,    16,    17,    18,    19,     0,     0,    20,
       0,     0,     0,     0,     0,     0,    21,    22,    23,    24,
      25,     0,    26,   406,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    27,
       0,     0,     0,     0,     0,     0,    28,    29,    30,    31,
      37,    38,    39,    40,    41,     0,     0,   442,    32,     0,
       0,    33,   443,     0,     0,   444,     0,     0,   445,     0,
      34,   446,   447,     0,     0,     0,     0,     0,     0,     0,
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
      25,   245,    26,    45,     0,     0,     0,    27,     0,    49,
       0,    50,     0,     0,    28,    29,    30,    31,     0,    27,
      13,    14,    15,    16,   102,    18,    28,    29,    30,    31,
       0,     0,    13,    14,    15,    16,   102,    18,    34,    24,
      25,     0,    26,   268,     0,     0,     0,     0,    42,    43,
      34,    24,    25,   277,    26,     0,     0,     0,     0,    27,
      42,    43,     0,   119,     0,     0,    28,    29,    30,    31,
       0,    27,    13,    14,    15,    16,   102,    18,    28,    29,
      30,    31,     0,     0,    13,    14,    15,    16,   102,    18,
      34,    24,    25,     0,    26,     0,     0,   340,     0,     0,
      42,    43,    34,    24,    25,   385,    26,     0,     0,     0,
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
      19,    20,    21,     3,   175,   176,    25,    85,   203,     3,
     207,   223,   181,    31,    33,   227,     7,   223,     7,    26,
      31,   227,    31,    31,    53,     7,    31,   402,   403,    31,
      23,    27,     7,     7,    31,     7,   449,    32,     7,    27,
       7,   518,    30,    39,   215,    31,   190,   524,   219,   424,
      31,    26,   427,   224,    32,   532,   431,    24,   471,    31,
      53,     7,    53,   102,    85,    27,    93,     7,   545,    98,
      32,    75,    93,   100,    27,    28,    98,    39,    31,   100,
      98,   100,   288,   458,    24,   460,     7,    98,   463,    98,
      98,   303,   304,    98,   300,    26,    98,   303,   304,   305,
      31,    98,   273,    98,    78,    79,    80,    81,    82,    95,
     254,    85,   101,    95,    95,     7,    90,   492,    31,    93,
      98,     7,     7,    24,    37,    99,   100,     7,     7,     7,
      31,   275,    78,    79,    80,    81,    82,   512,    24,    24,
     147,   338,    97,     7,    24,    24,   315,   522,   103,   104,
       7,    34,   358,   528,   360,     7,    24,    24,   165,   178,
     179,   536,   181,    31,    31,   540,    24,    23,   543,     7,
     177,   342,    31,    31,    28,    24,   551,    31,    37,   323,
     555,   352,    31,    26,   559,   329,   330,    24,    31,    24,
     197,   210,   567,     7,    31,   570,    31,    53,    28,   218,
     207,    31,    33,    59,    60,   580,   159,   160,   161,   162,
     163,   164,    24,    28,     7,     7,    31,    35,    36,    31,
     391,    78,    79,    80,    81,    82,   397,    24,    24,    24,
      86,    87,     7,   377,    31,    31,    31,    27,    24,   408,
     384,   211,     7,   213,   439,    31,    37,    38,    39,    40,
      98,   422,   423,    74,    75,   426,    41,    42,   265,   430,
      27,   405,    31,   282,    98,    76,    77,    78,    79,    80,
      81,    82,    98,   417,    66,    67,    68,    69,    70,    71,
      72,    15,    16,    17,    18,   497,    62,    63,   500,   433,
      98,   462,    23,   505,   438,    27,   315,    89,    62,    63,
      23,   308,    10,    11,     7,   324,    94,   519,   520,   521,
      43,    44,    45,    46,    47,    48,    25,   461,    13,    14,
      10,    11,    27,    28,   151,   152,    31,   498,   347,    27,
     501,   338,   157,   158,    27,   506,     7,   356,    23,   333,
     153,   154,   155,   156,   515,     7,   490,   366,    94,   368,
       7,     7,     7,    23,   525,    76,    77,    78,    79,    80,
      81,    82,   533,    66,    67,    68,    69,    70,    71,    72,
     448,   365,   379,    25,   374,    23,    97,     7,    99,    39,
      13,   552,    98,   527,    98,   556,    89,     7,    24,   408,
      27,     7,    98,    28,    28,    23,    28,   475,   542,    23,
     571,    88,    15,   547,    66,    67,    68,    69,    70,    71,
      72,    26,    29,     7,     7,    98,    30,   561,    23,    27,
      94,   101,   566,    24,    31,    24,    24,    89,    23,    98,
      30,    98,     7,   577,    31,    24,    28,    24,    24,    24,
      94,    94,    24,   443,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
      29,    65,     7,     0,    31,    23,     3,     4,     5,     6,
       7,     8,     9,    98,    32,    12,    97,    24,    24,     7,
      98,    31,    19,    20,    21,    22,    23,    97,    25,    98,
       7,    94,    94,     7,     7,    53,    54,    55,    56,    57,
      58,    59,    60,    94,    94,    42,     7,     7,    23,    97,
      94,   530,    49,    50,    51,    52,    23,    98,    97,     7,
      98,    98,    94,    94,    61,     7,     7,    64,    86,    87,
      23,    94,     7,    98,    98,    94,    73,    23,    23,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    32,    23,
      94,    94,    89,    90,    91,    92,    93,    98,     7,    96,
      98,    98,    99,   100,     3,     4,     5,     6,     7,     8,
       9,    94,    98,    12,    94,     5,    98,    98,    94,    98,
      19,    20,    21,    22,    23,     2,    25,    78,    79,    80,
      81,    82,    98,    98,    85,    98,    98,     5,    34,    90,
      98,    98,    93,    42,   374,    96,    97,    34,    99,   100,
      49,    50,    51,    52,    78,    79,    80,    81,    82,   313,
     149,    85,    61,   150,   265,    64,    90,   131,   325,    93,
     213,    23,    96,    97,    73,    99,   100,   266,   204,   374,
     259,    85,   317,   320,    83,    84,   440,   448,   448,    -1,
      -1,    90,    -1,    -1,    -1,    -1,    -1,    96,    97,    98,
       3,     4,     5,     6,     7,     8,     9,    -1,    -1,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    21,    22,
      23,    -1,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,
      78,    79,    80,    81,    82,    -1,    -1,    85,    61,    -1,
      -1,    64,    90,    -1,    -1,    93,    -1,    -1,    96,    -1,
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
      98,    99,   100,   113,   123,   124,   128,   129,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     147,   148,   151,   152,   157,   158,   159,   160,   162,   164,
     165,   166,   170,   171,   175,   180,   181,   182,   193,   196,
     197,   199,   102,   120,   109,   111,   112,    53,    98,     7,
      27,    30,     7,   128,   128,   128,   161,     7,   163,   163,
     128,   129,   146,   137,   139,   137,   137,    98,   201,    98,
     128,     7,    66,    67,    68,    69,    70,    71,    72,    89,
     114,   115,     7,     7,     7,     7,    89,   114,   115,   116,
     117,   118,     7,     7,    93,   100,     7,    31,    98,    34,
      33,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    23,    32,    53,    54,    55,
      56,    57,    58,    59,    60,    86,    87,   130,    27,    15,
      16,    17,    18,   181,   182,     7,     7,     7,    98,   128,
      95,    98,    98,    98,    98,    24,    26,    31,    97,   103,
     104,   200,    62,    63,   167,   168,    98,    23,    53,    23,
      27,   143,   144,   143,    23,    94,    25,    27,    32,    39,
      27,    27,     7,    23,    94,     7,     7,    23,   129,   132,
     133,   134,   134,   135,   135,   135,   135,   136,   136,   137,
     137,   137,   137,   137,   137,    24,   126,   129,     7,     7,
     118,   118,   129,   128,   128,    25,   172,   161,    23,     7,
      39,   174,   121,    28,   201,    13,   153,   154,    26,   129,
      98,    98,   202,   169,   172,    63,   168,    24,   126,     7,
      24,   128,    27,   144,   145,   145,     7,    31,   125,   189,
     118,     7,   198,    28,   128,   118,   119,    28,    28,    98,
     125,   189,   118,    23,    23,   125,   189,    24,    31,    88,
      28,   201,    26,   173,    15,    29,     7,   174,     7,   184,
      30,   183,    98,    10,    11,   149,   150,   129,   146,   156,
      14,   154,   155,   127,   147,   118,   201,    24,    23,    28,
      28,    27,    94,   101,    31,   189,    24,    32,    98,    26,
      31,    98,    31,    37,   189,    24,    32,    98,   125,   189,
     125,   189,   189,    24,   129,   127,    23,   161,    30,   183,
      31,    37,   184,    98,   122,   201,   128,    10,   150,    31,
     201,   201,    97,   147,     7,    24,   126,    28,   118,     7,
      24,    94,   128,     7,    26,   118,    24,    94,   128,   189,
      24,   189,    24,    24,    65,   190,    26,   128,    29,   128,
      98,     7,   176,   178,    97,   123,   175,    95,   201,   129,
     201,    24,    94,    94,   118,    98,    94,   118,    98,    24,
      94,    24,   190,   190,     7,   191,   201,    24,   161,    24,
     177,   179,    85,    90,    93,    96,    99,   100,   180,   185,
     186,   187,   188,   192,   195,    97,   201,   118,   118,   190,
     118,   190,    94,   118,   190,    98,   201,    31,    98,   201,
     172,   185,    97,     7,     7,   180,     7,     7,    85,    93,
     100,     7,     7,    90,   188,   192,    97,   186,   190,    98,
     190,   201,   118,   190,    98,     7,    97,    23,    94,     7,
      23,    94,     7,     7,     7,    23,    94,     7,    98,   201,
     190,    98,    24,   125,   118,    94,    24,   125,   118,    23,
      23,    23,    24,   125,   118,    94,    98,   190,    24,    31,
      32,   194,   118,    94,    24,   194,    24,   125,    24,   125,
      24,   125,   190,    24,   194,   118,   201,   190,   128,    98,
     194,   118,    94,    98,   190,    24,    94,    24,   190,    24,
     201,   190,    98,   194,   201,    98,   190,   118,    98,   190,
     118,    94,    98,   190,   201,    98,   201,   190,    98,   190,
     118,    98,   201,    98,   190,    98
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
#line 105 "diksam.y"
    {
            dkc_set_require_and_rename_list(NULL, NULL);
        }
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 109 "diksam.y"
    {
            dkc_set_require_and_rename_list((yyvsp[(1) - (2)].require_list), (yyvsp[(2) - (2)].rename_list));
        }
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 113 "diksam.y"
    {
            dkc_set_require_and_rename_list((yyvsp[(1) - (1)].require_list), NULL);
        }
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 117 "diksam.y"
    {
            dkc_set_require_and_rename_list(NULL, (yyvsp[(1) - (1)].rename_list));
        }
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 121 "diksam.y"
    {
            dkc_set_require_and_rename_list(NULL, NULL);
		}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 128 "diksam.y"
    {
            (yyval.require_list) = dkc_chain_require_list((yyvsp[(1) - (2)].require_list), (yyvsp[(2) - (2)].require_list));
        }
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 134 "diksam.y"
    {
            (yyval.require_list) = dkc_create_require_list((yyvsp[(2) - (3)].package_name));
        }
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 140 "diksam.y"
    {
            (yyval.package_name) = dkc_create_package_name((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 144 "diksam.y"
    {
            (yyval.package_name) = dkc_chain_package_name((yyvsp[(1) - (3)].package_name), (yyvsp[(3) - (3)].identifier));
        }
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 151 "diksam.y"
    {
            (yyval.rename_list) = dkc_chain_rename_list((yyvsp[(1) - (2)].rename_list), (yyvsp[(2) - (2)].rename_list));
        }
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 157 "diksam.y"
    {
            (yyval.rename_list) = dkc_create_rename_list((yyvsp[(2) - (4)].package_name), (yyvsp[(3) - (4)].identifier));
        }
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 165 "diksam.y"
    {
            DKC_Compiler *compiler = dkc_get_current_compiler();

            compiler->statement_list
                = dkc_chain_statement_list(compiler->statement_list, (yyvsp[(1) - (1)].statement));
        }
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 177 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_VOID_TYPE;
        }
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 181 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_BOOLEAN_TYPE;
        }
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 185 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_INT_TYPE;
        }
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 189 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_DOUBLE_TYPE;
        }
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 193 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_STRING_TYPE;
        }
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 197 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_VARIENT_TYPE;
        }
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 201 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_NATIVE_POINTER_TYPE;
        }
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 205 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_DELEGATE_TYPE;
        }
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 211 "diksam.y"
    {
            (yyval.type_specifier) = dkc_create_identifier_type_specifier((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 217 "diksam.y"
    {
            TypeSpecifier *basic_type
                = dkc_create_type_specifier((yyvsp[(1) - (3)].basic_type_specifier));
            (yyval.type_specifier) = dkc_create_array_type_specifier(basic_type);
        }
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 223 "diksam.y"
    {
            TypeSpecifier *identifier_type
                = dkc_create_identifier_type_specifier((yyvsp[(1) - (3)].identifier));
            (yyval.type_specifier) = dkc_create_array_type_specifier(identifier_type);
        }
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 229 "diksam.y"
    {
            (yyval.type_specifier) = dkc_create_array_type_specifier((yyvsp[(1) - (3)].type_specifier));
        }
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 235 "diksam.y"
    {//fix-me : shift/reduce
			(yyval.type_specifier)= dkc_create_template_type_specifier((yyvsp[(1) - (4)].identifier),(yyvsp[(3) - (4)].template));
		}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 241 "diksam.y"
    {
                    (yyval.type_specifier) = dkc_create_type_specifier((yyvsp[(1) - (1)].basic_type_specifier));
        }
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 251 "diksam.y"
    {
			(yyval.template)=dkc_create_template_list((yyvsp[(1) - (1)].type_specifier));
		}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 255 "diksam.y"
    {
            (yyval.template) = dkc_chain_template_list((yyvsp[(1) - (3)].template), (yyvsp[(3) - (3)].type_specifier));
        }
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 262 "diksam.y"
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
#line 272 "diksam.y"
    {
			BcGetCurrentCompilerContext()->isLib=0;
		}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 284 "diksam.y"
    {
            dkc_function_define((yyvsp[(9) - (11)].type_specifier), (yyvsp[(3) - (11)].identifier), (yyvsp[(5) - (11)].parameter_list), (yyvsp[(10) - (11)].exception_list), NULL,(yyvsp[(6) - (11)].apost));
        }
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 288 "diksam.y"
    {
            dkc_function_define((yyvsp[(8) - (10)].type_specifier), (yyvsp[(3) - (10)].identifier), NULL, (yyvsp[(9) - (10)].exception_list), NULL,(yyvsp[(5) - (10)].apost));
        }
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 292 "diksam.y"
    {
            dkc_function_define(0, (yyvsp[(3) - (9)].identifier), (yyvsp[(5) - (9)].parameter_list), (yyvsp[(8) - (9)].exception_list), NULL,(yyvsp[(6) - (9)].apost));
        }
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 296 "diksam.y"
    {
			//printf("lib:%s\n",BcGetCurrentCompilerContext()->libname);
            dkc_function_define(0, (yyvsp[(3) - (8)].identifier), NULL, (yyvsp[(7) - (8)].exception_list), NULL,(yyvsp[(5) - (8)].apost));
        }
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 303 "diksam.y"
    {
            dkc_function_define((yyvsp[(8) - (10)].type_specifier), (yyvsp[(2) - (10)].identifier), (yyvsp[(4) - (10)].parameter_list), (yyvsp[(9) - (10)].exception_list), (yyvsp[(10) - (10)].block),(yyvsp[(5) - (10)].apost));
        }
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 307 "diksam.y"
    {
            dkc_function_define((yyvsp[(7) - (9)].type_specifier), (yyvsp[(2) - (9)].identifier), NULL, (yyvsp[(8) - (9)].exception_list), (yyvsp[(9) - (9)].block),(yyvsp[(4) - (9)].apost));
        }
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 311 "diksam.y"
    { //modified
            dkc_function_define(0, (yyvsp[(2) - (8)].identifier), (yyvsp[(4) - (8)].parameter_list), (yyvsp[(7) - (8)].exception_list), (yyvsp[(8) - (8)].block),(yyvsp[(5) - (8)].apost));
        }
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 315 "diksam.y"
    {
            dkc_function_define(0, (yyvsp[(2) - (7)].identifier), NULL, (yyvsp[(6) - (7)].exception_list), (yyvsp[(7) - (7)].block),(yyvsp[(4) - (7)].apost));
        }
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 322 "diksam.y"
    {
            (yyval.parameter_list) = dkc_create_parameter((yyvsp[(3) - (3)].type_specifier), (yyvsp[(1) - (3)].identifier));
        }
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 326 "diksam.y"
    {
            (yyval.parameter_list) = dkc_chain_parameter((yyvsp[(1) - (5)].parameter_list), (yyvsp[(5) - (5)].type_specifier), (yyvsp[(3) - (5)].identifier));
        }
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 332 "diksam.y"
    {
            (yyval.argument_list) = dkc_create_argument_list((yyvsp[(1) - (1)].expression));
        }
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 336 "diksam.y"
    {
            (yyval.argument_list) = dkc_chain_argument_list((yyvsp[(1) - (3)].argument_list), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 342 "diksam.y"
    {
            (yyval.statement_list) = dkc_create_statement_list((yyvsp[(1) - (1)].statement));
        }
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 346 "diksam.y"
    {
            (yyval.statement_list) = dkc_chain_statement_list((yyvsp[(1) - (2)].statement_list), (yyvsp[(2) - (2)].statement));
        }
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 353 "diksam.y"
    {
            (yyval.expression) = dkc_create_comma_expression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 360 "diksam.y"
    {
            (yyval.expression) = dkc_create_assign_expression((yyvsp[(1) - (3)].expression), (yyvsp[(2) - (3)].assignment_operator), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 366 "diksam.y"
    {
            (yyval.assignment_operator) = NORMAL_ASSIGN;
        }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 370 "diksam.y"
    {
            (yyval.assignment_operator) = ADD_ASSIGN;
        }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 374 "diksam.y"
    {
            (yyval.assignment_operator) = SUB_ASSIGN;
        }
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 378 "diksam.y"
    {
            (yyval.assignment_operator) = MUL_ASSIGN;
        }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 382 "diksam.y"
    {
            (yyval.assignment_operator) = DIV_ASSIGN;
        }
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 386 "diksam.y"
    {
            (yyval.assignment_operator) = MOD_ASSIGN;
        }
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 393 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(LOGICAL_OR_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 400 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(LOGICAL_AND_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 407 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(EQ_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 411 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(NE_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 418 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(GT_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 422 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(GE_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 426 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(LT_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 430 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(LE_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 437 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(ADD_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 441 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(SUB_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 448 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(MUL_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 452 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(DIV_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 456 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(MOD_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 460 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(BIT_AND_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 464 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(BIT_OR_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 468 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(BIT_XOR_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 475 "diksam.y"
    {
            (yyval.expression) = dkc_create_minus_expression((yyvsp[(2) - (2)].expression));
        }
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 479 "diksam.y"
    {
            (yyval.expression) = dkc_create_logical_not_expression((yyvsp[(2) - (2)].expression));
        }
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 483 "diksam.y"
    {
            (yyval.expression) = dkc_create_bit_not_expression((yyvsp[(2) - (2)].expression));
        }
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 490 "diksam.y"
    {
            (yyval.expression) = dkc_create_incdec_expression((yyvsp[(1) - (2)].expression), INCREMENT_EXPRESSION);
        }
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 494 "diksam.y"
    {
            (yyval.expression) = dkc_create_incdec_expression((yyvsp[(1) - (2)].expression), DECREMENT_EXPRESSION);
        }
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 498 "diksam.y"
    {
            (yyval.expression) = dkc_create_instanceof_expression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].type_specifier));
        }
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 506 "diksam.y"
    {
            (yyval.expression) = dkc_create_identifier_expression((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 510 "diksam.y"
    {
			(yyval.expression)=BcCreateAutoExpression((yyvsp[(1) - (1)].identifier));
		}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 516 "diksam.y"
    {
            (yyval.expression) = dkc_create_index_expression((yyvsp[(1) - (4)].expression), (yyvsp[(3) - (4)].expression));
        }
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 520 "diksam.y"
    {
            Expression *identifier = dkc_create_identifier_expression((yyvsp[(1) - (4)].identifier));
            (yyval.expression) = dkc_create_index_expression(identifier, (yyvsp[(3) - (4)].expression));
        }
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 525 "diksam.y"
    {
            (yyval.expression) = dkc_create_member_expression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].identifier));
        }
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 529 "diksam.y"
    {
            (yyval.expression) = dkc_create_function_call_expression((yyvsp[(1) - (4)].expression), (yyvsp[(3) - (4)].argument_list));
        }
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 533 "diksam.y"
    {
            (yyval.expression) = dkc_create_function_call_expression((yyvsp[(1) - (3)].expression), NULL);
        }
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 537 "diksam.y"
    {
            (yyval.expression) = (yyvsp[(2) - (3)].expression);
        }
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 541 "diksam.y"
    {
            (yyval.expression) = dkc_create_down_cast_expression((yyvsp[(1) - (4)].expression), (yyvsp[(3) - (4)].type_specifier));
        }
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 549 "diksam.y"
    {
            (yyval.expression) = dkc_create_boolean_expression(DVM_TRUE);
        }
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 553 "diksam.y"
    {
            (yyval.expression) = dkc_create_boolean_expression(DVM_FALSE);
        }
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 557 "diksam.y"
    {
            (yyval.expression) = dkc_create_null_expression();
        }
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 562 "diksam.y"
    {
            (yyval.expression) = dkc_create_this_expression();
        }
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 566 "diksam.y"
    {
            (yyval.expression) = dkc_create_super_expression();
        }
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 570 "diksam.y"
    {
			(yyval.expression) = dkc_create_new_delegate_expression();
		}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 574 "diksam.y"
    {
            (yyval.expression) = dkc_create_new_expression((yyvsp[(2) - (4)].identifier), NULL, NULL);
        }
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 578 "diksam.y"
    {
            (yyval.expression) = dkc_create_new_expression((yyvsp[(2) - (5)].identifier), NULL, (yyvsp[(4) - (5)].argument_list));
        }
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 582 "diksam.y"
    {
            (yyval.expression) = dkc_create_new_expression((yyvsp[(2) - (6)].identifier), (yyvsp[(4) - (6)].identifier), NULL);
        }
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 586 "diksam.y"
    {
            (yyval.expression) = dkc_create_new_expression((yyvsp[(2) - (7)].identifier), (yyvsp[(4) - (7)].identifier), (yyvsp[(6) - (7)].argument_list));
        }
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 592 "diksam.y"
    {
            (yyval.expression) = dkc_create_array_literal_expression((yyvsp[(2) - (3)].expression_list));
        }
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 596 "diksam.y"
    {
            (yyval.expression) = dkc_create_array_literal_expression((yyvsp[(2) - (4)].expression_list));
        }
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 602 "diksam.y"
    {
            (yyval.expression) = dkc_create_basic_array_creation((yyvsp[(2) - (3)].basic_type_specifier), (yyvsp[(3) - (3)].array_dimension), NULL);
        }
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 606 "diksam.y"
    {
            (yyval.expression) = dkc_create_basic_array_creation((yyvsp[(2) - (4)].basic_type_specifier), (yyvsp[(3) - (4)].array_dimension), (yyvsp[(4) - (4)].array_dimension));
        }
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 610 "diksam.y"
    {
            (yyval.expression) = dkc_create_class_array_creation((yyvsp[(2) - (3)].type_specifier), (yyvsp[(3) - (3)].array_dimension), NULL);
        }
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 615 "diksam.y"
    {
            (yyval.expression) = dkc_create_class_array_creation((yyvsp[(2) - (4)].type_specifier), (yyvsp[(3) - (4)].array_dimension), (yyvsp[(4) - (4)].array_dimension));
        }
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 622 "diksam.y"
    {
            (yyval.array_dimension) = dkc_chain_array_dimension((yyvsp[(1) - (2)].array_dimension), (yyvsp[(2) - (2)].array_dimension));
        }
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 628 "diksam.y"
    {
            (yyval.array_dimension) = dkc_create_array_dimension((yyvsp[(2) - (3)].expression));
        }
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 634 "diksam.y"
    {
            (yyval.array_dimension) = dkc_create_array_dimension(NULL);
        }
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 638 "diksam.y"
    {
            (yyval.array_dimension) = dkc_chain_array_dimension((yyvsp[(1) - (3)].array_dimension),
                                           dkc_create_array_dimension(NULL));
        }
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 645 "diksam.y"
    {
            (yyval.expression_list) = NULL;
        }
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 649 "diksam.y"
    {
            (yyval.expression_list) = dkc_create_expression_list((yyvsp[(1) - (1)].expression));
        }
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 653 "diksam.y"
    {
            (yyval.expression_list) = dkc_chain_expression_list((yyvsp[(1) - (3)].expression_list), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 659 "diksam.y"
    {
          (yyval.statement) = dkc_create_expression_statement((yyvsp[(1) - (2)].expression));
        }
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 675 "diksam.y"
    {/*empty line*/
			(yyval.statement)=0;
		}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 681 "diksam.y"
    {
            (yyval.statement) = dkc_create_if_statement((yyvsp[(2) - (4)].expression), (yyvsp[(4) - (4)].block), NULL, NULL);
        }
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 685 "diksam.y"
    {
			//printf("IF-ELSE %d\n",dkc_get_current_compiler()->current_line_number);
            (yyval.statement) = dkc_create_if_statement((yyvsp[(2) - (6)].expression), (yyvsp[(4) - (6)].block), NULL, (yyvsp[(6) - (6)].block));
        }
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 690 "diksam.y"
    {
            (yyval.statement) = dkc_create_if_statement((yyvsp[(2) - (5)].expression), (yyvsp[(4) - (5)].block), (yyvsp[(5) - (5)].elsif), NULL);
        }
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 694 "diksam.y"
    {
            (yyval.statement) = dkc_create_if_statement((yyvsp[(2) - (7)].expression), (yyvsp[(4) - (7)].block), (yyvsp[(5) - (7)].elsif), (yyvsp[(7) - (7)].block));
        }
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 701 "diksam.y"
    {
            (yyval.elsif) = dkc_chain_elsif_list((yyvsp[(1) - (2)].elsif), (yyvsp[(2) - (2)].elsif));
        }
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 707 "diksam.y"
    {
            (yyval.elsif) = dkc_create_elsif((yyvsp[(2) - (4)].expression), (yyvsp[(4) - (4)].block));
        }
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 713 "diksam.y"
    {
            (yyval.identifier) = NULL;
        }
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 717 "diksam.y"
    {
            (yyval.identifier) = (yyvsp[(1) - (2)].identifier);
        }
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 723 "diksam.y"
    {
            (yyval.statement) = dkc_create_switch_statement((yyvsp[(2) - (5)].expression), (yyvsp[(4) - (5)].case_list), (yyvsp[(5) - (5)].block));
        }
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 730 "diksam.y"
    {
            (yyval.case_list) = dkc_chain_case((yyvsp[(1) - (2)].case_list), (yyvsp[(2) - (2)].case_list));
        }
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 736 "diksam.y"
    {
            (yyval.case_list) = dkc_create_one_case((yyvsp[(2) - (3)].expression_list), (yyvsp[(3) - (3)].block));
        }
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 742 "diksam.y"
    {
            (yyval.block) = NULL;
        }
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 746 "diksam.y"
    {
            (yyval.block) = (yyvsp[(2) - (2)].block);
        }
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 752 "diksam.y"
    {
            (yyval.expression_list) = dkc_create_expression_list((yyvsp[(1) - (1)].expression));
        }
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 756 "diksam.y"
    {
            (yyval.expression_list) = dkc_chain_expression_list((yyvsp[(1) - (3)].expression_list), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 762 "diksam.y"
    {
            (yyval.statement) = dkc_create_while_statement((yyvsp[(1) - (4)].identifier), (yyvsp[(3) - (4)].expression), (yyvsp[(4) - (4)].block));
        }
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 768 "diksam.y"
    {
            (yyval.statement) = dkc_create_for_statement((yyvsp[(1) - (8)].identifier), (yyvsp[(3) - (8)].expression), (yyvsp[(5) - (8)].expression), (yyvsp[(7) - (8)].expression), (yyvsp[(8) - (8)].block));
        }
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 774 "diksam.y"
    {
            (yyval.statement) = dkc_create_do_while_statement((yyvsp[(1) - (8)].identifier), (yyvsp[(3) - (8)].block), (yyvsp[(6) - (8)].expression));
        }
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 780 "diksam.y"
    {
            (yyval.statement) = dkc_create_foreach_statement((yyvsp[(1) - (8)].identifier), (yyvsp[(4) - (8)].identifier), (yyvsp[(6) - (8)].expression), (yyvsp[(8) - (8)].block));
        }
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 786 "diksam.y"
    {
            (yyval.expression) = NULL;
        }
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 793 "diksam.y"
    {
            (yyval.statement) = dkc_create_return_statement((yyvsp[(2) - (3)].expression));
        }
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 799 "diksam.y"
    {
            (yyval.identifier) = NULL;
        }
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 806 "diksam.y"
    {
            (yyval.statement) = dkc_create_break_statement((yyvsp[(2) - (3)].identifier));
        }
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 812 "diksam.y"
    {
            (yyval.statement) = dkc_create_continue_statement((yyvsp[(2) - (3)].identifier));
        }
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 818 "diksam.y"
    {
            (yyval.statement) = dkc_create_try_statement((yyvsp[(2) - (5)].block), (yyvsp[(3) - (5)].catch_clause), (yyvsp[(5) - (5)].block));
        }
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 822 "diksam.y"
    {
            (yyval.statement) = dkc_create_try_statement((yyvsp[(2) - (4)].block), NULL, (yyvsp[(4) - (4)].block));
        }
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 826 "diksam.y"
    {
            (yyval.statement) = dkc_create_try_statement((yyvsp[(2) - (3)].block), (yyvsp[(3) - (3)].catch_clause), NULL);
        }
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 833 "diksam.y"
    {
            (yyval.catch_clause) = dkc_chain_catch_list((yyvsp[(1) - (2)].catch_clause), (yyvsp[(2) - (2)].catch_clause));
        }
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 839 "diksam.y"
    {
            (yyval.catch_clause) = dkc_start_catch_clause();
        }
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 843 "diksam.y"
    {
            (yyval.catch_clause) = dkc_end_catch_clause((yyvsp[(2) - (5)].catch_clause), (yyvsp[(3) - (5)].type_specifier), (yyvsp[(4) - (5)].identifier), (yyvsp[(5) - (5)].block));
        }
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 849 "diksam.y"
    {
            (yyval.statement) = dkc_create_throw_statement((yyvsp[(2) - (3)].expression));
        }
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 853 "diksam.y"
    {
            (yyval.statement) = dkc_create_throw_statement(NULL);
        }
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 859 "diksam.y"
    {
            (yyval.statement) = dkc_create_declaration_statement(DVM_FALSE, (yyvsp[(4) - (5)].type_specifier), (yyvsp[(2) - (5)].identifier), NULL);
        }
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 863 "diksam.y"
    {
            (yyval.statement) = dkc_create_declaration_statement(DVM_FALSE, (yyvsp[(4) - (7)].type_specifier), (yyvsp[(2) - (7)].identifier), (yyvsp[(6) - (7)].expression));
        }
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 867 "diksam.y"
    {
            (yyval.statement) = dkc_create_declaration_statement(DVM_FALSE, (yyvsp[(4) - (5)].type_specifier), (yyvsp[(2) - (5)].identifier), NULL);
        }
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 871 "diksam.y"
    {
            (yyval.statement) = dkc_create_declaration_statement(DVM_TRUE, (yyvsp[(4) - (7)].type_specifier), (yyvsp[(2) - (7)].identifier), (yyvsp[(6) - (7)].expression));
        }
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 877 "diksam.y"
    {
            (yyval.block) = dkc_open_block(0);
        }
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 881 "diksam.y"
    {
            (yyval.block) = dkc_close_block((yyvsp[(2) - (4)].block), (yyvsp[(3) - (4)].statement_list));
        }
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 885 "diksam.y"
    {
            Block *empty_block = dkc_open_block(0);
            (yyval.block) = dkc_close_block(empty_block, NULL);
        }
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 893 "diksam.y"
    {
			(yyval.extends_list)=(yyvsp[(2) - (3)].extends_list);
		}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 897 "diksam.y"
    {(yyval.extends_list)=NULL;}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 902 "diksam.y"
    {
            dkc_start_class_definition(NULL, (yyvsp[(1) - (5)].class_or_interface), (yyvsp[(2) - (5)].identifier),(yyvsp[(3) - (5)].extends_list), (yyvsp[(4) - (5)].extends_list));
        }
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 906 "diksam.y"
    {
            dkc_class_define((yyvsp[(7) - (8)].member_declaration));
        }
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 911 "diksam.y"
    {
            dkc_start_class_definition(&(yyvsp[(1) - (6)].class_or_member_modifier), (yyvsp[(2) - (6)].class_or_interface), (yyvsp[(3) - (6)].identifier),(yyvsp[(4) - (6)].extends_list), (yyvsp[(5) - (6)].extends_list));
        }
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 914 "diksam.y"
    {
            dkc_class_define((yyvsp[(8) - (9)].member_declaration));
        }
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 918 "diksam.y"
    {
            dkc_start_class_definition(NULL, (yyvsp[(1) - (5)].class_or_interface), (yyvsp[(2) - (5)].identifier),(yyvsp[(3) - (5)].extends_list), (yyvsp[(4) - (5)].extends_list));
        }
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 922 "diksam.y"
    {
            dkc_class_define(NULL);
        }
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 927 "diksam.y"
    {
            dkc_start_class_definition(&(yyvsp[(1) - (6)].class_or_member_modifier), (yyvsp[(2) - (6)].class_or_interface), (yyvsp[(3) - (6)].identifier),(yyvsp[(4) - (6)].extends_list), (yyvsp[(5) - (6)].extends_list));
        }
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 931 "diksam.y"
    {
            dkc_class_define(NULL);
        }
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 938 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_chain_class_or_member_modifier((yyvsp[(1) - (2)].class_or_member_modifier), (yyvsp[(2) - (2)].class_or_member_modifier));
        }
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 945 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(VIRTUAL_MODIFIER);
        }
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 949 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(OVERRIDE_MODIFIER);
        }
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 953 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(ABSTRACT_MODIFIER);
        }
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 959 "diksam.y"
    {
            (yyval.class_or_interface) = DVM_CLASS_DEFINITION;
        }
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 963 "diksam.y"
    {
            (yyval.class_or_interface) = DVM_INTERFACE_DEFINITION;
        }
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 969 "diksam.y"
    {
            (yyval.extends_list) = NULL;
        }
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 973 "diksam.y"
    {
            (yyval.extends_list) = (yyvsp[(2) - (2)].extends_list);
        }
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 979 "diksam.y"
    {
            (yyval.extends_list) = dkc_create_extends_list((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 983 "diksam.y"
    {
            (yyval.extends_list) = dkc_chain_extends_list((yyvsp[(1) - (3)].extends_list), (yyvsp[(3) - (3)].identifier));
        }
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 990 "diksam.y"
    {
            (yyval.member_declaration) = dkc_chain_member_declaration((yyvsp[(1) - (2)].member_declaration), (yyvsp[(2) - (2)].member_declaration));
        }
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 1000 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_method_member(NULL, (yyvsp[(1) - (1)].function_definition), DVM_FALSE);
        }
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 1004 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_method_member(&(yyvsp[(1) - (2)].class_or_member_modifier), (yyvsp[(2) - (2)].function_definition), DVM_FALSE);
        }
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 1008 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_method_member(NULL, (yyvsp[(1) - (1)].function_definition), DVM_TRUE);
        }
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 1012 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_method_member(&(yyvsp[(1) - (2)].class_or_member_modifier), (yyvsp[(2) - (2)].function_definition), DVM_TRUE);
        }
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 1018 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define((yyvsp[(7) - (9)].type_specifier), (yyvsp[(2) - (9)].identifier), (yyvsp[(4) - (9)].parameter_list), (yyvsp[(8) - (9)].exception_list), (yyvsp[(9) - (9)].block));
        }
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 1022 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define((yyvsp[(6) - (8)].type_specifier), (yyvsp[(2) - (8)].identifier), NULL, (yyvsp[(7) - (8)].exception_list), (yyvsp[(8) - (8)].block));
        }
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 1026 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define((yyvsp[(8) - (10)].type_specifier), (yyvsp[(3) - (10)].identifier), (yyvsp[(5) - (10)].parameter_list), (yyvsp[(9) - (10)].exception_list), NULL);
        }
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 1030 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define((yyvsp[(7) - (9)].type_specifier), (yyvsp[(3) - (9)].identifier), NULL, (yyvsp[(8) - (9)].exception_list), NULL);
        }
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 1034 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define(0, (yyvsp[(2) - (7)].identifier), (yyvsp[(4) - (7)].parameter_list), (yyvsp[(6) - (7)].exception_list), (yyvsp[(7) - (7)].block));
        }
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 1038 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define(0, (yyvsp[(2) - (6)].identifier), NULL, (yyvsp[(5) - (6)].exception_list), (yyvsp[(6) - (6)].block));
        }
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 1042 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define(0, (yyvsp[(3) - (8)].identifier), (yyvsp[(5) - (8)].parameter_list), (yyvsp[(7) - (8)].exception_list), NULL);
        }
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 1046 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define(0, (yyvsp[(3) - (7)].identifier), NULL, (yyvsp[(6) - (7)].exception_list), NULL);
        }
    break;

  case 238:

/* Line 1455 of yacc.c  */
#line 1052 "diksam.y"
    {
			(yyval.apost)=0;
		}
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 1056 "diksam.y"
    {
			(yyval.apost)=1;
		}
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 1062 "diksam.y"
    {
            (yyval.exception_list) = NULL;
        }
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 1066 "diksam.y"
    {
            (yyval.exception_list) = (yyvsp[(2) - (2)].exception_list);
        }
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 1072 "diksam.y"
    {
            (yyval.exception_list) = dkc_create_throws((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 1076 "diksam.y"
    {
            (yyval.exception_list) = dkc_chain_exception_list((yyvsp[(1) - (3)].exception_list), (yyvsp[(3) - (3)].identifier));
        }
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 1082 "diksam.y"
    {
            (yyval.function_definition) = dkc_constructor_function_define((yyvsp[(2) - (7)].identifier), (yyvsp[(4) - (7)].parameter_list), (yyvsp[(6) - (7)].exception_list), (yyvsp[(7) - (7)].block));
        }
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 1086 "diksam.y"
    {
            (yyval.function_definition) = dkc_constructor_function_define((yyvsp[(2) - (6)].identifier), NULL, (yyvsp[(5) - (6)].exception_list), (yyvsp[(6) - (6)].block));
        }
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 1090 "diksam.y"
    {
            (yyval.function_definition) = dkc_constructor_function_define((yyvsp[(3) - (8)].identifier), (yyvsp[(5) - (8)].parameter_list), (yyvsp[(7) - (8)].exception_list), NULL);
        }
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 1094 "diksam.y"
    {
            (yyval.function_definition) = dkc_constructor_function_define((yyvsp[(3) - (7)].identifier), NULL, (yyvsp[(6) - (7)].exception_list), NULL);
        }
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 1100 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(PUBLIC_MODIFIER);
        }
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 1104 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(PRIVATE_MODIFIER);
        }
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 1110 "diksam.y"
    {
            (yyval.expression) = NULL;
        }
    break;

  case 251:

/* Line 1455 of yacc.c  */
#line 1114 "diksam.y"
    {
            (yyval.expression) = (yyvsp[(2) - (2)].expression);
        }
    break;

  case 252:

/* Line 1455 of yacc.c  */
#line 1120 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(NULL, DVM_FALSE, (yyvsp[(4) - (6)].type_specifier), (yyvsp[(2) - (6)].identifier), (yyvsp[(5) - (6)].expression));
        }
    break;

  case 253:

/* Line 1455 of yacc.c  */
#line 1125 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(&(yyvsp[(1) - (6)].class_or_member_modifier), DVM_FALSE, (yyvsp[(4) - (6)].type_specifier), (yyvsp[(2) - (6)].identifier), (yyvsp[(5) - (6)].expression));
        }
    break;

  case 254:

/* Line 1455 of yacc.c  */
#line 1129 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(NULL, DVM_TRUE, (yyvsp[(4) - (6)].type_specifier), (yyvsp[(2) - (6)].identifier), (yyvsp[(5) - (6)].expression));
        }
    break;

  case 255:

/* Line 1455 of yacc.c  */
#line 1134 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(&(yyvsp[(1) - (7)].class_or_member_modifier), DVM_TRUE, (yyvsp[(5) - (7)].type_specifier), (yyvsp[(3) - (7)].identifier), (yyvsp[(6) - (7)].expression));
        }
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 1138 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(&(yyvsp[(2) - (7)].class_or_member_modifier), DVM_TRUE, (yyvsp[(5) - (7)].type_specifier), (yyvsp[(3) - (7)].identifier), (yyvsp[(6) - (7)].expression));
        }
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 1144 "diksam.y"
    {
            dkc_create_delegate_definition((yyvsp[(8) - (10)].type_specifier), (yyvsp[(2) - (10)].identifier), (yyvsp[(4) - (10)].parameter_list), (yyvsp[(9) - (10)].exception_list),(yyvsp[(5) - (10)].apost));
        }
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 1148 "diksam.y"
    {
            dkc_create_delegate_definition((yyvsp[(7) - (9)].type_specifier), (yyvsp[(2) - (9)].identifier), NULL, (yyvsp[(8) - (9)].exception_list),(yyvsp[(4) - (9)].apost));
        }
    break;

  case 259:

/* Line 1455 of yacc.c  */
#line 1154 "diksam.y"
    {
            dkc_create_enum_definition((yyvsp[(2) - (5)].identifier), (yyvsp[(4) - (5)].enumerator));
        }
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 1158 "diksam.y"
    {
            dkc_create_enum_definition((yyvsp[(2) - (6)].identifier), (yyvsp[(4) - (6)].enumerator));
        }
    break;

  case 261:

/* Line 1455 of yacc.c  */
#line 1164 "diksam.y"
    {
            (yyval.enumerator) = dkc_create_enumerator((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 262:

/* Line 1455 of yacc.c  */
#line 1168 "diksam.y"
    {
            (yyval.enumerator) = dkc_chain_enumerator((yyvsp[(1) - (3)].enumerator), (yyvsp[(3) - (3)].identifier));
        }
    break;

  case 263:

/* Line 1455 of yacc.c  */
#line 1174 "diksam.y"
    {
            dkc_create_const_definition(NULL, (yyvsp[(2) - (5)].identifier), (yyvsp[(4) - (5)].expression));
        }
    break;

  case 264:

/* Line 1455 of yacc.c  */
#line 1178 "diksam.y"
    {
            dkc_create_const_definition((yyvsp[(2) - (4)].type_specifier), (yyvsp[(3) - (4)].identifier), NULL);
        }
    break;

  case 265:

/* Line 1455 of yacc.c  */
#line 1184 "diksam.y"
    {
			(yyval.apost)=0;
		}
    break;

  case 266:

/* Line 1455 of yacc.c  */
#line 1188 "diksam.y"
    {
			(yyval.apost)=1;
		}
    break;

  case 267:

/* Line 1455 of yacc.c  */
#line 1192 "diksam.y"
    {
			(yyval.apost)=-1;
		}
    break;

  case 268:

/* Line 1455 of yacc.c  */
#line 1198 "diksam.y"
    {
            (yyval.block) = dkc_open_block((yyvsp[(2) - (2)].apost));
			//printf("E1 %d\n",dkc_get_current_compiler());
        }
    break;

  case 269:

/* Line 1455 of yacc.c  */
#line 1203 "diksam.y"
    {
            (yyval.block) = dkc_close_block((yyvsp[(3) - (5)].block), (yyvsp[(4) - (5)].statement_list));
			//printf("C1 %d\n",dkc_get_current_compiler()->current_line_number);
        }
    break;

  case 270:

/* Line 1455 of yacc.c  */
#line 1208 "diksam.y"
    {
            Block *empty_block = dkc_open_block(0);
            (yyval.block) = dkc_close_block(empty_block, NULL);
			//printf("C2 %d\n",dkc_get_current_compiler()->current_line_number);
        }
    break;



/* Line 1455 of yacc.c  */
#line 4155 "y.tab.c"
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
#line 1214 "diksam.y"


