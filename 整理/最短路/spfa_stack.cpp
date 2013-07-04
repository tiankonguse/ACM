/*************************************************************************
    > File Name: spfa_stack.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/7 17:33:33
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
const int V = 30001;
const int E = 150001;
int pnt[E], cost[E], nxt[E];
stack<int>sta;
int e, head[V]; int dist[V]; bool vis[V];
void init(){
	e = 0;memset(head, -1, sizeof(head));
}
void addedge(int u, int v, int c){
	pnt[e] = v; cost[e] = c; nxt[e] = head[u]; head[u] = e++;
}
int SPFA(int src, int n){
	int i,u,v;
	for( i=1; i <= n; ++i ){
		vis[i] = 1; dist[i] = INF;
	}
	while(!sta.empty())sta.pop();

	dist[src] = 0;
	sta.push(src);vis[src] = 0;

	while(!sta.empty()){
		u=sta.top();sta.pop();vis[u] = 1;
		for( i=head[u]; i != -1; i=nxt[i] ){
			v = pnt[i];
			if(dist[v] > dist[u] + cost[i]){
				dist[v] = dist[u] + cost[i];
				if(vis[v]){
					sta.push(v);vis[v] = 0;
				}
			}
		}
	}
	return dist[n];
}
int main() {

    return 0;
}
