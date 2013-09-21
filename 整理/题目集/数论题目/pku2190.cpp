#include <iostream>
#include <string>
using namespace std;

int a[] = {10,9,8,7,6,5,4,3,2,1};

int main()
{    
    string str;
    cin>>str;
    long nISBN = 0;
    int i, pos, len = str.size();
        
    for (i = 0; i < len; ++i) {
        if (str[i] == '?')     {
            pos = i;
        }
        else if (str[i] == 'X')
            nISBN = nISBN + a[i]*10;
        else
            nISBN = nISBN + a[i]*(str[i]-'0');
    }

    /* 注意，只有最后一位才可以是X */
    /* 如果缺的是最后一位,单独考虑X */
    if (pos == 9 && (nISBN + 10)%11 == 0) {
        cout<<"X"<<endl;
        return 0;
    }

    /*从0到9逐个测试*/
    for (i = 0; i <= 9 ; ++i ) {
        if ((nISBN + i*a[pos])%11 == 0) {  
            cout<<i<<endl;
            return 0;
        }
    }
    
    cout<<"-1"<<endl;
    return 0;
}