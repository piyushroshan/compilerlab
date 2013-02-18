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
	int BINDING; /* Address of the Identifier in Memory*/
	/*ArgStruct *ARGLIST; // Argument List for functions*/

	/***Argstruct must store the name and type of each argument ***/
	struct Gsymbol *NEXT; /* Pointer to next Symbol Table Entry * /*/
} *Gnode;

struct Lsymbol {
	/* Here only name, type, binding and pointer to next entry needed */
	char *NAME; /* Name of the Identifier*/
	int TYPE; /* TYPE can be INTEGER or BOOLEAN*/
	/***The TYPE field must be a TypeStruct if user defined types are allowed***/
	int BINDING; /* Address of the Identifier in Memory*/
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
    0,   22,   23,   23,   15,   16,   16,   17,   17,   21,
   21,    1,    2,   24,   25,   25,   19,   18,   18,   20,
    3,    4,    4,    5,    5,    5,    5,    5,    6,    6,
    7,   14,   14,    8,    8,    9,   10,   11,   11,   11,
   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,
   11,   11,   11,   11,   11,   11,   11,   11,   12,   12,
   12,   12,   12,   12,   12,   12,   12,   13,   13,   13,
   13,   13,   13,   13,   13,   13,   13,   13,   13,
};
static const short yylen[] = {                            2,
    2,    3,    0,    2,    3,    1,    3,    1,    1,    1,
    4,    7,    2,    3,    0,    2,    3,    1,    3,    1,
    4,    0,    2,    1,    1,    1,    1,    1,    6,    8,
    6,    4,    7,    5,    8,    5,    3,    3,    3,    3,
    3,    3,    3,    1,    3,    3,    3,    3,    3,    3,
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
    0,   65,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   21,   19,    0,    0,    0,
    0,    0,    0,   76,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   22,
   22,    0,    0,    0,    0,   37,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   32,    0,    0,    0,    0,   64,   77,   63,    0,
    0,    0,    0,    0,    0,    0,    0,   61,   62,   74,
   75,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   34,   36,   67,    0,   22,    0,    0,    0,    0,
   29,    0,   31,   33,    0,    0,   35,   30,
};
static const short yydgoto[] = {                          2,
    6,   26,   31,   35,   45,   46,   47,   48,   49,   50,
   73,   64,   75,   51,   10,   14,   11,   37,   34,   38,
   15,    3,    4,   27,   28,
};
static const short yysindex[] = {                      -250,
    0,    0, -249, -170, -274,    0,    0,    0,    0,    0,
 -231, -254, -207, -237,    0, -233, -196,    0, -231, -209,
 -175,    0, -157,    0,    0, -192, -167,  -56,    0,    0,
    0,    0, -135,    0, -259,    0, -101,    0, -261, -155,
 -143,  110,  110,  112,    0,    0,    0,    0,    0, -148,
    0,    0, -135, -238,  112,  -90, -238,  -78,    0,    0,
  110,    0,  110,  175,  -43, -241,  -75,    0,    0,  110,
    0,  110, -105,  186,  -40,    0,    0, -238,  -98,  -60,
 -262, -213, -238,    0,  141, -253, -238, -238, -238, -238,
 -238, -238, -238, -238, -238, -238, -238,  110,  110,    0,
    0, -238,    0,  152, -234,    0, -238, -238, -238, -238,
 -238, -238, -238, -238, -238, -238, -238,  110,  110,  -48,
  -64,    0, -238,  -51,  -26,  118,    0,    0,    0,  -10,
  -10,  -10,  -10,  -10,  -10, -165, -165,    0,    0,    0,
    0,  205,  -50,  124,    0,    0,    0,  -10,  -10,  -10,
  -10,  -10,  -10, -165, -165,    0,    0,    0,    0,  112,
  129,    0,    0,    0,  -22,    0,  -21,    0,  -15,  -47,
    0, -110,    0,    0,    1,   15,    0,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -45,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -176,    0,    0,
    0,    0,    0,    0,    0,    0,  -33, -172, -138,    0,
  -20,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -132,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -174,
 -136,  -89,  -76,  -74,  -61, -141, -109,    0,    0,    0,
    0,    0,    0,    0,    3,  -59,   14,  115,  223,  226,
  228,  230,  232,   60,   83,   37,   48,  236,  245,    0,
    0,    0,    0,    0,    0,    0,    0,   71,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
    0,    0,    0,  -92,    0,    0,    0,    0,    0,    0,
  -54,  -44,  -37,    0,    0,    0,  247,    0,    0,  224,
  257,    0,    0,    0,    0,
};
#define YYTABLESIZE 516
static const short yytable[] = {                         74,
   80,  123,   54,   39,   65,   66,    1,  142,  143,   79,
   74,    5,   82,   40,   41,   42,   98,   99,   85,   43,
   55,   18,   19,   84,   58,   86,   12,  104,   98,   99,
  124,   13,  103,  120,  105,   98,   99,   16,  126,  128,
   44,   62,  129,  130,  131,  132,  133,  134,  135,  136,
  137,  138,  139,   78,  101,   87,   17,  144,  146,   20,
  140,  141,  147,  148,  149,  150,  151,  152,  153,  154,
  155,  156,  157,  172,   94,   95,   96,   97,  161,  125,
  158,  159,   66,   21,   68,   23,   55,    7,   66,   24,
    8,    9,   66,   66,   66,   68,   68,   78,   78,   25,
   66,   29,   68,   87,   66,  169,   66,   66,   66,   66,
   66,   66,   66,   66,   66,   74,   66,   59,   68,   66,
   56,   68,   73,   59,   96,   97,   53,   36,   59,   59,
   30,   79,   79,   73,   73,   59,   56,   76,   76,   59,
   73,   59,   59,   59,   59,   59,   59,   59,   57,   60,
   76,   59,   39,  106,   59,   60,   73,   52,   53,   73,
   60,   60,   40,   41,   42,  176,  121,   60,   43,   69,
   87,   60,   81,   60,   60,   60,   60,   60,   60,   60,
   69,   69,   72,   60,   70,   83,   60,   69,  102,   94,
   95,   96,   97,   72,   72,   70,   70,   71,  122,   54,
   72,   32,   70,   69,    8,    9,   69,  162,   71,   71,
   77,   77,   39,   10,   10,   71,   72,  160,   70,   72,
   87,   70,   40,   41,   42,   57,   98,   99,   43,  118,
  119,   71,  163,  100,   71,   66,  171,  173,   44,   94,
   95,   96,   97,  174,  127,  175,  167,   66,   65,   66,
   66,   66,   66,   66,   66,   66,   66,   66,   87,  177,
   65,   43,   65,   65,   65,   65,   65,   65,   65,   65,
   65,   64,   42,  178,   33,   22,   77,   94,   95,   96,
   97,    0,   63,   64,    0,   64,   64,   64,   64,   64,
   64,   64,   64,   64,   63,   40,   63,   63,   63,   63,
   63,   63,   63,   63,   63,   61,   41,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   62,   61,   38,   61,
   61,   61,   61,   61,   61,   61,   61,   61,   62,   58,
   62,   62,   62,   62,   62,   62,   62,   62,   62,   67,
   59,   39,   59,   59,   59,   59,   59,   59,   59,    0,
    0,   67,    0,   67,   67,   67,   67,   67,   67,   67,
   67,   67,    0,   60,    0,   60,   60,   60,   60,   60,
   60,   60,   58,   45,   67,   59,   60,   68,   69,    0,
    0,   61,  164,   70,   68,   68,   87,    0,  168,   62,
    0,   71,   87,  170,    0,    0,    0,   87,    0,    0,
    0,   63,    0,   72,    0,   94,   95,   96,   97,   87,
    0,   94,   95,   96,   97,    0,   94,   95,   96,   97,
   87,   88,    0,   89,   90,   91,   92,   93,   94,   95,
   96,   97,   88,  127,   89,   90,   91,   92,   93,   94,
   95,   96,   97,   87,  145,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  107,   88,    0,   89,   90,   91,
   92,   93,   94,   95,   96,   97,  108,   39,  109,  110,
  111,  112,  113,  114,  115,  116,  117,   40,   41,   42,
  165,   50,  166,   43,   46,    0,   49,    0,   47,    0,
   48,    0,   73,   73,   51,   69,   69,   72,   72,   70,
   70,   71,   71,   52,    0,   74,   74,    0,    0,    0,
    0,    0,    0,    0,   75,   75,
};
static const short yycheck[] = {                         44,
   55,  264,  264,  263,   42,   43,  257,  100,  101,   54,
   55,  261,   57,  273,  274,  275,  270,  271,   63,  279,
  282,  259,  260,   61,  263,   63,  301,   72,  270,  271,
  293,  263,   70,   78,   72,  270,  271,  292,   83,  293,
  300,  280,   87,   88,   89,   90,   91,   92,   93,   94,
   95,   96,   97,  292,  296,  269,  264,  102,  293,  293,
   98,   99,  107,  108,  109,  110,  111,  112,  113,  114,
  115,  116,  117,  166,  288,  289,  290,  291,  123,  293,
  118,  119,  259,  280,  259,  295,  259,  258,  265,  265,
  261,  262,  269,  270,  271,  270,  271,  270,  271,  257,
  277,  294,  277,  269,  281,  160,  283,  284,  285,  286,
  287,  288,  289,  290,  291,  160,  293,  259,  293,  296,
  259,  296,  259,  265,  290,  291,  259,  263,  270,  271,
  298,  270,  271,  270,  271,  277,  292,  270,  271,  281,
  277,  283,  284,  285,  286,  287,  288,  289,  292,  259,
  299,  293,  263,  259,  296,  265,  293,  259,  260,  296,
  270,  271,  273,  274,  275,  276,  265,  277,  279,  259,
  269,  281,  263,  283,  284,  285,  286,  287,  288,  289,
  270,  271,  259,  293,  259,  264,  296,  277,  264,  288,
  289,  290,  291,  270,  271,  270,  271,  259,  259,  259,
  277,  258,  277,  293,  261,  262,  296,  259,  270,  271,
  270,  271,  263,  259,  260,  277,  293,  282,  293,  296,
  269,  296,  273,  274,  275,  259,  270,  271,  279,  270,
  271,  293,  259,  277,  296,  269,  259,  259,  259,  288,
  289,  290,  291,  259,  293,  293,  297,  281,  269,  283,
  284,  285,  286,  287,  288,  289,  290,  291,  269,  259,
  281,  259,  283,  284,  285,  286,  287,  288,  289,  290,
  291,  269,  259,  259,   28,   19,   53,  288,  289,  290,
  291,   -1,  269,  281,   -1,  283,  284,  285,  286,  287,
  288,  289,  290,  291,  281,  259,  283,  284,  285,  286,
  287,  288,  289,  290,  291,  269,  259,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  269,  281,  259,  283,
  284,  285,  286,  287,  288,  289,  290,  291,  281,  259,
  283,  284,  285,  286,  287,  288,  289,  290,  291,  269,
  281,  259,  283,  284,  285,  286,  287,  288,  289,   -1,
   -1,  281,   -1,  283,  284,  285,  286,  287,  288,  289,
  290,  291,   -1,  281,   -1,  283,  284,  285,  286,  287,
  288,  289,  263,  259,  263,  266,  267,  266,  267,   -1,
   -1,  272,  265,  272,  270,  271,  269,   -1,  265,  280,
   -1,  280,  269,  265,   -1,   -1,   -1,  269,   -1,   -1,
   -1,  292,   -1,  292,   -1,  288,  289,  290,  291,  269,
   -1,  288,  289,  290,  291,   -1,  288,  289,  290,  291,
  269,  281,   -1,  283,  284,  285,  286,  287,  288,  289,
  290,  291,  281,  293,  283,  284,  285,  286,  287,  288,
  289,  290,  291,  269,  293,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  269,  281,   -1,  283,  284,  285,
  286,  287,  288,  289,  290,  291,  281,  263,  283,  284,
  285,  286,  287,  288,  289,  290,  291,  273,  274,  275,
  276,  259,  278,  279,  259,   -1,  259,   -1,  259,   -1,
  259,   -1,  270,  271,  259,  270,  271,  270,  271,  270,
  271,  270,  271,  259,   -1,  270,  271,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  270,  271,
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
"return : RETURN expression SEMICOLON",
"expression : aexpression PLUS aexpression",
"expression : aexpression MINUS aexpression",
"expression : aexpression MULT aexpression",
"expression : aexpression DIVIDE aexpression",
"expression : aexpression MODULUS aexpression",
"expression : LPAREN aexpression RPAREN",
"expression : NUMBER",
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
"expression : ID",
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
#line 216 "symbol.y"

int main(){
	return(yyparse());
}

yyerror(s)
char *s;
{
  fprintf(stderr, "%s\n",s);
}



#line 522 "y.tab.c"

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
	{ printf("PARSING SUCCESS\n"); yyval.n=yystack.l_mark[0].n; PrintSymbol();}
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
	{  yyval.n=CreateNode(0,'S', 0, NULL, yystack.l_mark[-2].n, yystack.l_mark[-1].n, NULL);}
break;
case 22:
#line 135 "symbol.y"
	{ yyval.n = NULL; }
break;
case 23:
#line 136 "symbol.y"
	{  yyval.n=CreateNode(0,'S', 0, NULL, yystack.l_mark[0].n, yystack.l_mark[-1].n, NULL); }
break;
case 24:
#line 139 "symbol.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 25:
#line 140 "symbol.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 26:
#line 141 "symbol.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 27:
#line 142 "symbol.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 28:
#line 143 "symbol.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 29:
#line 146 "symbol.y"
	{ yystack.l_mark[-5].n = CreateNode(0,'I', 0, NULL, yystack.l_mark[-2].n, yystack.l_mark[-4].n, NULL); yyval.n = yystack.l_mark[-5].n; }
break;
case 30:
#line 147 "symbol.y"
	{ yystack.l_mark[-7].n = CreateNode(0,'I', 0, NULL, yystack.l_mark[-4].n, yystack.l_mark[-6].n, yystack.l_mark[-2].n); yyval.n = yystack.l_mark[-7].n; }
break;
case 31:
#line 150 "symbol.y"
	{ yystack.l_mark[-5].n = CreateNode(0,'W', 0, NULL, yystack.l_mark[-2].n, yystack.l_mark[-4].n, NULL); yyval.n=yystack.l_mark[-5].n; }
break;
case 32:
#line 153 "symbol.y"
	{ yystack.l_mark[-2].n = CreateNode(0,'=', 0, NULL, yystack.l_mark[-3].n, NULL, yystack.l_mark[-1].n); yyval.n=yystack.l_mark[-2].n; }
break;
case 33:
#line 154 "symbol.y"
	{ yystack.l_mark[-6].n->center = yystack.l_mark[-4].n; yystack.l_mark[-2].n = CreateNode(0,'=', 0, NULL, yystack.l_mark[-6].n, NULL, yystack.l_mark[-1].n); yyval.n=yystack.l_mark[-2].n;  }
break;
case 34:
#line 157 "symbol.y"
	{ yystack.l_mark[-4].n = CreateNode(0,'r', 0, NULL, NULL, yystack.l_mark[-2].n, NULL); yyval.n = yystack.l_mark[-4].n; }
break;
case 35:
#line 158 "symbol.y"
	{ yystack.l_mark[-5].n->center = yystack.l_mark[-3].n;  yystack.l_mark[-7].n = CreateNode(0,'r', 0, NULL, NULL, yystack.l_mark[-5].n, NULL); yyval.n = yystack.l_mark[-7].n; }
break;
case 36:
#line 161 "symbol.y"
	{ yystack.l_mark[-4].n = CreateNode(0,'w', 0, NULL, NULL, yystack.l_mark[-2].n, NULL); yyval.n = yystack.l_mark[-4].n; }
break;
case 37:
#line 164 "symbol.y"
	{ yystack.l_mark[-2].n = CreateNode(0,'R', 0, NULL, NULL, yystack.l_mark[-1].n, NULL); yyval.n = yystack.l_mark[-2].n; }
break;
case 38:
#line 167 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'+', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; }
break;
case 39:
#line 168 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'-', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; }
break;
case 40:
#line 169 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'*', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; }
break;
case 41:
#line 170 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'/', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; }
break;
case 42:
#line 171 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'%', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; }
break;
case 43:
#line 172 "symbol.y"
	{ yyval.n=yystack.l_mark[-1].n; }
break;
case 44:
#line 173 "symbol.y"
	{ yyval.n=yystack.l_mark[0].n; }
break;
case 45:
#line 174 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'E', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; }
break;
case 46:
#line 175 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'<', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; }
break;
case 47:
#line 176 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'>', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; }
break;
case 48:
#line 177 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'G', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; }
break;
case 49:
#line 178 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'L', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; }
break;
case 50:
#line 179 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'N', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; }
break;
case 51:
#line 180 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'&', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; }
break;
case 52:
#line 181 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'|', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; }
break;
case 53:
#line 182 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'!', 0, NULL, NULL, yystack.l_mark[0].n, NULL); yyval.n = yystack.l_mark[-1].n; }
break;
case 54:
#line 183 "symbol.y"
	{ yyval.n = yystack.l_mark[-1].n; }
break;
case 55:
#line 184 "symbol.y"
	{ yystack.l_mark[0].n = CreateNode(0,'T', 0, NULL,NULL,NULL,NULL); yyval.n = yystack.l_mark[0].n; }
break;
case 56:
#line 185 "symbol.y"
	{ yystack.l_mark[0].n = CreateNode(0,'F', 0, NULL, NULL, NULL, NULL); yyval.n = yystack.l_mark[0].n; }
break;
case 57:
#line 186 "symbol.y"
	{ yyval.n=yystack.l_mark[0].n; }
break;
case 58:
#line 187 "symbol.y"
	{   yystack.l_mark[-3].n->center = yystack.l_mark[-1].n; yyval.n = yystack.l_mark[-3].n;}
break;
case 59:
#line 190 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'+', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; }
break;
case 60:
#line 191 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'-', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; }
break;
case 61:
#line 192 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'*', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; }
break;
case 62:
#line 193 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'/', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; }
break;
case 63:
#line 194 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'%', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; }
break;
case 64:
#line 195 "symbol.y"
	{ yyval.n = yystack.l_mark[-1].n; }
break;
case 65:
#line 196 "symbol.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 66:
#line 197 "symbol.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 67:
#line 198 "symbol.y"
	{   yystack.l_mark[-3].n->center = yystack.l_mark[-1].n; yyval.n = yystack.l_mark[-3].n;}
break;
case 68:
#line 201 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'E', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; }
break;
case 69:
#line 202 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'<', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; }
break;
case 70:
#line 203 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'>', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; }
break;
case 71:
#line 204 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'G', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; }
break;
case 72:
#line 205 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'L', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; }
break;
case 73:
#line 206 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'N', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; }
break;
case 74:
#line 207 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'&', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; }
break;
case 75:
#line 208 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'|', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; }
break;
case 76:
#line 209 "symbol.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'!', 0, NULL, NULL, yystack.l_mark[0].n, NULL); yyval.n = yystack.l_mark[-1].n; }
break;
case 77:
#line 210 "symbol.y"
	{ yyval.n = yystack.l_mark[-1].n; }
break;
case 78:
#line 211 "symbol.y"
	{ yystack.l_mark[0].n = CreateNode(0,'T', 0, NULL,NULL,NULL,NULL); yyval.n = yystack.l_mark[0].n; }
break;
case 79:
#line 212 "symbol.y"
	{ yystack.l_mark[0].n = CreateNode(0,'F', 0, NULL, NULL, NULL, NULL); yyval.n = yystack.l_mark[0].n; }
break;
#line 1004 "y.tab.c"
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
