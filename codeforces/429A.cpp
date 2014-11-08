#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair <int, int> PII;
const int N = 1e5 + 5;
int n;
int a[N], b[N];
vector <int> ans;
vector <int> E[N];

void dfs(int u, int fa, int dep, int ceven, int codd) {
    int cur = a[u] ^ ( dep == 0 ? ceven : codd );
    if (cur != b[u]) {
        ans.push_back(u + 1);
        if (dep == 0) {
            ceven ^= 1;
        } else {
            codd ^= 1;
        }
    }
    for (int v : E[u]) {
        if (v == fa) continue;
        dfs(v, u, dep ^ 1, ceven, codd);
    }
}

int main() {
    scanf("%d", &n);
    rep (i, n - 1) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--; v--;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    rep (i, n) scanf("%d", &a[i]);
    rep (i, n) scanf("%d", &b[i]);
    dfs(0, -1, 0, 0, 0);
    cout << ans.size() << "\n";
    for (int x : ans) {
        cout << x << "\n";
    }
    return 0;
}

