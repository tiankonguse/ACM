/* XVIII Championship of Ural
 * Problem C - Christmas tree
 * by yxdb
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> PII;

const int N = 100005;

struct foo {
	LL p, h, c;
	void read() { cin >> p >> h >> c; }
	bool operator<(const foo& rhs) const {
		if (h != rhs.h) return h < rhs.h;
		return p < rhs.p;
	}
} a[N];

LL n, m, k, w, s;

int main() {
	cin >> n >> m >> k >> w >> s;
	LL need = (s * m - 1) / w + 1;
	for (int i = 0; i < k; ++i) a[i].read();
	sort(a, a+k);
	LL cnt = 0, ans = 0;
	priority_queue<PII> q;
	for (int i = 0; i < k; ++i) {
		LL cap = a[i].h * m;
		cnt += a[i].c;
		ans += a[i].p * a[i].c;
		q.push(PII(a[i].p, a[i].c));
		while (cnt > need || cnt > cap) {
			LL p = q.top().first;
			LL c = q.top().second;
			q.pop();
			LL o = min(c, cnt - min(need, cap));
			cnt -= o;
			ans -= p * o;
			if (o < c) q.push(PII(p, c - o));
		}
	}
	cout << (cnt < need ? -1 : ans) << '\n';
}
