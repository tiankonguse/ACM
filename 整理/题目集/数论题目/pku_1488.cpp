#include<iostream>
#include <string>
using namespace std;

int main()
{
    bool bIsFirst = true;
    string str;
    int len;
    while(getline(cin, str)) {
        len = str.size();
        for(int i = 0;i < len; ++i) {
            if(str[i] == '\"') {
                if( bIsFirst == true){
                    cout<<"``";
                    bIsFirst = false;
                }
                else {
                    cout<<"''";
                    bIsFirst = true;
                }
            }
            else
                cout<<str[i];
        }
        cout<<endl;    
    }
    return 0;
}
