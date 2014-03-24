#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int n,dp[200];

int main()
{
	freopen ("domino.in","r",stdin);
	freopen ("domino.out","w",stdout);
	dp[0]=dp[1]=1;
	cin>>n;
	for (int i=2;i<=n;i++)
		dp[i]=dp[i-1]+dp[i-2];
	cout<<dp[n];
	return 0;
} 
