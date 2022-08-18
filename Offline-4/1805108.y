%{
#include<stdio.h>
#include<string.h>
#include"SymbolTable.cpp"
#include<fstream>
#include<iostream>
#include<bits/stdc++.h>

struct nodeVar{
    string name;
    string type;
    int arraySize;
}tempNodeVar;
int lineCount = 1;
int errorCount = 0;
int tempCount = 0;
int labelCount = 0;
vector<nodeVar> var_list_asm;

string newTemp(){
    stringstream ss;
    ss << "temp_" << tempCount++;
    nodeVar temp;
    temp.name = ss.str();
    temp.type = "int";
    temp.arraySize = 0;
    var_list_asm.push_back(temp);
    return ss.str();
}

string newLabel(){
    stringstream ss;
    ss << "label_" << labelCount++;
    return ss.str();
}

vector<string> split (string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}




struct nodeParam{
    string name;
    string type;
}tempNodeParam;


vector<nodeVar> variable_list;
vector<nodeParam> parameter_list;

SymbolTable symbolTable(30);

// FILE *errorFile, *logFile;
ofstream errorFile, logFile,asmFile;

extern FILE *yyin;
// extern ifstream yyin;

int yyparse(void);
int yylex(void);

void yyerror(const char* str) {
}
    
%}

%define parse.error verbose

%union {
    SymbolInfo *symbolInfo;
}


%token VOID NEWLINE NUMBER LESS GREATER EQUAL IF FOR ELSE WHILE BREAK CONTINUE CASE DEFAULT SWITCH DO RETURN
%token INCOP DECOP ASSIGNOP LOGICNOT NOT LPAREN RPAREN LCURL RCURL LTHIRD RTHIRD
%token COMMA SEMICOLON COLON PRINTLN
%token INT FLOAT DOUBLE CHAR 
%token PLUS MINUS SLASH ASTERISK

%token<symbolInfo>ADDOP 
%token<symbolInfo>MULOP
%token<symbolInfo>RELOP
%token<symbolInfo>BITOP
%token<symbolInfo>LOGICOP



%token<symbolInfo>ID
%token<symbolInfo>CONST_CHAR
%token<symbolInfo>CONST_INT
%token<symbolInfo>CONST_FLOAT

%type <symbolInfo> start program unit 

%type <symbolInfo> variable_declaration function_declaration function_definition declaration_list

%type <symbolInfo> statement_list  parameter_list 
%type <symbolInfo> expression compound_statement logic_expression rel_expression simple_expression term factor
%type <symbolInfo> type_specifier
%type<symbolInfo> unary_expression variable argument_list arguments
%type <symbolInfo> statement expression_statement

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE


%%


start: program
    {
     $$ = $1;
     logFile << "line number" << lineCount << ": " ;
     asmFile << ".model small\n";
     asmFile << ".stack 100h\n\n";
    asmFile << ".data\n\n";
    asmFile << "print_var dw ?\n";

    for(int i = 0; i < var_list_asm.size(); i++){
        if(var_list_asm[i].arraySize == 0 || var_list_asm[i].arraySize == -1){
            asmFile << var_list_asm[i].name << " dw ?\n";
        }
        else{
            asmFile << var_list_asm[i].name << " dw "+ to_string(var_list_asm[i].arraySize)+"\n";
        }
    }

    asmFile << ".code\n\n";

    asmFile << "println proc near\n";
    asmFile << "\tpush ax\n";
    asmFile << "\tpush bx\n";
    asmFile << "\tpush cx\n";
    asmFile << "\tpush dx\n\n";
    // asmFIle << ""

    asmFile << "\tmov ax, print_var\n";
    asmFile << "\tor ax, ax\n";
    asmFile << "\tjge end_if_1\n";
    asmFile << "\tpush ax\n";
    asmFile << "\tmov dl, '-'\n";
    asmFile << "\tmov ah, 2\n";
    asmFile << "\tint 21h\n";
    asmFile << "\tpop ax\n";
    asmFile << "\tneg ax\n\n";
    
    asmFile << "end_if_1:\n";
    asmFile << "\txor cx,cx\n";
    asmFile << "\tmov bx,10d\n\n";

    asmFile << "loop_1:\n";
    asmFile << "\txor dx, dx\n";
    asmFile << "\tdiv bx\n";
    asmFile << "\tpush dx\n";
    asmFile << "\tinc cx\n";
    asmFile << "\tor ax,ax\n";
    asmFile << "\tjne loop_1\n";
    asmFile << "\tmov ah, 2\n\n";

    asmFile << "loop_2:\n";
    asmFile << "\tpop dx\n";
    asmFile << "\tor dl, 30h\n";
    asmFile << "\tint 21h\n";
    asmFile << "\tloop loop_2\n\n";
    
    asmFile << "\tmov dl, 0dh\n";
    asmFile << "\tmov ah, 2\n";
    asmFile << "\tint 21h\n\n";

    asmFile << "\tmov dl, 0ah\n";
    asmFile << "\tmov ah, 2\n";
    asmFile << "\tint 21h\n\n";

    asmFile << "\tpop dx\n";
    asmFile << "\tpop cx\n";
    asmFile << "\tpop bx\n";
    asmFile << "\tpop ax\n";

    asmFile << "\tret\n\n";
    asmFile << "println endp\n\n";

    // asmFile << 
    asmFile << $$->getAsmCodes();
    logFile << $$->getAsmCodes() << endl;
    

    logFile << "start: program" << endl;
    // symbolTable.printAllScopes();
    
    }
    
    ;

program : program unit
            {
            $$ = new SymbolInfo( $1->getName() +"\n" +$2->getName(),"SYMBOL_PROGRAM");
            $$ -> setAsmCodes($1->getAsmCodes() + $2->getAsmCodes());
            logFile << "line number" << lineCount << ": " ;
            logFile << "program: program unit \n\n" << $$->getName() << endl<<endl;
            }
        | unit
            {
            $$ = $1;
            logFile << "line number" << lineCount << ": " ;
            logFile << "program:  unit \n\n" << $$->getName() << endl<<endl;
            }
            
            
        ;

unit : variable_declaration
        {
        $$ = $1;
        logFile << "line number" << lineCount << ": " ;
        logFile << "unit: variable_declaration \n\n" << $$->getName() << endl<<endl;
        // symbolTable.printAllScopesInFile(logFile);

        }
    | function_declaration
        {
        $$ = $1;
        logFile << "line number" << lineCount << ": " ;
        logFile << "unit: function_declaration \n\n" << $$->getName() << endl<<endl;

        }
    | function_definition
        {
        $$ = $1;
        logFile << "line number" << lineCount << ": " ;
        logFile << "unit: function_definition \n\n" << $$->getName() << endl<<endl;


        }
    ;

