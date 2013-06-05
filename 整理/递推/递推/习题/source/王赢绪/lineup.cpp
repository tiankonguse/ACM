#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("lineup.in");
ofstream fout("lineup.out");

long long f[500][500];
long long ff(int n)
{
	long long ans = 1;
	for (int i = 2; i <= n; i++)
		ans *= i;
	return ans;
}

int main()
{
	int n;
	fin >> n;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++) {
			if ( !j ) f[i][j] = ff(i);
			else if ( i < j ) f[i][j] = 0;
			else if ( i >= j ) f[i][j] = f[i][j-1]*j+f[i-1][j]*i;
		}
	fout << f[n][n] << endl;
	return 0;
}
