#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define maxm 8192
#define maxn 14
#define maxh 1600000
using namespace std;
int pop[maxn];
char _mp[maxn][maxn];
bool mp[maxn][maxn];
int pops[maxm];
int neigh[maxm]; bool mark[maxn];
int n, mx;

struct HashMap{
    int p[maxh], v[maxh], next[maxh], idx;
    int dp[maxh];
    void init(){
        idx = 0;
        memset(p, 0xff, sizeof p);
    }
    int query(int u) {
        int x = u % maxh;
        for (int i = p[x]; ~i; i = next[i]) {
            if (v[i] == u) return dp[i];
        }
        return -1;
    }
    void insert(int u, int val){
        int x = u % maxh;
        dp[idx] = val;
        v[idx] = u;
        next[idx] = p[x];
        p[x] = idx++;
    }
} h[2];
void printbin(int n) {
    int num[30];
    for (int i = 0; i < 10; ++i) {
        num[i] = n % 2;
        n >>= 1;
    }
    for (int i = 10 - 1; i >= 0; --i) {
        printf("%d", num[i]);
    }
    puts("");
}
int dfs(int state, int player, bool flag) {
    int sa = state & (mx - 1);
    int sb = state >> n;
    if ((sa | sb) == mx - 1) {
        if (player == 0) return pops[sa] - pops[sb];
        else return pops[sb] - pops[sa];
    }
    int tmp = h[player].query(state);
    if (tmp != -1) return tmp;
    int ret = -inf;
    for (int i = 1; i < mx; ++i) {
        if (!(i & sa) && !(i & sb)) {
            if (player == 0) {
                if (pops[sa & neigh[i]] > pops[i] + pops[neigh[i] & sb]) {
                    ret = max(ret, -dfs((sa | i) | (sb << n), 1, true));
                }
            }
            else {
                if (pops[sb & neigh[i]] > pops[i] + pops[neigh[i] & sa]) {
                    ret = max(ret, -dfs(sa | ((sb | i) << n), 0, true));
                }
            }
        }
    }
    if (ret == -inf) {
        if (!flag) {
            if (player == 0) return pops[sa] - pops[sb];
            else return pops[sb] - pops[sa];
        }
        else ret = max(ret, -dfs(state, player ^ 1, false));
    }
    h[player].insert(state, ret);
    return ret;
}




int main() {
    int s, t;
    while (~scanf("%d%d%d", &n, &s, &t)) {
        --s, --t;
        for (int i = 0; i < n; ++i) {
            scanf(" %s", _mp[i]);
            for (int j = 0; j < n; ++j) {
                mp[i][j] = (_mp[i][j] == '1');
            }
        }
        for (int i = 0; i < n; ++i) scanf("%d", &pop[i]);
        mx = 1 << n;
        memset(pops, 0, sizeof pops);
        for (int i = 0; i < mx; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    pops[i] += pop[j];
                }
            }
        }
        memset(neigh, 0, sizeof neigh);
        for (int i = 0; i < mx; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    for (int k = 0; k < n; ++k) {
                        if (!(i & (1 << k)) && mp[j][k]) {
                            neigh[i] |= (1 << k);
                        }
                    }
                }
            }
        }
        h[0].init(), h[1].init();
        int ini_state = (1 << s) | (mx << t);
        printf("%d\n", dfs(ini_state, 0, true));
    }
    return 0;
}

