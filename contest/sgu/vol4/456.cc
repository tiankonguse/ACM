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
double const eps = 1e-8;
double cal(double s, double x, double p, int m) {
    double t;
    for (int i = 0; i < m; ++i) {
        t = s * p;
        s -= (x - t);
    }
    return s;
}
int main() {
    double s, p, x;
    double l, h, mid, tr;
    int m;
    while (cin >> s >> m >> p) {
        p /= 100.0;
        l = 0, h = 1e15;
        while (l + eps < h) {
            mid = (l + h) / 2.0;
            tr = cal(s, mid, p, m);
            if (tr > 0) l = mid;
            else h = mid;
        }
        printf("%.5lf\n", mid);
    }
    return 0;
}
