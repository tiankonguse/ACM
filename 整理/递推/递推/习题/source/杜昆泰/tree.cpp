
#include <fstream>
using namespace std;

long long Catalan(long n)
{
	
	long i;
	long long t=1;
	
	for(i=2*n;i>n;i--)
		t=t*i/(i-n);
		
	t/=n+1;
	
	return t;
	
}

ifstream fin("tree.in");
ofstream fout("tree.out");

int main(void)
{
	
	long n;
	
	fin>>n;
	
	fout<<Catalan(n)<<endl;
	
	fin.close();
	fout.close();
	
	return 0;
	
};
