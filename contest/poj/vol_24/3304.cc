#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <complex>
#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define x real()
#define y imag()
#define maxn 105
using namespace std;
const double eps = 1e-8;
typedef complex<double> Point;
inline int sgn(double a){ return (a > eps) - (a < -eps);}
inline bool equal(Point a, Point b){ return sgn(a.x - b.x) == 0 && sgn(a.y - b.y) == 0;}
double cross(Point a, Point b){ return imag(conj(a) * b);}
double dmul(Point a, Point b){ return real(conj(a) * b);}
bool crosspoint(Point p1, Point p2, Point q1, Point q2){
    double a = cross(p2 - p1, q2 - q1), b = cross(p2 - p1, p2 - q1), c = cross(q2 - q1, p2 - p1), d = cross(q2 - q1, q2 - p1);
    if(a == 0) return b == 0? 1: 0;
    else return (sgn(b/a) >= 0 && sgn(b/a - 1) <= 0);
}

Point p[maxn][2], t1, t2;

int main(){
  int T, n;
	for(scanf("%d", &T);T--;){
		scanf("%d", &n);
		for(int i=0;i<n;i++){
            scanf("%lf%lf%lf%lf", &p[i][0].x, &p[i][0].y, &p[i][1].x, &p[i][1].y);
		}
		if(n <= 2) puts("Yes!");
		else{
			bool flag = false;
			for(int i=0;i<n;i++){
				flag = true;
				for(int j=0;j<n;j++){
					if(j == i) continue;
					flag &= crosspoint(p[i][0], p[i][1], p[j][0], p[j][1]);
					if(!flag) break;
				}
				if(flag){
					break;
				}
				for(int k=0;k<2;k++){
					t1 = p[i][k];
					for(int j=i+1;j<n;j++){
						for(int jk=0;jk<2;jk++){
							t2 = p[j][jk];
							if(equal(t1, t2)) continue;
							flag = true;
							for(int l=0;l<n;l++){
								if(l == i || l == j) continue;
								flag &= crosspoint(t1, t2, p[l][0], p[l][1]);
								if(!flag) break;
							}
							if(flag) goto tag;
						}
					}
				}
			}
tag:
			if(flag) puts("Yes!");
			else puts("No!");
		}
	}
    return 0;
}
