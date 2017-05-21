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
#define maxn 5050
#define maxm 55555
using namespace std;
struct edges{
    int u, c, next;
}e[maxm];
int p[maxn], idx;
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
int loc[maxn];
struct node{
    int u, d, t;
    node(int _u, int _d, int _t){ u = _u, d = _d, t = _t;}
    node(){}
}tmp;
set<int> st[maxn];;
queue<node> q;

int bfs(){
    while(!q.empty()) q.pop();
    q.push(node(1, 0, 0));
    st[1].insert(0);
    int u, v;
    while(!q.empty()){
        tmp = q.front();
        q.pop();
      //  printf("%d %d %d\n", tmp.u, tmp.d, tmp.t);
        u = tmp.u;
        for(int i=p[u];i!=-1;i=e[i].next){
            v = e[i].u;
            if(v == 1 && tmp.d + e[i].c != 0 && (tmp.d + e[i].c) % 360 == 0) return tmp.t + 1;
            if(st[v].find(tmp.d + e[i].c) == st[v].end()){
                st[v].insert(tmp.d + e[i].c);
                q.push(node(v, tmp.d + e[i].c, tmp.t + 1));
            }
        }
    }
    return -1;
}
int main(){
    int n, m, a, b, c;
    while(~scanf("%d%d", &n, &m)){
        init();
        for(int i=1;i<=n;i++){
            scanf("%d", &loc[i]);
        }
        for(int i=0;i<m;i++){
            scanf("%d%d", &a, &b);
            c = (loc[b] - loc[a] + 360) % 360;
            if(c < 180){
                addedge(a, b, c);
                addedge(b, a, -c);
            }
            else{
                c = 360 - c;
                addedge(b, a, c);
                addedge(a, b, -c);
            }
        }
        for(int i=1;i<=n;i++) st[i].clear();
        printf("%d\n", bfs());
    }
    return 0;
}
