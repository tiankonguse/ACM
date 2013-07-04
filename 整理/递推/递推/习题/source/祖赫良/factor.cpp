#include<iostream>
#include<stdio.h>
using namespace std;
int max(int a,int b)
{
	if(a>b) return a;
	else return b;
}
int main()
{
	freopen("factor.in","r",stdin);
    freopen("factor.out","w",stdout);
	int a,b,n,m,k,ta=1,tb=1,answer,maxn;
	cin>>a>>b>>k>>n>>m;
	for(int i=0;i<n;i++)
		ta*=a%10007;
	for(int i=0;i<m;i++)
		tb*=b%10007;
	answer=(ta*tb)%10007;
	maxn=max(n,m);
	for(int i=1,j=k;i<=m+n-maxn;i++,j--)
	{	
		answer*=j/i;
		answer%=10007;
	}
	cout<<answer<<endl;
	return 0;
}
