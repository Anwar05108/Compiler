// #include<string>
#include<string>

using namespace std;



class SymbolInfo
{
private:
    /* data */
    string name;
    string type;

    SymbolInfo *next;
public:
    SymbolInfo(string,string);
    ~SymbolInfo();
    SymbolInfo* getNext();
    void setNext(SymbolInfo*);
    string getName();
    string getType();
    void setName(string);
    void setType(string);

};

SymbolInfo::SymbolInfo(string name,string type)
{
    /* code */
    this->next = NULL;
    this -> name = name;
    this -> type = type;

}

SymbolInfo::~SymbolInfo()
{
    /* code */
    // this->next = NULL;
}

void SymbolInfo::setNext(SymbolInfo* next)
{
    /* code */
    this->next = next;
}

SymbolInfo* SymbolInfo::getNext()
{
    /* code */
    return this->next;
}

string SymbolInfo::getName()
{
    /* code */
    return this->name;
}

string SymbolInfo::getType()
{
    /* code */
    return this->type;
}

void SymbolInfo::setName(string name)
{
    /* code */
    this->name = name;
}

void SymbolInfo::setType(string type)
{
    /* code */
    this->type = type;
}