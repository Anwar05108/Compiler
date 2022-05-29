#include "SymbolTable.cpp"




int main()
{
    SymbolTable symbolTable = SymbolTable(5);
    symbolTable.insert("a", "int");
    
    symbolTable.enterScope(5);
    symbolTable.insert("c", "int");
    symbolTable.printAllScopes();
    symbolTable.exitScope();





    return 0;
}