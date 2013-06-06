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
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;
double e = 2.718281828459045;

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

int getMinHeight(double x) {
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


double getLen(double x,int pos) {



    if(pos == -1){
        return x;
    }

    x = 2 * str[pos].k * (x - str[pos].a);
//    double a = 4 * str[pos].k * str[pos].k;
//    double b = -1.0 * a * 2 * str[pos].a;
//    double c = a * str[pos].a * str[pos].a + 1;
    double tmp = sqrt(x * x + 1);

    return x * tmp / 2 + log(x + tmp) / 2;
//    return (2 * a * x + b) * tmp / (4 * a) + (4 * a * c - b * b) * (log(fabs(2 * a * x + b + 2 * sqrt(a) * tmp))) / (8*pow(a,1.0/3));
}

int main() {

    int cas,i,pre_pos,h_pos;
    double x,pre,now;
    double step = 0.005,ans;
    scanf("%d",&cas);
    while(cas--) {
        scanf("%d",&n);
        for(i=0; i<n; i++) {
            str[i].input();
        }
        ans = 0;
        pre_pos = getMinHeight(0);
        pre = 0;
        for(x=step; x<=100; x+=step) {
            h_pos= getMinHeight(x);
            if(pre_pos != h_pos) {
                ans += getLen(x,pre_pos) - getLen(pre,pre_pos);
                printf("pos=%d  %lf %lf ans = %lf\n",pre_pos, pre,x,ans);
                //sqrt(step*step + (pre - h)*(pre - h));
                pre_pos = h_pos;
                pre = x;

            }
        }
        if(pre_pos == h_pos) {
            ans += getLen(100,pre_pos) - getLen(pre,pre_pos);
            printf("%lf %lf ans = %lf\n",pre,100.0,ans);
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