function_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON
                        {
                        
                      $$ = new SymbolInfo($1->getName()+" "+ $2->getName()+"("+$4->getName()+");", "function_declaration");
                        string functionName = $2->getName();
                        string functionType = $1->getName();
                        if(symbolTable.search(functionName) == NULL)
                        {
                            symbolTable.insert(functionName, functionType);
                            $$->setDefined(false);
                        }
                        else
                        {
                            errorCount++;
                        logFile << "line number" << lineCount << ": " ;
                            
                            logFile << "error: function "<<functionName<<" already declared\n\n";
                            errorFile << "error: function "<<functionName<<" already declared\n";
                        }
                        // symbolTable.printCurrentScope();
                        logFile << "line number" << lineCount << ": " ;
                        logFile << "func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON";
                        logFile << endl<<endl;
                        logFile << $$->getName();
                        logFile << endl << endl;

                        SymbolInfo *temp = symbolTable.search(functionName);
                        if(temp == NULL)
                        {
                            errorFile<<"error: function "<<functionName<<" not found\n";
                        }
                        else
                        {
                            temp->setDefined(false);
                            temp->setArraySize(-2);

                        for(int i = 0; i < parameter_list.size(); i++)
                        {
                            string parameterName = parameter_list[i].name;
                            string parameterType = parameter_list[i].type;
                            temp->insertParameter(parameterName, parameterType);
                        }
                        }

                      
                       
                        parameter_list.clear();
                        
                        }
                    |   type_specifier ID LPAREN  RPAREN SEMICOLON
                    {
                        $$ = new SymbolInfo($1->getName()+" "+ $2->getName()+"();", "SYMBOL_FUNCTION");
                        string functionName = $2->getName();
                        string functionType = $1->getName();
                        if(symbolTable.search(functionName) == NULL)
                        {
                            symbolTable.insert(functionName, functionType);
                            SymbolInfo *temp = symbolTable.search(functionName);
                            temp->setDefined(false);
                            temp->setArraySize(-2);
                            // $$->setDefined(false);
                        }
                        else
                        {
                            errorCount++;
                        logFile << "line number" << lineCount << ": " ;
                            
                            logFile << "error: function "<<functionName<<" already declared\n\n";
                            errorFile << "error: function "<<functionName<<" already declared\n";
                        }
                        parameter_list.clear();
                        // symbolTable.printCurrentScope();
                        logFile << "line number" << lineCount << ": " ;
                        logFile << "func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON";
                        logFile << endl<<endl;
                        logFile << $$->getName();
                        logFile << endl << endl;

                        }                                   
                    ;


function_definition : type_specifier ID LPAREN parameter_list RPAREN  
                        
                        {
                        string functionName = $2->getName();
                        string functionType = $1->getName();
                        SymbolInfo* function = symbolTable.search(functionName);
                        if(symbolTable.search(functionName) == NULL)
                        {
                            symbolTable.insert(functionName, functionType);
                            SymbolInfo *temp = symbolTable.search(functionName);
                            temp->setArraySize(-2);
                            temp->setDefined(true);
                            // $$->setDefined(true);
                            symbolTable.enterScope(30);
                            // logFile << "size of parameter list: " << parameter_list.size() << endl;
                            for(int i = 0; i < parameter_list.size(); i++)
                            {
                                // logFile << "parameter_list: " << parameter_list[i].name << " " << parameter_list[i].type << endl;
                                string parameterName = parameter_list[i].name;
                                string parameterType = parameter_list[i].type;
                                symbolTable.insert(parameterName, parameterType);
                            }
                        }
                        else
                        {
                            if(function->getDefined() == false)
                            {
                                symbolTable.insert(functionName, functionType);
                                 function->setArraySize(-2);
                            function->setDefined(true);
                                // $$->setDefined(true);
                            }
                            else
                            {
                                errorCount++;
                                logFile << "line number" << lineCount << ": " ;
                                logFile << "error: function "<<functionName<<" already defined\n\n";
                                errorFile << "line number" << lineCount << ": " ;
                                
                                errorFile << "error: function "<<functionName<<" already defined\n";
                            }
                        

                        SymbolInfo *temp = symbolTable.search(functionName);
                       symbolTable.enterScope(30);

                       if(temp != NULL){

                        for(int i = 0; i < temp->getParamSize(); i++ ){
                            string declaredParameterName = temp->getParameterName(i);
                            string declaredParameterType = temp->getParameterType(i);

                            
                       
                            string definedParameterName = parameter_list[i].name;
                            string definedParameterType = parameter_list[i].type;
                            if(declaredParameterType != definedParameterType ){
                                errorCount++;
                                logFile << "line number" << lineCount << ": " ;
                                logFile << "error: parameter "<<definedParameterName<<" has wrong type as declared\n\n";
                                errorFile << "error: parameter "<<definedParameterName<<" has wrong type as declared\n";
                            }else{
                             symbolTable.insert(definedParameterName, definedParameterType);
                            }
                        }}
                    }
                        // symbolTable.printAllScopesInFile(logFile);
                        // logFile<<"enterScope";
                        parameter_list.clear();
                        // logFile << "line number" << lineCount << ": " ;
                        // logFile << "func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement"<<endl<<endl;
                        // logFile <<$$->getName()<< endl<<endl;
                        


                        }
                        compound_statement{
                        $$ = new SymbolInfo($1->getName()+" "+$2->getName()+" ( " +$4->getName()+" ) "+$7->getName() + "\n"  , "SYMBOL_FUNCTION");
                        string functionName = $2->getName();
                        cout << "functionName: " << functionName << endl;
                        string functionType = $1->getName();
                        string asmCodes = "";
                        SymbolInfo* function = symbolTable.search(functionName);
                        cout << function;
                        if(function != NULL){
                            if(functionName == "main"){
                                asmCodes    +=   "MAIN PROC\n";
                                asmCodes   += "MOV AX, @DATA\n";
                                asmCodes   += "MOV DS, AX\n";
                                // asmCodes   += "MOV AX, @BSS\n";

                                // asmCodes = $7->getName();
                                asmCodes += "\tMOV AX, 4C00h\n";
                                asmCodes += "\tINT 21h\n";
                                asmCodes += "MAIN ENDP\n";
                                asmCodes += "END MAIN\n";





                            }
                            else{
                                asmCodes    = functionName+ "PROC "+"\n";
                                asmCodes += "\tPOP BP\n";
                                // asmCodes += paramete recieved code
                                asmCodes += "\tPUSH BP\n";
                                asmCodes = $7->getAsmCodes();
                                asmCodes += "\tPUSH BP\n";
                                asmCodes += "\tRET\n";
                                asmCodes += functionName+ "ENDP\n";
                                
                                
                            }
                        }
                                $$->setAsmCodes(asmCodes);
                                // asmFile << $$->getAsmCodes();
                                // asmFile << endl;
                                // asmFile << asmCodes;

                        logFile << "line number" << lineCount << ": " ;
                        logFile << "func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement"<<endl<<endl;
                        logFile <<$$->getName()<< endl<<endl;
                        }
                    |
                    type_specifier ID LPAREN RPAREN 
                    {
                        string functionName = $2->getName();
                        string functionType = $1->getName();
                        if(symbolTable.search(functionName) == NULL)
                        {

                            symbolTable.insert(functionName, functionType);
                            SymbolInfo *temp = symbolTable.search(functionName);
                            temp->setDefined(false);
                            temp->setArraySize(-2);

                        }
                        else
                        {
                                if(symbolTable.search(functionName)->getDefined() == false)
                                {
                                    symbolTable.insert(functionName, functionType);
                                    SymbolInfo *temp = symbolTable.search(functionName);
                                    temp->setDefined(false);
                                    temp->setArraySize(-2);
                                }
                                else
                                {
                                    errorCount++;
                                    logFile << "line number" << lineCount << ": " ;
                                    logFile << "error: function "<<functionName<<" already defined\n\n";
                                errorFile << "line number" << lineCount << ": " ;

                                    errorFile << "error: function "<<functionName<<" already defined\n";
                                }
                        }
                        symbolTable.enterScope(30);
                        
                    }
                    compound_statement{
                        $$ = new SymbolInfo($1->getName()+" "+$2->getName()+" ( ) "+$6->getName() + "\n"  , "SYMBOL_FUNCTION");
                        string functionName = $2->getName();
                        string asmCodes = "";
                        SymbolInfo* function = symbolTable.search(functionName);
                        
                            if(functionName == "main"){
                                asmCodes    +=   "MAIN PROC\n";
                                asmCodes   += "MOV AX, @DATA\n";
                                asmCodes   += "MOV DS, AX\n";
                                // asmCodes   += "MOV AX, @BSS\n";
                                asmCodes += $6->getAsmCodes();
                                asmCodes += "MOV AX, 4C00h\n";
                                asmCodes += "INT 21h\n";
                                asmCodes += "MAIN ENDP\n";
                                asmCodes += "END MAIN\n";
                            }
                            else{
                                asmCodes    = functionName+ "PROC "+"\n";
                                asmCodes += "\tPOP BP\n";
                                // asmCodes += paramete recieved code
                                asmCodes += "\tPUSH BP\n";
                                asmCodes = $6->getAsmCodes();
                                asmCodes += "\tPUSH BP\n";
                                asmCodes += "\tRET\n";
                                asmCodes += functionName+ "ENDP\n";
                                
                                
                            }

                            $$->setAsmCodes(asmCodes);
                            
                        
                        logFile << "line number" << lineCount << ": " ;
                        logFile << "func_definition : type_specifier ID LPAREN RPAREN compound_statement"<<endl<<endl;
                        logFile <<$$->getName()<< endl<<endl;
                    }
                    ;


