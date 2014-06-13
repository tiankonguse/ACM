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

	LL str[20][2];
	int n,k;
	while(~scanf("%d%d",&n,&k)){

		str[1][0] = 0;
		str[1][1] = k-1;

		for(int i=2;i<=n;i++){
			str[i][0] = str[i-1][1];
			str[i][1] = (k-1) *(str[i-1][1] + str[i-1][0]);
		}
		printf("%lld\n",str[n][1] + str[n][0]);

	}


    return 0;
}
