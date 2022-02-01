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
const int N = 1 << 12;
int Tc, n, Mod;
int a[1 << 20];
int f[2][N];

inline void add(int &t, int x) {
    t += x;
    if (t >= Mod) t-= Mod;
}

void solve() {
    rep (mask, 1 << n) {
        a[mask] = 0;
        rep (i, n) if (mask & 1 << i) {
            a[mask] ^= i + 1;
        }
    }
    ll ans = 0;
    rep (mask, 1 << n) {
        for (int sub = mask; ; sub = (sub - 1) & mask) {
            if (sub >= (sub ^ mask) && a[sub] == a[sub ^ mask]) {
                ans++;
            }
            if (sub >= (sub ^ mask)) ans++;
            if (!sub) break;
        }
    }
    cout << ans % Mod << "\n";
}

int main() {
    //init();
    scanf("%d", &Tc);
    rep (_, Tc) {
        cout << "Case " << _ + 1 << ": ";
        scanf("%d%d", &n, &Mod);
//        Mod *= 2;
/*
        rep (i, N) f[i] = 0;
        int p = 0;
        memset(f, 0, sizeof(f));
        f[p][0] = 1;
        rep (_, n) {
            int i = _ + 1;
            memcpy(f[p ^ 1], f[p], sizeof(f[p ^ 1]));
            rep (j, N) {
                add(f[p ^ 1][j ^ i], f[p][j]);
            }
            p ^= 1;
        }
*/
        ll ans = 1;
        rep (i, n) ans = (ans * 3) % Mod;
        ans++;
        solve();
    }
}

