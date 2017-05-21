#include"iostream"
using namespace std;
int main(){
    int N,x,y;
    cin>>N;
    for(int i=0;i<N;i++){
            cin>>x>>y;
            if(x==y){
                     if(x%2==0)cout<<x*2<<endl;
                     else cout<<x*2-1<<endl;
            }
            else if(x-y==2){
                 if(x%2==0)cout<<x+y<<endl;
                 else cout<<x+y-1<<endl;
            }
            else{
                 cout<<"No Number"<<endl;
            }
    }
    return 0;
}
