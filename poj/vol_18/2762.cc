#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define MAXN 1005
#define MAXM 15005
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
struct edges{
    int u,next;
}e[MAXM],es[MAXM];
int N,M,idx,idxs;
int p[MAXN],ps[MAXN];
void addedge(int u,int v){
    e[idx].u=v;
    e[idx].next=p[u];
    p[u]=idx++;
}
void addedges(int u,int v){
    es[idxs].u=v;
    es[idxs].next=ps[u];
    ps[u]=idxs++;
}
int low[MAXN],dfn[MAXN],cont;
int color[MAXN],ccnt;
int stack[MAXN],stop;
bool instack[MAXN];

void tarjan(int u){
    low[u]=dfn[u]=++cont;
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

void init(){
    idx=cont=ccnt=stop=0;
    memset(p,0xff,sizeof(p));
    memset(dfn,0,sizeof(dfn));
    memset(instack,false,sizeof(instack));
}

int degree[MAXN];
bool topsort(){
    int s,u,cnt;
    for(int i=0;i<ccnt;i++){
        cnt=0;
        for(int j=0;j<ccnt;j++){
            if(degree[j]==0){
                cnt++;
                s=j;
            }
        }
        if(cnt!=1)return false;
        degree[s]=-1;
        for(int j=ps[s];j!=-1;j=es[j].next){
            u=es[j].u;
            degree[u]--;
        }
    }
    return true;
}

void inits(){
    idxs=0;
    memset(ps,0xff,sizeof(ps));
    memset(degree,0,sizeof(degree));
}
int main(){
    int T,a,b;
    scanf("%d",&T);
    while(T--){
        init();
        scanf("%d%d",&N,&M);
        for(int i=0;i<M;i++){
            scanf("%d%d",&a,&b);
            a--;b--;
            addedge(a,b);
        }
        for(int i=0;i<N;i++){
            if(!dfn[i])tarjan(i);
        }
        inits();
        int v;
        for(int i=0;i<N;i++){
            for(int j=p[i];j!=-1;j=e[j].next){
                v=e[j].u;
                if(color[i]!=color[v]){
                    addedges(color[i],color[v]);
                    degree[color[v]]++;
                }
            }
        }
        if(topsort())printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
