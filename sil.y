%{
#include <stdio.h>
%}
%token DECL ENDDECL SEMICOLON COMMA INTEGER BOOLEAN ID LSQUARE RSQUARE TRUE FALSE ADDRESSOF 
%token MODULUS AND OR NOT READ WRITE IF THEN ELSE WHILE NUMBER
%token EQUAL ASSIGN NEQUAL LESS_THAN LESS_EQUAL GREATER_THAN GREATER_EQ PLUS MINUS 
%token MULT DIVIDE LPAREN RPAREN RFLOWER LFLOWER DO ENDWHILE PRINT BEGINN END RETURN RECORD
%%
body : declaration { printf("PARSING SUCCESS\n"); }
	| declaration functions { printf("PARSING SUCCESS\n"); }
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
	| ID LSQUARE NUMBER RSQUARE 
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
fbody : declaration 
	| declaration bbody 
	;
bbody : BEGINN  END
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
