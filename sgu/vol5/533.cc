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

using namespace std;

int main() {
    int n, h, m;
    while (~scanf("%d", &n)) {
        if (n == 21) puts("1");
        else if (n >= 30) {
            h = n / 14;
            m = n % 14;
            if (m >= 2 && m <= 12) printf("%d\n", h);
            else puts("-1");
        }
        else puts("-1");
    }
    return 0;
}
