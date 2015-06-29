#ifndef lint
static char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif
#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define yyclearin (yychar=(-1))
#define yyerrok (yyerrflag=0)
#define YYRECOVERING (yyerrflag!=0)
#define YYPREFIX "yy"
#line 2 "tiny.y"
#define YYPARSER
#include "global.h"
#include "util.h"
#include "scan.h"
#include "parse.h"
#define YYSTYPE TreeNode *
static char * savedName;
static int savedLineNo;
static TreeNode* savedTree;
static int savedNum;
static int level=0;
int yyparse();
static int yylex(){
    return getToken();
}

int yyerror(char* message) {
    fprintf(listing, "Syntax error at line %d: %s\n",lineno,message);
   /* printToken(yychar, tokenString);*/
    return 0;
}

#line 35 "y.tab.c"
#define TOKEN_PROGRAM 257
#define TOKEN_FUNCTION 258
#define TOKEN_PROCEDURE 259
#define TOKEN_CONST 260
#define TOKEN_TYPE 261
#define TOKEN_VAR 262
#define TOKEN_IF 263
#define TOKEN_THEN 264
#define TOKEN_ELSE 265
#define TOKEN_REPEAT 266
#define TOKEN_UNTIL 267
#define TOKEN_WHILE 268
#define TOKEN_DO 269
#define TOKEN_CASE 270
#define TOKEN_TO 271
#define TOKEN_DOWNTO 272
#define TOKEN_FOR 273
#define TOKEN_EQUAL 274
#define TOKEN_UNEQUAL 275
#define TOKEN_GE 276
#define TOKEN_GT 277
#define TOKEN_LE 278
#define TOKEN_LT 279
#define TOKEN_ASSIGN 280
#define TOKEN_PLUS 281
#define TOKEN_MINUS 282
#define TOKEN_MUL 283
#define TOKEN_DIV 284
#define TOKEN_OR 285
#define TOKEN_AND 286
#define TOKEN_NOT 287
#define TOKEN_MOD 288
#define TOKEN_READ 289
#define TOKEN_WRITE 290
#define TOKEN_WRITELN 291
#define TOKEN_LB 292
#define TOKEN_RB 293
#define TOKEN_SEMI 294
#define TOKEN_DOT 295
#define TOKEN_DOTDOT 296
#define TOKEN_LP 297
#define TOKEN_RP 298
#define TOKEN_COMMA 299
#define TOKEN_COLON 300
#define TOKEN_INTEGER_TYPE 301
#define TOKEN_BOOLEAN_TYPE 302
#define TOKEN_CHAR_TYPE 303
#define TOKEN_REAL_TYPE 304
#define TOKEN_TRUE 305
#define TOKEN_FALSE 306
#define TOKEN_MAXINT 307
#define TOKEN_ARRAY 308
#define TOKEN_OF 309
#define TOKEN_RECORD 310
#define TOKEN_BEGIN 311
#define TOKEN_END 312
#define TOKEN_GOTO 313
#define TOKEN_ID 314
#define TOKEN_INT 315
#define TOKEN_REAL 316
#define TOKEN_CHAR 317
#define TOKEN_STRING 318
#define ERROR 319
#define TOKEN_ABS 320
#define TOKEN_CHR 321
#define TOKEN_ODD 322
#define TOKEN_ORD 323
#define TOKEN_PRED 324
#define TOKEN_SQR 325
#define TOKEN_SQRT 326
#define TOKEN_SUCC 327
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    1,    0,    2,    3,    8,    8,    8,    8,    8,    9,
   13,   11,   12,   12,   15,   15,   16,   16,   10,   19,
   18,    7,    7,   20,   20,   21,    5,    5,   23,   23,
   24,   26,   26,   26,   26,   26,   26,   26,    6,    6,
   27,   27,   28,   22,   22,   22,   30,   31,   31,   32,
   29,   14,   14,   14,   14,   14,   14,   14,   14,   14,
   14,   17,   17,   25,    4,   33,   34,   34,   36,   35,
   35,   37,   37,   37,   37,   37,   37,   37,   37,   37,
   38,   38,   38,   39,   40,   47,   47,   41,   41,   42,
   43,   48,   48,   49,   49,   44,   44,   45,   45,   45,
   45,   45,   45,   50,   50,   46,   46,   46,   46,   46,
   46,   46,   52,   52,   52,   52,   53,   53,   53,   53,
   53,   51,   51,   51,   51,   51,   51,   51,   51,   51,
   51,   51,   51,   51,   51,   51,   51,
};
short yylen[] = {                                         2,
    0,    6,    2,    4,    0,    2,    2,    1,    1,    4,
    0,    6,    0,    3,    3,    1,    4,    3,    4,    0,
    4,    0,    2,    2,    1,    4,    0,    2,    2,    1,
    4,    1,    1,    1,    1,    1,    1,    1,    0,    2,
    2,    1,    4,    1,    1,    1,    3,    2,    1,    4,
    6,    1,    3,    3,    4,    5,    3,    1,    1,    1,
    1,    3,    1,    1,    1,    3,    0,    3,    0,    4,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    3,    6,    5,    2,    5,    0,    2,    4,    0,    4,
    5,    2,    1,    4,    4,    8,    8,    1,    4,    4,
    4,    1,    4,    3,    1,    3,    3,    3,    3,    3,
    3,    1,    3,    3,    3,    1,    3,    3,    3,    3,
    1,    1,    4,    1,    3,    2,    2,    4,    3,    4,
    4,    4,    4,    4,    4,    4,    4,
};
short yydefred[] = {                                      0,
    0,    0,    1,    0,    0,    0,    0,    0,    0,   64,
    0,   30,    0,    2,   67,    3,   65,    0,    0,   29,
    0,    0,    0,    0,   42,    0,    0,   36,   37,   38,
   32,   33,   34,   35,    0,    0,   67,    0,    0,    0,
    0,    0,    0,   66,    0,   69,    0,   73,    0,   71,
   72,   74,   75,   76,   77,   78,   79,   80,    0,   41,
    0,    0,   25,   63,    0,    0,    0,    8,    9,    0,
    0,   31,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  124,    0,  121,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   84,    0,    0,    0,
    0,    0,   68,    0,    0,   58,   59,   61,   60,    0,
    0,   44,    0,    0,    0,   45,   46,    0,    0,   24,
   11,   20,    6,    7,    0,    0,  127,  126,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   49,   43,    0,    0,   62,    0,    0,    0,
    0,    0,  125,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  129,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  117,  118,  120,  119,    0,   90,
    0,    0,    0,   93,    0,  100,  101,    0,  103,   70,
    0,    0,   99,    0,   53,    0,    0,   47,   48,   57,
   54,   26,    0,    0,   21,   10,   19,  130,  131,  132,
  133,  134,  135,  136,  137,  128,  123,    0,   85,    0,
    0,   91,   92,    0,    0,    0,    0,    0,    0,   55,
    0,    0,    0,    0,   16,    0,    0,   87,    0,    0,
    0,    0,    0,   56,    0,   50,    0,    0,   14,    0,
   12,   95,   94,    0,    0,   51,    0,   15,   18,   96,
   97,   17,
};
short yydgoto[] = {                                       2,
    4,    7,    8,   16,    9,   19,   27,   67,   68,   69,
   70,  234,  179,  112,  264,  265,   61,   71,  180,   62,
   63,  113,   11,   12,   84,   85,   24,   25,  116,  117,
  172,  173,   48,   22,   49,   98,   50,   51,   52,   53,
   54,   55,   56,   57,   58,  160,  249,  213,  214,  161,
   87,   88,   89,
};
short yysindex[] = {                                   -228,
 -277,    0,    0, -248, -209, -254, -225, -219, -178,    0,
 -254,    0, -159,    0,    0,    0,    0, -254, -141,    0,
 -121,  -60, -146, -254,    0, -254, -204,    0,    0,    0,
    0,    0,    0,    0, -154,  119,    0,  119,  119, -254,
 -148, -129, -123,    0, -177,    0, -158,    0, -102,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  552,    0,
 -223, -254,    0,    0, -149, -116, -204,    0,    0,  -92,
  -85,    0,  119,  119,  119,  -79,  -69,  -58,  -54,  -51,
  -49,  -48,  -41, -199,    0,    9,    0, -156, -125,   26,
  -11, -168,  -21,  119,  119,  119,    0,  -40,  119,  119,
 -254,  119,    0, -121, -254,    0,    0,    0,    0,  -30,
 -254,    0,  -24,  -25,  -20,    0,    0, -254,  552,    0,
    0,    0,    0,    0, -209, -209,    0,    0, -131,  119,
  119,  119,  119,  119,  119,  119,  119,  119, -254,  119,
   34,  119,  119,  119,  119,  119,  119,  119,  119,  119,
  119,  119,  119,  119,  119,   34,  104,  119,  -23,  153,
 -128, -126,   63,  153,   94,   -3, -122,  -16, -120,  579,
 -198, -293,    0,    0, -254, -121,    0,    1,    4,    4,
   11,   12,    0, -117, -110, -108,  -98,  -94,  -87,  -84,
  -82,  196,    0,  -75,   43, -156, -156, -156, -156, -156,
 -156, -125, -125, -125,    0,    0,    0,    0,  153,    0,
   -9,   13,  593,    0,  231,    0,    0,  119,    0,    0,
   29,  119,    0, -244,    0,   18,  552,    0,    0,    0,
    0,    0, -247,   14,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   34,    0,   34,
   34,    0,    0,  119,  119,  153,  119,  153, -121,    0,
    3,   24, -254, -255,    0,  -74,  579,    0,   25,   28,
  338,  374,  153,    0,  552,    0,  -67, -247,    0,  579,
    0,    0,    0,   34,   34,    0,  579,    0,    0,    0,
    0,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0, -236,    0,    0,    0, -245,    0,
 -226,    0,    0,    0,    0,    0,    0,    0, -231,    0,
    0,   36,    0, -217,    0,    0,   17,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -235,    0,    0,    0, -216,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -211,    0,    0,    0,    0,   21,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  114,    0,    0,    0,  327,  183,   36,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -162,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -236, -236,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -215,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -215,    0,    0,    0,  -64,
    0,    0, -215, -213,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   20,   40,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   41,  363,  399,  435,  471,  507,
  543,  219,  255,  291,    0,    0,    0,    0, -208,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -215,    0,   36,
   36,    0,    0,    0,    0,  -61,    0, -207,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -197,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -215, -215,    0,    0,    0,    0,    0,
    0,    0,
};
short yygindex[] = {                                      0,
    0,  115,    0,    0,    0,    0,    0,    0,  271,  275,
    0,  163,    0, -163,    0,   66, -103,    0,    0,    0,
  284, -113,    0,  339,   -6,   23,    0,  340,    0,    0,
    0,  179,  355,  329, -132,    0,  204,    0,    0,    0,
    0,    0,    0,    0,    0,  -35,    0,    0,  162,  225,
  -63,  400,    6,
};
#define YYTABLESIZE 911
short yytable[] = {                                      13,
   86,  169,   91,   92,   13,  178,  226,  171,  195,  127,
  128,   23,   39,   39,  263,   47,   39,   23,  228,   64,
   10,   27,   27,  210,   27,   27,   22,   22,    1,  102,
  159,   28,   28,   93,   28,   28,    3,  259,  278,  129,
   40,   40,  279,   35,   40,    5,   23,   23,   98,   89,
    6,   81,  114,   65,   66,   64,   88,   83,  102,   10,
   28,   29,   30,  164,  165,   39,   10,   82,  171,   14,
   31,   32,   33,   34,   27,  118,  119,   98,   89,   22,
   81,  115,   18,   47,   28,   88,   83,  205,  206,  207,
  208,   15,  138,   40,  166,  139,   82,  140,   64,   23,
  118,  227,  192,  281,   64,  142,  143,  144,  145,  146,
  147,  177,  114,  262,   21,  268,  289,  269,  270,  209,
   26,   99,  215,  292,  148,  149,  168,   59,  150,  266,
   52,   52,  193,  100,   47,   52,  101,   97,  102,   72,
  157,  115,  142,  143,  144,  145,  146,  147,   94,   47,
  211,  290,  291,  202,  203,  204,   47,  151,  152,  277,
  153,  286,  154,  114,  121,   64,  183,   95,  230,  217,
  218,  219,  218,   96,  266,  223,  218,  225,  118,  212,
  238,  218,  256,   28,   29,   30,  258,  239,  218,  240,
  218,  103,  115,   31,   32,   33,   34,  122,  231,  241,
  218,  125,   36,  242,  218,   37,  211,   38,  126,   39,
  243,  218,   40,  244,  218,  245,  218,  130,  271,  272,
  114,  273,  247,  218,  118,  280,   64,  131,   41,   42,
   43,  118,  287,  105,  105,  212,  104,  104,  132,  181,
  182,   47,  133,   47,   47,  134,  260,  135,  136,  115,
   15,   44,   45,   10,   46,  137,   64,  156,  158,  163,
  114,  170,  142,  143,  144,  145,  146,  147,  114,  174,
  175,   64,  141,  114,  216,  176,  222,   47,   47,  224,
  114,  274,  142,  143,  144,  145,  146,  147,   36,  115,
  250,   37,  155,   38,  232,   39,   36,  115,   40,   37,
  233,   38,  115,   39,  236,  237,   40,  248,  257,  115,
  261,  275,  251,  267,   41,   42,   43,  276,  282,   13,
  162,  283,   41,   42,   43,   36,  167,    5,   37,   89,
   38,    4,   39,   13,   86,   40,   15,  123,   45,   10,
   46,  124,  235,  288,   15,  120,   45,   10,   46,   20,
  229,   41,   42,   43,  184,  185,  186,  187,  188,  189,
  190,  191,   17,   60,  194,   90,  220,  142,  143,  144,
  145,  146,  147,   15,  253,   45,   10,  122,  122,    0,
    0,    0,  122,    0,  122,  122,  221,  122,  122,  122,
  122,  122,  122,    0,  122,  122,  122,  122,  122,  122,
   73,  122,    0,    0,    0,   74,  122,  122,   28,   29,
   30,  122,  122,    0,    0,   75,    0,   10,   31,   32,
   33,   34,  122,   28,   29,   30,  142,  143,  144,  145,
  146,  147,   10,   31,   32,   33,   34,    0,   76,   77,
   78,   79,   80,   81,   82,   83,  116,  116,    0,    0,
    0,  116,    0,  116,  116,    0,  116,  116,  116,  116,
  116,  116,    0,  116,  116,    0,    0,  116,    0,  142,
  143,  144,  145,  146,  147,  116,  116,    0,    0,    0,
  116,  116,  113,  113,    0,    0,    0,  113,  246,  113,
  113,  116,  113,  113,  113,  113,  113,  113,    0,  113,
  113,  254,  255,  113,  142,  143,  144,  145,  146,  147,
    0,  113,  113,    0,    0,    0,  113,  113,  114,  114,
    0,    0,    0,  114,    0,  114,  114,  113,  114,  114,
  114,  114,  114,  114,    0,  114,  114,    0,    0,  114,
    0,  196,  197,  198,  199,  200,  201,  114,  114,    0,
    0,    0,  114,  114,  115,  115,    0,    0,    0,  115,
    0,  115,  115,  114,  115,  115,  115,  115,  115,  115,
    0,  115,  115,    0,    0,  115,    0,    0,    0,    0,
    0,    0,    0,  115,  115,    0,    0,    0,  115,  115,
  112,  112,    0,    0,    0,  112,    0,  112,  112,  115,
  112,  112,  112,  112,  112,  112,  284,    0,    0,    0,
    0,  142,  143,  144,  145,  146,  147,    0,    0,  112,
  112,    0,    0,    0,  112,  112,  110,  110,    0,    0,
    0,  110,    0,  110,  110,  112,  110,  110,  110,  110,
  110,  110,  285,    0,    0,    0,    0,  142,  143,  144,
  145,  146,  147,    0,    0,  110,  110,    0,    0,    0,
  110,  110,  111,  111,    0,    0,    0,  111,    0,  111,
  111,  110,  111,  111,  111,  111,  111,  111,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  111,  111,    0,    0,    0,  111,  111,  106,  106,
    0,    0,    0,  106,    0,  106,  106,  111,  106,  106,
  106,  106,  106,  106,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  106,  106,    0,
    0,    0,  106,  106,  107,  107,    0,    0,    0,  107,
    0,  107,  107,  106,  107,  107,  107,  107,  107,  107,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  107,  107,    0,    0,    0,  107,  107,
  108,  108,    0,    0,    0,  108,    0,  108,  108,  107,
  108,  108,  108,  108,  108,  108,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  108,
  108,    0,    0,    0,  108,  108,  109,  109,    0,    0,
    0,  109,    0,  109,  109,  108,  109,  109,  109,  109,
  109,  109,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  104,    0,  109,  109,    0,    0,    0,
  109,  109,    0,    0,    0,    0,    0,    0,  105,    0,
    0,  109,  106,  107,  108,  109,   28,   29,   30,  110,
  104,  111,    0,    0,    0,   10,   31,   32,   33,   34,
    0,    0,    0,    0,    0,  105,    0,    0,    0,  106,
  107,  108,  109,   28,   29,   30,    0,    0,    0,    0,
    0,    0,   10,   31,   32,   33,   34,   28,   29,   30,
    0,    0,    0,    0,  252,    0,   10,   31,   32,   33,
   34,
};
short yycheck[] = {                                       6,
   36,  105,   38,   39,   11,  119,  170,  111,  141,   73,
   74,   18,  258,  259,  262,   22,  262,   24,  312,   26,
  314,  258,  259,  156,  261,  262,  258,  259,  257,  265,
   94,  258,  259,   40,  261,  262,  314,  282,  294,   75,
  258,  259,  298,   21,  262,  294,  258,  259,  265,  265,
  260,  265,   59,  258,  259,   62,  265,  265,  294,  314,
  305,  306,  307,   99,  100,  311,  314,  265,  172,  295,
  315,  316,  317,  318,  311,  299,  300,  294,  294,  311,
  294,   59,  261,   90,  311,  294,  294,  151,  152,  153,
  154,  311,  292,  311,  101,  295,  294,  297,  105,  311,
  299,  300,  138,  267,  111,  274,  275,  276,  277,  278,
  279,  118,  119,  227,  274,  248,  280,  250,  251,  155,
  262,  280,  158,  287,  281,  282,  104,  274,  285,  233,
  293,  294,  139,  292,  141,  298,  295,  315,  297,  294,
  309,  119,  274,  275,  276,  277,  278,  279,  297,  156,
  157,  284,  285,  148,  149,  150,  163,  283,  284,  263,
  286,  275,  288,  170,  314,  172,  298,  297,  175,  298,
  299,  298,  299,  297,  278,  298,  299,  298,  299,  157,
  298,  299,  218,  305,  306,  307,  222,  298,  299,  298,
  299,  294,  170,  315,  316,  317,  318,  314,  176,  298,
  299,  294,  263,  298,  299,  266,  213,  268,  294,  270,
  298,  299,  273,  298,  299,  298,  299,  297,  254,  255,
  227,  257,  298,  299,  299,  300,  233,  297,  289,  290,
  291,  299,  300,  298,  299,  213,  298,  299,  297,  125,
  126,  248,  297,  250,  251,  297,  224,  297,  297,  227,
  311,  312,  313,  314,  315,  297,  263,  269,  280,  300,
  267,  292,  274,  275,  276,  277,  278,  279,  275,  294,
  296,  278,  264,  280,  298,  296,  280,  284,  285,  296,
  287,  259,  274,  275,  276,  277,  278,  279,  263,  267,
  300,  266,  267,  268,  294,  270,  263,  275,  273,  266,
  297,  268,  280,  270,  294,  294,  273,  265,  280,  287,
  293,  309,  300,  300,  289,  290,  291,  294,  294,  300,
   96,  294,  289,  290,  291,  263,  102,  311,  266,  294,
  268,  311,  270,  294,  294,  273,  311,   67,  313,  314,
  315,   67,  180,  278,  311,   62,  313,  314,  315,   11,
  172,  289,  290,  291,  130,  131,  132,  133,  134,  135,
  136,  137,    8,   24,  140,   37,  163,  274,  275,  276,
  277,  278,  279,  311,  213,  313,  314,  264,  265,   -1,
   -1,   -1,  269,   -1,  271,  272,  293,  274,  275,  276,
  277,  278,  279,   -1,  281,  282,  283,  284,  285,  286,
  282,  288,   -1,   -1,   -1,  287,  293,  294,  305,  306,
  307,  298,  299,   -1,   -1,  297,   -1,  314,  315,  316,
  317,  318,  309,  305,  306,  307,  274,  275,  276,  277,
  278,  279,  314,  315,  316,  317,  318,   -1,  320,  321,
  322,  323,  324,  325,  326,  327,  264,  265,   -1,   -1,
   -1,  269,   -1,  271,  272,   -1,  274,  275,  276,  277,
  278,  279,   -1,  281,  282,   -1,   -1,  285,   -1,  274,
  275,  276,  277,  278,  279,  293,  294,   -1,   -1,   -1,
  298,  299,  264,  265,   -1,   -1,   -1,  269,  293,  271,
  272,  309,  274,  275,  276,  277,  278,  279,   -1,  281,
  282,  271,  272,  285,  274,  275,  276,  277,  278,  279,
   -1,  293,  294,   -1,   -1,   -1,  298,  299,  264,  265,
   -1,   -1,   -1,  269,   -1,  271,  272,  309,  274,  275,
  276,  277,  278,  279,   -1,  281,  282,   -1,   -1,  285,
   -1,  142,  143,  144,  145,  146,  147,  293,  294,   -1,
   -1,   -1,  298,  299,  264,  265,   -1,   -1,   -1,  269,
   -1,  271,  272,  309,  274,  275,  276,  277,  278,  279,
   -1,  281,  282,   -1,   -1,  285,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  293,  294,   -1,   -1,   -1,  298,  299,
  264,  265,   -1,   -1,   -1,  269,   -1,  271,  272,  309,
  274,  275,  276,  277,  278,  279,  269,   -1,   -1,   -1,
   -1,  274,  275,  276,  277,  278,  279,   -1,   -1,  293,
  294,   -1,   -1,   -1,  298,  299,  264,  265,   -1,   -1,
   -1,  269,   -1,  271,  272,  309,  274,  275,  276,  277,
  278,  279,  269,   -1,   -1,   -1,   -1,  274,  275,  276,
  277,  278,  279,   -1,   -1,  293,  294,   -1,   -1,   -1,
  298,  299,  264,  265,   -1,   -1,   -1,  269,   -1,  271,
  272,  309,  274,  275,  276,  277,  278,  279,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  293,  294,   -1,   -1,   -1,  298,  299,  264,  265,
   -1,   -1,   -1,  269,   -1,  271,  272,  309,  274,  275,
  276,  277,  278,  279,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  293,  294,   -1,
   -1,   -1,  298,  299,  264,  265,   -1,   -1,   -1,  269,
   -1,  271,  272,  309,  274,  275,  276,  277,  278,  279,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  293,  294,   -1,   -1,   -1,  298,  299,
  264,  265,   -1,   -1,   -1,  269,   -1,  271,  272,  309,
  274,  275,  276,  277,  278,  279,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  293,
  294,   -1,   -1,   -1,  298,  299,  264,  265,   -1,   -1,
   -1,  269,   -1,  271,  272,  309,  274,  275,  276,  277,
  278,  279,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  282,   -1,  293,  294,   -1,   -1,   -1,
  298,  299,   -1,   -1,   -1,   -1,   -1,   -1,  297,   -1,
   -1,  309,  301,  302,  303,  304,  305,  306,  307,  308,
  282,  310,   -1,   -1,   -1,  314,  315,  316,  317,  318,
   -1,   -1,   -1,   -1,   -1,  297,   -1,   -1,   -1,  301,
  302,  303,  304,  305,  306,  307,   -1,   -1,   -1,   -1,
   -1,   -1,  314,  315,  316,  317,  318,  305,  306,  307,
   -1,   -1,   -1,   -1,  312,   -1,  314,  315,  316,  317,
  318,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 327
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"TOKEN_PROGRAM","TOKEN_FUNCTION",
"TOKEN_PROCEDURE","TOKEN_CONST","TOKEN_TYPE","TOKEN_VAR","TOKEN_IF",
"TOKEN_THEN","TOKEN_ELSE","TOKEN_REPEAT","TOKEN_UNTIL","TOKEN_WHILE","TOKEN_DO",
"TOKEN_CASE","TOKEN_TO","TOKEN_DOWNTO","TOKEN_FOR","TOKEN_EQUAL",
"TOKEN_UNEQUAL","TOKEN_GE","TOKEN_GT","TOKEN_LE","TOKEN_LT","TOKEN_ASSIGN",
"TOKEN_PLUS","TOKEN_MINUS","TOKEN_MUL","TOKEN_DIV","TOKEN_OR","TOKEN_AND",
"TOKEN_NOT","TOKEN_MOD","TOKEN_READ","TOKEN_WRITE","TOKEN_WRITELN","TOKEN_LB",
"TOKEN_RB","TOKEN_SEMI","TOKEN_DOT","TOKEN_DOTDOT","TOKEN_LP","TOKEN_RP",
"TOKEN_COMMA","TOKEN_COLON","TOKEN_INTEGER_TYPE","TOKEN_BOOLEAN_TYPE",
"TOKEN_CHAR_TYPE","TOKEN_REAL_TYPE","TOKEN_TRUE","TOKEN_FALSE","TOKEN_MAXINT",
"TOKEN_ARRAY","TOKEN_OF","TOKEN_RECORD","TOKEN_BEGIN","TOKEN_END","TOKEN_GOTO",
"TOKEN_ID","TOKEN_INT","TOKEN_REAL","TOKEN_CHAR","TOKEN_STRING","ERROR",
"TOKEN_ABS","TOKEN_CHR","TOKEN_ODD","TOKEN_ORD","TOKEN_PRED","TOKEN_SQR",
"TOKEN_SQRT","TOKEN_SUCC",
};
char *yyrule[] = {
"$accept : program",
"$$1 :",
"program : TOKEN_PROGRAM TOKEN_ID $$1 TOKEN_SEMI routine TOKEN_DOT",
"routine : routine_head routine_body",
"routine_head : const_part type_part var_part routine_part",
"routine_part :",
"routine_part : routine_part function_decl",
"routine_part : routine_part procedure_decl",
"routine_part : function_decl",
"routine_part : procedure_decl",
"function_decl : function_head TOKEN_SEMI routine TOKEN_SEMI",
"$$2 :",
"function_head : TOKEN_FUNCTION TOKEN_ID $$2 parameters TOKEN_COLON simple_type_decl",
"parameters :",
"parameters : TOKEN_LP para_decl_list TOKEN_RP",
"para_decl_list : para_decl_list TOKEN_SEMI para_type_list",
"para_decl_list : para_type_list",
"para_type_list : TOKEN_VAR name_list TOKEN_COLON simple_type_decl",
"para_type_list : name_list TOKEN_COLON simple_type_decl",
"procedure_decl : procedure_head TOKEN_SEMI routine TOKEN_SEMI",
"$$3 :",
"procedure_head : TOKEN_PROCEDURE TOKEN_ID $$3 parameters",
"var_part :",
"var_part : TOKEN_VAR var_decl_list",
"var_decl_list : var_decl_list var_decl",
"var_decl_list : var_decl",
"var_decl : name_list TOKEN_COLON type_decl TOKEN_SEMI",
"const_part :",
"const_part : TOKEN_CONST const_expr_list",
"const_expr_list : const_expr_list const_expr",
"const_expr_list : const_expr",
"const_expr : ID TOKEN_EQUAL const_value TOKEN_SEMI",
"const_value : TOKEN_INT",
"const_value : TOKEN_REAL",
"const_value : TOKEN_CHAR",
"const_value : TOKEN_STRING",
"const_value : TOKEN_TRUE",
"const_value : TOKEN_FALSE",
"const_value : TOKEN_MAXINT",
"type_part :",
"type_part : TOKEN_TYPE type_decl_list",
"type_decl_list : type_decl_list type_definition",
"type_decl_list : type_definition",
"type_definition : ID TOKEN_EQUAL type_decl TOKEN_SEMI",
"type_decl : simple_type_decl",
"type_decl : array_type_decl",
"type_decl : record_type_decl",
"record_type_decl : TOKEN_RECORD field_decl_list TOKEN_END",
"field_decl_list : field_decl_list field_decl",
"field_decl_list : field_decl",
"field_decl : name_list TOKEN_COLON type_decl TOKEN_SEMI",
"array_type_decl : TOKEN_ARRAY TOKEN_LB simple_type_decl TOKEN_RB TOKEN_OF type_decl",
"simple_type_decl : ID",
"simple_type_decl : TOKEN_LP name_list TOKEN_RP",
"simple_type_decl : const_value TOKEN_DOTDOT const_value",
"simple_type_decl : TOKEN_MINUS const_value TOKEN_DOTDOT const_value",
"simple_type_decl : TOKEN_MINUS const_value TOKEN_DOTDOT TOKEN_MINUS const_value",
"simple_type_decl : ID TOKEN_DOTDOT ID",
"simple_type_decl : TOKEN_INTEGER_TYPE",
"simple_type_decl : TOKEN_BOOLEAN_TYPE",
"simple_type_decl : TOKEN_REAL_TYPE",
"simple_type_decl : TOKEN_CHAR_TYPE",
"name_list : name_list TOKEN_COMMA ID",
"name_list : ID",
"ID : TOKEN_ID",
"routine_body : compound_stmt",
"compound_stmt : TOKEN_BEGIN stmt_list TOKEN_END",
"stmt_list :",
"stmt_list : stmt_list stmt TOKEN_SEMI",
"$$4 :",
"stmt : TOKEN_INT $$4 TOKEN_COLON no_label_stmt",
"stmt : no_label_stmt",
"no_label_stmt : assign_stmt",
"no_label_stmt : compound_stmt",
"no_label_stmt : goto_stmt",
"no_label_stmt : if_stmt",
"no_label_stmt : repeat_stmt",
"no_label_stmt : while_stmt",
"no_label_stmt : case_stmt",
"no_label_stmt : for_stmt",
"no_label_stmt : proc_stmt",
"assign_stmt : ID TOKEN_ASSIGN expression",
"assign_stmt : ID TOKEN_LB expression TOKEN_RB TOKEN_ASSIGN expression",
"assign_stmt : ID TOKEN_DOT ID TOKEN_ASSIGN expression",
"goto_stmt : TOKEN_GOTO TOKEN_INT",
"if_stmt : TOKEN_IF expression TOKEN_THEN stmt else_clause",
"else_clause :",
"else_clause : TOKEN_ELSE stmt",
"repeat_stmt : TOKEN_REPEAT stmt_list TOKEN_UNTIL expression",
"repeat_stmt :",
"while_stmt : TOKEN_WHILE expression TOKEN_DO stmt",
"case_stmt : TOKEN_CASE expression TOKEN_OF case_expr_list TOKEN_END",
"case_expr_list : case_expr_list case_expr",
"case_expr_list : case_expr",
"case_expr : const_value TOKEN_COLON stmt TOKEN_SEMI",
"case_expr : ID TOKEN_COLON stmt TOKEN_SEMI",
"for_stmt : TOKEN_FOR ID TOKEN_ASSIGN expression TOKEN_TO expression TOKEN_DO stmt",
"for_stmt : TOKEN_FOR ID TOKEN_ASSIGN expression TOKEN_DOWNTO expression TOKEN_DO stmt",
"proc_stmt : ID",
"proc_stmt : ID TOKEN_LP args_list TOKEN_RP",
"proc_stmt : TOKEN_READ TOKEN_LP factor TOKEN_RP",
"proc_stmt : TOKEN_WRITE TOKEN_LP args_list TOKEN_RP",
"proc_stmt : TOKEN_WRITELN",
"proc_stmt : TOKEN_WRITELN TOKEN_LP args_list TOKEN_RP",
"args_list : args_list TOKEN_COMMA expression",
"args_list : expression",
"expression : expression TOKEN_GE expr",
"expression : expression TOKEN_GT expr",
"expression : expression TOKEN_LE expr",
"expression : expression TOKEN_LT expr",
"expression : expression TOKEN_EQUAL expr",
"expression : expression TOKEN_UNEQUAL expr",
"expression : expr",
"expr : expr TOKEN_PLUS term",
"expr : expr TOKEN_MINUS term",
"expr : expr TOKEN_OR term",
"expr : term",
"term : term TOKEN_MUL factor",
"term : term TOKEN_DIV factor",
"term : term TOKEN_MOD factor",
"term : term TOKEN_AND factor",
"term : factor",
"factor : ID",
"factor : ID TOKEN_LP args_list TOKEN_RP",
"factor : const_value",
"factor : TOKEN_LP expression TOKEN_RP",
"factor : TOKEN_NOT factor",
"factor : TOKEN_MINUS factor",
"factor : ID TOKEN_LB expression TOKEN_RB",
"factor : ID TOKEN_DOT ID",
"factor : TOKEN_ABS TOKEN_LP args_list TOKEN_RP",
"factor : TOKEN_CHR TOKEN_LP args_list TOKEN_RP",
"factor : TOKEN_ODD TOKEN_LP args_list TOKEN_RP",
"factor : TOKEN_ORD TOKEN_LP args_list TOKEN_RP",
"factor : TOKEN_PRED TOKEN_LP args_list TOKEN_RP",
"factor : TOKEN_SQR TOKEN_LP args_list TOKEN_RP",
"factor : TOKEN_SQRT TOKEN_LP args_list TOKEN_RP",
"factor : TOKEN_SUCC TOKEN_LP args_list TOKEN_RP",
};
#endif
#ifndef YYSTYPE
typedef int YYSTYPE;
#endif
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH 500
#endif
#endif
int yydebug;
int yynerrs;
int yyerrflag;
int yychar;
short *yyssp;
YYSTYPE *yyvsp;
YYSTYPE yyval;
YYSTYPE yylval;
short yyss[YYSTACKSIZE];
YYSTYPE yyvs[YYSTACKSIZE];
#define yystacksize YYSTACKSIZE
#line 629 "tiny.y"

