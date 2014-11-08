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
const int N = 1005;
const int Mod = 1000000007;
int n, m, off = 10005;
int a[N];
int f[N][20010], g[N][20010];

void add(int &t, int x) {
	t += x;
	if (t >= Mod) t -= Mod;
}

int main() {
	scanf("%d", &n);
	rep (i, n) {
		scanf("%d", &a[i]);
		m += a[i];
	}
	rep (i, n) {
		add(f[i + 1][off + a[i]], 1);
		add(f[i + 1][off - a[i]], 1);
		for (int j = -m; j <= m; j++) if (f[i][off + j]) {
			add(f[i + 1][off + j + a[i]], f[i][off + j]);
			add(f[i + 1][off + j - a[i]], f[i][off + j]);
		}
	}
	int ans = 0;
	rep (i, n) {
		add(ans, f[i + 1][off]);
	}
	printf("%d\n", ans);
}
