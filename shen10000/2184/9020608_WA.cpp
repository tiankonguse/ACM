#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
 {
int n;
int a[103][2];
int b[103][2];
int max=0,p1,p2,p;
scanf("%d",&n);
for(int i=0;i<n;i++)
{
	scanf("%d%d",&a[i][0],&a[i][1]);	
	b[i][0]=a[i][0],b[i][1]=a[i][1];
	for(int j=0;j<i;j++)
	{
		p1=a[i][0]+b[j][0];
		p2=a[i][1]+b[j][1];
		if(p2>=0&&p1>=0&&p1+p2>=b[i][0]+b[i][1])
		{
			b[i][0]=p1;
			b[i][1]=p2;	
		}	
	}	
	p=b[i][0]+b[i][1];
	if(max<p&&b[i][0>=0&&b[i][1]>=0])max=p;
}
printf("%d\n",max);
getchar();getchar();
return 0;
}
