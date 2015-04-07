
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
#define YYLAST   1000

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  105
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  99
/* YYNRULES -- Number of rules.  */
#define YYNRULES  277
/* YYNRULES -- Number of states.  */
#define YYNSTATES  599

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
      70,    72,    74,    78,    82,    86,    90,    95,    97,    99,
     101,   103,   105,   109,   110,   117,   118,   121,   124,   136,
     147,   157,   166,   177,   187,   196,   204,   206,   210,   216,
     218,   222,   224,   227,   229,   233,   235,   239,   241,   243,
     245,   247,   249,   251,   253,   257,   259,   263,   265,   269,
     273,   275,   279,   283,   287,   291,   293,   297,   301,   303,
     307,   311,   315,   319,   323,   327,   329,   332,   335,   338,
     340,   343,   346,   350,   352,   354,   356,   358,   363,   368,
     372,   377,   381,   385,   390,   392,   394,   396,   398,   400,
     402,   404,   406,   408,   410,   415,   420,   426,   433,   441,
     445,   450,   454,   459,   463,   468,   472,   477,   479,   482,
     486,   489,   493,   494,   496,   500,   503,   505,   507,   509,
     511,   513,   515,   517,   519,   521,   523,   525,   527,   529,
     534,   541,   547,   555,   557,   560,   565,   566,   569,   575,
     577,   580,   584,   585,   588,   590,   594,   599,   608,   617,
     626,   627,   629,   633,   634,   636,   640,   644,   650,   655,
     659,   661,   664,   665,   671,   675,   678,   684,   692,   698,
     706,   707,   712,   715,   717,   721,   725,   731,   735,   736,
     737,   746,   747,   757,   758,   766,   767,   776,   778,   781,
     783,   785,   787,   789,   791,   793,   794,   797,   799,   803,
     805,   808,   810,   812,   814,   817,   819,   822,   832,   841,
     852,   862,   870,   877,   886,   894,   895,   898,   899,   902,
     904,   908,   916,   923,   932,   940,   942,   944,   945,   948,
     955,   962,   969,   977,   985,   996,  1006,  1012,  1019,  1021,
    1025,  1031,  1036,  1037,  1040,  1043,  1044,  1050
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
      28,    -1,   116,    27,    28,    -1,   117,    27,    28,    -1,
       7,    39,   119,    37,    -1,   114,    -1,   116,    -1,   115,
      -1,   117,    -1,   118,    -1,   119,    31,   118,    -1,    -1,
     102,     7,   121,    98,   122,    97,    -1,    -1,   122,   123,
      -1,   122,   176,    -1,    99,    93,     7,    23,   125,   190,
      24,    94,   118,   191,    98,    -1,    99,    93,     7,    23,
     190,    24,    94,   118,   191,    98,    -1,    99,   100,     7,
      23,   125,   190,    24,   191,    98,    -1,    99,   100,     7,
      23,   190,    24,   191,    98,    -1,    93,     7,    23,   125,
     190,    24,    94,   118,   191,   202,    -1,    93,     7,    23,
     190,    24,    94,   118,   191,   202,    -1,   100,     7,    23,
     125,   190,    24,   191,   202,    -1,   100,     7,    23,   190,
      24,   191,   202,    -1,   123,    -1,     7,    94,   118,    -1,
     125,    31,     7,    94,   118,    -1,   129,    -1,   126,    31,
     129,    -1,   147,    -1,   127,   147,    -1,   129,    -1,   128,
      31,   129,    -1,   131,    -1,   139,   130,   129,    -1,    32,
      -1,    54,    -1,    55,    -1,    56,    -1,    57,    -1,    58,
      -1,   132,    -1,   131,    34,   132,    -1,   133,    -1,   132,
      33,   133,    -1,   134,    -1,   133,    35,   134,    -1,   133,
      36,   134,    -1,   135,    -1,   134,    37,   135,    -1,   134,
      38,   135,    -1,   134,    39,   135,    -1,   134,    40,   135,
      -1,   136,    -1,   135,    41,   136,    -1,   135,    42,   136,
      -1,   137,    -1,   136,    43,   137,    -1,   136,    44,   137,
      -1,   136,    45,   137,    -1,   136,    46,   137,    -1,   136,
      47,   137,    -1,   136,    48,   137,    -1,   138,    -1,    42,
     137,    -1,    52,   137,    -1,    49,   137,    -1,   139,    -1,
     139,    59,    -1,   139,    60,    -1,   139,    86,   118,    -1,
     140,    -1,   142,    -1,     7,    -1,     8,    -1,   140,    27,
     128,    28,    -1,     7,    27,   128,    28,    -1,   139,    53,
       7,    -1,   139,    23,   126,    24,    -1,   139,    23,    24,
      -1,    23,   128,    24,    -1,   139,    87,   118,    88,    -1,
       3,    -1,     4,    -1,     5,    -1,     6,    -1,    50,    -1,
      51,    -1,    22,    -1,   141,    -1,    83,    -1,    84,    -1,
      73,    89,    23,    24,    -1,    73,     7,    23,    24,    -1,
      73,     7,    23,   126,    24,    -1,    73,     7,    53,     7,
      23,    24,    -1,    73,     7,    53,     7,    23,   126,    24,
      -1,    25,   146,    26,    -1,    25,   146,    31,    26,    -1,
      73,   114,   143,    -1,    73,   114,   143,   145,    -1,    73,
     115,   143,    -1,    73,   115,   143,   145,    -1,    73,   117,
     143,    -1,    73,   117,   143,   145,    -1,   144,    -1,   143,
     144,    -1,    27,   128,    28,    -1,    27,    28,    -1,   145,
      27,    28,    -1,    -1,   129,    -1,   146,    31,   129,    -1,
     128,    98,    -1,   148,    -1,   152,    -1,   157,    -1,   158,
      -1,   159,    -1,   160,    -1,   162,    -1,   164,    -1,   165,
      -1,   166,    -1,   170,    -1,   171,    -1,    98,    -1,     9,
     128,    95,   202,    -1,     9,   128,    95,   202,    10,   202,
      -1,     9,   128,    95,   202,   149,    -1,     9,   128,    95,
     202,   149,    10,   202,    -1,   150,    -1,   149,   150,    -1,
      11,   128,    95,   202,    -1,    -1,     7,    30,    -1,    12,
     128,    98,   153,   155,    -1,   154,    -1,   153,   154,    -1,
      13,   156,   202,    -1,    -1,    14,   202,    -1,   129,    -1,
     146,    31,   129,    -1,   151,    15,   128,   202,    -1,   151,
      17,   161,    29,   161,    29,   161,   202,    -1,   151,    16,
     172,    15,    23,   128,    24,    98,    -1,   151,    18,    23,
       7,    30,   128,    24,   172,    -1,    -1,   128,    -1,    19,
     161,    98,    -1,    -1,     7,    -1,    20,   163,    98,    -1,
      21,   163,    98,    -1,    61,   202,   167,    63,   202,    -1,
      61,   202,    63,   172,    -1,    61,   202,   167,    -1,   168,
      -1,   167,   168,    -1,    -1,    62,   169,   118,     7,   202,
      -1,    64,   128,    98,    -1,    64,    98,    -1,    96,     7,
      94,   118,    98,    -1,    96,     7,    94,   118,    32,   128,
      98,    -1,    90,     7,    94,   118,    98,    -1,    90,     7,
      94,   118,    32,   128,    98,    -1,    -1,    25,   173,   127,
      26,    -1,    25,    26,    -1,     7,    -1,   174,    31,     7,
      -1,     7,    30,   115,    -1,   174,    31,     7,    30,   115,
      -1,    39,   174,    37,    -1,    -1,    -1,   183,     7,   175,
     184,    98,   177,   186,    97,    -1,    -1,   181,   183,     7,
     175,   184,    98,   178,   186,    97,    -1,    -1,   183,     7,
     175,   184,    98,   179,    97,    -1,    -1,   181,   183,     7,
     175,   184,    98,   180,    97,    -1,   182,    -1,   181,   182,
      -1,   194,    -1,    80,    -1,    81,    -1,    82,    -1,    76,
      -1,    77,    -1,    -1,    30,   185,    -1,     7,    -1,   185,
      31,     7,    -1,   187,    -1,   186,   187,    -1,   188,    -1,
     196,    -1,   189,    -1,   181,   189,    -1,   193,    -1,   181,
     193,    -1,    93,     7,    23,   125,    24,    94,   118,   191,
     202,    -1,    93,     7,    23,    24,    94,   118,   191,   202,
      -1,    99,    93,     7,    23,   125,    24,    94,   118,   191,
      98,    -1,    99,    93,     7,    23,    24,    94,   118,   191,
      98,    -1,   100,     7,    23,   125,    24,   191,   202,    -1,
     100,     7,    23,    24,   191,   202,    -1,    99,   100,     7,
      23,   125,    24,   191,    98,    -1,    99,   100,     7,    23,
      24,   191,    98,    -1,    -1,    31,   101,    -1,    -1,    65,
     192,    -1,     7,    -1,   192,    31,     7,    -1,    85,     7,
      23,   125,    24,   191,   202,    -1,    85,     7,    23,    24,
     191,   202,    -1,    99,    85,     7,    23,   125,    24,   191,
      98,    -1,    99,    85,     7,    23,    24,   191,    98,    -1,
      78,    -1,    79,    -1,    -1,    32,   128,    -1,    96,     7,
      94,   118,   195,    98,    -1,   181,     7,    94,   118,   195,
      98,    -1,    90,     7,    94,   118,   195,    98,    -1,   181,
      90,     7,    94,   118,   195,    98,    -1,    90,   181,     7,
      94,   118,   195,    98,    -1,    89,     7,    23,   125,   190,
      24,    94,   118,   191,    98,    -1,    89,     7,    23,   190,
      24,    94,   118,   191,    98,    -1,    91,     7,    25,   199,
      26,    -1,    91,     7,    25,   199,    31,    26,    -1,     7,
      -1,   199,    31,     7,    -1,    92,     7,    32,   128,    98,
      -1,    92,   118,     7,    98,    -1,    -1,   103,    98,    -1,
     104,    98,    -1,    -1,    98,   201,   203,   127,    97,    -1,
      98,    97,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   102,   102,   103,   107,   110,   114,   118,   122,   128,
     129,   135,   141,   145,   151,   152,   158,   164,   165,   166,
     173,   174,   175,   178,   182,   186,   190,   194,   198,   202,
     206,   212,   218,   224,   230,   234,   240,   246,   250,   251,
     252,   256,   260,   268,   267,   282,   285,   286,   289,   293,
     297,   301,   308,   312,   316,   320,   324,   327,   331,   337,
     341,   347,   351,   357,   358,   364,   365,   371,   375,   379,
     383,   387,   391,   397,   398,   404,   405,   411,   412,   416,
     422,   423,   427,   431,   435,   441,   442,   446,   452,   453,
     457,   461,   465,   469,   473,   479,   480,   484,   488,   494,
     495,   499,   503,   509,   510,   511,   515,   521,   525,   530,
     534,   538,   542,   546,   550,   551,   552,   553,   554,   558,
     562,   566,   567,   571,   575,   579,   583,   587,   591,   597,
     601,   607,   611,   615,   619,   624,   628,   634,   635,   641,
     647,   651,   659,   662,   666,   672,   676,   677,   678,   679,
     680,   681,   682,   683,   684,   685,   686,   687,   688,   694,
     698,   703,   707,   713,   714,   720,   727,   730,   736,   742,
     743,   749,   756,   759,   765,   769,   775,   781,   787,   793,
     800,   803,   806,   813,   816,   819,   825,   831,   835,   839,
     845,   846,   853,   852,   862,   866,   872,   876,   880,   884,
     891,   890,   898,   905,   909,   913,   917,   923,   928,   933,
     931,   942,   940,   949,   948,   958,   956,   967,   968,   974,
     975,   979,   983,   989,   993,  1000,  1003,  1009,  1013,  1019,
    1020,  1026,  1027,  1030,  1034,  1038,  1042,  1048,  1052,  1056,
    1060,  1064,  1068,  1072,  1076,  1083,  1086,  1093,  1096,  1102,
    1106,  1112,  1116,  1120,  1124,  1130,  1134,  1141,  1144,  1150,
    1154,  1159,  1163,  1168,  1174,  1178,  1184,  1188,  1194,  1198,
    1204,  1208,  1215,  1218,  1222,  1229,  1228,  1238
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
     114,   115,   116,   116,   116,   116,   117,   118,   118,   118,
     118,   119,   119,   121,   120,   122,   122,   122,   123,   123,
     123,   123,   124,   124,   124,   124,   124,   125,   125,   126,
     126,   127,   127,   128,   128,   129,   129,   130,   130,   130,
     130,   130,   130,   131,   131,   132,   132,   133,   133,   133,
     134,   134,   134,   134,   134,   135,   135,   135,   136,   136,
     136,   136,   136,   136,   136,   137,   137,   137,   137,   138,
     138,   138,   138,   139,   139,   139,   139,   140,   140,   140,
     140,   140,   140,   140,   140,   140,   140,   140,   140,   140,
     140,   140,   140,   140,   140,   140,   140,   140,   140,   141,
     141,   142,   142,   142,   142,   142,   142,   143,   143,   144,
     145,   145,   146,   146,   146,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   148,
     148,   148,   148,   149,   149,   150,   151,   151,   152,   153,
     153,   154,   155,   155,   156,   156,   157,   158,   159,   160,
     161,   161,   162,   163,   163,   164,   165,   166,   166,   166,
     167,   167,   169,   168,   170,   170,   171,   171,   171,   171,
     173,   172,   172,   174,   174,   174,   174,   175,   175,   177,
     176,   178,   176,   179,   176,   180,   176,   181,   181,   182,
     182,   182,   182,   183,   183,   184,   184,   185,   185,   186,
     186,   187,   187,   188,   188,   188,   188,   189,   189,   189,
     189,   189,   189,   189,   189,   190,   190,   191,   191,   192,
     192,   193,   193,   193,   193,   194,   194,   195,   195,   196,
     196,   196,   196,   196,   197,   197,   198,   198,   199,   199,
     200,   200,   201,   201,   201,   203,   202,   202
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
       1,     1,     1,     1,     3,     1,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     3,     3,     1,     2,     2,     2,     1,
       2,     2,     3,     1,     1,     1,     1,     4,     4,     3,
       4,     3,     3,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     5,     6,     7,     3,
       4,     3,     4,     3,     4,     3,     4,     1,     2,     3,
       2,     3,     0,     1,     3,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       6,     5,     7,     1,     2,     4,     0,     2,     5,     1,
       2,     3,     0,     2,     1,     3,     4,     8,     8,     8,
       0,     1,     3,     0,     1,     3,     3,     5,     4,     3,
       1,     2,     0,     5,     3,     2,     5,     7,     5,     7,
       0,     4,     2,     1,     3,     3,     5,     3,     0,     0,
       8,     0,     9,     0,     7,     0,     8,     1,     2,     1,
       1,     1,     1,     1,     1,     0,     2,     1,     3,     1,
       2,     1,     1,     1,     2,     1,     2,     9,     8,    10,
       9,     7,     6,     8,     7,     0,     2,     0,     2,     1,
       3,     7,     6,     8,     7,     1,     1,     0,     2,     6,
       6,     6,     7,     7,    10,     9,     5,     6,     1,     3,
       5,     4,     0,     2,     2,     0,     5,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       4,     0,     0,   166,     2,     6,     9,     7,    14,    12,
       0,     0,     1,   114,   115,   116,   117,   105,   106,     0,
       0,   180,   183,   183,   120,     0,   142,     0,     0,   118,
     119,     0,     0,     0,     0,   223,   224,   255,   256,   220,
     221,   222,   122,   123,     0,     0,     0,     0,     0,     0,
     158,     0,     0,     3,    56,    17,     0,    63,    65,    73,
      75,    77,    80,    85,    88,    95,    99,   103,   121,   104,
      19,   146,     0,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,    18,     0,   217,     0,   219,    20,
      21,    22,     0,     8,    10,     5,    15,     0,    11,     0,
       0,   167,   105,     0,     0,   181,     0,   184,     0,     0,
       0,   143,     0,    96,    99,    98,    97,   272,     0,   195,
       0,    31,    23,    24,    25,    26,    27,    28,    29,    30,
       0,     0,     0,     0,     0,     0,    31,    30,    37,    39,
      38,    40,     0,     0,     0,     0,     0,     0,     0,   145,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    67,     0,    68,
      69,    70,    71,    72,   100,   101,     0,     0,     0,     0,
       0,     0,   180,     0,   218,     0,   208,    43,    13,    16,
       0,     0,     0,   182,   185,   186,   112,   129,     0,   277,
       0,     0,   275,   192,     0,   189,   190,   194,     0,     0,
       0,     0,     0,   131,   137,   133,   135,   245,     0,     0,
       0,     0,     0,     0,     0,     0,   245,     0,     0,     0,
     245,    64,    74,    76,    78,    79,    81,    82,    83,    84,
      86,    87,    89,    90,    91,    92,    93,    94,   111,     0,
      59,   109,    31,   102,     0,    66,     0,     0,   200,     0,
       0,     0,   208,     0,   225,     0,   108,   159,   142,   172,
     169,   130,   144,   273,   274,   166,     0,   188,     0,   191,
     125,     0,    41,     0,     0,   124,     0,     0,   138,   132,
     134,   136,     0,     0,   245,     0,     0,   268,     0,    33,
       0,    32,    34,    35,   271,   245,     0,     0,   245,   245,
     245,     0,   110,     0,   113,   107,   176,   202,   166,     0,
     180,     0,   225,   203,     0,     0,     0,    45,     0,     0,
     161,   163,   143,     0,     0,     0,   170,   168,   166,    61,
       0,   187,   126,     0,    36,     0,   139,   140,     0,     0,
     246,     0,     0,     0,     0,   198,   266,     0,   270,     0,
       0,     0,   196,   245,     0,   245,     0,     0,   247,    60,
     166,     0,     0,     0,     0,     0,     0,   207,   227,   226,
     209,     0,   160,     0,     0,   164,     0,   171,   173,   276,
      62,     0,    42,   127,     0,   141,    57,     0,     0,     0,
       0,   269,   267,     0,     0,     0,     0,     0,     0,   247,
     247,     0,     0,   201,     0,   180,     0,   211,    31,   205,
     204,     0,     0,     0,    44,    46,    47,     0,   162,   144,
     193,   128,     0,     0,   247,   199,     0,   247,   197,     0,
       0,   247,     0,     0,   249,   248,    55,     0,     0,     0,
       0,     0,     0,   228,     0,     0,     0,     0,     0,     0,
       0,     0,   229,   231,   233,   235,   232,   214,   165,    58,
     247,     0,   247,     0,     0,   247,     0,    51,    54,     0,
     178,   177,   179,     0,   216,   206,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   234,   236,   210,
     230,     0,   265,     0,    53,   247,     0,    50,   250,   212,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   264,    52,     0,    49,   247,     0,   257,     0,     0,
       0,   257,     0,     0,     0,   247,     0,   257,     0,    48,
       0,   247,     0,     0,     0,   257,     0,     0,     0,   247,
       0,     0,     0,   247,     0,     0,   247,     0,   257,   252,
       0,   258,   261,     0,   247,     0,   259,     0,   247,     0,
       0,     0,   247,   242,     0,   260,     0,   251,   263,     0,
     247,   254,     0,   247,     0,   244,     0,   241,   262,   238,
       0,   253,     0,   247,   243,   237,   240,     0,   239
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,     6,    10,     7,     8,    53,   138,
     139,   140,   141,   142,   283,    93,   265,   381,    54,    55,
     294,   249,   338,    56,    57,   178,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,   213,   214,
     289,   112,   339,    71,   330,   331,    72,    73,   269,   270,
     337,   334,    74,    75,    76,    77,   106,    78,   108,    79,
      80,    81,   205,   206,   276,    82,    83,   259,   318,   324,
     264,    84,   422,   450,   423,   451,   460,    86,    87,   326,
     379,   461,   462,   463,   464,   295,   412,   445,   465,    88,
     544,   466,    89,    90,   298,    91,   202,   118,   275
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -479
static const yytype_int16 yypact[] =
{
     154,    57,    57,   412,   -28,   154,  -479,    29,  -479,  -479,
     -44,    18,  -479,  -479,  -479,  -479,  -479,    11,  -479,   910,
     910,   910,    78,    78,  -479,   910,   910,   910,   910,  -479,
    -479,   910,    87,   754,   249,  -479,  -479,  -479,  -479,  -479,
    -479,  -479,  -479,  -479,   184,   190,   194,   262,   223,   267,
    -479,   -32,   269,  -479,  -479,  -479,    -7,  -479,    92,   176,
     138,   202,   252,   343,  -479,  -479,   913,   228,  -479,  -479,
    -479,  -479,   281,  -479,  -479,  -479,  -479,  -479,  -479,  -479,
    -479,  -479,  -479,  -479,  -479,   284,  -479,   273,  -479,  -479,
    -479,  -479,   282,  -479,  -479,    29,  -479,   293,  -479,   211,
     910,  -479,   285,     3,    -5,   283,   259,  -479,   271,   286,
      39,  -479,   103,  -479,   204,  -479,  -479,    65,   245,  -479,
      -2,     7,  -479,  -479,  -479,  -479,  -479,  -479,  -479,   357,
     365,   365,   365,   374,   305,   382,    45,  -479,   398,  -479,
     399,   400,   404,   405,   335,   423,   429,   415,   910,  -479,
     910,   910,   910,   910,   910,   910,   910,   910,   910,   910,
     910,   910,   910,   910,   910,   910,   766,  -479,   432,  -479,
    -479,  -479,  -479,  -479,  -479,  -479,   376,   376,   910,   910,
     910,   416,   910,   417,  -479,   442,   411,  -479,  -479,  -479,
     308,    87,   438,  -479,  -479,  -479,  -479,  -479,   806,  -479,
     354,   355,  -479,  -479,   416,   261,  -479,  -479,   818,   376,
     449,   433,   910,   431,  -479,   431,   431,    25,   376,   452,
     439,   910,   440,   441,   443,   368,    25,   376,   437,   447,
      25,  -479,   176,   138,   202,   202,   252,   252,   252,   252,
     343,   343,  -479,  -479,  -479,  -479,  -479,  -479,  -479,    59,
    -479,  -479,    98,  -479,   386,  -479,   340,    14,   446,   460,
     448,   471,   411,   472,   450,   383,  -479,   345,   910,   362,
    -479,  -479,  -479,  -479,  -479,   702,   376,  -479,    87,  -479,
    -479,   119,  -479,     5,   459,  -479,   342,   858,  -479,   456,
     456,   456,   390,   385,   466,   463,   -11,  -479,   247,  -479,
      16,  -479,  -479,  -479,  -479,   466,   474,    -4,    25,    25,
     466,   475,  -479,   910,  -479,  -479,  -479,  -479,   702,   477,
     910,   476,   450,   479,   114,   500,   422,  -479,    87,   910,
     384,  -479,   425,   490,    87,    87,  -479,  -479,   510,  -479,
     518,  -479,  -479,   376,  -479,   870,  -479,  -479,   498,   376,
    -479,    15,   503,   434,   910,  -479,  -479,    32,  -479,   517,
     451,   910,  -479,   466,   520,   466,   522,   523,   469,  -479,
     606,   910,   513,   910,   455,   542,   543,  -479,  -479,   525,
     480,   205,  -479,    12,    87,  -479,   910,  -479,  -479,  -479,
    -479,    87,  -479,  -479,   124,  -479,  -479,   478,   482,   376,
      19,  -479,  -479,   486,   376,    20,   544,   492,   545,   469,
     469,   566,    87,  -479,   141,   910,   163,   491,  -479,  -479,
     549,   580,    99,   493,  -479,  -479,  -479,    87,  -479,   494,
    -479,  -479,   376,   376,   469,  -479,   376,   469,  -479,   495,
     376,   469,   497,    87,  -479,   560,  -479,   499,    87,   416,
      99,   501,   542,  -479,   589,   126,   592,   594,    46,   595,
      42,   458,  -479,  -479,  -479,  -479,  -479,  -479,  -479,  -479,
     469,   505,   469,    87,   376,   469,   506,  -479,  -479,   598,
    -479,  -479,  -479,   485,  -479,  -479,   593,   526,   169,   596,
     527,   610,   615,   616,   601,   536,   626,  -479,  -479,  -479,
    -479,   537,  -479,    87,  -479,   469,   538,  -479,  -479,  -479,
      28,   376,   540,    55,   376,   614,   617,   618,    58,   376,
     548,  -479,  -479,   541,  -479,   469,   221,   611,   376,   550,
     230,   611,    62,   106,   112,   469,   234,   611,   376,  -479,
      87,   469,   631,   910,   547,   611,   376,   552,   551,   469,
     235,   553,   246,   469,   264,    87,   469,   554,   611,  -479,
      87,   283,  -479,   555,   469,   376,  -479,   556,   469,   376,
     557,   561,   469,  -479,    87,  -479,   562,  -479,  -479,    87,
     469,  -479,   563,   469,   376,  -479,   564,  -479,  -479,  -479,
      87,  -479,   565,   469,  -479,  -479,  -479,   567,  -479
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -479,  -479,  -479,  -479,   645,   662,   661,    10,  -479,   634,
     -30,  -479,   635,  -161,  -479,  -479,  -479,  -479,   290,  -479,
    -207,  -188,   356,   -19,    -8,  -479,  -479,   528,   521,   248,
     192,   244,    72,  -479,    61,  -479,  -479,  -479,   274,   128,
     198,   407,     2,  -479,  -479,   346,  -479,  -479,  -479,   408,
    -479,  -479,  -479,  -479,  -479,  -479,  -171,  -479,   650,  -479,
    -479,  -479,  -479,   481,  -479,  -479,  -479,  -196,  -479,  -479,
     418,   300,  -479,  -479,  -479,  -479,     0,   -78,   597,   361,
    -479,   237,  -428,  -479,   224,  -199,  -397,  -479,   225,  -479,
    -478,  -479,  -479,  -479,  -479,  -479,  -479,  -181,  -479
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -216
static const yytype_int16 yytable[] =
{
     103,   104,   105,    85,   131,    70,   110,   184,   277,    97,
     267,   260,   442,   443,   120,   253,   254,    96,   111,   305,
     281,   354,   397,   310,   148,    99,   148,   306,   361,   148,
     208,   311,   292,   500,   148,   292,   343,   471,   100,   401,
     473,   101,   344,   148,   476,   148,   209,   148,   282,   495,
     148,   148,   525,   548,    98,   500,   293,   296,   402,   557,
     210,   145,   292,   196,     9,   292,   307,   563,   146,   292,
     148,    97,   220,   501,    92,   503,   316,   221,   506,   529,
     576,   190,   535,   312,   209,   107,   549,   355,   114,   114,
     313,   149,   114,   192,   362,   352,   207,   341,   191,   113,
     115,   363,   365,   116,     2,    96,   359,   427,   523,   364,
     366,   367,   117,   292,   358,   340,   350,   435,   438,   292,
      37,    38,    39,    40,    41,   220,   150,   454,   540,   197,
     551,   491,   496,   487,   198,   456,   553,   209,   555,   492,
     231,   458,   459,   342,   560,   376,   493,   382,   431,   372,
     313,   377,   567,   387,   388,   313,   571,   394,   250,   574,
     256,   257,   199,   105,   406,   447,   408,   579,   200,   201,
     255,   582,   148,   152,   153,   586,   512,    37,    38,    39,
      40,    41,   392,   590,   454,   117,   592,   449,   396,   455,
     272,   133,   456,   286,   148,   457,   597,   134,   458,   459,
     250,   135,   300,   428,    37,    38,    39,    40,    41,   151,
     430,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   166,     1,     2,
     143,   446,   242,   243,   244,   245,   246,   247,   434,   154,
     155,   156,   157,   437,   448,   541,   468,    37,    38,    39,
      40,    41,   542,   482,   547,   179,   121,   168,   556,   568,
     332,   542,   478,   174,   175,   542,   542,   481,   286,   136,
     570,   469,   470,   356,   144,   472,   147,   542,   357,   475,
     186,    35,    36,    37,    38,    39,    40,    41,   572,   187,
     176,   177,   504,   158,   159,   542,   180,   181,   182,   183,
     188,   105,   424,   526,    51,   369,   530,   203,   204,   189,
     383,   536,   100,   505,   148,   122,   123,   124,   125,   126,
     127,   128,   522,   203,   278,   550,   552,   554,   122,   123,
     124,   125,   126,   127,   128,   400,   266,   250,   129,   148,
     390,   288,   405,   288,   288,   419,   236,   237,   238,   239,
     527,   137,   414,   531,   416,   328,   329,   193,   537,   559,
      35,    36,    37,    38,    39,    40,    41,   545,   315,   194,
     346,   148,   390,   148,   573,   268,   335,   558,   429,   577,
     211,    85,   184,   252,   195,   564,   160,   161,   162,   163,
     164,   165,   212,   587,   384,   329,   105,   217,   589,   218,
     234,   235,   240,   241,   580,   215,   216,   219,   583,   595,
     184,   225,    12,   290,   291,    13,    14,    15,    16,    17,
      18,    19,   485,   593,    20,   222,   223,   224,   226,   227,
     228,    21,    22,    23,    24,    25,   229,    26,   230,   251,
     261,   258,   122,   123,   124,   125,   126,   127,   128,   262,
     263,   268,   273,   274,    27,   488,   284,   285,   287,   297,
     308,    28,    29,    30,    31,   137,   304,   299,   301,   302,
     309,   303,   317,    32,   314,   319,    33,   320,   321,   323,
     325,   327,   345,   348,   349,    34,   350,   353,    35,    36,
      37,    38,    39,    40,    41,    42,    43,   351,   360,   368,
     371,    44,    45,    46,    47,    48,   373,   378,    49,   375,
      50,    51,    52,    13,    14,    15,    16,    17,    18,    19,
     380,   386,    20,  -174,   561,   391,   395,   398,   399,    21,
      22,    23,    24,    25,   411,    26,    37,    38,    39,    40,
      41,   403,   415,   454,   407,   404,   409,   410,   455,   418,
     420,   456,    27,   417,   457,   499,   421,   458,   459,    28,
      29,    30,    31,    37,    38,    39,    40,    41,   439,   441,
     454,    32,   432,   444,    33,   455,   433,  -213,   456,   452,
     436,   457,   509,    34,   458,   459,   440,   453,  -215,   474,
     467,   479,  -175,    42,    43,   477,   486,   480,   484,   489,
      45,   490,   494,   502,   507,   508,    49,   389,    50,    13,
      14,    15,    16,    17,    18,    19,   510,   515,    20,   513,
     511,   514,   516,   517,   518,    21,    22,    23,    24,    25,
     519,    26,   413,   520,   528,   521,   524,   532,   397,   539,
     533,   534,   538,   543,   546,   562,   565,   569,    27,   566,
      94,   584,   575,   578,   581,    28,    29,    30,    31,   585,
     588,   591,   594,   596,    11,   598,    95,    32,   130,   132,
      33,   425,   233,   109,   370,   333,   385,   336,   232,    34,
     322,   426,   185,   374,   497,   498,   279,   483,     0,    42,
      43,     0,     0,     0,     0,     0,    45,     0,     0,     0,
       0,     0,    49,     0,    50,    13,    14,    15,    16,    17,
      18,    19,     0,     0,    20,     0,     0,     0,     0,     0,
       0,    21,    22,    23,    24,    25,     0,    26,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    27,     0,     0,     0,     0,     0,
       0,    28,    29,    30,    31,     0,     0,    13,    14,    15,
      16,   102,    18,    32,     0,     0,    33,     0,     0,    13,
      14,    15,    16,   102,    18,    34,    24,    25,     0,    26,
       0,     0,     0,     0,     0,    42,    43,     0,    24,    25,
     248,    26,    45,     0,     0,     0,    27,     0,    49,     0,
      50,     0,     0,    28,    29,    30,    31,     0,    27,    13,
      14,    15,    16,   102,    18,    28,    29,    30,    31,     0,
       0,    13,    14,    15,    16,   102,    18,    34,    24,    25,
       0,    26,   271,     0,     0,     0,     0,    42,    43,    34,
      24,    25,   280,    26,     0,     0,     0,     0,    27,    42,
      43,     0,   119,     0,     0,    28,    29,    30,    31,     0,
      27,    13,    14,    15,    16,   102,    18,    28,    29,    30,
      31,     0,     0,    13,    14,    15,    16,   102,    18,    34,
      24,    25,     0,    26,     0,     0,   347,     0,     0,    42,
      43,    34,    24,    25,   393,    26,     0,     0,     0,     0,
      27,    42,    43,     0,     0,     0,     0,    28,    29,    30,
      31,     0,    27,    13,    14,    15,    16,   102,    18,    28,
      29,    30,    31,     0,     0,     0,     0,     0,     0,     0,
       0,    34,    24,    25,     0,    26,   166,     0,     0,     0,
       0,    42,    43,    34,     0,   167,     0,     0,     0,     0,
       0,     0,    27,    42,    43,     0,     0,     0,     0,    28,
      29,    30,    31,     0,     0,     0,   168,   169,   170,   171,
     172,   173,   174,   175,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    34,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    42,    43,     0,     0,     0,     0,   176,
     177
};

static const yytype_int16 yycheck[] =
{
      19,    20,    21,     3,    34,     3,    25,    85,   204,    53,
     191,   182,   409,   410,    33,   176,   177,     7,    26,   226,
     208,    32,     7,   230,    31,     7,    31,   226,    32,    31,
      23,   230,     7,   461,    31,     7,    31,   434,    27,     7,
     437,    30,    37,    31,   441,    31,    39,    31,   209,     7,
      31,    31,    24,   531,    98,   483,    31,   218,    26,   537,
      53,    93,     7,    24,     7,     7,   227,   545,   100,     7,
      31,    53,    27,   470,   102,   472,   257,    32,   475,    24,
     558,   100,    24,    24,    39,     7,    24,    98,    27,    28,
      31,    98,    31,    98,    98,   294,    98,   278,    95,    27,
      28,   308,   309,    31,    75,    95,   305,    95,   505,   308,
     309,   310,    98,     7,    98,   276,   101,    98,    98,     7,
      78,    79,    80,    81,    82,    27,    34,    85,   525,    26,
      24,    85,    90,     7,    31,    93,    24,    39,   535,    93,
     148,    99,   100,    24,   541,    31,   100,   328,    24,   320,
      31,    37,   549,   334,   335,    31,   553,   345,   166,   556,
     179,   180,    97,   182,   363,    24,   365,   564,   103,   104,
     178,   568,    31,    35,    36,   572,     7,    78,    79,    80,
      81,    82,   343,   580,    85,    98,   583,    24,   349,    90,
     198,     7,    93,   212,    31,    96,   593,     7,    99,   100,
     208,     7,   221,   384,    78,    79,    80,    81,    82,    33,
     391,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,    23,    74,    75,
       7,   412,   160,   161,   162,   163,   164,   165,   399,    37,
      38,    39,    40,   404,   415,    24,   427,    78,    79,    80,
      81,    82,    31,   449,    24,    27,     7,    53,    24,    24,
     268,    31,   443,    59,    60,    31,    31,   448,   287,     7,
      24,   432,   433,    26,     7,   436,     7,    31,    31,   440,
       7,    76,    77,    78,    79,    80,    81,    82,    24,     7,
      86,    87,   473,    41,    42,    31,    15,    16,    17,    18,
       7,   320,    97,   510,    99,   313,   513,    62,    63,    98,
     329,   518,    27,   474,    31,    66,    67,    68,    69,    70,
      71,    72,   503,    62,    63,   532,   533,   534,    66,    67,
      68,    69,    70,    71,    72,   354,    28,   345,    89,    31,
     338,   213,   361,   215,   216,   375,   154,   155,   156,   157,
     511,    89,   371,   514,   373,    10,    11,    98,   519,   540,
      76,    77,    78,    79,    80,    81,    82,   528,    28,    98,
      28,    31,   370,    31,   555,    13,    14,   538,   386,   560,
      23,   381,   460,     7,    98,   546,    43,    44,    45,    46,
      47,    48,    27,   574,    10,    11,   415,    23,   579,    94,
     152,   153,   158,   159,   565,   131,   132,    25,   569,   590,
     488,     7,     0,   215,   216,     3,     4,     5,     6,     7,
       8,     9,   452,   584,    12,    27,    27,    27,    23,    94,
       7,    19,    20,    21,    22,    23,     7,    25,    23,     7,
      23,    25,    66,    67,    68,    69,    70,    71,    72,     7,
      39,    13,    98,    98,    42,   455,     7,    24,    27,     7,
      23,    49,    50,    51,    52,    89,    98,    28,    28,    28,
      23,    28,    26,    61,    88,    15,    64,    29,     7,     7,
      30,    98,    23,    27,    94,    73,   101,    24,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    31,    24,    24,
      23,    89,    90,    91,    92,    93,    30,     7,    96,    30,
      98,    99,   100,     3,     4,     5,     6,     7,     8,     9,
      98,    31,    12,    98,   543,     7,    28,    24,    94,    19,
      20,    21,    22,    23,    65,    25,    78,    79,    80,    81,
      82,    24,    29,    85,    24,    94,    24,    24,    90,     7,
       7,    93,    42,    98,    96,    97,    31,    99,   100,    49,
      50,    51,    52,    78,    79,    80,    81,    82,    24,    24,
      85,    61,    94,     7,    64,    90,    94,    97,    93,    30,
      94,    96,    97,    73,    99,   100,    94,     7,    97,    94,
      97,    31,    98,    83,    84,    98,     7,    98,    97,     7,
      90,     7,     7,    98,    98,     7,    96,    97,    98,     3,
       4,     5,     6,     7,     8,     9,    23,     7,    12,    23,
      94,    94,     7,     7,    23,    19,    20,    21,    22,    23,
      94,    25,    26,     7,    94,    98,    98,    23,     7,    98,
      23,    23,    94,    32,    94,    98,    94,    94,    42,    98,
       5,    94,    98,    98,    98,    49,    50,    51,    52,    98,
      98,    98,    98,    98,     2,    98,     5,    61,    34,    34,
      64,   381,   151,    23,   318,   268,   330,   269,   150,    73,
     262,   381,    85,   322,   460,   460,   205,   450,    -1,    83,
      84,    -1,    -1,    -1,    -1,    -1,    90,    -1,    -1,    -1,
      -1,    -1,    96,    -1,    98,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    20,    21,    22,    23,    -1,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    50,    51,    52,    -1,    -1,     3,     4,     5,
       6,     7,     8,    61,    -1,    -1,    64,    -1,    -1,     3,
       4,     5,     6,     7,     8,    73,    22,    23,    -1,    25,
      -1,    -1,    -1,    -1,    -1,    83,    84,    -1,    22,    23,
      24,    25,    90,    -1,    -1,    -1,    42,    -1,    96,    -1,
      98,    -1,    -1,    49,    50,    51,    52,    -1,    42,     3,
       4,     5,     6,     7,     8,    49,    50,    51,    52,    -1,
      -1,     3,     4,     5,     6,     7,     8,    73,    22,    23,
      -1,    25,    26,    -1,    -1,    -1,    -1,    83,    84,    73,
      22,    23,    24,    25,    -1,    -1,    -1,    -1,    42,    83,
      84,    -1,    98,    -1,    -1,    49,    50,    51,    52,    -1,
      42,     3,     4,     5,     6,     7,     8,    49,    50,    51,
      52,    -1,    -1,     3,     4,     5,     6,     7,     8,    73,
      22,    23,    -1,    25,    -1,    -1,    28,    -1,    -1,    83,
      84,    73,    22,    23,    24,    25,    -1,    -1,    -1,    -1,
      42,    83,    84,    -1,    -1,    -1,    -1,    49,    50,    51,
      52,    -1,    42,     3,     4,     5,     6,     7,     8,    49,
      50,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    73,    22,    23,    -1,    25,    23,    -1,    -1,    -1,
      -1,    83,    84,    73,    -1,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    83,    84,    -1,    -1,    -1,    -1,    49,
      50,    51,    52,    -1,    -1,    -1,    53,    54,    55,    56,
      57,    58,    59,    60,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    83,    84,    -1,    -1,    -1,    -1,    86,
      87
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
     114,   115,   117,     7,     7,     7,     7,    89,   114,   115,
     116,   117,   118,     7,     7,    93,   100,     7,    31,    98,
      34,    33,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    23,    32,    53,    54,
      55,    56,    57,    58,    59,    60,    86,    87,   130,    27,
      15,    16,    17,    18,   182,   183,     7,     7,     7,    98,
     128,    95,    98,    98,    98,    98,    24,    26,    31,    97,
     103,   104,   201,    62,    63,   167,   168,    98,    23,    39,
      53,    23,    27,   143,   144,   143,   143,    23,    94,    25,
      27,    32,    27,    27,    27,     7,    23,    94,     7,     7,
      23,   129,   132,   133,   134,   134,   135,   135,   135,   135,
     136,   136,   137,   137,   137,   137,   137,   137,    24,   126,
     129,     7,     7,   118,   118,   129,   128,   128,    25,   172,
     161,    23,     7,    39,   175,   121,    28,   202,    13,   153,
     154,    26,   129,    98,    98,   203,   169,   172,    63,   168,
      24,   126,   118,   119,     7,    24,   128,    27,   144,   145,
     145,   145,     7,    31,   125,   190,   118,     7,   199,    28,
     128,    28,    28,    28,    98,   125,   190,   118,    23,    23,
     125,   190,    24,    31,    88,    28,   202,    26,   173,    15,
      29,     7,   175,     7,   174,    30,   184,    98,    10,    11,
     149,   150,   129,   146,   156,    14,   154,   155,   127,   147,
     118,   202,    24,    31,    37,    23,    28,    28,    27,    94,
     101,    31,   190,    24,    32,    98,    26,    31,    98,   190,
      24,    32,    98,   125,   190,   125,   190,   190,    24,   129,
     127,    23,   161,    30,   184,    30,    31,    37,     7,   185,
      98,   122,   202,   128,    10,   150,    31,   202,   202,    97,
     147,     7,   118,    24,   126,    28,   118,     7,    24,    94,
     128,     7,    26,    24,    94,   128,   190,    24,   190,    24,
      24,    65,   191,    26,   128,    29,   128,    98,     7,   115,
       7,    31,   177,   179,    97,   123,   176,    95,   202,   129,
     202,    24,    94,    94,   118,    98,    94,   118,    98,    24,
      94,    24,   191,   191,     7,   192,   202,    24,   161,    24,
     178,   180,    30,     7,    85,    90,    93,    96,    99,   100,
     181,   186,   187,   188,   189,   193,   196,    97,   202,   118,
     118,   191,   118,   191,    94,   118,   191,    98,   202,    31,
      98,   202,   172,   186,    97,   115,     7,     7,   181,     7,
       7,    85,    93,   100,     7,     7,    90,   189,   193,    97,
     187,   191,    98,   191,   202,   118,   191,    98,     7,    97,
      23,    94,     7,    23,    94,     7,     7,     7,    23,    94,
       7,    98,   202,   191,    98,    24,   125,   118,    94,    24,
     125,   118,    23,    23,    23,    24,   125,   118,    94,    98,
     191,    24,    31,    32,   195,   118,    94,    24,   195,    24,
     125,    24,   125,    24,   125,   191,    24,   195,   118,   202,
     191,   128,    98,   195,   118,    94,    98,   191,    24,    94,
      24,   191,    24,   202,   191,    98,   195,   202,    98,   191,
     118,    98,   191,   118,    94,    98,   191,   202,    98,   202,
     191,    98,   191,   118,    98,   202,    98,   191,    98
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
#line 235 "diksam.y"
    {
			(yyval.type_specifier) = dkc_create_array_type_specifier((yyvsp[(1) - (3)].type_specifier));
		}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 241 "diksam.y"
    {//fix-me : shift/reduce
			(yyval.type_specifier)= dkc_create_template_type_specifier((yyvsp[(1) - (4)].identifier),(yyvsp[(3) - (4)].template));
		}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 247 "diksam.y"
    {
                    (yyval.type_specifier) = dkc_create_type_specifier((yyvsp[(1) - (1)].basic_type_specifier));
        }
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 257 "diksam.y"
    {
			(yyval.template)=dkc_create_template_list((yyvsp[(1) - (1)].type_specifier));
		}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 261 "diksam.y"
    {
            (yyval.template) = dkc_chain_template_list((yyvsp[(1) - (3)].template), (yyvsp[(3) - (3)].type_specifier));
        }
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 268 "diksam.y"
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
#line 278 "diksam.y"
    {
			BcGetCurrentCompilerContext()->isLib=0;
		}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 290 "diksam.y"
    {
            dkc_function_define((yyvsp[(9) - (11)].type_specifier), (yyvsp[(3) - (11)].identifier), (yyvsp[(5) - (11)].parameter_list), (yyvsp[(10) - (11)].exception_list), NULL,(yyvsp[(6) - (11)].apost));
        }
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 294 "diksam.y"
    {
            dkc_function_define((yyvsp[(8) - (10)].type_specifier), (yyvsp[(3) - (10)].identifier), NULL, (yyvsp[(9) - (10)].exception_list), NULL,(yyvsp[(5) - (10)].apost));
        }
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 298 "diksam.y"
    {
            dkc_function_define(0, (yyvsp[(3) - (9)].identifier), (yyvsp[(5) - (9)].parameter_list), (yyvsp[(8) - (9)].exception_list), NULL,(yyvsp[(6) - (9)].apost));
        }
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 302 "diksam.y"
    {
			//printf("lib:%s\n",BcGetCurrentCompilerContext()->libname);
            dkc_function_define(0, (yyvsp[(3) - (8)].identifier), NULL, (yyvsp[(7) - (8)].exception_list), NULL,(yyvsp[(5) - (8)].apost));
        }
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 309 "diksam.y"
    {
            dkc_function_define((yyvsp[(8) - (10)].type_specifier), (yyvsp[(2) - (10)].identifier), (yyvsp[(4) - (10)].parameter_list), (yyvsp[(9) - (10)].exception_list), (yyvsp[(10) - (10)].block),(yyvsp[(5) - (10)].apost));
        }
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 313 "diksam.y"
    {
            dkc_function_define((yyvsp[(7) - (9)].type_specifier), (yyvsp[(2) - (9)].identifier), NULL, (yyvsp[(8) - (9)].exception_list), (yyvsp[(9) - (9)].block),(yyvsp[(4) - (9)].apost));
        }
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 317 "diksam.y"
    { //modified
            dkc_function_define(0, (yyvsp[(2) - (8)].identifier), (yyvsp[(4) - (8)].parameter_list), (yyvsp[(7) - (8)].exception_list), (yyvsp[(8) - (8)].block),(yyvsp[(5) - (8)].apost));
        }
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 321 "diksam.y"
    {
            dkc_function_define(0, (yyvsp[(2) - (7)].identifier), NULL, (yyvsp[(6) - (7)].exception_list), (yyvsp[(7) - (7)].block),(yyvsp[(4) - (7)].apost));
        }
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 328 "diksam.y"
    {
            (yyval.parameter_list) = dkc_create_parameter((yyvsp[(3) - (3)].type_specifier), (yyvsp[(1) - (3)].identifier));
        }
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 332 "diksam.y"
    {
            (yyval.parameter_list) = dkc_chain_parameter((yyvsp[(1) - (5)].parameter_list), (yyvsp[(5) - (5)].type_specifier), (yyvsp[(3) - (5)].identifier));
        }
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 338 "diksam.y"
    {
            (yyval.argument_list) = dkc_create_argument_list((yyvsp[(1) - (1)].expression));
        }
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 342 "diksam.y"
    {
            (yyval.argument_list) = dkc_chain_argument_list((yyvsp[(1) - (3)].argument_list), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 348 "diksam.y"
    {
            (yyval.statement_list) = dkc_create_statement_list((yyvsp[(1) - (1)].statement));
        }
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 352 "diksam.y"
    {
            (yyval.statement_list) = dkc_chain_statement_list((yyvsp[(1) - (2)].statement_list), (yyvsp[(2) - (2)].statement));
        }
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 359 "diksam.y"
    {
            (yyval.expression) = dkc_create_comma_expression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 366 "diksam.y"
    {
            (yyval.expression) = dkc_create_assign_expression((yyvsp[(1) - (3)].expression), (yyvsp[(2) - (3)].assignment_operator), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 372 "diksam.y"
    {
            (yyval.assignment_operator) = NORMAL_ASSIGN;
        }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 376 "diksam.y"
    {
            (yyval.assignment_operator) = ADD_ASSIGN;
        }
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 380 "diksam.y"
    {
            (yyval.assignment_operator) = SUB_ASSIGN;
        }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 384 "diksam.y"
    {
            (yyval.assignment_operator) = MUL_ASSIGN;
        }
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 388 "diksam.y"
    {
            (yyval.assignment_operator) = DIV_ASSIGN;
        }
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 392 "diksam.y"
    {
            (yyval.assignment_operator) = MOD_ASSIGN;
        }
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 399 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(LOGICAL_OR_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 406 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(LOGICAL_AND_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 413 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(EQ_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 417 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(NE_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 424 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(GT_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 428 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(GE_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 432 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(LT_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 436 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(LE_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 443 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(ADD_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 447 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(SUB_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 454 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(MUL_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 458 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(DIV_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 462 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(MOD_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 466 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(BIT_AND_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 470 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(BIT_OR_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 474 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(BIT_XOR_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 481 "diksam.y"
    {
            (yyval.expression) = dkc_create_minus_expression((yyvsp[(2) - (2)].expression));
        }
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 485 "diksam.y"
    {
            (yyval.expression) = dkc_create_logical_not_expression((yyvsp[(2) - (2)].expression));
        }
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 489 "diksam.y"
    {
            (yyval.expression) = dkc_create_bit_not_expression((yyvsp[(2) - (2)].expression));
        }
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 496 "diksam.y"
    {
            (yyval.expression) = dkc_create_incdec_expression((yyvsp[(1) - (2)].expression), INCREMENT_EXPRESSION);
        }
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 500 "diksam.y"
    {
            (yyval.expression) = dkc_create_incdec_expression((yyvsp[(1) - (2)].expression), DECREMENT_EXPRESSION);
        }
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 504 "diksam.y"
    {
            (yyval.expression) = dkc_create_instanceof_expression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].type_specifier));
        }
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 512 "diksam.y"
    {
            (yyval.expression) = dkc_create_identifier_expression((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 516 "diksam.y"
    {
			(yyval.expression)=BcCreateAutoExpression((yyvsp[(1) - (1)].identifier));
		}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 522 "diksam.y"
    {
            (yyval.expression) = dkc_create_index_expression((yyvsp[(1) - (4)].expression), (yyvsp[(3) - (4)].expression));
        }
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 526 "diksam.y"
    {
            Expression *identifier = dkc_create_identifier_expression((yyvsp[(1) - (4)].identifier));
            (yyval.expression) = dkc_create_index_expression(identifier, (yyvsp[(3) - (4)].expression));
        }
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 531 "diksam.y"
    {
            (yyval.expression) = dkc_create_member_expression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].identifier));
        }
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 535 "diksam.y"
    {
            (yyval.expression) = dkc_create_function_call_expression((yyvsp[(1) - (4)].expression), (yyvsp[(3) - (4)].argument_list));
        }
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 539 "diksam.y"
    {
            (yyval.expression) = dkc_create_function_call_expression((yyvsp[(1) - (3)].expression), NULL);
        }
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 543 "diksam.y"
    {
            (yyval.expression) = (yyvsp[(2) - (3)].expression);
        }
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 547 "diksam.y"
    {
            (yyval.expression) = dkc_create_down_cast_expression((yyvsp[(1) - (4)].expression), (yyvsp[(3) - (4)].type_specifier));
        }
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 555 "diksam.y"
    {
            (yyval.expression) = dkc_create_boolean_expression(DVM_TRUE);
        }
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 559 "diksam.y"
    {
            (yyval.expression) = dkc_create_boolean_expression(DVM_FALSE);
        }
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 563 "diksam.y"
    {
            (yyval.expression) = dkc_create_null_expression();
        }
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 568 "diksam.y"
    {
            (yyval.expression) = dkc_create_this_expression();
        }
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 572 "diksam.y"
    {
            (yyval.expression) = dkc_create_super_expression();
        }
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 576 "diksam.y"
    {
			(yyval.expression) = dkc_create_new_delegate_expression();
		}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 580 "diksam.y"
    {
            (yyval.expression) = dkc_create_new_expression((yyvsp[(2) - (4)].identifier), NULL, NULL);
        }
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 584 "diksam.y"
    {
            (yyval.expression) = dkc_create_new_expression((yyvsp[(2) - (5)].identifier), NULL, (yyvsp[(4) - (5)].argument_list));
        }
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 588 "diksam.y"
    {
            (yyval.expression) = dkc_create_new_expression((yyvsp[(2) - (6)].identifier), (yyvsp[(4) - (6)].identifier), NULL);
        }
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 592 "diksam.y"
    {
            (yyval.expression) = dkc_create_new_expression((yyvsp[(2) - (7)].identifier), (yyvsp[(4) - (7)].identifier), (yyvsp[(6) - (7)].argument_list));
        }
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 598 "diksam.y"
    {
            (yyval.expression) = dkc_create_array_literal_expression((yyvsp[(2) - (3)].expression_list));
        }
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 602 "diksam.y"
    {
            (yyval.expression) = dkc_create_array_literal_expression((yyvsp[(2) - (4)].expression_list));
        }
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 608 "diksam.y"
    {
            (yyval.expression) = dkc_create_basic_array_creation((yyvsp[(2) - (3)].basic_type_specifier), (yyvsp[(3) - (3)].array_dimension), NULL);
        }
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 612 "diksam.y"
    {
            (yyval.expression) = dkc_create_basic_array_creation((yyvsp[(2) - (4)].basic_type_specifier), (yyvsp[(3) - (4)].array_dimension), (yyvsp[(4) - (4)].array_dimension));
        }
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 616 "diksam.y"
    {
            (yyval.expression) = dkc_create_class_array_creation((yyvsp[(2) - (3)].type_specifier), (yyvsp[(3) - (3)].array_dimension), NULL);
        }
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 621 "diksam.y"
    {
            (yyval.expression) = dkc_create_class_array_creation((yyvsp[(2) - (4)].type_specifier), (yyvsp[(3) - (4)].array_dimension), (yyvsp[(4) - (4)].array_dimension));
        }
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 625 "diksam.y"
    {
            (yyval.expression) = dkc_create_class_array_creation((yyvsp[(2) - (3)].type_specifier), (yyvsp[(3) - (3)].array_dimension), NULL);
        }
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 629 "diksam.y"
    {
            (yyval.expression) = dkc_create_class_array_creation((yyvsp[(2) - (4)].type_specifier), (yyvsp[(3) - (4)].array_dimension), (yyvsp[(4) - (4)].array_dimension));
        }
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 636 "diksam.y"
    {
            (yyval.array_dimension) = dkc_chain_array_dimension((yyvsp[(1) - (2)].array_dimension), (yyvsp[(2) - (2)].array_dimension));
        }
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 642 "diksam.y"
    {
            (yyval.array_dimension) = dkc_create_array_dimension((yyvsp[(2) - (3)].expression));
        }
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 648 "diksam.y"
    {
            (yyval.array_dimension) = dkc_create_array_dimension(NULL);
        }
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 652 "diksam.y"
    {
            (yyval.array_dimension) = dkc_chain_array_dimension((yyvsp[(1) - (3)].array_dimension),
                                           dkc_create_array_dimension(NULL));
        }
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 659 "diksam.y"
    {
            (yyval.expression_list) = NULL;
        }
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 663 "diksam.y"
    {
            (yyval.expression_list) = dkc_create_expression_list((yyvsp[(1) - (1)].expression));
        }
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 667 "diksam.y"
    {
            (yyval.expression_list) = dkc_chain_expression_list((yyvsp[(1) - (3)].expression_list), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 673 "diksam.y"
    {
          (yyval.statement) = dkc_create_expression_statement((yyvsp[(1) - (2)].expression));
        }
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 689 "diksam.y"
    {/*empty line*/
			(yyval.statement)=0;
		}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 695 "diksam.y"
    {
            (yyval.statement) = dkc_create_if_statement((yyvsp[(2) - (4)].expression), (yyvsp[(4) - (4)].block), NULL, NULL);
        }
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 699 "diksam.y"
    {
			//printf("IF-ELSE %d\n",dkc_get_current_compiler()->current_line_number);
            (yyval.statement) = dkc_create_if_statement((yyvsp[(2) - (6)].expression), (yyvsp[(4) - (6)].block), NULL, (yyvsp[(6) - (6)].block));
        }
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 704 "diksam.y"
    {
            (yyval.statement) = dkc_create_if_statement((yyvsp[(2) - (5)].expression), (yyvsp[(4) - (5)].block), (yyvsp[(5) - (5)].elsif), NULL);
        }
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 708 "diksam.y"
    {
            (yyval.statement) = dkc_create_if_statement((yyvsp[(2) - (7)].expression), (yyvsp[(4) - (7)].block), (yyvsp[(5) - (7)].elsif), (yyvsp[(7) - (7)].block));
        }
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 715 "diksam.y"
    {
            (yyval.elsif) = dkc_chain_elsif_list((yyvsp[(1) - (2)].elsif), (yyvsp[(2) - (2)].elsif));
        }
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 721 "diksam.y"
    {
            (yyval.elsif) = dkc_create_elsif((yyvsp[(2) - (4)].expression), (yyvsp[(4) - (4)].block));
        }
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 727 "diksam.y"
    {
            (yyval.identifier) = NULL;
        }
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 731 "diksam.y"
    {
            (yyval.identifier) = (yyvsp[(1) - (2)].identifier);
        }
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 737 "diksam.y"
    {
            (yyval.statement) = dkc_create_switch_statement((yyvsp[(2) - (5)].expression), (yyvsp[(4) - (5)].case_list), (yyvsp[(5) - (5)].block));
        }
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 744 "diksam.y"
    {
            (yyval.case_list) = dkc_chain_case((yyvsp[(1) - (2)].case_list), (yyvsp[(2) - (2)].case_list));
        }
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 750 "diksam.y"
    {
            (yyval.case_list) = dkc_create_one_case((yyvsp[(2) - (3)].expression_list), (yyvsp[(3) - (3)].block));
        }
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 756 "diksam.y"
    {
            (yyval.block) = NULL;
        }
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 760 "diksam.y"
    {
            (yyval.block) = (yyvsp[(2) - (2)].block);
        }
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 766 "diksam.y"
    {
            (yyval.expression_list) = dkc_create_expression_list((yyvsp[(1) - (1)].expression));
        }
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 770 "diksam.y"
    {
            (yyval.expression_list) = dkc_chain_expression_list((yyvsp[(1) - (3)].expression_list), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 776 "diksam.y"
    {
            (yyval.statement) = dkc_create_while_statement((yyvsp[(1) - (4)].identifier), (yyvsp[(3) - (4)].expression), (yyvsp[(4) - (4)].block));
        }
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 782 "diksam.y"
    {
            (yyval.statement) = dkc_create_for_statement((yyvsp[(1) - (8)].identifier), (yyvsp[(3) - (8)].expression), (yyvsp[(5) - (8)].expression), (yyvsp[(7) - (8)].expression), (yyvsp[(8) - (8)].block));
        }
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 788 "diksam.y"
    {
            (yyval.statement) = dkc_create_do_while_statement((yyvsp[(1) - (8)].identifier), (yyvsp[(3) - (8)].block), (yyvsp[(6) - (8)].expression));
        }
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 794 "diksam.y"
    {
            (yyval.statement) = dkc_create_foreach_statement((yyvsp[(1) - (8)].identifier), (yyvsp[(4) - (8)].identifier), (yyvsp[(6) - (8)].expression), (yyvsp[(8) - (8)].block));
        }
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 800 "diksam.y"
    {
            (yyval.expression) = NULL;
        }
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 807 "diksam.y"
    {
            (yyval.statement) = dkc_create_return_statement((yyvsp[(2) - (3)].expression));
        }
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 813 "diksam.y"
    {
            (yyval.identifier) = NULL;
        }
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 820 "diksam.y"
    {
            (yyval.statement) = dkc_create_break_statement((yyvsp[(2) - (3)].identifier));
        }
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 826 "diksam.y"
    {
            (yyval.statement) = dkc_create_continue_statement((yyvsp[(2) - (3)].identifier));
        }
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 832 "diksam.y"
    {
            (yyval.statement) = dkc_create_try_statement((yyvsp[(2) - (5)].block), (yyvsp[(3) - (5)].catch_clause), (yyvsp[(5) - (5)].block));
        }
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 836 "diksam.y"
    {
            (yyval.statement) = dkc_create_try_statement((yyvsp[(2) - (4)].block), NULL, (yyvsp[(4) - (4)].block));
        }
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 840 "diksam.y"
    {
            (yyval.statement) = dkc_create_try_statement((yyvsp[(2) - (3)].block), (yyvsp[(3) - (3)].catch_clause), NULL);
        }
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 847 "diksam.y"
    {
            (yyval.catch_clause) = dkc_chain_catch_list((yyvsp[(1) - (2)].catch_clause), (yyvsp[(2) - (2)].catch_clause));
        }
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 853 "diksam.y"
    {
            (yyval.catch_clause) = dkc_start_catch_clause();
        }
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 857 "diksam.y"
    {
            (yyval.catch_clause) = dkc_end_catch_clause((yyvsp[(2) - (5)].catch_clause), (yyvsp[(3) - (5)].type_specifier), (yyvsp[(4) - (5)].identifier), (yyvsp[(5) - (5)].block));
        }
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 863 "diksam.y"
    {
            (yyval.statement) = dkc_create_throw_statement((yyvsp[(2) - (3)].expression));
        }
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 867 "diksam.y"
    {
            (yyval.statement) = dkc_create_throw_statement(NULL);
        }
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 873 "diksam.y"
    {
            (yyval.statement) = dkc_create_declaration_statement(DVM_FALSE, (yyvsp[(4) - (5)].type_specifier), (yyvsp[(2) - (5)].identifier), NULL);
        }
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 877 "diksam.y"
    {
            (yyval.statement) = dkc_create_declaration_statement(DVM_FALSE, (yyvsp[(4) - (7)].type_specifier), (yyvsp[(2) - (7)].identifier), (yyvsp[(6) - (7)].expression));
        }
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 881 "diksam.y"
    {
            (yyval.statement) = dkc_create_declaration_statement(DVM_FALSE, (yyvsp[(4) - (5)].type_specifier), (yyvsp[(2) - (5)].identifier), NULL);
        }
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 885 "diksam.y"
    {
            (yyval.statement) = dkc_create_declaration_statement(DVM_TRUE, (yyvsp[(4) - (7)].type_specifier), (yyvsp[(2) - (7)].identifier), (yyvsp[(6) - (7)].expression));
        }
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 891 "diksam.y"
    {
            (yyval.block) = dkc_open_block(0);
        }
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 895 "diksam.y"
    {
            (yyval.block) = dkc_close_block((yyvsp[(2) - (4)].block), (yyvsp[(3) - (4)].statement_list));
        }
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 899 "diksam.y"
    {
            Block *empty_block = dkc_open_block(0);
            (yyval.block) = dkc_close_block(empty_block, NULL);
        }
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 906 "diksam.y"
    {
            (yyval.template_def) = dkc_create_template_declare_list((yyvsp[(1) - (1)].identifier),NULL);
        }
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 910 "diksam.y"
    {
            (yyval.template_def) = dkc_chain_template_declare_list((yyvsp[(1) - (3)].template_def), (yyvsp[(3) - (3)].identifier),NULL);
        }
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 914 "diksam.y"
    {
            (yyval.template_def) = dkc_create_template_declare_list((yyvsp[(1) - (3)].identifier),(yyvsp[(3) - (3)].type_specifier));
        }
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 918 "diksam.y"
    {
            (yyval.template_def) = dkc_chain_template_declare_list((yyvsp[(1) - (5)].template_def), (yyvsp[(3) - (5)].identifier) ,(yyvsp[(5) - (5)].type_specifier));
        }
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 924 "diksam.y"
    {
			(yyval.template_def)=(yyvsp[(2) - (3)].template_def);
		}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 928 "diksam.y"
    {(yyval.template_def)=NULL;}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 933 "diksam.y"
    {
            dkc_start_class_definition(NULL, (yyvsp[(1) - (5)].class_or_interface), (yyvsp[(2) - (5)].identifier),(yyvsp[(3) - (5)].template_def), (yyvsp[(4) - (5)].extends_list));
        }
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 937 "diksam.y"
    {
            dkc_class_define((yyvsp[(7) - (8)].member_declaration));
        }
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 942 "diksam.y"
    {
            dkc_start_class_definition(&(yyvsp[(1) - (6)].class_or_member_modifier), (yyvsp[(2) - (6)].class_or_interface), (yyvsp[(3) - (6)].identifier),(yyvsp[(4) - (6)].template_def), (yyvsp[(5) - (6)].extends_list));
        }
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 945 "diksam.y"
    {
            dkc_class_define((yyvsp[(8) - (9)].member_declaration));
        }
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 949 "diksam.y"
    {
            dkc_start_class_definition(NULL, (yyvsp[(1) - (5)].class_or_interface), (yyvsp[(2) - (5)].identifier),(yyvsp[(3) - (5)].template_def), (yyvsp[(4) - (5)].extends_list));
        }
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 953 "diksam.y"
    {
            dkc_class_define(NULL);
        }
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 958 "diksam.y"
    {
            dkc_start_class_definition(&(yyvsp[(1) - (6)].class_or_member_modifier), (yyvsp[(2) - (6)].class_or_interface), (yyvsp[(3) - (6)].identifier),(yyvsp[(4) - (6)].template_def), (yyvsp[(5) - (6)].extends_list));
        }
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 962 "diksam.y"
    {
            dkc_class_define(NULL);
        }
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 969 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_chain_class_or_member_modifier((yyvsp[(1) - (2)].class_or_member_modifier), (yyvsp[(2) - (2)].class_or_member_modifier));
        }
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 976 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(VIRTUAL_MODIFIER);
        }
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 980 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(OVERRIDE_MODIFIER);
        }
    break;

  case 222:

/* Line 1455 of yacc.c  */
#line 984 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(ABSTRACT_MODIFIER);
        }
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 990 "diksam.y"
    {
            (yyval.class_or_interface) = DVM_CLASS_DEFINITION;
        }
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 994 "diksam.y"
    {
            (yyval.class_or_interface) = DVM_INTERFACE_DEFINITION;
        }
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 1000 "diksam.y"
    {
            (yyval.extends_list) = NULL;
        }
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 1004 "diksam.y"
    {
            (yyval.extends_list) = (yyvsp[(2) - (2)].extends_list);
        }
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 1010 "diksam.y"
    {
            (yyval.extends_list) = dkc_create_extends_list((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 1014 "diksam.y"
    {
            (yyval.extends_list) = dkc_chain_extends_list((yyvsp[(1) - (3)].extends_list), (yyvsp[(3) - (3)].identifier));
        }
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 1021 "diksam.y"
    {
            (yyval.member_declaration) = dkc_chain_member_declaration((yyvsp[(1) - (2)].member_declaration), (yyvsp[(2) - (2)].member_declaration));
        }
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 1031 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_method_member(NULL, (yyvsp[(1) - (1)].function_definition), DVM_FALSE);
        }
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 1035 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_method_member(&(yyvsp[(1) - (2)].class_or_member_modifier), (yyvsp[(2) - (2)].function_definition), DVM_FALSE);
        }
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 1039 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_method_member(NULL, (yyvsp[(1) - (1)].function_definition), DVM_TRUE);
        }
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 1043 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_method_member(&(yyvsp[(1) - (2)].class_or_member_modifier), (yyvsp[(2) - (2)].function_definition), DVM_TRUE);
        }
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 1049 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define((yyvsp[(7) - (9)].type_specifier), (yyvsp[(2) - (9)].identifier), (yyvsp[(4) - (9)].parameter_list), (yyvsp[(8) - (9)].exception_list), (yyvsp[(9) - (9)].block));
        }
    break;

  case 238:

/* Line 1455 of yacc.c  */
#line 1053 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define((yyvsp[(6) - (8)].type_specifier), (yyvsp[(2) - (8)].identifier), NULL, (yyvsp[(7) - (8)].exception_list), (yyvsp[(8) - (8)].block));
        }
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 1057 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define((yyvsp[(8) - (10)].type_specifier), (yyvsp[(3) - (10)].identifier), (yyvsp[(5) - (10)].parameter_list), (yyvsp[(9) - (10)].exception_list), NULL);
        }
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 1061 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define((yyvsp[(7) - (9)].type_specifier), (yyvsp[(3) - (9)].identifier), NULL, (yyvsp[(8) - (9)].exception_list), NULL);
        }
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 1065 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define(0, (yyvsp[(2) - (7)].identifier), (yyvsp[(4) - (7)].parameter_list), (yyvsp[(6) - (7)].exception_list), (yyvsp[(7) - (7)].block));
        }
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 1069 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define(0, (yyvsp[(2) - (6)].identifier), NULL, (yyvsp[(5) - (6)].exception_list), (yyvsp[(6) - (6)].block));
        }
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 1073 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define(0, (yyvsp[(3) - (8)].identifier), (yyvsp[(5) - (8)].parameter_list), (yyvsp[(7) - (8)].exception_list), NULL);
        }
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 1077 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define(0, (yyvsp[(3) - (7)].identifier), NULL, (yyvsp[(6) - (7)].exception_list), NULL);
        }
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 1083 "diksam.y"
    {
			(yyval.apost)=0;
		}
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 1087 "diksam.y"
    {
			(yyval.apost)=1;
		}
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 1093 "diksam.y"
    {
            (yyval.exception_list) = NULL;
        }
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 1097 "diksam.y"
    {
            (yyval.exception_list) = (yyvsp[(2) - (2)].exception_list);
        }
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 1103 "diksam.y"
    {
            (yyval.exception_list) = dkc_create_throws((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 1107 "diksam.y"
    {
            (yyval.exception_list) = dkc_chain_exception_list((yyvsp[(1) - (3)].exception_list), (yyvsp[(3) - (3)].identifier));
        }
    break;

  case 251:

/* Line 1455 of yacc.c  */
#line 1113 "diksam.y"
    {
            (yyval.function_definition) = dkc_constructor_function_define((yyvsp[(2) - (7)].identifier), (yyvsp[(4) - (7)].parameter_list), (yyvsp[(6) - (7)].exception_list), (yyvsp[(7) - (7)].block));
        }
    break;

  case 252:

/* Line 1455 of yacc.c  */
#line 1117 "diksam.y"
    {
            (yyval.function_definition) = dkc_constructor_function_define((yyvsp[(2) - (6)].identifier), NULL, (yyvsp[(5) - (6)].exception_list), (yyvsp[(6) - (6)].block));
        }
    break;

  case 253:

/* Line 1455 of yacc.c  */
#line 1121 "diksam.y"
    {
            (yyval.function_definition) = dkc_constructor_function_define((yyvsp[(3) - (8)].identifier), (yyvsp[(5) - (8)].parameter_list), (yyvsp[(7) - (8)].exception_list), NULL);
        }
    break;

  case 254:

/* Line 1455 of yacc.c  */
#line 1125 "diksam.y"
    {
            (yyval.function_definition) = dkc_constructor_function_define((yyvsp[(3) - (7)].identifier), NULL, (yyvsp[(6) - (7)].exception_list), NULL);
        }
    break;

  case 255:

/* Line 1455 of yacc.c  */
#line 1131 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(PUBLIC_MODIFIER);
        }
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 1135 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(PRIVATE_MODIFIER);
        }
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 1141 "diksam.y"
    {
            (yyval.expression) = NULL;
        }
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 1145 "diksam.y"
    {
            (yyval.expression) = (yyvsp[(2) - (2)].expression);
        }
    break;

  case 259:

/* Line 1455 of yacc.c  */
#line 1151 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(NULL, DVM_FALSE, (yyvsp[(4) - (6)].type_specifier), (yyvsp[(2) - (6)].identifier), (yyvsp[(5) - (6)].expression));
        }
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 1156 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(&(yyvsp[(1) - (6)].class_or_member_modifier), DVM_FALSE, (yyvsp[(4) - (6)].type_specifier), (yyvsp[(2) - (6)].identifier), (yyvsp[(5) - (6)].expression));
        }
    break;

  case 261:

/* Line 1455 of yacc.c  */
#line 1160 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(NULL, DVM_TRUE, (yyvsp[(4) - (6)].type_specifier), (yyvsp[(2) - (6)].identifier), (yyvsp[(5) - (6)].expression));
        }
    break;

  case 262:

/* Line 1455 of yacc.c  */
#line 1165 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(&(yyvsp[(1) - (7)].class_or_member_modifier), DVM_TRUE, (yyvsp[(5) - (7)].type_specifier), (yyvsp[(3) - (7)].identifier), (yyvsp[(6) - (7)].expression));
        }
    break;

  case 263:

/* Line 1455 of yacc.c  */
#line 1169 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(&(yyvsp[(2) - (7)].class_or_member_modifier), DVM_TRUE, (yyvsp[(5) - (7)].type_specifier), (yyvsp[(3) - (7)].identifier), (yyvsp[(6) - (7)].expression));
        }
    break;

  case 264:

/* Line 1455 of yacc.c  */
#line 1175 "diksam.y"
    {
            dkc_create_delegate_definition((yyvsp[(8) - (10)].type_specifier), (yyvsp[(2) - (10)].identifier), (yyvsp[(4) - (10)].parameter_list), (yyvsp[(9) - (10)].exception_list),(yyvsp[(5) - (10)].apost));
        }
    break;

  case 265:

/* Line 1455 of yacc.c  */
#line 1179 "diksam.y"
    {
            dkc_create_delegate_definition((yyvsp[(7) - (9)].type_specifier), (yyvsp[(2) - (9)].identifier), NULL, (yyvsp[(8) - (9)].exception_list),(yyvsp[(4) - (9)].apost));
        }
    break;

  case 266:

/* Line 1455 of yacc.c  */
#line 1185 "diksam.y"
    {
            dkc_create_enum_definition((yyvsp[(2) - (5)].identifier), (yyvsp[(4) - (5)].enumerator));
        }
    break;

  case 267:

/* Line 1455 of yacc.c  */
#line 1189 "diksam.y"
    {
            dkc_create_enum_definition((yyvsp[(2) - (6)].identifier), (yyvsp[(4) - (6)].enumerator));
        }
    break;

  case 268:

/* Line 1455 of yacc.c  */
#line 1195 "diksam.y"
    {
            (yyval.enumerator) = dkc_create_enumerator((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 269:

/* Line 1455 of yacc.c  */
#line 1199 "diksam.y"
    {
            (yyval.enumerator) = dkc_chain_enumerator((yyvsp[(1) - (3)].enumerator), (yyvsp[(3) - (3)].identifier));
        }
    break;

  case 270:

/* Line 1455 of yacc.c  */
#line 1205 "diksam.y"
    {
            dkc_create_const_definition(NULL, (yyvsp[(2) - (5)].identifier), (yyvsp[(4) - (5)].expression));
        }
    break;

  case 271:

/* Line 1455 of yacc.c  */
#line 1209 "diksam.y"
    {
            dkc_create_const_definition((yyvsp[(2) - (4)].type_specifier), (yyvsp[(3) - (4)].identifier), NULL);
        }
    break;

  case 272:

/* Line 1455 of yacc.c  */
#line 1215 "diksam.y"
    {
			(yyval.apost)=0;
		}
    break;

  case 273:

/* Line 1455 of yacc.c  */
#line 1219 "diksam.y"
    {
			(yyval.apost)=1;
		}
    break;

  case 274:

/* Line 1455 of yacc.c  */
#line 1223 "diksam.y"
    {
			(yyval.apost)=-1;
		}
    break;

  case 275:

/* Line 1455 of yacc.c  */
#line 1229 "diksam.y"
    {
            (yyval.block) = dkc_open_block((yyvsp[(2) - (2)].apost));
			//printf("E1 %d\n",dkc_get_current_compiler());
        }
    break;

  case 276:

/* Line 1455 of yacc.c  */
#line 1234 "diksam.y"
    {
            (yyval.block) = dkc_close_block((yyvsp[(3) - (5)].block), (yyvsp[(4) - (5)].statement_list));
			//printf("C1 %d\n",dkc_get_current_compiler()->current_line_number);
        }
    break;

  case 277:

/* Line 1455 of yacc.c  */
#line 1239 "diksam.y"
    {
            Block *empty_block = dkc_open_block(0);
            (yyval.block) = dkc_close_block(empty_block, NULL);
			//printf("C2 %d\n",dkc_get_current_compiler()->current_line_number);
        }
    break;



/* Line 1455 of yacc.c  */
#line 4217 "y.tab.c"
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
#line 1245 "diksam.y"


