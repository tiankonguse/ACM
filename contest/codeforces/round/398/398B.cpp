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
uSETng namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define foreach(it,v) for (__typeof((v).end()) it = (v).begin(); it != (v).end(); it++)
typedef long long ll;
typedef pair <int, int> PII;
const int N = 2005;
int n;
double f[N][N];

double rec(int i, int j) {
    if (i == 0 && j == 0) return 0;
    double &res = f[i][j];
    if (res >= 0) return res;
    res = 0;
    if (i > 0)
        res += (i * (n - j)) / (double)(n * n) * rec(i - 1, j);
    if (j > 0)
        res += j * (n - i) / (double)(n * n) * rec(i, j - 1);
    if (i && j)
        res += (i * j) / (double)(n * n) * rec(i - 1, j - 1);
    res++;
    res /= 1 - (n - i) * (n - j) / (double)(n * n);
    return res;
}

int main() {
    int m;
    scanf("%d%d", &n, &m);
    set <int> sx, sy;
    rep (i, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        sx.insert(u);
        sy.insert(v);
    }
    rep (i, N) rep (j, N) f[i][j] = -1;
    int lc = 0, rc = 0;
    rep (i, n) if (!sx.count(i + 1)) lc++;
    rep (i, n) if (!sy.count(i + 1)) rc++;
    printf("%.12f\n", rec(lc, rc));
    return 0;
}

