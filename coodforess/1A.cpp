#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
using namespace std;
#define LL __int64

LL myfun(LL x,LL y){
	return (x+y-1)/y;
}

int main()
{
	LL a,b,c;
	while(~scanf("%I64d%I64d%I64d",&a,&b,&c)){
		a=myfun(a,c);
		b=myfun(b,c);
		printf("%I64d\n",a*b);
	}
	
	return 0;
}
