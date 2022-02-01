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

using namespace std;
typedef long long ll;
double const pi = acos(-1.0);

int main() {
    int T, ca = 1;
    double x, y;
    for (scanf("%d", &T); T--; ) {
        scanf("%lf %lf", &x, &y);
        int ret = (int)(ceil(pi * (x * x + y * y) * 0.01));
        printf("Property %d: This property will begin eroding in year %d.\n", ca++, ret);
    }
    puts("END OF OUTPUT.");
    return 0;
}
