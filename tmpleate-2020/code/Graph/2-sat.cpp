#include <vector>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
const int N = 8005;
int low[N], dfn[N], id[N], stack[N], inS[N];
int stop, ts, idn;
vector <int> E[N];

void dfs(int u) {
	stack[stop++] = u;
	dfn[u] = ts++;
	low[u] = dfn[u];
	inS[u] = 1;
	rep (i, E[u].size()) {
		int v = E[u][i];
		if (dfn[v] == -1) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		} else if (inS[v]) {
			low[u] = min(low[u], dfn[v]);
		}
	}
	if (low[u] == dfn[u]) {
		while (stack[--stop] != u) {
			id[stack[stop]] = idn;
			inS[stack[stop]] = 0;
		}
		id[u] = idn++;
		inS[u] = 0;
	}
}

//传入强连通的点数
void SCC(int n) {
	idn = ts = stop = 0;
	rep (i, n) dfn[i] = -1, inS[i] = 0;
	rep (i, n)
		if (dfn[i] == -1) 
			dfs(i);
}

//传入2-sat本质拥有的点数(是强连通的一半)，i * 2和i * 2 + 1号点分别为2-sat里的一组点，返回长度为n的vector，res[i]表示是否取第i组里的i * 2号点
bool twosat(int n, vector <bool> &res) {
	rep (i, n) if (id[i * 2] == id[i * 2 + 1]) return 0;
	static int c[N];
	static vector <int> block[N];
	rep (i, idn) block[i].clear(), c[i] = -1;
	rep (i, n + n) block[id[i]].push_back(i);
	rep (i, idn) {
		c[i] = 1;
		rep (j, block[i].size()) {
			int u = block[i][j];
			rep (k, E[u].size())
				if (c[id[E[u][k]]] == 0) c[i] = 0;
			if (c[id[u ^ 1]] == 1) c[i] = 0;
		}
	}
	res.resize(n);
	rep (i, n) res[i] = c[id[i * 2]];
	return 1;
}
