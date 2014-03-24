#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

long long n,dp[10000];

int main()
{
	freopen ("book.in","r",stdin);
	freopen ("book.out","w",stdout);
	cin>>n;
	//
	dp[2]=1;
	for (int i=3;i<=n;i++)
		dp[i]=(i-1)*(dp[i-1]+dp[i-2]);
	//
	cout<<dp[n]<<endl;
	return 0;
} 
