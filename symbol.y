%{
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

struct Gsymbol {
	char *NAME; // Name of the Identifier
	int TYPE; // TYPE can be INTEGER or BOOLEAN
	/***The TYPE field must be a TypeStruct if user defined types are allowed***/
	int SIZE; // Size field for arrays
	int BINDING; // Address of the Identifier in Memory
	//ArgStruct *ARGLIST; // Argument List for functions

	/***Argstruct must store the name and type of each argument ***/
	struct Gsymbol *NEXT; // Pointer to next Symbol Table Entry */
} *Gnode;

struct Lsymbol {
	/* Here only name, type, binding and pointer to next entry needed */
	char *NAME; // Name of the Identifier
	int TYPE; // TYPE can be INTEGER or BOOLEAN
	/***The TYPE field must be a TypeStruct if user defined types are allowed***/
	int BINDING; // Address of the Identifier in Memory
	struct Lsymbol *NEXT; // Pointer to next Symbol Table Entry */
} *Lnode;



void printTree(struct node* root);
struct node* CreateNode(int TYPE1, int NODETYPE1, int VALUE1, char* NAME1, struct node *ptr1, struct node *ptr2, struct node *ptr3);
void Ginstall(char* NAME, int TYPE, int SIZE);
struct Gsymbol *Glookup(char* NAME);
struct Lsymbol *Llookup(char* NAME);
void Linstall(char* NAME, int TYPE);
int TYPE;

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
%}

%union {
	struct node* n;
}

//token declaration
%token <n> DECL ENDDECL SEMICOLON COMMA INTEGER BOOLEAN ID LSQUARE RSQUARE TRUE FALSE ADDRESSOF
%token <n> MODULUS AND OR NOT READ WRITE IF ENDIF THEN ELSE WHILE NUMBER
%token <n> EQUAL ASSIGN NEQUAL LESS_THAN LESS_EQUAL GREATER_THAN GREATER_EQ PLUS MINUS
%token <n> MULT DIVIDE LPAREN RPAREN RFLOWER LFLOWER DO ENDWHILE BEGINN END RETURN MAIN


//precedence dcaration
%left COMMA
%right  ASSIGN
%left AND OR
%left EQUAL NEQUAL
%left LESS_THAN LESS_EQUAL GREATER_THAN GREATER_EQ
%right NOT
%left LPAREN RPAREN LSQUARE RSQUARE

%left  PLUS  MINUS
%left  MULT  DIVIDE  MODULUS

%type <n> program main_function fbody beginbody statements statement ifelse dowhile read write
%type <n> return expression aexpression lexpression astatement
%type <n> GdeclStatement Gvars type vars declStatement var Gvar

%%
program : Gdeclaration  main_function { printf("PARSING SUCCESS\n"); $$=$2; PrintSymbol();}
	;
Gdeclaration : DECL GdeclStatements ENDDECL
	;
GdeclStatements : {/*empty*/}
	| GdeclStatements GdeclStatement
	;
GdeclStatement : type Gvars SEMICOLON
	;
Gvars : Gvar 
	| Gvars COMMA Gvar 
	;
type : INTEGER { TYPE = 1; }
	| BOOLEAN {TYPE=2; }
	;

Gvar : ID { Ginstall($1->NAME, TYPE, 0); }
	| ID LSQUARE NUMBER RSQUARE { Ginstall($1->NAME, TYPE, $3->VALUE); }
	;

main_function : INTEGER MAIN LPAREN RPAREN LFLOWER fbody RFLOWER { $$=CreateNode(0,'f', 0, "MAIN", NULL, $6, NULL);}
	;

fbody : declaration beginbody  { $$=$2; }
	;

declaration : DECL declStatements ENDDECL
	;
declStatements : {/*empty*/}
	| declStatements declStatement
	;
declStatement : type vars SEMICOLON 
	;
vars : var
	| vars COMMA var
	;

var : ID { Linstall($1->NAME, TYPE); } 
	;

beginbody : BEGINN statements return END {  $$=CreateNode(0,'S', 0, NULL, $2, $3, NULL);}
	;

statements : { $$ = NULL; }
    | statements statement {  $$=CreateNode(0,'S', 0, NULL, $2, $1, NULL); }
	;

statement : ifelse { $$ = $1; }
	| dowhile { $$ = $1; }
	| read { $$ = $1; }
	| write { $$ = $1; }
	| astatement { $$ = $1; }
	;

ifelse : IF lexpression THEN statements ENDIF SEMICOLON { $1 = CreateNode(0,'I', 0, NULL, $4, $2, NULL); $$ = $1; }
	| IF lexpression THEN statements ELSE statements ENDIF SEMICOLON { $1 = CreateNode(0,'I', 0, NULL, $4, $2, $6); $$ = $1; }
	;

dowhile : WHILE lexpression DO statements ENDWHILE SEMICOLON { $1 = CreateNode(0,'W', 0, NULL, $4, $2, NULL); $$=$1; }
	;

astatement : ID ASSIGN expression SEMICOLON { $2 = CreateNode(0,'=', 0, NULL, $1, NULL, $3); $$=$2; }
	| ID LSQUARE aexpression RSQUARE ASSIGN expression SEMICOLON { $1->center = $3; $5 = CreateNode(0,'=', 0, NULL, $1, NULL, $6); $$=$5;  }
	;

read : READ LPAREN ID RPAREN SEMICOLON { $1 = CreateNode(0,'r', 0, NULL, NULL, $3, NULL); $$ = $1; }
	| READ LPAREN ID LSQUARE aexpression RSQUARE RPAREN SEMICOLON { $3->center = $5;  $1 = CreateNode(0,'r', 0, NULL, NULL, $3, NULL); $$ = $1; }
	;

