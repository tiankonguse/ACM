#include<iostream>
#include<stdio.h>
using namespace std;
long long int fac(long long int n)
{
	if(n==1) return 1;
	return n*fac(n-1);
}
long long int C(int a,int b)
{
	return fac(a)/(fac(a-b)*fac(b));
}
int main()
{
	freopen("lineup.in","r",stdin);
    freopen("lineup.out","w",stdout);
	int n;
	cin>>n;
	long long ans=C(2*n,n)/(n+1)*fac(n)*fac(n);
	cout<<ans<<endl;
	return 0;
}
