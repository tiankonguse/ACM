#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a,b;
    int sum=0;
    cin>>a>>b;
    for(int i=0;i<a.length();i++){
        for(int j=0;j<b.length();j++){
            sum+=(a[i]-48)*(b[j]-48);
        }
    }
    cout<<sum<<endl;
    return 0;
}
