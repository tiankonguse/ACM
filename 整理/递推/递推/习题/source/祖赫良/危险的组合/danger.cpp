#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
int main()
{
	freopen("danger.in","r",stdin);
    freopen("danger.out","w",stdout);	
	long long int n,f[1000][4];
	cin>>n;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=3;j++)
		{
			if(j==3) f[i][j]=pow(2,i);
			else if(i<=3) f[i][j]=f[i-1][j+1];
			else if(i>3) f[i][j]=f[i-1][j+1]+f[i-1][0];
		}
	cout<<f[n][0]<<endl;
	return 0;
}
