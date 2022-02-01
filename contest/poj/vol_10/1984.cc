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
#include <ctime>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL

using namespace std;
int const maxn = 40400;
int parents[maxn], vx[maxn], vy[maxn];
int Find(int a){
    if(parents[a] < 0) return a;
    else{
  int t = parents[a];
        parents[a] = Find(parents[a]);
        vx[a] += vx[t];
        vy[a] += vy[t];
        return parents[a];
    }
}
void Union(int a, int b, int cx, int cy) {
    if (parents[a] < parents[b]) {
        parents[a] += parents[b];
        parents[b] = a;
        vx[b] += cx;
        vy[b] += cy;
    }
    else {
        parents[b] += parents[a];
        parents[a] = b;
        vx[a] -= cx;
        vy[a] -= cy;
    }
}
void init() {
    memset(parents, 0xff, sizeof parents);
    memset(vx, 0, sizeof vx);
    memset(vy, 0, sizeof vy);
}
struct lines {
    int a, b, c;
    char d;
} l[maxn];
struct Querys {
    int a, b, c, id;
    friend bool operator < (Querys A, Querys B) {
        return A.c < B.c;
    }
} q[maxn];
int ans[maxn];
inline int __abs(int x) { return x > 0 ? x : -x; }
int main() {
    init();
    int n, m;
    while (~scanf("%*d%d", &n)) {
        for (int i = 1; i <= n; ++i) {
            scanf("%d %d %d %c", &l[i].a, &l[i].b, &l[i].c, &l[i].d);
        }
        scanf("%d", &m);
        for (int i = 1; i <= m; ++i) {
            scanf("%d%d%d", &q[i].a, &q[i].b, &q[i].c);
            q[i].id = i;
        }
        sort(q + 1, q + m + 1);
        int pos = 1, dx, dy, ra, rb;
        init();
        for (int i = 1; i <= n; ++i) {
            ra = Find(l[i].a);
            rb = Find(l[i].b);
            if (ra != rb) {
                if (l[i].d == 'E') {
                    dx = l[i].c;
                    dy = 0;
                }
                else if (l[i].d == 'W') {
                    dx = -l[i].c;
                    dy = 0;
                }
                else if (l[i].d == 'N') {
                    dx = 0;
                    dy = l[i].c;
                }
                else {
                    dx = 0;
                    dy = -l[i].c;
                }
                Union(ra, rb, vx[l[i].a] - vx[l[i].b] + dx, vy[l[i].a] - vy[l[i].b] + dy);
            }
            while (pos <= m && q[pos].c < i) ++pos;
            while (pos <= m && q[pos].c == i) {
                ra = Find(q[pos].a);
                rb = Find(q[pos].b);
                if (ra != rb) ans[q[pos].id] = -1;
                else ans[q[pos].id] = __abs(vx[q[pos].a] - vx[q[pos].b]) + __abs(vy[q[pos].a] - vy[q[pos].b]);
                ++pos;
            }
            if (pos > m) break;
        }
        for (int i = 1; i <= m; ++i) printf("%d\n", ans[i]);
    }
    return 0;
}
