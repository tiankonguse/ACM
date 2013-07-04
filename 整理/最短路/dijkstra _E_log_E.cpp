/*************************************************************************
    > File Name: dijkstra.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/5 9:54:20
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;

typedef int typec;
const int V = 100;
const int E = 10000;
const typec inf = 0x3f3f3f3f; // max of cost
typec cost[E], dist[V];
int e, pnt[E], nxt[E], head[V], prev[V], vis[V];

struct qnode {
    int v;
    typec c;
    qnode (int vv = 0, typec cc = 0) : v(vv), c(cc) {}
    bool operator < (const qnode& r) const {
        return c>r.c;
    }
};

void dijkstra(int n, const int src) {
    qnode mv;
    int i, j, k, pre;
    priority_queue<qnode> que;
    vis[src] = 1;
    dist[src] = 0;
    que.push(qnode(src, 0));

    for (pre = src, i=1; i<n; i++) {
        for (j = head[pre]; j != -1; j = nxt[j]) {
            k = pnt[j];
            if (vis[k] == 0 && dist[pre] + cost[j] < dist[k]) {
                dist[k] = dist[pre] + cost[j];
                que.push(qnode(pnt[j], dist[k]));
                prev[k] = pre;
            }
        }

        while (!que.empty() && vis[que.top().v] == 1){
            que.pop();
        }

        if (que.empty()) break;
        mv = que.top();
        que.pop();
        vis[pre = mv.v] = 1;
    }
}

inline void addedge(int u, int v, typec c) {
    pnt[e] = v;
    cost[e] = c;
    nxt[e] = head[u];
    head[u] = e++;
}

void init(int nv, int ne) {
    int i, u, v;
    typec c;
    e = 0;
    memset(head, -1, sizeof(head));
    memset(vis, 0, sizeof(vis));
    memset(prev, -1, sizeof(prev));
    for (i = 0; i < nv; i++) dist[i] = inf;
    for (i = 0; i < ne; ++i) {
        scanf("%d%d%d", &u, &v, &c);
        addedge(u, v, c);
        addedge(v, u, c);
    }
}

int main() {

    return 0;
}
