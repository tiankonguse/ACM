#include<stdio.h>
int main()
{
	 int n,m,max;
	 while(scanf("%d",&n),n)
	{ 
		max=-1;
		while(n--)
		{
			scanf("%d",&m);
			max=max>m?max:m;	
		}
		if(max>=1000000) printf("Too much money to pay!\n");
		else printf("The CEO must bring %d pounds.\n",max);
		
	}
	

return 0;
}
