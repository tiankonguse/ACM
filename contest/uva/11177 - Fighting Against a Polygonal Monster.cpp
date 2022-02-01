#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <cmath>
#include <cassert>
using namespace std;
typedef long long LL;

const double eps = 1e-10 , pi = acos(-1.0);
int dcmp(double x) {
    return (x > eps) - (x < -eps);
}


struct Point
{
    double x , y;
    Point () {x = y = 0;}
    Point (double _x , double _y) {x = _x , y = _y;}
    void input() {
        scanf("%lf%lf",&x,&y);
    }
    void output() {
        printf("(%f,%f)", x + eps , y + eps);
    }
    bool operator < (const Point& R) const{
        if (dcmp(x - R.x) == 0)
            return dcmp(y - R.y) < 0;
        return dcmp(x - R.x) < 0;
    }
    bool operator == (const Point& R) const{
        return dcmp(x - R.x) == 0 && dcmp(y - R.y) == 0;
    }
    Point operator + (const Point& R) const{
        return Point(x + R.x , y + R.y);
    }
    Point operator - (const Point& R) const{
        return Point(x - R.x , y - R.y);
    }
    Point operator * (const double& R) const{
        return Point(x * R , y * R);
    }
    Point operator / (const double& R) const{
        return Point(x / R , y / R);
    }// Cross Product
    double operator ^ (const Point& R) const{
        return x * R.y - y * R.x;
    }// dot
    double operator % (const Point& R) const{
        return x * R.x + y * R.y;
    }
    double len()
    {
        return sqrt(*this % *this);
    }
};
// 向量的极角，[0,2pi)
double Angle(Point V) {
    double a = atan2(V.y , V.x);
    return a < 0 ? a + pi + pi : a;
}
// 两个向量的夹角，不分正负
double Angle(Point A , Point B) {
    double a = Angle(B) - Angle(A);
    if (a < -pi) a += pi + pi;
    return a;
}
// 逆时针旋转
Point Rotate(Point A , double rad) {
    double Sin = sin(rad) , Cos = cos(rad);
    return Point(A.x * Cos - A.y * Sin , A.x * Sin + A.y * Cos);
}
// 向量的单位法向量，利用旋转得到
Point Normal(Point A) {
    double L = A.len();
    return Point(-A.y / L , A.x / L);
}
// 直线交点，v和w为两个直线的方向向量，
// 设交点的参数为P+vt,Q+wt,连立方程解t
// 线段，射线对这个t的参数有限制，很好理解。
Point GetLineIntersection(Point P , Point v , Point Q , Point w) {
    Point u = P - Q;
    double t1 = (w ^ u) / (v ^ w);
    return P + v * t1;
}
struct Line
{
    Point P , V; // P + Vt
    Line () {}
    Line (Point A , Point B) {P = A , V = B - A;}
    Point point(double t){
        return P + V * t;
    }
};
struct Circle
{
    Point O;
    double r;
    Circle () {}
    Circle (Point _O , double _r) {O = _O , r = _r;}
    Point point(double arc) {
        return Point(O.x + cos(arc) * r , O.y + sin(arc) * r);
    }
    void input() {
        O.input() , scanf("%lf",&r);
    }
    void print() {
        printf("(%f,%f,%f)\n" , O.x + eps , O.y + eps , r + eps);
    }
};

// 判定直线与圆相交
// 方法为连立直线的参数方程与圆的方程，很好理解
// t1,t2为两个参数，sol为点集。有了参数，射线线段什么的也很方便
int getLineCircleIntersection(Line L , Circle C , double& t1 , double& t2) {
    double a = L.V.x , b = L.P.x - C.O.x , c = L.V.y , d = L.P.y - C.O.y;
    double e = a * a + c * c , f = 2 * (a * b + c * d) , g = b * b + d * d - C.r * C.r;
    double delta = f * f - 4 * e * g;
    if (dcmp(delta) < 0) return 0;
    if (dcmp(delta) == 0)
    {
        t1 = t2 = -f / (2 * e);
        //sol.push_back(L.point(t1));
        return 1;
    }
    t1 = (-f - sqrt(delta)) / (e + e);
    t2 = (-f + sqrt(delta)) / (e + e);
    //sol.push_back(L.point(t1)) , sol.push_back(L.point(t2));
    return 2;
}


int n , ca;
double S;
Point a[55];

double sector_area(Point A , Point B , double R) {
    double theta = Angle(A) - Angle(B);
    while (theta < 0) theta += pi + pi;
    while (theta >= pi + pi) theta -= pi + pi;
    theta = min(theta , pi + pi - theta);
    return R * R * theta;
}

double cal(double R) {
    double area = 0;
    for (int i = 0 ; i < n ; ++ i) {
        double t1 = 0 , t2 = 0 , delta;
        Line L = Line(a[i] , a[i + 1]);
        int cnt = getLineCircleIntersection(L , Circle(Point(0 , 0) , R) , t1 , t2);
        Point X = L.point(t1) , Y = L.point(t2);
        bool f1 = dcmp(a[i].len() - R) <= 0 , f2 = dcmp(a[i + 1].len() - R) <= 0;
        if (f1 && f2)
            delta = fabs(a[i] ^ a[i + 1]);
        else if (!f1 && f2) {
            delta = sector_area(a[i] , X , R) + fabs(X ^ a[i + 1]);
        } else if (f1 && !f2) {
            delta = fabs(a[i] ^ Y) + sector_area(Y , a[i + 1] , R);
        } else {
            if (cnt > 1 && 0 < t1 && t1 < 1 && 0 < t2 && t2 < 1) {
                delta = sector_area(a[i] , X , R) + sector_area(Y , a[i + 1] , R) + fabs(X ^ Y);
            } else {
                delta = sector_area(a[i] , a[i + 1] , R);
            }
        }
        area += delta * dcmp(a[i] ^ a[i + 1]);
    }
    return area / 2;
}

void work()
{
    scanf("%lf",&S);
    double l = 0 , r = 1e10 , m;
    for (int i = 0 ; i < n ; ++ i)
        a[i].input() ;
    a[n] = a[0];
    while (r - l > 1e-8) {
        m = 0.5 * (l + r);
        if (fabs(cal(m)) >= S)
            r = m;
        else
            l = m;
    }
    printf("Case %d: %.2f\n" , ++ ca , r + eps);
}

int main()
{
    //freopen("~input.txt" , "r" , stdin);
    //freopen("2.txt" , "w" , stdout);

    while (scanf("%d",&n) , n)
        work();
    return 0;
}


/*
Case 1: 8.58
Case 2: 7.80
Case 3: 7.15
Case 4: 7.76
Case 5: 6.01
Case 6: 5.59
Case 7: 6.25
Case 8: 5.47
Case 9: 13.51
Case 10: 3.95
*/
