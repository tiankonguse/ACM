#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<queue>
#define MAXN 505
#define MAXM 250005
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
struct edges{
    int u,w,next;
}e[MAXM],es[MAXM];
int N,M,K,idx,idxs;
int p[MAXN],ps[MAXN];
void addedge(int u,int v,int w){
    e[idx].u=v;
    e[idx].next=p[u];
    e[idx].w=w;
    p[u]=idx++;
}
void addedges(int u,int v,int w){
    es[idxs].u=v;
    es[idxs].w=w;
    es[idxs].next=ps[u];
    ps[u]=idxs++;
}
int low[MAXN],dfn[MAXN],cont;
int stack[MAXN],stop;
int color[MAXN],ccnt;
bool instack[MAXN];

void tarjan(int u){
    dfn[u]=low[u]=++cont;
    stack[stop++]=u;
    instack[u]=true;
    int v,t;
    for(int i=p[u];i!=-1;i=e[i].next){
        v=e[i].u;
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(instack[v]){
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(dfn[u]==low[u]){
        do{
            t=stack[--stop];
            color[t]=ccnt;
            instack[t]=false;
        }while(t!=u);
        ccnt++;
    }
}

void inits(){
    idxs=0;
    memset(ps,0xff,sizeof(ps));
}
void init(){
    idx=cont=stop=ccnt=0;
    memset(p,0xff,sizeof(p));
    memset(dfn,0,sizeof(dfn));
    memset(instack,false,sizeof(instack));
}

struct node{
    int u,c;
    node(int a,int b){u=a;c=b;}
    node(){}
    friend bool operator<(node a,node b){
        return a.c>b.c;
    }
}t;
int dist[MAXN];
bool used[MAXN];
priority_queue<node>q;
int dijkstra(int s,int d){
    while(!q.empty())q.pop();
    memset(used,false,sizeof(used));
    memset(dist,0x7f,sizeof(dist));
    dist[s]=0;
    q.push(node(s,0));
    int u,v,w;
    while(!q.empty()){
        t=q.top();
        q.pop();
        u=t.u;
        if(used[u])continue;
        else used[u]=true;
        if(u==d)return dist[d];
        for(int i=ps[u];i!=-1;i=es[i].next){
            v=es[i].u;
            w=es[i].w;
            if(used[v])continue;
            if(dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
                q.push(node(v,dist[v]));
            }
        }
    }
    if(!used[d])return -1;
}


int main(){
    int a,b,c,k;
    while(scanf("%d%d",&N,&M)&&N){
        init();
        for(int i=0;i<M;i++){
            scanf("%d%d%d",&a,&b,&c);
            addedge(a-1,b-1,c);
        }
        for(int i=0;i<N;i++){
            if(!dfn[i])tarjan(i);
        }
        int v;
        inits();
        for(int i=0;i<N;i++){
            for(int j=p[i];j!=-1;j=e[j].next){
                v=e[j].u;
                if(color[i]!=color[v]){
                    addedges(color[i],color[v],e[j].w);
                }
            }
        }
        scanf("%d",&k);
        while(k--){
            scanf("%d%d",&a,&b);
            int res=dijkstra(color[a-1],color[b-1]);
            if(res==-1)printf("Nao e possivel entregar a carta\n");
            else printf("%d\n",res);
        }
        printf("\n");
    }
    return 0;
}
