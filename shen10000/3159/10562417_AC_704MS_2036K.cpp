#include<stdio.h>
#include<stack>
#include<string.h> 
using namespace std;
// POJ 3159 Candies
const int INF = 0x3F3F3F3F;
const int V = 30001;
const int E = 150001;
int pnt[E], cost[E], nxt[E];
stack<int>sta;
int e, head[V]; int dist[V]; bool vis[V];

void init(){
	e = 0;
	memset(head, -1, sizeof(head));	
}
void addedge(int u, int v, int c){
	pnt[e] = v; cost[e] = c; nxt[e] = head[u]; head[u] = e++;
}

int SPFA(int src, int n){
	int i;
	for( i=1; i <= n; ++i ){ 
		vis[i] = 1; dist[i] = INF;
	}
	while(!sta.empty())sta.pop();

	dist[src] = 0;
	
	vis[src] = 0;
	sta.push(src);
	
	while(!sta.empty()){
		int u, v;
		u=sta.top();sta.pop();
		vis[u] = 1;
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

int main(){
	int n, m;
	while( scanf("%d%d", &n, &m) != EOF ){
		int a, b, c;
		init();
		for(int  i=0; i < m; ++i ){
			scanf("%d%d%d", &a, &b, &c);
			addedge(a, b, c);
		}
		printf("%d\n", SPFA(1, n));
	}
return 0;
}
