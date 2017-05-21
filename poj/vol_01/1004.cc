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

int main() {
    double a, s = 0;
    while (~scanf("%lf", &a)) s += a;
    printf("$%.2lf\n", s / 12.0);
    return 0;
}
