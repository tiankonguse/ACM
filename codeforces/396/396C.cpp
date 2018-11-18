#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <bitset>
#include <string>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define foreach(it,v) for (__typeof((v).end()) it = (v).begin(); it != (v).end(); it++)
typedef long long ll;
typedef pair <int, int> PII;
const int N = 300005;
const int Mod = 1000000007;
int n, times;
int order[N];
int st[N], ed[N], depth[N], a[N];
vector <int> E[N];

struct Node {
    int l, r;
    int tag;
    int delta;
    Node(){}
    Node(int left, int right): l(left), r(right) {
        tag = 0;
        delta = 0;
    }
}Tr[N * 4];

void dfs(int u) {
    ++times;
    order[times] = u;
    st[u] = times;
    rep (i, E[u].size()) {
        int v = E[u][i];
        depth[v] = depth[u] + 1;
        dfs(v);
    }
    ed[u] = times;
}

void build(int p, int l, int r) {
    Tr[p] = Node(l, r);
    if (l < r) {
        int mid = (l + r) / 2;
        build(p * 2, l, mid);
        build(p * 2 + 1, mid + 1, r);
    }
}

void addv(int &t, int x) {
    t += x;
    if (t >= Mod) t-= Mod;
}

void add(int p, int l, int r, int v) {
    if (l <= Tr[p].l && Tr[p].r <= r) {
        addv(Tr[p].delta, v);
    } else {
        int mid = (Tr[p].l + Tr[p].r) / 2;
        if (l <= mid) add(p * 2, l, r, v);
        if (r >  mid) add(p * 2 + 1, l, r, v);
    }
}

void addTag(int p, int l, int r, int v) {
    if (l <= Tr[p].l && Tr[p].r <= r) {
        addv(Tr[p].tag, v);
    } else {
        int mid = (Tr[p].l + Tr[p].r) / 2;
        if (l <= mid) addTag(p * 2, l, r, v);
        if (r >  mid) addTag(p * 2 + 1, l, r, v);
    }
}

void pushdown(int p) {
    if (Tr[p].l == Tr[p].r) {
        int i = Tr[p].l;
        addv(a[i], Tr[p].delta);
        addv(a[i], (Mod - depth[order[i]] * (ll)Tr[p].tag % Mod) % Mod);
    } else {
        addv(Tr[p * 2].tag, Tr[p].tag);
        addv(Tr[p * 2].delta, Tr[p].delta);
        addv(Tr[p * 2 + 1].tag, Tr[p].tag);
        addv(Tr[p * 2 + 1].delta, Tr[p].delta);
    }
    Tr[p].tag = Tr[p].delta = 0;
}

void query(int p, int i) {
    pushdown(p);
    if (Tr[p].l == Tr[p].r) return;
    int mid = (Tr[p].l + Tr[p].r) / 2;
    if (i <= mid) 
        query(p * 2, i);
    else
        query(p * 2 + 1, i);
}

int main() {
    scanf("%d", &n);
    rep (i, n - 1) {
        int x;
        scanf("%d", &x);
        E[x].push_back(i + 2);
    }
    times = 0;
    depth[1] = 1;
    dfs(1);
    build(1, 1, n);
    int Q;
    scanf("%d", &Q);
    rep (_, Q) {
        int t, v, x, k;
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d%d%d", &v, &x, &k);
            x %= Mod;
            k %= Mod;
            add(1, st[v], ed[v], (x + (ll)(k) * depth[v]) % Mod);
            addTag(1, st[v], ed[v], k);
        } else {
            scanf("%d", &v);
            query(1, st[v]);
            printf("%d\n", a[st[v]]);
        }
    }
}