parameter_list : parameter_list COMMA type_specifier ID
                    
                    {
                    $$ = new SymbolInfo($1->getName() + "," + $3->getName() + " " + $4->getName(), "SYMBOL_PARAMETER");
                    logFile << "line number" << lineCount << ": " ;
                    logFile << "parameter_list : parameter_list COMMA type_specifier ID"<<endl<<endl ;
                    logFile<< $$->getName() << endl<<endl;
                    tempNodeParam.name = $4->getName();
                    tempNodeParam.type = $3->getName();
                    parameter_list.push_back(tempNodeParam);
                    
                    }
                | parameter_list COMMA type_specifier
                    {
                    $$ = new SymbolInfo($1->getName() + "," + $3->getName(), "SYMBOL_PARAMETER");
                    logFile << "line number" << lineCount << ": " ;
                    logFile << "parameter_list : parameter_list COMMA type_specifier"<<endl<<endl ;
                    logFile<< $$->getName() << endl<<endl;
                    tempNodeParam.name = "";
                    tempNodeParam.type = $3->getName();
                    parameter_list.push_back(tempNodeParam);


                    }
                | type_specifier ID
                    {
                    $$ = new SymbolInfo($1->getName() + " " + $2->getName(), "SYMBOL_PARAMETER");
                    logFile << "line number" << lineCount << ": " ;
                    logFile << "parameter_list : type_specifier ID"<<endl<<endl ;
                    logFile<< $$->getName() << endl<<endl;
                    tempNodeParam.name = $2->getName();
                    tempNodeParam.type = $1->getName();
                    parameter_list.push_back(tempNodeParam);
                    
                    }
                | type_specifier
                    {
                    $$ = new SymbolInfo($1->getName(), "SYMBOL_PARAMETER");
                    logFile << "line number" << lineCount << ": " ;
                    logFile << "parameter_list : type_specifier"<<endl<<endl ;
                    logFile<< $$->getName() << endl<<endl;

                    tempNodeParam.name = "";
                    tempNodeParam.type = $1->getType();
                    parameter_list.push_back(tempNodeParam);
                    
                    }
                ;







compound_statement : LCURL statement_list RCURL{
    $$ = new SymbolInfo("{\n"+$2->getName()+"\n}", "SYMBOL_COMPOUND_STATEMENT");
    $$->setAsmCodes($2->getAsmCodes());
    logFile << "line number" << lineCount << ": " ;
    logFile << "compound_statement : LCURL statement_list RCURL"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
    symbolTable.printAllScopesInFile(logFile);
    symbolTable.exitScope();
    
}
| LCURL RCURL {
    $$ = new SymbolInfo("{\n}", "SYMBOL_COMPOUND_STATEMENT");
    logFile << "line number" << lineCount << ": " ;
    logFile << "compound_statement : LCURL RCURL"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}
;

variable_declaration : type_specifier declaration_list SEMICOLON
                        {

                            string variable_name = $2->getName();
                            string variable_type = $1->getName();
                            if(variable_type == "void"){
                                errorCount++;
                                errorFile << "line number" << lineCount << ": " ;
                                errorFile << "variable_declaration: void type is not allowed" << endl;
                                logFile << "line number" << lineCount << ": " ;
                                logFile << "variable_declaration: void type is not allowed" << endl;
                            }
                            else{
                                for(int i = 0;i < variable_list.size();i++){
                                    symbolTable.insert(variable_list[i].name, $1->getName());
                                    var_list_asm.push_back(variable_list[i]);
                                    string global_name = variable_list[i].name ;
                                    // + (symbolTable.getScopeTable())->getShowId();
                                        SymbolInfo *temp = symbolTable.search(variable_list[i].name);
                                    if(variable_list[i].arraySize > 0){
                                        if(temp != NULL){
                                            temp->setArraySize(variable_list[i].arraySize);
                                        }
                                        // temp->setArraySize(variable_list[i].arraySize);
                                        logFile << "array size of " << variable_list[i].name << " is " << temp->getArraySize() << endl;
                                    }
                                   
                                        if(temp != NULL){
                                            cout << global_name << endl;
                                            temp->setAsmName(global_name);
                                            cout << "temp-getAsm"<<temp->getAsmName() << endl;
                                            // cout 
                                        }
                                   
                                   
                                }
                            }

                            variable_list.clear();

                       
                        
                        $$ = new SymbolInfo($1->getName() + " " +$2->getName()+";", $1->getType());
                        logFile << "line number" << lineCount << ": " ;
                        logFile << "variable_declaration: type_specifier declaration_list SEMICOLON \n\n" << $$->getName() << endl<<endl;

                        }
                   
                    ;

type_specifier : INT
                {
                $$ = new SymbolInfo("int", "int");
                logFile << "line number" << lineCount << ": " ;
                logFile << "type_specifier : INT"<<endl<<endl ;
                logFile << $$->getName() << endl<<endl;

                }
            | FLOAT
                {
                $$ = new SymbolInfo("float", "float");
                logFile << "line number" << lineCount << ": " ;
                logFile << "type_specifier : FLOAT"<<endl<<endl ;
                logFile << $$->getName() << endl<<endl;

                }
            | DOUBLE
                {
                $$ = new SymbolInfo("double", "double");
                logFile << "line number" << lineCount << ": " ;
                logFile << "type_specifier : DOUBLE"<<endl<<endl ;
                logFile << $$->getName() << endl<<endl;

                }
            | VOID
                {
                $$ = new SymbolInfo("void", "VOID");
                logFile << "line number" << lineCount << ": " ;
                logFile << "type_specifier : VOID"<<endl<<endl ;
                logFile << $$->getName() << endl<<endl;

                }
            ;






declaration_list : declaration_list COMMA ID

            {
$$ = new SymbolInfo($1->getName() + "," +$3->getName(), $3->getType());
   tempNodeVar.name = $3->getName();
    tempNodeVar.type = $3->getType();
    tempNodeVar.arraySize = -1;
    variable_list.push_back(tempNodeVar);
    if(symbolTable.search($3->getName()) != NULL)
    {
        errorFile << "line number" << lineCount << ": " ;
        errorFile << "error: variable " << $3->getName() << " already declared" << endl;
        errorCount++;
    }
    
    logFile << "line number" << lineCount << ": " ;
    logFile << "declaration_list: declaration_list COMMA ID \n\n" << $$->getName() << endl<<endl;
            }
