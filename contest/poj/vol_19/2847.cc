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

using namespace std;
typedef __int64 ll;
ll const mod[] = {
    10LL,
    100LL,
    1000LL,
    10000LL,
    100000LL,
    1000000LL,
    10000000LL,
    100000000LL,
    1000000000LL,
    10000000000LL
};

inline ll mulMod(ll a, ll b, ll c){
  ll res = 0LL;
	for (; b; b >>= 1, a = (a << 1) % c ) {
		if (b & 1) res = (res + a) % c;
	}
	return res;
}
ll powMod(ll a, ll b, ll c){
	ll res = 1LL;
	for (; b; b >>= 1, a = mulMod(a, a, c) ) {
		if (b & 1) res = mulMod(res, a, c);
	}
	return res;
}

ll a, ret;
int const dig[] = {1, 3, 7, 9};
bool dfs(int d, ll res) {
    ll t, nxt;
    ll des = a % mod[d];
    if (d == 0) {
        for (int i = 0; i < 4; ++i) {
            nxt = powMod(dig[i], 3LL, mod[0]);
            if (nxt == a) {
                ret = dig[i];
                return true;
            }
            if (nxt == des) {
                if (dfs(d + 1, dig[i])) return true;
            }
        }
    }
    else {
        for (ll i = 0; i < 10; ++i) {
            t = res + i * mod[d - 1];
            nxt = powMod(t, 3LL, mod[d]);
            if (nxt == a) {
                ret = t;
                return true;
            }
            if (nxt == des) {
                if (dfs(d + 1, t)) return true;
            }
        }
    }
    return false;
}
int main() {
    int T;
    for (scanf("%d", &T); T--; ) {
        scanf("%I64d", &a);
        dfs(0, 0);
        printf("%I64d\n", ret);
    }
    return 0;
}
