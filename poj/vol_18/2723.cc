#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define MAXN 4100
#define MAXM 5000000
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
    low[u]=dfn[u]=++cont;
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
    if(low[u]==dfn[u]){
        do{
            t=stack[--stop];
            color[t]=ccnt;
            instack[t]=false;
        }while(t!=u);
        ccnt++;
    }
}
bool solve(){
    for(int i=0;i<N*2;i++){
        if(!dfn[i])tarjan(i);
    }
    for(int i=0;i<N*2;i+=2){
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
int key[MAXN];
int door[MAXN][2];
void build(int n){
    init();
    int a;
    for(int i=0;i<=n;i++){
        for(int j=0;j<2;j++){
            a=key[door[i][j]];
            for(int it=0;it<=n;it++){
                if(it==i)continue;
                for(int jt=0;jt<2;jt++){
                    if(a==door[it][jt]){
                        addedge(2*i+j,2*it+(jt^1));
                    }
                }
            }
        }
    }
}

int main(){
    int a,b;
    while(scanf("%d%d",&M,&N) && (M||N)){
        for(int i=0;i<M;i++){
            scanf("%d%d",&a,&b);
            key[a]=b;
            key[b]=a;
        }
        for(int i=0;i<N;i++){
            scanf("%d%d",&door[i][0],&door[i][1]);
        }
        int l=0,h=N-1,mid;
        while(l<=h){
            mid=(l+h)>>1;
            build(mid);
            if(solve())l=mid+1;
            else h=mid-1;
        }
        printf("%d\n",h+1);
    }
    return 0;
}
