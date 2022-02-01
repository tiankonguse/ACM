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
struct fractions{
    ll x, y;
    fractions(ll _x, ll _y){
        x = _x, y = _y;
    }
    fractions() {}
    void shrink(){
        ll g = __gcd(x, y);
        x /= g;
        y /= g;
    }
    fractions operator+(fractions b){
        fractions c;
        c.y = (*this).y * b.y;
        c.x = (*this).x * b.y + (*this).y * b.x;
        c.shrink();
        return c;
    }
}a, b;
inline int getLen(ll n){ return n ? getLen(n / 10) + 1 : 0; }
int main(){
    int n;
    while(~scanf("%d", &n)){
        a = fractions(0, 1);
        for(int i=1;i<=n;i++){
            a = a + fractions(n, i);
        }
        if(a.y == 1) printf("%d\n", a.x);
        else{
            ll p = a.x / a.y;
            int pl = getLen(p);
            int ql = getLen(a.y);
            a.x %= a.y;
            for(int i=0;i<pl+1;i++) putchar(32);
            printf("%I64d\n", a.x);
            printf("%I64d ", p);
            for(int i=0;i<ql;i++) putchar('-'); puts("");
            for(int i=0;i<pl+1;i++) putchar(32);
            printf("%I64d\n", a.y);
        }
    }
    return 0;
}
