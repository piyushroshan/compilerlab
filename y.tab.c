#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20110908

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "symbol.y"
#include <stdio.h>
#include <stdlib.h>
struct node {
	int TYPE;			/* Integer (1), Boolean (2) or Void (0) (for statements) */
					/* Must point to the type expression tree for user defined types */
	int NODETYPE;			/* this field should carry following information:
					* a) operator : (+,*,/ etc.) for expressions
					* b) statement Type : (WHILE, READ etc.) for statements
					* c) else 0
					*/
	int VALUE;			/* for constants */
	char* NAME;			/* For Identifiers */
	struct	node	*center, *left,	*right;
};

struct Gsymbol {
	char *NAME; /* Name of the Identifier*/
	int TYPE; /* TYPE can be INTEGER or BOOLEAN*/
	/***The TYPE field must be a TypeStruct if user defined types are allowed***/
	int SIZE; /* Size field for arrays*/
	/*int BINDING; // Address of the Identifier in Memory*/
	/*ArgStruct *ARGLIST; // Argument List for functions*/

	/***Argstruct must store the name and type of each argument ***/
	struct Gsymbol *NEXT; /* Pointer to next Symbol Table Entry * /*/
} *Gnode;

struct Lsymbol {
	/* Here only name, type, binding and pointer to next entry needed */
	char *NAME; /* Name of the Identifier*/
	int TYPE; /* TYPE can be INTEGER or BOOLEAN*/
	/***The TYPE field must be a TypeStruct if user defined types are allowed***/
	/*int BINDING; // Address of the Identifier in Memory*/
	struct Lsymbol *NEXT; /* Pointer to next Symbol Table Entry * /*/
} *Lnode;



void printTree(struct node* root);
struct node* CreateNode(int TYPE1, int NODETYPE1, int VALUE1, char* NAME1, struct node *ptr1, struct node *ptr2, struct node *ptr3);
void Ginstall(char* NAME, int TYPE, int SIZE);
struct Gsymbol *Glookup(char* NAME);
struct Lsymbol *Llookup(char* NAME);
void Linstall(char* NAME, int TYPE);
int TYPE;

void PrintSymbol(){
	struct Gsymbol *Gtemp = Gnode;
	while(Gtemp != NULL){
		printf("%s --> %d ",Gtemp->NAME,Gtemp->TYPE) ;
		Gtemp =Gtemp->NEXT;
	}
	printf("\n");
	struct Lsymbol *Ltemp = Lnode;
	while(Ltemp != NULL){
		printf("%s --> %d ",Ltemp->NAME,Ltemp->TYPE) ;
		Ltemp = Ltemp->NEXT;
	}
	printf("\n");
}

