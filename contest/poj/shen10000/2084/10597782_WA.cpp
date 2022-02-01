#include<iostream>
#include<string>
#include<queue>
#include<cstdio>
#include<stdlib.h>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
__int64 str[111];
using namespace std;
void init(){
	str[0]=1;
	str[1]=1;
	for(int i=2;i<101;i++){
		str[i]=0;
		for(int j=0;j<i;j++){
			str[i]+=str[j]*str[i-j-1];
		}
	}
}
int main()
{
	init();
	int n;
	while(scanf("%d",&n),n+1){
		printf("%I64d\n",str[n]);
	}
	return 0;
}
