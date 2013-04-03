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

#line 2 "func.y"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linklist.h"
#define INT 1
#define BOOL 2
#define FUNC 6
#define SIZEOFINT 1 /*In SIM all memory location has size of 4bytes*/
#define SIZEOFBOOL 1    /*changing this sizes implies i have to change code for arrayindex*/
int current_reg;
static int current_temp=0;

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
    struct	node 	*center, *left,	*right;
    struct ArgStruct *argList;
    struct Gsymbol *lookup;
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


int GetGtableSize();
void printTree(struct node* root);
struct node* CreateNode(int TYPE1, int NODETYPE1, int VALUE1, char* NAME1, struct node *ptr1, struct node *ptr2, struct node *ptr3);
void Ginstall(char* NAME, int TYPE, int SIZE, int BINDING, int VALUE, struct ArgStruct* ARGLIST);
struct Gsymbol *Glookup(char* NAME);
struct Lsymbol *Llookup(char* NAME);
void Linstall(char* NAME, int TYPE, int BINDING, int VALUE);
void TAinstall(char op, char* op1, char* op2,char* op3);
void print_TAlist();
void codeGen();
void Gen3A(struct node* root, int flag);
int TYPE;
int RTYPE;
int FTYPE;
bool declaration ;  /*It's for deciding whether it's a context of declaration or definition in the case of functions*/
int Goffset;     /*It's for assigning location value to globalvariables*/
int Loffset;    /*It's for assigning location value to localvariables*/


int pcount=0; /*count parameters*/

int returnmem = 4000;
int mem = 1000;
int argc = 0;
int fcount = 0;


/*  Adding arguments*/
struct ArgStruct* headArg = NULL;
struct ArgStruct* newArg;


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


struct istack
{
 int value;
 struct istack *next;
}*itop;

struct wstack{
 int value;
 struct wstack *next;
}*wtop;

