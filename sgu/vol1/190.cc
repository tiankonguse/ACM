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
#include <ctime>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
using namespace std;
typedef long long ll;
int const maxn = 2000;
int const maxm = 20000;
struct edges {
  int u, d, next;
} e[maxm];
int p[maxn], idx;
void addedge(int u, int v, int d) {
	e[idx].u = v;
	e[idx].d = d;
	e[idx].next = p[u];
	p[u] = idx++;
}
void init() {
	idx = 0; memset(p, 0xff, sizeof p);
}
int matx[maxn],maty[maxn],dirx[maxn];
bool fy[maxn];
int N;

int path(int u){
   int v;
   for (int i = p[u]; ~i; i = e[i].next) {
	  v = e[i].u;
      if(!fy[v]){
         fy[v]=1;
         if(maty[v]<0 || path(maty[v])){
            matx[u]=v;
			dirx[u]=e[i].d;
            maty[v]=u;
            return 1;
         }
      }
   }
   return 0;
}
int hungary(){
   int res=0;
   memset(matx,0xff,sizeof(matx));
   memset(maty,0xff,sizeof(maty));
   for(int i=1;i<=N;i++){
       if(matx[i]<0){
           memset(fy,false,sizeof(fy));
           res+=path(i);
       }
   }
   return res;
}

bool mp[42][42];
int id[42][42], cnt;
int cor[maxn][2];
bool even[maxn];

int h[maxn], hnt;
int v[maxn], vnt;
int main() {
	int n, p;
	int x, y;
	while (~scanf("%d%d", &n, &p)) {
		memset(mp, 0, sizeof mp);
		for (int i = 0; i < p; ++i) {
			scanf("%d%d", &y, &x);
			mp[x][y] = true;
		}
		memset(even, 0, sizeof even);
		cnt = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (!mp[i][j]) {
					id[i][j] = ++cnt;
					if ((i + j) % 2 == 0) even[cnt] = true;
					cor[cnt][0] = i;
					cor[cnt][1] = j;
				}
			}
		}
		N = cnt;
		init();
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if ((i + j) & 1) continue;
				if (!mp[i][j]) {
					if (j + 1 <= n && !mp[i][j + 1]) {
						addedge(id[i][j], id[i][j + 1], 0);
					}
					if (j - 1 >= 1 && !mp[i][j - 1]) {
						addedge(id[i][j], id[i][j - 1], 1);
					}
					if (i + 1 <= n && !mp[i + 1][j]) {
						addedge(id[i][j], id[i + 1][j], 2);
					}
					if (i - 1 >= 1 && !mp[i - 1][j]) {
						addedge(id[i][j], id[i - 1][j], 3);
					}
				}
			}
		}
		int ret = hungary();
		if (ret * 2 == N) {
			puts("Yes");
			hnt = vnt = 0;
			for (int i = 1; i <= N; ++i) {
				if (!even[i]) continue;
				if (dirx[i] == 0) h[hnt++] = i;
				else if (dirx[i] == 1) h[hnt++] = matx[i];
				else if (dirx[i] == 2) v[vnt++] = i;
				else if (dirx[i] == 3) v[vnt++] = matx[i];
			}
			printf("%d\n", hnt);
			for (int i = 0; i < hnt; ++i) {
				printf("%d %d\n", cor[h[i]][1], cor[h[i]][0]);
			}
			printf("%d\n", vnt);
			for (int i = 0; i < vnt; ++i) {
				printf("%d %d\n", cor[v[i]][1], cor[v[i]][0]);
			}
		}
		else puts("No");
		
		
	}
    return 0;
}
