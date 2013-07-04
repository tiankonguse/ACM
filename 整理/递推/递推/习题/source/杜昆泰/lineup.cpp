
#include <fstream>
using namespace std;

ifstream fin("lineup.in");
ofstream fout("lineup.out");

long long Catalan(long n)
{
	
	long i;
	long long t=1;
	
	for(i=2*n;i>n;i--)
		t=t*i/(i-n);
		
	t/=n+1;
	
	return t;
	
}

long long P(long n)
{
	if(n==0) return 1; else return n*P(n-1);
}

int main(void)
{
	
	long all,t1,t2;
	
	all=2;
	
	fout<<Catalan(all)*P(all)*P(all)<<endl;
	
	fin.close();
	fout.close();
	
	return 0;

	
}

	
	