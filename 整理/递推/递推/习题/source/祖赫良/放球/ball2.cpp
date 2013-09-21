#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	freopen("ball2.in","r",stdin);
    freopen("ball2.out","w",stdout);
	long long int m,n,f[1000][1000];
	cin>>m>>n;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
		{
			if(j==0||j==i) f[i][j]=1;
			else if(i<j) f[i][j]=0;
			else f[i][j]=f[i-1][j-1]+f[i-1][j]*j;
		}
	cout<<f[m][n]<<endl;
	return 0;
}
