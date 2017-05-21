#include"iostream"
#define Max(a,b) ((a)>(b)?(a):(b))
using namespace std;
char ch[5001],ach[5001];
short dp[5001][5001];
int fun(int n){
    for(int i=1;i<=n;i++){
       for(int j=1;j<=n;j++){
           if(ch[i-1]==ach[j-1])dp[i][j]=dp[i-1][j-1]+1;
           else dp[i][j]=Max(dp[i-1][j],dp[i][j-1]);
       }
    }
    return dp[n][n];
}
int main(){
    int n;
    scanf("%d",&n);
    scanf("%s",ch);
    for(int i=n-1;i>=0;i--){
       ach[n-1-i]=ch[i];
    }
    printf("%d\n",n-fun(n));
    return 0;
}
