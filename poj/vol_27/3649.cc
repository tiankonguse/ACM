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
#define maxn 22
#define maxh 22
#define maxw 550
using namespace std;
struct node {
    char mp[maxh][maxw];
    int w;
    int begin[maxh], end[maxh];
} p[maxn];
char buf[maxw];
char res[maxh][maxw];
int mark[maxh];

int main() {
    int n, _ca = 1;
    int cnt, len, pos;
    while (~scanf("%d", &n) && n) {
        getchar();
        cnt = 0;
        for (int i = 0; i < n; ++i) {
            gets(buf);
            len = strlen(buf);
            buf[len++] = ' ';
            pos = 0;
            cnt = 0;
            for (int j = 0; j < len; ++j) {
                if (buf[j] == ' ') {
                    p[cnt].mp[i][p[cnt].w = pos] = 0;
                    pos = 0;
                    ++cnt;
                }
                else {
                    p[cnt].mp[i][pos++] = buf[j];
                }
            }
        }
        for (int i = 0; i < cnt; ++i) {
            for (int j = 0; j < n; ++j) {
                p[i].begin[j] = p[i].end[j] = -1;
                for (int k = 0; k < p[i].w; ++k) {
                    if (p[i].mp[j][k] == '#' || p[i].mp[j][k] == '0') {
                        if (p[i].begin[j] == -1) p[i].begin[j] = k;
                        p[i].end[j] = k;
                    }
                }
            }
        }
//        for (int i = 0; i < cnt; ++i) {
//            for (int j =0; j < n; ++j) {
//                puts(p[i].mp[j]);
//            }
//        }
        for (int i = 0; i < n; ++i) {
            mark[i] = 20;
            fill(res[i], res[i] + 400, '.');
        }

        int mx;
        for (int i = 0; i < cnt; ++i) {
            mx = 0;
            for (int j = 0; j < n; ++j) {
                if (p[i].begin[j] != -1) {
                    mx = max(mx, mark[j] + 2 - p[i].begin[j]);
                }
            }
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < p[i].w; ++k) {
                    if (p[i].mp[j][k] == '#') res[j][k + mx] = '#';
                    else if (res[j][k + mx] != '#') res[j][k + mx] = '.';
                }
            }
            for (int j = 0; j < n; ++j) {
                if (p[i].begin[j] == -1) {
                    if (i == 0) mark[j] = 0;
                }
                else {
                    mark[j] = max(mark[j], p[i].end[j] + mx);
                }
            }
        }
        int _begin = 0, _end = 0;
        for (int i = 0; i < n; ++i) _end = max(_end, mark[i]);
        bool f1 = false, f2 = false;
        for (int j = 0; j <= _end; ++j) {
            for (int i = 0; i < n; ++i) {
                if (res[i][j] == '#') {
                    _begin = j;
                    f1 = true;
                    break;
                }
            }
            if (f1) break;
        }
        for (int j = _end; j >= _begin; --j) {
            for (int i = 0; i < n; ++i) {
                if (res[i][j] == '#') {
                    _end = j;
                    f2 = true;
                    break;
                }
            }
            if (f2) break;
        }
        printf("%d\n", _ca++);
        for (int i = 0; i < n; ++i) {
            for (int j = _begin; j <= _end; ++j) {
                putchar(res[i][j]);
            }
            puts("");
        }
    }
    return 0;
}
