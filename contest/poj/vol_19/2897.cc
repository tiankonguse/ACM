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
bool mark[10][10];
int ans[111];
int solve(int n, int k) {
    int len = 0;
    int p = k, q = 0, pp, r;
    memset(mark, 0, sizeof mark);
    while (1) {
        r = p * n + q;
        pp = p;
        p = r % 10;
        q = r / 10;
        ans[len++] = p;
        if (p == k && q == 0) {
            if (pp == 0) return -1;
            else return len;
        }
        else if (mark[p][q]) return -1;
        mark[p][q] = true;
    }
    return -1;
}
int main() {
    int T, n, k;
    for (scanf("%d", &T); T--; ) {
        scanf("%d%d", &n, &k);
        int ret = solve(n, k);
        if (ret != -1) {
            for (int i = ret - 2; i >= 0; --i) printf("%d", ans[i]);
            printf("%d\n", k);
        }
        else puts("0");
    }
    return 0;
}
