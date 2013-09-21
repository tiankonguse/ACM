/*************************************************************************
    > File Name: E. Road02.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/12 20:22:14
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;

const int INF=0xfffff;
const int N=10005;


int G[N][N],dist[N];
int path[N][N];//从i到j的路径上最大边的权值
int pre[N],visit[N];
bool used[N][N];//边是否在该MST中
int n,m;

int Prim()
{
    int Mst=0;
    memset(visit, 0, sizeof(visit));
    memset(used, 0, sizeof(used));
    memset(path, 0, sizeof(path));
    visit[1]=1;
    for(int i=1; i<=n; ++i)
    {
        dist[i]=G[1][i];
        pre[i]=1;
    }
    for(int i=1; i<n; ++i)
    {
        int u=-1;
        for(int j=1; j<=n; ++j)
        {
            if(!visit[j])
            {
                if(u==-1||dist[j]<dist[u])
                    u=j;
            }
        }
        if(u == -1)return -1;
        used[u][pre[u]]=used[pre[u]][u]=true;//加入MST
        Mst+=G[pre[u]][u];
        visit[u]=1;
        for(int j=1; j<=n; ++j)
        {
            if(visit[j]&&j!=u)//求从u到j的路径上最大边的权值
            {
                path[u][j]=path[j][u]=max(path[j][pre[u]],dist[u]);
            }
            if(!visit[j])
            {
                if(dist[j]>G[u][j])//更新相邻顶点的dist
                {
                    dist[j]=G[u][j];
                    pre[j]=u;
                }
            }

        }
    }
    return Mst;
}

int main()
{
    //freopen("C:\\Users\\Administrator\\Desktop\\kd.txt","r",stdin);
    int tcase;
    scanf("%d",&tcase);
    while(tcase--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0; i<=n; i++)
            for(int j=i+1; j<=n; j++)
                G[i][j]=G[j][i]=INF;
        int u,v,w;
        for(int i=1; i<=m; ++i)
        {
            scanf("%d%d%d",&u,&v,&w);
            G[u][v]=G[v][u]=w;
        }
        int Mst=Prim();
        int res=INF;
        if(Mst == -1){
            printf("-1\n");
            continue;
        }
        for(int i=1; i<=n; ++i)
        {
            for(int j=1; j<=n; ++j)
                if(i!=j)
                {
                    if(!used[i][j])
                        res=min(res,Mst+G[i][j]-path[i][j]);
                }
        }
        if(res==Mst)
            puts("Not Unique!");
        else
            printf("%d\n",Mst);
    }
    return 0;
}
