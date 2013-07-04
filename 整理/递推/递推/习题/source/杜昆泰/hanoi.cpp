
#include <fstream>
using namespace std;

long long f[10000];	// f[i] refers to hanoi(i)'s min ways.
ifstream fin("hanoi.in");
ofstream fout("hanoi.out");

int main(void)
{
	
	long i,all;
	
	fin>>all;
	f[1]=1;
	
	for(i=2;i<=all;i++)
		f[i]=2*f[i-1]+1;
		
	fout<<f[all]<<endl;
	
	fin.close();
	fout.close();
	
	return 0;
	
}
