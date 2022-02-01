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
const int N = 1000005;
int n, m, Tc;
vector <int> E[N];

int main() {
    scanf("%d", &Tc);
    rep (ri, Tc) {
        printf("Case %d: ", ri + 1);
        scanf("%d", &n);
        rep (i, n) E[i].clear();
        rep (i, n - 1) {
            int u, v;
            scanf("%d%d", &u, &v);
            u--;
            v--;
            E[u].push_back(v);
            E[v].push_back(u);
        }
        scanf("%d", &m);
        rep (i, m - 1) {
            int u, v;
            scanf("%d%d", &u, &v);
            u--;
            v--;
        }
        if (m >= 4) {
            puts("YES");
        } else if (m == 3) {
            bool ok = 1;
            rep (i, n) if (E[i].size() > 2) {
                ok = 0;
            }
            puts(ok ? "YES" : "NO");
        } else {
            puts("NO");
        }
    }
}