#line 121 "func.y"
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
#line 148 "y.tab.c"

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
    0,   31,   32,   32,   23,   24,   24,   25,   25,   16,
   16,   19,   19,   20,   20,   17,   17,   22,   21,   21,
   18,   18,   13,   13,   14,   29,   29,   29,    1,    2,
   33,   34,   34,   27,   26,   26,   28,    3,    4,    4,
    5,    5,    5,    5,    5,    6,    6,    7,   12,   12,
    8,    8,    9,   10,   11,   11,   11,   11,   11,   11,
   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,
   11,   11,   11,   11,   11,   30,   30,   15,   15,
};
static const short yylen[] = {                            2,
    3,    3,    0,    2,    3,    1,    3,    1,    1,    0,
    1,    0,    1,    3,    1,    3,    1,    2,    3,    1,
    1,    2,    0,    2,    8,    1,    4,    4,    7,    2,
    3,    0,    2,    3,    1,    3,    1,    4,    0,    2,
    1,    1,    1,    1,    1,    6,    8,    6,    4,    7,
    5,    8,    5,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    2,    3,    1,
    1,    1,    1,    4,    4,    0,    1,    3,    1,
};
static const short yydefred[] = {                         0,
    3,    0,   23,    0,    0,    2,    8,    9,    4,    0,
    0,    1,   24,    0,    0,    0,    6,    0,    0,    0,
    0,    5,    0,    0,    0,    0,    0,    0,   17,    0,
    7,    0,    0,    0,   15,   27,   28,    0,   21,    0,
   20,    0,    0,    0,    0,   16,   22,    0,   32,    0,
    0,    0,   14,   19,    0,   29,   39,   30,    0,   31,
    0,   33,    0,   25,   37,    0,   35,    0,    0,    0,
    0,    0,    0,   40,   41,   42,   43,   44,    0,   45,
   34,    0,    0,    0,    0,    0,    0,   70,   71,    0,
   72,    0,    0,    0,    0,   38,   36,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   39,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   39,
   54,    0,   49,    0,    0,    0,    0,    0,    0,    0,
   69,   59,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   57,   58,    0,    0,    0,   51,   53,
   74,    0,   75,    0,   39,    0,    0,    0,    0,   46,
    0,   48,   50,    0,    0,   52,   47,
};
static const short yydgoto[] = {                          2,
   12,   50,   58,   63,   74,   75,   76,   77,   78,   79,
   93,   80,    5,   13,  129,   27,   28,   41,   33,   34,
   42,   29,    9,   16,   30,   66,   62,   67,   17,  130,
    3,    4,   51,   55,
};
static const short yysindex[] = {                      -248,
    0,    0,    0, -195, -204,    0,    0,    0,    0, -250,
 -279,    0,    0, -239, -216, -198,    0, -260, -228, -212,
 -189,    0, -250, -219, -189, -148, -215, -129,    0, -258,
    0, -170, -159, -124,    0,    0,    0, -189,    0, -127,
    0, -111, -100, -130, -189,    0,    0, -258,    0, -132,
 -137, -100,    0,    0, -115,    0,    0,    0, -128,    0,
  -96,    0, -246,    0,    0, -162,    0, -257, -121, -120,
  165,  165,  165,    0,    0,    0,    0,    0, -131,    0,
    0,  -96,  165,  165,  -90,  165, -213,    0,    0,  165,
    0,  165,  332,  177,   90,    0,    0,  205,  113, -256,
  282,  165,  165, -187,  307,  165,  165,  165,    0,  165,
  165,  165,  165,  165,  165,  165,  165,  165,  165,    0,
    0, -108,    0,  165,  -84,  -82,  232,  355,  -81, -112,
    0,    0,  366,  366,   79,  124,  124, -187, -187, -187,
 -187, -177, -177,    0,    0, -164,  165,  259,    0,    0,
    0,  165,    0,  -66,    0,  -62,  136, -106,  355,    0,
 -134,    0,    0,  -61,  -56,    0,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -85,    0,    0,    0, -152,    0,    0,    0,    0,    0,
  -89,    0,    0,    0,  -88,    0,    0,  -86,    0,    0,
    0,    0,    0,  -74,    0,    0,    0,    0,    0,    0,
    0, -238,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -200,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -73, -101,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -244,  -67,    0,
    0,    0,  -69,   74,    0,   45,   54,  -71,  -42,  -13,
   16, -165, -133,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -237,    0,
    0,    0,    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
    0,  157,    0, -105,    0,    0,    0,    0,    0,    0,
  -72,    0,    0,    0,    0,    0,    0,  163,    0,    0,
    0,  -19,    0,    0,   -2,    0,    0,  139,  207,    0,
    0,    0,    0,    0,
};
#define YYTABLESIZE 657
static const short yytable[] = {                         94,
   95,   10,   14,  135,   39,   35,   83,  124,    1,   40,
   98,   99,   15,  101,  146,   79,   68,  104,   46,  105,
   18,   18,   78,   19,   84,   53,   69,   70,   71,  127,
  128,   24,   72,  132,  133,  134,  125,  136,  137,  138,
  139,  140,  141,  142,  143,  144,  145,   20,   79,  161,
  102,  148,   61,   73,   18,   78,   11,    8,   73,   73,
   22,   23,    6,   25,   73,    7,    8,   26,   73,   73,
   73,    7,    8,   32,  157,   21,   73,   37,  103,  159,
   73,  106,   73,   73,   73,   73,   73,   73,   73,   73,
   73,  106,   73,   55,   55,   73,   81,   82,   68,   55,
  116,  117,  118,  119,   55,   55,   26,   26,   69,   70,
   71,   55,  118,  119,   72,   55,   36,   55,   55,   55,
   55,   55,   55,   55,   43,   56,   56,   55,   68,   38,
   55,   56,  156,   44,   45,   47,   56,   56,   69,   70,
   71,  165,   60,   56,   72,    7,    8,   56,   48,   56,
   56,   56,   56,   56,   56,   56,   49,   68,   68,   56,
   57,   56,   56,   68,   52,   64,   65,   96,   68,   68,
   85,   86,  100,  147,  149,   68,  150,    8,  152,   68,
  153,   68,   68,   68,   68,   68,  164,   61,   61,   66,
   66,   68,  160,   61,   68,   66,  162,  166,   61,   61,
   66,   66,  167,   10,   12,   61,   11,   66,   59,   61,
   54,   61,   61,   61,   61,   61,   64,   64,   13,   76,
   97,   61,   64,   66,   61,   77,   66,   64,   64,   31,
    0,    0,    0,    0,   64,    0,    0,    0,   64,    0,
   64,   64,   64,   64,   64,   62,   62,    0,    0,    0,
   64,   62,    0,   64,    0,    0,   62,   62,    0,    0,
    0,    0,    0,   62,    0,    0,    0,   62,    0,   62,
   62,   62,   62,   62,   63,   63,    0,    0,    0,   62,
   63,    0,   62,    0,    0,   63,   63,    0,    0,    0,
    0,    0,   63,    0,    0,    0,   63,    0,   63,   63,
   63,   63,   63,   60,   60,    0,    0,    0,   63,   60,
    0,   63,   65,   65,   60,   60,    0,    0,   65,    0,
    0,   60,    0,   65,   65,   60,    0,   60,    0,    0,
   65,    0,   67,   67,   65,    0,   65,   60,   67,    0,
   60,   68,    0,   67,   67,    0,   65,    0,  121,   65,
   67,   69,   70,   71,  154,    0,  155,   72,  106,  107,
  108,    0,    0,    0,    0,    0,   67,    0,    0,   67,
  110,  123,  111,  112,  113,  114,  115,  116,  117,  118,
  119,  106,  107,  108,    0,    0,    0,    0,    0,    0,
    0,    0,  106,  110,  163,  111,  112,  113,  114,  115,
  116,  117,  118,  119,  106,  107,  108,  112,  113,  114,
  115,  116,  117,  118,  119,    0,  110,    0,  111,  112,
  113,  114,  115,  116,  117,  118,  119,   87,    0,    0,
   88,   89,    0,    0,    0,    0,   90,    0,    0,    0,
    0,    0,    0,    0,   91,  106,  107,  108,    0,    0,
    0,    0,    0,    0,    0,    0,   92,  110,    0,  111,
  112,  113,  114,  115,  116,  117,  118,  119,    0,  122,
    0,    0,  120,  106,  107,  108,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  110,    0,  111,  112,  113,
  114,  115,  116,  117,  118,  119,  151,    0,    0,    0,
  106,  107,  108,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  110,    0,  111,  112,  113,  114,  115,  116,
  117,  118,  119,  158,    0,    0,    0,  106,  107,  108,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  110,
    0,  111,  112,  113,  114,  115,  116,  117,  118,  119,
  106,  107,  108,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  110,    0,  111,  112,  113,  114,  115,  116,
  117,  118,  119,    0,  126,  106,  107,  108,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  110,    0,  111,
  112,  113,  114,  115,  116,  117,  118,  119,    0,  131,
  106,  107,  108,    0,    0,    0,    0,    0,  109,    0,
    0,    0,  110,    0,  111,  112,  113,  114,  115,  116,
  117,  118,  119,  106,  107,  108,    0,    0,    0,    0,
    0,    0,    0,    0,  106,  110,    0,  111,  112,  113,
  114,  115,  116,  117,  118,  119,  110,    0,  111,  112,
  113,  114,  115,  116,  117,  118,  119,
};
static const short yycheck[] = {                         72,
   73,    4,    5,  109,  263,   25,  264,  264,  257,  268,
   83,   84,  263,   86,  120,  260,  263,   90,   38,   92,
  259,  301,  260,  263,  282,   45,  273,  274,  275,  102,
  103,  292,  279,  106,  107,  108,  293,  110,  111,  112,
  113,  114,  115,  116,  117,  118,  119,  264,  293,  155,
  264,  124,   55,  300,  293,  293,  261,  262,  259,  260,
  259,  260,  258,  292,  265,  261,  262,  280,  269,  270,
  271,  261,  262,  293,  147,  292,  277,  293,  292,  152,
  281,  269,  283,  284,  285,  286,  287,  288,  289,  290,
  291,  269,  293,  259,  260,  296,  259,  260,  263,  265,
  288,  289,  290,  291,  270,  271,  259,  260,  273,  274,
  275,  277,  290,  291,  279,  281,  265,  283,  284,  285,
  286,  287,  288,  289,  295,  259,  260,  293,  263,  259,
  296,  265,  297,  293,  259,  263,  270,  271,  273,  274,
  275,  276,  258,  277,  279,  261,  262,  281,  260,  283,
  284,  285,  286,  287,  288,  289,  257,  259,  260,  293,
  298,  294,  296,  265,  295,  294,  263,  299,  270,  271,
  292,  292,  263,  282,  259,  277,  259,  263,  260,  281,
  293,  283,  284,  285,  286,  287,  293,  259,  260,  259,
  260,  293,  259,  265,  296,  265,  259,  259,  270,  271,
  270,  271,  259,  293,  293,  277,  293,  277,   52,  281,
   48,  283,  284,  285,  286,  287,  259,  260,  293,  293,
   82,  293,  265,  293,  296,  293,  296,  270,  271,   23,
   -1,   -1,   -1,   -1,  277,   -1,   -1,   -1,  281,   -1,
  283,  284,  285,  286,  287,  259,  260,   -1,   -1,   -1,
  293,  265,   -1,  296,   -1,   -1,  270,  271,   -1,   -1,
   -1,   -1,   -1,  277,   -1,   -1,   -1,  281,   -1,  283,
  284,  285,  286,  287,  259,  260,   -1,   -1,   -1,  293,
  265,   -1,  296,   -1,   -1,  270,  271,   -1,   -1,   -1,
   -1,   -1,  277,   -1,   -1,   -1,  281,   -1,  283,  284,
  285,  286,  287,  259,  260,   -1,   -1,   -1,  293,  265,
   -1,  296,  259,  260,  270,  271,   -1,   -1,  265,   -1,
   -1,  277,   -1,  270,  271,  281,   -1,  283,   -1,   -1,
  277,   -1,  259,  260,  281,   -1,  283,  293,  265,   -1,
  296,  263,   -1,  270,  271,   -1,  293,   -1,  259,  296,
  277,  273,  274,  275,  276,   -1,  278,  279,  269,  270,
  271,   -1,   -1,   -1,   -1,   -1,  293,   -1,   -1,  296,
  281,  259,  283,  284,  285,  286,  287,  288,  289,  290,
  291,  269,  270,  271,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  269,  281,  259,  283,  284,  285,  286,  287,
  288,  289,  290,  291,  269,  270,  271,  284,  285,  286,
  287,  288,  289,  290,  291,   -1,  281,   -1,  283,  284,
  285,  286,  287,  288,  289,  290,  291,  263,   -1,   -1,
  266,  267,   -1,   -1,   -1,   -1,  272,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  280,  269,  270,  271,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  292,  281,   -1,  283,
  284,  285,  286,  287,  288,  289,  290,  291,   -1,  265,
   -1,   -1,  296,  269,  270,  271,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  281,   -1,  283,  284,  285,
  286,  287,  288,  289,  290,  291,  265,   -1,   -1,   -1,
  269,  270,  271,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  281,   -1,  283,  284,  285,  286,  287,  288,
  289,  290,  291,  265,   -1,   -1,   -1,  269,  270,  271,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  281,
   -1,  283,  284,  285,  286,  287,  288,  289,  290,  291,
  269,  270,  271,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  281,   -1,  283,  284,  285,  286,  287,  288,
  289,  290,  291,   -1,  293,  269,  270,  271,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  281,   -1,  283,
  284,  285,  286,  287,  288,  289,  290,  291,   -1,  293,
  269,  270,  271,   -1,   -1,   -1,   -1,   -1,  277,   -1,
   -1,   -1,  281,   -1,  283,  284,  285,  286,  287,  288,
  289,  290,  291,  269,  270,  271,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  269,  281,   -1,  283,  284,  285,
  286,  287,  288,  289,  290,  291,  281,   -1,  283,  284,
  285,  286,  287,  288,  289,  290,  291,
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
"program : Gdeclaration functions main_function",
"Gdeclaration : DECL GdeclStatements ENDDECL",
"GdeclStatements :",
"GdeclStatements : GdeclStatements GdeclStatement",
"GdeclStatement : type Gvars SEMICOLON",
"Gvars : Gvar",
"Gvars : Gvars COMMA Gvar",
"type : INTEGER",
"type : BOOLEAN",
"parametr :",
"parametr : PvarsList",
"Fparametr :",
"Fparametr : FvarsList",
"FvarsList : FvarsList SEMICOLON PvarsDef",
"FvarsList : PvarsDef",
"PvarsList : PvarsList SEMICOLON PvarsDef",
"PvarsList : PvarsDef",
"PvarsDef : type Pvars",
"Pvars : Pvars COMMA Pvar",
"Pvars : Pvar",
"Pvar : ID",
"Pvar : ADDRESSOF ID",
"functions :",
"functions : functions function",
"function : type ID LPAREN Fparametr RPAREN LFLOWER fbody RFLOWER",
"Gvar : ID",
"Gvar : ID LSQUARE NUMBER RSQUARE",
"Gvar : ID LPAREN parametr RPAREN",
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
"expression : ID LPAREN FexprList RPAREN",
"FexprList :",
"FexprList : exprList",
"exprList : exprList COMMA expression",
"exprList : expression",

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
#line 410 "func.y"

int main(){
    Goffset = 0;
    FILE *fp;
    fp = fopen("sim.asm","w");
    fclose(fp);
    fp = fopen("sim.asm","a");
    fprintf(fp,"START\n");
    fprintf(fp,"MOV SP, 0\n");
    fprintf(fp,"MOV BP, 0\n");
    fclose(fp);
    yyparse();
    fp = fopen("sim.asm","a");
    fprintf(fp,"HALT\n");
    fclose(fp);
    return 0;

}


void makeArglist(struct ArgStruct* head, struct ArgStruct* arg)
{
	if(headArg == NULL)
	 {
	 	headArg = arg;
	}
	else
	{
		struct ArgStruct* temp = head;
		while(temp->ARGNEXT!=NULL)
		{
			if(strcmp(temp->ARGNAME,arg->ARGNAME)==0)
			 {
			 	yyerror("Multiple Declaration of Arguments");
			 }
			temp = temp->ARGNEXT;
		}
		if(strcmp(temp->ARGNAME,arg->ARGNAME)==0)
		 {
		 	yyerror("Multiple Declaration of Arguments");
		 }
		temp->ARGNEXT = arg;
	}
}


void printArg(struct ArgStruct* head)
{
	struct ArgStruct* temp = head;
	while(temp!=NULL)
	{
		printf("%d %s - ",temp->ARGTYPE,temp->ARGNAME);
		temp=temp->ARGNEXT;
	}
}

int argDefCheck(struct ArgStruct* arg1, struct ArgStruct* arg2)
{
	struct ArgStruct* i = arg1;
	struct ArgStruct* j = arg2;
	while(i!=NULL)
	{
		if(j==NULL)
		{
		 	return 0;
		}
		else
		{
			if(strcmp(j->ARGNAME,i->ARGNAME)!=0 || i->ARGTYPE!=j->ARGTYPE )
			{
			return 0;
			}
			//Linstall(j->ARGNAME,j->ARGTYPE);
			i=i->ARGNEXT;
			j=j->ARGNEXT;

		}
	}
	if(j==NULL)
	{
	 	return 1;
	}
	else
	{
	 	return 0;
	}
}

int argInstall(struct ArgStruct* head)
{
	struct ArgStruct* temp = head;
	memcount=-1;
	/*memcount starts at -3 for arguments, as -1: Return address and -2 Return value*/
	while(temp!=NULL)
	{
		memcount = memcount - 2;
		Linstall(temp->ARGNAME,temp->ARGTYPE);
		temp=temp->ARGNEXT;
	}
	memcount=1;
}

int pushArg(struct node *x, struct ArgStruct *args)
{
	FILE *fp;
	int res=0;
	if(x==NULL)
	{
		if(args==NULL)
		{
			return 0;
		}
		else
		{
		 	yyerror("Arguments Mismatch");
		}
	}
	else
	{
		if(args==NULL)
		{
			yyerror("Arguments Mismatch");
		}
		else
		{
		  	if(x->TYPE==args->ARGTYPE )
		  	{
				if(args->PASSTYPE==1)
				{
				  if(x->NODETYPE!='v')
				  {
				  	yyerror("Pass By Reference Error");
				  }
				}

				res = pushArg(x->P3,args->ARGNEXT) + 1;
				traverse(x);
				fp = fopen("sim.asm","a");
		  		fprintf(fp,"PUSH R%d\n",regcount-1);
		  		regcount--;
		  		fclose(fp);
		  		return res;
		  	}
		  	else
		  	{
		  		yyerror("Arguments mismatch");
			}

		}

	}
}

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
   static int current = 0;
    current++;
    char *temp =(char *) malloc(5);
    temp[0]='L';temp[1]='\0';
    strcat(temp,itoa(current));

    //printf("Newlabel %s\n",temp);
    return temp;
}

