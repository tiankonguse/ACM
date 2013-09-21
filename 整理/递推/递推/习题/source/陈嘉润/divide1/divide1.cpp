#include<fstream>

using namespace std;
long n,m,i,j,c[51][51];
int main()
{
	ifstream fin("divide1.in");
	ofstream fout("divide1.out");
	fin>>n>>m;
	c[1][0]=c[1][1]=1;
	for(i=2;i<=n-1;i++)
	{
		c[i][0]=1;
		c[i][i]=1;
		for(j=1;j<i;j++)
		  c[i][j]=c[i-1][j]+c[i-1][j-1];
	}
	fout<<c[n-1][m-1];
	fin.close();
	fout.close();
	return 0;
}

