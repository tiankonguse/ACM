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
bool check(ll n, ll a, ll b){
    ll t = 0;
    while(n){
        t += n / a;
        if(t >= b) return true;
        n /= a;
    }
    return false;
}

int main(){
    ll n, m;
    while(~scanf("%I64d%I64d", &n, &m)){
        if(m == 0) printf("%I64d does not divide %I64d!\n", m, n);
        else if(n >= m) printf("%I64d divides %I64d!\n", m, n);
        else{
            ll t = m, cnt;
            bool flag = true;
            for(ll i=2;i*i<=t;i++){
                cnt = 0;
                while(t % i == 0){
                    t /= i;
                    cnt++;
                }
                if(cnt){
                    flag &= check(n, i, cnt);
                    if(!flag) break;
                }
            }
            if(t != 1) flag &= check(n, t, 1);
            if(flag) printf("%I64d divides %I64d!\n", m, n);
            else printf("%I64d does not divide %I64d!\n", m, n);
        }
    }
    return 0;
}
