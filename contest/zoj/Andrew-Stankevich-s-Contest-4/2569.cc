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
int const maxn = 100;
int m, n, t, l;
inline int __div(int x, int y) { return (x + y - 1) / y; }
struct Prob {
  int I, A, L, O;
} pp[maxn];
struct Team {
	int T, Z, V, C;
} pt[maxn];
struct res {
	int d, p, id;

} rt[maxn];

inline bool __less(int u, int v) {
	if (rt[u].d == rt[v].d) return rt[u].p > rt[v].p;
	else return rt[u].d < rt[v].d;
}

struct SolveList {
	int e, r;
	SolveList(int e, int r) : e(e), r(r) { }
	SolveList() { }
	friend bool operator < (SolveList a, SolveList b) {
		if (a.e == b.e) return a.r < b.r;
		else return a.e < b.e;
	}
} s[maxn];


void cal(int mask, int id) {
	int snt = 0, e, r;
	for (int i = 0; i < m; ++i) {
		if ((mask >> i) & 1) {
			if (pt[id].T + pt[id].C > pp[i].I - pp[i].O) { // Tj + Cj exceeds Ii - Oi
				e = __div(pp[i].I, pp[i].O) + max(__div(pp[i].A, pt[id].C), 5);
				r = max(pp[i].I - pt[id].T, 0) + __div(pp[i].A, pt[id].Z + pt[id].C) + 
					__div(pp[i].L, pt[id].V);
				s[snt++] = SolveList(e, r);
			}
		}
	}
	sort(s, s + snt);
	int tt = 0, dd = 0, pp = 0;
	for (int i = 0; i < snt; ++i) {
		if (tt + s[i].r <= l) {
			tt += s[i].r;
			++dd;
			pp += tt;
		}
		else break;
	}
	rt[id].d = dd, rt[id].p = pp, rt[id].id = id;
}
int main() {
	while (~scanf("%d%d%d%d", &m, &n, &t, &l)) {
		for (int i = 0; i < m; ++i) scanf("%d%d%d%d", &pp[i].I, &pp[i].A, &pp[i].L, &pp[i].O);
		for (int i = 0; i < t; ++i) scanf("%d%d%d%d", &pt[i].T, &pt[i].Z, &pt[i].V, &pt[i].C);
		int mx = 1 << m;
		int ret = 0, rm = inf;
		for (int i = 0; i < mx; ++i) {
			if (__builtin_popcount(i) == n) {
				for (int j = 0; j < t; ++j) cal(i, j);
				int rc = 0;
				for (int j = 1; j < t; ++j) {
					if (__less(0, j)) ++rc;
				}
				if (rc < rm) {
					rm = rc;
					ret = i;
				}
			}
		}
		for (int i = 0, j = 0; ; ++i) {
			if ((ret >> i) & 1) {
				printf("%d", i + 1);
				++j;
				if (j == n) {
					puts("");
					break;
				}
				else putchar(' ');
			}
		}
	}
    return 0;
}
