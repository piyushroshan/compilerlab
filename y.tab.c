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
#line 1 "piyush.y"

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
void printTree(struct node* root);
struct node* CreateNode(int TYPE1, int NODETYPE1, int VALUE1, char* NAME1, struct node *ptr1, struct node *ptr2, struct node *ptr3);


/* Line 268 of yacc.c  */
#line 91 "y.tab.c"

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
#line 20 "piyush.y"

	struct node* n;



/* Line 293 of yacc.c  */
#line 227 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 239 "y.tab.c"

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
#define YYLAST   313

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNRULES -- Number of states.  */
#define YYNSTATES  183

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
       0,     0,     3,     6,    10,    11,    14,    18,    20,    24,
      26,    28,    30,    35,    43,    46,    50,    51,    54,    58,
      60,    64,    66,    71,    76,    77,    80,    82,    84,    86,
      88,    90,    97,   106,   113,   118,   126,   132,   141,   147,
     151,   155,   159,   163,   167,   171,   175,   177,   181,   185,
     189,   193,   197,   201,   205,   209,   212,   216,   218,   220,
     222,   227,   231,   235,   239,   243,   247,   251,   253,   255,
     260,   264,   268,   272,   276,   280,   284,   288,   292,   295,
     299,   301
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      49,     0,    -1,    50,    56,    -1,     3,    51,     4,    -1,
      -1,    51,    52,    -1,    54,    53,     5,    -1,    55,    -1,
      53,     6,    55,    -1,     7,    -1,     8,    -1,     9,    -1,
       9,    10,    26,    11,    -1,     7,    47,    38,    39,    41,
      57,    40,    -1,    58,    63,    -1,     3,    59,     4,    -1,
      -1,    59,    60,    -1,    54,    61,     5,    -1,    62,    -1,
      61,     6,    62,    -1,     9,    -1,     9,    10,    73,    11,
      -1,    44,    64,    71,    45,    -1,    -1,    64,    65,    -1,
      66,    -1,    67,    -1,    69,    -1,    70,    -1,    68,    -1,
      21,    74,    23,    64,    22,     5,    -1,    21,    74,    23,
      64,    24,    64,    22,     5,    -1,    25,    74,    42,    64,
      43,     5,    -1,     9,    28,    72,     5,    -1,     9,    10,
      73,    11,    28,    72,     5,    -1,    19,    38,     9,    39,
       5,    -1,    19,    38,     9,    10,    73,    11,    39,     5,
      -1,    20,    38,    73,    39,     5,    -1,    46,    72,     5,
      -1,    73,    34,    73,    -1,    73,    35,    73,    -1,    73,
      36,    73,    -1,    73,    37,    73,    -1,    73,    15,    73,
      -1,    38,    73,    39,    -1,    26,    -1,    73,    27,    73,
      -1,    73,    30,    73,    -1,    73,    32,    73,    -1,    73,
      33,    73,    -1,    73,    31,    73,    -1,    73,    29,    73,
      -1,    74,    16,    74,    -1,    74,    17,    74,    -1,    18,
      74,    -1,    38,    74,    39,    -1,    12,    -1,    13,    -1,
       9,    -1,     9,    10,    73,    11,    -1,    73,    34,    73,
      -1,    73,    35,    73,    -1,    73,    36,    73,    -1,    73,
      37,    73,    -1,    73,    15,    73,    -1,    38,    73,    39,
      -1,    26,    -1,     9,    -1,     9,    10,    73,    11,    -1,
      73,    27,    73,    -1,    73,    30,    73,    -1,    73,    32,
      73,    -1,    73,    33,    73,    -1,    73,    31,    73,    -1,
      73,    29,    73,    -1,    74,    16,    74,    -1,    74,    17,
      74,    -1,    18,    74,    -1,    38,    74,    39,    -1,    12,
      -1,    13,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    48,    48,    50,    52,    53,    55,    57,    58,    60,
      61,    64,    65,    68,    71,    74,    76,    77,    79,    81,
      82,    85,    86,    89,    92,    93,    96,    97,    98,    99,
     100,   103,   104,   107,   110,   111,   114,   115,   118,   121,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169
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
  "Gvar", "main_function", "fbody", "declaration", "declStatements",
  "declStatement", "vars", "var", "beginbody", "statements", "statement",
  "ifelse", "dowhile", "astatement", "read", "write", "return",
  "expression", "aexpression", "lexpression", 0
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
      54,    55,    55,    56,    57,    58,    59,    59,    60,    61,
      61,    62,    62,    63,    64,    64,    65,    65,    65,    65,
      65,    66,    66,    67,    68,    68,    69,    69,    70,    71,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     3,     0,     2,     3,     1,     3,     1,
       1,     1,     4,     7,     2,     3,     0,     2,     3,     1,
       3,     1,     4,     4,     0,     2,     1,     1,     1,     1,
       1,     6,     8,     6,     4,     7,     5,     8,     5,     3,
       3,     3,     3,     3,     3,     3,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     3,     1,     1,     1,
       4,     3,     3,     3,     3,     3,     3,     1,     1,     4,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     3,
       1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     4,     0,     0,     0,     1,     0,     2,     3,     9,
      10,     5,     0,     0,    11,     0,     7,     0,     0,     6,
       0,     0,     0,     8,     0,    12,    16,     0,     0,     0,
      13,    24,    14,    15,     0,    17,     0,    21,     0,    19,
       0,     0,     0,     0,     0,     0,    25,    26,    27,    30,
      28,    29,     0,     0,    18,     0,     0,     0,     0,     0,
      68,    80,    81,     0,    67,     0,     0,     0,     0,    68,
      80,    81,     0,    67,     0,     0,     0,     0,    23,     0,
       0,    20,     0,     0,     0,     0,     0,    78,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    24,    24,     0,    78,     0,     0,    39,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    22,     0,    34,     0,     0,     0,
       0,    66,    79,    65,    70,    75,    71,    74,    72,    73,
      61,    62,    63,    64,    76,    77,     0,     0,     0,    66,
      79,    65,    70,    75,    71,    74,    72,    73,    61,    62,
      63,    64,    76,    77,     0,     0,    36,    38,    69,     0,
      24,     0,    69,     0,     0,    31,     0,    33,    35,     0,
       0,    37,    32
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,    11,    15,    12,    16,     7,    27,
      28,    29,    35,    38,    39,    32,    36,    46,    47,    48,
      49,    50,    51,    52,    75,    66,    77
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -88
static const yytype_int16 yypact[] =
{
      23,   -88,    59,    72,   179,   -88,    37,   -88,   -88,   -88,
     -88,   -88,    95,    54,    96,    83,   -88,    74,   105,   -88,
      95,   104,   135,   -88,   153,   -88,   -88,    76,   114,   203,
     -88,   -88,   -88,   -88,   148,   -88,    12,   157,   138,   -88,
      33,   133,   139,    -3,    -3,   156,   -88,   -88,   -88,   -88,
     -88,   -88,   131,    -2,   -88,   148,    -2,   156,   172,    -2,
     168,   -88,   -88,    -3,   -88,    -3,   242,    77,   -12,    17,
     180,   183,    -3,   190,    -3,   191,   255,     2,   -88,    -2,
     118,   -88,   155,   197,     3,   216,    -2,   -88,   193,   -14,
      -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,
      -2,    -3,    -3,   -88,   -88,    -2,   204,   206,    47,   -88,
      -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,
      -2,    -3,    -3,   229,   -88,   184,   -88,    -2,   208,   209,
     164,   -88,   -88,   -88,    62,    62,    62,    62,    62,    62,
      66,    66,   -88,   -88,   -88,   -88,   274,    19,   169,   210,
     241,   243,    75,    86,    90,   102,   113,   125,   127,   136,
     244,   249,   251,   253,   156,   182,   -88,   -88,   -88,   254,
     -88,   256,   257,   262,   195,   -88,   288,   -88,   -88,   275,
     276,   -88,   -88
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -88,   -88,   -88,   -88,   -88,   -88,   218,   240,   -88,   -88,
     -88,   -88,   -88,   -88,   245,   -88,   -87,   -88,   -88,   -88,
     -88,   -88,   -88,   -88,   -56,   -45,    13
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -61
static const yytype_int16 yytable[] =
{
      76,    83,   101,   102,   101,   102,    60,    60,    80,    61,
      62,    82,    76,   127,    85,    63,   146,   147,   121,   122,
      88,    40,   -59,    64,    64,   132,     1,   105,    40,   107,
     104,    41,    42,    43,   123,    65,    79,    44,    41,    42,
      43,   130,   128,    56,    44,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,    67,    68,    45,     5,
     148,    57,   171,   101,   102,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,    87,    90,    89,     6,
     -47,    90,   165,   176,    13,   106,   150,   108,    19,    20,
      90,   -52,    17,   101,   102,   -48,    97,    98,    99,   100,
     103,    90,    99,   100,    14,    90,    18,   -51,   173,    97,
      98,    99,   100,    21,   144,   145,    30,    90,   -49,    76,
      97,    98,    99,   100,    97,    98,    99,   100,    90,   124,
     -50,    22,   -40,    90,   162,   163,    97,    98,    99,   100,
      90,   -41,    90,    54,    55,    24,    25,    97,    98,    99,
     100,    90,    97,    98,    99,   100,    26,    37,    31,    97,
      98,    99,   100,    99,   100,    69,   125,    53,    70,    71,
      90,    58,    99,   100,    72,   168,    78,    59,    86,    90,
     172,    84,    73,     8,    90,   -57,     9,    10,   -58,    97,
      98,    99,   100,   174,    74,   -46,   109,    90,    97,    98,
      99,   100,   126,    97,    98,    99,   100,    33,    90,   -55,
       9,    10,   164,   166,   167,   -45,    97,    98,    99,   100,
      91,    90,    92,    93,    94,    95,    96,    97,    98,    99,
     100,    90,   131,    91,   179,    92,    93,    94,    95,    96,
      97,    98,    99,   100,    90,   149,   -56,    34,   -44,   -42,
      97,    98,    99,   100,   -43,   129,   -53,    90,   -54,   175,
      23,   177,   -60,    97,    98,    99,   100,   178,   131,    91,
     110,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     181,   182,   111,    40,   112,   113,   114,   115,   116,   117,
     118,   119,   120,    41,    42,    43,   169,    40,   170,    44,
      81,     0,     0,     0,     0,     0,     0,    41,    42,    43,
     180,     0,     0,    44
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-88))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      45,    57,    16,    17,    16,    17,     9,     9,    53,    12,
      13,    56,    57,    10,    59,    18,   103,   104,    16,    17,
      65,     9,     5,    26,    26,    39,     3,    10,     9,    74,
      42,    19,    20,    21,    79,    38,    38,    25,    19,    20,
      21,    86,    39,    10,    25,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,    43,    44,    46,     0,
     105,    28,    43,    16,    17,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,    63,    15,    65,     7,
       5,    15,   127,   170,    47,    72,    39,    74,     5,     6,
      15,     5,    38,    16,    17,     5,    34,    35,    36,    37,
      23,    15,    36,    37,     9,    15,    10,     5,   164,    34,
      35,    36,    37,    39,   101,   102,    40,    15,     5,   164,
      34,    35,    36,    37,    34,    35,    36,    37,    15,    11,
       5,    26,     5,    15,   121,   122,    34,    35,    36,    37,
      15,     5,    15,     5,     6,    41,    11,    34,    35,    36,
      37,    15,    34,    35,    36,    37,     3,     9,    44,    34,
      35,    36,    37,    36,    37,     9,    11,    10,    12,    13,
      15,    38,    36,    37,    18,    11,    45,    38,    10,    15,
      11,     9,    26,     4,    15,     5,     7,     8,     5,    34,
      35,    36,    37,    11,    38,     5,     5,    15,    34,    35,
      36,    37,     5,    34,    35,    36,    37,     4,    15,     5,
       7,     8,    28,     5,     5,     5,    34,    35,    36,    37,
      27,    15,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    15,    39,    27,    39,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    15,    39,     5,    29,     5,     5,
      34,    35,    36,    37,     5,    39,     5,    15,     5,     5,
      20,     5,     5,    34,    35,    36,    37,     5,    39,    27,
      15,    29,    30,    31,    32,    33,    34,    35,    36,    37,
       5,     5,    27,     9,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    19,    20,    21,    22,     9,    24,    25,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    21,
      22,    -1,    -1,    25
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    49,    50,    51,     0,     7,    56,     4,     7,
       8,    52,    54,    47,     9,    53,    55,    38,    10,     5,
       6,    39,    26,    55,    41,    11,     3,    57,    58,    59,
      40,    44,    63,     4,    54,    60,    64,     9,    61,    62,
       9,    19,    20,    21,    25,    46,    65,    66,    67,    68,
      69,    70,    71,    10,     5,     6,    10,    28,    38,    38,
       9,    12,    13,    18,    26,    38,    73,    74,    74,     9,
      12,    13,    18,    26,    38,    72,    73,    74,    45,    38,
      73,    62,    73,    72,     9,    73,    10,    74,    73,    74,
      15,    27,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    16,    17,    23,    42,    10,    74,    73,    74,     5,
      15,    27,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    16,    17,    73,    11,    11,     5,    10,    39,    39,
      73,    39,    39,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    74,    74,    64,    64,    73,    39,
      39,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    74,    74,    28,    73,     5,     5,    11,    22,
      24,    43,    11,    72,    11,     5,    64,     5,     5,    39,
      22,     5,     5
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
#line 48 "piyush.y"
    { printf("PARSING SUCCESS\n"); (yyval.n)=(yyvsp[(2) - (2)].n); printTree((yyvsp[(2) - (2)].n));}
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 52 "piyush.y"
    {/*empty*/}
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 68 "piyush.y"
    { (yyval.n)=CreateNode(0,'f', 0, "MAIN", NULL, (yyvsp[(6) - (7)].n), NULL);}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 71 "piyush.y"
    { (yyval.n)=(yyvsp[(2) - (2)].n); }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 76 "piyush.y"
    {/*empty*/}
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 89 "piyush.y"
    {  (yyval.n)=CreateNode(0,'S', 0, NULL, (yyvsp[(2) - (4)].n), (yyvsp[(3) - (4)].n), NULL);}
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 92 "piyush.y"
    { (yyval.n) = NULL; }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 93 "piyush.y"
    {  (yyval.n)=CreateNode(0,'S', 0, NULL, (yyvsp[(2) - (2)].n), (yyvsp[(1) - (2)].n), NULL); }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 96 "piyush.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n); }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 97 "piyush.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n); }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 98 "piyush.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n); }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 99 "piyush.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n); }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 100 "piyush.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n); }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 103 "piyush.y"
    { (yyvsp[(1) - (6)].n) = CreateNode(0,'I', 0, NULL, (yyvsp[(4) - (6)].n), (yyvsp[(2) - (6)].n), NULL); (yyval.n) = (yyvsp[(1) - (6)].n); }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 104 "piyush.y"
    { (yyvsp[(1) - (8)].n) = CreateNode(0,'I', 0, NULL, (yyvsp[(4) - (8)].n), (yyvsp[(2) - (8)].n), (yyvsp[(6) - (8)].n)); (yyval.n) = (yyvsp[(1) - (8)].n); }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 107 "piyush.y"
    { (yyvsp[(1) - (6)].n) = CreateNode(0,'W', 0, NULL, (yyvsp[(4) - (6)].n), (yyvsp[(2) - (6)].n), NULL); (yyval.n)=(yyvsp[(1) - (6)].n); }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 110 "piyush.y"
    { (yyvsp[(2) - (4)].n) = CreateNode(0,'=', 0, NULL, (yyvsp[(1) - (4)].n), NULL, (yyvsp[(3) - (4)].n)); (yyval.n)=(yyvsp[(2) - (4)].n); }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 111 "piyush.y"
    { (yyvsp[(1) - (7)].n)->center = (yyvsp[(3) - (7)].n); (yyvsp[(5) - (7)].n) = CreateNode(0,'=', 0, NULL, (yyvsp[(1) - (7)].n), NULL, (yyvsp[(6) - (7)].n)); (yyval.n)=(yyvsp[(5) - (7)].n);  }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 114 "piyush.y"
    { (yyvsp[(1) - (5)].n) = CreateNode(0,'r', 0, NULL, NULL, (yyvsp[(3) - (5)].n), NULL); (yyval.n) = (yyvsp[(1) - (5)].n); }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 115 "piyush.y"
    { (yyvsp[(3) - (8)].n)->center = (yyvsp[(5) - (8)].n);  (yyvsp[(1) - (8)].n) = CreateNode(0,'r', 0, NULL, NULL, (yyvsp[(3) - (8)].n), NULL); (yyval.n) = (yyvsp[(1) - (8)].n); }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 118 "piyush.y"
    { (yyvsp[(1) - (5)].n) = CreateNode(0,'w', 0, NULL, NULL, (yyvsp[(3) - (5)].n), NULL); (yyval.n) = (yyvsp[(1) - (5)].n); }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 121 "piyush.y"
    { (yyvsp[(1) - (3)].n) = CreateNode(0,'R', 0, NULL, NULL, (yyvsp[(2) - (3)].n), NULL); (yyval.n) = (yyvsp[(1) - (3)].n); }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 124 "piyush.y"
    { (yyvsp[(2) - (3)].n) = CreateNode(0,'+', 0, NULL, (yyvsp[(1) - (3)].n), NULL, (yyvsp[(3) - (3)].n)); (yyval.n) = (yyvsp[(2) - (3)].n); }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 125 "piyush.y"
    { (yyvsp[(2) - (3)].n) = CreateNode(0,'-', 0, NULL, (yyvsp[(1) - (3)].n), NULL, (yyvsp[(3) - (3)].n)); (yyval.n) = (yyvsp[(2) - (3)].n); }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 126 "piyush.y"
    { (yyvsp[(2) - (3)].n) = CreateNode(0,'*', 0, NULL, (yyvsp[(1) - (3)].n), NULL, (yyvsp[(3) - (3)].n)); (yyval.n) = (yyvsp[(2) - (3)].n); }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 127 "piyush.y"
    { (yyvsp[(2) - (3)].n) = CreateNode(0,'/', 0, NULL, (yyvsp[(1) - (3)].n), NULL, (yyvsp[(3) - (3)].n)); (yyval.n) = (yyvsp[(2) - (3)].n); }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 128 "piyush.y"
    { (yyvsp[(2) - (3)].n) = CreateNode(0,'%', 0, NULL, (yyvsp[(1) - (3)].n), NULL, (yyvsp[(3) - (3)].n)); (yyval.n) = (yyvsp[(2) - (3)].n); }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 129 "piyush.y"
    { (yyval.n)=(yyvsp[(2) - (3)].n); }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 130 "piyush.y"
    { (yyval.n)=(yyvsp[(1) - (1)].n); }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 131 "piyush.y"
    { (yyvsp[(2) - (3)].n) = CreateNode(0,'E', 0, NULL, (yyvsp[(1) - (3)].n), NULL, (yyvsp[(3) - (3)].n)); (yyval.n) = (yyvsp[(2) - (3)].n); }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 132 "piyush.y"
    { (yyvsp[(2) - (3)].n) = CreateNode(0,'<', 0, NULL, (yyvsp[(1) - (3)].n), NULL, (yyvsp[(3) - (3)].n)); (yyval.n) = (yyvsp[(2) - (3)].n); }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 133 "piyush.y"
    { (yyvsp[(2) - (3)].n) = CreateNode(0,'>', 0, NULL, (yyvsp[(1) - (3)].n), NULL, (yyvsp[(3) - (3)].n)); (yyval.n) = (yyvsp[(2) - (3)].n); }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 134 "piyush.y"
    { (yyvsp[(2) - (3)].n) = CreateNode(0,'G', 0, NULL, (yyvsp[(1) - (3)].n), NULL, (yyvsp[(3) - (3)].n)); (yyval.n) = (yyvsp[(2) - (3)].n); }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 135 "piyush.y"
    { (yyvsp[(2) - (3)].n) = CreateNode(0,'L', 0, NULL, (yyvsp[(1) - (3)].n), NULL, (yyvsp[(3) - (3)].n)); (yyval.n) = (yyvsp[(2) - (3)].n); }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 136 "piyush.y"
    { (yyvsp[(2) - (3)].n) = CreateNode(0,'N', 0, NULL, (yyvsp[(1) - (3)].n), NULL, (yyvsp[(3) - (3)].n)); (yyval.n) = (yyvsp[(2) - (3)].n); }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 137 "piyush.y"
    { (yyvsp[(2) - (3)].n) = CreateNode(0,'&', 0, NULL, (yyvsp[(1) - (3)].n), NULL, (yyvsp[(3) - (3)].n)); (yyval.n) = (yyvsp[(2) - (3)].n); }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 138 "piyush.y"
    { (yyvsp[(2) - (3)].n) = CreateNode(0,'|', 0, NULL, (yyvsp[(1) - (3)].n), NULL, (yyvsp[(3) - (3)].n)); (yyval.n) = (yyvsp[(2) - (3)].n); }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 139 "piyush.y"
    { (yyvsp[(1) - (2)].n) = CreateNode(0,'!', 0, NULL, NULL, (yyvsp[(2) - (2)].n), NULL); (yyval.n) = (yyvsp[(1) - (2)].n); }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 140 "piyush.y"
    { (yyval.n) = (yyvsp[(2) - (3)].n); }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 141 "piyush.y"
    { (yyvsp[(1) - (1)].n) = CreateNode(0,'T', 0, NULL,NULL,NULL,NULL); (yyval.n) = (yyvsp[(1) - (1)].n); }
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 142 "piyush.y"
    { (yyvsp[(1) - (1)].n) = CreateNode(0,'F', 0, NULL, NULL, NULL, NULL); (yyval.n) = (yyvsp[(1) - (1)].n); }
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 143 "piyush.y"
    { (yyval.n)=(yyvsp[(1) - (1)].n); }
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 144 "piyush.y"
    {   (yyvsp[(1) - (4)].n)->center = (yyvsp[(3) - (4)].n); (yyval.n) = (yyvsp[(1) - (4)].n);}
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 147 "piyush.y"
    { (yyvsp[(2) - (3)].n) = CreateNode(0,'+', 0, NULL, (yyvsp[(1) - (3)].n), NULL, (yyvsp[(3) - (3)].n)); (yyval.n) = (yyvsp[(2) - (3)].n); }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 148 "piyush.y"
    { (yyvsp[(2) - (3)].n) = CreateNode(0,'-', 0, NULL, (yyvsp[(1) - (3)].n), NULL, (yyvsp[(3) - (3)].n)); (yyval.n) = (yyvsp[(2) - (3)].n); }
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 149 "piyush.y"
    { (yyvsp[(2) - (3)].n) = CreateNode(0,'*', 0, NULL, (yyvsp[(1) - (3)].n), NULL, (yyvsp[(3) - (3)].n)); (yyval.n) = (yyvsp[(2) - (3)].n); }
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 150 "piyush.y"
    { (yyvsp[(2) - (3)].n) = CreateNode(0,'/', 0, NULL, (yyvsp[(1) - (3)].n), NULL, (yyvsp[(3) - (3)].n)); (yyval.n) = (yyvsp[(2) - (3)].n); }
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 151 "piyush.y"
    { (yyvsp[(2) - (3)].n) = CreateNode(0,'%', 0, NULL, (yyvsp[(1) - (3)].n), NULL, (yyvsp[(3) - (3)].n)); (yyval.n) = (yyvsp[(2) - (3)].n); }
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 152 "piyush.y"
    { (yyval.n) = (yyvsp[(2) - (3)].n); }
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 153 "piyush.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n); }
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 154 "piyush.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n); }
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 155 "piyush.y"
    {   (yyvsp[(1) - (4)].n)->center = (yyvsp[(3) - (4)].n); (yyval.n) = (yyvsp[(1) - (4)].n);}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 158 "piyush.y"
    { (yyvsp[(2) - (3)].n) = CreateNode(0,'E', 0, NULL, (yyvsp[(1) - (3)].n), NULL, (yyvsp[(3) - (3)].n)); (yyval.n) = (yyvsp[(2) - (3)].n); }
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 159 "piyush.y"
    { (yyvsp[(2) - (3)].n) = CreateNode(0,'<', 0, NULL, (yyvsp[(1) - (3)].n), NULL, (yyvsp[(3) - (3)].n)); (yyval.n) = (yyvsp[(2) - (3)].n); }
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 160 "piyush.y"
    { (yyvsp[(2) - (3)].n) = CreateNode(0,'>', 0, NULL, (yyvsp[(1) - (3)].n), NULL, (yyvsp[(3) - (3)].n)); (yyval.n) = (yyvsp[(2) - (3)].n); }
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 161 "piyush.y"
    { (yyvsp[(2) - (3)].n) = CreateNode(0,'G', 0, NULL, (yyvsp[(1) - (3)].n), NULL, (yyvsp[(3) - (3)].n)); (yyval.n) = (yyvsp[(2) - (3)].n); }
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 162 "piyush.y"
    { (yyvsp[(2) - (3)].n) = CreateNode(0,'L', 0, NULL, (yyvsp[(1) - (3)].n), NULL, (yyvsp[(3) - (3)].n)); (yyval.n) = (yyvsp[(2) - (3)].n); }
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 163 "piyush.y"
    { (yyvsp[(2) - (3)].n) = CreateNode(0,'N', 0, NULL, (yyvsp[(1) - (3)].n), NULL, (yyvsp[(3) - (3)].n)); (yyval.n) = (yyvsp[(2) - (3)].n); }
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 164 "piyush.y"
    { (yyvsp[(2) - (3)].n) = CreateNode(0,'&', 0, NULL, (yyvsp[(1) - (3)].n), NULL, (yyvsp[(3) - (3)].n)); (yyval.n) = (yyvsp[(2) - (3)].n); }
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 165 "piyush.y"
    { (yyvsp[(2) - (3)].n) = CreateNode(0,'|', 0, NULL, (yyvsp[(1) - (3)].n), NULL, (yyvsp[(3) - (3)].n)); (yyval.n) = (yyvsp[(2) - (3)].n); }
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 166 "piyush.y"
    { (yyvsp[(1) - (2)].n) = CreateNode(0,'!', 0, NULL, NULL, (yyvsp[(2) - (2)].n), NULL); (yyval.n) = (yyvsp[(1) - (2)].n); }
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 167 "piyush.y"
    { (yyval.n) = (yyvsp[(2) - (3)].n); }
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 168 "piyush.y"
    { (yyvsp[(1) - (1)].n) = CreateNode(0,'T', 0, NULL,NULL,NULL,NULL); (yyval.n) = (yyvsp[(1) - (1)].n); }
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 169 "piyush.y"
    { (yyvsp[(1) - (1)].n) = CreateNode(0,'F', 0, NULL, NULL, NULL, NULL); (yyval.n) = (yyvsp[(1) - (1)].n); }
    break;