| declaration_list COMMA ID LTHIRD CONST_INT RTHIRD
{
$$ = new SymbolInfo($1->getName() + "," +$3->getName()+"["+$5->getName()+"]", $3->getType());
    tempNodeVar.name = $3->getName();
    tempNodeVar.type = "array";

    tempNodeVar.arraySize = stoi($5->getName());
    variable_list.push_back(tempNodeVar);
    if(symbolTable.search($3->getName()) != NULL)
    {
        errorFile << "line number" << lineCount << ": " ;
        errorFile << "error: variable " << $3->getName() << " already declared" << endl;
        errorCount++;
    }
    logFile << "line number" << lineCount << ": " ;
    logFile << "declaration_list: declaration_list COMMA ID LTHIRD CONST INT RTHIRD \n\n" << $$->getName() << endl<<endl;
}
| ID
{
$$ = new SymbolInfo($1->getName(), $1->getType());
    tempNodeVar.name = $1->getName();
    $$->setAsmName($1->getAsmName());
    // SymbolInfo *temp; 
    // temp = symbolTable.search($1->getName());
    string type = "";
    //  type =  temp->getType();
    tempNodeVar.type = type;
    tempNodeVar.arraySize = -1;
        variable_list.push_back(tempNodeVar);
    // SymbolInfo *temp = symbolTable.search($1->getName());
    // temp ->setAsmName($1->getAsmName());
    if(symbolTable.search($1->getName()) != NULL)
    {
        errorFile << "line number" << lineCount << ": " ;
        errorFile << "error: variable " << $1->getName() << " already declared" << endl;
        errorCount++;
    }
    logFile << "line number" << lineCount << ": " ;
    logFile << "declaration_list: ID \n\n" << $$->getName() << endl<<endl;
}
| ID LTHIRD CONST_INT RTHIRD{
    $$ = new SymbolInfo($1->getName() + " [" + $3->getName()+"]", $1->getType());
    tempNodeVar.name = $1->getName();
    tempNodeVar.type = "array";
    tempNodeVar.arraySize = stoi($3->getName());
    

    variable_list.push_back(tempNodeVar);
    if(symbolTable.search($1->getName()) != NULL)
    {
        errorFile << "line number" << lineCount << ": " ;
        errorFile << "error: variable " << $1->getName() << " already declared" << endl;
        errorCount++;
    }

   
    
    logFile << "line number" << lineCount << ": " ;
    logFile << "declaration_list: ID LTHIRD CONST INT RTHIRD \n\n" << $$->getName() << endl<<endl;
}
;


statement_list : statement
                    {
                    $$ = $1;
                    logFile << "line number" << lineCount << ": " ;
                    logFile << "statement_list : statement"<<endl<<endl ;
                    logFile<< $$->getName() << endl<<endl;
                    }
                | statement_list statement
                    {
                    $$ = new SymbolInfo($1->getName() + "\n" + $2->getName(), "SYMBOL_STATEMENT_LIST");
                    $$->setAsmCodes($1->getAsmCodes() + $2->getAsmCodes());
                    logFile << "line number" << lineCount << ": " ;
                    logFile << "statement_list : statement_list statement"<<endl<<endl ;
                    logFile<< $$->getName() << endl<<endl;
                    }
                ;

statement : variable_declaration
            {
            $$ = $1;
            logFile << "line number" << lineCount << ": " ;
            logFile << "statement : variable_declaration"<<endl<<endl ;
            logFile<< $$->getName() << endl<<endl;

            }
        | expression_statement
            {
            $$ = $1;
            logFile << "line number" << lineCount << ": " ;
            logFile << "statement : expression_statement"<<endl<<endl ;
            logFile<< $$->getName() << endl<<endl;
            }
        | {symbolTable.enterScope(30);}compound_statement
            {
            $$ = $2;
            logFile << "line number" << lineCount << ": " ;
            logFile << "statement : compound_statement"<<endl<<endl ;
            logFile<< $$->getName() << endl<<endl;
            }
        | FOR LPAREN expression_statement expression_statement expression
    RPAREN statement
    {
    $$ = new SymbolInfo("for("+$3->getName()+$4->getName()+")"+$5->getName(), "SYMBOL_FOR_STATEMENT");
    string asmCodes = "";
    string initCode = $3->getAsmCodes();
    string conditonAsm = $4 -> getAsmName();
    string conditionCode = $4 -> getAsmCodes();
    string incrementCode = $5 -> getAsmCodes();
    string bodyCode = $7 -> getAsmCodes();
    // cout << $7 -> getType() << endl;
    // cout << $7-> getAsmCodes() << endl;
    // cout << $3->getName() << endl;
    // cout << $3->getAsmCodes() << endl;
    cout << initCode << endl;


    string firstStatement = $3 -> getName();
    string secondStatement = $4 -> getName();

    asmCodes += initCode;
    if(firstStatement != ";" && secondStatement != ";"){
        string label1 = newLabel();
        string label2 = newLabel();

        asmCodes += label1 + ": \n" + conditionCode  ;
        asmCodes += "mov ax, " + conditonAsm  + "\n";
        asmCodes += "\tcmp ax, 0\n";
        asmCodes += "\tje " + label2 + "\n";

        asmCodes += bodyCode;
        asmCodes += incrementCode;
        asmCodes += "jmp " + label1 + "\n";
        asmCodes += label2 + ": \n";

    }

    $$ -> setAsmCodes(asmCodes);

    logFile << "line number" << lineCount << ": " ;
    logFile << "statement : FOR LPAREN expression statement expression statement expression RPAREN statement"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
    }
        | WHILE LPAREN expression RPAREN statement
            {

                string bodyCode = $5 -> getAsmCodes();
                string conditionCode = $3 -> getAsmCodes();
                string conditonAsm = $3 -> getAsmName();

                string label1 = newLabel();
                string label2 = newLabel();

                string asmCodes = "";
                asmCodes += label1 + ": \n" + conditionCode  ;
                asmCodes += "\tmov ax, " + conditonAsm  + "\n";
                asmCodes += "\tcmp ax, 0\n";
                asmCodes += "\tje " + label2 + "\n";

                asmCodes += bodyCode;
                asmCodes += "jmp " + label1 + "\n";
                asmCodes += label2 + ": \n";

            $$ = new SymbolInfo("while("+$3->getName()+")"+$5->getName(), "SYMBOL_WHILE_STATEMENT");
            $$ -> setAsmCodes(asmCodes);
            logFile << "line number" << lineCount << ": " ;
            logFile << "statement : WHILE LPAREN expression RPAREN statement"<<endl<<endl ;
            logFile<< $$->getName() << endl<<endl;
            }
        | IF LPAREN expression RPAREN statement %prec LOWER_THAN_ELSE
            {
            $$ = new SymbolInfo("if("+$3->getName()+")"+$5->getName(), "SYMBOL_IF_STATEMENT");
            string asmCodes = "";
            string conditionCode = $3 -> getAsmCodes();
            string conditonAsm = $3 -> getAsmName();
            string bodyCode = $5 -> getAsmCodes();
            string label = newLabel();
            asmCodes += conditionCode;
            asmCodes += "mov ax, " + conditonAsm  + "\n";
            asmCodes += "\tcmp ax, 0\n";
            asmCodes += "\tje " + label + "\n";
            asmCodes += bodyCode;
            asmCodes += label + ": \n";
            $$ -> setAsmCodes(asmCodes);

            logFile << "line number" << lineCount << ": " ;
            logFile << "statement : IF LPAREN expression RPAREN statement"<<endl<<endl ;
            logFile<< $$->getName() << endl<<endl;
            }
        | IF LPAREN expression RPAREN statement ELSE statement
            {
                string asmCodes = "";
            string conditionCode = $3 -> getAsmCodes();
            string conditonAsm = $3 -> getAsmName();
            string bodyCodeIf = $5 -> getAsmCodes();
            string bodyCodeElse = $7 -> getAsmCodes();
            string label1 = newLabel();
            string label2 = newLabel();
            asmCodes += conditionCode;
            asmCodes += "mov ax, " + conditonAsm  + "\n";
            asmCodes += "\tcmp ax, 0\n";
            asmCodes += "\tje " + label1 + "\n";
            asmCodes += bodyCodeIf;
            asmCodes += "jmp " + label2 + "\n";
            asmCodes += label1 + ": \n";
            asmCodes += bodyCodeElse;
            asmCodes += label2 + ": \n";
            $$ = new SymbolInfo("if("+$3->getName()+")"+$5->getName()+"else"+$7->getName(), "SYMBOL_IF_STATEMENT");
            $$ -> setAsmCodes(asmCodes);
            logFile << "line number" << lineCount << ": " ;
            logFile << "statement : IF LPAREN expression RPAREN statement ELSE statement"<<endl<<endl ;
            logFile<< $$->getName() << endl<<endl;
            }
        | RETURN expression SEMICOLON
            {
            $$ = new SymbolInfo ("return "+$2->getName()+";", "SYMBOL_RETURN_STATEMENT");
            string asmCodes = "";
            string expressionCode = $2 -> getAsmCodes();
            string expressionAsm = $2 -> getAsmName();
            asmCodes += expressionCode;
            asmCodes += "\tpop bp\n";
            asmCodes += "\tpush " + expressionAsm + "\n";
            // asmCodes += "mov ax, " + expressionAsm  + "\n";
            // asmCodes += "\tmov [bp - 4], ax\n";
            // asmCodes += "\tjmp [bp - 8]\n";
            $$ -> setAsmCodes(asmCodes);
            logFile << "line number" << lineCount << ": " ;
            logFile << "statement : RETURN expression"<<endl<<endl ;
            logFile<< $$->getName() << endl<<endl;
            }   
        | PRINTLN LPAREN ID RPAREN SEMICOLON
            {
                SymbolInfo *temp = symbolTable.search($3->getName());
            if(symbolTable.search($3->getName()) == NULL)
            {
                errorFile << "line number" << lineCount << ": " ;
                errorFile << "error: variable " << $3->getName() << " not declared" << endl;
                errorCount++;
            }
            else
            {
                if(temp != NULL){
               if(temp->getArraySize() == -2){
                    errorFile << "line number" << lineCount << ": " ;
                    errorFile << "error: variable " << $3->getName() << " is a function" << endl;
                    errorCount++;
                }
               }}
            
            string asmCode = "";
            asmCode += "\tmov ax, " + $3->getName() + "\n";
            asmCode += "\tmov print_var , ax\n";
            asmCode += "\tcall println\n";

            

            
            $$ = new SymbolInfo ("println("+$3->getName()+");", "statement");
            $$ -> setAsmCodes(asmCode);
            logFile << "line number" << lineCount << ": " ;
            logFile << "statement : PRINTLN LPAREN expression RPAREN SEMICOLON"<<endl<<endl ;
            logFile<< $$->getName() << endl<<endl;
            }   
        ;



