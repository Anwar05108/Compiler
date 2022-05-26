#include "SymbolInfo.cpp"

class ScopeTable
{
private:
    /* data */
    SymbolInfo** bucket;
    int id;
    int size;
    int level;
    int maxLevel;
    ScopeTable *parentScope;
public:
    int smdbHash(string);
    ScopeTable(int);
    ~ScopeTable();
    bool insert(SymbolInfo*);
    SymbolInfo* search(SymbolInfo);
    void print();
    void print(int);
    void print(int,int);
    bool deleteSymbol(string);
};

ScopeTable::ScopeTable(int n)
{
    /* code */
    this->bucket = new SymbolInfo*[n];
    this->id = 0;
    this->size = n;
    this->level = 0;
    this->maxLevel = 0;
    this->parentScope = NULL;
    for (int i = 0; i < n; ++i)
    {
        /* code */
        this->bucket[i] = NULL;
    }
}

ScopeTable::~ScopeTable()
{
    /* code */
    for (int i = 0; i < this->size; ++i)
    {
        /* code */
        SymbolInfo *temp = this->bucket[i];
        while (temp != NULL)
        {
            /* code */
            SymbolInfo *temp2 = temp;
            temp = temp->getNext();
            delete temp2;
        }
    }
    delete[] this->bucket;
}

int ScopeTable::smdbHash(string str)
{
    int hash = 0;
    int len = str.length();
    for (int i = 0; i < len; i++)
    {
        hash = (hash << 4) + str[i];
        int x = hash & 0xF0000000;
        if (x != 0)
        {
            hash ^= (x >> 24);
        }
        hash &= ~x;
    }
    return hash;
}

bool ScopeTable::insert(SymbolInfo& symbol )
{
    /* code */
    string name = symbol.getName();
    string type = symbol.getType();

    int index = smdbHash(name) % this->size;
    SymbolInfo *temp = this->bucket[index];
    while (temp != NULL)
    {
        /* code */
        if (temp->getName() == name)
        {
            /* code */
            return false;
        }
        temp = temp->getNext();
    }
    SymbolInfo *newSymbol = new SymbolInfo(name,type);
    newSymbol->setNext(this->bucket[index]);
    this->bucket[index] = newSymbol;
    return true;
}

bool ScopeTable::deleteSymbol(string name)
{
    /* code */
    int index = smdbHash(name) % this->size;
    SymbolInfo *temp = this->bucket[index];
    SymbolInfo *prev = NULL;
    while (temp != NULL)
    {
        /* code */
        if (temp->getName() == name)
        {
            /* code */
            if (prev == NULL)
            {
                /* code */
                this->bucket[index] = temp->getNext();
            }
            else
            {
                /* code */
                prev->setNext(temp->getNext());
            }
            delete temp;
            return true;
        }
        prev = temp;
        temp = temp->getNext();
    }
    return false;
}


SymbolInfo* ScopeTable::search(SymbolInfo symbol)
{
    /* code */
    int index = smdbHash(symbol.getName()) % this->size;
    SymbolInfo *temp = this->bucket[index];
    while (temp != NULL)
    {
        /* code */
        if (temp->getName() == symbol.getName())
        {
            /* code */
            return temp;
        }
        temp = temp->getNext();
    }
    return NULL;
}
