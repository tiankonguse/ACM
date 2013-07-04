#include<fstream>
using namespace std;
long a,b,k,n,m,ag,ce,f[1001][1001],i,j,pa,ba;
int main()
{
	ifstream fin("factor.in");
	ofstream fout("factor.out");
	fin>>a>>b>>k>>n>>m;
	a=a%10007;
	b=b%10007;
	//if(k==0)
	  //{
		  //fout<<1;
	  //}
	  //else
	  //{
		pa=ba=1;
		for(i=0;i<n;i++)
		{
			pa=pa*a;
			pa=pa%10007;
		}
		for(i=0;i<m;i++)
		{
			ba=ba*b;
			ba=ba%10007;
		}
		ag=(pa*ba)%10007;
		f[1][0]=1;f[1][1]=1;
		for(i=1;i<=k;i++)
		  for(j=1;j<=n;j++)
		  f[i][j]=(f[i-1][j-1]+f[i-1][j])%10007;
		ag=(ag*f[k][n])%10007;;
		fout<<ag;  
	  //}
	fin.close();
	fout.close();
	return 0;	
}