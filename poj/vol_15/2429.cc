#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#define maxn 25
#define Inf 0x7FFFFFFFFFFFFFFFLL
using namespace std;
const int MAXP=1000000;
typedef __int64 ll;
ll pri[MAXP],pnt;
bool mark[MAXP];
int setp() {
    int i,j,m;
    mark[1] = 1;
    pnt=1;pri[0]=2;mark[4]=1;
    for(i=3;i<MAXP;i++){   //如果要全部mark(除了1) 则i++
        if(!mark[i])pri[pnt++]=i;
        for(j=0;j<pnt,pri[j]*i<MAXP;j++){
            mark[i*pri[j]]=1;
            if(!(i%pri[j]))break;
        }
    }
    return pnt;
}

ll gcd(ll a, ll b) {
    if(b == 0) return a;
    else return gcd(b, a % b);
}
inline ll mulMod(ll a, ll b, ll c){
    ll res = 0LL;
    for (; b; b >>= 1, a = (a << 1) % c ) {
        if (b & 1) res = (res + a) % c;
    }
    return res;
}
ll powMod(ll a, ll b, ll c){
    ll res = 1LL;
    for (; b; b >>= 1, a = mulMod(a, a, c) ) {
        if (b & 1) res = mulMod(res, a, c);
    }
    return res;
}


ll pollard_rho(ll n, ll c){
    ll d, x = rand() % n, y = x;
    for(ll i=1,k=2; ;i++){
        x = (mulMod(x, x, n) + c) % n;
        d = gcd(y - x, n);
        if (d > 1 && d < n) return d;
        if (x == y) return n;
        if (i == k) y = x, k += k;
    }
    return 0;
}
bool suspect(ll a, int s, ll d, ll n) {
    ll x = powMod(a, d, n);
    if (x == 1) return  true;
    for (int r = 0; r < s; ++r) {
        if (x == n - 1) return  true;
        x = x * x % n;
    } return  false;
}
// {2,7,61,-1} is for n < 4759123141 (= 2^32)
// {2,3,5,7,11,13,17,19,23,-1} is for n < 10^16 (at least)

bool isPrime(ll n) {
    if (n <= 1 || (n > 2 && n % 2 == 0)) return  false;
    int test[] = {2,3,5,7,11,13,17,19,23,-1};
    ll d = n - 1, s = 0;
    while (d % 2 == 0) ++s, d /= 2;
    for (int i = 0; test[i] < n && test[i] != -1; ++i)
        if (!suspect(test[i], s, d, n)) return  false;
    return  true;
}




ll divs[maxn];
ll dive[maxn];
int fun(ll n){
    int cnt = 0;
    for(int i=0;i<pnt && pri[i]*pri[i] <= n;i++){
        if(n % pri[i] == 0){
            while(n % pri[i] == 0){
                divs[cnt++] = pri[i];
                n /= pri[i];
            }
        }
    }
    if(isPrime(n)) {divs[cnt++] = n; return cnt;}
    ll r, t;
    int cc = 0;
    while(n != 1 && cc < 10){
        r = pollard_rho(n, 31);
        t = r;
        if(r < 100000000000LL){
            for(int i=0;pri[i]*pri[i] <= r;i++){
                if(r % pri[i] == 0){
                    while(r % pri[i] == 0){
                        r /= pri[i];
                        divs[cnt++] = pri[i];
                    }
                }
            }
            if(r > 1) divs[cnt++] = r;
            n /= t;
        }
        cc++;
    }

    return cnt;
}
int main(){
    setp();

    ll a, b, c;
    while(~scanf("%I64d%I64d", &a, &b)){
        if(a == b){
            printf("%I64d %I64d\n", a, b);
            continue;
        }
        if(a > b) swap(a, b);
        c = b / a;
        int cnt = fun(c);
        sort(divs, divs + cnt);
        int m = 0;
        dive[0] = divs[0];
        for(int i=1;i<cnt;i++){
            if(divs[i] == divs[i - 1]) dive[m] *= divs[i];
            else dive[++m] = divs[i];
        }
        m++;
        ll mx = Inf, x, y, rx, ry;
        for(int i=0;i<(1<<m);i++){
            x = y = a;
            for(int j=0;j<m;j++){
                if((i >> j) & 1) x *= dive[j];
                else y *= dive[j];
            }
            if(x + y < mx){
                mx = x + y;
                rx = x;
                ry = y;
            }
        }
        if(rx > ry) swap(rx, ry);
        printf("%I64d %I64d\n", rx, ry);
    }
    return 0;
}
