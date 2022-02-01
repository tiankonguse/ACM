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

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL

using namespace std;
typedef __int64 ll;
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}
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
ll MLES(ll a,ll b,ll n){
    ll d,x,y;
    d=Extended_Euclid(a,n,&x,&y);
    ll x0;
    if(b%d==0){
               x0=(x*b/d)%n+n;
    }
    else return -1;
    return x0%(n/d);
}
int main() {
    ll a, b, c, k;
    while (~scanf("%I64d %I64d %I64d %I64d", &a, &b, &c, &k)) {
        if (a == 0 && b == 0 && c == 0 && k == 0) break;
        ll mod = 1LL << k;
        ll ret = MLES(c, b - a, mod);
        if (ret == -1) puts("FOREVER");
        else printf("%I64d\n", ret);
    }
    return 0;
}
