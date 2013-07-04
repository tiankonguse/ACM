/*************************************************************************
    > File Name: 2794_F��Function Curve.cpp
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

struct T {
    double k,a,b;
    void input() {
        scanf("%lf%lf%lf",&k,&a,&b);
    }
} str[55];
int n;

double getHeight(int pos, double x){
    return str[pos].k * (x - str[pos].a) * (x - str[pos].a) + str[pos].b;
}

double getMinHeight(double x){
    double h = 100;
    for(int i=0;i<n;i++){
        h = min(h, getHeight(i,x));
    }
//    printf("-x=%lf  %lf\n",x,h);
    return h;
}

int main() {

    int cas,i;
    double x,pre,h;
    double step = 0.001,ans;
    scanf("%d",&cas);
    while(cas--) {
        scanf("%d",&n);
        for(i=0; i<n; i++) {
            str[i].input();
        }
        ans = 0;
        pre = getMinHeight(0);
        for(x=step;x<=100;x+=step){
            h = getMinHeight(x);
            ans += sqrt(step*step + (pre - h)*(pre - h));
            pre = h;
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
