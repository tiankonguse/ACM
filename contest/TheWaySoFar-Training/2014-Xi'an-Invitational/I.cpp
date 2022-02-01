#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
//#include <cassert>
//#pragma comment(linker, "/STACK:16777216")
using namespace std;
typedef long long LL;
const double eps = 1e-10 , pi = acos(-1.0);
inline int dcmp(double x) {
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
    double len() {
        return sqrt(*this % *this);
    }
};
// 向量的极角，[0,2pi)
double Angle(Point V) {
    double x = atan2(V.y , V.x);
    return x < 0 ? x + pi + pi : x;
}
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
};
// 过点p到圆C的切线。返回切线条数，sol里为方向向量
void getTangents(Point P, Circle C, vector<double>& sol)
{
    Point u = C.O - P;
    double Ang = Angle(u) , x;
    double ang = asin(C.r / u.len());
    x = Ang + ang;
    while (x < 0) x += pi + pi;
    while (x >= pi + pi) x -= pi + pi;
    sol.push_back(x);
    x = Ang - ang;
    while (x < 0) x += pi + pi;
    while (x >= pi + pi) x -= pi + pi;
    sol.push_back(x);
}
const int N = 205;
int n;
Circle C[N];
vector<double> E;

double cal(double arc) {
    double res = 0;
    Point Vec = Point(cos(arc) , sin(arc));
    for (int i = 0 ; i < n ; ++ i) {
        if (dcmp(Vec % C[i].O) <= 0)
            continue;
        double dist = fabs(C[i].O.len() * sin(Angle(C[i].O) - arc));
        if (dcmp(dist - C[i].r) < 0) {
            res += 2 * sqrt(C[i].r * C[i].r - dist * dist);
        }
    }
    return res;
}

void work() {
    int i , j;
    for (i = 0 ; i < n ; ++ i)
        C[i].input();
    E.clear();
    for (i = 0 ; i < n ; ++ i)
        getTangents(Point(0 , 0) , C[i] , E);
    double ans = 0;
    sort(E.begin() , E.end());
    E.push_back(E[0] + pi + pi);
    for (i = 0 ; i + 1 < (int)E.size() ; ++ i) {
        double l = E[i] , r = E[i + 1] , m1 , m2;
        for (j = 0 ; j < 50 ; ++ j) {
            m1 = (l + l + r) / 3;
            m2 = (l + r + r) / 3;
            if (cal(m1) > cal(m2))
                r = m2;
            else
                l = m1;
        }
        ans = max(ans , cal((m1 + m2) / 2));
    }
    printf("%.10f\n" , ans);
}

int main()
{
    while (~scanf("%d",&n))
        work();
    return 0;
}
