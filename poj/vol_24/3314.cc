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
#define maxn 111
#define maxw 12
using namespace std;
int res[maxn];

int up[maxw];

int n, w, b, h;
char mp[maxn][maxw];
char board[maxn][maxw];
void init(int w, int b) {
    for (int i = 0; i < b; ++i) {
        for (int j = 0; j < w; ++j) {
            board[i][j] = '.';
        }
    }
}
bool put(int p, int h) {
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (mp[i][j] == 'X' && board[p - i][j] == 'X') {
                return false;
            }
        }
    }
    return true;
}
void pp(int p, int h) {
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            board[p - i][j] = mp[i][j];
        }
    }
}
void print() {
    for (int i = b - 1; i >= 0; --i) {
        puts(board[i]);
    }
    puts("");
}
int calH() {
    int ret = 0;
    for (int i = 0; i < w; ++i) {
        up[i] = 0;
        for (int j = b - 1; j >= 0; --j) {
            if (board[j][i] == 'X') break;
            else ++up[i];
        }
        ret = max(ret, b - up[i]);
    }
    return ret;
}
int main() {
    int cnt;
    while (~scanf("%d%d%d", &n, &w, &b)) {
        if (n == 0 && w == 0 && b == 0) break;
        cnt = 0;
        init(w, b);

        for (int i = 0; i < n; ++i) {
            scanf("%d", &h);
            for (int j = 0; j < h; ++j) {
                scanf(" %s", mp[j]);
            }
            int p = -1;
            for (int j = b - 1; j >= h - 1; --j) {
                if (put(j, h)) {
                    p = j;
                }
                else break;
            }
            if (p != -1) pp(p, h);
            else {
                res[cnt++] = calH();
                init(w, b);
                for (int j = b - 1; j >= h - 1; --j) {
                    if (put(j, h)) {
                        p = j;
                    }
                    else break;
                }
                pp(p, h);
            }
//            print();
        }
        res[cnt] = calH();
        if (res[cnt] == 0) --cnt;
        for (int i = 0; i <= cnt; ++i) {
            if (i == cnt) printf("%d\n", res[i]);
            else printf("%d ", res[i]);
        }
    }
    return 0;
}
