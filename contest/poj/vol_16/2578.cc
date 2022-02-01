#include"iostream"
using namespace std;
int main(){
    int a[3];
    cin>>a[0]>>a[1]>>a[2];
    for(int i=0;i<3;i++){
            if(a[i]<168){
               cout<<"CRASH "<<a[i]<<endl;
               return 0;
            }
    }
    
    cout<<"NO CRASH"<<endl;
    return 0;
}
