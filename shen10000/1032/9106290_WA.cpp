#include<iostream>
#include<string>
#include<stdlib.h>
#include<math.h>
using namespace std;

int main()
{
int m;
while(scanf("%d",&m)!=EOF)
{
	int k=(int)(sqrt(m+m+2+0.25)-0.5);	
	int n=(int)((k*k+k-2)/2);
	if(n>m){n=n-k;k--;}
	int p=m-n;
	int q=k-p+1;
	bool t=false;
	for(int i=2;i<=k+1;i++)
	{
		
		if(i==q)continue;
		if(t)putchar(' ');
		printf("%d",i);	
		
		t=true;
	}
	putchar('\n');
}
    getchar();getchar();
return 0;
}