void Gen3A(struct node* root,int flag){
    if(root==NULL){
        return;
    }

    switch(root->NODETYPE){
        case 'f' :{
            TAinstall('B',root->NAME,NULL,NULL);
            Gen3A(root->center,0);
            break;}
        case 'S':
            Gen3A(root->left,0);
            Gen3A(root->center,0);
            break;
        case 'I':{
            int ct = current_temp;
            char* label=newlabel();
            Gen3A(root->center,0);
            char *t =(char *) malloc(5);
            t[0]='t';t[1]='\0';
            strcat(t,itoa(current_temp));
            TAinstall('I',t,label,NULL);
            Gen3A(root->left,0);

            if(root->right){
                char* endif = newlabel();
                TAinstall('g',endif,NULL,NULL);
                TAinstall('B',label,NULL,NULL);
                Gen3A(root->right,0);
                TAinstall('B',endif,NULL,NULL);
            }else{
                TAinstall('B',label,NULL,NULL);
            }
            current_temp=ct;
            break;
        }
        case 'W':{
            int ct = current_temp;
            char* l1=newlabel();
            char* l2=newlabel();
            TAinstall('B',l1,NULL,NULL);
            Gen3A(root->center,0);
            char *t =(char *) malloc(5);
            t[0]='t';t[1]='\0';
            strcat(t,itoa(current_temp));

            TAinstall('I',t,l2,NULL);
            Gen3A(root->left,0);
            TAinstall('g',l1,NULL,NULL);
            TAinstall('B',l2,NULL,NULL);
            current_temp = ct;
            break;
        }
        case 'D':{
            int ct = current_temp;
            char* l1=newlabel();
            char* l2=newlabel();
            TAinstall('B',l1,NULL,NULL);
            Gen3A(root->left,0);
            Gen3A(root->center,0);
            char *t =(char *) malloc(5);
            t[0]='t';t[1]='\0';
            strcat(t,itoa(current_temp));
            TAinstall('I',t,l2,NULL);
            TAinstall('g',l1,NULL,NULL);
            TAinstall('B',l2,NULL,NULL);
            current_temp = ct;
            break;
        }
        case 'r':
        {
            int ct = current_temp;
            char *t =(char *) malloc(5);
            t[0]='t';t[1]='\0';
            char *t1 =(char *) malloc(5);
            t1[0]='t';t1[1]='\0';
            strcat(t,itoa(current_temp));
            Gen3A(root->center,1);
            strcat(t1,itoa(current_temp));
            TAinstall('r',t,t1,NULL);
            current_temp=ct;
            break;
        }
        case 'w':
        {
            int ct = current_temp;
            Gen3A(root->center,0);
            char *t =(char *) malloc(5);
            t[0]='t';t[1]='\0';
            strcat(t,itoa(current_temp));
            TAinstall('w',t,NULL,NULL);
            current_temp=ct;
            break;
        }
        case 'R':
        {
            Gen3A(root->center,0);
            char *t =(char *) malloc(5);
            t[0]='t';t[1]='\0';
            strcat(t,itoa(current_temp));
            TAinstall('R',t,NULL,NULL);
            current_temp--;
            break;
        }
        case '+':
        {
            Gen3A(root->left,0);
            char *t1 =(char *) malloc(5);
            t1[0]='t';t1[1]='\0';
            strcat(t1,itoa(current_temp));
            Gen3A(root->right,0);
            char *t2 =(char *) malloc(5);
            t2[0]='t';t2[1]='\0';
            strcat(t2,itoa(current_temp));
            TAinstall('+',t1, t1, t2);
            current_temp--;
            break;
        }
        case '-':
        {
            Gen3A(root->left,0);
            char *t1 =(char *) malloc(5);
            t1[0]='t';t1[1]='\0';
            strcat(t1,itoa(current_temp));
            Gen3A(root->right,0);
            char *t2 =(char *) malloc(5);
            t2[0]='t';t2[1]='\0';
            strcat(t2,itoa(current_temp));
            TAinstall('-',t1, t1, t2);
            current_temp--;
            break;
        }
        case '*':
        {
            Gen3A(root->left,0);
            char *t1 =(char *) malloc(5);
            t1[0]='t';t1[1]='\0';
            strcat(t1,itoa(current_temp));
            Gen3A(root->right,0);
            char *t2 =(char *) malloc(5);
            t2[0]='t';t2[1]='\0';
            strcat(t2,itoa(current_temp));
            TAinstall('*',t1, t1, t2);
            current_temp--;
            break;
        }
        case '/':
        {
            Gen3A(root->left,0);
            char *t1 =(char *) malloc(5);
            t1[0]='t';t1[1]='\0';
            strcat(t1,itoa(current_temp));
            Gen3A(root->right,0);
            char *t2 =(char *) malloc(5);
            t2[0]='t';t2[1]='\0';
            strcat(t2,itoa(current_temp));
            TAinstall('/',t1, t1, t2);
            current_temp--;
            break;
        }
        case '%':
        {
            Gen3A(root->left,0);
            char *t1 =(char *) malloc(5);
            t1[0]='t';t1[1]='\0';
            strcat(t1,itoa(current_temp));
            Gen3A(root->right,0);
            char *t2 =(char *) malloc(5);
            t2[0]='t';t2[1]='\0';
            strcat(t2,itoa(current_temp));
            TAinstall('%',t1, t1, t2);
            current_temp--;
            break;
        }
        case 'T' :
        {
            current_temp++;
            char *t =(char *) malloc(5);
            t[0]='t';t[1]='\0';
            strcat(t,itoa(current_temp));
            TAinstall('M',t,"1",NULL);
            break;
        }
        case 'F' :
        {
            current_temp++;
            char *t =(char *) malloc(5);
            t[0]='t';t[1]='\0';
            strcat(t,itoa(current_temp));
            TAinstall('M',t,"0",NULL);
            break;
        }
        case '&' :
            {
            Gen3A(root->left,0);
            char *t1 =(char *) malloc(5);
            t1[0]='t';t1[1]='\0';
            strcat(t1,itoa(current_temp));
            Gen3A(root->right,0);
            char *t2 =(char *) malloc(5);
            t2[0]='t';t2[1]='\0';
            strcat(t2,itoa(current_temp));
            TAinstall('&',t1, t1, t2);
            current_temp--;
            break;
        }
        case '|' :
           {
            Gen3A(root->left,0);
            char *t1 =(char *) malloc(5);
            t1[0]='t';t1[1]='\0';
            strcat(t1,itoa(current_temp));
            Gen3A(root->right,0);
            char *t2 =(char *) malloc(5);
            t2[0]='t';t2[1]='\0';
            strcat(t2,itoa(current_temp));
            char *t3 =(char *) malloc(5);
            t3[0]='t';t3[1]='\0';
            current_temp++;
            strcat(t3,itoa(current_temp));
            TAinstall('|',t1, t2, t3);
            current_temp--;
            current_temp--;
            break;
        }
        case '!' :
            {
            Gen3A(root->center,0);
            char *t =(char *) malloc(5);
            t[0]='t';t[1]='\0';
            strcat(t,itoa(current_temp));
            char *t1 =(char *) malloc(5);
            t1[0]='t';t1[1]='\0';
            current_temp++;
            strcat(t1,itoa(current_temp));
            TAinstall('!',t, t,t1);
            current_temp--;
            break;
        }
        case 'G' :
            {
            Gen3A(root->left,0);
            char *t1 =(char *) malloc(5);
            t1[0]='t';t1[1]='\0';
            strcat(t1,itoa(current_temp));
            Gen3A(root->right,0);
            char *t2 =(char *) malloc(5);
            t2[0]='t';t2[1]='\0';
            strcat(t2,itoa(current_temp));
            TAinstall('G',t1, t1, t2);
            current_temp--;
            break;
        }
        case 'L' :
            {
            Gen3A(root->left,0);
            char *t1 =(char *) malloc(5);
            t1[0]='t';t1[1]='\0';
            strcat(t1,itoa(current_temp));
            Gen3A(root->right,0);
            char *t2 =(char *) malloc(5);
            t2[0]='t';t2[1]='\0';
            strcat(t2,itoa(current_temp));
            TAinstall('L',t1, t1, t2);
            current_temp--;
            break;
        }
        case '>' :
            {
            Gen3A(root->left,0);
            char *t1 =(char *) malloc(5);
            t1[0]='t';t1[1]='\0';
            strcat(t1,itoa(current_temp));
            Gen3A(root->right,0);
            char *t2 =(char *) malloc(5);
            t2[0]='t';t2[1]='\0';
            strcat(t2,itoa(current_temp));
            TAinstall('>',t1, t1, t2);
            current_temp--;
            break;
        }
        case '<' :
            {
            Gen3A(root->left,0);
            char *t1 =(char *) malloc(5);
            t1[0]='t';t1[1]='\0';
            strcat(t1,itoa(current_temp));
            Gen3A(root->right,0);
            char *t2 =(char *) malloc(5);
            t2[0]='t';t2[1]='\0';
            strcat(t2,itoa(current_temp));
            TAinstall('<',t1, t1, t2);
            current_temp--;
            break;
        }
        case 'E' :
            {
            Gen3A(root->left,0);
            char *t1 =(char *) malloc(5);
            t1[0]='t';t1[1]='\0';
            strcat(t1,itoa(current_temp));
            Gen3A(root->right,0);
            char *t2 =(char *) malloc(5);
            t2[0]='t';t2[1]='\0';
            strcat(t2,itoa(current_temp));
            TAinstall('E',t1, t1, t2);
            current_temp--;
            break;
        }
        case 'N' :
           {
            Gen3A(root->left,0);
            char *t1 =(char *) malloc(5);
            t1[0]='t';t1[1]='\0';
            strcat(t1,itoa(current_temp));
            Gen3A(root->right,0);
            char *t2 =(char *) malloc(5);
            t2[0]='t';t2[1]='\0';
            strcat(t2,itoa(current_temp));
            TAinstall('N',t1, t1, t2);
            current_temp--;
            break;
        }
        case 1:
        {
            current_temp++;
            char *t =(char *) malloc(5);
            t[0]='t';t[1]='\0';
            strcat(t,itoa(current_temp));
            TAinstall('M',t,itoa(root->VALUE),NULL);
            break;
        }
        case 2:
        {
            char *t =(char *) malloc(5);
            if(root->center){
                Gen3A(root->center,0);
                current_temp++;
                t[0]='t';t[1]='\0';
                strcat(t,itoa(current_temp));
                TAinstall('M',t,itoa(Glookup(root->NAME)->BINDING),NULL);
                char *t1 =(char *) malloc(5);
                t1[0]='t';t1[1]='\0';
                strcat(t1,itoa(current_temp-1));
                TAinstall('+',t,t,t1);
            }else
            {
                current_temp++;
                t[0]='t';t[1]='\0';
                strcat(t,itoa(current_temp));
                if(Glookup(root->NAME))
                    TAinstall('M',t,itoa(Glookup(root->NAME)->BINDING),NULL);
                else
                    TAinstall('M',t,itoa(Llookup(root->NAME)->BINDING+GetGtableSize()),NULL);
            }
            if(flag==0){
                TAinstall('l',t,t,NULL);
                break;
            }else{
                break;
            }
        }
        case '=':
        {
            int ct = current_temp;
            Gen3A(root->right,0);
            char *t2 =(char *) malloc(5);
            t2[0]='t';t2[1]='\0';
            strcat(t2,itoa(current_temp));
            Gen3A(root->left,1);
            char *t1 =(char *) malloc(5);
            t1[0]='t';t1[1]='\0';
            strcat(t1,itoa(current_temp));
            TAinstall('=',t1,t2,NULL);
            current_temp=ct;
            break;

        }
        case 'C':
        {
            int ct = current_temp;

            int pc=root->VALUE;
            struct node* temp = root->center;
            while(pc)
            {
                char *t =(char *) malloc(5);
                t[0]='t';t[1]='\0';
                Gen3A(temp->center,0);
                strcat(t,itoa(current_temp));
                pc--;
                TAinstall('V',t,NULL,NULL);
                temp=temp->left;
            }
            current_temp=ct;
            break;
        }
        default:
        {
            Gen3A(root->center,0);
            Gen3A(root->left,0);
            Gen3A(root->right,0);
        }
        break;
    }
}

