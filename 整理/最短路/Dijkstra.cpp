#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
using namespace std;
const int  E=10000;//边的个数 
const int  V=10000;//定点的个数 
#define typec int // type of cost
const typec inf = 0x3f3f3f3f; // max of cost
typec cost[E], dist[V];
int e, pnt[E], nxt[E], head[V], prev[V], vis[V];
struct qnode {
	int v;typec c;
	qnode(int vv = 0, typec cc = 0) :
			v(vv), c(cc) {
	}
	bool operator <(const qnode& r) const {
		return c > r.c;
	}
};
void dijkstra(int n, const int src) {
	qnode mv;
	int i, j, k, pre;
	priority_queue<qnode> que;
	vis[src] = 1;
	dist[src] = 0;
	que.push(qnode(src, 0));
	for (pre = src, i = 1; i < n; i++) {
		for (j = head[pre]; j != -1; j = nxt[j]) {
			k = pnt[j];
			if (vis[k] == 0 && dist[pre] + cost[j] < dist[k]) {
				dist[k] = dist[pre] + cost[j];
				que.push(qnode(pnt[j], dist[k]));
				prev[k] = pre;
			}
		}
		while (!que.empty() && vis[que.top().v] == 1)
			que.pop();
		if (que.empty())
			break;
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
	for (i = 0; i < nv; i++)
		dist[i] = inf;
	for (i = 0; i < ne; ++i) {
		scanf("%d%d%d", &u, &v, &c); // %d: type of cost
		addedge(u, v, c); // vertex: 0 ~ n-1, 单向边
	}
}
int main()
{
	return 0;
}
