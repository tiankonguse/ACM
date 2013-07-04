
#include <fstream>
using namespace std;

long f[5000][5000];
ifstream fin("factor.in");
ofstream fout("factor.out");
// State f[i][j] refers to (ax+by)^i's x^j*y^(k-j).

#define mn 10007

int main(void)
{
	
	long a,b,k,n,m,i,j;
	
	fin>>a>>b>>k>>n>>m;
	a%=mn;
	b%=mn;

	f[0][0]=1;
	
	for(i=1;i<=k;i++)
		for(j=0;j<=n;j++)
			f[i][j]=( (a*f[i-1][j-1]) + (b*f[i-1][j]) ) % mn;
			
	fout<<f[k][n]<<endl;
	
	fin.close();
	fout.close();
	
	return 0;
	
}
