#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define MAXN 30005
#define MAXM 300005
#define min(a,b) (a<b?a:b)
#define inf 0x7f7f7f7f
using namespace std;
struct edges{
    int u,next;
}e[MAXM],et[MAXM];
int N,M,idx,idxt;
int p[MAXN],pt[MAXN];
void addedge(int u,int v){
    e[idx].u=v;
    e[idx].next=p[u];
    p[u]=idx++;
}
void addedget(int u,int v){
    et[idxt].u=v;
    et[idxt].next=pt[u];
    pt[u]=idxt++;
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
int comfort[MAXN];
int comt[MAXN];
int sorted[MAXN],sidx;
bool mark[MAXN];
int dp[MAXN];

void topsort(int u){
    int v;
    mark[u]=true;
    for(int i=pt[u];i!=-1;i=et[i].next){
        v=et[i].u;
        if(!mark[v])topsort(v);
    }
    sorted[sidx++]=u;
}


void init(){
    idx=cont=ccnt=stop=0;
    memset(p,0xff,sizeof(p));
    memset(dfn,0,sizeof(dfn));
    memset(instack,false,sizeof(instack));
}
void initt(){
    idxt=sidx=0;
    memset(pt,0xff,sizeof(pt));
    memset(comt,0,sizeof(comt));
    memset(mark,false,sizeof(mark));
    memset(dp,0,sizeof(dp));
}

int main(){
    int a,b;
    while(~scanf("%d%d",&N,&M)){
        init();
        for(int i=0;i<N;i++){
            scanf("%d",&comfort[i]);
        }
        for(int i=0;i<M;i++){
            scanf("%d%d",&a,&b);
            addedge(a,b);
        }
        for(int i=0;i<N;i++){
            if(!dfn[i])tarjan(i);
        }
        int u,v;
        initt();
        for(int i=0;i<N;i++){
            if(comfort[i]>0)comt[color[i]]+=comfort[i];
            for(int j=p[i];j!=-1;j=e[j].next){
                v=e[j].u;
                if(color[i]!=color[v]){
                    addedget(color[i],color[v]);
                }
            }
        }
        for(int i=0;i<ccnt;i++){
            if(!mark[i])topsort(i);
        }
        int res=0;
        for(int i=0;i<sidx;i++){
            u=sorted[i];
            dp[u]=comt[u];
            int mt=0;
            for(int j=pt[u];j!=-1;j=et[j].next){
                v=et[j].u;
                if(dp[v]>mt)mt=dp[v];
            }
            dp[u]+=mt;
            if(dp[u]>res)res=dp[u];
        }
        printf("%d\n",res);
    }
    return 0;
}
