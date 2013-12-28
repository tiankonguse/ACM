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


LL getLen(LL m){
	LL res = 0;
	while(m){
		res++;
		m /= 10;
	}
	return res;
}


LL getLenMaxVal(LL m){
	LL res = 1;
	while(m){
		res *= 10;
		m--;
	}
	return res;
}

int main() {
	LL n,m,k,w;
	LL ans,now,num,realNum,len;
	while(~scanf("%lld%lld%lld",&w,&m,&k)){
		ans = 0;
		len = getLen(m);
		now = getLenMaxVal(len);
		while(1){
			num = now - m;
			realNum = w/(len*k);

			if(realNum > num){
				ans += num;
				m = now;
				w = w - len * k* num;
				len++;
				now *= 10;
			}else{
				ans += realNum;
				break;
			}

		}
		printf("%lld\n",ans);
	}

    return 0;
}
