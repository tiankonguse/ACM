#include <iostream>
#include <fstream>
#define cin fin
#define cout fout
using namespace std;
ifstream fin("hanoi.in");
ofstream fout("hanoi.out");

long long pow(int n, int m)
{
	long long ans = 1;
	for (int i = 1; i <= m; i++)
		ans *= n;
	return ans-1;
}

int main()
{
	int n;
	cin >> n;
	cout << pow(2, n) << endl;
	return 0;
} 