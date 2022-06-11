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