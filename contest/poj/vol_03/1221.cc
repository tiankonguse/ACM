#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define MAXN 250
using namespace std;
long long dp[MAXN][MAXN];
void init(){
    int m;
    memset(dp,0,sizeof(dp));
    for(int i=0;i<MAXN;i++)dp[0][i]=1;
    for(int i=1;i<MAXN;i++){
        m=i/2;
        dp[i][i]=1;
        for(int j=i-1;j>=1;j--){
            if(i-2*j<0)dp[i][j]=dp[i][j+1];
            else dp[i][j]=dp[i-2*j][j]+dp[i][j+1];
        }
    }
}
int main(){
    init();
    int N;
    while(scanf("%d",&N)&&N){
        printf("%d %lld\n",N,dp[N][1]);
    }
    return 0;
}
