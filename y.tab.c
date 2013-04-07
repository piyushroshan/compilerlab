/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 1 "func.y"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linklist.h"
#define INT 1
#define BOOL 2
#define FUNC 6
#define SIZEOFINT 1 //In SIM all memory location has size of 4bytes
#define SIZEOFBOOL 1    //changing this sizes implies i have to change code for arrayindex
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
    int PASSTYPE;	//0 Call By Value and 1 Call By Reference
    struct ArgStruct *ARGNEXT;
};

struct Gsymbol {
    char *NAME; // Name of the Identifier
    int TYPE; // TYPE can be INTEGER or BOOLEAN
    /***The TYPE field must be a TypeStruct if user defined types are allowed***/
    int VALUE; // for constants
    int SIZE; // Size field for arrays
    int BINDING; // Address of the Identifier in Memory
    struct ArgStruct *ARGLIST; // Argument List for functions
    struct Lsymbol *LTABLE;
    /***Argstruct must store the name and type of each argument ***/
    struct Gsymbol *NEXT; // Pointer to next Symbol Table Entry */
} *Gnode;

struct Lsymbol {
    /* Here only name, type, binding and pointer to next entry needed */
    char *NAME; // Name of the Identifier
    int TYPE; // TYPE can be INTEGER or BOOLEAN
    /***The TYPE field must be a TypeStruct if user defined types are allowed***/
    int VALUE; // for constants
    int PASSTYPE;
    int BINDING; // Address of the Identifier in Memory
    struct Lsymbol *NEXT; // Pointer to next Symbol Table Entry */
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
bool declaration ;  //It's for deciding whether it's a context of declaration or definition in the case of functions
int Goffset;     //It's for assigning location value to globalvariables
int Loffset;    //It's for assigning location value to localvariables


int pcount=0; //count parameters

int returnmem = 4000;
int mem = 1000;
int argc = 0;
int fcount = 0;
int Loffset = 0;
char* fname;
//  Adding arguments
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


/* Line 268 of yacc.c  */
#line 190 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     DECL = 258,
     ENDDECL = 259,
     SEMICOLON = 260,
     COMMA = 261,
     INTEGER = 262,
     BOOLEAN = 263,
     ID = 264,
     LSQUARE = 265,
     RSQUARE = 266,
     TRUE = 267,
     FALSE = 268,
     ADDRESSOF = 269,
     MODULUS = 270,
     AND = 271,
     OR = 272,
     NOT = 273,
     READ = 274,
     WRITE = 275,
     IF = 276,
     ENDIF = 277,
     THEN = 278,
     ELSE = 279,
     WHILE = 280,
     NUMBER = 281,
     EQUAL = 282,
     ASSIGN = 283,
     NEQUAL = 284,
     LESS_THAN = 285,
     LESS_EQUAL = 286,
     GREATER_THAN = 287,
     GREATER_EQ = 288,
     PLUS = 289,
     MINUS = 290,
     MULT = 291,
     DIVIDE = 292,
     LPAREN = 293,
     RPAREN = 294,
     RFLOWER = 295,
     LFLOWER = 296,
     DO = 297,
     ENDWHILE = 298,
     BEGINN = 299,
     END = 300,
     RETURN = 301,
     MAIN = 302
   };
#endif
/* Tokens.  */
#define DECL 258
#define ENDDECL 259
#define SEMICOLON 260
#define COMMA 261
#define INTEGER 262
#define BOOLEAN 263
#define ID 264
#define LSQUARE 265
#define RSQUARE 266
#define TRUE 267
#define FALSE 268
#define ADDRESSOF 269
#define MODULUS 270
#define AND 271
#define OR 272
#define NOT 273
#define READ 274
#define WRITE 275
#define IF 276
#define ENDIF 277
#define THEN 278
#define ELSE 279
#define WHILE 280
#define NUMBER 281
#define EQUAL 282
#define ASSIGN 283
#define NEQUAL 284
#define LESS_THAN 285
#define LESS_EQUAL 286
#define GREATER_THAN 287
#define GREATER_EQ 288
#define PLUS 289
#define MINUS 290
#define MULT 291
#define DIVIDE 292
#define LPAREN 293
#define RPAREN 294
#define RFLOWER 295
#define LFLOWER 296
#define DO 297
#define ENDWHILE 298
#define BEGINN 299
#define END 300
#define RETURN 301
#define MAIN 302




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 119 "func.y"

    struct node* n;



