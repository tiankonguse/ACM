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

    int t;
    LL a,b,c,ans;
    scanf("%d",&t);
    for(int i=1; i<=t; i++) {
        scanf("%I64d",&a);
        b = a+1;
        if(a%2 == 0) {
            c = a/2;
            ans = c*b+1;
            ans += (a/2)*(a/2) - (a-1);
        } else {
            c = b/2;
            ans = a*c+1;
            ans += (a/2)*(a/2 + 1) - (a-1);

        }
        printf("Case #%d:\n%I64d\n",i,ans);
    }

    return 0;
}
