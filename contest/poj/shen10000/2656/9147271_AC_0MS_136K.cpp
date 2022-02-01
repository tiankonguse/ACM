#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
int n;
while(scanf("%d",&n),n)
{
	int a,b,max=8,d=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&b);
		a+=b;
		if(a>max){max=a;d=i;}
	}
	printf("%d\n",d);	
	
}
getchar();getchar();
return 0;
}
