
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
#define YYLAST   985

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  103
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  94
/* YYNRULES -- Number of rules.  */
#define YYNRULES  261
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
       0,     0,     3,     5,     8,     9,    12,    14,    16,    18,
      20,    23,    27,    29,    33,    35,    38,    43,    45,    47,
      49,    51,    53,    55,    57,    59,    61,    63,    65,    67,
      69,    71,    73,    77,    81,    85,    87,    89,    91,    92,
      99,   100,   103,   106,   118,   129,   139,   148,   159,   169,
     178,   186,   188,   192,   198,   200,   204,   206,   209,   211,
     215,   217,   221,   223,   225,   227,   229,   231,   233,   235,
     239,   241,   245,   247,   251,   255,   257,   261,   265,   269,
     273,   275,   279,   283,   285,   289,   293,   297,   301,   305,
     309,   311,   314,   317,   320,   322,   325,   328,   332,   334,
     336,   338,   340,   345,   350,   354,   359,   363,   367,   372,
     374,   376,   378,   380,   382,   384,   386,   388,   390,   392,
     397,   402,   408,   415,   423,   427,   432,   436,   441,   445,
     450,   452,   455,   459,   462,   466,   467,   469,   473,   476,
     478,   480,   482,   484,   486,   488,   490,   492,   494,   496,
     498,   500,   502,   507,   514,   520,   528,   530,   533,   538,
     539,   542,   548,   550,   553,   557,   558,   561,   563,   567,
     572,   581,   590,   599,   600,   602,   606,   607,   609,   613,
     617,   623,   628,   632,   634,   637,   638,   644,   648,   651,
     657,   665,   671,   679,   680,   685,   688,   689,   697,   698,
     707,   708,   715,   716,   724,   726,   729,   731,   733,   735,
     737,   739,   741,   742,   745,   747,   751,   753,   756,   758,
     760,   762,   765,   767,   770,   780,   789,   800,   810,   818,
     825,   834,   842,   843,   846,   847,   850,   852,   856,   864,
     871,   880,   888,   890,   892,   893,   896,   903,   910,   917,
     925,   933,   944,   954,   960,   967,   969,   973,   979,   984,
     985,   990
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     104,     0,    -1,   105,    -1,   104,   111,    -1,    -1,   106,
     109,    -1,   106,    -1,   109,    -1,   116,    -1,   107,    -1,
     106,   107,    -1,    74,   108,    98,    -1,     7,    -1,   108,
      53,     7,    -1,   110,    -1,   109,   110,    -1,    75,   108,
       7,    98,    -1,   120,    -1,   170,    -1,   143,    -1,   191,
      -1,   192,    -1,   194,    -1,    66,    -1,    67,    -1,    68,
      -1,    69,    -1,    70,    -1,    71,    -1,    72,    -1,    89,
      -1,     7,    -1,   112,    27,    28,    -1,     7,    27,    28,
      -1,   114,    27,    28,    -1,   112,    -1,   114,    -1,   113,
      -1,    -1,   102,     7,   117,    98,   118,    97,    -1,    -1,
     118,   119,    -1,   118,   170,    -1,    99,    93,     7,    23,
     121,   184,    24,    94,   115,   185,    98,    -1,    99,    93,
       7,    23,   184,    24,    94,   115,   185,    98,    -1,    99,
     100,     7,    23,   121,   184,    24,   185,    98,    -1,    99,
     100,     7,    23,   184,    24,   185,    98,    -1,    93,     7,
      23,   121,   184,    24,    94,   115,   185,   195,    -1,    93,
       7,    23,   184,    24,    94,   115,   185,   195,    -1,   100,
       7,    23,   121,   184,    24,   185,   195,    -1,   100,     7,
      23,   184,    24,   185,   195,    -1,   119,    -1,     7,    94,
     115,    -1,   121,    31,     7,    94,   115,    -1,   125,    -1,
     122,    31,   125,    -1,   143,    -1,   123,   143,    -1,   125,
      -1,   124,    31,   125,    -1,   127,    -1,   135,   126,   125,
      -1,    32,    -1,    54,    -1,    55,    -1,    56,    -1,    57,
      -1,    58,    -1,   128,    -1,   127,    34,   128,    -1,   129,
      -1,   128,    33,   129,    -1,   130,    -1,   129,    35,   130,
      -1,   129,    36,   130,    -1,   131,    -1,   130,    37,   131,
      -1,   130,    38,   131,    -1,   130,    39,   131,    -1,   130,
      40,   131,    -1,   132,    -1,   131,    41,   132,    -1,   131,
      42,   132,    -1,   133,    -1,   132,    43,   133,    -1,   132,
      44,   133,    -1,   132,    45,   133,    -1,   132,    46,   133,
      -1,   132,    47,   133,    -1,   132,    48,   133,    -1,   134,
      -1,    42,   133,    -1,    52,   133,    -1,    49,   133,    -1,
     135,    -1,   135,    59,    -1,   135,    60,    -1,   135,    86,
     115,    -1,   136,    -1,   138,    -1,     7,    -1,     8,    -1,
     136,    27,   124,    28,    -1,     7,    27,   124,    28,    -1,
     135,    53,     7,    -1,   135,    23,   122,    24,    -1,   135,
      23,    24,    -1,    23,   124,    24,    -1,   135,    87,   115,
      88,    -1,     3,    -1,     4,    -1,     5,    -1,     6,    -1,
      50,    -1,    51,    -1,    22,    -1,   137,    -1,    83,    -1,
      84,    -1,    73,    89,    23,    24,    -1,    73,     7,    23,
      24,    -1,    73,     7,    23,   122,    24,    -1,    73,     7,
      53,     7,    23,    24,    -1,    73,     7,    53,     7,    23,
     122,    24,    -1,    25,   142,    26,    -1,    25,   142,    31,
      26,    -1,    73,   112,   139,    -1,    73,   112,   139,   141,
      -1,    73,   113,   139,    -1,    73,   113,   139,   141,    -1,
     140,    -1,   139,   140,    -1,    27,   124,    28,    -1,    27,
      28,    -1,   141,    27,    28,    -1,    -1,   125,    -1,   142,
      31,   125,    -1,   124,    98,    -1,   144,    -1,   148,    -1,
     153,    -1,   154,    -1,   155,    -1,   156,    -1,   158,    -1,
     160,    -1,   161,    -1,   162,    -1,   166,    -1,   167,    -1,
      98,    -1,     9,   124,    95,   195,    -1,     9,   124,    95,
     195,    10,   195,    -1,     9,   124,    95,   195,   145,    -1,
       9,   124,    95,   195,   145,    10,   195,    -1,   146,    -1,
     145,   146,    -1,    11,   124,    95,   195,    -1,    -1,     7,
      30,    -1,    12,   124,    98,   149,   151,    -1,   150,    -1,
     149,   150,    -1,    13,   152,   195,    -1,    -1,    14,   195,
      -1,   125,    -1,   142,    31,   125,    -1,   147,    15,   124,
     195,    -1,   147,    17,   157,    29,   157,    29,   157,   195,
      -1,   147,    16,   168,    15,    23,   124,    24,    98,    -1,
     147,    18,    23,     7,    30,   124,    24,   168,    -1,    -1,
     124,    -1,    19,   157,    98,    -1,    -1,     7,    -1,    20,
     159,    98,    -1,    21,   159,    98,    -1,    61,   195,   163,
      63,   195,    -1,    61,   195,    63,   168,    -1,    61,   195,
     163,    -1,   164,    -1,   163,   164,    -1,    -1,    62,   165,
     115,     7,   195,    -1,    64,   124,    98,    -1,    64,    98,
      -1,    96,     7,    94,   115,    98,    -1,    96,     7,    94,
     115,    32,   124,    98,    -1,    90,     7,    94,   115,    98,
      -1,    90,     7,    94,   115,    32,   124,    98,    -1,    -1,
      25,   169,   123,    26,    -1,    25,    26,    -1,    -1,   177,
       7,   178,    98,   171,   180,    97,    -1,    -1,   175,   177,
       7,   178,    98,   172,   180,    97,    -1,    -1,   177,     7,
     178,    98,   173,    97,    -1,    -1,   175,   177,     7,   178,
      98,   174,    97,    -1,   176,    -1,   175,   176,    -1,   188,
      -1,    80,    -1,    81,    -1,    82,    -1,    76,    -1,    77,
      -1,    -1,    30,   179,    -1,     7,    -1,   179,    31,     7,
      -1,   181,    -1,   180,   181,    -1,   182,    -1,   190,    -1,
     183,    -1,   175,   183,    -1,   187,    -1,   175,   187,    -1,
      93,     7,    23,   121,    24,    94,   115,   185,   195,    -1,
      93,     7,    23,    24,    94,   115,   185,   195,    -1,    99,
      93,     7,    23,   121,    24,    94,   115,   185,    98,    -1,
      99,    93,     7,    23,    24,    94,   115,   185,    98,    -1,
     100,     7,    23,   121,    24,   185,   195,    -1,   100,     7,
      23,    24,   185,   195,    -1,    99,   100,     7,    23,   121,
      24,   185,    98,    -1,    99,   100,     7,    23,    24,   185,
      98,    -1,    -1,    31,   101,    -1,    -1,    65,   186,    -1,
       7,    -1,   186,    31,     7,    -1,    85,     7,    23,   121,
      24,   185,   195,    -1,    85,     7,    23,    24,   185,   195,
      -1,    99,    85,     7,    23,   121,    24,   185,    98,    -1,
      99,    85,     7,    23,    24,   185,    98,    -1,    78,    -1,
      79,    -1,    -1,    32,   124,    -1,    96,     7,    94,   115,
     189,    98,    -1,   175,     7,    94,   115,   189,    98,    -1,
      90,     7,    94,   115,   189,    98,    -1,   175,    90,     7,
      94,   115,   189,    98,    -1,    90,   175,     7,    94,   115,
     189,    98,    -1,    89,     7,    23,   121,   184,    24,    94,
     115,   185,    98,    -1,    89,     7,    23,   184,    24,    94,
     115,   185,    98,    -1,    91,     7,    25,   193,    26,    -1,
      91,     7,    25,   193,    31,    26,    -1,     7,    -1,   193,
      31,     7,    -1,    92,     7,    32,   124,    98,    -1,    92,
     115,     7,    98,    -1,    -1,    98,   196,   123,    97,    -1,
      98,    97,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    96,    96,    97,   101,   104,   108,   112,   116,   122,
     123,   129,   135,   139,   145,   146,   152,   158,   159,   160,
     167,   168,   169,   172,   176,   180,   184,   188,   192,   196,
     200,   206,   212,   218,   224,   230,   234,   235,   240,   239,
     248,   251,   252,   255,   259,   263,   267,   274,   278,   282,
     286,   290,   293,   297,   303,   307,   313,   317,   323,   324,
     330,   331,   337,   341,   345,   349,   353,   357,   363,   364,
     370,   371,   377,   378,   382,   388,   389,   393,   397,   401,
     407,   408,   412,   418,   419,   423,   427,   431,   435,   439,
     445,   446,   450,   454,   460,   461,   465,   469,   475,   476,
     477,   481,   487,   491,   496,   500,   504,   508,   512,   516,
     517,   518,   519,   520,   524,   528,   532,   533,   537,   541,
     545,   549,   553,   557,   563,   567,   573,   577,   581,   585,
     592,   593,   599,   605,   609,   617,   620,   624,   630,   634,
     635,   636,   637,   638,   639,   640,   641,   642,   643,   644,
     645,   646,   652,   656,   661,   665,   671,   672,   678,   685,
     688,   694,   700,   701,   707,   714,   717,   723,   727,   733,
     739,   745,   751,   758,   761,   764,   771,   774,   777,   783,
     789,   793,   797,   803,   804,   811,   810,   820,   824,   830,
     834,   838,   842,   849,   848,   856,   865,   863,   874,   872,
     881,   880,   890,   888,   899,   900,   906,   907,   911,   915,
     921,   925,   932,   935,   941,   945,   951,   952,   958,   959,
     962,   966,   970,   974,   980,   984,   988,   992,   996,  1000,
    1004,  1008,  1015,  1018,  1025,  1028,  1034,  1038,  1044,  1048,
    1052,  1056,  1062,  1066,  1073,  1076,  1082,  1086,  1091,  1095,
    1100,  1106,  1110,  1116,  1120,  1126,  1130,  1136,  1140,  1147,
    1146,  1156
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
     118,   118,   118,   119,   119,   119,   119,   120,   120,   120,
     120,   120,   121,   121,   122,   122,   123,   123,   124,   124,
     125,   125,   126,   126,   126,   126,   126,   126,   127,   127,
     128,   128,   129,   129,   129,   130,   130,   130,   130,   130,
     131,   131,   131,   132,   132,   132,   132,   132,   132,   132,
     133,   133,   133,   133,   134,   134,   134,   134,   135,   135,
     135,   135,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   137,   137,   138,   138,   138,   138,
     139,   139,   140,   141,   141,   142,   142,   142,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   144,   144,   144,   144,   145,   145,   146,   147,
     147,   148,   149,   149,   150,   151,   151,   152,   152,   153,
     154,   155,   156,   157,   157,   158,   159,   159,   160,   161,
     162,   162,   162,   163,   163,   165,   164,   166,   166,   167,
     167,   167,   167,   169,   168,   168,   171,   170,   172,   170,
     173,   170,   174,   170,   175,   175,   176,   176,   176,   176,
     177,   177,   178,   178,   179,   179,   180,   180,   181,   181,
     182,   182,   182,   182,   183,   183,   183,   183,   183,   183,
     183,   183,   184,   184,   185,   185,   186,   186,   187,   187,
     187,   187,   188,   188,   189,   189,   190,   190,   190,   190,
     190,   191,   191,   192,   192,   193,   193,   194,   194,   196,
     195,   195
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     1,     1,
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
       4,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       4,     0,     0,     0,   159,     2,     6,     9,     7,    14,
       8,    12,     0,     0,    38,     1,   109,   110,   111,   112,
     100,   101,     0,     0,   173,   176,   176,   115,     0,   135,
       0,     0,   113,   114,     0,     0,     0,     0,   210,   211,
     242,   243,   207,   208,   209,   117,   118,     0,     0,     0,
       0,     0,     0,   151,     0,     0,     3,    51,    17,     0,
      58,    60,    68,    70,    72,    75,    80,    83,    90,    94,
      98,   116,    99,    19,   139,     0,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,    18,     0,   204,
       0,   206,    20,    21,    22,    10,     5,    15,     0,    11,
       0,     0,     0,   160,   100,     0,     0,   174,     0,   177,
       0,     0,     0,   136,     0,    91,    94,    93,    92,   259,
       0,   188,     0,    31,    23,    24,    25,    26,    27,    28,
      29,    30,     0,     0,     0,     0,     0,    31,    30,    35,
      37,    36,     0,     0,     0,     0,     0,     0,     0,   138,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    62,     0,    63,
      64,    65,    66,    67,    95,    96,     0,     0,     0,     0,
       0,     0,   173,     0,   205,     0,   212,    13,    16,    40,
       0,     0,     0,   175,   178,   179,   107,   124,     0,   261,
     159,   185,     0,   182,   183,   187,     0,     0,     0,     0,
     126,   130,   128,   232,     0,     0,     0,     0,     0,     0,
       0,   232,     0,     0,     0,   232,    59,    69,    71,    73,
      74,    76,    77,    78,    79,    81,    82,    84,    85,    86,
      87,    88,    89,   106,     0,    54,   104,    31,    97,     0,
      61,     0,     0,   193,     0,     0,     0,   212,     0,     0,
       0,   103,   152,   135,   165,   162,   125,   137,   159,    56,
       0,   181,     0,   184,   120,     0,     0,   119,     0,     0,
     131,   127,   129,     0,     0,   232,     0,     0,   255,     0,
      33,     0,    32,    34,   258,   232,     0,     0,   232,   232,
     232,     0,   105,     0,   108,   102,   169,   195,   159,     0,
     173,     0,     0,   214,   213,   196,    39,    41,    42,     0,
       0,   154,   156,   136,     0,     0,     0,   163,   161,   260,
      57,     0,   180,   121,     0,   132,   133,     0,     0,   233,
       0,     0,     0,     0,   191,   253,     0,   257,     0,     0,
       0,   189,   232,     0,   232,     0,     0,   234,    55,   159,
       0,     0,     0,   198,     0,     0,     0,   153,     0,     0,
     157,     0,   164,   166,     0,   122,     0,   134,    52,     0,
       0,     0,     0,   256,   254,     0,     0,     0,     0,     0,
       0,   234,   234,     0,     0,   194,     0,   173,     0,     0,
       0,   215,     0,     0,     0,     0,     0,     0,     0,     0,
     216,   218,   220,   222,   219,   201,     0,   155,   137,   186,
     123,     0,     0,   234,   192,     0,   234,   190,     0,     0,
     234,     0,     0,   236,   235,    50,     0,     0,     0,     0,
     203,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   221,   223,   197,   217,   158,    53,   234,     0,
     234,     0,     0,   234,     0,    46,    49,     0,   171,   170,
     172,   199,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   252,     0,    48,   234,     0,    45,
     237,   234,     0,   244,     0,     0,     0,   244,     0,     0,
       0,   234,     0,   244,     0,   251,    47,     0,    44,     0,
     234,     0,     0,     0,   244,     0,     0,     0,   234,     0,
       0,     0,   234,     0,     0,   234,     0,   244,    43,   239,
       0,   245,   248,     0,   234,     0,   246,     0,   234,     0,
       0,     0,   234,   229,     0,   247,     0,   238,   250,     0,
     234,   241,     0,   234,     0,   231,     0,   228,   249,   225,
       0,   240,     0,   234,   230,   224,   227,     0,   226
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,     7,    12,     8,     9,    56,   139,
     140,   141,   142,    10,   101,   260,    57,    58,   285,   244,
     268,    59,    60,   178,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,   210,   211,   281,   114,
     269,    74,   321,   322,    75,    76,   264,   265,   328,   325,
      77,    78,    79,    80,   108,    81,   110,    82,    83,    84,
     203,   204,   270,    85,    86,   254,   308,    87,   365,   399,
     366,   400,   408,    89,    90,   259,   314,   409,   410,   411,
     412,   286,   394,   434,   413,    91,   513,   414,    92,    93,
     289,    94,   120,   200
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -376
static const yytype_int16 yypact[] =
{
      78,    49,    49,    61,   419,  -376,   228,  -376,    -3,  -376,
    -376,  -376,   -12,    18,  -376,  -376,  -376,  -376,  -376,  -376,
     135,  -376,   877,   877,   877,    92,    92,  -376,   877,   877,
     877,   877,  -376,  -376,   877,    23,    24,    62,  -376,  -376,
    -376,  -376,  -376,  -376,  -376,  -376,  -376,   106,   116,   118,
     165,   132,   134,  -376,    71,   138,  -376,  -376,  -376,    -7,
    -376,   127,   148,   214,   279,   267,   305,  -376,  -376,   898,
     158,  -376,  -376,  -376,  -376,   365,  -376,  -376,  -376,  -376,
    -376,  -376,  -376,  -376,  -376,  -376,  -376,  -376,   316,  -376,
     208,  -376,  -376,  -376,  -376,  -376,    -3,  -376,   211,  -376,
     105,   123,   877,  -376,   213,   -18,     2,   199,   140,  -376,
     167,   178,   142,  -376,   175,  -376,   271,  -376,  -376,   164,
     260,  -376,     5,    17,  -376,  -376,  -376,  -376,  -376,  -376,
    -376,   255,   236,   236,   257,   195,   261,   258,  -376,   265,
    -376,   272,   294,   283,   217,   313,   327,   338,   877,  -376,
     877,   877,   877,   877,   877,   877,   877,   877,   877,   877,
     877,   877,   877,   877,   877,   877,   761,  -376,   358,  -376,
    -376,  -376,  -376,  -376,  -376,  -376,   384,   384,   877,   877,
     877,   342,   877,   345,  -376,   362,   341,  -376,  -376,  -376,
      26,    23,   359,  -376,  -376,  -376,  -376,  -376,   813,  -376,
     709,  -376,   342,   264,  -376,  -376,   773,   366,   352,   877,
     350,  -376,   350,    27,   384,   371,   356,   877,   372,   373,
     301,    27,   384,   397,   398,    27,  -376,   148,   214,   279,
     279,   267,   267,   267,   267,   305,   305,  -376,  -376,  -376,
    -376,  -376,  -376,  -376,   153,  -376,  -376,   402,  -376,   344,
    -376,    56,     6,   404,   418,   405,   428,   341,   429,   339,
     473,  -376,   303,   877,   319,  -376,  -376,  -376,   517,  -376,
     384,  -376,    23,  -376,  -376,   155,   420,  -376,   169,   825,
    -376,   421,   421,   351,   346,   415,   425,    12,  -376,   274,
    -376,     7,  -376,  -376,  -376,   415,   433,    20,    27,    27,
     415,   434,  -376,   877,  -376,  -376,  -376,  -376,   709,   436,
     877,   430,   364,  -376,   432,   367,  -376,  -376,  -376,    23,
     877,   326,  -376,   368,   441,    23,    23,  -376,  -376,  -376,
    -376,   458,  -376,  -376,   865,  -376,  -376,   439,   384,  -376,
      13,   450,   381,   877,  -376,  -376,    36,  -376,   452,   383,
     877,  -376,   415,   454,   415,   455,   457,   417,  -376,   613,
     877,   456,   877,   387,   479,   657,   390,  -376,    -5,    23,
    -376,   877,  -376,  -376,    23,  -376,   174,  -376,  -376,   394,
     395,   384,     8,  -376,  -376,   399,   384,    11,   467,   400,
     480,   417,   417,   498,    23,  -376,   192,   877,   196,   657,
     409,  -376,   500,   163,   506,   507,    83,   509,   129,   495,
    -376,  -376,  -376,  -376,  -376,  -376,    23,  -376,   435,  -376,
    -376,   384,   384,   417,  -376,   384,   417,  -376,   437,   384,
     417,   443,    23,  -376,   496,  -376,   445,    23,   342,   588,
    -376,   505,   438,   263,   511,   451,   523,   528,   537,   524,
     462,   539,  -376,  -376,  -376,  -376,  -376,  -376,   417,   459,
     417,    23,   384,   417,   460,  -376,  -376,   541,  -376,  -376,
    -376,  -376,    43,   384,   466,    54,   384,   538,   540,   542,
      57,   384,   468,   481,  -376,    23,  -376,   417,   484,  -376,
    -376,   417,   224,   532,   384,   477,   227,   532,    91,   113,
     120,   417,   240,   532,   384,  -376,  -376,   485,  -376,    23,
     417,   577,   877,   488,   532,   384,   493,   491,   417,   242,
     499,   250,   417,   251,    23,   417,   501,   532,  -376,  -376,
      23,   199,  -376,   504,   417,   384,  -376,   508,   417,   384,
     502,   510,   417,  -376,    23,  -376,   512,  -376,  -376,    23,
     417,  -376,   513,   417,   384,  -376,   514,  -376,  -376,  -376,
      23,  -376,   525,   417,  -376,  -376,  -376,   526,  -376
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -376,  -376,  -376,  -376,   591,   596,   597,    15,  -376,   567,
     568,  -376,  -169,  -376,  -376,  -376,   349,  -376,  -203,  -194,
     318,   -22,   -24,  -376,  -376,   478,   476,   203,   232,   204,
      29,  -376,   253,  -376,  -376,  -376,   497,   -93,   431,   374,
       0,  -376,  -376,   308,  -376,  -376,  -376,   376,  -376,  -376,
    -376,  -376,  -376,  -376,  -172,  -376,   605,  -376,  -376,  -376,
    -376,   442,  -376,  -376,  -376,  -191,  -376,   382,  -376,  -376,
    -376,  -376,    -1,   -79,   553,   389,  -376,   245,  -374,  -376,
     239,  -206,  -375,  -376,   241,  -376,  -301,  -376,  -376,  -376,
    -376,  -376,  -170,  -376
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -203
static const yytype_int16 yytable[] =
{
     105,   106,   107,    88,    73,   113,   112,   248,   249,   184,
     255,   271,   275,   148,   122,   296,   431,   432,   295,   301,
     379,   262,   300,    97,   148,   100,   148,    16,    17,    18,
      19,   104,    21,   148,   283,   455,   148,   148,   148,   148,
     206,    98,   148,   383,   343,   287,    27,    28,   459,    29,
     283,   461,   350,   297,   261,   464,    11,   148,   284,   115,
     117,   283,   384,   118,   283,   455,    30,   491,    14,   123,
     207,    98,     2,    31,    32,    33,    34,   191,   495,   341,
     190,   501,   306,   483,   305,   485,    99,   148,   488,   348,
     416,   149,   353,   355,   356,   352,   354,    37,   283,   109,
     192,   331,   332,   205,   119,   347,   424,    45,    46,   427,
     344,    97,   507,   134,   339,   518,   509,   280,   351,   280,
     283,   119,   121,   135,   226,   136,   524,   283,   124,   125,
     126,   127,   128,   129,   130,   530,   450,   520,   361,   143,
     376,   144,   245,   537,   522,   147,   388,   541,   390,   367,
     544,   131,     1,     2,   250,   372,   373,   251,   252,   549,
     107,   150,   102,   552,   145,   103,   196,   556,   446,   378,
     442,   146,   137,   148,   267,   560,   447,   302,   562,   333,
       3,   151,   245,   448,   303,   179,   303,   278,   567,   237,
     238,   239,   240,   241,   242,   291,   517,   335,   420,   417,
     148,   197,   526,   188,   419,   303,   198,    40,    41,    42,
      43,    44,   423,   533,   402,   186,   436,   426,   187,   451,
     438,   189,   404,   148,   435,   437,   546,   148,   406,   407,
     148,   124,   125,   126,   127,   128,   129,   130,   193,   323,
     102,    40,    41,    42,    43,    44,   456,   470,   510,   152,
     153,   516,   457,   458,   138,   511,   460,   278,   511,    88,
     463,   199,   466,   209,   525,   194,   538,   469,   330,   492,
     474,   511,   496,   511,   540,   542,   195,   502,   208,   358,
     213,   511,   511,   116,   116,   216,   215,   116,   107,   214,
     217,   486,   218,   487,   166,   519,   521,   523,   368,   219,
     345,   220,     1,     2,   493,   346,   221,   497,   158,   159,
     245,   222,   503,   319,   320,   506,   154,   155,   156,   157,
     223,   382,   201,   202,   168,   514,   201,   272,   387,   184,
     174,   175,   263,   326,   224,   527,   369,   320,   396,   529,
     398,    40,    41,    42,    43,    44,   534,   418,   160,   161,
     162,   163,   164,   165,   543,   229,   230,   176,   177,   330,
     547,   225,   235,   236,   184,   246,   550,   253,   256,   257,
     553,   258,   263,   276,   557,   107,   277,   279,   288,   559,
     180,   181,   182,   183,   290,   563,   231,   232,   233,   234,
     565,   247,    38,    39,    40,    41,    42,    43,    44,   294,
     292,   293,   443,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,    15,
     298,   299,    16,    17,    18,    19,    20,    21,    22,   216,
     307,    23,   304,   309,   310,   311,   313,   315,    24,    25,
      26,    27,    28,   334,    29,   338,   340,   339,   337,   342,
     124,   125,   126,   127,   128,   129,   130,   349,   357,   360,
     362,    30,   363,   364,  -200,   374,  -167,   377,    31,    32,
      33,    34,   371,   138,   380,   381,   385,   386,   389,   391,
      35,   392,   393,    36,  -202,   397,   401,   415,   421,   422,
     531,   428,    37,   425,   429,    38,    39,    40,    41,    42,
      43,    44,    45,    46,   430,   433,   440,   441,    47,    48,
      49,    50,    51,   444,   445,    52,   449,    53,    54,    55,
      16,    17,    18,    19,    20,    21,    22,   467,   472,    23,
     477,   462,   473,  -168,   475,   478,    24,    25,    26,    27,
      28,   465,    29,   468,   479,   476,   482,   480,   490,    38,
      39,    40,    41,    42,    43,    44,   481,   484,   489,    30,
     494,   498,   504,   499,   512,   500,    31,    32,    33,    34,
     316,   515,    54,    40,    41,    42,    43,    44,    35,   505,
     402,    36,   508,   528,   379,   403,   532,   535,   404,   536,
      37,   405,   454,   539,   406,   407,   554,    95,    13,   545,
      45,    46,   548,    96,   132,   133,   551,    48,   555,   317,
     558,   561,   564,    52,   329,    53,    16,    17,    18,    19,
      20,    21,    22,   566,   568,    23,   359,   228,   227,   370,
     212,   111,    24,    25,    26,    27,    28,   324,    29,   395,
     327,   185,   318,   282,   439,   273,   312,   452,     0,   453,
       0,     0,     0,     0,     0,    30,     0,     0,     0,     0,
       0,     0,    31,    32,    33,    34,    40,    41,    42,    43,
      44,     0,     0,   402,    35,     0,     0,    36,   403,     0,
       0,   404,     0,     0,   405,   471,    37,   406,   407,     0,
       0,     0,     0,     0,     0,     0,    45,    46,     0,     0,
       0,     0,     0,    48,     0,     0,     0,     0,     0,    52,
       0,    53,    16,    17,    18,    19,    20,    21,    22,     0,
       0,    23,     0,     0,     0,     0,     0,     0,    24,    25,
      26,    27,    28,     0,    29,    40,    41,    42,    43,    44,
       0,     0,   402,     0,     0,     0,     0,   403,     0,     0,
     404,    30,     0,   405,     0,     0,   406,   407,    31,    32,
      33,    34,     0,     0,    16,    17,    18,    19,   104,    21,
      35,     0,     0,    36,     0,     0,    16,    17,    18,    19,
     104,    21,    37,    27,    28,   243,    29,     0,     0,     0,
       0,     0,    45,    46,     0,    27,    28,   274,    29,    48,
       0,     0,     0,    30,     0,    52,     0,    53,     0,     0,
      31,    32,    33,    34,     0,    30,    16,    17,    18,    19,
     104,    21,    31,    32,    33,    34,     0,     0,    16,    17,
      18,    19,   104,    21,    37,    27,    28,     0,    29,   266,
       0,     0,     0,     0,    45,    46,    37,    27,    28,     0,
      29,     0,     0,   336,     0,    30,    45,    46,     0,     0,
       0,     0,    31,    32,    33,    34,     0,    30,    16,    17,
      18,    19,   104,    21,    31,    32,    33,    34,     0,     0,
      16,    17,    18,    19,   104,    21,    37,    27,    28,   375,
      29,     0,     0,     0,     0,     0,    45,    46,    37,    27,
      28,     0,    29,     0,     0,     0,     0,    30,    45,    46,
       0,     0,     0,     0,    31,    32,    33,    34,     0,    30,
       0,   166,     0,     0,     0,     0,    31,    32,    33,    34,
     167,     0,     0,     0,     0,     0,     0,     0,    37,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    45,    46,
      37,   168,   169,   170,   171,   172,   173,   174,   175,     0,
      45,    46,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   176,   177
};

static const yytype_int16 yycheck[] =
{
      22,    23,    24,     4,     4,    29,    28,   176,   177,    88,
     182,   202,   206,    31,    36,   221,   391,   392,   221,   225,
       7,   191,   225,     8,    31,     7,    31,     3,     4,     5,
       6,     7,     8,    31,     7,   409,    31,    31,    31,    31,
      23,    53,    31,     7,    32,   214,    22,    23,   423,    25,
       7,   426,    32,   222,    28,   430,     7,    31,    31,    30,
      31,     7,    26,    34,     7,   439,    42,    24,     7,     7,
      53,    53,    75,    49,    50,    51,    52,    95,    24,   285,
     102,    24,   252,   458,    28,   460,    98,    31,   463,   295,
      95,    98,   298,   299,   300,   298,   299,    73,     7,     7,
      98,   270,   272,    98,    98,    98,    98,    83,    84,    98,
      98,    96,   487,     7,   101,    24,   491,   210,    98,   212,
       7,    98,    98,     7,   148,     7,   501,     7,    66,    67,
      68,    69,    70,    71,    72,   510,     7,    24,   310,     7,
     334,     7,   166,   518,    24,     7,   352,   522,   354,   319,
     525,    89,    74,    75,   178,   325,   326,   179,   180,   534,
     182,    34,    27,   538,    93,    30,    24,   542,    85,   338,
       7,   100,     7,    31,   198,   550,    93,    24,   553,    24,
     102,    33,   206,   100,    31,    27,    31,   209,   563,   160,
     161,   162,   163,   164,   165,   217,   497,    28,    24,   369,
      31,    26,   503,    98,   374,    31,    31,    78,    79,    80,
      81,    82,   381,   514,    85,     7,    24,   386,     7,    90,
      24,    98,    93,    31,   394,   397,   527,    31,    99,   100,
      31,    66,    67,    68,    69,    70,    71,    72,    98,   263,
      27,    78,    79,    80,    81,    82,   416,   438,    24,    35,
      36,    24,   421,   422,    89,    31,   425,   279,    31,   260,
     429,    97,   432,    27,    24,    98,    24,   437,   268,   472,
       7,    31,   475,    31,    24,    24,    98,   480,    23,   303,
      23,    31,    31,    30,    31,    27,    25,    34,   310,    94,
      32,   461,    27,   462,    23,   498,   499,   500,   320,    27,
      26,     7,    74,    75,   473,    31,    23,   476,    41,    42,
     334,    94,   481,    10,    11,   485,    37,    38,    39,    40,
       7,   343,    62,    63,    53,   494,    62,    63,   350,   408,
      59,    60,    13,    14,     7,   504,    10,    11,   360,   509,
     362,    78,    79,    80,    81,    82,   515,   371,    43,    44,
      45,    46,    47,    48,   524,   152,   153,    86,    87,   359,
     530,    23,   158,   159,   443,     7,   535,    25,    23,     7,
     539,    30,    13,     7,   544,   397,    24,    27,     7,   549,
      15,    16,    17,    18,    28,   554,   154,   155,   156,   157,
     560,     7,    76,    77,    78,    79,    80,    81,    82,    98,
      28,    28,   403,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,     0,
      23,    23,     3,     4,     5,     6,     7,     8,     9,    27,
      26,    12,    88,    15,    29,     7,     7,    98,    19,    20,
      21,    22,    23,    23,    25,    94,    31,   101,    27,    24,
      66,    67,    68,    69,    70,    71,    72,    24,    24,    23,
      30,    42,    98,    31,    97,     7,    98,    28,    49,    50,
      51,    52,    31,    89,    24,    94,    24,    94,    24,    24,
      61,    24,    65,    64,    97,    29,     7,    97,    94,    94,
     512,    24,    73,    94,    94,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    24,     7,    97,     7,    89,    90,
      91,    92,    93,     7,     7,    96,     7,    98,    99,   100,
       3,     4,     5,     6,     7,     8,     9,    31,    23,    12,
       7,    94,    94,    98,    23,     7,    19,    20,    21,    22,
      23,    98,    25,    98,     7,    94,     7,    23,     7,    76,
      77,    78,    79,    80,    81,    82,    94,    98,    98,    42,
      94,    23,    94,    23,    32,    23,    49,    50,    51,    52,
      97,    94,    99,    78,    79,    80,    81,    82,    61,    98,
      85,    64,    98,    98,     7,    90,    98,    94,    93,    98,
      73,    96,    97,    94,    99,   100,    94,     6,     2,    98,
      83,    84,    98,     6,    37,    37,    98,    90,    98,   260,
      98,    98,    98,    96,    97,    98,     3,     4,     5,     6,
       7,     8,     9,    98,    98,    12,   308,   151,   150,   321,
     133,    26,    19,    20,    21,    22,    23,   263,    25,    26,
     264,    88,   260,   212,   399,   203,   257,   408,    -1,   408,
      -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    50,    51,    52,    78,    79,    80,    81,
      82,    -1,    -1,    85,    61,    -1,    -1,    64,    90,    -1,
      -1,    93,    -1,    -1,    96,    97,    73,    99,   100,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    83,    84,    -1,    -1,
      -1,    -1,    -1,    90,    -1,    -1,    -1,    -1,    -1,    96,
      -1,    98,     3,     4,     5,     6,     7,     8,     9,    -1,
      -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,
      21,    22,    23,    -1,    25,    78,    79,    80,    81,    82,
      -1,    -1,    85,    -1,    -1,    -1,    -1,    90,    -1,    -1,
      93,    42,    -1,    96,    -1,    -1,    99,   100,    49,    50,
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
      -1,    23,    -1,    -1,    -1,    -1,    49,    50,    51,    52,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,    84,
      73,    53,    54,    55,    56,    57,    58,    59,    60,    -1,
      83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    87
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
     177,   188,   191,   192,   194,   107,   109,   110,    53,    98,
       7,   117,    27,    30,     7,   124,   124,   124,   157,     7,
     159,   159,   124,   125,   142,   133,   135,   133,   133,    98,
     195,    98,   124,     7,    66,    67,    68,    69,    70,    71,
      72,    89,   112,   113,     7,     7,     7,     7,    89,   112,
     113,   114,   115,     7,     7,    93,   100,     7,    31,    98,
      34,    33,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    23,    32,    53,    54,
      55,    56,    57,    58,    59,    60,    86,    87,   126,    27,
      15,    16,    17,    18,   176,   177,     7,     7,    98,    98,
     124,    95,    98,    98,    98,    98,    24,    26,    31,    97,
     196,    62,    63,   163,   164,    98,    23,    53,    23,    27,
     139,   140,   139,    23,    94,    25,    27,    32,    27,    27,
       7,    23,    94,     7,     7,    23,   125,   128,   129,   130,
     130,   131,   131,   131,   131,   132,   132,   133,   133,   133,
     133,   133,   133,    24,   122,   125,     7,     7,   115,   115,
     125,   124,   124,    25,   168,   157,    23,     7,    30,   178,
     118,    28,   195,    13,   149,   150,    26,   125,   123,   143,
     165,   168,    63,   164,    24,   122,     7,    24,   124,    27,
     140,   141,   141,     7,    31,   121,   184,   115,     7,   193,
      28,   124,    28,    28,    98,   121,   184,   115,    23,    23,
     121,   184,    24,    31,    88,    28,   195,    26,   169,    15,
      29,     7,   178,     7,   179,    98,    97,   119,   170,    10,
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

  case 43:

/* Line 1455 of yacc.c  */
#line 256 "diksam.y"
    {
            dkc_function_define((yyvsp[(9) - (11)].type_specifier), (yyvsp[(3) - (11)].identifier), (yyvsp[(5) - (11)].parameter_list), (yyvsp[(10) - (11)].exception_list), NULL,(yyvsp[(6) - (11)].apost));
        }
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 260 "diksam.y"
    {
            dkc_function_define((yyvsp[(8) - (10)].type_specifier), (yyvsp[(3) - (10)].identifier), NULL, (yyvsp[(9) - (10)].exception_list), NULL,(yyvsp[(5) - (10)].apost));
        }
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 264 "diksam.y"
    {
            dkc_function_define(0, (yyvsp[(3) - (9)].identifier), (yyvsp[(5) - (9)].parameter_list), (yyvsp[(8) - (9)].exception_list), NULL,(yyvsp[(6) - (9)].apost));
        }
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 268 "diksam.y"
    {
			printf("lib:%s\n",BcGetCurrentCompilerContext()->libname);
            dkc_function_define(0, (yyvsp[(3) - (8)].identifier), NULL, (yyvsp[(7) - (8)].exception_list), NULL,(yyvsp[(5) - (8)].apost));
        }
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 275 "diksam.y"
    {
            dkc_function_define((yyvsp[(8) - (10)].type_specifier), (yyvsp[(2) - (10)].identifier), (yyvsp[(4) - (10)].parameter_list), (yyvsp[(9) - (10)].exception_list), (yyvsp[(10) - (10)].block),(yyvsp[(5) - (10)].apost));
        }
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 279 "diksam.y"
    {
            dkc_function_define((yyvsp[(7) - (9)].type_specifier), (yyvsp[(2) - (9)].identifier), NULL, (yyvsp[(8) - (9)].exception_list), (yyvsp[(9) - (9)].block),(yyvsp[(4) - (9)].apost));
        }
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 283 "diksam.y"
    { //modified
            dkc_function_define(0, (yyvsp[(2) - (8)].identifier), (yyvsp[(4) - (8)].parameter_list), (yyvsp[(7) - (8)].exception_list), (yyvsp[(8) - (8)].block),(yyvsp[(5) - (8)].apost));
        }
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 287 "diksam.y"
    {
            dkc_function_define(0, (yyvsp[(2) - (7)].identifier), NULL, (yyvsp[(6) - (7)].exception_list), (yyvsp[(7) - (7)].block),(yyvsp[(4) - (7)].apost));
        }
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 294 "diksam.y"
    {
            (yyval.parameter_list) = dkc_create_parameter((yyvsp[(3) - (3)].type_specifier), (yyvsp[(1) - (3)].identifier));
        }
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 298 "diksam.y"
    {
            (yyval.parameter_list) = dkc_chain_parameter((yyvsp[(1) - (5)].parameter_list), (yyvsp[(5) - (5)].type_specifier), (yyvsp[(3) - (5)].identifier));
        }
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 304 "diksam.y"
    {
            (yyval.argument_list) = dkc_create_argument_list((yyvsp[(1) - (1)].expression));
        }
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 308 "diksam.y"
    {
            (yyval.argument_list) = dkc_chain_argument_list((yyvsp[(1) - (3)].argument_list), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 314 "diksam.y"
    {
            (yyval.statement_list) = dkc_create_statement_list((yyvsp[(1) - (1)].statement));
        }
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 318 "diksam.y"
    {
            (yyval.statement_list) = dkc_chain_statement_list((yyvsp[(1) - (2)].statement_list), (yyvsp[(2) - (2)].statement));
        }
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 325 "diksam.y"
    {
            (yyval.expression) = dkc_create_comma_expression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 332 "diksam.y"
    {
            (yyval.expression) = dkc_create_assign_expression((yyvsp[(1) - (3)].expression), (yyvsp[(2) - (3)].assignment_operator), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 338 "diksam.y"
    {
            (yyval.assignment_operator) = NORMAL_ASSIGN;
        }
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 342 "diksam.y"
    {
            (yyval.assignment_operator) = ADD_ASSIGN;
        }
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 346 "diksam.y"
    {
            (yyval.assignment_operator) = SUB_ASSIGN;
        }
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 350 "diksam.y"
    {
            (yyval.assignment_operator) = MUL_ASSIGN;
        }
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 354 "diksam.y"
    {
            (yyval.assignment_operator) = DIV_ASSIGN;
        }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 358 "diksam.y"
    {
            (yyval.assignment_operator) = MOD_ASSIGN;
        }
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 365 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(LOGICAL_OR_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 372 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(LOGICAL_AND_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 379 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(EQ_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 383 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(NE_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 390 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(GT_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 394 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(GE_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 398 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(LT_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 402 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(LE_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 409 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(ADD_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 413 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(SUB_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 420 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(MUL_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 424 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(DIV_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 428 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(MOD_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 432 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(BIT_AND_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 436 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(BIT_OR_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 440 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(BIT_XOR_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 447 "diksam.y"
    {
            (yyval.expression) = dkc_create_minus_expression((yyvsp[(2) - (2)].expression));
        }
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 451 "diksam.y"
    {
            (yyval.expression) = dkc_create_logical_not_expression((yyvsp[(2) - (2)].expression));
        }
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 455 "diksam.y"
    {
            (yyval.expression) = dkc_create_bit_not_expression((yyvsp[(2) - (2)].expression));
        }
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 462 "diksam.y"
    {
            (yyval.expression) = dkc_create_incdec_expression((yyvsp[(1) - (2)].expression), INCREMENT_EXPRESSION);
        }
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 466 "diksam.y"
    {
            (yyval.expression) = dkc_create_incdec_expression((yyvsp[(1) - (2)].expression), DECREMENT_EXPRESSION);
        }
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 470 "diksam.y"
    {
            (yyval.expression) = dkc_create_instanceof_expression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].type_specifier));
        }
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 478 "diksam.y"
    {
            (yyval.expression) = dkc_create_identifier_expression((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 482 "diksam.y"
    {
			(yyval.expression)=BcCreateAutoExpression((yyvsp[(1) - (1)].identifier));
		}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 488 "diksam.y"
    {
            (yyval.expression) = dkc_create_index_expression((yyvsp[(1) - (4)].expression), (yyvsp[(3) - (4)].expression));
        }
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 492 "diksam.y"
    {
            Expression *identifier = dkc_create_identifier_expression((yyvsp[(1) - (4)].identifier));
            (yyval.expression) = dkc_create_index_expression(identifier, (yyvsp[(3) - (4)].expression));
        }
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 497 "diksam.y"
    {
            (yyval.expression) = dkc_create_member_expression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].identifier));
        }
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 501 "diksam.y"
    {
            (yyval.expression) = dkc_create_function_call_expression((yyvsp[(1) - (4)].expression), (yyvsp[(3) - (4)].argument_list));
        }
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 505 "diksam.y"
    {
            (yyval.expression) = dkc_create_function_call_expression((yyvsp[(1) - (3)].expression), NULL);
        }
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 509 "diksam.y"
    {
            (yyval.expression) = (yyvsp[(2) - (3)].expression);
        }
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 513 "diksam.y"
    {
            (yyval.expression) = dkc_create_down_cast_expression((yyvsp[(1) - (4)].expression), (yyvsp[(3) - (4)].type_specifier));
        }
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 521 "diksam.y"
    {
            (yyval.expression) = dkc_create_boolean_expression(DVM_TRUE);
        }
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 525 "diksam.y"
    {
            (yyval.expression) = dkc_create_boolean_expression(DVM_FALSE);
        }
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 529 "diksam.y"
    {
            (yyval.expression) = dkc_create_null_expression();
        }
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 534 "diksam.y"
    {
            (yyval.expression) = dkc_create_this_expression();
        }
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 538 "diksam.y"
    {
            (yyval.expression) = dkc_create_super_expression();
        }
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 542 "diksam.y"
    {
			(yyval.expression) = dkc_create_new_delegate_expression();
		}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 546 "diksam.y"
    {
            (yyval.expression) = dkc_create_new_expression((yyvsp[(2) - (4)].identifier), NULL, NULL);
        }
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 550 "diksam.y"
    {
            (yyval.expression) = dkc_create_new_expression((yyvsp[(2) - (5)].identifier), NULL, (yyvsp[(4) - (5)].argument_list));
        }
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 554 "diksam.y"
    {
            (yyval.expression) = dkc_create_new_expression((yyvsp[(2) - (6)].identifier), (yyvsp[(4) - (6)].identifier), NULL);
        }
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 558 "diksam.y"
    {
            (yyval.expression) = dkc_create_new_expression((yyvsp[(2) - (7)].identifier), (yyvsp[(4) - (7)].identifier), (yyvsp[(6) - (7)].argument_list));
        }
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 564 "diksam.y"
    {
            (yyval.expression) = dkc_create_array_literal_expression((yyvsp[(2) - (3)].expression_list));
        }
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 568 "diksam.y"
    {
            (yyval.expression) = dkc_create_array_literal_expression((yyvsp[(2) - (4)].expression_list));
        }
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 574 "diksam.y"
    {
            (yyval.expression) = dkc_create_basic_array_creation((yyvsp[(2) - (3)].basic_type_specifier), (yyvsp[(3) - (3)].array_dimension), NULL);
        }
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 578 "diksam.y"
    {
            (yyval.expression) = dkc_create_basic_array_creation((yyvsp[(2) - (4)].basic_type_specifier), (yyvsp[(3) - (4)].array_dimension), (yyvsp[(4) - (4)].array_dimension));
        }
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 582 "diksam.y"
    {
            (yyval.expression) = dkc_create_class_array_creation((yyvsp[(2) - (3)].type_specifier), (yyvsp[(3) - (3)].array_dimension), NULL);
        }
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 587 "diksam.y"
    {
            (yyval.expression) = dkc_create_class_array_creation((yyvsp[(2) - (4)].type_specifier), (yyvsp[(3) - (4)].array_dimension), (yyvsp[(4) - (4)].array_dimension));
        }
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 594 "diksam.y"
    {
            (yyval.array_dimension) = dkc_chain_array_dimension((yyvsp[(1) - (2)].array_dimension), (yyvsp[(2) - (2)].array_dimension));
        }
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 600 "diksam.y"
    {
            (yyval.array_dimension) = dkc_create_array_dimension((yyvsp[(2) - (3)].expression));
        }
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 606 "diksam.y"
    {
            (yyval.array_dimension) = dkc_create_array_dimension(NULL);
        }
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 610 "diksam.y"
    {
            (yyval.array_dimension) = dkc_chain_array_dimension((yyvsp[(1) - (3)].array_dimension),
                                           dkc_create_array_dimension(NULL));
        }
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 617 "diksam.y"
    {
            (yyval.expression_list) = NULL;
        }
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 621 "diksam.y"
    {
            (yyval.expression_list) = dkc_create_expression_list((yyvsp[(1) - (1)].expression));
        }
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 625 "diksam.y"
    {
            (yyval.expression_list) = dkc_chain_expression_list((yyvsp[(1) - (3)].expression_list), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 631 "diksam.y"
    {
          (yyval.statement) = dkc_create_expression_statement((yyvsp[(1) - (2)].expression));
        }
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 647 "diksam.y"
    {/*empty line*/
			(yyval.statement)=0;
		}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 653 "diksam.y"
    {
            (yyval.statement) = dkc_create_if_statement((yyvsp[(2) - (4)].expression), (yyvsp[(4) - (4)].block), NULL, NULL);
        }
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 657 "diksam.y"
    {
			//printf("IF-ELSE %d\n",dkc_get_current_compiler()->current_line_number);
            (yyval.statement) = dkc_create_if_statement((yyvsp[(2) - (6)].expression), (yyvsp[(4) - (6)].block), NULL, (yyvsp[(6) - (6)].block));
        }
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 662 "diksam.y"
    {
            (yyval.statement) = dkc_create_if_statement((yyvsp[(2) - (5)].expression), (yyvsp[(4) - (5)].block), (yyvsp[(5) - (5)].elsif), NULL);
        }
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 666 "diksam.y"
    {
            (yyval.statement) = dkc_create_if_statement((yyvsp[(2) - (7)].expression), (yyvsp[(4) - (7)].block), (yyvsp[(5) - (7)].elsif), (yyvsp[(7) - (7)].block));
        }
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 673 "diksam.y"
    {
            (yyval.elsif) = dkc_chain_elsif_list((yyvsp[(1) - (2)].elsif), (yyvsp[(2) - (2)].elsif));
        }
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 679 "diksam.y"
    {
            (yyval.elsif) = dkc_create_elsif((yyvsp[(2) - (4)].expression), (yyvsp[(4) - (4)].block));
        }
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 685 "diksam.y"
    {
            (yyval.identifier) = NULL;
        }
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 689 "diksam.y"
    {
            (yyval.identifier) = (yyvsp[(1) - (2)].identifier);
        }
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 695 "diksam.y"
    {
            (yyval.statement) = dkc_create_switch_statement((yyvsp[(2) - (5)].expression), (yyvsp[(4) - (5)].case_list), (yyvsp[(5) - (5)].block));
        }
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 702 "diksam.y"
    {
            (yyval.case_list) = dkc_chain_case((yyvsp[(1) - (2)].case_list), (yyvsp[(2) - (2)].case_list));
        }
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 708 "diksam.y"
    {
            (yyval.case_list) = dkc_create_one_case((yyvsp[(2) - (3)].expression_list), (yyvsp[(3) - (3)].block));
        }
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 714 "diksam.y"
    {
            (yyval.block) = NULL;
        }
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 718 "diksam.y"
    {
            (yyval.block) = (yyvsp[(2) - (2)].block);
        }
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 724 "diksam.y"
    {
            (yyval.expression_list) = dkc_create_expression_list((yyvsp[(1) - (1)].expression));
        }
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 728 "diksam.y"
    {
            (yyval.expression_list) = dkc_chain_expression_list((yyvsp[(1) - (3)].expression_list), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 734 "diksam.y"
    {
            (yyval.statement) = dkc_create_while_statement((yyvsp[(1) - (4)].identifier), (yyvsp[(3) - (4)].expression), (yyvsp[(4) - (4)].block));
        }
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 740 "diksam.y"
    {
            (yyval.statement) = dkc_create_for_statement((yyvsp[(1) - (8)].identifier), (yyvsp[(3) - (8)].expression), (yyvsp[(5) - (8)].expression), (yyvsp[(7) - (8)].expression), (yyvsp[(8) - (8)].block));
        }
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 746 "diksam.y"
    {
            (yyval.statement) = dkc_create_do_while_statement((yyvsp[(1) - (8)].identifier), (yyvsp[(3) - (8)].block), (yyvsp[(6) - (8)].expression));
        }
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 752 "diksam.y"
    {
            (yyval.statement) = dkc_create_foreach_statement((yyvsp[(1) - (8)].identifier), (yyvsp[(4) - (8)].identifier), (yyvsp[(6) - (8)].expression), (yyvsp[(8) - (8)].block));
        }
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 758 "diksam.y"
    {
            (yyval.expression) = NULL;
        }
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 765 "diksam.y"
    {
            (yyval.statement) = dkc_create_return_statement((yyvsp[(2) - (3)].expression));
        }
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 771 "diksam.y"
    {
            (yyval.identifier) = NULL;
        }
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 778 "diksam.y"
    {
            (yyval.statement) = dkc_create_break_statement((yyvsp[(2) - (3)].identifier));
        }
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 784 "diksam.y"
    {
            (yyval.statement) = dkc_create_continue_statement((yyvsp[(2) - (3)].identifier));
        }
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 790 "diksam.y"
    {
            (yyval.statement) = dkc_create_try_statement((yyvsp[(2) - (5)].block), (yyvsp[(3) - (5)].catch_clause), (yyvsp[(5) - (5)].block));
        }
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 794 "diksam.y"
    {
            (yyval.statement) = dkc_create_try_statement((yyvsp[(2) - (4)].block), NULL, (yyvsp[(4) - (4)].block));
        }
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 798 "diksam.y"
    {
            (yyval.statement) = dkc_create_try_statement((yyvsp[(2) - (3)].block), (yyvsp[(3) - (3)].catch_clause), NULL);
        }
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 805 "diksam.y"
    {
            (yyval.catch_clause) = dkc_chain_catch_list((yyvsp[(1) - (2)].catch_clause), (yyvsp[(2) - (2)].catch_clause));
        }
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 811 "diksam.y"
    {
            (yyval.catch_clause) = dkc_start_catch_clause();
        }
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 815 "diksam.y"
    {
            (yyval.catch_clause) = dkc_end_catch_clause((yyvsp[(2) - (5)].catch_clause), (yyvsp[(3) - (5)].type_specifier), (yyvsp[(4) - (5)].identifier), (yyvsp[(5) - (5)].block));
        }
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 821 "diksam.y"
    {
            (yyval.statement) = dkc_create_throw_statement((yyvsp[(2) - (3)].expression));
        }
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 825 "diksam.y"
    {
            (yyval.statement) = dkc_create_throw_statement(NULL);
        }
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 831 "diksam.y"
    {
            (yyval.statement) = dkc_create_declaration_statement(DVM_FALSE, (yyvsp[(4) - (5)].type_specifier), (yyvsp[(2) - (5)].identifier), NULL);
        }
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 835 "diksam.y"
    {
            (yyval.statement) = dkc_create_declaration_statement(DVM_FALSE, (yyvsp[(4) - (7)].type_specifier), (yyvsp[(2) - (7)].identifier), (yyvsp[(6) - (7)].expression));
        }
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 839 "diksam.y"
    {
            (yyval.statement) = dkc_create_declaration_statement(DVM_FALSE, (yyvsp[(4) - (5)].type_specifier), (yyvsp[(2) - (5)].identifier), NULL);
        }
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 843 "diksam.y"
    {
            (yyval.statement) = dkc_create_declaration_statement(DVM_TRUE, (yyvsp[(4) - (7)].type_specifier), (yyvsp[(2) - (7)].identifier), (yyvsp[(6) - (7)].expression));
        }
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 849 "diksam.y"
    {
            (yyval.block) = dkc_open_block();
        }
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 853 "diksam.y"
    {
            (yyval.block) = dkc_close_block((yyvsp[(2) - (4)].block), (yyvsp[(3) - (4)].statement_list));
        }
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 857 "diksam.y"
    {
            Block *empty_block = dkc_open_block();
            (yyval.block) = dkc_close_block(empty_block, NULL);
        }
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 865 "diksam.y"
    {
            dkc_start_class_definition(NULL, (yyvsp[(1) - (4)].class_or_interface), (yyvsp[(2) - (4)].identifier), (yyvsp[(3) - (4)].extends_list));
        }
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 869 "diksam.y"
    {
            dkc_class_define((yyvsp[(6) - (7)].member_declaration));
        }
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 874 "diksam.y"
    {
            dkc_start_class_definition(&(yyvsp[(1) - (5)].class_or_member_modifier), (yyvsp[(2) - (5)].class_or_interface), (yyvsp[(3) - (5)].identifier), (yyvsp[(4) - (5)].extends_list));
        }
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 877 "diksam.y"
    {
            dkc_class_define((yyvsp[(7) - (8)].member_declaration));
        }
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 881 "diksam.y"
    {
            dkc_start_class_definition(NULL, (yyvsp[(1) - (4)].class_or_interface), (yyvsp[(2) - (4)].identifier), (yyvsp[(3) - (4)].extends_list));
        }
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 885 "diksam.y"
    {
            dkc_class_define(NULL);
        }
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 890 "diksam.y"
    {
            dkc_start_class_definition(&(yyvsp[(1) - (5)].class_or_member_modifier), (yyvsp[(2) - (5)].class_or_interface), (yyvsp[(3) - (5)].identifier), (yyvsp[(4) - (5)].extends_list));
        }
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 894 "diksam.y"
    {
            dkc_class_define(NULL);
        }
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 901 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_chain_class_or_member_modifier((yyvsp[(1) - (2)].class_or_member_modifier), (yyvsp[(2) - (2)].class_or_member_modifier));
        }
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 908 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(VIRTUAL_MODIFIER);
        }
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 912 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(OVERRIDE_MODIFIER);
        }
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 916 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(ABSTRACT_MODIFIER);
        }
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 922 "diksam.y"
    {
            (yyval.class_or_interface) = DVM_CLASS_DEFINITION;
        }
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 926 "diksam.y"
    {
            (yyval.class_or_interface) = DVM_INTERFACE_DEFINITION;
        }
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 932 "diksam.y"
    {
            (yyval.extends_list) = NULL;
        }
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 936 "diksam.y"
    {
            (yyval.extends_list) = (yyvsp[(2) - (2)].extends_list);
        }
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 942 "diksam.y"
    {
            (yyval.extends_list) = dkc_create_extends_list((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 946 "diksam.y"
    {
            (yyval.extends_list) = dkc_chain_extends_list((yyvsp[(1) - (3)].extends_list), (yyvsp[(3) - (3)].identifier));
        }
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 953 "diksam.y"
    {
            (yyval.member_declaration) = dkc_chain_member_declaration((yyvsp[(1) - (2)].member_declaration), (yyvsp[(2) - (2)].member_declaration));
        }
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 963 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_method_member(NULL, (yyvsp[(1) - (1)].function_definition), DVM_FALSE);
        }
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 967 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_method_member(&(yyvsp[(1) - (2)].class_or_member_modifier), (yyvsp[(2) - (2)].function_definition), DVM_FALSE);
        }
    break;

  case 222:

/* Line 1455 of yacc.c  */
#line 971 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_method_member(NULL, (yyvsp[(1) - (1)].function_definition), DVM_TRUE);
        }
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 975 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_method_member(&(yyvsp[(1) - (2)].class_or_member_modifier), (yyvsp[(2) - (2)].function_definition), DVM_TRUE);
        }
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 981 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define((yyvsp[(7) - (9)].type_specifier), (yyvsp[(2) - (9)].identifier), (yyvsp[(4) - (9)].parameter_list), (yyvsp[(8) - (9)].exception_list), (yyvsp[(9) - (9)].block));
        }
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 985 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define((yyvsp[(6) - (8)].type_specifier), (yyvsp[(2) - (8)].identifier), NULL, (yyvsp[(7) - (8)].exception_list), (yyvsp[(8) - (8)].block));
        }
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 989 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define((yyvsp[(8) - (10)].type_specifier), (yyvsp[(3) - (10)].identifier), (yyvsp[(5) - (10)].parameter_list), (yyvsp[(9) - (10)].exception_list), NULL);
        }
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 993 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define((yyvsp[(7) - (9)].type_specifier), (yyvsp[(3) - (9)].identifier), NULL, (yyvsp[(8) - (9)].exception_list), NULL);
        }
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 997 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define(0, (yyvsp[(2) - (7)].identifier), (yyvsp[(4) - (7)].parameter_list), (yyvsp[(6) - (7)].exception_list), (yyvsp[(7) - (7)].block));
        }
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 1001 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define(0, (yyvsp[(2) - (6)].identifier), NULL, (yyvsp[(5) - (6)].exception_list), (yyvsp[(6) - (6)].block));
        }
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 1005 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define(0, (yyvsp[(3) - (8)].identifier), (yyvsp[(5) - (8)].parameter_list), (yyvsp[(7) - (8)].exception_list), NULL);
        }
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 1009 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define(0, (yyvsp[(3) - (7)].identifier), NULL, (yyvsp[(6) - (7)].exception_list), NULL);
        }
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 1015 "diksam.y"
    {
			(yyval.apost)=0;
		}
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 1019 "diksam.y"
    {
			(yyval.apost)=1;
		}
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 1025 "diksam.y"
    {
            (yyval.exception_list) = NULL;
        }
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 1029 "diksam.y"
    {
            (yyval.exception_list) = (yyvsp[(2) - (2)].exception_list);
        }
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 1035 "diksam.y"
    {
            (yyval.exception_list) = dkc_create_throws((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 1039 "diksam.y"
    {
            (yyval.exception_list) = dkc_chain_exception_list((yyvsp[(1) - (3)].exception_list), (yyvsp[(3) - (3)].identifier));
        }
    break;

  case 238:

/* Line 1455 of yacc.c  */
#line 1045 "diksam.y"
    {
            (yyval.function_definition) = dkc_constructor_function_define((yyvsp[(2) - (7)].identifier), (yyvsp[(4) - (7)].parameter_list), (yyvsp[(6) - (7)].exception_list), (yyvsp[(7) - (7)].block));
        }
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 1049 "diksam.y"
    {
            (yyval.function_definition) = dkc_constructor_function_define((yyvsp[(2) - (6)].identifier), NULL, (yyvsp[(5) - (6)].exception_list), (yyvsp[(6) - (6)].block));
        }
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 1053 "diksam.y"
    {
            (yyval.function_definition) = dkc_constructor_function_define((yyvsp[(3) - (8)].identifier), (yyvsp[(5) - (8)].parameter_list), (yyvsp[(7) - (8)].exception_list), NULL);
        }
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 1057 "diksam.y"
    {
            (yyval.function_definition) = dkc_constructor_function_define((yyvsp[(3) - (7)].identifier), NULL, (yyvsp[(6) - (7)].exception_list), NULL);
        }
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 1063 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(PUBLIC_MODIFIER);
        }
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 1067 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(PRIVATE_MODIFIER);
        }
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 1073 "diksam.y"
    {
            (yyval.expression) = NULL;
        }
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 1077 "diksam.y"
    {
            (yyval.expression) = (yyvsp[(2) - (2)].expression);
        }
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 1083 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(NULL, DVM_FALSE, (yyvsp[(4) - (6)].type_specifier), (yyvsp[(2) - (6)].identifier), (yyvsp[(5) - (6)].expression));
        }
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 1088 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(&(yyvsp[(1) - (6)].class_or_member_modifier), DVM_FALSE, (yyvsp[(4) - (6)].type_specifier), (yyvsp[(2) - (6)].identifier), (yyvsp[(5) - (6)].expression));
        }
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 1092 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(NULL, DVM_TRUE, (yyvsp[(4) - (6)].type_specifier), (yyvsp[(2) - (6)].identifier), (yyvsp[(5) - (6)].expression));
        }
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 1097 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(&(yyvsp[(1) - (7)].class_or_member_modifier), DVM_TRUE, (yyvsp[(5) - (7)].type_specifier), (yyvsp[(3) - (7)].identifier), (yyvsp[(6) - (7)].expression));
        }
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 1101 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(&(yyvsp[(2) - (7)].class_or_member_modifier), DVM_TRUE, (yyvsp[(5) - (7)].type_specifier), (yyvsp[(3) - (7)].identifier), (yyvsp[(6) - (7)].expression));
        }
    break;

  case 251:

/* Line 1455 of yacc.c  */
#line 1107 "diksam.y"
    {
            dkc_create_delegate_definition((yyvsp[(8) - (10)].type_specifier), (yyvsp[(2) - (10)].identifier), (yyvsp[(4) - (10)].parameter_list), (yyvsp[(9) - (10)].exception_list),(yyvsp[(5) - (10)].apost));
        }
    break;

  case 252:

/* Line 1455 of yacc.c  */
#line 1111 "diksam.y"
    {
            dkc_create_delegate_definition((yyvsp[(7) - (9)].type_specifier), (yyvsp[(2) - (9)].identifier), NULL, (yyvsp[(8) - (9)].exception_list),(yyvsp[(4) - (9)].apost));
        }
    break;

  case 253:

/* Line 1455 of yacc.c  */
#line 1117 "diksam.y"
    {
            dkc_create_enum_definition((yyvsp[(2) - (5)].identifier), (yyvsp[(4) - (5)].enumerator));
        }
    break;

  case 254:

/* Line 1455 of yacc.c  */
#line 1121 "diksam.y"
    {
            dkc_create_enum_definition((yyvsp[(2) - (6)].identifier), (yyvsp[(4) - (6)].enumerator));
        }
    break;

  case 255:

/* Line 1455 of yacc.c  */
#line 1127 "diksam.y"
    {
            (yyval.enumerator) = dkc_create_enumerator((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 1131 "diksam.y"
    {
            (yyval.enumerator) = dkc_chain_enumerator((yyvsp[(1) - (3)].enumerator), (yyvsp[(3) - (3)].identifier));
        }
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 1137 "diksam.y"
    {
            dkc_create_const_definition(NULL, (yyvsp[(2) - (5)].identifier), (yyvsp[(4) - (5)].expression));
        }
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 1141 "diksam.y"
    {
            dkc_create_const_definition((yyvsp[(2) - (4)].type_specifier), (yyvsp[(3) - (4)].identifier), NULL);
        }
    break;

  case 259:

/* Line 1455 of yacc.c  */
#line 1147 "diksam.y"
    {
            (yyval.block) = dkc_open_block();
			//printf("E1 %d\n",dkc_get_current_compiler());
        }
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 1152 "diksam.y"
    {
            (yyval.block) = dkc_close_block((yyvsp[(2) - (4)].block), (yyvsp[(3) - (4)].statement_list));
			//printf("C1 %d\n",dkc_get_current_compiler()->current_line_number);
        }
    break;

  case 261:

/* Line 1455 of yacc.c  */
#line 1157 "diksam.y"
    {
            Block *empty_block = dkc_open_block();
            (yyval.block) = dkc_close_block(empty_block, NULL);
			//printf("C2 %d\n",dkc_get_current_compiler()->current_line_number);
        }
    break;



/* Line 1455 of yacc.c  */
#line 4048 "y.tab.c"
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
#line 1163 "diksam.y"


