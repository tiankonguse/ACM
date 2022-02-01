#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <string>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define foreach(it,v) for (__typeof((v).end()) it = (v).begin(); it != (v).end(); it++)
typedef long long ll;
typedef pair <int, int> PII;
const int N = 105;
int m, n, p;
int ans;
int a[N][N], b[N][N];
bitset <100> c[N];
bitset <100> row;
bitset <100> mask;
int v[N];

int calc(int m) {
    int cnt = 0;
    rep (j, n) {
        cnt += min(v[j], m - v[j]);
    }
    return cnt;
}

void dfs(int i) {
    int res = calc(i);
    if (res >= ans) return;
    if (i == m) {
        ans = res;
        return;
    }
    if (!i) {
        row = c[i];
        dfs(i + 1);
    } else {
        {
            rep (j, n) if (row[j] != c[i][j]) v[j]++;
            dfs(i + 1);
            rep (j, n) if (row[j] != c[i][j]) v[j]--;
        }
        {
            row = row.flip();
            rep (j, n) if (row[j] != c[i][j]) v[j]++;
            dfs(i + 1);
            rep (j, n) if (row[j] != c[i][j]) v[j]--;
            row = row.flip();
        }
    }
}

int main() {
    scanf("%d%d%d", &m, &n, &p);
    ans = p + 1;
    rep (i, m) {
        rep (j, n) {
            scanf("%d", &a[i][j]);
        }
    }
    if (m > n) {
        rep (i, m) rep (j, n) {
            b[j][m - i - 1] = a[i][j];
        }
        swap(m, n);
        memcpy(a, b, sizeof(a));
    }
    mask.reset();
    rep (j, n) mask[j] = 1;
    rep (i, m) {
        c[i].reset();
        rep (j, n) {
            c[i][j] = a[i][j];
        }
    }
    dfs(0);
    if (ans > p) {
        puts("-1");
    } else {
        printf("%d\n", ans);
    }
}

