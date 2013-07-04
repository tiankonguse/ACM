#include <iostream>
#include <fstream>
#define cin fin
#define cout fout
using namespace std;
ifstream fin("lineup.in");
ofstream fout("lineup.out");
long long f[11][11];

long long q(int n)
{
	long long ans = 1;
	for (int i = 1; i <= n; i++)
		ans *= i;
	return ans;
}

int main()
{
	int n;
	cin >> n;
	f[0][0] = 1;
	for (int i = 0; i <= n; i++) 
		for (int j = 0; j <= n; j++) {
			if ( !j ) f[i][j] = q(i);
			else if ( i < j ) f[i][j] = 0;
			else f[i][j] = f[i][j-1]*j + f[i-1][j]*i;
	}
	cout << f[n][n] << endl;
	return 0;
}