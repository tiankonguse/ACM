#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define MAXN 255
#define MAXM 105000
#define inf 0x7f7f7f7f
using namespace std;
struct edges{
    int u,c,t,next;
}e[MAXM];
int p[MAXN],idx;
int N,M,K;
void init(){ idx=0; memset(p,0xff,sizeof(p));}
void addedge(int u,int v,int c,int t){
    e[idx].u=v;
    e[idx].c=c;
    e[idx].t=t;
    e[idx].next=p[u];
    p[u]=idx++;
}
struct node{
    int u,c,t;
    friend bool operator<(node a,node b){
        return a.c>b.c;
    }
    node(int x,int y,int z){
        u=x,c=y,t=z;
    }
    node(){}
}tmp;
priority_queue<node>q;
int dist[MAXN][10010];
int mark[MAXN][2];
int bfs(int s,int t){
    int u,c,v,tk,tc;
    while(!q.empty())q.pop();
    q.push(node(s,0,0));
    for(int i=1;i<=N;i++)for(int j=0;j<=K;j++)dist[i][j]=inf;
    for(int i=1;i<=N;i++)mark[i][0]=mark[i][1]=inf;
    dist[s][0]=0;
    mark[s][0]=mark[s][1]=0;
    while(!q.empty()){
        tmp=q.top();
        q.pop();
        u=tmp.u;
        c=tmp.c;
        if(u==t)break;
     //   cout<<u<<","<<c<<endl;
        for(int i=p[u];i!=-1;i=e[i].next){
            v=e[i].u;
            tk=tmp.t+e[i].t;
            tc=c+e[i].c;
            if(tk<=K && tc<=dist[v][tk] && !(tc>=mark[v][0] && tk>=mark[v][1])){
                if(tc<=mark[v][0] && tk<=mark[v][1]){
                    mark[v][0]=tc;
                    mark[v][1]=tk;
                }
                dist[v][tk]=tc;
                q.push(node(v,dist[v][tk],tk));
            }
        }
    }
    int res=12345678;
    for(int i=0;i<=K;i++)if(dist[t][i]<res)res=dist[t][i];
    if(res!=12345678)return res;
    else return -1;
}
int main(){
    int a,b,c,d;
    scanf("%d%d%d",&K,&N,&M);
    init();
    for(int i=0;i<M;i++){
        scanf("%d%d%d%d",&a,&b,&c,&d);
        addedge(a,b,c,d);
    }
    printf("%d\n",bfs(1,N));
    return 0;
}
