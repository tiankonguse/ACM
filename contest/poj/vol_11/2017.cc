#include"iostream"
using namespace std;
int main(){
    int N,v,t0,t,sum;
    while(scanf("%d",&N)){
       if(N==-1)break;
       t0=0;
       sum=0;
       while(N--){
           scanf("%d%d",&v,&t);
           sum+=v*(t-t0);
           t0=t;
       }
       printf("%d miles\n",sum);
    }
    return 0;
}
