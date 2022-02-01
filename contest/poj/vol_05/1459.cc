#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAXN 205
#define MAXM 22000
#define inf 0x7f7f7f7f
using namespace std;
struct edges{
    int u,c,next;
}e[MAXM];
int p[MAXN],idx;
int N;
int n,m,np,nc;
void addedge(int u,int v,int c,int cc=0){
    e[idx].u=v; e[idx].c=c;  e[idx].next=p[u]; p[u]=idx++;
    e[idx].u=u; e[idx].c=cc; e[idx].next=p[v]; p[v]=idx++;
}
void init(){ idx=0; memset(p,0xff,sizeof(p));}
int gap[MAXN],dis[MAXN],pre[MAXN],cur[MAXN];

int sap(int s,int t){
    memset(dis,0,sizeof(dis));
    memset(gap,0,sizeof(gap));
    for(int i=1;i<=N;i++)cur[i]=p[i];
    int u=pre[s]=s, max_flow=0,step=inf;
    gap[0]=N;
    while(dis[s]<N){
loop:   for(int &i=cur[u];i!=-1;i=e[i].next){
            int v=e[i].u;
            if(e[i].c>0 && dis[u]==dis[v]+1){
                step=min(step,e[i].c);
                pre[v]=u;
                u=v;
                if(v==t){
                    max_flow += step;
                    for(u=pre[u];v!=s;v=u,u=pre[u]){
                        e[cur[u]].c -= step;
                        e[cur[u]^1].c += step;
                    }
                    step=inf;
                }
                goto loop;
            }
        }
        int mindis=N;
        for(int i=p[u];i!=-1;i=e[i].next){
            int v=e[i].u;
            if(e[i].c>0 && mindis>dis[v]){
                cur[u]=i;
                mindis=dis[v];
            }
        }
        if( (--gap[dis[u]])==0) break;
        gap[ dis[u] = mindis+1] ++;
        u=pre[u];
    }
    return max_flow;
}


int main(){
    int a,b,c;
    while(~scanf("%d%d%d%d",&n,&np,&nc,&m)){
        init();
        N=n+2;
        int start=n+1, end=N;
        for(int i=0;i<m;i++){
            scanf(" (%d,%d)%d",&a,&b,&c);
            addedge(a+1,b+1,c);
        }
        for(int i=0;i<np;i++){
            scanf(" (%d)%d",&a,&c);
            addedge(start,a+1,c);
        }
        for(int i=0;i<nc;i++){
            scanf(" (%d)%d",&a,&c);
            addedge(a+1,end,c);
        }
        printf("%d\n",sap(start,end));
    }
    return 0;
}
