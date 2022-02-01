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
	int a,b,c;
	while(~scanf("%d%d",&a,&b)){
		c = a+b-1;
		printf("%d %d\n",c-a,c-b);
	}

    return 0;
}
