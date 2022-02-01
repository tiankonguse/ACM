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
#define maxn 65536
#define maxm 131072

using namespace std;
int mx;
struct edges {
    int u, next;
} e[maxm];
int p[maxn], idx;
void init() {
    idx = 0;
    memset(p, 0xff, sizeof p);
}
void addedge(int u, int v) {
    e[idx].u = v;
    e[idx].next = p[u];
    p[u] = idx++;
}

char res[maxn];
bool used[maxn];

bool dfs(int u, int d) {
 //   printf("dfs(%d, %d)\n", u, d);
    int v;
    res[d] = u % 2 + '0';
    if (d == mx - 1) return true;
    used[u] = true;
    for (int i = p[u]; i != -1; i = e[i].next) {
        v = e[i].u;
        if (!used[v]) {
            if (dfs(v, d + 1)) return true;
        }
    }
    used[u] = false;
    return false;
}

void solve(int n) {
    mx = 1 << n;
    int msk = mx - 1, nxt;
    init();
    for (int i = 0; i < mx; ++i) {
        for (int j = 1; j >= 0; --j) {
            nxt = ((i << 1) | j) & msk;
            addedge(i, nxt);
//            printf("add(%d, %d)\n", i, nxt);
        }
    }
    memset(used, false, sizeof used);

    dfs(0, 0);
    res[mx] = 0;
  //  puts(res);
}
int main() {
    int n, k;
    while (scanf("%d%d", &n, &k) && n + k) {
        solve(n);
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            ret <<= 1;
            ret |= (res[(i + k - n + 1) % mx] == '1');
        }
        printf("%d\n", ret);
    }
    return 0;
}
