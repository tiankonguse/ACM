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
	char op[1000];
	int n,k,now;
	LL ans;
	while(~scanf("%d%s",&n,op)){
		k = strlen(op);
		if(n%k == 0){
			now = ans = k;
		}else{
			now = ans = n%k;
		}
		now += k;
		while(now <= n){
			ans *= now;
			now += k;
		}
		printf("%lld\n",ans);

	}

    return 0;
}
