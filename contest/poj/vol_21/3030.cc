#include"iostream"
using namespace std;
int main(){
    int N,a,b,c;
    cin>>N;
    while(N--){
       cin>>a>>b>>c;
       if(a<b-c)cout<<"advertise"<<endl;
       else if(a==b-c)cout<<"does not matter"<<endl;
       else cout<<"do not advertise"<<endl;
    }
    return 0;
}
