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
#define maxn 100100
#define maxl 101
#define maxd 11
using namespace std;
char name[maxl], addr[maxl];
char str[maxl];
int cnt[maxd];
void cal(int n) {
    while (n) {
        ++cnt[n % 10];
        n /= 10;
    }
}
int main() {
    int T;
    int n, m;
    int a, b, c;
    for (scanf("%d", &T); T--; ) {
        getchar(); gets(name);
        scanf(" %d %s", &n, addr);
        memset(cnt, 0, sizeof cnt);
        m = 0;
        while (~scanf(" %s", str)) {
            if (str[0] == '+') {
                scanf("%d %d %d", &a, &b, &c);
                for (int i = a; i <= b; i += c) {
                    cal(i);
                    ++m;
                }
            }
            else {
                sscanf(str, "%d", &a);
                cal(a);
                ++m;
            }
            if (m == n) break;
        }
        puts(name);
        printf("%d %s\n", n, addr);
        int s = 0;
        for (int i = 0; i < 10; ++i) {
            printf("Make %d digit %d\n", cnt[i], i);
            s += cnt[i];
        }
        printf("In total %d digit", s);
        if (s > 1) puts("s");
        else puts("");

    }
    return 0;
}
