%{
#include "y.tab.h"
#include "def.h"

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
"+"     { return PLUS; }
"-"     { return MINUS; }
"*"     { return MULT; }
"/"     { return DIVIDE; }
")"     { return RPAREN; }
"("     { return LPAREN; }
"]"		{ return RSQUARE; }
"["		{ return LSQUARE; }
"}"     { return RFLOWER; }
"{"     { return LFLOWER; }
","		{ return COMMA;}
";"		{ return SEMICOLON;}
"&"     { return ADDRESSOF;}
"%"     { return MODULUS;}
AND		{ return AND;}
OR		{ return OR;}
NOT		{ return NOT;}
read	{ return READ;}
write	{ return WRITE;}
if		{ return IF;}
endif	{ return ENDIF;}
then	{ return THEN;}
else	{ return ELSE;}
while   { return WHILE; }
do   	{ return DO; }
endwhile	{ return ENDWHILE; }
decl	{ return DECL; }
enddecl	{ return ENDDECL; }
begin	{ return BEGINN; }
end		{ return END; }
main 	{ return MAIN; }
return  { return RETURN; }
{id}	{ char *name =  (char *)malloc(sizeof(yytext)); strcpy(name,yytext);
			yylval.n = CreateNode(0,2,0,name,NULL,NULL,NULL); return ID; }
{number}	{ yylval.n = CreateNode(0,1,atoi(yytext),NULL,NULL,NULL,NULL); return NUMBER; }
