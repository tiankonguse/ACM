#include<iostream>
#include<cmath>
using namespace std;
int main()
{
int i,j,k,n,m=1000000000;
int mi,mj,mk;
    cin>>n;
    int p=sqrt(n);
	for(i=1;i<=p+1;++i)
		if(n%i==0)
			for(j=i;j<=n/i;++j)
			{
				k=i*j;
				if(n%k==0)
				k=n/k;
				if(i*j+i*k+j*k<m)
				{
					m=i*j+i*k+j*k;
					mi=i;
					mj=j;
					mk=k;
				}
			}
	cout<<mi<<" "<<mj<<" "<<mk<<endl;
	
return 0;
}

