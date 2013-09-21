/*************************************************************************
    > File Name: e.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/4 19:23:32
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

const double eps = 1e-8;
const double pi = acos(-1);

struct Point{
    double x,y;
    void init(double _x,double _y){
        x = _x,y = _y;
    }
}door__left,door__right,_left,_right;

double calc(Point& a) {
    double lena = (a.x - door__left.x)*(a.x - door__left.x) + (a.y - door__left.y)*(a.y - door__left.y);
    double lenb = (a.x - door__right.x)*(a.x - door__right.x) + (a.y - door__right.y)*(a.y - door__right.y);
    double lenc = (door__right.x - door__left.x)*(door__right.x - door__left.x);
//    printf("%llf\n",(lena + lenb - lenc)/(2*sqrt(lena)*sqrt(lenb)));
    return acos((lena + lenb - lenc)/(2*sqrt(lena)*sqrt(lenb)))*360/(2*pi);

}
double Solve() {
    double _left_val = calc(_left);
    double _right_val = calc(_right);
//printf("%lf %lf\n",_left_val,_right_val);
    while (fabs(_left.x - _right.x )>eps ||fabs(_left.y - _right.y )>eps || fabs(_left_val - _right_val )>eps) {
//        printf("%lf %lf\n",_left_val,_right_val);
        if(_right_val < _left_val){
            _right.x = _left.x + (_right.x - _left.x)*2/3;
            _right.y = _left.y + (_right.y - _left.y)*2/3;
            _right_val = calc(_right);
        }else{
            _left.x = _left.x + (_right.x - _left.x)/3;
            _left.y = _left.y + (_right.y - _left.y)/3;
            _left_val = calc(_left);
        }
    }
    return _right_val;
}
int main() {
    double x1,x2,y;
    while(~scanf("%lf%lf%lf",&x1,&x2,&y)){
        door__left.init(x1,y);
        door__right.init(x2,y);

        scanf("%lf%lf",&x1,&y);
        _left.init(x1,y);

        scanf("%lf%lf",&x1,&y);
        _right.init(x1,y);
        if(_left.x > _right.x){
            swap(_left.x , _right.x);
            swap(_left.y , _right.y);
        }

        printf("%.8f\n",Solve());



    }
    return 0;
}
