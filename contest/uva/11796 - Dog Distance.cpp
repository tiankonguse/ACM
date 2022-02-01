#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <stack>
#include <cmath>
using namespace std;
typedef long long LL;

double eps = 1e-8;
int dcmp(double x) {
    return fabs(x) < eps ? 0 : x < 0 ? -1 : 1;
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
        printf("%f %f\n", x , y);
    }
    bool operator < (const Point& R) const{
        return x < R.x || (x == R.x && y < R.y);
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
    }
    double operator ^ (const Point& R) const{
        return x * R.y - y * R.x;
    }
    double operator % (const Point& R) const{
        return x * R.x + y * R.y;
    }
    double len()
    {
        return sqrt(*this % *this);
    }
};

double Angle(Point A , Point B)
{
    return acos((A % B) / A.len() / B.len());
}
Point Rotate(Point A , double rad)
{
    double Sin = sin(rad) , Cos = cos(rad);
    return Point(A.x * Cos - A.y * Sin , A.x * Sin + A.y * Cos);
}
Point Normal(Point A)
{
    double L = A.len();
    return Point(-A.y / L , A.x / L);
}
Point GetLineIntersection(Point P , Point v , Point Q , Point w)
{
    Point u = P - Q;
    double t1 = (w ^ u) / (v ^ w);
    return P + v * t1;
}
double DistancePointToLine(Point P , Point A , Point B)
{
    Point v = B - A;
    return (v ^ (P - A)) / v.len();
}
double DistancePointToSegment(Point P , Point A , Point B)
{
    if (A == B) return (P - A).len();
    Point v1 = B - A , v2 = P - A , v3 = P - B;
    if (dcmp(v1 % v2) < 0) return v2.len();
    if (dcmp(v1 % v3) > 0) return v3.len();
    return fabs(v1 ^ v2) / v1.len();
}
Point GetLineProjection(Point P , Point A , Point B)
{
    Point v = B - A;
    return A + v * (v % (P - A) / (v % v));
}
bool SegmentProperIntersection(Point a1 , Point a2 , Point b1 , Point b2)
{
    double c1 = (a2 - a1) ^ (b1 - a1);
    double c2 = (a2 - a1) ^ (b2 - a1);
    double c3 = (b2 - b1) ^ (a1 - b1);
    double c4 = (b2 - b1) ^ (a2 - b1);
    return dcmp(c1) * dcmp(c2) < 0 && dcmp(c3) * dcmp(c4) < 0;
}
//判断点是否在线段上，不包含端点，原理为由叉积判定在直线上，点积判断方向。
//容易改为在射线/直线上
bool OnSegment(Point P , Point a1 , Point a2)
{
    return dcmp((a1 - P) ^ (a2 - P)) == 0 && dcmp((a1 - P) % (a2 - P)) < 0;
}

int n , m , ca;
Point P[100] , Q[100];
double mx , mn;

void update(Point P , Point A , Point B)
{
    mn = min(mn , DistancePointToSegment(P , A , B));
    mx = max(mx , (P - A).len());
    mx = max(mx , (P - B).len());
}

void work()
{
    int i , j;
    scanf("%d%d",&n,&m);
    for (i = 0 ; i < n ; ++ i)
        P[i].input();
    for (i = 0 ; i < m ; ++ i)
        Q[i].input();
    mx = -1e60 , mn = 1e60;
    double LenA = 0 , LenB = 0;
    for (i = 0 ; i + 1 < n ; ++ i)
        LenA += (P[i + 1] - P[i]).len();
    for (i = 0 ; i + 1 < m ; ++ i)
        LenB += (Q[i + 1] - Q[i]).len();
    i = 0 , j = 0;
    Point Pa = P[0] , Pb = Q[0];
    while (i < n - 1 && j < m - 1)
    {
        double La = (P[i + 1] - Pa).len();
        double Lb = (Q[j + 1] - Pb).len();
        double T = min(La / LenA , Lb / LenB);
        Point Va = (P[i + 1] - Pa) / La * T * LenA;
        Point Vb = (Q[j + 1] - Pb) / Lb * T * LenB;
        update(Pa , Pb , Pb + Vb - Va);
        Pa = Pa + Va;
        Pb = Pb + Vb;
        if (Pa == P[i + 1]) ++ i;
        if (Pb == Q[j + 1]) ++ j;
    }
    printf("Case %d: %.0f\n" , ++ ca , mx - mn);
}

int main()
{
    freopen("~input.txt" , "r" , stdin);
    int _; scanf("%d",&_); while (_ --)
    //while (scanf("%d",&n) , n)
        work();
    return 0;
}