int	eval(struct node* root) ;
#line 66 "symbol.y"
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
#line 93 "y.tab.c"

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
#define YYERROR_DECL() yyerror(const char *s)
#define YYERROR_CALL(msg) yyerror(msg)

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
    0,   23,   24,   24,   16,   17,   17,   18,   18,   22,
   22,    1,    2,   25,   26,   26,   20,   19,   19,   21,
    3,    4,    4,    5,    5,    5,    5,    5,    6,    6,
    7,   14,   14,    8,    8,    9,   10,   15,   11,   11,
   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,
   11,   11,   11,   11,   11,   11,   11,   11,   12,   12,
   12,   12,   12,   12,   12,   12,   12,   13,   13,   13,
   13,   13,   13,   13,   13,   13,   13,   13,   13,
};
static const short yylen[] = {                            2,
    2,    3,    0,    2,    3,    1,    3,    1,    1,    1,
    4,    7,    2,    3,    0,    2,    3,    1,    3,    1,
    4,    0,    2,    1,    1,    1,    1,    1,    6,    8,
    6,    4,    7,    5,    8,    5,    3,    1,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    2,    3,    1,    1,    1,    4,    3,    3,
    3,    3,    3,    3,    1,    1,    4,    3,    3,    3,
    3,    3,    3,    3,    3,    2,    3,    1,    1,
};
static const short yydefred[] = {                         0,
    3,    0,    0,    0,    0,    1,    2,    8,    9,    4,
    0,    0,    0,    0,    6,    0,    0,    5,    0,    0,
    0,    7,    0,   11,   15,    0,    0,    0,   12,   22,
   13,   14,    0,   16,    0,   20,    0,   18,    0,    0,
    0,    0,    0,    0,   23,   24,   25,   26,   27,    0,
   28,   17,    0,    0,    0,    0,    0,    0,   78,   79,
    0,   65,    0,    0,    0,    0,   38,    0,   21,   19,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   76,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   22,   22,   37,    0,    0,    0,    0,    0,    0,   32,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   64,   77,   63,
    0,    0,    0,    0,    0,    0,    0,    0,   61,   62,
   74,   75,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   34,   36,   67,    0,   22,    0,    0,    0,
    0,   29,    0,   31,   33,    0,    0,   35,   30,
};
static const short yydgoto[] = {                          2,
    6,   26,   31,   35,   45,   46,   47,   48,   49,   50,
   79,   64,   81,   51,   68,   10,   14,   11,   37,   34,
   38,   15,    3,    4,   27,   28,
};
static const short yysindex[] = {                      -239,
    0,    0, -236, -250, -274,    0,    0,    0,    0,    0,
 -231, -216, -208, -246,    0, -205, -195,    0, -231, -193,
 -175,    0, -151,    0,    0, -171, -166,  -52,    0,    0,
    0,    0, -128,    0, -253,    0, -244,    0, -259, -139,
 -115,   91,   91, -120,    0,    0,    0,    0,    0, -144,
    0,    0, -128, -261,   93,  -73, -261,  -71,    0,    0,
   91,    0,   91,  167, -222, -242,    0, -101,    0,    0,
 -261,  -94,  -61,    0,    0,   91,    0,   91,  -47,  190,
 -176, -260,  -44, -261,    0,  122, -225, -261, -261, -261,
 -261, -261, -261, -261, -261, -261, -261, -261,   91,   91,
    0,    0,    0,  156,  -64, -261,    0,  133, -197,    0,
 -261, -261, -261, -261, -261, -261, -261, -261, -261, -261,
 -261,   91,   91, -261,  -40,  -37,   99,    0,    0,    0,
   -6,   -6,   -6,   -6,   -6,   -6, -149, -149,    0,    0,
    0,    0,  164,  -46,   93,  105,    0,    0,    0,   -6,
   -6,   -6,   -6,   -6,   -6, -149, -149,    0,    0,    0,
    0,  110,    0,    0,    0,  -28,    0,  -27,  -25,    0,
  -58,    0, -106,    0,    0,  -22,  -21,    0,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -97,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -172,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  201, -170, -134,    0,  -29,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -55,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -167, -132,  -85,  -72,  -70,  -57, -137, -105,    0,    0,
    0,    0,    0,    0,    0,    0,  -16,   96,    7,  224,
  234,  237,  239,  241,  243, -206,   64,   18,   41,  247,
  256,    0,    0,    0,    0,    0,    0,    0,    0,   52,
    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
    0,    0,    0,  -95,    0,    0,    0,    0,    0,    0,
   97,  -54,    8,    0,    0,    0,    0,  213,    0,    0,
  195,  231,    0,    0,    0,    0,
};
#define YYTABLESIZE 527
static const short yytable[] = {                         72,
   80,   58,   83,  124,   54,  143,  144,    7,   86,   39,
    8,    9,   18,   19,   52,   53,  104,    1,   62,   40,
   41,   42,   55,  108,    5,   43,   12,   99,  100,  127,
   71,   13,  125,  130,  131,  132,  133,  134,  135,  136,
  137,  138,  139,  140,   99,  100,   44,   99,  100,   65,
   66,  146,   39,  102,  101,   17,  149,  150,  151,  152,
  153,  154,  155,  156,  157,  158,  159,  129,   85,  162,
   87,  173,   99,  100,   59,   16,   59,   59,   59,   59,
   59,   59,   59,  107,   21,  109,   66,   20,   55,   24,
   80,   68,   66,  122,  123,  148,   66,   66,   66,   78,
   78,   23,   68,   68,   66,   25,  141,  142,   66,   68,
   66,   66,   66,   66,   66,   66,   66,   66,   66,   88,
   66,   59,   29,   66,   56,   68,   73,   59,   68,  160,
  161,   30,   59,   59,   36,   79,   79,   73,   73,   59,
   97,   98,   67,   59,   73,   59,   59,   59,   59,   59,
   59,   59,   56,   60,   69,   59,   39,  103,   59,   60,
   73,   10,   10,   73,   60,   60,   40,   41,   42,  177,
  105,   60,   43,   69,   88,   60,   57,   60,   60,   60,
   60,   60,   60,   60,   69,   69,   72,   60,   70,   82,
   60,   69,   84,   95,   96,   97,   98,   72,   72,   70,
   70,   71,  106,   53,   72,   32,   70,   69,    8,    9,
   69,  110,   71,   71,   76,   76,   39,  145,  163,   71,
   72,  164,   70,   72,   88,   70,   40,   41,   42,   57,
  172,  174,   43,  175,  176,   71,  178,  179,   71,   65,
   33,  169,   44,   95,   96,   97,   98,   70,  126,   22,
  168,   65,   64,   65,   65,   65,   65,   65,   65,   65,
   65,   65,   88,    0,   64,   43,   64,   64,   64,   64,
   64,   64,   64,   64,   64,   63,   41,    0,    0,    0,
    0,   95,   96,   97,   98,    0,   61,   63,    0,   63,
   63,   63,   63,   63,   63,   63,   63,   63,   61,   42,
   61,   61,   61,   61,   61,   61,   61,   61,   61,   62,
   58,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   67,   62,   40,   62,   62,   62,   62,   62,   62,   62,
   62,   62,   67,    0,   67,   67,   67,   67,   67,   67,
   67,   67,   67,    0,   60,    0,   60,   60,   60,   60,
   60,   60,   60,   58,   54,   73,   59,   60,   74,   75,
    0,    0,   61,  165,   76,   77,   77,   88,    0,  170,
   62,    0,   77,   88,  171,    0,    0,    0,   88,    0,
    0,    0,   63,    0,   78,    0,   95,   96,   97,   98,
   88,    0,   95,   96,   97,   98,    0,   95,   96,   97,
   98,   88,   89,    0,   90,   91,   92,   93,   94,   95,
   96,   97,   98,   89,  128,   90,   91,   92,   93,   94,
   95,   96,   97,   98,   88,  147,   39,    0,    0,    0,
    0,    0,    0,    0,    0,   88,   40,   41,   42,  166,
    0,  167,   43,   95,   96,   97,   98,   89,  128,   90,
   91,   92,   93,   94,   95,   96,   97,   98,  111,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   66,
  112,    0,  113,  114,  115,  116,  117,  118,  119,  120,
  121,   66,   45,   66,   66,   66,   66,   66,   66,   66,
   66,   66,   50,   68,   68,   46,    0,   49,    0,   47,
    0,   48,    0,   73,   73,   51,   69,   69,   72,   72,
   70,   70,   71,   71,   52,    0,   74,   74,    0,    0,
    0,    0,    0,    0,    0,   75,   75,
};
static const short yycheck[] = {                         54,
   55,  263,   57,  264,  264,  101,  102,  258,   63,  263,
  261,  262,  259,  260,  259,  260,   71,  257,  280,  273,
  274,  275,  282,   78,  261,  279,  301,  270,  271,   84,
  292,  263,  293,   88,   89,   90,   91,   92,   93,   94,
   95,   96,   97,   98,  270,  271,  300,  270,  271,   42,
   43,  106,  259,  296,  277,  264,  111,  112,  113,  114,
  115,  116,  117,  118,  119,  120,  121,  293,   61,  124,
   63,  167,  270,  271,  281,  292,  283,  284,  285,  286,
  287,  288,  289,   76,  280,   78,  259,  293,  259,  265,
  145,  259,  265,  270,  271,  293,  269,  270,  271,  270,
  271,  295,  270,  271,  277,  257,   99,  100,  281,  277,
  283,  284,  285,  286,  287,  288,  289,  290,  291,  269,
  293,  259,  294,  296,  259,  293,  259,  265,  296,  122,
  123,  298,  270,  271,  263,  270,  271,  270,  271,  277,
  290,  291,  263,  281,  277,  283,  284,  285,  286,  287,
  288,  289,  292,  259,  299,  293,  263,  259,  296,  265,
  293,  259,  260,  296,  270,  271,  273,  274,  275,  276,
  265,  277,  279,  259,  269,  281,  292,  283,  284,  285,
  286,  287,  288,  289,  270,  271,  259,  293,  259,  263,
  296,  277,  264,  288,  289,  290,  291,  270,  271,  270,
  271,  259,  264,  259,  277,  258,  277,  293,  261,  262,
  296,  259,  270,  271,  270,  271,  263,  282,  259,  277,
  293,  259,  293,  296,  269,  296,  273,  274,  275,  259,
  259,  259,  279,  259,  293,  293,  259,  259,  296,  269,
   28,  145,  259,  288,  289,  290,  291,   53,  293,   19,
  297,  281,  269,  283,  284,  285,  286,  287,  288,  289,
  290,  291,  269,   -1,  281,  259,  283,  284,  285,  286,
  287,  288,  289,  290,  291,  269,  259,   -1,   -1,   -1,
   -1,  288,  289,  290,  291,   -1,  269,  281,   -1,  283,
  284,  285,  286,  287,  288,  289,  290,  291,  281,  259,
  283,  284,  285,  286,  287,  288,  289,  290,  291,  269,
  259,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  269,  281,  259,  283,  284,  285,  286,  287,  288,  289,
  290,  291,  281,   -1,  283,  284,  285,  286,  287,  288,
  289,  290,  291,   -1,  281,   -1,  283,  284,  285,  286,
  287,  288,  289,  263,  259,  263,  266,  267,  266,  267,
   -1,   -1,  272,  265,  272,  270,  271,  269,   -1,  265,
  280,   -1,  280,  269,  265,   -1,   -1,   -1,  269,   -1,
   -1,   -1,  292,   -1,  292,   -1,  288,  289,  290,  291,
  269,   -1,  288,  289,  290,  291,   -1,  288,  289,  290,
  291,  269,  281,   -1,  283,  284,  285,  286,  287,  288,
  289,  290,  291,  281,  293,  283,  284,  285,  286,  287,
  288,  289,  290,  291,  269,  293,  263,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  269,  273,  274,  275,  276,
   -1,  278,  279,  288,  289,  290,  291,  281,  293,  283,
  284,  285,  286,  287,  288,  289,  290,  291,  269,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  269,
  281,   -1,  283,  284,  285,  286,  287,  288,  289,  290,
  291,  281,  259,  283,  284,  285,  286,  287,  288,  289,
  290,  291,  259,  270,  271,  259,   -1,  259,   -1,  259,
   -1,  259,   -1,  270,  271,  259,  270,  271,  270,  271,
  270,  271,  270,  271,  259,   -1,  270,  271,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  270,  271,
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
"return : RETURN expression1 SEMICOLON",
"expression1 : ID",
"expression : aexpression PLUS aexpression",
"expression : aexpression MINUS aexpression",
"expression : aexpression MULT aexpression",
"expression : aexpression DIVIDE aexpression",
"expression : aexpression MODULUS aexpression",
"expression : LPAREN aexpression RPAREN",
"expression : aexpression EQUAL aexpression",
"expression : aexpression LESS_THAN aexpression",
"expression : aexpression GREATER_THAN aexpression",
"expression : aexpression GREATER_EQ aexpression",
"expression : aexpression LESS_EQUAL aexpression",
"expression : aexpression NEQUAL aexpression",
"expression : lexpression AND lexpression",
"expression : lexpression OR lexpression",
"expression : NOT lexpression",
"expression : LPAREN lexpression RPAREN",
"expression : TRUE",
"expression : FALSE",
"expression : NUMBER",
"expression : ID LSQUARE aexpression RSQUARE",
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
#line 218 "symbol.y"

int main(){
	return(yyparse());
}

yyerror(s)
char *s;
{
  fprintf(stderr, "%s\n",s);
}

int	eval(struct node* root) {
	if (root == NULL ) {
		printf("\nTree root is NULL");
		return;
	} else {
		if(root->TYPE==0 &&	root->NODETYPE==2)	/* if INTEGER/variable */ {
			if(root->NAME)	{
				struct Lsymbol *lt = Llookup(root->NAME);
				struct Gsymbol *gt = Glookup(root->NAME);
				if(lt)	{
					return 1;
				}
				if(gt)	{
					if(root->center)	{//if there is an array index
						return	1;
					}
					else {
						return	1;
					}
				} else	{
					printf("Wrong identifier '%s' used\n", root->NAME);
					exit(0);
				}
			} else
				return	root->VALUE;
		}

		switch(root->NODETYPE)	{
			case 10 :	return(root->VALUE); break;
			case 11 :	return (eval(root->left) + eval(root->right)); break;
			case 21 :	return (eval(root->left) - eval(root->right)); break;
			case 31 :	return (eval(root->left) * eval(root->right)); break;
			case 41 :	return (eval(root->left) / eval(root->right)); break;
		}
	}
}

#line 557 "y.tab.c"

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
#line 94 "symbol.y"
	{ printf("PARSING SUCCESS\n"); yyval.n=yystack.l_mark[0].n; PrintSymbol();}
break;
case 3:
#line 98 "symbol.y"
	{/*empty*/}
break;
case 8:
#line 106 "symbol.y"
	{ TYPE = 1; }
break;
case 9:
#line 107 "symbol.y"
	{TYPE=2; }
break;
case 10:
#line 110 "symbol.y"
	{ Ginstall(yystack.l_mark[0].n->NAME, TYPE, 0); }
break;
case 11:
#line 111 "symbol.y"
	{ Ginstall(yystack.l_mark[-3].n->NAME, TYPE, yystack.l_mark[-1].n->VALUE); }
break;
case 12:
#line 114 "symbol.y"
	{ yyval.n=CreateNode(0,'f', 0, "MAIN", NULL, yystack.l_mark[-1].n, NULL);}
break;
case 13:
#line 117 "symbol.y"
	{ yyval.n=yystack.l_mark[0].n; }
break;
case 15:
#line 122 "symbol.y"
	{/*empty*/}
break;
case 20:
#line 131 "symbol.y"
	{ Linstall(yystack.l_mark[0].n->NAME, TYPE); }
break;
case 21:
#line 134 "symbol.y"
	{  yyval.n=CreateNode(0,'S', 0, NULL, yystack.l_mark[-2].n, yystack.l_mark[-1].n, NULL); }
break;
case 22:
#line 137 "symbol.y"
	{ yyval.n = NULL; }
break;
case 23:
#line 138 "symbol.y"
	{  yyval.n=CreateNode(0,'S', 0, NULL, yystack.l_mark[0].n, yystack.l_mark[-1].n, NULL); if (yystack.l_mark[-1].n->TYPE==0 && yystack.l_mark[0].n->TYPE==0) yyval.n->TYPE=0; else yyval.n->TYPE=-1;}
break;
case 24:
#line 141 "symbol.y"
	{ yyval.n = yystack.l_mark[0].n; yyval.n->TYPE = yystack.l_mark[0].n->TYPE; }
break;
case 25:
#line 142 "symbol.y"
	{ yyval.n = yystack.l_mark[0].n; yyval.n->TYPE = yystack.l_mark[0].n->TYPE;}
break;
case 26:
#line 143 "symbol.y"
	{ yyval.n = yystack.l_mark[0].n; yyval.n->TYPE = yystack.l_mark[0].n->TYPE; }
break;
case 27:
#line 144 "symbol.y"
	{ yyval.n = yystack.l_mark[0].n;  yyval.n->TYPE = yystack.l_mark[0].n->TYPE; }
break;
case 28:
#line 145 "symbol.y"
	{ yyval.n = yystack.l_mark[0].n; yyval.n->TYPE = yystack.l_mark[0].n->TYPE; }
break;
case 29:
#line 148 "symbol.y"
	{ yystack.l_mark[-5].n = CreateNode(0,'I', 0, NULL, yystack.l_mark[-2].n, yystack.l_mark[-4].n, NULL); yyval.n = yystack.l_mark[-5].n; if (yystack.l_mark[-4].n->TYPE==2 && yystack.l_mark[-2].n->TYPE==0) yyval.n->TYPE=0; else yyval.n->TYPE=-1;  }
break;
case 30:
#line 149 "symbol.y"
	{ yystack.l_mark[-7].n = CreateNode(0,'I', 0, NULL, yystack.l_mark[-4].n, yystack.l_mark[-6].n, yystack.l_mark[-2].n); yyval.n = yystack.l_mark[-7].n; if (yystack.l_mark[-6].n->TYPE==2 && yystack.l_mark[-4].n->TYPE==0 && yystack.l_mark[-2].n->TYPE==0) yyval.n->TYPE=0; else yyval.n->TYPE=-1; }
break;
case 31:
#line 152 "symbol.y"
	{ yystack.l_mark[-5].n = CreateNode(0,'W', 0, NULL, yystack.l_mark[-2].n, yystack.l_mark[-4].n, NULL); yyval.n=yystack.l_mark[-5].n; if (yystack.l_mark[-4].n->TYPE==2 && yystack.l_mark[-2].n->TYPE==0) yyval.n->TYPE=0; else yyval.n->TYPE=-1; }
break;
case 32:
#line 155 "symbol.y"
	{ yystack.l_mark[-2].n = CreateNode(0,'=', 0, NULL, yystack.l_mark[-3].n, NULL, yystack.l_mark[-1].n); yyval.n=yystack.l_mark[-2].n; if (yystack.l_mark[-1].n->TYPE==1 || yystack.l_mark[-1].n->TYPE==2) yyval.n->TYPE=0; else yyval.n->TYPE=-1; }
break;
case 33:
#line 156 "symbol.y"
	{ yystack.l_mark[-6].n->center = yystack.l_mark[-4].n; yystack.l_mark[-2].n = CreateNode(0,'=', 0, NULL, yystack.l_mark[-6].n, NULL, yystack.l_mark[-1].n); yyval.n=yystack.l_mark[-2].n; if (yystack.l_mark[-4].n->TYPE==1 && (yystack.l_mark[-1].n->TYPE==1 || yystack.l_mark[-1].n->TYPE==2)) yyval.n->TYPE=0; else yyval.n->TYPE=-1; }
break;
case 34:
#line 159 "symbol.y"
	{ yystack.l_mark[-4].n = CreateNode(0,'r', 0, NULL, NULL, yystack.l_mark[-2].n, NULL); yyval.n = yystack.l_mark[-4].n; if(yystack.l_mark[-2].n->TYPE!=-1) yyval.n->TYPE=0; else yyval.n->TYPE=-1;}
break;
case 35:
#line 160 "symbol.y"
	{ yystack.l_mark[-5].n->center = yystack.l_mark[-3].n;  yystack.l_mark[-7].n = CreateNode(0,'r', 0, NULL, NULL, yystack.l_mark[-5].n, NULL); yyval.n = yystack.l_mark[-7].n; if(yystack.l_mark[-5].n->TYPE!=-1 && yystack.l_mark[-3].n->TYPE==1) yyval.n->TYPE=0; else yyval.n->TYPE=-1; }
break;
case 36:
#line 163 "symbol.y"
	{ yystack.l_mark[-4].n = CreateNode(0,'w', 0, NULL, NULL, yystack.l_mark[-2].n, NULL); yyval.n = yystack.l_mark[-4].n; if(yystack.l_mark[-2].n->TYPE==1) yyval.n->TYPE=0; else yyval.n->TYPE=-1; }
break;
case 37:
#line 166 "symbol.y"
	{ yystack.l_mark[-2].n = CreateNode(0,'R', 0, NULL, NULL, yystack.l_mark[-1].n, NULL); eval(yystack.l_mark[-1].n); yyval.n = yystack.l_mark[-2].n; }
break;
case 38:
#line 168 "symbol.y"
	{ yyval.n=yystack.l_mark[0].n; if(eval(yystack.l_mark[0].n)!=1){printf("WROng");}}
break;
case 39:
#line 170 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'+', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==1 && yystack.l_mark[0].n->TYPE ==1) yyval.n->TYPE=1; else yyval.n->TYPE=-1; }
break;
case 40:
#line 171 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'-', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==1 && yystack.l_mark[0].n->TYPE ==1) yyval.n->TYPE=1; else yyval.n->TYPE=-1;  }
break;
case 41:
#line 172 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'*', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==1 && yystack.l_mark[0].n->TYPE ==1) yyval.n->TYPE=1; else yyval.n->TYPE=-1;  }
break;
case 42:
#line 173 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'/', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n;  if(yystack.l_mark[-2].n->TYPE==1 && yystack.l_mark[0].n->TYPE ==1) yyval.n->TYPE=1; else yyval.n->TYPE=-1; }
break;
case 43:
#line 174 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'%', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==1 && yystack.l_mark[0].n->TYPE ==1) yyval.n->TYPE=1; else yyval.n->TYPE=-1;  }
break;
case 44:
#line 175 "symbol.y"
	{ yyval.n=yystack.l_mark[-1].n; yyval.n->TYPE = yystack.l_mark[-2].n->TYPE; }
break;
case 45:
#line 176 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'E', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==1 && yystack.l_mark[0].n->TYPE ==1) yyval.n->TYPE=2; else yyval.n->TYPE=-1;  }
break;
case 46:
#line 177 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'<', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==1 && yystack.l_mark[0].n->TYPE ==1) yyval.n->TYPE=2; else yyval.n->TYPE=-1;  }
break;
case 47:
#line 178 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'>', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==1 && yystack.l_mark[0].n->TYPE ==1) yyval.n->TYPE=2; else yyval.n->TYPE=-1;  }
break;
case 48:
#line 179 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'G', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==1 && yystack.l_mark[0].n->TYPE ==1) yyval.n->TYPE=2; else yyval.n->TYPE=-1;  }
break;
case 49:
#line 180 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'L', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==1 && yystack.l_mark[0].n->TYPE ==1) yyval.n->TYPE=2; else yyval.n->TYPE=-1;  }
break;
case 50:
#line 181 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'N', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==1 && yystack.l_mark[0].n->TYPE ==1) yyval.n->TYPE=2; else yyval.n->TYPE=-1;  }
break;
case 51:
#line 182 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'&', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==1 && yystack.l_mark[0].n->TYPE ==1) yyval.n->TYPE=2; else yyval.n->TYPE=-1;  }
break;
case 52:
#line 183 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'|', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==1 && yystack.l_mark[0].n->TYPE ==1) yyval.n->TYPE=2; else yyval.n->TYPE=-1;  }
break;
case 53:
#line 184 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'!', 0, NULL, NULL, yystack.l_mark[0].n, NULL); yyval.n = yystack.l_mark[-1].n;  }
break;
case 54:
#line 185 "symbol.y"
	{ yyval.n = yystack.l_mark[-1].n; }
break;
case 55:
#line 186 "symbol.y"
	{ yystack.l_mark[0].n = CreateNode(0,'T', 0, NULL,NULL,NULL,NULL); yyval.n = yystack.l_mark[0].n; }
break;
case 56:
#line 187 "symbol.y"
	{ yystack.l_mark[0].n = CreateNode(0,'F', 0, NULL, NULL, NULL, NULL); yyval.n = yystack.l_mark[0].n; }
break;
case 57:
#line 188 "symbol.y"
	{ yyval.n=yystack.l_mark[0].n; }
break;
case 58:
#line 189 "symbol.y"
	{   yystack.l_mark[-3].n->center = yystack.l_mark[-1].n; yyval.n = yystack.l_mark[-3].n;}
break;
case 59:
#line 192 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'+', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; }
break;
case 60:
#line 193 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'-', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; }
break;
case 61:
#line 194 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'*', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; }
break;
case 62:
#line 195 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'/', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; }
break;
case 63:
#line 196 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'%', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; }
break;
case 64:
#line 197 "symbol.y"
	{ yyval.n = yystack.l_mark[-1].n; }
break;
case 65:
#line 198 "symbol.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 66:
#line 199 "symbol.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 67:
#line 200 "symbol.y"
	{   yystack.l_mark[-3].n->center = yystack.l_mark[-1].n; yyval.n = yystack.l_mark[-3].n;}
break;
case 68:
#line 203 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'E', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n;  }
break;
case 69:
#line 204 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'<', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; }
break;
case 70:
#line 205 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'>', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; }
break;
case 71:
#line 206 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'G', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; }
break;
case 72:
#line 207 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'L', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; }
break;
case 73:
#line 208 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'N', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; }
break;
case 74:
#line 209 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'&', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; }
break;
case 75:
#line 210 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'|', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; }
break;
case 76:
#line 211 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'!', 0, NULL, NULL, yystack.l_mark[0].n, NULL); yyval.n = yystack.l_mark[-1].n; }
break;
case 77:
#line 212 "symbol.y"
	{ yyval.n = yystack.l_mark[-1].n; }
break;
case 78:
#line 213 "symbol.y"
	{ yystack.l_mark[0].n = CreateNode(0,'T', 0, NULL,NULL,NULL,NULL); yyval.n = yystack.l_mark[0].n; }
break;
case 79:
#line 214 "symbol.y"
	{ yystack.l_mark[0].n = CreateNode(0,'F', 0, NULL, NULL, NULL, NULL); yyval.n = yystack.l_mark[0].n; }
break;
#line 1039 "y.tab.c"
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
