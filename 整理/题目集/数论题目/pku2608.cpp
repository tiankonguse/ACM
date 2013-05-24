#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//                  ABCDEFGHIJKLMNOPQRSTUVWXYZ
string szSoundex = "01230120022455012623010202";

int main()
{
   // freopen("in.txt","r",stdin);
    string sLine, sResult;
    while (getline(cin, sLine)) {
        sResult = "";
        int len = sLine.size();
        
        for(int i = 0; i < len; ++i){
            if(szSoundex[sLine[i]-'A'] != '0') {
               if (i > 0 && szSoundex[sLine[i]-'A'] == szSoundex[sLine[i-1]-'A'])//左邻的值相同，不再处理。
                   continue;
                sResult = sResult + szSoundex[sLine[i]-'A'];
            }
        } 
        cout<<sResult<<endl;
        
    }
    return 0;
}


