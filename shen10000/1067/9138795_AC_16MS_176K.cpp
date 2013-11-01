#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
int a,b;
double q=(sqrt(5.0)+1)/2;
while(scanf("%d%d",&a,&b)!=EOF)
{
	if(a==b){printf("1\n");continue;}
	
	if(a>b){int c=a;a=b;b=c;}
	
	b=(int)((b-a)*q);
	
	if(a==b)printf("0\n");
	else printf("1\n");
}
return 0;
}
