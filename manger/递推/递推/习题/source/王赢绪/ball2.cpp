#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

long long n,r,dp[100][100];

int main()
{
	freopen ("ball2.in","r",stdin);
	freopen ("ball2.out","w",stdout);
	cin>>n>>r; // n个球 放在r个盒子里
	//
	for (int i=1;i<=n;i++)
		for (int j=1;j<=r;j++)
		{
			if (j==1 || i==j)
				dp[i][j]=1;
			else if (i<j)
				dp[i][j]=0;
			else
				dp[i][j]=dp[i-1][j-1]+dp[i-1][j]*j;
		}
	//
	cout<<dp[n][r]; 
	return 0;
} 
