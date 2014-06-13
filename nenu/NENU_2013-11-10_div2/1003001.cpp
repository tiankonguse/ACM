#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
#include<stdarg.h>
using namespace std;
#ifdef __int64
typedef __int64 LL;
#else
typedef long long LL;
#endif



int main() {
    LL a,b,i;
    LL ans,tmp,val;
    while(~scanf("%lld%lld",&a,&b)) {
        printf("%lld %lld ",a,b);
        if(a>b) {
            a^=b,b^=a,a^=b;
        }
        ans = 1;
        for(i=a; i<=b; i++) {
            val = i;
            tmp = 1;
            while(val != 1) {
                if(val%2 == 0) {
                    val /= 2;
                } else {
                    val = val*3+1;
                }
                tmp++;
            }
            if(ans < tmp) {
                ans = tmp;
            }
        }
        printf("%lld\n",ans);

    }

    return 0;
}
