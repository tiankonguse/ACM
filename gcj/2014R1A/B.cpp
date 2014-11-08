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
const int N = 1005;
const int INF = N;
int Tc, n;
vector <int> E[N], E2[N];
int f[N][2][2][2];
int fa[N];

void dfs(int u, int f) {
    fa[u] = f;
    rep (i, E[u].size()) {
        int v = E[u][i];
        if (v == f) continue;
        E2[u].push_back(v);
        dfs(v, u);
    }
}

int dp(int u, bool hasTwo, bool exist, bool fExist) {
    int &res = f[u][hasTwo][exist][fExist];
    if (res != -1) return res;
    res = -INF;
    if (hasTwo) res = max(res, dp(u, !hasTwo, exist, fExist));
    if (!exist) {
        int cur = 0;
        rep (i, E[u].size()) {
            int v = E[u][i];
            cur += max(dp(v, 1, 0, 0), dp(v, 1, 1, 0));
        }
        return res = max(res, cur);
    } else {
        rep (degree, 4) {
            if (degree < fExist) continue;
            if (degree == 2 && !hasTwo) continue;
            int decision = degree - fExist;
            int cur = 1;
            if (decision == 0) {
                rep (i, E[u].size()) {
                    int v = E[u][i];
                    cur += dp(v, 1, 0, 1);
                }
            } else if (decision == 1) {
                int sum = 1;
                rep (i, E[u].size()) {
                    int v = E[u][i];
                    sum += dp(v, 1, 0, 1);
                }
                rep (i, E[u].size()) {
                    int v = E[u][i];
                    cur = max(cur, sum - dp(v, 1, 0, 1) + dp(v, hasTwo && (degree != 2), 1, 1));
                }
            } else if (decision == 2) {
                int sum = 1;
                rep (i, E[u].size()) {
                    int v = E[u][i];
                    sum += dp(v, 1, 0, 1);
                }
                rep (i, E[u].size()) {
                    int v0 = E[u][i];
                    rep (j, i) {
                        int v1 = E[u][j];
                        cur = max(cur, sum - dp(v0, 1, 0, 1) + dp(v0, hasTwo && (degree != 2), 1, 1) - dp(v1, 1, 0, 1) + dp(v1, 0, 1, 1));
                        cur = max(cur, sum - dp(v1, 1, 0, 1) + dp(v1, hasTwo && (degree != 2), 1, 1) - dp(v0, 1, 0, 1) + dp(v0, 0, 1, 1));
                    }
                }

            } else if (decision == 3) {
                int sum = 1;
                rep (i, E[u].size()) {
                    int v = E[u][i];
                    sum += dp(v, 1, 0, 1);
                }
                rep (i, E[u].size()) {
                    int v0 = E[u][i];
                    rep (j, i) {
                        int v1 = E[u][j];
                        rep (k, j) {
                            int v2 = E[u][k];
                            int tmp = sum - dp(v0, 1, 0, 1) - dp(v1, 1, 0, 1) - dp(v2, 1, 0, 1);
                            cur = max(cur, tmp + dp(v0, hasTwo && (degree != 2), 1, 1) + dp(v1, 0, 1, 1) + dp(v2, 0, 1, 1));
                            cur = max(cur, tmp + dp(v1, hasTwo && (degree != 2), 1, 1) + dp(v0, 0, 1, 1) + dp(v2, 0, 1, 1));
                            cur = max(cur, tmp + dp(v2, hasTwo && (degree != 2), 1, 1) + dp(v0, 0, 1, 1) + dp(v1, 0, 1, 1));
                        }
                    }
                }
            }
            if (cur > res) res = cur;
        }
    }
    return res;
}

int main() {
    freopen("in", "r", stdin);
    cin >> Tc;
    rep (ri, Tc) {
        scanf("%d", &n);
        rep (i, n) E[i].clear(), E2[i].clear();
        memset(f, 0xff, sizeof(f));
        rep (i, n - 1) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            E[u].push_back(v);
            E[v].push_back(u);
        }
        dfs(0, -1);
        rep (i, n) E[i] = E2[i];
        int rhs = max(dp(0, 1, 0, 0), dp(0, 1, 1, 0));
        cout << n - rhs << endl;
    }
}

