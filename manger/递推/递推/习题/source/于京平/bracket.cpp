#include<stdio.h>
int f[1000];
int main()
{
	freopen("bracket.in","r+",stdin);
	freopen("bracket.out","w+",stdout);
	int n;
	scanf("%d",&n);
	f[1]=0;
	f[2]=1;
	int i;
	for(i=3;i<=n;i++)
	{
		f[i]=(i-1)*(f[i-1]+f[i-2]);
	}
	printf("%d",f[n]);
	return 0;
}
