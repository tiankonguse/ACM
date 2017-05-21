#include"iostream"
#include"cstdio"
#include"string.h"
#include"queue"
#define MAXN 1005
#define MAXM 1000005
#define inf 0x3f3f3f3f
using namespace std;
struct edges{
    int u,c,next;
}e[MAXM];
int N,M,idx;
int p[MAXN],dist[MAXN];
bool used[MAXN];
queue<int>q;
void init(){
    idx=0;
    memset(p,0xff,sizeof(p));
}
void addedge(int u,int v,int c){
    e[idx].u=v;
    e[idx].c=c;
    e[idx].next=p[u];
    p[u]=idx++;
}
void spfa(int s){
    int t,u,w;
    while(!q.empty())q.pop();
    for(int i=0;i<N;i++)dist[i]=inf;
    memset(used,false,sizeof(used));
    dist[s]=0;
    q.push(s);
    while(!q.empty()){
        t=q.front();
        q.pop();
        used[t]=false;
        for(int i=p[t];i!=-1;i=e[i].next){
            u=e[i].u;
            w=e[i].c;
            if(dist[t]+w<dist[u]){
                dist[u]=dist[t]+w;
                if(!used[u]){
                    used[u]=true;
                    q.push(u);
                }
            }
        }
    }
}
int dp[MAXN];
void bfs(int s){
    int t,u;
    while(!q.empty())q.pop();
   // memset(used,false,sizeof(used));
   // used[s]=true;
    q.push(s);
    while(!q.empty()){
        t=q.front();
        q.pop();
        if(dp[t]==0)continue;
        for(int i=p[t];i!=-1;i=e[i].next){
            u=e[i].u;
            if(dist[u]<dist[t]){
                 dp[u]+=dp[t];
                 q.push(u);
            }
        }
        if(t!=1)dp[t]=0;
    }
}
int dfs(int s){
    if(dp[s]!=-1)return dp[s];
    dp[s]=0;
    int u;
    for(int i=p[s];i!=-1;i=e[i].next){
        u=e[i].u;
        if(dist[u]>dist[s])dp[s]+=dfs(u);
    }
    return dp[s];
}
int main(){
    int a,b,c;
    while(scanf("%d",&N)&&N){
        init();
        scanf("%d",&M);
        for(int i=0;i<M;i++){
            scanf("%d%d%d",&a,&b,&c);
            a--;b--;
            addedge(a,b,c);
            addedge(b,a,c);
        }
        spfa(1);
        memset(dp,0xff,sizeof(dp));
        dp[0]=1;
       // bfs(0);
        printf("%d\n",dfs(1));
    }
    return 0;
}

