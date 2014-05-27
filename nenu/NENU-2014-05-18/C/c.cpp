/*************************************************************************
> File Name: c.cpp
> Author: tiankonguse
> Mail: i@tiankonguse.com 
> Created Time: Sun 18 May 2014 04:06:49 PM CST
***********************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
#include<stdarg.h>
using namespace std;
#ifdef __int64
typedef __int64 LL;
#else
typedef long long LL;
#endif
const int N = 1111;

int sum[N];
int ans, ansSum;

vector<int> G[N];
bool have[N];
bool s[N];

int dfs(int u){
    if(have[u])return 0;
    int now = sum[u];
    have[u] = true;
    for(int i=0;i<G[u].size();i++){
        now += dfs(G[u][i]);
    }

    return now;
}


int main() {
    freopen("C.in", "r", stdin);
    freopen("out_c.txt", "w", stdout);

    int n,m;
    int i,j;
    int u,v;
    int tmp;
    while(~scanf("%d%d",&n,&m)){
        for(i=0;i<n;i++){
            G[i].clear();
            s[i] = true;
            scanf("%d",&sum[i]);
        }
        for(j=0;j<m;j++){
            scanf("%d%d",&u,&v);
            u--,v--;
            if(u < v){
                s[v] = false;
            }
            G[u].push_back(v);
        }
        ans = 0;ansSum = sum[0];
        for(i=0;i<n;i++){
            if(s[i]){
                memset(have, false, sizeof(have));
                tmp = dfs(i);
                if(tmp < ansSum){
                    ansSum = tmp;
                    ans = i;
                }
//                printf("%d->%d\n",i,tmp);
            }
        }
        printf("%d\n",ans + 1);
    }

    return 0;
}
