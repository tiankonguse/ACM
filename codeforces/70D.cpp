#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <string>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define foreach(it,v) for (__typeof((v).end()) it = (v).begin(); it != (v).end(); it++)
typedef long long ll;
typedef pair <int, int> PII;
const int N = 100005;
const double eps = 1e-10;
const double INF = 1e9;

int sgn(double x) {
    if (x > eps) return 1;
    if (x < -eps) return -1;
    return 0;
}

struct Point {
    double x, y;
    int id;
    void read() {
        scanf("%lf%lf", &x, &y);
    }
    Point(): x(0), y(0) {}
    Point(double x, double y): x(x), y(y) {}

    bool operator < (const Point &oth) const {
        if (sgn(x - oth.x) == 0) {
            return sgn(oth.y - y) > 0;
        } else {
            return sgn(oth.x - x) > 0;
        }
    }
    double operator / (const Point &oth) const { return x * oth.y - y * oth.x; }
    Point operator - (const Point &oth) const { return Point(x - oth.x, y - oth.y); }
    Point operator + (const Point &oth) const { return Point(x + oth.x, y + oth.y); }
    Point rot() const { return Point(-y, x); }
    Point neg() const { return Point(-x, -y); }
    double len() const { return hypot(x, y); }
};

struct Line {
    Point u, v;

    Line() {}
    Line(Point u, Point v): u(u), v(v) {}

    bool operator < (const Line &oth) const {
        Point lhs = v - u, rhs = oth.v - oth.u;
        return sgn(rhs / lhs) > 0;
    }

    Line neg() const { return Line(u.neg(), v.neg()); }
};


int n;
Point a[N], b[N];
Line c[N];

Point resize(Point p, double len) {
    double mul = len / p.len();
    p.x *= mul;
    p.y *= mul;
    return p;
}

bool isLEQ(Point u, Point v, Point o) {
    return sgn((v - u) / (o - u)) >= 0;
}

bool isLhs(Point u, Point v, Point o) {
    return sgn((v - u) / (o - u)) > 0;
}

bool isValid(set <Line> &sl, set <Point> &sp, Line l) { //Does all points lie on the left hand side of vector l?
    if (sp.size() > 1u) {
        auto it = sl.lower_bound(l);
        if (it == sl.end())
            return !isLEQ(l.v, l.u, (--it)->u);
        return !isLEQ(l.v, l.u, it->v);
    } else {
        for (auto p : sp)
            if (isLEQ(l.v, l.u, p))
                return false;
        return true;      
    }
}

bool isInside(Point p, set <Point> &sp) {
    if (sp.empty()) return 0;
    if (sgn(p.x - sp.begin()->x) < 0 || sgn(p.x - (--sp.end())->x) > 0) return 0;
    auto it = sp.lower_bound(Point(p.x, -INF));
    if (sgn(it->x - p.x) == 0) {
        return sgn(it->y - p.y) >= 0;
    } else {
        auto prev = it;
        prev--;
        return isLEQ(*it, *prev, p);
    }
}

void erasePoint(set <Line> &sl, set <Point> &sp, set <Point>::iterator it) {
    auto tmp = it;
    bool lhs = 0, rhs = 0;
    if (++(tmp = it) != sp.end()) {
        rhs = 1;
        sl.erase(Line(*tmp, *it));
    }
    if (it != sp.begin()) {
        lhs = 1;
        sl.erase(Line(*it, *--(tmp = it)));
    }
    if (lhs && rhs) {
        auto tmp2 = tmp = it;
        tmp--;
        tmp2++;
        sl.insert(Line(*tmp2, *tmp));
    }
    sp.erase(it);
}

void insertPoint(set <Line> &sl, set <Point> &sp, Point p) {
    if (isInside(p, sp)) return;
    auto it = sp.lower_bound(Point(p.x, -INF)), tmp = it;
    if (it != sp.end() && sgn(it->x - p.x) == 0) {
        erasePoint(sl, sp, it);
    }
    for (it = sp.lower_bound(p); it != sp.end() && ++(tmp = it) != sp.end() && !isLhs(*tmp, *it, p); erasePoint(sl, sp, it++));
    if ((it = sp.lower_bound(p)) != sp.begin()) {
        for (--it; it != sp.begin() && !isLhs(*it, *--(tmp = it), p); ) {
            erasePoint(sl, sp, it--);
        }
    }
    it = sp.lower_bound(p);
    if (it != sp.end() && it != sp.begin()) {
        sl.erase(Line(*it, *--(tmp = it)));
    }
    if (it != sp.end()) {
        sl.insert(Line(*it, p));
    }
    if (it != sp.begin()) {
        sl.insert(Line(p, *--(tmp = it)));
    }
    sp.insert(p);
}

bool cmp(const Point &a, const Point &b) {
    return a.len() < b.len();
}

int main() {
    scanf("%d", &n);
    set <Line> ul, dl;
    set <Point> up, dp;
    rep (i, n) {
        Point p;
        int t;
        scanf("%d", &t);
        p.read();
        if (t == 1) {
            insertPoint(ul, up, p);
            insertPoint(dl, dp, p.neg());
        } else {
            if (isInside(p, up) && isInside(p.neg(), dp)) {
                puts("YES");
            } else {
                puts("NO");
            }
        }
    }
    return 0;
}