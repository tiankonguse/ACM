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
#define maxn 10
#define maxl 100
using namespace std;
char dat[maxn][maxl];
char str[maxl], pat[maxl];
int ext[maxl], ex[maxl];
int la, lb;
void extkmp(char *str, char *pat, int ext[], int ex[]) {
    int p = 0, k = 1;
    while (pat[p] == pat[p + 1]) ++p;
    ext[0] = lb, ext[1] = p;
    for (int i = 2; i < lb; ++i) {
        int x = k + ext[k] - i, y = ext[i - k];
        if (y < x) ext[i] = y;
        else {
            p = max(0, x);
            while (pat[p] == pat[p + i]) ++p;
            ext[i] = p;
            k = i;
        }
    }
    p = k = 0;
    while (str[p] && str[p] == pat[p]) ++p;
    ex[0] = p;
    for (int i = 1; i < la; ++i) {
        int x = k + ex[k] - i, y = ext[i - k];
        if (y < x) ex[i] = y;
        else {
            p = max(0, x);
            while (pat[p] && pat[p] == str[p + i]) ++p;
            ex[i] = p;
            k = i;
        }
    }
}
int a[maxn];
int main() {
    int n;
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; ++i) {
            scanf(" %s", dat[i]);
            a[i] = i;
        }
        int ret = inf;
        do {
            la = 0;
            for (int i = 0; i < n; ++i) {
                lb = strlen(dat[ a[i] ]);
                for (int j = 0; j < lb; ++j) pat[j] = dat[ a[i] ][j];
                pat[lb] = 0;
                str[la] = 0;
                extkmp(str, pat, ext, ex);
                int pos = la;
                for (int j = 0; j < la; ++j) {
                    if (ex[j] + j >= la) {
                        pos = j;
                        break;
                    }
                }
                for (int j = 0; j < lb; ++j) {
                    str[pos++] = pat[j];
                }
                la = pos;
            }
            ret = min(ret, la);

        } while (next_permutation(a, a + n));
        printf("%d\n", ret);
    }
    return 0;
}
