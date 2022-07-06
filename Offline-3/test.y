%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "ScopeTable.cpp"
#include "SymbolTable.cpp"
// #include "SymbolInfo.cpp"
// #define YYSTYPE SymbolInfo*      /* yyparse() stack type */

SymbolTable symbolTable(30);

void yyerror(char *s){
	printf("%s\n",s);
}

int yylex(void);

%}



%token VOID NEWLINE NUMBER LESS GREATER EQUAL IF FOR ELSE WHILE BREAK CONTINUE CASE DEFAULT SWITCH DO
%token INCOP DECOP ASSIGNOP ADDOP MULOP RELOP BITOP LOGICOP LOGICNOT NOT LPAREN RPAREN LCURL RCURL LTHIRD RTHIRD
%token COMMA SEMICOLON 
%token INT FLOAT DOUBLE CHAR 
%token PLUS MINUS SLASH ASTERISK

%token<symbolInfo>ID
%token<symbolInfo>CONST_CHAR
%token<symbolInfo>CONST_INT
%token<symbolInfo>CONST_FLOAT





%%
input : {
    printf("hello\n");
}
%%

main()
{
    yyparse();
    exit(0);
}
