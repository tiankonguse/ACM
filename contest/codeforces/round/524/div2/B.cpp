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

LL sum(LL n) {
	LL ans = 0;

	if(n % 2 == 0) {
		ans = n/2;
	} else {
		ans = n/2 - n;
	}

	return ans;
}


int main() {


#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	LL q,l,r;
	while(~scanf("%lld", &q)) {
		while(q--) {
			scanf("%lld%lld",&l,&r);
			printf("%lld\n", sum(r) - sum(l-1));

		}
	}

	return 0;
}
