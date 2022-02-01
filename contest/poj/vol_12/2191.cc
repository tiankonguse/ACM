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
#define maxn 100100
using namespace std;
typedef long long ll;

inline ll mulMod(ll a, ll b, ll c){
    ll res = 0LL;
    for(; b > 0; b >>= 1, a = (a << 1) % c ) {
        if(b & 1) res = (res + a) % c;
    }
    return res;
}
inline ll powMod(ll a, ll b, ll c){
    ll res = 1LL;
    for(; b > 0; b >>= 1, a = mulMod(a, a, c) ){
        if(b & 1) res = mulMod(res, a, c);
    }
    return res;
}
bool suspect(ll a, int s, ll d, ll n) {
  ll x = powMod(a, d, n);
  if (x == 1) return true;
  for (int r = 0; r < s; ++r) {
    if (x == n - 1) return true;
    x = mulMod(x, x, n);
  }
  return false;
}
// {2,7,61,-1}                 is for n < 4759123141 (= 2^32)
// {2,3,5,7,11,13,17,19,23,-1} is for n < 10^16 (at least)
bool isPrime(ll n) {
  if (n <= 1 || (n > 2 && n % 2 == 0)) return false;
  int test[] = {2,3,5,7,11,13,17,19,23,-1};
  ll d = n - 1, s = 0;
  while (d % 2 == 0) ++s, d /= 2;
  for (int i = 0; test[i] < n && test[i] != -1; ++i)
    if (!suspect(test[i], s, d, n)) return false;
  return true;
}
inline ll gcd(ll a, ll b){
    return b == 0? a : gcd(b, a % b);
}
ll pollard_rho(ll n, ll c){
    ll d, x = rand() % n, y = x;
    for(ll i=1,k=2;;i++){
        x = (mulMod(x, x, n) + c) % n;
        d = gcd(y - x, n);
        if(d > 1 && d < n) return d;
        if(x == y) return n;
        if(i == k) y = x, k += k;
    }
    return 0;
}
ll divs[maxn];
int cnt;
void find(ll n){
    if(isPrime(n)) divs[cnt++] = n;
    else{
        ll d;
        while((d = pollard_rho(n, rand() % n)) == n);
        find(d), find(n / d);
    }
}

int main(){
    ll k, t;
    while(~scanf("%I64d", &k)){
        for(ll i=2;i<=k;i++){
            if(!isPrime(i)) continue;
            t = (1LL << i) - 1;
            cnt = 0;
            find(t);
            if(cnt > 1){
                sort(divs, divs + cnt);
                printf("%I64d ", divs[0]);
                for(int j=1;j<cnt;j++){
                    printf("* %I64d ", divs[j]);
                }
                printf("= %I64d = ( 2 ^ %I64d ) - 1\n", t, i);
            }
        }
    }
    return 0;
}
