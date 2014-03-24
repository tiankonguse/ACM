#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	freopen("ball1.in","r",stdin);
    freopen("ball1.out","w",stdout);
	long long int n,m,f[1000][1000];
	cin>>n>>m;
	f[0][0]=1;
	for(int i=1;i<=n;i++) f[i][0]=0;
	for(int j=1;j<=m;j++) for(int i=0;i<=n;i++) f[i][j]=f[(i-1+n)%n][j-1]+f[(i+1)%n][j-1];
	cout<<f[0][m]<<endl;
	return 0;
}
