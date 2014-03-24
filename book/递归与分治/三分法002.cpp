/*************************************************************************
    > File Name: 三分法002.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/15 16:14:52
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;
double Calc(double a) {
    /* 根据题目的意思计算 */
}
void Solve(double Left, double Right) {
    double mid_left, mid_right, mid_left_value, mid_right_value;

    while (Left + 1e-6 < Right) {
        mid_left = (Left + Right) / 2;
        mid_right = (mid + Right) / 2;
        mid_left_value = Calc(mid);
        mid_right_value = Calc(midmid);
        // 假设求解最大极值.
        if (mid_left_value >= mid_right_value){
            Right = mid_right;
        }else{
            Left = mid_left;
        }
    }
    return mid_left_value;
}
int main() {

    return 0;
}
