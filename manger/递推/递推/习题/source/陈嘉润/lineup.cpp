#include<fstream>

using namespace std;


long n,i,j,f[11];
long long num;
int main()
{
	ifstream fin("lineup.in");
	ofstream fout("lineup.out");
	fin>>n;
	f[0]=1;
	for(i=1;i<=n;i++)
	{
		f[i]=0;
		for(j=0;j<=i-1;j++)
		  f[i]+=f[j]*f[i-1-j];
	}
	num=f[n];
	for(i=1;i<=n;i++)
	{
		num=num*i;
	}
	for(i=1;i<=n;i++)
	{
		num=num*i;
	}
	fout<<num;
	fin.close();
	fout.close();
	return 0;
}
