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
#define maxn 4040
using namespace std;
int p[maxn][2];
struct lines {
    int x1, y1, x2, y2;
    int v, leng;
    void print() {
        printf("(%d, %d) -> (%d, %d) : %d\n", x1, y1, x2, y2, v);
    }
} l[maxn];
inline int __abs(int x) {
    return x > 0 ? x : -x;
}
inline int __dis(int x1, int y1, int x2, int y2) {
    return __abs(x1 - x2) + __abs(y1 - y2);
}
inline bool __cross(lines a, lines b, int &x, int &y) {
    if (a.v == b.v) {
        if (a.x2 == b.x1 && a.y2 == b.y1) {
            x = b.x1, y = b.y1;
            return true;
        }
        else if (a.x2 == b.x2 && a.y2 == b.y2) {
            x = b.x2, y = b.y2;
            return true;
        }
        else return false;
    }
    else if (a.v == 0 && b.v == 1) {
        if (b.x1 >= min(a.x1, a.x2) && b.x1 <= max(a.x1, a.x2) &&
            a.y1 >= min(b.y1, b.y2) && a.y1 <= max(b.y1, b.y2)) {
                x = b.x1, y = a.y1;
                return true;
            }
        else return false;
    }
    else if (a.v == 1 && b.v == 0) {
        if (a.x1 >= min(b.x1, b.x2) && a.x1 <= max(b.x1, b.x2) &&
            b.y1 >= min(a.y1, a.y2) && b.y1 <= max(a.y1, a.y2)) {
                x = a.x1, y = b.y1;
                return true;
            }
        else return false;
    }
    return false;
}
int main() {
    int n;
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; ++i) {
            scanf("%d %d", &p[i][0], &p[i][1]);
        }
        int ret = 0;
        for (int i = 1; i < n; ++i) {
            l[i].x1 = p[i - 1][0], l[i].y1 = p[i - 1][1];
            l[i].x2 = p[i][0], l[i].y2 = p[i][1];
            if (l[i].y1 == l[i].y2) l[i].v = 0;
            else l[i].v = 1;
            l[i].leng = __dis(l[i].x1, l[i].y1, l[i].x2, l[i].y2);
            ret += l[i].leng;
        }
        int cx, cy, s;
        for (int i = 1; i < n; ++i) {
            s = l[i].leng;
            if (i >= 2) s += l[i - 1].leng;
            bool flag = false;
            for (int j = i - 2; s < ret && j >= 1; --j) {
                if (__cross(l[i], l[j], cx, cy)) {
                    s += __dis(cx, cy, l[j].x2, l[j].y2);
                    s -= __dis(cx, cy, l[i].x2, l[i].y2);
                    flag = true;
                    break;
                }
                else {
                    s += l[j].leng;
                }
            }
            if (flag) ret = min(ret, s);
        }
        printf("%d\n", ret);
    }
    return 0;
}
