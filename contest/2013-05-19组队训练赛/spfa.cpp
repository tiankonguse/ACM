const int maxn = 1000;
const int inf = 0x3fffffff;
const int V = 1001;
const int E = 20001;
int pnt[E],cost[E],nxt[E];
int e,head[V],dist[V];
bool vis[V];
int cnt[V];
queue<int>que;
void init()
{
    e=0;memset(head,-1,sizeof(head));
}
inline void addedge(int u,int v,int c)
{
    pnt[e]=v;
    cost[e]=c;
    nxt[e]=head[u];
    head[u]=e++;
}
int spfa(int src,int n)
{
    int i,u,v;
    for(i=1;i<=n;i++)
    {
        dist[i]=inf;
        cnt[i]=0;
        vis[i]=1;
    }
    while(!que.empty())que.pop();
    que.push(src);
    vis[src]=0;
    dist[src]=0;
    ++cnt[src];
    while
}