expression_statement :  SEMICOLON
                        {
                        $$ = new SymbolInfo(";", "SYMBOL_EXPRESSION_STATEMENT");
                        
                        }
            | expression SEMICOLON
                        {
                        $$ = new SymbolInfo($1->getName()+";", "SYMBOL_EXPRESSION_STATEMENT");
                        $$ -> setAsmCodes($1->getAsmCodes());
                        $$ -> setAsmName($1->getAsmName());
                        
                        logFile << "line number" << lineCount << ": " ;
                        logFile << "expression_statement : expression SEMICOLON"<<endl<<endl ;
                        logFile<< $$->getName() << endl<<endl;
                        }
                    ;

variable : ID{
    SymbolInfo *temp = symbolTable.search($1->getName());
    if(temp != NULL){

    $$ = new SymbolInfo($1->getName(), temp->getType());
    $$ -> setAsmName(temp->getAsmName());
    }
    else{
        $$ = new SymbolInfo($1->getName(), "undeclared");
    }
    cout << "variable "<<$1->getName()<<": ID" << $1->getAsmName()<<endl;
    logFile << "line number" << lineCount << ": " ;
    logFile << "variable : ID"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;

}
| ID LTHIRD expression RTHIRD{
    SymbolInfo *currentId = symbolTable.search($1->getName());
    string globalName;
    if(currentId == NULL)
    {
        errorFile << "line number" << lineCount << ": " ;
        errorFile << "error: variable " << $1->getName() << " not declared" << endl;
        errorCount++;
    }
    else{
     globalName = currentId-> getAsmName();
     if(currentId->getArraySize() < 0)
    {
        errorFile << "line number" << lineCount << ": " ;
        errorFile << "error: variable " << $1->getName() << " is not an array" << endl;
        errorCount++;
    }
    else{
     if(currentId->getArraySize() <= stoi($3->getName()))
    {
        errorFile << "line number" << lineCount << ": " ;
        errorFile << "error: variable " << $1->getName() << " is out of range. array size: " << currentId->getArraySize() << endl;
        errorCount++; 
    }
     if($3->getType() != "int")
    {
        errorFile << "line number" << lineCount << ": " ;
        errorFile << "error: index of variable " << $1->getName() << " is not of type INT" << endl;
        errorCount++;
    }}}
    
    $$ = new SymbolInfo($1->getName()+"["+$3->getName()+"]", $1->getType());
     string asmCodes = "";
    string temp = newTemp();
    string expressionCode = $3->getAsmCodes();
    string expressionAsm = $3->getAsmName();
    asmCodes += expressionCode;
   asmCodes += "\tmov si, " + expressionAsm + "\n";
   asmCodes += "\tadd si,si\n";
    asmCodes += "\tmov ax, " + globalName + "[si]\n";
    temp = globalName + "["+ expressionAsm +"]";
    $$->setAsmCodes(asmCodes);
    $$->setAsmName(temp);
    logFile << "line number" << lineCount << ": " ;
    logFile << "variable : ID LTHIRD expression RTHIRD"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
};


expression : logic_expression{
    $$ = $1;
    logFile << "line number" << lineCount << ": " ;
    logFile << "expression : logic expression"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}

