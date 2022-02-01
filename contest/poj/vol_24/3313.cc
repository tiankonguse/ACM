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
#include <ctime>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL

using namespace std;
int l, c, n;
int dat[1515][18];
int _all[33000][18], ac;
int rul[11][18];
char str[18];
int B[11], W[11];
int cnt;
int tmp[18];
int ca[22], cb[22];


inline bool check() {
    int b, w;
    for (int i = 0; i < n; ++i) {
        b = w = 0;
        memset(ca, 0, sizeof ca);
        memset(cb, 0, sizeof cb);
        for (int j = 0; j < l; ++j) {
            if (rul[i][j] == tmp[j]) ++b;
            else {
                ++ca[rul[i][j]];
                ++cb[tmp[j]];
            }
        }
        for (int j = 0; j < c; ++j) {
            w += min(ca[j], cb[j]);
        }
        if (b != B[i] || w != W[i]) return false;
    }
    return true;
}
void dfs(int d) {
    if (d == l) {
        tmp[d] = 0;
        if (check()) {
            for (int i = 0; i < l; ++i) dat[cnt][i] = tmp[i];
            ++cnt;
        }
        for (int i = 0; i < l; ++i) _all[ac][i] = tmp[i];
        ++ac;
        return;
    }
    for (int i = 0; i < c; ++i) {
        tmp[d] = i;
        dfs(d + 1);
    }
}

int mp[22][22];


int main() {
    int T;
    for (scanf("%d", &T); T--; ) {
        scanf("%d%d%d", &l, &c, &n);
        for (int i = 0; i < n; ++i) {
            scanf(" %s %d %d", str, &B[i], &W[i]);
            for (int j = 0; j < l; ++j) {
                rul[i][j] = str[j] - 'A';
            }
        }
        cnt = ac = 0;
        dfs(0);
//        for (int i = 0; i < cnt; ++i) {
//            for (int j = 0; j < l; ++j) {
//                putchar('A' + dat[i][j]);
//            }
//            puts("");
//        }

        int ret = inf, ch = -1;
        for (int i = 0; i < ac; ++i) {
            memset(mp, 0, sizeof mp);
            for (int j = 0; j < cnt; ++j) {
                memset(ca, 0, sizeof ca);
                memset(cb, 0, sizeof cb);
                int b = 0, w = 0;
                for (int k = 0; k < l; ++k) {
                    if (_all[i][k] == dat[j][k]) ++b;
                    else {
                        ++ca[_all[i][k]];
                        ++cb[dat[j][k]];
                    }
                }
                for (int k = 0; k < c; ++k) {
                    w += min(ca[k], cb[k]);
                }
                if (b == l) continue;
                ++mp[b][w];
            }
            int mx = 0;
            for (int j = 0; j <= l; ++j) {
                for (int k = 0; k <= l; ++k) {
                    mx = max(mx, mp[j][k]);
                }
            }
            if (mx < ret) {
                ret = mx;
                ch = i;
            }
        }
        for (int i = 0; i < l; ++i) {
            putchar('A' + _all[ch][i]);
        }
        printf(" %d\n", ret);
    }
    return 0;
}
