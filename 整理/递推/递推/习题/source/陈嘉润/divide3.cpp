#include<fstream>

using namespace std;
long n,m,i,j,f[51][51];
int main()
{
	ifstream fin("divide3.in");
	ofstream fout("divide3.out");
	fin>>n>>m;
	f[1][1]=1;
	for(i=2;i<=n;i++)
	{
		f[i][1]=1;
		for(j=2;j<=i;j++)
		 f[i][j]=f[i-1][j-1]+f[i-j][j];
	}
	fout<<f[n][m];
	fin.close();
	fout.close();
	return 0;
}

