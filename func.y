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
int SP;
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
    struct Lsymbol *lookup;
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
    struct Lsymbol *LTABLE;
    /***Argstruct must store the name and type of each argument ***/
    struct Gsymbol *NEXT; // Pointer to next Symbol Table Entry */
} *Gnode;

struct Lsymbol {
    /* Here only name, type, binding and pointer to next entry needed */
    char *NAME; // Name of the Identifier
    int TYPE; // TYPE can be INTEGER or BOOLEAN
    /***The TYPE field must be a TypeStruct if user defined types are allowed***/
    int VALUE; // for constants
    int PASSTYPE;
    int BINDING; // Address of the Identifier in Memory
    struct Lsymbol *NEXT; // Pointer to next Symbol Table Entry */
};

int GetGtableSize();
void printTree(struct node* root);
struct node* CreateNode(int TYPE1, int NODETYPE1, int VALUE1, char* NAME1, struct node *ptr1, struct node *ptr2, struct node *ptr3);
void Ginstall(char* NAME, int TYPE, int SIZE, int BINDING, int VALUE, struct ArgStruct* ARGLIST, struct Lsymbol* LTABLE);
struct Gsymbol *Glookup(char* NAME);
struct Lsymbol *Llookup(char* NAME, struct Lsymbol* Lnode);
struct Lsymbol* Linstall(char* NAME, int TYPE, int BINDING, int VALUE, int PASSTYPE, struct Lsymbol* Lnode);
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
int Loffset = 0;
char* fname;
//  Adding arguments
struct ArgStruct* headArg = NULL;
struct ArgStruct* headArg2 = NULL;
struct ArgStruct* newArg;
struct Lsymbol* Lnode = NULL;

void PrintSymbol(){
    struct Gsymbol *Gtemp = Gnode;
    while(Gtemp != NULL){
        printf("%s --> %d ",Gtemp->NAME,Gtemp->TYPE) ;
        Gtemp =Gtemp->NEXT;
    }
    printf("\n");
    printf("\n");
}

void PrintLSymbol(struct Lsymbol *Lnode){
    struct Lsymbol *Ltemp = Lnode;
    while(Ltemp != NULL){
        printf("%s --> %d ",Ltemp->NAME,Ltemp->TYPE) ;
        Ltemp =Ltemp->NEXT;
    }
    printf("\n");
    printf("\n");
}

void makeArglist(struct ArgStruct* arg);
void makeArglist2(struct ArgStruct* arg);
void printArg(struct ArgStruct* head);
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
%type <n> return expression astatement  functions function exprList parametr PvarsList Pvar Fparametr FvarsList Pvars PvarsDef ftype declaration declStatements
%type <n> GdeclStatement Gvars type vars declStatement var Gvar FexprList FvarsDef Fvars Fvar

%%
program : /*Gdeclaration  main_function { printf("PARSING SUCCESS\n"); $$=$2; PrintSymbol(); printTree($2); Gen3A($2,0); print_TAlist(); codeGen();}
	| */
	Gdeclaration functions main_function { printf("PARSING SUCCESS\n"); $$=CreateNode(0,'S', 0, NULL, $2, $3, NULL); PrintSymbol(); printTree($$); Gen3A($$,0); print_TAlist();codeGen(); }
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
ftype : INTEGER { FTYPE = INT; }
    | BOOLEAN {FTYPE = BOOL; }
    ;

parametr : {}
	|PvarsList { }
	;

Fparametr : {}
    | FvarsList
    ;

FvarsList : FvarsList SEMICOLON FvarsDef
    | FvarsDef
    ;

FvarsDef : type Fvars
    ;

Fvars : Fvars COMMA Fvar { makeArglist2(newArg);    }
	| Fvar { makeArglist2(newArg);  }
	;

Fvar : ID {
                            newArg = malloc(sizeof(struct ArgStruct));
                            newArg->ARGNAME = $1->NAME;
                            newArg->ARGTYPE = TYPE;
                            newArg->PASSTYPE = 0;
                            newArg->ARGNEXT = NULL;
        }
    |ADDRESSOF ID  {
                             newArg = malloc(sizeof(struct ArgStruct));
                            newArg->ARGNAME = $2->NAME;
                            newArg->ARGTYPE = TYPE;
                            newArg->PASSTYPE = 1;
                            newArg->ARGNEXT = NULL;
    }
    ;