void codeGen()
{
    FILE *fp;
    fp = fopen("sim.asm","a");
    fclose(fp);
    while(TAroot){
        switch(TAroot->op){
            case '+':{
                char *r1 =(char *) malloc(5);
                strcpy(r1,TAroot->op2);
                char *r2 =(char *) malloc(5);
                strcpy(r2,TAroot->op3);
                r1[0]='R';
                r2[0]='R';
                fp = fopen("sim.asm","a");
                fprintf(fp,"ADD %s,%s\n",r1,r2);
                fclose(fp);
                break;
            }
            case '-':{
                char *r1 =(char *) malloc(5);
                strcpy(r1,TAroot->op2);
                char *r2 =(char *) malloc(5);
                strcpy(r2,TAroot->op3);
                r1[0]='R';
                r2[0]='R';
                fp = fopen("sim.asm","a");
                fprintf(fp,"SUB %s,%s\n",r1,r2);
                fclose(fp);
                break;
            }
            case '*':{
                char *r1 =(char *) malloc(5);
                strcpy(r1,TAroot->op2);
                char *r2 =(char *) malloc(5);
                strcpy(r2,TAroot->op3);
                r1[0]='R';
                r2[0]='R';
                fp = fopen("sim.asm","a");
                fprintf(fp,"MUL %s,%s\n",r1,r2);
                fclose(fp);
                break;
            }
            case '/':{
                char *r1 =(char *) malloc(5);
                strcpy(r1,TAroot->op2);
                char *r2 =(char *) malloc(5);
                strcpy(r2,TAroot->op3);
                r1[0]='R';
                r2[0]='R';
                fp = fopen("sim.asm","a");
                fprintf(fp,"DIV %s,%s\n",r1,r2);
                fclose(fp);
                break;
            }
            case '%':{
                char *r1 =(char *) malloc(5);
                strcpy(r1,TAroot->op2);
                char *r2 =(char *) malloc(5);
                strcpy(r2,TAroot->op3);
                r1[0]='R';
                r2[0]='R';
                fp = fopen("sim.asm","a");
                fprintf(fp,"MOD %s,%s\n",r1,r2);
                fclose(fp);
                break;
            }
            case 'L':{
                char *r1 =(char *) malloc(5);
                strcpy(r1,TAroot->op2);
                char *r2 =(char *) malloc(5);
                strcpy(r2,TAroot->op3);
                r1[0]='R';
                r2[0]='R';
                fp = fopen("sim.asm","a");
                fprintf(fp,"LE %s,%s\n",r1,r2);
                fclose(fp);
                break;
            }
            case 'G':{
                char *r1 =(char *) malloc(5);
                strcpy(r1,TAroot->op2);
                char *r2 =(char *) malloc(5);
                strcpy(r2,TAroot->op3);
                r1[0]='R';
                r2[0]='R';
                fp = fopen("sim.asm","a");
                fprintf(fp,"GE %s,%s\n",r1,r2);
                fclose(fp);
                break;
            }
            case '<':{
                char *r1 =(char *) malloc(5);
                strcpy(r1,TAroot->op2);
                char *r2 =(char *) malloc(5);
                strcpy(r2,TAroot->op3);
                r1[0]='R';
                r2[0]='R';
                fp = fopen("sim.asm","a");
                fprintf(fp,"LT %s,%s\n",r1,r2);
                fclose(fp);
                break;
            }
            case '>':{
                char *r1 =(char *) malloc(5);
                strcpy(r1,TAroot->op2);
                char *r2 =(char *) malloc(5);
                strcpy(r2,TAroot->op3);
                r1[0]='R';
                r2[0]='R';
                fp = fopen("sim.asm","a");
                fprintf(fp,"GT %s,%s\n",r1,r2);
                fclose(fp);
                break;
            }
            case 'N':{
                char *r1 =(char *) malloc(5);
                strcpy(r1,TAroot->op2);
                char *r2 =(char *) malloc(5);
                strcpy(r2,TAroot->op3);
                r1[0]='R';
                r2[0]='R';
                fp = fopen("sim.asm","a");
                fprintf(fp,"NE %s,%s\n",r1,r2);
                fclose(fp);
                break;
            }
            case 'E':{
                char *r1 =(char *) malloc(5);
                strcpy(r1,TAroot->op2);
                char *r2 =(char *) malloc(5);
                strcpy(r2,TAroot->op3);
                r1[0]='R';
                r2[0]='R';
                fp = fopen("sim.asm","a");
                fprintf(fp,"EQ %s,%s\n",r1,r2);
                fclose(fp);
                break;
            }
            case '&':{
                char *r1 =(char *) malloc(5);
                strcpy(r1,TAroot->op2);
                char *r2 =(char *) malloc(5);
                strcpy(r2,TAroot->op3);
                r1[0]='R';
                r2[0]='R';
                fp = fopen("sim.asm","a");
                fprintf(fp,"MUL %s,%s\n",r1,r2);
                fclose(fp);
                break;
            }
            case '|':{
                char *r1 =(char *) malloc(5);
                strcpy(r1,TAroot->op1);
                char *r2 =(char *) malloc(5);
                strcpy(r2,TAroot->op2);
                char *r3 =(char *) malloc(5);
                strcpy(r3,TAroot->op3);
                r3[0]='R';
                r1[0]='R';
                r2[0]='R';
                fp = fopen("sim.asm","a");
                fprintf(fp,"MOV %s,1\n",r3);
                fprintf(fp,"ADD %s,%s\n",r1,r2);
                fprintf(fp,"GE %s,%s\n",r1,r3);
                fclose(fp);
                break;
            }
            case '!':{
                char *r1 =(char *) malloc(5);
                strcpy(r1,TAroot->op2);
                char *r2 =(char *) malloc(5);
                strcpy(r2,TAroot->op3);
                r1[0]='R';
                r2[0]='R';
                fp = fopen("sim.asm","a");
                fprintf(fp,"MOV %s,1\n",r2);
                fprintf(fp,"LT %s,%s\n",r1,r2);
                fclose(fp);
                break;
            }
            case 'B':{
                fp = fopen("sim.asm","a");
                fprintf(fp,"%s:\n",TAroot->op1);
                fclose(fp);
                break;
            }
            case 'g':{
                fp = fopen("sim.asm","a");
                fprintf(fp,"JMP %s\n",TAroot->op1);
                fclose(fp);
                break;
            }
            case 'r':{
                char *r1 =(char *) malloc(5);
                strcpy(r1,TAroot->op1);
                char *r2 =(char *) malloc(5);
                strcpy(r2,TAroot->op2);
                r1[0]='R';
                r2[0]='R';
                fp = fopen("sim.asm","a");
                fprintf(fp,"IN %s\n",r1);
                fprintf(fp,"MOV [%s] %s\n",r2,r1);
                fclose(fp);
                break;
            }
            case 'w':{
                char *r1 =(char *) malloc(5);
                strcpy(r1,TAroot->op1);
                r1[0]='R';
                fp = fopen("sim.asm","a");
                fprintf(fp,"OUT %s\n",r1);
                fclose(fp);
                break;
            }
            case '=':{
                char *r1 =(char *) malloc(5);
                strcpy(r1,TAroot->op1);
                char *r2 =(char *) malloc(5);
                strcpy(r2,TAroot->op2);
                r1[0]='R';
                r2[0]='R';
                fp = fopen("sim.asm","a");
                fprintf(fp,"MOV [%s],%s\n",r1,r2);
                fclose(fp);
                break;
            }
            case 'M':{
                char *r1 =(char *) malloc(5);
                strcpy(r1,TAroot->op1);
                char *r2 =(char *) malloc(5);
                strcpy(r2,TAroot->op2);
                r1[0]='R';
                if(r2[0]=='t')
                    r2[0]='R';
                fp = fopen("sim.asm","a");
                fprintf(fp,"MOV %s,%s\n",r1,r2);
                fclose(fp);
                break;
            }
            case 'l':{
                char *r1 =(char *) malloc(5);
                strcpy(r1,TAroot->op1);
                char *r2 =(char *) malloc(5);
                strcpy(r2,TAroot->op2);
                r1[0]='R';
                if(r2[0]=='t')
                    r2[0]='R';
                fp = fopen("sim.asm","a");
                fprintf(fp,"MOV %s,[%s]\n",r1,r2);
                fclose(fp);
                break;
            }
            case 'I':{
                char *r1 =(char *) malloc(5);
                strcpy(r1,TAroot->op1);
                r1[0]='R';
                fp = fopen("sim.asm","a");
                fprintf(fp,"JZ %s,%s\n",r1,TAroot->op2);
                fclose(fp);
                break;
            }
            case 'R':{
                char *r1 =(char *) malloc(5);
                strcpy(r1,TAroot->op1);
                r1[0]='R';
                fp = fopen("sim.asm","a");
                fprintf(fp,"MOV R0,%s\n",r1);
                //fprintf(fp,"RET\n");
                fclose(fp);
                break;
            }
            default:
                break;
        }
    TAroot=TAroot->next;
    }

}

