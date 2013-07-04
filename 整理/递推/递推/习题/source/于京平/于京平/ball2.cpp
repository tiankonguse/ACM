#include<stdio.h>
int f[1000][1000];
int main()
{
	freopen("ball2.in","r+",stdin);
	freopen("ball2.out","w+",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int i,j;
	f[0][0]=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(i==j)
			f[i][j]=1;
			if(j==1)
			f[i][j]=1;
			if(i<j)
			f[i][j]=0;
			f[i][j]=f[i-1][j-1]+f[i-1][j]*j;
			if(i==j)
			f[i][j]=1;
			if(j==1)
			f[i][j]=1;
			if(i<j)
			f[i][j]=0;
		}
	}
	printf("%d",f[n][m]);
	return 0;
}

