#include"iostream"
#include"cstdio"
using namespace std;
int guest[31];
int main(){
    int N,sum,sum2;
    while(scanf("%d",&N)&&N){
       sum=0;
       for(int i=0;i<N;i++){
          scanf("%d",&guest[i]);
          sum+=guest[i];
       }
       if(sum&1)printf("No equal partitioning.\n");
       else{
          sum>>=1;
          sum2=0;
          for(int i=0;i<N;i++){
             sum2+=guest[i];
             if(sum2==sum){
                printf("Sam stops at position %d and Ella stops at position %d.\n",i+1,i+2);
                break;
             }
             else if(sum2>sum){
                printf("No equal partitioning.\n");
                break;
             }
          }
       }
    }
    return 0;
}
