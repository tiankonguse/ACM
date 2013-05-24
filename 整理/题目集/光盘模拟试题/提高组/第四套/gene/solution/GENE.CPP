#include<fstream.h>

ifstream fin("gene.in");
ofstream fout("gene.out");

const int maxn=101;
const int d[5][5]={{5,-1,-2,-1,-3},
		   {-1,5,-3,-2,-4},
		   {-2,-3,5,-2,-2},
		   {-1,-2,-2,5,-1},
		   {-3,-4,-2,-1,0x7fff}};
char a[maxn],b[maxn];
int la,lb,n;

void init()
{
	char temp;
	int i;
	int num[256];
	num['A']=0;
	num['C']=1;
	num['G']=2;
	num['T']=3;
	num['-']=4;
	fin>>la;
	fin.get(temp);
	for (i=1;i<=la;i++)
	{
		fin.get(a[i]);
		a[i]=num[a[i]];
	}
	fin>>lb;
	fin.get(temp);
	for (i=1;i<=lb;i++)
	{
	    fin.get(b[i]);
	    b[i]=num[b[i]];
	}
}

void main()
{
	init();
	int f[maxn][maxn];
	int i,j;
	memset(f,0,sizeof(f));
	f[0][0]=0;
	for (i=1;i<=la;i++)
	    f[i][0]=f[i-1][0]+d[a[i]][4];
	for (i=1;i<=lb;i++)
	    f[0][i]=f[0][i-1]+d[4][b[i]];
	for (i=1;i<=lb;i++)
	    for (j=1;j<=la;j++)
	    {
		int max=-0x7fff;
		if (f[j-1][i-1]+d[a[j]][b[i]]>max)
		   max=f[j-1][i-1]+d[a[j]][b[i]];
		if (f[j-1][i]+d[a[j]][4]>max)
		   max=f[j-1][i]+d[a[j]][4];
		if (f[j][i-1]+d[4][b[i]]>max)
		   max=f[j][i-1]+d[4][b[i]];
		f[j][i]=max;
	    }
	fout<<f[la][lb]<<endl;
}
