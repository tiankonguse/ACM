#include"iostream"
#include"cstdlib"
#include"string.h"
#include"cstdio"
#define MAX (1<<11)
using namespace std;
__int64 dp[25][MAX];
int pre[11]={1,2,4,8,16,32,64,128,256,512,1024};
int N,M;
void dfs(int i,int j,int v,int r){
    if(j>=M){
         dp[i][v]+=dp[i-1][r];
         return;
    }
    if((r>>j)&1==1){
         dfs(i,j+1,v,r);
    }
    else{
        if(j+1<M && ((r>>(j+1))&1)==0 ){
           dfs(i,j+2,v,r);
        }
        if(i+1<=N){
           dfs(i,j+1,v+pre[j],r);
        }
    }
}
int main(){
    int T;
    M=4;
    scanf("%d",&T);
    for(int c=1;c<=T;c++){
          scanf("%d",&N);
          memset(dp,0,sizeof(dp));
          dp[0][0]=1;
          for(int i=1;i<=N;i++){
              for(int j=0;j<MAX;j++){
                  if(dp[i-1][j]){
                      dfs(i,0,0,j);
                  }
              }
          }
          printf("%d %I64d\n",c,dp[N][0]);
    }
    return 0;
}
