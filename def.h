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
	temp->NODETYPE	=	NODETYPE1;
	temp->VALUE		=	VALUE1;
	temp->NAME		=	NAME1;
	temp->left		=	ptr1; // left node
	temp->center	=	ptr2; // unknown nodes
	temp->right		=	ptr3; // right node
	return temp;
}
