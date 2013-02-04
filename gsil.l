%{
#include <stdio.h>
#include "y.tab.h"


struct node
{
	int TYPE;
	int NODETYPE;
	int VALUE;
	struct node *left,*right;
};

struct node* treecreate(int nodetype1,int value1)
{
	struct node* temp=malloc(sizeof(struct node));
	if(nodetype1==0)
	{
		temp->TYPE=1;
		temp->NODETYPE=nodetype1;
		temp->VALUE=value1;
		temp->left=NULL;
		temp->right=NULL;

	}
	else if(nodetype1==1)
	{
		temp->TYPE=1;
		temp->NODETYPE=nodetype1;
		temp->left=NULL;
		temp->right=NULL;
	}
	return temp;
}

%}
ws	[ ]
tab	\t
nl	\n
wss	{ws}+
tabs 	{tab}+
nls	{nl}+
letter	[A-Za-z]
digit	[0-9]
id	{letter}({letter}|{digit})*
number	{digit}+


%%

TRUE	{ return TRUE;}
FALSE	{ return FALSE;}
boolean	{ return BOOLEAN;}
integer	{ return INTEGER;}
{wss}	{ }
{tabs}	{ }
{nls}	{ }
"//".*	{ }
"=="    { return EQUAL; }
"="     { return ASSIGN; }
"!="    { return NEQUAL; }
"<"     { return LESS_THAN; }
"<="    { return LESS_EQUAL; }
">"     { return GREATER_THAN; }
">="    { return GREATER_EQ; }
"+"     { yylval.n =treecreate(1,0);  return PLUS; }
"-"     { return MINUS; }
"*"     { return MULT; }
"/"     { return DIVIDE; }
")"     { return RPAREN; }
"("     { return LPAREN; }
"]"	{ return RSQUARE; }
"["	{ return LSQUARE; }
"}"     { return RFLOWER; }
"{"     { return LFLOWER; }
","	{ return COMMA;}
";"	{ return SEMICOLON;}
"&"     { return ADDRESSOF;}
"%"     { return MODULUS;}
AND	{ return AND;}
OR	{ return OR;}
NOT	{ return NOT;}
read	{ return READ;}
write	{ return WRITE;}
if	{ return IF;}
endif	{ return ENDIF;}
then	{ return THEN;}
else	{ return ELSE;}
while   { return WHILE; }
do   	{ return DO; }
endwhile	{ return ENDWHILE; }
decl	{ return DECL; }
enddecl	{ return ENDDECL; }
begin	{ return BEGINN; }
end	{ return END; }
main { return MAIN; }
return  { return RETURN; }
record  { return RECORD; }
{id}	{ yylval.str = yytext; return ID; }
{number}	{ yylval.n = treecreate(0,atoi(yytext)); return NUMBER; }

%%

