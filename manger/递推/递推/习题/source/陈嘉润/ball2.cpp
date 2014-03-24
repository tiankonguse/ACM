#include<fstream>

using namespace std;

long ball,box,i,j,f[21][21];

int main()
{
	ifstream fin("ball2.in");
	ofstream fout("ball2.out");
	fin>>ball>>box;
	for(i=1;i<=ball;i++)
	  f[i][1]=1;
    for(i=1;i<=ball;i++)
    {
    	f[i][i]=1;
    	for(j=1;j<i;j++)
    	  f[i][j]=f[i-1][j-1]+f[i-1][j]*j;
    }
    fout<<f[ball][box];
    fin.close();
    fout.close();
    return 0;
}
