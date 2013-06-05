#include<fstream>

using namespace std;

long f[1000],n,i;

int main()
{
	ifstream fin("hanoi.in");
	ofstream fout("hanoi.out");
	fin>>n;
	f[1]=1;
	for(i=2;i<=n;i++)
	 f[i]=2*f[i-1]+1;
	fout<<f[n]<<endl;
	fin.close();
	fout.close();
	return 0; 
}
