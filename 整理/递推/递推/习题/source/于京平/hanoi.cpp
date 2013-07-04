#include<stdio.h>
int main()
{
	freopen("hanoi.in","r+",stdin);
	freopen("hanoi.out","w+",stdout);
	int n;
	scanf("%d",&n);
	int f[200];
	f[1]=1;
	f[2]=3;
	f[3]=7;
	int i;
	for(i=2;i<=n;i++)
	f[i]=2*f[i-1]+1;
	printf("%d",f[n]);
	return 0;
}
