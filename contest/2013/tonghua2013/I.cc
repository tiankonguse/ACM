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
typedef long long ll;
int const maxn = 305;
int const maxm = 100100;
struct edges{ int u, next; } e[maxm];
int p[maxn], idx;
void addedge(int u, int v) {
  e[idx].u = v, e[idx].next = p[u], p[u] = idx++;
}
int parents[maxn];
int Find(int a){
    return parents[a] < 0 ? a : parents[a] = Find(parents[a]);
}
void Union(int a,int b){
    if(parents[a] < parents[b]){ parents[a] += parents[b], parents[b] = a;}
    else{ parents[b] += parents[a], parents[a] = b;}
}

void init() { idx = 0; memset(p, 0xff, sizeof p); memset(parents, 0xff, sizeof(parents)); }

int n; char buf[maxn];
set <int> s;
int mark[maxn];
bool dfs(int u, int c) {
	mark[u] = c;
	int v;
	for (int i = p[u]; ~i; i = e[i].next) {
		v = e[i].u;
		if (mark[v] == c) return false;
		if (mark[v] != -1) continue;
		if (!dfs(v, c ^ 1)) return false;
	}
	return true;
}
int main() {
	int T;
	for (scanf("%d", &T); T--; ) {
		scanf("%d", &n);
		init();
		for (int i = 0; i < n; ++i) {
			scanf(" %s", buf);
			for (int j = 0; j < n; ++j) {
				if (buf[j] == '1') {
					addedge(i, j);
					int ra = Find(i), rb = Find(j);
					if (ra != rb) Union(ra, rb);
				}
			}
		}
		s.clear();
		memset(mark, 0xff, sizeof mark);
		int beg = -1;
		for (int i = 0; i < n; ++i) {
			if (parents[i] < -1) {
				beg = i;
				s.insert(i);
			}
		}
		if (s.size() >= 2) {
			puts("No");
			continue;
		}
		bool ret = dfs(beg, 0);
		if (ret) puts("Yes");
		else puts("No");
	}	
	return 0;
}

