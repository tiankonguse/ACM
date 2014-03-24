#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("divide1.in");
ofstream fout("divide1.out");

long long c(int n, int m)
{
	long long ans = 1;
	for (int i = n-m+1; i <= n; i++)
		ans *= i;
	for (int i = 2; i <= m; i++)
		ans /= i;
	return ans;
}

int main()
{
	int n, m;
	fin >> n >> m;
	fout << c(n-1, m-1) << endl;
	return 0;
}