yyerror(s)
char *s;
{
fprintf(stderr, "%s\n",s);
}


#line 1473 "y.tab.c"

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
#line 151 "func.y"
	{ printf("PARSING SUCCESS\n"); }
break;
case 3:
#line 155 "func.y"
	{/*empty*/}
break;
case 8:
#line 163 "func.y"
	{ TYPE = INT; }
break;
case 9:
#line 164 "func.y"
	{TYPE = BOOL; }
break;
case 10:
#line 167 "func.y"
	{}
break;
case 11:
#line 168 "func.y"
	{ }
break;
case 12:
#line 171 "func.y"
	{}
break;
case 13:
#line 172 "func.y"
	{ argInstall(headArg); }
break;
case 18:
#line 183 "func.y"
	{ }
break;
case 19:
#line 186 "func.y"
	{ makeArglist(headArg, newArg);	}
break;
case 20:
#line 187 "func.y"
	{ makeArglist(headArg, newArg);	}
break;
case 21:
#line 190 "func.y"
	{
							newArg = malloc(sizeof(struct ArgStruct));
							newArg->ARGNAME = yystack.l_mark[0].n->NAME;
							newArg->ARGTYPE = TYPE;
							newArg->PASSTYPE = 0;
							newArg->ARGNEXT = NULL;
		}
