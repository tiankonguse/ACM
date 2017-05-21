#include"iostream"
#define MAXN 205
using namespace std;
char map[MAXN][MAXN];
int dp[MAXN][MAXN];
int main(){
    int N,cnt=1,res;
    while(scanf("%d",&N)&&N){
        res=0;
        for(int i=0;i<N;i++){
           scanf(" %s",map[i]);
        }
        for(int i=0;i<N*2-1;i++){
            if(map[0][i]=='-'){
              dp[0][i]=1;
              if(dp[0][i]>res)res=dp[0][i];
            }
        }
        for(int i=1;i<N;i++){
            for(int j=0;j<(N-i)*2-1;j+=2){
                if(map[i][j]=='-'){
                     dp[i][j]=1;
                     if(map[i-1][j]=='-' && map[i-1][j+1]=='-' && map[i-1][j+2]=='-'){
                        dp[i][j]+=min(dp[i-1][j],dp[i-1][j+2]);
                        if(dp[i][j]>res)res=dp[i][j];
                     }
                }
            }
        }
        for(int i=N-1;i>=0;i--){
            for(int j=1;j<(N-i)*2-1;j+=2){
                if(map[i][j]=='-'){
                     dp[i][j]=1;
                     if(j>=2 && j<(N-i)*2-2){
                         if(map[i+1][j-2]=='-' && map[i+1][j-1]=='-' && map[i+1][j]=='-'){
                             dp[i][j]+=min(dp[i+1][j],dp[i+1][j-2]);
                         }
                     }
                     if(dp[i][j]>res)res=dp[i][j];
                }
            }
        }
        printf("Triangle #%d\nThe largest triangle area is %d.\n\n",cnt++,res*res);
    }
    return 0;
}
