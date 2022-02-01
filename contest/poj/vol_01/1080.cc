#include"iostream"
using namespace std;
int map[5][5]={{0,-3,-4,-2,-1},
               {-3,5,-1,-2,-1},
               {-4,-1,5,-3,-2},
               {-2,-2,-3,5,-2},
               {-1,-1,-2,-2,5}};
char a[105],b[105];
int dp[105][105];
int tr(char c){
   switch(c){
      case '-':return 0;
      case 'A':return 1;
      case 'C':return 2;
      case 'G':return 3;
      case 'T':return 4;
   }
}
int Max(int a,int b,int c){
   if(a>b){
      return a>c?a:c;
   }
   else{
      return b>c?b:c;
   }
}
int fun(int l1,int l2){
    for(int i=1;i<=l2;i++)dp[0][i]=dp[0][i-1]+map[0][tr(b[i-1])];
    for(int i=1;i<=l1;i++)dp[i][0]=dp[i-1][0]+map[0][tr(a[i-1])];
   /* for(int i=0;i<=l1;i++){
            for(int j=0;j<=l2;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
    }*/
    for(int i=1;i<=l1;i++){
        for(int j=1;j<=l2;j++){
            dp[i][j]=Max(dp[i-1][j-1]+map[tr(a[i-1])][tr(b[j-1])],
                         dp[i-1][j]+map[0][tr(a[i-1])],
                         dp[i][j-1]+map[0][tr(b[j-1])]);
        }
    }
    /*for(int i=0;i<=l1;i++){
            for(int j=0;j<=l2;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
    }*/
    return dp[l1][l2];
}
int main(){
    int n,l1,l2;
    scanf("%d",&n);
    while(n--){
       scanf("%d%s%d%s",&l1,a,&l2,b);
       printf("%d\n",fun(l1,l2));
    }
   // system("pause");
    return 0;
}
