#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#define MAXN 5005
#define MAXM 25000005
#define min(a,b) (a<b?a:b)
using namespace std;
struct edges{
    int u,next;
}e[MAXM];
int N,M,idx;
int p[MAXN];
void addedge(int u,int v){
    e[idx].u=v;
    e[idx].next=p[u];
    p[u]=idx++;
}

int low[MAXN],dfn[MAXN],cont;
int color[MAXN],ccnt;
int stack[MAXN],stop;
bool instack[MAXN];

void tarjan(int u){
    dfn[u]=low[u]=++cont;
    instack[u]=true;
    stack[stop++]=u;
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
int degree[MAXN];
void init(){
    idx=ccnt=cont=stop=0;
    memset(p,0xff,sizeof(p));
    memset(dfn,0,sizeof(dfn));
    memset(instack,false,sizeof(instack));
    memset(degree,0,sizeof(degree));
}
int main(){
    int a,b;
    while(scanf("%d",&N) && N){
        scanf("%d",&M);
        init();
        for(int i=0;i<M;i++){
            scanf("%d%d",&a,&b);
            a--;b--;
            addedge(a,b);
        }
        for(int i=0;i<N;i++){
            if(!dfn[i])tarjan(i);
        }
        for(int i=0;i<N;i++){
            for(int j=p[i];j!=-1;j=e[j].next){
                if(color[i]!=color[e[j].u]){
                    degree[color[i]]++;
                }
            }
        }
        bool f=true;
        for(int i=0;i<N;i++){
            if(degree[color[i]]==0){
                if(f){printf("%d",i+1);f=false;}
                else printf(" %d",i+1);
            }
        }
        printf("\n");
    }
    return 0;
}
