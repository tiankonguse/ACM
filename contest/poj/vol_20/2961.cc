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
int base[2][2] = {1, 1, 1, -1};
int fun(ll x, ll y){
   // printf("f(%I64d, %I64d)\n", x, y);
    if(x <= 1 && y <= 1) return base[x][y];
    int p = 62, q = 62;
    while(((1LL << p) & x) == 0 && p) p--;
    while(((1LL << q) & y) == 0 && q) q--;
    ll s = max(1LL << p, 1LL << q);
    if(x >= s && y >= s) return -fun(x - s, y - s);
    else if(x >= s) return fun(x - s, y);
    else if(y >= s) return fun(x, y - s);
}
int main(){
    int t;
    ll n, x, y, w, h;
    for(scanf("%d", &t); t--; ){
        scanf("%I64d %I64d %I64d %I64d %I64d", &n, &x, &y, &w, &h);
        for(ll i=y;i<y+h;i++){
            for(ll j=x;j<x+w;j++){
                //printf("%I64d, %I64d = %d\n", i, j, fun(i,j));
                if(j == x + w - 1) printf("%d\n", fun(i, j));
                else printf("%d ", fun(i, j));
            }
        }
        puts("");
    }
    return 0;
}