| variable ASSIGNOP logic_expression{
    // logFile << $1->getType()<< $3->getType() << endl;
    // logFile << $3->getName() << endl;
    // logFile << $3->getArraySize() << endl;
    // logFile << $3->getArraySize() << endl;
    // SymbolInfo *leftVar = symbolTable.search($1->getName());
    // SymbolInfo *rightVar = symbolTable.search($3->getName());
    if($1->getType() == "undeclared" || $3->getType() == "undeclared")
    {
      if($1->getType() == "undeclared"){
        errorFile << "line number" << lineCount << ": " ;
        errorFile << "error: variable " << $1->getName() << " not declared" << endl;
        errorCount++;
    }
    if($3->getType() == "undeclared"){
        errorFile << "line number" << lineCount << ": " ;
        errorFile << "error: variable " << $3->getName() << " not declared" << endl;
        errorCount++;
    } 
    }  
    else if((($1->getType() == "int") || ($3->getType() == "float")) && (($3->getType() == "int") || ($1->getType() == "float"))){
        if($1->getArraySize()>0){
        if($3 -> getArraySize() == -1){
            errorFile << "line number" << lineCount << ": " ;
            errorFile << "error: variable " << $1->getName()<<" "<<$1->getType() << " is an array and cannot be assigned to a variable" << endl;
            errorCount++;
        }
    }
    else if($1->getType() != $3->getType())
    {
        errorFile << "line number" << lineCount << ": " ;
        errorFile << "error: variable " << $1->getName()<<" "<<$1->getType() << " is not of type " << $3->getType() << endl;
        errorCount++;
    }
    }
    
   
    
    
    // if($1->getArraySize() != -1 && $3->getArraySize() == -1)
    // {
    //     errorFile << "line number" << lineCount << ": " ;
    //     errorFile << "error: variable " << $1->getName() << " is an array and cannot be assigned to" << endl;
    //     errorCount++;
    // }
    // if($1->getArraySize() == -1 && $3->getArraySize() != -1)
    // {
    //     errorFile << "line number" << lineCount << ": " ;
    //     errorFile << "error: variable " << $1->getName() << " is not an array and cannot be assigned to" << endl;
    //     errorCount++;
    // }
   
    $$ = new SymbolInfo($1->getName()+"="+$3->getName(), "SYMBOL_ASSIGNMENT_EXPRESSION");
     string asmCodes = "";
    string lefAsm = $1->getAsmName();
    cout << $1->getName() << endl;
    cout << $1->getAsmName() << endl;

    string rightAsm = $3->getAsmName();
    string leftCode = $1->getAsmCodes();
    string rightCode = $3->getAsmCodes();
    asmCodes += leftCode;
    asmCodes += rightCode;
    asmCodes += "\tmov ax," + rightAsm  + "\n";
    asmCodes += "\tmov " + lefAsm + ", ax\n";

    // string temp = newTemp();
    $$->setAsmCodes(asmCodes);
    $$->setAsmName(lefAsm);
    logFile << "line number" << lineCount << ": " ;
    logFile << "expression : variable ASSIGNOP logic expression"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}
;

logic_expression : rel_expression {
    $$ = $1;
    logFile << "line number" << lineCount << ": " ;
    logFile << "logic_expression : rel_expression"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}
| rel_expression LOGICOP rel_expression {
    string type = "int";
    if($1->getType() != "int" || $3->getType() != "int")
    {
        type = "error";
        errorFile << "line number" << lineCount << ": " ;
        errorFile << "error: operands of logical operator are not of type INT" << endl;
        errorCount++;
    }
   
    $$ = new SymbolInfo($1->getName()+$2->getName()+$3->getName(), type);
     string asmCodes = "";
    string leftAsm = $1->getAsmName();
    string rightAsm = $3->getAsmName();
    string leftCode = $1->getAsmCodes();
    string rightCode = $3->getAsmCodes();
    asmCodes += leftCode;
    asmCodes += rightCode;
    string temp = newTemp();
    string return0 = newLabel();
    string return1 = newLabel();
    string logicOperator = $2->getName();
    if(logicOperator == "&&"){
        asmCodes += "\tmov ax, " + leftAsm + "\n";
        asmCodes += "\tcmp ax, 0\n";
        asmCodes += "\tje " + return0 + "\n";
        asmCodes += "\tmov ax, " + rightAsm + "\n";
        asmCodes += "\tcmp ax, 0\n";
        asmCodes += "\tje " + return1 + "\n";
        asmCodes += "\tmov ax, 1\n";
        asmCodes += "\tmov " + temp + ", ax\n";
        asmCodes += "\tjmp " + return1 + "\n";
        asmCodes += return0 + ":\n";
        asmCodes += "\tmov ax, 0\n";
        asmCodes += "\tmov " + temp + ", ax\n";
        asmCodes += return1 + ":\n";
    }
    else if(logicOperator == "||"){
        asmCodes += "\tmov ax, " + leftAsm + "\n";
        asmCodes += "\tcmp ax, 0\n";
        asmCodes += "\tjne " + return0 + "\n";
        asmCodes += "\tmov ax, " + rightAsm + "\n";
        asmCodes += "\tcmp ax, 0\n";
        asmCodes += "\tjne " + return0 + "\n";
        asmCodes += "\tmov ax, 0\n";
        asmCodes += "\tmov " + temp + ", ax\n";
        asmCodes += "\tjmp " + return1 + "\n";
        asmCodes += return0 + ":\n";
        asmCodes += "\tmov ax, 1\n";
        asmCodes += "\tmov " + temp + ", ax\n";
        asmCodes += return1 + ":\n";
    }

    // string temp = newTemp();
    $$->setAsmCodes(asmCodes);
    $$->setAsmName(temp);
    logFile << "line number" << lineCount << ": " ;
    logFile << "logic_expression : logic_expression AND rel_expression"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
};



rel_expression : simple_expression
{
    $$ = $1;
    logFile << "line number" << lineCount << ": " ;
    logFile << "expression : simple expression"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}
| simple_expression RELOP simple_expression{
    $$ = new SymbolInfo($1->getName()+$2->getName()+$3->getName(), $1->getType());
     string asmCodes = "";
    string temp = newTemp();
    string lefAsm = $1->getAsmName();
    string rightAsm = $3->getAsmName();
    string leftCode = $1->getAsmCodes();
    string rightCode = $3->getAsmCodes();
    string return0 = newLabel();
    string return1 = newLabel();
    asmCodes += leftCode;
    asmCodes += rightCode;
    asmCodes += "\tmov ax, " + lefAsm + "\n";
    asmCodes += "\tcmp ax, " + rightAsm + "\n";

    string relOperator = $2->getName();
    if(relOperator == "=="){
        asmCodes += "\tje " + return1 + "\n";
        asmCodes += "\tmov ax, 0\n";
        asmCodes += "\tmov " + temp + ", ax\n";
        asmCodes += "\tjmp " + return0 + "\n";
        asmCodes += return1 + ":\n";
        asmCodes += "\tmov ax, 1\n";
        asmCodes += "\tmov " + temp + ", ax\n";
        asmCodes += return0 + ":\n";
    }
    else if(relOperator == "!="){
        asmCodes += "\tjne " + return1 + "\n";
        asmCodes += "\tmov ax, 0\n";
        asmCodes += "\tmov " + temp + ", ax\n";
        asmCodes += "\tjmp " + return0 + "\n";
        asmCodes += return1 + ":\n";
        asmCodes += "\tmov ax, 1\n";
        asmCodes += "\tmov " + temp + ", ax\n";
        asmCodes += return0 + ":\n";
    }
   
    else if(relOperator == "<"){
        asmCodes += "\tjl " + return1 + "\n";
        asmCodes += "\tmov ax, 0\n";
        asmCodes += "\tmov " + temp + ", ax\n";
        asmCodes += "\tjmp " + return0 + "\n";
        asmCodes += return1 + ":\n";
        asmCodes += "\tmov ax, 1\n";
        asmCodes += "\tmov " + temp + ", ax\n";
        asmCodes += return0 + ":\n";
    }
   else if(relOperator == ">"){
        asmCodes += "\tjg " + return1 + "\n";
        asmCodes += "\tmov ax, 0\n";
        asmCodes += "\tmov " + temp + ", ax\n";
        asmCodes += "\tjmp " + return0 + "\n";
        asmCodes += return1 + ":\n";
        asmCodes += "\tmov ax, 1\n";
        asmCodes += "\tmov " + temp + ", ax\n";
        asmCodes += return0 + ":\n";
    }
    else if(relOperator == "<="){
        asmCodes += "\tjle " + return1 + "\n";
        asmCodes += "\tmov ax, 0\n";
        asmCodes += "\tmov " + temp + ", ax\n";
        asmCodes += "\tjmp " + return0 + "\n";
        asmCodes += return1 + ":\n";
        asmCodes += "\tmov ax, 1\n";
        asmCodes += "\tmov " + temp + ", ax\n";
        asmCodes += return0 + ":\n";
    }
    else if(relOperator == ">="){
        asmCodes += "\tjge " + return1 + "\n";
        asmCodes += "\tmov ax, 0\n";
        asmCodes += "\tmov " + temp + ", ax\n";
        asmCodes += "\tjmp " + return0 + "\n";
        asmCodes += return1 + ":\n";
        asmCodes += "\tmov ax, 1\n";
        asmCodes += "\tmov " + temp + ", ax\n";
        asmCodes += return0 + ":\n";
    }
    $$->setAsmCodes(asmCodes);
    $$->setAsmName(temp);
    logFile << "line number" << lineCount << ": " ;
    logFile << "expression : simple_expression RELOP simple_expression"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;

};

