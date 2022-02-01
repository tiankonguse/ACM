#define PI 3.1415926
#include<stdio.h>
int main()
{
	int n,i,year;
	float num1,num2;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
	scanf("%f%f",&num1,&num2);	
	year=(num1*num1+num2*num2)*PI/100+1;
	printf("Property %d: This property will begin eroding in year %d.\n",i,year);
	}
	printf("END OF OUTPUT.\n");
	
getchar();
return 0;	
}
