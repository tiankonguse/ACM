#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <stack>
#include <cmath>
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
    return atan2(V.y , V.x);
}
// 两个向量的夹角，不分正负
double Angle(Point A , Point B) {
    return acos((A % B) / A.len() / B.len());
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
// 点到直线距离，这里直线是用两个点表示的
double DistancePointToLine(Point P , Point A , Point B) {
    Point v = B - A;
    return (v ^ (P - A)) / v.len();
}
// 点到线段距离，就是上面的代码判断一下P在AB上投影的位置。
double DistancePointToSegment(Point P , Point A , Point B) {
    if (A == B) return (P - A).len();
    Point v1 = B - A , v2 = P - A , v3 = P - B;
    if (dcmp(v1 % v2) < 0) return v2.len();
    if (dcmp(v1 % v3) > 0) return v3.len();
    return fabs(v1 ^ v2) / v1.len();
}
// 返回点在直线上的投影
Point GetLineProjection(Point P , Point A , Point B) {
    Point v = B - A;
    return A + v * (v % (P - A) / (v % v));
}
// 判断线段是否相交，没有考虑共线的情况。
bool SegmentProperIntersection(Point a1 , Point a2 , Point b1 , Point b2) {
    double c1 = (a2 - a1) ^ (b1 - a1);
    double c2 = (a2 - a1) ^ (b2 - a1);
    double c3 = (b2 - b1) ^ (a1 - b1);
    double c4 = (b2 - b1) ^ (a2 - b1);
    return dcmp(c1) * dcmp(c2) < 0 && dcmp(c3) * dcmp(c4) < 0;
}
// 点是否在线段上,判定方式为到两个端点的方向是否不一致。
bool OnSegment(Point P , Point a1 , Point a2) {
    return dcmp((a1 - P) ^ (a2 - P)) == 0 && dcmp((a1 - P) % (a2 - P)) < 0;
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
int getLineCircleIntersection(Line L , Circle C , double& t1 , double& t2 , vector<Point>& sol) {
    double a = L.V.x , b = L.P.x - C.O.x , c = L.V.y , d = L.P.y - C.O.y;
    double e = a * a + c * c , f = 2 * (a * b + c * d) , g = b * b + d * d - C.r * C.r;
    double delta = f * f - 4 * e * g;
    if (dcmp(delta) < 0) return 0;
    if (dcmp(delta) == 0)
    {
        t1 = t2 = -f / (2 * e);
        sol.push_back(L.point(t1));
        return 1;
    }
    t1 = (-f - sqrt(delta)) / (e + e);
    t2 = (-f + sqrt(delta)) / (e + e);
    sol.push_back(L.point(t1)) , sol.push_back(L.point(t2));
    return 2;
}
// 判定圆和圆之间的关系
// 内含，内切，相交，重合，外切，相离
int getCircleCircleIntersection(Circle C1 , Circle C2 , vector<Point>& sol) {
    double d = (C1.O - C2.O).len();
    if (dcmp(d) == 0)//同心
    {
        if (dcmp(C1.r - C2.r) == 0)//重合
            return -1;
        return 0;//内含
    }
    if (dcmp(C1.r + C2.r - d) < 0) return 0;//内含
    if (dcmp(fabs(C1.r - C2.r) - d) > 0) return 0; //相离

    double a = Angle(C2.O - C1.O);
    double da = acos((C1.r * C1.r + d * d - C2.r * C2.r) / (2 * C1.r * d));
    Point P1 = C1.point(a - da) , P2 = C1.point(a + da);
    sol.push_back(P1);
    if (P1 == P2) return 1; //切
    sol.push_back(P2);
    return 2;
}

// 过点p到圆C的切线。返回切线条数，sol里为方向向量
int getTangents(Point P, Circle C, vector<Point>& sol)
{
    Point u = C.O - P;
    double dist = u.len();
    if(dist < C.r) return 0;
    if(dcmp(dist - C.r) == 0)
    { // p在圆上，只有一条切线
        sol.push_back(Rotate(u, pi/2));
        return 1;
    } else {
        double ang = asin(C.r / dist);
        sol.push_back(Rotate(u, +ang));
        sol.push_back(Rotate(u, -ang));
        return 2;
    }
}
//两个圆的公切线，对应切点存在ab里面
int getTangents(Circle A , Circle B , Point* a , Point* b) {
    int cnt = 0;
    if (A.r < B.r)
        swap(A , B) , swap(a , b);
    double dist = (A.O - B.O).len() , dr = A.r - B.r , sr = A.r + B.r;
    if (dcmp(dist - dr) < 0) // 内含
        return 0;
    double base = Angle(B.O - A.O);
    if (dcmp(dist) == 0 && dcmp(A.r - B.r) == 0)
        return -1;//重合
    if (dcmp(dist - dr) == 0) {//内切
        a[cnt] = A.point(base);
        b[cnt] = B.point(base);
        return 1;
    }
    double ang = acos(dr / dist);//非上述情况，两条外公切线
    a[cnt] = A.point(base + ang) , b[cnt] = B.point(base + ang) , ++ cnt;
    a[cnt] = A.point(base - ang) , b[cnt] = B.point(base - ang) , ++ cnt;
    if (dcmp(dist - sr) == 0) {// 外切，中间一条内公切线
        a[cnt] = A.point(base) , b[cnt] = B.point(pi + base) , ++ cnt;
    } else if (dcmp(dist - sr) > 0) {
        ang = acos(sr / dist);//相离，两条内公切线
        a[cnt] = A.point(base + ang) , b[cnt] = B.point(pi + base + ang) , ++ cnt;
        a[cnt] = A.point(base - ang) , b[cnt] = B.point(pi + base - ang) , ++ cnt;
    }
    return cnt;
}
// 外接圆，三根中线交点
Circle CircumscribedCircle(Point A , Point B , Point C) {
    Point D = (B + C) / 2 , d = Normal(B - C);
    Point E = (A + C) / 2 , e = Normal(A - C);
    Point P = GetLineIntersection(D , d , E , e);
    return Circle(P , (C - P).len());
}
// 内接圆，黑科技
Circle InscribedCircle(Point A , Point B , Point C) {
    double a = (B - C).len() , b = (A - C).len() , c = (A - B).len();
    Point P = (A * a + B * b + C * c) / (a + b + c);
    return Circle(P , fabs(DistancePointToLine(P , A , B)));
}

void work()
{
    Point A , B , C , D;
    Circle X , Y;
    double d , x , y;
    vector<Point> res;
    vector<double> ans;

    char str[100];
    while (~scanf("%s" , str)) {
        if (strcmp(str , "CircumscribedCircle") == 0) {
            A.input() , B.input() , C.input();
            CircumscribedCircle(A , B , C).print();
        } else if (strcmp(str , "InscribedCircle") == 0) {
            A.input() , B.input() , C.input();
            InscribedCircle(A , B , C).print();
        } else if (strcmp(str , "TangentLineThroughPoint") == 0) {
            X.input() , A.input();
            res.clear() , ans.clear();
            getTangents(A , X , res);
            ans.resize(res.size());
            for (int i = 0 ; i < (int)res.size() ; ++ i) {
                double x = Angle(res[i]) / pi * 180;
                if (dcmp(x - 180) >= 0) x -= 180.0;
                if (dcmp(x) < 0) x += 180.0;
                ans[i] = x;
            }
            sort(ans.begin() , ans.end());
            printf("[");
            for (int i = 0 ; i < (int)res.size() ; ++ i) {
                printf("%f" , ans[i] + eps);
                if (i + 1 < (int)res.size())
                    printf(",");
            }
            printf("]\n");
        } else if (strcmp(str , "CircleThroughAPointAndTangentToALineWithRadius") == 0) {
            C.input() , A.input() , B.input();
            scanf("%lf" , &d) , res.clear() , X = Circle(C , d);
            Point Nor = Normal(B - A);
            double dist = DistancePointToLine(C , A , B);
            if (dcmp(dist) == 0) {
                res.push_back(C + Nor * d);
                res.push_back(C - Nor * d);
            } else if (dcmp(dist - d - d) == 0) {
                res.push_back(C - Nor * d);
            } else if (dcmp(dist + d + d) == 0) {
                res.push_back(C + Nor * d);
            } else {
                getLineCircleIntersection(Line(A + Nor * d , B + Nor * d) , X , x , y , res);
                getLineCircleIntersection(Line(A - Nor * d , B - Nor * d) , X , x , y , res);
            }
            sort(res.begin() , res.end());
            printf("[");
            for (int i = 0 ; i < (int)res.size() ; ++ i) {
                res[i].output();
                if (i + 1 < (int)res.size())
                    printf(",");
            }
            printf("]\n");
        } else if (strcmp(str , "CircleTangentToTwoLinesWithRadius") == 0) {
            res.clear();
            A.input() , B.input() , C.input() , D.input() , scanf("%lf" , &d);
            Point Nor1 = Normal(B - A) , Nor2 = Normal(D - C);
            res.push_back(GetLineIntersection(A + Nor1 * d , B - A , C + Nor2 * d , D - C));
            res.push_back(GetLineIntersection(A + Nor1 * d , B - A , C - Nor2 * d , D - C));
            res.push_back(GetLineIntersection(A - Nor1 * d , B - A , C + Nor2 * d , D - C));
            res.push_back(GetLineIntersection(A - Nor1 * d , B - A , C - Nor2 * d , D - C));
            sort(res.begin() , res.end());
            printf("[");
            for (int i = 0 ; i < (int)res.size() ; ++ i) {
                res[i].output();
                if (i + 1 < (int)res.size())
                    printf(",");
            }
            printf("]\n");
        } else if (strcmp(str , "CircleTangentToTwoDisjointCirclesWithRadius") == 0) {
            X.input() , Y.input() , scanf("%lf",&d);
            Circle XX = Circle(X.O , X.r + d);
            Circle YY = Circle(Y.O , Y.r + d);
            res.clear();
            getCircleCircleIntersection(XX , YY , res);
            sort(res.begin() , res.end());
            printf("[");
            for (int i = 0 ; i < (int)res.size() ; ++ i) {
                res[i].output();
                if (i + 1 < (int)res.size())
                    printf(",");
            }
            printf("]\n");
        }
    }
}

int main()
{
    freopen("1.txt" , "r" , stdin);
    freopen("ww.txt" , "w" , stdout);

    work();
    return 0;
}

