/*************************************************************************
    > File Name: 2794_F．Function Curve.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/6/5 20:34:24
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<map>
#include<cmath>
#include<ctime>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;
double e = 2.718281828459045;
const double eps = 1e-5;
const double step = 0.01;
const int TEST = 10;


struct T {
    double k,a,b;
    void input() {
        scanf("%lf%lf%lf",&k,&a,&b);
    }
} str[55];
int n;

double getHeight(int pos, double x) {
    return str[pos].k * (x - str[pos].a) * (x - str[pos].a) + str[pos].b;
}

int getMinHeightPos(double x) {
    double tmp,h = 100;
    int pos = -1;
    for(int i=0; i<n; i++) {
        tmp = getHeight(i,x);
        if(tmp < h) {
            h = tmp;
            pos = i;
        }
    }
    return pos;
}
double getMinHeight(double x) {
    double h = 100;
    for(int i=0; i<n; i++) {
        h = min(getHeight(i,x),h);
    }
    return h;
}


double getLen(double x,int pos) {


    if(pos == -1) {
        return x;
    }

    x = x - str[pos].a;
    double k = str[pos].k;
    double ans;
    if(x <0) {
        ans = -1.0 * sqrt((4*k*k*x*x + 1)*x*x/4) + (log(2*k*x + sqrt(4*x*x*k*k+1)) - log(2*k))/(4*k);
    } else {
        ans = sqrt((4*k*k*x*x + 1)*x*x/4) + (log(2*k*x + sqrt(4*x*x*k*k+1)) - log(2*k))/(4*k);
    }
    return ans;
}

double find(double left,double right,int pos,int& h_pos) {
    double mid ;
    double mid_pos;
    h_pos = pos;
    while(left + eps < right) {
        mid = (left + right)/2;
        mid_pos = getMinHeightPos(mid);
        if(mid_pos == pos) {
            left = mid;
        } else {
            right = mid;
            h_pos = mid_pos;
        }
    }
    return left;
}

double check(double left,double right,int pos, double & _x) {

    int _pos;
    for(int i=0; i<TEST; i++) {
        _pos = getMinHeightPos(_x = left + (right - left)*(rand()%100)/100);
        if(pos != _pos) {
            return true;
        }
    }
    return false;
}

int main() {
    srand(time(NULL));
    int cas,i,pre_pos,h_pos;
    double x,pre,xx,_x;
    double ans;
    scanf("%d",&cas);
    while(cas--) {
        scanf("%d",&n);
        for(i=0; i<n; i++) {
            str[i].input();
        }
        ans = 0;
        pre_pos = getMinHeightPos(0);
        pre = 0;
        for(x=step; x<=100; x+=step) {
            if(check(pre,x,pre_pos,_x)) {
                x = find(x - step, _x, pre_pos, h_pos);
//                printf("- %lf %lf h_pos=%d pre_pos=%d\n",x, pre,h_pos,pre_pos);
                ans += getLen(x,pre_pos) - getLen(pre,pre_pos);
                pre_pos = h_pos;
                pre = x+eps;
//                printf("- %lf %lf h_pos=%d\n",x, pre,h_pos);
            }
        }
        if(pre < 100) {
            ans += getLen(100,pre_pos) - getLen(pre,pre_pos);
        }
        printf("%.2f\n",ans);
    }

    return 0;
}

/*
2
3
1 2 3
4 5 6
7 8 9
1
4 5 6

215.56
278.91
*/
