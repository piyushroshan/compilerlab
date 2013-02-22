struct node {
	int TYPE;			/* Integer (1), Boolean (2) or Void (3) (for statements) */
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

/* Sample Global and Local Symbol Table Structure */

/** Symbol Table Entry is required for variables, arrays and functions**/

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




struct Gsymbol *Glookup(char* NAME){
	struct Gsymbol *Gtemp = Gnode;
	while(Gtemp != NULL){
		if(strcmp(Gtemp->NAME, NAME) == 0)
			return Gtemp;
		Gtemp = Gtemp->NEXT;
	}
	return Gtemp;
}

void Ginstall(char* NAME, int TYPE, int SIZE){ // Installation
	if(Glookup(NAME) == NULL){
	    struct Gsymbol* temp=(struct Gsymbol *)malloc(sizeof(struct Gsymbol));
	    temp->NAME = NAME;
	    temp->TYPE = TYPE;
	    temp->SIZE = SIZE;
 	    temp->NEXT = Gnode;
 	    Gnode = temp;
    }
}


struct Lsymbol *Llookup(char* NAME){
	struct Lsymbol *Ltemp = Lnode;
	while(Ltemp != NULL){
		if(strcmp(Ltemp->NAME, NAME) == 0)
			return Ltemp;
		Ltemp = Ltemp->NEXT;
	}
	return Ltemp;
}

void Linstall(char* NAME, int TYPE){
	struct Lsymbol* temp=(struct Lsymbol *)malloc(sizeof(struct Lsymbol));
	temp->NAME = NAME;
	temp->TYPE = TYPE;
 	temp->NEXT = Lnode;
 	Lnode = temp;
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
		case 'S' :
			printTree(root->center);
			printTree(root->left);
			printTree(root->right);
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

