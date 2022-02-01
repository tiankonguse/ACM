#include"iostream"
using namespace std;
int main(){
    __int64 ans;
    int N,k;
    while(~scanf("%d",&N)){
        ans=N;
        for(__int64 i=2;i*i<=N;i++){
            if(N%i==0){
                k=0;
                while(N%i==0){
                   N/=i;
                   k++;
                }
                ans=ans*(1+k)-ans*k/i;
            }
        }
        if(N>1)ans=ans*2-ans/N;
        printf("%I64d\n",ans);
    }
    return 0;
}
