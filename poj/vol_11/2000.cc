#include"iostream"
using namespace std;
int main(){
    int N,sum,t,m;
    while(scanf("%d",&N)&&N){
        sum=0;
        t=m=1;
        for(int i=1;i<=N;i++){
           sum+=m;
           t++;
           if(t>m){
              m++;
              t=1;
           }
        }
        printf("%d %d\n",N,sum);
    }
    return 0;
}
