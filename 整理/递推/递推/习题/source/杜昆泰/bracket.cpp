
#include <fstream>
using namespace std;

ifstream fin("bracket.in");
ofstream fout("bracket.out");

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
	
	fout<<Catalan(all)<<endl;
	
	fin.close();
	fout.close();
	
	return 0;
	
}
	