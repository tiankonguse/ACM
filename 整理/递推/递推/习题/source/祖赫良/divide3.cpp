 #include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	freopen("divide3.in","r",stdin);
    freopen("divide3.out","w",stdout);
	long long int n,m,f[1000][1000];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(j==1) f[i][j]=1;
			if(j>i) f[i][j]=0;
			if(j>1&&i>=j) f[i][j]=f[i-1][j-1]+f[i-j][j]; 
		}
	cout<<f[n][m]<<endl;
	return 0;
}
