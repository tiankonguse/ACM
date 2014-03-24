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
	int a,b,c;
	bool yes;
	while(scanf("%d%d",&a,&b),a){
		c=(b-a*100%b)%b;
		printf("%d%d",c/10,c%10);
		c+=b;
		while(c<100){
			printf(" %d%d",c/10,c%10);
			c+=b;
		}
		puts("");
	}
	return 0;
}
