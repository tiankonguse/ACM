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
#define maxn 111
using namespace std;
int score[maxn];

int main() {
    int n, m;
    int a, b;
    int ga, gb;
    while (~scanf("%d%d", &n, &m)) {
        memset(score, 0, sizeof score);
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &a, &b);
            for (int j = 0; j < n; ++j) {
                scanf("%d%d", &ga, &gb);
                if ((a < b && ga < gb) || (a == b && ga == gb) || (a > b && ga > gb)) score[j] += 2;
                if (a - b == ga - gb) score[j] += 3;
                if (a == ga) score[j]++;
                if (b == gb) score[j]++;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (i == n - 1) printf("%d\n", score[i]);
            else printf("%d ", score[i]);
        }
    }
    return 0;
}
