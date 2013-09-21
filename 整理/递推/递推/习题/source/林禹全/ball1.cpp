#include <iostream>
#include <fstream>
#define cin fin
#define cout fout
using namespace std;
ifstream fin("ball1.in");
ofstream fout("ball1.out");
long long f[50][50];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int j = 0; j <= m; j++)
		for (int i = 0; i < n; i++) {
			if ( !i && !j ) f[i][j] = 1;
			else if ( i%n && !j ) f[i][j] = 0;
			else f[i][j] = f[(i+1)%n][j-1] + f[(i-1+n)%n][j-1];
		}
	cout << f[0][m] << endl;
	return 0;
}
