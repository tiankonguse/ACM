struct point {
    ll x, y;
	point (){}
	point (ll x, ll y):x(x), y(y) {}
	bool operator / (point oth){return x * oth.y - y * oth.x;} //²æ³Ë>0
	point operator - (point oth) {return point(x - oth.x, y - oth.y);}
	point rot(ll a) { return point(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a)); }
	point rot90() { return point(-y, x); }
	ll length() { return hypot(x, y); }
};
bool fitInRange(point o, point a, point b) {
	if (a.x > b.x) swap(a.x, b.x);
	if (a.y > b.y) swap(a.y, b.y);
	return a.x <= o.x && o.x <= b.x && a.y <= o.y && o.y <= b.y;
}
bool onSeg(point o, point a, point b) {
	return !((b - o) / (a - o)) && fitInRange(o, a, b);
}
bool inPoly(int n, point *p, point o) {
	bool ret = 0;
	for (int i = 0; i < n; i++) {
		point a = p[i], b = p[(i + 1) % n];
		if (onSeg(o, a, b)) return 1; //ÔÚÏß¶ÎÉÏ
		if (a.y > b.y) swap(a, b);
		ret ^= a.y != b.y && a.y != o.y && a.y <= o.y && o.y <= b.y && ((b - a) / (o - a) > 0);
	}
	return ret;
}

bool cmp(point a, point b) { return a.x < b.x || (a.x == b.x && a.y < b.y); }
vector <point> convex_hull(vector <point> a) {
	vector <point> res;
	int n = a.size();
	sort(a.begin(), a.end(), cmp);
	for (int i = 0; i < n; i++) a.push_back(a[n - i - 1]);
	for (int i = 0, limit = 1; i < n * 2; i++) {
	    while ((int)res.size() > limit && (*--res.end() - *----res.end()) / (a[i] - *----res.end()) <= 0)
	        res.pop_back();
        res.push_back(a[i]);
        if (i == n - 1) limit = res.size();
	}
	res.pop_back();
	return res;
}
struct line {
	ll a, b, c;
	line() {}
	line(point p, point q) { a = p.y - q.y; b = q.x - p.x; c = -(a * p.x + b * p.y); }
	line (ll a, ll b, ll c): a(a), b(b), c(c) {}
};
ll dis_point_line(point a, line l) {
    return fabs(l.a * a.x + l.b * a.y + l.c) / sqrt(l.a * l.a + l.b * l.b);
}
int getIntersect(line a, line b, point &res) {
    double a0 = a.a, b0 = a.b, c0 = a.c;
    double a1 = b.a, b1 = b.b, c1 = b.c;
    ll tmp = point(b0, b1) / point(a0, a1);
    if (zero(tmp)) return -1;
    res.x =    point(c0, c1) / point(b0, b1) / tmp;
    res.y =  -(point(c0, c1) / point(a0, a1) / tmp);
    return 0;
}
struct segment {
	point a, b;
	segment() {}
	segment(point a, point b):a(a), b(b) {}
	ll angle() { return atan2(b.y - a.y, b.x - a.x); }
};
void getIntersect(segment a, segment b, point &res) {
    res = a.a + (a.b - a.a) * (((a.a - b.a) / (b.a - b.b)) / ((a.a - a.b) / (b.a - b.b)));
}
bool cmpSegment(segment a, segment b) {
	if (!zero(a.angle() - b.angle())) return a.angle() < b.angle();
	return (a.b - a.a) / (b.a - a.a) < 0;
}
bool equalSegment(segment a, segment b) {
    return zero(a.angle() - b.angle());
}
bool check(segment a, segment b, segment c) {
    point p;
    getIntersect(a, b, p);
    return (c.b - c.a) / (p - c.a) > 0;
}
vector <segment> halfPlaneIntersect(vector <segment> a) {
    sort(a.begin(), a.end(), cmpSegment);
    a.resize(unique(a.begin(), a.end(), equalSegment) - a.begin());
    int S = 0, T = 0, n = a.size();
    vector <segment> b(n);
    for (int i = 0; i < n; i++) {
        while (S + 1 < T && !check(b[T - 2], b[T - 1], a[i])) T--;
        while (S + 1 < T && !check(b[S], b[S + 1], a[i])) S++;
        b[T++] = a[i];
    }
    while (S + 1 < T && !check(b[T - 2], b[T - 1], b[S])) T--;
    while (S + 1 < T && !check(b[S], b[S + 1], b[T - 1])) S++;
    return vector <segment> (b.begin() + S, b.begin() + T);
}