
#include <fstream>
using namespace std;

ifstream fin("polygon.in");
ofstream fout("polygon.out");

long long Catalan(long n)
{
	
	long i;
	long long t=1;
	
	for(i=2*n;i>n;i--)
		t=t*i/(i-n);
		
	t/=n+1;
	
	return t;
	
}

int main(void)
{
	
	long all;
	
	fin>>all;
	all-=2;
	
	fout<<Catalan(all)<<endl;
	
	fin.close();
	fout.close();
	
	return 0;
	
}
	