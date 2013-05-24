#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n; 
    cin>>n;
    string sLine;
    while (n--) {
        cin>>sLine;
        int nLen = sLine.size(), nCounter = 1;
        for (int i = 1; i < nLen; ++i) {
            if (sLine[i] == sLine[i-1]) {
                ++nCounter;
            }
            else {
                cout<<nCounter<<sLine[i-1];    
                nCounter = 1;
            }            
        }
        cout<<nCounter<<sLine[nLen-1]<<endl;
    }
    return 0;
}

