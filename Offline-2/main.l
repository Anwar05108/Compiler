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
NORMAL_CHAR ['][a-zA-Z0-9_][']


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
{IF} { printf("if keyword\n"); 
        fprintf(tokenFile, "<IF>\n");
        fprintf(logFile, "Line no %d: Token <IF> Lexeme if found\n",lineNumber);}
{ELSE} { printf("else keyword\n");
        fprintf(tokenFile, "<ELSE>\n");
        fprintf(logFile, "Line no %d: Token <ELSE> Lexeme else found\n",lineNumber);}
{WHILE} { printf("while keyword\n"); 
        fprintf(tokenFile, "<WHILE>\n");
        fprintf(logFile, "Line no %d: Token <WHILE> Lexeme while found\n",lineNumber);}
{RETURN} { printf("return keyword\n"); 
        fprintf(tokenFile, "<RETURN>\n");
        fprintf(logFile, "Line no %d: Token <RETURN> Lexeme return found\n",lineNumber);}
{INT} { printf("int keyword\n"); 
        fprintf(tokenFile, "<INT>\n");
        fprintf(logFile, "Line no %d: Token <INT> Lexeme int found\n",lineNumber);}
{VOID} { printf("void keyword\n"); 
        fprintf(tokenFile, "<VOID>\n");
        fprintf(logFile, "Line no %d: Token <VOID> Lexeme void found\n",lineNumber);}
{FLOAT} { printf("float keyword\n"); 
        fprintf(tokenFile, "<FLOAT>\n");
        fprintf(logFile, "Line no %d: Token <FLOAT> Lexeme float found\n",lineNumber);}
{CHAR} { printf("char keyword\n"); 
        fprintf(tokenFile, "<CHAR>\n");
        fprintf(logFile, "Line no %d: Token <CHAR> Lexeme char found\n",lineNumber);}
{BOOL} { printf("bool keyword\n"); 
        fprintf(tokenFile, "<BOOL>\n");
        fprintf(logFile, "Line no %d: Token <BOOL> Lexeme bool found\n",lineNumber);}
{DIGIT} {printf("%s\n", yytext);
        fprintf(tokenFile, "<DIGIT %s>\n", yytext);
        fprintf(logFile, "Line no %d: Token <DIGIT %s> Lexeme %s found\n",lineNumber, yytext, yytext);}
{MULTI_COMMENT}     {printf("%s matched in MULTI_COMMENT rule\n",yytext);
                        
                        fprintf(logFile, "Line no %d: Token <MULTI_COMMENT %s> Lexeme %s found\n",lineNumber, yytext, yytext);}
{COMMENT}           {
                        fprintf(logFile, "Line no %d: Token <COMMENT %s> Lexeme %s found\n",lineNumber, yytext, yytext);}
{ADDOP} 			{printf("%s matched in ADDOP rule\n",yytext);
                    fprintf(tokenFile, "<%s %s>\n", "ADDOP",yytext);
                    fprintf(logFile, "Line no %d: Token <%s %s> Lexeme %s found\n",lineNumber, "ADDOP", yytext, yytext);}

{MULOP} 			{printf("%s matched in MULOP rule\n",yytext);
                    fprintf(tokenFile, "<%s %s>\n", "MULOP",yytext);
                    fprintf(logFile, "Line no %d: Token <%s %s> Lexeme %s found\n",lineNumber, "MULOP", yytext, yytext);}
                            
{ASSIGNOP} 			{printf("%s matched in ASSIGNOP rule\n",yytext);
                    fprintf(tokenFile, "<%s %s>\n", "ASSIGNOP",yytext);
                    fprintf(logFile, "Line no %d: Token <%s %s> Lexeme %s found\n",lineNumber, "ASSIGNOP", yytext, yytext);}

{RELOP} 			{printf("%s matched in RELOP rule\n",yytext);
                    fprintf(tokenFile, "<%s %s>\n", "RELOP",yytext);
                    fprintf(logFile, "Line no %d: Token <%s %s> Lexeme %s found\n",lineNumber, "RELOP", yytext, yytext);}
{BITOP} 			{printf("%s matched in BITOP rule\n",yytext);
                    fprintf(tokenFile, "<%s %s>\n", "BITOP",yytext);
                    fprintf(logFile, "Line no %d: Token <%s %s> Lexeme %s found\n",lineNumber, "BITOP", yytext, yytext);}
{LOGICOP} 			{printf("%s matched in LOGICOP rule\n",yytext);
                    fprintf(tokenFile, "<%s %s>\n", "LOGICOP",yytext);
                    fprintf(logFile, "Line no %d: Token <%s %s> Lexeme %s found\n",lineNumber, "LOGICOP", yytext, yytext);}

