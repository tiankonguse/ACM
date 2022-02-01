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

int main() {
	double x, y, z;
	scanf("%lf %lf %lf", &x, &y, &z);
	double t = (y - x) * 60.0;
	double v = t * t;
	double s = (t - z) * (t - z);
	printf("%.7lf\n", (v - s) / v);
	return 0;
}
