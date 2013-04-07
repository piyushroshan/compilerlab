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

struct node* CreateNode(int TYPE1, int NODETYPE1, int VALUE1, char* NAME1, struct node *ptr1, struct node *ptr2, struct node *ptr3) {
    struct node* temp=(struct node *)malloc(sizeof(struct node));
    temp->TYPE		=	TYPE1;
    temp->NODETYPE		=	NODETYPE1;
    temp->VALUE		=	VALUE1;
    temp->NAME		=	NAME1;

    temp->left		=	ptr1; // left node
    temp->center		=	ptr2; // unknown nodes
    temp->right		=	ptr3; // right node
    return temp;
}

/** Sample Global and Local Symbol Table Structure **/

/** Symbol Table Entry is required for variables, arrays and functions**/

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




struct Gsymbol *Glookup(char* NAME){
    struct Gsymbol *Gtemp = Gnode;
    while(Gtemp != NULL){
        if(strcmp(Gtemp->NAME, NAME) == 0)
            return Gtemp;
        Gtemp = Gtemp->NEXT;
    }
    return Gtemp;
}

void Ginstall(char* NAME, int TYPE, int SIZE, int BINDING, int VALUE, struct ArgStruct* ARGLIST, struct Lsymbol* LTABLE){ // Installation
    if(Glookup(NAME) == NULL){
        struct Gsymbol* temp=(struct Gsymbol *)malloc(sizeof(struct Gsymbol));
        temp->NAME = NAME;
        temp->TYPE = TYPE;
        temp->SIZE = SIZE;
        temp->BINDING = BINDING;
        temp->VALUE = VALUE;
        temp->ARGLIST = ARGLIST;
        temp->LTABLE= LTABLE;
        temp->NEXT = Gnode;
        Gnode = temp;
    }else
        printf("Global ID %s redeclared at %d\n",NAME, BINDING);
}


int GetGtableSize(){
    if(Gnode)
        return (Gnode->BINDING + Gnode->SIZE);
    else
        return 0;
}

struct Lsymbol *Llookup(char* NAME, struct Lsymbol* Ltemp1){
    struct Lsymbol *Ltemp = Ltemp1;
    while(Ltemp != NULL){
        if(strcmp(Ltemp->NAME, NAME) == 0)
            return Ltemp;
        Ltemp = Ltemp->NEXT;
    }
    return Ltemp;
}



struct Lsymbol* Linstall(char* NAME, int TYPE,int BINDING,int VALUE, int PASSTYPE, struct Lsymbol* Lnode){
    if(!Llookup(NAME, Lnode)){
        struct Lsymbol* temp=(struct Lsymbol *)malloc(sizeof(struct Lsymbol));
        temp->NAME = NAME;
        temp->TYPE = TYPE;
        temp->BINDING = BINDING;
        temp->VALUE = VALUE;
        temp->PASSTYPE = PASSTYPE;
        temp->NEXT = Lnode;
        Lnode = temp;
        return Lnode;
    }else
        printf("ID %s redeclared\n", NAME);
        return Lnode;
}

void printTree(struct node* root){
    if(root==NULL) {
        return;
    }

    switch(root->NODETYPE ) {
        case 'f' :
            printf("( ");
            printf("%s ->",root->NAME);
            printTree(root->center);
            printf(" )\n");
            break;
        case 'C' :
            printf("( ");
            printf("%s ->",root->NAME);
            printTree(root->center);
            printTree(root->left);
            printf(" )\n");
            break;
        case 'S' :
            printTree(root->left);
            printTree(root->center);
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
        case 1:
            printf("%d ",root->VALUE);
            break;
        case 2:
            printf("%s",root->NAME);
            if(root->center!=NULL){
                printf("-->");
                printTree(root->center);
            }else
                printf(" ");
            break;
        default:
            break;
    }
}

