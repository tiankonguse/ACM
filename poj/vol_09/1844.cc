#include"iostream"
#include"cmath"
using namespace std;
int main(){
    int S,N,sum;
    while(~scanf("%d",&S)){
       N=(int)sqrt(S*2.0)-1;
       sum=(1+N)*N/2;
       for(N++;;N++){
          sum+=N;
          if(sum>=S && (sum-S)%2==0){
              printf("%d\n",N);
              break;
          }
       }
    }
    return 0;
}
