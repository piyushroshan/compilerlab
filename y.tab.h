/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
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

/* Line 2068 of yacc.c  */
#line 119 "func.y"

    struct node* n;



/* Line 2068 of yacc.c  */
#line 150 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