simple_expression : term{
    $$ = $1;
    logFile << "line number" << lineCount << ": " ;
    logFile << "simple_expression : term"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}
|simple_expression ADDOP term
{
    //problem in getting the plus and minus
    string type;
    if($1->getType() == "int" && $3->getType() == "int")
    {
        type = "int";
    }
    else
    {
        type = "float";
    }
    $$ = new SymbolInfo($1->getName()+$2->getName()+$3->getName(), type);
     string asmCodes = "";
    
    string lefAsm = $1->getAsmName();
    string rightAsm = $3->getAsmName();
    string leftCode = $1->getAsmCodes();
    string rightCode = $3->getAsmCodes();
    string addOperator = $2->getName();
    asmCodes += leftCode;
        asmCodes += rightCode;
    string temp = newTemp();

    if(addOperator == "+"){
        
        asmCodes += "\tmov ax, " + lefAsm + "\n";
        asmCodes += "\tadd ax, " + rightAsm + "\n";
        asmCodes += "\tmov " + temp + ", ax\n";
    }
    else if(addOperator == "-"){
        
        asmCodes += "\tmov ax, " + lefAsm + "\n";
        asmCodes += "\tsub ax, " + rightAsm + "\n";
        asmCodes += "\tmov " + temp + ", ax\n";
    }
    $$->setAsmCodes(asmCodes);
    $$->setAsmName(temp);
    logFile << "line number" << lineCount << ": " ;
    logFile << "simple_expression : simple_expression ADDOP term"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}
;

term : unary_expression {
    $$ = $1;
    logFile << "line number" << lineCount << ": " ;
    logFile << "term : unary_expression"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}
 | term MULOP unary_expression{

    string leftType = $1->getType();
    string rightType = $3->getType();
    string mulOperator = $2->getName();
    string type;
    if(mulOperator == "%"){
        if(leftType != "int" || rightType != "int"){
            errorFile << "line number" << lineCount << ": " ;
            errorFile << "error: modulo mulOperator can only be used with ints" << endl;
            errorCount++;
        }
    }
    else if(mulOperator == "*" || mulOperator == "/"){
        if(leftType != "int" || rightType != "int"){
            type = "float";
            
        }
    }

    if(mulOperator == "/" ){
        if($3->getName() == "0"){
            errorFile << "line number" << lineCount << ": " ;
            errorFile << "error: division by zero" << endl;
            errorCount++;
        }
    }

    if( mulOperator == "%"){
        if($3->getName() == "0"){
            errorFile << "line number" << lineCount << ": " ;
            errorFile << "error: modulo by zero" << endl;
            errorCount++;
        }
    }
    
    
    string asmCodes = "";
    string lefAsm = $1->getAsmName();
    string rightAsm = $3->getAsmName();
    string leftCode = $1->getAsmCodes();
    string rightCode = $3->getAsmCodes();
    // string mulOperator = $2->getName();
    string temp = newTemp();
    asmCodes += leftCode;
    asmCodes += rightCode;

    if(mulOperator == "*"){
        
        asmCodes += "\tmov ax, " + lefAsm + "\n";
        asmCodes += "mov bx, " + rightAsm + "\n";
        asmCodes += "\timul bx\n";
        asmCodes += "\tmov " + temp + ", ax\n";
    }
    else if(mulOperator == "/"){
        
        asmCodes += "\tmov ax, " + lefAsm + "\n";
        asmCodes += "\tcwd\n";
        asmCodes += "\tmov bx, " + rightAsm + "\n";
        asmCodes += "\tidiv bx\n";
        // asmCodes += "\tdiv ax, " + rightAsm + "\n";
        asmCodes += "\tmov " + temp + ", ax\n";
    }
    else if(mulOperator == "%"){
        
        asmCodes += "\tmov ax, " + lefAsm + "\n";
        asmCodes += "\tcwd\n";
        asmCodes += "\tmov bx, " + rightAsm + "\n";
        asmCodes += "\tidiv bx\n";
        asmCodes += "\tmov " + temp + ", dx\n";
    }
    $$ = new SymbolInfo($1->getName()+$2->getName()+$3->getName(), type);
    $$->setAsmCodes(asmCodes);
    $$->setAsmName(temp);
    logFile << "line number" << lineCount << ": " ;
    logFile << "term : term MULOP unary_expression"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}
;

unary_expression: ADDOP unary_expression
{
    $$ = new SymbolInfo($1->getName()+$2->getName(), $2->getType());
    string asmCodes = "";
    string temp ;
    string addOperator = $1->getName();
    string unaryExpressionAsm = $2->getAsmName();
    string unaryExpressionCode = $2->getAsmCodes();
    if(addOperator == "+"){
       temp = unaryExpressionAsm;
       asmCodes = unaryExpressionCode;
    }
    else if(addOperator == "-"){
        temp = newTemp();
        asmCodes += unaryExpressionCode;

        asmCodes += "\tmov ax, " + unaryExpressionAsm + "\n";
        asmCodes += "\tmov " + temp + ", ax\n";
        asmCodes += "\tneg "+temp+"\n";
    }
    $$->setAsmCodes(asmCodes);
    $$->setAsmName(temp);
    logFile << "line number" << lineCount << ": " ;
    logFile << "expression : ADDOP unary expression"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}
| NOT unary_expression
{
    $$ = new SymbolInfo(" !"+$2->getName(), $2->getType());
    string asmCodes = "";
    string temp = newTemp();
    string unaryExpressionAsm = $2->getAsmName();
    string unaryExpressionCode = $2->getAsmCodes();

    string return0 = newLabel();
    string return1 = newLabel();

    asmCodes += unaryExpressionCode;
    asmCodes += "\tmov ax, " + unaryExpressionAsm + "\n";
    asmCodes += "\tcmp ax, 0\n";
    asmCodes += "\tje " + return1 + "\n";
    asmCodes += "\tmov ax, 0\n";
    asmCodes += "\tmov " + temp + ", ax\n";
    asmCodes += "\tjmp " + return0 + "\n";

    asmCodes += return1 + ":\n";
    asmCodes += "\tmov ax, 1\n";
    asmCodes += "\tmov " + temp + ", ax\n";
    asmCodes += return0 + ":\n";

    $$->setAsmCodes(asmCodes);
    $$->setAsmName(temp);
    logFile << "line number" << lineCount << ": " ;
    logFile << "expression : NOT unary_expression"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}
| factor
{
    $$ = $1;
    logFile << "line number" << lineCount << ": " ;
    logFile << "unary_expression : factor"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}
;


