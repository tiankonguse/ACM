#include"iostream"
#define Max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int a[101][101],dp[101][101];
int main(){
    int F,V,temp;
    while(scanf("%d%d",&F,&V)!=EOF){
    for(int i=0;i<F;i++){
        for(int j=0;j<V;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<V;i++)dp[0][i]=a[0][i];
    for(int i=1;i<F;i++){
         for(int j=i;j<V;j++){
            if(j==i){
                 dp[i][j]=a[i][j]+dp[i-1][j-1];
                 temp=dp[i-1][j-1];
            }
            else{
                 temp=Max(temp,dp[i-1][j-1]);
                 dp[i][j]=temp+a[i][j];
            }
         }
    }
    temp=dp[F-1][V-1];
    for(int i=V-1;i>=F-1;i--){
        if(dp[F-1][i]>temp)temp=dp[F-1][i];
    }
    printf("%d\n",temp);
  }
  //  system("pause");
    return 0;
}
