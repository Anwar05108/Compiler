#include "ScopeTable.cpp"
// #include "SymbolInfo.cpp"

class SymbolTable
{
private:
    ScopeTable *scopeTable;
public:
    SymbolTable(int);
    ~SymbolTable();
    bool insert(string, string);
    bool deletef(string);
    void enterScope(int, int );
    void exitScope();
    SymbolInfo* search(string);
    void printCurrentScope();
    void printAllScopes();
};

SymbolTable::SymbolTable(int n)
{
    this->scopeTable = new ScopeTable(0, n, NULL);
}


SymbolTable::~SymbolTable()
{
}

bool SymbolTable::insert(string name, string type)
{
    return scopeTable->insert(name, type);
}

// bool SymbolTable::delete(SymbolInfo info)
// {
//     return scopeTable->deleteSymbol(info.getName());
// }

void SymbolTable::enterScope(int id, int size)
{
    scopeTable = new ScopeTable(id, size, scopeTable);
    // cout << "scope with " << id <<" created" << endl;
}

void SymbolTable:: exitScope()
{
     scopeTable = scopeTable->getParentScope();
}

SymbolInfo* SymbolTable::search(string name)
{
    return scopeTable->search(name);
}

void SymbolTable::printCurrentScope()
{
    scopeTable->print();
}

void SymbolTable::printAllScopes()
{
    scopeTable->printAllScopes();
}

bool SymbolTable::deletef(string name)
{
    return scopeTable->deleteSymbol(name);
}