write : WRITE LPAREN aexpression RPAREN SEMICOLON { $1 = CreateNode(0,'w', 0, NULL, NULL, $3, NULL); $$ = $1; }
	;

return : RETURN expression SEMICOLON { $1 = CreateNode(0,'R', 0, NULL, NULL, $2, NULL); $$ = $1; }
	;

expression : aexpression PLUS aexpression { $2 = CreateNode(0,'+', 0, NULL, $1, NULL, $3); $$ = $2; }
	| aexpression MINUS aexpression { $2 = CreateNode(0,'-', 0, NULL, $1, NULL, $3); $$ = $2; }
	| aexpression MULT aexpression { $2 = CreateNode(0,'*', 0, NULL, $1, NULL, $3); $$ = $2; }
	| aexpression DIVIDE aexpression { $2 = CreateNode(0,'/', 0, NULL, $1, NULL, $3); $$ = $2; }
	| aexpression MODULUS aexpression { $2 = CreateNode(0,'%', 0, NULL, $1, NULL, $3); $$ = $2; }
	| LPAREN aexpression RPAREN { $$=$2; }
	| NUMBER { $$=$1; }
	| aexpression EQUAL aexpression { $2 = CreateNode(0,'E', 0, NULL, $1, NULL, $3); $$ = $2; }
	| aexpression LESS_THAN aexpression { $2 = CreateNode(0,'<', 0, NULL, $1, NULL, $3); $$ = $2; }
	| aexpression GREATER_THAN aexpression { $2 = CreateNode(0,'>', 0, NULL, $1, NULL, $3); $$ = $2; }
	| aexpression GREATER_EQ aexpression { $2 = CreateNode(0,'G', 0, NULL, $1, NULL, $3); $$ = $2; }
	| aexpression LESS_EQUAL aexpression { $2 = CreateNode(0,'L', 0, NULL, $1, NULL, $3); $$ = $2; }
	| aexpression NEQUAL aexpression { $2 = CreateNode(0,'N', 0, NULL, $1, NULL, $3); $$ = $2; }
	| lexpression AND lexpression { $2 = CreateNode(0,'&', 0, NULL, $1, NULL, $3); $$ = $2; }
	| lexpression OR lexpression { $2 = CreateNode(0,'|', 0, NULL, $1, NULL, $3); $$ = $2; }
	| NOT lexpression { $1 = CreateNode(0,'!', 0, NULL, NULL, $2, NULL); $$ = $1; }
	| LPAREN lexpression RPAREN { $$ = $2; }
	| TRUE { $1 = CreateNode(0,'T', 0, NULL,NULL,NULL,NULL); $$ = $1; }
	| FALSE { $1 = CreateNode(0,'F', 0, NULL, NULL, NULL, NULL); $$ = $1; }
	| ID { $$=$1; }
	| ID LSQUARE aexpression RSQUARE {   $1->center = $3; $$ = $1;}
	;

aexpression : aexpression PLUS aexpression { $2 = CreateNode(0,'+', 0, NULL, $1, NULL, $3); $$ = $2; }
	| aexpression MINUS aexpression { $2 = CreateNode(0,'-', 0, NULL, $1, NULL, $3); $$ = $2; }
	| aexpression MULT aexpression { $2 = CreateNode(0,'*', 0, NULL, $1, NULL, $3); $$ = $2; }
	| aexpression DIVIDE aexpression { $2 = CreateNode(0,'/', 0, NULL, $1, NULL, $3); $$ = $2; }
	| aexpression MODULUS aexpression { $2 = CreateNode(0,'%', 0, NULL, $1, NULL, $3); $$ = $2; }
	| LPAREN aexpression RPAREN { $$ = $2; }
	| NUMBER { $$ = $1; }
	| ID { $$ = $1; }
	| ID LSQUARE aexpression RSQUARE {   $1->center = $3; $$ = $1;}
	;

lexpression : aexpression EQUAL aexpression { $2 = CreateNode(0,'E', 0, NULL, $1, NULL, $3); $$ = $2; }
	| aexpression LESS_THAN aexpression { $2 = CreateNode(0,'<', 0, NULL, $1, NULL, $3); $$ = $2; }
	| aexpression GREATER_THAN aexpression { $2 = CreateNode(0,'>', 0, NULL, $1, NULL, $3); $$ = $2; }
	| aexpression GREATER_EQ aexpression { $2 = CreateNode(0,'G', 0, NULL, $1, NULL, $3); $$ = $2; }
	| aexpression LESS_EQUAL aexpression { $2 = CreateNode(0,'L', 0, NULL, $1, NULL, $3); $$ = $2; }
	| aexpression NEQUAL aexpression { $2 = CreateNode(0,'N', 0, NULL, $1, NULL, $3); $$ = $2; }
	| lexpression AND lexpression { $2 = CreateNode(0,'&', 0, NULL, $1, NULL, $3); $$ = $2; }
	| lexpression OR lexpression { $2 = CreateNode(0,'|', 0, NULL, $1, NULL, $3); $$ = $2; }
	| NOT lexpression { $1 = CreateNode(0,'!', 0, NULL, NULL, $2, NULL); $$ = $1; }
	| LPAREN lexpression RPAREN { $$ = $2; }
	| TRUE { $1 = CreateNode(0,'T', 0, NULL,NULL,NULL,NULL); $$ = $1; }
	| FALSE { $1 = CreateNode(0,'F', 0, NULL, NULL, NULL, NULL); $$ = $1; }
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



