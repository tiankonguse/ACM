#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
#include<stdarg.h>
using namespace std;
typedef long long LL;
const double eps = 1e-3;
const double PI = acos(-1.0);

typedef struct Point Vector;

struct Point {
    double x, y;
    Point(double x=0, double y=0): x(x), y(y) {}
    Point operator + (Point B)const {
        return Point(this->x+B.x, this->y+B.y);
    }
    Point operator - (Point B)const {
        return Point(this->x - B.x, this->y - B.y);
    }

    Point operator * (double k)const {
        return Point(this->x*k, this->y*k);
    }

    Point operator / (double k)const {
        return Point(this->x/k, this->y/k);
    }
};



inline int dcmp(double x) {
    if (fabs(x) < eps) return 0;
    return x < 0 ? -1 : 1;

}

inline double Dot(Point A, Point B) {
    return A.x*B.x + A.y*B.y;
}

inline double Cross(Point A, Point B) {
    return A.x*B.y - A.y*B.x;
}

inline double Length(Point A) {
    return sqrt(A.x*A.x + A.y*A.y);
}

inline double _Angle(Point A, Point B) {
    return acos(Dot(A, B) / Length(A) / Length(B));
}

inline Point Normal(Point A) {
    return Point(-A.y/Length(A), A.x/Length(A));    //逆时针90
}

inline void GetSegmentBisector(Point A, Point B, Point &C, Point &v) {
    C = (A + B) / 2;
    v = Normal(B - A);
}

inline Point _GetLineIntersection(Point P, Point v, Point Q, Point w) {
    Point u = P - Q;
    double t = Cross(w, u) / Cross(v, w);
    return P + v*t;
}

inline Point GetCircle(Point A, Point B, Point C) {
    Point P, Q;
    Point v, w;
    GetSegmentBisector(A, B, P, v);
    GetSegmentBisector(A, C, Q, w);
    return _GetLineIntersection(P, v, Q, w);
}

inline double area(double r, double a) {
    return r * r * sin(a) / 2;
}

Point a[5], c;
double r, ang[5], angle;
int n;

double fgcd(double a, double b) {
    if(b > -eps && b < eps) {
        return a;
    } else {
        return fgcd( b, fmod(a, b) );
    }
}

int main() {

    while (~scanf("%lf%lf%lf%lf%lf%lf", &a[0].x, &a[0].y, &a[1].x, &a[1].y, &a[2].x, &a[2].y)) {
        a[3] = a[0];
        c = GetCircle(a[0], a[1], a[2]);
        r = Length(c - a[0]);
        for (int i=0; i<3; i++) {
            ang[i] = _Angle(a[i]-c, a[i+1]-c);
        }
        sort(ang,ang+3);
        if(fabs(ang[0] + ang[1] - ang[2]) <= eps) {
            ang[2] = 2*PI - ang[2];
        }


        angle = 2*PI;
        for (int i=2; i>=0; i--) {
            angle = fgcd(angle,ang[i]);
        }

        printf("%.8lf\n", 2 * PI / angle * area(r, angle));
    }

    return 0;
}


