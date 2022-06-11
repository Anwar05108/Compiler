%option noyywrap

%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "SymbolTable.cpp"

SymbolTable symbolTable(7);
FILE *tokenFile, *logFile;
int lineNumber = 1;

void printError(char *errorMessage) {
    fprintf(logFile, "Error: %s\n", errorMessage);
}

void printWarning(char *warningMessage) {
    fprintf(logFile, "Warning: %s\n", warningMessage);
}

void printToken(char *token, char *tokenType) {
    fprintf(tokenFile, "%s %s\n", token, tokenType);
}

void printToken(char *token, char *tokenType, int lineNumber) {
    fprintf(tokenFile, "%s %s %d\n", token, tokenType, lineNumber);
}

void printToken(char *token, char *tokenType, int lineNumber, char *tokenValue) {
    fprintf(tokenFile, "%s %s %d %s\n", token, tokenType, lineNumber, tokenValue);
}

void printToken(char *token, char *tokenType, int lineNumber, char *tokenValue, char *tokenValueType) {
    fprintf(tokenFile, "%s %s %d %s %s\n", token, tokenType, lineNumber, tokenValue, tokenValueType);
}

void countLineNumber() {
    lineNumber++;
}

string toUpper(string str) {
    for (int i = 0; i < str.length(); i++) {
        str[i] = toupper(str[i]);
    }
    return str;
}

string processToken(char *token) {
    string tokenStr = string(token);
    tokenStr = toUpper(tokenStr);
    return tokenStr;
}

char processChar(char c) {
    if (c == '\n') {
        c = '\n';
    }
    else if(c == '\t') {
        c = '\t';
    }
    else if(c == '\r') {
        c = '\r';
    }
    else if(c == '\b') {
        c = '\b';
    }
    else if(c == '\f') {
        c = '\f';
    }
    return c;
}






%}


/*operators*/
ADDOP [+-]
MULOP [*/]
ASSIGNOP [=]
RELOP [<>=!]
LOGICOP ("&&"|"||")
BITOP [&|^~]
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

SPECIAL_CHAR [\t\n\r\f\v]
NORMAL_CHAR [a-zA-Z0-9_]


/*comments*/
COMMENT ("//"(([\\]+([\n]))|[\n]*)*)
MULTI_COMMENT ([^*]|("*"[^\n]))*"*/"










/*keywords*/

IF "if"
ELSE "else"
WHILE "while"
RETURN "return"
INT "int"
VOID "void"
FLOAT "float"
CHAR "char"
BOOL "bool"
BREAK "break"
CONTINUE "continue"
CASE "case"
DEFAULT "default"




WHITESPACE [ \t\n\r]+


/*identifiers*/
ID [a-zA-Z_][a-zA-Z0-9_]*


/*numbers*/



/*strings*/
STRING ["][^"]*["]





/*constants*/

DIGIT [0-9]+














%%

{WHITESPACE}  {  }
{IF} { printf("if keyword\n"); }
{ELSE} { printf("else keyword\n"); }
{WHILE} { printf("while keyword\n"); }
{RETURN} { printf("return keyword\n"); }
{INT} { printf("int keyword\n"); }
{VOID} { printf("void keyword\n"); }
{FLOAT} { printf("float keyword\n"); }
{CHAR} { printf("char keyword\n"); }
{BOOL} { printf("bool keyword\n"); }
{DIGIT} {printf("%s\n", yytext);}
{MULTI_COMMENT}     {printf("%s matched in MULTI_COMMENT rule\n",yytext);}
{COMMENT}           {printf("%s matched in COMMENT rule\n",yytext);}
{ADDOP} 			{printf("%s matched in ADDOP rule\n",yytext);
                    fprintf(tokenFile, "<%s %s>\n", yytext, "ADDOP");}

{MULOP} 			{printf("%s matched in MULOP rule\n",yytext);}
{ASSIGNOP} 			{printf("%s matched in ASSIGNOP rule\n",yytext);}
{RELOP} 			{printf("%s matched in RELOP rule\n",yytext);}
{BITOP} 			{printf("%s matched in BITOP rule\n",yytext);}
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
{NEWLINE} 			{lineNumber++;}
{SPECIAL_CHAR} 		{printf("%s matched in SPECIAL_CHAR rule\n",yytext);}
{NORMAL_CHAR} 		{printf("%s matched in NORMAL_CHAR rule\n",yytext);}
{ID} 				{printf("%s matched in ID rule\n",yytext);}
{STRING} 			{printf("%s matched in STRING rule\n",yytext);}
. {printf("Mysterious character %s found\n",yytext);}
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
	
    tokenFile=fopen("token.txt","w");
    if(tokenFile==NULL){
        printf("Cannot open token file\n");
        return 0;
    }



	yyin= fin;
	yylex();
	fclose(yyin);
	return 0;
}