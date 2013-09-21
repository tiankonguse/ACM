#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, set = 1;
    int i, front, back, c;
    string str;
    while(cin>>n && n != 0) {
        front = 0;
        back = n - 1;
        string a[20];
        c = 0;
        for (i = 0; i < n; ++i) {
            cin>>str;
            if (c == 0) {
                a[front++] = str;
            }
            else {
                a[back--] = str;
            }
            c = (c+1)%2;
        }
        cout<<"SET "<<set++<<endl;
        for (i = 0; i < n; ++i) {
            cout<<a[i]<<endl;
        }
    }
    return 0;
}