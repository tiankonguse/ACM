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
#define maxh 40400
#define maxn 404
using namespace std;
struct node {
    int h, a, c;
    friend bool operator < (node x, node y) {
        return x.a < y.a;
    }
} p[maxn];

bool dp[maxh];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", &p[i].h, &p[i].a, &p[i].c);
    }
    sort(p, p + n);
    memset(dp, false, sizeof dp);
    dp[0] = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < p[i].c; ++j) {
            for (int k = p[i].a; k - p[i].h >= 0; --k) {
                if (dp[k - p[i].h]) {
                    dp[k] = true;
                }
            }
        }
    }
    for (int i = p[n - 1].a; i >= 0; --i) {
        if (dp[i]) {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}
