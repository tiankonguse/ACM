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
	char str[100];
	while(scanf("%s",str)){
		if(str[0]=='0' && str[1]=='\0')break;
		int l=strlen(str);
		__int64 ans=0;
		__int64 tmp=2;
		for(int i=l-1;i>=0;i--){
			ans+=(str[i]-'0')*(tmp-1);
			tmp<<=1;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
