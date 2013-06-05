
#include <fstream>
using namespace std;

ifstream fin("ball1.in");
ofstream fout("ball1.out");

long f[5000][5000];
// f[i][j]指第j次传球传到第i人的方案数 

int main(void)
{
	
	long all,time,i,j;
	
	fin>>all>>time;
	
	f[0][0]=1;
	
	for(j=1;j<=time;j++)
		for(i=0;i<=all;i++)
			f[i][j]=f[(i-1+all)%all][j-1]+f[(i+1)%all][j-1];
			
	fout<<f[all][time]<<endl;
	
	fin.close();
	fout.close();
	
	return 0;
	
}
