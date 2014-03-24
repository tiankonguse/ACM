#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	freopen("hanoi.in","r",stdin);
    freopen("hanoi.out","w",stdout);	
	long long int n,f[30000];
	cin>>n;
	f[1]=1;
	for(int i=2;i<=n;i++) f[i]=2*f[i-1]+1;
	cout<<f[n]<<endl;
	return 0;
}
