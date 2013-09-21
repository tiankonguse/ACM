/*************************************************************************
    > File Name: Party All the Time.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/15 15:59:15
    >http://acm.hdu.edu.cn/showproblem.php?pid=4355
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;
typedef double Type;
typedef long long LL;
double const eps = 1e-6;
double const scale = (sqrt(5.0) - 1) / 2;
double str[50010][2];
int n;

double Calc(Type a) {
    double sum = 0,tmp;
    for(int i=0;i<n;i++){
        tmp = fabs(a - str[i][0]);
        sum += tmp*tmp*tmp*str[i][1];
    }
    return sum;
}
double Solve(double left, double right) {
    double mid_left, mid_right;
    double mid_left_value, mid_right_value;
    double Golden_Section ,len, tmp;

    bool left_scale = true;

    len = right - left;
    Golden_Section = scale * len;

    mid_left = right - Golden_Section;
    mid_left_value = Calc(mid_left);

    while (left + eps < right) {
        if(left_scale) {
            mid_right = left + Golden_Section;
            mid_right_value = Calc(mid_right);
        } else {
            mid_left = right - Golden_Section;
            mid_left_value = Calc(mid_left);
        }

        tmp = len;
        len = Golden_Section;
        Golden_Section = tmp - Golden_Section;

        if (mid_left_value >= mid_right_value) {
            left = mid_left;
            left_scale = true;

            mid_left = mid_right;
            mid_left_value = mid_right_value;
        } else {
            right = mid_right;
            left_scale = false;

            mid_right = mid_left;
            mid_right_value = mid_left_value;
        }
    }
    return mid_right_value;
}
int main() {
    int cas,i,ca;
    scanf("%d",&cas);
    for(ca=1;ca<=cas;ca++){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%lf%lf",&str[i][0],&str[i][1]);
        }

        printf("Case #%d: %lld\n",ca,(LL)(Solve(str[i][0], str[n-1][0])+0.5));
    }
    return 0;
}
