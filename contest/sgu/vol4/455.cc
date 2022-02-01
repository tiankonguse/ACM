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
#define maxn 2000000
using namespace std;
typedef __int64 ll;
ll a, b, c;
inline ll cal(ll x) {
    return (a * x + x % b) % c;
}
ll solve() {
    ll p1 = 1LL, p2 = 1LL;
    int r;
    for (int i = 1; i <= maxn; ++i) {
        p1 = cal(p1);
        p2 = cal(p2); p2 = cal(p2);
        if (p1 == p2) break;
    }
    if (p1 != p2) return -1;
    for (r = 1; ; ++r) {
        p1 = cal(p1);
        p2 = cal(p2); p2 = cal(p2);
        if (p1 == p2) break;
    }
    p1 = p2 = 1LL;
    for (int i = 0; i < r; ++i) p2 = cal(p2);
    int idx = r;
    while (p1 != p2) {
        p1 = cal(p1);
        p2 = cal(p2);
        ++idx;
    }
    if (idx > maxn) return -1;
    else return idx;
}
int main() {
    ll p1, p2;
    while (~scanf("%I64d%I64d%I64d", &a, &b, &c)) {
        printf("%I64d\n", solve());
    }
    return 0;
}
