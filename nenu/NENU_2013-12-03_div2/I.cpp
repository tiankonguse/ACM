#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
#include <cstdio>
#include <cmath>
#include <string>
#include <map>
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
#define maxn 400000
using namespace std;

#ifdef __int64
typedef __int64 LL;
#else
typedef long long LL;
#endif

LL str[maxn];
LL sum[maxn];
LL ti_me[maxn];

int main(){

    LL k;
    LL n,m;
    LL pos;
    int i,j;

    while(scanf("%lld%lld%lld",&n,&m,&k)!=EOF){
        sum[0]=ti_me[0]=0;
        for(i=1;i<=n;i++){
            scanf("%lld",&str[i]);
            sum[i]=str[i]+sum[i-1];
        }
        for(i=1;i<=m;i++){
            scanf("%lld",&ti_me[i]);
        }

        LL now = 0;
        LL pos;
        LL other;

        for(i=1;i<=m;i++){
            now = now + ti_me[i]-ti_me[i-1] - 1;
            if(now >= n){
            	printf("%lld\n",ti_me[i] - (now - n));
            	now = -1;
            	break;
            }
            LL val = sum[now-1];
            if(val<=k){
                now = 0;
                continue;
            }
            pos = upper_bound(sum+1,sum+1+n,val-k)-(sum+1);
            now = max(pos,(LL)0);
        }
        if(~now){
			 printf("%lld\n",ti_me[m]+n-now);
        }

    }
    return 0;
}

/*

5 2 4
1 2 3 4 5
4 5

1 2 3
|| 2 3

*/
