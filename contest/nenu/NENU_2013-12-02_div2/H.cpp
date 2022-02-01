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

const int N = 1000;
int str[N];
int n,k;
int ans;

int main() {
    while(~scanf("%d",&n)) {
        for(int i=0; i<n; i++) {
            scanf("%d",&str[i]);
        }
        sort(str,str+n);
        k = (n+1)/2;
        ans = 0;
        for(int i=0;i<k;i++){
			ans += (str[i]+1)/2;
        }
        printf("%d\n",ans);
    }

    return 0;
}
