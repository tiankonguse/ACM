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
#include <bitset>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define maxn 601
using namespace std;
struct line1 {
    int y, x1, x2;
    line1(int _y, int _x1, int _x2) { y = _y, x1 = _x1, x2 = _x2;}
    line1() {}
    bitset<maxn> bit;
} p1[maxn];
struct line2 {
    int x, y1, y2;
    line2(int _x, int _y1, int _y2) { x = _x, y1 = _y1, y2 = _y2;}
    line2() {}
} p2[maxn];

inline bool cross(line1 a, line2 b) {
    if (a.y >= b.y1 && a.y <= b.y2 &&
        b.x >= a.x1 && b.x <= a.x2) return true;
    else return false;
}
int main() {
    int n;
    int x1, y1, x2, y2;
    int c1, c2;
    int ret;
    while (~scanf("%d", &n)) {
        c1 = c2 = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            if (x1 > x2) swap(x1, x2);
            if (y1 > y2) swap(y1, y2);
            if (y1 == y2) {
                p1[c1++] = line1(y1, x1, x2);
            }
            else {
                p2[c2++] = line2(x1, y1, y2);
            }
        }
        for (int i = 0; i < c1; ++i) {
            for (int j = 0; j < c2; ++j) {
                if (cross(p1[i], p2[j])) {
                    p1[i].bit[j] = 1;
                }
            }
        }
        ret = 0;
        int t;
        for (int i = 0; i < c1; ++i) {
            for (int j = i + 1; j < c1; ++j) {
                t = (p1[i].bit & p1[j].bit).count();
                ret += t * (t - 1) / 2;
            }
        }
        printf("%d\n", ret);
    }
    return 0;
}
