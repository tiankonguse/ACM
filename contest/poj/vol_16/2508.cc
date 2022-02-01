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
const double pi = acos(-1.0);

int main(){
    double r, h, l, d1, a1, d2, a2, da, res;
    double x, y;
    while(~scanf("%lf%lf%lf%lf%lf%lf", &r, &h, &d1, &a1, &d2, &a2)){
        l = sqrt(h * h + r * r);
        da = abs(a1 - a2) * r / l / 180.0 * pi;
        x = d2 * sin(da);
        y = d2 * cos(da) - d1;
        res = sqrt(x * x + y * y);
        da = (360.0 - abs(a1 - a2) ) * r / l / 180.0 * pi;
        x = d2 * sin(da);
        y = d2 * cos(da) - d1;
        res = min(res, sqrt(x * x + y * y) );
        printf("%.2lf\n", res);
    }
    return 0;
}
