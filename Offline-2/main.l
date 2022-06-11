%option noyywrap

%{
#include<stdio.h>
#include<stdlib.h>
%}


/*operators*/
ADDOP [+-]
MULOP [*/]
ASSIGNOP [=]
RELOP [<>=!]
LOGICOP [&&||]
LOGICNOT [!]

/*PARENTHESIS*/
LPAREN [\(]
RPAREN [\)]
LCURL [\{]
RCURL [\}]
LTHIRD [\[]
RTHIRD [\]]

/*COMMA*/
COMMA [,]
SEMICOLON [;]
NEWLINE [\n]


/*CHARS*/





/*keywords*/

KEYWORD "if" | "then" | "else" | "while" | "do" | "for" | "todo" | "end"

WHITESPACE [ \t\n\r]+


/*identifiers*/
ID [a-zA-Z_] [a-zA-Z0-9_]*


/*constants*/

DIGIT [0-9]+














%%

{WHITESPACE}  {  }

{DIGIT} {printf("%s\n", yytext);}

[A-Z]{3}			{printf("%s matched in [A-Z]{3} rule\n",yytext);}
a* 					{printf("%s matched in a* rule\n",yytext);}
A* 					{printf("%s matched in A* rule\n",yytext);}
{ADDOP} 			{printf("%s matched in ADDOP rule\n",yytext);}
{MULOP} 			{printf("%s matched in MULOP rule\n",yytext);}
{ASSIGNOP} 			{printf("%s matched in ASSIGNOP rule\n",yytext);}
{RELOP} 			{printf("%s matched in RELOP rule\n",yytext);}
{LOGICOP} 			{printf("%s matched in LOGICOP rule\n",yytext);}
{LOGICNOT} 			{printf("%s matched in LOGICNOT rule\n",yytext);}
{LPAREN} 			{printf("%s matched in LPAREN rule\n",yytext);}
{RPAREN} 			{printf("%s matched in RPAREN rule\n",yytext);}
{LCURL} 			{printf("%s matched in LCURL rule\n",yytext);}
{RCURL} 			{printf("%s matched in RCURL rule\n",yytext);}
{LTHIRD} 			{printf("%s matched in LTHIRD rule\n",yytext);}
{RTHIRD} 			{printf("%s matched in RTHIRD rule\n",yytext);}
{COMMA} 			{printf("%s matched in COMMA rule\n",yytext);}
{SEMICOLON} 		{printf("%s matched in SEMICOLON rule\n",yytext);}
{NEWLINE} 			{printf("%s matched in NEWLINE rule\n",yytext);}



. 					{printf("Mysterious character %s found\n",yytext);}
%%
int main(int argc,char *argv[]){
	
	if(argc!=2){
		printf("Please provide input file name and try again\n");
		return 0;
	}
	
	FILE *fin=fopen(argv[1],"r");
	if(fin==NULL){
		printf("Cannot open specified file\n");
		return 0;
	}
	

	yyin= fin;
	yylex();
	fclose(yyin);
	return 0;
}