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

const int MAXP=1000000;
ll pri[MAXP]; int cnt;
bool mark[MAXP];
int setp() {
    int i,j,m;
    cnt=1;pri[0]=2;mark[4]=1;
    for(i=3;i<MAXP;i+=2){   //如果要全部mark(除了1) 则i++
        if(!mark[i])pri[cnt++]=i;
        for(j=0;j<cnt,pri[j]*i<MAXP;j++){
            mark[i*pri[j]]=1;
            if(!(i%pri[j]))break;
        }
    }
    return cnt;
}

ll phi(ll n) {
  ll res = n;
	for (int i = 0; pri[i] * pri[i] <= n; ++i) {
		if(n % pri[i] == 0) {
			res = res / pri[i] * (pri[i] - 1);
			while (n % pri[i] == 0) n /= pri[i];
		}
	}
	if (n > 1) res = res / n * (n - 1);
	return res;
}

int len;

ll tst[10010];
int tnt;

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

int main() {
    setp();
    ll n; int _ca = 1;

    while (~scanf("%I64d", &n) && n) {
        ll t = n; len = 0; while (t) { ++len; t /= 10; }

        int cc = 0;
        while (n % 2 == 0) {
            n >>= 1;
            ++cc;
        }
        if (cc > 3 || n % 5 == 0) {
            printf("Case %d: 0\n", _ca++);
            continue;
        }
        n *= 9LL;
        ll r = phi(n);
        ll ret;
        tnt = 0;
        for (ll i = 1; i * i <= r; ++i) {
            if (r % i == 0) {
                tst[tnt++] = i;
                tst[tnt++] = r / i;
            }
        }
        sort(tst, tst + tnt);
        for (int i = 0; i < tnt; ++i) {
            if (powMod(10, tst[i], n) == 1) {
                ret = tst[i];
                break;
            }
        }

        printf("Case %d: %I64d\n", _ca++, ret);
    }
    return 0;
}
