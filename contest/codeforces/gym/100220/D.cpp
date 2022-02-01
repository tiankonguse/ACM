#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define foreach(it,v) for (__typeof((v).end()) it = (v).begin(); it != (v).end(); it++)
typedef long long ll;
typedef pair <int, int> PII;

typedef double NUM;
const NUM EPS = 1e-12, MAGIC = 2.71828e18, PI = acos(-1);

inline NUM sqr(NUM a){return a*a;}
inline NUM cmp(NUM a, NUM b){
    return (1+fabs(a))*EPS<fabs(a-b)?a-b:0; // 整数几何：return a-b;
}

struct VEC {NUM x,y;} NOVEC = {MAGIC,MAGIC}; // 二维向量或坐标
struct RAY {VEC u,v;} NORAY = {NOVEC,NOVEC}; // 二维直线、射线或线段
struct CIR {VEC u; NUM r;} NOCIR = {NOVEC,MAGIC}; // 二维圆

inline NUM sqr(const VEC& a){return sqr(a.x)+sqr(a.y);}
inline NUM abs(const VEC& a){return sqrt(sqr(a));}
inline NUM cmp(const VEC& a, const VEC& b){
    NUM at=cmp(a.x,b.x);
    return !at?cmp(a.y,b.y):at;
}

inline VEC operator *(NUM u, const VEC& a){return (VEC){a.x*u,a.y*u};}
inline VEC operator *(const VEC& a, NUM u){return (VEC){a.x*u,a.y*u};}
inline VEC operator /(const VEC& a, NUM u){return (VEC){a.x/u,a.y/u};}
inline VEC operator +(const VEC& a, const VEC& b){
    return (VEC){a.x+b.x,a.y+b.y};
}
inline VEC operator -(const VEC& a, const VEC& b){
    return (VEC){a.x-b.x,a.y-b.y};
}
inline NUM operator *(const VEC& a, const VEC& b){
    return cmp(a.x*b.y,+a.y*b.x);
}
inline NUM operator %(const VEC& a, const VEC& b){
    return cmp(a.x*b.x,-a.y*b.y);
}

VEC intersect(const RAY& a, const RAY& b){
    VEC t=a.u-a.v,s=b.u-b.v;
    NUM o=s*t;
    if(!o) return NOVEC;
    return a.u+(a.u-b.u)*s/o*t;
}

struct Obstacle {
    double x0, y0, x1, y1;
    bool ru(const VEC &p) const { return !cmp(p, (VEC){x1, y1}); }
    bool rd(const VEC &p) const { return !cmp(p, (VEC){x1, y0}); }
    bool lu(const VEC &p) const { return !cmp(p, (VEC){x0, y1}); }
    bool ld(const VEC &p) const { return !cmp(p, (VEC){x0, y0}); }
    bool inside(const VEC &p) const {
        return cmp(p.x, x0) > 0 && cmp(x1, p.x) > 0 && cmp(p.y, y0) > 0 && cmp(y1, p.y) > 0;
    }
}obstacle[10];

int n, m, e;
VEC p0, p1;
VEC corner[105];
RAY sides[105];

void readVEC(VEC &a) {
    scanf("%lf%lf", &a.x, &a.y);
}

int getInsideLevel(const VEC &v, RAY r) {
    if (!cmp(r.u, v) || !cmp(r.v, v)) return 1;
    if (r.u.x > r.v.x) swap(r.u.x, r.v.x);
    if (r.u.y > r.v.y) swap(r.u.y, r.v.y);
    if (cmp(r.u.x, v.x) > 0 || cmp(v.x, r.v.x) > 0 || cmp(r.u.y, v.y) > 0 || cmp(v.y, r.v.y) > 0) return 0;
    return 2;
}

bool checkEdge(RAY r) {
    if (!cmp(r.u, r.v)) return 1;
    rep (i, e) {
        VEC res = intersect(r, sides[i]);
        if (!cmp(res, NOVEC)) continue;
        int lhs = getInsideLevel(res, r);
        int rhs = getInsideLevel(res, sides[i]);
        if (lhs < 2 || !rhs) continue;
        if (rhs == 2) { return 0; }
        bool hasL = 0, hasR = 0;
        rep (j, e) {
            VEC o;
            if (!cmp(sides[j].u, res)) {
                o = sides[j].v;
            } else if (!cmp(sides[j].v, res)) {
                o = sides[j].u;
            } else {
                continue;
            }
            NUM d = (r.u - r.v) * (o - r.v);
            hasL |= cmp(d, 0) > 0;
            hasR |= cmp(d, 0) < 0;
        }
        if (hasL && hasR) {  return 0; }
        bool flag[4] = {0};
        int c = 0;
        for (int dx = -1; dx <= 1; dx += 2) {
            for (int dy = -1; dy <= 1; dy += 2) {
                VEC cur = (VEC){res.x + 0.5 * dx, res.y + 0.5 * dy};
                rep (j, n) {
                    if (obstacle[j].inside(cur)) {
                        flag[c] = 1;
                        break;
                    }
                }
                c++;
            }
        }
        if (flag[0] && flag[3]) {  return 0; }
        if (flag[1] && flag[2]) {  return 0; }
    }
    return 1;
}

bool ok(VEC p) {
    if (!cmp(p, NOVEC)) return 0;
    rep (i, n) {
        if (obstacle[i].inside(p)) return 0;
    }
    rep (i, n) rep (j, n) {
        if ((obstacle[i].ru(p) && obstacle[j].ld(p)) || (obstacle[i].rd(p) && obstacle[j].lu(p))) {
            return 0;
        }
    }
    return checkEdge((RAY){p, p0}) && checkEdge((RAY){p, p1});
}

int main() {
	freopen("love.in", "r", stdin);
	freopen("love.out", "w", stdout);
    readVEC(p0);
    readVEC(p1);
	scanf("%d", &n);
	m = e = 0;
	rep (i, n) {
		VEC t0, t1;
		readVEC(t0);
		readVEC(t1);
		obstacle[i] = (Obstacle){t0.x, t0.y, t1.x, t1.y};
		corner[m++] = t0;
		corner[m++] = t1;
		corner[m++] = (VEC){t0.x, t1.y};
		corner[m++] = (VEC){t1.x, t0.y};
		sides[e++] = (RAY){t0, (VEC){t0.x, t1.y}};
		sides[e++] = (RAY){t0, (VEC){t1.x, t0.y}};
		sides[e++] = (RAY){t1, (VEC){t0.x, t1.y}};
		sides[e++] = (RAY){t1, (VEC){t1.x, t0.y}};
	}
	bool done = 0;
	VEC res, tmp;
	tmp = (VEC){(p0.x + p1.x) / 2, (p0.y + p1.y) / 2};
	if (ok(tmp)) {
		done = 1;
		res = tmp;
	} else {
		rep (i, m) {
			rep (j, m) {
				tmp = intersect((RAY){p0, corner[i]}, (RAY){p1, corner[j]});
				if (cmp(tmp, NOVEC) && ok(tmp)) {
					done = 1;
					res = tmp;
					goto FINISH;
				}
			}
		}
		FINISH:;
	}
	if (done) {
		puts("YES");
		printf("%.12f %.12f\n", res.x, res.y);
	} else {
		puts("NO");
	}
	return 0;
}
