%{
char *language_string = "GNU C";
#include <stdio.h>

struct node
{
	int TYPE;
	int NODETYPE;
	int VALUE;
	struct node *left,*right;
};


%}



%union
{
	int num;
	char* str;
	struct node* n;
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

%type<n> expression NUMBER PLUS
%%


program : expression {   printf ("\n PArsing SHSlkjHKfd \n");
								postfix($1);
						}
	;
expression : NUMBER { $$=$1;}
	| expression PLUS expression {  $$=$2; $$->left=$1;
										$$->right=$3;
													}
	;
%%


int main(){
	return(yyparse());
}

void postfix(struct node* root)
{
	if(root==NULL) {
		return;
	} else {
		postfix(root->left);
		postfix(root->right);
		switch(root->NODETYPE ) {
			case 0 :
				printf("%d ",root->VALUE);
				break;
			case 1 :
				printf("%c ",'+');
				break;
		}
	}
}

yyerror(s)
char *s;
{
  fprintf(stderr, "%s\n",s);
}
