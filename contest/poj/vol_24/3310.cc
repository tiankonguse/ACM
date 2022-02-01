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
#include <ctime>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define maxn 222
#define maxm 1010
using namespace std;
int parents[maxn];
int Find(int a){
    return parents[a] < 0 ? a : parents[a] = Find(parents[a]);
}
void Union(int a,int b){
    if(parents[a] < parents[b]){ parents[a] += parents[b], parents[b] = a;}
    else{ parents[b] += parents[a], parents[a] = b;}
}

int n, m;
struct edges {
    int u, next;
} e[maxm];
int p[maxn], idx;
void addedge(int u, int v) {
    e[idx].u = v;
    e[idx].next = p[u];
    p[u] = idx++;
}
void init(){
    memset(parents, 0xff, sizeof(parents));
    idx = 0;
    memset(p, 0xff, sizeof p);
}
bool mark[maxn];
int cc;
int deg[maxn];

void dfs(int u) {
    mark[u] = true;
    ++cc;
    int v;
    int ch = -1;
    for (int i = p[u]; ~i; i = e[i].next) {
        v = e[i].u;
        if (mark[v]) continue;
        if (deg[v] >= 2) ch = v;
        else {
            if (!mark[v]) {
                mark[v] = true;
                ++cc;
            }
        }
    }
    if (ch != -1) dfs(ch);
}
int main() {
    int ca = 1;
    while (scanf("%d", &n) && n) {
        scanf("%d", &m);
        init();
        memset(deg, 0, sizeof deg);
        int a, b;
        bool flag = true;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &a, &b);
            addedge(a, b);
            addedge(b, a);
            ++deg[a], ++deg[b];
            int ra = Find(a), rb = Find(b);
            if (ra == rb) {
                flag = false;
            }
            else Union(ra, rb);
        }
        if (-parents[Find(1)] != n) flag = false;
        if (!flag) {
            printf("Graph %d is not a caterpillar.\n", ca++);
            continue;
        }
        else {
            flag = false;
            for (int i = 1; i <= n; ++i) {
                memset(mark, 0, sizeof mark);
                cc = 0;
                dfs(i);
                if (cc == n) {
                    flag = true;
                    break;
                }
            }
            if (flag) printf("Graph %d is a caterpillar.\n", ca++);
            else printf("Graph %d is not a caterpillar.\n", ca++);
        }
    }
    return 0;
}
