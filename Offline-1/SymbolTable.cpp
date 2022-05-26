#include "ScopeTable.cpp"
#include "SymbolInfo.cpp"

class SymbolTable
{
private:
    ScopeTable *scopeTable;
public:
    SymbolTable(/* args */);
    ~SymbolTable();
    bool insert(SymbolInfo);
    bool delete(SymbolInfo);
};

SymbolTable::SymbolTable(/* args */)
{
}

SymbolTable::~SymbolTable()
{
}

bool SymbolTable::insert(SymbolInfo info)
{
    return scopeTable->insert(info);
}
