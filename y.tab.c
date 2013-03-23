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

#line 2 "code.y"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linklist.h"
#define INT 1
#define BOOL 2
#define SIZEOFINT 1 /*In SIM all memory location has size of 4bytes*/
#define SIZEOFBOOL 1    /*changing this sizes implies i have to change code for arrayindex*/
int current_reg;
static int current_temp=0;
char* itoa(int value);
#define INTSIZE 10

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

struct ArgStruct{
    char* ARGNAME;
    int ARGTYPE;
    int PASSTYPE;	/*0 Call By Value and 1 Call By Reference*/
    struct ArgStruct *ARGNEXT;
};

struct Gsymbol {
    char *NAME; /* Name of the Identifier*/
    int TYPE; /* TYPE can be INTEGER or BOOLEAN*/
    /***The TYPE field must be a TypeStruct if user defined types are allowed***/
    int VALUE; /* for constants*/
    int SIZE; /* Size field for arrays*/
    int BINDING; /* Address of the Identifier in Memory*/
    struct ArgStruct *ARGLIST; /* Argument List for functions*/

    /***Argstruct must store the name and type of each argument ***/
    struct Gsymbol *NEXT; /* Pointer to next Symbol Table Entry * /*/
} *Gnode;

struct Lsymbol {
    /* Here only name, type, binding and pointer to next entry needed */
    char *NAME; /* Name of the Identifier*/
    int TYPE; /* TYPE can be INTEGER or BOOLEAN*/
    /***The TYPE field must be a TypeStruct if user defined types are allowed***/
    int VALUE; /* for constants*/
    int BINDING; /* Address of the Identifier in Memory*/
    struct Lsymbol *NEXT; /* Pointer to next Symbol Table Entry * /*/
} *Lnode;



void printTree(struct node* root);
struct node* CreateNode(int TYPE1, int NODETYPE1, int VALUE1, char* NAME1, struct node *ptr1, struct node *ptr2, struct node *ptr3);
void Ginstall(char* NAME, int TYPE, int SIZE, int BINDING, int VALUE, struct ArgStruct* ARGLIST);
struct Gsymbol *Glookup(char* NAME);
struct Lsymbol *Llookup(char* NAME);
void Linstall(char* NAME, int TYPE, int BINDING, int VALUE);
void TAinstall(int op, char* op1, char* op2);
void print_TAlist();
int TYPE;
int RTYPE;
int FTYPE;
bool declaration ;  /*It's for deciding whether it's a context of declaration or definition in the case of functions*/
int Goffset;     /*It's for assigning location value to globalvariables*/
int Loffset;    /*It's for assigning location value to localvariables*/

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