/* Line 1806 of yacc.c  */
#line 2097 "y.tab.c"
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
#line 172 "piyush.y"


int main(){
	return(yyparse());
}

yyerror(s)
char *s;
{
  fprintf(stderr, "%s\n",s);
}



void printTree(struct node* root){
	if(root==NULL) {
		return;
	}
	switch(root->TYPE){
		case 0 :
			switch(root->NODETYPE ) {
				case 'f' :
					printf("( ");
					printf("%s ->",root->NAME);
					printTree(root->center);
					printf(" )\n");
					break;
				case 'S' :
					printTree(root->center);
					printTree(root->left);
					printTree(root->right);
					break;
				case 'I' :
					printf("( ");
					printf("%s ","IF");
					printTree(root->center);
					printf("\n");
					printTree(root->left);
					printTree(root->right);
					printf(" )\n");
					break;
				case 'W' :
					printf("( ");
					printf("%s ","WHILE");
					printTree(root->center);
					printf("\n");
					printTree(root->left);
					printf(" )\n");
					break;
				case 'r' :
					printf("( ");
					printf("%s ","READ");
					printTree(root->center);
					printf(" )\n");
					break;
				case 'w' :
					printf("( ");
					printf("%s ","WRITE");
					printTree(root->center);
					printf(" )\n");
					break;
				case 'R' :
					printf("( ");
					printf("%s ","RETURN");
					printTree(root->center);
					printf(" )\n");
					break;
				case '=' :
					printf("( ");
					printf("%c ",'=');
					printTree(root->left);
					printTree(root->right);
					printf(" )\n");
					break;
				case '+' :
					printf("( ");
					printf("%c ",'+');
					printTree(root->left);
					printTree(root->right);
					printf(") ");
					break;
				case '-' :
					printf("( ");
					printf("%c ",'-');
					printTree(root->left);
					printTree(root->right);
					printf(") ");
					break;
				case '*' :
					printf("( ");
					printf("%c ",'*');
					printTree(root->left);
					printTree(root->right);
					printf(") ");
					break;
				case '/' :
					printf("( ");
					printf("%c ",'/');
					printTree(root->left);
					printTree(root->right);
					printf(") ");
					break;
				case '%' :
					printf("( ");
					printf("%c ",'%');
					printTree(root->left);
					printTree(root->right);
					printf(") ");
					break;
				case 'T' :
					printf("%s ","True");
					break;
				case 'F' :
					printf("%s ","False");
					break;
				case '&' :
					printf("( ");
					printf("%c ",'&');
					printTree(root->left);
					printTree(root->right);
					printf(") ");
					break;
				case '|' :
					printf("( ");
					printf("%c ",'|');
					printTree(root->left);
					printTree(root->right);
					printf(") ");
					break;
				case '!' :
					printf("( ");
					printf("%c ",'!');
					printTree(root->center);
					printf(") ");
					break;
				case 'G' :
					printf("( ");
					printf("%s ",">=");
					printTree(root->left);
					printTree(root->right);
					printf(") ");
					break;
				case 'L' :
					printf("( ");
					printf("%s ","<=");
					printTree(root->left);
					printTree(root->right);
					printf(") ");
					break;
				case '>' :
					printf("( ");
					printf("%c ",'>');
					printTree(root->left);
					printTree(root->right);
					printf(") ");
					break;
				case '<' :
					printf("( ");
					printf("%c ",'<');
					printTree(root->left);
					printTree(root->right);
					printf(") ");
					break;
				case 'E' :
					printf("( ");
					printf("%s ","==");
					printTree(root->left);
					printTree(root->right);
					printf(") ");
					break;
				case 'N' :
					printf("( ");
					printf("%s ","!=");
					printTree(root->left);
					printTree(root->right);
					printf(") ");
					break;
				default:
					break;

			}
			break;
		case 1:
			printf("%d ",root->VALUE);
			break;
		case 2:
			printf("%s",root->NAME);
			if(root->center!=NULL){
				printf("-->");
				printTree(root->center);
			}else{
				printf(" ");
			}
			break;
		default:
			break;
	}
}

