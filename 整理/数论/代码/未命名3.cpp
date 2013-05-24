#include<stdio.h>
#include<math.h>
int find(int n)
{
	double t=pow((double)2,(n-1960)/10+2),sum=0;
	int i=0;
	printf("%lf\n",log(2.0));
	for(i=2;sum<t;i++)
	{
		sum+=log((double)i)/log((double)2);
	}
	return i-2;
}
int main()
{
	int n=0;
	while(scanf("%d",&n)&&n)
	{
		printf("%d\n",find(n));
	}
}
