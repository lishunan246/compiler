/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TOKEN_PROGRAM = 258,
     TOKEN_FUNCTION = 259,
     TOKEN_PROCEDURE = 260,
     TOKEN_CONST = 261,
     TOKEN_TYPE = 262,
     TOKEN_VAR = 263,
     TOKEN_IF = 264,
     TOKEN_THEN = 265,
     TOKEN_ELSE = 266,
     TOKEN_REPEAT = 267,
     TOKEN_UNTIL = 268,
     TOKEN_WHILE = 269,
     TOKEN_DO = 270,
     TOKEN_CASE = 271,
     TOKEN_TO = 272,
     TOKEN_DOWNTO = 273,
     TOKEN_FOR = 274,
     TOKEN_EQUAL = 275,
     TOKEN_UNEQUAL = 276,
     TOKEN_GE = 277,
     TOKEN_GT = 278,
     TOKEN_LE = 279,
     TOKEN_LT = 280,
     TOKEN_ASSIGN = 281,
     TOKEN_PLUS = 282,
     TOKEN_MINUS = 283,
     TOKEN_MUL = 284,
     TOKEN_DIV = 285,
     TOKEN_OR = 286,
     TOKEN_AND = 287,
     TOKEN_NOT = 288,
     TOKEN_MOD = 289,
     TOKEN_READ = 290,
     TOKEN_WRITE = 291,
     TOKEN_WRITELN = 292,
     TOKEN_LB = 293,
     TOKEN_RB = 294,
     TOKEN_SEMI = 295,
     TOKEN_DOT = 296,
     TOKEN_DOTDOT = 297,
     TOKEN_LP = 298,
     TOKEN_RP = 299,
     TOKEN_COMMA = 300,
     TOKEN_COLON = 301,
     TOKEN_INTEGER_TYPE = 302,
     TOKEN_BOOLEAN_TYPE = 303,
     TOKEN_CHAR_TYPE = 304,
     TOKEN_REAL_TYPE = 305,
     TOKEN_TRUE = 306,
     TOKEN_FALSE = 307,
     TOKEN_MAXINT = 308,
     TOKEN_ARRAY = 309,
     TOKEN_OF = 310,
     TOKEN_RECORD = 311,
     TOKEN_BEGIN = 312,
     TOKEN_END = 313,
     TOKEN_GOTO = 314,
     TOKEN_ID = 315,
     TOKEN_INT = 316,
     TOKEN_REAL = 317,
     TOKEN_CHAR = 318,
     TOKEN_STRING = 319,
     ERROR = 320,
     TOKEN_ABS = 321,
     TOKEN_CHR = 322,
     TOKEN_ODD = 323,
     TOKEN_ORD = 324,
     TOKEN_PRED = 325,
     TOKEN_SQR = 326,
     TOKEN_SQRT = 327,
     TOKEN_SUCC = 328,
     TOKEN_READLN = 329
   };
#endif
/* Tokens.  */
#define TOKEN_PROGRAM 258
#define TOKEN_FUNCTION 259
#define TOKEN_PROCEDURE 260
#define TOKEN_CONST 261
#define TOKEN_TYPE 262
#define TOKEN_VAR 263
#define TOKEN_IF 264
#define TOKEN_THEN 265
#define TOKEN_ELSE 266
#define TOKEN_REPEAT 267
#define TOKEN_UNTIL 268
#define TOKEN_WHILE 269
#define TOKEN_DO 270
#define TOKEN_CASE 271
#define TOKEN_TO 272
#define TOKEN_DOWNTO 273
#define TOKEN_FOR 274
#define TOKEN_EQUAL 275
#define TOKEN_UNEQUAL 276
#define TOKEN_GE 277
#define TOKEN_GT 278
#define TOKEN_LE 279
#define TOKEN_LT 280
#define TOKEN_ASSIGN 281
#define TOKEN_PLUS 282
#define TOKEN_MINUS 283
#define TOKEN_MUL 284
#define TOKEN_DIV 285
#define TOKEN_OR 286
#define TOKEN_AND 287
#define TOKEN_NOT 288
#define TOKEN_MOD 289
#define TOKEN_READ 290
#define TOKEN_WRITE 291
#define TOKEN_WRITELN 292
#define TOKEN_LB 293
#define TOKEN_RB 294
#define TOKEN_SEMI 295
#define TOKEN_DOT 296
#define TOKEN_DOTDOT 297
#define TOKEN_LP 298
#define TOKEN_RP 299
#define TOKEN_COMMA 300
#define TOKEN_COLON 301
#define TOKEN_INTEGER_TYPE 302
#define TOKEN_BOOLEAN_TYPE 303
#define TOKEN_CHAR_TYPE 304
#define TOKEN_REAL_TYPE 305
#define TOKEN_TRUE 306
#define TOKEN_FALSE 307
#define TOKEN_MAXINT 308
#define TOKEN_ARRAY 309
#define TOKEN_OF 310
#define TOKEN_RECORD 311
#define TOKEN_BEGIN 312
#define TOKEN_END 313
#define TOKEN_GOTO 314
#define TOKEN_ID 315
#define TOKEN_INT 316
#define TOKEN_REAL 317
#define TOKEN_CHAR 318
#define TOKEN_STRING 319
#define ERROR 320
#define TOKEN_ABS 321
#define TOKEN_CHR 322
#define TOKEN_ODD 323
#define TOKEN_ORD 324
#define TOKEN_PRED 325
#define TOKEN_SQR 326
#define TOKEN_SQRT 327
#define TOKEN_SUCC 328
#define TOKEN_READLN 329




/* Copy the first part of user declarations.  */
#line 1 "pas.y"

#define YYPARSER
#include "util.h"
#define YYSTYPE TreeNode *
static char * myName;
static TreeNode* myTree;
static int myNum;
static int level=0;
TokenType getToken();

int yyparse();
static int yylex(){
    return getToken();
}

