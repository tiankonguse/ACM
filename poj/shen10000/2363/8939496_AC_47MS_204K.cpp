#include<stdio.h>

#include<math.h>
int main()
{
int n,m,p1,p2,min,s;
scanf("%d",&n);
while(n--)
{
scanf("%d",&m);
min=100000;
p1=(int)exp(log(m*1.0)/3)+1;
p2=(int)sqrt(m*1.0)+1;
for(int i=1;i<=p1;i++)
for(int j=i;j<=p2;j++)
for(int k=j;k<=m;k++)
{
if(i*j*k==m){s=(i*j+k*j+i*k)*2;if(s<min)min=s;}	
	
}	
printf("%d\n",min);	
	
}


return 0;
}
