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

const int debug = 0;
typedef unsigned uint;
typedef unsigned char uchar;


int main() {


#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif

	LL n,k, ans;
	while(~scanf("%lld%lld",&n,&k)){
		ans = 0;
		ans += (n * 2 + k - 1)/k;
		ans += (n * 5 + k - 1)/k;
		ans += (n * 8 + k - 1)/k;
		printf("%d\n", ans);
	}

    return 0;
}
