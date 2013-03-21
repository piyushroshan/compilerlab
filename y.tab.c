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
int RTYPE;
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
#line 64 "symbol.y"
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
#line 91 "y.tab.c"

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
    0,   20,   21,   21,   13,   14,   14,   15,   15,   19,
   19,    1,    2,   22,   23,   23,   17,   16,   16,   18,
    3,    4,    4,    5,    5,    5,    5,    5,    6,    6,
    7,   12,   12,    8,    8,    9,   10,   11,   11,   11,
   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,
   11,   11,   11,   11,   11,   11,   11,
};
static const short yylen[] = {                            2,
    2,    3,    0,    2,    3,    1,    3,    1,    1,    1,
    4,    7,    2,    3,    0,    2,    3,    1,    3,    1,
    4,    0,    2,    1,    1,    1,    1,    1,    6,    8,
    6,    4,    7,    5,    8,    5,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    2,    3,    1,    1,    1,    1,    4,
};
static const short yydefred[] = {                         0,
    3,    0,    0,    0,    0,    1,    2,    8,    9,    4,
    0,    0,    0,    0,    6,    0,    0,    5,    0,    0,
    0,    7,    0,   11,   15,    0,    0,    0,   12,   22,
   13,   14,    0,   16,    0,   20,    0,   18,    0,    0,
    0,    0,    0,    0,   23,   24,   25,   26,   27,    0,
   28,   17,    0,    0,    0,    0,    0,    0,   53,   54,
    0,   55,    0,    0,    0,    0,   21,   19,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   22,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   22,
   37,    0,   32,    0,    0,    0,    0,   52,   42,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   40,   41,    0,    0,    0,   34,   36,   57,    0,   22,
    0,    0,    0,   29,    0,   31,   33,    0,    0,   35,
   30,
};
static const short yydgoto[] = {                          2,
    6,   26,   31,   35,   45,   46,   47,   48,   49,   50,
   64,   51,   10,   14,   11,   37,   34,   38,   15,    3,
    4,   27,   28,
};
static const short yysindex[] = {                      -248,
    0,    0, -251, -254, -282,    0,    0,    0,    0,    0,
 -241, -260, -236, -244,    0, -257, -223,    0, -241, -232,
 -201,    0, -192,    0,    0, -227, -230, -209,    0,    0,
    0,    0, -194,    0, -250,    0, -204,    0, -261, -208,
 -206,  144,  144,  144,    0,    0,    0,    0,    0, -203,
    0,    0, -194,  144,  144, -175,  144, -174,    0,    0,
  144,    0,  144,  311,  156,   69,    0,    0,  184,   92,
 -262,  261,  144, -136,  286,  144,  144,  144,    0,  144,
  144,  144,  144,  144,  144,  144,  144,  144,  144,    0,
    0, -191,    0,  144, -162, -161,  211,    0,    0,  322,
  322,  155,   80,   80, -136, -136, -136, -136, -264, -264,
    0,    0,   18,  144,  238,    0,    0,    0, -159,    0,
 -157,  115, -189,    0, -147,    0,    0, -145, -138,    0,
    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -198,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -211,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -114,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -176,
   48,    0,   31,   40,  -85,  -56,  -27,    2, -178, -146,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,
};
static const short yygindex[] = {                         0,
    0,    0,    0,  -73,    0,    0,    0,    0,    0,    0,
  -43,    0,    0,    0,   84,    0,    0,   70,  103,    0,
    0,    0,    0,
};
#define YYTABLESIZE 613
static const short yytable[] = {                         65,
   66,   94,   54,    7,   76,  102,    8,    9,    1,    5,
   69,   70,   39,   72,   18,   19,  113,   74,   12,   75,
   55,   13,   40,   41,   42,   88,   89,   17,   43,   97,
   95,   16,   99,  100,  101,   20,  103,  104,  105,  106,
  107,  108,  109,  110,  111,  112,  125,   56,   32,   44,
  115,    8,    9,   56,   52,   53,   21,   56,   56,   56,
   10,   10,   23,   24,   25,   56,   29,   30,   36,   56,
  122,   56,   56,   56,   56,   56,   56,   56,   56,   56,
   38,   56,   49,   56,   56,   57,   38,   71,   49,   73,
  114,   38,   38,   49,   49,   67,  116,  117,   38,  124,
   49,  126,   38,  128,   38,   38,   38,   38,   38,   38,
   38,   33,   39,  130,   38,   39,   49,   38,   39,   49,
  131,   22,   68,   39,   39,   40,   41,   42,  129,    0,
   39,   43,   76,    0,   39,    0,   39,   39,   39,   39,
   39,   39,   39,    0,   51,    0,   39,    0,    0,   39,
   51,   86,   87,   88,   89,   51,   51,    0,    0,    0,
    0,    0,   51,    0,    0,    0,   51,    0,   51,   51,
   51,   51,   51,   44,    0,    0,    0,    0,   51,   44,
    0,   51,    0,    0,   44,   44,    0,    0,    0,    0,
    0,   44,    0,    0,    0,   44,    0,   44,   44,   44,
   44,   44,   47,    0,    0,    0,    0,   44,   47,    0,
   44,    0,    0,   47,   47,    0,    0,    0,    0,    0,
   47,    0,    0,    0,   47,    0,   47,   47,   47,   47,
   47,   45,    0,    0,    0,    0,   47,   45,    0,   47,
    0,    0,   45,   45,    0,    0,    0,    0,    0,   45,
    0,    0,    0,   45,    0,   45,   45,   45,   45,   45,
   46,    0,    0,    0,    0,   45,   46,    0,   45,    0,
    0,   46,   46,    0,    0,    0,    0,    0,   46,    0,
   39,    0,   46,    0,   46,   46,   46,   46,   46,   43,
   40,   41,   42,    0,   46,   43,   43,   46,   48,    0,
   43,   43,    0,    0,   48,    0,   50,   43,    0,   48,
   48,   43,   50,   43,  121,    0,   48,   50,   50,    0,
   48,    0,   48,   43,   50,    0,   43,   91,    0,    0,
    0,    0,   48,    0,    0,   48,    0,   76,   77,   78,
   50,    0,    0,   50,    0,    0,    0,    0,   76,   80,
   93,   81,   82,   83,   84,   85,   86,   87,   88,   89,
   76,   77,   78,   82,   83,   84,   85,   86,   87,   88,
   89,    0,   80,  127,   81,   82,   83,   84,   85,   86,
   87,   88,   89,   76,   77,   78,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   80,    0,   81,   82,   83,
   84,   85,   86,   87,   88,   89,   58,    0,    0,   59,
   60,    0,    0,    0,    0,   61,    0,   39,    0,    0,
    0,    0,    0,   62,   76,   77,   78,   40,   41,   42,
  119,    0,  120,   43,    0,   63,   80,    0,   81,   82,
   83,   84,   85,   86,   87,   88,   89,    0,   92,    0,
    0,   90,   76,   77,   78,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   80,    0,   81,   82,   83,   84,
   85,   86,   87,   88,   89,  118,    0,    0,    0,   76,
   77,   78,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   80,    0,   81,   82,   83,   84,   85,   86,   87,
   88,   89,  123,    0,    0,    0,   76,   77,   78,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   80,    0,
   81,   82,   83,   84,   85,   86,   87,   88,   89,   76,
   77,   78,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   80,    0,   81,   82,   83,   84,   85,   86,   87,
   88,   89,    0,   96,   76,   77,   78,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   80,    0,   81,   82,
   83,   84,   85,   86,   87,   88,   89,    0,   98,   76,
   77,   78,    0,    0,    0,    0,    0,   79,    0,    0,
   76,   80,    0,   81,   82,   83,   84,   85,   86,   87,
   88,   89,   80,    0,   81,   82,   83,   84,   85,   86,
   87,   88,   89,
};
static const short yycheck[] = {                         43,
   44,  264,  264,  258,  269,   79,  261,  262,  257,  261,
   54,   55,  263,   57,  259,  260,   90,   61,  301,   63,
  282,  263,  273,  274,  275,  290,  291,  264,  279,   73,
  293,  292,   76,   77,   78,  293,   80,   81,   82,   83,
   84,   85,   86,   87,   88,   89,  120,  259,  258,  300,
   94,  261,  262,  265,  259,  260,  280,  269,  270,  271,
  259,  260,  295,  265,  257,  277,  294,  298,  263,  281,
  114,  283,  284,  285,  286,  287,  288,  289,  290,  291,
  259,  293,  259,  292,  296,  292,  265,  263,  265,  264,
  282,  270,  271,  270,  271,  299,  259,  259,  277,  259,
  277,  259,  281,  293,  283,  284,  285,  286,  287,  288,
  289,   28,  259,  259,  293,  263,  293,  296,  265,  296,
  259,   19,   53,  270,  271,  273,  274,  275,  276,   -1,
  277,  279,  269,   -1,  281,   -1,  283,  284,  285,  286,
  287,  288,  289,   -1,  259,   -1,  293,   -1,   -1,  296,
  265,  288,  289,  290,  291,  270,  271,   -1,   -1,   -1,
   -1,   -1,  277,   -1,   -1,   -1,  281,   -1,  283,  284,
  285,  286,  287,  259,   -1,   -1,   -1,   -1,  293,  265,
   -1,  296,   -1,   -1,  270,  271,   -1,   -1,   -1,   -1,
   -1,  277,   -1,   -1,   -1,  281,   -1,  283,  284,  285,
  286,  287,  259,   -1,   -1,   -1,   -1,  293,  265,   -1,
  296,   -1,   -1,  270,  271,   -1,   -1,   -1,   -1,   -1,
  277,   -1,   -1,   -1,  281,   -1,  283,  284,  285,  286,
  287,  259,   -1,   -1,   -1,   -1,  293,  265,   -1,  296,
   -1,   -1,  270,  271,   -1,   -1,   -1,   -1,   -1,  277,
   -1,   -1,   -1,  281,   -1,  283,  284,  285,  286,  287,
  259,   -1,   -1,   -1,   -1,  293,  265,   -1,  296,   -1,
   -1,  270,  271,   -1,   -1,   -1,   -1,   -1,  277,   -1,
  263,   -1,  281,   -1,  283,  284,  285,  286,  287,  259,
  273,  274,  275,   -1,  293,  265,  279,  296,  259,   -1,
  270,  271,   -1,   -1,  265,   -1,  259,  277,   -1,  270,
  271,  281,  265,  283,  297,   -1,  277,  270,  271,   -1,
  281,   -1,  283,  293,  277,   -1,  296,  259,   -1,   -1,
   -1,   -1,  293,   -1,   -1,  296,   -1,  269,  270,  271,
  293,   -1,   -1,  296,   -1,   -1,   -1,   -1,  269,  281,
  259,  283,  284,  285,  286,  287,  288,  289,  290,  291,
  269,  270,  271,  284,  285,  286,  287,  288,  289,  290,
  291,   -1,  281,  259,  283,  284,  285,  286,  287,  288,
  289,  290,  291,  269,  270,  271,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  281,   -1,  283,  284,  285,
  286,  287,  288,  289,  290,  291,  263,   -1,   -1,  266,
  267,   -1,   -1,   -1,   -1,  272,   -1,  263,   -1,   -1,
   -1,   -1,   -1,  280,  269,  270,  271,  273,  274,  275,
  276,   -1,  278,  279,   -1,  292,  281,   -1,  283,  284,
  285,  286,  287,  288,  289,  290,  291,   -1,  265,   -1,
   -1,  296,  269,  270,  271,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  281,   -1,  283,  284,  285,  286,
  287,  288,  289,  290,  291,  265,   -1,   -1,   -1,  269,
  270,  271,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  281,   -1,  283,  284,  285,  286,  287,  288,  289,
  290,  291,  265,   -1,   -1,   -1,  269,  270,  271,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  281,   -1,
  283,  284,  285,  286,  287,  288,  289,  290,  291,  269,
  270,  271,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  281,   -1,  283,  284,  285,  286,  287,  288,  289,
  290,  291,   -1,  293,  269,  270,  271,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  281,   -1,  283,  284,
  285,  286,  287,  288,  289,  290,  291,   -1,  293,  269,
  270,  271,   -1,   -1,   -1,   -1,   -1,  277,   -1,   -1,
  269,  281,   -1,  283,  284,  285,  286,  287,  288,  289,
  290,  291,  281,   -1,  283,  284,  285,  286,  287,  288,
  289,  290,  291,
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
"ifelse : IF expression THEN statements ENDIF SEMICOLON",
"ifelse : IF expression THEN statements ELSE statements ENDIF SEMICOLON",
"dowhile : WHILE expression DO statements ENDWHILE SEMICOLON",
"astatement : ID ASSIGN expression SEMICOLON",
"astatement : ID LSQUARE expression RSQUARE ASSIGN expression SEMICOLON",
"read : READ LPAREN ID RPAREN SEMICOLON",
"read : READ LPAREN ID LSQUARE expression RSQUARE RPAREN SEMICOLON",
"write : WRITE LPAREN expression RPAREN SEMICOLON",
"return : RETURN expression SEMICOLON",
"expression : expression PLUS expression",
"expression : expression MINUS expression",
"expression : expression MULT expression",
"expression : expression DIVIDE expression",
"expression : expression MODULUS expression",
"expression : expression EQUAL expression",
"expression : expression LESS_THAN expression",
"expression : expression GREATER_THAN expression",
"expression : expression GREATER_EQ expression",
"expression : expression LESS_EQUAL expression",
"expression : expression NEQUAL expression",
"expression : expression AND expression",
"expression : expression OR expression",
"expression : NOT expression",
"expression : LPAREN expression RPAREN",
"expression : TRUE",
"expression : FALSE",
"expression : NUMBER",
"expression : ID",
"expression : ID LSQUARE expression RSQUARE",

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
#line 224 "symbol.y"

int main(){
	return(yyparse());
}

yyerror(s)
char *s;
{
  fprintf(stderr, "%s\n",s);
}


#line 503 "y.tab.c"

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
#line 92 "symbol.y"
	{ printf("PARSING SUCCESS\n"); yyval.n=yystack.l_mark[0].n; PrintSymbol(); printTree(yystack.l_mark[0].n);}
break;
case 3:
#line 96 "symbol.y"
	{/*empty*/}
break;
case 8:
#line 104 "symbol.y"
	{ TYPE = 1; }
break;
case 9:
#line 105 "symbol.y"
	{TYPE=2; }
break;
case 10:
#line 108 "symbol.y"
	{ Ginstall(yystack.l_mark[0].n->NAME, TYPE, 0); }
break;
case 11:
#line 109 "symbol.y"
	{ Ginstall(yystack.l_mark[-3].n->NAME, TYPE, yystack.l_mark[-1].n->VALUE); }
break;
case 12:
#line 112 "symbol.y"
	{ yyval.n=CreateNode(0,'f', 0, "MAIN", NULL, yystack.l_mark[-1].n, NULL);}
break;
case 13:
#line 115 "symbol.y"
	{ yyval.n=yystack.l_mark[0].n; }
break;
case 15:
#line 120 "symbol.y"
	{/*empty*/}
break;
case 20:
#line 129 "symbol.y"
	{ Linstall(yystack.l_mark[0].n->NAME, TYPE); }
break;
case 21:
#line 132 "symbol.y"
	{  yyval.n=CreateNode(0,'S', 0, NULL, yystack.l_mark[-2].n, yystack.l_mark[-1].n, NULL); if ((yystack.l_mark[-2].n==NULL || yystack.l_mark[-2].n->TYPE==0) && yystack.l_mark[-1].n->TYPE==0) yyval.n->TYPE=0; else yyval.n->TYPE=-1; }
break;
case 22:
#line 135 "symbol.y"
	{ yyval.n = NULL; }
break;
case 23:
#line 136 "symbol.y"
	{  yyval.n=CreateNode(0,'S', 0, NULL, yystack.l_mark[0].n, yystack.l_mark[-1].n, NULL); if ((yystack.l_mark[-1].n==NULL || yystack.l_mark[-1].n->TYPE==0) && yystack.l_mark[0].n->TYPE==0) yyval.n->TYPE=0; else yyval.n->TYPE=-1;}
break;
case 24:
#line 139 "symbol.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 25:
#line 140 "symbol.y"
	{ yyval.n = yystack.l_mark[0].n;}
break;
case 26:
#line 141 "symbol.y"
	{ yyval.n = yystack.l_mark[0].n;  }
break;
case 27:
#line 142 "symbol.y"
	{ yyval.n = yystack.l_mark[0].n;  }
break;
case 28:
#line 143 "symbol.y"
	{ yyval.n = yystack.l_mark[0].n;  }
break;
case 29:
#line 146 "symbol.y"
	{ yystack.l_mark[-5].n = CreateNode(0,'I', 0, NULL, yystack.l_mark[-2].n, yystack.l_mark[-4].n, NULL); yyval.n = yystack.l_mark[-5].n;
												if (yystack.l_mark[-4].n->TYPE==2 && (yystack.l_mark[-2].n==NULL || yystack.l_mark[-2].n->TYPE==0)) yyval.n->TYPE=0; else yyval.n->TYPE=-1;  }
break;
case 30:
#line 148 "symbol.y"
	{ yystack.l_mark[-7].n = CreateNode(0,'I', 0, NULL, yystack.l_mark[-4].n, yystack.l_mark[-6].n, yystack.l_mark[-2].n); yyval.n = yystack.l_mark[-7].n;
												if (yystack.l_mark[-6].n->TYPE==2 && (yystack.l_mark[-4].n==NULL || yystack.l_mark[-4].n->TYPE==0) && (yystack.l_mark[-2].n==NULL || yystack.l_mark[-2].n->TYPE==0)) yyval.n->TYPE=0; else yyval.n->TYPE=-1; }
break;
case 31:
#line 152 "symbol.y"
	{ yystack.l_mark[-5].n = CreateNode(0,'W', 0, NULL, yystack.l_mark[-2].n, yystack.l_mark[-4].n, NULL); yyval.n=yystack.l_mark[-5].n; if (yystack.l_mark[-4].n->TYPE==2 && (yystack.l_mark[-2].n==NULL || yystack.l_mark[-2].n->TYPE==0)) yyval.n->TYPE=0; else yyval.n->TYPE=-1; }
break;
case 32:
#line 155 "symbol.y"
	{ yystack.l_mark[-2].n = CreateNode(0,'=', 0, NULL, yystack.l_mark[-3].n, NULL, yystack.l_mark[-1].n); yyval.n=yystack.l_mark[-2].n;
											struct Lsymbol* lt = Llookup(yystack.l_mark[-3].n->NAME);
											if(lt) { if (lt->TYPE == yystack.l_mark[-1].n->TYPE ) yyval.n->TYPE=0; }
											else {
												struct Gsymbol* gt = Glookup(yystack.l_mark[-3].n->NAME);
												if(gt) { if ( gt->SIZE==0 && (gt->TYPE == yystack.l_mark[-1].n->TYPE )) yyval.n->TYPE=0;
												else { yyval.n->TYPE=-1;	yyerror("Wrong assignment");}}else { printf("ID %s not found\n",yystack.l_mark[-3].n->NAME); yyval.n->TYPE=-1;}
											}}
break;
case 33:
#line 163 "symbol.y"
	{ yystack.l_mark[-6].n->center = yystack.l_mark[-4].n; yystack.l_mark[-2].n = CreateNode(0,'=', 0, NULL, yystack.l_mark[-6].n, NULL, yystack.l_mark[-1].n); yyval.n=yystack.l_mark[-2].n;
																struct Gsymbol* gt = Glookup(yystack.l_mark[-6].n->NAME);
																if(gt) {if ( gt->SIZE!=0 && yystack.l_mark[-4].n->TYPE==1 && (gt->TYPE == yystack.l_mark[-1].n->TYPE)) yyval.n->TYPE=0; else { yyval.n->TYPE=-1;
																yyerror("Wrong assignment of array type");}} else {printf("Array %s not found\n",yystack.l_mark[-6].n->NAME); yyval.n->TYPE=-1; }
															}
break;
case 34:
#line 170 "symbol.y"
	{ yystack.l_mark[-4].n = CreateNode(0,'r', 0, NULL, NULL, yystack.l_mark[-2].n, NULL); yyval.n = yystack.l_mark[-4].n;
											struct Lsymbol* lt = Llookup(yystack.l_mark[-2].n->NAME);
											if(lt && (lt->TYPE == 1))
												yyval.n->TYPE=0;
											else {
												struct Gsymbol* gt = Glookup(yystack.l_mark[-2].n->NAME);
												if(gt) {if( gt->SIZE==0 && gt->TYPE == 1 ) yyval.n->TYPE=0; else { yyval.n->TYPE=-1;
												yyerror("Read type error");}} else { printf("ID %s not found\n",yystack.l_mark[-2].n->NAME); yyval.n->TYPE=-1;}
											}}
break;
case 35:
#line 179 "symbol.y"
	{ yystack.l_mark[-5].n->center = yystack.l_mark[-3].n;  yystack.l_mark[-7].n = CreateNode(0,'r', 0, NULL, NULL, yystack.l_mark[-5].n, NULL); yyval.n = yystack.l_mark[-7].n;
												struct Gsymbol* gt = Glookup(yystack.l_mark[-5].n->NAME);
												if(gt) { if(gt->SIZE!=0 && gt->TYPE==1 && yystack.l_mark[-3].n->TYPE==1) yyval.n->TYPE=0; else { yyval.n->TYPE=-1;
												yyerror("Read type error");}} else { printf("ID %s not found\n",yystack.l_mark[-5].n->NAME); yyval.n->TYPE=-1;}
											}
break;
case 36:
#line 186 "symbol.y"
	{ yystack.l_mark[-4].n = CreateNode(0,'w', 0, NULL, NULL, yystack.l_mark[-2].n, NULL); yyval.n = yystack.l_mark[-4].n;
																			if(yystack.l_mark[-2].n->TYPE==1) yyval.n->TYPE=0; else {yyval.n->TYPE=-1; yyerror("Write error");} }
break;
case 37:
#line 190 "symbol.y"
	{ yystack.l_mark[-2].n = CreateNode(0,'R', 0, NULL, NULL, yystack.l_mark[-1].n, NULL);  yyval.n = yystack.l_mark[-2].n;
																			if(yystack.l_mark[-1].n->TYPE==1) yyval.n->TYPE=0; else {yyval.n->TYPE=-1; yyerror("Return type nomatch");}}
break;
case 38:
#line 194 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'+', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==1 && yystack.l_mark[0].n->TYPE ==1) yyval.n->TYPE=1; else yyval.n->TYPE=-1; }
break;
case 39:
#line 195 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'-', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==1 && yystack.l_mark[0].n->TYPE ==1) yyval.n->TYPE=1; else yyval.n->TYPE=-1;  }
break;
case 40:
#line 196 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'*', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==1 && yystack.l_mark[0].n->TYPE ==1) yyval.n->TYPE=1; else yyval.n->TYPE=-1;  }
break;
case 41:
#line 197 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'/', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n;  if(yystack.l_mark[-2].n->TYPE==1 && yystack.l_mark[0].n->TYPE ==1) yyval.n->TYPE=1; else yyval.n->TYPE=-1; }
break;
case 42:
#line 198 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'%', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==1 && yystack.l_mark[0].n->TYPE ==1) yyval.n->TYPE=1; else yyval.n->TYPE=-1;  }
break;
case 43:
#line 199 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'E', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==1 && yystack.l_mark[0].n->TYPE ==1) yyval.n->TYPE=2; else yyval.n->TYPE=-1;  }
break;
case 44:
#line 200 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'<', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==1 && yystack.l_mark[0].n->TYPE ==1) yyval.n->TYPE=2; else yyval.n->TYPE=-1;  }
break;
case 45:
#line 201 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'>', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==1 && yystack.l_mark[0].n->TYPE ==1) yyval.n->TYPE=2; else yyval.n->TYPE=-1;  }
break;
case 46:
#line 202 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'G', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==1 && yystack.l_mark[0].n->TYPE ==1) yyval.n->TYPE=2; else yyval.n->TYPE=-1;  }
break;
case 47:
#line 203 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'L', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==1 && yystack.l_mark[0].n->TYPE ==1) yyval.n->TYPE=2; else yyval.n->TYPE=-1;  }
break;
case 48:
#line 204 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'N', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==1 && yystack.l_mark[0].n->TYPE ==1) yyval.n->TYPE=2; else yyval.n->TYPE=-1;  }
break;
case 49:
#line 205 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'&', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==2 && yystack.l_mark[0].n->TYPE ==2) yyval.n->TYPE=2; else yyval.n->TYPE=-1;  }
break;
case 50:
#line 206 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'|', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==2 && yystack.l_mark[0].n->TYPE ==2) yyval.n->TYPE=2; else yyval.n->TYPE=-1;  }
break;
case 51:
#line 207 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'!', 0, NULL, NULL, yystack.l_mark[0].n, NULL); yyval.n = yystack.l_mark[-1].n;  if(yystack.l_mark[0].n->TYPE==2) yyval.n->TYPE=2; else yyval.n->TYPE=-1; }
break;
case 52:
#line 208 "symbol.y"
	{ yyval.n = yystack.l_mark[-1].n; }
break;
case 53:
#line 209 "symbol.y"
	{ yystack.l_mark[0].n = CreateNode(2,'T', 0, NULL,NULL,NULL,NULL); yyval.n = yystack.l_mark[0].n;  }
break;
case 54:
#line 210 "symbol.y"
	{ yystack.l_mark[0].n = CreateNode(2,'F', 0, NULL, NULL, NULL, NULL); yyval.n = yystack.l_mark[0].n; }
break;
case 55:
#line 211 "symbol.y"
	{ yyval.n=yystack.l_mark[0].n; }
break;
case 56:
#line 212 "symbol.y"
	{ yyval.n = yystack.l_mark[0].n; struct Lsymbol* lt = Llookup(yystack.l_mark[0].n->NAME); if(lt) yyval.n->TYPE=lt->TYPE; else {
															struct Gsymbol* gt = Glookup(yystack.l_mark[0].n->NAME);
															if(gt) {if(gt->SIZE==0) yyval.n->TYPE=gt->TYPE; else yyval.n->TYPE=-1; }
															else { printf("ID %s not found\n",yystack.l_mark[0].n->NAME); yyval.n->TYPE=-1;}}}
break;
case 57:
#line 216 "symbol.y"
	{   yystack.l_mark[-3].n->center = yystack.l_mark[-1].n; yyval.n = yystack.l_mark[-3].n;  struct Gsymbol* gt = Glookup(yystack.l_mark[-3].n->NAME);
																	if(gt) { if(gt->SIZE!=0 && yystack.l_mark[-1].n->TYPE==1)
																	yyval.n->TYPE=gt->TYPE; else yyval.n->TYPE=-1; }
																	else { printf("Array %s not found\n",yystack.l_mark[-3].n->NAME); yyval.n->TYPE=-1;}}
break;
#line 930 "y.tab.c"
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
