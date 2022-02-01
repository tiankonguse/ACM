#include"iostream"
#define typef int // type of flow
#define typec int // type of dis
#define MAXN 210
#define E 50000
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
struct node
{
    int x,y;
} men[110],house[110];
int dist(node a,node b)
{
    int dx=a.x-b.x,dy=a.y-b.y;
    dx=dx>0?dx:-dx;
    dy=dy>0?dy:-dy;
    return dx+dy;
}
int main()
{
    int N,M,cm,ch,S,T;
    char c;
    while(scanf("%d%d",&N,&M)&&N)
    {
        cm=0;
        ch=0;
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<M; j++)
            {
                scanf(" %c",&c);
                if(c=='m')
                {
                    men[cm].x=i;
                    men[cm++].y=j;
                }
                if(c=='H')
                {
                    house[ch].x=i;
                    house[ch++].y=j;
                }
            }
        }
        S=2*cm,T=2*cm+1;
        g.init(2*cm+2);
        for(int i=0; i<cm; i++)
        {
            g.addedge(S,i,1,0);
            g.addedge(cm+i,T,1,0);
            for(int j=0; j<ch; j++)
            {
                g.addedge(i,cm+j,1,dist(men[i],house[j]));
            }
        }
        printf("%d\n",g.mincost(S,T));
    }
    return 0;
}
