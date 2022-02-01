// POJ 3159 Candies
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
const int INF = 0x3F3F3F3F;
const int V = 30001;
const int E = 150001;
int pnt[E], cost[E], nxt[E];
int e, head[V]; int dist[V]; bool vis[V];
int relax(int u, int v, int c){
	if( dist[v] > dist[u] + c ) {
		dist[v] = dist[u] + c; return 1;
	}
	return 0;
}
inline void addedge(int u, int v, int c){
	pnt[e] = v; cost[e] = c; nxt[e] = head[u]; head[u] = e++;
}
int SPFA(int src, int n)
{ // ´Ë´¦ÓÃ¶ÑÕ»ÊµÏÖ£¬ÓÐÐ©Ê±ºò±È¶ÓÁÐÒª¿ì
	int i;
	for( i=1; i <= n; ++i ){ // ¶¥µã1...n
		vis[i] = 0; dist[i] = INF;
	}
	dist[src] = 0;
	int Q[E], top = 1;
	Q[0] = src; vis[src] = true;
	while( top ){
	int u, v;
	u = Q[--top]; vis[u] = false;
	for( i=head[u]; i != -1; i=nxt[i] ){
		v = pnt[i];
		if( 1 == relax(u, v, cost[i]) && !vis[v] ) {
			Q[top++] = v; vis[v] = true;
		}
	}
}
return dist[n];
}
int main(){
	int n, m;
	while( scanf("%d%d", &n, &m) != EOF ){
		int i, a, b, c;
		e = 0;
		memset(head, -1, sizeof(head));
		for( i=0; i < m; ++i )
		{// b-a <= c, ÓÐÏò±ß(a, b):c £¬±ßµÄ·½Ïò£¡£¡£¡
			scanf("%d%d%d", &a, &b, &c);
			addedge(a, b, c);
		}
		printf("%d\n", SPFA(1, n));
	}
return 0;
}
