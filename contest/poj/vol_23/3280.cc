#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#define MAXN 2005
#define MAXC 300
#define min(a,b) (a<b?a:b)
using namespace std;
char str[MAXN];
int dp[MAXN][MAXN];
int cost[MAXC];
int main(){
    char c;
    int N,M,a,b;
    while(~scanf("%d%d",&N,&M)){
        scanf(" %s",str);
        for(int i=0;i<N;i++){
            scanf(" %c %d%d",&c,&a,&b);
            cost[c]=min(a,b);
        }
        for(int i=0;i<M;i++){
            for(int j=0;j+i<M;j++){
                if(str[j]==str[j+i])dp[j][j+i]=dp[j+1][j+i-1];
                else dp[j][j+i]=min(dp[j+1][j+i]+cost[str[j]],dp[j][j+i-1]+cost[str[j+i]]);
            }
        }
        printf("%d\n",dp[0][M-1]);
    }
    return 0;
}
