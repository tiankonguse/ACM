#include <iostream>
#include <fstream>
#define cin fin
#define cout fout
using namespace std;
ifstream fin("ball2.in");
ofstream fout("ball2.out");
long long f[30][30];

int main()
{
	int n, r;
	cin >> n >> r;
	for (int i = 1; i <= r; i++)
		for (int j = 0; j <= n; j++) {
			if ( j < i ) f[j][i] = 0;
			else if ( j == i || i == 1 ) f[j][i] = 1;
			else f[j][i] = f[j-1][i-1] + f[j-1][i]*i;
		}
	cout << f[n][r] << endl;
	return 0;
}
