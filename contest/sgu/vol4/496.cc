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
#define maxn 5050
using namespace std;
struct node {
    int x1, y1, x2, y2;
} p[maxn];

int cal(int x1, int y1, int x2, int y2, int x3, int y3) {
    int _x1 = x2 - x1, _y1 = y2 - y1;
    int _x2 = x3 - x1, _y2 = y3 - y1;
    return _x1 * _x2 + _y1 * _y2;
}
int main() {
    int n;
    int x1, y1, x2, y2, x3, y3, x4, y4;
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d%d", &p[i].x1, &p[i].y1, &p[i].x2, &p[i].y2);
        }
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                x1 = p[i].x1, y1 = p[i].y1, x2 = p[i].x2, y2 = p[i].y2;
                x3 = p[j].x1, y3 = p[j].y1, x4 = p[j].x2, y4 = p[j].y2;
                if (x1 == x3 && y1 == y3) {
                    ret += cal(x1, y1, x2, y2, x4, y4) == 0;
                }
                else if (x1 == x4 && y1 == y4) {
                    ret += cal(x1, y1, x2, y2, x3, y3) == 0;
                }
                else if (x2 == x3 && y2 == y3) {
                    ret += cal(x2, y2, x1, y1, x4, y4) == 0;
                }
                else if (x2 == x4 && y2 == y4) {
                    ret += cal(x2, y2, x1, y1, x3, y3) == 0;
                }
            }
        }
        printf("%d\n", ret);
    }
    return 0;
}
