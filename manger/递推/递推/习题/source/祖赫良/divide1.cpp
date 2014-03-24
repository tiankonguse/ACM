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
	freopen("divide1.in","r",stdin);
    freopen("divide1.out","w",stdout);	
	int n,m;
	cin>>n>>m;
	cout<<C(n-1,m-1)<<endl;
	return 0;
}
