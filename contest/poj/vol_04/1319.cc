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

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL

using namespace std;
const double q = 0.5 * sqrt(3.0);
const double eps = 1e-8;

int main(){
    double a, b;
    int g, s, s1, s2, t1, t2, t3;
    while(~scanf("%lf %lf", &a, &b)){
        if(a < 1 || b < 1) { puts("0 grid"); continue;}
        g = (int)a * (int)b;
        t1 = (int)((a - 1.0) / q + eps) + 1;
        t2 = (int)b;
        t3 = (int)(b - 0.5);
        s1 = t1 / 2 * (t2 + t3);
        if(t1 % 2 == 1) s1 += t2;
        t1 = (int)((b - 1.0) / q + eps) + 1;
        t2 = (int)a;
        t3 = (int)(a - 0.5);
        s2 = t1 / 2 * (t2 + t3);
        if(t1 % 2 == 1) s2 += t2;
        s = max(s1, s2);
        if(g >= s) printf("%d grid\n", g);
        else printf("%d skew\n", s);
    }
    return 0;
}
