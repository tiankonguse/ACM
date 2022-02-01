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
int const maxn = 22222;
int const bz = 10001;
int parents[maxn];
int Find(int a){
    return parents[a] < 0 ? a : parents[a] = Find(parents[a]);
}
void Union(int a,int b){
    if(parents[a] < parents[b]){ parents[a] += parents[b], parents[b] = a;}
    else{ parents[b] += parents[a], parents[a] = b;}
}
void init(){ memset(parents, 0xff, sizeof(parents)); }

int n;
struct point {
	int x, y;
} p[maxn];
inline bool cmp_x(int a, int b) { return p[a].x < p[b].x; }
inline bool cmp_y(int a, int b) { return p[a].y < p[b].y; }
vector <int> vx[maxn], vy[maxn];

struct seg {
	int x1, y1, x2, y2, t;
	seg (int x1, int y1, int x2, int y2, int t) : x1(x1), y1(y1), x2(x2), y2(y2), t(t) { }
	seg () { }
	friend bool operator < (seg a, seg b) {
		return a.y1 < b.y1;
	}
} s[maxn];

int tree[maxn << 2];

void update(int l, int r, int a, int c, int p) {
	if (l == r) {
		tree[p] = c;
		return;
	}
	int mid = (l + r) >> 1, lp = p << 1, rp = p << 1 | 1;
	if (a <= mid) update(l, mid, a, c, lp);
	else update(mid + 1, r, a, c, rp);
	tree[p] = max(tree[lp], tree[rp]);
}

int query(int l, int r, int a, int b, int p) {
	if (l == a && r == b) {
		return tree[p];
	}
	int mid = (l + r) >> 1, lp = p << 1, rp = p << 1 | 1;
	if (b <= mid) return query(l, mid, a, b, lp);
	else if (a > mid) return query(mid + 1, r, a, b, rp);
	else return max(query(l, mid, a, mid, lp), query(mid + 1, r, mid + 1, b, rp));
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &p[i].x, &p[i].y);
		p[i].x += bz, p[i].y += bz;
		vx[p[i].x].push_back(i);
		vy[p[i].y].push_back(i);
	}
	init();
	int cnt = 0;
	for (int i = 1; i <= 20002; ++i) {
		int sz = vx[i].size();
		if (sz > 0) {
			if (sz & 1) {
				puts("0");
				return 0;
			}
			sort(vx[i].begin(), vx[i].end(), cmp_y);
			for (int j = 0; j < sz; j += 2) {
				int id1 = vx[i][j], id2 = vx[i][j + 1];
				int ra = Find(id1), rb = Find(id2);
				if (ra != rb) Union(ra, rb);
				s[cnt++] = seg(p[id1].x, p[id1].y, p[id2].x, p[id2].y, 1);
			}
		}
	}
	for (int i = 1; i <= 20002; ++i) {
		int sz = vy[i].size();
		if (sz > 0) {
			if (sz & 1) {
				puts("0");
				return 0;
			}
		}
		sort(vy[i].begin(), vy[i].end(), cmp_x);
		for (int j = 0; j < sz; j += 2) {
			int id1 = vy[i][j], id2 = vy[i][j + 1];
			int ra = Find(id1), rb = Find(id2);
			if (ra != rb) Union(ra, rb);
			s[cnt++] = seg(p[id1].x, p[id1].y, p[id2].x, p[id2].y, 0);
		}
	}
	if (-parents[Find(0)] != n) {
		puts("0");
		return 0;
	}
	sort(s, s + cnt);
	int ret = 0;
	for (int i = 0; i < cnt; ++i) {
		ret += (s[i].x2 - s[i].x1) + (s[i].y2 - s[i].y1);
		if (s[i].t == 0) {
			if (s[i].x1 + 2 <= s[i].x2) {
				int r = query(1, 20001, s[i].x1 + 1, s[i].x2 - 1, 1);
				if (r > s[i].y1) {
					puts("0");
					return 0;
				}
			}
		}
		else {
			update(1, 20001, s[i].x1, s[i].y2, 1);
		}
	}
	printf("%d\n", ret);
	return 0;
}

