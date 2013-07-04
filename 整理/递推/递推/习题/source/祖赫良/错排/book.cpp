#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	freopen("book.in","r",stdin);
    freopen("book.out","w",stdout);	
	long long int n,f[3000];
	cin>>n;
	f[1]=0,f[2]=1;
	for(int i=3;i<=n;i++) f[i]=(f[i-1]+f[i-2])*(i-1);
	cout<<f[n]<<endl;
	return 0;
}
