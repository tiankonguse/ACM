#include<stdio.h>
	float a[20];
float fab(int n)
{
	if(n==1){a[1]=0.5;return a[1];}
else
{
a[n]=fab(n-1)+1/((n+1)*1.0);
return a[n];
}	
}

int main()
{
	float num;
	int n,i;
	fab(277);
	while(1)	
	{
		scanf("%f",&num);
	if(num<0.01)break;
	for(i=0;i<277;i++)
	if(a[i]>=num)
	{printf("%d card(s)\n",i);break;}	
		
		
		
	}

//getchar();getchar();
return 0;	
}
