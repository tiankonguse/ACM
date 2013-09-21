#include <iostream>
#include <fstream>
#define cin fin
#define cout fout
using namespace std;
ifstream fin("danger.in");
ofstream fout("danger.out");
long long f[50][4];

long long pow(int k)
{
	long long ans = 1;
	for (int i = 1; i <= k; i++) 
		ans *= 2;
	return ans;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= 3; j++) {
			if ( i == 3 && !j ) f[i][j] = 1;
			else if ( i+j < 3 ) f[i][j] = 0;
			else if ( j == 3 ) f[i][j] = pow(i);
			else if ( i <= 3 ) f[i][j] = f[i-1][j+1];
			else f[i][j] = f[i-1][j+1] + f[i-1][0];
		}
	cout << f[n][0] << endl;
	return 0;
}