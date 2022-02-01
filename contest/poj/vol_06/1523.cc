#include"iostream"
#include"cstdlib"
#include"cstdio"
#include"cstring"
#define MAXN 1005
#define MAXM 500005
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
int dfn[MAXN],low[MAXN],cnt[MAXN],cont;
void dfs(int u){
    int v;
    dfn[u]=low[u]=++cont;
    for(int i=p[u];i!=-1;i=e[i].next){
        v=e[i].u;
        if(!dfn[v]){
            dfs(v);
            low[u]=min(low[u],low[v]);
            if(low[v]>=dfn[u])cnt[u]++;
        }
        else
            low[u]=min(low[u],dfn[v]);
    }
    if(u!=0)cnt[u]++;
}
void init(){
    idx=cont=0;
    memset(p,0xff,sizeof(p));
    memset(dfn,0,sizeof(dfn));
    memset(cnt,0,sizeof(cnt));
}
int main(){
    int a,b,f,cas=1;
    while(scanf("%d",&f)&&f){
        init();
        N=0;
        a=f; scanf("%d",&b);
        if(a>b)N=a;else N=b;
        addedge(a-1,b-1);
        addedge(b-1,a-1);
        while(scanf("%d",&a)&&a){
            scanf("%d",&b);
            if(a>N)N=a;
            if(b>N)N=b;
            addedge(a-1,b-1);
            addedge(b-1,a-1);
        }
        N--;
        dfs(0);
        bool flag=false;
        printf("Network #%d\n",cas++);
        for(int i=0;i<N;i++){
            if(cnt[i]>1){
                flag=true;
                printf("  SPF node %d leaves %d subnets\n",i+1,cnt[i]);
            }
        }
        if(!flag)printf("  No SPF nodes\n");
        printf("\n");
    }
    return 0;
}
