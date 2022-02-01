#include"cstdio"
using namespace std;
int main(){
    int N,s;
    while(scanf("%d",&N)&&N){
        for(int m=2;;m++){
           s=0;
           for(int i=2;i<=N-1;i++){
               s=(s+m)%i;
           }
           if(!s){
               printf("%d\n",m);
               break;
           }
        }
    }
    return 0;
}
