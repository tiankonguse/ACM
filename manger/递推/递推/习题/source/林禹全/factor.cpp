#include <iostream>
#include <fstream>
#define mod 10007
#define cin fin
#define cout fout
using namespace std;
ifstream fin("factor.in");
ofstream fout("factor.out");
long long C[2000][2000];

int main()
{
	int a, b, k, n, m;
	cin >> a >> b >> k >> n >> m;
	a %= mod;
	b %= mod;
	for (int i = 1; i <= k; i++)
		for (int j = 0; j <= n; j++) {
			if ( !j ) continue;
			else if ( j == i ) C[i][j] = 1;
			else if ( j > i ) C[i][j] = 0;
			else if ( j == 1 ) C[i][j] = i;
			else C[i][j] = C[i-1][j]%mod + C[i-1][j-1]%mod;
		}
	int ans = C[k][n];
	for (int i = 1; i <= n; i++) {
		ans *= a;
		ans %= mod;
	}
	for (int i = 1; i <= m; i++) {
		ans *= b;
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}