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
NORMAL_CHAR [a-zA-Z0-9_#@%$&*+-/;]
CONST_CHAR  [']({NORMAL_CHAR}|{SPECIAL_CHAR})[']
CHAR_ERROR [']({NORMAL_CHAR}{NORMAL_CHAR}+)[']
/*comments*/
COMMENT "//".*
MULTI_COMMENT "/*"([^*]|\*+[^*/])*\*+"/"
UNFINISHED_CHAR_ERROR [']({NORMAL_CHAR}|{SPECIAL_CHAR})*
CHAR_GAP_ERROR [']({NORMAL_CHAR}|{SPECIAL_CHAR})*[ ]+[']
UNFINISHED_MULTI_COMMENT "/*"([^*]|\*+[^*/])*







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
{IF} { 
        fprintf(tokenFile, "<IF>\n");
        fprintf(logFile, "Line no %d: Token <IF> Lexeme if found\n",lineNumber);}
{ELSE} { 
        fprintf(tokenFile, "<ELSE>\n");
        fprintf(logFile, "Line no %d: Token <ELSE> Lexeme else found\n",lineNumber);}
{WHILE} {  
        fprintf(tokenFile, "<WHILE>\n");
        fprintf(logFile, "Line no %d: Token <WHILE> Lexeme while found\n",lineNumber);}
        
{RETURN} {  
        fprintf(tokenFile, "<RETURN>\n");
        fprintf(logFile, "Line no %d: Token <RETURN> Lexeme return found\n",lineNumber);}
{INT} {  
        fprintf(tokenFile, "<INT>\n");
        fprintf(logFile, "Line no %d: Token <INT> Lexeme int found\n",lineNumber);}
{VOID} {  
        fprintf(tokenFile, "<VOID>\n");
        fprintf(logFile, "Line no %d: Token <VOID> Lexeme void found\n",lineNumber);}
{FLOAT} {  
        fprintf(tokenFile, "<FLOAT>\n");
        fprintf(logFile, "Line no %d: Token <FLOAT> Lexeme float found\n",lineNumber);}
{CHAR} {  
        fprintf(tokenFile, "<CHAR>\n");
        fprintf(logFile, "Line no %d: Token <CHAR> Lexeme char found\n",lineNumber);}
{FOR} { 
        fprintf(tokenFile, "<FOR>\n");
        fprintf(logFile, "Line no %d: Token <FOR> Lexeme for found\n",lineNumber);}
{BREAK} { 
        fprintf(tokenFile, "<BREAK>\n");
        fprintf(logFile, "Line no %d: Token <BREAK> Lexeme break found\n",lineNumber);}
{CONTINUE} { 
        fprintf(tokenFile, "<CONTINUE>\n");
        fprintf(logFile, "Line no %d: Token <CONTINUE> Lexeme continue found\n",lineNumber);}
{CASE} { 
        fprintf(tokenFile, "<CASE>\n");
        fprintf(logFile, "Line no %d: Token <CASE> Lexeme case found\n",lineNumber);}
{DEFAULT} { 
        fprintf(tokenFile, "<DEFAULT>\n");
        fprintf(logFile, "Line no %d: Token <DEFAULT> Lexeme default found\n",lineNumber);}
{SWITCH} { 
        fprintf(tokenFile, "<SWITCH>\n");
        fprintf(logFile, "Line no %d: Token <SWITCH> Lexeme switch found\n",lineNumber);}
{DO} { 
        fprintf(tokenFile, "<DO>\n");
        fprintf(logFile, "Line no %d: Token <DO> Lexeme do found\n",lineNumber);}
{DOUBLE} { printf("double keyword\n");
        fprintf(tokenFile, "<DOUBLE>\n");
        fprintf(logFile, "Line no %d: Token <DOUBLE> Lexeme double found\n",lineNumber);}


{NUMBER} {symbolTable.insert(yytext,"CONST_INT");
        fprintf(tokenFile, "<CONST_INT %s>\n", yytext);
        fprintf(logFile, "Line no %d: Token <CONST_INT> Lexeme %s found\n",lineNumber, yytext);}

{CONST_FLOAT} {
        fprintf(tokenFile, "<CONST_FLOAT %s>\n", yytext);
        fprintf(logFile, "Line no %d: Token <CONST_FLOAT> Lexeme %s found\n",lineNumber, yytext);}
{FLOAT_ERR} {
        fprintf(logFile, "Line no %d: Token <FLOAT_ERR> Lexeme %s found\n",lineNumber, yytext);
        errorCount++;}

{CONST_CHAR} {
        symbolTable.insert(yytext, "CONST_CHAR");
        fprintf(tokenFile, "<CONST_CHAR %c>\n", yytext[1]);
        fprintf(logFile, "Line no %d: Token <CONST_CHAR> Lexeme %c found\n",lineNumber, yytext[1]);
        }
{CHAR_ERROR} {
        fprintf(logFile, "Line no %d: Multi charError  Lexeme %s found\n",lineNumber,  yytext);
        errorCount++;}
{UNFINISHED_CHAR_ERROR} {
        fprintf(logFile, "Line no %d: UNFINISHED_CHAR_ERROR  Lexeme %s found\n",lineNumber,  yytext);
        errorCount++;}
{CHAR_GAP_ERROR} {
        
        fprintf(logFile, "Line no %d: Error in character Lexeme %s found\n",lineNumber,  yytext);
        errorCount++;}
{MULTI_COMMENT}     {
                        fprintf(logFile, "Line no %d: Token <COMMENT> Lexeme %s found\n",lineNumber, yytext);
                        int i;
                        for(i = 0; i < strlen(yytext); i++)
                        {
                            if(yytext[i] == '\n')
                            {
                                lineNumber++;
                            }
                        }
                        }

{COMMENT}           {
                        fprintf(logFile, "Line no %d: Token <COMMENT> Lexeme %s found\n",lineNumber, yytext);}
{ADDOP} 			{
                    fprintf(tokenFile, "<%s %s>\n", "ADDOP",yytext);
                    fprintf(logFile, "Line no %d: Token <%s> Lexeme %s found\n",lineNumber, "ADDOP", yytext);}

{MULOP} 			{
                    fprintf(tokenFile, "<%s %s>\n", "MULOP",yytext);
                    fprintf(logFile, "Line no %d: Token <%s> Lexeme %s found\n",lineNumber, "MULOP", yytext);}
                            
{ASSIGNOP} 			{
                    fprintf(tokenFile, "<%s %s>\n", "ASSIGNOP",yytext);
                    fprintf(logFile, "Line no %d: Token <%s> Lexeme %s found\n",lineNumber, "ASSIGNOP",  yytext);}

{RELOP} 			{
                    fprintf(tokenFile, "<%s %s>\n", "RELOP",yytext);
                    fprintf(logFile, "Line no %d: Token <%s> Lexeme %s found\n",lineNumber, "RELOP",  yytext);}
{BITOP} 			{
                    fprintf(tokenFile, "<%s %s>\n", "BITOP",yytext);
                    fprintf(logFile, "Line no %d: Token <%s> Lexeme %s found\n",lineNumber, "BITOP",  yytext);}
{LOGICOP} 			{
                    fprintf(tokenFile, "<%s %s>\n", "LOGICOP",yytext);
                    fprintf(logFile, "Line no %d: Token <%s> Lexeme %s found\n",lineNumber, "LOGICOP",  yytext);}

{LOGICNOT} 			{
                    fprintf(tokenFile, "<%s %s>\n", "LOGICNOT",yytext);
                    fprintf(logFile, "Line no %d: Token <%s> Lexeme %s found\n",lineNumber, "LOGICNOT",  yytext);}
{INCOP}         {
                    fprintf(tokenFile, "<%s %s>\n", "INCOP",yytext);
                    fprintf(logFile, "Line no %d: Token <%s> Lexeme %s found\n",lineNumber, "INCOP",  yytext);}
{LPAREN} 			{
                    fprintf(tokenFile, "<%s %s>\n", "LPAREN",yytext);
                    fprintf(logFile, "Line no %d: Token <%s> Lexeme %s found\n",lineNumber, "LPAREN",  yytext);}
                    
{RPAREN} 			{
                    fprintf(tokenFile, "<%s %s>\n", "RPAREN",yytext);
                    fprintf(logFile, "Line no %d: Token <%s> Lexeme %s found\n",lineNumber, "RPAREN",  yytext);}
{LCURL} 			{
                    fprintf(tokenFile, "<%s %s>\n", "LCURL",yytext);
                    fprintf(logFile, "Line no %d: Token <%s %s> Lexeme %s found\n",lineNumber, "LCURL", yytext, yytext);
                    symbolTable.enterScope(7);
                    }


{RCURL} 			{
                    fprintf(tokenFile, "<%s %s>\n", "RCURL",yytext);
                    fprintf(logFile, "Line no %d: Token <%s> Lexeme %s found\n",lineNumber, "RCURL",  yytext);
                    symbolTable.exitScope();
                    }
                    
{LTHIRD} 			{
                        fprintf(tokenFile, "<%s %s>\n", "LTHIRD",yytext);
                        fprintf(logFile, "Line no %d: Token <%s> Lexeme %s found\n",lineNumber, "LTHIRD",  yytext);}

{RTHIRD} 			{
                        fprintf(tokenFile, "<%s %s>\n", "RTHIRD",yytext);
                        fprintf(logFile, "Line no %d: Token <%s> Lexeme %s found\n",lineNumber, "RTHIRD",  yytext);}
{COMMA} 			{
                        fprintf(tokenFile, "<%s %s>\n", "COMMA",yytext);
                        fprintf(logFile, "Line no %d: Token <%s> Lexeme %s found\n",lineNumber, "COMMA",  yytext);}
{SEMICOLON} 		{
                        fprintf(tokenFile, "<%s %s>\n", "SEMICOLON",yytext);
                        fprintf(logFile, "Line no %d: Token <%s> Lexeme %s found\n",lineNumber, "SEMICOLON",  yytext);}
{NEWLINE} 			{lineNumber++;}


{ID} 				{
                        fprintf(tokenFile, "<%s %s>\n", "ID",yytext);

                        fprintf(logFile, "Line no %d: Token <%s> Lexeme %s found\n",lineNumber, "ID",  yytext);
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

{INVALID_ID}    {
                    fprintf(tokenFile, "<%s %s>\n", "INVALID_ID",yytext);   
                    fprintf(logFile, "Line no %d: Error: %s is not a valid identifier\n",lineNumber, yytext);
                    errorCount++;}


{STRING} 			{ yytext[0] = ' ';yytext[strlen(yytext)-1] = '\0';
fprintf(tokenFile, "<%s %s>\n", "STRING",yytext);
                    fprintf(logFile, "Line no %d: Token <%s %s> Lexeme %s found\n",lineNumber, "STRING", yytext, yytext); 
                    int i ;
                            for(i = 0; yytext[i] != '\0'; i++)
                            {

                                if(yytext[i] == '\n')
                                {
                                    lineNumber++;
                                }
                            }
                            
                        }
{UNFINISHED_STRING_ERROR} {
                        fprintf(tokenFile, "<%s %s>\n", "UNFINISHED_STRING_ERROR",yytext);
                    fprintf(logFile, "Line no %d: Error: Unfinished string\n",lineNumber);
                        errorCount++;}
                        



. {}
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
	
    tokenFile=fopen("1805108_token.txt","w");
    if(tokenFile==NULL){
        printf("Cannot open token file\n");
        return 0;
    }

    logFile = fopen("1805108_log.txt","w");
    if(logFile==NULL){
        printf("Cannot open log file\n");
        return 0;
    }



	yyin= fin;
	yylex();
    symbolTable.printAllScopesInFile(logFile);
    fprintf(logFile, "Total number of errors: %d\n",errorCount);
    fprintf(logFile, "Total number of lines: %d\n",lineNumber);
	fclose(yyin);
    fclose(tokenFile);
    fclose(logFile);
	return 0;
}