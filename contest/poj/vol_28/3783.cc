#include"iostream"
using namespace std;
int dp[1001][51];
int max(int a,int b){
    return a>b?a:b;
}
void init(){
    int min,t;
    for(int i=0;i<=1001;i++){
            dp[i][1]=i;
          if(i<=50)  dp[1][i]=1;
    }
    for(int j=2;j<=50;j++){
    for(int i=2;i<=1000;i++){
             min=i;
             for(int k=1;k<i;k++){
                 t=max(dp[k][j]+1,dp[i-k-1][j-1]+1);
                 if(t<min){
                     min=t;
                 }
             }
             dp[i][j]=min;
        }
    }
}
int main(){
    int T,p,d,a;
    init();
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        scanf("%d%d%d",&p,&d,&a);
        printf("%d %d\n",p,dp[a][d]);
        
    }
 //   system("pause");
    return 0;
}
