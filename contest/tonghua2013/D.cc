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
int const maxn = 10100;
int const maxm = 100100;
typedef long long ll;
int parents[maxn];
int Find(int a){
    return parents[a] < 0 ? a : parents[a] = Find(parents[a]);
}
void Union(int a,int b){
    if(parents[a] < parents[b]){ parents[a] += parents[b], parents[b] = a;}
    else{ parents[b] += parents[a], parents[a] = b;}
}
void init(){ memset(parents, 0xff, sizeof(parents)); }

int u[maxm], v[maxm], ans[maxm];
int main() {
  int n, m, ra, rb;
	while (~scanf("%d%d", &n, &m)) {
		for (int i = 1; i <= m; ++i) scanf("%d%d", &u[i], &v[i]);
		init();
		int now = n;
		for (int i = m; i >= 1; --i) {
			ans[i] = now;
			ra = Find(u[i]), rb = Find(v[i]);
			if (ra != rb) {
				--now;
				Union(ra, rb);
			}
		}
		for (int i = 1; i <= m; ++i) {
			printf("%d\n", ans[i]);
		}
	}	
	return 0;
}

