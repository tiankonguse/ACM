/*************************************************************************
    > File Name: spfa_queue.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/7 17:34:16
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
const int INF = 0x3F3F3F3F;
const int V = 1001;
const int E = 20001;
int pnt[E], cost[E], nxt[E];
int e, head[V], dist[V];
bool vis[V];
int cnt[V]; // 入队列次数
queue<int> que;

void init(){e = 0;memset(head, -1, sizeof(head));}

inline void addedge(int u, int v, int c){
pnt[e] = v; cost[e] = c; nxt[e] = head[u]; head[u] = e++;
}

int SPFA(int src, int n){
	int i,u,v;
for( i=1; i <= n; ++i ) {dist[i] = INF;cnt[i]=0;vis[i]=1;}

	while(!que.empty())que.pop();
	que.push(src);vis[src] =0; dist[src] = 0;++cnt[src];
	while( !que.empty() ){
		u = que.front();que.pop(); vis[u] =1;
		for( i=head[u]; i != -1; i=nxt[i] ){
			v = pnt[i];
			if(dist[v] > dist[u] + cost[i] ){
				dist[v] = dist[u] + cost[i];
		if(vis[v]){
			que.push(v);vis[v]=0;
			if((++cnt[v])>n)return -1;//出现负权回路
		}
			}
		}
	}
	if( dist[n] == INF ) return -2; // src与n不可达
	return dist[n]; // 返回src到n的最短距离
}
int main() {

    return 0;
}
