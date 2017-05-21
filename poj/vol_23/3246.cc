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
#define maxn 100100
using namespace std;
typedef __int64 ll;
struct Point {
    ll x, y; int id;
    friend bool operator < (Point a, Point b) {
        if (a.y == b.y) return a.x < b.x;
        else return a.y < b.y;
    }
} p[maxn], pnt[maxn], res[maxn], q[maxn], res2[maxn];

ll Xmul(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

ll Xmul(Point b, Point c) {
    return b.x * c.y - c.x * b.y;
}
int Graham(Point pnt[], int n, Point res[]) {
    int i, j, top = 1;
    sort(pnt, pnt + n);
    pnt[n] = pnt[0];
    if (n == 0) return 0; res[0] = pnt[0];
    if (n == 1) return 1; res[1] = pnt[1];
    if (n == 2) return 2; res[2] = pnt[2];
    for (i = 2; i < n; ++i) {
        while (top && Xmul(res[top - 1], res[top], pnt[i]) <= 0) --top;
        res[++top] = pnt[i];
    }
    j = top;
    res[++top] = pnt[n - 2];
    for (i = n - 3; i >= 0; --i) {
        while (top != j && Xmul(res[top - 1], res[top], pnt[i]) <= 0) --top;
        res[++top] = pnt[i];
    }
    res[top] = res[0];
    res[top].id = n;
    return top;
}

inline ll __abs(ll a) { return a < 0 ? -a : a; }

inline ll cross(Point a, Point b){
    return a.x * b.y - a.y * b.x;
}
bool cmp(Point a, Point b){
    return cross(a, b) > 0;
}
void polar_sort(int n){
    int mx = 0, x0, y0;
    for(int i=0;i<n;i++){
        if(p[i].y < p[mx].y) mx = i;
        else if (p[i].y == p[mx].y && p[i].x < p[mx].x) mx = i;
    }
    swap(p[0], p[mx]);
    x0 = p[0].x, y0 = p[0].y;
    for(int i=0;i<n;i++){
        p[i].x -= x0;
        p[i].y -= y0;
    }
    for(int i=n-1;i>=0;i--){
        if(cross(p[i], p[i-1]) != 0){
            reverse(p + i, p + n);
            break;
        }
    }
    sort(p + 1, p + n, cmp);
}
int main() {
//    freopen("E.in", "r", stdin);
    int n;
    while (~scanf("%d", &n) && n) {
        for (int i = 0; i < n; ++i) {
            scanf("%I64d %I64d", &p[i].x, &p[i].y);
        }
        polar_sort(n);
        p[n] = p[0];
        for (int i = 0; i <= n; ++i) p[i].id = i;
        for (int i = 0; i <= n; ++i) pnt[i] = p[i];

        int g = Graham(pnt, n, res);
        ll area = 0;
        for (int i = 0; i < g; ++i) {
            area += cross(res[i], res[i + 1]);
        }
        if (area < 0) area = -area;

        int ia, ib, pa, pb;
        ll ret = Inf;

        for (int i = 0; i < g; ++i) {
            if (res[i].id == 0) {
                int m = 0;
                for (int j = 0; j < n; ++j) {
                    if (j == 0) continue;
                    q[m++] = p[j];
                }
                int g2 = Graham(q, m, res2);
                ll tr = 0;
                for (int j = 0; j < g2; ++j) {
                    tr += cross(res2[j], res2[j + 1]);
                }
                if (tr < 0) tr = -tr;
                ret = min(ret, tr);
            }
            else {
                ia = i - 1, ib = i + 1;
                if (ia < 0) ia = g - 1;
                pa = res[ia].id, pb = res[ib].id;
                int m = 0;
//                if (pa > pb) {
//                    for (int j = pa; j < n; ++j) {
//                        if (j != res[i].id && Xmul(p[j], res[ia], res[ib]) >= 0) q[m++] = p[j];
//                    }
//                    for (int j = 0; j <= pb; ++j) {
//                        if (j != res[i].id && Xmul(p[j], res[ia], res[ib]) >= 0) q[m++] = p[j];
//                    }
//                }
//                else {
                    for (int j = pa; j <= pb; ++j) {
                        if (j != res[i].id && Xmul(res[ia], p[j], res[ib]) >= 0) {
                            q[m++] = p[j];
                        }
                    }

                int g2 = Graham(q, m, res2);

                ll ts1 = cross(res[ia], res[i]) + cross(res[i], res[ib]) + cross(res[ib], res[ia]);
                ll ts2 = 0;
                if (g2 >= 3){
                    for (int j = 0; j < g2; ++j) {
                        ts2 += cross(res2[j], res2[j + 1]);
                    }
                }

                ll ts = __abs(ts1) - __abs(ts2);
                if (area - ts < ret) {
                    ret = area - ts;
                }

            }
        }
        if (ret & 1) printf("%I64d.50\n", ret >> 1);
        else printf("%I64d.00\n", ret >> 1);
    }
    return 0;
}
