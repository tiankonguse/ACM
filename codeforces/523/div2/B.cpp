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

LL str[110000];

int main() {


#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	LL n, m;
	while(~scanf("%lld%lld", &n,&m)) {
		for(int i=0; i<n; i++) {
			scanf("%lld", &str[i]);
		}
		sort(str, str+n);

		LL ans = 0;
		LL lev = 0;
		for(int i=0; i<n; i++) {
			//printf("i[%d] Value=%lld\n", i, str[i]);
			if(i == n-1) {
				if(str[i] > lev){
					ans += lev;
			//	printf("i[%d] remove=%lld\n", i, lev);
				}else{
					ans += lev -1;
			//	printf("i[%d] remove=%lld\n", i, lev-1);
				}
			} else {
				if(str[i] > lev) {
					//可以贡献一个位置
				//	printf("add lev = %lld\n", lev);
					lev++;
				}
				//至少留一个
			//	printf("i[%d] remove=%lld\n", i, str[i] - 1);
				ans += str[i] - 1;
			}
		}
		printf("%lld\n", ans);


	}


	return 0;
}
