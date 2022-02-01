#include"iostream"
using namespace std;
char a[201],b[201],c[401];
bool dp[201][201];
bool check(int l1,int l2){
    dp[0][0]=true;
    for(int i=1;i<=l1;i++)dp[i][0]=(dp[i-1][0] && a[i-1]==c[i-1]);  
    for(int i=1;i<=l2;i++)dp[0][i]=(dp[0][i-1] && b[i-1]==c[i-1]);
    for(int i=1;i<=l1;i++){
       for(int j=1;j<=l2;j++){
           if((dp[i-1][j] && a[i-1]==c[i+j-1]) ||
              (dp[i][j-1] && b[j-1]==c[i+j-1]))
              dp[i][j]=true;
           else dp[i][j]=false;
       }
    }
    return dp[l1][l2];
  /*  for(int i=0;i<=l1;i++){
      for(int j=0;j<=l2;j++){
        cout<<dp[i][j]<<" ";
      }
      cout<<endl;
    }*/
}
int main(){
    int n,l1,l2;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
       scanf("%s%s%s",a,b,c);
       l1=strlen(a);
       l2=strlen(b);
       if(check(l1,l2))printf("Data set %d: yes\n",i);
       else printf("Data set %d: no\n",i);
    }
   // system("pause");
    return 0;
}
