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
int const maxn = 10010;
int const maxm = 1000100;


vector < pair<int, int> > v[21][21];
int n;

int main() {
	scanf("%d", &n);
	int id; int x, y;
	int a, b, c, g;
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &x, &y);
		x += 10000, y += 10000;
		for (ll dx = -10; dx <= 10; ++dx) {
			for (ll dy = -10; dy <= 10; ++dy) {
				g = __gcd(dx, dy);
				if (g == 1 || g == -1) {
					a = dy + 10;
					b = -dx + 10;
					c = dx * y - dy * x;
					if (b == 10) v[a][b].push_back( make_pair(c, y) );
					else v[a][b].push_back( make_pair(c, x) );
				}
			}
		}
	}
	for (int i = 0; i <= 20; ++i) {
		for (int j = 0; j <= 20; ++j) {
			sort(v[i][j].begin(), v[i][j].end());
		}
	}
	int Q;
	int x1, y1, vx1, vy1;
	int ax, bx, ay, by, avx, bvx, avy, bvy;
	scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d ", &Q, &x1, &y1, &vx1, &vy1, &ax, &bx, &ay, &by, &avx, &bvx, &avy, &bvy);
	int ret = -1, rc = -1;
	for (int i = 1; i <= Q; ++i) {
		ll vx, vy;
		if (vx1 == 0) {
			if (vy1 < 0) vy = -1;
			else vy = 1;
			vx = 0;
		}
		else if (vy1 == 0) {
			if (vx1 < 0) vx = -1;
			else vx = 1;
			vy = 0;
		}
		else {
			g = __gcd(vx1, vy1);
			if (g < 0) g = -g;
			vx = vx1 / g, vy = vy1 / g;
		}


		x1 += 10000, y1 += 10000;
		a = vy + 10;
		b = -vx + 10;
		c = vx * y1 - vy * x1;
		int tr = 0;
		if (v[a][b].size() > 0) {
			if (vx < 0) {
				tr = upper_bound(v[a][b].begin(), v[a][b].end(), make_pair(c, x1)) - v[a][b].begin();
				tr -= upper_bound(v[a][b].begin(), v[a][b].end(), make_pair(c - 1, inf)) - v[a][b].begin();
			}
			else if (vx == 0) {
				if (vy < 0) {
					tr = upper_bound(v[a][b].begin(), v[a][b].end(), make_pair(c, y1)) - v[a][b].begin();
					tr -= upper_bound(v[a][b].begin(), v[a][b].end(), make_pair(c - 1, inf)) - v[a][b].begin();
				}
				if (vy > 0) {
					tr = upper_bound(v[a][b].begin(), v[a][b].end(), make_pair(c + 1, -inf)) - v[a][b].begin();
					tr -= upper_bound(v[a][b].begin(), v[a][b].end(), make_pair(c, y1 - 1)) - v[a][b].begin();
				}
			}
			else {
				tr = upper_bound(v[a][b].begin(), v[a][b].end(), make_pair(c + 1, -inf)) - v[a][b].begin();
				tr -= upper_bound(v[a][b].begin(), v[a][b].end(), make_pair(c, x1 - 1)) - v[a][b].begin();
			}
		}
		if (ret <= tr) {
			ret = tr;
			rc = i;
		}
		x1 = (1LL * ax * x1 + bx) % 20001 - 10000;
		y1 = (1LL * ay * y1 + by) % 20001 - 10000;
		vx1 = (1LL * avx * (vx1 + 10) + bvx) % 21 - 10;
		vy1 = (1LL * avy * (vy1 + 10) + bvy) % 21 - 10;
	}
	printf("%d %d\n", rc, ret);
	return 0;
}
