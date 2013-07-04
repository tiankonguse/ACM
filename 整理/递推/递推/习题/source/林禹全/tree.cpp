#include <iostream>
#include <fstream>
#define cin fin
#define cout fout
using namespace std;
ifstream fin("tree.in");
ofstream fout("tree.out");
long long f[50];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++) {
		if ( i == 1 ) f[i] = 1;
		else if ( !i ) f[i] = 1;
		else if ( i == 2 ) f[i] = 2;
		else if ( i == 3 ) f[i] = 5;
		else {
			long long sum = 0;
			for (int j = 0; j < i; j++)
				sum += f[j]*f[i-j-1];
			f[i] = sum;
		}
	}
	cout << f[n] << endl;
	return 0;
}
