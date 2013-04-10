#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<string>
#include<queue>
#include<cstdio>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
using namespace std;
int main()
{

	__int64 n,a,b;
	__int64 sum;
	while(~scanf("%I64d",&n)){
		a=(__int64)sqrt(2.0*n);
		sum=(1+a)*a/2;
		if(sum>=n)sum-=a;
		else a++;
		b=n-sum;
		if(a&1){
			printf("%I64d/%I64d\n",a-b+1,b);
		}else{
			printf("%I64d/%I64d\n",b,a-b+1);
		}
	}
	return 0;
}
