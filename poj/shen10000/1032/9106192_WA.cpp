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
	printf("k=%d n=%d\n",k,n);
	if(n>m){n=n-k;k--;}
	int p=m-n;
	if(p==0)
	{
		printf("2");
		for(int i=3;i<=k;i++)
		printf(" %d",i);
		printf("\n");
		continue;
	}
	int q=k-p+1;
	for(int i=2;i<=k;i++)
	{
		if(i==q)continue;
		printf("%d ",i);	
	}
	printf("%d\n",q+p);
}
    getchar();getchar();
return 0;
}
