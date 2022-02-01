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
double dis(double x1, double y1, double x2, double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
int main() {
	double x1, y1, x2, y2, x3, y3;
	while (~scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3)) {
		double a = dis(x1, y1, x2, y2);
		double b = dis(x1, y1, x3, y3);
		double c = dis(x2, y2, x3, y3);
		double r2 = 0.5 * (a - b + c);
		double r3 = c - r2;
		double r1 = a - r2;
		printf("%.10lf\n%.10lf\n%.10lf\n", r1, r2, r3);
	}
    return 0;
}
