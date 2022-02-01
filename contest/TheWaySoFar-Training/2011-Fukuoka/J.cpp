#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long LL;

#define N 105
int n , m , pre[N] , mcnt;
int cost[N] , height[N];
struct edge {
    int x , w , next;
}e[N * N] , g[N * N];
int bre[N] , wcnt;

struct opt {
    int x , y;
    LL mask; int w;
    opt (int _x , int _y , LL _mask , int _w) {
        x = _x , y = _y , mask = _mask , w = _w;
    }
    bool operator < (const opt& R) const {
        return w > R.w;
    }
};
priority_queue<opt> Q;
int d[N][N];
bool f[N][N];

void work()
{
    int i , x , y , z , w;
    while (!Q.empty()) Q.pop();
    height[0] = 0 , height[n - 1] = 1000;
    cost[0] = cost[n - 1] = 0;
    for (i = 1 ; i + 1 < n ; ++ i)
        scanf("%d%d",&cost[i] , &height[i]);
    memset(pre , -1 , sizeof(pre)) , mcnt = 0;
    memset(bre , -1 , sizeof(bre)) , wcnt = 0;
    for (i = 1 ; i <= m ; ++ i) {
        scanf("%d%d%d",&x,&y,&z);
        -- x , -- y;
        e[mcnt] = (edge) {y , z , pre[x]} , pre[x] = mcnt ++;
        g[wcnt] = (edge) {x , z , bre[y]} , bre[y] = wcnt ++;
    }
    memset(f , 0 , sizeof(f));
    memset(d , 63 , sizeof(d));
    Q.push(opt(0 , 0 , 1 , 0));
    while (!Q.empty()) {
        int u = Q.top().x , v = Q.top().y ; z = Q.top().w;
        LL mask = Q.top().mask; Q.pop();
        if (f[u][v]) continue;
        f[u][v] = 1;
        if (u == n - 1 && v == n - 1) {
            printf("%d\n" , z);
            return;
        }
        for (i = pre[u] ; ~i ; i = e[i].next) {
            y = e[i].x;
            if (height[y] >= height[u]) {
                w = z + e[i].w;
                if (~mask >> y & 1)
                    w += cost[y];
                if (!f[y][v] && w < d[y][v])
                    d[y][v] = w , Q.push(opt(y , v , mask | (1LL << y) , w));
            }
        }
        for (i = bre[v] ; ~i ; i = g[i].next) {
            y = g[i].x;
            if (height[y] >= height[v]) {
                w = z + g[i].w;
                if (~mask >> y & 1)
                    w += cost[y];
                if (!f[u][y] && w < d[u][y])
                    d[u][y] = w , Q.push(opt(u , y , mask | (1LL << y) , w));
            }
        }
    }
    puts("-1");
}


int main()
{
    freopen("1.txt" , "r" , stdin);
    while (scanf("%d%d",&n,&m) , n || m)
        work();
    return 0;
}


