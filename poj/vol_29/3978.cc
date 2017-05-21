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
int mark[maxn];
int pri[maxn], cnt;
void sieve() {
    cnt = 0;
    for (int i = 2; i < maxn; ++i) {
        if (!mark[i]) pri[cnt++] = i;
        for (int j = 0; j < cnt && pri[j] * i < maxn; ++j) {
            mark[i * pri[j]] = 1;
            if (i % pri[j] == 0) break;
        }
    }
}
int main() {
    sieve();
    for (int i = 2; i <= 100000; ++i) mark[i] = mark[i - 1] + !mark[i];
    int a, b;
    while (~scanf("%d%d", &a, &b) && (a != -1 || b != -1)) {
        a = max(a, 1), b = max(b, 1);
        printf("%d\n", mark[b] - mark[a - 1]);
    }

    return 0;
}
