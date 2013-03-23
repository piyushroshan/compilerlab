%{
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linklist.h"
#define INT 1
#define BOOL 2
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



void printTree(struct node* root);
struct node* CreateNode(int TYPE1, int NODETYPE1, int VALUE1, char* NAME1, struct node *ptr1, struct node *ptr2, struct node *ptr3);
void Ginstall(char* NAME, int TYPE, int SIZE, int BINDING, int VALUE, struct ArgStruct* ARGLIST);
struct Gsymbol *Glookup(char* NAME);
struct Lsymbol *Llookup(char* NAME);
void Linstall(char* NAME, int TYPE, int BINDING, int VALUE);
void TAinstall(char op, char* op1, char* op2);
void print_TAlist();
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
%type <n> return expression expression expression astatement
%type <n> GdeclStatement Gvars type vars declStatement var Gvar

%%
program : Gdeclaration  main_function { printf("PARSING SUCCESS\n"); $$=$2; PrintSymbol(); printTree($2); Gen3A($2); print_TAlist();}
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
type : INTEGER { TYPE = INT; }
    | BOOLEAN {TYPE = BOOL; }
    ;

Gvar : ID {
            printf("*****offset of %s is %d\n",$1,Goffset);
            Ginstall($1->NAME, TYPE, 0, Goffset, 0, NULL);
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
    | ID LSQUARE NUMBER RSQUARE {
                                Ginstall($1->NAME, TYPE+2, $3->VALUE, Goffset, 0, NULL);
                                /*-----------Code Generation-------------------*/
                                switch(TYPE)
                                {
                                    case INT :
                                        Goffset += SIZEOFINT*$3->VALUE;
                                        break;
                                    case BOOL :
                                        Goffset += SIZEOFBOOL*$3->VALUE;
                                        break;
                                }
                                /*---------------------------------------------*/
                            }
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

var : ID {
        printf("*****L offset of %s is %d\n",$1,Loffset);
        Linstall($1->NAME, TYPE, Loffset, 0);
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
    ;

beginbody : BEGINN statements END {  $$=CreateNode(0,'S', 0, NULL, $2, NULL, NULL); if (($2==NULL || $2->TYPE==0) && $3->TYPE==0) $$->TYPE=0; else $$->TYPE=-1; }
    ;

statements : { $$ = NULL; }
    | statements statement {  $$=CreateNode(0,'S', 0, NULL, $1, $2, NULL); if (($1==NULL || $1->TYPE==0) && $2->TYPE==0) $$->TYPE=0; else $$->TYPE=-1;}
    ;

statement : ifelse { $$ = $1; }
    | dowhile { $$ = $1;}
    | read { $$ = $1;  }
    | write { $$ = $1;  }
    | astatement { $$ = $1;  }
    ;

ifelse : IF expression THEN statements ENDIF SEMICOLON { $1 = CreateNode(0,'I', 0, NULL, $4, $2, NULL); $$ = $1;
                                                if ($2->TYPE==2 && ($4==NULL || $4->TYPE==0)) $$->TYPE=0; else $$->TYPE=-1;  }
    | IF expression THEN statements ELSE statements ENDIF SEMICOLON { $1 = CreateNode(0,'I', 0, NULL, $4, $2, $6); $$ = $1;
                                                if ($2->TYPE==2 && ($4==NULL || $4->TYPE==0) && ($6==NULL || $6->TYPE==0)) $$->TYPE=0; else $$->TYPE=-1; }
    ;

dowhile : WHILE expression DO statements ENDWHILE SEMICOLON { $1 = CreateNode(0,'W', 0, NULL, $4, $2, NULL); $$=$1; if ($2->TYPE==2 && ($4==NULL || $4->TYPE==0)) $$->TYPE=0; else $$->TYPE=-1; }
    ;

astatement : ID ASSIGN expression SEMICOLON { $2 = CreateNode(0,'=', 0, NULL, $1, NULL, $3); $$=$2;
                                            struct Lsymbol* lt = Llookup($1->NAME);
                                            if(lt) { if (lt->TYPE == $3->TYPE ) $$->TYPE=0; }
                                            else {
                                                struct Gsymbol* gt = Glookup($1->NAME);
                                                if(gt) { if ( gt->SIZE==0 && (gt->TYPE == $3->TYPE )) $$->TYPE=0;
                                                else { $$->TYPE=-1;	yyerror("Wrong assignment");}}else { printf("ID %s not found\n",$1->NAME); $$->TYPE=-1;}
                                            }}
    | ID LSQUARE expression RSQUARE ASSIGN expression SEMICOLON { $1->center = $3; $5 = CreateNode(0,'=', 0, NULL, $1, NULL, $6); $$=$5;
                                                                struct Gsymbol* gt = Glookup($1->NAME);
                                                                if(gt) {if ( gt->SIZE!=0 && $3->TYPE==INT && ((gt->TYPE-2) == $6->TYPE)) $$->TYPE=0; else { $$->TYPE=-1;
                                                                yyerror("Wrong assignment of array type");}} else {printf("Array %s not found\n",$1->NAME); $$->TYPE=-1; }
                                                            }
    ;

read : READ LPAREN ID RPAREN SEMICOLON { $1 = CreateNode(0,'r', 0, NULL, NULL, $3, NULL); $$ = $1;
                                            struct Lsymbol* lt = Llookup($3->NAME);
                                            if(lt && (lt->TYPE == 1))
                                                $$->TYPE=0;
                                            else {
                                                struct Gsymbol* gt = Glookup($3->NAME);
                                                if(gt) {if( gt->SIZE==0 && gt->TYPE == 1 ) $$->TYPE=0; else { $$->TYPE=-1;
                                                yyerror("Read type error");}} else { printf("ID %s not found\n",$3->NAME); $$->TYPE=-1;}
                                            }}
    | READ LPAREN ID LSQUARE expression RSQUARE RPAREN SEMICOLON { $3->center = $5;  $1 = CreateNode(0,'r', 0, NULL, NULL, $3, NULL); $$ = $1;
                                                struct Gsymbol* gt = Glookup($3->NAME);
                                                if(gt) { if(gt->SIZE!=0 && gt->TYPE==(INT+2) && $5->TYPE==1) $$->TYPE=0; else { $$->TYPE=-1;
                                                yyerror("Read type error");}} else { printf("ID %s not found\n",$3->NAME); $$->TYPE=-1;}
                                            }
    ;

write : WRITE LPAREN expression RPAREN SEMICOLON { $1 = CreateNode(0,'w', 0, NULL, NULL, $3, NULL); $$ = $1;
                                                                            if($3->TYPE==1) $$->TYPE=0; else {$$->TYPE=-1; yyerror("Write error");} }
    ;

return : RETURN expression SEMICOLON { $1 = CreateNode(0,'R', 0, NULL, NULL, $2, NULL);  $$ = $1;
                                                                            if($2->TYPE==1) $$->TYPE=0; else {$$->TYPE=-1; yyerror("Return type nomatch");}}
    ;

expression : expression PLUS expression { $2 = CreateNode(0,'+', 0, NULL, $1, NULL, $3); $$ = $2; if($1->TYPE==1 && $3->TYPE ==1) $$->TYPE=1; else $$->TYPE=-1; }
    | expression MINUS expression { $2 = CreateNode(0,'-', 0, NULL, $1, NULL, $3); $$ = $2; if($1->TYPE==1 && $3->TYPE ==1) $$->TYPE=1; else $$->TYPE=-1;  }
    | expression MULT expression { $2 = CreateNode(0,'*', 0, NULL, $1, NULL, $3); $$ = $2; if($1->TYPE==1 && $3->TYPE ==1) $$->TYPE=1; else $$->TYPE=-1;  }
    | expression DIVIDE expression { $2 = CreateNode(0,'/', 0, NULL, $1, NULL, $3); $$ = $2;  if($1->TYPE==1 && $3->TYPE ==1) $$->TYPE=1; else $$->TYPE=-1; }
    | expression MODULUS expression { $2 = CreateNode(0,'%', 0, NULL, $1, NULL, $3); $$ = $2; if($1->TYPE==1 && $3->TYPE ==1) $$->TYPE=1; else $$->TYPE=-1;  }
    | expression EQUAL expression { $2 = CreateNode(0,'E', 0, NULL, $1, NULL, $3); $$ = $2; if($1->TYPE==1 && $3->TYPE ==1) $$->TYPE=2; else $$->TYPE=-1;  }
    | expression LESS_THAN expression { $2 = CreateNode(0,'<', 0, NULL, $1, NULL, $3); $$ = $2; if($1->TYPE==1 && $3->TYPE ==1) $$->TYPE=2; else $$->TYPE=-1;  }
    | expression GREATER_THAN expression { $2 = CreateNode(0,'>', 0, NULL, $1, NULL, $3); $$ = $2; if($1->TYPE==1 && $3->TYPE ==1) $$->TYPE=2; else $$->TYPE=-1;  }
    | expression GREATER_EQ expression { $2 = CreateNode(0,'G', 0, NULL, $1, NULL, $3); $$ = $2; if($1->TYPE==1 && $3->TYPE ==1) $$->TYPE=2; else $$->TYPE=-1;  }
    | expression LESS_EQUAL expression { $2 = CreateNode(0,'L', 0, NULL, $1, NULL, $3); $$ = $2; if($1->TYPE==1 && $3->TYPE ==1) $$->TYPE=2; else $$->TYPE=-1;  }
    | expression NEQUAL expression { $2 = CreateNode(0,'N', 0, NULL, $1, NULL, $3); $$ = $2; if($1->TYPE==1 && $3->TYPE ==1) $$->TYPE=2; else $$->TYPE=-1;  }
    | expression AND expression { $2 = CreateNode(0,'&', 0, NULL, $1, NULL, $3); $$ = $2; if($1->TYPE==2 && $3->TYPE ==2) $$->TYPE=2; else $$->TYPE=-1;  }
    | expression OR expression { $2 = CreateNode(0,'|', 0, NULL, $1, NULL, $3); $$ = $2; if($1->TYPE==2 && $3->TYPE ==2) $$->TYPE=2; else $$->TYPE=-1;  }
    | NOT expression { $1 = CreateNode(0,'!', 0, NULL, NULL, $2, NULL); $$ = $1;  if($2->TYPE==2) $$->TYPE=2; else $$->TYPE=-1; }
    | LPAREN expression RPAREN { $$ = $2; }
    | TRUE { $1 = CreateNode(2,'T', 0, NULL,NULL,NULL,NULL); $$ = $1;  }
    | FALSE { $1 = CreateNode(2,'F', 0, NULL, NULL, NULL, NULL); $$ = $1; }
    | NUMBER { $$=$1; }
    | ID { $$ = $1; struct Lsymbol* lt = Llookup($1->NAME); if(lt) $$->TYPE=lt->TYPE; else {
                                                            struct Gsymbol* gt = Glookup($1->NAME);
                                                            if(gt) {if(gt->SIZE==0) $$->TYPE=gt->TYPE; else $$->TYPE=-1; }
                                                            else { printf("ID %s not found\n",$1->NAME); $$->TYPE=-1;}}}
    | ID LSQUARE expression RSQUARE {   $1->center = $3; $$ = $1;  struct Gsymbol* gt = Glookup($1->NAME);
                                                                    if(gt) { if(gt->SIZE!=0 && $3->TYPE==1)
                                                                    $$->TYPE=gt->TYPE; else $$->TYPE=-1; }
                                                                    else { printf("Array %s not found\n",$1->NAME); $$->TYPE=-1;}}
    ;


%%

int main(){
    Goffset = 0;

    yyparse();
    /*printf("\nSTART\n");
		printf("MOV R1,%d\n",Goffset-1);
		printf("INR R1\n");
		printf("MOV SP,R1\n");
		printf("MOV %s,SP\n",reg3);
		printf("MOV %s,%d\n",reg4,l_getarglocalsize(gtable,"main"));
		printf("ADD %s,%s\n",reg3,reg4);
		printf("MOV SP,%s\n",reg3);
		printf("CALL Pmain\n");
		printf("MOV %s,SP\n",reg3);
		printf("MOV %s,%d\n",reg4,l_getarglocalsize(gtable,"main"));
		printf("SUB %s,%s\n",reg3,reg4);
		printf("MOV SP,%s\n",reg3);
		printf("MOV R1,%d\n",Goffset-1);
		printf("HALT\n");*/
}

/*char* newreg3()
{
	char *temp =(char *) malloc(5);
	temp[0]='R';temp[1]='\0';
	for(int i=2;i<100;i++)
	{
		temp[0]='R';temp[1]='\0';
		strcat(temp,itoa(i));
		if(reglist.member(temp)==-1)
		{
			printf("//Allocated from here\n");
			return temp;
		}
	}
	strcat(temp,itoa(current_reg));
	current_reg++;

	//printf("*********Newreg %s\n",temp);
	return temp;
}

char* newreg()
{
	char *temp =(char *) malloc(5);
	temp[0]='R';temp[1]='\0';
	strcat(temp,itoa(current_reg));
	current_reg++;

	//printf("*********Newreg %s\n",temp);
	return temp;
}

char* newlabel()
{
	static int current = 0;
	current++;
	char *temp =(char *) malloc(5);
	temp[0]='L';temp[1]='\0';
	strcat(temp,itoa(current));

	//printf("Newlabel %s\n",temp);
	return temp;
}*/

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
    static int num = 1;
    char* label="L";
    strcat(label,itoa(num));
    num++;
    return label;
}

void Gen3A(struct node* root){
    if(root==NULL){
        return;
    }

    switch(root->NODETYPE){
        case 'f' :
            TAinstall('L',root->NAME,NULL);
            Gen3A(root->center);
            break;
        case 'S':
            Gen3A(root->left);
            Gen3A(root->center);
            break;
        case 'I':{
            char* label=newlabel();
            Gen3A(root->center);
            char* t = "t";
            strcat(t,itoa(current_temp));
            TAinstall('I',t,label);
            Gen3A(root->left);

            if(root->right){
                char* endif = newlabel();
                TAinstall('G',endif,NULL);
                TAinstall('L',label,NULL);
                Gen3A(root->right);
                TAinstall('L',endif,NULL);
            }else{
                TAinstall('L',label,NULL);
            }
            break;
            }
        case 'W':{
            char* l1=newlabel();
            char* l2=newlabel();
            TAinstall('L',l1,NULL);
            Gen3A(root->center);
            char* t = "t";
            strcat(t,itoa(current_temp));
            TAinstall('I',t,l2);
            Gen3A(root->left);
            TAinstall('G',l1,NULL);
            TAinstall('L',l2,NULL);
            break;
            }
        case 'r':
            {
            Gen3A(root->center);
            char* t = "t";
            strcat(t,itoa(current_temp));
            TAinstall('r',t,NULL);
            break;
            }
        case 'w':
            {
            Gen3A(root->center);
            char* t = "t";
            strcat(t,itoa(current_temp));
            TAinstall('w',t,NULL);
            break;
            }
        case 'R':
            {
            Gen3A(root->center);
            char* t = "t";
            strcat(t,itoa(current_temp));
            TAinstall('R',t,NULL);
            break;
            }
        case '=':
            {
            Gen3A(root->left);
            char* t1 = "t";
            strcat(t1,itoa(current_temp));
            Gen3A(root->right);
            char* t2 = "t";
            strcat(t2,itoa(current_temp));
            TAinstall('=',t1,t2);
            break;
            }
        case '+':
            {
            Gen3A(root->left);
            Gen3A(root->right);
            char* t1 = "t";
            strcat(t1,itoa(current_temp-2));
            char* t2 = "t";
            strcat(t2,itoa(current_temp-1));
            TAinstall('+', t1, t2);
            current_temp--;
            break;
            }
        case '-':
            {
            Gen3A(root->left);
            char* t1 = "t";
            strcat(t1,itoa(current_temp));
            Gen3A(root->right);
            char* t2 = "t";
            strcat(t2,itoa(current_temp));
            TAinstall('-', t1, t2);
            break;
            }
        case '*':
            {
            Gen3A(root->left);
            char* t1 = "t";
            strcat(t1,itoa(current_temp));
            Gen3A(root->right);
            char* t2 = "t";
            strcat(t2,itoa(current_temp));
            TAinstall('*', t1, t2);
            break;
            }
        case '/':
            {
            Gen3A(root->left);
            char* t1 = "t";
            strcat(t1,itoa(current_temp));
            Gen3A(root->right);
            char* t2 = "t";
            strcat(t2,itoa(current_temp));
            TAinstall('/', t1, t2);
            break;
            }
        case '%':
            {
            Gen3A(root->left);
            char* t1 = "t";
            strcat(t1,itoa(current_temp));
            Gen3A(root->right);
            char* t2 = "t";
            strcat(t2,itoa(current_temp));
            TAinstall('%', t1, t2);
            break;
            }
        case 'T' :
            {
            current_temp++;
            char* t = "t";
            strcat(t,itoa(current_temp));
            TAinstall('=',t,"T");
            break;
            }
        case 'F' :
            {
            current_temp++;
            char* t = "t";
            strcat(t,itoa(current_temp));
            TAinstall('=',t,"F");
            break;
            }
        case 1:
            {
            current_temp++;
            char* t = "t";
            strcat(t,itoa(current_temp));
            TAinstall('=',t,itoa(root->VALUE));
            break;
            }
        case 2:
            {
            if(root->center){
                Gen3A(root->center);
                char* t = "t";
                strcat(t,itoa(current_temp));
                TAinstall('l',root->NAME,t);
                current_temp++;
                char* t1 = "t";
                strcat(t1,itoa(current_temp));
                TAinstall('=',t1,t);
            }else
            {
                char* t = "t";
                strcat(t,itoa(current_temp));
                if(Glookup(root->NAME))
                    TAinstall('l',t,Glookup(root->NAME)->BINDING);
                else
                    TAinstall('l',t,Llookup(root->NAME)->BINDING);
            }
            break;
            }
        default:
        {
            Gen3A(root->center);
            Gen3A(root->left);
            Gen3A(root->right);
        }
            break;
    }
}

yyerror(s)
char *s;
{
fprintf(stderr, "%s\n",s);
}


