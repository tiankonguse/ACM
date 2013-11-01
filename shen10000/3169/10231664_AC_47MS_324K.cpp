// ¶ÓÁÐÊµÏÖ£¬¶øÇÒÓÐ¸ºÈ¨»ØÂ·ÅÐ¶Ï¡ªPOJ 3169 Layout
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<queue>
using namespace std;
#define swap(t, a, b) (t=a, a=b, b=t)
const int INF = 0x3F3F3F3F;
const int V = 1001;
const int E = 20001;
int pnt[E], cost[E], nxt[E];
int e, head[V], dist[V];
bool vis[V];
int cnt[V]; // Èë¶ÓÁÐ´ÎÊý
int relax(int u, int v, int c){
if( dist[v] > dist[u] + c ) {
dist[v] = dist[u] + c; return 1;
}
return 0;
}
inline void addedge(int u, int v, int c){
pnt[e] = v; cost[e] = c; nxt[e] = head[u]; head[u] = e++;
}
int SPFA(int src, int n){// ´Ë´¦ÓÃ¶ÓÁÐÊµÏÖ
	int i;
	memset(cnt, 0, sizeof(cnt)); // Èë¶Ó´ÎÊý
	memset(vis, false, sizeof(vis));
	for( i=1; i <= n; ++i ) dist[i] = INF;
	dist[src] = 0;
	queue<int> Q;
	Q.push(src); vis[src] = true; ++cnt[src];
	while( !Q.empty() ){
		int u, v;
		u = Q.front(); Q.pop(); vis[u] = false;
		for( i=head[u]; i != -1; i=nxt[i] ){
			v = pnt[i];
			if( 1 == relax(u, v, cost[i]) && !vis[v] ) {
				Q.push(v); vis[v] = true;
				if( (++cnt[v]) > n ) return -1; // cnt[i]ÎªÈë¶ÓÁÐ´ÎÊý£¬ÓÃÀ´ÅÐ¶ÏÊÇ·ñ´æÔÚ¸ºÈ¨»ØÂ·
			}
		}
	}
	if( dist[n] == INF ) return -2; // srcÓën²»¿É´ï£¬ÓÐÐ©ÌâÄ¿¿ÉÊ¡£¡£¡£¡
	return dist[n]; // ·µ»Øsrcµ½nµÄ×î¶Ì¾àÀë£¬¸ù¾ÝÌâÒâ²»Í¬¶ø¸Ä±ä
}

int main(){
	int n, ml, md;
	while( scanf("%d%d%d", &n, &ml, &md) != EOF ){
		int i, a, b, c, t;
		e = 0;
		memset(head, -1, sizeof(head));
		for( i=0; i < ml; ++i ) // ±ß·½Ïò£¡£¡£¡
		{// ´ó-Ð¡<=c, ÓÐÏò±ß(Ð¡, ´ó):c
			scanf("%d%d%d", &a, &b, &c);
			if( a > b) swap(t, a, b);
			addedge(a, b, c);
		}
		for( i=0; i < md; ++i )
		{// ´ó-Ð¡>=c ==> Ð¡-´ó<=-c, ÓÐÏò±ß(´ó, Ð¡):-c
			scanf("%d%d%d", &a, &b, &c);
			if( a < b ) swap(t, a, b);
			addedge(a, b, -c);
		}
		//for( i=1; i <= n; ++i ) printf("%d\n", dist[i]);
		printf("%d\n", SPFA(1, n));
	}
	return 0;
}
