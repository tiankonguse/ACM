#include"iostream"
#include"cstdio"
#include"cstring"
#include"cstdlib"
#define MAXN 10005
#define MAXM 100005
#define min(a,b) (a<b?a:b)
using namespace std;
struct edges{
    int u,next;
}e[MAXM];
int N,M;
int p[MAXN],idx;
void addedge(int u,int v){
    e[idx].u=v;
    e[idx].next=p[u];
    p[u]=idx++;
}
int stack[MAXN],top,cnt,cc;
int dfn[MAXN],low[MAXN],color[MAXN];
bool instack[MAXN];

void tarjan(int u){
    int v,t;
    dfn[u]=low[u]=++cnt;
    stack[top++]=u;
    instack[u]=true;
    for(int i=p[u];i!=-1;i=e[i].next){
        v=e[i].u;
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(instack[v])low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u]){
        do{
            t=stack[--top];
            color[t]=cc;
            instack[t]=false;
        }while(t!=u);
        cc++;
    }
}

int degree[MAXN];
int solve(){
    int v,r=0,t;
    for(int i=0;i<N;i++){
        for(int j=p[i];j!=-1;j=e[j].next){
            v=e[j].u;
            if(color[i]!=color[v]){
                degree[color[i]]++;
            }
        }
    }
    for(int i=0;i<cc;i++){
        if(degree[i]==0){
            r++;
            t=i;
        }
    }
    if(r==0)return N;
    else if(r==1){
        int ans=0;
        for(int i=0;i<N;i++){
            if(color[i]==t)ans++;
        }
        return ans;
    }
    else return 0;
}
void init(){
    idx=top=cnt=cc=0;
    memset(p,0xff,sizeof(p));
    memset(instack,false,sizeof(instack));
    memset(color,0,sizeof(color));
    memset(degree,0,sizeof(degree));
    memset(dfn,0,sizeof(dfn));
}
int main(){
    int a,b;
    while(~scanf("%d%d",&N,&M)){
        init();
        for(int i=0;i<M;i++){
            scanf("%d%d",&a,&b);
            addedge(a-1,b-1);
        }
        for(int i=0;i<N;i++){
                if(!dfn[i])tarjan(i);
        }
        //cout<<tot<<endl;
        //if(tot!=N){printf("%d\n",0);continue;}
        //for(int i=0;i<N;i++)printf("V[%d].color=%d\n",i,color[i]);
        printf("%d\n",solve());
    }
    return 0;
}
