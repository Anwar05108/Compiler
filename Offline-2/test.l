/*desinging a lexer using flex and bison*/

%option noyywrap

%{

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cassert>
#include <cstdarg>
#include <cstddef>

%}




/*operators*/

/*ADDOP  '+' | '-';
/*MULOP  '*' | '/';
/*RELOP  '<' | '>' | '=' | '<=' | '>=' | '!=';
/*ASSIGNOP  '=';

ADDOP [+-]
MULOP [*\/]
RELOP [<>=!]
ASSIGNOP [=]

/*KEWORD [if then else while do for todo end]
/*KEWORD [int float double char string bool]
/*KEWORD ["int" "float" "double" "char" "string" "bool"]


/*FLOATING POINTS
EXP [e|E][+|-]?[0-9]+
FRAC [0-9]+
FLOAT [0-9]+\.[0-9]+[e|E][+|-]?[0-9]+

SPECIAL_CHAR ("\t"|"\r"|"\b"|"\f"|"\n"|"\0"|"\v"|"\a"|"\\"|"\'")
COMMENT ("//"(([\\]+([\n]))|[\n]*)*)
MULTI_COMMENT ([^*]|("*"[^\n]))*"*/"





%%


{ADDOP} {printf("ADDOP\n");}
{MULOP} {printf("MULOP\n");}
{RELOP} {printf("RELOP\n");}
{ASSIGNOP} {printf("ASSIGNOP\n");}
. {printf("\n");}



%%


void main(int argc, char *argv[]){
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

}




   if(!symbolTable.search(yytext))
                        {
                            symbolTable.insert(yytext, "ID");
                            symbolTable.printAllScopesInFile(logFile);
                        }
                        else
                        {
                            fprintf(logFile, "Line no %d: Error: %s already declared\n",lineNumber, yytext);
                        }