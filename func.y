%{
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
    int PASSTYPE;
    int VALUE;			/* for constants */
    char* NAME;			/* For Identifiers */
    struct	node 	*center, *left,	*right;
    struct ArgStruct *ARGLIST;
    struct Gsymbol *lookup;
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


int pcount=0; //count parameters

int returnmem = 4000;
int mem = 1000;
int argc = 0;
int fcount = 0;


//  Adding arguments
struct ArgStruct* headArg = NULL;
struct ArgStruct* newArg;


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
%type <n> return expression astatement  functions function exprList parametr PvarsList Pvar Fparametr FvarsList Pvars PvarsDef
%type <n> GdeclStatement Gvars type vars declStatement var Gvar FexprList

%%
program : /*Gdeclaration  main_function { printf("PARSING SUCCESS\n"); $$=$2; PrintSymbol(); printTree($2); Gen3A($2,0); print_TAlist(); codeGen();}
	| */
	Gdeclaration functions main_function { printf("PARSING SUCCESS\n"); }
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

parametr : {}
	|PvarsList { }
	;

Fparametr : {}
    | FvarsList { argInstall(headArg); }
    ;

FvarsList : FvarsList SEMICOLON PvarsDef
    | PvarsDef
    ;

PvarsList	: PvarsList SEMICOLON PvarsDef
    | PvarsDef
    ;

PvarsDef : type Pvars { }
    ;

Pvars : Pvars COMMA Pvar { makeArglist(headArg, newArg);	}
	| Pvar		{ makeArglist(headArg, newArg);	}
	;

Pvar : ID {
							newArg = malloc(sizeof(struct ArgStruct));
							newArg->ARGNAME = $1->NAME;
							newArg->ARGTYPE = TYPE;
							newArg->PASSTYPE = 0;
							newArg->ARGNEXT = NULL;
		}
	|ADDRESSOF ID  {
						    newArg = malloc(sizeof(struct ArgStruct));
							newArg->ARGNAME = $1->NAME;
							newArg->ARGTYPE = TYPE;
							newArg->PASSTYPE = 1;
							newArg->ARGNEXT = NULL;
	}
	;

functions : { $$ = NULL; }
	| functions function {  $$=CreateNode(0,'S', 0, NULL, $1, $2, NULL); if (($1==NULL || $1->TYPE == FUNC) && $2->TYPE== FUNC) $$->TYPE= FUNC; else $$->TYPE=-1; yyerror("Bad functions") ; }
	;

function : type ID LPAREN Fparametr RPAREN LFLOWER fbody RFLOWER {
																$$=CreateNode(0,'f', 0, $2->NAME, $4, $7, NULL);
																if($7->TYPE == TYPE) { $$->TYPE=FUNC; }else{ yyerror(" return type error"); $$->TYPE = -1;}
                                                                    fnDefCheck(TYPE, $2->NAME, headArg);
																}
	;

Gvar : ID {
            printf("*****offset of %s is %d\n",$1->NAME,Goffset);
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
                                printf("*****offset of %s[%d] is %d\n",$1->NAME,$3->VALUE,Goffset);
                                /*---------------------------------------------*/
                            }
    | ID LPAREN parametr RPAREN {
    								Ginstall($1->NAME, TYPE, 0, -1, 0, NULL);
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
                                	printf("*****offset of function %s is %d\n",$1->NAME,$3->VALUE,Goffset);
                                /*---------------------------------------------*/
    							}
    ;

main_function : INTEGER MAIN LPAREN RPAREN LFLOWER fbody RFLOWER {
                                                                    $$=CreateNode(0,'f', 0, "MAIN", NULL, $6, NULL);
                                                                    if($6->TYPE == INT) { $$->TYPE=0; }else{ yyerror(" return type error"); $$->TYPE = -1;}
                                                                }
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
        printf("*****L offset of %s is %d\n",$1->NAME,Loffset);
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

beginbody : BEGINN statements return END {  $$=CreateNode(0,'S', 0, NULL, $2, $3, NULL); if ($2==NULL || $2->TYPE==0) $$->TYPE=$3->TYPE; else {$$->TYPE=-1; yyerror("Bad begin error");} }
    ;

statements : { $$ = NULL; }
    | statements statement {  $$=CreateNode(0,'S', 0, NULL, $1, $2, NULL); if (($1==NULL || $1->TYPE==0) && $2->TYPE==0) $$->TYPE=0; else $$->TYPE=-1; yyerror("Bad statements");}
    ;

statement : ifelse { $$ = $1; }
    | dowhile { $$ = $1;}
    | read { $$ = $1;  }
    | write { $$ = $1;  }
    | astatement { $$ = $1;  }
    ;

ifelse : IF expression THEN statements ENDIF SEMICOLON { $1 = CreateNode(0,'I', 0, NULL, $4, $2, NULL); $$ = $1;
                                                if ($2->TYPE==2 && ($4==NULL || $4->TYPE==0)) $$->TYPE=0; else $$->TYPE=-1; yyerror("If type error");  }
    | IF expression THEN statements ELSE statements ENDIF SEMICOLON { $1 = CreateNode(0,'I', 0, NULL, $4, $2, $6); $$ = $1;
                                                if ($2->TYPE==2 && ($4==NULL || $4->TYPE==0) && ($6==NULL || $6->TYPE==0)) $$->TYPE=0; else $$->TYPE=-1; yyerror("If else error"); }
    ;

dowhile : WHILE expression DO statements ENDWHILE SEMICOLON { $1 = CreateNode(0,'W', 0, NULL, $4, $2, NULL); $$=$1; if ($2->TYPE==2 && ($4==NULL || $4->TYPE==0)) $$->TYPE=0; else $$->TYPE=-1; yyerror("while error"); }
    ;

astatement : ID ASSIGN expression SEMICOLON { $2 = CreateNode(0,'=', 0, NULL, $1, NULL, $3); $$=$2;
                                            struct Lsymbol* lt = Llookup($1->NAME);
                                            if(lt) { if (lt->TYPE == $3->TYPE ) $$->TYPE=0; }
                                            else {
                                                struct Gsymbol* gt = Glookup($1->NAME);
                                                if(gt) { if ( gt->SIZE==0 && (gt->TYPE == $3->TYPE )) $$->TYPE=0;
                                                else { $$->TYPE=-1;	yyerror("Wrong assignment");}}else { printf("ID %s not found\n",$1->NAME); yyerror(""); $$->TYPE=-1;}
                                            }}
    | ID LSQUARE expression RSQUARE ASSIGN expression SEMICOLON { $1->center = $3; $5 = CreateNode(0,'=', 0, NULL, $1, NULL, $6); $$=$5;
                                                                struct Gsymbol* gt = Glookup($1->NAME);
                                                                if(gt) {if ( gt->SIZE!=0 && $3->TYPE==INT && ((gt->TYPE-2) == $6->TYPE)) $$->TYPE=0; else { $$->TYPE=-1;
                                                                yyerror("Wrong assignment of array type");}} else {printf("Array %s not found\n",$1->NAME); yyerror(""); $$->TYPE=-1; }
                                                            }
    ;

read : READ LPAREN ID RPAREN SEMICOLON { $1 = CreateNode(0,'r', 0, NULL, NULL, $3, NULL); $$ = $1;
                                            struct Lsymbol* lt = Llookup($3->NAME);
                                            if(lt && (lt->TYPE == 1))
                                                $$->TYPE=0;
                                            else {
                                                struct Gsymbol* gt = Glookup($3->NAME);
                                                if(gt) {if( gt->SIZE==0 && gt->TYPE == 1 ) $$->TYPE=0; else { $$->TYPE=-1;
                                                yyerror("Read type error");}} else { printf("ID %s not found\n",$3->NAME); yyerror(""); $$->TYPE=-1;}
                                            }}
    | READ LPAREN ID LSQUARE expression RSQUARE RPAREN SEMICOLON { $3->center = $5;  $1 = CreateNode(0,'r', 0, NULL, NULL, $3, NULL); $$ = $1;
                                                struct Gsymbol* gt = Glookup($3->NAME);
                                                if(gt) { if(gt->SIZE!=0 && gt->TYPE==(INT+2) && $5->TYPE==1) $$->TYPE=0; else { $$->TYPE=-1;
                                                yyerror("Read type error");}} else { printf("ID %s not found\n",$3->NAME); yyerror(""); $$->TYPE=-1;}
                                            }
    ;

write : WRITE LPAREN expression RPAREN SEMICOLON { $1 = CreateNode(0,'w', 0, NULL, NULL, $3, NULL); $$ = $1;
                                                                            if($3->TYPE==1) $$->TYPE=0; else {$$->TYPE=-1; yyerror("Write error");} }
    ;

return : RETURN expression SEMICOLON { $1 = CreateNode(0,'R', 0, NULL, NULL, $2, NULL);  $$ = $1;
                                                                            if($2->TYPE==1) $$->TYPE=0; else {$$->TYPE=-1; yyerror("Return type nomatch");}}
    ;

expression : expression PLUS expression { $2 = CreateNode(0,'+', 0, NULL, $1, NULL, $3); $$ = $2; if($1->TYPE==1 && $3->TYPE ==1) $$->TYPE=1; else $$->TYPE=-1; yyerror("+ error"); }
    | expression MINUS expression { $2 = CreateNode(0,'-', 0, NULL, $1, NULL, $3); $$ = $2; if($1->TYPE==1 && $3->TYPE ==1) $$->TYPE=1; else $$->TYPE=-1; yyerror("- error");  }
    | expression MULT expression { $2 = CreateNode(0,'*', 0, NULL, $1, NULL, $3); $$ = $2; if($1->TYPE==1 && $3->TYPE ==1) $$->TYPE=1; else $$->TYPE=-1; yyerror("* error"); }
    | expression DIVIDE expression { $2 = CreateNode(0,'/', 0, NULL, $1, NULL, $3); $$ = $2;  if($1->TYPE==1 && $3->TYPE ==1) $$->TYPE=1; else $$->TYPE=-1; yyerror("/ error"); }
    | expression MODULUS expression { $2 = CreateNode(0,'%', 0, NULL, $1, NULL, $3); $$ = $2; if($1->TYPE==1 && $3->TYPE ==1) $$->TYPE=1; else $$->TYPE=-1; yyerror("%error"); }
    | expression EQUAL expression { $2 = CreateNode(0,'E', 0, NULL, $1, NULL, $3); $$ = $2; if($1->TYPE==1 && $3->TYPE ==1) $$->TYPE=2; else $$->TYPE=-1; yyerror("= error");  }
    | expression LESS_THAN expression { $2 = CreateNode(0,'<', 0, NULL, $1, NULL, $3); $$ = $2; if($1->TYPE==1 && $3->TYPE ==1) $$->TYPE=2; else $$->TYPE=-1; yyerror("< error"); }
    | expression GREATER_THAN expression { $2 = CreateNode(0,'>', 0, NULL, $1, NULL, $3); $$ = $2; if($1->TYPE==1 && $3->TYPE ==1) $$->TYPE=2; else $$->TYPE=-1; yyerror("> error"); }
    | expression GREATER_EQ expression { $2 = CreateNode(0,'G', 0, NULL, $1, NULL, $3); $$ = $2; if($1->TYPE==1 && $3->TYPE ==1) $$->TYPE=2; else $$->TYPE=-1; yyerror(">= error"); }
    | expression LESS_EQUAL expression { $2 = CreateNode(0,'L', 0, NULL, $1, NULL, $3); $$ = $2; if($1->TYPE==1 && $3->TYPE ==1) $$->TYPE=2; else $$->TYPE=-1; yyerror("<= error");  }
    | expression NEQUAL expression { $2 = CreateNode(0,'N', 0, NULL, $1, NULL, $3); $$ = $2; if($1->TYPE==1 && $3->TYPE ==1) $$->TYPE=2; else $$->TYPE=-1; yyerror("!= error");  }
    | expression AND expression { $2 = CreateNode(0,'&', 0, NULL, $1, NULL, $3); $$ = $2; if($1->TYPE==2 && $3->TYPE ==2) $$->TYPE=2; else $$->TYPE=-1; yyerror("& error"); }
    | expression OR expression { $2 = CreateNode(0,'|', 0, NULL, $1, NULL, $3); $$ = $2; if($1->TYPE==2 && $3->TYPE ==2) $$->TYPE=2; else $$->TYPE=-1; yyerror("| error"); }
    | NOT expression { $1 = CreateNode(0,'!', 0, NULL, NULL, $2, NULL); $$ = $1;  if($2->TYPE==2) $$->TYPE=2; else $$->TYPE=-1; yyerror("NOT error"); }
    | LPAREN expression RPAREN { $$ = $2; }
    | TRUE { $1 = CreateNode(2,'T', 0, NULL,NULL,NULL,NULL); $$ = $1;  }
    | FALSE { $1 = CreateNode(2,'F', 0, NULL, NULL, NULL, NULL); $$ = $1; }
    | NUMBER { $$=$1; }
    | ID { $$ = $1; struct Lsymbol* lt = Llookup($1->NAME); if(lt) $$->TYPE=lt->TYPE; else {
                                                            struct Gsymbol* gt = Glookup($1->NAME);
                                                            if(gt) {if(gt->SIZE==0) $$->TYPE=gt->TYPE; else $$->TYPE=-1; }
                                                            else { printf("ID %s not found\n",$1->NAME); yyerror(""); $$->TYPE=-1;}}}
    | ID LSQUARE expression RSQUARE {   $1->center = $3; $$ = $1;  struct Gsymbol* gt = Glookup($1->NAME);
                                                                    if(gt) { if(gt->SIZE!=0 && $3->TYPE==1)
                                                                    $$->TYPE=gt->TYPE; else $$->TYPE=-1; yyerror("array type expression"); }
                                                                    else { printf("Array %s not found\n",$1->NAME); yyerror(""); $$->TYPE=-1;}}
	| ID LPAREN FexprList RPAREN { struct Gsymbol* gtemp = Glookup($1->NAME);
                                    $$=CreateNode(0,'C', pcount, $1->NAME,NULL,$3,NULL);
                                    if(gtemp==NULL || gtemp->SIZE!=0) yyerror("Undefined Function");
                                    else
                                    {
                                        $$->lookup = gtemp;
                                        $$->TYPE = gtemp->TYPE;
                                    }
                                    struct ArgStruct* ARGLIST = gtemp->ARGLIST;
                                    struct node* ptemp=$3;
                                    while(true)
                                    {
                                        if(pcount>0 )
                                        {
                                            if(ptemp==NULL && ARGLIST)
                                            {
                                                yyerror("argument count error");
                                                break;
                                            }

                                            if(ARGLIST==NULL && ptemp)
                                            {
                                                yyerror("argument count error");
                                                break;
                                            }

                                            if(ARGLIST->TYPE == ptemp->left->TYPE)
                                            {
                                                if(ARGLIST->PASSTYPE == 1)
                                                {
                                                    if(ptemp->left->NODETYPE=='v')
                                                    {
                                                        ARGLIST=ARGLIST->ARGNEXT;
                                                        ptemp = ptemp->center;
                                                        pcount--;
                                                    }
                                                    else{
                                                        yyerror("argument type error");
                                                        break;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    pcount=0;
                            }
    ;

FexprList: { $$=NULL; }
        | exprList { $$ = $1; }
        ;

exprList : exprList COMMA expression { $$=CreateNode(0,',', 0, NULL,$1,$3,NULL); pcount++; }
		| expression { $$=$1; pcount++; }
		| ADDRESSOF ID { $$ = $1; $$->NODETYPE='v'; struct Lsymbol* lt = Llookup($1->NAME); if(lt) $$->TYPE=lt->TYPE; else {
                                                            struct Gsymbol* gt = Glookup($1->NAME);
                                                            if(gt) {if(gt->SIZE==0) $$->TYPE=gt->TYPE; else $$->TYPE=-1; }
                                                            else { printf("ID %s not found\n",$1->NAME); yyerror(""); $$->TYPE=-1;}}
                        }
		;

%%

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


void makeArglist(struct ArgStruct* head, struct ArgStruct* arg)
{
	if(headArg == NULL)
	 {
	 	headArg = arg;
	}
	else
	{
		struct ArgStruct* temp = head;
		while(temp->ARGNEXT!=NULL)
		{
			if(strcmp(temp->ARGNAME,arg->ARGNAME)==0)
			 {
			 	yyerror("Multiple Declaration of Arguments");
			 }
			temp = temp->ARGNEXT;
		}
		if(strcmp(temp->ARGNAME,arg->ARGNAME)==0)
		 {
		 	yyerror("Multiple Declaration of Arguments");
		 }
		temp->ARGNEXT = arg;
	}
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
		 	return 0;
		}
		else
		{
			if(strcmp(j->ARGNAME,i->ARGNAME)!=0 || i->ARGTYPE!=j->ARGTYPE )
			{
			return 0;
			}
			//Linstall(j->ARGNAME,j->ARGTYPE);
			i=i->ARGNEXT;
			j=j->ARGNEXT;

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

int argInstall(struct ArgStruct* head)
{
	struct ArgStruct* temp = head;
	memcount=-1;
	/*memcount starts at -3 for arguments, as -1: Return address and -2 Return value*/
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
                if(Llookup(root->NAME))
                    TAinstall('M',t,itoa(Llookup(root->NAME)->BINDING+GetGtableSize()),NULL);
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
            struct ArgStruct* args = gtemp->lookup;
            while(pc && temp)
            {
                if(args && args->ARGTYPE == gtemp->TYPE){
                char *t =(char *) malloc(5);
                t[0]='t';t[1]='\0';
                Gen3A(temp->center,0);
                strcat(t,itoa(current_temp));
                TAinstall('V',t,NULL,NULL);
                current_temp--;
                pc--;
                temp=temp->left;
                }
            }
            TAinstall('B',root->NAME,NULL,NULL);
            current_temp=ct;
            break;
        }
        case 'v':
        {
            current_temp++;
            t[0]='t';t[1]='\0';
            strcat(t,itoa(current_temp));
            if(Llookup(root->NAME))
                TAinstall('M',t,itoa(Llookup(root->NAME)->BINDING+GetGtableSize()),NULL);
            else
                TAinstall('M',t,itoa(Glookup(root->NAME)->BINDING),NULL);
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


