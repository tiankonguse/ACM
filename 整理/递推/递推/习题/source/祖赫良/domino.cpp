#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	freopen("domino.in","r",stdin);
    freopen("domino.out","w",stdout);	
	long long n,f[3000];
	cin>>n;
	f[1]=1,f[2]=2;
	for(int i=3;i<=n;i++) f[i]=f[i-1]+f[i-2];
	cout<<f[n]<<endl;
	return 0;
}
