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
int main() {
    int n, m;
    double ret;
    while (~scanf("%d%d", &n, &m)) {
        ret = 0;
        for (int i = 0; i < m; ++i) {
            ret += (n - ret) / n;
        }
        printf("%.11lf\n", ret);
    }
    return 0;
}
