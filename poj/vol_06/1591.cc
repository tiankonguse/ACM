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
#define maxn 52
using namespace std;
int a[maxn];
int num[maxn];
int main() {
    int n, m, _ca = 1;
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 0; i < 20; ++i) scanf("%d", &a[i]);
        for (int i = 1; i <= n; ++i) num[i] = i;
        int rmd = n;
        for (int i = 0; i < 20; ++i) {
            int pos = 1, t = a[i];
            while (pos <= n) {
                if (num[pos] == -1) ++pos;
                else {
                    --t;
                    if (t == 0) {
                        num[pos] = -1;
                        --rmd;
                        t = a[i];
                        if (rmd == m) goto next;
                    }
                    ++pos;
                }
            }
        }
        next:;
        bool begin = true;
        printf("Selection #%d\n", _ca++);
        for (int i = 1; i <= n; ++i) {
            if (num[i] != -1) {
                if (!begin) putchar(' ');
                begin = false;
                printf("%d", i);
            }
        }
        puts("\n");
    }
    return 0;
}