/* Line 293 of yacc.c  */
#line 326 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 338 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   378

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  93
/* YYNRULES -- Number of states.  */
#define YYNSTATES  185

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   302

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,    11,    12,    15,    19,    21,    25,
      27,    29,    31,    33,    34,    36,    37,    39,    43,    45,
      48,    52,    54,    56,    59,    63,    65,    68,    72,    74,
      76,    79,    81,    86,    87,    93,    94,    97,    98,   108,
     109,   118,   119,   123,   124,   129,   130,   133,   137,   139,
     143,   145,   150,   151,   154,   156,   158,   160,   162,   164,
     171,   180,   187,   192,   200,   206,   215,   221,   225,   229,
     233,   237,   241,   245,   249,   253,   257,   261,   265,   269,
     273,   277,   280,   284,   286,   288,   290,   292,   297,   302,
     303,   305,   309,   311
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      49,     0,    -1,    50,    68,    71,    -1,     3,    51,     4,
      -1,    -1,    51,    52,    -1,    54,    53,     5,    -1,    66,
      -1,    53,     6,    66,    -1,     7,    -1,     8,    -1,     7,
      -1,     8,    -1,    -1,    62,    -1,    -1,    58,    -1,    58,
       5,    59,    -1,    59,    -1,    54,    60,    -1,    60,     6,
      61,    -1,    61,    -1,     9,    -1,    14,     9,    -1,    62,
       5,    63,    -1,    63,    -1,    54,    64,    -1,    64,     6,
      65,    -1,    65,    -1,     9,    -1,    14,     9,    -1,     9,
      -1,     9,    10,    26,    11,    -1,    -1,     9,    67,    38,
      56,    39,    -1,    -1,    68,    69,    -1,    -1,    55,     9,
      70,    38,    57,    39,    41,    73,    40,    -1,    -1,     7,
      47,    72,    38,    39,    41,    73,    40,    -1,    -1,    75,
      74,    81,    -1,    -1,     3,    76,    77,     4,    -1,    -1,
      77,    78,    -1,    54,    79,     5,    -1,    80,    -1,    79,
       6,    80,    -1,     9,    -1,    44,    82,    89,    45,    -1,
      -1,    82,    83,    -1,    84,    -1,    85,    -1,    87,    -1,
      88,    -1,    86,    -1,    21,    90,    23,    82,    22,     5,
      -1,    21,    90,    23,    82,    24,    82,    22,     5,    -1,
      25,    90,    42,    82,    43,     5,    -1,     9,    28,    90,
       5,    -1,     9,    10,    90,    11,    28,    90,     5,    -1,
      19,    38,     9,    39,     5,    -1,    19,    38,     9,    10,
      90,    11,    39,     5,    -1,    20,    38,    90,    39,     5,
      -1,    46,    90,     5,    -1,    90,    34,    90,    -1,    90,
      35,    90,    -1,    90,    36,    90,    -1,    90,    37,    90,
      -1,    90,    15,    90,    -1,    90,    27,    90,    -1,    90,
      30,    90,    -1,    90,    32,    90,    -1,    90,    33,    90,
      -1,    90,    31,    90,    -1,    90,    29,    90,    -1,    90,
      16,    90,    -1,    90,    17,    90,    -1,    18,    90,    -1,
      38,    90,    39,    -1,    12,    -1,    13,    -1,    26,    -1,
       9,    -1,     9,    10,    90,    11,    -1,     9,    38,    91,
      39,    -1,    -1,    92,    -1,    92,     6,    90,    -1,    90,
      -1,    14,     9,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   149,   149,   151,   153,   154,   156,   158,   159,   161,
     162,   164,   165,   168,   169,   172,   173,   176,   177,   180,
     183,   184,   187,   194,   202,   203,   206,   209,   210,   213,
     220,   231,   246,   262,   262,   292,   293,   296,   296,   310,
     310,   324,   324,   345,   345,   347,   348,   350,   352,   353,
     356,   373,   376,   377,   380,   381,   382,   383,   384,   387,
     389,   393,   396,   404,   411,   420,   427,   431,   435,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   457,   461,   531,
     532,   535,   536,   537
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DECL", "ENDDECL", "SEMICOLON", "COMMA",
  "INTEGER", "BOOLEAN", "ID", "LSQUARE", "RSQUARE", "TRUE", "FALSE",
  "ADDRESSOF", "MODULUS", "AND", "OR", "NOT", "READ", "WRITE", "IF",
  "ENDIF", "THEN", "ELSE", "WHILE", "NUMBER", "EQUAL", "ASSIGN", "NEQUAL",
  "LESS_THAN", "LESS_EQUAL", "GREATER_THAN", "GREATER_EQ", "PLUS", "MINUS",
  "MULT", "DIVIDE", "LPAREN", "RPAREN", "RFLOWER", "LFLOWER", "DO",
  "ENDWHILE", "BEGINN", "END", "RETURN", "MAIN", "$accept", "program",
  "Gdeclaration", "GdeclStatements", "GdeclStatement", "Gvars", "type",
  "ftype", "parametr", "Fparametr", "FvarsList", "FvarsDef", "Fvars",
  "Fvar", "PvarsList", "PvarsDef", "Pvars", "Pvar", "Gvar", "$@1",
  "functions", "function", "$@2", "main_function", "$@3", "fbody", "$@4",
  "declaration", "$@5", "declStatements", "declStatement", "vars", "var",
  "beginbody", "statements", "statement", "ifelse", "dowhile",
  "astatement", "read", "write", "return", "expression", "FexprList",
  "exprList", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    50,    51,    51,    52,    53,    53,    54,
      54,    55,    55,    56,    56,    57,    57,    58,    58,    59,
      60,    60,    61,    61,    62,    62,    63,    64,    64,    65,
      65,    66,    66,    67,    66,    68,    68,    70,    69,    72,
      71,    74,    73,    76,    75,    77,    77,    78,    79,    79,
      80,    81,    82,    82,    83,    83,    83,    83,    83,    84,
      84,    85,    86,    86,    87,    87,    88,    89,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    91,
      91,    92,    92,    92
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     0,     2,     3,     1,     3,     1,
       1,     1,     1,     0,     1,     0,     1,     3,     1,     2,
       3,     1,     1,     2,     3,     1,     2,     3,     1,     1,
       2,     1,     4,     0,     5,     0,     2,     0,     9,     0,
       8,     0,     3,     0,     4,     0,     2,     3,     1,     3,
       1,     4,     0,     2,     1,     1,     1,     1,     1,     6,
       8,     6,     4,     7,     5,     8,     5,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     3,     1,     1,     1,     1,     4,     4,     0,
       1,     3,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     4,     0,    35,     0,     1,     0,     3,     9,    10,
       5,     0,    11,    12,     0,    36,     2,    31,     0,     7,
      39,    37,     0,     0,     6,     0,     0,     0,     0,    13,
       8,     0,    15,    32,     0,     0,    14,    25,     0,     0,
       0,    16,    18,    29,     0,    26,    28,    34,     0,     0,
      22,     0,    19,    21,     0,     0,    30,     0,    24,    43,
       0,    41,    23,     0,     0,    17,    27,    45,    40,     0,
      20,     0,     0,    52,    42,    38,    44,     0,    46,     0,
      50,     0,    48,     0,     0,     0,     0,     0,     0,    53,
      54,    55,    58,    56,    57,     0,    47,     0,     0,     0,
       0,     0,    86,    83,    84,     0,    85,     0,     0,     0,
       0,    51,    49,     0,     0,     0,     0,     0,    89,    81,
       0,     0,     0,     0,    52,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    52,    67,     0,    62,     0,
       0,     0,     0,     0,    92,     0,    90,    82,    72,    79,
      80,     0,    73,    78,    74,    77,    75,    76,    68,    69,
      70,    71,     0,     0,     0,    64,    66,    87,    93,    88,
       0,     0,    52,     0,     0,     0,    91,    59,     0,    61,
      63,     0,     0,    65,    60
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    10,    18,    34,    14,    35,    40,
      41,    42,    52,    53,    36,    37,    45,    46,    19,    23,
       6,    15,    27,    16,    26,    60,    69,    61,    67,    72,
      78,    81,    82,    74,    79,    89,    90,    91,    92,    93,
      94,    95,   108,   145,   146
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -123
static const yytype_int16 yypact[] =
{
       6,  -123,    19,  -123,    61,  -123,    -1,  -123,  -123,  -123,
    -123,    17,   -25,  -123,    48,  -123,  -123,    11,    10,  -123,
    -123,  -123,    36,    32,  -123,    17,    40,    41,   113,    59,
    -123,    86,    59,  -123,    -4,    91,   127,  -123,   102,    47,
     109,   145,  -123,  -123,   153,   155,  -123,  -123,    59,   160,
    -123,   156,   158,  -123,   129,    59,  -123,    -4,  -123,  -123,
     132,  -123,  -123,    47,   160,  -123,  -123,  -123,  -123,   130,
    -123,   136,    73,  -123,  -123,  -123,  -123,   164,  -123,     8,
    -123,   117,  -123,    43,   137,   139,   140,   140,   140,  -123,
    -123,  -123,  -123,  -123,  -123,   147,  -123,   164,   140,   140,
     171,   140,    13,  -123,  -123,   140,  -123,   140,   307,   152,
      58,  -123,  -123,   180,    81,    -2,   257,   140,   133,    92,
     282,   140,   140,   140,  -123,   140,   140,   140,   140,   140,
     140,   140,   140,   140,   140,  -123,  -123,   165,  -123,   140,
     193,   194,   207,   195,   330,   169,   213,  -123,  -123,   341,
     341,   181,    69,    69,    92,    92,    92,    92,   -12,   -12,
    -123,  -123,    39,   140,   234,  -123,  -123,  -123,  -123,  -123,
     140,   215,  -123,   216,   104,   186,   330,  -123,   135,  -123,
    -123,   221,   222,  -123,  -123
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -123,  -123,  -123,  -123,  -123,  -123,     0,  -123,  -123,  -123,
    -123,   173,  -123,   166,  -123,   182,  -123,   174,   208,  -123,
    -123,  -123,  -123,  -123,  -123,   168,  -123,  -123,  -123,  -123,
    -123,  -123,   138,  -123,  -122,  -123,  -123,  -123,  -123,  -123,
    -123,  -123,   -87,  -123,  -123
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -34
static const yytype_int16 yytable[] =
{
     109,   110,   151,   121,    11,    43,    12,    13,   139,     1,
      44,   113,   114,   162,   116,    24,    25,    83,   119,     5,
     120,    22,    20,   117,   133,   134,    17,    84,    85,    86,
     142,   144,    39,    87,   148,   149,   150,   140,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,    83,   -33,
     178,   118,   164,    98,    88,    39,    50,    21,    84,    85,
      86,    51,    28,   136,    87,     7,     8,     9,     8,     9,
      29,    99,    77,   121,   122,   123,   174,    76,    31,    32,
       8,     9,   173,   176,   121,   125,   138,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   121,   122,   123,   127,
     128,   129,   130,   131,   132,   133,   134,   121,   125,   180,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   121,
     122,   123,    96,    97,    33,    38,   131,   132,   133,   134,
      47,   125,    48,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   102,    49,    83,   103,   104,   143,    54,   102,
      55,   105,   103,   104,    84,    85,    86,   182,   105,   106,
      87,    57,    56,    59,    63,    62,   106,   121,   122,   123,
      64,   107,    68,    80,    73,   100,    75,   101,   107,   125,
     115,   126,   127,   128,   129,   130,   131,   132,   133,   134,
      83,   137,   111,   163,   135,   121,   122,   123,   165,   166,
      84,    85,    86,   171,   168,   172,    87,   125,   169,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   167,   170,
     177,   179,   121,   122,   123,   181,   183,   184,    65,    70,
      58,    66,    71,    30,   125,   112,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   175,     0,     0,     0,   121,
     122,   123,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   125,     0,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   121,   122,   123,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   125,     0,   126,   127,   128,   129,
     130,   131,   132,   133,   134,     0,   141,   121,   122,   123,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   125,
       0,   126,   127,   128,   129,   130,   131,   132,   133,   134,
       0,   147,   121,   122,   123,     0,     0,     0,     0,     0,
     124,     0,     0,     0,   125,     0,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   121,   122,   123,     0,     0,
       0,     0,     0,     0,     0,     0,   121,   125,     0,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   125,     0,
     126,   127,   128,   129,   130,   131,   132,   133,   134
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-123))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      87,    88,   124,    15,     4,     9,     7,     8,    10,     3,
      14,    98,    99,   135,   101,     5,     6,     9,   105,     0,
     107,    10,    47,    10,    36,    37,     9,    19,    20,    21,
     117,   118,    32,    25,   121,   122,   123,    39,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,     9,    38,
     172,    38,   139,    10,    46,    55,     9,     9,    19,    20,
      21,    14,    26,     5,    25,     4,     7,     8,     7,     8,
      38,    28,    72,    15,    16,    17,   163,     4,    38,    38,
       7,     8,    43,   170,    15,    27,     5,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    15,    16,    17,    30,
      31,    32,    33,    34,    35,    36,    37,    15,    27,     5,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    15,
      16,    17,     5,     6,    11,    39,    34,    35,    36,    37,
      39,    27,     5,    29,    30,    31,    32,    33,    34,    35,
      36,    37,     9,    41,     9,    12,    13,    14,    39,     9,
       5,    18,    12,    13,    19,    20,    21,    22,    18,    26,
      25,     6,     9,     3,     6,     9,    26,    15,    16,    17,
      41,    38,    40,     9,    44,    38,    40,    38,    38,    27,
       9,    29,    30,    31,    32,    33,    34,    35,    36,    37,
       9,    11,    45,    28,    42,    15,    16,    17,     5,     5,
      19,    20,    21,    22,     9,    24,    25,    27,    39,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    11,     6,
       5,     5,    15,    16,    17,    39,     5,     5,    55,    63,
      48,    57,    64,    25,    27,    97,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    11,    -1,    -1,    -1,    15,
      16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    27,    -1,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    -1,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    39,    15,    16,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    39,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,
      23,    -1,    -1,    -1,    27,    -1,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    15,    16,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    27,    -1,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    27,    -1,
      29,    30,    31,    32,    33,    34,    35,    36,    37
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    49,    50,    51,     0,    68,     4,     7,     8,
      52,    54,     7,     8,    55,    69,    71,     9,    53,    66,
      47,     9,    10,    67,     5,     6,    72,    70,    26,    38,
      66,    38,    38,    11,    54,    56,    62,    63,    39,    54,
      57,    58,    59,     9,    14,    64,    65,    39,     5,    41,
       9,    14,    60,    61,    39,     5,     9,     6,    63,     3,
      73,    75,     9,     6,    41,    59,    65,    76,    40,    74,
      61,    73,    77,    44,    81,    40,     4,    54,    78,    82,
       9,    79,    80,     9,    19,    20,    21,    25,    46,    83,
      84,    85,    86,    87,    88,    89,     5,     6,    10,    28,
      38,    38,     9,    12,    13,    18,    26,    38,    90,    90,
      90,    45,    80,    90,    90,     9,    90,    10,    38,    90,
      90,    15,    16,    17,    23,    27,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    42,     5,    11,     5,    10,
      39,    39,    90,    14,    90,    91,    92,    39,    90,    90,
      90,    82,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    82,    28,    90,     5,     5,    11,     9,    39,
       6,    22,    24,    43,    90,    11,    90,     5,    82,     5,
       5,    39,    22,     5,     5
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1806 of yacc.c  */
#line 149 "func.y"
    { printf("PARSING SUCCESS\n"); (yyval.n)=CreateNode(0,'S', 0, NULL, (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n), NULL); PrintSymbol(); printTree((yyval.n)); Gen3A((yyval.n),0); print_TAlist();codeGen(); }
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 153 "func.y"
    {/*empty*/}
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 161 "func.y"
    { TYPE = INT; }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 162 "func.y"
    {TYPE = BOOL; }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 164 "func.y"
    { FTYPE = INT; }
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 165 "func.y"
    {FTYPE = BOOL; }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 168 "func.y"
    {}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 169 "func.y"
    { }
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 172 "func.y"
    {}
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 183 "func.y"
    { makeArglist2(newArg);    }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 184 "func.y"
    { makeArglist2(newArg);  }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 187 "func.y"
    {
                            newArg = malloc(sizeof(struct ArgStruct));
                            newArg->ARGNAME = (yyvsp[(1) - (1)].n)->NAME;
                            newArg->ARGTYPE = TYPE;
                            newArg->PASSTYPE = 0;
                            newArg->ARGNEXT = NULL;
        }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 194 "func.y"
    {
                             newArg = malloc(sizeof(struct ArgStruct));
                            newArg->ARGNAME = (yyvsp[(2) - (2)].n)->NAME;
                            newArg->ARGTYPE = TYPE;
                            newArg->PASSTYPE = 1;
                            newArg->ARGNEXT = NULL;
    }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 206 "func.y"
    { }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 209 "func.y"
    { makeArglist(newArg);	}
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 210 "func.y"
    { makeArglist(newArg);	}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 213 "func.y"
    {
							newArg = malloc(sizeof(struct ArgStruct));
							newArg->ARGNAME = (yyvsp[(1) - (1)].n)->NAME;
							newArg->ARGTYPE = TYPE;
							newArg->PASSTYPE = 0;
							newArg->ARGNEXT = NULL;
		}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 220 "func.y"
    {
						   	 newArg = malloc(sizeof(struct ArgStruct));
							newArg->ARGNAME = (yyvsp[(2) - (2)].n)->NAME;
							newArg->ARGTYPE = TYPE;
							newArg->PASSTYPE = 1;
							newArg->ARGNEXT = NULL;
	}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 231 "func.y"
    {
            printf("*****offset of %s is %d\n",(yyvsp[(1) - (1)].n)->NAME,Goffset);
            Ginstall((yyvsp[(1) - (1)].n)->NAME, TYPE, 0, Goffset, 0, NULL,NULL);
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

  case 32:

/* Line 1806 of yacc.c  */
#line 246 "func.y"
    {
                                Ginstall((yyvsp[(1) - (4)].n)->NAME, TYPE+2, (yyvsp[(3) - (4)].n)->VALUE, Goffset, 0, NULL, NULL);
                                 printf("*****offset of %s[%d] is %d\n",(yyvsp[(1) - (4)].n)->NAME,(yyvsp[(3) - (4)].n)->VALUE,Goffset);
                                /*-----------Code Generation-------------------*/
                                switch(TYPE)
                                {
                                    case INT :
                                        Goffset += SIZEOFINT*(yyvsp[(3) - (4)].n)->VALUE;
                                        break;
                                    case BOOL :
                                        Goffset += SIZEOFBOOL*(yyvsp[(3) - (4)].n)->VALUE;
                                        break;
                                }

                                /*---------------------------------------------*/
                            }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 262 "func.y"
    {

                                headArg = NULL;
                                Ginstall((yyvsp[(1) - (1)].n)->NAME, TYPE, 0, Goffset, 0, NULL, NULL);
                                printf("*****offset of function %s is %d\n",(yyvsp[(1) - (1)].n)->NAME,Goffset);
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

  case 34:

/* Line 1806 of yacc.c  */
#line 280 "func.y"
    {

    							struct Gsymbol* gt =  Glookup((yyvsp[(1) - (5)].n)->NAME);
                                if(gt)
                                {
                                    gt->ARGLIST = headArg;
    							}else
                                    yyerror("function not found");
                        }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 292 "func.y"
    { (yyval.n) = NULL; }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 293 "func.y"
    {  (yyval.n)=CreateNode(0,'S', 0, NULL, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n), NULL); if (((yyvsp[(1) - (2)].n)==NULL || (yyvsp[(1) - (2)].n)->TYPE == FUNC) && (yyvsp[(2) - (2)].n)->TYPE== FUNC) (yyval.n)->TYPE= FUNC; else {(yyval.n)->TYPE=-1; yyerror("Bad functions") ;} }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 296 "func.y"
    { fname = (char *)malloc(30); strcpy(fname,(yyvsp[(2) - (2)].n)->NAME); }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 296 "func.y"
    {
                                                                struct Gsymbol* gt =  Glookup((yyvsp[(2) - (9)].n)->NAME);
                                                                if(gt)
                                                                {
                                                                    gt->LTABLE = Lnode;
                                                                    gt->ARGLIST = headArg2;
                                                                }
                                                                (yyval.n)=CreateNode(0,'f', 0, fname, (yyvsp[(5) - (9)].n), (yyvsp[(8) - (9)].n), NULL);
                                                                if((yyvsp[(8) - (9)].n)->TYPE == FTYPE) { (yyval.n)->TYPE=FUNC; }else{ yyerror(" return type error"); (yyval.n)->TYPE = -1;}
                                                                //PrintLSymbol(Lnode);

        }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 310 "func.y"
    {                                      headArg = (struct ArgStruct*)NULL;
                                                                    headArg2 = (struct ArgStruct*)NULL;
                                                                    fname = (char *)malloc(30);
                                                                    strcpy(fname,(yyvsp[(2) - (2)].n)->NAME);
                                                                    FTYPE = INT;
                             }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 317 "func.y"
    {
                                                                    (yyval.n)=CreateNode(0,'f', 0, "main", NULL, (yyvsp[(7) - (8)].n), NULL);
                                                                    if((yyvsp[(7) - (8)].n)->TYPE == FTYPE) { (yyval.n)->TYPE=0; }else{ yyerror(" return type error"); printf("main return %d",(yyvsp[(7) - (8)].n)->TYPE); (yyval.n)->TYPE = -1;}
                                                                    (yyval.n)->lookup=(yyvsp[(7) - (8)].n)->lookup;
                                                                }
    break;

  case 41:

/* Line 1806 of yacc.c  */
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

  case 42:

/* Line 1806 of yacc.c  */
#line 342 "func.y"
    { (yyval.n) = (yyvsp[(3) - (3)].n);}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 345 "func.y"
    { Lnode = malloc(sizeof(struct Lsymbol)); Lnode = NULL; Loffset = 0; }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 345 "func.y"
    {  }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 347 "func.y"
    {/*empty*/}
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 356 "func.y"
    {
        Lnode = Linstall((yyvsp[(1) - (1)].n)->NAME, TYPE, Loffset, 0,0, Lnode);
         printf("*****L offset of %s is %d\n",(yyvsp[(1) - (1)].n)->NAME,Loffset);
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

  case 51:

/* Line 1806 of yacc.c  */
#line 373 "func.y"
    {  (yyval.n)=CreateNode(1,'S', 0, NULL, (yyvsp[(2) - (4)].n), (yyvsp[(3) - (4)].n), NULL); if ((yyvsp[(2) - (4)].n)==NULL || (yyvsp[(2) - (4)].n)->TYPE==0) { (yyval.n)->TYPE = (yyvsp[(3) - (4)].n)->TYPE; } else {(yyval.n)->TYPE=-1; yyerror("Bad begin error");} }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 376 "func.y"
    { (yyval.n) = NULL; }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 377 "func.y"
    {  (yyval.n)=CreateNode(0,'S', 0, NULL, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n), NULL); if (((yyvsp[(1) - (2)].n)==NULL || (yyvsp[(1) - (2)].n)->TYPE==0) && (yyvsp[(2) - (2)].n)->TYPE==0) (yyval.n)->TYPE=0; else { (yyval.n)->TYPE=-1; yyerror("Bad statements");}}
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 380 "func.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n); }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 381 "func.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 382 "func.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n);  }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 383 "func.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n);  }
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 384 "func.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n);  }
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 387 "func.y"
    { (yyvsp[(1) - (6)].n) = CreateNode(0,'I', 0, NULL, (yyvsp[(4) - (6)].n), (yyvsp[(2) - (6)].n), NULL); (yyval.n) = (yyvsp[(1) - (6)].n);
                                                if ((yyvsp[(2) - (6)].n)->TYPE==2 && ((yyvsp[(4) - (6)].n)==NULL || (yyvsp[(4) - (6)].n)->TYPE==0)) (yyval.n)->TYPE=0; else {(yyval.n)->TYPE=-1; yyerror("If type error"); } }
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 389 "func.y"
    { (yyvsp[(1) - (8)].n) = CreateNode(0,'I', 0, NULL, (yyvsp[(4) - (8)].n), (yyvsp[(2) - (8)].n), (yyvsp[(6) - (8)].n)); (yyval.n) = (yyvsp[(1) - (8)].n);
                                                if ((yyvsp[(2) - (8)].n)->TYPE==2 && ((yyvsp[(4) - (8)].n)==NULL || (yyvsp[(4) - (8)].n)->TYPE==0) && ((yyvsp[(6) - (8)].n)==NULL || (yyvsp[(6) - (8)].n)->TYPE==0)) (yyval.n)->TYPE=0; else { (yyval.n)->TYPE=-1; yyerror("If else error");}}
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 393 "func.y"
    { (yyvsp[(1) - (6)].n) = CreateNode(0,'W', 0, NULL, (yyvsp[(4) - (6)].n), (yyvsp[(2) - (6)].n), NULL); (yyval.n)=(yyvsp[(1) - (6)].n); if ((yyvsp[(2) - (6)].n)->TYPE==2 && ((yyvsp[(4) - (6)].n)==NULL || (yyvsp[(4) - (6)].n)->TYPE==0)) (yyval.n)->TYPE=0; else (yyval.n)->TYPE=-1; yyerror("while error"); }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 396 "func.y"
    { (yyvsp[(2) - (4)].n) = CreateNode(0,'=', 0, NULL, (yyvsp[(1) - (4)].n), NULL, (yyvsp[(3) - (4)].n)); (yyval.n)=(yyvsp[(2) - (4)].n);
                                            struct Lsymbol* lt = Llookup((yyvsp[(1) - (4)].n)->NAME, Lnode);
                                            if(lt) { if (lt->TYPE == (yyvsp[(3) - (4)].n)->TYPE ) (yyval.n)->TYPE=0; }
                                            else {
                                                struct Gsymbol* gt = Glookup((yyvsp[(1) - (4)].n)->NAME);
                                                if(gt) { if ( gt->SIZE==0 && (gt->TYPE == (yyvsp[(3) - (4)].n)->TYPE )) (yyval.n)->TYPE=0;
                                                else { (yyval.n)->TYPE=-1;	yyerror("Wrong assignment");}}else { printf("ID %s not found\n",(yyvsp[(1) - (4)].n)->NAME); yyerror(""); (yyval.n)->TYPE=-1;}
                                            }}
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 404 "func.y"
    { (yyvsp[(1) - (7)].n)->center = (yyvsp[(3) - (7)].n); (yyvsp[(5) - (7)].n) = CreateNode(0,'=', 0, NULL, (yyvsp[(1) - (7)].n), NULL, (yyvsp[(6) - (7)].n)); (yyval.n)=(yyvsp[(5) - (7)].n);
                                                                struct Gsymbol* gt = Glookup((yyvsp[(1) - (7)].n)->NAME);
                                                                if(gt) {if ( gt->SIZE!=0 && (yyvsp[(3) - (7)].n)->TYPE==INT && ((gt->TYPE-2) == (yyvsp[(6) - (7)].n)->TYPE)) (yyval.n)->TYPE=0; else { (yyval.n)->TYPE=-1;
                                                                yyerror("Wrong assignment of array type");}} else {printf("Array %s not found\n",(yyvsp[(1) - (7)].n)->NAME); yyerror(""); (yyval.n)->TYPE=-1; }
                                                            }
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 411 "func.y"
    { (yyvsp[(1) - (5)].n) = CreateNode(0,'r', 0, NULL, NULL, (yyvsp[(3) - (5)].n), NULL); (yyval.n) = (yyvsp[(1) - (5)].n);
                                            struct Lsymbol* lt = Llookup((yyvsp[(3) - (5)].n)->NAME, Lnode);
                                            if(lt && (lt->TYPE == 1))
                                                (yyval.n)->TYPE=0;
                                            else {
                                                struct Gsymbol* gt = Glookup((yyvsp[(3) - (5)].n)->NAME);
                                                if(gt) {if( gt->SIZE==0 && gt->TYPE == 1 ) (yyval.n)->TYPE=0; else { (yyval.n)->TYPE=-1;
                                                yyerror("Read type error");}} else { printf("ID %s not found\n",(yyvsp[(3) - (5)].n)->NAME); yyerror(""); (yyval.n)->TYPE=-1;}
                                            }}
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 420 "func.y"
    { (yyvsp[(3) - (8)].n)->center = (yyvsp[(5) - (8)].n);  (yyvsp[(1) - (8)].n) = CreateNode(0,'r', 0, NULL, NULL, (yyvsp[(3) - (8)].n), NULL); (yyval.n) = (yyvsp[(1) - (8)].n);
                                                struct Gsymbol* gt = Glookup((yyvsp[(3) - (8)].n)->NAME);
                                                if(gt) { if(gt->SIZE!=0 && gt->TYPE==(INT+2) && (yyvsp[(5) - (8)].n)->TYPE==1) (yyval.n)->TYPE=0; else { (yyval.n)->TYPE=-1;
                                                yyerror("Read type error");}} else { printf("ID %s not found\n",(yyvsp[(3) - (8)].n)->NAME); yyerror(""); (yyval.n)->TYPE=-1;}
                                            }
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 427 "func.y"
    { (yyvsp[(1) - (5)].n) = CreateNode(0,'w', 0, NULL, NULL, (yyvsp[(3) - (5)].n), NULL); (yyval.n) = (yyvsp[(1) - (5)].n);
                                                                            if((yyvsp[(3) - (5)].n)->TYPE==1) (yyval.n)->TYPE=0; else {(yyval.n)->TYPE=-1; yyerror("Write error");} }
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 431 "func.y"
    { (yyvsp[(1) - (3)].n) = CreateNode(0,'R', 0, NULL, NULL, (yyvsp[(2) - (3)].n), NULL);  (yyval.n) = (yyvsp[(1) - (3)].n);
                                        (yyval.n)->TYPE = (yyvsp[(2) - (3)].n)->TYPE;  }
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 435 "func.y"
    { (yyvsp[(2) - (3)].n) = CreateNode(0,'+', 0, NULL, (yyvsp[(1) - (3)].n), NULL, (yyvsp[(3) - (3)].n)); (yyval.n) = (yyvsp[(2) - (3)].n); if((yyvsp[(1) - (3)].n)->TYPE==1 && (yyvsp[(3) - (3)].n)->TYPE ==1) (yyval.n)->TYPE=1; else {(yyval.n)->TYPE=-1; yyerror("+ error");} }
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 436 "func.y"
    { (yyvsp[(2) - (3)].n) = CreateNode(0,'-', 0, NULL, (yyvsp[(1) - (3)].n), NULL, (yyvsp[(3) - (3)].n)); (yyval.n) = (yyvsp[(2) - (3)].n); if((yyvsp[(1) - (3)].n)->TYPE==1 && (yyvsp[(3) - (3)].n)->TYPE ==1) (yyval.n)->TYPE=1; else {(yyval.n)->TYPE=-1; yyerror("- error"); } }
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 437 "func.y"
    { (yyvsp[(2) - (3)].n) = CreateNode(0,'*', 0, NULL, (yyvsp[(1) - (3)].n), NULL, (yyvsp[(3) - (3)].n)); (yyval.n) = (yyvsp[(2) - (3)].n); if((yyvsp[(1) - (3)].n)->TYPE==1 && (yyvsp[(3) - (3)].n)->TYPE ==1) (yyval.n)->TYPE=1; else{(yyval.n)->TYPE=-1; yyerror("* error"); }}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 438 "func.y"
    { (yyvsp[(2) - (3)].n) = CreateNode(0,'/', 0, NULL, (yyvsp[(1) - (3)].n), NULL, (yyvsp[(3) - (3)].n)); (yyval.n) = (yyvsp[(2) - (3)].n);  if((yyvsp[(1) - (3)].n)->TYPE==1 && (yyvsp[(3) - (3)].n)->TYPE ==1) (yyval.n)->TYPE=1; else {(yyval.n)->TYPE=-1; yyerror("/ error"); }}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 439 "func.y"
    { (yyvsp[(2) - (3)].n) = CreateNode(0,'%', 0, NULL, (yyvsp[(1) - (3)].n), NULL, (yyvsp[(3) - (3)].n)); (yyval.n) = (yyvsp[(2) - (3)].n); if((yyvsp[(1) - (3)].n)->TYPE==1 && (yyvsp[(3) - (3)].n)->TYPE ==1) (yyval.n)->TYPE=1; else {(yyval.n)->TYPE=-1; yyerror("%error"); }}
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 440 "func.y"
    { (yyvsp[(2) - (3)].n) = CreateNode(0,'E', 0, NULL, (yyvsp[(1) - (3)].n), NULL, (yyvsp[(3) - (3)].n)); (yyval.n) = (yyvsp[(2) - (3)].n); if((yyvsp[(1) - (3)].n)->TYPE==1 && (yyvsp[(3) - (3)].n)->TYPE ==1) (yyval.n)->TYPE=2; else {(yyval.n)->TYPE=-1; yyerror("== error");  }}
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 441 "func.y"
    { (yyvsp[(2) - (3)].n) = CreateNode(0,'<', 0, NULL, (yyvsp[(1) - (3)].n), NULL, (yyvsp[(3) - (3)].n)); (yyval.n) = (yyvsp[(2) - (3)].n); if((yyvsp[(1) - (3)].n)->TYPE==1 && (yyvsp[(3) - (3)].n)->TYPE ==1) (yyval.n)->TYPE=2; else {(yyval.n)->TYPE=-1; yyerror("< error"); }}
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 442 "func.y"
    { (yyvsp[(2) - (3)].n) = CreateNode(0,'>', 0, NULL, (yyvsp[(1) - (3)].n), NULL, (yyvsp[(3) - (3)].n)); (yyval.n) = (yyvsp[(2) - (3)].n); if((yyvsp[(1) - (3)].n)->TYPE==1 && (yyvsp[(3) - (3)].n)->TYPE ==1) (yyval.n)->TYPE=2; else {(yyval.n)->TYPE=-1; yyerror("> error"); }}
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 443 "func.y"
    { (yyvsp[(2) - (3)].n) = CreateNode(0,'G', 0, NULL, (yyvsp[(1) - (3)].n), NULL, (yyvsp[(3) - (3)].n)); (yyval.n) = (yyvsp[(2) - (3)].n); if((yyvsp[(1) - (3)].n)->TYPE==1 && (yyvsp[(3) - (3)].n)->TYPE ==1) (yyval.n)->TYPE=2; else {(yyval.n)->TYPE=-1; yyerror(">= error"); }}
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 444 "func.y"
    { (yyvsp[(2) - (3)].n) = CreateNode(0,'L', 0, NULL, (yyvsp[(1) - (3)].n), NULL, (yyvsp[(3) - (3)].n)); (yyval.n) = (yyvsp[(2) - (3)].n); if((yyvsp[(1) - (3)].n)->TYPE==1 && (yyvsp[(3) - (3)].n)->TYPE ==1) (yyval.n)->TYPE=2; else {(yyval.n)->TYPE=-1; yyerror("<= error"); } }
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 445 "func.y"
    { (yyvsp[(2) - (3)].n) = CreateNode(0,'N', 0, NULL, (yyvsp[(1) - (3)].n), NULL, (yyvsp[(3) - (3)].n)); (yyval.n) = (yyvsp[(2) - (3)].n); if((yyvsp[(1) - (3)].n)->TYPE==1 && (yyvsp[(3) - (3)].n)->TYPE ==1) (yyval.n)->TYPE=2; else {(yyval.n)->TYPE=-1; yyerror("!= error"); } }
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 446 "func.y"
    { (yyvsp[(2) - (3)].n) = CreateNode(0,'&', 0, NULL, (yyvsp[(1) - (3)].n), NULL, (yyvsp[(3) - (3)].n)); (yyval.n) = (yyvsp[(2) - (3)].n); if((yyvsp[(1) - (3)].n)->TYPE==2 && (yyvsp[(3) - (3)].n)->TYPE ==2) (yyval.n)->TYPE=2; else {(yyval.n)->TYPE=-1; yyerror("& error");} }
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 447 "func.y"
    { (yyvsp[(2) - (3)].n) = CreateNode(0,'|', 0, NULL, (yyvsp[(1) - (3)].n), NULL, (yyvsp[(3) - (3)].n)); (yyval.n) = (yyvsp[(2) - (3)].n); if((yyvsp[(1) - (3)].n)->TYPE==2 && (yyvsp[(3) - (3)].n)->TYPE ==2) (yyval.n)->TYPE=2; else {(yyval.n)->TYPE=-1; yyerror("| error");} }
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 448 "func.y"
    { (yyvsp[(1) - (2)].n) = CreateNode(0,'!', 0, NULL, NULL, (yyvsp[(2) - (2)].n), NULL); (yyval.n) = (yyvsp[(1) - (2)].n);  if((yyvsp[(2) - (2)].n)->TYPE==2) (yyval.n)->TYPE=2; {(yyval.n)->TYPE=-1; yyerror("NOT error");} }
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 449 "func.y"
    { (yyval.n) = (yyvsp[(2) - (3)].n); }
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 450 "func.y"
    { (yyvsp[(1) - (1)].n) = CreateNode(2,'T', 0, NULL,NULL,NULL,NULL); (yyval.n) = (yyvsp[(1) - (1)].n);  }
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 451 "func.y"
    { (yyvsp[(1) - (1)].n) = CreateNode(2,'F', 0, NULL, NULL, NULL, NULL); (yyval.n) = (yyvsp[(1) - (1)].n); }
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 452 "func.y"
    { (yyval.n)=(yyvsp[(1) - (1)].n); }
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 453 "func.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n); struct Lsymbol* lt = Llookup((yyvsp[(1) - (1)].n)->NAME, Lnode); if(lt) (yyval.n)->TYPE=lt->TYPE; else {
                                                            struct Gsymbol* gt = Glookup((yyvsp[(1) - (1)].n)->NAME);
                                                            if(gt) {if(gt->SIZE==0) (yyval.n)->TYPE=gt->TYPE; else (yyval.n)->TYPE=-1; }
                                                            else { printf("ID %s not found\n",(yyvsp[(1) - (1)].n)->NAME); yyerror(""); (yyval.n)->TYPE=-1;}}}
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 457 "func.y"
    {   (yyvsp[(1) - (4)].n)->center = (yyvsp[(3) - (4)].n); (yyval.n) = (yyvsp[(1) - (4)].n);  struct Gsymbol* gt = Glookup((yyvsp[(1) - (4)].n)->NAME);
                                                                    if(gt) { if(gt->SIZE!=0 && (yyvsp[(3) - (4)].n)->TYPE==1)
                                                                    (yyval.n)->TYPE=gt->TYPE; else (yyval.n)->TYPE=-1; yyerror("array type expression"); }
                                                                    else { printf("Array %s not found\n",(yyvsp[(1) - (4)].n)->NAME); yyerror(""); (yyval.n)->TYPE=-1;}}
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 461 "func.y"
    { struct Gsymbol* gtemp = Glookup((yyvsp[(1) - (4)].n)->NAME);
                                    (yyval.n)=CreateNode(0,'C', pcount, (yyvsp[(1) - (4)].n)->NAME,NULL,(yyvsp[(3) - (4)].n),NULL);
                                    if(gtemp==NULL || gtemp->SIZE!=0) yyerror("Undefined Function");
                                    else
                                    {
                                        (yyval.n)->lookup = gtemp->LTABLE;
                                        (yyval.n)->TYPE = gtemp->TYPE;
                                    }
                                    struct ArgStruct* ARGLIST = gtemp->ARGLIST;
                                    struct node* ptemp=(yyvsp[(3) - (4)].n);
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
                                                 ARGLIST=ARGLIST->ARGNEXT;
                                                 ptemp = ptemp->left;
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

  case 89:

/* Line 1806 of yacc.c  */
#line 531 "func.y"
    { (yyval.n)=NULL; }
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 532 "func.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n); }
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 535 "func.y"
    { (yyval.n)=CreateNode(0,'z', 0, NULL,(yyvsp[(1) - (3)].n),(yyvsp[(3) - (3)].n),NULL); pcount++; (yyvsp[(3) - (3)].n)->PASSTYPE=0; }
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 536 "func.y"
    { (yyval.n)=CreateNode(0,'z', 0, NULL,NULL,(yyvsp[(1) - (1)].n),NULL); pcount++; (yyvsp[(1) - (1)].n)->PASSTYPE=0; }
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 537 "func.y"
    { (yyval.n) = (yyvsp[(1) - (2)].n); (yyval.n)->PASSTYPE=1; struct Lsymbol* lt = Llookup((yyvsp[(1) - (2)].n)->NAME, Lnode); if(lt) (yyval.n)->TYPE=lt->TYPE; else {
                                                            struct Gsymbol* gt = Glookup((yyvsp[(1) - (2)].n)->NAME);
                                                            if(gt) {if(gt->SIZE==0) (yyval.n)->TYPE=gt->TYPE; else (yyval.n)->TYPE=-1; }
                                                            else { printf("ID %s not found\n",(yyvsp[(1) - (2)].n)->NAME); yyerror(""); (yyval.n)->TYPE=-1;}}
                        }
    break;



/* Line 1806 of yacc.c  */
#line 2544 "y.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 544 "func.y"


int main(){
    Goffset = 0;
    SP=0;
    FILE *fp;
    fp = fopen("sim.asm","w");
    fclose(fp);
    yyparse();
    fp = fopen("sim.asm","a");
    fprintf(fp,"START\n");
    fprintf(fp,"MOV SP, 100\n");
    fprintf(fp,"MOV BP, 0\n");
    fprintf(fp,"CALL main\n");
    fclose(fp);
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
struct Lsymbol* ltemp = NULL;
char * FNAME;
void Gen3A(struct node* root,int flag){
    if(root==NULL){
        return;
    }
    
    switch(root->NODETYPE){
        case 'f' :{
            struct Gsymbol* gt = Glookup(root->NAME);
            if(gt){
            struct Lsymbol* lt = gt->LTABLE;
            ltemp = lt;
            printf("Printing LSymbol for %s\n", root->NAME);
            PrintLSymbol(ltemp);
            struct ArgStruct* at = gt->ARGLIST;
            struct Lsymbol* lcopy = (struct Lsymbol*)malloc(sizeof (struct Lsymbol));
            int bp=SP+50;
            FNAME = malloc(30);
            FNAME[0]='\0';
            strcat(FNAME,root->NAME);
            TAinstall('B',root->NAME,NULL,NULL);
            current_temp=1;
                int offset = 0;
                char *t1 =(char *) malloc(5);
                t1[0]='t';t1[1]='\0';
                strcat(t1,itoa(current_temp));
                TAinstall('M',t1,"SP",NULL);
                while(at)
                {
                current_temp++;
                char *t2 =(char *) malloc(5);
                t2[0]='t';t2[1]='\0';
                strcat(t2,itoa(current_temp));
                TAinstall('M',t2,itoa(offset),NULL);
                current_temp++;
                char *t3 =(char *) malloc(5);
                t3[0]='t';t3[1]='\0';
                strcat(t3,itoa(current_temp));
                TAinstall('M',t3,t1,NULL);
                TAinstall('-',t3,t3,t2);
                TAinstall('l',t2,t3,NULL);
                t3 =(char *) malloc(5);
                t3[0]='t';t3[1]='\0';
                strcat(t3,itoa(current_temp));
                TAinstall('M',t3,itoa(Llookup(at->ARGNAME,ltemp)->BINDING),NULL);
                TAinstall('+',t3,t3,t1);
                TAinstall('M',t3,t2,NULL);
                offset = offset+1;
                at=at->ARGNEXT;
                current_temp--;
                current_temp--;
            }
            Gen3A(root->center,0);
            }
            break;
        }
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
            //printf("%c %s %s %s",'E',t1, t1, t2);
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
                //printf("Printing LSymbol for %s when looking for %s\n",FNAME, root->NAME);
                //PrintLSymbol(ltemp);
                if(Llookup(root->NAME,ltemp))
                 {  
                    current_temp++;
                    char *t1 =(char *) malloc(5);
                     t1[0]='\0';
                    strcat(t1,"SP");
                    char *t2 =(char *) malloc(5);
                     t2[0]='t';t2[1]='\0';
                    strcat(t2,itoa(current_temp));
                    current_temp++;
                    char *t3 =(char *) malloc(5);
                     t3[0]='t';t3[1]='\0';
                    strcat(t3,itoa(current_temp));
                    
                    TAinstall('M',t2,t1,NULL);
                    TAinstall('M',t3,itoa(Llookup(root->NAME, ltemp)->BINDING),NULL);
                    TAinstall('+',t2,t2,t3);
                    TAinstall('M',t,t2,NULL);
                    current_temp--;
                    current_temp--;
                }
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
            int pc=root->VALUE;
            struct node* temp = root->center;
            struct Gsymbol* gtemp = Glookup(root->NAME);
            struct ArgStruct* args = gtemp->ARGLIST;
            printf("printing Argument");
            printArg(args);
            //gtemp->BINDING =
            while(current_temp)
            {
                char *t =(char *) malloc(5);
                t[0]='t';t[1]='\0';
                strcat(t,itoa(current_temp));
                TAinstall('P',t,NULL,NULL);
                current_temp--;
            }
            char *t =(char *) malloc(5);
            t[0]='\0';
            strcat(t,"SP");
            char *t1 =(char *) malloc(5);
            t1[0]='t';t1[1]='\0';
            current_temp++;
            strcat(t1,itoa(current_temp));
            TAinstall('M',t1,t,NULL);
            char *t2 =(char *) malloc(5);
            t2[0]='t';t2[1]='\0';
            current_temp++;
            strcat(t2,itoa(current_temp));
            TAinstall('M',t2,itoa(50),NULL);
            TAinstall('+',t1,t1,t2);
            TAinstall('M',t,t1,NULL);
            current_temp--;
            current_temp--;
            while(pc && temp)
            {
                char *t =(char *) malloc(5);
                t[0]='t';t[1]='\0';
                Gen3A(temp->center,0);
                strcat(t,itoa(current_temp));
                TAinstall('P',t,NULL,NULL);
                //printf("%c %s %s %s",'v',t,NULL,NULL);
                current_temp--;
                pc--;
                if(temp->left)
                temp=temp->left;
            }
            
            TAinstall('C',root->NAME,NULL,NULL);
            printf("%c %s %s %s",'C',root->NAME,NULL,NULL);
            pc=root->VALUE;
            while(pc)
            {
                char *t =(char *) malloc(5);
                t[0]='t';t[1]='\0';
                strcat(t,itoa(0));
                TAinstall('p',t,NULL,NULL);
                //printf("%c %s %s %s",'v',t,NULL,NULL);
                pc--;
            }
            t =(char *) malloc(5);
            t[0]='\0';
            strcat(t,"SP");
            t1 =(char *) malloc(5);
            t1[0]='t';t1[1]='\0';
            current_temp++;
            strcat(t1,itoa(current_temp));
            TAinstall('M',t1,t,NULL);
            t2 =(char *) malloc(5);
            t2[0]='t';t2[1]='\0';
            current_temp++;
            strcat(t2,itoa(current_temp));
            TAinstall('M',t2,itoa(50),NULL);
            TAinstall('-',t1,t1,t2);
            TAinstall('M',t,t1,NULL);
            current_temp--;
            current_temp--;
            current_temp=1;
            while(current_temp<=ct)
            {
                char *t =(char *) malloc(5);
                t[0]='t';t[1]='\0';
                strcat(t,itoa(current_temp));
                TAinstall('p',t,NULL,NULL);
                //printf("%c %s %s %s",'p',t,NULL,NULL);
                current_temp++;
            }
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
                if(r1[0]=='t')
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
            case 'P':{
                char *r1 =(char *) malloc(5);
                strcpy(r1,TAroot->op1);
                r1[0]='R';
                fp = fopen("sim.asm","a");
                fprintf(fp,"PUSH %s\n",r1);
                fclose(fp);
                break;
            }
            case 'p':{
                char *r1 =(char *) malloc(5);
                strcpy(r1,TAroot->op1);
                r1[0]='R';
                fp = fopen("sim.asm","a");
                fprintf(fp,"POP %s\n",r1);
                fclose(fp);
                break;
            }
            case 'R':{
                char *r1 =(char *) malloc(5);
                strcpy(r1,TAroot->op1);
                r1[0]='R';
                fp = fopen("sim.asm","a");
                fprintf(fp,"MOV R0,%s\n",r1);
                fprintf(fp,"RET\n");
                fclose(fp);
                break;
            }
            case 'C':{
                fp = fopen("sim.asm","a");
                fprintf(fp,"CALL %s\n",TAroot->op1);
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



