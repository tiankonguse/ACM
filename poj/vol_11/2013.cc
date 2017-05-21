#include"iostream"
#include"string"
using namespace std;
int main(){
    string a[50];
    int c=1,n;
    while(cin>>n){
         if(n==0)break;
         for(int i=0;i<n;i++){
            if(i%2==0)cin>>a[i/2];
            else cin>>a[n-i/2-1];
         }
         cout<<"SET "<<c++<<endl;
         for(int i=0;i<n;i++)cout<<a[i]<<endl;
    }
    return 0;
}
