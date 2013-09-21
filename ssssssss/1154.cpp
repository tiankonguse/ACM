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
	int n,num;
	int str[111];
	memset(str,0,sizeof(str));
	for(int i=1;i<=100;i++){
		for(int j=i;j<=100;j+=i){
			str[j]++;
		}
		str[i]=(str[i]&1)+str[i-1];
	}
	scanf("%d",&n);
	while(~scanf("%d",&n)){
		printf("%d\n",str[n]);
	}
	return 0;
}
