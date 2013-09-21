/* Problem Set: Central European Regional ACM ICPC 1995 */
/* Problem Name: Joseph */
/* Author: Michal Koucky */
/* Date: 1998/01/26 */
/* Used Method: table method */

#include <stdio.h>

int x[] = { 2, 7, 5, 30, 169, 441, 1872, 7632, 1740, 93313, 459901, 1358657, 
	    2504881 };

void main()
{
	int n;
	
	for(;;)
	{
		scanf("%d", &n);
		if(!n) break;
		printf("%d\n", x[n-1] );	
	}
}

#if 0

/* following code were used to generate the array */ 
	
static int test(int m, int N)
{
	int i, p;

        m--;	

        i=0;
	for(p = 2*N; p>N; p--){
		i = (i+m) % p;
		if(i<N) return 0;
	}

	return 1;
}

void main()
{
	int m, N;

	for(N = 1; N < 14; N++)
	{	
		for(m = 1; ; m++)
		{
			if(test(m, N))
			{
				printf("%2d, ", m);
				break;
			}
		}
		
	}
}

#endif
