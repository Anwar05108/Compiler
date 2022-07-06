// #include<string>
#include<string>
#include<iostream>

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
