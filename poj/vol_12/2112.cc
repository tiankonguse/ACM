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
#define maxn 250
#define maxm 100000
using namespace std;
int mp[maxn][maxn];
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

int main(){
    int k, c, m, n;
    int l, h, mid;
    while(~scanf("%d%d%d", &k, &c, &m)){
        n = k + c;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                scanf("%d", &mp[i][j]);
                if(mp[i][j] == 0) mp[i][j] = inf;
            }
        }
        for(int t=1;t<=n;t++){
            for(int i=1;i<=n;i++){
                if(t == i) continue;
                for(int j=1;j<=n;j++){
                    if(i == j) continue;
                    mp[i][j] = min(mp[i][j], mp[i][t] + mp[t][j]);
                }
            }
        }
        N = n + 2;
        l = inf, h = 0;
        for(int i=k+1;i<=n;i++){
            for(int j=1;j<=k;j++){
                if(mp[i][j]!=inf){
                l = min(l, mp[i][j]);
                h = max(h, mp[i][j]);
                }
            }
        }
        int r, res;
        while(l <= h){
            mid = (l + h) >> 1;
            init();
            for(int i=1;i<=k;i++){
                addedge(i, n + 2, m);
            }
            for(int i=k+1;i<=n;i++){
                for(int j=1;j<=k;j++){
                    if(mp[i][j] <= mid){
                        addedge(i, j, 1);
                    }
                }
                addedge(n + 1, i, 1);
            }
            r = sap(n + 1, n + 2);
            if(r == c){
                res = mid;
                h = mid - 1;
            }
            else l = mid + 1;
        }
        printf("%d\n", res);
    }
    return 0;
}
