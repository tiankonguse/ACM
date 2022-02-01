#include<stdio.h>

int main()
{

	double sum=2.5;
	double tmp=2;

	printf("n e\n");
	printf("- -----------\n");
	printf("0 1\n");
	printf("1 2\n");
	printf("2 2.5\n");
	for(int i=3;i<10;i++)
	{ 
		sum = 1/(tmp*=i) +sum;
		printf("%d %.9f\n",i,sum);
           
	}

return 0;
}
