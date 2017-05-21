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
#define maxn 32
using namespace std;
typedef __int64 ll;
ll cal(ll n){
    ll low = 1LL << n;
    ll high = 1LL << (n + 1);
    return (low + high - 1) * (high - low) / 2;
}
ll cnt[maxn];
int main(){
    int k;
    ll n, res, p, t;
    for(scanf("%d", &k); k--; ){
        scanf("%I64d", &n);
        memset(cnt, 0, sizeof(cnt));
        t = n - 1;
        for(int i=31;i>=0;i--){
            p = (1LL << i);
            if(t & p){
                cnt[i] += t - p + 1;
                for(int j=i-1;j>=0;j--){
                    cnt[j] += p >> 1;
                }
                t ^= p;
            }
        }
        //for(int i=0;i<=10;i++) printf("%d ", cnt[i]); puts("");
        res = 0;

        double r = 1.0 * n * n;
        double ans = 0;
        for(int i=31;i>=0;i--){
           // res += cnt[i] * cal(i);
            ans += 2.0 * cnt[i] * cal(i) / r;
        }
        printf("%.2lf\n", ans);
    }
    return 0;
}
