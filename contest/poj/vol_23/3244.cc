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
#define maxn 200200
using namespace std;
typedef __int64 ll;
ll a[maxn], b[maxn], c[maxn];

int main() {
    int n; ll x, y, z;
    while (scanf("%d", &n) && n) {
        for (int i = 0; i < n; ++i) {
            scanf("%I64d %I64d %I64d", &x, &y, &z);
            a[i] = x - y, b[i] = y - z, c[i] = z - x;
        }
        sort(a, a + n), sort(b, b + n), sort(c, c + n);
        ll ret = 0;
        for (int i = 0; i < n; ++i) {
            ret += (2 * i + 1 - n) * (a[i] + b[i] + c[i]);
        }
        printf("%I64d\n", ret / 2);
    }
    return 0;
}
