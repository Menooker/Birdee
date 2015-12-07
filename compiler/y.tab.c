
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
     SHARED = 360
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
#line 359 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 371 "y.tab.c"

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
#define YYLAST   1038

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  106
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  100
/* YYNRULES -- Number of rules.  */
#define YYNRULES  279
/* YYNRULES -- Number of states.  */
#define YYNSTATES  602

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   360

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
     105
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
     659,   661,   664,   665,   671,   675,   678,   685,   694,   700,
     708,   709,   714,   717,   719,   723,   727,   733,   737,   738,
     739,   749,   750,   761,   762,   771,   772,   782,   784,   787,
     789,   791,   793,   795,   797,   799,   800,   803,   805,   809,
     811,   814,   816,   818,   820,   823,   825,   828,   838,   847,
     858,   868,   876,   883,   892,   900,   901,   904,   905,   908,
     910,   914,   922,   929,   938,   946,   948,   950,   951,   954,
     961,   968,   975,   983,   991,  1002,  1012,  1018,  1025,  1027,
    1031,  1037,  1042,  1043,  1045,  1046,  1049,  1052,  1053,  1059
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     107,     0,    -1,   108,    -1,   107,   114,    -1,    -1,   109,
     112,    -1,   109,    -1,   112,    -1,   108,   121,    -1,   110,
      -1,   109,   110,    -1,    74,   111,    98,    -1,     7,    -1,
     111,    53,     7,    -1,   113,    -1,   112,   113,    -1,    75,
     111,     7,    98,    -1,   125,    -1,   177,    -1,   148,    -1,
     198,    -1,   199,    -1,   201,    -1,    66,    -1,    67,    -1,
      68,    -1,    69,    -1,    70,    -1,    71,    -1,    72,    -1,
      89,    -1,     7,    -1,   115,    27,    28,    -1,     7,    27,
      28,    -1,   117,    27,    28,    -1,   118,    27,    28,    -1,
       7,    39,   120,    37,    -1,   115,    -1,   117,    -1,   116,
      -1,   118,    -1,   119,    -1,   120,    31,   119,    -1,    -1,
     102,     7,   122,    98,   123,    97,    -1,    -1,   123,   124,
      -1,   123,   177,    -1,    99,    93,     7,    23,   126,   191,
      24,    94,   119,   192,    98,    -1,    99,    93,     7,    23,
     191,    24,    94,   119,   192,    98,    -1,    99,   100,     7,
      23,   126,   191,    24,   192,    98,    -1,    99,   100,     7,
      23,   191,    24,   192,    98,    -1,    93,     7,    23,   126,
     191,    24,    94,   119,   192,   204,    -1,    93,     7,    23,
     191,    24,    94,   119,   192,   204,    -1,   100,     7,    23,
     126,   191,    24,   192,   204,    -1,   100,     7,    23,   191,
      24,   192,   204,    -1,   124,    -1,     7,    94,   119,    -1,
     126,    31,     7,    94,   119,    -1,   130,    -1,   127,    31,
     130,    -1,   148,    -1,   128,   148,    -1,   130,    -1,   129,
      31,   130,    -1,   132,    -1,   140,   131,   130,    -1,    32,
      -1,    54,    -1,    55,    -1,    56,    -1,    57,    -1,    58,
      -1,   133,    -1,   132,    34,   133,    -1,   134,    -1,   133,
      33,   134,    -1,   135,    -1,   134,    35,   135,    -1,   134,
      36,   135,    -1,   136,    -1,   135,    37,   136,    -1,   135,
      38,   136,    -1,   135,    39,   136,    -1,   135,    40,   136,
      -1,   137,    -1,   136,    41,   137,    -1,   136,    42,   137,
      -1,   138,    -1,   137,    43,   138,    -1,   137,    44,   138,
      -1,   137,    45,   138,    -1,   137,    46,   138,    -1,   137,
      47,   138,    -1,   137,    48,   138,    -1,   139,    -1,    42,
     138,    -1,    52,   138,    -1,    49,   138,    -1,   140,    -1,
     140,    59,    -1,   140,    60,    -1,   140,    86,   119,    -1,
     141,    -1,   143,    -1,     7,    -1,     8,    -1,   141,    27,
     129,    28,    -1,     7,    27,   129,    28,    -1,   140,    53,
       7,    -1,   140,    23,   127,    24,    -1,   140,    23,    24,
      -1,    23,   129,    24,    -1,   140,    87,   119,    88,    -1,
       3,    -1,     4,    -1,     5,    -1,     6,    -1,    50,    -1,
      51,    -1,    22,    -1,   142,    -1,    83,    -1,    84,    -1,
      73,    89,    23,    24,    -1,    73,     7,    23,    24,    -1,
      73,     7,    23,   127,    24,    -1,    73,     7,    53,     7,
      23,    24,    -1,    73,     7,    53,     7,    23,   127,    24,
      -1,    25,   147,    26,    -1,    25,   147,    31,    26,    -1,
      73,   115,   144,    -1,    73,   115,   144,   146,    -1,    73,
     116,   144,    -1,    73,   116,   144,   146,    -1,    73,   118,
     144,    -1,    73,   118,   144,   146,    -1,   145,    -1,   144,
     145,    -1,    27,   129,    28,    -1,    27,    28,    -1,   146,
      27,    28,    -1,    -1,   130,    -1,   147,    31,   130,    -1,
     129,    98,    -1,   149,    -1,   153,    -1,   158,    -1,   159,
      -1,   160,    -1,   161,    -1,   163,    -1,   165,    -1,   166,
      -1,   167,    -1,   171,    -1,   172,    -1,    98,    -1,     9,
     129,    95,   204,    -1,     9,   129,    95,   204,    10,   204,
      -1,     9,   129,    95,   204,   150,    -1,     9,   129,    95,
     204,   150,    10,   204,    -1,   151,    -1,   150,   151,    -1,
      11,   129,    95,   204,    -1,    -1,     7,    30,    -1,    12,
     129,    98,   154,   156,    -1,   155,    -1,   154,   155,    -1,
      13,   157,   204,    -1,    -1,    14,   204,    -1,   130,    -1,
     147,    31,   130,    -1,   152,    15,   129,   204,    -1,   152,
      17,   162,    29,   162,    29,   162,   204,    -1,   152,    16,
     173,    15,    23,   129,    24,    98,    -1,   152,    18,    23,
       7,    30,   129,    24,   173,    -1,    -1,   129,    -1,    19,
     162,    98,    -1,    -1,     7,    -1,    20,   164,    98,    -1,
      21,   164,    98,    -1,    61,   204,   168,    63,   204,    -1,
      61,   204,    63,   173,    -1,    61,   204,   168,    -1,   169,
      -1,   168,   169,    -1,    -1,    62,   170,   119,     7,   204,
      -1,    64,   129,    98,    -1,    64,    98,    -1,    96,     7,
      94,   202,   119,    98,    -1,    96,     7,    94,   202,   119,
      32,   129,    98,    -1,    90,     7,    94,   119,    98,    -1,
      90,     7,    94,   119,    32,   129,    98,    -1,    -1,    25,
     174,   128,    26,    -1,    25,    26,    -1,     7,    -1,   175,
      31,     7,    -1,     7,    30,   116,    -1,   175,    31,     7,
      30,   116,    -1,    39,   175,    37,    -1,    -1,    -1,   202,
     184,     7,   176,   185,    98,   178,   187,    97,    -1,    -1,
     202,   182,   184,     7,   176,   185,    98,   179,   187,    97,
      -1,    -1,   202,   184,     7,   176,   185,    98,   180,    97,
      -1,    -1,   202,   182,   184,     7,   176,   185,    98,   181,
      97,    -1,   183,    -1,   182,   183,    -1,   195,    -1,    80,
      -1,    81,    -1,    82,    -1,    76,    -1,    77,    -1,    -1,
      30,   186,    -1,     7,    -1,   186,    31,     7,    -1,   188,
      -1,   187,   188,    -1,   189,    -1,   197,    -1,   190,    -1,
     182,   190,    -1,   194,    -1,   182,   194,    -1,    93,     7,
      23,   126,    24,    94,   119,   192,   204,    -1,    93,     7,
      23,    24,    94,   119,   192,   204,    -1,    99,    93,     7,
      23,   126,    24,    94,   119,   192,    98,    -1,    99,    93,
       7,    23,    24,    94,   119,   192,    98,    -1,   100,     7,
      23,   126,    24,   192,   204,    -1,   100,     7,    23,    24,
     192,   204,    -1,    99,   100,     7,    23,   126,    24,   192,
      98,    -1,    99,   100,     7,    23,    24,   192,    98,    -1,
      -1,    31,   101,    -1,    -1,    65,   193,    -1,     7,    -1,
     193,    31,     7,    -1,    85,     7,    23,   126,    24,   192,
     204,    -1,    85,     7,    23,    24,   192,   204,    -1,    99,
      85,     7,    23,   126,    24,   192,    98,    -1,    99,    85,
       7,    23,    24,   192,    98,    -1,    78,    -1,    79,    -1,
      -1,    32,   129,    -1,    96,     7,    94,   119,   196,    98,
      -1,   182,     7,    94,   119,   196,    98,    -1,    90,     7,
      94,   119,   196,    98,    -1,   182,    90,     7,    94,   119,
     196,    98,    -1,    90,   182,     7,    94,   119,   196,    98,
      -1,    89,     7,    23,   126,   191,    24,    94,   119,   192,
      98,    -1,    89,     7,    23,   191,    24,    94,   119,   192,
      98,    -1,    91,     7,    25,   200,    26,    -1,    91,     7,
      25,   200,    31,    26,    -1,     7,    -1,   200,    31,     7,
      -1,    92,     7,    32,   129,    98,    -1,    92,   119,     7,
      98,    -1,    -1,   105,    -1,    -1,   103,    98,    -1,   104,
      98,    -1,    -1,    98,   203,   205,   128,    97,    -1,    98,
      97,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   103,   103,   104,   108,   111,   115,   119,   123,   129,
     130,   136,   142,   146,   152,   153,   159,   165,   166,   167,
     174,   175,   176,   179,   183,   187,   191,   195,   199,   203,
     207,   213,   219,   225,   231,   235,   241,   247,   251,   252,
     253,   257,   261,   269,   268,   283,   286,   287,   290,   294,
     298,   302,   309,   313,   317,   321,   325,   328,   332,   338,
     342,   348,   352,   358,   359,   365,   366,   372,   376,   380,
     384,   388,   392,   398,   399,   405,   406,   412,   413,   417,
     423,   424,   428,   432,   436,   442,   443,   447,   453,   454,
     458,   462,   466,   470,   474,   480,   481,   485,   489,   495,
     496,   500,   504,   510,   511,   512,   516,   522,   526,   531,
     535,   539,   543,   547,   551,   552,   553,   554,   555,   559,
     563,   567,   568,   572,   576,   580,   584,   588,   592,   598,
     602,   608,   612,   616,   620,   625,   629,   635,   636,   642,
     648,   652,   660,   663,   667,   673,   677,   678,   679,   680,
     681,   682,   683,   684,   685,   686,   687,   688,   689,   695,
     699,   704,   708,   714,   715,   721,   728,   731,   737,   743,
     744,   750,   757,   760,   766,   770,   776,   782,   788,   794,
     801,   804,   807,   814,   817,   820,   826,   832,   836,   840,
     846,   847,   854,   853,   863,   867,   873,   877,   881,   885,
     892,   891,   899,   906,   910,   914,   918,   924,   929,   934,
     932,   943,   941,   950,   949,   959,   957,   968,   969,   975,
     976,   980,   984,   990,   994,  1001,  1004,  1010,  1014,  1020,
    1021,  1027,  1028,  1031,  1035,  1039,  1043,  1049,  1053,  1057,
    1061,  1065,  1069,  1073,  1077,  1084,  1087,  1094,  1097,  1103,
    1107,  1113,  1117,  1121,  1125,  1131,  1135,  1142,  1145,  1151,
    1155,  1160,  1164,  1169,  1175,  1179,  1185,  1189,  1195,  1199,
    1205,  1209,  1216,  1219,  1226,  1229,  1233,  1240,  1239,  1249
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
  "UNSAFE", "SAFE", "SHARED", "$accept", "translation_unit",
  "initial_declaration", "require_list", "require_declaration",
  "package_name", "rename_list", "rename_declaration",
  "definition_or_statement", "basic_type_specifier",
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
     355,   356,   357,   358,   359,   360
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   106,   107,   107,   108,   108,   108,   108,   108,   109,
     109,   110,   111,   111,   112,   112,   113,   114,   114,   114,
     114,   114,   114,   115,   115,   115,   115,   115,   115,   115,
     115,   116,   117,   117,   117,   117,   118,   119,   119,   119,
     119,   120,   120,   122,   121,   123,   123,   123,   124,   124,
     124,   124,   125,   125,   125,   125,   125,   126,   126,   127,
     127,   128,   128,   129,   129,   130,   130,   131,   131,   131,
     131,   131,   131,   132,   132,   133,   133,   134,   134,   134,
     135,   135,   135,   135,   135,   136,   136,   136,   137,   137,
     137,   137,   137,   137,   137,   138,   138,   138,   138,   139,
     139,   139,   139,   140,   140,   140,   140,   141,   141,   141,
     141,   141,   141,   141,   141,   141,   141,   141,   141,   141,
     141,   141,   141,   141,   141,   141,   141,   141,   141,   142,
     142,   143,   143,   143,   143,   143,   143,   144,   144,   145,
     146,   146,   147,   147,   147,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   149,
     149,   149,   149,   150,   150,   151,   152,   152,   153,   154,
     154,   155,   156,   156,   157,   157,   158,   159,   160,   161,
     162,   162,   163,   164,   164,   165,   166,   167,   167,   167,
     168,   168,   170,   169,   171,   171,   172,   172,   172,   172,
     174,   173,   173,   175,   175,   175,   175,   176,   176,   178,
     177,   179,   177,   180,   177,   181,   177,   182,   182,   183,
     183,   183,   183,   184,   184,   185,   185,   186,   186,   187,
     187,   188,   188,   189,   189,   189,   189,   190,   190,   190,
     190,   190,   190,   190,   190,   191,   191,   192,   192,   193,
     193,   194,   194,   194,   194,   195,   195,   196,   196,   197,
     197,   197,   197,   197,   198,   198,   199,   199,   200,   200,
     201,   201,   202,   202,   203,   203,   203,   205,   204,   204
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
       1,     2,     0,     5,     3,     2,     6,     8,     5,     7,
       0,     4,     2,     1,     3,     3,     5,     3,     0,     0,
       9,     0,    10,     0,     8,     0,     9,     1,     2,     1,
       1,     1,     1,     1,     1,     0,     2,     1,     3,     1,
       2,     1,     1,     1,     2,     1,     2,     9,     8,    10,
       9,     7,     6,     8,     7,     0,     2,     0,     2,     1,
       3,     7,     6,     8,     7,     1,     1,     0,     2,     6,
       6,     6,     7,     7,    10,     9,     5,     6,     1,     3,
       5,     4,     0,     1,     0,     2,     2,     0,     5,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       4,     0,     0,   272,     2,     6,     9,     7,    14,    12,
       0,     0,     1,   114,   115,   116,   117,   105,   106,     0,
       0,   180,   183,   183,   120,     0,   142,     0,     0,   118,
     119,     0,     0,     0,     0,   122,   123,     0,     0,     0,
       0,     0,     0,   158,     0,     0,   273,     3,    56,    17,
       0,    63,    65,    73,    75,    77,    80,    85,    88,    95,
      99,   103,   121,   104,    19,   146,     0,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,    18,    20,
      21,    22,     0,     0,     8,    10,     5,    15,     0,    11,
       0,     0,   167,   105,     0,     0,   181,     0,   184,     0,
       0,     0,   143,     0,    96,    99,    98,    97,   274,     0,
     195,     0,    31,    23,    24,    25,    26,    27,    28,    29,
      30,     0,     0,     0,     0,     0,     0,    31,    30,    37,
      39,    38,    40,     0,     0,     0,     0,     0,     0,     0,
     145,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    67,     0,
      68,    69,    70,    71,    72,   100,   101,     0,     0,     0,
       0,     0,     0,   180,     0,   223,   224,   255,   256,   220,
     221,   222,     0,   217,     0,   219,    43,    13,    16,     0,
       0,     0,   182,   185,   186,   112,   129,     0,   279,     0,
       0,   277,   192,     0,   189,   190,   194,     0,     0,     0,
       0,     0,   131,   137,   133,   135,   245,     0,     0,     0,
       0,     0,     0,     0,     0,   245,   272,     0,     0,   245,
      64,    74,    76,    78,    79,    81,    82,    83,    84,    86,
      87,    89,    90,    91,    92,    93,    94,   111,     0,    59,
     109,    31,   102,     0,    66,     0,     0,   200,     0,     0,
       0,   218,     0,   208,     0,   108,   159,   142,   172,   169,
     130,   144,   275,   276,   166,     0,   188,     0,   191,   125,
       0,    41,     0,     0,   124,     0,     0,   138,   132,   134,
     136,     0,     0,   245,     0,     0,   268,     0,    33,     0,
      32,    34,    35,   271,   245,     0,     0,   245,   245,   245,
       0,   110,     0,   113,   107,   176,   202,   166,     0,   180,
       0,   208,     0,   225,    45,     0,     0,   161,   163,   143,
       0,     0,     0,   170,   168,   166,    61,     0,   187,   126,
       0,    36,     0,   139,   140,     0,     0,   246,     0,     0,
       0,     0,   198,   266,     0,   270,     0,     0,     0,   245,
       0,   245,     0,     0,   247,    60,   166,     0,     0,     0,
     225,   203,     0,     0,     0,   272,   160,     0,     0,   164,
       0,   171,   173,   278,    62,     0,    42,   127,     0,   141,
      57,     0,     0,     0,     0,   269,   267,     0,     0,     0,
     196,     0,     0,     0,   247,   247,     0,     0,   201,     0,
     180,     0,     0,     0,     0,   207,   227,   226,   209,    44,
      46,    47,     0,   162,   144,   193,   128,     0,     0,   247,
     199,     0,   247,     0,     0,     0,   247,     0,     0,   249,
     248,    55,     0,     0,     0,   211,    31,   205,   204,     0,
       0,     0,   165,    58,   247,     0,   247,     0,   197,     0,
     247,     0,    51,    54,     0,   178,   177,   179,     0,     0,
       0,   228,     0,     0,     0,     0,     0,     0,     0,     0,
     229,   231,   233,   235,   232,   214,     0,   265,     0,    53,
     247,     0,    50,   250,     0,   216,   206,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   234,   236,
     210,   230,   264,    52,     0,    49,   212,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    48,   247,
       0,   257,     0,     0,     0,   257,     0,     0,     0,   247,
       0,   257,     0,     0,   247,     0,     0,     0,   257,     0,
       0,     0,   247,     0,     0,     0,   247,     0,     0,   247,
       0,   257,   252,     0,   258,   261,     0,   247,     0,   259,
       0,   247,     0,     0,     0,   247,   242,     0,   260,     0,
     251,   263,     0,   247,   254,     0,   247,     0,   244,     0,
     241,   262,   238,     0,   253,     0,   247,   243,   237,   240,
       0,   239
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,     6,    10,     7,     8,    47,   129,
     130,   131,   132,   133,   282,    84,   264,   375,    48,    49,
     293,   248,   335,    50,    51,   169,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,   212,   213,
     288,   103,   336,    65,   327,   328,    66,    67,   268,   269,
     334,   331,    68,    69,    70,    71,    97,    72,    99,    73,
      74,    75,   204,   205,   275,    76,    77,   258,   317,   372,
     323,    78,   450,   468,   451,   469,   478,   183,   184,   374,
     417,   479,   480,   481,   482,   294,   407,   440,   483,   185,
     547,   484,    79,    80,   297,    81,    82,   201,   109,   274
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -406
static const yytype_int16 yypact[] =
{
      -5,    54,    54,   467,   -21,    -5,  -406,    66,  -406,  -406,
      20,    23,  -406,  -406,  -406,  -406,  -406,   239,  -406,   930,
     930,   930,   110,   110,  -406,   930,   930,   930,   930,  -406,
    -406,   930,    89,    13,   219,  -406,  -406,   152,   189,   193,
     306,   197,   221,  -406,    93,   246,  -406,  -406,  -406,  -406,
      -8,  -406,   223,   214,    44,   240,   130,   299,  -406,  -406,
     951,   243,  -406,  -406,  -406,  -406,   286,  -406,  -406,  -406,
    -406,  -406,  -406,  -406,  -406,  -406,  -406,  -406,  -406,  -406,
    -406,  -406,   456,   268,  -406,  -406,    66,  -406,   277,  -406,
     200,   930,  -406,   278,    -4,    -6,   294,   230,  -406,   238,
     241,   191,  -406,   109,  -406,   102,  -406,  -406,   121,   199,
    -406,     0,    14,  -406,  -406,  -406,  -406,  -406,  -406,  -406,
     326,   332,   332,   332,   337,   267,   339,   118,  -406,   335,
    -406,   338,   341,   359,   360,   276,   377,   378,   364,   930,
    -406,   930,   930,   930,   930,   930,   930,   930,   930,   930,
     930,   930,   930,   930,   930,   930,   930,   814,  -406,   381,
    -406,  -406,  -406,  -406,  -406,  -406,  -406,   431,   431,   930,
     930,   930,   365,   930,   366,  -406,  -406,  -406,  -406,  -406,
    -406,  -406,   456,  -406,   385,  -406,  -406,  -406,  -406,   266,
      89,   380,  -406,  -406,  -406,  -406,  -406,   866,  -406,   296,
     301,  -406,  -406,   365,   220,  -406,  -406,   826,   431,   390,
     376,   930,   375,  -406,   375,   375,    26,   431,   396,   379,
     930,   382,   383,   384,   308,    26,   303,   391,   393,    26,
    -406,   214,    44,   240,   240,   130,   130,   130,   130,   299,
     299,  -406,  -406,  -406,  -406,  -406,  -406,  -406,   196,  -406,
    -406,    94,  -406,   316,  -406,   287,     1,   387,   402,   389,
     412,  -406,   414,   394,   324,  -406,   282,   930,   307,  -406,
    -406,  -406,  -406,  -406,   762,   431,  -406,    89,  -406,  -406,
     207,  -406,    10,   400,  -406,   288,   878,  -406,   403,   403,
     403,   340,   334,   405,   417,    -3,  -406,   188,  -406,     3,
    -406,  -406,  -406,  -406,   405,   418,   431,    26,    26,   405,
     421,  -406,   930,  -406,  -406,  -406,  -406,   762,   425,   930,
     419,   394,   443,   438,  -406,    89,   930,   313,  -406,   371,
     446,    89,    89,  -406,  -406,   570,  -406,   471,  -406,  -406,
     431,  -406,   918,  -406,  -406,   452,   431,  -406,     8,   457,
     397,   930,  -406,  -406,    32,  -406,   469,   401,    16,   405,
     470,   405,   472,   480,   440,  -406,   666,   930,   477,   930,
     438,   478,   101,   500,   413,    98,  -406,    21,    89,  -406,
     930,  -406,  -406,  -406,  -406,    89,  -406,  -406,   209,  -406,
    -406,   416,   420,   431,    12,  -406,  -406,   427,   431,   930,
    -406,   488,   428,   489,   440,   440,   508,    89,  -406,   210,
     930,   212,   426,   516,   519,  -406,  -406,   494,   432,  -406,
    -406,  -406,    89,  -406,   441,  -406,  -406,   431,   431,   440,
    -406,   431,   440,    15,   436,   431,   440,   444,    89,  -406,
     510,  -406,   445,    89,   365,   447,  -406,  -406,   515,   539,
     545,   450,  -406,  -406,   440,   451,   440,    89,  -406,   431,
     440,   454,  -406,  -406,   541,  -406,  -406,  -406,   545,   458,
     516,  -406,   546,    86,   547,   554,   106,   555,    49,   347,
    -406,  -406,  -406,  -406,  -406,  -406,   466,  -406,    89,  -406,
     440,   473,  -406,  -406,   518,  -406,  -406,   557,   474,   100,
     558,   475,   563,   576,   577,   562,   492,   580,  -406,  -406,
    -406,  -406,  -406,  -406,   490,  -406,  -406,    35,   431,   507,
      42,   431,   571,   579,   581,    53,   431,   511,  -406,   440,
     213,   574,   431,   513,   215,   574,    61,    64,   113,   440,
     224,   574,   431,    89,   440,   602,   930,   512,   574,   431,
     522,   530,   440,   227,   535,   228,   440,   232,    89,   440,
     534,   574,  -406,    89,   294,  -406,   538,   440,   431,  -406,
     542,   440,   431,   543,   544,   440,  -406,    89,  -406,   548,
    -406,  -406,    89,   440,  -406,   549,   440,   431,  -406,   550,
    -406,  -406,  -406,    89,  -406,   551,   440,  -406,  -406,  -406,
     552,  -406
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -406,  -406,  -406,  -406,   608,   631,   634,    17,  -406,   617,
     -31,  -406,   618,  -163,  -406,  -406,  -406,  -406,   280,  -406,
    -203,  -196,   342,   -19,   -13,  -406,  -406,   517,   514,   187,
     164,   202,    56,  -406,   310,  -406,  -406,  -406,   231,    59,
     142,   395,     5,  -406,  -406,   330,  -406,  -406,  -406,   408,
    -406,  -406,  -406,  -406,  -406,  -406,  -161,  -406,   638,  -406,
    -406,  -406,  -406,   459,  -406,  -406,  -406,  -194,  -406,  -406,
     343,   290,  -406,  -406,  -406,  -406,   -75,  -172,   495,   309,
    -406,   216,  -405,  -406,   203,  -185,  -354,  -406,   204,  -406,
    -388,  -406,  -406,  -406,  -406,  -406,   464,  -406,  -162,  -406
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -216
static const yytype_int16 yytable[] =
{
      94,    95,    96,   122,   252,   253,   101,   182,    64,   276,
     261,   280,   259,   102,   111,   391,    13,    14,    15,    16,
      93,    18,   304,   139,    87,   139,   309,   139,   266,   351,
      90,   139,   139,   291,   139,    24,    25,   207,    26,   395,
     305,   340,   291,   139,   310,   281,   139,   341,   399,   291,
     437,   438,   139,   208,   295,    27,   506,   292,   396,   529,
     291,     9,    28,    29,    30,    31,   533,   209,   291,     1,
       2,   291,   189,    88,   511,   455,    88,   539,   457,   143,
     144,    83,   461,   104,   106,   552,    34,   107,   554,   511,
     140,   190,   191,   498,   315,   352,    35,    36,   206,   108,
     486,   355,   488,    87,   359,   361,   491,   519,   349,   347,
     430,   110,   337,   458,   400,   338,   422,    98,    89,   356,
     291,   219,   360,   362,   363,   157,   230,   177,   178,   179,
     180,   181,   414,   208,   472,   196,   514,   556,   415,   507,
     197,     2,   474,   358,   249,   219,   388,   551,   476,   477,
     220,   255,   256,   560,    96,   159,   254,   208,   368,   124,
     566,   165,   166,   376,   177,   178,   179,   180,   181,   381,
     382,   149,   150,   579,   401,   543,   403,   386,   177,   178,
     179,   180,   181,   390,   271,   558,   136,   108,   167,   168,
     563,   502,   285,   137,   249,   419,   125,    44,   570,   503,
     126,   299,   574,    46,   134,   577,   504,   241,   242,   243,
     244,   245,   246,   582,   353,   195,   423,   585,   198,   354,
     311,   589,   139,   425,   199,   200,   112,   312,   135,   593,
     429,   339,   595,   426,   442,   432,   444,   544,   312,   550,
     312,   139,   600,   139,   545,   441,   545,   142,   559,   443,
     467,   571,   573,   138,   329,   545,   575,   141,   545,   545,
     452,   202,   203,   545,   453,   454,    91,   285,   456,    92,
     170,   287,   460,   287,   287,   186,   463,   145,   146,   147,
     148,   466,   202,   277,   187,   113,   114,   115,   116,   117,
     118,   119,   325,   326,   265,   489,   490,   139,   188,   365,
      96,   171,   172,   173,   174,    91,   261,   377,   120,   235,
     236,   237,   238,   127,   530,   314,   343,   534,   139,   139,
     267,   332,   540,   378,   326,   139,   513,   261,   192,   249,
     233,   234,   394,   553,   555,   557,   193,   105,   105,   194,
     384,   105,   151,   152,   153,   154,   155,   156,   409,   210,
     411,   239,   240,   214,   215,   531,   289,   290,   535,   211,
     216,   217,   221,   541,   218,   222,   224,   424,   223,   548,
     226,   384,   113,   114,   115,   116,   117,   118,   119,   561,
     433,   562,   447,   225,   227,   228,   567,   229,   250,   260,
     257,    96,   263,   267,   272,   128,   576,   283,   499,   273,
     284,   580,   286,   296,   313,   583,   303,   298,    46,   586,
     300,   301,   302,   316,   307,   590,   308,   318,   319,   320,
     592,   321,   324,   342,   596,   177,   178,   179,   180,   181,
     345,   598,   472,   322,   346,   347,   348,   473,   251,   496,
     474,   350,   357,   475,   510,   364,   476,   477,   367,   369,
     371,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,    12,   373,  -174,
      13,    14,    15,    16,    17,    18,    19,   380,   385,    20,
     389,   392,  -166,  -166,  -166,  -166,    21,    22,    23,    24,
      25,   393,    26,   397,   402,   398,   404,   113,   114,   115,
     116,   117,   118,   119,   405,   406,   410,   416,   413,    27,
     427,   418,   434,   436,   428,   439,    28,    29,    30,    31,
     128,   431,   435,   446,   445,   449,   448,   564,    32,  -213,
     459,    33,   175,   176,   177,   178,   179,   180,   181,  -175,
      34,   464,   462,   465,  -215,   470,   471,   485,   493,   487,
      35,    36,   492,   497,   500,   495,    37,    38,    39,    40,
      41,   501,   505,    42,   512,    43,    44,    45,   518,   521,
     522,   515,    46,    13,    14,    15,    16,    17,    18,    19,
     517,   520,    20,   523,   524,   525,   526,   527,   528,    21,
      22,    23,    24,    25,   536,    26,   177,   178,   179,   180,
     181,   532,   537,   472,   538,   542,   546,   549,   473,   391,
     565,   474,    27,    85,   475,   516,   568,   476,   477,    28,
      29,    30,    31,   177,   178,   179,   180,   181,   569,   572,
     472,    32,   578,    11,    33,   473,   581,   587,   474,    86,
     584,   475,   588,    34,   476,   477,   591,   594,   597,   599,
     601,   121,   123,    35,    36,   420,   232,   379,   231,   366,
      38,   100,   330,   278,   370,   421,    42,   383,    43,    13,
      14,    15,    16,    17,    18,    19,   333,   262,    20,   412,
       0,   508,   509,     0,   494,    21,    22,    23,    24,    25,
     306,    26,   408,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    27,     0,
       0,     0,     0,     0,     0,    28,    29,    30,    31,     0,
       0,     0,     0,     0,     0,     0,     0,    32,     0,     0,
      33,     0,     0,     0,     0,     0,     0,     0,     0,    34,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    35,
      36,     0,     0,     0,     0,     0,    38,     0,     0,     0,
       0,     0,    42,     0,    43,    13,    14,    15,    16,    17,
      18,    19,     0,     0,    20,     0,     0,     0,     0,     0,
       0,    21,    22,    23,    24,    25,     0,    26,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    27,     0,     0,     0,     0,     0,
       0,    28,    29,    30,    31,     0,     0,    13,    14,    15,
      16,    93,    18,    32,     0,     0,    33,     0,     0,    13,
      14,    15,    16,    93,    18,    34,    24,    25,   247,    26,
       0,     0,     0,     0,     0,    35,    36,     0,    24,    25,
     279,    26,    38,     0,     0,     0,    27,     0,    42,     0,
      43,     0,     0,    28,    29,    30,    31,     0,    27,    13,
      14,    15,    16,    93,    18,    28,    29,    30,    31,     0,
       0,    13,    14,    15,    16,    93,    18,    34,    24,    25,
       0,    26,   270,     0,     0,     0,     0,    35,    36,    34,
      24,    25,     0,    26,     0,     0,   344,     0,    27,    35,
      36,     0,     0,     0,     0,    28,    29,    30,    31,     0,
      27,    13,    14,    15,    16,    93,    18,    28,    29,    30,
      31,     0,     0,    13,    14,    15,    16,    93,    18,    34,
      24,    25,   387,    26,     0,     0,     0,     0,     0,    35,
      36,    34,    24,    25,     0,    26,     0,     0,     0,     0,
      27,    35,    36,     0,     0,     0,     0,    28,    29,    30,
      31,     0,    27,     0,   157,     0,     0,     0,     0,    28,
      29,    30,    31,   158,     0,     0,     0,     0,     0,     0,
       0,    34,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    35,    36,    34,   159,   160,   161,   162,   163,   164,
     165,   166,     0,    35,    36,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   167,   168
};

static const yytype_int16 yycheck[] =
{
      19,    20,    21,    34,   167,   168,    25,    82,     3,   203,
     182,   207,   173,    26,    33,     7,     3,     4,     5,     6,
       7,     8,   225,    31,     7,    31,   229,    31,   190,    32,
       7,    31,    31,     7,    31,    22,    23,    23,    25,     7,
     225,    31,     7,    31,   229,   208,    31,    37,    32,     7,
     404,   405,    31,    39,   217,    42,     7,    31,    26,    24,
       7,     7,    49,    50,    51,    52,    24,    53,     7,    74,
      75,     7,    91,    53,   479,   429,    53,    24,   432,    35,
      36,   102,   436,    27,    28,    24,    73,    31,    24,   494,
      98,    95,    98,     7,   256,    98,    83,    84,    98,    98,
     454,    98,   456,    86,   307,   308,   460,     7,   293,   101,
      98,    98,   275,    98,    98,   277,    95,     7,    98,   304,
       7,    27,   307,   308,   309,    23,   139,    78,    79,    80,
      81,    82,    31,    39,    85,    26,   490,    24,    37,    90,
      31,    75,    93,   306,   157,    27,   342,   535,    99,   100,
      32,   170,   171,   541,   173,    53,   169,    39,   319,     7,
     548,    59,    60,   325,    78,    79,    80,    81,    82,   331,
     332,    41,    42,   561,   359,   529,   361,   340,    78,    79,
      80,    81,    82,   346,   197,   539,    93,    98,    86,    87,
     544,    85,   211,   100,   207,    97,     7,    99,   552,    93,
       7,   220,   556,   105,     7,   559,   100,   151,   152,   153,
     154,   155,   156,   567,    26,    24,   378,   571,    97,    31,
      24,   575,    31,   385,   103,   104,     7,    31,     7,   583,
     393,    24,   586,    24,    24,   398,    24,    24,    31,    24,
      31,    31,   596,    31,    31,   407,    31,    33,    24,   410,
     444,    24,    24,     7,   267,    31,    24,    34,    31,    31,
     422,    62,    63,    31,   427,   428,    27,   286,   431,    30,
      27,   212,   435,   214,   215,     7,   438,    37,    38,    39,
      40,   443,    62,    63,     7,    66,    67,    68,    69,    70,
      71,    72,    10,    11,    28,   457,   459,    31,    98,   312,
     319,    15,    16,    17,    18,    27,   478,   326,    89,   145,
     146,   147,   148,     7,   517,    28,    28,   520,    31,    31,
      13,    14,   525,    10,    11,    31,   488,   499,    98,   342,
     143,   144,   351,   536,   537,   538,    98,    27,    28,    98,
     335,    31,    43,    44,    45,    46,    47,    48,   367,    23,
     369,   149,   150,   122,   123,   518,   214,   215,   521,    27,
      23,    94,    27,   526,    25,    27,     7,   380,    27,   532,
      94,   366,    66,    67,    68,    69,    70,    71,    72,   542,
     399,   543,   413,    23,     7,     7,   549,    23,     7,    23,
      25,   410,     7,    13,    98,    89,   558,     7,   473,    98,
      24,   563,    27,     7,    88,   568,    98,    28,   105,   572,
      28,    28,    28,    26,    23,   577,    23,    15,    29,     7,
     582,     7,    98,    23,   587,    78,    79,    80,    81,    82,
      27,   593,    85,    39,    94,   101,    31,    90,     7,   470,
      93,    24,    24,    96,    97,    24,    99,   100,    23,    30,
       7,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,     0,    30,    98,
       3,     4,     5,     6,     7,     8,     9,    31,     7,    12,
      28,    24,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    94,    25,    24,    24,    94,    24,    66,    67,    68,
      69,    70,    71,    72,    24,    65,    29,     7,    30,    42,
      94,    98,    24,    24,    94,     7,    49,    50,    51,    52,
      89,    94,    94,     7,    98,    31,     7,   546,    61,    97,
      94,    64,    76,    77,    78,    79,    80,    81,    82,    98,
      73,    31,    98,    98,    97,    30,     7,    97,     7,    98,
      83,    84,    98,     7,     7,    97,    89,    90,    91,    92,
      93,     7,     7,    96,    98,    98,    99,   100,    94,    94,
       7,    98,   105,     3,     4,     5,     6,     7,     8,     9,
      23,    23,    12,     7,     7,    23,    94,     7,    98,    19,
      20,    21,    22,    23,    23,    25,    78,    79,    80,    81,
      82,    94,    23,    85,    23,    94,    32,    94,    90,     7,
      98,    93,    42,     5,    96,    97,    94,    99,   100,    49,
      50,    51,    52,    78,    79,    80,    81,    82,    98,    94,
      85,    61,    98,     2,    64,    90,    98,    94,    93,     5,
      98,    96,    98,    73,    99,   100,    98,    98,    98,    98,
      98,    34,    34,    83,    84,   375,   142,   327,   141,   317,
      90,    23,   267,   204,   321,   375,    96,    97,    98,     3,
       4,     5,     6,     7,     8,     9,   268,   182,    12,   370,
      -1,   478,   478,    -1,   468,    19,    20,    21,    22,    23,
     226,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,
      64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,
      84,    -1,    -1,    -1,    -1,    -1,    90,    -1,    -1,    -1,
      -1,    -1,    96,    -1,    98,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    20,    21,    22,    23,    -1,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    50,    51,    52,    -1,    -1,     3,     4,     5,
       6,     7,     8,    61,    -1,    -1,    64,    -1,    -1,     3,
       4,     5,     6,     7,     8,    73,    22,    23,    24,    25,
      -1,    -1,    -1,    -1,    -1,    83,    84,    -1,    22,    23,
      24,    25,    90,    -1,    -1,    -1,    42,    -1,    96,    -1,
      98,    -1,    -1,    49,    50,    51,    52,    -1,    42,     3,
       4,     5,     6,     7,     8,    49,    50,    51,    52,    -1,
      -1,     3,     4,     5,     6,     7,     8,    73,    22,    23,
      -1,    25,    26,    -1,    -1,    -1,    -1,    83,    84,    73,
      22,    23,    -1,    25,    -1,    -1,    28,    -1,    42,    83,
      84,    -1,    -1,    -1,    -1,    49,    50,    51,    52,    -1,
      42,     3,     4,     5,     6,     7,     8,    49,    50,    51,
      52,    -1,    -1,     3,     4,     5,     6,     7,     8,    73,
      22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,    83,
      84,    73,    22,    23,    -1,    25,    -1,    -1,    -1,    -1,
      42,    83,    84,    -1,    -1,    -1,    -1,    49,    50,    51,
      52,    -1,    42,    -1,    23,    -1,    -1,    -1,    -1,    49,
      50,    51,    52,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    83,    84,    73,    53,    54,    55,    56,    57,    58,
      59,    60,    -1,    83,    84,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    74,    75,   107,   108,   109,   110,   112,   113,     7,
     111,   111,     0,     3,     4,     5,     6,     7,     8,     9,
      12,    19,    20,    21,    22,    23,    25,    42,    49,    50,
      51,    52,    61,    64,    73,    83,    84,    89,    90,    91,
      92,    93,    96,    98,    99,   100,   105,   114,   124,   125,
     129,   130,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   148,   149,   152,   153,   158,   159,
     160,   161,   163,   165,   166,   167,   171,   172,   177,   198,
     199,   201,   202,   102,   121,   110,   112,   113,    53,    98,
       7,    27,    30,     7,   129,   129,   129,   162,     7,   164,
     164,   129,   130,   147,   138,   140,   138,   138,    98,   204,
      98,   129,     7,    66,    67,    68,    69,    70,    71,    72,
      89,   115,   116,   118,     7,     7,     7,     7,    89,   115,
     116,   117,   118,   119,     7,     7,    93,   100,     7,    31,
      98,    34,    33,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    23,    32,    53,
      54,    55,    56,    57,    58,    59,    60,    86,    87,   131,
      27,    15,    16,    17,    18,    76,    77,    78,    79,    80,
      81,    82,   182,   183,   184,   195,     7,     7,    98,   129,
      95,    98,    98,    98,    98,    24,    26,    31,    97,   103,
     104,   203,    62,    63,   168,   169,    98,    23,    39,    53,
      23,    27,   144,   145,   144,   144,    23,    94,    25,    27,
      32,    27,    27,    27,     7,    23,    94,     7,     7,    23,
     130,   133,   134,   135,   135,   136,   136,   136,   136,   137,
     137,   138,   138,   138,   138,   138,   138,    24,   127,   130,
       7,     7,   119,   119,   130,   129,   129,    25,   173,   162,
      23,   183,   184,     7,   122,    28,   204,    13,   154,   155,
      26,   130,    98,    98,   205,   170,   173,    63,   169,    24,
     127,   119,   120,     7,    24,   129,    27,   145,   146,   146,
     146,     7,    31,   126,   191,   119,     7,   200,    28,   129,
      28,    28,    28,    98,   126,   191,   202,    23,    23,   126,
     191,    24,    31,    88,    28,   204,    26,   174,    15,    29,
       7,     7,    39,   176,    98,    10,    11,   150,   151,   130,
     147,   157,    14,   155,   156,   128,   148,   119,   204,    24,
      31,    37,    23,    28,    28,    27,    94,   101,    31,   191,
      24,    32,    98,    26,    31,    98,   191,    24,   119,   126,
     191,   126,   191,   191,    24,   130,   128,    23,   162,    30,
     176,     7,   175,    30,   185,   123,   204,   129,    10,   151,
      31,   204,   204,    97,   148,     7,   119,    24,   127,    28,
     119,     7,    24,    94,   129,     7,    26,    24,    94,    32,
      98,   191,    24,   191,    24,    24,    65,   192,    26,   129,
      29,   129,   185,    30,    31,    37,     7,   186,    98,    97,
     124,   177,    95,   204,   130,   204,    24,    94,    94,   119,
      98,    94,   119,   129,    24,    94,    24,   192,   192,     7,
     193,   204,    24,   162,    24,    98,     7,   116,     7,    31,
     178,   180,   204,   119,   119,   192,   119,   192,    98,    94,
     119,   192,    98,   204,    31,    98,   204,   173,   179,   181,
      30,     7,    85,    90,    93,    96,    99,   100,   182,   187,
     188,   189,   190,   194,   197,    97,   192,    98,   192,   204,
     119,   192,    98,     7,   187,    97,   116,     7,     7,   182,
       7,     7,    85,    93,   100,     7,     7,    90,   190,   194,
      97,   188,    98,   204,   192,    98,    97,    23,    94,     7,
      23,    94,     7,     7,     7,    23,    94,     7,    98,    24,
     126,   119,    94,    24,   126,   119,    23,    23,    23,    24,
     126,   119,    94,   192,    24,    31,    32,   196,   119,    94,
      24,   196,    24,   126,    24,   126,    24,   126,   192,    24,
     196,   119,   204,   192,   129,    98,   196,   119,    94,    98,
     192,    24,    94,    24,   192,    24,   204,   192,    98,   196,
     204,    98,   192,   119,    98,   192,   119,    94,    98,   192,
     204,    98,   204,   192,    98,   192,   119,    98,   204,    98,
     192,    98
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
#line 108 "diksam.y"
    {
            dkc_set_require_and_rename_list(NULL, NULL);
        }
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 112 "diksam.y"
    {
            dkc_set_require_and_rename_list((yyvsp[(1) - (2)].require_list), (yyvsp[(2) - (2)].rename_list));
        }
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 116 "diksam.y"
    {
            dkc_set_require_and_rename_list((yyvsp[(1) - (1)].require_list), NULL);
        }
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 120 "diksam.y"
    {
            dkc_set_require_and_rename_list(NULL, (yyvsp[(1) - (1)].rename_list));
        }
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 124 "diksam.y"
    {
            dkc_set_require_and_rename_list(NULL, NULL);
		}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 131 "diksam.y"
    {
            (yyval.require_list) = dkc_chain_require_list((yyvsp[(1) - (2)].require_list), (yyvsp[(2) - (2)].require_list));
        }
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 137 "diksam.y"
    {
            (yyval.require_list) = dkc_create_require_list((yyvsp[(2) - (3)].package_name));
        }
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 143 "diksam.y"
    {
            (yyval.package_name) = dkc_create_package_name((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 147 "diksam.y"
    {
            (yyval.package_name) = dkc_chain_package_name((yyvsp[(1) - (3)].package_name), (yyvsp[(3) - (3)].identifier));
        }
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 154 "diksam.y"
    {
            (yyval.rename_list) = dkc_chain_rename_list((yyvsp[(1) - (2)].rename_list), (yyvsp[(2) - (2)].rename_list));
        }
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 160 "diksam.y"
    {
            (yyval.rename_list) = dkc_create_rename_list((yyvsp[(2) - (4)].package_name), (yyvsp[(3) - (4)].identifier));
        }
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 168 "diksam.y"
    {
            DKC_Compiler *compiler = dkc_get_current_compiler();

            compiler->statement_list
                = dkc_chain_statement_list(compiler->statement_list, (yyvsp[(1) - (1)].statement));
        }
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 180 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_VOID_TYPE;
        }
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 184 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_BOOLEAN_TYPE;
        }
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 188 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_INT_TYPE;
        }
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 192 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_DOUBLE_TYPE;
        }
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 196 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_STRING_TYPE;
        }
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 200 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_VARIENT_TYPE;
        }
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 204 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_NATIVE_POINTER_TYPE;
        }
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 208 "diksam.y"
    {
            (yyval.basic_type_specifier) = DVM_DELEGATE_TYPE;
        }
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 214 "diksam.y"
    {
            (yyval.type_specifier) = dkc_create_identifier_type_specifier((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 220 "diksam.y"
    {
            TypeSpecifier *basic_type
                = dkc_create_type_specifier((yyvsp[(1) - (3)].basic_type_specifier));
            (yyval.type_specifier) = dkc_create_array_type_specifier(basic_type);
        }
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 226 "diksam.y"
    {
            TypeSpecifier *identifier_type
                = dkc_create_identifier_type_specifier((yyvsp[(1) - (3)].identifier));
            (yyval.type_specifier) = dkc_create_array_type_specifier(identifier_type);
        }
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 232 "diksam.y"
    {
            (yyval.type_specifier) = dkc_create_array_type_specifier((yyvsp[(1) - (3)].type_specifier));
        }
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 236 "diksam.y"
    {
			(yyval.type_specifier) = dkc_create_array_type_specifier((yyvsp[(1) - (3)].type_specifier));
		}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 242 "diksam.y"
    {//fix-me : shift/reduce
			(yyval.type_specifier)= dkc_create_template_type_specifier((yyvsp[(1) - (4)].identifier),(yyvsp[(3) - (4)].template));
		}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 248 "diksam.y"
    {
                    (yyval.type_specifier) = dkc_create_type_specifier((yyvsp[(1) - (1)].basic_type_specifier));
        }
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 258 "diksam.y"
    {
			(yyval.template)=dkc_create_template_list((yyvsp[(1) - (1)].type_specifier));
		}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 262 "diksam.y"
    {
            (yyval.template) = dkc_chain_template_list((yyvsp[(1) - (3)].template), (yyvsp[(3) - (3)].type_specifier));
        }
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 269 "diksam.y"
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
#line 279 "diksam.y"
    {
			BcGetCurrentCompilerContext()->isLib=0;
		}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 291 "diksam.y"
    {
            dkc_function_define((yyvsp[(9) - (11)].type_specifier), (yyvsp[(3) - (11)].identifier), (yyvsp[(5) - (11)].parameter_list), (yyvsp[(10) - (11)].exception_list), NULL,(yyvsp[(6) - (11)].intval));
        }
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 295 "diksam.y"
    {
            dkc_function_define((yyvsp[(8) - (10)].type_specifier), (yyvsp[(3) - (10)].identifier), NULL, (yyvsp[(9) - (10)].exception_list), NULL,(yyvsp[(5) - (10)].intval));
        }
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 299 "diksam.y"
    {
            dkc_function_define(0, (yyvsp[(3) - (9)].identifier), (yyvsp[(5) - (9)].parameter_list), (yyvsp[(8) - (9)].exception_list), NULL,(yyvsp[(6) - (9)].intval));
        }
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 303 "diksam.y"
    {
			//printf("lib:%s\n",BcGetCurrentCompilerContext()->libname);
            dkc_function_define(0, (yyvsp[(3) - (8)].identifier), NULL, (yyvsp[(7) - (8)].exception_list), NULL,(yyvsp[(5) - (8)].intval));
        }
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 310 "diksam.y"
    {
            dkc_function_define((yyvsp[(8) - (10)].type_specifier), (yyvsp[(2) - (10)].identifier), (yyvsp[(4) - (10)].parameter_list), (yyvsp[(9) - (10)].exception_list), (yyvsp[(10) - (10)].block),(yyvsp[(5) - (10)].intval));
        }
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 314 "diksam.y"
    {
            dkc_function_define((yyvsp[(7) - (9)].type_specifier), (yyvsp[(2) - (9)].identifier), NULL, (yyvsp[(8) - (9)].exception_list), (yyvsp[(9) - (9)].block),(yyvsp[(4) - (9)].intval));
        }
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 318 "diksam.y"
    { //modified
            dkc_function_define(0, (yyvsp[(2) - (8)].identifier), (yyvsp[(4) - (8)].parameter_list), (yyvsp[(7) - (8)].exception_list), (yyvsp[(8) - (8)].block),(yyvsp[(5) - (8)].intval));
        }
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 322 "diksam.y"
    {
            dkc_function_define(0, (yyvsp[(2) - (7)].identifier), NULL, (yyvsp[(6) - (7)].exception_list), (yyvsp[(7) - (7)].block),(yyvsp[(4) - (7)].intval));
        }
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 329 "diksam.y"
    {
            (yyval.parameter_list) = dkc_create_parameter((yyvsp[(3) - (3)].type_specifier), (yyvsp[(1) - (3)].identifier));
        }
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 333 "diksam.y"
    {
            (yyval.parameter_list) = dkc_chain_parameter((yyvsp[(1) - (5)].parameter_list), (yyvsp[(5) - (5)].type_specifier), (yyvsp[(3) - (5)].identifier));
        }
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 339 "diksam.y"
    {
            (yyval.argument_list) = dkc_create_argument_list((yyvsp[(1) - (1)].expression));
        }
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 343 "diksam.y"
    {
            (yyval.argument_list) = dkc_chain_argument_list((yyvsp[(1) - (3)].argument_list), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 349 "diksam.y"
    {
            (yyval.statement_list) = dkc_create_statement_list((yyvsp[(1) - (1)].statement));
        }
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 353 "diksam.y"
    {
            (yyval.statement_list) = dkc_chain_statement_list((yyvsp[(1) - (2)].statement_list), (yyvsp[(2) - (2)].statement));
        }
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 360 "diksam.y"
    {
            (yyval.expression) = dkc_create_comma_expression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 367 "diksam.y"
    {
            (yyval.expression) = dkc_create_assign_expression((yyvsp[(1) - (3)].expression), (yyvsp[(2) - (3)].assignment_operator), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 373 "diksam.y"
    {
            (yyval.assignment_operator) = NORMAL_ASSIGN;
        }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 377 "diksam.y"
    {
            (yyval.assignment_operator) = ADD_ASSIGN;
        }
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 381 "diksam.y"
    {
            (yyval.assignment_operator) = SUB_ASSIGN;
        }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 385 "diksam.y"
    {
            (yyval.assignment_operator) = MUL_ASSIGN;
        }
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 389 "diksam.y"
    {
            (yyval.assignment_operator) = DIV_ASSIGN;
        }
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 393 "diksam.y"
    {
            (yyval.assignment_operator) = MOD_ASSIGN;
        }
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 400 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(LOGICAL_OR_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 407 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(LOGICAL_AND_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 414 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(EQ_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 418 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(NE_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 425 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(GT_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 429 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(GE_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 433 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(LT_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 437 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(LE_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 444 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(ADD_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 448 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(SUB_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 455 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(MUL_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 459 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(DIV_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 463 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(MOD_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 467 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(BIT_AND_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 471 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(BIT_OR_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 475 "diksam.y"
    {
            (yyval.expression) = dkc_create_binary_expression(BIT_XOR_EXPRESSION, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 482 "diksam.y"
    {
            (yyval.expression) = dkc_create_minus_expression((yyvsp[(2) - (2)].expression));
        }
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 486 "diksam.y"
    {
            (yyval.expression) = dkc_create_logical_not_expression((yyvsp[(2) - (2)].expression));
        }
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 490 "diksam.y"
    {
            (yyval.expression) = dkc_create_bit_not_expression((yyvsp[(2) - (2)].expression));
        }
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 497 "diksam.y"
    {
            (yyval.expression) = dkc_create_incdec_expression((yyvsp[(1) - (2)].expression), INCREMENT_EXPRESSION);
        }
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 501 "diksam.y"
    {
            (yyval.expression) = dkc_create_incdec_expression((yyvsp[(1) - (2)].expression), DECREMENT_EXPRESSION);
        }
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 505 "diksam.y"
    {
            (yyval.expression) = dkc_create_instanceof_expression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].type_specifier));
        }
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 513 "diksam.y"
    {
            (yyval.expression) = dkc_create_identifier_expression((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 517 "diksam.y"
    {
			(yyval.expression)=BcCreateAutoExpression((yyvsp[(1) - (1)].identifier));
		}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 523 "diksam.y"
    {
            (yyval.expression) = dkc_create_index_expression((yyvsp[(1) - (4)].expression), (yyvsp[(3) - (4)].expression));
        }
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 527 "diksam.y"
    {
            Expression *identifier = dkc_create_identifier_expression((yyvsp[(1) - (4)].identifier));
            (yyval.expression) = dkc_create_index_expression(identifier, (yyvsp[(3) - (4)].expression));
        }
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 532 "diksam.y"
    {
            (yyval.expression) = dkc_create_member_expression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].identifier));
        }
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 536 "diksam.y"
    {
            (yyval.expression) = dkc_create_function_call_expression((yyvsp[(1) - (4)].expression), (yyvsp[(3) - (4)].argument_list));
        }
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 540 "diksam.y"
    {
            (yyval.expression) = dkc_create_function_call_expression((yyvsp[(1) - (3)].expression), NULL);
        }
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 544 "diksam.y"
    {
            (yyval.expression) = (yyvsp[(2) - (3)].expression);
        }
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 548 "diksam.y"
    {
            (yyval.expression) = dkc_create_down_cast_expression((yyvsp[(1) - (4)].expression), (yyvsp[(3) - (4)].type_specifier));
        }
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 556 "diksam.y"
    {
            (yyval.expression) = dkc_create_boolean_expression(DVM_TRUE);
        }
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 560 "diksam.y"
    {
            (yyval.expression) = dkc_create_boolean_expression(DVM_FALSE);
        }
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 564 "diksam.y"
    {
            (yyval.expression) = dkc_create_null_expression();
        }
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 569 "diksam.y"
    {
            (yyval.expression) = dkc_create_this_expression();
        }
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 573 "diksam.y"
    {
            (yyval.expression) = dkc_create_super_expression();
        }
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 577 "diksam.y"
    {
			(yyval.expression) = dkc_create_new_delegate_expression();
		}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 581 "diksam.y"
    {
            (yyval.expression) = dkc_create_new_expression((yyvsp[(2) - (4)].identifier), NULL, NULL);
        }
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 585 "diksam.y"
    {
            (yyval.expression) = dkc_create_new_expression((yyvsp[(2) - (5)].identifier), NULL, (yyvsp[(4) - (5)].argument_list));
        }
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 589 "diksam.y"
    {
            (yyval.expression) = dkc_create_new_expression((yyvsp[(2) - (6)].identifier), (yyvsp[(4) - (6)].identifier), NULL);
        }
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 593 "diksam.y"
    {
            (yyval.expression) = dkc_create_new_expression((yyvsp[(2) - (7)].identifier), (yyvsp[(4) - (7)].identifier), (yyvsp[(6) - (7)].argument_list));
        }
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 599 "diksam.y"
    {
            (yyval.expression) = dkc_create_array_literal_expression((yyvsp[(2) - (3)].expression_list));
        }
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 603 "diksam.y"
    {
            (yyval.expression) = dkc_create_array_literal_expression((yyvsp[(2) - (4)].expression_list));
        }
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 609 "diksam.y"
    {
            (yyval.expression) = dkc_create_basic_array_creation((yyvsp[(2) - (3)].basic_type_specifier), (yyvsp[(3) - (3)].array_dimension), NULL);
        }
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 613 "diksam.y"
    {
            (yyval.expression) = dkc_create_basic_array_creation((yyvsp[(2) - (4)].basic_type_specifier), (yyvsp[(3) - (4)].array_dimension), (yyvsp[(4) - (4)].array_dimension));
        }
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 617 "diksam.y"
    {
            (yyval.expression) = dkc_create_class_array_creation((yyvsp[(2) - (3)].type_specifier), (yyvsp[(3) - (3)].array_dimension), NULL);
        }
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 622 "diksam.y"
    {
            (yyval.expression) = dkc_create_class_array_creation((yyvsp[(2) - (4)].type_specifier), (yyvsp[(3) - (4)].array_dimension), (yyvsp[(4) - (4)].array_dimension));
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
#line 630 "diksam.y"
    {
            (yyval.expression) = dkc_create_class_array_creation((yyvsp[(2) - (4)].type_specifier), (yyvsp[(3) - (4)].array_dimension), (yyvsp[(4) - (4)].array_dimension));
        }
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 637 "diksam.y"
    {
            (yyval.array_dimension) = dkc_chain_array_dimension((yyvsp[(1) - (2)].array_dimension), (yyvsp[(2) - (2)].array_dimension));
        }
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 643 "diksam.y"
    {
            (yyval.array_dimension) = dkc_create_array_dimension((yyvsp[(2) - (3)].expression));
        }
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 649 "diksam.y"
    {
            (yyval.array_dimension) = dkc_create_array_dimension(NULL);
        }
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 653 "diksam.y"
    {
            (yyval.array_dimension) = dkc_chain_array_dimension((yyvsp[(1) - (3)].array_dimension),
                                           dkc_create_array_dimension(NULL));
        }
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 660 "diksam.y"
    {
            (yyval.expression_list) = NULL;
        }
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 664 "diksam.y"
    {
            (yyval.expression_list) = dkc_create_expression_list((yyvsp[(1) - (1)].expression));
        }
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 668 "diksam.y"
    {
            (yyval.expression_list) = dkc_chain_expression_list((yyvsp[(1) - (3)].expression_list), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 674 "diksam.y"
    {
          (yyval.statement) = dkc_create_expression_statement((yyvsp[(1) - (2)].expression));
        }
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 690 "diksam.y"
    {/*empty line*/
			(yyval.statement)=0;
		}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 696 "diksam.y"
    {
            (yyval.statement) = dkc_create_if_statement((yyvsp[(2) - (4)].expression), (yyvsp[(4) - (4)].block), NULL, NULL);
        }
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 700 "diksam.y"
    {
			//printf("IF-ELSE %d\n",dkc_get_current_compiler()->current_line_number);
            (yyval.statement) = dkc_create_if_statement((yyvsp[(2) - (6)].expression), (yyvsp[(4) - (6)].block), NULL, (yyvsp[(6) - (6)].block));
        }
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 705 "diksam.y"
    {
            (yyval.statement) = dkc_create_if_statement((yyvsp[(2) - (5)].expression), (yyvsp[(4) - (5)].block), (yyvsp[(5) - (5)].elsif), NULL);
        }
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 709 "diksam.y"
    {
            (yyval.statement) = dkc_create_if_statement((yyvsp[(2) - (7)].expression), (yyvsp[(4) - (7)].block), (yyvsp[(5) - (7)].elsif), (yyvsp[(7) - (7)].block));
        }
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 716 "diksam.y"
    {
            (yyval.elsif) = dkc_chain_elsif_list((yyvsp[(1) - (2)].elsif), (yyvsp[(2) - (2)].elsif));
        }
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 722 "diksam.y"
    {
            (yyval.elsif) = dkc_create_elsif((yyvsp[(2) - (4)].expression), (yyvsp[(4) - (4)].block));
        }
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 728 "diksam.y"
    {
            (yyval.identifier) = NULL;
        }
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 732 "diksam.y"
    {
            (yyval.identifier) = (yyvsp[(1) - (2)].identifier);
        }
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 738 "diksam.y"
    {
            (yyval.statement) = dkc_create_switch_statement((yyvsp[(2) - (5)].expression), (yyvsp[(4) - (5)].case_list), (yyvsp[(5) - (5)].block));
        }
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 745 "diksam.y"
    {
            (yyval.case_list) = dkc_chain_case((yyvsp[(1) - (2)].case_list), (yyvsp[(2) - (2)].case_list));
        }
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 751 "diksam.y"
    {
            (yyval.case_list) = dkc_create_one_case((yyvsp[(2) - (3)].expression_list), (yyvsp[(3) - (3)].block));
        }
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 757 "diksam.y"
    {
            (yyval.block) = NULL;
        }
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 761 "diksam.y"
    {
            (yyval.block) = (yyvsp[(2) - (2)].block);
        }
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 767 "diksam.y"
    {
            (yyval.expression_list) = dkc_create_expression_list((yyvsp[(1) - (1)].expression));
        }
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 771 "diksam.y"
    {
            (yyval.expression_list) = dkc_chain_expression_list((yyvsp[(1) - (3)].expression_list), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 777 "diksam.y"
    {
            (yyval.statement) = dkc_create_while_statement((yyvsp[(1) - (4)].identifier), (yyvsp[(3) - (4)].expression), (yyvsp[(4) - (4)].block));
        }
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 783 "diksam.y"
    {
            (yyval.statement) = dkc_create_for_statement((yyvsp[(1) - (8)].identifier), (yyvsp[(3) - (8)].expression), (yyvsp[(5) - (8)].expression), (yyvsp[(7) - (8)].expression), (yyvsp[(8) - (8)].block));
        }
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 789 "diksam.y"
    {
            (yyval.statement) = dkc_create_do_while_statement((yyvsp[(1) - (8)].identifier), (yyvsp[(3) - (8)].block), (yyvsp[(6) - (8)].expression));
        }
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 795 "diksam.y"
    {
            (yyval.statement) = dkc_create_foreach_statement((yyvsp[(1) - (8)].identifier), (yyvsp[(4) - (8)].identifier), (yyvsp[(6) - (8)].expression), (yyvsp[(8) - (8)].block));
        }
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 801 "diksam.y"
    {
            (yyval.expression) = NULL;
        }
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 808 "diksam.y"
    {
            (yyval.statement) = dkc_create_return_statement((yyvsp[(2) - (3)].expression));
        }
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 814 "diksam.y"
    {
            (yyval.identifier) = NULL;
        }
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 821 "diksam.y"
    {
            (yyval.statement) = dkc_create_break_statement((yyvsp[(2) - (3)].identifier));
        }
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 827 "diksam.y"
    {
            (yyval.statement) = dkc_create_continue_statement((yyvsp[(2) - (3)].identifier));
        }
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 833 "diksam.y"
    {
            (yyval.statement) = dkc_create_try_statement((yyvsp[(2) - (5)].block), (yyvsp[(3) - (5)].catch_clause), (yyvsp[(5) - (5)].block));
        }
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 837 "diksam.y"
    {
            (yyval.statement) = dkc_create_try_statement((yyvsp[(2) - (4)].block), NULL, (yyvsp[(4) - (4)].block));
        }
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 841 "diksam.y"
    {
            (yyval.statement) = dkc_create_try_statement((yyvsp[(2) - (3)].block), (yyvsp[(3) - (3)].catch_clause), NULL);
        }
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 848 "diksam.y"
    {
            (yyval.catch_clause) = dkc_chain_catch_list((yyvsp[(1) - (2)].catch_clause), (yyvsp[(2) - (2)].catch_clause));
        }
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 854 "diksam.y"
    {
            (yyval.catch_clause) = dkc_start_catch_clause();
        }
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 858 "diksam.y"
    {
            (yyval.catch_clause) = dkc_end_catch_clause((yyvsp[(2) - (5)].catch_clause), (yyvsp[(3) - (5)].type_specifier), (yyvsp[(4) - (5)].identifier), (yyvsp[(5) - (5)].block));
        }
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 864 "diksam.y"
    {
            (yyval.statement) = dkc_create_throw_statement((yyvsp[(2) - (3)].expression));
        }
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 868 "diksam.y"
    {
            (yyval.statement) = dkc_create_throw_statement(NULL);
        }
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 874 "diksam.y"
    {
            (yyval.statement) = dkc_create_declaration_statement(DVM_FALSE, (yyvsp[(5) - (6)].type_specifier), (yyvsp[(2) - (6)].identifier), NULL,(yyvsp[(4) - (6)].intval));
        }
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 878 "diksam.y"
    {
            (yyval.statement) = dkc_create_declaration_statement(DVM_FALSE, (yyvsp[(5) - (8)].type_specifier), (yyvsp[(2) - (8)].identifier), (yyvsp[(7) - (8)].expression),(yyvsp[(4) - (8)].intval));
        }
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 882 "diksam.y"
    {
            (yyval.statement) = dkc_create_declaration_statement(DVM_FALSE, (yyvsp[(4) - (5)].type_specifier), (yyvsp[(2) - (5)].identifier), NULL,DVM_FALSE);
        }
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 886 "diksam.y"
    {
            (yyval.statement) = dkc_create_declaration_statement(DVM_TRUE, (yyvsp[(4) - (7)].type_specifier), (yyvsp[(2) - (7)].identifier), (yyvsp[(6) - (7)].expression),DVM_FALSE);
        }
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 892 "diksam.y"
    {
            (yyval.block) = dkc_open_block(0);
        }
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 896 "diksam.y"
    {
            (yyval.block) = dkc_close_block((yyvsp[(2) - (4)].block), (yyvsp[(3) - (4)].statement_list));
        }
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 900 "diksam.y"
    {
            Block *empty_block = dkc_open_block(0);
            (yyval.block) = dkc_close_block(empty_block, NULL);
        }
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 907 "diksam.y"
    {
            (yyval.template_def) = dkc_create_template_declare_list((yyvsp[(1) - (1)].identifier),NULL);
        }
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 911 "diksam.y"
    {
            (yyval.template_def) = dkc_chain_template_declare_list((yyvsp[(1) - (3)].template_def), (yyvsp[(3) - (3)].identifier),NULL);
        }
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 915 "diksam.y"
    {
            (yyval.template_def) = dkc_create_template_declare_list((yyvsp[(1) - (3)].identifier),(yyvsp[(3) - (3)].type_specifier));
        }
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 919 "diksam.y"
    {
            (yyval.template_def) = dkc_chain_template_declare_list((yyvsp[(1) - (5)].template_def), (yyvsp[(3) - (5)].identifier) ,(yyvsp[(5) - (5)].type_specifier));
        }
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 925 "diksam.y"
    {
			(yyval.template_def)=(yyvsp[(2) - (3)].template_def);
		}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 929 "diksam.y"
    {(yyval.template_def)=NULL;}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 934 "diksam.y"
    {
            dkc_start_class_definition((yyvsp[(1) - (6)].intval),NULL, (yyvsp[(2) - (6)].class_or_interface), (yyvsp[(3) - (6)].identifier),(yyvsp[(4) - (6)].template_def), (yyvsp[(5) - (6)].extends_list));
        }
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 938 "diksam.y"
    {
            dkc_class_define((yyvsp[(8) - (9)].member_declaration));
        }
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 943 "diksam.y"
    {
            dkc_start_class_definition((yyvsp[(1) - (7)].intval),&(yyvsp[(2) - (7)].class_or_member_modifier), (yyvsp[(3) - (7)].class_or_interface), (yyvsp[(4) - (7)].identifier),(yyvsp[(5) - (7)].template_def), (yyvsp[(6) - (7)].extends_list));
        }
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 946 "diksam.y"
    {
            dkc_class_define((yyvsp[(9) - (10)].member_declaration));
        }
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 950 "diksam.y"
    {
            dkc_start_class_definition((yyvsp[(1) - (6)].intval),NULL, (yyvsp[(2) - (6)].class_or_interface), (yyvsp[(3) - (6)].identifier),(yyvsp[(4) - (6)].template_def), (yyvsp[(5) - (6)].extends_list));
        }
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 954 "diksam.y"
    {
            dkc_class_define(NULL);
        }
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 959 "diksam.y"
    {
            dkc_start_class_definition((yyvsp[(1) - (7)].intval),&(yyvsp[(2) - (7)].class_or_member_modifier), (yyvsp[(3) - (7)].class_or_interface), (yyvsp[(4) - (7)].identifier),(yyvsp[(5) - (7)].template_def), (yyvsp[(6) - (7)].extends_list));
        }
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 963 "diksam.y"
    {
            dkc_class_define(NULL);
        }
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 970 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_chain_class_or_member_modifier((yyvsp[(1) - (2)].class_or_member_modifier), (yyvsp[(2) - (2)].class_or_member_modifier));
        }
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 977 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(VIRTUAL_MODIFIER);
        }
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 981 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(OVERRIDE_MODIFIER);
        }
    break;

  case 222:

/* Line 1455 of yacc.c  */
#line 985 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(ABSTRACT_MODIFIER);
        }
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 991 "diksam.y"
    {
            (yyval.class_or_interface) = DVM_CLASS_DEFINITION;
        }
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 995 "diksam.y"
    {
            (yyval.class_or_interface) = DVM_INTERFACE_DEFINITION;
        }
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 1001 "diksam.y"
    {
            (yyval.extends_list) = NULL;
        }
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 1005 "diksam.y"
    {
            (yyval.extends_list) = (yyvsp[(2) - (2)].extends_list);
        }
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 1011 "diksam.y"
    {
            (yyval.extends_list) = dkc_create_extends_list((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 1015 "diksam.y"
    {
            (yyval.extends_list) = dkc_chain_extends_list((yyvsp[(1) - (3)].extends_list), (yyvsp[(3) - (3)].identifier));
        }
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 1022 "diksam.y"
    {
            (yyval.member_declaration) = dkc_chain_member_declaration((yyvsp[(1) - (2)].member_declaration), (yyvsp[(2) - (2)].member_declaration));
        }
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 1032 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_method_member(NULL, (yyvsp[(1) - (1)].function_definition), DVM_FALSE);
        }
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 1036 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_method_member(&(yyvsp[(1) - (2)].class_or_member_modifier), (yyvsp[(2) - (2)].function_definition), DVM_FALSE);
        }
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 1040 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_method_member(NULL, (yyvsp[(1) - (1)].function_definition), DVM_TRUE);
        }
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 1044 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_method_member(&(yyvsp[(1) - (2)].class_or_member_modifier), (yyvsp[(2) - (2)].function_definition), DVM_TRUE);
        }
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 1050 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define((yyvsp[(7) - (9)].type_specifier), (yyvsp[(2) - (9)].identifier), (yyvsp[(4) - (9)].parameter_list), (yyvsp[(8) - (9)].exception_list), (yyvsp[(9) - (9)].block));
        }
    break;

  case 238:

/* Line 1455 of yacc.c  */
#line 1054 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define((yyvsp[(6) - (8)].type_specifier), (yyvsp[(2) - (8)].identifier), NULL, (yyvsp[(7) - (8)].exception_list), (yyvsp[(8) - (8)].block));
        }
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 1058 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define((yyvsp[(8) - (10)].type_specifier), (yyvsp[(3) - (10)].identifier), (yyvsp[(5) - (10)].parameter_list), (yyvsp[(9) - (10)].exception_list), NULL);
        }
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 1062 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define((yyvsp[(7) - (9)].type_specifier), (yyvsp[(3) - (9)].identifier), NULL, (yyvsp[(8) - (9)].exception_list), NULL);
        }
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 1066 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define(0, (yyvsp[(2) - (7)].identifier), (yyvsp[(4) - (7)].parameter_list), (yyvsp[(6) - (7)].exception_list), (yyvsp[(7) - (7)].block));
        }
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 1070 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define(0, (yyvsp[(2) - (6)].identifier), NULL, (yyvsp[(5) - (6)].exception_list), (yyvsp[(6) - (6)].block));
        }
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 1074 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define(0, (yyvsp[(3) - (8)].identifier), (yyvsp[(5) - (8)].parameter_list), (yyvsp[(7) - (8)].exception_list), NULL);
        }
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 1078 "diksam.y"
    {
            (yyval.function_definition) = dkc_method_function_define(0, (yyvsp[(3) - (7)].identifier), NULL, (yyvsp[(6) - (7)].exception_list), NULL);
        }
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 1084 "diksam.y"
    {
			(yyval.intval)=0;
		}
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 1088 "diksam.y"
    {
			(yyval.intval)=1;
		}
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 1094 "diksam.y"
    {
            (yyval.exception_list) = NULL;
        }
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 1098 "diksam.y"
    {
            (yyval.exception_list) = (yyvsp[(2) - (2)].exception_list);
        }
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 1104 "diksam.y"
    {
            (yyval.exception_list) = dkc_create_throws((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 1108 "diksam.y"
    {
            (yyval.exception_list) = dkc_chain_exception_list((yyvsp[(1) - (3)].exception_list), (yyvsp[(3) - (3)].identifier));
        }
    break;

  case 251:

/* Line 1455 of yacc.c  */
#line 1114 "diksam.y"
    {
            (yyval.function_definition) = dkc_constructor_function_define((yyvsp[(2) - (7)].identifier), (yyvsp[(4) - (7)].parameter_list), (yyvsp[(6) - (7)].exception_list), (yyvsp[(7) - (7)].block));
        }
    break;

  case 252:

/* Line 1455 of yacc.c  */
#line 1118 "diksam.y"
    {
            (yyval.function_definition) = dkc_constructor_function_define((yyvsp[(2) - (6)].identifier), NULL, (yyvsp[(5) - (6)].exception_list), (yyvsp[(6) - (6)].block));
        }
    break;

  case 253:

/* Line 1455 of yacc.c  */
#line 1122 "diksam.y"
    {
            (yyval.function_definition) = dkc_constructor_function_define((yyvsp[(3) - (8)].identifier), (yyvsp[(5) - (8)].parameter_list), (yyvsp[(7) - (8)].exception_list), NULL);
        }
    break;

  case 254:

/* Line 1455 of yacc.c  */
#line 1126 "diksam.y"
    {
            (yyval.function_definition) = dkc_constructor_function_define((yyvsp[(3) - (7)].identifier), NULL, (yyvsp[(6) - (7)].exception_list), NULL);
        }
    break;

  case 255:

/* Line 1455 of yacc.c  */
#line 1132 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(PUBLIC_MODIFIER);
        }
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 1136 "diksam.y"
    {
            (yyval.class_or_member_modifier) = dkc_create_class_or_member_modifier(PRIVATE_MODIFIER);
        }
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 1142 "diksam.y"
    {
            (yyval.expression) = NULL;
        }
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 1146 "diksam.y"
    {
            (yyval.expression) = (yyvsp[(2) - (2)].expression);
        }
    break;

  case 259:

/* Line 1455 of yacc.c  */
#line 1152 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(NULL, DVM_FALSE, (yyvsp[(4) - (6)].type_specifier), (yyvsp[(2) - (6)].identifier), (yyvsp[(5) - (6)].expression));
        }
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 1157 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(&(yyvsp[(1) - (6)].class_or_member_modifier), DVM_FALSE, (yyvsp[(4) - (6)].type_specifier), (yyvsp[(2) - (6)].identifier), (yyvsp[(5) - (6)].expression));
        }
    break;

  case 261:

/* Line 1455 of yacc.c  */
#line 1161 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(NULL, DVM_TRUE, (yyvsp[(4) - (6)].type_specifier), (yyvsp[(2) - (6)].identifier), (yyvsp[(5) - (6)].expression));
        }
    break;

  case 262:

/* Line 1455 of yacc.c  */
#line 1166 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(&(yyvsp[(1) - (7)].class_or_member_modifier), DVM_TRUE, (yyvsp[(5) - (7)].type_specifier), (yyvsp[(3) - (7)].identifier), (yyvsp[(6) - (7)].expression));
        }
    break;

  case 263:

/* Line 1455 of yacc.c  */
#line 1170 "diksam.y"
    {
            (yyval.member_declaration) = dkc_create_field_member(&(yyvsp[(2) - (7)].class_or_member_modifier), DVM_TRUE, (yyvsp[(5) - (7)].type_specifier), (yyvsp[(3) - (7)].identifier), (yyvsp[(6) - (7)].expression));
        }
    break;

  case 264:

/* Line 1455 of yacc.c  */
#line 1176 "diksam.y"
    {
            dkc_create_delegate_definition((yyvsp[(8) - (10)].type_specifier), (yyvsp[(2) - (10)].identifier), (yyvsp[(4) - (10)].parameter_list), (yyvsp[(9) - (10)].exception_list),(yyvsp[(5) - (10)].intval));
        }
    break;

  case 265:

/* Line 1455 of yacc.c  */
#line 1180 "diksam.y"
    {
            dkc_create_delegate_definition((yyvsp[(7) - (9)].type_specifier), (yyvsp[(2) - (9)].identifier), NULL, (yyvsp[(8) - (9)].exception_list),(yyvsp[(4) - (9)].intval));
        }
    break;

  case 266:

/* Line 1455 of yacc.c  */
#line 1186 "diksam.y"
    {
            dkc_create_enum_definition((yyvsp[(2) - (5)].identifier), (yyvsp[(4) - (5)].enumerator));
        }
    break;

  case 267:

/* Line 1455 of yacc.c  */
#line 1190 "diksam.y"
    {
            dkc_create_enum_definition((yyvsp[(2) - (6)].identifier), (yyvsp[(4) - (6)].enumerator));
        }
    break;

  case 268:

/* Line 1455 of yacc.c  */
#line 1196 "diksam.y"
    {
            (yyval.enumerator) = dkc_create_enumerator((yyvsp[(1) - (1)].identifier));
        }
    break;

  case 269:

/* Line 1455 of yacc.c  */
#line 1200 "diksam.y"
    {
            (yyval.enumerator) = dkc_chain_enumerator((yyvsp[(1) - (3)].enumerator), (yyvsp[(3) - (3)].identifier));
        }
    break;

  case 270:

/* Line 1455 of yacc.c  */
#line 1206 "diksam.y"
    {
            dkc_create_const_definition(NULL, (yyvsp[(2) - (5)].identifier), (yyvsp[(4) - (5)].expression));
        }
    break;

  case 271:

/* Line 1455 of yacc.c  */
#line 1210 "diksam.y"
    {
            dkc_create_const_definition((yyvsp[(2) - (4)].type_specifier), (yyvsp[(3) - (4)].identifier), NULL);
        }
    break;

  case 272:

/* Line 1455 of yacc.c  */
#line 1216 "diksam.y"
    {
			(yyval.intval)=0;
		}
    break;

  case 273:

/* Line 1455 of yacc.c  */
#line 1220 "diksam.y"
    {
			(yyval.intval)=1;
		}
    break;

  case 274:

/* Line 1455 of yacc.c  */
#line 1226 "diksam.y"
    {
			(yyval.intval)=0;
		}
    break;

  case 275:

/* Line 1455 of yacc.c  */
#line 1230 "diksam.y"
    {
			(yyval.intval)=1;
		}
    break;

  case 276:

/* Line 1455 of yacc.c  */
#line 1234 "diksam.y"
    {
			(yyval.intval)=-1;
		}
    break;

  case 277:

/* Line 1455 of yacc.c  */
#line 1240 "diksam.y"
    {
            (yyval.block) = dkc_open_block((yyvsp[(2) - (2)].intval));
			//printf("E1 %d\n",dkc_get_current_compiler());
        }
    break;

  case 278:

/* Line 1455 of yacc.c  */
#line 1245 "diksam.y"
    {
            (yyval.block) = dkc_close_block((yyvsp[(3) - (5)].block), (yyvsp[(4) - (5)].statement_list));
			//printf("C1 %d\n",dkc_get_current_compiler()->current_line_number);
        }
    break;

  case 279:

/* Line 1455 of yacc.c  */
#line 1250 "diksam.y"
    {
            Block *empty_block = dkc_open_block(0);
            (yyval.block) = dkc_close_block(empty_block, NULL);
			//printf("C2 %d\n",dkc_get_current_compiler()->current_line_number);
        }
    break;



/* Line 1455 of yacc.c  */
#line 4249 "y.tab.c"
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
#line 1256 "diksam.y"


