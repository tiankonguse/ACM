
#include <fstream>
using namespace std;

long long f[10000]={0,0,1,2};
// f[i]指i个人拿书时有的方案总数

ifstream fin("book.in");
ofstream fout("book.out");

int main(void)
{

	long all,i;
	
	fin>>all;
	
	for(i=3;i<=all;i++)
		f[i]=(i-1)*(f[i-1]+f[i-2]); 
		
	fout<<f[all]<<endl;
	
	fin.close();
	fout.close();
	
	return 0;
	
}
