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
#define maxn 16000 + 10
#define maxm 32000 + 10
using namespace std;
struct edges{
    int u, next;
}e[maxm];
int p[maxn], idx;
int n;
void addedge(int u, int v){
    e[idx].u = v;
    e[idx].next = p[u];
    p[u] = idx++;
}
void init(){
    idx = 0;
    memset(p, 0xff, sizeof p);
}

int res[maxn], _best, rlist[maxn];
int dfs(int u, int pre){
    int v, s = 0, t, c = 0;
    for(int i=p[u];i!=-1;i=e[i].next){
        v = e[i].u;
        if(v != pre){
            t = dfs(v, u);
            s += t;
            c = max(c, t);
        }
    }
    res[u] = max(c, n - s - 1);
    _best = min(_best, res[u]);
    return s + 1;
}
int main(){
    int a, b;
    init();
    scanf("%d", &n);
    for(int i=0;i<n-1;i++){
        scanf("%d%d", &a, &b);
        addedge(a, b);
        addedge(b, a);
    }
    _best = inf;
    dfs(1, -1);
    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(res[i] == _best) rlist[cnt++] = i;
    }
    printf("%d %d\n", _best, cnt);
    for(int i=0;i<cnt;i++){
        if(i == cnt - 1) printf("%d\n", rlist[i]);
        else printf("%d ", rlist[i]);
    }
    return 0;
}
