#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
	int n,i,sum,init=2,t=0;
	scanf("%d",&n);
	i=sqrt(n*2.);
	sum=(i*i+3*i)/2;
	while((sum-=i+1)>n)--i;
	n-=sum;
	--i;
	init+=n/i;
	n%=i;
	while(t++<i-n)printf("%d ",init++);
	++init;
	while(n--)printf("%d ",init++);
	return 0;
}
