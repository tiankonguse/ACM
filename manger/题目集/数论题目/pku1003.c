#include <stdio.h>
int main()
{
	float x, y;
	long n = 1; 
	while (scanf("%f", &x) == 1 && x != 0.00) {
		y = 0.0;
		n = 1;
		while (y < x) {
			y += 1.0/(++n);
		}
		printf("%d card(s)\n", n-1);
	}
	return 0;
}
