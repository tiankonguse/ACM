#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
#include<stdarg.h>
using namespace std;
#ifdef __int64
typedef __int64 LL;
#else
typedef long long LL;
#endif
const int N = 1010;
struct T {
    double t,x,y;
    void read() {
        scanf("%lf%lf%lf", &t, &x, &y);
    }
} str[N];

inline double three(double a, double b){
    return sqrt(a * a + b * b);
}

inline double getAns(const T& a, const T& b) {
    return three(a.x - b.x, a.y - b.y) / (b.t - a.t);
}



int main() {
    int cas;
    int n;
    scanf("%d",&cas);
    while(cas--) {
        scanf("%d",&n);
        for(int i = 0; i < n; i++){
            str[i].read();
        }
        double ans = -1.0;
        for(int i = 0; i < n-1; i++){
            ans = max(ans, getAns(str[i], str[i+1]));
        }

        printf("%.10f\n",ans);
    }
    return 0;
}
