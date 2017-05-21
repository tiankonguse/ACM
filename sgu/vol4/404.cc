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
char str[maxn][maxn];

int main() {
    int m, n;
    while (~scanf("%d%d", &m, &n)) {
        for (int i = 0; i < n; ++i) {
            scanf(" %s", str[i]);
        }
        int ret = m % n - 1;
        if (ret == -1) ret = n - 1;
        printf("%s\n", str[ret]);
    }
    return 0;
}
