%{
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

%}

%union {
	char* str;
	int num;
}

//token declaration
%token DECL ENDDECL SEMICOLON COMMA INTEGER BOOLEAN ID LSQUARE RSQUARE TRUE FALSE ADDRESSOF
%token MODULUS AND OR NOT READ WRITE IF ENDIF THEN ELSE WHILE NUMBER
%token EQUAL ASSIGN NEQUAL LESS_THAN LESS_EQUAL GREATER_THAN GREATER_EQ PLUS MINUS
%token MULT DIVIDE LPAREN RPAREN RFLOWER LFLOWER DO ENDWHILE PRINT BEGINN END RETURN RECORD MAIN


//precedence dcaration
%left OR
%left AND
%left NOT
%right  ASSIGN
%left  PLUS  MINUS
%left  MULT  DIVIDE  MODULUS

%%
body : Gdeclaration { printf("PARSING SUCCESS\n"); }
	| Gdeclaration  main_function { printf("PARSING SUCCESS\n"); }
	;
Gdeclaration : DECL GdeclStatements ENDDECL
	;
GdeclStatements : GdeclStatement
	| GdeclStatements GdeclStatement
	;
GdeclStatement : type Gvars SEMICOLON
	;
Gvars : Gvar
	| Gvars COMMA Gvar
	;
type : INTEGER
	| BOOLEAN
	;

Gvar : ID
	| ID LSQUARE NUMBER RSQUARE
	| ADDRESSOF ID
	;

main_function : INTEGER MAIN LPAREN RPAREN LFLOWER fbody RFLOWER
	;

fbody : declaration beginbody
	;

declaration : DECL declStatements ENDDECL
	;
declStatements : declStatement
	| declStatements declStatement
	;
declStatement : type vars SEMICOLON
	;
vars : var
	| vars COMMA var
	;

var : ID
	| ADDRESSOF ID

beginbody : BEGINN statements mreturn END
	;

statements : statement
	| statements statement
	;

statement : ifelse
	| dowhile
	| read
	| write
	| astatement
	;

ifelse : IF lexpression THEN statements ENDIF SEMICOLON
	| IF lexpression THEN statements ELSE statements ENDIF SEMICOLON
	;

dowhile : WHILE lexpression DO statements ENDWHILE SEMICOLON
	;

astatement : ID ASSIGN expression SEMICOLON
	;

read : READ LPAREN ID RPAREN SEMICOLON
	;

write : WRITE LPAREN aexpression RPAREN SEMICOLON
	;

mreturn : RETURN aexpression SEMICOLON
	;

expression : aexpression
	| lexpression
	;

aexpression : aexpression PLUS aexpression
	| aexpression MINUS aexpression
	| aexpression MULT aexpression
	| aexpression DIVIDE aexpression
	| aexpression MODULUS aexpression
	| LPAREN aexpression RPAREN
	| ID
	| NUMBER
	| ID LSQUARE aexpression RSQUARE
	;

lexpression : aexpression EQUAL aexpression
	| aexpression LESS_THAN aexpression
	| aexpression GREATER_THAN aexpression
	| aexpression GREATER_EQ aexpression
	| aexpression LESS_EQUAL aexpression
	| aexpression NEQUAL aexpression
	| lexpression AND lexpression
	| lexpression OR lexpression
	| NOT lexpression
	| LPAREN lexpression RPAREN
	| TRUE
	| FALSE
	;

%%

int main(){
	return(yyparse());
}

yyerror(s)
char *s;
{
  fprintf(stderr, "%s\n",s);
}
