#include<stdio.h>
#include<string.h>
#include<stdlib.h>

__int64 search_b(__int64 n){
	__int64 sum=0;
	while(n>>=1)sum+=n;
	return sum;
}

int main()
{
	__int64 a,b;
	while(scanf("%I64d%I64d",&a,&b)!=EOF){
	
	        if(search_b(a)>search_b(b)+search_b(a-b)) printf("0\n");
	        else printf("1\n");	
	}
return 0;
}
