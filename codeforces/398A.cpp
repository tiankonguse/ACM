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
const ll INF = 1LL << 62;
ll n, m;

void out(int i, int j) {
    //cout << i << " " << j << endl;
    vector <int> lhs, rhs;
    rep (k, m % i) lhs.push_back(m / i + 1);
    rep (k, i - m % i) lhs.push_back(m / i);
    rep (k, j - 1) rhs.push_back(1);
    rhs.push_back(n - (j - 1));
    //cout << n - (j - 1) << endl;
    rep (k, lhs.size()) {
        rep (o, lhs[k]) printf("x");
        if (k < rhs.size()) rep (o, rhs[k]) printf("o");
    }
}

int main() {
    cin >> n >> m;
    if (n == 0) {
        cout << -m * (ll)m << endl;
        rep (i, m) printf("x");
    } else if (m == 0) {
        cout << n * (ll)n << endl;
        rep (i, n) printf("o");
    } else {
        ll ans = -INF;
        int ansi = -1;
        int ansj = -1;
        for (int i = 1; i <= min(m, n + 1); i++) {
            ll cur = 0;
            cur -= (m / i + 1) * (ll)(m / i + 1) * (m % i);
            cur -= (m / i) * (ll)(m / i) * (i - m % i);
            if (i == 1) {
                cur += n * (ll)n;
            } else {
                cur += 1 * (i - 2) + (n - (i - 2)) * (ll)(n - (i - 2));
            }
            if (cur > ans) {
                ans = cur;
                ansi = i;
                ansj = max(1, i - 1);
            }
        }
        cout << ans << endl;
        out(ansi, ansj);
    }
}

