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
int SP;
static int current_temp=0;

struct node {
    int TYPE;			/* Integer (1), Boolean (2) or Void (0) (for statements) */
                    /* Must point to the type expression tree for user defined types */
    int NODETYPE;			/* this field should carry following information:
                    * a) operator : (+,*,/ etc.) for expressions
                    * b) statement Type : (WHILE, READ etc.) for statements
                    * c) else 0
                    */
    int PASSTYPE;
    int VALUE;			/* for constants */
    char* NAME;			/* For Identifiers */
    struct	node 	*center, *left,	*right;
    struct ArgStruct *ARGLIST;
    struct Lsymbol *lookup;
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
    struct Lsymbol *LTABLE;
    /***Argstruct must store the name and type of each argument ***/
    struct Gsymbol *NEXT; /* Pointer to next Symbol Table Entry * /*/
} *Gnode;

struct Lsymbol {
    /* Here only name, type, binding and pointer to next entry needed */
    char *NAME; /* Name of the Identifier*/
    int TYPE; /* TYPE can be INTEGER or BOOLEAN*/
    /***The TYPE field must be a TypeStruct if user defined types are allowed***/
    int VALUE; /* for constants*/
    int PASSTYPE;
    int BINDING; /* Address of the Identifier in Memory*/
    struct Lsymbol *NEXT; /* Pointer to next Symbol Table Entry * /*/
};

int GetGtableSize();
void printTree(struct node* root);
struct node* CreateNode(int TYPE1, int NODETYPE1, int VALUE1, char* NAME1, struct node *ptr1, struct node *ptr2, struct node *ptr3);
void Ginstall(char* NAME, int TYPE, int SIZE, int BINDING, int VALUE, struct ArgStruct* ARGLIST, struct Lsymbol* LTABLE);
struct Gsymbol *Glookup(char* NAME);
struct Lsymbol *Llookup(char* NAME, struct Lsymbol* Lnode);
struct Lsymbol* Linstall(char* NAME, int TYPE, int BINDING, int VALUE, int PASSTYPE, struct Lsymbol* Lnode);
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
int Loffset = 0;
char* fname;
/*  Adding arguments*/
struct ArgStruct* headArg = NULL;
struct ArgStruct* headArg2 = NULL;
struct ArgStruct* newArg;
struct Lsymbol* Lnode = NULL;

void PrintSymbol(){
    struct Gsymbol *Gtemp = Gnode;
    while(Gtemp != NULL){
        printf("%s --> %d ",Gtemp->NAME,Gtemp->TYPE) ;
        Gtemp =Gtemp->NEXT;
    }
    printf("\n");
    printf("\n");
}

void PrintLSymbol(struct Lsymbol *Lnode){
    struct Lsymbol *Ltemp = Lnode;
    while(Ltemp != NULL){
        printf("%s --> %d ",Ltemp->NAME,Ltemp->TYPE) ;
        Ltemp =Ltemp->NEXT;
    }
    printf("\n");
    printf("\n");
}

