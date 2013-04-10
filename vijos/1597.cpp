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

void print(int n){
	int str[33],i=0,j;
	for(j=0;n;j++){
		if(n&1){
			str[i++]=j;
		}
		n>>=1;
	}
	j=i-1;
	putchar('2');
	if(str[j]!=1){
		putchar('(');
		if(str[j]==0)putchar('0');
		else print(str[j]);
		putchar(')');
	}
	for(j--;j>=0;j--){
		putchar('+');
		putchar('2');
		if(str[j]!=1){
			putchar('(');
			if(str[j]==0)putchar('0');
			else print(str[j]);
			putchar(')');
		}
	}
}

int main()
{
	int n;
	while(~scanf("%d",&n)){
		print(n);
		puts("");
	}
	return 0;
}
