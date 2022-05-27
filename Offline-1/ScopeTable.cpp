// #include "SymbolTable.cpp"
#include "SymbolInfo.cpp"

using namespace std;

class ScopeTable
{
private:
    /* data */
    SymbolInfo** bucket;
    int id;
    int size;
    int level = 0;
    int maxLevel;
    int child, sibling;


    // int 
    
    ScopeTable *parentScope;
    int smdbHash(string);


public:
    ScopeTable(int,int , ScopeTable*);
    ~ScopeTable();
    bool insert(string, string);
    SymbolInfo* search(string);
    void print();
    // void print(int);
    // void print(int,int);
    void printAllScopes();
    bool deleteSymbol(string);
    ScopeTable* getParentScope();
    void setParentScope(ScopeTable*);
    int getId();
    int getLevel();
    int getMaxLevel();
    void setMaxLevel(int);
    void setLevel(int);
    int getChild();
    int getSibling();
    void setChild(int);
    void setSibling(int);
};

ScopeTable::ScopeTable(int sibling, int n, ScopeTable *parentScope)
{
    /* code */
    // this-> level = ;
    this->id = sibling + 1;
    this -> child = 0;
    
    this->size = n;
    this->parentScope = parentScope;
    this->bucket = new SymbolInfo*[n];
    for (int i = 0; i < n; i++)
    {
        /* code */
        this->bucket[i] = NULL;
    }
    cout << "scope with id " << id <<" created and parentScope is"<< parentScope << endl;
}


ScopeTable::~ScopeTable()
{
    /* code */
    for (int i = 0; i < this->size; i++)
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

bool ScopeTable::insert(string name, string type )
{
    /* code */
    // string name = symbol.getName();
    // string type = symbol.getType();

    int index = smdbHash(name) % this->size;
    SymbolInfo* temp = bucket[index];
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
    cout << "Inserted " << name << " " << type << " in scope " << this->id <<" in index "<<  index << endl;
    // cout << "in bucket " << index << endl;
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


SymbolInfo* ScopeTable::search(string name)
{
    /* code */
    int index = smdbHash(name) % this->size;
    SymbolInfo *temp = this->bucket[index];
    while (temp != NULL)
    {
        /* code */
        if (temp->getName() == name)
        {
            /* code */
             cout << "in bucket " << index ;
        cout << "in scope " << this->id ;
            return temp;
        }
        temp = temp->getNext();
    }
    if (this->parentScope != NULL)
    {
        /* code */
        cout << "Searching in parent scope" << endl;
        cout << "in bucket " << index ;
        cout << "in scope " << this->id ;
        return this->parentScope->search(name);
    }
    return NULL;
}
// {
//     /* code */
//     int index = smdbHash(symbol.getName()) % this->size;
//     SymbolInfo *temp = this->bucket[index];
//     while (temp != NULL)
//     {
//         /* code */
//         if (temp->getName() == symbol.getName())
//         {
//             /* code */
//             return temp;
//         }
//         temp = temp->getNext();
//     }
//     return NULL;
// }



void ScopeTable::print()
{
    /* code */
    
        // cout << "bucket " <<  << ": ";
        cout << "Scope Table " << this->id << " ";
    for (int i = 0; i < this->size; i++)
    {
        /* code */
        SymbolInfo *temp = this->bucket[i];
        while (temp != NULL)
        {
            /* code */
            cout  << temp->getName() << " " << temp->getType() << endl; 
            // cout << temp->getName() << " " << temp->getType() << endl;
            temp = temp->getNext();
        }
    }
}



// void ScopeTable::printAllScopes()
// {
//     /* code */
//     cout << "Scope " << this->id << endl;
//     this->print();
//     if (this->parentScope != NULL)
//     {
//         /* code */
//         this->parentScope->printAllScopes();
//     }
// }




ScopeTable* ScopeTable::getParentScope()
{
    /* code */
    // cout << "exit from scope " << this->id << endl;
    return this->parentScope;
}

int ScopeTable::getId()
{
    /* code */
    return this->id;
}

int ScopeTable::getLevel()
{
    /* code */
    return this->level;
}

int ScopeTable::getMaxLevel()
{
    /* code */
    return this->maxLevel;
}

void ScopeTable::setMaxLevel(int maxLevel)
{
    /* code */
    this->maxLevel = maxLevel;
}

void ScopeTable::setLevel(int level)
{
    /* code */
    this->level = level;
}

void ScopeTable::setParentScope(ScopeTable *parentScope)
{
    /* code */
    this->parentScope = parentScope;
}

int ScopeTable::getChild()
{
    /* code */
    return this->child;
}

void ScopeTable:: setChild(int child)
{
    /* code */
    this->child = child;
}

int ScopeTable::getSibling()
{
    /* code */
    return this->sibling;
}

void ScopeTable:: setSibling(int sibling)
{
    /* code */
    this->sibling = sibling;
}
