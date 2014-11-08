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
typedef long double real;
const int N = 100005;
const real eps = 1e-16;
const real INF = 1e9;

/*
int sgn(real x) {
    if (x > eps) return 1;
    if (x < -eps) return -1;
    return 0;
}
*/
inline real cmp(real a, real b){
    return (1+fabs(a))*eps<fabs(a-b)?a-b:0; // 整数几何：return a-b;
}

struct Point {
    real x, y;
    int id;
    void read() {
        cin >> x >> y;
    }
    Point(): x(0), y(0) {}
    Point(real x, real y): x(x), y(y) {}

    bool operator < (const Point &oth) const {
        if (cmp(x, oth.x) == 0) {
            return cmp(oth.y, y) > 0;
        } else {
            return cmp(oth.x, x) > 0;
        }
    }
    real operator / (const Point &oth) const { return cmp(x * oth.y, y * oth.x); }
    Point operator - (const Point &oth) const { return Point(x - oth.x, y - oth.y); }
    Point operator + (const Point &oth) const { return Point(x + oth.x, y + oth.y); }
    Point rot() const { return Point(-y, x); }
    Point neg() const { return Point(-x, -y); }
    real len() const { return hypot(x, y); }
};

struct Line {
    Point u, v;

    Line() {}
    Line(Point u, Point v): u(u), v(v) {}

    bool operator < (const Line &oth) const {
        Point lhs = v - u, rhs = oth.v - oth.u;
        return (rhs / lhs) > 0;
    }

    Line neg() const { return Line(u.neg(), v.neg()); }
};


int n;
Point a[N], b[N];
Line c[N];

Point resize(Point p, real len) {
    real mul = len / p.len();
    p.x *= mul;
    p.y *= mul;
    return p;
}

bool isLEQ(Point u, Point v, Point o) {
    return (v - u) / (o - u) >= 0;
}

bool isLhs(Point u, Point v, Point o) {
    return (v - u) / (o - u) > 0;
}

//Does all points lie on the left hand side of vector l?(On l is not OK)
bool isValid(set <Line> &sl, set <Point> &sp, Line l) {
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
//Does p in upper side convex hull sp ?
bool isInside(Point p, set <Point> &sp) {
    if (sp.empty()) return 0;
    if (cmp(p.x, sp.begin()->x) < 0 || cmp(p.x, (--sp.end())->x) > 0) return 0;
    auto it = sp.lower_bound(Point(p.x, -INF));
    if (cmp(it->x, p.x) == 0) {
        return cmp(it->y, p.y) >= 0;
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
    if (it != sp.end() && cmp(it->x, p.x) == 0) {
        erasePoint(sl, sp, it++);
    }
    for (; it != sp.end() && ++(tmp = it) != sp.end() && !isLhs(*tmp, *it, p); ) {
        erasePoint(sl, sp, it++);
    }
    if (it != sp.begin()) {
        for (--it; it != sp.begin() && !isLhs(*it, *--(tmp = it), p); ) {
            erasePoint(sl, sp, it--);
        }
        it++;
    }
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

bool cmpLength(const Point &a, const Point &b) {
    return a.len() < b.len();
}

int main() {
    freopen("nothingontv.in", "r", stdin);
#ifndef DEBUG
    freopen("nothingontv.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin >> n;
    rep (i, n) {
        a[i].read();
        a[i].id = i;
    }
    sort(a, a + n, cmpLength);
    rep (i, n) {
        real len = 1e5 / a[i].len();
        b[i] = resize(a[i], len);
        c[i] = Line(b[i], a[i].rot() + b[i]);
    }
    set <Line> ul, dl;
    set <Point> up, dp;
    vector <int> ans;
    rep (i, n) {
        bool ok;
        if (c[i].u.x > c[i].v.x) {
            ok = isValid(ul, up, c[i]);
        } else {
            ok = isValid(dl, dp, c[i].neg());
        }
        if (ok) {
            insertPoint(ul, up, b[i]);
            insertPoint(dl, dp, b[i].neg());
            ans.push_back(a[i].id + 1);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    rep (i, ans.size()) cout << ans[i] << " ";
    cout << endl;
    return 0;
}