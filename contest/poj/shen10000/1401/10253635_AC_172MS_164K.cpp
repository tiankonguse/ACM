#include<stdio.h>
#include<string.h>
#include<stdlib.h>

__int64 count_zero(__int64 m){
	__int64 sum=0;
	while(m){
		sum+=m/5;
		m/=5;
	}
	return sum;
}

int main()
{
int n;
__int64 m,sum;
scanf("%d",&n);
while(n--){
	scanf("%I64d",&m);
	printf("%I64d\n",count_zero(m));
}
return 0;
}
