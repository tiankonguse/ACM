/*************************************************************************
    > File Name: 三分法.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/15 15:23:10
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<map>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;
typedef double Type;
double const eps = 1e-6;
double const scale = (sqrt(5.0) - 1) / 2;
double Calc(Type a) {
    /* 根据题目的意思计算 */
}
void Solve(double left, double right) {
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
}
int main() {


    return 0;
}
