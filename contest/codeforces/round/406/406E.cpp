#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <string>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define foreach(it,v) for (__typeof((v).end()) it = (v).begin(); it != (v).end(); it++)
typedef long long ll;
typedef pair <int, int> PII;
const int N = 100005;
int n, m;
int f[N], s[N];
ll ans;

ll solve() {
    int cnt = 0;
    int maxv = -1, minv = 2e9;
    rep (i, m) if (!s[i]) {
        maxv = max(maxv, f[i]);
        minv = min(minv, f[i]);
        cnt++;
    }
    ll res = 0;
    if (cnt >= 3) {
        res = max(res, (maxv - minv) * 2ll);
        //cout << res << endl;
    }
    if (cnt >= 2) {
        rep (i, m) if (s[i]) {
            int r = n - f[i];
            res = max(res, maxv - minv + (ll)min(minv + r, n + n - minv - r) + min(maxv + r, n + n - maxv - r));
        }
    }
    return res;
}

ll C(int n, int x) {
    if (x < 0 || x > n) return 0;
    if (x == 1) return n;
    if (x == 2) {
        return n * (ll)(n - 1) / 2;
    } else {
        return n * (ll)(n - 1) * (ll)(n - 2) / 6;
    }
}


void gao(ll goal) {
    int cnt = 0;
    int maxv = -1, minv = 2e9;
    map <int, int> ref;
    vector <int> v;
    rep (i, m) if (!s[i]) {
        maxv = max(maxv, f[i]);
        minv = min(minv, f[i]);
        cnt++;
        ref[f[i]]++;
        v.push_back(f[i]);
    }
    sort(v.begin(), v.end());
    if (cnt >= 3) {
        if ((maxv - minv) * 2ll == goal) {
            if (maxv == minv) {
                ans += C(cnt, 3);
            } else {
                ans += C(ref[minv], 2) * ref[maxv];
                ans += C(ref[maxv], 2) * ref[minv];
                ans += ref[minv] * (ll)ref[maxv] * (cnt - ref[maxv] - ref[minv]);
            }
        }
    }
    if (cnt >= 2) {
        rep (i, m) if (s[i]) {
            int r = n - f[i];
            ll tmp = maxv - minv + (ll)min(minv + r, n + n - minv - r) + min(maxv + r, n + n - maxv - r);
            if (tmp == goal) {
                if (n + n - minv - r <= minv + r) {
                    ans += C(ref[minv], 2);
                    ans += ref[minv] * (ll)(cnt - ref[minv]);
                } else if (maxv + r <= n + n - maxv - r) {
                    ans += C(ref[maxv], 2);
                    ans += ref[maxv] * (ll)(cnt - ref[maxv]);
                } else {
                    int x = n - r;
                    int lhs = lower_bound(v.begin(), v.end(), x) - v.begin();
                    int mid = ref[x];
                    int rhs = cnt - lhs - mid;
                    ans += C(mid, 2);
                    ans += lhs * mid;
                    ans += lhs * rhs;
                    ans += mid * rhs;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    rep (i, m) {
        cin >> s[i] >> f[i];
    }
    ll res = solve();
    rep (i, m) s[i] ^= 1;
    res = max(res, solve());
    gao(res);
    rep (i, m) s[i] ^= 1;
    gao(res);
    cout << ans << endl;
}

