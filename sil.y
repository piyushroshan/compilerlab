%{
char *language_string = "GNU C";
#include <stdio.h>
%}

%union
{
	int num;
	char* str;
}
%token DECL ENDDECL SEMICOLON COMMA INTEGER BOOLEAN ID LSQUARE RSQUARE TRUE FALSE ADDRESSOF 
%token MODULUS AND OR NOT READ WRITE IF ENDIF THEN ELSE WHILE NUMBER
%token EQUAL ASSIGN NEQUAL LESS_THAN LESS_EQUAL GREATER_THAN GREATER_EQ PLUS MINUS 
%token MULT DIVIDE LPAREN RPAREN RFLOWER LFLOWER DO ENDWHILE PRINT BEGINN END RETURN RECORD MAIN 
%right  ASSIGN
%left  PLUS  MINUS
%left  MULT  DIVIDE  MODULUS
%left OR
%left AND
%left NOT

%%
body : declaration { printf("PARSING SUCCESS\n"); }
	| declaration  main_function { printf("PARSING SUCCESS\n"); }
	| declaration functions main_function { printf("PARSING SUCCESS\n"); }
	;
declaration : DECL dstatemnts ENDDECL
	;
dstatemnts : dstatemnt 
	| dstatemnt dstatemnts 	
	;
dstatemnt : type dvars	
	; 
dvars : var SEMICOLON 
	| var COMMA dvars
	;
type : INTEGER 
	| BOOLEAN
	;
var : ID 
	| ID LSQUARE aexpression RSQUARE 
	| ID LPAREN parametr RPAREN
	| ADDRESSOF ID
	;

parametr :  
	|type plvars 
	;

plvars	: pvars SEMICOLON parametr
	| pvars
	;

pvars : ID COMMA pvars
	|ID 
	|ADDRESSOF ID
	|ADDRESSOF ID COMMA pvars
	;

functions : function 
	| functions function
	;

function : type ID LPAREN parametr RPAREN LFLOWER fbody RFLOWER
	;

main_function : INTEGER MAIN LPAREN RPAREN LFLOWER fbody RFLOWER
	;

fbody : declaration 
	| declaration bbody 
	;
	
bbody : BEGINN statements return END
	;

ifelse : IF lexpression THEN statements ENDIF SEMICOLON
	| IF lexpression THEN statements ELSE statements ENDIF SEMICOLON
	;

statement : ifelse
	| dowhile
	| read
	| write
	| astatement
	;

statements : statement 
	| statement statements
	;

dowhile : WHILE lexpression DO statements ENDWHILE SEMICOLON
	;

return : RETURN expression SEMICOLON
	;

astatement : ID ASSIGN expression SEMICOLON
	;

read : READ LPAREN ID RPAREN SEMICOLON
	;

write : WRITE LPAREN aexpression RPAREN SEMICOLON
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
