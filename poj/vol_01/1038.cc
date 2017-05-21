#include"iostream"
#include"cstdlib"
#define MAX 59049
using namespace std;
int dp[2][MAX],tr[11];
bool bad[151][11];
int pre[11]={0,1,3,9,27,81,243,729,2187,6561,19683};
int N,M;
bool check(int a,int b,int i,int j){
    if(a+i>N+1 || b+j>M+1)return false;
    for(int jp=0;jp<b;jp++){
       if(tr[j+jp]!=0)return false;
    }
    for(int ip=0;ip<a;ip++){
       for(int jp=0;jp<b;jp++){
           if(bad[i+ip][j+jp])return false;
       }
    }
    return true;
}
void dfs(int i,int j,int v,int r,int am){
    if(j>M){
           
        if(am>dp[i%2][v])dp[i%2][v]=am;
        return;
    }
    if(tr[j]>0){
       dfs(i,j+1,v+(tr[j]-1)*pre[j],r,am);
    }
    else{
       if(check(2,3,i,j)){
          dfs(i,j+3,v+pre[j]+pre[j+1]+pre[j+2],r,am+1);
       }
       if(check(3,2,i,j)){
                         // cout<<i<<","<<j<<endl;
          dfs(i,j+2,v+2*(pre[j]+pre[j+1]),r,am+1);
       }
       dfs(i,j+1,v,r,am);
    }
}
int main(){
    int T,K,x,y;
    scanf("%d",&T);
    while(T--){
       scanf("%d%d%d",&N,&M,&K);
       memset(bad,false,sizeof(bad));
       while(K--){
           scanf("%d%d",&x,&y);
           bad[x][y]=true;
       }
  /*     for(int i=1;i<=N;i++){
         for(int j=1;j<=M;j++)if(bad[i][j])printf("X");else printf(".");
         printf("\n");
       }*/
       memset(dp,0xff,sizeof(dp));
       dp[0][0]=0;
       int tmp;
       for(int i=1;i<=N;i++){
            for(int j=0;j<MAX;j++){
               if(dp[(i-1)%2][j]>=0){
                    tmp=j;
                    for(int l=1;l<=M;l++){
                       tr[l]=tmp%3;
                       tmp/=3;
                  //     printf("%d",tr[l]);
                    }
                 //   printf("\n");
               //   printf("dp[%d][%d]=%d\n",i-1,j,dp[(i-1)%2][j]);
                  //  cout<<dp[(i-1)%2][j]<<endl;
                  //  cout<<i<<","<<j<<endl;
                    dfs(i,1,0,j,dp[(i-1)%2][j]);
               }
            }
       }
       printf("%d\n",dp[N%2][0]);
    }
  //  system("pause");
    return 0;
}
