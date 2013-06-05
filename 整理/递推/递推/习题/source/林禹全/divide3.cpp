#include <iostream>
#include <fstream>
#define cin fin
#define cout fout
using namespace std;
ifstream fin("divide3.in");
ofstream fout("divide3.out");
long long f[100][100];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			if ( j == 1 ) f[i][j] = 1;
			else if ( i < j ) f[i][j] = 0;
			else f[i][j] = f[i-1][j-1] + f[i-j][j];
		}
	cout << f[n][m] << endl;
	return 0;
}