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

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define maxn 400
#define maxm 20000
using namespace std;

struct edges{
    int u,c,next;
}e[maxm];
int p[maxn],idx;
int N,M;
void addedge(int u,int v,int c,int cc=0){
  //  printf("e[%d]:(%d,%d) = %d\n",idx,u,v,c);
    e[idx].u=v; e[idx].c=c;  e[idx].next=p[u]; p[u]=idx++;
  //  printf("e[%d]:(%d,%d) = %d\n",idx,v,u,c);
    e[idx].u=u; e[idx].c=cc; e[idx].next=p[v]; p[v]=idx++;

}
void init(){ idx=0; memset(p,0xff,sizeof(p));}

int gap[maxn],dis[maxn],pre[maxn],cur[maxn];

int sap(int s,int t){
    memset(dis,0,sizeof(dis));
    memset(gap,0,sizeof(gap));
    for(int i=1;i<=N;i++)cur[i]=p[i];
    int u=pre[s]=s, max_flow=0,step=inf;
    gap[0]=N;
    while(dis[s]<N){
loop:   for(int &i=cur[u];i!=-1;i=e[i].next){
            int v=e[i].u;
            if(e[i].c>0 && dis[u]==dis[v]+1){
                step=min(step,e[i].c);
                pre[v]=u;
                u=v;
                if(v==t){
                    max_flow += step;
                    for(u=pre[u];v!=s;v=u,u=pre[u]){
                        e[cur[u]].c -= step;
                        e[cur[u]^1].c += step;
                    }
                    step=inf;
                }
                goto loop;
            }
        }
        int mindis=N;
        for(int i=p[u];i!=-1;i=e[i].next){
            int v=e[i].u;
            if(e[i].c>0 && mindis>dis[v]){
                cur[u]=i;
                mindis=dis[v];
            }
        }
        if( (--gap[dis[u]])==0) break;
        gap[ dis[u] = mindis+1] ++;
        u=pre[u];
    }
    return max_flow;
}
int av[10];
int main(){
    int t, n;
    // S = 1, T = 2
    int week, des;
    int d, w;
    for(scanf("%d", &t); t--; ){
        scanf("%d", &n);
        init();
        week = des = 0;
        for(int i=3;i<n+3;i++){
            for(int j=1;j<=7;j++){
                scanf("%d", &av[j]);
            }
            scanf("%d%d", &d, &w);
            week = max(week, w);
            des += d;
            addedge(1, i, d);
            for(int j=1;j<=7;j++){
                if(av[j]){
                    for(int k=0;k<w;k++){
                        addedge(i, n + 2 + k * 7 + j, 1);
                    }
                }
            }
        }
        N = n + 2 + week * 7 ;
        for(int i=0;i<week;i++){
            for(int j=1;j<=7;j++){
                addedge(n + 2 + i * 7 + j, 2, 1);
            }
        }
        int res = sap(1, 2);
       // cout<<res<<endl;
        if(res == des) puts("Yes");
        else puts("No");
    }
    return 0;
}
