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
#define maxn 10010
using namespace std;
int res[maxn];
int fun(int n) {
    int cnt = 0;
    for (int i = 2; i * i <= n; i += 2) {
        while (n % i == 0) {
            n /= i;
            ++cnt;
        }
        if (i == 2) --i;
    }
    if (n > 1) ++cnt;
    return cnt + 1;
}
int main() {
    int n;
    while (~scanf("%d", &n)) {
        int mx = 0;
        for (int i = 1; i <= n; ++i) {
            res[i] = fun(i);
            mx = max(mx, res[i]);
        }
        printf("%d\n", mx);
        for (int i = 1; i <= n; ++i) {
            if (i == n) printf("%d\n", res[i]);
            else printf("%d ", res[i]);
        }
    }
    return 0;
}
