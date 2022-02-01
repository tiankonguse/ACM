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
#define maxn 1010
using namespace std;
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
char str[maxn][maxn];
int h[maxn];
int calHeight(int id) {
    int l1 = strlen(str[id]);
    int l2 = strlen(str[id + 1]);
    int l = min(l1, l2);
    for (int i = 0; i < l; ++i) {
        if ((str[id][i] != '#' && str[id][i] != '*') || str[id][i] != str[id + 1][i]) return i;
    }
    return l;
}
int st[maxn], top;

void printWord(int id) {
    if (st[top] > 0) {
        puts("<li>");
        for (int j = st[top]; str[id][j]; ++j) putchar(str[id][j]); puts("");
        puts("</li>");
    }
    else {
        for (int j = st[top]; str[id][j]; ++j) putchar(str[id][j]); puts("");
    }
}
int main() {
    int n = 0;
    while (~scanf(" %s", str[n])) ++n;
    for (int i = 0; i + 1 < n; ++i) h[i] = calHeight(i);
    //pv(h, h + n - 1);
    st[top = 0] = 0;
    for (int i = 0; i < n; ++i) {
        if (h[i] > st[top]) {
            for (int j = st[top] + 1; j <= h[i]; ++j) {
                if (j - 1 > 0) puts("<li>");
                if (str[i][j - 1] == '*') puts("<ul>");
                else if (str[i][j - 1] == '#') puts("<ol>");
                st[++top] = j;
            }
            printWord(i);
        }
        else if (h[i] == st[top]) {
            printWord(i);
        }
        else if (h[i] < st[top]) {
            printWord(i);
            while (h[i] != st[top]) {
                if (str[i][ st[top] - 1 ] == '*') puts("</ul>");
                else if (str[i][ st[top] - 1 ] == '#') puts("</ol>");
                if (st[top] - 1 > 0) puts("</li>");
                --top;
            }
        }


    }
    return 0;
}
