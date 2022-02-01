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
#define maxn 222
#define maxm 88888
using namespace std;
struct node {
    double x, y;
    node (double _x, double _y) { x = _x, y = _y; }
    node () {}
} point[maxn];

struct edges {
    int u, next;
    double c;
} e[maxm];

int n;
int p[maxn], idx;
void init() {
    idx = 0;
    memset(p, 0xff, sizeof p);
}
void addedge(int u, int v, double c) {
//    printf("add(%d, %d, %.2lf)\n", u, v, c);
    e[idx].u = v;
    e[idx].c = c;
    e[idx].next = p[u];
    p[u] = idx++;
}

queue <int> q;
bool used[maxn];
double dist[maxn];

double spfa() {
    int t, u; double w;
    while (!q.empty()) q.pop();
    memset(used, false, sizeof used);
    fill(dist, dist + n, 1e10);
    dist[0] = 0;
    q.push(0);
    while (!q.empty()) {
        t = q.front();
        q.pop();
        used[t] = false;
        for (int i = p[t]; i != -1; i = e[i].next) {
            u = e[i].u;
            w = e[i].c;
            if (dist[t] + w < dist[u]) {
                dist[u] = dist[t] + w;
                if (!used[u]) {
                    used[u] = true;
                    q.push(u);
                }
            }
        }
    }
    return dist[1];
}

inline double dis(double x1, double y1, double x2, double y2) {
    return sqrt( (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) );
}
inline double cal1(double x1, double y1, double x2, double y2) {
    return dis(x1, y1, x2, y2) * 60.0 / 10000.0;
}
inline double cal2(double x1, double y1, double x2, double y2) {
    return dis(x1, y1, x2, y2) * 60.0 / 40000.0;
}
int main() {
    init();
    int cnt = 2;
    double x, y, xp = -1, yp = -1, t;
    scanf("%lf%lf%lf%lf", &point[0].x, &point[0].y, &point[1].x, &point[1].y);

    while (~scanf("%lf %lf", &x, &y)) {
        if (x != -1 && y != -1) {
            point[cnt] = node(x, y);
            if (xp != -1 && yp != -1) {
                t = cal2(xp, yp, x, y);
                addedge(cnt - 1, cnt, t);
                addedge(cnt, cnt - 1, t);
            }
            ++cnt;
        }
        xp = x;
        yp = y;
    }

    for (int i = 0; i < cnt; ++i) {
        for (int j = 0; j < cnt; ++j) {
            if (i == j) continue;
            t = cal1(point[i].x, point[i].y, point[j].x, point[j].y);
            addedge(i, j, t);
            addedge(j, i, t);
        }
    }
    n = cnt;
    printf("%.0lf\n", spfa());
    return 0;
}
