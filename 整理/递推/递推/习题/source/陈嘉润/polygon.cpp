#include<fstream>

using namespace std;


long n,i,j,f[31];

int main()
{
	ifstream fin("polygon.in");
	ofstream fout("polygon.out");
	fin>>n;
	f[0]=1;
	for(i=1;i<=n-2;i++)
	{
		f[i]=0;
		for(j=0;j<=i-1;j++)
		  f[i]+=f[j]*f[i-1-j];
	}
    fout<<f[n-2];
	fin.close();
	fout.close();
	return 0;
}
