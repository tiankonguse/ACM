#include"iostream"
using namespace std;
int T[1005],W[1005];
int main(){
    for(int i=1;i<=1000;i++){
      T[i]=T[i-1]+i;
    }
    for(int i=1;i<=1000;i++){
      W[i]=W[i-1]+i*T[i+1];
    }
    int N,a;
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
       scanf("%d",&a);
       printf("%d %d %d\n",i,a,W[a]);
    }
    return 0;
}
