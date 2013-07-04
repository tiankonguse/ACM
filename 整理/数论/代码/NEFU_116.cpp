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
typedef long long LL;
LL gcd(LL x,LL y){
	if(!x || !y)return x?x:y;
	for(LL t;t=x%y;x=y,y=t);
	return y;
}
int main()
{
	LL a,b,c;
	while(scanf("%lld%lld",&a,&b)!=EOF){
		c=gcd(a,b);
		printf("%lld\n",a/c*b);
	}
	
	return 0;
}
