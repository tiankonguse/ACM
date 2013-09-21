/*
#include<iostream>
#include<string>
#include<queue>
#include<cstdio>
#include<stdlib.h>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
using namespace std;
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
	double  n,m;
	while(~scanf("%lf",&n)){
		printf("%.0f\n",0.5+n-log10(n*1.0)-log10(log(10.0)));
	}
	return 0;
}
