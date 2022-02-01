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
#define maxn 1000010
using namespace std;
int mark[11][maxn];

int main() {
    int x, y;
    while (~scanf("%d %d", &x, &y)) {
        x %= y;
        if (x == 0) { puts("0 0"); continue; }
        memset(mark, 0xff, sizeof mark);
        int t, r0, r1;
        for (int i = 0; ; ++i) {
            x *= 10;
            t = x / y;
            x %= y;
            if (x == 0) { r0 = i + 1, r1 = 0; break; }
            if (mark[t][x] == -1) mark[t][x] = i;
            else {
                r0 = mark[t][x];
                r1 = i - mark[t][x];
                break;
            }
        }
       printf("%d %d\n", r0, r1);
    }
    return 0;
}
