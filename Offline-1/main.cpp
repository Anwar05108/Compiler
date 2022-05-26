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
        string line;
        while (getline(fin, line))
        {
            /* code */
            cout << line << endl;
            
            cout << "this is a line"<<endl;
            // if ()
            // {
            //     /* code */
            // }
            
            // fout << line << endl;
        }
    }
    fin.close();


    
}