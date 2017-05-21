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
double const eps = 1e-8;

double f(double a, double b, double c) {
  return sqrt(b * c * ((b + c) * (b + c) - a * a)) / (b+c);
}

int main() {
  double h, d, m;
  scanf("%lf%lf%lf", &h, &d, &m);
  if (d < h) {
    puts("NO");
    return 0;
  } else if (d == h) {
    if (d == m) {
      puts("YES");
      printf("%.8lf %.8lf\n", 0., h);
      puts("-1 0\n1 0");
    } else {
      puts("NO");
    }
    return 0;
  } else if (d == m) {
    puts("NO");
    return 0;
  }
  double x = sqrt(m * m - h * h);
  double low = 0, high = 1e8, mid, ans = -1;
  rep(i, 100) {
    mid = (high + low) * 0.5;
    double a = mid * 2.0;
    double b = sqrt((x - mid) * (x - mid) + h * h);
    double c = sqrt((x + mid) * (x + mid) + h * h);
    double k = f(a, b, c);
    if (fabs(k - d) < eps) {
      ans = mid;
      break;
    } else if (k < d) {
      high = mid;
    } else low = mid;
  }
  if (ans < 0) {
    puts("NO");
  } else {
    puts("YES");
    printf("%.8lf %.8lf\n", 0., h);
    printf("%.8lf %.8lf\n", x - ans, 0.);
    printf("%.8lf %.8lf\n", x + ans, 0.);
  }
  return 0;
}
