#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int gcd(int x,int y)
{
    if(!x || !y)return x?x:y;
    for(int t;t=x%y;x=y,y=t);
    return y;
}
long long polya(int s , int c=3)
{
	long long p[100];
	p[0]=1;
	for( int k=0; k<s;k++)p[k+1]=p[k]*c;
	
	long long count=s&1 ? s*p[(s>>1) +1]:(s>>1)*(p[s>>1] + p[(s>>1)+1]);
	for(int k=1; k<=s;k++)count+=p[gcd(k,s)];
	return count/(2*s);
}
int main()
{
	int n;
	while(scanf("%d",&n),n+1)
	{
		printf("%d\n",n?polya(n):0);
	}
	return 0;
}
