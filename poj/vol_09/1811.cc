#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <ctime>

#define inf 0x3f3f3f3f
#define INF 0x3FFFFFFFFFFFFFFFLL
#define maxn 100100
using namespace std;
typedef long long ll;
inline ll mulMod(ll a, ll b, ll c){
    ll res = 0LL;
    for(; b; b >>= 1, a = (a << 1) % c ) {
        if(b & 1) res = (res + a) % c;
    }
    return res;
}
inline ll powMod(ll a, ll b, ll c){
    ll res = 1LL;
    for(; b; b >>= 1, a = mulMod(a, a, c) ){
        if(b & 1) res = mulMod(res, a, c);
    }
    return res;
}
bool suspect(ll a, int s, ll d, ll n) {
  ll x = powMod(a, d, n);
  if (x == 1) return true;
  for (int r = 0; r < s; ++r) {
    if (x == n - 1) return true;
    x = x * x % n;
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
//void find(ll n){
//    if(isPrime(n)) divs[cnt++] = n;
//    else{
//        ll d;
//        while((d = pollard_rho(n, rand() % n)) == n);
//        find(d), find(n / d);
//    }
//}
ll que[maxn << 1];
set<ll> st;
void find(ll n){
    ll l = 0, h = 0, t, d;
    que[h++] = n;
    st.clear();
    st.insert(n);
    while(l != h){
        t = que[l++]; if(l == maxn) l = 0;
     //   cout<<t<<endl; system("pause");
        if(isPrime(t)) divs[cnt++] = t;
        else{
            while((d = pollard_rho(t, rand() % t)) == t);
            if(st.find(d) == st.end()) {que[h++] = d; if(h == maxn) h = 0;}
            if(st.find(t / d) == st.end()) {que[h++] = t / d; if(h == maxn) h = 0;}
        }
    }
}
int main(){
    int T, res;
    ll n;
    srand(time(0));
    for(scanf("%d", &T);T--;){
        scanf("%I64d", &n);
        if(isPrime(n)) puts("Prime");
        else{
            cnt = res = 0;
            find(n);
            for(int i=1;i<cnt;i++){
                if(divs[i] < divs[res]) res = i;
            }
            printf("%I64d\n", divs[res]);
        }
    }
    return 0;
}