{LOGICNOT} 			{printf("%s matched in LOGICNOT rule\n",yytext);
                    fprintf(tokenFile, "<%s %s>\n", "LOGICNOT",yytext);
                    fprintf(logFile, "Line no %d: Token <%s %s> Lexeme %s found\n",lineNumber, "LOGICNOT", yytext, yytext);}
{LPAREN} 			{printf("%s matched in LPAREN rule\n",yytext);
                    fprintf(tokenFile, "<%s %s>\n", "LPAREN",yytext);
                    fprintf(logFile, "Line no %d: Token <%s %s> Lexeme %s found\n",lineNumber, "LPAREN", yytext, yytext);}
                    
{RPAREN} 			{printf("%s matched in RPAREN rule\n",yytext);
                    fprintf(tokenFile, "<%s %s>\n", "RPAREN",yytext);
                    fprintf(logFile, "Line no %d: Token <%s %s> Lexeme %s found\n",lineNumber, "RPAREN", yytext, yytext);}
{LCURL} 			{printf("%s matched in LCURL rule\n",yytext);
                    fprintf(tokenFile, "<%s %s>\n", "LCURL",yytext);
                    fprintf(logFile, "Line no %d: Token <%s %s> Lexeme %s found\n",lineNumber, "LCURL", yytext, yytext);
                    symbolTable.enterScope(7);
                    }


{RCURL} 			{printf("%s matched in RCURL rule\n",yytext);
                    fprintf(tokenFile, "<%s %s>\n", "RCURL",yytext);
                    fprintf(logFile, "Line no %d: Token <%s %s> Lexeme %s found\n",lineNumber, "RCURL", yytext, yytext);
                    symbolTable.exitScope();
                    }
{LTHIRD} 			{printf("%s matched in LTHIRD rule\n",yytext);
                        fprintf(tokenFile, "<%s %s>\n", "LTHIRD",yytext);
                        fprintf(logFile, "Line no %d: Token <%s %s> Lexeme %s found\n",lineNumber, "LTHIRD", yytext, yytext);}
{RTHIRD} 			{printf("%s matched in RTHIRD rule\n",yytext);
                        fprintf(tokenFile, "<%s %s>\n", "RTHIRD",yytext);
                        fprintf(logFile, "Line no %d: Token <%s %s> Lexeme %s found\n",lineNumber, "RTHIRD", yytext, yytext);}
{COMMA} 			{printf("%s matched in COMMA rule\n",yytext);
                        fprintf(tokenFile, "<%s %s>\n", "COMMA",yytext);
                        fprintf(logFile, "Line no %d: Token <%s %s> Lexeme %s found\n",lineNumber, "COMMA", yytext, yytext);}
{SEMICOLON} 		{printf("%s matched in SEMICOLON rule\n",yytext);
                        fprintf(tokenFile, "<%s %s>\n", "SEMICOLON",yytext);
                        fprintf(logFile, "Line no %d: Token <%s %s> Lexeme %s found\n",lineNumber, "SEMICOLON", yytext, yytext);}
{NEWLINE} 			{lineNumber++;}
{SPECIAL_CHAR} 		{printf("%s matched in SPECIAL_CHAR rule\n",yytext);
                        fprintf(tokenFile, "<%s %s>\n", "SPECIAL_CHAR",yytext);
                        fprintf(logFile, "Line no %d: Token <%s %s> Lexeme %s found\n",lineNumber, "SPECIAL_CHAR", yytext, yytext);}
{NORMAL_CHAR} 		{printf("%s matched in NORMAL_CHAR rule\n",yytext);
                        fprintf(tokenFile, "<%s %s>\n", "NORMAL_CHAR",yytext);}
{ID} 				{printf("%s matched in ID rule\n",yytext);
                        fprintf(tokenFile, "<%s %s>\n", "ID",yytext);

                        fprintf(logFile, "Line no %d: Token <%s %s> Lexeme %s found\n",lineNumber, "ID", yytext, yytext);
                        if(!symbolTable.search(yytext))
                        {
                            symbolTable.insert(yytext, "ID");
                            symbolTable.printAllScopesInFile(logFile);
                        }
                        else
                        {
                            fprintf(logFile, "Line no %d: Error: %s already declared\n",lineNumber, yytext);
                        }
                        }
{STRING} 			{printf("%s matched in STRING rule\n",yytext);
                        fprintf(tokenFile, "<%s %s>\n", "STRING",yytext);
                        fprintf(logFile, "Line no %d: Token <%s %s> Lexeme %s found\n",lineNumber, "STRING", yytext, yytext);} 
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

    logFile = fopen("log.txt","w");
    if(logFile==NULL){
        printf("Cannot open log file\n");
        return 0;
    }



	yyin= fin;
	yylex();
	fclose(yyin);
    fclose(tokenFile);
    fclose(logFile);
	return 0;
}