TreeNode * parse(){
    yyparse();
    return savedTree;
}
#line 641 "y.tab.c"
#define YYABORT goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
int
yyparse()
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register char *yys;
    extern char *getenv();

    if (yys = getenv("YYDEBUG"))
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = (-1);

    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if (yyn = yydefred[yystate]) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yyssp >= yyss + yystacksize - 1)
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = (-1);
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;
#ifdef lint
    goto yynewerror;
#endif
yynewerror:
    yyerror("syntax error");
#ifdef lint
    goto yyerrlab;
#endif
yyerrlab:
    ++yynerrs;
yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yyss + yystacksize - 1)
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = (-1);
        goto yyloop;
    }
yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    yyval = yyvsp[1-yym];
    switch (yyn)
    {
case 1:
#line 38 "tiny.y"
{   savedName = copyString(tokenString); }
break;
case 2:
#line 40 "tiny.y"
{   yyval = yyvsp[-1];
                            yyval->attr.name=savedName;
                            savedTree = yyval;
                        }
break;
case 3:
#line 45 "tiny.y"
{
                            yyval = yyvsp[-1];
                            yyval->sibling=yyvsp[0];
                        }
break;
case 4:
#line 50 "tiny.y"
{
                            yyval = newDeclNode(DECL_ROUTINEHEAD);
                            yyval ->child[0]=yyvsp[-3];
                            yyval ->child[1]=yyvsp[-2];
                            yyval ->child[2]=yyvsp[-1];
                            yyval ->child[3]=yyvsp[0];
                        }
break;
case 5:
#line 58 "tiny.y"
{   yyval= NULL;}
break;
case 6:
#line 60 "tiny.y"
{   YYSTYPE t=yyvsp[-1];
                            if(t!=NULL){
                                while(t->sibling!=NULL)
                                  t=t->sibling;
                                t->sibling=yyvsp[0];
                                yyval=yyvsp[-1];
                            }
                            else
                                yyval=yyvsp[0];
                        }
break;
case 7:
#line 71 "tiny.y"
{   YYSTYPE t=yyvsp[-1];
                            if(t!=NULL){
                                while(t->sibling!=NULL)
                                  t=t->sibling;
                                t->sibling=yyvsp[0];
                                yyval=yyvsp[-1];
                            }
                            else
                                yyval=yyvsp[0];
                        }
break;
case 8:
#line 81 "tiny.y"
{yyval=yyvsp[0];}
break;
case 9:
#line 82 "tiny.y"
{yyval=yyvsp[0];}
break;
case 10:
#line 85 "tiny.y"
{
                            yyval=newDeclNode(DECL_FUNCTION);
                            yyval->child[0]=yyvsp[-3];
                            yyval->child[1]=yyvsp[-1];
                        }
break;
case 11:
#line 92 "tiny.y"
{   savedName=copyString(tokenString);}
break;
case 12:
#line 94 "tiny.y"
{
                            yyval=newDeclNode(DECL_FUNCTIONHEAD);
                            yyval->attr.name=savedName;
                            yyval->child[0]=yyvsp[-2];
                            yyval->child[1]=yyvsp[0];
                        }
break;
case 13:
#line 102 "tiny.y"
{yyval=NULL;}
break;
case 14:
#line 104 "tiny.y"
{yyval=yyvsp[-1];}
break;
case 15:
#line 107 "tiny.y"
{   YYSTYPE t=yyvsp[-2];
                            if(t!=NULL){
                                while(t->sibling!=NULL)
                                  t=t->sibling;
                                t->sibling=yyvsp[0];
                                yyval=yyvsp[-2];
                            }
                            else
                                yyval=yyvsp[0];
                        }
break;
case 16:
#line 118 "tiny.y"
{   yyval=yyvsp[0]; }
break;
case 17:
#line 121 "tiny.y"
{
                            yyval=newDeclNode(DECL_VAR_PARA);
                            yyval->child[0]=yyvsp[-2];
                            yyval->child[1]=yyvsp[0];
                        }
break;
case 18:
#line 127 "tiny.y"
{
                            yyval=newDeclNode(DECL_VAL_PARA);
                            yyval->child[0]=yyvsp[-2];
                            yyval->child[1]=yyvsp[0];
                        }
break;
case 19:
#line 134 "tiny.y"
{
                            yyval=newDeclNode(DECL_PROCEDURE);
                            yyval->child[0]=yyvsp[-3];
                            yyval->child[1]=yyvsp[-1];
                        }
break;
case 20:
#line 141 "tiny.y"
{   savedName=copyString(tokenString);}
break;
case 21:
#line 143 "tiny.y"
{   yyval=newDeclNode(DECL_PROCEDUREHEAD);
                            yyval->attr.name=savedName;
                            yyval->child[0]=yyvsp[0];
                        }
break;
case 22:
#line 149 "tiny.y"
{   yyval = NULL;}
break;
case 23:
#line 151 "tiny.y"
{   yyval=yyvsp[0];}
break;
case 24:
#line 154 "tiny.y"
{   YYSTYPE t = yyvsp[-1];
                            if(t!=NULL){
                                while(t->sibling!=NULL)
                                  t=t->sibling;
                                t->sibling=yyvsp[0];
                                yyval=yyvsp[-1];
                            }
                            else
                                yyval=yyvsp[0];
                        }
break;
case 25:
#line 164 "tiny.y"
{yyval=yyvsp[0];}
break;
case 26:
#line 167 "tiny.y"
{   yyval=newDeclNode(DECL_VAR);
                            yyval->child[0]=yyvsp[-3];
                            yyval->child[1]=yyvsp[-1];
                        }
break;
case 27:
#line 173 "tiny.y"
{   yyval = NULL; }
break;
case 28:
#line 175 "tiny.y"
{   yyval=yyvsp[0]; }
break;
case 29:
#line 178 "tiny.y"
{
                            YYSTYPE t = yyvsp[-1];
                            if(t!=NULL){
                                while(t->sibling!=NULL)
                                  t=t->sibling;
                                t->sibling = yyvsp[0];
                                yyval=yyvsp[0];
                            }
                            else
                                yyval=yyvsp[-1];
                        }
break;
case 30:
#line 191 "tiny.y"
{   yyval=yyvsp[0]; }
break;
case 31:
#line 194 "tiny.y"
{
                            yyval = newDeclNode(DECL_CONST);
                            yyval->attr.name = copyString(yyvsp[-3]->attr.name);
                            freeNode(yyvsp[-3]);
                            yyval->child[0]=yyvsp[-1];
                            yyval->type=yyvsp[-1]->type;
                        }
break;
case 32:
#line 203 "tiny.y"
{
                            yyval = newExpNode(EXP_CONST);
                            yyval->type = EXPTYPE_INT;
                            yyval->attr.val = atoi(tokenString);
                        }
break;
case 33:
#line 209 "tiny.y"
{
                            yyval = newExpNode(EXP_CONST);
                            yyval->type = EXPTYPE_REAL;
                            yyval->attr.real_val = atof(tokenString);
                        }
break;
case 34:
#line 215 "tiny.y"
{
                            yyval = newExpNode(EXP_CONST);
                            yyval->type = EXPTYPE_CHAR;
                            yyval->attr.char_val = tokenString[1];
                        }
break;
case 35:
#line 221 "tiny.y"
{
                            yyval = newExpNode(EXP_CONST);
                            yyval->type=EXPTYPE_STRING;
                            yyval->attr.string_val = (char*)malloc(strlen(tokenString)-1);
                            memmove(yyval->attr.string_val,tokenString+1,strlen(tokenString)-2);
                            yyval->attr.string_val[strlen(tokenString)-2]='\0';
                        }
break;
case 36:
#line 229 "tiny.y"
{
                            yyval=newExpNode(EXP_CONST);
                            yyval->type=EXPTYPE_BOOL;
                            yyval->attr.val=1;
                        }
break;
case 37:
#line 235 "tiny.y"
{
                            yyval=newExpNode(EXP_CONST);
                            yyval->type=EXPTYPE_BOOL;
                            yyval->attr.val=0;
                        }
break;
case 38:
#line 241 "tiny.y"
{
                            yyval=newExpNode(EXP_CONST);
                            yyval->type=EXPTYPE_INT;
                            yyval->attr.val=2147483647;
                        }
break;
case 39:
#line 248 "tiny.y"
{   yyval=NULL;}
break;
case 40:
#line 250 "tiny.y"
{   yyval=yyvsp[0];}
break;
case 41:
#line 253 "tiny.y"
{
                            YYSTYPE t=yyvsp[-1];
                            if(t!=NULL){
                                while(t->sibling!=NULL)
                                  t=t->sibling;
                                t->sibling=yyvsp[0];
                                yyval=yyvsp[-1];
                            }
                            else
                              yyval=yyvsp[0];
                        }
break;
case 42:
#line 265 "tiny.y"
{   yyval=yyvsp[0];}
break;
case 43:
#line 268 "tiny.y"
{   yyval=newDeclNode(DECL_TYPE);
                            yyval->child[0]=yyvsp[-3];
                            yyval->child[1]=yyvsp[-1];
                        }
break;
case 44:
#line 273 "tiny.y"
{yyval=yyvsp[0];}
break;
case 45:
#line 274 "tiny.y"
{yyval=yyvsp[0];}
break;
case 46:
#line 275 "tiny.y"
{yyval=yyvsp[0];}
break;
case 47:
#line 278 "tiny.y"
{   yyval=yyvsp[-1]; }
break;
case 48:
#line 281 "tiny.y"
{
                            YYSTYPE t=yyvsp[-1];
                            if(t!=NULL){
                                while(t->sibling!=NULL)
                                  t=t->sibling;
                                t->sibling=yyvsp[0];
                                yyval=yyvsp[-1];
                            }
                            else
                              yyval=yyvsp[0];
                        }
break;
case 49:
#line 292 "tiny.y"
{yyval=yyvsp[0];}
break;
case 50:
#line 295 "tiny.y"
{
                            yyval=newTypeNode(TYPE_RECORD);
                            yyval->child[0]=yyvsp[-3];
                            yyval->child[1]=yyvsp[-1];
                        }
break;
case 51:
#line 302 "tiny.y"
{
                            yyval=newTypeNode(TYPE_ARRAY);
                            yyval->child[0]=yyvsp[-3];
                            yyval->child[1]=yyvsp[0];
                            yyval->type=EXPTYPE_ARRAY;
                        }
break;
case 52:
#line 310 "tiny.y"
{
                            yyval=newTypeNode(TYPE_SIMPLE_ID);
                            yyval->attr.name = copyString(yyvsp[0]->attr.name);
                            free(yyvsp[0]);
                        }
break;
case 53:
#line 316 "tiny.y"
{   yyval=newTypeNode(TYPE_SIMPLE_ENUM);
                            yyval->child[0]=yyvsp[-1];
                            yyval->type=EXPTYPE_SIMPLE_ENUM;
                        }
break;
case 54:
#line 321 "tiny.y"
{   yyval=newTypeNode(TYPE_SIMPLE_LIMIT);
                            yyval->child[0]=yyvsp[-2];
                            yyval->child[1]=yyvsp[0];
                            yyval->type=EXPTYPE_SIMPLE_LIMIT;
                        }
break;
case 55:
#line 327 "tiny.y"
{
                            yyval=newTypeNode(TYPE_SIMPLE_LIMIT);
                            yyval->child[0]=yyvsp[-2];
                            yyval->child[0]->attr.val *= -1;
                            yyval->child[1]=yyvsp[0];
                            yyval->type=EXPTYPE_SIMPLE_LIMIT;
                        }
break;
case 56:
#line 335 "tiny.y"
{   yyval=newTypeNode(TYPE_SIMPLE_LIMIT);
                            yyval->child[0]=yyvsp[-3];
                            yyval->child[0]->attr.val *=-1;
                            yyval->child[1]=yyvsp[0];
                            yyval->child[1]->attr.val *=-1;
                            yyval->type=EXPTYPE_SIMPLE_LIMIT;
                        }
break;
case 57:
#line 343 "tiny.y"
{
                            yyval=newTypeNode(TYPE_SIMPLE_LIMIT);
                            yyval->child[0]=yyvsp[-2];
                            yyval->child[1]=yyvsp[0];
                            yyval->type=EXPTYPE_SIMPLE_LIMIT;
                        }
break;
case 58:
#line 350 "tiny.y"
{   yyval=newTypeNode(TYPE_SIMPLE_SYS);
                            yyval->type=EXPTYPE_INT;
                        }
break;
case 59:
#line 354 "tiny.y"
{   yyval=newTypeNode(TYPE_SIMPLE_SYS);
                            yyval->type=EXPTYPE_BOOL;
                        }
break;
case 60:
#line 358 "tiny.y"
{   yyval=newTypeNode(TYPE_SIMPLE_SYS);
                            yyval->type=EXPTYPE_REAL;
                        }
break;
case 61:
#line 362 "tiny.y"
{   yyval=newTypeNode(TYPE_SIMPLE_SYS);
                            yyval->type=EXPTYPE_CHAR;
                        }
break;
case 62:
#line 367 "tiny.y"
{
                            YYSTYPE t=yyvsp[-2];
                            if(t!=NULL){
                                while(t->sibling!=NULL)
                                  t=t->sibling;
                                t->sibling=yyvsp[0];
                                yyval=yyvsp[-2];
                            }
                            else
                                yyval=yyvsp[-2];
                        }
break;
case 63:
#line 378 "tiny.y"
{   yyval=yyvsp[0]; }
break;
case 64:
#line 381 "tiny.y"
{   yyval=newExpNode(EXP_ID);
                            yyval->attr.name=copyString(tokenString);
                        }
break;
case 65:
#line 384 "tiny.y"
{yyval=yyvsp[0];}
break;
case 66:
#line 385 "tiny.y"
{yyval=yyvsp[-1];}
break;
case 67:
#line 387 "tiny.y"
{yyval=NULL;}
break;
case 68:
#line 389 "tiny.y"
{
                            YYSTYPE t=yyvsp[-2];
                            if(t!=NULL){
                                while(t->sibling!=NULL)
                                  t=t->sibling;
                                t->sibling=yyvsp[-1];
                                yyval=yyvsp[-2];
                            }
                            else
                                yyval=yyvsp[-1];
                        }
break;
case 69:
#line 402 "tiny.y"
{   savedNum= atoi(tokenString);}
break;
case 70:
#line 404 "tiny.y"
{
                            yyval=newStmtNode(STMT_LABEL);
                            yyval->attr.val=savedNum;
                            yyval->child[0]=yyvsp[0];
                        }
break;
case 71:
#line 410 "tiny.y"
{   yyval=yyvsp[0];}
break;
case 72:
#line 412 "tiny.y"
{yyval=yyvsp[0];}
break;
case 73:
#line 413 "tiny.y"
{yyval=yyvsp[0];}
break;
case 74:
#line 414 "tiny.y"
{yyval=yyvsp[0];}
break;
case 75:
#line 415 "tiny.y"
{yyval=yyvsp[0];}
break;
case 76:
#line 416 "tiny.y"
{yyval=yyvsp[0];}
break;
case 77:
#line 417 "tiny.y"
{yyval=yyvsp[0];}
break;
case 78:
#line 418 "tiny.y"
{yyval=yyvsp[0];}
break;
case 79:
#line 419 "tiny.y"
{yyval=yyvsp[0];}
break;
case 80:
#line 420 "tiny.y"
{yyval=yyvsp[0];}
break;
case 81:
#line 422 "tiny.y"
{   yyval=newStmtNode(STMT_ASSIGN);
                            yyval->child[0]=yyvsp[-2];
                            yyval->child[1]=yyvsp[0];
                            yyval->attr.op=TOKEN_ID;
                        }
break;
case 82:
#line 428 "tiny.y"
{   yyval=newStmtNode(STMT_ASSIGN);
                            yyval->child[0]=yyvsp[-5];
                            (yyval->child[0])->child[0]=yyvsp[-3];
                            yyval->child[1]=yyvsp[0];
                            yyval->attr.op=TOKEN_ARRAY;
                        }
break;
case 83:
#line 436 "tiny.y"
{   yyval=newStmtNode(STMT_ASSIGN);
                            yyval->child[0]=yyvsp[-4];
                            (yyval->child[0])->child[0]=yyvsp[-2];
                            yyval->child[1]=yyvsp[0];
                            yyval->attr.op=TOKEN_RECORD;
                        }
break;
case 84:
#line 444 "tiny.y"
{   yyval=newStmtNode(STMT_GOTO);
                            yyval->attr.val=atoi(tokenString);
                        }
break;
case 85:
#line 449 "tiny.y"
{   yyval=newStmtNode(STMT_IF);
                            yyval->child[0]=yyvsp[-3];
                            yyval->child[1]=yyvsp[-1];
                            yyval->child[2]=yyvsp[0];
                        }
break;
case 86:
#line 455 "tiny.y"
{yyval=NULL;}
break;
case 87:
#line 456 "tiny.y"
{yyval=yyvsp[0];}
break;
case 88:
#line 459 "tiny.y"
{
                            yyval=newStmtNode(STMT_REPEAT);
                            yyval->child[0]=yyvsp[-2];
                            yyval->child[1]=yyvsp[0];
                        }
break;
case 90:
#line 466 "tiny.y"
{   yyval=newStmtNode(STMT_WHILE);
                            yyval->child[0]=yyvsp[-2];
                            yyval->child[1]=yyvsp[0];
                        }
break;
case 91:
#line 471 "tiny.y"
{   yyval=newStmtNode(STMT_CASE);
                            yyval->child[0]=yyvsp[-3];
                            yyval->child[1]=yyvsp[-1];
                        }
break;
case 92:
#line 476 "tiny.y"
{   YYSTYPE t=yyvsp[-1];
                            if(t!=NULL){
                                while(t->sibling!=NULL)
                                  t=t->sibling;
                                t->sibling=yyvsp[0];
                                yyval=yyvsp[-1];
                            }
                            else
                                yyval=yyvsp[0];
                        }
break;
case 93:
#line 486 "tiny.y"
{yyval=yyvsp[0];}
break;
case 94:
#line 488 "tiny.y"
{
                            yyval=newExpNode(EXP_CASE);
                            yyval->child[0]=yyvsp[-3];
                            yyval->child[1]=yyvsp[-1];
                        }
break;
case 95:
#line 494 "tiny.y"
{
                            yyval=newExpNode(EXP_CASE);
                            yyval->child[0]=yyvsp[-3];
                            yyval->child[1]=yyvsp[-1];
                        }
break;
case 96:
#line 500 "tiny.y"
{
                            yyval=newStmtNode(STMT_FOR);
                            yyval->child[0]=yyvsp[-6];
                            yyval->child[1]=yyvsp[-4];
                            yyval->child[2]=yyvsp[-2];
                            yyval->child[3]=yyvsp[0];
                            yyval->attr.op=TOKEN_TO;
                        }
break;
case 97:
#line 509 "tiny.y"
{
                            yyval=newStmtNode(STMT_FOR);
                            yyval->child[0]=yyvsp[-6];
                            yyval->child[1]=yyvsp[-4];
                            yyval->child[2]=yyvsp[-2];
                            yyval->child[3]=yyvsp[0];
                            yyval->attr.op=TOKEN_DOWNTO;
                        }
break;
case 98:
#line 518 "tiny.y"
{   yyval=newStmtNode(STMT_PROC_ID);
                            yyval->attr.name=copyString(yyvsp[0]->attr.name);
                        }
break;
case 99:
#line 522 "tiny.y"
{   yyval=newStmtNode(STMT_PROC_ID);
                            yyval->attr.name=copyString(yyvsp[-3]->attr.name);
                            yyval->child[0]=yyvsp[-1];
                        }
break;
case 100:
#line 527 "tiny.y"
{
                            yyval=newStmtNode(STMT_PROC_SYS);
                            yyval->attr.op=TOKEN_READ;
                            yyval->child[0]=yyvsp[-1];
                        }
break;
case 101:
#line 533 "tiny.y"
{   yyval=newStmtNode(STMT_PROC_SYS);
                            yyval->attr.op=TOKEN_WRITE;
                            yyval->child[0]=yyvsp[-1];
                        }
break;
case 102:
#line 538 "tiny.y"
{   yyval=newStmtNode(STMT_PROC_SYS);
                            yyval->attr.op=TOKEN_WRITELN;
                        }
break;
case 103:
#line 542 "tiny.y"
{   yyval=newStmtNode(STMT_PROC_SYS);
                            yyval->attr.op=TOKEN_WRITELN;
                            yyval->child[0]=yyvsp[-1];
                        }
break;
case 104:
#line 547 "tiny.y"
{   YYSTYPE t=yyvsp[-2];
                            if(t!=NULL){
                                while(t->sibling!=NULL)
                                  t=t->sibling;
                                t->sibling=yyvsp[0];
                                yyval=yyvsp[-2];
                            }
                            else
                                yyval=yyvsp[0];
                        }
break;
case 105:
#line 557 "tiny.y"
{yyval=yyvsp[0];}
break;
case 106:
#line 559 "tiny.y"
{   yyval=newOpExpNode(yyvsp[-2],yyvsp[0],TOKEN_GE); }
break;
case 107:
#line 560 "tiny.y"
{   yyval=newOpExpNode(yyvsp[-2],yyvsp[0],TOKEN_GT); }
break;
case 108:
#line 561 "tiny.y"
{   yyval=newOpExpNode(yyvsp[-2],yyvsp[0],TOKEN_LE); }
break;
case 109:
#line 562 "tiny.y"
{   yyval=newOpExpNode(yyvsp[-2],yyvsp[0],TOKEN_LT); }
break;
case 110:
#line 563 "tiny.y"
{   yyval=newOpExpNode(yyvsp[-2],yyvsp[0],TOKEN_EQUAL); }
break;
case 111:
#line 564 "tiny.y"
{   yyval=newOpExpNode(yyvsp[-2],yyvsp[0],TOKEN_UNEQUAL); }
break;
case 112:
#line 565 "tiny.y"
{   yyval=yyvsp[0];}
break;
case 113:
#line 567 "tiny.y"
{   yyval=newOpExpNode(yyvsp[-2],yyvsp[0],TOKEN_PLUS); }
break;
case 114:
#line 568 "tiny.y"
{   yyval=newOpExpNode(yyvsp[-2],yyvsp[0],TOKEN_MINUS); }
break;
case 115:
#line 569 "tiny.y"
{   yyval=newOpExpNode(yyvsp[-2],yyvsp[0],TOKEN_OR); }
break;
case 116:
#line 570 "tiny.y"
{   yyval=yyvsp[0];}
break;
case 117:
#line 572 "tiny.y"
{   yyval=newOpExpNode(yyvsp[-2],yyvsp[0],TOKEN_MUL); }
break;
case 118:
#line 573 "tiny.y"
{   yyval=newOpExpNode(yyvsp[-2],yyvsp[0],TOKEN_DIV); }
break;
case 119:
#line 574 "tiny.y"
{   yyval=newOpExpNode(yyvsp[-2],yyvsp[0],TOKEN_MOD); }
break;
case 120:
#line 575 "tiny.y"
{   yyval=newOpExpNode(yyvsp[-2],yyvsp[0],TOKEN_AND); }
break;
case 121:
#line 576 "tiny.y"
{yyval=yyvsp[0];}
break;
case 122:
#line 579 "tiny.y"
{yyval=yyvsp[0];}
break;
case 123:
#line 581 "tiny.y"
{   yyval=newExpNode(EXP_FUNC_ID);
                            yyval->attr.name=copyString(yyvsp[-3]->attr.name);
                            yyval->child[0]=yyvsp[-1];
                        }
break;
case 124:
#line 585 "tiny.y"
{yyval=yyvsp[0];}
break;
case 125:
#line 586 "tiny.y"
{yyval=yyvsp[-1];}
break;
case 126:
#line 588 "tiny.y"
{   yyval=newOpExpNode(yyvsp[0],NULL,TOKEN_NOT);
                        }
break;
case 127:
#line 591 "tiny.y"
{   yyval=newOpExpNode(yyvsp[0],NULL,TOKEN_MINUS);
                        }
break;
case 128:
#line 594 "tiny.y"
{   yyval=yyvsp[-3];
                            yyval->child[0]=yyvsp[-1];
                            yyval->type=EXPTYPE_ARRAY;
                        }
break;
case 129:
#line 599 "tiny.y"
{   yyval=yyvsp[-2];
                            yyval->child[0]=yyvsp[0];
                            yyval->type=EXPTYPE_RECORD;
                        }
break;
case 130:
#line 604 "tiny.y"
{   yyval=newFuncSysExpNode(TOKEN_ABS,yyvsp[-1]);
                        }
break;
case 131:
#line 607 "tiny.y"
{   yyval=newFuncSysExpNode(TOKEN_CHR,yyvsp[-1]);
                        }
break;
case 132:
#line 610 "tiny.y"
{   yyval=newFuncSysExpNode(TOKEN_ODD,yyvsp[-1]);
                        }
break;
case 133:
#line 613 "tiny.y"
{   yyval=newFuncSysExpNode(TOKEN_ORD,yyvsp[-1]);
                        }
break;
case 134:
#line 616 "tiny.y"
{   yyval=newFuncSysExpNode(TOKEN_PRED,yyvsp[-1]);
                        }
break;
case 135:
#line 619 "tiny.y"
{   yyval=newFuncSysExpNode(TOKEN_SQR,yyvsp[-1]);
                        }
break;
case 136:
#line 622 "tiny.y"
{   yyval=newFuncSysExpNode(TOKEN_SQRT,yyvsp[-1]);
                        }
break;
case 137:
#line 625 "tiny.y"
{   yyval=newFuncSysExpNode(TOKEN_SUCC,yyvsp[-1]);
                        }
break;
#line 1647 "y.tab.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yyssp, yystate);
#endif
    if (yyssp >= yyss + yystacksize - 1)
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;
yyoverflow:
    yyerror("yacc stack overflow");
yyabort:
    return (1);
yyaccept:
    return (0);
}
