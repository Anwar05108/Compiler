%option noyywrap

%{
    
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "SymbolTable.cpp"

SymbolTable symbolTable(7);
FILE *tokenFile, *logFile;
int lineNumber = 1;
int errorCount = 0;

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
    if (c== '\n') {
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
MULOP [*/%]
ASSIGNOP [=]
RELOP ("<="|">="|"<"|">"|"!="|"==")
LOGICOP ("&&"|"||")
BITOP [&|^~]
LOGICNOT [!]
INCOP ("++"|"--")
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

EMPTY_CHARACTER_ERROR ('')
/*CHARS*/
SPECIAL_CHAR (\\['nt\\afrbv0\"])
NORMAL_CHAR [a-zA-Z0-9_]
CONST_CHAR  [']({NORMAL_CHAR}|{SPECIAL_CHAR})[']
CHAR_ERROR [']({NORMAL_CHAR}{NORMAL_CHAR}+)[']
/*comments*/
COMMENT "//".*
MULTI_COMMENT "/*"([^*]|\*+[^*/])*\*+"/"
UNFINISHED_CHAR_ERROR [']({NORMAL_CHAR}|{SPECIAL_CHAR})*









/*keywords*/

IF "if"
ELSE "else"
WHILE "while"
RETURN "return"
INT "int"
VOID "void"
FLOAT "float"
CHAR "char"
FOR "for"
BREAK "break"
CONTINUE "continue"
CASE "case"
DEFAULT "default"
SWITCH "switch"
DO "do"
DOUBLE "double"

WHITESPACE [ \t\r]+


/*identifiers*/
ID [a-zA-Z_][a-zA-Z0-9_]*
INVALID_ID [0-9]*[a-zA-Z0-9]*

/*numbers*/



/*strings*/
STRING ["][^"]*["]
UNFINISHED_STRING_ERROR ["][^"]*



DIGIT [0-9]
NUMBER [0-9]+
EXP [eE][ +-]?[0-9]+

FLOAT_NUM [0-9]+.[0-9]+
FLOAT_NUM_1 ({FLOAT_NUM})({EXP})
FLOAT_NUM_2 ({NUMBER})({EXP})
FLOAT_NUM_3 .({NUMBER})({FLOAT_NUM_1})
CONST_FLOAT ({FLOAT_NUM}|{FLOAT_NUM_2}|{FLOAT_NUM_3}|{FLOAT_NUM})
FLOAT_NUM_ERR1 [0-9]+.[.]+[0-9]+
FLOAT_NUM_ERR2 .[.]+[0-9]+
FLOAT_NUM_ERR3 [.]({CONST_FLOAT})
FLOAT_NUM_ERR4 [eE]({CONST_FLOAT})
FLOAT_NUM_ERR5 ([.]|({CONST_FLOAT}))*
FLOAT_ERR ({FLOAT_NUM_ERR1}|{FLOAT_NUM_ERR2}|{FLOAT_NUM_ERR3}|{FLOAT_NUM_ERR4}|{FLOAT_NUM_ERR5})
/*FLOATING POINTS
FRAC [0-9]+

/*constants*/















%%

{WHITESPACE}  {  }
{EMPTY_CHARACTER_ERROR}  {  fprintf(logFile, "Error: EMPTY character constant\n"); errorCount++; }
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
{FOR} { printf("for keyword\n");
        fprintf(tokenFile, "<FOR>\n");
        fprintf(logFile, "Line no %d: Token <FOR> Lexeme for found\n",lineNumber);}
{BREAK} { printf("break keyword\n");
        fprintf(tokenFile, "<BREAK>\n");
        fprintf(logFile, "Line no %d: Token <BREAK> Lexeme break found\n",lineNumber);}
{CONTINUE} { printf("continue keyword\n");
        fprintf(tokenFile, "<CONTINUE>\n");
        fprintf(logFile, "Line no %d: Token <CONTINUE> Lexeme continue found\n",lineNumber);}
{CASE} { printf("case keyword\n");
        fprintf(tokenFile, "<CASE>\n");
        fprintf(logFile, "Line no %d: Token <CASE> Lexeme case found\n",lineNumber);}
{DEFAULT} { printf("default keyword\n");
        fprintf(tokenFile, "<DEFAULT>\n");
        fprintf(logFile, "Line no %d: Token <DEFAULT> Lexeme default found\n",lineNumber);}
{SWITCH} { printf("switch keyword\n");
        fprintf(tokenFile, "<SWITCH>\n");
        fprintf(logFile, "Line no %d: Token <SWITCH> Lexeme switch found\n",lineNumber);}
{DO} { printf("do keyword\n");
        fprintf(tokenFile, "<DO>\n");
        fprintf(logFile, "Line no %d: Token <DO> Lexeme do found\n",lineNumber);}
{DOUBLE} { printf("double keyword\n");
        fprintf(tokenFile, "<DOUBLE>\n");
        fprintf(logFile, "Line no %d: Token <DOUBLE> Lexeme double found\n",lineNumber);}


{NUMBER} {printf("%s\n", yytext);
        fprintf(tokenFile, "<NUMBER %s>\n", yytext);
        fprintf(logFile, "Line no %d: Token <NUMBER %s> Lexeme %s found\n",lineNumber, yytext, yytext);}

{CONST_FLOAT} {
        fprintf(tokenFile, "<CONST_FLOAT %s>\n", yytext);
        fprintf(logFile, "Line no %d: Token <CONST_FLOAT %s> Lexeme %s found\n",lineNumber, yytext, yytext);}
{FLOAT_ERR} {
        fprintf(tokenFile, "<FLOAT_ERR %s>\n", yytext);
        fprintf(logFile, "Line no %d: Token <FLOAT_ERR %s> Lexeme %s found\n",lineNumber, yytext, yytext);
        errorCount++;}

{CONST_CHAR} {
  
        fprintf(tokenFile, "<CONST_CHAR %c>\n", yytext[1]);
        fprintf(logFile, "Line no %d: Token <CONST_CHAR %c> Lexeme %c found\n",lineNumber, yytext[1], yytext[1]);
        }
{CHAR_ERROR} {
        fprintf(tokenFile, "<CHAR_ERROR %s>\n", yytext);
        fprintf(logFile, "Line no %d: Token <CHAR_ERROR %s> Lexeme %s found\n",lineNumber, yytext, yytext);
        errorCount++;}
{UNFINISHED_CHAR_ERROR} {
        fprintf(tokenFile, "<UNFINISHED_CHAR_ERROR %s>\n", yytext);
        fprintf(logFile, "Line no %d: Token <UNFINISHED_CHAR_ERROR %s> Lexeme %s found\n",lineNumber, yytext, yytext);
        errorCount++;}
{MULTI_COMMENT}     {
                        
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
{INCOP}         {printf("%s matched in INCOP rule\n",yytext);
                    fprintf(tokenFile, "<%s %s>\n", "INCOP",yytext);
                    fprintf(logFile, "Line no %d: Token <%s %s> Lexeme %s found\n",lineNumber, "INCOP", yytext, yytext);}
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

{INVALID_ID}    {printf("%s matched in INVALID_ID rule\n",yytext);
                    fprintf(tokenFile, "<%s %s>\n", "INVALID_ID",yytext);   
                    fprintf(logFile, "Line no %d: Error: %s is not a valid identifier\n",lineNumber, yytext);
                    errorCount++;}


{STRING} 			{ yytext[0] = ' ';yytext[strlen(yytext)-1] = '\0';
                            fprintf(tokenFile, "<%s %s>\n", "STRING",yytext);
                    fprintf(logFile, "Line no %d: Token <%s %s> Lexeme %s found\n",lineNumber, "STRING", yytext, yytext); 
                        }
{UNFINISHED_STRING_ERROR} {
                        fprintf(tokenFile, "<%s %s>\n", "UNFINISHED_STRING_ERROR",yytext);
                    fprintf(logFile, "Line no %d: Error: Unfinished string\n",lineNumber);
                        errorCount++;}

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