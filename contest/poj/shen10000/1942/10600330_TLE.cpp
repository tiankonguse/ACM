#include < iostream >
using namespace std;
unsigned int com (unsigned int n,unsigned int m)
{
	double i;
	double result(1);
	if ( n >= m - n ){ n = m-n; }
	for ( i = m;i >= m-n+1;i-=1 )
	{
		result *= (i / (i - (m - n)));
	}
	return result;
}
int main()
{
	unsigned int n,m;
	while (1)
	{
		scanf("%d%d",&n,&m);
		if ( n==0 && m==0 ){ break; }
		printf("%d\n",com (n,m+n));
	}
	return 0;
}