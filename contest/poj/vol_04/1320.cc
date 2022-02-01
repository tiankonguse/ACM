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
#define maxn 10001
using namespace std;
typedef long long ll;

ll a[maxn], p[maxn], q[maxn];
ll _p[maxn], _q[maxn];

ll solve(ll D, int k) {
    a[0] = (ll)(floor(sqrt(1.0 * D)));
    p[0] = 0, q[0] = 1;
    for (int i = 1; i <= k; ++i) {
        p[i] = a[i - 1] * q[i - 1] - p[i - 1];
        q[i] = (D - p[i] * p[i]) / q[i - 1];
        a[i] = (a[0] + p[i]) / q[i];
    }
    _p[0] = a[0], _p[1] = a[0] * a[1] + 1;
    _q[0] = 1, _q[1] = a[1];
    for (int i = 2; i <= k; ++i) {
        _p[i] = a[i] * _p[i - 1] + _p[i - 2];
        _q[i] = a[i] * _q[i - 1] + _q[i - 2];
        if (_p[i] * _p[i] - D * _q[i] * _q[i] == 1) {
            printf("%10lld%10lld\n", _q[i] / 2, _p[i] / 2);
        }
    }
  for (int i = 0; i <= k; ++i) {
		if (_p[i] * _p[i] - D * _q[i] * _q[i] == 1) return _p[i];
	}
	return -1;
}

int main() {
    solve(2, 21);

    return 0;
}
