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

const int N = 1 << 7;

int n, m, full;
bool f[26][N];
vector <string> rules[26];
vector <int> Q[26];

int getLength(int mask) {
    return 31 - __builtin_clz(mask);
}

int concat(int prefix, int suffix) {
    int len = getLength(suffix);
    while (getLength(prefix) < m && --len >= 0) {
        prefix = prefix << 1 | !!(suffix & 1 << len);
    }
    return prefix;
}

string toString(int mask) {
    string s;
    for (int i = getLength(mask) - 1; i >= 0; i--)
        s += mask & 1 << i ? '1' : '0';
    return s;
}

bool isFinal(char c) {
    return c == '0' || c == '1';
}

bool isFinal(char *s) {
    for (; *s; s++)
        if (!isFinal(*s))
            return 0;
    return 1;
}

bool setValue(int n, int mask) {
    if (!f[n][mask]) {
        f[n][mask] = 1;
        Q[n].push_back(mask);
        return 1;
    } else {
        return 0;        
    }
}

void BellmanFord() {
    while (1) {
        bool changed = 0;
        rep (i, 26) rep (j, rules[i].size()) {
            static bool g[15][N];
            memset(g[0], 0, sizeof(bool) * full);
            g[0][1] = 1;
            string &r = rules[i][j];
            rep (k, r.size()) {
                memset(g[k + 1], 0, sizeof(bool) * full);
                if (isFinal(r[k])) {
                    rep (mask, full) if (g[k][mask]) {
                        g[k + 1][concat(mask, r[k] == '0' ? 2 : 3)] = 1;
                    }
                } else {
                    rep (mask, full) if (g[k][mask]) {
                        foreach (it, Q[r[k] - 'A']) {
                            g[k + 1][concat(mask, *it)] = 1;
                        }
                    }
                }
            }
            rep (mask, full) if (g[r.size()][mask] && setValue(i, mask)) {
                changed = 1;
            }
        }
        if (!changed) break;
    }
}

int main() {
    freopen("valid.in", "r", stdin);
    freopen("valid.out", "w", stdout);
    static char buf[1000];
    gets(buf);
    sscanf(buf, "%d%d", &n, &m);
    full = 1 << (m + 1);
    rep (i, 26) Q[i].clear();
    rep (_, n) {
        gets(buf);
        if (isFinal(buf + 3)) {
            char *s = buf + 3;
            int len = strlen(s);
            int mask = 1;
            rep (i, min(len, m))
                mask = concat(mask, s[i] == '0' ? 2 : 3);
            setValue(buf[0] - 'A', mask);
        } else {
            rules[buf[0] - 'A'].push_back(buf + 3);
        }
    }
    BellmanFord();
    vector <string> ans;
    foreach (it, Q['S' - 'A']) ans.push_back(toString(*it));
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    foreach (it, ans)
        cout << (it->empty() ? "eps" : *it) << "\n";
    return 0;
}