#include<stdio.h>
#define MAXN 1000
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
long long polya(int c , int s)
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
int c,s;
while(scanf("%d%d",&c,&s),c){
	printf("%d\n",polya(c,s));
}
return 0;	
}
