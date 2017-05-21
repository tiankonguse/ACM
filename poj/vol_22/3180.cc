#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define MAXN 10005
#define MAXM 50005
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
int dfn[MAXN],low[MAXN],cont;
int stack[MAXN],stop;
bool instack[MAXN];
int res=0;
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
    if(low[u]==dfn[u]){
        int cnt=0;
        do{
            t=stack[--stop];
            cnt++;
        }while(t!=u);
        if(cnt>1)res++;
    }
}

void init(){
    idx=cont=stop=res=0;
    memset(p,0xff,sizeof(p));
    memset(dfn,0,sizeof(dfn));
    memset(instack,false,sizeof(instack));
}
int main(){
    int a,b;
    while(~scanf("%d%d",&N,&M)){
        init();
        for(int i=0;i<M;i++){
            scanf("%d%d",&a,&b);
            a--;b--;
            addedge(a,b);
        }
        for(int i=0;i<N;i++){
            if(!dfn[i])tarjan(i);
        }
        printf("%d\n",res);
    }
    return 0;
}
