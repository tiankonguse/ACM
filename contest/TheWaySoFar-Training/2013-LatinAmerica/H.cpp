#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cassert>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
using namespace std;
typedef long long LL;
#define N 10005
int S , K , W;
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
double Angle(Point V) {
    double A = atan2(V.y , V.x);
    return A < 0 ? A + pi + pi : A;
}
Point a[N] , w[N][2];
struct event {
    int type;
    double arc;
    int x;
    event(int _T , double _A , int _x) {
        type = _T , arc = _A , x = _x;
    }
    bool operator < (const event& R) const {
        return arc < R.arc;
    }
};
double Arc , Dis;
Point Vec;
double GetLineIntersection(Point Q , Point w) {
    Point u = Point(0 , 0) - Q;
    double t1 = (w ^ u) / (Vec ^ w);
    return t1;
}

struct Segment {
    int id;
    Segment (int _id) {
        id = _id;
    }
    bool operator < (const Segment& R) const {
        double L1 = id == W ? Dis : GetLineIntersection(w[id][0] , w[id][1] - w[id][0]);
        double L2 = R.id == W ? Dis : GetLineIntersection(w[R.id][0] , w[R.id][1] - w[R.id][0]);
        return L1 < L2;
    }
};

void cal(int X) {
    int i;
    Point O = a[X];
    for (i = 0 ; i < K ; ++ i)
        a[i] = a[i] - O;
    for (i = 0 ; i < W ; ++ i)
        w[i][0] = w[i][0] - O , w[i][1] = w[i][1] - O;

    vector<event> E;
    for (i = 0 ; i < K ; ++ i)
        if (i != X)
            E.push_back(event(0 , Angle(a[i]) , i));
    int res = 0; set<Segment> hash;
    for (i = 0 ; i < W ; ++ i) {
        double AA = Angle(w[i][0]);
        double BB = Angle(w[i][1]);
        if (AA > BB) {
            swap(w[i][0] , w[i][1]);
            swap(AA , BB);
        }
        if (dcmp(BB - AA - pi) >= 0) {
            //E.push_back(event(1 , 0 , i));
            hash.insert(Segment(i));
            E.push_back(event(2 , AA , i));
            E.push_back(event(1 , BB , i));
            //E.push_back(event(2 , pi + pi , i));
        } else {
            E.push_back(event(1 , AA , i));
            E.push_back(event(2 , BB , i));
        }
    }
    sort(E.begin() , E.end());
    for (i = 0 ; i < E.size() ; ++ i) {
        Arc = E[i].arc;
        Vec = Point(cos(Arc) , sin(Arc));
        if (E[i].type == 0) {
            Dis = a[E[i].x].len();
            if (hash.lower_bound(Segment(W)) == hash.begin())
                ++ res;
        } else if (E[i].type == 1) {
            hash.insert(Segment(E[i].x));
        } else {
            hash.erase(Segment(E[i].x));
        }
    }
    printf("%d\n" , res);
    for (i = 0 ; i < K ; ++ i)
        a[i] = a[i] + O;
    for (i = 0 ; i < W ; ++ i)
        w[i][0] = w[i][0] + O , w[i][1] = w[i][1] + O;
}

void work(){
    int i ;
    for (i = 0 ; i < K ; ++ i)
        a[i].input();
    for (i = 0 ; i < W ; ++ i)
        w[i][0].input() , w[i][1].input();
    for (i = 0 ; i < S ; ++ i)
        cal(i);
}

int main(){
    while (~scanf("%d%d%d",&S,&K,&W))
        work();
    return 0;
}
