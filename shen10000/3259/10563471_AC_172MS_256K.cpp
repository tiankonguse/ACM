#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
using namespace std;
const int INF = 0x3F3F3F3F;
const int V = 501;
const int E = 6001;
int pnt[E], cost[E], nxt[E];
int e, head[V], dist[V];
bool vis[V];
int cnt[V]; // 入队列次数
queue<int> que;

void init(){e = 0;memset(head, -1, sizeof(head));}

inline void addedge(int u, int v, int c){
	pnt[e] = v; cost[e] = c; nxt[e] = head[u]; head[u] = e++;
}

bool SPFA(int src, int n){
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
					if((++cnt[v])>n)return true;//出现负权回路 
				}
			}
		}
	}
return false;
}
int main()
{
	int f,n,m,w,s,e,t;
	scanf("%d",&f);
	while(f--){
		
		scanf("%d%d%d",&n,&m,&w);
		init();
		while(m--){
			scanf("%d%d%d",&s,&e,&t);
			addedge(s,e,t);
			addedge(e,s,t);
		}
		while(w--){
			scanf("%d%d%d",&s,&e,&t);
			addedge(s,e,-t);
		}
		if(SPFA(1,n)){
			puts("YES");
		}else{
			puts("NO");
		}
	}
	return 0;
}
