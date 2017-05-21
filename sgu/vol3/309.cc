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

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define maxn 20202
using namespace std;
typedef __int64 ll;
struct Point {
  ll x, y;
	friend bool operator < (Point a, Point b) {
		return a.y < b.y;
	}
} p[maxn], p2[maxn];
inline bool cmp(Point a, Point b) {
	return a.x < b.x;
}
int n;
ll min_x, max_x, min_y, max_y, w, h;
int left_t, left_b, right_t, right_b;

inline bool check0(int p1, int p2, ll a) {
	return (abs(p[p1].x - p[p2].x) <= a && abs(p[p1].y - p[p2].y) <= a);
}
inline void print(int id) {
	printf(" (%I64d, %I64d) \n", p[id].x, p[id].y);
}

bool check(ll a) {
	if (w <= a) {
		int cnt = 1;
		ll s = 0;
		for (int i = 1; i < n; ++i) {
			if (s + p[i].y - p[i - 1].y > a) {
				s = 0;
				++cnt;
				if (cnt > 3) return false;
			}
			else s += p[i].y - p[i - 1].y;
		}
		return true;
	}
	else {
		ll rmd_l, rmd_r, rmd_t, rmd_b;
		int top_l = -1, top_r = -1, top_mid = -1;
		bool f_top = true, f1, f2;
		for (int i = n - 1; i >= 0; --i) {

			f1 = check0(left_t, i, a);
			f2 = check0(right_t, i, a);
			if (f1 && f2) {
				if (top_mid == -1) top_mid = i;
				else if (p[i].y > p[top_mid].y) {
					top_mid = i;
				}
			}
			else if (f1 && !f2) {
				if (top_l == -1) top_l = i;
				else if (p[i].y > p[top_l].y) {
					top_l = i;
				}
			}
			else if (!f1 && f2) {
				if (top_r == -1) top_r = i;
				else if (p[i].y > p[top_r].y) {
					top_r = i;
				}
			}
		}
		top_l = (top_l == -1 || p[top_l].y <= p[left_t].y) ? left_t : top_l;
		top_r = (top_r == -1 || p[top_r].y <= p[right_t].y) ? right_t : top_r;

		rmd_l = Inf, rmd_r = -Inf, rmd_b = Inf, rmd_t = -Inf;
		if (top_mid == -1 || p[top_mid].y <= p[top_l].y || p[top_mid].y <= p[top_r].y) {
			for (int i = 0; i < n; ++i) {
				f1 = check0(i, top_l, a) && check0(i, left_t, a);
				f2 = check0(i, top_r, a) && check0(i, right_t, a);
				if (!f1 && !f2) {
					rmd_l = min(rmd_l, p[i].x);
					rmd_r = max(rmd_r, p[i].x);
					rmd_b = min(rmd_b, p[i].y);
					rmd_t = max(rmd_t, p[i].y);
				}
			}
			if (rmd_l == Inf || (rmd_t - rmd_b <= a && rmd_r - rmd_l <= a)) return true;
		}
		else {
			for (int i = 0; i < n; ++i) {
				f1 = check0(i, top_mid, a) && check0(i, left_t, a);
				f2 = check0(i, top_r, a) && check0(i, right_t, a);
				if (!f1 && !f2) {
					rmd_l = min(rmd_l, p[i].x);
					rmd_r = max(rmd_r, p[i].x);
					rmd_b = min(rmd_b, p[i].y);
					rmd_t = max(rmd_t, p[i].y);
				}
			}
			if (rmd_l == Inf || (rmd_t - rmd_b <= a && rmd_r - rmd_l <= a)) return true;
			rmd_l = Inf, rmd_r = -Inf, rmd_b = Inf, rmd_t = -Inf;

			for (int i = 0; i < n; ++i) {
				f1 = check0(i, top_l, a) && check0(i, left_t, a);
				f2 = check0(i, top_mid, a) && check0(i, right_t, a);
				if (!f1 && !f2) {
					rmd_l = min(rmd_l, p[i].x);
					rmd_r = max(rmd_r, p[i].x);
					rmd_b = min(rmd_b, p[i].y);
					rmd_t = max(rmd_t, p[i].y);
				}
			}
			if (rmd_l == Inf || (rmd_t - rmd_b <= a && rmd_r - rmd_l <= a)) return true;
		}

		int bot_l = -1, bot_r = -1, bot_mid = -1;
		for (int i = 0; i < n; ++i) {

			f1 = check0(left_b, i, a);
			f2 = check0(right_b, i, a);
			if (f1 && f2) {
				if (bot_mid == -1) bot_mid = i;
				else if (p[i].y < p[bot_mid].y) {
					bot_mid = i;
				}
			}
			else if (f1 && !f2) {
				if (bot_l == -1) bot_l = i;
				else if (p[i].y < p[bot_l].y) {
					bot_l = i;
				}
			}
			else if (!f1 && f2) {
				if (bot_r == -1) bot_r = i;
				else if (p[i].y < p[bot_r].y) {
					bot_r = i;
				}
			}
		}
		bot_l = (bot_l == -1 || p[bot_l].y >= p[left_b].y) ? left_b : bot_l;
		bot_r = (bot_r == -1 || p[bot_r].y >= p[right_b].y) ? right_b : bot_r;

		rmd_l = Inf, rmd_r = -Inf, rmd_b = Inf, rmd_t = -Inf;
		if (bot_mid == -1 || p[bot_mid].y >= p[bot_l].y || p[bot_mid].y >= p[bot_r].y) {
			for (int i = 0; i < n; ++i) {
				f1 = check0(i, bot_l, a) && check0(i, left_b, a);
				f2 = check0(i, bot_r, a) && check0(i, right_b, a);
				if (!f1 && !f2) {
					rmd_l = min(rmd_l, p[i].x);
					rmd_r = max(rmd_r, p[i].x);
					rmd_b = min(rmd_b, p[i].y);
					rmd_t = max(rmd_t, p[i].y);
				}
			}
			if (rmd_l == Inf || (rmd_t - rmd_b <= a && rmd_r - rmd_l <= a)) return true;
		}
		else {
			for (int i = 0; i < n; ++i) {
				f1 = check0(i, bot_mid, a) && check0(i, left_b, a);
				f2 = check0(i, bot_r, a) && check0(i, right_b, a);
				if (!f1 && !f2) {
					rmd_l = min(rmd_l, p[i].x);
					rmd_r = max(rmd_r, p[i].x);
					rmd_b = min(rmd_b, p[i].y);
					rmd_t = max(rmd_t, p[i].y);
				}
			}
			if (rmd_l == Inf || (rmd_t - rmd_b <= a && rmd_r - rmd_l <= a)) return true;
			rmd_l = Inf, rmd_r = -Inf, rmd_b = Inf, rmd_t = -Inf;

			for (int i = 0; i < n; ++i) {
				f1 = check0(i, bot_l, a) && check0(i, left_b, a);
				f2 = check0(i, bot_mid, a) && check0(i, right_b, a);
				if (!f1 && !f2) {
					rmd_l = min(rmd_l, p[i].x);
					rmd_r = max(rmd_r, p[i].x);
					rmd_b = min(rmd_b, p[i].y);
					rmd_t = max(rmd_t, p[i].y);
				}
			}
			if (rmd_l == Inf || (rmd_t - rmd_b <= a && rmd_r - rmd_l <= a)) return true;
		}

		bot_l = (bot_mid == -1 || p[bot_l].y < p[bot_mid].y) ? bot_l : bot_mid;
		bot_r = (bot_mid == -1 || p[bot_r].y < p[bot_mid].y) ? bot_r : bot_mid;
		top_l = (top_mid == -1 || p[top_l].y > p[top_mid].y) ? top_l : top_mid;
		top_r = (top_mid == -1 || p[top_r].y > p[top_mid].y) ? top_r : top_mid;

		rmd_l = Inf, rmd_r = -Inf, rmd_b = Inf, rmd_t = -Inf;
		for (int i = 0; i < n; ++i) {
			f1 = check0(i, bot_l, a) && check0(i, left_b, a);
			f2 = check0(i, top_r, a) && check0(i, right_t, a);
			if (!f1 && !f2) {
				rmd_l = min(rmd_l, p[i].x);
				rmd_r = max(rmd_r, p[i].x);
				rmd_b = min(rmd_b, p[i].y);
				rmd_t = max(rmd_t, p[i].y);
			}
		}
		if (rmd_l == Inf || (rmd_t - rmd_b <= a && rmd_r - rmd_l <= a)) return true;

		rmd_l = Inf, rmd_r = -Inf, rmd_b = Inf, rmd_t = -Inf;
		for (int i = 0; i < n; ++i) {
			f1 = check0(i, bot_r, a) && check0(i, right_b, a);
			f2 = check0(i, top_l, a) && check0(i, left_t, a);
			if (!f1 && !f2) {
				rmd_l = min(rmd_l, p[i].x);
				rmd_r = max(rmd_r, p[i].x);
				rmd_b = min(rmd_b, p[i].y);
				rmd_t = max(rmd_t, p[i].y);
			}
		}
		if (rmd_l == Inf || (rmd_t - rmd_b <= a && rmd_r - rmd_l <= a)) return true;

		return false;
	}
}

