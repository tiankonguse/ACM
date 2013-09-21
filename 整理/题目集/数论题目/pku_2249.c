#include <stdio.h>

int main()
{
	long double res;
	int n, k, i, j;
	while (scanf("%d %d", &n, &k) == 2 && !(n==0 && k==0) ) {
		if (k > n/2) {
			k = n-k;
		}
		res = 1.0;
		for (i = 1; i <= k; ++i) {
			res *= n;
			res /= i;
			--n;
		}
		printf("%.lf\n", res);	
	}
	return 0;
}
