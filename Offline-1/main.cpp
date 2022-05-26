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

#include "SymbolInfo.cpp"
#include "ScopeTable.cpp"
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
        while (!fin.eof())
        {
            /* code */
            fin >> n;
            SymbolTable symbolTable = SymbolTable(n);
            string choice, name, type;
            fin >> choice;
            while (choice != "end")
            {
                /* code */
                if (choice == "insert")
                {
                    /* code */
                    fin >> name >> type;
                    // SymbolInfo *symbolInfo = new SymbolInfo(symbol, type);
                    symbolTable.insert(name, type);
                }
                // else if (choice == "search")
                // {
                //     /* code */
                //     fin >> symbol;
                //     SymbolInfo *symbolInfo = symbolTable.search(symbol);
                //     if (symbolInfo == NULL)
                //     {
                //         /* code */
                //         fout << "not found" << endl;
                //     }
                //     else
                //     {
                //         /* code */
                //         fout << symbolInfo->getType() << endl;
                //     }
                // }
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
            }
            
            
            




        }
        
        
    }
    fin.close();


    
}