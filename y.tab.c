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
/*struct node* TreeCreate_(int TYPE, int NODETYPE, int VALUE, char* NAME, struct node *ptr1, struct node *ptr2, struct node *ptr3) {
	struct node* temp=malloc(sizeof(struct node));
	temp->TYPE		=	TYPE;
	temp->NODETYPE	=	NODETYPE;
	temp->VALUE		=	VALUE;
	temp->left		=	ptr1; // left node
	temp->link		=	ptr2; // unkownn nodes
	temp->right		=	ptr3; // right node
	return temp;
}
*/

#line 18 "piyush.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	char* str;
	int num;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 46 "y.tab.c"

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
#define PRINT 298
#define BEGINN 299
#define END 300
#define RETURN 301
#define RECORD 302
#define MAIN 303
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    0,    1,    3,    3,    4,    6,    6,    5,    5,
    7,    7,    7,    2,    8,    9,   11,   11,   12,   13,
   13,   14,   14,   10,   15,   15,   17,   17,   17,   17,
   17,   18,   18,   19,   22,   20,   21,   16,   24,   24,
   25,   25,   25,   25,   25,   25,   25,   25,   25,   23,
   23,   23,   23,   23,   23,   23,   23,   23,   23,   23,
   23,
};
static const short yylen[] = {                            2,
    1,    2,    3,    1,    2,    3,    1,    3,    1,    1,
    1,    4,    2,    7,    2,    3,    1,    2,    3,    1,
    3,    1,    2,    4,    1,    2,    1,    1,    1,    1,
    1,    6,    8,    6,    4,    5,    5,    3,    1,    1,
    3,    3,    3,    3,    3,    3,    1,    1,    4,    3,
    3,    3,    3,    3,    3,    3,    3,    2,    3,    1,
    1,
};
static const short yydefred[] = {                         0,
    0,    0,    0,    9,   10,    0,    4,    0,    0,    2,
    3,    5,    0,    0,    0,    7,    0,    0,   13,    6,
    0,    0,    0,    8,    0,   12,    0,    0,    0,    0,
    0,    0,   17,   14,    0,   15,   22,    0,    0,   20,
   16,   18,    0,    0,    0,    0,    0,    0,   25,   27,
   28,   29,   30,   31,   23,   19,    0,    0,    0,    0,
    0,   60,   61,    0,   48,    0,    0,    0,    0,    0,
    0,   26,   21,    0,    0,    0,    0,    0,    0,    0,
   58,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   24,
   35,    0,    0,    0,    0,   59,   46,   56,    0,    0,
   45,    0,    0,    0,    0,    0,    0,    0,    0,   43,
   44,    0,   38,   36,   37,   49,    0,    0,    0,   32,
    0,   34,    0,   33,
};
static const short yydgoto[] = {                          2,
    3,   10,    6,    7,    8,   15,   16,   29,   30,   36,
   32,   33,   39,   40,   48,   71,   49,   50,   51,   52,
   53,   54,   67,   75,   68,
};
static const short yysindex[] = {                      -242,
 -204,    0, -234,    0,    0,  -81,    0, -260, -274,    0,
    0,    0, -220, -200, -157,    0, -233, -215,    0,    0,
 -260, -216, -192,    0, -183,    0, -161, -204, -178, -175,
 -252,   18,    0,    0, -165,    0,    0, -137, -126,    0,
    0,    0, -147, -144, -131, -211, -211, -256,    0,    0,
    0,    0,    0,    0,    0,    0, -252, -211,  -89, -212,
 -100,    0,    0, -211,    0, -211, -265,  -23, -221, -212,
 -117,    0,    0,  -69,  -54,  -23,  -82, -212,  -46, -212,
    0, -217,  -52, -211, -211, -165, -212, -212, -212, -212,
 -212, -212, -212, -212, -212, -212, -212, -165,  -63,    0,
    0,  -51,  -39,  -35, -123,    0,    0,    0,  -50,  -60,
    0,  -16,  -16,  -16,  -16,  -16,  -16, -190, -190,    0,
    0,  -75,    0,    0,    0,    0,  -19, -165,  -11,    0,
 -135,    0,   -4,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,  221,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -70,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -199,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   -3,    0,   -2,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -229,    0,
    0, -164, -114, -101,  -99,  -86,  -84, -166, -134,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
    0,    0,    0,  253,   -7,    0,  248,    0,    0,    0,
    0,  238,    0,  214,  -85,    0,  -48,    0,    0,    0,
    0,    0,  -38,    0,  -56,
};
#define YYTABLESIZE 280
static const short yytable[] = {                         72,
  110,   76,   13,   79,   84,   85,   43,   14,   69,   83,
   37,   86,  122,   99,    1,   38,   44,   45,   46,   74,
   31,  103,   47,  105,   31,   81,    9,   82,   17,   57,
  111,  112,  113,  114,  115,  116,  117,  118,  119,  120,
  121,   57,  131,   18,   70,  108,  109,   57,   84,   85,
   61,   61,   84,   85,   62,   63,    4,    5,   22,   47,
   64,   72,   19,   57,   23,   47,   57,   65,   65,   47,
   47,   47,   26,   72,   98,  106,   25,   47,   87,   78,
   66,   47,   72,   47,   47,   47,   47,   47,   47,   47,
   47,   47,   41,   47,   50,   28,   47,   43,   41,   96,
   97,   20,   21,   41,   41,   50,   50,   44,   45,   46,
   41,   27,   50,   47,   41,   34,   41,   41,   41,   41,
   41,   41,   41,   35,   42,   55,   41,   43,   50,   41,
   42,   50,   56,   57,   58,   42,   42,   44,   45,   46,
  133,  126,   42,   47,   55,   87,   42,   59,   42,   42,
   42,   42,   42,   42,   42,   55,   55,   51,   42,   54,
   60,   42,   55,   80,   94,   95,   96,   97,   51,   51,
   54,   54,   52,   77,   53,   51,   11,   54,   55,    4,
    5,   55,  100,   52,   52,   53,   53,   43,   11,   11,
   52,   51,   53,   54,   51,  123,   54,   44,   45,   46,
   84,   85,   43,   47,  101,   87,   52,  124,   53,   52,
  102,   53,   44,   45,   46,  127,   87,  128,   47,   84,
    1,  129,   87,  125,   94,   95,   96,   97,   88,   87,
   89,   90,   91,   92,   93,   94,   95,   96,   97,  130,
  107,   94,   95,   96,   97,   87,  104,  132,   94,   95,
   96,   97,   87,  107,  134,   40,   39,   88,   12,   89,
   90,   91,   92,   93,   94,   95,   96,   97,   24,   42,
   73,   94,   95,   96,   97,   41,    0,    0,    4,    5,
};
static const short yycheck[] = {                         48,
   86,   58,  263,   60,  270,  271,  263,  268,   47,   66,
  263,  277,   98,   70,  257,  268,  273,  274,  275,   58,
   28,   78,  279,   80,   32,   64,  261,   66,  303,  259,
   87,   88,   89,   90,   91,   92,   93,   94,   95,   96,
   97,  271,  128,  264,  301,   84,   85,  277,  270,  271,
  263,  263,  270,  271,  266,  267,  261,  262,  292,  259,
  272,  110,  263,  293,  280,  265,  296,  280,  280,  269,
  270,  271,  265,  122,  296,  293,  293,  277,  269,  292,
  292,  281,  131,  283,  284,  285,  286,  287,  288,  289,
  290,  291,  259,  293,  259,  257,  296,  263,  265,  290,
  291,  259,  260,  270,  271,  270,  271,  273,  274,  275,
  277,  295,  277,  279,  281,  294,  283,  284,  285,  286,
  287,  288,  289,  299,  259,  263,  293,  263,  293,  296,
  265,  296,  259,  260,  282,  270,  271,  273,  274,  275,
  276,  265,  277,  279,  259,  269,  281,  292,  283,  284,
  285,  286,  287,  288,  289,  270,  271,  259,  293,  259,
  292,  296,  277,  264,  288,  289,  290,  291,  270,  271,
  270,  271,  259,  263,  259,  277,  258,  277,  293,  261,
  262,  296,  300,  270,  271,  270,  271,  263,  259,  260,
  277,  293,  277,  293,  296,  259,  296,  273,  274,  275,
  270,  271,  263,  279,  259,  269,  293,  259,  293,  296,
  293,  296,  273,  274,  275,  276,  269,  278,  279,  270,
    0,  297,  269,  259,  288,  289,  290,  291,  281,  269,
  283,  284,  285,  286,  287,  288,  289,  290,  291,  259,
  293,  288,  289,  290,  291,  269,  293,  259,  288,  289,
  290,  291,  269,  293,  259,  259,  259,  281,    6,  283,
  284,  285,  286,  287,  288,  289,  290,  291,   21,   32,
   57,  288,  289,  290,  291,  258,   -1,   -1,  261,  262,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 303
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
"LFLOWER","DO","ENDWHILE","PRINT","BEGINN","END","RETURN","RECORD","MAIN",
};
static const char *yyrule[] = {
"$accept : body",
"body : Gdeclaration",
"body : Gdeclaration main_function",
"Gdeclaration : DECL GdeclStatements ENDDECL",
"GdeclStatements : GdeclStatement",
"GdeclStatements : GdeclStatements GdeclStatement",
"GdeclStatement : type Gvars SEMICOLON",
"Gvars : Gvar",
"Gvars : Gvars COMMA Gvar",
"type : INTEGER",
"type : BOOLEAN",
"Gvar : ID",
"Gvar : ID LSQUARE NUMBER RSQUARE",
"Gvar : ADDRESSOF ID",
"main_function : INTEGER MAIN LPAREN RPAREN LFLOWER fbody RFLOWER",
"fbody : declaration beginbody",
"declaration : DECL declStatements ENDDECL",
"declStatements : declStatement",
"declStatements : declStatements declStatement",
"declStatement : type vars SEMICOLON",
"vars : var",
"vars : vars COMMA var",
"var : ID",
"var : ADDRESSOF ID",
"beginbody : BEGINN statements mreturn END",
"statements : statement",
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
"read : READ LPAREN ID RPAREN SEMICOLON",
"write : WRITE LPAREN aexpression RPAREN SEMICOLON",
"mreturn : RETURN aexpression SEMICOLON",
"expression : aexpression",
"expression : lexpression",
"aexpression : aexpression PLUS aexpression",
"aexpression : aexpression MINUS aexpression",
"aexpression : aexpression MULT aexpression",
"aexpression : aexpression DIVIDE aexpression",
"aexpression : aexpression MODULUS aexpression",
"aexpression : LPAREN aexpression RPAREN",
"aexpression : ID",
"aexpression : NUMBER",
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
#line 144 "piyush.y"

int main(){
	return(yyparse());
}

yyerror(s)
char *s;
{
  fprintf(stderr, "%s\n",s);
}
#line 396 "y.tab.c"

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
#line 39 "piyush.y"
	{ printf("PARSING SUCCESS\n"); }
break;
case 2:
#line 40 "piyush.y"
	{ printf("PARSING SUCCESS\n"); }
break;
#line 610 "y.tab.c"
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
