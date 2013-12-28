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
typedef long long LL;



int main() {
	double tmp;
	int n,plus,minus,zero;
	while(~scanf("%d",&n),n){
		plus = minus = zero=0;
		while(n--){
			scanf("%lf",&tmp);
			tmp<0?minus++:tmp>0?plus++:zero++;
		}
		printf("%d %d %d\n",minus,zero,plus);
	}

    return 0;
}
