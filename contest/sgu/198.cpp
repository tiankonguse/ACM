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

const double eps = 1e-7 , pi = acos(-1.0);
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
// 逆时针旋转
Point Rotate(Point A , double rad) {
    double Sin = sin(rad) , Cos = cos(rad);
    return Point(A.x * Cos - A.y * Sin , A.x * Sin + A.y * Cos);
}
// 直线交点，v和w为两个直线的方向向量，
// 设交点的参数为P+vt,Q+wt,连立方程解t
// 线段，射线对这个t的参数有限制，很好理解。
double GetLineIntersection(Point P , Point v , Point Q , Point w) {
    Point u = P - Q;
    double t1 = (w ^ u) / (v ^ w);
    return t1;
}
double Angle(Point V) {
    return atan2(V.y , V.x);
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
    void print() {
        printf("(%f,%f,%f)\n" , O.x + eps , O.y + eps , r + eps);
    }
};

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

#define N 305
int n , F[N] , f[N] , ncnt;
Circle a[N];
Point P;
bool g[N][N] , ans ;

bool InConvex(vector<Point> C) {
    int sz = C.size();
    Point W = Rotate(P , 2.33);
    for (int i = 0 ; i < sz ; ++ i)
        C[i] = Rotate(C[i] , 2.33);
    C.push_back(C[0]);
    int cnt = 0;
    for (int i = 0 ; i < sz ; ++ i) {
        double t  = GetLineIntersection(W , Point(0 , 1) , C[i] , C[i + 1] - C[i]);
        double t1 = GetLineIntersection(C[i] , C[i + 1] - C[i] , W , Point(0 , 1));
        cnt += dcmp(t) >= 0 && dcmp(t1) >= 0 && dcmp(t1 - 1) <= 0;
    }
    return cnt & 1;
}

void dfs(int x , int fa)
{
    F[x] = fa , f[x] = ++ ncnt;
    for (int y = 1 ; y <= n ; ++ y) {
        if (g[x][y] && y != fa) {
            if (!f[y]) {
                dfs(y , x);
            } else if (f[y] < f[x]){
                vector<Point> Convex;
                int z = x;
                do {
                    Convex.push_back(a[z].O);
                    z = F[z];
                } while (z != y);
                Convex.push_back(a[z].O);
                ans |= InConvex(Convex);
            }
        }
    }
}

void work()
{
    int i , j;
    double x;
    scanf("%d",&n);
    for (i = 1 ; i <= n ; ++ i)
        a[i].input();
    P.input() , scanf("%lf",&x);
    for (i = 1 ; i <= n ; ++ i)
        a[i].r += x;
    for (i = 1 ; i <= n ; ++ i)
        for (j = i + 1 ; j <= n ; ++ j){
            vector<Point> tmp;
            if (getCircleCircleIntersection(a[i] , a[j] , tmp) > 1)
                g[i][j] = g[j][i] = 1 ;// cerr << i << ' ' << j << endl;
        }
    for (i = 1 ; i <= n ; ++ i)
        if (!f[i]) {
            dfs(i , 0);
        }
    if (ans) {
        puts("NO");
    } else {
        puts("YES");
    }
}

int main()
{
    work();
    return 0;
}
