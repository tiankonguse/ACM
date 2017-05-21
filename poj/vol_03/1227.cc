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
#define maxn 110
#define maxm 10100
using namespace std;
struct edges{
    int u, next;
}e[maxm];
int p[maxn], idx;
void addedge(int u, int v){
    e[idx].u = v;
    e[idx].next = p[u];
    p[u] = idx++;
}
void init(){
    idx = 0;
    memset(p, 0xff, sizeof(p));
}
int rs[maxn];
struct node{
    int u, t;
    node(int _u, int _t){ u = _u, t = _t;}
    node(){}
}tmp;
queue<node>q;
bool mark[maxn][2];
void bfs(int s){
    int u, v, t;
    while(!q.empty()) q.pop();
    memset(mark, false, sizeof(mark));
    mark[s][0] = true;
    q.push(node(s, 0));
    while(!q.empty()){
        tmp = q.front(); q.pop();
        u = tmp.u;
        t = tmp.t;
        for(int i=p[u];i!=-1;i=e[i].next){
            v = e[i].u;
            if(!mark[v][t ^ 1]){
                mark[v][t ^ 1] = true;
                q.push(node(v, t ^ 1));
            }
        }
    }
}
int main(){
    int T, n, k;
    int id, m, a;
    for(scanf("%d", &T);T--;){
        init();
        scanf("%d%d", &n, &k);
        for(int i=0;i<n;i++){
            scanf("%d%d", &id, &m);
            for(int j=0;j<m;j++){
                scanf("%d", &a);
                addedge(id, a);
            }
        }
        for(int i=0;i<k;i++){
            scanf("%d", &rs[i]);
        }
        bfs(rs[0]);
        bool flag = true;
        for(int i=0;i<k;i++){
            flag &= mark[ rs[i] ][0];
            if(!flag) break;
        }
        puts(flag? "YES": "NO");
    }
    return 0;
}
