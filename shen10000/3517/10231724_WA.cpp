#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int fun(int n,int k){
	int s=0;
	for (int i=2; i<=n; i++)  s=(s+k)%i;
	return s+1;
}
int main()
{
	int n,k,m,s;
	while(scanf("%d%d%d",&n,&k,&m),n){
		int s=fun(n-1,k);
		printf("%d\n",s<n-m?s+m:s+m-n);
	}
return 0;
}
