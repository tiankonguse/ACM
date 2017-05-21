nclude <iostream>
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
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define Rep(i, n) for (int i = 1; i <= (n); ++i)
#define clr(x, a) memset(x, (a), sizeof x)
using namespace std;
typedef long long ll;
struct node {
	int a[3];
} u, v;

set <int> s;
bool vis(int a[]) {
	int t = 0; rep(i, 3) t = t * 256 + a[i];
	if (s.find(t) == s.end()) {
		s.insert(t);
		return 0;
	} else {
		return 1;
	}
}

queue <node> Q;

bool mk[1024];
void upd(node t) {
	if (vis(t.a)) return;
	Q.push(t);
	rep(i, 8) {
		int r = 0;
		rep(j, 3) if (i >> j & 1) {
			r += t.a[j];
		}
		mk[r] = 1;
	}
}

int main() {
	int a[3]; rep(i, 3) scanf("%d", &a[i]);
	Q.push(u);
	vis(u.a);
	while (!Q.empty()) {
		u = Q.front(); Q.pop();
		rep(i, 3) {
			rep(j, 3) v.a[j] = u.a[j];
			v.a[i] = a[i];
			upd(v);
		}
		rep(i, 3) rep(j, 3) if (i != j) {
			rep(k, 3) v.a[k] = u.a[k];
			int t = min(v.a[i], a[j] - v.a[j]);
			v.a[i] -= t, v.a[j] += t;
			upd(v);
		}
	}
	int ret = 0;
	Rep(i, 1000) ret += mk[i];
	printf("%d\n", ret);

	return 0;
}
