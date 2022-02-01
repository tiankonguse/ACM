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
int const maxn(1111);
int const maxm(111111);
typedef long long ll;
map <string, int> mp; int idx;
string dat[maxn];

inline int getID(string s) { 
  if (mp.find(s) == mp.end()) {
		dat[idx] = s;
		mp[s] = idx++; 
	}
	return mp[s]; 
}
struct edges{ int u, next; } e[maxm];
int p[maxn], eidx;
void addedge(int u, int v) {
	e[eidx].u = v, e[eidx].next = p[u], p[u] = eidx++;
}
void init() { eidx = 0; memset(p, 0xff, sizeof p); }
int n, d;
bool mark[maxn];
int dp[maxn][maxn];
string str;

void dfs(int u, int pre) {
	if (mark[u]) return;
	mark[u] = true;
	int v;
	for (int i = p[u]; ~i; i = e[i].next) {
		v = e[i].u;
		if (v != pre) {
			dfs(v, u);
			dp[u][1]++;
			for (int j = 2; j <= d; ++j) dp[u][j] += dp[v][j - 1];
		}
	}
}
struct node {
	string s; int v;
	friend bool operator < (node a, node b) {
		if (a.v == b.v) return a.s < b.s;
		else return a.v > b.v;
	}
} ans[maxn];

int main() {
	int T, ca = 1;
	
	for (cin >> T; T--; ) {
		mp.clear(); idx = 1;
		scanf("%d%d", &n, &d);
		init();
		int id0, id1, h;
		for (int i = 0; i < n; ++i) {
			cin >> str; id0 = getID(str);
			for (cin >> h; h--; ) {
				cin >> str; id1 = getID(str);
				addedge(id0, id1);
			}
		}
		memset(dp, 0, sizeof dp);
		memset(mark, 0, sizeof mark);
		for (int i = 1; i < idx; ++i) {
			dfs(i, -1);
		}
		int ant = 0;
		for (int i = 1; i < idx; ++i) {
			if (dp[i][d] > 0) {
				ans[ant].s = dat[i];
				ans[ant++].v = dp[i][d];
			}
		}
		sort(ans, ans + ant);
		cout << "Tree " << ca++ << ":\n";
		for (int i = 0; i < min(ant, 3); ++i) {
			cout << ans[i].s << " " << ans[i].v << '\n';
		}
		for (int i = 3; i < ant; ++i) {
			if (ans[i].v != ans[i - 1].v) break;
			cout << ans[i].s << " " << ans[i].v << '\n';
		}
		cout << '\n';
	}
    return 0;
}
