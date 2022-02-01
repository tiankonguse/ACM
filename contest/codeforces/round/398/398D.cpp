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
#include <unordered_set>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define foreach(it,v) for (auto it = (v).begin(); it != (v).end(); it++)
typedef long long ll;
typedef pair <int, int> PII;
typedef vector <int> VI;
#define SET unordered_set
const int BS = 800;
const int BS2 = 1000;
const int N = 50005;
struct Query P{
    char o;
    int x, y;
}Q[250005];
int n, m, q;
vector < pair <int, bool> > E[N], big[N];
int SZ[N];
int ans[N];
bool on[N];

void rebuild() {
    rep (i, n) {
        SZ[i] = E[i].size();
        big[i].clear();
        ans[i] = 0;
    }
    rep (i, n) foreach (it, E[i]) {
        int v = *it;
        VI lhs, rhs;
        if (SZ[v] > BS) {
            lhs.push_back(v);
        } else {
            rhs.push_back(v);
            if (SZ[i] > BS)
                ans[i] += on[v];
        }
        big[i] = VI(lhs.begin(), lhs.end());
    }
}

void addOn(int x) {
    on[x] = 1;
    if (SZ[x] <= BS) {
        VI &s = big[x];
        foreach (it, s) {
            ans[*it]++;
        }
    }
}

void addOff(int x) {
    on[x] = 0;
    if (SZ[x] <= BS) {
        VI &s = big[x];
        foreach (it, s) {
            ans[*it]--;
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &q);
    int num, x;
    scanf("%d", &num);
    rep (i, num) {
        scanf("%d", &x);
        x--;
        on[x] = 1;
    }
    rep (i, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--; v--;
        E[u].insert(v);
        E[v].insert(u);
    }
    rebuild();
    rep (i, q) {
        static char buf[10];
        scanf("%s", buf);
        Q[i].o = buf[0];
        Q[i].read();
        int x, y;
        if (buf[0] == 'O') {
            scanf("%d", &x);
            addOn(--x);
        } else if (buf[0] == 'F') {
            scanf("%d", &x);
            addOff(--x);
        } else if (buf[0] == 'A') {
            scanf("%d%d", &x, &y);
            x--; y--;
            assert(!E[x].count(y));
            E[x].insert(y);
            E[y].insert(x);
            if (SZ[y] > BS) {
                big[x].push_back(y);
            } else {
                if (SZ[x] > BS)
                    ans[x] += on[y];
            }
            if (SZ[x] > BS) {
                big[y].push_back(x);
            } else {
                if (SZ[y] > BS)
                    ans[y] += on[x];
            }
            ++cnt;
            if (cnt >= BS2) {
                rebuild();
                cnt = 0;
            }
        } else if (buf[0] == 'D') {
            scanf("%d%d", &x, &y);
            x--; y--;
        } else if (o == 'C') {
            scanf("%d", &x);
        }
    }
    int cnt = 0;
    rep (_, q) {
        static char buf[10];
        scanf("%s", buf);
        int x, y;
        if (buf[0] == 'O') {
            scanf("%d", &x);
            addOn(--x);
        } else if (buf[0] == 'F') {
            scanf("%d", &x);
            addOff(--x);
        } else if (buf[0] == 'A') {
            scanf("%d%d", &x, &y);
            x--; y--;
            assert(!E[x].count(y));
            E[x].insert(y);
            E[y].insert(x);
            if (SZ[y] > BS) {
                big[x].push_back(y);
            } else {
                if (SZ[x] > BS)
                    ans[x] += on[y];
            }
            if (SZ[x] > BS) {
                big[y].push_back(x);
            } else {
                if (SZ[y] > BS)
                    ans[y] += on[x];
            }
            ++cnt;
            if (cnt >= BS2) {
                rebuild();
                cnt = 0;
            }
        } else if (buf[0] == 'D') {
            scanf("%d%d", &x, &y);
            x--; y--;
            assert(E[x].count(y));
            E[x].erase(y);
            E[y].erase(x);
            if (SZ[y] > BS) {
                auto t = find(big[x].begin(), big[x].end(), y);
                if (t != big[x].end())
                    big[x].erase(t);
            } else {
                if (SZ[x] > BS)
                    ans[x] -= on[y];
            }
            if (SZ[x] > BS) {
                auto t = find(big[y].begin(), big[y].end(), x);
                if (t != big[y].end())
                    big[y].erase(t);
            } else {
                if (SZ[y] > BS)
                    ans[y] -= on[x];
            }
            ++cnt;
            if (cnt >= BS2) {
                rebuild();
                cnt = 0;
            }
        } else if (buf[0] == 'C') {
            int x;
            scanf("%d", &x);
            x--;
            if (SZ[x] > BS) {
                int base = ans[x];
                VI &s = big[x];
                foreach (it, s) {
                    base += on[*it];
                }
                printf("%d\n", base);
            } else {
                SET <int> &s = E[x];
                int base = 0;
                foreach (it, s) {
                    base += on[*it];
                }
                printf("%d\n", base);
            }
        } else {
            //assert(0);
        }
    }
}

