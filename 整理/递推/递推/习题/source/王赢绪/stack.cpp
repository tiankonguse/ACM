#include <iostream>
#include <cstdio>
using namespace std;
typedef long long lld;
lld i,n,ans;
lld h[1000];
int main()
{
	freopen ("stack.in","r",stdin);
	freopen ("stack.out","w",stdout);
	h[2]=1;
	cin>>n;
	n=n+2; 
	for (lld i=3;i<=n;i++)
		for (lld k=2;k<i;k++)
			h[i]=h[i]+h[k]*h[i-k+1];
	cout<<h[n]<<endl;
	return 0;
}
