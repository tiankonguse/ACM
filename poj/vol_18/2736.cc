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
int const maxn(1111);
ll cal(ll n, ll m) {
  //printf("cal(%I64d, %I64d)\n",n,m);
	if (n < m) swap(n, m);
	return n * m * (1 + m) - (1 + m) * (n + m) * m / 2 + m * (m + 1) * (m + m + 1) / 6;
}
ll _ab(ll x) { return x < 0 ? -x : x; }
int n;
struct rec {
	ll x1, y1, x2, y2;
	void print() {
		printf("%I64d, %I64d, %I64d, %I64d\n", x1, y1, x2, y2);
	}
} p[maxn];

int main() {
	int ca = 1;
	while (scanf("%d", &n) && n) {
		ll ret = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%I64d %I64d %I64d %I64d", &p[i].x1, &p[i].y1, &p[i].x2, &p[i].y2);
			if (p[i].x1 > p[i].x2) swap(p[i].x1, p[i].x2);
			if (p[i].y1 > p[i].y2) swap(p[i].y1, p[i].y2);
			ret += cal(_ab(p[i].x1 - p[i].x2), _ab(p[i].y1 - p[i].y2));
		}
		ll sec;
		
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i == j) continue;
				if (p[i].y2 == p[j].y1) {
					sec = 0;
					if (p[i].x1 >= p[j].x1 && p[i].x1 <= p[j].x2) sec = min(p[i].x2, p[j].x2) - p[i].x1;
					if (p[i].x2 >= p[j].x1 && p[i].x2 <= p[j].x2) sec = p[i].x2 - max(p[i].x1, p[j].x1);
					if (p[i].x2 >= p[j].x2 && p[i].x1 <= p[j].x1) sec = p[j].x2 - p[j].x1;
					if (sec > 2) {
						sec -= 2;
						ret += cal(sec, _ab(p[j].y2 - p[i].y1));
						ret -= cal(sec, _ab(p[j].y2 - p[j].y1));
						ret -= cal(sec, _ab(p[i].y2 - p[i].y1));
					}
				}
				if (p[i].x2 == p[j].x1) {
					sec = 0;
					if (p[i].y1 >= p[j].y1 && p[i].y1 <= p[j].y2) sec = min(p[i].y2, p[j].y2) - p[i].y1;
					if (p[i].y2 >= p[j].y1 && p[i].y2 <= p[j].y2) sec = p[i].y2 - max(p[i].y1, p[j].y1);
					if (p[i].y2 >= p[j].y2 && p[i].y1 <= p[j].y1) sec = p[j].y2 - p[j].y1;
					if (sec > 2) {
						sec -= 2;
						ret += cal(sec, _ab(p[j].x2 - p[i].x1));
						ret -= cal(sec, _ab(p[j].x2 - p[j].x1));
						ret -= cal(sec, _ab(p[i].x2 - p[i].x1));
					}
				}
			}
		}
		printf("Case %d: %I64d\n", ca++, ret);
	}
	return 0;
}
