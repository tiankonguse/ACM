#include <iostream>
#include <string>
using namespace std;

string sLeft[3], sRight[3], sState[3];

bool isLight(string c)
{    
    for(int i = 0; i < 3; ++i) {
        switch(sState[i][0]) {
        case 'u':
            if (sRight[i].find(c) == -1) 
                return false;
            break;
        case 'e':
            if (sLeft[i].find(c) != -1 || sRight[i].find(c) != -1) 
                return false;
            break;
        case 'd':
            if (sLeft[i].find(c) == -1) 
                return false;
            break;
        }
    }
    return true;
}

bool isHeavy(string c)
{
    for(int i = 0; i < 3; ++i) {
        switch(sState[i][0]) {
        case 'u':
            if (sLeft[i].find(c) == -1) 
                return false;
            break;
        case 'e':
            if (sLeft[i].find(c) != -1 || sRight[i].find(c) != -1) 
                return false;
            break;
        case 'd':
            if (sRight[i].find(c) == -1) 
                return false;
            break;
        }
    }
    return true;
}

int main()
{
    int n,  i;    
    
    cin>>n;
    ++n;
    while(--n) {
        bool bCoins[12] = {false};
        for (i = 0; i < 3; ++i) 
            cin>>sLeft[i]>>sRight[i]>>sState[i];
        
        for (char c = 'A'; c <= 'L'; ++c) {
            if (isLight(string(1,c)) == true) {
                printf("%c is the counterfeit coin and it is light.\n", c);
                break;
            }
            if (isHeavy(string(1, c)) == true) {
                printf("%c is the counterfeit coin and it is heavy.\n", c);
                break;
            }
        }//for        
    }//while
    return 0;
}
