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
stack<double>sta;


int main() {
	double a;
	while(~scanf("%lf",&a)){
		sta.push(sqrt(a));
	}
	while(!sta.empty()){
		printf("%lf\n",sta.top());sta.pop();
	}

    return 0;
}
