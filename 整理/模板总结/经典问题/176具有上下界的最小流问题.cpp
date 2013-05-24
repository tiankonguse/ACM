#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
const int maxn=100+100+2;
const int maxm=(10000*3+10000)*2;
const int INF=100000000;
inline int min(int x,int y){return x<y?x:y;}
int d[maxn],q[maxn],st[maxn],top,len;
typedef struct node
{
    int v,flow;
    node *next;
    node *rev();    
}node;
node edge[maxm],*adj[maxn],*cur[maxn],*pre[maxn];
node inline *node::rev(){return edge+((this-edge)^1);}
inline void addedge(int u,int v,int flow)
{
    edge[len].v=v;edge[len].flow=flow;
    edge[len].next=adj[u];adj[u]=&edge[len++]; 
}
void init()
{
     for(int i=0;i<maxn;i++) adj[i]=NULL;
     len=0;
}
inline void insert(int u,int v,int flow)
{
    addedge(u,v,flow);
    addedge(v,u,0); 
}
bool bfs(int n,int s,int t)
{
    int i,u,v,head=0,tail=0;q[tail++]=s;
    fill(d,d+n,-1);
    node *p;d[s]=0;
    while(head<tail)
    {
          for(u=q[head++],p=adj[u];p;p=p->next)
          {
              v=p->v;
              if(d[v]==-1&&p->flow>0)
              {
                 d[v]=d[u]+1;
                 q[tail++]=v;
                 if(v==t)return 1;                    
              }                                 
          }          
    } 
    return 0;      
}
int dinic(int n,int s,int t)
{
    int i,u,v,tmp,maxflow=0;
    while(bfs(n,s,t))
    {
          st[top=1]=u=s;
          for(i=0;i<n;i++)cur[i]=adj[i];
          while(cur[s])
          {
                if(u!=t&&cur[u]&&cur[u]->flow>0&&d[u]+1==d[cur[u]->v]){v=cur[u]->v;st[++top]=v;pre[v]=cur[u];u=v;}
                else if(u==t)
                {
                    for(tmp=INF,i=top;i>1;i--)tmp=min(tmp,pre[st[i]]->flow);
                    for(maxflow+=tmp,i=top;i>1;i--)
                    {
                        pre[st[i]]->flow-=tmp;
                        pre[st[i]]->rev()->flow+=tmp;
                        if(pre[st[i]]->flow==0)top=i-1;                           
                    } 
                    u=st[top];    
                }
                else
                {
                    while(u!=s&&cur[u]==NULL)u=st[--top];
                    cur[u]=cur[u]->next;
                }           
          }           
    }
    return maxflow;      
}
int n,m,s,t;
int in[maxn],out[maxn];
struct Edge
{
       int u,v,l,c;
       Edge(){}
       Edge(int u1,int v1,int c1,int l1)
       {
            u=u1,v=v1,c=c1,l=l1;
       }
}edges[maxm];
void buildG()
{
     init();
     for(int i=1;i<=m;i++) insert(edges[i].u,edges[i].v,edges[i].c-edges[i].l);
     s=0,t=n+1;
     for(int i=1;i<=n;i++)
     {
         if(in[i]-out[i]>0) insert(s,i,in[i]-out[i]);
         else insert(i,t,out[i]-in[i]);
     }
}
bool ok(int x)
{
     buildG();
     insert(n,1,x);
     dinic(n+2,0,n+1);
     for(node *p=adj[s];p;p=p->next)
          if(p->flow) return false;
     return true;
}
void slove()
{
     if(n==1) 
     {
          puts("Impossible");
          return ;
     }
     int l=-1,r=10000000,ans=-1,mid;
     while(l+1<r)
     {
         mid=l+r>>1;
         //printf("%11d %d %11d %d\n",mid,l,r,ok(mid));
         if(ok(mid)) ans=mid,r=mid;
         else l=mid;
     }
     if(ans==-1) puts("Impossible");
     else
     {
         ok(ans);
         printf("%d\n",ans);
         for(int i=1;i<=m;i++)
              printf("%d%c",edge[i*2-1].flow+edges[i].l,i==m?'\n':' ');
     }
}

int main()
{
     freopen("in.txt","r",stdin);
     freopen("out.txt","w",stdout);
     scanf("%d%d",&n,&m);    
     memset(in,0,sizeof(in));
     memset(out,0,sizeof(out));
     for(int i=1;i<=m;i++)
     {
          int u,v,l,c;
          scanf("%d%d%d%d",&u,&v,&c,&l);
          if(l) l=c; else l=0;
          edges[i]=Edge(u,v,c,l);
          in[v]+=l,out[u]+=l;
     }
     slove();
}
