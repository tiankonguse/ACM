#include<stdio.h>
#define N 1001000
int str[78500];
int num=2;
void fun()
{   
	int i,j; 
	for(i=5;i<=N;i+=2)
	{
		for(j=1;j<num;j++)
		    if(i%str[j]==0)break;		
			
		if(j>=num){str[num]=i;num++;}		
	}		
}
int main()
{
str[0]=2;
str[1]=3;
 fun();
 bool p1,p2;
 int m,n,x1,x2,i;
while(scanf("%d%d",&n,&m),(n+1)&&(m+1))
{  p1=true;
p2=true;
for(i=0;i<=num;i++)
{
if(p1||p2)
{
if(p1){if(str[i]>=n){x1=i;p1=false;}}
if(p2){if(str[i]>m){x2=i;p2=false;}}		
}
else break;	
	
}	
	
printf("%d\n",x2-x1);	
}
	   //getchar();getchar();
return 0;
}
