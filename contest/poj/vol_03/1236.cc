#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define MAXN 105
#define MAXM 10005
#define max(a,b) (a>b?a:b)
using namespace std;
struct edges{
    int u,next;
}e[MAXM];
int N,idx;
int p[MAXN];
int degree_in[MAXN], degree_out[MAXN];
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
    memset(degree_in,0,sizeof(degree_in));
    memset(degree_out,0,sizeof(degree_out));
}
int main(){
    int a;
    while(~scanf("%d",&N)){
        init();
        for(int i=0;i<N;i++){
            while(scanf("%d",&a)&&a){
                a--;
                addedge(i,a);
            }
        }
        for(int i=0;i<N;i++){
            if(!dfn[i])tarjan(i);
        }
        int v;
        for(int i=0;i<N;i++){
            for(int j=p[i];j!=-1;j=e[j].next){
                v=e[j].u;
                if(color[i]!=color[v]){
                    degree_in[color[v]]++;
                    degree_out[color[i]]++;
                }
            }
        }
        int ci=0,co=0;
        for(int i=0;i<ccnt;i++){
            if(degree_in[i]==0)ci++;
            if(degree_out[i]==0)co++;
        }
        printf("%d\n%d\n",ci,ccnt==1?0:max(ci,co));
    }
    return 0;
}
