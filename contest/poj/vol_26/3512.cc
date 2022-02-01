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
#define maxn 1010

using namespace std;
typedef long long ll;
struct Point {
    ll x, y;
    friend bool operator < (Point a, Point b) {
        if (a.y == b.y) return a.x < b.x;
        else return a.y < b.y;
    }
} p[maxn];

char buf[128];
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}
ll const base1 = 1000100;
ll h[maxn];

int main() {
    int n, _ca = 1;
    while (gets(buf)) {
        if (buf[1] == '-') break;
        n = 0;
        sscanf(buf, "%lld %lld", &p[n].x, &p[n].y);
        ++n;
        while (gets(buf)) {
            if (buf[1] == '-') break;
            sscanf(buf, "%lld %lld", &p[n].x, &p[n].y);
            ++n;
        }
        sort(p, p + n);
        int ret = 0;
        ll x, y, g, q;
        for (int i = 0; i < n; ++i) {
            if (n - i <= ret) break;
            int cnt = 0;
            for (int j = i + 1; j < n; ++j) {
                x = p[j].x - p[i].x;
                y = p[j].y - p[i].y;
                g = gcd(x, y);
                x /= g, y /= g;
                h[cnt++] = x * base1 + y;
            }
            sort(h, h + cnt);
            int t = 1;
            for (int j = 1; j < cnt; ++j) {
                if (h[j] != h[j - 1]) {
                    ret = max(ret, t + 1);
                    t = 1;
                }
                else ++t;
            }
            ret = max(ret, t + 1);
        }
        printf("%d. %d\n", _ca++, ret);
    }
    return 0;
}
