#include<stdio.h>
int f[1000];
int main()
{
	freopen("stack.in","r+",stdin);
	freopen("stack.out","w+",stdout);
	int n;
	scanf("%d",&n);
	f[0]=1;
	f[1]=0;
	int i,j;
	for(i=0;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		f[i]+=f[j-1]*f[i-j];
	}
	printf("%d",f[n]);
	return 0;
}

