#include"iostream"
using namespace std;
int main(){
    int N,M,sum,a;
    scanf("%d",&N);
    while(N--){
       sum=0;
       scanf("%d",&M);
       for(int i=0;i<M;i++){
          scanf("%d",&a);
          sum+=a;
       }
       printf("%d\n",sum-M+1);
    }
    return 0;
}
