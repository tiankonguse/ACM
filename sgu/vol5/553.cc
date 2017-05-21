#include <iostream>
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
#define maxn 200200
#define maxm 200200

using namespace std;
typedef __int64 ll;
ll w[maxn], s[maxn], c[maxn], cs[maxn];

int main() {
    int n, m; ll k;
    while (~scanf("%d%d%I64d", &n, &m, &k)) {
        s[0] = cs[0] = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%I64d %I64d", &w[i], &c[i]);
            s[i] = s[i - 1] + w[i];
            cs[i] = cs[i - 1] + c[i];
        }
        ll s1;
        ll ret = -1, rl, rr;
        int high, low, mid;
        ll limit;
        for (int cut = 0; cut + m < n; ++cut) {
            int p = n - cut - m;
            s1 = s[n - cut] - s[p];
            limit = s1;
            high = p - 1, low = 0, mid;
            int rp = -1;
            while (low <= high) {
                mid = (high + low) >> 1;
                if ((s[p] - s[mid]) * k >= limit) {
                    rp = mid;
                    low = mid + 1;
                }
                else high = mid - 1;
            }
            if (rp == -1) break;
            if (cs[rp] + (cs[n] - cs[n - cut]) > ret) {
                ret = cs[rp] + cs[n] - cs[n - cut];
                rl = rp;
                rr = cut;
            }
        }
        if (ret == -1) { puts("0 0"); continue; }
        cout << rl + rr << " " << ret << endl;
        for (int i = 0; i < rr; ++i) putchar('H');
        for (int i = 0; i < rl; ++i) putchar('T');
        puts("");
    }
    return 0;
}

