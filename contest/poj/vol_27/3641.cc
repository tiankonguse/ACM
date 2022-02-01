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
const int maxp = 1000000;
ll pri[maxp];
int cnt;
bool mark[maxp];
int sieve(){
    int i, j, m;
    cnt = 1, pri[0] = 2, mark[4] = 1;
    for(i=3;i<maxp;i+=2){
        if(!mark[i]) pri[cnt++] = i;
        for(j=0;j<cnt,pri[j]*i<maxp;j++){
            mark[i * pri[j]] = 1;
            if(!(i % pri[j]) ) break;
        }
    }
    return cnt;
}
bool isprime(ll x){
    for(int i=0;pri[i]*pri[i]<=x;i++){
        if(x % pri[i] == 0) return false;
    }
    return true;
}
ll powMod(ll a, ll b, ll c){
    ll res = 1;
    for( ; b; a = a * a % c, b >>= 1){
        if(b & 1) res = res * a % c;
    }
    return res;
}
int main(){
    sieve();
    ll p, a;
    while(~scanf("%I64d %I64d", &p, &a)){
        if(p == 0 && a == 0) break;
        if(isprime(p)) puts("no");
        else{
            if(powMod(a, p, p) == a) puts("yes");
            else puts("no");
        }
    }
    return 0;
}
