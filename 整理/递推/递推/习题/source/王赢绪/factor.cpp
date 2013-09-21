#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("factor.in");
ofstream fout("factor.out");

const int MAXN=1005;
int dp[MAXN][MAXN],a,b,k,n,m,ans;

int main()
{
	fin>>a>>b>>k>>n>>m;
	
	dp[1][1]=dp[1][2]=1;
	for (int i=2;i<=k;i++)
		for (int j=1;j<=i+1;j++)
			dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) % 10007;
	
	ans = dp[k][m+1];
	
	for (int i=1;i<=n;i++)
		ans= ((ans%10007) * (a%10007)) % 10007;
	for (int i=1;i<=m;i++)
		ans= ((ans%10007) * (b%10007)) % 10007;
		
	fout<<ans<<endl;
	
	return 0;
}