break;
case 22:
#line 197 "func.y"
	{
						    newArg = malloc(sizeof(struct ArgStruct));
							newArg->ARGNAME = yystack.l_mark[-1].n->NAME;
							newArg->ARGTYPE = TYPE;
							newArg->PASSTYPE = 1;
							newArg->ARGNEXT = NULL;
	}
break;
case 23:
#line 206 "func.y"
	{ yyval.n = NULL; }
break;
case 24:
#line 207 "func.y"
	{  yyval.n=CreateNode(0,'S', 0, NULL, yystack.l_mark[-1].n, yystack.l_mark[0].n, NULL); if ((yystack.l_mark[-1].n==NULL || yystack.l_mark[-1].n->TYPE == FUNC) && yystack.l_mark[0].n->TYPE== FUNC) yyval.n->TYPE= FUNC; else yyval.n->TYPE=-1; yyerror("Bad functions") ; }
break;
case 25:
#line 210 "func.y"
	{
																yyval.n=CreateNode(0,'f', 0, yystack.l_mark[-6].n->NAME, yystack.l_mark[-4].n, yystack.l_mark[-1].n, NULL);
																if(yystack.l_mark[-1].n->TYPE == TYPE) { yyval.n->TYPE=FUNC; }else{ yyerror(" return type error"); yyval.n->TYPE = -1;}
                                                                    fnDefCheck(TYPE, yystack.l_mark[-6].n->NAME, headArg);
																}