void makeArglist(struct ArgStruct* arg);
void makeArglist2(struct ArgStruct* arg);
void printArg(struct ArgStruct* head);
#line 119 "func.y"
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
#line 146 "y.tab.c"

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
    0,   37,   38,   38,   26,   27,   27,   28,   28,   23,
   23,   16,   16,   19,   19,   20,   20,   34,   35,   35,
   36,   36,   17,   17,   22,   21,   21,   18,   18,   32,
   32,   39,   32,   13,   13,   40,   14,   41,    1,   42,
    2,   43,   24,   25,   25,   30,   29,   29,   31,    3,
    4,    4,    5,    5,    5,    5,    5,    6,    6,    7,
   12,   12,    8,    8,    9,   10,   11,   11,   11,   11,
   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,
   11,   11,   11,   11,   11,   11,   11,   33,   33,   15,
   15,   15,
};
static const short yylen[] = {                            2,
    3,    3,    0,    2,    3,    1,    3,    1,    1,    1,
    1,    0,    1,    0,    1,    3,    1,    2,    3,    1,
    1,    2,    3,    1,    2,    3,    1,    1,    2,    1,
    4,    0,    5,    0,    2,    0,    9,    0,    8,    0,
    3,    0,    4,    0,    2,    3,    1,    3,    1,    4,
    0,    2,    1,    1,    1,    1,    1,    6,    8,    6,
    4,    7,    5,    8,    5,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    2,
    3,    1,    1,    1,    1,    4,    4,    0,    1,    3,
    1,    2,
};
static const short yydefred[] = {                         0,
    3,    0,   34,    0,    0,    2,    8,    9,    4,    0,
    0,   11,    1,   35,    0,    0,    0,    6,   38,   36,
    0,    0,    5,    0,    0,    0,    0,    0,    7,    0,
    0,   31,    0,    0,   24,    0,    0,    0,    0,    0,
   17,   33,    0,   28,    0,   27,    0,    0,    0,    0,
   21,    0,    0,   20,   23,   29,    0,   42,    0,   40,
    0,   16,   22,    0,   26,   44,   39,    0,    0,   19,
    0,   51,   41,   37,   43,    0,   45,    0,   49,    0,
   47,    0,    0,    0,    0,    0,    0,   52,   53,   54,
   55,   56,    0,   57,   46,    0,    0,    0,    0,    0,
    0,   82,   83,    0,   84,    0,    0,    0,    0,   50,
   48,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   51,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   51,   66,    0,   61,    0,    0,    0,
    0,    0,    0,    0,    0,   81,   71,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   69,   70,
    0,    0,    0,   63,   65,   86,   92,    0,   87,    0,
   51,    0,    0,    0,    0,   58,    0,   60,   62,    0,
    0,   64,   59,
};
static const short yydgoto[] = {                          2,
   13,   59,   73,   78,   88,   89,   90,   91,   92,   93,
  107,   94,    5,   14,  144,   33,   34,   46,   38,   39,
   47,   35,   15,   60,   71,    9,   17,   36,   80,   77,
   81,   18,  145,   41,   53,   54,    3,    4,   22,   26,
   25,   68,   66,
};
static const short yysindex[] = {                      -250,
    0,    0,    0, -184, -252,    0,    0,    0,    0, -239,
 -282,    0,    0,    0, -212, -209, -195,    0,    0,    0,
 -214, -224,    0, -239, -222, -208, -156, -146,    0, -190,
 -146,    0, -174, -132,    0, -255, -159, -161, -122, -205,
    0,    0, -146,    0, -119,    0, -117, -112, -148, -146,
    0, -115, -111,    0,    0,    0, -255,    0, -143,    0,
 -112,    0,    0, -205,    0,    0,    0, -139, -130,    0,
 -120,    0,    0,    0,    0,  -96,    0, -169,    0, -160,
    0, -207, -124, -123,  185,  185,  185,    0,    0,    0,
    0,    0, -129,    0,    0,  -96,  185,  185,  -83,  185,
 -232,    0,    0,  185,    0,  185,  352,  197,  103,    0,
    0,  225,  126, -260,  302,  185,  178, -263,  327,  185,
  185,  185,    0,  185,  185,  185,  185,  185,  185,  185,
  185,  185,  185,    0,    0, -105,    0,  185,  -78,  -76,
  252,  -72,  375,  -68,  -97,    0,    0,  386,  386,  226,
  114,  114, -263, -263, -263, -263, -210, -210,    0,    0,
 -162,  185,  279,    0,    0,    0,    0,  185,    0,  -66,
    0,  -61,  149,  -94,  375,    0, -100,    0,    0,  -57,
  -56,    0,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -59,    0,    0,    0,    0, -238,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -88,    0,    0,
  -87,    0,    0,  -85,    0,    0,    0,    0,  -84,    0,
    0,    0,    0,    0,    0,    0, -256,    0,    0,    0,
    0,    0, -244,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -198,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -81,  -99,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -243,  -73,    0,    0,    0,   75,   84,    0,
   46,   55,  -70,  -41,  -12,   17, -163, -131,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -237,    0,    0,    0,    0,    0,
    0,    0,    0,
};
static const short yygindex[] = {                         0,
    0,  160,    0, -118,    0,    0,    0,    0,    0,    0,
  -86,    0,    0,    0,    0,    0,    0,  153,    0,    0,
    0,  179,    0,    0,    0,    0,    0,   -2,    0,    0,
  129,  203,    0,  181,    0,  164,    0,    0,    0,    0,
    0,    0,    0,
};
#define YYTABLESIZE 677
static const short yytable[] = {                        108,
  109,   10,   25,  138,  150,  120,    1,   44,   11,   12,
  112,  113,   45,  115,   18,  161,   91,  118,   19,  119,
   30,   30,   90,   16,  130,  131,  132,  133,   40,  141,
  143,  116,  139,  147,  148,  149,   25,  151,  152,  153,
  154,  155,  156,  157,  158,  159,  160,   40,   18,   91,
   20,  163,  177,   32,   21,   90,   97,   51,  120,  117,
   85,   85,   52,   23,   24,   27,   85,   28,   76,   30,
   85,   85,   85,    6,   98,  173,    7,    8,   85,  132,
  133,  175,   85,   31,   85,   85,   85,   85,   85,   85,
   85,   85,   85,   82,   85,   67,   67,   85,   95,   96,
   82,   67,   37,   83,   84,   85,   67,   67,   32,   86,
   83,   84,   85,   67,    7,    8,   86,   67,   42,   67,
   67,   67,   67,   67,   67,   67,   43,   68,   68,   67,
   87,   49,   67,   68,  172,   48,   50,   75,   68,   68,
    7,    8,   57,   56,   58,   68,   61,   63,   64,   68,
   67,   68,   68,   68,   68,   68,   68,   68,   72,   80,
   80,   68,   82,   74,   68,   80,   79,   99,  100,  110,
   80,   80,   83,   84,   85,  181,  162,   80,   86,  114,
  164,   80,  165,   80,   80,   80,   80,   80,   73,   73,
  167,  168,  176,   80,   73,  169,   80,  178,  180,   73,
   73,  182,  183,   10,   12,   14,   73,   13,   15,   65,
   73,   88,   73,   73,   73,   73,   73,   76,   76,   89,
   69,   55,   73,   76,  111,   73,   29,   70,   76,   76,
   62,    0,    0,    0,    0,   76,    0,    0,    0,   76,
    0,   76,   76,   76,   76,   76,   74,   74,    0,    0,
    0,   76,   74,    0,   76,    0,    0,   74,   74,    0,
    0,    0,    0,    0,   74,    0,    0,    0,   74,    0,
   74,   74,   74,   74,   74,   75,   75,    0,    0,    0,
   74,   75,    0,   74,    0,    0,   75,   75,    0,    0,
    0,    0,    0,   75,    0,    0,    0,   75,    0,   75,
   75,   75,   75,   75,   72,   72,    0,    0,    0,   75,
   72,    0,   75,   77,   77,   72,   72,    0,    0,   77,
    0,    0,   72,    0,   77,   77,   72,    0,   72,    0,
    0,   77,    0,   78,   78,   77,    0,   77,   72,   78,
    0,   72,   79,   79,   78,   78,    0,   77,   79,    0,
   77,   78,    0,   79,   79,    0,    0,    0,    0,    0,
   79,  135,    0,    0,    0,    0,    0,   78,    0,    0,
   78,  120,  121,  122,    0,    0,   79,    0,    0,   79,
    0,    0,  120,  124,  137,  125,  126,  127,  128,  129,
  130,  131,  132,  133,  120,  121,  122,  126,  127,  128,
  129,  130,  131,  132,  133,    0,  124,  179,  125,  126,
  127,  128,  129,  130,  131,  132,  133,  120,  121,  122,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  124,
    0,  125,  126,  127,  128,  129,  130,  131,  132,  133,
  101,    0,    0,  102,  103,  142,    0,  101,    0,  104,
  102,  103,    0,    0,    0,    0,  104,  105,    0,    0,
    0,    0,    0,    0,  105,  120,  121,  122,    0,  106,
    0,    0,    0,    0,    0,    0,  106,  124,    0,  125,
  126,  127,  128,  129,  130,  131,  132,  133,   82,  136,
    0,    0,  134,  120,  121,  122,    0,    0,   83,   84,
   85,  170,    0,  171,   86,  124,    0,  125,  126,  127,
  128,  129,  130,  131,  132,  133,  166,    0,    0,    0,
  120,  121,  122,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  124,    0,  125,  126,  127,  128,  129,  130,
  131,  132,  133,  174,    0,    0,    0,  120,  121,  122,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  124,
    0,  125,  126,  127,  128,  129,  130,  131,  132,  133,
  120,  121,  122,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  124,    0,  125,  126,  127,  128,  129,  130,
  131,  132,  133,    0,  140,  120,  121,  122,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  124,    0,  125,
  126,  127,  128,  129,  130,  131,  132,  133,    0,  146,
  120,  121,  122,    0,    0,    0,    0,    0,  123,    0,
    0,    0,  124,    0,  125,  126,  127,  128,  129,  130,
  131,  132,  133,  120,  121,  122,    0,    0,    0,    0,
    0,    0,    0,    0,  120,  124,    0,  125,  126,  127,
  128,  129,  130,  131,  132,  133,  124,    0,  125,  126,
  127,  128,  129,  130,  131,  132,  133,
};
static const short yycheck[] = {                         86,
   87,    4,  259,  264,  123,  269,  257,  263,  261,  262,
   97,   98,  268,  100,  259,  134,  260,  104,  301,  106,
  259,  260,  260,  263,  288,  289,  290,  291,   31,  116,
  117,  264,  293,  120,  121,  122,  293,  124,  125,  126,
  127,  128,  129,  130,  131,  132,  133,   50,  293,  293,
  263,  138,  171,  292,  264,  293,  264,  263,  269,  292,
  259,  260,  268,  259,  260,  280,  265,  292,   71,  292,
  269,  270,  271,  258,  282,  162,  261,  262,  277,  290,
  291,  168,  281,  292,  283,  284,  285,  286,  287,  288,
  289,  290,  291,  263,  293,  259,  260,  296,  259,  260,
  263,  265,  293,  273,  274,  275,  270,  271,  265,  279,
  273,  274,  275,  277,  261,  262,  279,  281,  293,  283,
  284,  285,  286,  287,  288,  289,  259,  259,  260,  293,
  300,  293,  296,  265,  297,  295,  259,  258,  270,  271,
  261,  262,  260,  263,  257,  277,  295,  263,  260,  281,
  294,  283,  284,  285,  286,  287,  288,  289,  298,  259,
  260,  293,  263,  294,  296,  265,  263,  292,  292,  299,
  270,  271,  273,  274,  275,  276,  282,  277,  279,  263,
  259,  281,  259,  283,  284,  285,  286,  287,  259,  260,
  263,  260,  259,  293,  265,  293,  296,  259,  293,  270,
  271,  259,  259,  263,  293,  293,  277,  293,  293,   57,
  281,  293,  283,  284,  285,  286,  287,  259,  260,  293,
   61,   43,  293,  265,   96,  296,   24,   64,  270,  271,
   50,   -1,   -1,   -1,   -1,  277,   -1,   -1,   -1,  281,
   -1,  283,  284,  285,  286,  287,  259,  260,   -1,   -1,
   -1,  293,  265,   -1,  296,   -1,   -1,  270,  271,   -1,
   -1,   -1,   -1,   -1,  277,   -1,   -1,   -1,  281,   -1,
  283,  284,  285,  286,  287,  259,  260,   -1,   -1,   -1,
  293,  265,   -1,  296,   -1,   -1,  270,  271,   -1,   -1,
   -1,   -1,   -1,  277,   -1,   -1,   -1,  281,   -1,  283,
  284,  285,  286,  287,  259,  260,   -1,   -1,   -1,  293,
  265,   -1,  296,  259,  260,  270,  271,   -1,   -1,  265,
   -1,   -1,  277,   -1,  270,  271,  281,   -1,  283,   -1,
   -1,  277,   -1,  259,  260,  281,   -1,  283,  293,  265,
   -1,  296,  259,  260,  270,  271,   -1,  293,  265,   -1,
  296,  277,   -1,  270,  271,   -1,   -1,   -1,   -1,   -1,
  277,  259,   -1,   -1,   -1,   -1,   -1,  293,   -1,   -1,
  296,  269,  270,  271,   -1,   -1,  293,   -1,   -1,  296,
   -1,   -1,  269,  281,  259,  283,  284,  285,  286,  287,
  288,  289,  290,  291,  269,  270,  271,  284,  285,  286,
  287,  288,  289,  290,  291,   -1,  281,  259,  283,  284,
  285,  286,  287,  288,  289,  290,  291,  269,  270,  271,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  281,
   -1,  283,  284,  285,  286,  287,  288,  289,  290,  291,
  263,   -1,   -1,  266,  267,  268,   -1,  263,   -1,  272,
  266,  267,   -1,   -1,   -1,   -1,  272,  280,   -1,   -1,
   -1,   -1,   -1,   -1,  280,  269,  270,  271,   -1,  292,
   -1,   -1,   -1,   -1,   -1,   -1,  292,  281,   -1,  283,
  284,  285,  286,  287,  288,  289,  290,  291,  263,  265,
   -1,   -1,  296,  269,  270,  271,   -1,   -1,  273,  274,
  275,  276,   -1,  278,  279,  281,   -1,  283,  284,  285,
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
"ftype : INTEGER",
"ftype : BOOLEAN",
"parametr :",
"parametr : PvarsList",
"Fparametr :",
"Fparametr : FvarsList",
"FvarsList : FvarsList SEMICOLON FvarsDef",
"FvarsList : FvarsDef",
"FvarsDef : type Fvars",
"Fvars : Fvars COMMA Fvar",
"Fvars : Fvar",
"Fvar : ID",
"Fvar : ADDRESSOF ID",
"PvarsList : PvarsList SEMICOLON PvarsDef",
"PvarsList : PvarsDef",
"PvarsDef : type Pvars",
"Pvars : Pvars COMMA Pvar",
"Pvars : Pvar",
"Pvar : ID",
"Pvar : ADDRESSOF ID",
"Gvar : ID",
"Gvar : ID LSQUARE NUMBER RSQUARE",
"$$1 :",
"Gvar : ID $$1 LPAREN parametr RPAREN",
"functions :",
"functions : functions function",
"$$2 :",
"function : ftype ID $$2 LPAREN Fparametr RPAREN LFLOWER fbody RFLOWER",
"$$3 :",
"main_function : INTEGER MAIN $$3 LPAREN RPAREN LFLOWER fbody RFLOWER",
"$$4 :",
"fbody : declaration $$4 beginbody",
"$$5 :",
"declaration : DECL $$5 declStatements ENDDECL",
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
"exprList : ADDRESSOF ID",

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
#line 543 "func.y"

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


void makeArglist( struct ArgStruct* arg)
{
	if(!headArg)
	 {
	 	headArg = arg;
	 	printf("installed1 argument fisrt\n");
	}
	else
	{
		struct ArgStruct* temp = headArg;
		printf("installed argument rest\n");
		while(temp->ARGNEXT!=NULL)
		{
			if(strcmp(temp->ARGNAME,arg->ARGNAME)==0)
			 {
			 	yyerror("Multiple Declaration of Arguments");
			 	break;
			 }
			temp = temp->ARGNEXT;
		}
		if(strcmp(temp->ARGNAME,arg->ARGNAME)==0)
		 {
		 	yyerror("Multiple Declaration of Arguments");
		 }
		  arg->ARGNEXT=headArg;
		  headArg = arg;
	}
	printArg(headArg);
}

void makeArglist2(struct ArgStruct* arg)
{
    if(!headArg2)
     {
        headArg2 = arg;
        printf("installed2 argument fisrt\n");
    }
    else
    {
        struct ArgStruct* temp = headArg2;
        printf("installed argument rest\n");
        while(temp->ARGNEXT!=NULL)
        {
            if(strcmp(temp->ARGNAME,arg->ARGNAME)==0)
             {
                yyerror("Multiple Declaration of Arguments");
                break;
             }
            temp = temp->ARGNEXT;
        }
        if(strcmp(temp->ARGNAME,arg->ARGNAME)==0)
         {
            yyerror("Multiple Declaration of Arguments");
         }
        arg->ARGNEXT=headArg2;
		headArg2 = arg;
    }
    printArg(headArg2);
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
		    printf("Argument arg2 short\n");
		 	return 0;
		}
		else
		{
			if(strcmp(j->ARGNAME,i->ARGNAME)!=0 || i->ARGTYPE!=j->ARGTYPE )
			{
			printf("Argument name no match\n");
			return 0;
			}
			Lnode = Linstall(i->ARGNAME, i->ARGTYPE, Loffset, 0, i->PASSTYPE, Lnode);
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
            printf("installed 1 args %s\n",i->ARGNAME);
			i=i->ARGNEXT;
			j=j->ARGNEXT;
			 PrintLSymbol(Lnode);

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

int fnDefCheck(int type, char* name, struct ArgStruct* arg)
{
	   struct Gsymbol* res;
	   res = Gnode;
	   while(res != NULL)
	    {
		      if(strcmp(res->NAME, name) == 0 && res->SIZE==0)
			{
				 if(res->TYPE == type && argDefCheck(res->ARGLIST, arg))
				 {
				 	return 0;
				 }
				 else
				 {
					yyerror("Incorrect Function Definition");
					return -1;

			      	 }
		      	}
		      res = res->NEXT;
	     }
	  yyerror("Function Undeclared");

}
/**
int argInstall(struct ArgStruct* head)
{
	struct ArgStruct* temp = head;
	memcount=-1;
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
*/
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
    struct Lsymbol* ltemp;
    char * FNAME = malloc(30);
    switch(root->NODETYPE){
        case 'f' :{
            struct Gsymbol* gt = Glookup(root->NAME);
            struct Lsymbol* lt = gt->LTABLE;
            ltemp = lt;
            struct ArgStruct* at = gt->ARGLIST;
            struct Lsymbol* lcopy = (struct Lsymbol*)malloc(sizeof (struct Lsymbol));
            int bp;

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
                if(Llookup(root->NAME,ltemp))
                    TAinstall('M',t,itoa(Llookup(root->NAME, ltemp)->BINDING+GetGtableSize()+1),NULL);
                else
                    TAinstall('M',t,itoa(Glookup(root->NAME)->BINDING),NULL);
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
            char *t =(char *) malloc(5);
            int pc=root->VALUE;
            struct node* temp = root->center;
            struct Gsymbol* gtemp = Glookup(root->NAME);
            struct ArgStruct* args = gtemp->ARGLIST;
            //gtemp->BINDING =
            while(current_temp)
            {
                t[0]='t';t[1]='\0';
                strcat(t,itoa(current_temp));
                TAinstall('P',t,NULL,NULL);
                current_temp--;
            }

            while(pc && temp)
            {
                char *t =(char *) malloc(5);
                t[0]='t';t[1]='\0';
                Gen3A(temp->center,0);
                strcat(t,itoa(current_temp));
                TAinstall('v',t,NULL,NULL);
                current_temp--;
                pc--;
                temp=temp->left;
            }

            TAinstall('C',root->NAME,NULL,NULL);
            current_temp=ct;
            while(ct)
            {
                 t[0]='t';t[1]='\0';
                strcat(t,itoa(ct));
                TAinstall('p',t,NULL,NULL);
                ct--;
            }
            break;
        }
        case 'v':
        {
            char *t =(char *) malloc(5);
            current_temp++;
            t[0]='t';t[1]='\0';
            strcat(t,itoa(current_temp));

            if(Llookup(root->NAME, ltemp))
                TAinstall('M',t,itoa(Llookup(root->NAME, ltemp)->BINDING+1+SP),NULL);
            else
                TAinstall('M',t,itoa(Glookup(root->NAME)->BINDING),NULL);
            break;
        }
        default:
        {
            Gen3A(root->center,0);
            Gen3A(root->left,0);
            Gen3A(root->right,0);
            break;
        }
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

  
#line 1613 "y.tab.c"

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
#line 149 "func.y"
	{ printf("PARSING SUCCESS\n"); yyval.n=CreateNode(0,'S', 0, NULL, yystack.l_mark[-1].n, yystack.l_mark[0].n, NULL); PrintSymbol(); printTree(yyval.n); Gen3A(yyval.n,0); print_TAlist(); }
break;
case 3:
#line 153 "func.y"
	{/*empty*/}
break;
case 8:
#line 161 "func.y"
	{ TYPE = INT; }
break;
case 9:
#line 162 "func.y"
	{TYPE = BOOL; }
break;
case 10:
#line 164 "func.y"
	{ FTYPE = INT; }
break;
case 11:
#line 165 "func.y"
	{FTYPE = BOOL; }
break;
case 12:
#line 168 "func.y"
	{}
break;
case 13:
#line 169 "func.y"
	{ }
break;
case 14:
#line 172 "func.y"
	{}
break;
case 19:
#line 183 "func.y"
	{ makeArglist2(newArg);    }
break;
case 20:
#line 184 "func.y"
	{ makeArglist2(newArg);  }
break;
case 21:
#line 187 "func.y"
	{
                            newArg = malloc(sizeof(struct ArgStruct));
                            newArg->ARGNAME = yystack.l_mark[0].n->NAME;
                            newArg->ARGTYPE = TYPE;
                            newArg->PASSTYPE = 0;
                            newArg->ARGNEXT = NULL;
        }
break;
case 22:
#line 194 "func.y"
	{
                             newArg = malloc(sizeof(struct ArgStruct));
                            newArg->ARGNAME = yystack.l_mark[0].n->NAME;
                            newArg->ARGTYPE = TYPE;
                            newArg->PASSTYPE = 1;
                            newArg->ARGNEXT = NULL;
    }
break;
case 25:
#line 206 "func.y"
	{ }
break;
case 26:
#line 209 "func.y"
	{ makeArglist(newArg);	}
break;
case 27:
#line 210 "func.y"
	{ makeArglist(newArg);	}
break;
case 28:
#line 213 "func.y"
	{
							newArg = malloc(sizeof(struct ArgStruct));
							newArg->ARGNAME = yystack.l_mark[0].n->NAME;
							newArg->ARGTYPE = TYPE;
							newArg->PASSTYPE = 0;
							newArg->ARGNEXT = NULL;
		}
break;
case 29:
#line 220 "func.y"
	{
						   	 newArg = malloc(sizeof(struct ArgStruct));
							newArg->ARGNAME = yystack.l_mark[0].n->NAME;
							newArg->ARGTYPE = TYPE;
							newArg->PASSTYPE = 1;
							newArg->ARGNEXT = NULL;
	}
break;
case 30:
#line 231 "func.y"
	{
            printf("*****offset of %s is %d\n",yystack.l_mark[0].n->NAME,Goffset);
            Ginstall(yystack.l_mark[0].n->NAME, TYPE, 0, Goffset, 0, NULL,NULL);
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
case 31:
#line 246 "func.y"
	{
                                Ginstall(yystack.l_mark[-3].n->NAME, TYPE+2, yystack.l_mark[-1].n->VALUE, Goffset, 0, NULL, NULL);
                                 printf("*****offset of %s[%d] is %d\n",yystack.l_mark[-3].n->NAME,yystack.l_mark[-1].n->VALUE,Goffset);
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
case 32:
#line 262 "func.y"
	{
                                
                                headArg = NULL;
                                Ginstall(yystack.l_mark[0].n->NAME, TYPE, 0, Goffset, 0, NULL, NULL);
                                printf("*****offset of function %s is %d\n",yystack.l_mark[0].n->NAME,Goffset);
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
case 33:
#line 280 "func.y"
	{

    							struct Gsymbol* gt =  Glookup(yystack.l_mark[-4].n->NAME);
                                if(gt)
                                {
                                    gt->ARGLIST = headArg;
    							}else
                                    yyerror("function not found");
                        }
break;
case 34:
#line 292 "func.y"
	{ yyval.n = NULL; }
break;
case 35:
#line 293 "func.y"
	{  yyval.n=CreateNode(0,'S', 0, NULL, yystack.l_mark[-1].n, yystack.l_mark[0].n, NULL); if ((yystack.l_mark[-1].n==NULL || yystack.l_mark[-1].n->TYPE == FUNC) && yystack.l_mark[0].n->TYPE== FUNC) yyval.n->TYPE= FUNC; else {yyval.n->TYPE=-1; yyerror("Bad functions") ;} }
break;
case 36:
#line 296 "func.y"
	{ fname = (char *)malloc(30); strcpy(fname,yystack.l_mark[0].n->NAME); }
break;
case 37:
#line 296 "func.y"
	{ 
                                                                struct Gsymbol* gt =  Glookup(yystack.l_mark[-7].n->NAME);
                                                                if(gt)
                                                                {
                                                                    gt->LTABLE = Lnode;
                                                                    gt->ARGLIST = headArg2;
                                                                }
                                                                yyval.n=CreateNode(0,'f', 0, fname, yystack.l_mark[-4].n, yystack.l_mark[-1].n, NULL);
                                                                if(yystack.l_mark[-1].n->TYPE == FTYPE) { yyval.n->TYPE=FUNC; }else{ yyerror(" return type error"); yyval.n->TYPE = -1;}
                                                                PrintLSymbol(Lnode);

        }
break;
case 38:
#line 310 "func.y"
	{                                      headArg = (struct ArgStruct*)NULL;
                                                                    headArg2 = (struct ArgStruct*)NULL;
                                                                    fname = (char *)malloc(30);
                                                                    strcpy(fname,yystack.l_mark[0].n->NAME);
                                                                    FTYPE = INT;
                             }
break;
case 39:
#line 317 "func.y"
	{
                                                                    yyval.n=CreateNode(0,'f', 0, "MAIN", NULL, yystack.l_mark[-1].n, NULL);
                                                                    if(yystack.l_mark[-1].n->TYPE == FTYPE) { yyval.n->TYPE=0; }else{ yyerror(" return type error"); printf("main return %d",yystack.l_mark[-1].n->TYPE); yyval.n->TYPE = -1;}
                                                                    yyval.n->lookup=yystack.l_mark[-1].n->lookup;
                                                                }
break;
case 40:
#line 324 "func.y"
	{ if( strcmp(fname,"main")!=0)
                        {
                        if (fnDefCheck(INT, fname, headArg2))
                        {
                            struct Gsymbol* gt = Glookup(fname);
                            if(gt)
                            {
                                gt->LTABLE = Lnode;
                                gt->ARGLIST = headArg2;
                            }
                            else yyerror("Function definition error");
                        }
                        }
                        else
                        {
                            Ginstall(fname, FTYPE, 0, Goffset, 0, NULL, Lnode);
                        }
                    }
break;
case 41:
#line 342 "func.y"
	{ yyval.n = yystack.l_mark[0].n;}
break;
case 42:
#line 345 "func.y"
	{ Lnode = malloc(sizeof(struct Lsymbol)); Lnode = NULL; Loffset = 0; }
break;
case 43:
#line 345 "func.y"
	{  }
break;
case 44:
#line 347 "func.y"
	{/*empty*/}
break;
case 49:
#line 356 "func.y"
	{
        Lnode = Linstall(yystack.l_mark[0].n->NAME, TYPE, Loffset, 0,0, Lnode);
         printf("*****L offset of %s is %d\n",yystack.l_mark[0].n->NAME,Loffset);
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
case 50:
#line 373 "func.y"
	{  yyval.n=CreateNode(1,'S', 0, NULL, yystack.l_mark[-2].n, yystack.l_mark[-1].n, NULL); if (yystack.l_mark[-2].n==NULL || yystack.l_mark[-2].n->TYPE==0) { yyval.n->TYPE = yystack.l_mark[-1].n->TYPE; } else {yyval.n->TYPE=-1; yyerror("Bad begin error");} }
break;
case 51:
#line 376 "func.y"
	{ yyval.n = NULL; }
break;
case 52:
#line 377 "func.y"
	{  yyval.n=CreateNode(0,'S', 0, NULL, yystack.l_mark[-1].n, yystack.l_mark[0].n, NULL); if ((yystack.l_mark[-1].n==NULL || yystack.l_mark[-1].n->TYPE==0) && yystack.l_mark[0].n->TYPE==0) yyval.n->TYPE=0; else { yyval.n->TYPE=-1; yyerror("Bad statements");}}
break;
case 53:
#line 380 "func.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 54:
#line 381 "func.y"
	{ yyval.n = yystack.l_mark[0].n;}
break;
case 55:
#line 382 "func.y"
	{ yyval.n = yystack.l_mark[0].n;  }
break;
case 56:
#line 383 "func.y"
	{ yyval.n = yystack.l_mark[0].n;  }
break;
case 57:
#line 384 "func.y"
	{ yyval.n = yystack.l_mark[0].n;  }
break;
case 58:
#line 387 "func.y"
	{ yystack.l_mark[-5].n = CreateNode(0,'I', 0, NULL, yystack.l_mark[-2].n, yystack.l_mark[-4].n, NULL); yyval.n = yystack.l_mark[-5].n;
                                                if (yystack.l_mark[-4].n->TYPE==2 && (yystack.l_mark[-2].n==NULL || yystack.l_mark[-2].n->TYPE==0)) yyval.n->TYPE=0; else {yyval.n->TYPE=-1; yyerror("If type error"); } }
break;
case 59:
#line 389 "func.y"
	{ yystack.l_mark[-7].n = CreateNode(0,'I', 0, NULL, yystack.l_mark[-4].n, yystack.l_mark[-6].n, yystack.l_mark[-2].n); yyval.n = yystack.l_mark[-7].n;
                                                if (yystack.l_mark[-6].n->TYPE==2 && (yystack.l_mark[-4].n==NULL || yystack.l_mark[-4].n->TYPE==0) && (yystack.l_mark[-2].n==NULL || yystack.l_mark[-2].n->TYPE==0)) yyval.n->TYPE=0; else { yyval.n->TYPE=-1; yyerror("If else error");}}
break;
case 60:
#line 393 "func.y"
	{ yystack.l_mark[-5].n = CreateNode(0,'W', 0, NULL, yystack.l_mark[-2].n, yystack.l_mark[-4].n, NULL); yyval.n=yystack.l_mark[-5].n; if (yystack.l_mark[-4].n->TYPE==2 && (yystack.l_mark[-2].n==NULL || yystack.l_mark[-2].n->TYPE==0)) yyval.n->TYPE=0; else yyval.n->TYPE=-1; yyerror("while error"); }
break;
case 61:
#line 396 "func.y"
	{ yystack.l_mark[-2].n = CreateNode(0,'=', 0, NULL, yystack.l_mark[-3].n, NULL, yystack.l_mark[-1].n); yyval.n=yystack.l_mark[-2].n;
                                            struct Lsymbol* lt = Llookup(yystack.l_mark[-3].n->NAME, Lnode);
                                            if(lt) { if (lt->TYPE == yystack.l_mark[-1].n->TYPE ) yyval.n->TYPE=0; }
                                            else {
                                                struct Gsymbol* gt = Glookup(yystack.l_mark[-3].n->NAME);
                                                if(gt) { if ( gt->SIZE==0 && (gt->TYPE == yystack.l_mark[-1].n->TYPE )) yyval.n->TYPE=0;
                                                else { yyval.n->TYPE=-1;	yyerror("Wrong assignment");}}else { printf("ID %s not found\n",yystack.l_mark[-3].n->NAME); yyerror(""); yyval.n->TYPE=-1;}
                                            }}
break;
case 62:
#line 404 "func.y"
	{ yystack.l_mark[-6].n->center = yystack.l_mark[-4].n; yystack.l_mark[-2].n = CreateNode(0,'=', 0, NULL, yystack.l_mark[-6].n, NULL, yystack.l_mark[-1].n); yyval.n=yystack.l_mark[-2].n;
                                                                struct Gsymbol* gt = Glookup(yystack.l_mark[-6].n->NAME);
                                                                if(gt) {if ( gt->SIZE!=0 && yystack.l_mark[-4].n->TYPE==INT && ((gt->TYPE-2) == yystack.l_mark[-1].n->TYPE)) yyval.n->TYPE=0; else { yyval.n->TYPE=-1;
                                                                yyerror("Wrong assignment of array type");}} else {printf("Array %s not found\n",yystack.l_mark[-6].n->NAME); yyerror(""); yyval.n->TYPE=-1; }
                                                            }
break;
case 63:
#line 411 "func.y"
	{ yystack.l_mark[-4].n = CreateNode(0,'r', 0, NULL, NULL, yystack.l_mark[-2].n, NULL); yyval.n = yystack.l_mark[-4].n;
                                            struct Lsymbol* lt = Llookup(yystack.l_mark[-2].n->NAME, Lnode);
                                            if(lt && (lt->TYPE == 1))
                                                yyval.n->TYPE=0;
                                            else {
                                                struct Gsymbol* gt = Glookup(yystack.l_mark[-2].n->NAME);
                                                if(gt) {if( gt->SIZE==0 && gt->TYPE == 1 ) yyval.n->TYPE=0; else { yyval.n->TYPE=-1;
                                                yyerror("Read type error");}} else { printf("ID %s not found\n",yystack.l_mark[-2].n->NAME); yyerror(""); yyval.n->TYPE=-1;}
                                            }}
break;
case 64:
#line 420 "func.y"
	{ yystack.l_mark[-5].n->center = yystack.l_mark[-3].n;  yystack.l_mark[-7].n = CreateNode(0,'r', 0, NULL, NULL, yystack.l_mark[-5].n, NULL); yyval.n = yystack.l_mark[-7].n;
                                                struct Gsymbol* gt = Glookup(yystack.l_mark[-5].n->NAME);
                                                if(gt) { if(gt->SIZE!=0 && gt->TYPE==(INT+2) && yystack.l_mark[-3].n->TYPE==1) yyval.n->TYPE=0; else { yyval.n->TYPE=-1;
                                                yyerror("Read type error");}} else { printf("ID %s not found\n",yystack.l_mark[-5].n->NAME); yyerror(""); yyval.n->TYPE=-1;}
                                            }
break;
case 65:
#line 427 "func.y"
	{ yystack.l_mark[-4].n = CreateNode(0,'w', 0, NULL, NULL, yystack.l_mark[-2].n, NULL); yyval.n = yystack.l_mark[-4].n;
                                                                            if(yystack.l_mark[-2].n->TYPE==1) yyval.n->TYPE=0; else {yyval.n->TYPE=-1; yyerror("Write error");} }
break;
case 66:
#line 431 "func.y"
	{ yystack.l_mark[-2].n = CreateNode(0,'R', 0, NULL, NULL, yystack.l_mark[-1].n, NULL);  yyval.n = yystack.l_mark[-2].n;
                                        yyval.n->TYPE = yystack.l_mark[-1].n->TYPE;  }
break;
case 67:
#line 435 "func.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'+', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==1 && yystack.l_mark[0].n->TYPE ==1) yyval.n->TYPE=1; else {yyval.n->TYPE=-1; yyerror("+ error");} }
break;
case 68:
#line 436 "func.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'-', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==1 && yystack.l_mark[0].n->TYPE ==1) yyval.n->TYPE=1; else {yyval.n->TYPE=-1; yyerror("- error"); } }
break;
case 69:
#line 437 "func.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'*', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==1 && yystack.l_mark[0].n->TYPE ==1) yyval.n->TYPE=1; else{yyval.n->TYPE=-1; yyerror("* error"); }}
break;
case 70:
#line 438 "func.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'/', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n;  if(yystack.l_mark[-2].n->TYPE==1 && yystack.l_mark[0].n->TYPE ==1) yyval.n->TYPE=1; else {yyval.n->TYPE=-1; yyerror("/ error"); }}
break;
case 71:
#line 439 "func.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'%', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==1 && yystack.l_mark[0].n->TYPE ==1) yyval.n->TYPE=1; else {yyval.n->TYPE=-1; yyerror("%error"); }}
break;
case 72:
#line 440 "func.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'E', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==1 && yystack.l_mark[0].n->TYPE ==1) yyval.n->TYPE=2; else {yyval.n->TYPE=-1; yyerror("== error");  }}
break;
case 73:
#line 441 "func.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'<', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==1 && yystack.l_mark[0].n->TYPE ==1) yyval.n->TYPE=2; else {yyval.n->TYPE=-1; yyerror("< error"); }}
break;
case 74:
#line 442 "func.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'>', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==1 && yystack.l_mark[0].n->TYPE ==1) yyval.n->TYPE=2; else {yyval.n->TYPE=-1; yyerror("> error"); }}
break;
case 75:
#line 443 "func.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'G', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==1 && yystack.l_mark[0].n->TYPE ==1) yyval.n->TYPE=2; else {yyval.n->TYPE=-1; yyerror(">= error"); }}
break;
case 76:
#line 444 "func.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'L', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==1 && yystack.l_mark[0].n->TYPE ==1) yyval.n->TYPE=2; else {yyval.n->TYPE=-1; yyerror("<= error"); } }
break;
case 77:
#line 445 "func.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'N', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==1 && yystack.l_mark[0].n->TYPE ==1) yyval.n->TYPE=2; else {yyval.n->TYPE=-1; yyerror("!= error"); } }
break;
case 78:
#line 446 "func.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'&', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==2 && yystack.l_mark[0].n->TYPE ==2) yyval.n->TYPE=2; else {yyval.n->TYPE=-1; yyerror("& error");} }
break;
case 79:
#line 447 "func.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'|', 0, NULL, yystack.l_mark[-2].n, NULL, yystack.l_mark[0].n); yyval.n = yystack.l_mark[-1].n; if(yystack.l_mark[-2].n->TYPE==2 && yystack.l_mark[0].n->TYPE ==2) yyval.n->TYPE=2; else {yyval.n->TYPE=-1; yyerror("| error");} }
break;
case 80:
#line 448 "func.y"
	{ yystack.l_mark[-1].n = CreateNode(0,'!', 0, NULL, NULL, yystack.l_mark[0].n, NULL); yyval.n = yystack.l_mark[-1].n;  if(yystack.l_mark[0].n->TYPE==2) yyval.n->TYPE=2; {yyval.n->TYPE=-1; yyerror("NOT error");} }
break;
case 81:
#line 449 "func.y"
	{ yyval.n = yystack.l_mark[-1].n; }
break;
case 82:
#line 450 "func.y"
	{ yystack.l_mark[0].n = CreateNode(2,'T', 0, NULL,NULL,NULL,NULL); yyval.n = yystack.l_mark[0].n;  }
break;
case 83:
#line 451 "func.y"
	{ yystack.l_mark[0].n = CreateNode(2,'F', 0, NULL, NULL, NULL, NULL); yyval.n = yystack.l_mark[0].n; }
break;
case 84:
#line 452 "func.y"
	{ yyval.n=yystack.l_mark[0].n; }
break;
case 85:
#line 453 "func.y"
	{ yyval.n = yystack.l_mark[0].n; struct Lsymbol* lt = Llookup(yystack.l_mark[0].n->NAME, Lnode); if(lt) yyval.n->TYPE=lt->TYPE; else {
                                                            struct Gsymbol* gt = Glookup(yystack.l_mark[0].n->NAME);
                                                            if(gt) {if(gt->SIZE==0) yyval.n->TYPE=gt->TYPE; else yyval.n->TYPE=-1; }
                                                            else { printf("ID %s not found\n",yystack.l_mark[0].n->NAME); yyerror(""); yyval.n->TYPE=-1;}}}
break;
case 86:
#line 457 "func.y"
	{   yystack.l_mark[-3].n->center = yystack.l_mark[-1].n; yyval.n = yystack.l_mark[-3].n;  struct Gsymbol* gt = Glookup(yystack.l_mark[-3].n->NAME);
                                                                    if(gt) { if(gt->SIZE!=0 && yystack.l_mark[-1].n->TYPE==1)
                                                                    yyval.n->TYPE=gt->TYPE; else yyval.n->TYPE=-1; yyerror("array type expression"); }
                                                                    else { printf("Array %s not found\n",yystack.l_mark[-3].n->NAME); yyerror(""); yyval.n->TYPE=-1;}}
break;
case 87:
#line 461 "func.y"
	{ struct Gsymbol* gtemp = Glookup(yystack.l_mark[-3].n->NAME);
                                    yyval.n=CreateNode(0,'C', pcount, yystack.l_mark[-3].n->NAME,NULL,yystack.l_mark[-1].n,NULL);
                                    if(gtemp==NULL || gtemp->SIZE!=0) yyerror("Undefined Function");
                                    else
                                    {
                                        yyval.n->lookup = gtemp->LTABLE;
                                        yyval.n->TYPE = gtemp->TYPE;
                                    }
                                    struct ArgStruct* ARGLIST = gtemp->ARGLIST;
                                    struct node* ptemp=yystack.l_mark[-1].n;
                                    printf("PRINTING AGRUMENTS\n");
                                    printArg(ARGLIST);
                                    while(ARGLIST )
                                    {
                                        if(pcount>0 )
                                        {
                                            printf("%s %d %d\n",ARGLIST->ARGNAME, ARGLIST->ARGTYPE, ptemp->center->TYPE );
                                            if(ptemp==NULL && ARGLIST)
                                            {
                                                yyerror("argument count error 1");
                                            }
                                            else
                                            if(ARGLIST==NULL && ptemp)
                                            {
                                                yyerror("argument count error 2");
                                            }
                                            else
                                            if(ARGLIST->ARGTYPE == ptemp->center->TYPE)
                                            {
                                                if(ARGLIST->PASSTYPE == 1)
                                                {
                                                    if(ptemp->center->PASSTYPE==1)
                                                    {
                                                        printf("matched argument %d\n",pcount);
                                                    }
                                                    else{
                                                        yyerror("argument type error 1");
                                                    }
                                                    ARGLIST=ARGLIST->ARGNEXT;
                                                    ptemp = ptemp->left;

                                                }else if(ARGLIST->PASSTYPE == 0){
                                                    printf("NODETYPE %d\n",ptemp->center->PASSTYPE);
                                                    if(ptemp->center->PASSTYPE==0)
                                                    {
                                                        printf("matched argument %d\n",pcount);
                                                    }
                                                    else{
                                                        yyerror("argument type error 2");
                                                    }
                                                    ARGLIST=ARGLIST->ARGNEXT;
                                                    ptemp = ptemp->left;
                                                }

                                            }else
                                            {
                                                 yyerror("match type error 1");
                                            }
                                            pcount--;
                                        }else
                                        {
                                        break;
                                        }
                                    }
                                    pcount=0;
                            }
break;
case 88:
#line 529 "func.y"
	{ yyval.n=NULL; }
break;
case 89:
#line 530 "func.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 90:
#line 533 "func.y"
	{ yyval.n=CreateNode(0,'z', 0, NULL,yystack.l_mark[-2].n,yystack.l_mark[0].n,NULL); pcount++; }
break;
case 91:
#line 534 "func.y"
	{ yyval.n=CreateNode(0,'z', 0, NULL,NULL,yystack.l_mark[0].n,NULL); pcount++; yystack.l_mark[0].n->PASSTYPE=0; }
break;
case 92:
#line 535 "func.y"
	{ yyval.n = yystack.l_mark[-1].n; yyval.n->PASSTYPE=1; struct Lsymbol* lt = Llookup(yystack.l_mark[-1].n->NAME, Lnode); if(lt) yyval.n->TYPE=lt->TYPE; else {
                                                            struct Gsymbol* gt = Glookup(yystack.l_mark[-1].n->NAME);
                                                            if(gt) {if(gt->SIZE==0) yyval.n->TYPE=gt->TYPE; else yyval.n->TYPE=-1; }
                                                            else { printf("ID %s not found\n",yystack.l_mark[-1].n->NAME); yyerror(""); yyval.n->TYPE=-1;}}
                        }
break;
#line 2358 "y.tab.c"
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
