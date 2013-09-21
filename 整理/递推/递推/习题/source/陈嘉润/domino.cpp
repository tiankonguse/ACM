#include<fstream>

using namespace std;

long f[1000],i,n;
int main()
{
	ifstream fin("domino.in");
	ofstream fout("domino.out");
	fin>>n;
	f[0]=f[1]=1;
	for(i=2;i<=n;i++)
	{
		f[i]=f[i-1]+f[i-2];
	}
	fout<<f[n];
	fin.close();
	fout.close();
	return 0;
}
