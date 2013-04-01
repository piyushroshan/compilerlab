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
    struct	node	*center, *left,	*right;
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

    /***Argstruct must store the name and type of each argument ***/
    struct Gsymbol *NEXT; // Pointer to next Symbol Table Entry */
} *Gnode;

struct Lsymbol {
    /* Here only name, type, binding and pointer to next entry needed */
    char *NAME; // Name of the Identifier
    int TYPE; // TYPE can be INTEGER or BOOLEAN
    /***The TYPE field must be a TypeStruct if user defined types are allowed***/
    int VALUE; // for constants
    int BINDING; // Address of the Identifier in Memory
    struct Lsymbol *NEXT; // Pointer to next Symbol Table Entry */
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
bool declaration ;  //It's for deciding whether it's a context of declaration or definition in the case of functions
int Goffset;     //It's for assigning location value to globalvariables
int Loffset;    //It's for assigning location value to localvariables

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



/* Line 268 of yacc.c  */
#line 164 "y.tab.c"

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
#line 93 "func.y"

    struct node* n;



/* Line 293 of yacc.c  */
#line 300 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 312 "y.tab.c"

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
#define YYLAST   447

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNRULES -- Number of states.  */
#define YYNSTATES  172

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
      27,    29,    30,    33,    37,    39,    43,    45,    48,    53,
      54,    57,    66,    68,    73,    78,    86,    89,    93,    94,
      97,   101,   103,   107,   109,   114,   115,   118,   120,   122,
     124,   126,   128,   130,   137,   146,   153,   160,   165,   173,
     179,   188,   194,   198,   202,   206,   210,   214,   218,   222,
     226,   230,   234,   238,   242,   246,   250,   253,   257,   259,
     261,   263,   265,   270,   275,   279,   283
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      49,     0,    -1,    50,    58,    61,    -1,     3,    51,     4,
      -1,    -1,    51,    52,    -1,    54,    53,     5,    -1,    60,
      -1,    53,     6,    60,    -1,     7,    -1,     8,    -1,    -1,
      54,    56,    -1,    57,     5,    55,    -1,    57,    -1,     9,
       6,    57,    -1,     9,    -1,    14,     9,    -1,    14,     9,
       6,    57,    -1,    -1,    58,    59,    -1,    54,     9,    38,
      55,    39,    41,    62,    40,    -1,     9,    -1,     9,    10,
      26,    11,    -1,     9,    38,    55,    39,    -1,     7,    47,
      38,    39,    41,    62,    40,    -1,    63,    68,    -1,     3,
      64,     4,    -1,    -1,    64,    65,    -1,    54,    66,     5,
      -1,    67,    -1,    66,     6,    67,    -1,     9,    -1,    44,
      69,    77,    45,    -1,    -1,    69,    70,    -1,    71,    -1,
      72,    -1,    75,    -1,    76,    -1,    74,    -1,    73,    -1,
      21,    78,    23,    69,    22,     5,    -1,    21,    78,    23,
      69,    24,    69,    22,     5,    -1,    25,    78,    42,    69,
      43,     5,    -1,    42,    69,    25,    78,    43,     5,    -1,
       9,    28,    78,     5,    -1,     9,    10,    78,    11,    28,
      78,     5,    -1,    19,    38,     9,    39,     5,    -1,    19,
      38,     9,    10,    78,    11,    39,     5,    -1,    20,    38,
      78,    39,     5,    -1,    46,    78,     5,    -1,    78,    34,
      78,    -1,    78,    35,    78,    -1,    78,    36,    78,    -1,
      78,    37,    78,    -1,    78,    15,    78,    -1,    78,    27,
      78,    -1,    78,    30,    78,    -1,    78,    32,    78,    -1,
      78,    33,    78,    -1,    78,    31,    78,    -1,    78,    29,
      78,    -1,    78,    16,    78,    -1,    78,    17,    78,    -1,
      18,    78,    -1,    38,    78,    39,    -1,    12,    -1,    13,
      -1,    26,    -1,     9,    -1,     9,    10,    78,    11,    -1,
       9,    38,    79,    39,    -1,     9,    38,    39,    -1,    79,
       6,    78,    -1,    78,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   123,   123,   125,   127,   128,   130,   132,   133,   135,
     136,   139,   140,   143,   144,   147,   148,   149,   150,   153,
     154,   157,   161,   176,   191,   194,   199,   202,   204,   205,
     207,   209,   210,   213,   230,   233,   234,   237,   238,   239,
     240,   241,   242,   245,   247,   251,   253,   255,   263,   270,
     279,   286,   290,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   316,   320,   321,   325,   326
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
  "parametr", "PvarsList", "Pvar", "functions", "function", "Gvar",
  "main_function", "fbody", "declaration", "declStatements",
  "declStatement", "vars", "var", "beginbody", "statements", "statement",
  "ifelse", "dowhile", "dw", "astatement", "read", "write", "return",
  "expression", "exprList", 0
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
      54,    55,    55,    56,    56,    57,    57,    57,    57,    58,
      58,    59,    60,    60,    60,    61,    62,    63,    64,    64,
      65,    66,    66,    67,    68,    69,    69,    70,    70,    70,
      70,    70,    70,    71,    71,    72,    73,    74,    74,    75,
      75,    76,    77,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    79,    79
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     0,     2,     3,     1,     3,     1,
       1,     0,     2,     3,     1,     3,     1,     2,     4,     0,
       2,     8,     1,     4,     4,     7,     2,     3,     0,     2,
       3,     1,     3,     1,     4,     0,     2,     1,     1,     1,
       1,     1,     1,     6,     8,     6,     6,     4,     7,     5,
       8,     5,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     3,     1,     1,
       1,     1,     4,     4,     3,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     4,     0,    19,     0,     1,     0,     3,     9,    10,
       5,     0,     9,     0,    20,     2,    22,     0,     7,     0,
       0,     0,    11,     6,     0,     0,    11,     0,     0,     0,
       8,     0,     0,    23,    16,     0,    12,    14,    24,     0,
       0,     0,    17,    11,    28,     0,     0,     0,    15,     0,
      13,     0,    25,    35,    26,     0,    18,    27,     0,    29,
       0,    21,    33,     0,    31,     0,     0,     0,     0,     0,
      35,     0,    36,    37,    38,    42,    41,    39,    40,     0,
      30,     0,     0,     0,     0,     0,    71,    68,    69,     0,
      70,     0,     0,     0,     0,     0,    34,    32,     0,     0,
       0,     0,     0,     0,    66,     0,     0,     0,     0,    35,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      35,     0,    52,     0,    47,     0,     0,     0,     0,    74,
      76,     0,    67,    57,    64,    65,     0,    58,    63,    59,
      62,    60,    61,    53,    54,    55,    56,     0,     0,     0,
       0,    49,    51,    72,     0,    73,     0,    35,     0,     0,
       0,     0,    75,    43,     0,    45,    46,    48,     0,     0,
      50,    44
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    10,    17,    28,    29,    36,    37,
       6,    14,    18,    15,    45,    46,    51,    59,    63,    64,
      54,    60,    72,    73,    74,    75,    76,    77,    78,    79,
      92,   131
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -71
static const yytype_int16 yypact[] =
{
       2,   -71,    15,   -71,    33,   -71,    69,   -71,   -71,   -71,
     -71,     8,   -18,    24,   -71,   -71,    -3,    59,   -71,     7,
      40,    12,   112,   -71,     8,    32,   112,    78,     4,    67,
     -71,    76,    83,   -71,   117,   119,   -71,   124,   -71,   127,
      90,     4,   126,   112,   -71,    94,    89,   127,   -71,     4,
     -71,   101,   -71,   -71,   -71,   111,   -71,   -71,   143,   -71,
       0,   -71,   -71,    63,   -71,    -6,   115,   116,    98,    98,
     -71,    98,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   113,
     -71,   143,    98,    98,   146,    98,    -2,   -71,   -71,    98,
     -71,    98,   376,   221,    93,   110,   -71,   -71,   249,   133,
      -8,   326,    98,   185,    57,   351,    98,    98,    98,   -71,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
     -71,    98,   -71,   128,   -71,    98,   152,   177,   276,   -71,
     399,    -5,   -71,   -71,   410,   410,    61,   144,   144,    57,
      57,    57,    57,    -9,    -9,   -71,   -71,    54,   198,    98,
     303,   -71,   -71,   -71,    98,   -71,   179,   -71,   190,   191,
     156,   160,   399,   -71,    79,   -71,   -71,   -71,   195,   196,
     -71,   -71
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -71,   -71,   -71,   -71,   -71,   -71,    10,    41,   -71,   -38,
     -71,   -71,   178,   -71,   157,   -71,   -71,   -71,   -71,   125,
     -71,   -70,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -59,   -71
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      94,   154,   125,    48,    82,     1,   106,    21,   102,    65,
      93,    56,    95,    34,    11,     5,    13,    16,    35,    66,
      67,    68,    83,    98,    99,    69,   101,   118,   119,    19,
     104,   126,   105,    20,   155,    22,   103,     7,    27,   136,
       8,     9,    70,   128,   130,    25,    71,   133,   134,   135,
     147,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,    58,   148,    65,    23,    24,   150,    32,    80,    81,
      65,    31,   106,    66,    67,    68,    12,     9,    26,    69,
      66,    67,    68,   156,    50,   157,    69,   164,    65,    33,
     160,   116,   117,   118,   119,   162,    70,   158,    66,    67,
      68,   169,    65,    70,    69,    57,    38,    86,     8,     9,
      87,    88,    66,    67,    68,   122,    89,    39,   121,     8,
       9,    70,    40,    41,    90,   106,   107,   108,    42,    43,
      44,    47,    49,    53,    52,    70,    91,   110,   124,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   106,   107,
     108,    61,    62,    84,    85,   100,   149,   151,    96,   106,
     110,   167,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   106,   107,   108,   112,   113,   114,   115,   116,   117,
     118,   119,   152,   110,   163,   111,   112,   113,   114,   115,
     116,   117,   118,   119,    86,   165,   166,    87,    88,   168,
     170,   171,    30,    89,    55,     0,    97,     0,     0,     0,
       0,    90,     0,   106,   107,   108,     0,     0,     0,     0,
       0,     0,     0,    91,   129,   110,     0,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   106,   107,   108,     0,
     120,   159,     0,     0,     0,     0,     0,     0,   110,     0,
     111,   112,   113,   114,   115,   116,   117,   118,   119,     0,
     123,     0,     0,   120,   106,   107,   108,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   110,     0,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   153,     0,     0,
       0,   106,   107,   108,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   110,     0,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   161,     0,     0,     0,   106,   107,
     108,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     110,     0,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   106,   107,   108,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   110,     0,   111,   112,   113,   114,   115,
     116,   117,   118,   119,     0,   127,   106,   107,   108,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   110,     0,
     111,   112,   113,   114,   115,   116,   117,   118,   119,     0,
     132,   106,   107,   108,     0,     0,     0,     0,     0,   109,
       0,     0,     0,   110,     0,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   106,   107,   108,     0,     0,     0,
       0,     0,     0,     0,     0,   106,   110,     0,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   110,     0,   111,
     112,   113,   114,   115,   116,   117,   118,   119
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-71))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      70,     6,    10,    41,    10,     3,    15,    10,    10,     9,
      69,    49,    71,     9,     4,     0,     6,     9,    14,    19,
      20,    21,    28,    82,    83,    25,    85,    36,    37,    47,
      89,    39,    91,     9,    39,    38,    38,     4,    26,   109,
       7,     8,    42,   102,   103,    38,    46,   106,   107,   108,
     120,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,    51,   121,     9,     5,     6,   125,    26,     5,     6,
       9,    39,    15,    19,    20,    21,     7,     8,    38,    25,
      19,    20,    21,    22,    43,    24,    25,   157,     9,    11,
     149,    34,    35,    36,    37,   154,    42,    43,    19,    20,
      21,    22,     9,    42,    25,     4,    39,     9,     7,     8,
      12,    13,    19,    20,    21,     5,    18,    41,    25,     7,
       8,    42,    39,     6,    26,    15,    16,    17,     9,     5,
       3,    41,     6,    44,    40,    42,    38,    27,     5,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    15,    16,
      17,    40,     9,    38,    38,     9,    28,     5,    45,    15,
      27,     5,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    15,    16,    17,    30,    31,    32,    33,    34,    35,
      36,    37,     5,    27,     5,    29,    30,    31,    32,    33,
      34,    35,    36,    37,     9,     5,     5,    12,    13,    39,
       5,     5,    24,    18,    47,    -1,    81,    -1,    -1,    -1,
      -1,    26,    -1,    15,    16,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    39,    27,    -1,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    15,    16,    17,    -1,
      42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    27,    -1,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      11,    -1,    -1,    42,    15,    16,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    -1,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    11,    -1,    -1,
      -1,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    27,    -1,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    11,    -1,    -1,    -1,    15,    16,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      27,    -1,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    27,    -1,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    39,    15,    16,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    -1,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      39,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,    23,
      -1,    -1,    -1,    27,    -1,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    15,    16,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    27,    -1,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    27,    -1,    29,
      30,    31,    32,    33,    34,    35,    36,    37
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    49,    50,    51,     0,    58,     4,     7,     8,
      52,    54,     7,    54,    59,    61,     9,    53,    60,    47,
       9,    10,    38,     5,     6,    38,    38,    26,    54,    55,
      60,    39,    55,    11,     9,    14,    56,    57,    39,    41,
      39,     6,     9,     5,     3,    62,    63,    41,    57,     6,
      55,    64,    40,    44,    68,    62,    57,     4,    54,    65,
      69,    40,     9,    66,    67,     9,    19,    20,    21,    25,
      42,    46,    70,    71,    72,    73,    74,    75,    76,    77,
       5,     6,    10,    28,    38,    38,     9,    12,    13,    18,
      26,    38,    78,    78,    69,    78,    45,    67,    78,    78,
       9,    78,    10,    38,    78,    78,    15,    16,    17,    23,
      27,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      42,    25,     5,    11,     5,    10,    39,    39,    78,    39,
      78,    79,    39,    78,    78,    78,    69,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    69,    78,    28,
      78,     5,     5,    11,     6,    39,    22,    24,    43,    43,
      78,    11,    78,     5,    69,     5,     5,     5,    39,    22,
       5,     5
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
#line 123 "func.y"
    { printf("PARSING SUCCESS\n"); }
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 127 "func.y"
    {/*empty*/}
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 135 "func.y"
    { TYPE = INT; }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 136 "func.y"
    {TYPE = BOOL; }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 139 "func.y"
    {}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 153 "func.y"
    { (yyval.n) = NULL; }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 154 "func.y"
    {  (yyval.n)=CreateNode(0,'F', 0, NULL, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n), NULL); if (((yyvsp[(1) - (2)].n)==NULL || (yyvsp[(1) - (2)].n)->TYPE == FUNC) && (yyvsp[(2) - (2)].n)->TYPE== FUNC) (yyval.n)->TYPE= FUNC; else (yyval.n)->TYPE=-1; yyerror("Bad functions") ; }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 157 "func.y"
    { 
																(yyval.n)=CreateNode(0,'f', 0, (yyvsp[(2) - (8)].n)->NAME, (yyvsp[(4) - (8)].n), (yyvsp[(7) - (8)].n), NULL); }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 161 "func.y"
    {
            printf("*****offset of %s is %d\n",(yyvsp[(1) - (1)].n)->NAME,Goffset);
            Ginstall((yyvsp[(1) - (1)].n)->NAME, TYPE, 0, Goffset, 0, NULL);
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

  case 23:

/* Line 1806 of yacc.c  */
#line 176 "func.y"
    {
                                Ginstall((yyvsp[(1) - (4)].n)->NAME, TYPE+2, (yyvsp[(3) - (4)].n)->VALUE, Goffset, 0, NULL);
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
                                printf("*****offset of %s[%d] is %d\n",(yyvsp[(1) - (4)].n)->NAME,(yyvsp[(3) - (4)].n)->VALUE,Goffset);
                                /*---------------------------------------------*/
                            }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 194 "func.y"
    {
                                                                    (yyval.n)=CreateNode(0,'f', 0, "MAIN", NULL, (yyvsp[(6) - (7)].n), NULL);
                                                                }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 199 "func.y"
    { (yyval.n)=(yyvsp[(2) - (2)].n); }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 204 "func.y"
    {/*empty*/}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 213 "func.y"
    {
        printf("*****L offset of %s is %d\n",(yyvsp[(1) - (1)].n)->NAME,Loffset);
        Linstall((yyvsp[(1) - (1)].n)->NAME, TYPE, Loffset, 0);
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

  case 34:

/* Line 1806 of yacc.c  */
#line 230 "func.y"
    {  (yyval.n)=CreateNode(0,'S', 0, NULL, (yyvsp[(2) - (4)].n), (yyvsp[(3) - (4)].n), NULL); if (((yyvsp[(2) - (4)].n)==NULL || (yyvsp[(2) - (4)].n)->TYPE==0) && (yyvsp[(3) - (4)].n)->TYPE==0) (yyval.n)->TYPE=0; else (yyval.n)->TYPE=-1; yyerror("Bad begin error"); }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 233 "func.y"
    { (yyval.n) = NULL; }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 234 "func.y"
    {  (yyval.n)=CreateNode(0,'S', 0, NULL, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n), NULL); if (((yyvsp[(1) - (2)].n)==NULL || (yyvsp[(1) - (2)].n)->TYPE==0) && (yyvsp[(2) - (2)].n)->TYPE==0) (yyval.n)->TYPE=0; else (yyval.n)->TYPE=-1; yyerror("Bad statements");}
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 237 "func.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n); }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 238 "func.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 239 "func.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n);  }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 240 "func.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n);  }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 241 "func.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n);  }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 242 "func.y"
    {(yyval.n)=(yyvsp[(1) - (1)].n);}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 245 "func.y"
    { (yyvsp[(1) - (6)].n) = CreateNode(0,'I', 0, NULL, (yyvsp[(4) - (6)].n), (yyvsp[(2) - (6)].n), NULL); (yyval.n) = (yyvsp[(1) - (6)].n);
                                                if ((yyvsp[(2) - (6)].n)->TYPE==2 && ((yyvsp[(4) - (6)].n)==NULL || (yyvsp[(4) - (6)].n)->TYPE==0)) (yyval.n)->TYPE=0; else (yyval.n)->TYPE=-1; yyerror("If type error");  }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 247 "func.y"
    { (yyvsp[(1) - (8)].n) = CreateNode(0,'I', 0, NULL, (yyvsp[(4) - (8)].n), (yyvsp[(2) - (8)].n), (yyvsp[(6) - (8)].n)); (yyval.n) = (yyvsp[(1) - (8)].n);
                                                if ((yyvsp[(2) - (8)].n)->TYPE==2 && ((yyvsp[(4) - (8)].n)==NULL || (yyvsp[(4) - (8)].n)->TYPE==0) && ((yyvsp[(6) - (8)].n)==NULL || (yyvsp[(6) - (8)].n)->TYPE==0)) (yyval.n)->TYPE=0; else (yyval.n)->TYPE=-1; yyerror("If else error"); }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 251 "func.y"
    { (yyvsp[(1) - (6)].n) = CreateNode(0,'W', 0, NULL, (yyvsp[(4) - (6)].n), (yyvsp[(2) - (6)].n), NULL); (yyval.n)=(yyvsp[(1) - (6)].n); if ((yyvsp[(2) - (6)].n)->TYPE==2 && ((yyvsp[(4) - (6)].n)==NULL || (yyvsp[(4) - (6)].n)->TYPE==0)) (yyval.n)->TYPE=0; else (yyval.n)->TYPE=-1; yyerror("while error"); }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 253 "func.y"
    { (yyvsp[(1) - (6)].n) = CreateNode(0,'D', 0, NULL, (yyvsp[(2) - (6)].n), (yyvsp[(4) - (6)].n), NULL); (yyval.n)=(yyvsp[(1) - (6)].n); if ((yyvsp[(4) - (6)].n)->TYPE==2 && ((yyvsp[(2) - (6)].n)==NULL || (yyvsp[(2) - (6)].n)->TYPE==0)) (yyval.n)->TYPE=0; else (yyval.n)->TYPE=-1; yyerror("Do while error"); }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 255 "func.y"
    { (yyvsp[(2) - (4)].n) = CreateNode(0,'=', 0, NULL, (yyvsp[(1) - (4)].n), NULL, (yyvsp[(3) - (4)].n)); (yyval.n)=(yyvsp[(2) - (4)].n);
                                            struct Lsymbol* lt = Llookup((yyvsp[(1) - (4)].n)->NAME);
                                            if(lt) { if (lt->TYPE == (yyvsp[(3) - (4)].n)->TYPE ) (yyval.n)->TYPE=0; }
                                            else {
                                                struct Gsymbol* gt = Glookup((yyvsp[(1) - (4)].n)->NAME);
                                                if(gt) { if ( gt->SIZE==0 && (gt->TYPE == (yyvsp[(3) - (4)].n)->TYPE )) (yyval.n)->TYPE=0;
                                                else { (yyval.n)->TYPE=-1;	yyerror("Wrong assignment");}}else { printf("ID %s not found\n",(yyvsp[(1) - (4)].n)->NAME); yyerror(""); (yyval.n)->TYPE=-1;}
                                            }}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 263 "func.y"
    { (yyvsp[(1) - (7)].n)->center = (yyvsp[(3) - (7)].n); (yyvsp[(5) - (7)].n) = CreateNode(0,'=', 0, NULL, (yyvsp[(1) - (7)].n), NULL, (yyvsp[(6) - (7)].n)); (yyval.n)=(yyvsp[(5) - (7)].n);
                                                                struct Gsymbol* gt = Glookup((yyvsp[(1) - (7)].n)->NAME);
                                                                if(gt) {if ( gt->SIZE!=0 && (yyvsp[(3) - (7)].n)->TYPE==INT && ((gt->TYPE-2) == (yyvsp[(6) - (7)].n)->TYPE)) (yyval.n)->TYPE=0; else { (yyval.n)->TYPE=-1;
                                                                yyerror("Wrong assignment of array type");}} else {printf("Array %s not found\n",(yyvsp[(1) - (7)].n)->NAME); yyerror(""); (yyval.n)->TYPE=-1; }
                                                            }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 270 "func.y"
    { (yyvsp[(1) - (5)].n) = CreateNode(0,'r', 0, NULL, NULL, (yyvsp[(3) - (5)].n), NULL); (yyval.n) = (yyvsp[(1) - (5)].n);
                                            struct Lsymbol* lt = Llookup((yyvsp[(3) - (5)].n)->NAME);
                                            if(lt && (lt->TYPE == 1))
                                                (yyval.n)->TYPE=0;
                                            else {
                                                struct Gsymbol* gt = Glookup((yyvsp[(3) - (5)].n)->NAME);
                                                if(gt) {if( gt->SIZE==0 && gt->TYPE == 1 ) (yyval.n)->TYPE=0; else { (yyval.n)->TYPE=-1;
                                                yyerror("Read type error");}} else { printf("ID %s not found\n",(yyvsp[(3) - (5)].n)->NAME); yyerror(""); (yyval.n)->TYPE=-1;}
                                            }}
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 279 "func.y"
    { (yyvsp[(3) - (8)].n)->center = (yyvsp[(5) - (8)].n);  (yyvsp[(1) - (8)].n) = CreateNode(0,'r', 0, NULL, NULL, (yyvsp[(3) - (8)].n), NULL); (yyval.n) = (yyvsp[(1) - (8)].n);
                                                struct Gsymbol* gt = Glookup((yyvsp[(3) - (8)].n)->NAME);
                                                if(gt) { if(gt->SIZE!=0 && gt->TYPE==(INT+2) && (yyvsp[(5) - (8)].n)->TYPE==1) (yyval.n)->TYPE=0; else { (yyval.n)->TYPE=-1;
                                                yyerror("Read type error");}} else { printf("ID %s not found\n",(yyvsp[(3) - (8)].n)->NAME); yyerror(""); (yyval.n)->TYPE=-1;}
                                            }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 286 "func.y"
    { (yyvsp[(1) - (5)].n) = CreateNode(0,'w', 0, NULL, NULL, (yyvsp[(3) - (5)].n), NULL); (yyval.n) = (yyvsp[(1) - (5)].n);
                                                                            if((yyvsp[(3) - (5)].n)->TYPE==1) (yyval.n)->TYPE=0; else {(yyval.n)->TYPE=-1; yyerror("Write error");} }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 290 "func.y"
    { (yyvsp[(1) - (3)].n) = CreateNode(0,'R', 0, NULL, NULL, (yyvsp[(2) - (3)].n), NULL);  (yyval.n) = (yyvsp[(1) - (3)].n);
                                                                            if((yyvsp[(2) - (3)].n)->TYPE==1) (yyval.n)->TYPE=0; else {(yyval.n)->TYPE=-1; yyerror("Return type nomatch");}}
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 294 "func.y"
    { (yyvsp[(2) - (3)].n) = CreateNode(0,'+', 0, NULL, (yyvsp[(1) - (3)].n), NULL, (yyvsp[(3) - (3)].n)); (yyval.n) = (yyvsp[(2) - (3)].n); if((yyvsp[(1) - (3)].n)->TYPE==1 && (yyvsp[(3) - (3)].n)->TYPE ==1) (yyval.n)->TYPE=1; else (yyval.n)->TYPE=-1; yyerror("+ error"); }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 295 "func.y"
    { (yyvsp[(2) - (3)].n) = CreateNode(0,'-', 0, NULL, (yyvsp[(1) - (3)].n), NULL, (yyvsp[(3) - (3)].n)); (yyval.n) = (yyvsp[(2) - (3)].n); if((yyvsp[(1) - (3)].n)->TYPE==1 && (yyvsp[(3) - (3)].n)->TYPE ==1) (yyval.n)->TYPE=1; else (yyval.n)->TYPE=-1; yyerror("- error");  }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 296 "func.y"
    { (yyvsp[(2) - (3)].n) = CreateNode(0,'*', 0, NULL, (yyvsp[(1) - (3)].n), NULL, (yyvsp[(3) - (3)].n)); (yyval.n) = (yyvsp[(2) - (3)].n); if((yyvsp[(1) - (3)].n)->TYPE==1 && (yyvsp[(3) - (3)].n)->TYPE ==1) (yyval.n)->TYPE=1; else (yyval.n)->TYPE=-1; yyerror("* error"); }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 297 "func.y"
    { (yyvsp[(2) - (3)].n) = CreateNode(0,'/', 0, NULL, (yyvsp[(1) - (3)].n), NULL, (yyvsp[(3) - (3)].n)); (yyval.n) = (yyvsp[(2) - (3)].n);  if((yyvsp[(1) - (3)].n)->TYPE==1 && (yyvsp[(3) - (3)].n)->TYPE ==1) (yyval.n)->TYPE=1; else (yyval.n)->TYPE=-1; yyerror("/ error"); }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 298 "func.y"
    { (yyvsp[(2) - (3)].n) = CreateNode(0,'%', 0, NULL, (yyvsp[(1) - (3)].n), NULL, (yyvsp[(3) - (3)].n)); (yyval.n) = (yyvsp[(2) - (3)].n); if((yyvsp[(1) - (3)].n)->TYPE==1 && (yyvsp[(3) - (3)].n)->TYPE ==1) (yyval.n)->TYPE=1; else (yyval.n)->TYPE=-1; yyerror("%error"); }
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 299 "func.y"
    { (yyvsp[(2) - (3)].n) = CreateNode(0,'E', 0, NULL, (yyvsp[(1) - (3)].n), NULL, (yyvsp[(3) - (3)].n)); (yyval.n) = (yyvsp[(2) - (3)].n); if((yyvsp[(1) - (3)].n)->TYPE==1 && (yyvsp[(3) - (3)].n)->TYPE ==1) (yyval.n)->TYPE=2; else (yyval.n)->TYPE=-1; yyerror("= error");  }
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 300 "func.y"
    { (yyvsp[(2) - (3)].n) = CreateNode(0,'<', 0, NULL, (yyvsp[(1) - (3)].n), NULL, (yyvsp[(3) - (3)].n)); (yyval.n) = (yyvsp[(2) - (3)].n); if((yyvsp[(1) - (3)].n)->TYPE==1 && (yyvsp[(3) - (3)].n)->TYPE ==1) (yyval.n)->TYPE=2; else (yyval.n)->TYPE=-1; yyerror("< error"); }
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 301 "func.y"
    { (yyvsp[(2) - (3)].n) = CreateNode(0,'>', 0, NULL, (yyvsp[(1) - (3)].n), NULL, (yyvsp[(3) - (3)].n)); (yyval.n) = (yyvsp[(2) - (3)].n); if((yyvsp[(1) - (3)].n)->TYPE==1 && (yyvsp[(3) - (3)].n)->TYPE ==1) (yyval.n)->TYPE=2; else (yyval.n)->TYPE=-1; yyerror("> error"); }
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 302 "func.y"
    { (yyvsp[(2) - (3)].n) = CreateNode(0,'G', 0, NULL, (yyvsp[(1) - (3)].n), NULL, (yyvsp[(3) - (3)].n)); (yyval.n) = (yyvsp[(2) - (3)].n); if((yyvsp[(1) - (3)].n)->TYPE==1 && (yyvsp[(3) - (3)].n)->TYPE ==1) (yyval.n)->TYPE=2; else (yyval.n)->TYPE=-1; yyerror(">= error"); }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 303 "func.y"
    { (yyvsp[(2) - (3)].n) = CreateNode(0,'L', 0, NULL, (yyvsp[(1) - (3)].n), NULL, (yyvsp[(3) - (3)].n)); (yyval.n) = (yyvsp[(2) - (3)].n); if((yyvsp[(1) - (3)].n)->TYPE==1 && (yyvsp[(3) - (3)].n)->TYPE ==1) (yyval.n)->TYPE=2; else (yyval.n)->TYPE=-1; yyerror("<= error");  }
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 304 "func.y"
    { (yyvsp[(2) - (3)].n) = CreateNode(0,'N', 0, NULL, (yyvsp[(1) - (3)].n), NULL, (yyvsp[(3) - (3)].n)); (yyval.n) = (yyvsp[(2) - (3)].n); if((yyvsp[(1) - (3)].n)->TYPE==1 && (yyvsp[(3) - (3)].n)->TYPE ==1) (yyval.n)->TYPE=2; else (yyval.n)->TYPE=-1; yyerror("!= error");  }
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 305 "func.y"
    { (yyvsp[(2) - (3)].n) = CreateNode(0,'&', 0, NULL, (yyvsp[(1) - (3)].n), NULL, (yyvsp[(3) - (3)].n)); (yyval.n) = (yyvsp[(2) - (3)].n); if((yyvsp[(1) - (3)].n)->TYPE==2 && (yyvsp[(3) - (3)].n)->TYPE ==2) (yyval.n)->TYPE=2; else (yyval.n)->TYPE=-1; yyerror("& error"); }
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 306 "func.y"
    { (yyvsp[(2) - (3)].n) = CreateNode(0,'|', 0, NULL, (yyvsp[(1) - (3)].n), NULL, (yyvsp[(3) - (3)].n)); (yyval.n) = (yyvsp[(2) - (3)].n); if((yyvsp[(1) - (3)].n)->TYPE==2 && (yyvsp[(3) - (3)].n)->TYPE ==2) (yyval.n)->TYPE=2; else (yyval.n)->TYPE=-1; yyerror("| error"); }
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 307 "func.y"
    { (yyvsp[(1) - (2)].n) = CreateNode(0,'!', 0, NULL, NULL, (yyvsp[(2) - (2)].n), NULL); (yyval.n) = (yyvsp[(1) - (2)].n);  if((yyvsp[(2) - (2)].n)->TYPE==2) (yyval.n)->TYPE=2; else (yyval.n)->TYPE=-1; yyerror("NOT error"); }
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 308 "func.y"
    { (yyval.n) = (yyvsp[(2) - (3)].n); }
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 309 "func.y"
    { (yyvsp[(1) - (1)].n) = CreateNode(2,'T', 0, NULL,NULL,NULL,NULL); (yyval.n) = (yyvsp[(1) - (1)].n);  }
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 310 "func.y"
    { (yyvsp[(1) - (1)].n) = CreateNode(2,'F', 0, NULL, NULL, NULL, NULL); (yyval.n) = (yyvsp[(1) - (1)].n); }
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 311 "func.y"
    { (yyval.n)=(yyvsp[(1) - (1)].n); }
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 312 "func.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n); struct Lsymbol* lt = Llookup((yyvsp[(1) - (1)].n)->NAME); if(lt) (yyval.n)->TYPE=lt->TYPE; else {
                                                            struct Gsymbol* gt = Glookup((yyvsp[(1) - (1)].n)->NAME);
                                                            if(gt) {if(gt->SIZE==0) (yyval.n)->TYPE=gt->TYPE; else (yyval.n)->TYPE=-1; }
                                                            else { printf("ID %s not found\n",(yyvsp[(1) - (1)].n)->NAME); yyerror(""); (yyval.n)->TYPE=-1;}}}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 316 "func.y"
    {   (yyvsp[(1) - (4)].n)->center = (yyvsp[(3) - (4)].n); (yyval.n) = (yyvsp[(1) - (4)].n);  struct Gsymbol* gt = Glookup((yyvsp[(1) - (4)].n)->NAME);
                                                                    if(gt) { if(gt->SIZE!=0 && (yyvsp[(3) - (4)].n)->TYPE==1)
                                                                    (yyval.n)->TYPE=gt->TYPE; else (yyval.n)->TYPE=-1; yyerror("array type expression"); }
                                                                    else { printf("Array %s not found\n",(yyvsp[(1) - (4)].n)->NAME); yyerror(""); (yyval.n)->TYPE=-1;}}
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 320 "func.y"
    { }
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 321 "func.y"
    { }
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 325 "func.y"
    {}
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 326 "func.y"
    {}
    break;



/* Line 1806 of yacc.c  */
#line 2219 "y.tab.c"
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
#line 329 "func.y"


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



