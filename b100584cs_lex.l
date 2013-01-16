ws	[ ]
tab	\t
nl	\n
wss	{ws}{ws}+
tabs	{tab}{tab}+
nls	{nl}{nl}+
letter	[A-Za-z]
digit	[0-9]
id	{letter}({letter}|{digit})*
number	{digit}+
float	[+-]?{digit}+([.]{digit}+)(E[+-]?{digit}+)?

%%

TRUE	{ printf("BOOLEAN True\n");}
FALSE	{ printf("BOOLEAN False\n");}
boolean	{ printf("BOOLEAN TYPE\n");}
integer	{ printf("INTEGER TYPE\n");}
{ws}	{ printf("whitespace\n");}
{tab}	{ printf("tab\n");}
{nl}	{ printf("newline\n");}
{wss}	{ printf("whitespaces\n");}
{tabs}	{ printf("tabs\n");}
{nls}	{ printf("newlines\n");}
"//".*	{ printf("Comment line---> %s\n", yytext); }
"=="    { printf("Boolean equal\n"); }
"="     { printf("Assignment\n"); }
"!="    { printf("Not Equal\n"); }
"<"     { printf("LESS THAN\n"); }
"<="    { printf("LESS EQUAL\n"); }
">"     { printf("GREATER THAN\n"); }
">="    { printf("GREATER THAN\n"); }
"+"     { printf("PLUS\n"); }
"-"     { printf("MINUS\n"); }
"*"     { printf("MULT\n"); }
"/"     { printf("DIVIDE\n"); }
")"     { printf("Right PAREN\n"); }
"("     { printf("Left PAREN\n"); }
"]"	{ printf("Right SQUARE\n"); }
"["	{ printf("Left SQUARE\n"); }
"}"     { printf("Right FLOWER\n"); }
"{"     { printf("Left FLOWER\n"); }
","	{ printf("Coma\n");}
";"	{ printf("TERMINATOR\n");}
"&"     { printf("Address Operator\n");}
"%"     { printf("MODULUS\n");}
AND	{ printf("AND\n");}
OR	{ printf("OR\n");}
NOT	{ printf("NOT\n");}
read	{ printf("READ\n");}
write	{ printf("WRITE\n");}
if	{ printf("IF\n");}
then	{ printf("THEN\n");}
else	{ printf("ELSE\n");}
while   { printf("WHILE\n"); }
do   	{ printf("DO\n"); }
endwhile	{ printf("ENDWHILE\n"); }
decl	{ printf("DECL\n"); }
enddecl	{ printf("END DECLARATION\n"); }
print	{ printf("PRINT\n"); }
begin	{ printf("BEGIN\n"); }
return  { printf("RETURN\n"); }
record  { printf("RECORD\n"); }
{id}	{ printf("Identifier -> %s\n", yytext); }
{number}	{ printf("Number -> %d\n", atoi(yytext)); }
{float}	{ printf("Float -> %s\n", yytext);}