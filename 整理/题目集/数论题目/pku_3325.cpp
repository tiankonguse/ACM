#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int main()
{
	int n, i, min, max, sum;
	int a[110];
	while (cin>>n && n) {
		cin>>a[0];
		min = max = a[0];
		for (i = 1; i < n; ++i) {
			cin>>a[i];
			if (a[i] < min)
				min = a[i];
			if (a[i] > max) 
				max = a[i];
		}
		sum = 0;
		for (i = 0; i < n; ++i) {
			sum += a[i];
		}
		sum -= (min + max);
		cout<<sum/(n-2)<<endl;
	}
	return 0;
}
