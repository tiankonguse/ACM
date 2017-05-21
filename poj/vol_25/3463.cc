#include"iostream"
#include"queue"
#include"cstdio"
#include"string.h"
#define MAXN 1010
#define MAXM 10010
#define inf 0x3f3f3f3f
using namespace std;
struct edges{
    int u,c,next;
}e[MAXM];
struct node{
    int u,c,value;
    node(int u,int c,int value):u(u),c(c),value(value){}
    friend bool operator <(node a,node b){
        return a.c>b.c;
    }
};
int N,M,idx;
int p[MAXN],dist[MAXN][2],cnt[MAXN][2];
bool used[MAXN][2];

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
void dijkstra(int s,int d){
    int t,u,value,dis;
    
    memset(cnt,0,sizeof(cnt));
    memset(used,false,sizeof(used));
    for(int i=0;i<N;i++)dist[i][0]=dist[i][1]=inf;
    priority_queue<node>q;
    dist[s][0]=0;
    cnt[s][0]=1;
    node tmp(s,0,0);
    q.push(tmp);
    while(!q.empty()){
        tmp=q.top();
        q.pop();
        t=tmp.u;
        value=tmp.value;
        if(t==d)return;
        if(used[t][value])continue;
        used[t][value]=true;
        for(int i=p[t];i!=-1;i=e[i].next){
            u=e[i].u;
            dis=dist[t][value]+e[i].c;
            if(dis<dist[u][0]){
                if(dist[u][0]!=inf){
                    dist[u][1]=dist[u][0];
                    cnt[u][1]=cnt[u][0];
                    q.push(node(u,dist[u][1],1));
                }
                dist[u][0]=dis;
                cnt[u][0]=cnt[t][value];
                q.push(node(u,dist[u][0],0));
            }
            else if(dis==dist[u][0]){
                cnt[u][0]+=cnt[t][value];
            }
            else if(dis<dist[u][1]){
                dist[u][1]=dis;
                cnt[u][1]=cnt[t][value];
                q.push(node(u,dist[u][1],1));
            }
            else if(dis==dist[u][1]){
                cnt[u][1]+=cnt[t][value];
            }
        }
    }
}
int main(){
    int T,a,b,c;
    scanf("%d",&T);
    while(T--){
        init();
        scanf("%d%d",&N,&M);
        for(int i=0;i<M;i++){
            scanf("%d%d%d",&a,&b,&c);
            a--;b--;
            addedge(a,b,c);
        }
        scanf("%d%d",&a,&b);
        a--;b--;
        dijkstra(a,b);
        //printf("%d\n",dist[b][0]);
        if(dist[b][1]==dist[b][0]+1)printf("%d\n",cnt[b][1]+cnt[b][0]);
        else printf("%d\n",cnt[b][0]);
    }
    //system("pause");
    return 0;
}
