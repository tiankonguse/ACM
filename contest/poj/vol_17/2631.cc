#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#define maxn 11111
#define maxm 22222
using namespace std;
struct edges{
    int u, c, next;
}e[maxm];
int p[maxn], idx;
void addedge(int u, int v, int c){
    e[idx].u = v;
    e[idx].c = c;
    e[idx].next = p[u];
    p[u] = idx++;
}
void init(){
    idx = 0;
    memset(p, 0xff, sizeof(p));
}
int r1, d1;
bool used[maxn];
void dfs(int u, int d){
    used[u] = true;
    if(d > d1){
        d1 = d;
        r1 = u;
    }
    int v;
    for(int i=p[u];i!=-1;i=e[i].next){
        v = e[i].u;
        if(!used[v]){
            dfs(v, d + e[i].c);
        }
    }
}
int main(){
    int a, b, c;
    init();
    while(~scanf("%d%d%d", &a, &b, &c)){
        addedge(a, b, c);
        addedge(b, a, c);
    }
    d1 = -1;
    memset(used, false, sizeof(used));
    dfs(1, 0);
    memset(used, false, sizeof(used));
    d1 = -1;
    dfs(r1, 0);
    printf("%d\n", d1);
    return 0;
}
