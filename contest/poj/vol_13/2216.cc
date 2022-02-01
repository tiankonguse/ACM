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
#define maxn 1001000
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
ll MLES(ll a,ll b,ll n){
    ll d,x,y;
    d=Extended_Euclid(a,n,&x,&y);
    ll x0;
    if(b%d==0){
               x0=(x*b/d)%n;
    }
    else return -1;
    return x0>=0?x0:x0+n;
}
ll num[maxn];
int main(){
    int T, n;
    for(scanf("%d", &T);T--;){
        scanf("%d", &n);
        for(int i=0;i<n;i++){
            scanf("%I64d", &num[i]);
        }
        if(n == 1) puts("Dalsi cislo nelze urcit.");
        else{
            bool flag = true;
            ll t, res = -1;
            for(int i=1;i<n;i++){
                t = MLES(num[i-1], num[i], 47LL);
                if(res == -1) res = t;
                else if(res != t){
                    flag = false;
                    break;
                }
            }
            if(!flag) puts("Algoritmus byl zmenen.");
            else{
                printf("Vsad na %d.\n", num[n-1] * res % 47LL);
            }
        }
    }
    return 0;
}
