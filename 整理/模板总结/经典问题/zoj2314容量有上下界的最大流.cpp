#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
const int maxn=100+100+2;
const int maxm=(100000*3+100000)*2;
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
struct Edge
{
       int u,v,l,c,f;
       void read()
       {
            scanf("%d%d%d%d",&u,&v,&l,&c);
            f=0;
       }
}edges[maxm];
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
void slove()
{
     for(node *p=adj[s];p;p=p->next)
          if(p->flow)
          {
               puts("NO");
               return;
          }
     for(node *p=adj[t];p;p=p->next)
          if(p->flow!=out[p->v]-in[p->v])
          {
               puts("NO");
               return ;
          }
     puts("YES");
     for(int i=0;i<m;i++)
     {
         printf("%d\n",edges[i].l+edge[2*i+1].flow);
     }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
         init();
         memset(in,0,sizeof(in));
         memset(out,0,sizeof(out));
         scanf("%d%d",&n,&m);
         for(int i=0;i<m;i++)
         {
              edges[i].read();
              in[edges[i].v]+=edges[i].l;
              out[edges[i].u]+=edges[i].l;
              insert(edges[i].u,edges[i].v,edges[i].c-edges[i].l);
         }
         s=0,t=n+1;
         for(int i=1;i<=n;i++)
         {
              if(out[i]-in[i]>0) insert(i,t,out[i]-in[i]);
              else insert(s,i,in[i]-out[i]);
         }
         dinic(n+2,s,t);
         slove();
         if(T) puts("");
    }
}
