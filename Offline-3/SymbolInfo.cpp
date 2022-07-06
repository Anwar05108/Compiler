#include "SymbolInfo.h"

SymbolInfo::SymbolInfo(string name,string type)
{
    
    this->next = NULL;
    this -> name = name;
    this -> type = type;

}

SymbolInfo::~SymbolInfo()
{
    
    // this->next = NULL;
}

void SymbolInfo::setNext(SymbolInfo* next)
{
    
    this->next = next;
}

SymbolInfo* SymbolInfo::getNext()
{
    
    return this->next;
}

string SymbolInfo::getName()
{
    
    return this->name;
}

string SymbolInfo::getType()
{
    
    return this->type;
}

void SymbolInfo::setName(string name)
{
    
    this->name = name;
}

void SymbolInfo::setType(string type)
{
    
    this->type = type;
}