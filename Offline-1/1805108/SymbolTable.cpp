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
    void enterScope( int );
    void exitScope();
    SymbolInfo* search(string);
    void printCurrentScope();
    void printAllScopes();
    ScopeTable* getParentScope();
    ScopeTable* getScopeTable();
};

SymbolTable::SymbolTable(int n)
{
    this->scopeTable = new ScopeTable(0,n, NULL);
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

void SymbolTable::enterScope(int size)
{
    int noChild = scopeTable -> getChild();
    scopeTable -> setChild(noChild + 1);
    // cout << "scope with id " << scopeTable-> getShowId() << " created" << endl;
    ScopeTable *newScopeTable = new ScopeTable(noChild, size, this->scopeTable);
    // scopeTable = new ScopeTable(id, size, scopeTable);


    // newScopeTable-> setParentScope(scopeTable);
    // newScopeTable -> setLevel(scopeTable->getLevel() + 1);
    // newScopeTable -> setMaxLevel(scopeTable->getMaxLevel());
    this->scopeTable = newScopeTable;

    // cout << "scope with " << id <<" created" << endl;
}

void SymbolTable:: exitScope()
{       
    cout << "scope with id " << scopeTable->getShowId() <<" removed" << endl;
    // ScopeTable *nextScope = 
    ScopeTable *temp = scopeTable;
     scopeTable = temp->getParentScope();
}

SymbolInfo* SymbolTable::search(string name)
{
    return scopeTable->search(name);
}

void SymbolTable::printCurrentScope()
{
    cout << "printing current scope" << endl;
    scopeTable->print();
}

void SymbolTable::printAllScopes()

{
    cout << "print all scopes" << endl;
    ScopeTable *temp = scopeTable;
    

    //temp = scopeTable;
    
    while (temp != NULL)
    {
        cout <<" ScopeTable: " << temp->getShowId() << endl;
        temp->print();
        temp = temp->getParentScope();
        cout<<endl;
    }
    // while (scopeTable != NULL)
    // {
    //     scopeTable->print();
    //     scopeTable = scopeTable->getParentScope();
    // }
    // {
    //     /* code */
    // }
    
    // scopeTable->printAllScopes();
}

bool SymbolTable::deletef(string name)
{
    return scopeTable->deleteSymbol(name);
}


ScopeTable* SymbolTable::getParentScope()
{
    return scopeTable->getParentScope();
}

ScopeTable* SymbolTable::getScopeTable()
{
    return scopeTable;
}