break;
case 26:
#line 217 "func.y"
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
case 27:
#line 232 "func.y"
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
                                printf("*****offset of %s[%d] is %d\n",yystack.l_mark[-3].n->NAME,yystack.l_mark[-1].n->VALUE,Goffset);
                                /*---------------------------------------------*/
                            }
break;
case 28:
#line 247 "func.y"
	{
    								Ginstall(yystack.l_mark[-3].n->NAME, TYPE, 0, -1, 0, NULL);
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
                                	printf("*****offset of function %s is %d\n",yystack.l_mark[-3].n->NAME,yystack.l_mark[-1].n->VALUE,Goffset);
                                /*---------------------------------------------*/
    							}
break;
case 29:
#line 264 "func.y"
	{
                                                                    yyval.n=CreateNode(0,'f', 0, "MAIN", NULL, yystack.l_mark[-1].n, NULL);
                                                                    if(yystack.l_mark[-1].n->TYPE == INT) { yyval.n->TYPE=0; }else{ yyerror(" return type error"); yyval.n->TYPE = -1;}
                                                                }
break;
case 30:
#line 270 "func.y"
	{ yyval.n=yystack.l_mark[0].n; }
break;
case 32:
#line 275 "func.y"
	{/*empty*/}
break;
case 37:
#line 284 "func.y"
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
case 38:
#line 301 "func.y"
	{  yyval.n=CreateNode(0,'S', 0, NULL, yystack.l_mark[-2].n, yystack.l_mark[-1].n, NULL); if (yystack.l_mark[-2].n==NULL || yystack.l_mark[-2].n->TYPE==0) yyval.n->TYPE=yystack.l_mark[-1].n->TYPE; else {yyval.n->TYPE=-1; yyerror("Bad begin error");} }
break;
case 39:
#line 304 "func.y"
	{ yyval.n = NULL; }
break;
case 40:
#line 305 "func.y"
	{  yyval.n=CreateNode(0,'S', 0, NULL, yystack.l_mark[-1].n, yystack.l_mark[0].n, NULL); if ((yystack.l_mark[-1].n==NULL || yystack.l_mark[-1].n->TYPE==0) && yystack.l_mark[0].n->TYPE==0) yyval.n->TYPE=0; else yyval.n->TYPE=-1; yyerror("Bad statements");}
break;
case 41:
#line 308 "func.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 42:
#line 309 "func.y"
	{ yyval.n = yystack.l_mark[0].n;}
break;
case 43:
#line 310 "func.y"
	{ yyval.n = yystack.l_mark[0].n;  }
break;
case 44:
#line 311 "func.y"
	{ yyval.n = yystack.l_mark[0].n;  }
break;
case 45:
#line 312 "func.y"
	{ yyval.n = yystack.l_mark[0].n;  }
break;
case 46:
#line 315 "func.y"
	{ yystack.l_mark[-5].n = CreateNode(0,'I', 0, NULL, yystack.l_mark[-2].n, yystack.l_mark[-4].n, NULL); yyval.n = yystack.l_mark[-5].n;
                                                if (yystack.l_mark[-4].n->TYPE==2 && (yystack.l_mark[-2].n==NULL || yystack.l_mark[-2].n->TYPE==0)) yyval.n->TYPE=0; else yyval.n->TYPE=-1; yyerror("If type error");  }
break;
case 47:
#line 317 "func.y"
	{ yystack.l_mark[-7].n = CreateNode(0,'I', 0, NULL, yystack.l_mark[-4].n, yystack.l_mark[-6].n, yystack.l_mark[-2].n); yyval.n = yystack.l_mark[-7].n;
                                                if (yystack.l_mark[-6].n->TYPE==2 && (yystack.l_mark[-4].n==NULL || yystack.l_mark[-4].n->TYPE==0) && (yystack.l_mark[-2].n==NULL || yystack.l_mark[-2].n->TYPE==0)) yyval.n->TYPE=0; else yyval.n->TYPE=-1; yyerror("If else error"); }
break;
case 48:
#line 321 "func.y"
	{ yystack.l_mark[-5].n = CreateNode(0,'W', 0, NULL, yystack.l_mark[-2].n, yystack.l_mark[-4].n, NULL); yyval.n=yystack.l_mark[-5].n; if (yystack.l_mark[-4].n->TYPE==2 && (yystack.l_mark[-2].n==NULL || yystack.l_mark[-2].n->TYPE==0)) yyval.n->TYPE=0; else yyval.n->TYPE=-1; yyerror("while error"); }
break;
case 49:
#line 324 "func.y"
	{ yystack.l_mark[-2].n = CreateNode(0,'=', 0, NULL, yystack.l_mark[-3].n, NULL, yystack.l_mark[-1].n); yyval.n=yystack.l_mark[-2].n;
                                            struct Lsymbol* lt = Llookup(yystack.l_mark[-3].n->NAME);
                                            if(lt) { if (lt->TYPE == yystack.l_mark[-1].n->TYPE ) yyval.n->TYPE=0; }
                                            else {
                                                struct Gsymbol* gt = Glookup(yystack.l_mark[-3].n->NAME);
                                                if(gt) { if ( gt->SIZE==0 && (gt->TYPE == yystack.l_mark[-1].n->TYPE )) yyval.n->TYPE=0;
                                                else { yyval.n->TYPE=-1;	yyerror("Wrong assignment");}}else { printf("ID %s not found\n",yystack.l_mark[-3].n->NAME); yyerror(""); yyval.n->TYPE=-1;}
                                            }}
break;
case 50:
#line 332 "func.y"
	{ yystack.l_mark[-6].n->center = yystack.l_mark[-4].n; yystack.l_mark[-2].n = CreateNode(0,'=', 0, NULL, yystack.l_mark[-6].n, NULL, yystack.l_mark[-1].n); yyval.n=yystack.l_mark[-2].n;
                                                                struct Gsymbol* gt = Glookup(yystack.l_mark[-6].n->NAME);
                                                                if(gt) {if ( gt->SIZE!=0 && yystack.l_mark[-4].n->TYPE==INT && ((gt->TYPE-2) == yystack.l_mark[-1].n->TYPE)) yyval.n->TYPE=0; else { yyval.n->TYPE=-1;
                                                                yyerror("Wrong assignment of array type");}} else {printf("Array %s not found\n",yystack.l_mark[-6].n->NAME); yyerror(""); yyval.n->TYPE=-1; }
                                                            }
break;
case 51:
#line 339 "func.y"
	{ yystack.l_mark[-4].n = CreateNode(0,'r', 0, NULL, NULL, yystack.l_mark[-2].n, NULL); yyval.n = yystack.l_mark[-4].n;
                                            struct Lsymbol* lt = Llookup(yystack.l_mark[-2].n->NAME);
                                            if(lt && (lt->TYPE == 1))
                                                yyval.n->TYPE=0;
                                            else {
                                                struct Gsymbol* gt = Glookup(yystack.l_mark[-2].n->NAME);
                                                if(gt) {if( gt->SIZE==0 && gt->TYPE == 1 ) yyval.n->TYPE=0; else { yyval.n->TYPE=-1;
                                                yyerror("Read type error");}} else { printf("ID %s not found\n",yystack.l_mark[-2].n->NAME); yyerror(""); yyval.n->TYPE=-1;}
                                            }}
