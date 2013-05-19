/*************************************************************************
    > File Name: test.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/6 21:12:38
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

struct Point_2d {
    double x,y;
};
struct Point_3d {
    double x,y,z;
};

double distance_2d(Point_2d const&a,Point_2d const&b) {
    return(sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)));
}
double distance_3d(Point_3d &a, Point_3d&b) {
    return(sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z)));
}
double triangleArea(Point_2d const&a,Point_2d const&b,Point_2d const&c) {
    double ab,bc,ca,p,s;
    ab=distance_2d(a,b);
    bc=distance_2d(b,c);
    ca=distance_2d(c,a);
    p=(ab+bc+ca)/2;
    s=sqrt(p*(p-ab)*(p-bc)*(p-ca));
    return s;
}





int main() {

    return 0;
}
