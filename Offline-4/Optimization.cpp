// optimizing assembly code
#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
using namespace std;


int main()
{

    ifstream asmCodeFile;
    ofstream optimizedCodeFile;
    // cout << "mov" << endl;

    asmCodeFile.open("code.asm");
    if (!asmCodeFile)
    {
        cout << "File not found" << endl;
        return 0;
    }
    optimizedCodeFile.open("optimized_code.asm");

    while (asmCodeFile)
    {
        string line1, line2;
        getline(asmCodeFile, line1);
        getline(asmCodeFile, line2);
        if (line1.find("mov") != string::npos && line2.find("mov") != string::npos)
        {
            stringstream ss1(line1);
            stringstream ss2(line2);
            string token, token2, token3, token4;
            string line1_token[3];
            string line2_token[3];
            string line1_tokens, line2_tokens;
            int i = 0;
            while (getline(ss1, token, ' '))
            {
                if (i > 0)
                {
                    line1_tokens += token;
                }
                

                i++;
            }
            i = 0;
            while (getline(ss2, token2, ' '))
            {
                if (i > 0)
                {
                    line2_tokens += token2;
                }
                i++;
            }
            // cout << line1_tokens << endl;
            // cout << line2_tokens << endl;
            stringstream ss3(line1_tokens);
            stringstream ss4(line2_tokens);
            i = 0;
            while (getline(ss3, token3, ','))
            {
                line1_token[i] = token3;
                i++;
            }
            i = 0;
            while (getline(ss4, token4, ','))
            {
                line2_token[i] = token4;
                i++;
            }
        //    for(int i=0;i<3;i++)
        //     {
        //         /* code */
        //         cout << line1_token[i] << endl;
        //         cout << line2_token[i] << endl;
        //     }
            

            if(line1_token[0] == line2_token[1]  && line1_token[1] == line2_token[0])
            {
                optimizedCodeFile << line1<<endl;
                
            }
            else
            {
                optimizedCodeFile << line1<<endl;
                optimizedCodeFile << line2<<endl ;
                
            }
            

           
        }
        else{
            optimizedCodeFile << line1<<endl ;
            optimizedCodeFile << line2 <<endl;
        }
    }
}