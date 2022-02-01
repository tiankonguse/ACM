/*************************************************************************
    > File Name: k.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/4/13 14:16:30
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
#define typec int // type of cost
const int V = 111;
const typec inf = 0x3f3f3f3f; // max of cost
int vis[V];
typec cost[V][V];
typec lowc[V];

typec prim( int n) { // vertex: 0 ~ n-1
    int i, j, p;
    typec minc, res = 0;
    memset(vis, 0, sizeof(vis));
    vis[0] = 1;
    for (i=1; i<n; i++) lowc[i] = cost[0][i];
    for (i=1; i<n; i++) {
        minc = inf;
        p = -1;
        for (j=0; j<n; j++)
            if (0 == vis[j] && minc > lowc[j]) {
                minc = lowc[j];
                p = j;
            }
        if (inf == minc) return -1; // 原图不连通
        res += minc;
        vis[p] = 1;
        for (j=0; j<n; j++)
            if (0 == vis[j] && lowc[j] > cost[p][j])
                lowc[j] = cost[p][j];
    }
    return res;
}
int main() {
    int n,i,j;
    scanf("%d",&n);
    while(~scanf("%d",&n)){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                scanf("%d",&cost[i][j]);
            }
        }
        printf("%d\n",prim(n));
    }
    return 0;
}
