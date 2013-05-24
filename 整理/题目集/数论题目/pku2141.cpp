#include <iostream>
#include <string>
using namespace std;

string codes = "yrwhsoujgcxqbativndfezmlpk";

int main()
{
    string sDecryptionKey, sMessage, sMessageOutput = "";
    
    getline(cin, sDecryptionKey);
    getline(cin, sMessage);

    int len = sMessage.length();
    for (int i = 0; i < len; ++i) {
        if (isupper(sMessage[i])) {
            sMessage[i] = char(sDecryptionKey[sMessage[i]-'A'] - 32);
        }
        else if (islower(sMessage[i])) {
            sMessage[i] = sDecryptionKey[sMessage[i]-'a'];
        }
    }
    cout<<sMessage<<endl;
    
    return 0;
}