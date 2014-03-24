#include <iostream>
#include <fstream>
#define cin fin
#define cout fout
using namespace std;
ifstream fin("polygon.in");
ofstream fout("polygon.out");
long long f[50];

int main()
{
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		if ( i == 3 ) f[i] = 1;
		else if ( i == 2 ) f[i] = 1;
		else {
			for (int j = 2; j < i; j++) {
				f[i] += f[j]*f[i+1-j];
			}
		}
	}
	cout << f[n] << endl;
	return 0;
}
