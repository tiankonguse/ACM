#include"iostream"
using namespace std;
__int64 a[500002]={1,1,2,4,6};
int main(){
    for(int i=5;i<=500001;i++){
            a[i]=a[i-1]+a[(i+1)/2];
            if(a[i]>1000000000) a[i]%=1000000000;
    }    
    int n;
    while(cin>>n){
                  cout<<a[n/2+1]<<endl;
    }
    return 0;
}

