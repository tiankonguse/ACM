#include <iostream>
#include <fstream>
#define cin fin
#define cout fout
using namespace std;
ifstream fin("book.in");
ofstream fout("book.out");
long long f[50];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if ( i == 1 ) f[i] = 0;
		else if ( i == 2 ) f[i] = 1;
		else f[i] = (i-1)*(f[i-1] + f[i-2]);
	}
	cout << f[n] << endl;
	return 0;
}