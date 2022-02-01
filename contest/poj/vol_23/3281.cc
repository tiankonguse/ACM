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

#define MAXN 555
#define MAXM 1000100
#define inf 0x7f7f7f7f
using namespace std;
struct edges{
    int u,c,next;
}e[MAXM];
int p[MAXN],idx;
int N,M;
void addedge(int u,int v,int c,int cc=0){
    e[idx].u=v; e[idx].c=c;  e[idx].next=p[u]; p[u]=idx++;
    e[idx].u=u; e[idx].c=cc; e[idx].next=p[v]; p[v]=idx++;

}
void init(){ idx=0; memset(p,0xff,sizeof(p));}

int gap[MAXN],dis[MAXN],pre[MAXN],cur[MAXN];

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
int main(){
    int C,F,D,fi,di,a;
    int S,T;
    while(~scanf("%d%d%d",&C,&F,&D)){
        init();
        N=F+C+C+D+2;
        S=N-1;
        T=N;
        for(int i=1;i<=F;i++){
            addedge(S,i,1);
        }
        for(int i=1;i<=C;i++){
            scanf("%d%d",&fi,&di);
            for(int j=0;j<fi;j++){
                scanf("%d",&a);
                addedge(a,F+i,1);
            }
            addedge(F+i,F+C+i,1);
            for(int j=0;j<di;j++){
                scanf("%d",&a);
                a+= F+C+C;
                addedge(F+C+i,a,1);
            }
        }
        for(int i=F+C+C+1;i<=F+C+C+D;i++){
            addedge(i,T,1);
        }
        printf("%d\n",sap(S,T));
    }
    return 0;
}
