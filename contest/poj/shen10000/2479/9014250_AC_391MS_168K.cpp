#include<cstdio>

int max(int x, int y ) {return x>y? x : y; }

int main()
{
	int cas,n; 
	scanf("%d",&cas);
	while ( cas -- )
	{
		scanf("%d",&n);
		int a, b , ans, a_max,k; 
		a = b = a_max = 0;
		ans = -99999999;
		scanf("%d",&k);
		b = a_max = k; 
		a = max(k , 0 );
		for (int i = 1; i<n; i++)
		{
			scanf("%d",&k);
			a = a + k; 
			if ( a < 0 ) a = 0; 
			b = max( b+k , a_max+k );
			ans = max( ans , b);
			a_max = max( a, a_max);
			b = max( b , a_max);
		}
		printf("%d\n",ans);
	}
}