#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <stack>
#include <cmath>
#include <cassert>
using namespace std;
typedef long long LL;

#define N 10005
double A , B;
//Adaptive Simpson's Rule integral
double F(double x)
{
    return sqrt(B * B - x * x);
}
double simpson2(double a , double b)
{
    double c = (a + b) * 0.5;
    return (F(a) + 4 * F(c) + F(b)) * (b - a) / 6;
}
double asr2(double a , double b , double eps , double A)
{
    double c = (a + b) * 0.5;
    double L = simpson2(a , c) , R = simpson2(c , b);
    if (fabs(L + R - A) <= 15 * eps)
        return L + R + (L + R - A) / 15;
    return asr2(a , c , eps / 2 , L) + asr2(c , b , eps / 2 , R);
}
double cal2(double x)
{
    double R = sqrt(A * A - x * x);
    return asr2(0 , R , 1e-5 , simpson2(0 , R));
}
double simpson1(double a , double b)
{
    double c = (a + b) * 0.5;
    return (cal2(a) + 4 * cal2(c) + cal2(b)) * (b - a) / 6;
}
double asr1(double a , double b , double eps , double A)
{
    double c = (a + b) * 0.5;
    double L = simpson1(a , c) , R = simpson1(c , b);
    if (fabs(L + R - A) <= 15 * eps)
        return L + R + (L + R - A) / 15;
    return asr1(a , c , eps / 2 , L) + asr1(c , b , eps / 2 , R);
}
double cal1()
{
    return 8 * asr1(0 , A , 1e-5 , simpson1(0 , A));
}

void work() {
    scanf("%lf%lf",&A,&B);
    if (A > B) swap(A , B);
    printf("%.4f\n" , cal1());
}

int main()
{
    //freopen("1.txt" , "r" , stdin);
//    int _; scanf("%d",&_); while (_ --)
        work();
    return 0;
}
