#include<stdio.h>
int main()
{
	freopen("domino.in","r+",stdin);
	freopen("domino.out","w+",stdout);
	int n;
	scanf("%d",&n);
	int f[1000];
	f[0]=1;
	f[1]=1;
	f[2]=2;
	int i;
	for(i=2;i<=n;i++)
	f[i]=f[i-1]+f[i-2];
	printf("%d",f[n]);
	return 0;
}
