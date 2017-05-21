#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAXN 40005
#define MAXM 80005
#define MAXK 10005
using namespace std;
int N,M,K,idx1,idx2;
struct edges{
    int u,w,next;
}e1[MAXM],e2[MAXM];
int p1[MAXN],p2[MAXN];

void addedge1(int u,int v,int w){
    e1[idx1].u=v;
    e1[idx1].w=w;
    e1[idx1].next=p1[u];
    p1[u]=idx1++;
}
void addedge2(int u,int v,int id){
    e2[idx2].u=v;
    e2[idx2].w=id;
    e2[idx2].next=p2[u];
    p2[u]=idx2++;
}

int ans[MAXK];
int parents[MAXN];
int dist[MAXN];
bool used[MAXN];
int find(int a){
    if(parents[a]<0)return a;
    else return parents[a]=find(parents[a]);
}
void dfs(int u,int dis){
    int v,w;
    used[u]=true;
    dist[u]=dis;
    for(int i=p2[u];i!=-1;i=e2[i].next){
        v=e2[i].u;
        w=e2[i].w;
        if(used[v]){
            ans[w]=dist[u]+dist[v]-2*dist[find(v)];
        }
    }
    for(int i=p1[u];i!=-1;i=e1[i].next){
        v=e1[i].u;
        w=e1[i].w;
        if(!used[v]){
            dfs(v,dis+w);
            parents[v]=u;
        }
    }
}

void init(){
    idx1=idx2=0;
    memset(p1,0xff,sizeof(p1));
    memset(p2,0xff,sizeof(p2));
    memset(parents,0xff,sizeof(parents));
    memset(used,false,sizeof(used));
}
int main(){
    int a,b,c;
    char buf[10];
    while(~scanf("%d%d",&N,&M)){
        init();
        for(int i=0;i<M;i++){
            scanf("%d%d%d%s",&a,&b,&c,buf);
            a--;b--;
            addedge1(a,b,c);
            addedge1(b,a,c);
        }
        scanf("%d",&K);
        for(int i=0;i<K;i++){
            scanf("%d%d",&a,&b);
            a--;b--;
            addedge2(a,b,i);
            addedge2(b,a,i);
        }
        dfs(0,0);
        for(int i=0;i<K;i++)printf("%d\n",ans[i]);
    }
    return 0;
} 
