#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <ctime>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
using namespace std;
typedef long long ll;
double const pi = atan2(0.0, -1.0);
double const co = sqrt(3.0) / 6.0;
double const eps = 1e-10;
inline double p4(double x) { return x * x * x * x; }
inline double p2(double x) { return x * x; }
int main() {
	double a, b, c, p, A, B, C, Z;
	while (~scanf("%lf %lf %lf", &a, &b, &c)) {
		Z = sqrt(p4(a) + p4(b) + p4(c) - p2(a) * p2(b) - p2(b) * p2(c) - p2(c) * p2(a));
		A = sqrt(p2(a) + p2(b) + p2(c) + Z + Z) / 6.0;
		B = sqrt(p2(a) + p2(b) + p2(c) - Z - Z) / 6.0;
		C = sqrt(max(A * A - B * B, 0.0));
		printf("%.10lf %.10lf\n", C + C, A);
	}
	return 0;
}
