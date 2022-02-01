#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <ctime>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
using namespace std;
int const maxn = 2000;
int const maxm = 1001000;
double const eps = 1e-8;
struct edges{
  int u,c,next;
}e[maxm];
int p[maxn],idx;
int n, m;

void addedge(int u,int v,int c,int cc=0){
	//printf("add(%d, %d, %d)\n",u,v,c);
	e[idx].u=v; e[idx].c=c;  e[idx].next=p[u]; p[u]=idx++;
	e[idx].u=u; e[idx].c=cc; e[idx].next=p[v]; p[v]=idx++;

}
void init(){ idx=0; memset(p,0xff,sizeof(p));}

int gap[maxn],dis[maxn],pre[maxn],cur[maxn];

int sap(int s,int t){
	memset(dis,0,sizeof(dis));
	memset(gap,0,sizeof(gap));
	for(int i=1;i<=n;i++)cur[i]=p[i];
	int u=pre[s]=s, max_flow=0,step=inf;
	gap[0]=n;
	while(dis[s]<n){
loop:   for(int &i=cur[u];i!=-1;i=e[i].next){
			int v=e[i].u;
			if(e[i].c>0 && dis[u]==dis[v]+1){
				step=min(step,e[i].c);
				pre[v]=u;
				u=v;
				if(v==t){
					max_flow += step;
					for(u=pre[u];v!=s;v=u,u=pre[u]){
						e[cur[u]].c -= step;
						e[cur[u]^1].c += step;
					}
					step=inf;
				}
				goto loop;
			}
		}
		int mindis=n;
		for(int i=p[u];i!=-1;i=e[i].next){
			int v=e[i].u;
			if(e[i].c>0 && mindis>dis[v]){
				cur[u]=i;
				mindis=dis[v];
			}
		}
		if( (--gap[dis[u]])==0) break;
		gap[ dis[u] = mindis+1] ++;
		u=pre[u];
	}
	return max_flow;
}

struct nodeo {
	double x, y;
	int b, p;
	int need[6];
} o[maxn];
inline int dist(int a, int b) {
	return (int)(ceil(sqrt((o[a].x - o[b].x) * (o[a].x - o[b].x) + (o[a].y - o[b].y) * (o[a].y - o[b].y)) - eps));
}
bool ok[200][200];
int main() {
	int T;
	int _n, _m; 
	for (scanf("%d", &T); T--; ) {
		scanf("%d%d", &_n, &_m);
		scanf("%lf %lf", &o[0].x, &o[0].y); o[0].b = o[0].p = 0;
		int sum = 0;
		for (int i = 1; i < _n; ++i) {
			scanf("%lf %lf %d %d", &o[i].x, &o[i].y, &o[i].b, &o[i].p);
			for (int j = 0; j < _m; ++j) {
				scanf("%d", &o[i].need[j]);
				sum += o[i].need[j];
			}
		}
		memset(ok, 0, sizeof ok);
		for (int i = 0; i < _n; ++i) {
			for (int j = 0; j < _n; ++j) {
				if (i == j) continue;
				ok[i][j] = o[i].b + o[i].p + dist(i, j) <= o[j].b; 
			}
		}
		n = _n * _m * 2 + 2;
		int add = _n * _m;
		int S = n - 1, T = n;
		init();
		for (int i = 1; i < _n; ++i) {
			for (int j = 0; j < _m; ++j) {
				if (ok[0][i]) addedge(S, i * _m + j + 1, o[i].need[j]);
				addedge(i * _m + j + 1 + add, T, o[i].need[j]);
			}
		}
		for (int i = 1; i < _n; ++i) {
			for (int j = 1; j < _n; ++j) {
				if (!ok[i][j]) continue;
				for (int k = 0; k < _m; ++k) {
					addedge(i * _m + k + 1, j * _m + k + 1 + add, o[j].need[k]);
				}
			}
		}
		int ret = sap(S, T);
		printf("%d\n", sum - ret);
	}
	return 0;
}

