/*
ID: tiankonguse
PROG: test
LANG: C++
*/
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
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
    int a, b;
    while(~scanf("%d%d",&a,&b)){
		printf("%d\n",a+b);
    }
    return 0;
}
