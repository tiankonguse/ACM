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
#define maxn 7
#define maxm 20
using namespace std;
int const n = 6;
int m, red, x0;
int var[maxm];
char mp[maxn][maxn];
int chset[128];
inline bool check(int x, int y) { return x >= 0 && x < 6 && y >= 0 && y < 6; }
struct hs {
    int v[maxm];
    friend bool operator < (hs a, hs b) {
        for (int i = 0; i < m; ++i) {
            if (a.v[i] != b.v[i]) return a.v[i] < b.v[i];
        }
        return 0;
    }
} ht;
map <hs, int> s;
struct node {
    int x1[maxm], y1[maxm], x2[maxm], y2[maxm];
    int t;
} tmp, nmp;
queue <node> q;

inline void __copy() {
    for (int i = 0; i < m; ++i) {
        if (var[i] == 0) ht.v[i] = tmp.x1[i];
        else ht.v[i] = tmp.y1[i];
    }
}

inline void __copy_back(int t, int c) {
    for (int i = 0; i < m; ++i) {
        if (i == c) continue;
        nmp.x1[i] = tmp.x1[i];
        nmp.y1[i] = tmp.y1[i];
        nmp.x2[i] = tmp.x2[i];
        nmp.y2[i] = tmp.y2[i];
    }
    nmp.t = t;
}
inline bool __checkOK(int x, int y, int id) {
    for (int i = 0; i < m; ++i) {
        if (i == id) continue;
        if (tmp.x1[i] <= x && x <= tmp.x2[i] && tmp.y1[i] <= y && y <= tmp.y2[i]) return false;
    }
    return true;
}
inline bool __checkWIN() {
    int yl = tmp.y2[red] + 1;
    for (int i = 0; i < m; ++i) {
        if (i == red) continue;
        if (var[i] == 1) {
            if (tmp.x1[i] == x0 && tmp.y1[i] >= yl) return false;
        }
        else {
            if (tmp.y1[i] >= yl && tmp.x1[i] <= x0 && x0 <= tmp.x2[i]) return false;
        }
    }
    return true;
}
int bfs() {
    while (!q.empty()) q.pop();
    s.clear();
    for (int i = 0; i < m; ++i) {
        tmp.x1[i] = tmp.y1[i] = +inf;
        tmp.x2[i] = tmp.y2[i] = -inf;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mp[i][j] != '.') {
                int id = chset[ mp[i][j] ];
                tmp.x1[id] = min(i, tmp.x1[id]);
                tmp.y1[id] = min(j, tmp.y1[id]);
                tmp.x2[id] = max(i, tmp.x2[id]);
                tmp.y2[id] = max(j, tmp.y2[id]);
            }
        }
    }
    tmp.t = 1;
    q.push(tmp);
    __copy();
    s[ht] = 1;
//    for (int i = 0; i < m; ++i) {
//        printf("(%d, %d) -> (%d, %d)\n", tmp.x1[i], tmp.y1[i], tmp.x2[i], tmp.y2[i]);
//    }
    int tx1, ty1, tx2, ty2;
    while (!q.empty()) {
        tmp = q.front(); q.pop();
        if (__checkWIN()) return tmp.t;
        for (int i = 0; i < m; ++i) {
            if (var[i] == 0) {
                //up
                __copy();
                tx1 = tmp.x1[i], ty1 = tmp.y1[i];
                tx2 = tmp.x2[i], ty2 = tmp.y2[i];
                --tx1, --tx2; // move one step
                while (tx1 >= 0 && __checkOK(tx1, ty1, i)) {
                    --ht.v[i];
                    if (s.find(ht) == s.end()) {
                        s[ht] = tmp.t + 1;
                        __copy_back(tmp.t + 1, i);
                        nmp.x1[i] = tx1, nmp.x2[i] = tx2;
                        nmp.y1[i] = ty1, nmp.y2[i] = ty2;
                        q.push(nmp);
                    }
                    else if (s[ht] < tmp.t + 1) break;
                    --tx1, --tx2;

                }
                //down
                __copy();
                tx1 = tmp.x1[i], ty1 = tmp.y1[i];
                tx2 = tmp.x2[i], ty2 = tmp.y2[i];
                ++tx1, ++tx2;
                while (tx2 < n && __checkOK(tx2, ty2, i)) {
                    ++ht.v[i];
                    if (s.find(ht) == s.end()) {
                        s[ht] = tmp.t + 1;
                        __copy_back(tmp.t + 1, i);
                        nmp.x1[i] = tx1, nmp.x2[i] = tx2;
                        nmp.y1[i] = ty1, nmp.y2[i] = ty2;
                        q.push(nmp);
                    }
                    else if (s[ht] < tmp.t + 1) break;
                    ++tx1, ++tx2;

                }
            }
            else {

                //left
                __copy();
                tx1 = tmp.x1[i], ty1 = tmp.y1[i];
                tx2 = tmp.x2[i], ty2 = tmp.y2[i];
                --ty1, --ty2;
                while (ty1 >= 0 && __checkOK(tx1, ty1, i)) {
                    --ht.v[i];
                    if (s.find(ht) == s.end()) {
                        s[ht] = tmp.t + 1;
                        __copy_back(tmp.t + 1, i);
                        nmp.x1[i] = tx1, nmp.x2[i] = tx2;
                        nmp.y1[i] = ty1, nmp.y2[i] = ty2;
                        q.push(nmp);
                    }
                    else if (s[ht] < tmp.t + 1) break;
                    --ty1, --ty2;

                }
                //right
                __copy();
                tx1 = tmp.x1[i], ty1 = tmp.y1[i];
                tx2 = tmp.x2[i], ty2 = tmp.y2[i];
                ++ty1, ++ty2;
                while (ty2 < n && __checkOK(tx2, ty2, i)) {
                    ++ht.v[i];
                    if (s.find(ht) == s.end()) {
                        s[ht] = tmp.t + 1;
                        __copy_back(tmp.t + 1, i);
                        nmp.x1[i] = tx1, nmp.x2[i] = tx2;
                        nmp.y1[i] = ty1, nmp.y2[i] = ty2;
                        q.push(nmp);
                    }
                    else if (s[ht] < tmp.t + 1) break;
                    ++ty1, ++ty2;

                }

            }
        }
    }
    return -1;
}
int main() {
    int T, ca = 1;
    bool begin = true;
    while (~scanf("%d", &m) && m ) {
        for (int i = 0; i < 6; ++i) scanf(" %s", mp[i]);
        m = 0;
        memset(chset, 0xff, sizeof chset);
        memset(var, 0xff, sizeof var);
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 6; ++j) {
                if (mp[i][j] != '.' && chset[ mp[i][j] ] == -1) {
                    int id = m++;
                    chset[ mp[i][j] ] = id;
                    if (mp[i][j] == 'x') {
                        red = id;
                        x0 = i;
                    }
                    if (check(i - 1, j) && mp[i - 1][j] == mp[i][j]) var[id] = 0;
                    else if (check(i + 1, j) && mp[i + 1][j] == mp[i][j]) var[id] = 0;
                    else if (check(i, j - 1) && mp[i][j - 1] == mp[i][j]) var[id] = 1;
                    else if (check(i, j + 1) && mp[i][j + 1] == mp[i][j]) var[id] = 1;
                }
            }
        }

        int ret = bfs();
        if (ret == -1) printf("You are trapped in scenario #%d.\n", ca++);
        else printf("Scenario #%d requires %d moves.\n", ca++, ret);
    }
    return 0;
}