int yyerror(char* message) {
    printf( "Syntax error at line %d: %s\n",lineno,message);
    return 0;
}



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

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 276 "y.tab.c"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
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
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   464

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  75
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  138
/* YYNRULES -- Number of states.  */
#define YYNSTATES  294

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   329

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
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,    11,    14,    19,    22,    23,    26,
      28,    33,    35,    37,    39,    41,    43,    45,    47,    50,
      51,    54,    56,    61,    63,    65,    67,    74,    78,    81,
      83,    88,    92,    94,    96,   100,   104,   109,   115,   119,
     121,   123,   125,   127,   128,   131,   134,   136,   141,   142,
     145,   148,   150,   152,   157,   158,   165,   170,   171,   176,
     177,   181,   185,   187,   192,   196,   198,   200,   204,   205,
     209,   210,   215,   217,   219,   221,   223,   225,   227,   229,
     231,   233,   235,   239,   246,   252,   255,   261,   262,   265,
     270,   271,   276,   282,   285,   287,   292,   297,   306,   315,
     317,   322,   327,   332,   334,   339,   343,   345,   349,   353,
     357,   361,   365,   369,   371,   375,   379,   383,   385,   389,
     393,   397,   401,   403,   405,   410,   412,   416,   419,   422,
     427,   431,   436,   441,   446,   451,   456,   461,   466
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      76,     0,    -1,    -1,     3,    60,    77,    40,    78,    41,
      -1,    79,   108,    -1,    80,    84,    94,    97,    -1,     6,
      81,    -1,    -1,    81,    82,    -1,    82,    -1,   107,    20,
      83,    40,    -1,    61,    -1,    62,    -1,    63,    -1,    64,
      -1,    51,    -1,    52,    -1,    53,    -1,     7,    85,    -1,
      -1,    85,    86,    -1,    86,    -1,   107,    20,    87,    40,
      -1,    93,    -1,    88,    -1,    89,    -1,    54,    38,    93,
      39,    55,    87,    -1,    56,    90,    58,    -1,    90,    91,
      -1,    91,    -1,    92,    46,    87,    40,    -1,    92,    45,
     107,    -1,   107,    -1,   107,    -1,    43,    92,    44,    -1,
      83,    42,    83,    -1,    28,    83,    42,    83,    -1,    28,
      83,    42,    28,    83,    -1,   107,    42,   107,    -1,    47,
      -1,    48,    -1,    50,    -1,    49,    -1,    -1,     8,    95,
      -1,    95,    96,    -1,    96,    -1,    92,    46,    87,    40,
      -1,    -1,    97,    98,    -1,    97,   101,    -1,    98,    -1,
     101,    -1,    99,    40,    78,    40,    -1,    -1,     4,    60,
     100,   104,    46,    93,    -1,   102,    40,    78,    40,    -1,
      -1,     5,    60,   103,   104,    -1,    -1,    43,   105,    44,
      -1,   105,    40,   106,    -1,   106,    -1,     8,    92,    46,
      93,    -1,    92,    46,    93,    -1,    60,    -1,   109,    -1,
      57,   110,    58,    -1,    -1,   110,   111,    40,    -1,    -1,
      61,   112,    46,   113,    -1,   113,    -1,   114,    -1,   109,
      -1,   115,    -1,   116,    -1,   118,    -1,   119,    -1,   120,
      -1,   123,    -1,   124,    -1,   107,    26,   126,    -1,   107,
      38,   126,    39,    26,   126,    -1,   107,    41,   107,    26,
     126,    -1,    59,    61,    -1,     9,   126,    10,   111,   117,
      -1,    -1,    11,   111,    -1,    12,   110,    13,   126,    -1,
      -1,    14,   126,    15,   111,    -1,    16,   126,    55,   121,
      58,    -1,   121,   122,    -1,   122,    -1,    83,    46,   111,
      40,    -1,   107,    46,   111,    40,    -1,    19,   107,    26,
     126,    17,   126,    15,   111,    -1,    19,   107,    26,   126,
      18,   126,    15,   111,    -1,   107,    -1,   107,    43,   125,
      44,    -1,    35,    43,   129,    44,    -1,    36,    43,   125,
      44,    -1,    37,    -1,    37,    43,   125,    44,    -1,   125,
      45,   126,    -1,   126,    -1,   126,    22,   127,    -1,   126,
      23,   127,    -1,   126,    24,   127,    -1,   126,    25,   127,
      -1,   126,    20,   127,    -1,   126,    21,   127,    -1,   127,
      -1,   127,    27,   128,    -1,   127,    28,   128,    -1,   127,
      31,   128,    -1,   128,    -1,   128,    29,   129,    -1,   128,
      30,   129,    -1,   128,    34,   129,    -1,   128,    32,   129,
      -1,   129,    -1,   107,    -1,   107,    43,   125,    44,    -1,
      83,    -1,    43,   126,    44,    -1,    33,   129,    -1,    28,
     129,    -1,   107,    38,   126,    39,    -1,   107,    41,   107,
      -1,    66,    43,   125,    44,    -1,    67,    43,   125,    44,
      -1,    68,    43,   125,    44,    -1,    69,    43,   125,    44,
      -1,    70,    43,   125,    44,    -1,    71,    43,   125,    44,
      -1,    72,    43,   125,    44,    -1,    73,    43,   125,    44,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    26,    26,    25,    41,    46,    54,    58,    62,    75,
      80,    90,    96,   102,   108,   116,   122,   128,   136,   140,
     144,   156,   161,   167,   170,   173,   177,   187,   192,   204,
     206,   213,   225,   227,   233,   238,   244,   252,   260,   267,
     271,   275,   279,   285,   288,   293,   304,   308,   315,   318,
     329,   340,   341,   343,   351,   350,   360,   368,   367,   376,
     379,   384,   395,   400,   406,   413,   417,   421,   426,   429,
     443,   442,   452,   457,   460,   463,   466,   469,   472,   475,
     478,   481,   485,   491,   499,   507,   512,   519,   522,   526,
     532,   533,   538,   543,   554,   558,   564,   570,   579,   588,
     592,   597,   603,   608,   612,   618,   629,   634,   637,   640,
     643,   646,   649,   652,   657,   660,   663,   666,   671,   674,
     677,   680,   683,   688,   692,   697,   700,   703,   707,   711,
     716,   721,   725,   729,   733,   737,   741,   745,   749
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOKEN_PROGRAM", "TOKEN_FUNCTION",
  "TOKEN_PROCEDURE", "TOKEN_CONST", "TOKEN_TYPE", "TOKEN_VAR", "TOKEN_IF",
  "TOKEN_THEN", "TOKEN_ELSE", "TOKEN_REPEAT", "TOKEN_UNTIL", "TOKEN_WHILE",
  "TOKEN_DO", "TOKEN_CASE", "TOKEN_TO", "TOKEN_DOWNTO", "TOKEN_FOR",
  "TOKEN_EQUAL", "TOKEN_UNEQUAL", "TOKEN_GE", "TOKEN_GT", "TOKEN_LE",
  "TOKEN_LT", "TOKEN_ASSIGN", "TOKEN_PLUS", "TOKEN_MINUS", "TOKEN_MUL",
  "TOKEN_DIV", "TOKEN_OR", "TOKEN_AND", "TOKEN_NOT", "TOKEN_MOD",
  "TOKEN_READ", "TOKEN_WRITE", "TOKEN_WRITELN", "TOKEN_LB", "TOKEN_RB",
  "TOKEN_SEMI", "TOKEN_DOT", "TOKEN_DOTDOT", "TOKEN_LP", "TOKEN_RP",
  "TOKEN_COMMA", "TOKEN_COLON", "TOKEN_INTEGER_TYPE", "TOKEN_BOOLEAN_TYPE",
  "TOKEN_CHAR_TYPE", "TOKEN_REAL_TYPE", "TOKEN_TRUE", "TOKEN_FALSE",
  "TOKEN_MAXINT", "TOKEN_ARRAY", "TOKEN_OF", "TOKEN_RECORD", "TOKEN_BEGIN",
  "TOKEN_END", "TOKEN_GOTO", "TOKEN_ID", "TOKEN_INT", "TOKEN_REAL",
  "TOKEN_CHAR", "TOKEN_STRING", "ERROR", "TOKEN_ABS", "TOKEN_CHR",
  "TOKEN_ODD", "TOKEN_ORD", "TOKEN_PRED", "TOKEN_SQR", "TOKEN_SQRT",
  "TOKEN_SUCC", "TOKEN_READLN", "$accept", "program", "@1", "routine",
  "routine_head", "const_part", "const_expr_list", "const_expr",
  "const_value", "type_part", "type_decl_list", "type_definition",
  "type_decl", "array_type_decl", "record_type_decl", "field_decl_list",
  "field_decl", "name_list", "simple_type_decl", "var_part",
  "var_decl_list", "var_decl", "routine_part", "function_decl",
  "function_head", "@2", "procedure_decl", "procedure_head", "@3",
  "parameters", "para_decl_list", "para_type_list", "ID", "routine_body",
  "compound_stmt", "stmt_list", "stmt", "@4", "no_label_stmt",
  "assign_stmt", "goto_stmt", "if_stmt", "else_clause", "repeat_stmt",
  "while_stmt", "case_stmt", "case_expr_list", "case_expr", "for_stmt",
  "proc_stmt", "args_list", "expression", "expr", "term", "factor", 0
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
     325,   326,   327,   328,   329
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    75,    77,    76,    78,    79,    80,    80,    81,    81,
      82,    83,    83,    83,    83,    83,    83,    83,    84,    84,
      85,    85,    86,    87,    87,    87,    88,    89,    90,    90,
      91,    92,    92,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    94,    94,    95,    95,    96,    97,    97,
      97,    97,    97,    98,   100,    99,   101,   103,   102,   104,
     104,   105,   105,   106,   106,   107,   108,   109,   110,   110,
     112,   111,   111,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   114,   114,   114,   115,   116,   117,   117,   118,
     118,   119,   120,   121,   121,   122,   122,   123,   123,   124,
     124,   124,   124,   124,   124,   125,   125,   126,   126,   126,
     126,   126,   126,   126,   127,   127,   127,   127,   128,   128,
     128,   128,   128,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     6,     2,     4,     2,     0,     2,     1,
       4,     1,     1,     1,     1,     1,     1,     1,     2,     0,
       2,     1,     4,     1,     1,     1,     6,     3,     2,     1,
       4,     3,     1,     1,     3,     3,     4,     5,     3,     1,
       1,     1,     1,     0,     2,     2,     1,     4,     0,     2,
       2,     1,     1,     4,     0,     6,     4,     0,     4,     0,
       3,     3,     1,     4,     3,     1,     1,     3,     0,     3,
       0,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     6,     5,     2,     5,     0,     2,     4,
       0,     4,     5,     2,     1,     4,     4,     8,     8,     1,
       4,     4,     4,     1,     4,     3,     1,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     3,     1,     3,     3,
       3,     3,     1,     1,     4,     1,     3,     2,     2,     4,
       3,     4,     4,     4,     4,     4,     4,     4,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     1,     0,     7,     0,     0,     0,
      19,    65,     6,     9,     0,     3,    68,     4,    66,     0,
      43,     8,     0,    90,    18,    21,     0,     0,    48,    15,
      16,    17,    11,    12,    13,    14,     0,     0,    68,     0,
       0,     0,     0,     0,   103,    67,     0,    70,    99,    74,
       0,    72,    73,    75,    76,    77,    78,    79,    80,    81,
      20,     0,     0,    44,    46,    32,     0,     0,     5,    51,
       0,    52,     0,    10,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   125,   123,     0,   113,   117,
     122,    90,     0,     0,     0,     0,     0,     0,    85,     0,
       0,     0,     0,     0,    69,     0,     0,    39,    40,    42,
      41,     0,     0,     0,     0,    24,    25,    23,    33,     0,
       0,    45,    54,    57,    49,    50,     7,     7,   128,   127,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    90,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    90,     0,     0,
       0,     0,   106,     0,    90,    82,     0,     0,     0,     0,
       0,     0,     0,    29,     0,     0,    22,     0,    31,     0,
      59,    59,     0,     0,   126,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   130,     0,    87,   111,   112,   107,
     108,   109,   110,   114,   115,   116,   118,   119,   121,   120,
      89,    91,     0,     0,     0,    94,     0,   101,   102,     0,
     104,    71,     0,     0,   100,     0,    34,     0,    27,    28,
       0,    35,    38,    47,     0,     0,    58,    53,    56,   131,
     132,   133,   134,   135,   136,   137,   138,   129,   124,    90,
      86,    90,    90,    92,    93,     0,     0,   105,     0,    84,
       0,    36,     0,     0,     0,     0,     0,    62,     0,    88,
       0,     0,     0,     0,    83,    37,     0,    30,     0,     0,
       0,    60,    55,    95,    96,    90,    90,    26,     0,    64,
      61,    97,    98,    63
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     5,     8,     9,    10,    12,    13,    85,    20,
      24,    25,   114,   115,   116,   172,   173,    62,   117,    28,
      63,    64,    68,    69,    70,   180,    71,    72,   181,   235,
     266,   267,    86,    17,    49,    23,    50,    99,    51,    52,
      53,    54,   250,    55,    56,    57,   214,   215,    58,    59,
     161,   162,    88,    89,    90
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -161
static const yytype_int16 yypact[] =
{
      19,   -23,    49,  -161,  -161,    26,    69,    23,    52,    40,
     103,  -161,    23,  -161,    84,  -161,  -161,  -161,  -161,    23,
      98,  -161,   -20,   179,    23,  -161,    95,    23,    47,  -161,
    -161,  -161,  -161,  -161,  -161,  -161,    78,   249,  -161,   249,
     249,    23,    86,    91,    93,  -161,   100,  -161,    53,  -161,
     116,  -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,
    -161,   298,    24,    23,  -161,  -161,   115,   126,    47,  -161,
     119,  -161,   152,  -161,   249,   249,   249,   151,   154,   166,
     168,   175,   178,   181,   185,  -161,    73,   380,     8,   -11,
    -161,   271,   273,     4,   112,   249,   249,   249,  -161,   156,
     249,   249,    23,   249,  -161,   -20,    23,  -161,  -161,  -161,
    -161,   196,    23,   193,   201,  -161,  -161,  -161,   204,    23,
     298,  -161,  -161,  -161,  -161,  -161,    69,    69,  -161,  -161,
      65,   249,   249,   249,   249,   249,   249,   249,   249,   249,
      23,   249,    41,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,    41,   369,   249,
     199,    77,   371,    87,   194,   371,   157,   222,    97,   207,
      99,   325,   -45,  -161,   101,   -20,  -161,    23,  -161,   210,
     209,   209,   216,   218,  -161,   104,   108,   110,   122,   124,
     127,   140,   145,   359,  -161,   155,   248,     8,     8,     8,
       8,     8,     8,   -11,   -11,   -11,  -161,  -161,  -161,  -161,
     371,  -161,   214,   219,   355,  -161,   439,  -161,  -161,   249,
    -161,  -161,   236,   249,  -161,    10,  -161,   225,  -161,  -161,
     298,  -161,  -161,  -161,    -2,   221,  -161,  -161,  -161,  -161,
    -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,    41,
    -161,    41,    41,  -161,  -161,   249,   249,   371,   249,   371,
     -20,  -161,   213,   230,    23,   159,   -30,  -161,   325,  -161,
     231,   234,   419,   430,   371,  -161,   298,  -161,   180,   325,
      -2,  -161,  -161,  -161,  -161,    41,    41,  -161,   325,  -161,
    -161,  -161,  -161,  -161
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -161,  -161,  -161,   106,  -161,  -161,  -161,   264,   -13,  -161,
    -161,   262,  -113,  -161,  -161,  -161,   117,  -104,  -160,  -161,
    -161,   228,  -161,   235,  -161,  -161,   246,  -161,  -161,   123,
    -161,    43,    -7,  -161,   315,   287,  -112,  -161,   163,  -161,
    -161,  -161,  -161,  -161,  -161,  -161,  -161,   128,  -161,  -161,
     202,   -36,   280,   -69,   -28
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      14,    87,   170,    92,    93,    14,   264,   179,   174,    36,
     280,   227,    26,   228,   281,    11,    48,    26,   152,   153,
      65,   154,     1,   155,   143,   144,   145,   146,   147,   148,
     196,    29,    30,    31,    94,   149,   150,     3,   260,   151,
     130,    32,    33,    34,    35,   211,   128,   129,   113,     4,
      37,    66,    67,    38,   118,    39,    65,    40,    11,   158,
      41,    29,    30,    31,   165,   166,     6,   160,   174,   119,
     120,    32,    33,    34,    35,     7,    42,    43,    44,   100,
     203,   204,   205,    11,    48,   143,   144,   145,   146,   147,
     148,   101,   169,    15,   102,   167,   103,    16,    16,    65,
      46,    11,    47,   193,    22,    65,    27,   113,   282,   184,
      19,   139,   178,   118,   140,    61,   141,   263,    73,   289,
     210,   218,   219,   216,   206,   207,   208,   209,   293,    95,
     265,   220,   219,   194,    96,    48,    97,   269,   159,   270,
     271,   224,   219,   226,   119,   212,   119,   230,   239,   219,
      48,   213,   240,   219,   241,   219,   104,    48,   113,   126,
     278,    98,   231,   287,   118,    65,   242,   219,   243,   219,
     232,   244,   219,   291,   292,   122,   265,   143,   144,   145,
     146,   147,   148,   257,   245,   219,   123,   259,    37,   246,
     219,    38,   127,    39,   131,    40,   222,   132,    41,   248,
     219,   212,   164,    37,   119,   279,    38,   213,    39,   133,
      40,   134,   261,    41,    42,    43,    44,   113,   135,   272,
     273,   136,   274,   118,   137,   119,   288,    65,   138,    42,
      43,    44,   182,   183,   171,   175,    16,    45,    46,    11,
      47,   176,    48,   217,    48,    48,   177,   275,   223,   225,
     233,    16,   234,    46,    11,   113,   237,    65,   238,   249,
     251,   118,   258,   113,   262,   252,   113,   268,   276,   118,
     277,   283,   118,    65,   284,   113,    21,    74,    48,    48,
      37,   118,    75,    38,   156,    39,    60,    40,   157,   229,
      41,   121,    76,   143,   144,   145,   146,   147,   148,   163,
      29,    30,    31,   124,   236,   168,    42,    43,    44,    11,
      32,    33,    34,    35,   125,    77,    78,    79,    80,    81,
      82,    83,    84,   290,    18,    91,   105,   221,    16,     0,
      46,    11,    47,   185,   186,   187,   188,   189,   190,   191,
     192,   106,   254,   195,     0,   107,   108,   109,   110,    29,
      30,    31,   111,   105,   112,     0,     0,     0,    11,    32,
      33,    34,    35,     0,     0,     0,     0,     0,   106,     0,
       0,     0,   107,   108,   109,   110,    29,    30,    31,   143,
     144,   145,   146,   147,   148,    11,    32,    33,    34,    35,
     142,   143,   144,   145,   146,   147,   148,     0,   247,     0,
     143,   144,   145,   146,   147,   148,    29,    30,    31,     0,
       0,     0,     0,   253,     0,    11,    32,    33,    34,    35,
      29,    30,    31,   197,   198,   199,   200,   201,   202,    11,
      32,    33,    34,    35,   285,     0,     0,     0,     0,   143,
     144,   145,   146,   147,   148,   286,     0,     0,     0,     0,
     143,   144,   145,   146,   147,   148,   255,   256,     0,   143,
     144,   145,   146,   147,   148
};

