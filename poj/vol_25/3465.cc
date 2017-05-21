#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>

#define inf 0x3f3f3f3f
#define INF 0x3FFFFFFFFFFFFFFFLL
using namespace std;
priority_queue<int> q;

int main() {
    int n, x, y, h, h1, h2, a, t;
    while (~scanf("%d%d%d%d%d", &n, &x, &y, &h1, &h2)) {
        h = h2;
        while (!q.empty()) q.pop();
        bool flag = false;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a);
            if (flag) continue;
            h2 -= x;
            h1 -= a;
            q.push(a);
            if (h2 <= 0) {
                flag = true;
                printf("Win\n%d\n", i + 1);
                continue;
            }
            if (i == n - 1) break;
            while (h1 <= 0) {
                t = q.top();
                q.pop();
                h1 += max(t, y);
                h2 += x;
            }
        }
        if (!flag) {
            printf("Lose\n%d\n", h - h2);
        }
    }
    return 0;
}
