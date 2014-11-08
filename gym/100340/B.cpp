#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cassert>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define foreach(it,v) for (__typeof((v).end()) it = (v).begin(); it != (v).end(); it++)
using namespace std;
typedef vector <int> VI;
const int N = 20005;
int n, m, times;
int dfn[N], low[N];
set <int> E[N];
set <int> treeEdge[N];
set <int> ori[N];
vector < VI > ans;

void addTreeEdge(int u, int v) {
	treeEdge[u].insert(v);
	treeEdge[v].insert(u);
}

void removeTreeEdge(int u, int v) {
	treeEdge[u].erase(v);
	treeEdge[v].erase(u);
}

VI join(const VI &a, const VI &b) {
	VI res(a.size() + b.size());
	rep (i, a.size()) res[i] = a[i];
	rep (i, b.size()) res[i + a.size()] = b[i];
	return res;
}

bool dfs(int u) {
	dfn[u] = ++times;
	low[u] = times;
	foreach (it, E[u]) {
		if (dfn[*it]) {
			if (!treeEdge[u].count(*it) && dfn[*it] < low[u]) {
				low[u] = dfn[*it];
			}
		} else {
			addTreeEdge(u, *it);
			if (!dfs(*it)) return 0;
			if (low[*it] <= low[u]) {
				low[u] = low[*it];
			}
		}
	}
	if (low[u] >= times) return 0;
	for (set <int>::iterator it = E[u].begin(); it != E[u].end(); ) {
		if (treeEdge[u].count(*it) || low[u] != dfn[*it]) {
			int v = *it++;
			E[u].erase(v);
		} else {
			it++;
		}
	}
	return 1;
}

set <int> Q;

vector <int> go(int u) {
	vector <int> path(1, u);
	while (1) {
		int w = *treeEdge[u].begin();
		removeTreeEdge(u, w);
		path.push_back(w);
		if (treeEdge[w].size() == 1 && E[w].size() == 0) {
			u = w;
		} else {
			if (treeEdge[w].size() == 1 && E[w].size() == 1)
				Q.insert(w);
			break;
		}
	}
	return path;
}

void topsort() {
	rep (i, n) foreach (it, E[i]) E[*it].insert(i);
/*
	rep (i, n) foreach(it, E[i]) if (i < *it) {
		printf("%d %d\n", i + 1, *it + 1);
	}
	puts("----");
	rep (i, n) foreach(it, treeEdge[i]) if (i < *it) {
		printf("%d %d\n", i + 1, *it + 1);
	}
*/
	rep (i, n) foreach (it, ori[i])
		if (i < *it && !E[i].count(*it) && !treeEdge[i].count(*it)) {
			VI path;
			path.push_back(i);
			path.push_back(*it);
			ans.push_back(path);
		}
	rep (i, n) if (treeEdge[i].size() == 1 && E[i].size() == 1)
		Q.insert(i);
	while (!Q.empty()) {
		//printf("st %d\n", *Q.begin() + 1);
		int u = *Q.begin();
		Q.erase(Q.begin());
		if (E[u].size() != 1 || treeEdge[u].size() != 1) continue;
		int v = *E[u].begin();
		if (treeEdge[v].size() == 1 && E[v].size() == 1) {
			E[u].erase(v);
			E[v].erase(u);
			VI path;
			path = go(u);
			if (find(path.begin(), path.end(), v) == path.end()) {
				reverse(path.begin(), path.end());
				ans.push_back(join(path, go(v)));
			} else {
				path.push_back(u);
				ans.push_back(path);
			}
		} else {
			E[u].erase(v);
			E[v].erase(u);
			if (treeEdge[v].size() == 1 && E[v].size() == 1) {
				Q.insert(v);
			}
			VI path;
			path.push_back(v);
			path.push_back(u);
			while (1) {
				int w = *treeEdge[u].begin();
				removeTreeEdge(u, w);
				path.push_back(w);
				if (treeEdge[w].size() == 1 && E[w].size() == 0) {
					u = w;
				} else {
					if (treeEdge[w].size() == 1 && E[w].size() == 1)
						Q.insert(w);
					break;
				}
			}
			ans.push_back(path);
		}
	}
}

int main() {
	freopen("ear.in", "r", stdin);
	freopen("ear.out", "w", stdout);
	scanf("%d%d", &n, &m);
	if (n == 2) {
		puts("-1");
		return 0;
	}
	rep (i, m) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--; v--;
		E[u].insert(v);
		E[v].insert(u);
	}
	rep (i, n) ori[i] = E[i];
	times = 0;
	if (!dfs(0)) {
		puts("-1");
	} else {
		topsort();
		printf("%d\n", (int)ans.size());
		rep (i, ans.size()) {
			printf("%d", (int)ans[i].size() - 1);
			rep (j, ans[i].size()) {
				printf(" %d", ans[i][j] + 1);
			}
			puts("");
		}
	}
	return 0;
}
