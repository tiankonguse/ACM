#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define MAXL 45
#define MAXN 1605
#define MAXM 10005
#define inf 0x7f7f7f7f
#define min(a,b) (a<b?a:b)
using namespace std;
struct edges{
    int u,w,next;
}e[MAXM],es[MAXM];
int H,W;
int N,idx,idxs;
int p[MAXN],ps[MAXN];
void addedge(int u,int v){
    e[idx].u=v;
    e[idx].next=p[u];
    p[u]=idx++;
}
int dfn[MAXN],low[MAXN],cont;
int color[MAXN],ccnt;
int stack[MAXN],stop;
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
int ores[MAXN];

void init(){
    idx=cont=ccnt=stop=0;
    memset(p,0xff,sizeof(p));
    memset(dfn,0,sizeof(dfn));
    memset(instack,false,sizeof(instack));
}
void addedges(int u,int v,int w){
    es[idxs].u=v;
    es[idxs].w=w;
    es[idxs].next=ps[u];
    ps[u]=idxs++;
}
void inits(){
    idxs=0;
    memset(ps,0xff,sizeof(ps));
    memset(ores,0,sizeof(ores));
}
bool visit[MAXN];
int q[MAXM],dist[MAXN];
int spfa(int s){
    int l=0,h=1,t,u,w;
    memset(visit,false,sizeof(visit));
    memset(dist,0xff,sizeof(dist));
    dist[s]=0;
    q[0]=s;
    while(l<h){
        t=q[l++];
        visit[t]=false;
        for(int i=ps[t];i!=-1;i=es[i].next){
            u=es[i].u;
            w=es[i].w;
            if(dist[t]+w>dist[u]){
                dist[u]=dist[t]+w;
                if(!visit[u]){
                    visit[u]=true;
                    q[h++]=u;
                }
            }
        }
    }
    int res=0;
    for(int i=0;i<ccnt;i++){
        if(dist[i]>res)res=dist[i];
    }
    return res;
}
char map[MAXL][MAXL];
int main(){
    int T,a,b,t;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&H,&W);
        init();
        N=H*W;
        for(int i=0;i<H;i++)scanf(" %s",map[i]);
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                t=i*W+j;
                if(map[i][j]=='#')continue;
                else if(map[i][j]=='*'){
                    scanf("%d%d",&a,&b);
                    //if(map[a][b]!='#')
                        addedge(t,a*W+b);
                }
                if(i!=H-1 && map[i+1][j]!='#')addedge(t,t+W);
                if(j!=W-1 && map[i][j+1]!='#')addedge(t,t+1);
            }
        }
        for(int i=0;i<N;i++){
            if(!dfn[i])tarjan(i);
        }
        inits();
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                if(map[i][j]>='0' && map[i][j]<='9'){
                    ores[color[i*W+j]]+=map[i][j]-'0';
                }
            }
        }
        int v;
        for(int i=0;i<N;i++){
            for(int j=p[i];j!=-1;j=e[j].next){
                v=e[j].u;
                if(color[i]!=color[v]){
                    addedges(color[i],color[v],ores[color[v]]);
                }
            }
        }
        printf("%d\n",ores[color[0]]+spfa(color[0]));
    }
    return 0;
}
