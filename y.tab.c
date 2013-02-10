#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20120115

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "piyush.y"
#include <stdio.h>
#include <stdlib.h>
struct node {
	int TYPE;			/* Integer (1), Boolean (2) or Void (3) (for statements) */
					/* Must point to the type expression tree for user defined types */
	int NODETYPE;			/* this field should carry following information:
					* a) operator : (+,*,/ etc.) for expressions
					* b) statement Type : (WHILE, READ etc.) for statements
					* c) else 0
					*/
	int VALUE;			/* for constants */
	char* NAME;			/* For Identifiers */
	struct	node	*center, *next,	*left,	*right;
};

struct node* CreateNode(int TYPE1, int NODETYPE1, int VALUE1, char* NAME1, struct node *ptr1, struct node *ptr2, struct node *ptr3, struct node *ptr4);
#line 20 "piyush.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	struct node* n;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 47 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define DECL 257
#define ENDDECL 258
#define SEMICOLON 259
#define COMMA 260
#define INTEGER 261
#define BOOLEAN 262
#define ID 263
#define LSQUARE 264
#define RSQUARE 265
#define TRUE 266
#define FALSE 267
#define ADDRESSOF 268
#define MODULUS 269
#define AND 270
#define OR 271
#define NOT 272
#define READ 273
#define WRITE 274
#define IF 275
#define ENDIF 276
#define THEN 277
#define ELSE 278
#define WHILE 279
#define NUMBER 280
#define EQUAL 281
#define ASSIGN 282
#define NEQUAL 283
#define LESS_THAN 284
#define LESS_EQUAL 285
#define GREATER_THAN 286
#define GREATER_EQ 287
#define PLUS 288
#define MINUS 289
#define MULT 290
#define DIVIDE 291
#define LPAREN 292
#define RPAREN 293
#define RFLOWER 294
#define LFLOWER 295
#define DO 296
#define ENDWHILE 297
#define BEGINN 298
#define END 299
#define RETURN 300
#define MAIN 301
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,   15,   16,   16,   17,   19,   19,   18,   18,   20,
   20,    1,    2,   21,   22,   22,   23,   24,   24,   25,
   25,    3,    4,    4,    5,    5,    5,    5,    5,    6,
    6,    7,   14,   14,    8,    8,    9,   10,   11,   11,
   11,   11,   11,   11,   11,   11,   12,   12,   12,   12,
   12,   12,   12,   12,   12,   13,   13,   13,   13,   13,
   13,   13,   13,   13,   13,   13,   13,
};
static const short yylen[] = {                            2,
    2,    3,    0,    2,    3,    1,    3,    1,    1,    1,
    4,    7,    2,    3,    0,    2,    3,    1,    3,    1,
    4,    4,    0,    2,    1,    1,    1,    1,    1,    6,
    8,    6,    4,    7,    5,    8,    5,    3,    3,    3,
    3,    3,    3,    3,    1,    1,    3,    3,    3,    3,
    3,    3,    1,    1,    4,    3,    3,    3,    3,    3,
    3,    3,    3,    2,    3,    1,    1,
};
static const short yydefred[] = {                         0,
    3,    0,    0,    0,    0,    1,    2,    8,    9,    4,
    0,    0,    0,    0,    6,    0,    0,    5,    0,    0,
    0,    7,    0,   11,   15,    0,    0,    0,   12,   23,
   13,   14,    0,   16,    0,    0,    0,   18,    0,    0,
    0,    0,    0,    0,   24,   25,   26,   27,   28,    0,
   29,    0,   17,    0,    0,    0,    0,    0,    0,   66,
   67,    0,   53,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   22,    0,    0,   19,    0,    0,    0,    0,
    0,   64,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   23,   23,    0,
   38,    0,    0,    0,    0,    0,    0,   21,    0,   33,
    0,    0,    0,    0,   52,   65,   51,    0,    0,    0,
    0,    0,    0,    0,    0,   49,   50,   62,   63,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   35,
   37,   55,    0,   23,    0,    0,    0,   30,    0,   32,
   34,    0,    0,   36,   31,
};
static const short yydgoto[] = {                          2,
    6,   26,   31,   35,   45,   46,   47,   48,   49,   50,
   70,   65,   72,   51,    3,    4,   10,   11,   14,   15,
   27,   28,   34,   37,   38,
};
static const short yysindex[] = {                      -252,
    0,    0, -251, -180, -286,    0,    0,    0,    0,    0,
 -244, -269, -233, -189,    0, -257, -241,    0, -244, -216,
 -178,    0, -167,    0,    0, -201, -188,  -67,    0,    0,
    0,    0, -166,    0, -247, -140, -183,    0, -209, -164,
 -162,   64,   64,   66,    0,    0,    0,    0,    0, -187,
    0, -259,    0, -166, -259,   66, -137, -259, -126,    0,
    0,   64,    0,   64,  140, -202, -207,    0,   64, -119,
  163, -148,    0, -259, -109,    0,   72, -110, -255,  -59,
 -259,    0,   95, -253, -259, -259, -259, -259, -259, -259,
 -259, -259, -259, -259, -259,   64,   64,    0,    0,  106,
    0, -259, -259, -259, -259, -259,  129,    0, -107,    0,
 -259,  -97,  -81,   78,    0,    0,    0, -174, -174, -174,
 -174, -174, -174, -256, -256,    0,    0,    0,    0,  137,
  -61,    0,    0, -256, -256,    0,    0,   66,   83,    0,
    0,    0,  -62,    0,  -58,  -56,  -93,    0, -121,    0,
    0,  -52,  -42,    0,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -112,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -71,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -185,    0,
    0,    0,    0,    0,    0,    0,    0,  -43,    0,    0,
    0,  -39,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -205, -150, -100,
  -87,  -85,  -72, -152, -120,    0,    0,    0,    0,    0,
    0,  -32,   -9,   14,   37,    2,   25,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
    0,    0,    0,  -92,    0,    0,    0,    0,    0,    0,
  -55,  -44,  -40,    0,    0,    0,    0,  176,    0,  196,
    0,    0,    0,    0,  165,
};
#define YYTABLESIZE 454
static const short yytable[] = {                         71,
   78,   66,   67,   59,    1,  130,  131,   75,  111,    5,
   77,   71,   85,   80,   12,   39,   96,   97,   13,   83,
   63,   82,   16,   84,  100,   40,   41,   42,   84,  107,
   17,   43,   74,   94,   95,   20,  114,  112,   21,  116,
  117,  118,  119,  120,  121,  122,  123,  124,  125,  126,
  127,  149,   44,   56,   55,  128,  129,  133,  134,  135,
  136,  137,   96,   97,   56,   56,  139,   96,   97,   18,
   19,   56,   56,   54,   98,   53,   54,    7,   23,   54,
    8,    9,  146,   54,   54,   54,   24,   56,   99,   25,
   56,   54,   29,   71,   85,   54,   36,   54,   54,   54,
   54,   54,   54,   54,   54,   54,   47,   54,   61,   30,
   54,   73,   47,   92,   93,   94,   95,   47,   47,   61,
   61,   96,   97,   52,   47,   79,   61,   57,   47,   58,
   47,   47,   47,   47,   47,   47,   47,   81,   48,  101,
   47,   39,   61,   47,   48,   61,   10,   10,  110,   48,
   48,   40,   41,   42,  153,  108,   48,   43,   57,   85,
   48,  140,   48,   48,   48,   48,   48,   48,   48,   57,
   57,   60,   48,   58,  138,   48,   57,  141,   92,   93,
   94,   95,   60,   60,   58,   58,   59,   20,   20,   60,
   32,   58,   57,    8,    9,   57,  148,   59,   59,  152,
  150,   39,  151,   33,   59,   60,  154,   58,   60,   85,
   58,   40,   41,   42,   22,   45,  155,   43,   76,   46,
   59,    0,    0,   59,    0,   53,   44,    0,   92,   93,
   94,   95,    0,  113,    0,  145,   52,   53,    0,   53,
   53,   53,   53,   53,   53,   53,   53,   53,   52,   43,
   52,   52,   52,   52,   52,   52,   52,   52,   52,   51,
   41,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   49,   51,   39,   51,   51,   51,   51,   51,   51,   51,
   51,   51,   49,   42,   49,   49,   49,   49,   49,   49,
   49,   49,   49,   50,   47,   40,   47,   47,   47,   47,
   47,   47,   47,    0,    0,   50,    0,   50,   50,   50,
   50,   50,   50,   50,   50,   50,    0,   48,    0,   48,
   48,   48,   48,   48,   48,   48,   59,    0,   59,   60,
   61,   60,   61,    0,    0,   62,  109,   62,    0,    0,
   85,    0,  142,   63,    0,   68,   85,  147,    0,    0,
    0,   85,    0,    0,    0,   64,    0,   69,    0,   92,
   93,   94,   95,   85,    0,   92,   93,   94,   95,    0,
   92,   93,   94,   95,   85,   86,    0,   87,   88,   89,
   90,   91,   92,   93,   94,   95,   86,  115,   87,   88,
   89,   90,   91,   92,   93,   94,   95,   85,  132,   39,
    0,    0,    0,    0,    0,    0,    0,    0,   85,   40,
   41,   42,  143,    0,  144,   43,   92,   93,   94,   95,
   86,  115,   87,   88,   89,   90,   91,   92,   93,   94,
   95,  102,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   86,    0,   87,   88,   89,   90,   91,
  103,  104,  105,  106,
};
static const short yycheck[] = {                         44,
   56,   42,   43,  263,  257,   98,   99,   52,  264,  261,
   55,   56,  269,   58,  301,  263,  270,  271,  263,   64,
  280,   62,  292,   64,   69,  273,  274,  275,   69,   74,
  264,  279,  292,  290,  291,  293,   81,  293,  280,  293,
   85,   86,   87,   88,   89,   90,   91,   92,   93,   94,
   95,  144,  300,  259,  264,   96,   97,  102,  103,  104,
  105,  106,  270,  271,  270,  271,  111,  270,  271,  259,
  260,  277,  282,  259,  277,  259,  260,  258,  295,  265,
  261,  262,  138,  269,  270,  271,  265,  293,  296,  257,
  296,  277,  294,  138,  269,  281,  263,  283,  284,  285,
  286,  287,  288,  289,  290,  291,  259,  293,  259,  298,
  296,  299,  265,  288,  289,  290,  291,  270,  271,  270,
  271,  270,  271,  264,  277,  263,  277,  292,  281,  292,
  283,  284,  285,  286,  287,  288,  289,  264,  259,  259,
  293,  263,  293,  296,  265,  296,  259,  260,  259,  270,
  271,  273,  274,  275,  276,  265,  277,  279,  259,  269,
  281,  259,  283,  284,  285,  286,  287,  288,  289,  270,
  271,  259,  293,  259,  282,  296,  277,  259,  288,  289,
  290,  291,  270,  271,  270,  271,  259,  259,  260,  277,
  258,  277,  293,  261,  262,  296,  259,  270,  271,  293,
  259,  263,  259,   28,  277,  293,  259,  293,  296,  269,
  296,  273,  274,  275,   19,  259,  259,  279,   54,  259,
  293,   -1,   -1,  296,   -1,  269,  259,   -1,  288,  289,
  290,  291,   -1,  293,   -1,  297,  269,  281,   -1,  283,
  284,  285,  286,  287,  288,  289,  290,  291,  281,  259,
  283,  284,  285,  286,  287,  288,  289,  290,  291,  269,
  259,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  269,  281,  259,  283,  284,  285,  286,  287,  288,  289,
  290,  291,  281,  259,  283,  284,  285,  286,  287,  288,
  289,  290,  291,  269,  281,  259,  283,  284,  285,  286,
  287,  288,  289,   -1,   -1,  281,   -1,  283,  284,  285,
  286,  287,  288,  289,  290,  291,   -1,  281,   -1,  283,
  284,  285,  286,  287,  288,  289,  263,   -1,  263,  266,
  267,  266,  267,   -1,   -1,  272,  265,  272,   -1,   -1,
  269,   -1,  265,  280,   -1,  280,  269,  265,   -1,   -1,
   -1,  269,   -1,   -1,   -1,  292,   -1,  292,   -1,  288,
  289,  290,  291,  269,   -1,  288,  289,  290,  291,   -1,
  288,  289,  290,  291,  269,  281,   -1,  283,  284,  285,
  286,  287,  288,  289,  290,  291,  281,  293,  283,  284,
  285,  286,  287,  288,  289,  290,  291,  269,  293,  263,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  269,  273,
  274,  275,  276,   -1,  278,  279,  288,  289,  290,  291,
  281,  293,  283,  284,  285,  286,  287,  288,  289,  290,
  291,  269,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  281,   -1,  283,  284,  285,  286,  287,
  288,  289,  290,  291,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 301
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"DECL","ENDDECL","SEMICOLON",
"COMMA","INTEGER","BOOLEAN","ID","LSQUARE","RSQUARE","TRUE","FALSE","ADDRESSOF",
"MODULUS","AND","OR","NOT","READ","WRITE","IF","ENDIF","THEN","ELSE","WHILE",
"NUMBER","EQUAL","ASSIGN","NEQUAL","LESS_THAN","LESS_EQUAL","GREATER_THAN",
"GREATER_EQ","PLUS","MINUS","MULT","DIVIDE","LPAREN","RPAREN","RFLOWER",
"LFLOWER","DO","ENDWHILE","BEGINN","END","RETURN","MAIN",
};
static const char *yyrule[] = {
"$accept : program",
"program : Gdeclaration main_function",
"Gdeclaration : DECL GdeclStatements ENDDECL",
"GdeclStatements :",
"GdeclStatements : GdeclStatements GdeclStatement",
"GdeclStatement : type Gvars SEMICOLON",
"Gvars : Gvar",
"Gvars : Gvars COMMA Gvar",
"type : INTEGER",
"type : BOOLEAN",
"Gvar : ID",
"Gvar : ID LSQUARE NUMBER RSQUARE",
"main_function : INTEGER MAIN LPAREN RPAREN LFLOWER fbody RFLOWER",
"fbody : declaration beginbody",
"declaration : DECL declStatements ENDDECL",
"declStatements :",
"declStatements : declStatements declStatement",
"declStatement : type vars SEMICOLON",
"vars : var",
"vars : vars COMMA var",
"var : ID",
"var : ID LSQUARE aexpression RSQUARE",
"beginbody : BEGINN statements return END",
"statements :",
"statements : statements statement",
"statement : ifelse",
"statement : dowhile",
"statement : read",
"statement : write",
"statement : astatement",
"ifelse : IF lexpression THEN statements ENDIF SEMICOLON",
"ifelse : IF lexpression THEN statements ELSE statements ENDIF SEMICOLON",
"dowhile : WHILE lexpression DO statements ENDWHILE SEMICOLON",
"astatement : ID ASSIGN expression SEMICOLON",
"astatement : ID LSQUARE aexpression RSQUARE ASSIGN expression SEMICOLON",
"read : READ LPAREN ID RPAREN SEMICOLON",
"read : READ LPAREN ID LSQUARE aexpression RSQUARE RPAREN SEMICOLON",
"write : WRITE LPAREN aexpression RPAREN SEMICOLON",
"return : RETURN expression SEMICOLON",
"expression : aexpression PLUS aexpression",
"expression : aexpression MINUS aexpression",
"expression : aexpression MULT aexpression",
"expression : aexpression DIVIDE aexpression",
"expression : aexpression MODULUS aexpression",
"expression : LPAREN aexpression RPAREN",
"expression : NUMBER",
"expression : lexpression",
"aexpression : aexpression PLUS aexpression",
"aexpression : aexpression MINUS aexpression",
"aexpression : aexpression MULT aexpression",
"aexpression : aexpression DIVIDE aexpression",
"aexpression : aexpression MODULUS aexpression",
"aexpression : LPAREN aexpression RPAREN",
"aexpression : NUMBER",
"aexpression : ID",
"aexpression : ID LSQUARE aexpression RSQUARE",
"lexpression : aexpression EQUAL aexpression",
"lexpression : aexpression LESS_THAN aexpression",
"lexpression : aexpression GREATER_THAN aexpression",
"lexpression : aexpression GREATER_EQ aexpression",
"lexpression : aexpression LESS_EQUAL aexpression",
"lexpression : aexpression NEQUAL aexpression",
"lexpression : lexpression AND lexpression",
"lexpression : lexpression OR lexpression",
"lexpression : NOT lexpression",
"lexpression : LPAREN lexpression RPAREN",
"lexpression : TRUE",
"lexpression : FALSE",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 160 "piyush.y"

int main(){
	return(yyparse());
}

yyerror(s)
char *s;
{
  fprintf(stderr, "%s\n",s);
}



void printTree(struct node* root){
	if(root==NULL) {
		return;
	}
	switch(root->TYPE){
		case 0 :
			switch(root->NODETYPE ) {
				case 'f' :
					printf("( ");
					printf("%s",root->NAME);
					break;
				case 'I' :
					printf("( ");
					printf("%s","IF");
					break;
				case 'W' :
					printf("( ");
					printf("%s","WHILE");
					break;
				case 'r' :
					printf("( ");
					printf("%s","READ");
					break;
				case 'w' :
					printf("( ");
					printf("%s","WRITE");
					break;
				case 'R' :
					printf("( ");
					printf("%s","RETURN");
					break;
				case '+' :
					printf("( ");
					printf("%c",'+');
					break;
				case '-' :
					printf("( ");
					printf("%c",'-');
					break;
				case '*' :
					printf("( ");
					printf("%c",'*');
					break;
				case '/' :
					printf("( ");
					printf("%c",'/');
					break;
				case '%' :
					printf("( ");
					printf("%c",'%');
					break;
				case 'T' :
					printf("( ");
					printf("%c",'T');
					break;
				case 'F' :
					printf("( ");
					printf("%c",'F');
					break;
				case '&' :
					printf("( ");
					printf("%c",'&');
					break;
				case '|' :
					printf("( ");
					printf("%c",'|');
					break;
				case '!' :
					printf("( ");
					printf("%c",'!');
					break;
				case 'G' :
					printf("( ");
					printf("%c%c",'>','=');
					break;
				case 'L' :
					printf("( ");
					printf("%c%c",'<','=');
					break;
				case '>' :
					printf("( ");
					printf("%c",'>');
					break;
				case '<' :
					printf("( ");
					printf("%c",'<');
					break;
				case 'E' :
					printf("( ");
					printf("%c%c",'=','=');
					break;
				case 'N' :
					printf("( ");
					printf("%c%c",'!','=');
					break;
				case '=' :
					printf("( ");
					printf("%c",'=');
					break;
				default:
					break;

			}
			break;
		case 1:
			printf("( ");
			printf("%d",root->VALUE);
			break;
		case 2:
			printf("( ");
			printf("%s",root->NAME);
			break;
	}
		printTree(root->left);

		printTree(root->center);

		printTree(root->right);
	if(root->next!=NULL){
		printf(")");
		printf("\n");
		printTree(root->next);}
	else{
	printf(" ");
	printf(")");}

}
#line 573 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = data->s_mark - data->s_base;
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
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
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
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

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
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
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 48 "piyush.y"
	{ printf("PARSING SUCCESS\n"); yyval.n=yystack.l_mark[0].n; printTree(yystack.l_mark[0].n);}
break;
case 12:
#line 68 "piyush.y"
	{ yyval.n=CreateNode(0,'f', 0, "MAIN", NULL, yystack.l_mark[-1].n, NULL, NULL);}
break;
case 13:
#line 71 "piyush.y"
	{ yyval.n=yystack.l_mark[0].n; }
break;
case 22:
#line 89 "piyush.y"
	{  yyval.n=CreateNode(0,0, 0, NULL, NULL, yystack.l_mark[-1].n, NULL, yystack.l_mark[-2].n);}
break;
case 23:
#line 92 "piyush.y"
	{ yyval.n = NULL; }
break;
case 24:
#line 93 "piyush.y"
	{  yyval.n=CreateNode(0,0, 0, NULL, yystack.l_mark[-1].n, NULL, NULL, yystack.l_mark[0].n); }
break;
case 25:
#line 96 "piyush.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 26:
#line 97 "piyush.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 27:
#line 98 "piyush.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 28:
#line 99 "piyush.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 29:
#line 100 "piyush.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 30:
#line 103 "piyush.y"
	{ yystack.l_mark[-5].n = CreateNode(0,24, 0, NULL, yystack.l_mark[-2].n, yystack.l_mark[-4].n, NULL, NULL); yyval.n = yystack.l_mark[-5].n; }
break;
case 31:
#line 104 "piyush.y"
	{ yystack.l_mark[-7].n = CreateNode(0,'I', 0, NULL, yystack.l_mark[-4].n, yystack.l_mark[-6].n, yystack.l_mark[-2].n, NULL); yyval.n = yystack.l_mark[-7].n; }
break;
case 32:
#line 107 "piyush.y"
	{ yystack.l_mark[-5].n = CreateNode(0,'W', 0, NULL, yystack.l_mark[-4].n, yystack.l_mark[-4].n, NULL, NULL); yyval.n=yystack.l_mark[-5].n; }
break;
case 33:
#line 110 "piyush.y"
	{ yystack.l_mark[-2].n = CreateNode(0,'=', 0, NULL, yystack.l_mark[-3].n, NULL, yystack.l_mark[-1].n, NULL); yyval.n=yystack.l_mark[-2].n; }
break;
case 34:
#line 111 "piyush.y"
	{ yystack.l_mark[-6].n->center = yystack.l_mark[-5].n; yystack.l_mark[-2].n = CreateNode(0,'=', 0, NULL, yystack.l_mark[-6].n, NULL, yystack.l_mark[-4].n, NULL); yyval.n=yystack.l_mark[-2].n;  }
break;
case 35:
#line 114 "piyush.y"
	{ yystack.l_mark[-4].n = CreateNode(0,'r', 0, NULL, NULL, yystack.l_mark[-2].n, NULL, NULL); yyval.n = yystack.l_mark[-4].n; }
break;
case 36:
#line 115 "piyush.y"
	{ yystack.l_mark[-5].n->center = yystack.l_mark[-3].n;  yystack.l_mark[-7].n = CreateNode(0,'r', 0, NULL, NULL, yystack.l_mark[-5].n, NULL, NULL); yyval.n = yystack.l_mark[-7].n; }
break;
case 37:
#line 118 "piyush.y"
	{ yystack.l_mark[-4].n = CreateNode(0,'w', 0, NULL, NULL, yystack.l_mark[-2].n, NULL, NULL); yyval.n = yystack.l_mark[-4].n; }
break;
case 38:
#line 121 "piyush.y"
	{ yystack.l_mark[-2].n = CreateNode(0,'R', 0, NULL, NULL, yystack.l_mark[-1].n, NULL, NULL); yyval.n = yystack.l_mark[-2].n; }
break;
case 39:
#line 124 "piyush.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'+', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n, NULL); yyval.n = yystack.l_mark[-1].n; }
break;
case 40:
#line 125 "piyush.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'-', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n, NULL); yyval.n = yystack.l_mark[-1].n; }
break;
case 41:
#line 126 "piyush.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'*', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n, NULL); yyval.n = yystack.l_mark[-1].n; }
break;
case 42:
#line 127 "piyush.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'/', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n, NULL); yyval.n = yystack.l_mark[-1].n; }
break;
case 43:
#line 128 "piyush.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'%', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n, NULL); yyval.n = yystack.l_mark[-1].n; }
break;
case 44:
#line 129 "piyush.y"
	{ yyval.n=yystack.l_mark[-1].n; }
break;
case 45:
#line 130 "piyush.y"
	{ yyval.n=yystack.l_mark[0].n; }
break;
case 46:
#line 131 "piyush.y"
	{ yyval.n=yystack.l_mark[0].n; }
break;
case 47:
#line 134 "piyush.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'+', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n, NULL); yyval.n = yystack.l_mark[-1].n; }
break;
case 48:
#line 135 "piyush.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'-', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n, NULL); yyval.n = yystack.l_mark[-1].n; }
break;
case 49:
#line 136 "piyush.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'*', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n, NULL); yyval.n = yystack.l_mark[-1].n; }
break;
case 50:
#line 137 "piyush.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'/', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n, NULL); yyval.n = yystack.l_mark[-1].n; }
break;
case 51:
#line 138 "piyush.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'%', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n, NULL); yyval.n = yystack.l_mark[-1].n; }
break;
case 52:
#line 139 "piyush.y"
	{ yyval.n = yystack.l_mark[-1].n; }
break;
case 53:
#line 140 "piyush.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 54:
#line 141 "piyush.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 55:
#line 142 "piyush.y"
	{   yystack.l_mark[-3].n->center = yystack.l_mark[-1].n; yyval.n = yystack.l_mark[-3].n;}
break;
case 56:
#line 145 "piyush.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'E', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n, NULL); yyval.n = yystack.l_mark[-1].n; }
break;
case 57:
#line 146 "piyush.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'<', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n, NULL); yyval.n = yystack.l_mark[-1].n; }
break;
case 58:
#line 147 "piyush.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'>', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n, NULL); yyval.n = yystack.l_mark[-1].n; }
break;
case 59:
#line 148 "piyush.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'G', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n, NULL); yyval.n = yystack.l_mark[-1].n; }
break;
case 60:
#line 149 "piyush.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'L', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n, NULL); yyval.n = yystack.l_mark[-1].n; }
break;
case 61:
#line 150 "piyush.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'N', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n, NULL); yyval.n = yystack.l_mark[-1].n; }
break;
case 62:
#line 151 "piyush.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'&', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n, NULL); yyval.n = yystack.l_mark[-1].n; }
break;
case 63:
#line 152 "piyush.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'|', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n, NULL); yyval.n = yystack.l_mark[-1].n; }
break;
case 64:
#line 153 "piyush.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'!', 0, NULL, NULL, yystack.l_mark[0].n, NULL, NULL); yyval.n = yystack.l_mark[-1].n; }
break;
case 65:
#line 154 "piyush.y"
	{ yyval.n = yystack.l_mark[-1].n; }
break;
case 66:
#line 155 "piyush.y"
	{ yystack.l_mark[0].n = CreateNode(0,'T', 0, NULL,NULL,NULL,NULL, NULL); yyval.n = yystack.l_mark[0].n; }
break;
case 67:
#line 156 "piyush.y"
	{ yystack.l_mark[0].n = CreateNode(0,'F', 0, NULL, NULL, NULL, NULL, NULL); yyval.n = yystack.l_mark[0].n; }
break;
#line 975 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
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
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
