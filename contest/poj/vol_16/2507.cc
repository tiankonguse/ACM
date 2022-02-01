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
const double eps = 1e-8;
int main(){
    double x, y, c, hx, hy;
    while(~scanf("%lf%lf%lf", &x, &y, &c)){
        double l = 0, r = min(x, y), mid;
        while(l + eps < r){
            mid = (l + r) / 2.0;
            hx = sqrt(x * x - mid * mid);
            hy = sqrt(y * y - mid * mid);
            if(c / hx + c / hy > 1) r = mid;
            else l = mid;
        }
        printf("%.3lf\n", mid);
    }
    return 0;
}
