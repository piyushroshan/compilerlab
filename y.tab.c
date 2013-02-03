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

#line 2 "sil.y"
char *language_string = "GNU C";
#include <stdio.h>
#line 6 "sil.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union
{
	int num;
	char* str;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 35 "y.tab.c"

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
    0,    0,    0,    1,    4,    4,    5,    7,    7,    6,
    6,    8,    8,    8,    8,    9,    9,   10,   10,   11,
   11,   11,   11,    3,    3,   12,    2,   13,   13,   14,
   17,   17,   19,   19,   19,   19,   19,   15,   15,   20,
   16,   23,   21,   22,   24,   24,   25,   25,   25,   25,
   25,   25,   25,   18,   18,   18,   18,   18,   18,   18,
};
static const short yylen[] = {                            2,
    1,    2,    3,    3,    1,    2,    2,    2,    3,    1,
    1,    1,    4,    4,    2,    0,    2,    3,    1,    3,
    1,    2,    4,    1,    2,    8,    7,    1,    2,    4,
    6,    8,    1,    1,    1,    1,    1,    1,    2,    6,
    3,    4,    5,    5,    1,    1,    3,    3,    3,    3,
    3,    1,    1,    3,    3,    3,    3,    3,    3,    3,
};
static const short yydefred[] = {                         0,
    0,    0,    0,   10,   11,    0,    0,    0,    0,    2,
    0,    0,   24,    4,    6,    0,    0,    7,    0,    0,
    3,   25,    0,    0,    0,   15,    8,    0,    0,    0,
    0,    0,    0,    9,    0,    0,   13,    0,    0,   17,
    0,   14,    0,    0,    0,    0,    0,    0,    0,    0,
   20,    0,   18,    0,   29,   27,    0,   23,    0,    0,
    0,    0,    0,    0,   33,    0,   34,   35,   36,   37,
   26,    0,    0,    0,   52,   53,    0,    0,    0,    0,
    0,    0,   39,   46,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   30,   42,    0,    0,    0,   60,
   51,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   49,   50,    0,   41,   43,   44,    0,    0,    0,   31,
    0,   40,    0,   32,
};
static const short yydgoto[] = {                          2,
   48,   10,   11,    6,    7,   32,   18,   19,   33,   40,
   41,   13,   49,   55,   64,   82,   65,   84,   66,   67,
   68,   69,   70,   85,   79,
};
static const short yysindex[] = {                      -240,
 -193,    0, -104,    0,    0, -233, -193, -146, -282,    0,
 -104, -235,    0,    0,    0, -194, -205,    0, -185, -227,
    0,    0, -220, -197, -193,    0,    0, -146, -208, -193,
 -184, -108, -144,    0, -195, -134,    0, -154, -142,    0,
  -94,    0, -240, -129, -108,  -93, -193, -131, -125, -240,
    0, -108,    0, -260,    0,    0, -124,    0, -111, -120,
 -119, -196, -196, -126,    0, -260,    0,    0,    0,    0,
    0, -196,  -89, -187,    0,    0, -196, -101, -147, -118,
 -196, -123,    0,    0,  -80, -147, -113, -187, -143, -112,
 -158, -260, -187, -187, -187, -187, -187, -187, -187, -187,
 -187, -187, -260,  -77,    0,    0,  -76, -137,  -75,    0,
    0, -212, -127, -127, -127, -127, -127, -127, -172, -172,
    0,    0, -110,    0,    0,    0,  -74, -260,  -73,    0,
  -88,    0,  -70,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,  190,    0,    0,    0,  -67,    0,  -71,    0,
    0,    0,    0,    0,    0, -156,    0,    0,    0,    0,
    0,    0,    0,    0, -100,    0,    0,    0,    0, -100,
    0,    0,    0,    0,    0,    0,    0, -257,    0,    0,
  -99,    0,    0,    0,    0, -252, -100,  -98,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -177,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -64,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -239, -216, -214, -206, -204, -199, -254, -237,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
  197,  187,    0,  192,    0,    5,  172,    0,  -29,    0,
  -41,  191,  151,    0,  -66,    0,    0,  -53,    0,    0,
    0,    0,    0,  122,   14,
};
#define YYTABLESIZE 203
static const short yytable[] = {                         83,
   36,   21,   59,   51,   47,    8,   22,   12,   78,   80,
   58,    8,   60,   61,   62,   12,    1,   53,   63,   54,
   20,   48,   47,   90,   14,  112,   47,   23,   47,   47,
   47,   47,   47,   47,   47,   21,  123,   54,   47,   48,
   22,   47,   59,   48,   55,   48,   48,   48,   48,   48,
   48,   48,   58,   54,   56,   48,   54,   26,   48,   57,
   59,  131,   55,  127,   29,  128,   75,    4,    5,   24,
   58,   30,   56,   27,   28,   75,   59,   57,   55,   59,
   37,   55,   31,   76,   35,   86,   58,   89,   56,   58,
   91,   56,   76,   57,   86,   77,   57,   25,   38,   43,
   38,  108,   12,   12,   88,   45,  113,  114,  115,  116,
  117,  118,  119,  120,  121,  122,   16,  101,  102,   38,
   46,   17,   93,   38,   94,   95,   96,   97,   98,   99,
  100,  101,  102,   93,  111,   94,   95,   96,   97,   98,
   99,  100,  101,  102,   99,  100,  101,  102,   42,  109,
   99,  100,  101,  102,   38,  111,    9,    5,   44,   39,
   99,  100,  101,  102,   47,   50,   52,   54,   56,   71,
   72,   73,   74,   87,   81,   92,  105,  103,  106,  107,
  110,  124,  125,  126,  130,  132,  129,  133,  134,    1,
    5,   10,   16,   19,   45,   28,    3,   21,   15,   34,
   57,   22,  104,
};
static const short yycheck[] = {                         66,
   30,  259,  263,   45,  259,    1,  259,    3,   62,   63,
   52,    7,  273,  274,  275,   11,  257,   47,  279,  259,
  303,  259,  277,   77,  258,   92,  281,  263,  283,  284,
  285,  286,  287,  288,  289,  293,  103,  277,  293,  277,
  293,  296,  259,  281,  259,  283,  284,  285,  286,  287,
  288,  289,  259,  293,  259,  293,  296,  263,  296,  259,
  277,  128,  277,  276,  292,  278,  263,  261,  262,  264,
  277,  292,  277,  259,  260,  263,  293,  277,  293,  296,
  265,  296,  280,  280,  293,   72,  293,   74,  293,  296,
   77,  296,  280,  293,   81,  292,  296,  292,  276,  295,
  278,   88,  259,  260,  292,  260,   93,   94,   95,   96,
   97,   98,   99,  100,  101,  102,  263,  290,  291,  297,
  263,  268,  281,  301,  283,  284,  285,  286,  287,  288,
  289,  290,  291,  281,  293,  283,  284,  285,  286,  287,
  288,  289,  290,  291,  288,  289,  290,  291,  293,  293,
  288,  289,  290,  291,  263,  293,  261,  262,  293,  268,
  288,  289,  290,  291,  259,  295,  260,  299,  294,  294,
  282,  292,  292,  263,  301,  277,  300,  296,  259,  293,
  293,  259,  259,  259,  259,  259,  297,  276,  259,    0,
  258,  263,  293,  293,  259,  294,    0,   11,    7,   28,
   50,   11,   81,
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
"body : declaration",
"body : declaration main_function",
"body : declaration functions main_function",
"declaration : DECL dstatemnts ENDDECL",
"dstatemnts : dstatemnt",
"dstatemnts : dstatemnt dstatemnts",
"dstatemnt : type dvars",
"dvars : var SEMICOLON",
"dvars : var COMMA dvars",
"type : INTEGER",
"type : BOOLEAN",
"var : ID",
"var : ID LSQUARE NUMBER RSQUARE",
"var : ID LPAREN parametr RPAREN",
"var : ADDRESSOF ID",
"parametr :",
"parametr : type plvars",
"plvars : pvars SEMICOLON parametr",
"plvars : pvars",
"pvars : ID COMMA pvars",
"pvars : ID",
"pvars : ADDRESSOF ID",
"pvars : ADDRESSOF ID COMMA pvars",
"functions : function",
"functions : functions function",
"function : type ID LPAREN parametr RPAREN LFLOWER fbody RFLOWER",
"main_function : INTEGER MAIN LPAREN RPAREN LFLOWER fbody RFLOWER",
"fbody : declaration",
"fbody : declaration bbody",
"bbody : BEGINN statements return END",
"ifelse : IF lexpression THEN statements ENDIF SEMICOLON",
"ifelse : IF lexpression THEN statements ELSE statements ENDIF SEMICOLON",
"statement : ifelse",
"statement : dowhile",
"statement : read",
"statement : write",
"statement : astatement",
"statements : statement",
"statements : statement statements",
"dowhile : WHILE lexpression DO statements ENDWHILE SEMICOLON",
"return : RETURN expression SEMICOLON",
"astatement : ID ASSIGN expression SEMICOLON",
"read : READ LPAREN ID RPAREN SEMICOLON",
"write : WRITE LPAREN aexpression RPAREN SEMICOLON",
"expression : aexpression",
"expression : lexpression",
"aexpression : aexpression PLUS aexpression",
"aexpression : aexpression MINUS aexpression",
"aexpression : aexpression MULT aexpression",
"aexpression : aexpression DIVIDE aexpression",
"aexpression : LPAREN aexpression RPAREN",
"aexpression : ID",
"aexpression : NUMBER",
"lexpression : aexpression EQUAL aexpression",
"lexpression : aexpression LESS_THAN aexpression",
"lexpression : aexpression GREATER_THAN aexpression",
"lexpression : aexpression GREATER_EQ aexpression",
"lexpression : aexpression LESS_EQUAL aexpression",
"lexpression : aexpression NEQUAL aexpression",
"lexpression : LPAREN lexpression RPAREN",

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
#line 130 "sil.y"

int main(){
	return(yyparse());
}

yyerror(s)
char *s;
{
  fprintf(stderr, "%s\n",s);
}
#line 368 "y.tab.c"

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
#line 23 "sil.y"
	{ printf("PARSING SUCCESS\n"); }
break;
case 2:
#line 24 "sil.y"
	{ printf("PARSING SUCCESS\n"); }
break;
case 3:
#line 25 "sil.y"
	{ printf("PARSING SUCCESS\n"); }
break;
#line 586 "y.tab.c"
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
