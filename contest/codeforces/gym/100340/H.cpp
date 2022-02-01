#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

typedef double NUM;
const NUM EPS = 1e-12, MAGIC = 2.71828e18, PI = acos(-1);

inline NUM sqr(NUM a){return a*a;}
inline NUM cmp(NUM a, NUM b){
	return (1+fabs(a))*EPS<fabs(a-b)?a-b:0;
}

struct VEC {NUM x,y;} NOVEC = {MAGIC,MAGIC};
struct RAY {VEC u,v;} NORAY = {NOVEC,NOVEC};

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

VEC project(const VEC& p, const RAY& l){
	VEC o=l.v-l.u;
	return (p-l.u)%o/sqr(o)*o+l.u;
}

int segment(const VEC& p, const RAY& l){
	return (p-l.u)%(p-l.v)<=0;
}

VEC intersect(const RAY& a, const RAY& b){
	VEC t=a.u-a.v,s=b.u-b.v;
	NUM o=s*t;
	if(!o) return NOVEC;
	return a.u+(a.u-b.u)*s/o*t;
}

int relation(const VEC& p, const RAY& l){
	if((p-l.u)*(p-l.v)) return 0;
	return (p-l.u)%(p-l.v)>0?1:2;
}

const int N = 105;

int n, w, x[N], y[N];
double f[N][2];

VEC minp2seg(VEC p, int k) {
	RAY l = {(VEC){x[k], y[k]}, (VEC){x[k], y[k]+w}};
	//p = project(p, l);
//	printf("p = (%.2f, %.2f), l = (%.2f, %.2f) -> (%.2f, %.2f)\n",p.x,p.y,l.u.x,l.u.y,l.v.x,l.v.y);
	if(segment(project(p, l), l)) {
		return project(p, l);
	} else {
		if(abs(l.u-p) < abs(l.v-p)) return l.u;
		return l.v;
	}
}

/*
bool check(const VEC& u, const VEC& v) {
	RAY l1 = {u, v};
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < 2; ++j) {
			VEC p0 = {x[i], y[i]+j*w};
			VEC p1 = {x[i+1], y[i+1]+j*w};
			RAY l2 = {p0, p1};
			VEC c = intersect(l1, l2);
			if(!cmp(c, p0) || !cmp(c, p1)) continue;
			if(cmp(c, NOVEC) && segment(c, l1) && segment(c, l2)) {
				return false;
			}
		}
	}
	return true;
}
*/

bool check(const VEC& u, const VEC& v, int p, int q) {
	RAY l1 = {u, v};
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < 2; ++j) {
			VEC p0 = {x[i], y[i]+j*w};
			VEC p1 = {x[i+1], y[i+1]+j*w};
			RAY l2 = {p0, p1};
			VEC c = intersect(l1, l2);
			if(!cmp(c, p0) || !cmp(c, p1)) continue;
			if(cmp(c, NOVEC) && segment(c, l1) && segment(c, l2)) {
				return false;
			}
		}
	}
	for(int i = p; i <= q; ++i) {
		VEC p0 = {x[i], y[i]};
		VEC p1 = {x[i], y[i]+w};
		RAY l2 = {p0, p1};
		VEC c = intersect(l1, l2);
		if(cmp(c, NOVEC) && segment(c, l1) && segment(c, l2)) {
			;
		} else return false;
	}
	return true;
}

double gao() {
	int maxy = -1000000, miny = 1000000;
	for(int i = 0; i <= n; ++i) {
		miny = min(miny, y[i]);
		maxy = max(maxy, y[i]);
	}
	miny += w;
	if(miny >= maxy) return x[n] - x[0];
	double ans = 1e50;
	for(int i = 0; i < 2; ++i) {
		VEC p0 = {x[0], y[0]+i*w};
		for(int j = 0; j < 2; ++j) {
			VEC p1 = {x[n], y[n]+j*w};
			if(check(p0, p1, 0, n)) {
				ans = min(ans, abs(p0-p1));
			}
		}
	}
	for(int i = 1; i < n; ++i) for(int j = 0; j < 2; ++j) {
		VEC p0, p1 = {x[i], y[i]+j*w};
		// from begin
		p0 = minp2seg(p1, 0);
		if(check(p0, p1, 0, i)) {
			f[i][j] = min(f[i][j], abs(p0-p1));
		}
		// from mid
		for(int k = 1; k < i; ++k) for(int l = 0; l < 2; ++l) {
			p0 = (VEC){x[k], y[k]+l*w};
			if(check(p0, p1, k, i)) {
				f[i][j] = min(f[i][j], f[k][l]+abs(p0-p1));
			}
		}
//		printf("f[%d][%d] = %.6f\n",i,j,f[i][j]);
		p0 = minp2seg(p1, n);
		if(check(p0, p1, i, n)) {
	//		printf("%.6f + %.6f\n",f[i][j],abs(p0-p1));
			ans = min(ans, f[i][j]+abs(p0-p1));
		}
	}
	return ans;
}

int main() {
	freopen("race.in","r",stdin);
	freopen("race.out","w",stdout);
	scanf("%d", &n);
	for(int i = 0; i <= n; ++i) {
		scanf("%d%d", x+i, y+i);
		f[i][0] = f[i][1] = 1e50;
	}
	scanf("%d", &w);
	printf("%.12f\n", gao());
}
