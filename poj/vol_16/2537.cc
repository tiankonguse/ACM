#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define MAXN 101
#define MAXK 10
using namespace std;
double dp[MAXK][MAXN];
int main(){
    int k,n;
    double sum;
    double res;
    while(~scanf("%d%d",&k,&n)){
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=k;i++)dp[i][1]=1;
        for(int i=2;i<=n;i++){
            for(int j=0;j<=k;j++){
                dp[j][i]=dp[j][i-1];
                if(j-1>=0)dp[j][i]+=dp[j-1][i-1];
                if(j+1<=k)dp[j][i]+=dp[j+1][i-1];
            }
        }
        sum=0;
        for(int i=0;i<=k;i++)sum+=dp[i][n];
        res=100.0*sum/pow((double)(k+1),(double)n);
        printf("%.5lf\n",res);
    }
    return 0;
}
