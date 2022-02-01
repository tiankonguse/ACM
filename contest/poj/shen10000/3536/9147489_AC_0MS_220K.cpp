#include<iostream>
#include<math.h>
using namespace std;
int main()
{
int i,j,k,n,m;
int mi,mj,mk;
    while(cin>>n)
    {
		m=1000000000;
	    int p=(int)sqrt(n*1.0);
		for(i=1;i<=p+1;++i)
			if(n%i==0)
			{
				int a1=n/i;
				int q=(int)sqrt(a1*1.0);
				for(j=i;j<=q+1;++j)
				{
					if(a1%j==0)
					{
						k=a1/j;
						int a2=i*j;
						int a3=i*k;
						if(a1+a2+a3<m)
						{
							m=a1+a2+a3;
							mi=i;
							mj=j;
							mk=k;
						}
					}
				}
			}
		cout<<mi<<" "<<mj<<" "<<mk<<endl;
   }
return 0;
}

