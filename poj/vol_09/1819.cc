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
double const eps = 1e-8;
inline int sgn(double x) { return x < -eps ? -1 : x > eps ? 1 : 0; }
struct Point {
    double x, y;
    int id;
    Point (double _x, double _y, int _id) { x = _x, y = _y, id = _id; }
    Point () {}
} p[maxn];

double r[maxn];
int res[maxn];

double cal(Point a, double r) {
    return a.x + sqrt(4.0 * a.y * r);
}
int main() {
    int n;
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; ++i) {
            scanf("%lf", &r[i]);
        }
        int cnt = 0;
        int top = 0;
        p[top++] = Point(r[0], r[0], 1);
        double mx, t; int ch;
        for (int i = 1; i < n; ++i) {
            mx = r[i], ch = -1;
            for (int j = 0; j < top; ++j) {
                t = cal(p[j], r[i]);
                if (sgn(t - mx) > 0) {
                    mx = t;
                    ch = j;
                }
            }
            for (int j = ch + 1; j < top; ++j) res[cnt++] = p[j].id;
            top = ch + 1;
            p[top++] = Point(mx, r[i], i + 1);
        }

        mx = 0, ch = -1;
        for (int i = 0; i < top; ++i) {
            t = p[i].x + r[ p[i].id - 1];
            if (sgn(t - mx) > 0) {
                mx = t;
                ch = i;
            }
        }
        for (int i = ch + 1; i < top; ++i) {
            res[cnt++] = p[i].id;
        }

        printf("%d\n", cnt);
        sort(res, res + cnt);
        for (int i = 0; i < cnt; ++i) {
            printf("%d\n", res[i]);
        }
    }
    return 0;
}
