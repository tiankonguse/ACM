/*************************************************************************
    > File Name: HDU-4539-郑厂长系列故事——排兵布阵.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/4 9:10:24
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;
const int maxn=202;
int dp[maxn][maxn][maxn],e[maxn],s[maxn],c[maxn];
int n,m,cnt;
int Count(int x) {
    int ans=0;
    while(x) {
        if(x&1)
            ans++;
        x>>=1;
    }
    return ans;
}
int main() {
    while(scanf("%d%d",&n,&m)!=EOF) {
        memset(e,0,sizeof(e));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++) {
                int ita;
                scanf("%d",&ita);
                if(!ita)
                    e[i]|=(1<<j);
                printf("-->%d  %d\n",e[i],1<<j);
            }

        }


        //统计 0 到 total-1这些数字的1的个数
        cnt=0;
        int total=1<<m;
        for(int i=0; i<total; i++) {
            if(i&(i<<2))
                continue;
            s[cnt]=i;
            c[cnt++]=Count(i);
        }


        memset(dp,-1,sizeof(dp));
        for(int i=0; i<cnt; i++) {
            if(s[i]&e[0])
                continue;
            dp[0][i][0]=c[i];
            printf("%d  %d %d\n",i,c[i],e[0]);
        }

        for(int i=1; i<n; i++) {
            for(int j=0; j<cnt; j++) {
                if(e[i]&s[j])
                    continue;
                for(int k=0; k<cnt; k++) {
                    if((s[j]&(s[k]<<1))||(s[j]&(s[k]>>1)))
                        continue;
                    for(int l=0; l<cnt; l++) {
                        if(s[j]&s[l])
                            continue;
                        if(s[k]&(s[l]>>1))
                            continue;
                        if(s[k]&(s[l]<<1))
                            continue;
                        if(dp[i-1][k][l]==-1)
                            continue;
                        dp[i][j][k]=max(dp[i][j][k],dp[i-1][k][l]+c[j]);
                    }
                }
            }
        }
        int ans=0;
        for(int i=0; i<cnt; i++)
            for(int j=0; j<cnt; j++)
                ans=max(ans,dp[n-1][i][j]);
        printf("%d\n",ans);
    }
    return 0;
}
