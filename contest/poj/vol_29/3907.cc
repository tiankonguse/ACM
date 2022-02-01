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
int const maxn = 123456;
struct Point {
    double x, y;
} p[maxn];
int main() {
	int n;
	while (~scanf("%d", &n) && n) {
		for (int i = 0; i < n; ++i) scanf("%lf %lf", &p[i].x, &p[i].y);
		if (n <= 2) {
			puts("0"); 
			continue; 
		}
		p[n] = p[0];
		double ret = 0;
		for (int i = 0; i < n; ++i) {
			ret += p[i].x * p[i + 1].y - p[i].y * p[i + 1].x;
		}
		printf("%.0lf\n", fabs(ret * 0.5));
	}
    return 0;
}
