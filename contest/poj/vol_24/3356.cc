#include"iostream"
using namespace std;
int Min(int a,int b,int c){
    if(a<b)return a<c?a:c;
    else return b<c?b:c;
}
char a[1001],b[1001];
short dp[1001][1001];
int fun(int l1,int l2){
    for(int i=1;i<=l1;i++)dp[i][0]=i;
    for(int i=1;i<=l2;i++)dp[0][i]=i;
    for(int i=1;i<=l1;i++){
       for(int j=1;j<=l2;j++){
           if(a[i-1]==b[j-1]){
              dp[i][j]=Min(dp[i-1][j-1],dp[i-1][j]+1,dp[i][j-1]+1);
           }
           else{
              dp[i][j]=Min(dp[i-1][j-1],dp[i-1][j],dp[i][j-1])+1;
           }
       }
    }
   /* for(int i=0;i<=l1;i++){
      for(int j=0;j<=l2;j++){
        cout<<dp[i][j]<<" ";
      }
      cout<<endl;
    }*/
    return dp[l1][l2];
}
int main(){
    int l1,l2;
    while(scanf("%d",&l1)!=EOF){
       scanf("%s%d%s",a,&l2,b);
       printf("%d\n",fun(l1,l2));
    }
    return 0;
}