#line 92 "code.y"
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
#line 119 "y.tab.c"

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
    3,    0,    2,    1,    1,    1,    1,    1,    6,    8,
    6,    4,    7,    5,    8,    5,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    2,    3,    1,    1,    1,    1,    4,
};
static const short yydefred[] = {                         0,
    3,    0,    0,    0,    0,    1,    2,    8,    9,    4,
    0,    0,    0,    0,    6,    0,    0,    5,    0,    0,
    0,    7,    0,   11,   15,    0,    0,    0,   12,   22,
   13,   14,    0,   16,    0,   20,    0,   18,    0,    0,
    0,    0,    0,   21,   23,   24,   25,   26,   27,   28,
   17,    0,    0,    0,    0,    0,    0,   53,   54,    0,
   55,    0,    0,    0,   19,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   22,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   22,    0,   32,    0,
    0,    0,    0,   52,   42,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   40,   41,    0,    0,
    0,   34,   36,   57,    0,   22,    0,    0,    0,   29,
    0,   31,   33,    0,    0,   35,   30,
};
static const short yydgoto[] = {                          2,
    6,   26,   31,   35,   45,   46,   47,   48,   49,    0,
   63,   50,   10,   14,   11,   37,   34,   38,   15,    3,
    4,   27,   28,
};
static const short yysindex[] = {                      -256,
    0,    0, -247, -255, -283,    0,    0,    0,    0,    0,
 -242, -259, -209, -234,    0, -230, -211,    0, -242, -229,
 -183,    0, -173,    0,    0, -208, -204, -253,    0,    0,
    0,    0, -168,    0, -251,    0, -206,    0, -262, -196,
 -194,  123,  123,    0,    0,    0,    0,    0,    0,    0,
    0, -168,  123,  123, -163,  123, -162,    0,    0,  123,
    0,  123,  290,  135,    0,  163,   71, -248,  240,  123,
 -138,  265,  123,  123,  123,    0,  123,  123,  123,  123,
  123,  123,  123,  123,  123,  123,    0, -172,    0,  123,
 -147, -145,  190,    0,    0,  301,  301,  134,  228,  228,
 -138, -138, -138, -138, -240, -240,    0,    0,   54,  123,
  217,    0,    0,    0, -140,    0, -139,   94, -169,    0,
 -214,    0,    0, -134, -133,    0,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -171,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -213,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -116,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -178,    3,    0,   30,   39,
  -87,  -58,  -29,    1, -180, -148,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
    0,    0,    0,  -72,    0,    0,    0,    0,    0,    0,
  -43,    0,    0,    0,   93,    0,    0,   75,  109,    0,
    0,    0,    0,
};
#define YYTABLESIZE 592
static const short yytable[] = {                         64,
    1,   53,    7,   98,   32,    8,    9,    8,    9,   66,
   67,   39,   69,    5,  109,   90,   71,   12,   72,   54,
   13,   40,   41,   42,   18,   19,   93,   43,   73,   95,
   96,   97,   16,   99,  100,  101,  102,  103,  104,  105,
  106,  107,  108,  121,   91,   56,  111,   44,   39,   85,
   86,   56,   51,   52,   17,   56,   56,   56,   40,   41,
   42,  125,   20,   56,   43,   23,  118,   56,   21,   56,
   56,   56,   56,   56,   56,   56,   56,   56,   38,   56,
   49,   24,   56,   25,   38,   29,   49,   10,   10,   38,
   38,   49,   49,   30,   36,   55,   38,   56,   49,   68,
   38,   70,   38,   38,   38,   38,   38,   38,   38,  110,
   39,  112,   38,  113,   49,   38,   39,   49,  120,  122,
   33,   39,   39,  124,  126,  127,   65,   22,   39,    0,
   73,    0,   39,    0,   39,   39,   39,   39,   39,   39,
   39,    0,   51,    0,   39,    0,    0,   39,   51,   83,
   84,   85,   86,   51,   51,    0,    0,    0,    0,    0,
   51,    0,    0,    0,   51,    0,   51,   51,   51,   51,
   51,   44,    0,    0,    0,    0,   51,   44,    0,   51,
    0,    0,   44,   44,    0,    0,    0,    0,    0,   44,
    0,    0,    0,   44,    0,   44,   44,   44,   44,   44,
   47,    0,    0,    0,    0,   44,   47,    0,   44,    0,
    0,   47,   47,    0,    0,    0,    0,    0,   47,    0,
    0,    0,   47,    0,   47,   47,   47,   47,   47,   45,
    0,    0,    0,    0,   47,   45,    0,   47,    0,    0,
   45,   45,    0,    0,    0,    0,    0,   45,    0,    0,
    0,   45,    0,   45,   45,   45,   45,   45,    0,   46,
    0,   50,    0,   45,    0,   46,   45,   50,    0,    0,
   46,   46,   50,   50,    0,    0,    0,   46,    0,   50,
    0,   46,    0,   46,   46,   46,   46,   46,   43,    0,
    0,    0,    0,   46,   43,   50,   46,   48,   50,   43,
   43,    0,    0,   48,    0,    0,   43,    0,   48,   48,
   43,    0,   43,    0,    0,   48,   39,    0,    0,   48,
    0,   48,   43,    0,    0,   43,   40,   41,   42,   89,
    0,   48,   43,    0,   48,    0,    0,    0,    0,   73,
   74,   75,    0,    0,    0,    0,    0,    0,    0,    0,
  117,   77,  123,   78,   79,   80,   81,   82,   83,   84,
   85,   86,   73,   74,   75,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   77,    0,   78,   79,   80,   81,
   82,   83,   84,   85,   86,   57,    0,    0,   58,   59,
    0,    0,    0,    0,   60,    0,   39,    0,    0,    0,
    0,    0,   61,   73,   74,   75,   40,   41,   42,  115,
    0,  116,   43,    0,   62,   77,    0,   78,   79,   80,
   81,   82,   83,   84,   85,   86,    0,   88,    0,    0,
   87,   73,   74,   75,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   77,    0,   78,   79,   80,   81,   82,
   83,   84,   85,   86,  114,    0,    0,    0,   73,   74,
   75,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   77,    0,   78,   79,   80,   81,   82,   83,   84,   85,
   86,  119,    0,    0,    0,   73,   74,   75,    0,    0,
    0,    0,    0,    0,    0,    0,   73,   77,    0,   78,
   79,   80,   81,   82,   83,   84,   85,   86,   73,   74,
   75,   79,   80,   81,   82,   83,   84,   85,   86,    0,
   77,    0,   78,   79,   80,   81,   82,   83,   84,   85,
   86,    0,   92,   73,   74,   75,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   77,    0,   78,   79,   80,
   81,   82,   83,   84,   85,   86,    0,   94,   73,   74,
   75,    0,    0,    0,    0,    0,   76,    0,    0,   73,
   77,    0,   78,   79,   80,   81,   82,   83,   84,   85,
   86,   77,    0,   78,   79,   80,   81,   82,   83,   84,
   85,   86,
};
static const short yycheck[] = {                         43,
  257,  264,  258,   76,  258,  261,  262,  261,  262,   53,
   54,  263,   56,  261,   87,  264,   60,  301,   62,  282,
  263,  273,  274,  275,  259,  260,   70,  279,  269,   73,
   74,   75,  292,   77,   78,   79,   80,   81,   82,   83,
   84,   85,   86,  116,  293,  259,   90,  299,  263,  290,
  291,  265,  259,  260,  264,  269,  270,  271,  273,  274,
  275,  276,  293,  277,  279,  295,  110,  281,  280,  283,
  284,  285,  286,  287,  288,  289,  290,  291,  259,  293,
  259,  265,  296,  257,  265,  294,  265,  259,  260,  270,
  271,  270,  271,  298,  263,  292,  277,  292,  277,  263,
  281,  264,  283,  284,  285,  286,  287,  288,  289,  282,
  259,  259,  293,  259,  293,  296,  265,  296,  259,  259,
   28,  270,  271,  293,  259,  259,   52,   19,  277,   -1,
  269,   -1,  281,   -1,  283,  284,  285,  286,  287,  288,
  289,   -1,  259,   -1,  293,   -1,   -1,  296,  265,  288,
  289,  290,  291,  270,  271,   -1,   -1,   -1,   -1,   -1,
  277,   -1,   -1,   -1,  281,   -1,  283,  284,  285,  286,
  287,  259,   -1,   -1,   -1,   -1,  293,  265,   -1,  296,
   -1,   -1,  270,  271,   -1,   -1,   -1,   -1,   -1,  277,
   -1,   -1,   -1,  281,   -1,  283,  284,  285,  286,  287,
  259,   -1,   -1,   -1,   -1,  293,  265,   -1,  296,   -1,
   -1,  270,  271,   -1,   -1,   -1,   -1,   -1,  277,   -1,
   -1,   -1,  281,   -1,  283,  284,  285,  286,  287,  259,
   -1,   -1,   -1,   -1,  293,  265,   -1,  296,   -1,   -1,
  270,  271,   -1,   -1,   -1,   -1,   -1,  277,   -1,   -1,
   -1,  281,   -1,  283,  284,  285,  286,  287,   -1,  259,
   -1,  259,   -1,  293,   -1,  265,  296,  265,   -1,   -1,
  270,  271,  270,  271,   -1,   -1,   -1,  277,   -1,  277,
   -1,  281,   -1,  283,  284,  285,  286,  287,  259,   -1,
   -1,   -1,   -1,  293,  265,  293,  296,  259,  296,  270,
  271,   -1,   -1,  265,   -1,   -1,  277,   -1,  270,  271,
  281,   -1,  283,   -1,   -1,  277,  263,   -1,   -1,  281,
   -1,  283,  293,   -1,   -1,  296,  273,  274,  275,  259,
   -1,  293,  279,   -1,  296,   -1,   -1,   -1,   -1,  269,
  270,  271,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  297,  281,  259,  283,  284,  285,  286,  287,  288,  289,
  290,  291,  269,  270,  271,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  281,   -1,  283,  284,  285,  286,
  287,  288,  289,  290,  291,  263,   -1,   -1,  266,  267,
   -1,   -1,   -1,   -1,  272,   -1,  263,   -1,   -1,   -1,
   -1,   -1,  280,  269,  270,  271,  273,  274,  275,  276,
   -1,  278,  279,   -1,  292,  281,   -1,  283,  284,  285,
  286,  287,  288,  289,  290,  291,   -1,  265,   -1,   -1,
  296,  269,  270,  271,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  281,   -1,  283,  284,  285,  286,  287,
  288,  289,  290,  291,  265,   -1,   -1,   -1,  269,  270,
  271,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  281,   -1,  283,  284,  285,  286,  287,  288,  289,  290,
  291,  265,   -1,   -1,   -1,  269,  270,  271,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  269,  281,   -1,  283,
  284,  285,  286,  287,  288,  289,  290,  291,  269,  270,
  271,  284,  285,  286,  287,  288,  289,  290,  291,   -1,
  281,   -1,  283,  284,  285,  286,  287,  288,  289,  290,
  291,   -1,  293,  269,  270,  271,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  281,   -1,  283,  284,  285,
  286,  287,  288,  289,  290,  291,   -1,  293,  269,  270,
  271,   -1,   -1,   -1,   -1,   -1,  277,   -1,   -1,  269,
  281,   -1,  283,  284,  285,  286,  287,  288,  289,  290,
  291,  281,   -1,  283,  284,  285,  286,  287,  288,  289,
  290,  291,
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
"beginbody : BEGINN statements END",
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
#line 293 "code.y"

int main(){
    Goffset = 0;

    yyparse();
    /*printf("\nSTART\n");
		printf("MOV R1,%d\n",Goffset-1);
		printf("INR R1\n");
		printf("MOV SP,R1\n");
		printf("MOV %s,SP\n",reg3);
		printf("MOV %s,%d\n",reg4,l_getarglocalsize(gtable,"main"));
		printf("ADD %s,%s\n",reg3,reg4);
		printf("MOV SP,%s\n",reg3);
		printf("CALL Pmain\n");
		printf("MOV %s,SP\n",reg3);
		printf("MOV %s,%d\n",reg4,l_getarglocalsize(gtable,"main"));
		printf("SUB %s,%s\n",reg3,reg4);
		printf("MOV SP,%s\n",reg3);
		printf("MOV R1,%d\n",Goffset-1);
		printf("HALT\n");*/
}

/*char* newreg3()
{
	char *temp =(char *) malloc(5);
	temp[0]='R';temp[1]='\0';
	for(int i=2;i<100;i++)
	{
		temp[0]='R';temp[1]='\0';
		strcat(temp,itoa(i));
		if(reglist.member(temp)==-1)
		{
			printf("//Allocated from here\n");
			return temp;
		}
	}
	strcat(temp,itoa(current_reg));
	current_reg++;

	//printf("*********Newreg %s\n",temp);
	return temp;
}

char* newreg()
{
	char *temp =(char *) malloc(5);
	temp[0]='R';temp[1]='\0';
	strcat(temp,itoa(current_reg));
	current_reg++;

	//printf("*********Newreg %s\n",temp);
	return temp;
}

char* newlabel()
{
	static int current = 0;
	current++;
	char *temp =(char *) malloc(5);
	temp[0]='L';temp[1]='\0';
	strcat(temp,itoa(current));

	//printf("Newlabel %s\n",temp);
	return temp;
}*/

char* itoa(int value)
{
    char *temp=(char *)malloc(10);
    int i;

    if(value==0)
    {
        temp[8]='0';
        temp[9]='\0';
        return(temp+8);
    }

    for(i=8; i>0 && value ; i-- , value = value /10)
    {
        temp[i]=(char ) (48 + value%10 );
    }
    temp[9]='\0';

    return (temp+i+1);

}

char* newlabel() {
    static int num = 1;
    char *temp =(char *) malloc(5);
    temp[0]='L';temp[1]='\0';
    strcat(temp,itoa(num));
    num++;
    return temp;
}

void Gen3A(struct node* root){
    if(root==NULL){
        return;
    }

    switch(root->NODETYPE){
        case 'f' :
        {
            char* label=newlabel();
            TAinstall('L',root->NAME,NULL);
            Gen3A(root->center);
            break;
        }
        case 'S':
            Gen3A(root->left);
            Gen3A(root->center);
            break;
        case 'I':{
            char* label;
            strcpy(label,newlabel());
            Gen3A(root->center);
            char t[5] = "t";
            strcat(t,itoa(current_temp));
            TAinstall('I',t,label);
            Gen3A(root->left);

            if(root->right){
                char* endif = newlabel();
                TAinstall('G',endif,NULL);
                TAinstall('L',label,NULL);
                Gen3A(root->right);
                TAinstall('L',endif,NULL);
            }else{
                TAinstall('L',label,NULL);
            }
            break;
        }
        case 'W':{
            char* l1=newlabel();
            char* l2=newlabel();
            TAinstall('L',l1,NULL);
            Gen3A(root->center);
            char *t =(char *) malloc(5);
            t[0]='t';t[1]='\0';
            strcat(t,itoa(current_temp));
            TAinstall('I',t,l2);
            Gen3A(root->left);
            TAinstall('G',l1,NULL);
            TAinstall('L',l2,NULL);
            break;
        }
        case 'r':
        {
            Gen3A(root->center);
            char *t =(char *) malloc(5);
            t[0]='t';t[1]='\0';
            strcat(t,itoa(current_temp));
            TAinstall('r',t,NULL);
            break;
        }
        case 'w':
        {
            Gen3A(root->center);
            char *t =(char *) malloc(5);
            t[0]='t';t[1]='\0';
            strcat(t,itoa(current_temp));
            TAinstall('w',t,NULL);

            break;
        }
        case 'R':
        {
            Gen3A(root->center);
            char *t =(char *) malloc(5);
            t[0]='t';t[1]='\0';
            strcat(t,itoa(current_temp));
            TAinstall('R',t,NULL);
            break;
        }
        case '=':
        {
            Gen3A(root->left);
            char *t1 =(char *) malloc(5);
            t1[0]='t';t1[1]='\0';
            strcat(t1,itoa(current_temp));
            Gen3A(root->right);
            char *t2 =(char *) malloc(5);
            t2[0]='t';t2[1]='\0';
            strcat(t2,itoa(current_temp));
            TAinstall('=',t1,t2);
            break;
        }
        case '+':
        {
            Gen3A(root->left);
            Gen3A(root->right);
            char *t1 =(char *) malloc(5);
            t1[0]='t';t1[1]='\0';
            strcat(t1,itoa(current_temp-2));
            char *t2 =(char *) malloc(5);
            t2[0]='t';t2[1]='\0';
            strcat(t2,itoa(current_temp-1));
            TAinstall('+', t1, t2);
            current_temp--;
            break;
        }
        case '-':
        {
            Gen3A(root->left);
            char *t1 =(char *) malloc(5);
            t1[0]='t';t1[1]='\0';
            strcat(t1,itoa(current_temp));
            Gen3A(root->right);
            char *t2 =(char *) malloc(5);
            t2[0]='t';t2[1]='\0';
            strcat(t2,itoa(current_temp));
            TAinstall('-', t1, t2);
            break;
        }
        case '*':
        {
            Gen3A(root->left);
            char *t1 =(char *) malloc(5);
            t1[0]='t';t1[1]='\0';
            strcat(t1,itoa(current_temp));
            Gen3A(root->right);
            char *t2 =(char *) malloc(5);
            t2[0]='t';t2[1]='\0';
            strcat(t2,itoa(current_temp));
            TAinstall('*', t1, t2);
            break;
        }
        case '/':
        {
            Gen3A(root->left);
            char *t1 =(char *) malloc(5);
            t1[0]='t';t1[1]='\0';
            strcat(t1,itoa(current_temp));
            Gen3A(root->right);
            char *t2 =(char *) malloc(5);
            t2[0]='t';t2[1]='\0';
            strcat(t2,itoa(current_temp));
            TAinstall('/', t1, t2);
            break;
        }
        case '%':
        {
            Gen3A(root->left);
            char *t1 =(char *) malloc(5);
            t1[0]='t';t1[1]='\0';
            strcat(t1,itoa(current_temp));
            Gen3A(root->right);
            char *t2 =(char *) malloc(5);
            t2[0]='t';t2[1]='\0';
            strcat(t2,itoa(current_temp));
            TAinstall('%', t1, t2);
            break;
        }
        case 'T' :
        {
            current_temp++;
            char *t =(char *) malloc(5);
            t[0]='t';t[1]='\0';
            strcat(t,itoa(current_temp));
            TAinstall('=',t,"T");
            break;
        }
        case 'F' :
        {
            current_temp++;
            char *t =(char *) malloc(5);
            t[0]='t';t[1]='\0';
            strcat(t,itoa(current_temp));
            TAinstall('=',t,"F");
            break;
        }
       case 1:
        {
            current_temp++;
            char *t =(char *) malloc(5);
            t[0]='t';t[1]='\0';
            strcat(t,itoa(current_temp));
            TAinstall('=',t,itoa(root->VALUE));
            break;
        }
        case 2:
        {
            if(root->center){
                Gen3A(root->center);
                char *t =(char *) malloc(5);
                t[0]='t';t[1]='\0';
                strcat(t,itoa(current_temp));
                TAinstall('l',root->NAME,t);
                current_temp++;
                char *t1 =(char *) malloc(5);
                t1[0]='t';t1[1]='\0';
                strcat(t1,itoa(current_temp));
                TAinstall('=',t1,t);
            }else
            {
                char *t =(char *) malloc(5);
                t[0]='t';t[1]='\0';
                strcat(t,itoa(current_temp));
                if(Glookup(root->NAME))
                    TAinstall('l',t,itoa(Glookup(root->NAME)->BINDING));
                else
                    TAinstall('l',t,itoa(Llookup(root->NAME)->BINDING));
            }
            break;
        }
        default:
        {

            return;
        }
        break;
    }
}

yyerror(s)
char *s;
{
fprintf(stderr, "%s\n",s);
}


#line 835 "y.tab.c"

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
#line 120 "code.y"
	{ printf("PARSING SUCCESS\n"); yyval.n=yystack.l_mark[0].n; PrintSymbol(); printTree(yystack.l_mark[0].n); Gen3A(yystack.l_mark[0].n); print_TAlist();}
break;
case 3:
#line 124 "code.y"
	{/*empty*/}
break;
case 8:
#line 132 "code.y"
	{ TYPE = INT; }
break;
case 9:
#line 133 "code.y"
	{TYPE = BOOL; }
break;
case 10:
#line 136 "code.y"
	{
            printf("*****offset of %s is %d\n",yystack.l_mark[0].n->NAME,Goffset);
            Ginstall(yystack.l_mark[0].n->NAME, TYPE, 0, Goffset, 0, NULL);
            /*-----------Code Generation-------------------*/
            switch(TYPE)
            {
                case INT:
                    Goffset += SIZEOFINT;
                    break;
                case BOOL:
                    Goffset += SIZEOFBOOL;
                    break;
            }
            /*---------------------------------------------*/
        }
break;
case 11:
#line 151 "code.y"
	{
                                Ginstall(yystack.l_mark[-3].n->NAME, TYPE+2, yystack.l_mark[-1].n->VALUE, Goffset, 0, NULL);
                                /*-----------Code Generation-------------------*/
                                switch(TYPE)
                                {
                                    case INT :
                                        Goffset += SIZEOFINT*yystack.l_mark[-1].n->VALUE;
                                        break;
                                    case BOOL :
                                        Goffset += SIZEOFBOOL*yystack.l_mark[-1].n->VALUE;
                                        break;
                                }
                                /*---------------------------------------------*/
                            }
break;
case 12:
#line 167 "code.y"
	{ yyval.n=CreateNode(0,'f', 0, "MAIN", NULL, yystack.l_mark[-1].n, NULL);}
break;
case 13:
#line 170 "code.y"
	{ yyval.n=yystack.l_mark[0].n; }
break;
case 15:
#line 175 "code.y"
	{/*empty*/}
break;
case 20:
#line 184 "code.y"
	{
        printf("*****L offset of %s is %d\n",yystack.l_mark[0].n->NAME,Loffset);
        Linstall(yystack.l_mark[0].n->NAME, TYPE, Loffset, 0);
        /*-----------Code Generation-------------------*/
        switch(TYPE)
        {
            case INT :
                Loffset += SIZEOFINT;
                break;
            case BOOL :
                Loffset += SIZEOFBOOL;
                break;
        }
        /*---------------------------------------------*/
    }
break;
case 21:
#line 201 "code.y"
	{  yyval.n=CreateNode(0,'S', 0, NULL, yystack.l_mark[-1].n, NULL, NULL); if ((yystack.l_mark[-1].n==NULL || yystack.l_mark[-1].n->TYPE==0) && yystack.l_mark[0].n->TYPE==0) yyval.n->TYPE=0; else yyval.n->TYPE=-1; }
break;
case 22:
#line 204 "code.y"
	{ yyval.n = NULL; }
break;
case 23:
#line 205 "code.y"
	{  yyval.n=CreateNode(0,'S', 0, NULL, yystack.l_mark[-1].n, yystack.l_mark[0].n, NULL); if ((yystack.l_mark[-1].n==NULL || yystack.l_mark[-1].n->TYPE==0) && yystack.l_mark[0].n->TYPE==0) yyval.n->TYPE=0; else {yyval.n->TYPE=-1; yyerror("error");}}
break;
case 24:
#line 208 "code.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 25:
#line 209 "code.y"
	{ yyval.n = yystack.l_mark[0].n;}
break;
case 26:
#line 210 "code.y"
	{ yyval.n = yystack.l_mark[0].n;  }
break;
case 27:
#line 211 "code.y"
	{ yyval.n = yystack.l_mark[0].n;  }
break;
case 28:
#line 212 "code.y"
	{ yyval.n = yystack.l_mark[0].n;  }
break;
case 29:
#line 215 "code.y"
	{ yystack.l_mark[-5].n = CreateNode(0,'I', 0, NULL, yystack.l_mark[-2].n, yystack.l_mark[-4].n, NULL); yyval.n = yystack.l_mark[-5].n;
                                                if (yystack.l_mark[-4].n->TYPE==2 && (yystack.l_mark[-2].n==NULL || yystack.l_mark[-2].n->TYPE==0)) yyval.n->TYPE=0; else yyval.n->TYPE=-1;  }
break;
case 30:
#line 217 "code.y"
	{ yystack.l_mark[-7].n = CreateNode(0,'I', 0, NULL, yystack.l_mark[-4].n, yystack.l_mark[-6].n, yystack.l_mark[-2].n); yyval.n = yystack.l_mark[-7].n;
                                                if (yystack.l_mark[-6].n->TYPE==2 && (yystack.l_mark[-4].n==NULL || yystack.l_mark[-4].n->TYPE==0) && (yystack.l_mark[-2].n==NULL || yystack.l_mark[-2].n->TYPE==0)) yyval.n->TYPE=0; else yyval.n->TYPE=-1; }
break;
case 31:
#line 221 "code.y"
	{ yystack.l_mark[-5].n = CreateNode(0,'W', 0, NULL, yystack.l_mark[-2].n, yystack.l_mark[-4].n, NULL); yyval.n=yystack.l_mark[-5].n; if (yystack.l_mark[-4].n->TYPE==2 && (yystack.l_mark[-2].n==NULL || yystack.l_mark[-2].n->TYPE==0)) yyval.n->TYPE=0; else yyval.n->TYPE=-1; }
break;
case 32:
#line 224 "code.y"
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
#line 232 "code.y"
	{ yystack.l_mark[-6].n->center = yystack.l_mark[-4].n; yystack.l_mark[-2].n = CreateNode(0,'=', 0, NULL, yystack.l_mark[-6].n, NULL, yystack.l_mark[-1].n); yyval.n=yystack.l_mark[-2].n;
                                                                struct Gsymbol* gt = Glookup(yystack.l_mark[-6].n->NAME);
                                                                if(gt) {if ( gt->SIZE!=0 && yystack.l_mark[-4].n->TYPE==INT && ((gt->TYPE-2) == yystack.l_mark[-1].n->TYPE)) yyval.n->TYPE=0; else { yyval.n->TYPE=-1;
                                                                yyerror("Wrong assignment of array type");}} else {printf("Array %s not found\n",yystack.l_mark[-6].n->NAME); yyval.n->TYPE=-1; }
                                                            }
break;
case 34:
#line 239 "code.y"
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
#line 248 "code.y"
	{ yystack.l_mark[-5].n->center = yystack.l_mark[-3].n;  yystack.l_mark[-7].n = CreateNode(0,'r', 0, NULL, NULL, yystack.l_mark[-5].n, NULL); yyval.n = yystack.l_mark[-7].n;
                                                struct Gsymbol* gt = Glookup(yystack.l_mark[-5].n->NAME);
                                                if(gt) { if(gt->SIZE!=0 && gt->TYPE==(INT+2) && yystack.l_mark[-3].n->TYPE==1) yyval.n->TYPE=0; else { yyval.n->TYPE=-1;
                                                yyerror("Read type error");}} else { printf("ID %s not found\n",yystack.l_mark[-5].n->NAME); yyval.n->TYPE=-1;}
                                            }
break;
case 36:
#line 255 "code.y"
	{ yystack.l_mark[-4].n = CreateNode(0,'w', 0, NULL, NULL, yystack.l_mark[-2].n, NULL); yyval.n = yystack.l_mark[-4].n;
                                                                            if(yystack.l_mark[-2].n->TYPE==1) yyval.n->TYPE=0; else {yyval.n->TYPE=-1; yyerror("Write error");} }
break;
case 37:
#line 259 "code.y"
	{ yystack.l_mark[-2].n = CreateNode(0,'R', 0, NULL, NULL, yystack.l_mark[-1].n, NULL);  yyval.n = yystack.l_mark[-2].n;
                                                                            if(yystack.l_mark[-1].n->TYPE==1) yyval.n->TYPE=0; else {yyval.n->TYPE=-1; yyerror("Return type nomatch");}}
break;
case 38:
#line 263 "code.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'+', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==1 && yystack.l_mark[0].n->TYPE ==1) yyval.n->TYPE=1; else yyval.n->TYPE=-1; }
break;
case 39:
#line 264 "code.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'-', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==1 && yystack.l_mark[0].n->TYPE ==1) yyval.n->TYPE=1; else yyval.n->TYPE=-1;  }
break;
case 40:
#line 265 "code.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'*', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==1 && yystack.l_mark[0].n->TYPE ==1) yyval.n->TYPE=1; else yyval.n->TYPE=-1;  }
break;
case 41:
#line 266 "code.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'/', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n;  if(yystack.l_mark[-2].n->TYPE==1 && yystack.l_mark[0].n->TYPE ==1) yyval.n->TYPE=1; else yyval.n->TYPE=-1; }
break;
case 42:
#line 267 "code.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'%', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==1 && yystack.l_mark[0].n->TYPE ==1) yyval.n->TYPE=1; else yyval.n->TYPE=-1;  }
break;
case 43:
#line 268 "code.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'E', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==1 && yystack.l_mark[0].n->TYPE ==1) yyval.n->TYPE=2; else yyval.n->TYPE=-1;  }
break;
case 44:
#line 269 "code.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'<', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==1 && yystack.l_mark[0].n->TYPE ==1) yyval.n->TYPE=2; else yyval.n->TYPE=-1;  }
break;
case 45:
#line 270 "code.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'>', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==1 && yystack.l_mark[0].n->TYPE ==1) yyval.n->TYPE=2; else yyval.n->TYPE=-1;  }
break;
case 46:
#line 271 "code.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'G', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==1 && yystack.l_mark[0].n->TYPE ==1) yyval.n->TYPE=2; else yyval.n->TYPE=-1;  }
break;
case 47:
#line 272 "code.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'L', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==1 && yystack.l_mark[0].n->TYPE ==1) yyval.n->TYPE=2; else yyval.n->TYPE=-1;  }
break;
case 48:
#line 273 "code.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'N', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==1 && yystack.l_mark[0].n->TYPE ==1) yyval.n->TYPE=2; else yyval.n->TYPE=-1;  }
break;
case 49:
#line 274 "code.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'&', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==2 && yystack.l_mark[0].n->TYPE ==2) yyval.n->TYPE=2; else yyval.n->TYPE=-1;  }
break;
case 50:
#line 275 "code.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'|', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==2 && yystack.l_mark[0].n->TYPE ==2) yyval.n->TYPE=2; else yyval.n->TYPE=-1;  }
break;
case 51:
#line 276 "code.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'!', 0, NULL, NULL, yystack.l_mark[0].n, NULL); yyval.n = yystack.l_mark[-1].n;  if(yystack.l_mark[0].n->TYPE==2) yyval.n->TYPE=2; else yyval.n->TYPE=-1; }
break;
case 52:
#line 277 "code.y"
	{ yyval.n = yystack.l_mark[-1].n; }
break;
case 53:
#line 278 "code.y"
	{ yystack.l_mark[0].n = CreateNode(2,'T', 0, NULL,NULL,NULL,NULL); yyval.n = yystack.l_mark[0].n;  }
break;
case 54:
#line 279 "code.y"
	{ yystack.l_mark[0].n = CreateNode(2,'F', 0, NULL, NULL, NULL, NULL); yyval.n = yystack.l_mark[0].n; }
break;
case 55:
#line 280 "code.y"
	{ yyval.n=yystack.l_mark[0].n; }
break;
case 56:
#line 281 "code.y"
	{ yyval.n = yystack.l_mark[0].n; struct Lsymbol* lt = Llookup(yystack.l_mark[0].n->NAME); if(lt) yyval.n->TYPE=lt->TYPE; else {
                                                            struct Gsymbol* gt = Glookup(yystack.l_mark[0].n->NAME);
                                                            if(gt) {if(gt->SIZE==0) yyval.n->TYPE=gt->TYPE; else yyval.n->TYPE=-1; }
                                                            else { printf("ID %s not found\n",yystack.l_mark[0].n->NAME); yyval.n->TYPE=-1;}}}
break;
case 57:
#line 285 "code.y"
	{   yystack.l_mark[-3].n->center = yystack.l_mark[-1].n; yyval.n = yystack.l_mark[-3].n;  struct Gsymbol* gt = Glookup(yystack.l_mark[-3].n->NAME);
                                                                    if(gt) { if(gt->SIZE!=0 && yystack.l_mark[-1].n->TYPE==1)
                                                                    yyval.n->TYPE=gt->TYPE; else yyval.n->TYPE=-1; }
                                                                    else { printf("Array %s not found\n",yystack.l_mark[-3].n->NAME); yyval.n->TYPE=-1;}}
break;
#line 1303 "y.tab.c"
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
