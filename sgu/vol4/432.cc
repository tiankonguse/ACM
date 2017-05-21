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
#define maxn 1111
using namespace std;
char str[maxn][maxn];
char res[maxn][maxn];
int split[maxn], snt;
struct node {
    int pos, t;
    node (int _pos, int _t) { pos = _pos, t = _t; }
    node () {}
} p[maxn];
int pnt;

char tmp[11];
char const no[4][10] = {
    "is",
    "are"
};
int const noLen[2] = {2, 3};
char const can[5][10] = {
    "can",
    "may",
    "must",
    "should"
};
int const canLen[4] = {3, 3, 4, 6};

int check(char *s) {
    int len = strlen(s);
    if (s[len - 1] == '.') return 0;

    for (int i = 0; i < 2; ++i) {
        if (len == noLen[i]) {
            bool flag = true;
            for (int j = 0; j < len; ++j) {
                if (tolower(s[j]) != no[i][j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) return 1;
        }
    }
    for (int i = 0; i < 4; ++i) {
        if (len == canLen[i]) {
            bool flag = true;
            for (int j = 0; j < len; ++j) {
                if (tolower(s[j]) != can[i][j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) return 2;
        }
    }
    return -1;
}

int checkEnd(char *s) {
    int len = strlen(s) - 1;
    for (int i = 0; i < 2; ++i) {
        if (len == noLen[i]) {
            bool flag = true;
            for (int j = 0; j < len; ++j) {
                if (tolower(s[j]) != no[i][j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) return 1;
        }
    }
    for (int i = 0; i < 4; ++i) {
        if (len == canLen[i]) {
            bool flag = true;
            for (int j = 0; j < len; ++j) {
                if (tolower(s[j]) != can[i][j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) return 2;
        }
    }
    return -1;
}

char const athe[3][10] = {
    "a",
    "the"
};
int const aLen[3] = {1, 3};
bool checkA(char *s) {
    int len = strlen(s);
    if (s[len - 1] == '.') --len;
    for (int i = 0; i < 2; ++i) {
        if (len == aLen[i]) {
            bool flag = true;
            for (int j = 0; j < len; ++j) {
                if (tolower(s[j]) != athe[i][j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) return true;
        }
    }
    return false;
}

int st[maxn], ed[maxn];
int main() {
    int n = 0;
    split[0] = 0; snt = 1; pnt = 0;
    while (~scanf(" %s", str[n])) ++n;

    int g, gg;
    for (int i = 0; i < n; ++i) {
        g = check(str[i]);
        if (g == 0) {
            split[snt++] = i + 1;
            gg = checkEnd(str[i]);
            if (gg == 1) p[pnt++] = node(i, 3);
            else if (gg == 2) p[pnt++] = node(i, 4);
        }
        else if (g == 1) p[pnt++] = node(i, 1);
        else if (g == 2) p[pnt++] = node(i, 2);
    }
    for (int i = 1; i < snt; ++i) {
        for (int j = split[i - 1]; j < split[i]; ++j) {
            st[j] = split[i - 1];
            ed[j] = split[i];
        }
    }
    printf("%d\n", pnt);
    for (int i = 0; i < pnt; ++i) {
        int pos = p[i].pos;
        for (int j = st[pos]; j < ed[pos]; ++j) {
            if (j != ed[pos] - 1) printf("%s ", str[j]);

            if (j == p[i].pos) {
                if (p[i].t == 1) {
                    printf("no");
                    if (checkA(str[j + 1])) {
                        if (j + 1 == ed[pos] - 1) puts(".");
                        else putchar(' ');
                        ++j;
                        continue;
                    }
                    else putchar(' ');
                }
                else if (p[i].t == 2) {
                    printf("not ");
                }
                else if (p[i].t == 3) {
                    int lt = strlen(str[j]);
                    for (int k = 0; k < lt - 1; ++k) putchar(str[j][k]);
                    printf(" no.\n");
                    continue;
                }
                else if (p[i].t == 4) {
                    int lt = strlen(str[j]);
                    for (int k = 0; k < lt - 1; ++k) putchar(str[j][k]);
                    printf(" not.\n");
                    continue;
                }
            }
            if (j == ed[pos] - 1) printf("%s\n", str[j]);

        }
    }
    return 0;
}
