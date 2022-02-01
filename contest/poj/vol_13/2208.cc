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
//AB, AC, AD, CD, BD, BC.
double calc(double a, double b, double c, double r, double p, double q)
{
    a *= a, b *= b, c *= c, r *= r, p *= p, q *= q;
    double P1 = a * p * (-a + b + c - p + q + r);
    double P2 = b * q * (a - b + c + p - q + r);
    double P3 = c * r * (a + b - c + p + q - r);
    double P = a * b * r + a * c * q + b * c * p + p * q * r;
    return sqrt((P1 + P2 + P3 - P)) / 12.;
}
int main()
{
    double a, b, c, r, p, q;
    while (~scanf("%lf %lf %lf %lf %lf %lf", &a, &b, &c, &r, &q, &p))
    {
        printf("%.4lf\n", calc(a, b, c, r, p, q));
    }
    return 0;
}
