#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <queue>
using namespace std;
template <class T> void checkmin(T &t,T x){if (x < t) t = x;}
template <class T> void checkmax(T &t,T x){if (x > t) t = x;}
typedef pair <int,int> PII;
typedef pair <double,double> PDD;
typedef long long lld;
#define foreach(it,v) for (__typeof((v).begin()) it = (v).begin();it != (v).end();it++)

/*
 * 里面有大数组，开在全局上。每次使用init传点进去。getNearest取最近点
 */

struct KDTree {
#define MAXN 1000005
	struct Tree {
		Tree *lc, *rc;
		PII coor;
		bool div;
	}*root, store[MAXN];

	int pt;

	PII *point;

	static bool cmpX(PII a, PII b) {
		return a < b;
	}

	static bool cmpY(PII a, PII b) {
		return PII(a.second, a.first) < PII(b.second, b.first);
	}
	
	lld dis(PII a, PII b) {
		return 1LL * (a.first - b.first)*(a.first - b.first) 
			+  1LL * (a.second - b.second) * (a.second - b.second);
	}

	Tree* getMemory() {
		store[pt].lc = store[pt].rc = NULL;
		return &store[pt++];
	}

	void init(int n, PII *a) {
		point = a;
		pt = 0;
		build(root, 0, 0, n);
	}

	void build(Tree *&p, bool div, int l, int r) {
		if (l < r) {
			p = getMemory();
			p->div = div;
			if (l + 1 == r) {
				p->coor = point[l];
			} else {
				int mid = l + r >> 1;
				nth_element(point + l, point + mid, point + r, div ? cmpY : cmpX);
				p->coor = point[mid];
				build(p->lc, div ^ 1, l, mid);
				build(p->rc, div ^ 1, mid + 1, r);
			}
		}
	}

	//limit是最近距离
	void getNearest(Tree *p, PII a, lld &limit) {
		if (p->coor != a) {   //有重点的时候不能这样判断
			checkmin(limit, dis(a, p->coor));
		}
		lld d = p->div ? a.second - p->coor.second : a.first - p->coor.first;
		if (d < 0) {
			if (p->lc) getNearest(p->lc, a, limit);
			if (d * d < limit && p->rc) getNearest(p->rc, a, limit);
		} else {
			if (p->rc) getNearest(p->rc, a, limit);
			if (d * d < limit && p->lc) getNearest(p->lc, a, limit);
		}
	}
}kd;

const int N = 100005;

int Tc;
int n;
PII a[N];
PII b[N];

int main(){
#ifdef cwj
	freopen("in", "r", stdin);
#endif
	scanf("%d", &Tc);
	for (int ri = 0; ri < Tc; ri++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &a[i].first, &a[i].second);
			b[i] = a[i];
		}
		kd.init(n, a);
		for (int i = 0; i < n; i++) {
			lld ret = kd.dis(b[(i + 1) % n], b[i]);
			kd.getNearest(kd.root, b[i], ret);
			printf("%I64d\n", ret);
		}
	}
	return 0;
}

