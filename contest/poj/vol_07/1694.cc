#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define maxn 222
#define maxm 10110

using namespace std;

struct edges{
   int u, next;
}e[maxm];
int p[maxn], idx;
int n;
void addedge(int u,int v){
    e[idx].u=v;
    e[idx].next=p[u];
    p[u]=idx++;
}
void init(){
    idx = 0;
    memset(p, 0xff, sizeof(p));
}
int dp[maxn]; bool used[maxn];
int list[maxn][maxn];

void dfs(int u){
    used[u] = true;
    int v, cnt = 0;
    for(int i=p[u];i!=-1;i=e[i].next){
        v = e[i].u;
        if(!used[v]) dfs(v);
    }
    for(int i=p[u];i!=-1;i=e[i].next){
        v = e[i].u;
        list[u][cnt++] = dp[v];
    }
    sort(list[u], list[u] + cnt);
    int need = 1, r = 1;
    for(int i=cnt-1;i>=0;i--){
        if(list[u][i] > r){
            need += list[u][i] - r;
            r = list[u][i];
        }
        r--;
    }
    dp[u] = need;
}

int main(){
    int t;
    int a, d, b;
    for(scanf("%d", &t);t--;){
        scanf("%d", &n);
        init();
        for(int i=0;i<n;i++){
            scanf("%d%d", &a, &d);
            for(int j=0;j<d;j++){
                scanf("%d", &b);
                addedge(a, b);
            }
        }
        memset(used, false, sizeof(used));
        dfs(1);
        printf("%d\n", dp[1]);
    }
    return 0;
}
