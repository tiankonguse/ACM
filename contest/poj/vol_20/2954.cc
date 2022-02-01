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
inline int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}
int Xmul(int x1, int y1, int x2, int y2) {
    return x1 * y2 - x2 * y1;
}
int main() {
    int x1, y1, x2, y2, x3, y3;
    while (~scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3)) {
        if (x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0 && x3 == 0 && y3 == 0) break;
        int x12 = x2 - x1, y12 = y2 - y1;
        int x13 = x3 - x1, y13 = y3 - y1;
        int x23 = x3 - x2, y23 = y3 - y2;
        int S = abs( Xmul(x12, y12, x13, y13) / 2);
        int L = abs(gcd(x12, y12)) + abs(gcd(x13, y13)) + abs(gcd(x23, y23));
        int ret = S + 1 - L / 2;
        printf("%d\n", ret);
    }
    return 0;
}
