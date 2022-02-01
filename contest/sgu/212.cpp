#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

const int N = 1505;
const int M = 300005;
const int inf = 0x3f3f3f3f;

int n , m , L, s , t;
int rank[N], in[N], out[N];
struct arc
{
    int x , f , next;
}e[M << 1];
int pre[N] , mcnt;
void addarc(int x ,int y ,int z)
{
    e[mcnt] = (arc) {y , z , pre[x]} , pre[x] = mcnt ++;
    e[mcnt] = (arc) {x , 0 , pre[y]} , pre[y] = mcnt ++;
}
int d[N] , cur[N] , q[N];
bool BFS()
{
    memset(d , -1 , sizeof(d));
    int top = 0 , bot = -1;
    q[++ bot] = s , d[s] = 1;
    while (top != bot + 1) {
        int x = q[top ++];
        for (int i = pre[x] ; ~i ;i = e[i].next) {
            int y = e[i].x;
            if (!~d[y] && e[i].f) {
                d[y] = d[x] + 1 , q[++ bot] = y;
                if (y == t) return 1;
            }
        }
    }
    return 0;
}
int DFS(int x , int flow = 1 << 30)
{
    if (x == t || !flow) return flow;
    int sum = 0 , u;
    for (int& i = cur[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (d[y] == d[x] + 1 && (u = DFS(y , min(flow , e[i].f)))) {
            e[i].f -= u ,  e[i ^ 1].f += u;
            sum += u , flow -= u;
            if (!flow) break;
        }
    }
    if (!sum) d[x] = -1;
    return sum;
}

int dinic()
{
    int ans = 0;
    while (BFS()) {
        memcpy(cur , pre , sizeof(cur));
        ans += DFS(s);
    }
    return ans;
}

bool cmp(const int &a, const int &b) {
    return d[a] < d[b];
}

void greedy() {
    sort(rank+1, rank+1+n, cmp);
    in[s] = inf;
    for (int i = 1; i <= n; ++i) {
        int u = rank[i];
        for (int j = pre[u]; ~j; j = e[j].next) {
            int v = e[j].x, c = e[j].f;
            if (!(j & 1) && in[u] > out[u]) {
                int f = min(c, in[u]-out[u]);
                in[v] += f, out[u] += f;
            }
        }
    }
    memset(in, 0, sizeof (in));
    in[t] = inf;
    for (int i = n; i >= 1; --i) {
        int v = rank[i];
        for (int j = pre[v]; ~j; j = e[j].next) {
            int u = e[j].x, c = e[j^1].f;
            if (j & 1 && out[u] > in[u]) {
                int f = min(c, min(out[u]-in[u], in[v]));
                in[u] += f, in[v] -= f;
                e[j].f += f, e[j^1].f -= f;
            }
        }
    }
}

int main() {
    int i , x , y , z;
    memset(pre, -1 , sizeof (pre));
    scanf("%d%d%d", &n, &m, &x);
    for (i = 1; i <= n; ++ i) {
        rank[i] = i;
        scanf("%d", &d[i]);
        if (d[i] == 1) s = i;
        if (d[i] == x) t = i;
    }
    for (i = 0; i < m; ++ i) {
        scanf("%d%d%d", &x, &y, &z);
        addarc(x , y , z);
    }
    greedy(), dinic();
    for (i = 0; i < m; ++ i) {
        printf("%d\n", e[i << 1 | 1].f);
    }
    return 0;
}