factor : variable
{
    $$ = $1;
    logFile << "line number" << lineCount << ": " ;
    logFile << "factor : variable\n\n" ;
    logFile<< $$->getName() << "\n\n";
}
 | ID LPAREN argument_list RPAREN
{
    // cout << "factor : ID LPAREN argument_list RPAREN"<<endl;
    SymbolInfo *func = symbolTable.searchInGlobalScope($1->getName());
    string type = "";
    if(func == NULL){
        errorFile << "line number" << lineCount << ": " ;
        errorFile << "error: function " << $1->getName() << " not declared" << endl;
        errorCount++;
        type = "undeclared";
    }
    else{
        type = func->getType();
        if(func->getArraySize() != -2){
            errorFile << "line number" << lineCount << ": " ;
            errorFile << "error: " << $1->getName() << " is not a function" << endl;
            errorCount++;
        }
        else{
            string argument_name_list = $3->getName();
            string argument_type_list = $3->getType();
            
            // cout << "argument_name_list: " << argument_name_list << endl;
            // cout << "argument_type_list: " << argument_type_list << endl;
            vector<string> argument_name_vector = split(argument_name_list, ",");
            vector<string> argument_type_vector = split(argument_type_list, ",");
            
           if(argument_name_vector.size() != func->getParamSize()){
                // cout << "argument size:"<<argument_type_vector.size() << endl;
                // cout << func->getParamSize() << endl;
                errorFile << "line number" << lineCount << ": " ;
                errorFile << "error: function " << $1->getName() << " expects " << func->getParamSize() << " arguments" << endl;
                errorCount++;
            }
            else{
                for(int i = 0; i < argument_name_vector.size(); i++){
                    // cout << "argument_name_vector: " << argument_name_vector[i] << endl;
                    // cout << "argument_type_vector: " << argument_type_vector[i] << endl;
                    // cout << "func->getParameterName"<< func->getParameterName(i) << endl;
                    // cout << "func->getParamType(i): " << func->getParameterType(i) << endl;

                    if(argument_type_vector[i] != func->getParameterType(i)){
                        errorFile << "line number" << lineCount << ": " ;
                        errorFile << "error: function " << $1->getName() << " expects " << func->getParameterType(i) << " as argument " << i+1 << endl;
                        errorCount++;
                    }
                }
            }
           }
        }
        
    
    string argument_asm_list = $3->getAsmName();
    vector<string> argument_asm_vector = split(argument_asm_list, ",");

    $$ = new SymbolInfo($1->getName()+" ( "+$3->getName()+" )",type );
    string temp = newTemp();;
    string asmCodes = "";

    string funcName = $1->getName();

    asmCodes += "\tpush ax\n";
    asmCodes += "\tpush bx\n";
    asmCodes += "\tpush cx\n";
    asmCodes += "\tpush dx\n";

    int asmSize = argument_asm_vector.size();
    for(int i = 0; i < asmSize; i++){
        asmCodes += "\tpush , " + argument_asm_vector[i] + "\n";
        // asmCodes += "\tmov [bp-" + to_string(i*2) + "], ax\n";
    }
    asmCodes += "\tcall " + funcName + "\n";
    
    asmCodes += "\tpop " + temp + "\n";
    asmCodes += "\tpop dx\n";
    asmCodes += "\tpop cx\n";
    asmCodes += "\tpop bx\n";
    asmCodes += "\tpop ax\n";

    $$->setAsmCodes(asmCodes);
    $$->setAsmName(temp);
    logFile << "line number" << lineCount << ": " ;
    logFile << "factor : ID LPAREN argument_list RPAREN"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}
| LPAREN expression RPAREN
{
    $$ = new SymbolInfo(" ( "+$2->getName()+" ) ", $2->getType());
    $$->setAsmCodes($2->getAsmCodes());
    $$->setAsmName($2->getAsmName());
    logFile << "line number" << lineCount << ": " ;
    logFile << "factor : LPAREN expression RPAREN"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}
| CONST_INT
{
    $$ = yylval.symbolInfo;
    $$-> setAsmName(yylval.symbolInfo->getName());
    logFile << "line number" << lineCount << ": " ;
    logFile << "factor : CONST_INT"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}
| CONST_FLOAT{
    $$ = yylval.symbolInfo;
    $$-> setAsmName(yylval.symbolInfo->getName());

    logFile << "line number" << lineCount << ": " ;
    logFile << "factor : CONST_FLOAT"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}

| variable INCOP
{
    $$ = new SymbolInfo($1->getName()+"++", $1->getType());
     string asmCodes = "";
    string temp = newTemp();
    string varCode = $1->getAsmCodes();
    string varAsmName = $1->getAsmName();
    asmCodes += varCode;
    asmCodes += "\tmov ax ,"  + varAsmName + "\n";
    asmCodes += "\tmov " + temp + ", ax\n";
    asmCodes += "\tinc "+ varAsmName + "\n";

    $$->setAsmCodes(asmCodes);
    $$ -> setAsmName(temp);
    logFile << "line number" << lineCount << ": " ;
    logFile << "factor : variable INCOP"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}

| variable DECOP
{
    $$ = new SymbolInfo($1->getName()+"--", $1->getType());
    string asmCodes = "";
    string temp = newTemp();
    string varCode = $1->getAsmCodes();
    string varAsmName = $1->getAsmName();
    asmCodes += varCode;
    asmCodes += "\tmov ax,"  + varAsmName + "\n";
    asmCodes += "\tmov " + temp + ", ax\n";
    asmCodes += "\tdec a"+ varAsmName + "\n";

    $$->setAsmCodes(asmCodes);
    $$ -> setAsmName(temp);
    logFile << "line number" << lineCount << ": " ;
    logFile << "factor : variable DECOP"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}


;



argument_list : arguments{
    $$ = $1;
    logFile << "line number" << lineCount << ": " ;
    logFile << "argument_list : arguments"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}
| 
{
    $$ = new SymbolInfo("", "SYMBOL_ARGUMENT_LIST");
    $$ -> setAsmName("");
    logFile << "line number" << lineCount << ": " ;
    logFile << "argument_list :"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}
;

 arguments: arguments COMMA logic_expression
{
    $$ = new SymbolInfo($1->getName()+","+$3->getName(), $1->getType()+","+$3->getType());
    string asmCodes = $1->getAsmCodes()+$3->getAsmCodes();
    $$->setAsmCodes(asmCodes);
    $$->setAsmName($1->getAsmName()+","+$3->getAsmName());
    logFile << "line number" << lineCount << ": " ;
    logFile << "argument_list : arguments COMMA logic_expression"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}
| logic_expression
{
    $$ = $1;
    // $$ = new SymbolInfo($1->getName(), "SYMBOL_ARGUMENTS");
    logFile << "line number" << lineCount << ": " ;
    logFile << "argument_list : logic_expression"<<endl<<endl ;
    logFile<< $$->getName() << endl<<endl;
}
;










%%

int main(int argc, char *argv[]) {
    #ifdef YYDEBUG
    yydebug = 1;
    #endif
    	if(argc!=2){
		return 0;
	}
	

    FILE *fin = fopen(argv[1], "r");
	if(fin==NULL){
		return 0;
	}
	
    errorFile.open("1805108_error.txt");
    if(!errorFile){
        return 0;
    }

    logFile.open("1805108_log.txt");
    if(!logFile){
        return 0;
    }

    asmFile.open("1805108_asm.asm");
    if(!asmFile){
        return 0;
    }

    



	yyin = fin;
    yyparse();
    symbolTable.printAllScopesInFile(logFile);
    logFile << "total no. of errors: " << errorCount << endl;
    logFile << "total no. of lines" << lineCount << endl;
   
    logFile.close();
    errorFile.close();
    asmFile.close();
    
    return 0;
}