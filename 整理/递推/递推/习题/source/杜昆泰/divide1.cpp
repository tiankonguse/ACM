
#include <fstream>
using namespace std;

long long f[5000][5000];
// f[i][j]指把i分解成j个整数的所有方案数

ifstream fin("divide1.in");
ofstream fout("divide1.out");

int main(void)
{

	long sum,all,i,j,k;
	
	fin>>sum>>all;
	
	for(j=1;j<=all;j++)
		for(i=1;i<=sum;i++)
		{
			if(j==1)
				f[i][j]=1;
			else
				for(k=1;k<=i-j+1;k++)
					f[i][j]+=f[i-k][j-1];
		}
		
	fout<<f[sum][all]<<endl;
	
	fin.close();
	fout.close();
	
	return 0;
	
}
