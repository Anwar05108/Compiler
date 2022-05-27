// designig a compiler
// symbol table representation

#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<sstream>
#include<iomanip>
#include<bitset>
#include <fstream>

// #include "SymbolInfo.cpp"
// #include "ScopeTable.cpp"
#include "SymbolTable.cpp"


using namespace std;


#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,n) FOR(i,0,n)
#define REPE(i,n) FORE(i,0,n)
#define LL long long
#define FIR(n) REP(i,n)
#define FJR(n) REP(j,n)




int main()
{
    ifstream fin;
    fin.open("input.txt");
    ofstream fout;
    // fout.open("output.txt");

    if (fin.is_open())
    {
        /* code */
        // string line;
        int n;
        int serial = 1;
        while (!fin.eof())
        {
            /* code */
            fin >> n;
            SymbolTable symbolTable = SymbolTable(n);
            string choice, name, type;
            fin >> choice;
            // serial = 1;
            while (choice != "exit")
            {
                /* code */
                if (choice == "I")
                {
                    /* code */
                    fin >> name >> type;
                    // SymbolInfo *symbolInfo = new SymbolInfo(symbol, type);
                    symbolTable.insert(name, type);
                }
                else if (choice == "L")
                {
                    /* code */
                    fin >> name;
                    SymbolInfo *symbolInfo = symbolTable.search(name);
                    if (symbolInfo == NULL)
                    {
                        /* code */
                        // fout << "not found" << endl;
                        cout << "not found" << endl;
                    }
                    else
                    {
                        /* code */
                        // fout << symbolInfo->getType() << endl;
                        cout << "found";
                        cout << symbolInfo->getType() << endl;
                    }
                }
                else if (choice == "S")
                {
                    /* code */
                    // if(symbolTable.getParentScope() == NULL){
                    //     serial++;
                    //     cout << "no parentScope" << endl;
                    //     cout << "serial " << serial << endl;
                        symbolTable.enterScope(n);
                    // }
                    // else{
                    //     // symbolTable.enterScope(serial, symbolTable.getParentScope()->getSize());
                    //     cout << "serial " << serial << endl;
                    // symbolTable.enterScope(serial, n);
                    // }


                }
                else if (choice == "E")
                {
                    /* code */
                    symbolTable.exitScope();
                }
                else if (choice == "P")
                {
                    string printChoice;
                    /* code */
                    fin >> printChoice;
                    if (printChoice == "C")
                    {
                        /* code */
                        symbolTable.printCurrentScope();
                    }
                    else if (printChoice == "A")
                    {
                        /* code */
                        symbolTable.printAllScopes();
                    }
                    
                }
                // else if (choice == "A")
                // {
                //     /* code */
                //     symbolTable.printAllScopes();
                // }
                else if (choice == "D")
                {
                    /* code */
                    fin >> name;
                    symbolTable.deletef(name);
                }
                
                
                
                // else if (choice == "delete")
                // {
                //     /* code */
                //     fin >> symbol;
                //     symbolTable.deleteSymbol(symbol);
                // }
                // else if (choice == "print")
                // {
                //     /* code */
                //     symbolTable.print();
                // }
                fin >> choice;
                // cout << choice << endl;
                // cout << endl;
            }
            
            
            




        }
        
        
    }
    fin.close();


    
}