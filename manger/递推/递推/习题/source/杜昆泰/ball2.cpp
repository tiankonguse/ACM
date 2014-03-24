
#include <fstream>
using namespace std;

long f[5000][5000];
// f[i][j]指把i个不同的小球放进j个相同的盒子的方案数

ifstream fin("ball2.in");
ofstream fout("ball2.out");

int main(void)
{

	long all,i,j,boxes; 
	
	fin>>all>>boxes;
		
	for(i=1;i<=all;i++)
		for(j=1;j<=boxes;j++)
		{
			if( (j==1)||(i==j) )
				f[i][j]=1;
			else
				if( i<j )
					f[i][j]=0;
				else
					f[i][j]=f[i-1][j-1]+f[i-1][j]*j;
		}
					
	fout<<f[all][boxes]<<endl;
	
	fin.close();
	fout.close();
	
	return 0;
	
}
