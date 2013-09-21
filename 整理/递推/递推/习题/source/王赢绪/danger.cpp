#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int n,f[100][100];

int main()
{
	freopen ("danger.in","r",stdin);
	freopen ("danger.out","w",stdout);

	cin>>n;
	f[1][2]=1;	f[1][3]=2;
	for (int i=2;i<=n;i++)
	{
		for (int j=0;j<=3;j++)
		{
			if (j==3) f[i][j]=(int)pow(2,i);
			else if (i<=3) f[i][j]=f[i-1][j+1];
			else f[i][j]=f[i-1][j+1]+f[i-1][0];
		}
	}
	cout<<f[n][0];
	return 0;
} 
