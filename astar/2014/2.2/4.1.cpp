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
const int N = 10000010;
LL str[N];


int main() {
    int t;
    LL a,b,c,ans,n,i;
    scanf("%d",&t);
    for(int i=1; i<=t; i++) {
        scanf("%I64d",&n);
        ans = 1 + n;
        for(i=1;i<n;i+=2){

        }
        printf("Case #%d:\n%I64d\n",i,ans);
    }

    return 0;
}
