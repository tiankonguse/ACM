#include<fstream>

using namespace std;

long i,n,f[21];
int main()
{
	ifstream fin("book.in");
	ofstream fout("book.out");
	fin>>n;
	f[1]=0;
	f[2]=1;
	for(i=3;i<=n;i++)
	{
		f[i]=(f[i-1]+f[i-2])*(i-1);
	}
	fout<<f[n];
	fin.close();
	fout.close();
	return 0;
}
