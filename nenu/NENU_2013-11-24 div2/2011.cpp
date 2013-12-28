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
	int n,m;
	double sum;
	int sign ;
	while(~scanf("%d",&n)){
		while(n--){
			scanf("%d",&m);
			sum = 0;
			sign = 1;
			for(int i=1;i<=m;i++){
				sum += 1.0/(i*sign);
				sign = -sign;
			}
			printf("%.2f\n",sum);
		}
	}


    return 0;
}
