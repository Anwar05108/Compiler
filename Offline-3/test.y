%{
#include<stdio.h>
#include<string.h>
#include"SymbolTable.h"

int lineCount = 1;
int errorCount = 0;

SymbolTable symbolTable(30);

FILE *errorFile, *logFile;

extern FILE *yyin;

int yyparse(void);
int yylex(void);

void yyerror(const char* str) {
    printf("Syntax error at line: %d : \"%s\" \n", lineCount, str);
}
    
%}

%union {
    SymbolInfo *symbolInfo;
}


%token VOID NEWLINE NUMBER LESS GREATER EQUAL IF FOR ELSE WHILE BREAK CONTINUE CASE DEFAULT SWITCH DO RETURN
%token INCOP DECOP ASSIGNOP ADDOP MULOP RELOP BITOP LOGICOP LOGICNOT NOT LPAREN RPAREN LCURL RCURL LTHIRD RTHIRD
%token COMMA SEMICOLON COLON
%token INT FLOAT DOUBLE CHAR 
%token PLUS MINUS SLASH ASTERISK

%token<symbolInfo>ID
%token<symbolInfo>CONST_CHAR
%token<symbolInfo>CONST_INT
%token<symbolInfo>CONST_FLOAT

%type <symbolInfo> start program unit 

%type <symbolInfo> variable_declaration function_declaration function_definition

%type <symbolInfo> statement_list statement parameter_list parameter_declaration
%type <symbolInfo> expression

%%


start: program
     {
    
     $$ = $1;
     
    printf("hello the program has started\n");
     
    printf("%s", $$->getName());
        }
    ;

program : program unit
            {
            $$ = new SymbolInfo( $1->getName() + $2->getName(),"SYMBOL_PROGRAM");
            printf("%s", $$->getName());
            }
        | unit
            {
            $$ = $1;
            printf("%s", $$->getName());
            }
            
            
        ;

unit : variable_declaration
        {
        $$ = $1;
        printf("%s", $$->getName());
        }
    | function_declaration
        {
        $$ = $1;
        printf("%s", $$->getName());
        }
    | function_definition
        {
        $$ = $1;
        printf("%s", $$->getName());
        }
    ;


variable_declaration : INT ID
                        {
                        $$ = new SymbolInfo($2->getName(), "SYMBOL_VARIABLE");
                        printf("%s", $$->getName());
                        }
                   
                    ;

function_declaration : INT ID LPAREN parameter_list RPAREN
                        {
                        $$ = new SymbolInfo($2->getName(), "SYMBOL_FUNCTION");
                        printf("%s", $$->getName());
                        }
                   
                    ;


function_definition : INT ID LPAREN parameter_list RPAREN LCURL statement_list RCURL
                        {
                        $$ = new SymbolInfo($2->getName(), "SYMBOL_FUNCTION");
                        printf("%s", $$->getName());
                        }
                    
                    ;

parameter_list : parameter_declaration
                    {
                    $$ = $1;
                    printf("%s", $$->getName());
                    }
                | parameter_list COMMA parameter_declaration
                    {
                    $$ = $1 ;
                    printf("%s", $$->getName());
                    }
                ;


parameter_declaration : INT ID
                        {
                        $$ = new SymbolInfo($2->getName(), "SYMBOL_PARAMETER");
                        printf("%s", $$->getName());
                        }
                    | FLOAT ID
                        {
                        $$ = new SymbolInfo($2->getName(), "SYMBOL_PARAMETER");
                        printf("%s", $$->getName());
                        }
                    | DOUBLE ID
                        {
                        $$ = new SymbolInfo($2->getName(), "SYMBOL_PARAMETER");
                        printf("%s", $$->getName());
                        }
                    | CHAR ID
                        {
                        $$ = new SymbolInfo($2->getName(), "SYMBOL_PARAMETER");
                        printf("%s", $$->getName());
                        }
                    ;


statement_list : statement
                    {
                    $$ = $1;
                    printf("%s", $$->getName());
                    }
                | statement_list statement
                    {
                    $$ = $1 ;
                    printf("%s", $$->getName());
                    }
                ;

statement : variable_declaration
            {
            $$ = $1;
            printf("%s", $$->getName());
            }
        | function_declaration
            {
            $$ = $1;
            printf("%s", $$->getName());
            }
        | function_definition
            {
            $$ = $1;
            printf("%s", $$->getName());
            }
        | expression
            {
            $$ = $1;
            printf("%s", $$->getName());
            }
        ;

expression : expression ADDOP expression
                {
                $$ = newSymbolInfo($1, "SYMBOL_ADD");
                printf("%s", $$->getName());
                }
           
            | expression MULOP expression
                {
                $$ = newSymbolInfo($1, "SYMBOL_MUL");
                printf("%s", $$->getName());
                }
            
            
            
            | expression LESS expression
                {
                $$ = newSymbolInfo($1, "SYMBOL_LESS");
                printf("%s", $$->getName());
                }
            | expression GREATER expression
                {
                $$ = newSymbolInfo($1, "SYMBOL_GREATER");   
                printf("%s", $$->getName());
                }
            
                ;

%%

int main(int argc, char *argv[]) {
    	if(argc!=2){
		printf("Please provide input file name and try again\n");
		return 0;
	}
	
	FILE *fin=fopen(argv[1],"r");
	if(fin==NULL){
		printf("Cannot open specified file\n");
		return 0;
	}
	
    errorFile=fopen("1805108_error.txt","w");
    if(errorFile==NULL){
        printf("Cannot open error file\n");
        return 0;
    }

    logFile = fopen("1805108_log.txt","w");
    if(logFile==NULL){
        printf("Cannot open log file\n");
        return 0;
    }

    // symbolTable.printAllScopesInFile(logFile);


	yyin= fin;
    yyparse();
    fclose(logFile);
    fclose(errorFile);
    return 0;
}