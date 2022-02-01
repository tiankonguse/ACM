#include"iostream"
#include"cmath"
using namespace std;
int main(){
    int N;
    while(cin>>N){
          if(N==0)break;
          int k=pow((double)2,(double)(N/10-194));
          double log=0;
          double h=0;
          while(log<k){
                   log+=log10(++h)/log10(2.0);                
          }
          cout<<h-1<<endl;
    }
    return 0;
}
