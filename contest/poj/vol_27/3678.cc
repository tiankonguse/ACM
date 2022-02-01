#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#define MAXN 2001
#define MAXM 4000005
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
            instack[t]=false;
            color[t]=ccnt;
        }while(t!=u);
        ccnt++;
    }
}
bool solve(){
    for(int i=0;i<N;i++){
        if(!dfn[i])tarjan(i);
    }
    for(int i=0;i<N;i+=2){
        if(color[i]==color[i+1])return false;
    }
    return true;
}
void init(){
    idx=cont=ccnt=stop=0;
    memset(p,0xff,sizeof(p));
    memset(dfn,0,sizeof(dfn));
    memset(instack,false,sizeof(instack));
}
char str[5];
int main(){
    int a,b,c;
    while(~scanf("%d%d",&N,&M)){
        init();
        N<<=1;
        for(int i=0;i<M;i++){
            scanf("%d%d%d%s",&a,&b,&c,str);
            if(str[0]=='A' && c==1){
                addedge(2*a+1,2*b+1);
                addedge(2*b+1,2*a+1);
                addedge(2*a,2*a+1);
                addedge(2*b,2*b+1);
            }
            else if(str[0]=='A' && c==0){
                addedge(2*a+1,2*b);
                addedge(2*b+1,2*a);
            }
            else if(str[0]=='O' && c==1){
                addedge(2*a,2*b+1);
                addedge(2*b,2*a+1);
            }
            else if(str[0]=='O' && c==0){
                addedge(2*a+1,2*b);
                addedge(2*b+1,2*a);
                addedge(2*a+1,2*a);
                addedge(2*b+1,2*b);
            }
            else if(str[0]=='X' && c==1){
                addedge(2*a,2*b+1);
                addedge(2*a+1,2*b);
                addedge(2*b,2*a+1);
                addedge(2*b+1,2*a);
            }
            else if(str[0]=='X' && c==0){
                addedge(2*a,2*b);
                addedge(2*b,2*a);
                addedge(2*a+1,2*b+1);
                addedge(2*b+1,2*a+1);
            }
        }
        if(solve())printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
