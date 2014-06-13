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
	double sum,n;
	int m;
	while(~scanf("%lf%d",&n,&m)){
		sum = n;
		while(--m){
			n = sqrt(n);
			sum += n;
		}
		printf("%.2f\n",sum);
	}


    return 0;
}
