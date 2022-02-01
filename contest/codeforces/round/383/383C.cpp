#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define foreach(it,v) for (__typeof((v).end()) it = (v).begin(); it != (v).end(); it++)
typedef long long ll;
typedef pair <int, int> PII;
const int N = 200005 * 5;
int n, m, cnt;
int a[N];
int st[N], ed[N], depth[N];
int order[N];
vector <int> E[N];

struct Node {
	int l, r;
	int del[2];
}Tr[N];

void dfs(int u, int fa) {
	order[cnt] = u;
	st[u] = cnt++;
	rep (i, E[u].size()) {
		int v = E[u][i];
		if (v == fa) continue;
		depth[v] = depth[u] ^ 1;
		dfs(v, u);
	}
	ed[u] = cnt - 1;
}

void build(int p, int l, int r) {
	Tr[p].l = l; Tr[p].r = r;
	Tr[p].del[0] = Tr[p].del[1] = 0;
	if (l < r) {
		int mid = (l + r) / 2;
		build(p * 2, l, mid);
		build(p * 2 + 1, mid + 1, r);
	}
}

void add(int p, int l, int r, int o, int d) {
	if (l <= Tr[p].l && Tr[p].r <= r) {
		Tr[p].del[o] += d;
	} else {
		int mid = (Tr[p].l + Tr[p].r) / 2;
		if (l <= mid) add(p * 2, l, r, o, d);
		if (r >  mid) add(p * 2 + 1, l, r, o, d);
	}
}

int get(int p, int idx, int o) {
	if (Tr[p].l == Tr[p].r) return Tr[p].del[o];
	int mid = (Tr[p].l + Tr[p].r) / 2;
	if (idx <= mid) {
		return Tr[p].del[o] + get(p * 2, idx, o);
	} else {
		return Tr[p].del[o] + get(p * 2 + 1, idx, o);
	}
}

int main() {
	scanf("%d%d", &n, &m);
	rep (i, n) {
		scanf("%d", &a[i]);
	}
	rep (i, n - 1) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--; v--;
		E[u].push_back(v);
		E[v].push_back(u);
	}
	cnt = 0;
	depth[0] = 0;
	dfs(0, -1);
	build(1, 0, cnt - 1);
	rep (_, m) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int x, val;
			scanf("%d%d", &x, &val);
			x--;
			add(1, st[x], ed[x], depth[x], val);
			add(1, st[x], ed[x], depth[x] ^ 1, -val);
		} else {
			int x;
			scanf("%d", &x);
			x--;
			int res = get(1, st[x], depth[x]);
			printf("%d\n", res + a[x]);
		}
	}
}
