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
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define Rep(i, n) for (int i = 1; i <= (n); ++i)
#define clr(x, a) memset(x, (a), sizeof x)
using namespace std;
typedef long long ll;
int const N = 1000100;
double a[N];

int main() {
	int n; scanf("%d", &n);
	rep(i, n) scanf("%lf", &a[i]);
	double ret = 0; rep(i, n) ret += a[i];
	printf("%.10lf\n", ret / n);
    return 0;
}

