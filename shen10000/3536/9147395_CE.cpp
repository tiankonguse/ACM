#include<iostream>
      #include<cmath>
      using namespace std;
      int main()
      {
      int i,j,k,n,m=1000000000;
      int mi,mj,mk;
      cin>>n;
      for(i=1;i<=sqrt(n)+1;++i)
      {
      if(n%i==0)
      {
      for(j=1;j<=n/i;++j)
      {
      k=i*j;if(n%k==0)
      {
      k=n/k;if(i*j+i*k+j*k<m)
      {
      m=i*j+i*k+j*k;mi=i;mj=j;mk=k;
      }
      }
      }
      }
      }
      cout<<mi<<" "<<mj<<" "<<mk<<endl;return 0;
      }

