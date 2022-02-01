#include"iostream"
using namespace std;
int dp[13000],v[3500],w[3500];
int max(int a,int b){
    return a>b?a:b;
}
int main(){
    int N,M;
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++){
       scanf("%d%d",&v[i],&w[i]);
    }
    for(int i=0;i<N;i++){
       for(int j=M;j>=v[i];j--){
           dp[j]=max(dp[j],w[i]+dp[j-v[i]]);
       }
    }
  /*  int mm=0;
    for(int i=0;i<=M;i++){
       if(dp[i]>mm)mm=dp[i];
    }*/
    printf("%d\n",dp[M]);
 //   system("pause");
    return 0;
}
