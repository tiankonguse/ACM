#include <cstdio>
#include <cstring>
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
const int N = 105;
int dfn[N], low[N], id[N], num, st[N], top, in[N], tot, start;
vector <int> E[N];

void tarjan(int now) {
	in[st[top++] = now] = true;
	dfn[now] = low[now] = ++tot;
	int i;
	for (int ii = E[now].size() - 1; ii >= 0; --ii) {
		i = E[now][ii];
		if (!dfn[i]) {
			tarjan(i);
			low[now] = min(low[now], low[i]);
		} else if (in[i]) {
			low[now] = min(low[now], dfn[i]);
		}
	}
	if (dfn[now] == low[now]) {
		int cnt = 0;
		do {
			i = st[--top];
			in[i] = false;
			id[i] = num;
			++cnt;
		} while (i != now);
		if (cnt > 1) start = now;
		++num;
	}
}

void SCC(int n) {
	fill_n(dfn, n, 0);
	fill_n(low, n, 0);
	fill_n(in, n, 0);
	fill_n(id, n, -1);
	for (int i = top = num = tot = 0; i < n; ++i)
		if (!dfn[i])
			tarjan(i);
}

int n, m;
int mat[105][105];
int vis[105];
vector <int> path;

void dfs(int u) {
	vis[u] = 1;
	path.push_back(u);
	rep (v, n) if (mat[u][v] != -1) {
		if (!vis[v]) {
			dfs(v);
		} else if (v == start) {
			throw 1;
		}
	}
	path.pop_back();
}

int main() {
	freopen("electricity.in", "r", stdin);
	freopen("electricity.out", "w", stdout);
	memset(mat, 0xff, sizeof(mat));
	scanf("%d%d", &n, &m);
	for (int i = 0, u, v; i < m; i++) {
		scanf("%d%d", &u, &v);
		u--; v--;
		mat[u][v] = i;
	}
	vector <int> ans;
	while (1) {
		rep (i, n) E[i].clear();
		rep (i, n) rep (j, n) if (mat[i][j] != -1) {
			E[i].push_back(j);
		}
		SCC(n);
		if (num == n) break;
		path.clear();
		fill_n(vis, n, 0);
		try {
			dfs(start);
		} catch (...) {
			assert(path.size() >= 2);
			int u = path[0];
			int v = path[1];
			ans.push_back(mat[u][v]);
			mat[u][v] = -1;
		}
	}
	cout << ans.size() << "\n";
	rep (i, ans.size()) {
		cout << ans[i] + 1 << "\n";
	}				
}