PvarsList	: PvarsList SEMICOLON PvarsDef
    | PvarsDef
    ;

PvarsDef : type Pvars { }
    ;

Pvars : Pvars COMMA Pvar { makeArglist(newArg);	}
	| Pvar		{ makeArglist(newArg);	}
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
							newArg->ARGNAME = $2->NAME;
							newArg->ARGTYPE = TYPE;
							newArg->PASSTYPE = 1;
							newArg->ARGNEXT = NULL;
	}
	;



Gvar : ID {
            printf("*****offset of %s is %d\n",$1->NAME,Goffset);
            Ginstall($1->NAME, TYPE, 0, Goffset, 0, NULL,NULL);
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
                                Ginstall($1->NAME, TYPE+2, $3->VALUE, Goffset, 0, NULL, NULL);
                                 printf("*****offset of %s[%d] is %d\n",$1->NAME,$3->VALUE,Goffset);
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
    | ID {

                                headArg = NULL;
                                Ginstall($1->NAME, TYPE, 0, Goffset, 0, NULL, NULL);
                                printf("*****offset of function %s is %d\n",$1->NAME,Goffset);
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
        LPAREN parametr RPAREN {

    							struct Gsymbol* gt =  Glookup($1->NAME);
                                if(gt)
                                {
                                    gt->ARGLIST = headArg;
    							}else
                                    yyerror("function not found");
                        }

    ;

functions : { $$ = NULL; }
    | functions function {  $$=CreateNode(0,'S', 0, NULL, $1, $2, NULL); if (($1==NULL || $1->TYPE == FUNC) && $2->TYPE== FUNC) $$->TYPE= FUNC; else {$$->TYPE=-1; yyerror("Bad functions") ;} }
    ;

function : ftype ID { fname = (char *)malloc(30); strcpy(fname,$2->NAME); } LPAREN Fparametr RPAREN LFLOWER fbody RFLOWER {
                                                                struct Gsymbol* gt =  Glookup($2->NAME);
                                                                if(gt)
                                                                {
                                                                    gt->LTABLE = Lnode;
                                                                    gt->ARGLIST = headArg2;
                                                                }
                                                                $$=CreateNode(0,'f', 0, fname, $5, $8, NULL);
                                                                if($8->TYPE == FTYPE) { $$->TYPE=FUNC; }else{ yyerror(" return type error"); $$->TYPE = -1;}
                                                                //PrintLSymbol(Lnode);

        }
    ;

main_function : INTEGER MAIN {                                      headArg = (struct ArgStruct*)NULL;
                                                                    headArg2 = (struct ArgStruct*)NULL;
                                                                    fname = (char *)malloc(30);
                                                                    strcpy(fname,$2->NAME);
                                                                    FTYPE = INT;
                             }

                LPAREN RPAREN LFLOWER fbody RFLOWER {
                                                                    $$=CreateNode(0,'f', 0, "main", NULL, $7, NULL);
                                                                    if($7->TYPE == FTYPE) { $$->TYPE=0; }else{ yyerror(" return type error"); printf("main return %d",$7->TYPE); $$->TYPE = -1;}
                                                                    $$->lookup=$7->lookup;
                                                                }
    ;

fbody : declaration { if( strcmp(fname,"main")!=0)
                        {
                        if (fnDefCheck(INT, fname, headArg2))
                        {
                            struct Gsymbol* gt = Glookup(fname);
                            if(gt)
                            {
                                gt->LTABLE = Lnode;
                                gt->ARGLIST = headArg2;
                            }
                            else yyerror("Function definition error");
                        }
                        }
                        else
                        {
                            Ginstall(fname, FTYPE, 0, Goffset, 0, NULL, Lnode);
                        }
                    }
                    beginbody { $$ = $3;}
    ;

declaration : DECL { Lnode = malloc(sizeof(struct Lsymbol)); Lnode = NULL; Loffset = 0; } declStatements ENDDECL {  }
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
        Lnode = Linstall($1->NAME, TYPE, Loffset, 0,0, Lnode);
         printf("*****L offset of %s is %d\n",$1->NAME,Loffset);
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

beginbody : BEGINN statements return END {  $$=CreateNode(1,'S', 0, NULL, $2, $3, NULL); if ($2==NULL || $2->TYPE==0) { $$->TYPE = $3->TYPE; } else {$$->TYPE=-1; yyerror("Bad begin error");} }
    ;

statements : { $$ = NULL; }
    | statements statement {  $$=CreateNode(0,'S', 0, NULL, $1, $2, NULL); if (($1==NULL || $1->TYPE==0) && $2->TYPE==0) $$->TYPE=0; else { $$->TYPE=-1; yyerror("Bad statements");}}
    ;

statement : ifelse { $$ = $1; }
    | dowhile { $$ = $1;}
    | read { $$ = $1;  }
    | write { $$ = $1;  }
    | astatement { $$ = $1;  }
    ;

ifelse : IF expression THEN statements ENDIF SEMICOLON { $1 = CreateNode(0,'I', 0, NULL, $4, $2, NULL); $$ = $1;
                                                if ($2->TYPE==2 && ($4==NULL || $4->TYPE==0)) $$->TYPE=0; else {$$->TYPE=-1; yyerror("If type error"); } }
    | IF expression THEN statements ELSE statements ENDIF SEMICOLON { $1 = CreateNode(0,'I', 0, NULL, $4, $2, $6); $$ = $1;
                                                if ($2->TYPE==2 && ($4==NULL || $4->TYPE==0) && ($6==NULL || $6->TYPE==0)) $$->TYPE=0; else { $$->TYPE=-1; yyerror("If else error");}}
    ;

dowhile : WHILE expression DO statements ENDWHILE SEMICOLON { $1 = CreateNode(0,'W', 0, NULL, $4, $2, NULL); $$=$1; if ($2->TYPE==2 && ($4==NULL || $4->TYPE==0)) $$->TYPE=0; else $$->TYPE=-1; yyerror("while error"); }
    ;

astatement : ID ASSIGN expression SEMICOLON { $2 = CreateNode(0,'=', 0, NULL, $1, NULL, $3); $$=$2;
                                            struct Lsymbol* lt = Llookup($1->NAME, Lnode);
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
                                            struct Lsymbol* lt = Llookup($3->NAME, Lnode);
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
                                        $$->TYPE = $2->TYPE;  }
    ;

expression : expression PLUS expression { $2 = CreateNode(0,'+', 0, NULL, $1, NULL, $3); $$ = $2; if($1->TYPE==1 && $3->TYPE ==1) $$->TYPE=1; else {$$->TYPE=-1; yyerror("+ error");} }
    | expression MINUS expression { $2 = CreateNode(0,'-', 0, NULL, $1, NULL, $3); $$ = $2; if($1->TYPE==1 && $3->TYPE ==1) $$->TYPE=1; else {$$->TYPE=-1; yyerror("- error"); } }
    | expression MULT expression { $2 = CreateNode(0,'*', 0, NULL, $1, NULL, $3); $$ = $2; if($1->TYPE==1 && $3->TYPE ==1) $$->TYPE=1; else{$$->TYPE=-1; yyerror("* error"); }}
    | expression DIVIDE expression { $2 = CreateNode(0,'/', 0, NULL, $1, NULL, $3); $$ = $2;  if($1->TYPE==1 && $3->TYPE ==1) $$->TYPE=1; else {$$->TYPE=-1; yyerror("/ error"); }}
    | expression MODULUS expression { $2 = CreateNode(0,'%', 0, NULL, $1, NULL, $3); $$ = $2; if($1->TYPE==1 && $3->TYPE ==1) $$->TYPE=1; else {$$->TYPE=-1; yyerror("%error"); }}
    | expression EQUAL expression { $2 = CreateNode(0,'E', 0, NULL, $1, NULL, $3); $$ = $2; if($1->TYPE==1 && $3->TYPE ==1) $$->TYPE=2; else {$$->TYPE=-1; yyerror("== error");  }}
    | expression LESS_THAN expression { $2 = CreateNode(0,'<', 0, NULL, $1, NULL, $3); $$ = $2; if($1->TYPE==1 && $3->TYPE ==1) $$->TYPE=2; else {$$->TYPE=-1; yyerror("< error"); }}
    | expression GREATER_THAN expression { $2 = CreateNode(0,'>', 0, NULL, $1, NULL, $3); $$ = $2; if($1->TYPE==1 && $3->TYPE ==1) $$->TYPE=2; else {$$->TYPE=-1; yyerror("> error"); }}
    | expression GREATER_EQ expression { $2 = CreateNode(0,'G', 0, NULL, $1, NULL, $3); $$ = $2; if($1->TYPE==1 && $3->TYPE ==1) $$->TYPE=2; else {$$->TYPE=-1; yyerror(">= error"); }}
    | expression LESS_EQUAL expression { $2 = CreateNode(0,'L', 0, NULL, $1, NULL, $3); $$ = $2; if($1->TYPE==1 && $3->TYPE ==1) $$->TYPE=2; else {$$->TYPE=-1; yyerror("<= error"); } }
    | expression NEQUAL expression { $2 = CreateNode(0,'N', 0, NULL, $1, NULL, $3); $$ = $2; if($1->TYPE==1 && $3->TYPE ==1) $$->TYPE=2; else {$$->TYPE=-1; yyerror("!= error"); } }
    | expression AND expression { $2 = CreateNode(0,'&', 0, NULL, $1, NULL, $3); $$ = $2; if($1->TYPE==2 && $3->TYPE ==2) $$->TYPE=2; else {$$->TYPE=-1; yyerror("& error");} }
    | expression OR expression { $2 = CreateNode(0,'|', 0, NULL, $1, NULL, $3); $$ = $2; if($1->TYPE==2 && $3->TYPE ==2) $$->TYPE=2; else {$$->TYPE=-1; yyerror("| error");} }
    | NOT expression { $1 = CreateNode(0,'!', 0, NULL, NULL, $2, NULL); $$ = $1;  if($2->TYPE==2) $$->TYPE=2; {$$->TYPE=-1; yyerror("NOT error");} }
    | LPAREN expression RPAREN { $$ = $2; }
    | TRUE { $1 = CreateNode(2,'T', 0, NULL,NULL,NULL,NULL); $$ = $1;  }
    | FALSE { $1 = CreateNode(2,'F', 0, NULL, NULL, NULL, NULL); $$ = $1; }
    | NUMBER { $$=$1; }
    | ID { $$ = $1; struct Lsymbol* lt = Llookup($1->NAME, Lnode); if(lt) $$->TYPE=lt->TYPE; else {
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
                                        $$->lookup = gtemp->LTABLE;
                                        $$->TYPE = gtemp->TYPE;
                                    }
                                    struct ArgStruct* ARGLIST = gtemp->ARGLIST;
                                    struct node* ptemp=$3;
                                    printf("PRINTING AGRUMENTS\n");
                                    printArg(ARGLIST);
                                    while(ARGLIST )
                                    {
                                        if(pcount>0 )
                                        {
                                            printf("%s %d %d\n",ARGLIST->ARGNAME, ARGLIST->ARGTYPE, ptemp->center->TYPE );
                                            if(ptemp==NULL && ARGLIST)
                                            {
                                                yyerror("argument count error 1");
                                            }
                                            else
                                            if(ARGLIST==NULL && ptemp)
                                            {
                                                yyerror("argument count error 2");
                                            }
                                            else
                                            if(ARGLIST->ARGTYPE == ptemp->center->TYPE)
                                            {
                                                if(ARGLIST->PASSTYPE == 1)
                                                {
                                                    if(ptemp->center->PASSTYPE==1)
                                                    {
                                                        printf("matched argument %d\n",pcount);
                                                    }
                                                    else{
                                                        yyerror("argument type error 1");
                                                    }
                                                    ARGLIST=ARGLIST->ARGNEXT;
                                                    ptemp = ptemp->left;

                                                }else if(ARGLIST->PASSTYPE == 0){
                                                    printf("NODETYPE %d\n",ptemp->center->PASSTYPE);
                                                    if(ptemp->center->PASSTYPE==0)
                                                    {
                                                        printf("matched argument %d\n",pcount);
                                                    }
                                                    else{
                                                        yyerror("argument type error 2");
                                                    }
                                                    ARGLIST=ARGLIST->ARGNEXT;
                                                    ptemp = ptemp->left;
                                                }

                                            }else
                                            {
                                                 yyerror("match type error 1");
                                                 ARGLIST=ARGLIST->ARGNEXT;
                                                 ptemp = ptemp->left;
                                            }
                                            pcount--;
                                        }else
                                        {
                                        break;
                                        }
                                    }
                                    pcount=0;
                            }
    ;

FexprList: { $$=NULL; }
        | exprList { $$ = $1; }
        ;

exprList : exprList COMMA expression { $$=CreateNode(0,'z', 0, NULL,$1,$3,NULL); pcount++; $3->PASSTYPE=0; }
		| expression { $$=CreateNode(0,'z', 0, NULL,NULL,$1,NULL); pcount++; $1->PASSTYPE=0; }
		| ADDRESSOF ID { $$ = $1; $$->PASSTYPE=1; struct Lsymbol* lt = Llookup($1->NAME, Lnode); if(lt) $$->TYPE=lt->TYPE; else {
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
        yyparse();
        fp = fopen("sim.asm","a");
        fprintf(fp,"\nSTART\n");
		fprintf(fp,"MOV R1,%d\n",Goffset+1);
		fprintf(fp,"INR R1\n");
		fprintf(fp,"MOV SP,R1\n");
		fprintf(fp,"MOV R2,SP\n");
		fprintf(fp,"MOV R3,%d\n",GetLtableSize("main"));
		fprintf(fp,"ADD R2,R3\n");
		fprintf(fp,"MOV SP,R2\n");
		fprintf(fp,"CALL main\n");
		fprintf(fp,"MOV SP,R1\n");
		fprintf(fp,"MOV R2,SP\n");
		fprintf(fp,"MOV R3,%d\n",GetLtableSize("main"));
		fprintf(fp,"SUB R2,R3\n");
		fprintf(fp,"MOV SP,R2\n");
		fprintf(fp,"MOV R1,%d\n",Goffset+1);
		fprintf(fp,"HALT\n");
        fclose(fp);
        return 0;
}


void makeArglist( struct ArgStruct* arg)
{
	if(!headArg)
	 {
	 	headArg = arg;
	 	printf("installed1 argument fisrt\n");
	}
	else
	{
		struct ArgStruct* temp = headArg;
		printf("installed argument rest\n");
		while(temp->ARGNEXT!=NULL)
		{
			if(strcmp(temp->ARGNAME,arg->ARGNAME)==0)
			 {
			 	yyerror("Multiple Declaration of Arguments");
			 	break;
			 }
			temp = temp->ARGNEXT;
		}
		if(strcmp(temp->ARGNAME,arg->ARGNAME)==0)
		 {
		 	yyerror("Multiple Declaration of Arguments");
		 }
		  arg->ARGNEXT=headArg;
		  headArg = arg;
	}
	printArg(headArg);
}

void makeArglist2(struct ArgStruct* arg)
{
    if(!headArg2)
     {
        headArg2 = arg;
        printf("installed2 argument fisrt\n");
    }
    else
    {
        struct ArgStruct* temp = headArg2;
        printf("installed argument rest\n");
        while(temp->ARGNEXT!=NULL)
        {
            if(strcmp(temp->ARGNAME,arg->ARGNAME)==0)
             {
                yyerror("Multiple Declaration of Arguments");
                break;
             }
            temp = temp->ARGNEXT;
        }
        if(strcmp(temp->ARGNAME,arg->ARGNAME)==0)
         {
            yyerror("Multiple Declaration of Arguments");
         }
        arg->ARGNEXT=headArg2;
		headArg2 = arg;
    }
    printArg(headArg2);
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
		    printf("Argument arg2 short\n");
		 	return 0;
		}
		else
		{
			if(strcmp(j->ARGNAME,i->ARGNAME)!=0 || i->ARGTYPE!=j->ARGTYPE )
			{
			printf("Argument name no match\n");
			return 0;
			}
			Lnode = Linstall(i->ARGNAME, i->ARGTYPE, Loffset, 0, i->PASSTYPE, Lnode);
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
            printf("installed 1 args %s\n",i->ARGNAME);
			i=i->ARGNEXT;
			j=j->ARGNEXT;
			 PrintLSymbol(Lnode);

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

int fnDefCheck(int type, char* name, struct ArgStruct* arg)
{
	   struct Gsymbol* res;
	   res = Gnode;
	   while(res != NULL)
	    {
		      if(strcmp(res->NAME, name) == 0 && res->SIZE==0)
			{
				 if(res->TYPE == type && argDefCheck(res->ARGLIST, arg))
				 {
				 	return 0;
				 }
				 else
				 {
					yyerror("Incorrect Function Definition");
					return -1;

			      	 }
		      	}
		      res = res->NEXT;
	     }
	  yyerror("Function Undeclared");

}

char* itoa(int value)
{
	char *temp=(char *)malloc(10);
	int i;
    if(value<0)
    {
    value = 0-value;
    for(i=8; i>0 && value ; i-- , value = value /10)
	{
		temp[i]=(char ) (48 + value%10 );
	}
	temp[i]='-';

	temp[9]='\0';
	return (temp+i);
    }
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
struct Lsymbol* ltemp = NULL;
char * FNAME;
void Gen3A(struct node* root,int flag){
    if(root==NULL){
        return;
    }

    switch(root->NODETYPE){
        case 'f' :{
            struct Gsymbol* gt = Glookup(root->NAME);
            if(gt){
            struct Lsymbol* lt = gt->LTABLE;
            ltemp = lt;
            int offset=2;
            printf("Printing LSymbol for %s\n", root->NAME);
            PrintLSymbol(ltemp);
            struct ArgStruct* at = gt->ARGLIST;
            struct Lsymbol* lcopy = (struct Lsymbol*)malloc(sizeof (struct Lsymbol));
            FNAME = malloc(30);
            FNAME[0]='\0';
            strcat(FNAME,root->NAME);
            TAinstall('B',root->NAME,NULL,NULL);
            TAinstall('P',"BP",NULL,NULL);
			TAinstall('M',"BP","SP",NULL);
			char *t1 =(char *) malloc(5);
            t1[0]='t';t1[1]='\0';
            strcat(t1,itoa(current_temp));
            TAinstall('M',t1,"SP",NULL);
            char *t2 =(char *) malloc(5);
            t2[0]='t';t2[1]='\0';
            current_temp++;
            strcat(t2,itoa(current_temp));
            printf("Gtable size %s %d",root->NAME,GetLtableSize(root->NAME));
            TAinstall('M',t2,itoa(GetLtableSize(root->NAME)),NULL);
            TAinstall('+',t1,t1,t2);
            current_temp--;
            TAinstall('M',"SP",t1,NULL);
            TAinstall('M',t1,"BP",NULL);
            while(at)
            {
                current_temp++;
                char *t2 =(char *) malloc(5);
                t2[0]='t';t2[1]='\0';
                strcat(t2,itoa(current_temp));
                TAinstall('M',t2,itoa(offset),NULL);
                current_temp++;
                char *t3 =(char *) malloc(5);
                t3[0]='t';t3[1]='\0';
                strcat(t3,itoa(current_temp));
                TAinstall('M',t3,t1,NULL);
                TAinstall('-',t3,t3,t2);
                TAinstall('l',t2,t3,NULL);
                //TAinstall('w',t2,NULL,NULL);
                current_temp++;
                char* t4 =(char *) malloc(5);
                t4[0]='t';t4[1]='\0';
                strcat(t4,itoa(current_temp));
                TAinstall('M',t3,t1,NULL);
                TAinstall('M',t4,itoa(((Llookup(at->ARGNAME,ltemp))->BINDING)+1),NULL);
                TAinstall('+',t3,t3,t4);
                TAinstall('=',t3,t2,NULL);
                offset = offset+1;
                at=at->ARGNEXT;
                current_temp--;
                current_temp--;
                current_temp--;
            }
            Gen3A(root->center,0);
            }
            break;
        }
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
            //printf("%c %s %s %s",'E',t1, t1, t2);
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
                //printf("Printing LSymbol for %s when looking for %s\n",FNAME, root->NAME);
                //PrintLSymbol(ltemp);
                if(Llookup(root->NAME,ltemp))
                 {
                    current_temp++;
                    char *t1 =(char *) malloc(5);
                     t1[0]='t';t1[1]='\0';
                    strcat(t1,itoa(current_temp));
                    current_temp++;
                    char *t2 =(char *) malloc(5);
                     t2[0]='t';t2[1]='\0';
                    strcat(t2,itoa(current_temp));
                    TAinstall('M',t1,"BP",NULL);
                    TAinstall('M',t2,itoa(Llookup(root->NAME, ltemp)->BINDING+1),NULL);
                    TAinstall('+',t1,t1,t2);
                    TAinstall('M',t,t1,NULL);
                    current_temp--;
                    current_temp--;
                }
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
            struct ArgStruct* args = gtemp->ARGLIST;
            printf("printing Argument");
            printArg(args);
            //gtemp->BINDING =
            while(current_temp)
            {
                char *t =(char *) malloc(5);
                t[0]='t';t[1]='\0';
                strcat(t,itoa(current_temp));
                TAinstall('P',t,NULL,NULL);
                current_temp--;
            }
            current_temp;
            while(pc && temp)
            {
                char *t =(char *) malloc(5);
                t[0]='t';t[1]='\0';
                Gen3A(temp->center,0);
                strcat(t,itoa(current_temp));
                TAinstall('P',t,NULL,NULL);
                temp=temp->left;
                current_temp--;
                pc--;
            }
            TAinstall('C',root->NAME,NULL,NULL);
            printf("%c %s %s %s",'C',root->NAME,NULL,NULL);
            pc=root->VALUE;
            while(pc)
            {
                char *t =(char *) malloc(5);
                t[0]='t';t[1]='\0';
                strcat(t,itoa(1));
                TAinstall('p',t,NULL,NULL);
                //printf("%c %s %s %s",'v',t,NULL,NULL);
                pc--;
            }
            current_temp=1;
            while(current_temp<=ct)
            {
                char *t =(char *) malloc(5);
                t[0]='t';t[1]='\0';
                strcat(t,itoa(current_temp));
                TAinstall('p',t,NULL,NULL);
                //printf("%c %s %s %s",'p',t,NULL,NULL);
                current_temp++;
            }
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
                if(r1[0]=='t')
                    r1[0]='R';
                if(r2[0]=='t')
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
                if(r1[0]=='t')
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
                if(r1[0]=='t')
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
            case 'P':{
                char *r1 =(char *) malloc(5);
                strcpy(r1,TAroot->op1);
                if(r1[0]=='t')
                r1[0]='R';
                fp = fopen("sim.asm","a");
                fprintf(fp,"PUSH %s\n",r1);
                fclose(fp);
                break;
            }
            case 'p':{
                char *r1 =(char *) malloc(5);
                strcpy(r1,TAroot->op1);
                if(r1[0]=='t')
                r1[0]='R';
                fp = fopen("sim.asm","a");
                fprintf(fp,"POP %s\n",r1);
                fclose(fp);
                break;
            }
            case 'R':{
                char *r1 =(char *) malloc(5);
                strcpy(r1,TAroot->op1);
                if(r1[0]=='t')
                r1[0]='R';
                fp = fopen("sim.asm","a");
                fprintf(fp,"MOV R0,%s\n",r1);
                fprintf(fp,"MOV SP, BP\n");
			    fprintf(fp,"POP BP\n");
                fprintf(fp,"RET\n");
                fclose(fp);
                break;
            }
            case 'C':{
                fp = fopen("sim.asm","a");
                fprintf(fp,"CALL %s\n",TAroot->op1);
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