static const yytype_int16 yycheck[] =
{
       7,    37,   106,    39,    40,    12,     8,   120,   112,    22,
      40,   171,    19,    58,    44,    60,    23,    24,    29,    30,
      27,    32,     3,    34,    20,    21,    22,    23,    24,    25,
     142,    51,    52,    53,    41,    27,    28,    60,    28,    31,
      76,    61,    62,    63,    64,   157,    74,    75,    61,     0,
       9,     4,     5,    12,    61,    14,    63,    16,    60,    55,
      19,    51,    52,    53,   100,   101,    40,    95,   172,    45,
      46,    61,    62,    63,    64,     6,    35,    36,    37,    26,
     149,   150,   151,    60,    91,    20,    21,    22,    23,    24,
      25,    38,   105,    41,    41,   102,    43,    57,    57,   106,
      59,    60,    61,   139,    20,   112,     8,   120,   268,    44,
       7,    38,   119,   120,    41,    20,    43,   230,    40,   279,
     156,    44,    45,   159,   152,   153,   154,   155,   288,    43,
     234,    44,    45,   140,    43,   142,    43,   249,    26,   251,
     252,    44,    45,    44,    45,   158,    45,    46,    44,    45,
     157,   158,    44,    45,    44,    45,    40,   164,   171,    40,
     264,    61,   175,   276,   171,   172,    44,    45,    44,    45,
     177,    44,    45,   285,   286,    60,   280,    20,    21,    22,
      23,    24,    25,   219,    44,    45,    60,   223,     9,    44,
      45,    12,    40,    14,    43,    16,    39,    43,    19,    44,
      45,   214,    46,     9,    45,    46,    12,   214,    14,    43,
      16,    43,   225,    19,    35,    36,    37,   230,    43,   255,
     256,    43,   258,   230,    43,    45,    46,   234,    43,    35,
      36,    37,   126,   127,    38,    42,    57,    58,    59,    60,
      61,    40,   249,    44,   251,   252,    42,   260,    26,    42,
      40,    57,    43,    59,    60,   268,    40,   264,    40,    11,
      46,   268,    26,   276,    39,    46,   279,    46,    55,   276,
      40,    40,   279,   280,    40,   288,    12,    28,   285,   286,
       9,   288,    33,    12,    13,    14,    24,    16,    15,   172,
      19,    63,    43,    20,    21,    22,    23,    24,    25,    97,
      51,    52,    53,    68,   181,   103,    35,    36,    37,    60,
      61,    62,    63,    64,    68,    66,    67,    68,    69,    70,
      71,    72,    73,   280,     9,    38,    28,   164,    57,    -1,
      59,    60,    61,   131,   132,   133,   134,   135,   136,   137,
     138,    43,   214,   141,    -1,    47,    48,    49,    50,    51,
      52,    53,    54,    28,    56,    -1,    -1,    -1,    60,    61,
      62,    63,    64,    -1,    -1,    -1,    -1,    -1,    43,    -1,
      -1,    -1,    47,    48,    49,    50,    51,    52,    53,    20,
      21,    22,    23,    24,    25,    60,    61,    62,    63,    64,
      10,    20,    21,    22,    23,    24,    25,    -1,    39,    -1,
      20,    21,    22,    23,    24,    25,    51,    52,    53,    -1,
      -1,    -1,    -1,    58,    -1,    60,    61,    62,    63,    64,
      51,    52,    53,   143,   144,   145,   146,   147,   148,    60,
      61,    62,    63,    64,    15,    -1,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    25,    15,    -1,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    17,    18,    -1,    20,
      21,    22,    23,    24,    25
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    76,    60,     0,    77,    40,     6,    78,    79,
      80,    60,    81,    82,   107,    41,    57,   108,   109,     7,
      84,    82,    20,   110,    85,    86,   107,     8,    94,    51,
      52,    53,    61,    62,    63,    64,    83,     9,    12,    14,
      16,    19,    35,    36,    37,    58,    59,    61,   107,   109,
     111,   113,   114,   115,   116,   118,   119,   120,   123,   124,
      86,    20,    92,    95,    96,   107,     4,     5,    97,    98,
      99,   101,   102,    40,    28,    33,    43,    66,    67,    68,
      69,    70,    71,    72,    73,    83,   107,   126,   127,   128,
     129,   110,   126,   126,   107,    43,    43,    43,    61,   112,
      26,    38,    41,    43,    40,    28,    43,    47,    48,    49,
      50,    54,    56,    83,    87,    88,    89,    93,   107,    45,
      46,    96,    60,    60,    98,   101,    40,    40,   129,   129,
     126,    43,    43,    43,    43,    43,    43,    43,    43,    38,
      41,    43,    10,    20,    21,    22,    23,    24,    25,    27,
      28,    31,    29,    30,    32,    34,    13,    15,    55,    26,
     129,   125,   126,   125,    46,   126,   126,   107,   125,    83,
      92,    38,    90,    91,    92,    42,    40,    42,   107,    87,
     100,   103,    78,    78,    44,   125,   125,   125,   125,   125,
     125,   125,   125,   126,   107,   125,   111,   127,   127,   127,
     127,   127,   127,   128,   128,   128,   129,   129,   129,   129,
     126,   111,    83,   107,   121,   122,   126,    44,    44,    45,
      44,   113,    39,    26,    44,    42,    44,    93,    58,    91,
      46,    83,   107,    40,    43,   104,   104,    40,    40,    44,
      44,    44,    44,    44,    44,    44,    44,    39,    44,    11,
     117,    46,    46,    58,   122,    17,    18,   126,    26,   126,
      28,    83,    39,    87,     8,    92,   105,   106,    46,   111,
     111,   111,   126,   126,   126,    83,    55,    40,    92,    46,
      40,    44,    93,    40,    40,    15,    15,    87,    46,    93,
     106,   111,   111,    93
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
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
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
        case 2:
#line 26 "pas.y"
    {   
                            myName = copyString(tokenString);
                        }
    break;

  case 3:
#line 30 "pas.y"
    {   (yyval) = (yyvsp[(5) - (6)]);
                            (yyval)->attr.name=myName;
                            myTree = (yyval);
                        }
    break;

  case 4:
#line 42 "pas.y"
    {
                            (yyval) = (yyvsp[(1) - (2)]);
                            (yyval)->sibling=(yyvsp[(2) - (2)]);
                        }
    break;

  case 5:
#line 47 "pas.y"
    {
                            (yyval) = newDeclarationNode(DECL_ROUTINEHEAD);
                            (yyval) ->child[0]=(yyvsp[(1) - (4)]);
                            (yyval) ->child[1]=(yyvsp[(2) - (4)]);
                            (yyval) ->child[2]=(yyvsp[(3) - (4)]);
                            (yyval) ->child[3]=(yyvsp[(4) - (4)]);
                        }
    break;

  case 6:
#line 55 "pas.y"
    {   
                            (yyval)=(yyvsp[(2) - (2)]); 
                        }
    break;

  case 7:
#line 58 "pas.y"
    {   
                            (yyval) = NULL; 
                        }
    break;

  case 8:
#line 63 "pas.y"
    {
                            YYSTYPE t = (yyvsp[(1) - (2)]);
                            if(t!=NULL){
                                while(t->sibling!=NULL)
                                  t=t->sibling;
                                t->sibling = (yyvsp[(2) - (2)]);
                                (yyval)=(yyvsp[(2) - (2)]);
                            }
                            else
                                (yyval)=(yyvsp[(1) - (2)]);
                        }
    break;

  case 9:
#line 76 "pas.y"
    {   
                            (yyval)=(yyvsp[(1) - (1)]); 
                        }
    break;

  case 10:
#line 81 "pas.y"
    {
                            (yyval) = newDeclarationNode(DECL_CONST);
                            (yyval)->attr.name = copyString((yyvsp[(1) - (4)])->attr.name);
                            (yyval)->child[0]=(yyvsp[(3) - (4)]);
                            (yyval)->type=(yyvsp[(3) - (4)])->type;
                            freeNode((yyvsp[(1) - (4)]));
                            
                        }
    break;

  case 11:
#line 91 "pas.y"
    {
                            (yyval) = newExpNode(EXP_CONST);
                            (yyval)->type = EXPTYPE_INT;
                            (yyval)->attr.val = atoi(tokenString);
                        }
    break;

  case 12:
#line 97 "pas.y"
    {
                            (yyval) = newExpNode(EXP_CONST);
                            (yyval)->type = EXPTYPE_REAL;
                            (yyval)->attr.real_val = atof(tokenString);
                        }
    break;

  case 13:
#line 103 "pas.y"
    {
                            (yyval) = newExpNode(EXP_CONST);
                            (yyval)->type = EXPTYPE_CHAR;
                            (yyval)->attr.char_val = tokenString[1];
                        }
    break;

  case 14:
#line 109 "pas.y"
    {
                            (yyval) = newExpNode(EXP_CONST);
                            (yyval)->type=EXPTYPE_STRING;
                            (yyval)->attr.string_val = (char*)malloc(strlen(tokenString)-1);
                            memmove((yyval)->attr.string_val,tokenString+1,strlen(tokenString)-2);
                            (yyval)->attr.string_val[strlen(tokenString)-2]='\0';
                        }
    break;

  case 15:
#line 117 "pas.y"
    {
                            (yyval)=newExpNode(EXP_CONST);
                            (yyval)->type=EXPTYPE_BOOL;
                            (yyval)->attr.val=1;
                        }
    break;

  case 16:
#line 123 "pas.y"
    {
                            (yyval)=newExpNode(EXP_CONST);
                            (yyval)->type=EXPTYPE_BOOL;
                            (yyval)->attr.val=0;
                        }
    break;

  case 17:
#line 129 "pas.y"
    {
                            (yyval)=newExpNode(EXP_CONST);
                            (yyval)->type=EXPTYPE_INT;
                            (yyval)->attr.val=2147483647;
                        }
    break;

  case 18:
#line 137 "pas.y"
    {   
                            (yyval)=(yyvsp[(2) - (2)]);
                        }
    break;

  case 19:
#line 140 "pas.y"
    {   
                            (yyval)=NULL;
                        }
    break;

  case 20:
#line 145 "pas.y"
    {
                            YYSTYPE t=(yyvsp[(1) - (2)]);
                            if(t!=NULL){
                                while(t->sibling!=NULL)
                                  t=t->sibling;
                                t->sibling=(yyvsp[(2) - (2)]);
                                (yyval)=(yyvsp[(1) - (2)]);
                            }
                            else
                              (yyval)=(yyvsp[(2) - (2)]);
                        }
    break;

  case 21:
#line 157 "pas.y"
    {   
                            (yyval)=(yyvsp[(1) - (1)]);
                        }
    break;

  case 22:
#line 162 "pas.y"
    {   (yyval)=newDeclarationNode(DECL_TYPE);
                            (yyval)->child[0]=(yyvsp[(1) - (4)]);
                            (yyval)->child[1]=(yyvsp[(3) - (4)]);
                        }
    break;

  case 23:
#line 167 "pas.y"
    {
                            (yyval)=(yyvsp[(1) - (1)]);
                        }
    break;

  case 24:
#line 170 "pas.y"
    {
                            (yyval)=(yyvsp[(1) - (1)]);
                        }
    break;

  case 25:
#line 173 "pas.y"
    {
                            (yyval)=(yyvsp[(1) - (1)]);
                        }
    break;

  case 26:
#line 179 "pas.y"
    {
                            (yyval)=newTypeNode(TYPE_ARRAY);
                            (yyval)->type=EXPTYPE_ARRAY;
                            (yyval)->child[0]=(yyvsp[(3) - (6)]);
                            (yyval)->child[1]=(yyvsp[(6) - (6)]);
                            
                        }
    break;

  case 27:
#line 188 "pas.y"
    {   
                            (yyval)=(yyvsp[(2) - (3)]); 
                        }
    break;

  case 28:
#line 193 "pas.y"
    {
                            YYSTYPE t=(yyvsp[(1) - (2)]);
                            if(t!=NULL){
                                while(t->sibling!=NULL)
                                  t=t->sibling;
                                t->sibling=(yyvsp[(2) - (2)]);
                                (yyval)=(yyvsp[(1) - (2)]);
                            }
                            else
                              (yyval)=(yyvsp[(2) - (2)]);
                        }
    break;

  case 29:
#line 204 "pas.y"
    {(yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 30:
#line 207 "pas.y"
    {
                            (yyval)=newTypeNode(TYPE_RECORD);
                            (yyval)->child[0]=(yyvsp[(1) - (4)]);
                            (yyval)->child[1]=(yyvsp[(3) - (4)]);
                        }
    break;

  case 31:
#line 214 "pas.y"
    {
                            YYSTYPE t=(yyvsp[(1) - (3)]);
                            if(t!=NULL){
                                while(t->sibling!=NULL)
                                  t=t->sibling;
                                t->sibling=(yyvsp[(3) - (3)]);
                                (yyval)=(yyvsp[(1) - (3)]);
                            }
                            else
                                (yyval)=(yyvsp[(1) - (3)]);
                        }
    break;

  case 32:
#line 225 "pas.y"
    {   (yyval)=(yyvsp[(1) - (1)]); }
    break;

  case 33:
#line 228 "pas.y"
    {
                            (yyval)=newTypeNode(TYPE_SIMPLE_ID);
                            (yyval)->attr.name = copyString((yyvsp[(1) - (1)])->attr.name);
                            free((yyvsp[(1) - (1)]));
                        }
    break;

  case 34:
#line 234 "pas.y"
    {   (yyval)=newTypeNode(TYPE_SIMPLE_ENUM);
                            (yyval)->type=EXPTYPE_SIMPLE_ENUM;
                            (yyval)->child[0]=(yyvsp[(2) - (3)]);
                        }
    break;

  case 35:
#line 239 "pas.y"
    {   (yyval)=newTypeNode(TYPE_SIMPLE_LIMIT);
                            (yyval)->type=EXPTYPE_SIMPLE_LIMIT;
                            (yyval)->child[0]=(yyvsp[(1) - (3)]);
                            (yyval)->child[1]=(yyvsp[(3) - (3)]);
                        }
    break;

  case 36:
#line 245 "pas.y"
    {
                            (yyval)=newTypeNode(TYPE_SIMPLE_LIMIT);
                            (yyval)->type=EXPTYPE_SIMPLE_LIMIT;
                            (yyval)->child[0]=(yyvsp[(2) - (4)]);
                            (yyval)->child[0]->attr.val *= -1;
                            (yyval)->child[1]=(yyvsp[(4) - (4)]);
                        }
    break;

  case 37:
#line 253 "pas.y"
    {   (yyval)=newTypeNode(TYPE_SIMPLE_LIMIT);
                            (yyval)->type=EXPTYPE_SIMPLE_LIMIT;
                            (yyval)->child[0]=(yyvsp[(2) - (5)]);
                            (yyval)->child[0]->attr.val *=-1;
                            (yyval)->child[1]=(yyvsp[(5) - (5)]);
                            (yyval)->child[1]->attr.val *=-1;
                        }
    break;

  case 38:
#line 261 "pas.y"
    {
                            (yyval)=newTypeNode(TYPE_SIMPLE_LIMIT);
                            (yyval)->type=EXPTYPE_SIMPLE_LIMIT;
                            (yyval)->child[0]=(yyvsp[(1) - (3)]);
                            (yyval)->child[1]=(yyvsp[(3) - (3)]);
                        }
    break;

  case 39:
#line 268 "pas.y"
    {   (yyval)=newTypeNode(TYPE_SIMPLE_SYS);
                            (yyval)->type=EXPTYPE_INT;
                        }
    break;

  case 40:
#line 272 "pas.y"
    {   (yyval)=newTypeNode(TYPE_SIMPLE_SYS);
                            (yyval)->type=EXPTYPE_BOOL;
                        }
    break;

  case 41:
#line 276 "pas.y"
    {   (yyval)=newTypeNode(TYPE_SIMPLE_SYS);
                            (yyval)->type=EXPTYPE_REAL;
                        }
    break;

  case 42:
#line 280 "pas.y"
    {   (yyval)=newTypeNode(TYPE_SIMPLE_SYS);
                            (yyval)->type=EXPTYPE_CHAR;
                        }
    break;

  case 43:
#line 285 "pas.y"
    {   
                            (yyval) = NULL;
                        }
    break;

  case 44:
#line 289 "pas.y"
    {   
                            (yyval)=(yyvsp[(2) - (2)]);
                        }
    break;

  case 45:
#line 294 "pas.y"
    {   YYSTYPE t = (yyvsp[(1) - (2)]);
                            if(t!=NULL){
                                while(t->sibling!=NULL)
                                  t=t->sibling;
                                t->sibling=(yyvsp[(2) - (2)]);
                                (yyval)=(yyvsp[(1) - (2)]);
                            }
                            else
                                (yyval)=(yyvsp[(2) - (2)]);
                        }
    break;

  case 46:
#line 304 "pas.y"
    {
                            (yyval)=(yyvsp[(1) - (1)]);
                        }
    break;

  case 47:
#line 309 "pas.y"
    {   (yyval)=newDeclarationNode(DECL_VAR);
                            (yyval)->child[0]=(yyvsp[(1) - (4)]);
                            (yyval)->child[1]=(yyvsp[(3) - (4)]);
                        }
    break;

  case 48:
#line 315 "pas.y"
    {   
                            (yyval)= NULL;
                        }
    break;

  case 49:
#line 319 "pas.y"
    {   YYSTYPE t=(yyvsp[(1) - (2)]);
                            if(t!=NULL){
                                while(t->sibling!=NULL)
                                  t=t->sibling;
                                t->sibling=(yyvsp[(2) - (2)]);
                                (yyval)=(yyvsp[(1) - (2)]);
                            }
                            else
                                (yyval)=(yyvsp[(2) - (2)]);
                        }
    break;

  case 50:
#line 330 "pas.y"
    {   YYSTYPE t=(yyvsp[(1) - (2)]);
                            if(t!=NULL){
                                while(t->sibling!=NULL)
                                  t=t->sibling;
                                t->sibling=(yyvsp[(2) - (2)]);
                                (yyval)=(yyvsp[(1) - (2)]);
                            }
                            else
                                (yyval)=(yyvsp[(2) - (2)]);
                        }
    break;

  case 51:
#line 340 "pas.y"
    {(yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 52:
#line 341 "pas.y"
    {(yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 53:
#line 344 "pas.y"
    {
                            (yyval)=newDeclarationNode(DECL_FUNCTION);
                            (yyval)->child[0]=(yyvsp[(1) - (4)]);
                            (yyval)->child[1]=(yyvsp[(3) - (4)]);
                        }
    break;

  case 54:
#line 351 "pas.y"
    {   myName=copyString(tokenString);}
    break;

  case 55:
#line 353 "pas.y"
    {
                            (yyval)=newDeclarationNode(DECL_FUNCTIONHEAD);
                            (yyval)->attr.name=myName;
                            (yyval)->child[0]=(yyvsp[(4) - (6)]);
                            (yyval)->child[1]=(yyvsp[(6) - (6)]);
                        }
    break;

  case 56:
#line 361 "pas.y"
    {
                            (yyval)=newDeclarationNode(DECL_PROCEDURE);
                            (yyval)->child[0]=(yyvsp[(1) - (4)]);
                            (yyval)->child[1]=(yyvsp[(3) - (4)]);
                        }
    break;

  case 57:
#line 368 "pas.y"
    {   myName=copyString(tokenString);}
    break;

  case 58:
#line 370 "pas.y"
    {   (yyval)=newDeclarationNode(DECL_PROCEDUREHEAD);
                            (yyval)->attr.name=myName;
                            (yyval)->child[0]=(yyvsp[(4) - (4)]);
                        }
    break;

  case 59:
#line 376 "pas.y"
    {
                            (yyval)=NULL;
                        }
    break;

  case 60:
#line 380 "pas.y"
    {
                            (yyval)=(yyvsp[(2) - (3)]);
                        }
    break;

  case 61:
#line 385 "pas.y"
    {   YYSTYPE t=(yyvsp[(1) - (3)]);
                            if(t!=NULL){
                                while(t->sibling!=NULL)
                                  t=t->sibling;
                                t->sibling=(yyvsp[(3) - (3)]);
                                (yyval)=(yyvsp[(1) - (3)]);
                            }
                            else
                                (yyval)=(yyvsp[(3) - (3)]);
                        }
    break;

  case 62:
#line 396 "pas.y"
    {   
                            (yyval)=(yyvsp[(1) - (1)]); 
                        }
    break;

  case 63:
#line 401 "pas.y"
    {
                            (yyval)=newDeclarationNode(DECL_VAR_PARA);
                            (yyval)->child[0]=(yyvsp[(2) - (4)]);
                            (yyval)->child[1]=(yyvsp[(4) - (4)]);
                        }
    break;

  case 64:
#line 407 "pas.y"
    {
                            (yyval)=newDeclarationNode(DECL_VAL_PARA);
                            (yyval)->child[0]=(yyvsp[(1) - (3)]);
                            (yyval)->child[1]=(yyvsp[(3) - (3)]);
                        }
    break;

  case 65:
#line 414 "pas.y"
    {   (yyval)=newExpNode(EXP_ID);
                            (yyval)->attr.name=copyString(tokenString);
                        }
    break;

  case 66:
#line 417 "pas.y"
    {
                            (yyval)=(yyvsp[(1) - (1)]);
                        }
    break;

  case 67:
#line 421 "pas.y"
    {
                            (yyval)=(yyvsp[(2) - (3)]);
                        }
    break;

  case 68:
#line 426 "pas.y"
    {
                            (yyval)=NULL;
                        }
    break;

  case 69:
#line 430 "pas.y"
    {
                            YYSTYPE t=(yyvsp[(1) - (3)]);
                            if(t!=NULL){
                                while(t->sibling!=NULL)
                                  t=t->sibling;
                                t->sibling=(yyvsp[(2) - (3)]);
                                (yyval)=(yyvsp[(1) - (3)]);
                            }
                            else
                                (yyval)=(yyvsp[(2) - (3)]);
                        }
    break;

  case 70:
#line 443 "pas.y"
    {   
                            myNum= atoi(tokenString);
                        }
    break;

  case 71:
#line 447 "pas.y"
    {
                            (yyval)=newStatementNode(STMT_LABEL);
                            (yyval)->attr.val=myNum;
                            (yyval)->child[0]=(yyvsp[(4) - (4)]);
                        }
    break;

  case 72:
#line 453 "pas.y"
    {   
                            (yyval)=(yyvsp[(1) - (1)]);
                        }
    break;

  case 73:
#line 457 "pas.y"
    {
                            (yyval)=(yyvsp[(1) - (1)]);
                        }
    break;

  case 74:
#line 460 "pas.y"
    {
                            (yyval)=(yyvsp[(1) - (1)]);
                        }
    break;

  case 75:
#line 463 "pas.y"
    {
                            (yyval)=(yyvsp[(1) - (1)]);
                        }
    break;

  case 76:
#line 466 "pas.y"
    {
                            (yyval)=(yyvsp[(1) - (1)]);
                        }
    break;

  case 77:
#line 469 "pas.y"
    {
                            (yyval)=(yyvsp[(1) - (1)]);
                        }
    break;

  case 78:
#line 472 "pas.y"
    {
                            (yyval)=(yyvsp[(1) - (1)]);
                        }
    break;

  case 79:
#line 475 "pas.y"
    {
                            (yyval)=(yyvsp[(1) - (1)]);
                        }
    break;

  case 80:
#line 478 "pas.y"
    {
                            (yyval)=(yyvsp[(1) - (1)]);
                        }
    break;

  case 81:
#line 481 "pas.y"
    {
                            (yyval)=(yyvsp[(1) - (1)]);
                        }
    break;

  case 82:
#line 486 "pas.y"
    {   (yyval)=newStatementNode(STMT_ASSIGN);
                            (yyval)->child[0]=(yyvsp[(1) - (3)]);
                            (yyval)->child[1]=(yyvsp[(3) - (3)]);
                            (yyval)->attr.op=TOKEN_ID;
                        }
    break;

  case 83:
#line 492 "pas.y"
    {   (yyval)=newStatementNode(STMT_ASSIGN);
                            (yyval)->child[0]=(yyvsp[(1) - (6)]);
                            ((yyval)->child[0])->child[0]=(yyvsp[(3) - (6)]);
                            (yyval)->child[1]=(yyvsp[(6) - (6)]);
                            (yyval)->attr.op=TOKEN_ARRAY;
                        }
    break;

  case 84:
#line 500 "pas.y"
    {   (yyval)=newStatementNode(STMT_ASSIGN);
                            (yyval)->child[0]=(yyvsp[(1) - (5)]);
                            ((yyval)->child[0])->child[0]=(yyvsp[(3) - (5)]);
                            (yyval)->child[1]=(yyvsp[(5) - (5)]);
                            (yyval)->attr.op=TOKEN_RECORD;
                        }
    break;

  case 85:
#line 508 "pas.y"
    {   (yyval)=newStatementNode(STMT_GOTO);
                            (yyval)->attr.val=atoi(tokenString);
                        }
    break;

  case 86:
#line 513 "pas.y"
    {   (yyval)=newStatementNode(STMT_IF);
                            (yyval)->child[0]=(yyvsp[(2) - (5)]);
                            (yyval)->child[1]=(yyvsp[(4) - (5)]);
                            (yyval)->child[2]=(yyvsp[(5) - (5)]);
                        }
    break;

  case 87:
#line 519 "pas.y"
    {
                            (yyval)=NULL;
                        }
    break;

  case 88:
#line 522 "pas.y"
    {
                            (yyval)=(yyvsp[(2) - (2)]);
                        }
    break;

  case 89:
#line 527 "pas.y"
    {
                            (yyval)=newStatementNode(STMT_REPEAT);
                            (yyval)->child[0]=(yyvsp[(2) - (4)]);
                            (yyval)->child[1]=(yyvsp[(4) - (4)]);
                        }
    break;

  case 91:
#line 534 "pas.y"
    {   (yyval)=newStatementNode(STMT_WHILE);
                            (yyval)->child[0]=(yyvsp[(2) - (4)]);
                            (yyval)->child[1]=(yyvsp[(4) - (4)]);
                        }
    break;

  case 92:
#line 539 "pas.y"
    {   (yyval)=newStatementNode(STMT_CASE);
                            (yyval)->child[0]=(yyvsp[(2) - (5)]);
                            (yyval)->child[1]=(yyvsp[(4) - (5)]);
                        }
    break;

  case 93:
#line 544 "pas.y"
    {   YYSTYPE t=(yyvsp[(1) - (2)]);
                            if(t!=NULL){
                                while(t->sibling!=NULL)
                                  t=t->sibling;
                                t->sibling=(yyvsp[(2) - (2)]);
                                (yyval)=(yyvsp[(1) - (2)]);
                            }
                            else
                                (yyval)=(yyvsp[(2) - (2)]);
                        }
    break;

  case 94:
#line 554 "pas.y"
    {
                            (yyval)=(yyvsp[(1) - (1)]);
                        }
    break;

  case 95:
#line 559 "pas.y"
    {
                            (yyval)=newExpNode(EXP_CASE);
                            (yyval)->child[0]=(yyvsp[(1) - (4)]);
                            (yyval)->child[1]=(yyvsp[(3) - (4)]);
                        }
    break;

  case 96:
#line 565 "pas.y"
    {
                            (yyval)=newExpNode(EXP_CASE);
                            (yyval)->child[0]=(yyvsp[(1) - (4)]);
                            (yyval)->child[1]=(yyvsp[(3) - (4)]);
                        }
    break;

  case 97:
#line 571 "pas.y"
    {
                            (yyval)=newStatementNode(STMT_FOR);
                            (yyval)->child[0]=(yyvsp[(2) - (8)]);
                            (yyval)->child[1]=(yyvsp[(4) - (8)]);
                            (yyval)->child[2]=(yyvsp[(6) - (8)]);
                            (yyval)->child[3]=(yyvsp[(8) - (8)]);
                            (yyval)->attr.op=TOKEN_TO;
                        }
    break;

  case 98:
#line 580 "pas.y"
    {
                            (yyval)=newStatementNode(STMT_FOR);
                            (yyval)->child[0]=(yyvsp[(2) - (8)]);
                            (yyval)->child[1]=(yyvsp[(4) - (8)]);
                            (yyval)->child[2]=(yyvsp[(6) - (8)]);
                            (yyval)->child[3]=(yyvsp[(8) - (8)]);
                            (yyval)->attr.op=TOKEN_DOWNTO;
                        }
    break;

  case 99:
#line 589 "pas.y"
    {   (yyval)=newStatementNode(STMT_PROC_ID);
                            (yyval)->attr.name=copyString((yyvsp[(1) - (1)])->attr.name);
                        }
    break;

  case 100:
#line 593 "pas.y"
    {   (yyval)=newStatementNode(STMT_PROC_ID);
                            (yyval)->attr.name=copyString((yyvsp[(1) - (4)])->attr.name);
                            (yyval)->child[0]=(yyvsp[(3) - (4)]);
                        }
    break;

  case 101:
#line 598 "pas.y"
    {
                            (yyval)=newStatementNode(STMT_PROC_SYS);
                            (yyval)->attr.op=TOKEN_READ;
                            (yyval)->child[0]=(yyvsp[(3) - (4)]);
                        }
    break;

  case 102:
#line 604 "pas.y"
    {   (yyval)=newStatementNode(STMT_PROC_SYS);
                            (yyval)->attr.op=TOKEN_WRITE;
                            (yyval)->child[0]=(yyvsp[(3) - (4)]);
                        }
    break;

  case 103:
#line 609 "pas.y"
    {   (yyval)=newStatementNode(STMT_PROC_SYS);
                            (yyval)->attr.op=TOKEN_WRITELN;
                        }
    break;

  case 104:
#line 613 "pas.y"
    {   (yyval)=newStatementNode(STMT_PROC_SYS);
                            (yyval)->attr.op=TOKEN_WRITELN;
                            (yyval)->child[0]=(yyvsp[(3) - (4)]);
                        }
    break;

  case 105:
#line 619 "pas.y"
    {   YYSTYPE t=(yyvsp[(1) - (3)]);
                            if(t!=NULL){
                                while(t->sibling!=NULL)
                                  t=t->sibling;
                                t->sibling=(yyvsp[(3) - (3)]);
                                (yyval)=(yyvsp[(1) - (3)]);
                            }
                            else
                                (yyval)=(yyvsp[(3) - (3)]);
                        }
    break;

  case 106:
#line 629 "pas.y"
    {
                            (yyval)=(yyvsp[(1) - (1)]);
                        }
    break;

  case 107:
#line 634 "pas.y"
    {   
                            (yyval)=newExpressionNode((yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),TOKEN_GE);
                        }
    break;

  case 108:
#line 637 "pas.y"
    {   
                            (yyval)=newExpressionNode((yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),TOKEN_GT);
                        }
    break;

  case 109:
#line 640 "pas.y"
    {   
                            (yyval)=newExpressionNode((yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),TOKEN_LE);
                        }
    break;

  case 110:
#line 643 "pas.y"
    {   
                            (yyval)=newExpressionNode((yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),TOKEN_LT);
                        }
    break;

  case 111:
#line 646 "pas.y"
    {   
                            (yyval)=newExpressionNode((yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),TOKEN_EQUAL);
                        }
    break;

  case 112:
#line 649 "pas.y"
    {   
                            (yyval)=newExpressionNode((yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),TOKEN_UNEQUAL);
                        }
    break;

  case 113:
#line 652 "pas.y"
    {   
                            (yyval)=(yyvsp[(1) - (1)]);
                        }
    break;

  case 114:
#line 657 "pas.y"
    {   
                            (yyval)=newExpressionNode((yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),TOKEN_PLUS);
                        }
    break;

  case 115:
#line 660 "pas.y"
    {   
                            (yyval)=newExpressionNode((yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),TOKEN_MINUS);
                        }
    break;

  case 116:
#line 663 "pas.y"
    {   
                            (yyval)=newExpressionNode((yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),TOKEN_OR);
                        }
    break;

  case 117:
#line 666 "pas.y"
    {   
                            (yyval)=(yyvsp[(1) - (1)]);
                        }
    break;

  case 118:
#line 671 "pas.y"
    {   
                            (yyval)=newExpressionNode((yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),TOKEN_MUL);
                        }
    break;

  case 119:
#line 674 "pas.y"
    {   
                            (yyval)=newExpressionNode((yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),TOKEN_DIV);
                        }
    break;

  case 120:
#line 677 "pas.y"
    {   
                            (yyval)=newExpressionNode((yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),TOKEN_MOD);
                        }
    break;

  case 121:
#line 680 "pas.y"
    {   
                            (yyval)=newExpressionNode((yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),TOKEN_AND);
                        }
    break;

  case 122:
#line 683 "pas.y"
    {
                            (yyval)=(yyvsp[(1) - (1)]);
                        }
    break;

  case 123:
#line 689 "pas.y"
    {
                            (yyval)=(yyvsp[(1) - (1)]);
                        }
    break;

  case 124:
#line 693 "pas.y"
    {   (yyval)=newExpNode(EXP_FUNC_ID);
                            (yyval)->attr.name=copyString((yyvsp[(1) - (4)])->attr.name);
                            (yyval)->child[0]=(yyvsp[(3) - (4)]);
                        }
    break;

  case 125:
#line 697 "pas.y"
    {
                            (yyval)=(yyvsp[(1) - (1)]);
                        }
    break;

  case 126:
#line 700 "pas.y"
    {
                            (yyval)=(yyvsp[(2) - (3)]);
                        }
    break;

  case 127:
#line 704 "pas.y"
    {   
                            (yyval)=newExpressionNode((yyvsp[(2) - (2)]),NULL,TOKEN_NOT);
                        }
    break;

  case 128:
#line 708 "pas.y"
    {   
                            (yyval)=newExpressionNode((yyvsp[(2) - (2)]),NULL,TOKEN_MINUS);
                        }
    break;

  case 129:
#line 712 "pas.y"
    {   (yyval)=(yyvsp[(1) - (4)]);
                            (yyval)->child[0]=(yyvsp[(3) - (4)]);
                            (yyval)->type=EXPTYPE_ARRAY;
                        }
    break;

  case 130:
#line 717 "pas.y"
    {   (yyval)=(yyvsp[(1) - (3)]);
                            (yyval)->child[0]=(yyvsp[(3) - (3)]);
                            (yyval)->type=EXPTYPE_RECORD;
                        }
    break;

  case 131:
#line 722 "pas.y"
    {   
                            (yyval)=newFuncSysExpNode(TOKEN_ABS,(yyvsp[(3) - (4)]));
                        }
    break;

  case 132:
#line 726 "pas.y"
    {   
                            (yyval)=newFuncSysExpNode(TOKEN_CHR,(yyvsp[(3) - (4)]));
                        }
    break;

  case 133:
#line 730 "pas.y"
    {   
                            (yyval)=newFuncSysExpNode(TOKEN_ODD,(yyvsp[(3) - (4)]));
                        }
    break;

  case 134:
#line 734 "pas.y"
    {   
                            (yyval)=newFuncSysExpNode(TOKEN_ORD,(yyvsp[(3) - (4)]));
                        }
    break;

  case 135:
#line 738 "pas.y"
    {   
                            (yyval)=newFuncSysExpNode(TOKEN_PRED,(yyvsp[(3) - (4)]));
                        }
    break;

  case 136:
#line 742 "pas.y"
    {   
                            (yyval)=newFuncSysExpNode(TOKEN_SQR,(yyvsp[(3) - (4)]));
                        }
    break;

  case 137:
#line 746 "pas.y"
    {   
                            (yyval)=newFuncSysExpNode(TOKEN_SQRT,(yyvsp[(3) - (4)]));
                        }
    break;

  case 138:
#line 750 "pas.y"
    {   
                            (yyval)=newFuncSysExpNode(TOKEN_SUCC,(yyvsp[(3) - (4)]));
                        }
    break;


/* Line 1267 of yacc.c.  */
#line 2905 "y.tab.c"
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
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  if (yyn == YYFINAL)
    YYACCEPT;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
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


#line 754 "pas.y"


TreeNode * parse(){
    yyparse();
    return myTree;
}

