#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define MAXN 5555
#define E 50000
#define typef int // type of flow
#define typec int // type of dis
using namespace std;
const typef inff = 0x3f3f3f3f; // max of flow
const typec infc = 0x3f3f3f3f; // max of dis
struct network
{
    int nv, ne, pnt[E], nxt[E];
    int vis[MAXN], que[MAXN], head[MAXN], pv[MAXN], pe[MAXN];
    typef flow, cap[E];
    typec cost, dis[E], d[MAXN];
    void addedge(int u, int v, typef c, typec w)
    {
       // printf("add(%d,%d,%d,%d)\n",u,v,c,w);
        pnt[ne] = v;
        cap[ne] = c;
        dis[ne] = +w;
        nxt[ne] = head[u];
        head[u] = (ne++);
        pnt[ne] = u;
        cap[ne] = 0;
        dis[ne] = -w;
        nxt[ne] = head[v];
        head[v] = (ne++);
    }
    int mincost(int src, int sink)
    {
        int i, k, f, r;
        typef mxf;
        for (flow = 0, cost = 0; ; )
        {
            memset(pv, -1, sizeof(pv));
            memset(vis, 0, sizeof(vis));
            for (i = 0; i < nv; ++i) d[i] = infc;
            d[src] = 0;
            pv[src] = src;
            vis[src] = 1;
            for (f = 0, r = 1, que[0] = src; r != f; )
            {
                i = que[f++];
                vis[i] = 0;
                if (MAXN == f) f = 0;
                for (k = head[i]; k != -1; k = nxt[k])
                    if(cap[k] && dis[k]+d[i] < d[pnt[k]])
                    {
                        d[pnt[k]] = dis[k] + d[i];
                        if (0 == vis[pnt[k]])
                        {
                            vis[pnt[k]] = 1;
                            que[r++] = pnt[k];
                            if (MAXN == r) r = 0;
                        }
                        pv[pnt[k]]=i;
                        pe[pnt[k]]=k;
                    }
            }
            if (-1 == pv[sink]) break;
            for (k = sink, mxf = inff; k != src; k = pv[k])
                if (cap[pe[k]] < mxf) mxf = cap[pe[k]];
            flow += mxf;
            cost += d[sink] * mxf;
            for (k = sink; k != src; k = pv[k])
            {
                cap[pe[k]] -= mxf;
                cap[pe[k] ^ 1] += mxf;
            }
        }
        return cost;
    }
    void init(int v)
    {
        nv = v;
        ne = 0;
        memset(head, -1, sizeof(head));
    }
} g;

int mat[55][55];

int main(){
    int n, k;
    while(~scanf("%d%d", &n, &k)){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                scanf("%d", &mat[i][j]);
            }
        }
        if(k == 0) { puts("0"); continue;}
        g.init(n * n * 2 + 10);
        g.addedge(1, 2, k, 0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int ti = i - 1;
                g.addedge( (ti * n + j) * 2, (ti * n + j) * 2 + 1, 1, -mat[i][j]);
                g.addedge( (ti * n + j) * 2, (ti * n + j) * 2 + 1, k, 0);
                if(i >= 2) g.addedge( ((ti - 1) * n + j) * 2 + 1, (ti * n + j) * 2, k , 0);
                if(j >= 2) g.addedge( (ti * n + j - 1) * 2 + 1, (ti * n + j) * 2, k , 0);
            }
        }
        g.addedge(n * n * 2 + 1, n * n * 2 + 2, k, 0);
        printf("%d\n", -g.mincost(1, n * n * 2 + 2) );
    }
    return 0;
}
