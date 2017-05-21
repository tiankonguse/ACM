#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MAXN 1005
#define MAXM 2005
#define inf 0x3f3f3f3f
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
struct planet{
    int id,x,y,z;
}pl[MAXN];
void init(){
    idx=0;
    memset(p,0xff,sizeof(p));
}
int dist(planet a,planet b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z);
}

bool used[MAXN];
int dfs(int u){
    used[u]=true;
    int res=0,d,v;
    for(int i=p[u];i!=-1;i=e[i].next){
        v=e[i].u;
        if(!used[v]){
            d=dfs(v);
            if(d>res)res=d;
        }
    }
    return res+1;
}
int dis[MAXN];
int ans[MAXN];
int main(){
    while(scanf("%d",&N) && N){
        init();
        for(int i=0;i<N;i++){
            scanf("%d%d%d%d",&pl[i].id,&pl[i].x,&pl[i].y,&pl[i].z);
            int _min=inf,d,mid;
            for(int j=0;j<i;j++){
                d=dist(pl[i],pl[j]);
                if(d<_min){
                    _min=d;
                    mid=j;
                }
            }
            if(i!=0){
                addedge(mid,i);
                addedge(i,mid);
            }
        }
        int k,res=inf;
        for(int i=0;i<N;i++){
            memset(used,false,sizeof(used));
            dis[i]=dfs(i);
            if(dis[i]<res)res=dis[i];
        }
        int cnt=0;
        for(int i=0;i<N;i++){
            if(dis[i]==res)ans[cnt++]=pl[i].id;
        }
        sort(ans,ans+cnt);
        for(int i=0;i<cnt;i++)printf("%d ",ans[i]);
        printf("\n");
    }
    return 0;
}
