#include"iostream"
#include"cstdlib"
#define V 501
#define typec int // type of cost
const typec inf = 0x3f3f3f3f; // max of cost
int vis[V];
typec lowc[V];
int map[V][V];
typec prim(typec cost[][V], int n) // vertex: 0 ~ n-1
{
    int i, j, p;
    typec minc, res = 0;
    memset(vis, 0, sizeof(vis));
    vis[0] = 1;
    for (i=1; i<n; i++) lowc[i] = cost[0][i];
    for (i=1; i<n; i++)
    {
        minc = inf;
        p = -1;
        for (j=0; j<n; j++)
            if (0 == vis[j] && minc > lowc[j])
            {
                minc = lowc[j];
                p = j;
            }
        if (inf == minc) return -1; // 原图不连通
        if(minc>res)res=minc;
        vis[p] = 1;
        for (j=0; j<n; j++)
            if (0 == vis[j] && lowc[j] > cost[p][j])
                lowc[j] = cost[p][j];
    }
    return res;
}
int main()
{
    int T,N;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                scanf("%d",&map[i][j]);
            }
        }
        printf("%d\n",prim(map,N));
    }
    return 0;
}