int main() {
	while (~scanf("%d", &n)) {
		min_x = Inf, max_x = -Inf, min_y = Inf, max_y = -Inf;
		for (int i = 0; i < n; ++i) {
			scanf("%I64d %I64d", &p[i].x, &p[i].y);
		}
		memcpy(p2, p, sizeof p);
		sort(p, p + n);
		sort(p2, p2 + n, cmp);
		for (int i = 0; i < n; ++i) {
			if (p[i].x < min_x) {
				min_x = p[i].x;
				left_b = left_t = i;
			}
			else if (p[i].x == min_x) {
				if (p[i].y > p[left_t].y) {
					left_t = i;
				}
				if (p[i].y < p[left_b].y) {
					left_b = i;
				}
			}
			if (p[i].x > max_x) {
				max_x = p[i].x;
				right_b = right_t = i;
			}
			else if (p[i].x == max_x) {
				if (p[i].y > p[right_t].y) {
					left_t = i;
				}
				if (p[i].y < p[right_b].y) {
					right_b = i;
				}
			}
			min_y = min(min_y, p[i].y);
			max_y = max(max_y, p[i].y);
		}
		w = max_x - min_x;
		h = max_y - min_y;
		ll low = 1, high = max(w, h), mid;
		ll ret = 0;
		while (low <= high) {
			mid = (low + high) >> 1;
			if (check(mid)) {
				ret = mid;
				high = mid - 1;
			}
			else low = mid + 1;
		}
		printf("%I64d\n", ret);
	}
	return 0;
}

