#include"iostream"
#include"cmath"
using namespace std;
int main(){
    int N,cnt=0;
    cin>>N;
    N*=2;
    for(int i=1;i<sqrt((double)N);i++){
       if(N%i==0){
          if((N/i-i+1)%2==0)cnt++;
       }
    }
    cout<<cnt<<endl;
    //system("pause");
    return 0;
}
