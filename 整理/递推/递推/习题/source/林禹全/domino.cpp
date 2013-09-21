#include <iostream>
#include <fstream>
#define cin fin
#define cout fout
using namespace std;
ifstream fin("domino.in");
ofstream fout("domino.out");
int f[100];

int main()
{
	int n;
	cin >> n;
	f[0] = f[1] = 1;
	for (int i = 2; i <= n; i++) 
		f[i] = f[i-1] + f[i-2];
	cout << f[n] << endl;
	return 0;
}
