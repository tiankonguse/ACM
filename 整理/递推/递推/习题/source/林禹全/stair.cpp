#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("stair.in");
ofstream fout("stair.out");

int main()
{
	long long n, f[10000];
	fin >> n;
	f[1] = f[0] = 1;
	for (int i = 2; i <= n; i++) 
		f[i] = f[i-1] + f[i-2];
	fout << f[n] << endl;
	return 0;
}