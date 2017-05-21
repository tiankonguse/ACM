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
#define maxn 222
#define maxm 200000
#define maxp 40040
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
struct lines{
    int a, b, c;
}line[maxp];

int main(){
    int n, p, t;
    int l, h, mid, res, r;
    while(~scanf("%d%d%d", &n, &p, &t)){
        l = inf, h = 0;
        for(int i=0;i<p;i++){
            scanf("%d%d%d", &line[i].a, &line[i].b, &line[i].c);
            l = min(l, line[i].c);
            h = max(h, line[i].c);
        }
        N = n;
       // cout<<l<<","<<h<<endl;
        while(l <= h){
            mid = (l + h) >> 1;
            init();
            for(int i=0;i<p;i++){
                if(line[i].c <= mid){
                    addedge(line[i].a, line[i].b, 1);
                    addedge(line[i].b, line[i].a, 1);
                }
            }
            r = sap(1, n);
            if(r >= t){
                res = mid;
                h = mid - 1;
            }
            else l = mid + 1;
        }
        printf("%d\n", res);
    }
    return 0;
}
