#include <iostream>
#include <fstream>
#define cin fin
#define cout fout
using namespace std;
ifstream fin("stack.in");
ofstream fout("stack.out");
long long f[50];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++) {
		if ( i == 1 ) f[i] = 1;
		else if ( !i ) f[i] = 1;
		else if ( i == 2 ) f[i] = 2;
		else {
			for (int j = 0; j < i; j++) {
				f[i] += f[j]*f[i-j-1];
			}
		}
	}
	cout << f[n] << endl;
	return 0;
}