break;
case 52:
#line 348 "func.y"
	{ yystack.l_mark[-5].n->center = yystack.l_mark[-3].n;  yystack.l_mark[-7].n = CreateNode(0,'r', 0, NULL, NULL, yystack.l_mark[-5].n, NULL); yyval.n = yystack.l_mark[-7].n;
                                                struct Gsymbol* gt = Glookup(yystack.l_mark[-5].n->NAME);
                                                if(gt) { if(gt->SIZE!=0 && gt->TYPE==(INT+2) && yystack.l_mark[-3].n->TYPE==1) yyval.n->TYPE=0; else { yyval.n->TYPE=-1;
                                                yyerror("Read type error");}} else { printf("ID %s not found\n",yystack.l_mark[-5].n->NAME); yyerror(""); yyval.n->TYPE=-1;}
                                            }
break;
case 53:
#line 355 "func.y"
	{ yystack.l_mark[-4].n = CreateNode(0,'w', 0, NULL, NULL, yystack.l_mark[-2].n, NULL); yyval.n = yystack.l_mark[-4].n;
                                                                            if(yystack.l_mark[-2].n->TYPE==1) yyval.n->TYPE=0; else {yyval.n->TYPE=-1; yyerror("Write error");} }
break;
case 54:
#line 359 "func.y"
	{ yystack.l_mark[-2].n = CreateNode(0,'R', 0, NULL, NULL, yystack.l_mark[-1].n, NULL);  yyval.n = yystack.l_mark[-2].n;
                                                                            if(yystack.l_mark[-1].n->TYPE==1) yyval.n->TYPE=0; else {yyval.n->TYPE=-1; yyerror("Return type nomatch");}}
break;
case 55:
#line 363 "func.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'+', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==1 && yystack.l_mark[0].n->TYPE ==1) yyval.n->TYPE=1; else yyval.n->TYPE=-1; yyerror("+ error"); }
break;
case 56:
#line 364 "func.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'-', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==1 && yystack.l_mark[0].n->TYPE ==1) yyval.n->TYPE=1; else yyval.n->TYPE=-1; yyerror("- error");  }
break;
case 57:
#line 365 "func.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'*', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==1 && yystack.l_mark[0].n->TYPE ==1) yyval.n->TYPE=1; else yyval.n->TYPE=-1; yyerror("* error"); }
break;
case 58:
#line 366 "func.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'/', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n;  if(yystack.l_mark[-2].n->TYPE==1 && yystack.l_mark[0].n->TYPE ==1) yyval.n->TYPE=1; else yyval.n->TYPE=-1; yyerror("/ error"); }
break;
case 59:
#line 367 "func.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'%', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==1 && yystack.l_mark[0].n->TYPE ==1) yyval.n->TYPE=1; else yyval.n->TYPE=-1; yyerror("%error"); }
break;
case 60:
#line 368 "func.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'E', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==1 && yystack.l_mark[0].n->TYPE ==1) yyval.n->TYPE=2; else yyval.n->TYPE=-1; yyerror("= error");  }
break;
case 61:
#line 369 "func.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'<', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==1 && yystack.l_mark[0].n->TYPE ==1) yyval.n->TYPE=2; else yyval.n->TYPE=-1; yyerror("< error"); }
break;
case 62:
#line 370 "func.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'>', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==1 && yystack.l_mark[0].n->TYPE ==1) yyval.n->TYPE=2; else yyval.n->TYPE=-1; yyerror("> error"); }
break;
case 63:
#line 371 "func.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'G', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==1 && yystack.l_mark[0].n->TYPE ==1) yyval.n->TYPE=2; else yyval.n->TYPE=-1; yyerror(">= error"); }
break;
case 64:
#line 372 "func.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'L', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==1 && yystack.l_mark[0].n->TYPE ==1) yyval.n->TYPE=2; else yyval.n->TYPE=-1; yyerror("<= error");  }
break;
case 65:
#line 373 "func.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'N', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==1 && yystack.l_mark[0].n->TYPE ==1) yyval.n->TYPE=2; else yyval.n->TYPE=-1; yyerror("!= error");  }
break;
case 66:
#line 374 "func.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'&', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==2 && yystack.l_mark[0].n->TYPE ==2) yyval.n->TYPE=2; else yyval.n->TYPE=-1; yyerror("& error"); }
break;
case 67:
#line 375 "func.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'|', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==2 && yystack.l_mark[0].n->TYPE ==2) yyval.n->TYPE=2; else yyval.n->TYPE=-1; yyerror("| error"); }
break;
case 68:
#line 376 "func.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'!', 0, NULL, NULL, yystack.l_mark[0].n, NULL); yyval.n = yystack.l_mark[-1].n;  if(yystack.l_mark[0].n->TYPE==2) yyval.n->TYPE=2; else yyval.n->TYPE=-1; yyerror("NOT error"); }
break;
case 69:
#line 377 "func.y"
	{ yyval.n = yystack.l_mark[-1].n; }
break;
case 70:
#line 378 "func.y"
	{ yystack.l_mark[0].n = CreateNode(2,'T', 0, NULL,NULL,NULL,NULL); yyval.n = yystack.l_mark[0].n;  }
break;
case 71:
#line 379 "func.y"
	{ yystack.l_mark[0].n = CreateNode(2,'F', 0, NULL, NULL, NULL, NULL); yyval.n = yystack.l_mark[0].n; }
break;
case 72:
#line 380 "func.y"
	{ yyval.n=yystack.l_mark[0].n; }
break;
case 73:
#line 381 "func.y"
	{ yyval.n = yystack.l_mark[0].n; struct Lsymbol* lt = Llookup(yystack.l_mark[0].n->NAME); if(lt) yyval.n->TYPE=lt->TYPE; else {
                                                            struct Gsymbol* gt = Glookup(yystack.l_mark[0].n->NAME);
                                                            if(gt) {if(gt->SIZE==0) yyval.n->TYPE=gt->TYPE; else yyval.n->TYPE=-1; }
                                                            else { printf("ID %s not found\n",yystack.l_mark[0].n->NAME); yyerror(""); yyval.n->TYPE=-1;}}}
break;
case 74:
#line 385 "func.y"
	{   yystack.l_mark[-3].n->center = yystack.l_mark[-1].n; yyval.n = yystack.l_mark[-3].n;  struct Gsymbol* gt = Glookup(yystack.l_mark[-3].n->NAME);
                                                                    if(gt) { if(gt->SIZE!=0 && yystack.l_mark[-1].n->TYPE==1)
                                                                    yyval.n->TYPE=gt->TYPE; else yyval.n->TYPE=-1; yyerror("array type expression"); }
                                                                    else { printf("Array %s not found\n",yystack.l_mark[-3].n->NAME); yyerror(""); yyval.n->TYPE=-1;}}
break;
case 75:
#line 389 "func.y"
	{ struct Gsymbol* gtemp = Glookup(yystack.l_mark[-3].n->NAME);
                                    yyval.n=CreateNode(0,'C', pcount, yystack.l_mark[-3].n->NAME,NULL,yystack.l_mark[-1].n,NULL);
                                    if(gtemp==NULL || gtemp->SIZE!=0) yyerror("Undefined Function");
                                    else
                                    {
                                        yyval.n->lookup = gtemp;
                                        yyval.n->TYPE = gtemp->TYPE;
                                    }
                                    pcount=0;
        }
break;
case 76:
#line 401 "func.y"
	{ yyval.n=NULL; }
break;
case 77:
#line 402 "func.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 78:
#line 405 "func.y"
	{ yyval.n=CreateNode(0,',', 0, NULL,yystack.l_mark[-2].n,yystack.l_mark[0].n,NULL); pcount++; }
break;
case 79:
#line 406 "func.y"
	{ yyval.n=yystack.l_mark[0].n; pcount++; }
break;
#line 2056 "y.tab.c"
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
