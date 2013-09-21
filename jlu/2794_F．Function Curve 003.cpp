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
#include<ctime>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;
double e = 2.718281828459045;
const double eps = 1e-6;
const double step = 0.001;
const int TEST = 50;


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


    if(pos == -1){
        return x;
    }
//    printf("k=%lf a=%lf b=%lf  x=%lf\n",str[pos].k,str[pos].a,str[pos].b,x);



    x = x - str[pos].a;
//    double a = 4 * str[pos].k * str[pos].k;
//    double b = -1.0 * a * 2 * str[pos].a;
//    double c = a * str[pos].a * str[pos].a + 1;
    double k = str[pos].k;
    double ans;
    if(x <0){
        ans = -1.0 * sqrt((4*k*k*x*x + 1)*x*x/4) + (log(2*k*x + sqrt(4*x*x*k*k+1)) - log(2*k))/(4*k);
    }else{
        ans = sqrt((4*k*k*x*x + 1)*x*x/4) + (log(2*k*x + sqrt(4*x*x*k*k+1)) - log(2*k))/(4*k);
    }
//    double ans = sqrt((4*k*k*x*x + 1)*x*x/4) + (log(2*k*x + sqrt(4*x*x*k*k+1)) - log(2*k))/(4*k);

//    double ans =
//    (x * sqrt((x * x * 4 * k * k+ 1)/(4 * k * k)) / 2 + log(x + sqrt((x * x * 4 * k * k+ 1)/(4 * k * k))) / (8 * k * k)) * (2 * k);
//    printf("\n ans=%lf  tmp=%lf  x=%lf\n\n",ans,tmp,x);
    return ans;
//    return (2 * a * x + b) * tmp / (4 * a) + (4 * a * c - b * b) * (log(fabs(2 * a * x + b + 2 * sqrt(a) * tmp))) / (8*pow(a,1.0/3));
}

double find(double left,double right,int pos){
    double mid ;
    double mid_pos;
    while(left + eps < right){
//        printf("%lf %lf\n",left,right);
        mid = (left + right)/2;
        mid_pos = getMinHeightPos(mid);
        if(mid_pos == pos){
            left = mid;
        }else{
            right = mid;
        }
    }
    return left;
}

double check(double left,double right,int pos,double &_x){

    int _pos;
    for(int i=0;i<TEST;i++){
        _pos = getMinHeightPos(_x=(left + (right - left)*(rand()%100)/100));
        if(pos != _pos){
            return true;
        }
    }
    return false;
}

int main() {
    srand(time(NULL));
    int cas,i,pre_pos,h_pos;
    double x,pre,now,h1,h2,xx,_x;
//    printf("%lf  %lf\n",5 + sqrt(23.5),5 - sqrt(23.5));
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
            h_pos= getMinHeightPos(x);
            if(pre_pos != h_pos) {
                xx = find(x-step,x,pre_pos);
                ans += getLen(xx,pre_pos) - getLen(pre,pre_pos);
                //h1 =getMinHeight(x-step),h2 = getMinHeight(x);
                //ans += sqrt(step*step + (h1 - h2)*(h1 - h2));
//                printf("pos=%d  pre=%lf x=%lf ans = %lf\n",pre_pos, pre,x,ans);
                //sqrt(step*step + (pre - h)*(pre - h));
                pre_pos = h_pos;
                pre = xx;
            }else{
                if(check(pre,x,pre_pos,_x)){
                    int a = 1/0;
                }
            }
        }
        if(pre != 100) {
            ans += getLen(100,pre_pos) - getLen(pre,pre_pos);
//            printf("pre=%lf x=%lf ans = %lf\n",pre,100.0,ans);
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
