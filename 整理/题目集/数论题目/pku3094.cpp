//from: 20:47
//AC:   20:54
#include <iostream>
#include <string>
using namespace std;


int main()
{
    string sLine;
    int i, j,  strLen;
    int nQuicksum ;
    while (getline(cin, sLine) && sLine != "#") {
        strLen = sLine.size();
        j = 1; nQuicksum = 0;
        for (i = 0; i < strLen; ++i, ++j) {
            if (isupper(sLine[i])) 
                nQuicksum += j*(sLine[i]-'A'+1);
        }
        cout<<nQuicksum<<endl;        
    }
    return 0;
}

