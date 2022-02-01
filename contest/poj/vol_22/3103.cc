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

int main(){
    double x, y, z; int n;
    while(~scanf("%lf %lf %lf %d", &x, &y, &z, &n)){
        double tn = 1.0 * n, px = 0;
        x /= tn;
        for(int i=0;i<n;i++){
            printf("%.10lf %.10lf %.10lf %.10lf %.10lf %.10lf\n",
                   px, 0.0, 0.0, px + x, y, z);

            px += x;
        }
    }
    return 0;
}
