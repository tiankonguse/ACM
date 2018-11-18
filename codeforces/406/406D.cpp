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
int n;
ll x[N], y[N];
int fa[N][17];
int depth[N];

bool cmp(ll x0, ll y0, ll x1, ll y1, ll x2, ll y2) {
    return (y2 - y0) * (ll)(x1 - x0)  > (y1 - y0) * (ll)(x2 - x0);
}

int getLca(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);
    for (int k = 16; depth[u] != depth[v] && ~k; k--) {
        if (depth[fa[v][k]] >= depth[u]) {
            v = fa[v][k];
        }
    }
    if (u == v) return u;
    for (int k = 16; ~k; k--) {
        if (fa[u][k] != fa[v][k]) {
            u = fa[u][k];
            v = fa[v][k];
        }
    }
    return fa[u][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    rep (i, n) cin >> x[i] >> y[i];
    static int Q[N];
    int qh = 0, qt = 1;
    Q[0] = n - 1;
    fa[n - 1][0] = n - 1;
    depth[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {
        while (qh + 1 < qt && cmp(x[i], y[i], x[Q[qt - 1]], y[Q[qt - 1]], x[Q[qt - 2]], y[Q[qt - 2]])) {
            qt--;
        }
        fa[i][0] = Q[qt - 1];
        depth[i] = depth[Q[qt - 1]] + 1;
        Q[qt++] = i;
    }
    rep (k, 16) rep (i, n) {
        fa[i][k + 1] = fa[fa[i][k]][k];
    }
    int m;
    cin >> m;
    rep (_, m) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        int lca = getLca(u, v);
        cout << lca + 1 << " ";
    }
    cout << endl;
}

