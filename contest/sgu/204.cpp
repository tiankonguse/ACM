#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <vector>
#include <queue>
#include <cmath>
#include <cassert>
using namespace std;
typedef long long LL;

#define N 405

double b1, t1, b2, t2, l, ds, df , g;
double cal(double d , double s , double h) {
    double A = h / (d * (s - d));
    return (g * A * s * s + g / A) / 2;
}

double check(double Q) {
    double d , s , v1 , v2;
    d = ds , s = ds + Q;
    double h1 = d * (s - d) / s;
    if (h1 >= t1)
        v1 = cal(d , s , t1);
    else if (h1 <= b1)
        v1 = cal(d , s , b1);
    else
        v1 = g * s;

    d = df , s = df + (l - Q);
    double h2 = d * (s - d) / s;
    if (h2 >= t2)
        v2 = cal(d , s , t2);
    else if (h2 <= b2)
        v2 = cal(d , s , b2);
    else
        v2 = g * s;
    return max(v1 , v2);
}

void work() {
    double L , R , m1 , m2;
    L = 0 , R = l;
    for (int T = 100 ; T ; -- T) {
        m1 = (L + L + R) / 3;
        m2 = (L + R + R) / 3;
        if (check(m1) < check(m2))
            R = m2;
        else
            L = m1;
    }
    printf("%.4f\n" , sqrt(check((L + R) / 2)));
}

int main(){
    while (cin >> b1 >> t1 >> b2 >> t2 >> l >> ds >> df >> g)
        work();
    return 0;
}
