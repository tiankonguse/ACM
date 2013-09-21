#include<stdio.h>
#include<string.h>
const int N=51,M=N*N,MAX=0x7fffffff;
int g[N][M],map[N][N],n,m;
int lx[N],ly[M],vstx[N],vsty[M],match[M],slack[M];
int dfs(int x)
{
    vstx[x]=1;
    for(int y=0;y<m;y++)
        if(!vsty[y])
        {
            int tmp=lx[x]+ly[y]-g[x][y];
            if(tmp==0)
            {
                 vsty[y]=1;
                 if(match[y]<0||dfs(match[y]))
                 {
                      match[y]=x;
                      return 1;
                 }
            }
            else if(tmp<slack[y]) slack[y]=tmp;
        }
    return 0;
}
int KM()
{
    memset(match,-1,sizeof(match));
    memset(ly,0,sizeof(ly));
    for(int i=0;i<n;i++)
    {
         lx[i]=-MAX;
         for(int j=0;j<m;j++)
            if(lx[i]<g[i][j])
                lx[i]=g[i][j];         
    }
    for(int x=0;x<n;x++)
    {
           for(int i=0;i<m;i++) slack[i]=MAX;
           while(true)
           {
                 memset(vstx,0,sizeof(vstx));
                 memset(vsty,0,sizeof(vsty));
                 if(dfs(x)) break;
                 int ex=MAX;
                 for(int i=0;i<m;i++)
                     if(!vsty[i]&&ex>slack[i]) ex=slack[i];
                 for(int i=0;i<n;i++)
                     if(vstx[i]) lx[i]-=ex;
                 for(int i=0;i<m;i++)
                     if(vsty[i]) ly[i]+=ex;
                     else slack[i]-=ex;
           }
    }
    int ans=0;
    for(int i=0;i<m;i++)
       if(match[i]>=0) ans+=g[match[i]][i];
    return ans;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
         int x,y;
         scanf("%d%d",&x,&y);
         n=x,m=x*y;
         for(int i=0;i<x;i++)
             for(int j=0;j<y;j++)
                scanf("%d",&map[i][j]);
         memset(g,0,sizeof(g));
         for(int i=0;i<x;i++)
            for(int j=0;j<y;j++)
               for(int k=0;k<x;k++)
                  g[i][k*y+j]=-(k+1)*map[i][j];
         printf("%.6f\n",double(-KM())/n);
    }
}
