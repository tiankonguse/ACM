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
int main()
{
	int n,a,b;
	scanf("%d",&n);
	while(~scanf("%d",&n)){
		a=n/150;
		b=n%150;
		if(b>=100 && a>=2){
			b-=100;
		}if(b>=50 && a>=1){
			b-=50;
		}
		printf("%d\n",b);

	}
	return 0;
}
