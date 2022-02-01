#include"iostream"
using namespace std;
int main(){
    int a,b,t;
    while(cin>>a>>b){
       if(a==0 && b==0)break;
       if(a>b){
               t=a;
               a=b;
               b=t;
       }
       if(a*1.618>b && a!=b)cout<<"Ollie wins"<<endl;
       else cout<<"Stan wins"<<endl;
    }
    return 0;
}
