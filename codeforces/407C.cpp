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
const int N = 100005;
const int Mod = 1000000007;
int n, m;
int f[N][105];
int C[N][105];
int a[N];

void add(int &t, int x) {
    t += x;
    if (t >= Mod) t -= Mod;
}

int main() {
    rep (i, N) rep (j, min(i + 1, 101))
        C[i][j] = !i || !j ? 1 : (C[i - 1][j] + C[i - 1][j - 1]) % Mod;
    scanf("%d%d", &n, &m);
    rep (i, n) {
        scanf("%d", &a[i]);
    }
    rep (i, m) {
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        l--;
        int len = r - l;
        for (int j = 0; j <= k; j++) {
            add(f[l][j], C[k][k - j]);
            add(f[r][j], (Mod - C[k + len][k - j]) % Mod);
        }
    }
    rep (i, n) {
        rep (j, 101) {
            add(f[i + 1][j], f[i][j]);
            add(f[i + 1][j], f[i][j + 1]);
        }
    }
    rep (i, n) {
        add(a[i], f[i][0]);
        printf("%d ", a[i]);
    }
    puts("");
}

