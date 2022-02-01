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
int a[10], s[10];
int main() {
    int n, m;
    int x, y;
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 1; i <= n; ++i) {
            a[i] = 100;
            s[i] = 0;
        }
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &x, &y);
            if (a[x] <= 0) continue;
            if (a[y] > 0) s[x] += 3;
            a[y] -= 8;
        }
        for (int i = 1; i <= n; ++i) {
            if (a[i] > 0) s[i] += a[i] / 2;
        }
        for (int i = 1; i <= n; ++i) {
            printf("%d %d\n", a[i], s[i]);
        }
    }
    return 0;
}
