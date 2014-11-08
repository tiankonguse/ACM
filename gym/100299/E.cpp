#include <cstdio>
#include <vector>
#include <set>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> PLL;
typedef multiset <PLL> MS;
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define foreach(it,v) for (__typeof((v).end()) it = (v).begin(); it != (v).end(); it++)
const int N = 200005;
const ll INF = 1e15;
int Tc, n, m;
vector <int> E[N];
MS pool[N];
ll a[N];

MS* merge(MS *a, MS *b) {
    if (a->size() < b->size()) swap(a, b);
    foreach (it, *b) a->insert(*it);
    b->clear();
    return a;
}

MS* dfs(int u, int fa) {
    MS *res = &pool[u];
    rep (i, E[u].size())
        if (E[u][i] != fa)
            res = merge(dfs(E[u][i], u), res);
    PLL cur = a[u] > 0 ? PLL(0, a[u]) : PLL(-a[u], 0);
    while (!res->empty() && (cur.second < cur.first || cur.second >= res->begin()->first)) {
        PLL tmp = *res->begin();
        res->erase(res->begin());
        cur = tmp.first > cur.second ? PLL(cur.first - cur.second + tmp.first, tmp.second) : PLL(cur.first, cur.second - tmp.first + tmp.second);
    }
    if (cur.second > cur.first) res->insert(cur);
    return res;
}

int main() {
    scanf("%d", &Tc);
    while (Tc--) {
        scanf("%d%d", &n, &m);
        rep (i, n + 1) E[i].clear();
        rep (i, n) {
            int x;
            scanf("%d", &x);
            a[i] = x;
        }
        rep (i, n - 1) {
            int u, v;
            scanf("%d%d", &u, &v);
            u--; v--;
            E[u].push_back(v);
            E[v].push_back(u);
        }
        --m;
        E[m].push_back(n);
        E[n].push_back(m);
        a[n++] = INF;
        MS *res = dfs(0, -1);
        ll hp = 0;
        bool flag = 0;
        foreach (it, *res) if (hp >= it->first) {
            hp += it->second - it->first;
            if (hp >= INF / 2) flag = 1;
        }
        res->clear();
        puts(flag ? "escaped" : "trapped");
    }
    return 0;
}