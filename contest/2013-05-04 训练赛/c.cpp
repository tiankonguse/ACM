#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<ctime>
#include<stack>
#include<queue>
#include<vector>
#include<cstdlib>
#include<algorithm>
#define PI acos(-1.0)
#define inf 0x3fffffff

using namespace std;
const int maxn = 10005;
struct
{
    int to,next,val;
}edge[200005];
int head[maxn],tot=0;
int vis[maxn],dis[maxn];
void addedge(int a,int b)
{
    edge[tot].to=b;
    edge[tot].next=head[a];
    head[a]=tot++;
}
queue<int>q;
int pre[maxn];
int main()
{
    int n,m,i,j,a,b,c;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(head,-1,sizeof(head));
        tot=0;
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            addedge(a,b);
            addedge(b,a);
        }
        for(i=1;i<=n;i++)
        {
            pre[i]=1;dis[i]=inf;vis[i]=0;
        }
        vis[1]=1;ans=0;
        for(i=1;i<n;i++)
        {
            int tmp = inf,t=1;
            for(j=2;j<=n;j++)
            {
                if(!vis[j]&&dis[j]<tmp)
                {
                    t=j;tmp=dis[j];
                }
            }
            ans += tmp;
            for(j=1;j<=n;j++)
            {
                if(vis[j]==0)continue;
                maxl[j]
            }
        }
    }
}
