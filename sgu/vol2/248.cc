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
#include <ctime>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
using namespace std;
typedef __int64 ll;
ll Extended_Euclid(ll a,ll b,ll *x,ll *y){
    if(b==0){
             *x=1;
             *y=0;
             return a;
    }
    ll d=Extended_Euclid(b,a%b,x,y);
    ll t=*x;
    *x=*y;
    *y=t-a/b*(*y);
    return d;
}
ll gcd(ll a, ll b) {
  return b == 0 ? a : gcd(b, a % b);
}
ll c[10], v;

ll solve(ll s) {
	ll a = c[0], b = c[1];
	if (a > b) swap(a, b);
	ll g = gcd(a, b);
	if (s % g != 0) return -1;
	s /= g, a /= g, b /= g;
	ll x, y;
	Extended_Euclid(a, b, &x, &y);
	x *= s, y *= s;
	//cout << x << "," << y << endl;
	if (x > 0) {
		ll t = x / b;
		x -= t * b;
		y += t * a;
		//cout<<"t="<<t<<endl;
		if (y >= 0) {
			return  (x + y);
		}
		else return -1;
	}
	else {
		ll t = -x / b;
		x += t * b;
		y -= t * a;
		if (x < 0) {
			x += b;
			y -= a;
		}
		if (y >= 0) {
			return  (x + y);
		}
		else return -1;
	}
}
int main() {
	int n;
	while (~scanf("%d", &n)) {
		for (int i = 0; i < n; ++i) scanf("%I64d", &c[i]);
		scanf("%I64d", &v);
		if (n == 1) {
			if (v % c[0] == 0) printf("%I64d\n", v / c[0]);
			else puts("-1");
		}
		else if (n == 2) {
			printf("%I64d\n", solve(v));
		}
		else {
			ll ret = Inf;
			for (ll i = 0; ; ++i) {
				ll vp = v - c[2] * i;
				if (vp < 0) break;
				ll tr = solve(vp);
				if (tr != -1) ret = min(ret, i + tr);
			}
			if (ret == Inf) puts("-1");
			else printf("%I64d\n", ret);
		}
	}	
    return 0;
}
