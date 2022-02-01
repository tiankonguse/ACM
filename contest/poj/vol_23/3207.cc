#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define MAXN 1005
#define MAXM 250005
#define min(a,b) (a<b?a:b)
using namespace std;
struct edges{
    int u,next;
}e[MAXM];
int N,idx;
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
    int v,t;
    dfn[u]=low[u]=++cont;
    stack[stop++]=u;
    instack[u]=true;
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
    idx=ccnt=cont=stop=0;
    memset(p,0xff,sizeof(p));
    memset(dfn,0,sizeof(dfn));
    memset(instack,false,sizeof(instack));
}
int line[MAXN][2];
int main(){
    while(~scanf("%*d%d",&N)){
        init();
        for(int i=0;i<N;i++){
            scanf("%d%d",&line[i][0],&line[i][1]);
            if(line[i][0]>line[i][1])swap(line[i][0],line[i][1]);
        }
        for(int i=0;i<N;i++){
            for(int j=i+1;j<N;j++){
                if((line[i][0]<line[j][0] && line[i][1]>line[j][0] && line[i][1]<line[j][1])||
                   (line[j][0]<line[i][0] && line[j][1]>line[i][0] && line[j][1]<line[i][1])){
                    addedge(i<<1,(j<<1)+1);
                    addedge(j<<1,(i<<1)+1);
                    addedge((i<<1)+1,j<<1);
                    addedge((j<<1)+1,i<<1);
                 //   printf("add(%d,%d)\n",i<<1,(j<<1)+1);
                 //   printf("add(%d,%d)\n",j<<1,(i<<1)+1);
                 //   printf("add(%d,%d)\n",(i<<1)+1,j<<1);
                 //   printf("add(%d,%d)\n",(j<<1)+1,i<<1);
                }
            }
        }
        N<<=1;
        if(solve())printf("panda is telling the truth...\n");
        else printf("the evil panda is lying again\n");

       // for(int i=0;i<N;i++)printf("%d ",color[i]);printf("\n");
    }
    return 0;
}
