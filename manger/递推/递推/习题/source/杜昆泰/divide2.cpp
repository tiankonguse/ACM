
#include <fstream>
using namespace std;

long long f[5000][5000];
// f[i][j]指把正整数N分解成M 个非负整数的和的总方案数 

ifstream fin("divide2.in");
ofstream fout("divide2.out");

int main(void)
{
	
	long sum,all,i,j,k;
	
	fin>>sum>>all;
	
	for(j=1;j<=all;j++)
		for(i=0;i<=sum;i++)
		{
			if(j==1)
				f[i][j]=1;
			else
				for(k=0;k<=i;k++)
					f[i][j]+=f[i-k][j-1];
		}
		
	fout<<f[sum][all]<<endl;
	
	fin.close();
	fout.close();
	
	return 0;
	
}
