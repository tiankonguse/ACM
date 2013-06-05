#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

const int MAXN=40;
int n,m,dp[MAXN][MAXN];

int main()
{
	freopen ("ball1.in","r",stdin);
	freopen ("ball1.out","w",stdout);
	cin>>n>>m; // n ren   chuan  m ci
	dp[0][0]=1;
	for (int i=1;i<=m;i++)
		for (int j=0;j<n;j++)
			dp[i][j]=dp[i-1][(j+1)%n]+dp[i-1][(j+n-1)%n];
	cout<<dp[m][0]<<endl;
	return 0;
} 
