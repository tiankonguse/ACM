#include <iostream>
#include <fstream>
#define cin fin
#define cout fout
using namespace std;
ifstream fin("divide1.in");
ofstream fout("divide1.out");

long long C(int n, int m)
{
	long long ans = 1;
	int k = 0;
		for (int i = n; i >= n-m+1; i--) {
			ans *= i;
			while ( ans%(m-k) == 0 && k != m-1 ) {
				ans /= (m-k);
				k++;
			}
		}
	while ( ans%(m-k) == 0 && k != m-1 ) {
		ans /= (m-k);
		k++;
	}
	return ans;
}

int main()
{
	int n, m;
	cin >> n >> m;
	cout << C(n-1, m-1) << endl;
	return 0;
}