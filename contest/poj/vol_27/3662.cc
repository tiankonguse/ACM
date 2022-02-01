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
#define maxn 1010
#define maxm 20010
using namespace std;

struct lines{
    int a, b, c;
}line[maxm];

struct edges{
    int u, c, next;
}e[maxm];
int idx, p[maxn];
void addedge(int u, int v, int c){
    e[idx].u = v;
    e[idx].c = c;
    e[idx].next = p[u];
    p[u] = idx++;
}
void init(){
    idx = 0;
    memset(p, 0xff, sizeof(p));
}
int dist[maxn];
bool used[maxn];
queue<int> q;

int spfa(int N, int s){
    int t,u,w;
    while(!q.empty())q.pop();
    memset(used,false,sizeof(used));
    for(int i=1;i<=N;i++) dist[i]=inf;
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
    return dist[N];
}
bool check(int n, int p, int k, int limit){
    init();
    for(int i=0;i<p;i++){
        if(line[i].c <= limit){
            addedge(line[i].a, line[i].b, 0);
            addedge(line[i].b, line[i].a, 0);
        }
        else{
            addedge(line[i].a, line[i].b, 1);
            addedge(line[i].b, line[i].a, 1);
        }
    }
    return spfa(n, 1) <= k;
}
int main(){
    int n, p, k, mx, mi, a, b, d, l, r, mid, res;
    while(~scanf("%d%d%d", &n, &p, &k)){
        mx = 0, mi = inf;
        init();
        for(int i=0;i<p;i++){
            scanf("%d%d%d", &line[i].a, &line[i].b, &line[i].c);
            addedge(line[i].a, line[i].b, 1);
            addedge(line[i].b, line[i].a, 1);
            mx = max(mx, line[i].c);
            mi = min(mi, line[i].c);
        }
        d = spfa(n, 1);
        if(d == inf) puts("-1");
        else if(d <= k) puts("0");
        else{
            l = mi, r = mx;
            while(l <= r){
                mid = (l + r) >> 1;
                if(check(n, p, k, mid)){
                    res = mid;
                    r = mid - 1;
                }
                else l = mid + 1;
            }
            printf("%d\n", res);
        }
    }

    return 0;
}
