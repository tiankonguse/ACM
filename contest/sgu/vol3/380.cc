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
int h[maxn];
int main() {
    int n;
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &h[i]);
        }
        int minL = 0, maxL = 0, minR = 0, maxR = 0;
        int p1 = 0, p2 = n - 1;
        bool flag = true;
        while (p1 < p2) {
            minL = min(minL, h[p1]);
            maxL = max(maxL, h[p1]);
            minR = min(minR, h[p2]);
            maxR = max(maxR, h[p2]);
            bool f = false;
            if (minL <= h[p2] && maxL >= h[p2]) {
                --p2;
                f = true;
            }
            if (minR <= h[p1] && maxR >= h[p1]) {
                ++p1;
                f = true;
            }
            if (!f) { flag = false; break; }
        }
        puts(flag ? "YES" : "NO");
    }
    return 0;
}
