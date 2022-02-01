#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define MAXN 105
#define MAXK 15
using namespace std;
int dp[MAXN][MAXN];
int tmp[MAXN][MAXN];
int res[MAXK];

int main(){
    dp[50][50]=1;
    for(int k=1;k<=14;k++){
        for(int i=0;i<MAXN;i++){
            for(int j=0;j<MAXN;j++){
                if(dp[i][j]>0){
                    tmp[i-1][j-1] += dp[i][j];
                    tmp[i-1][j+1] += dp[i][j];
                    tmp[i][j-2] += dp[i][j];
                    tmp[i][j+2] += dp[i][j];
                    tmp[i+1][j-1] += dp[i][j];
                    tmp[i+1][j+1] += dp[i][j];
                }
            }
        }
        res[k]=tmp[50][50];
        memcpy(dp,tmp,sizeof(tmp));
        memset(tmp,0,sizeof(tmp));
    }
    int N,a;
    scanf("%d",&N);
    while(N--){
        scanf("%d",&a);
        printf("%d\n",res[a]);
    }
    return 0;
}
