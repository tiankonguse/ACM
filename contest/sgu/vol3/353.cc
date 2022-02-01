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
ll cal(ll n, ll k1, ll k2, ll p1, ll p2, ll p3) {
    ll ret = 0;
    if (n < p1) return 0;
    n -= p1, ret += k1;
    ll t2 = n / p2;
    if (t2 >= k2) {
        n -= k2 * p2;
        ret += k2;
        ret += (n + p3 - 1) / p3;
        return ret;
    }
    else {
        ret += (n + p2 - 1) / p2;
        return ret;
    }
}
int main() {
    ll n, k1, k2, p1, p2, p3;
    while (cin >> n >> k1 >> k2 >> p1 >> p2 >> p3) {
        cout << cal(n, k1, k2, p1, p2, p3) << endl;
    }
    return 0;
}
