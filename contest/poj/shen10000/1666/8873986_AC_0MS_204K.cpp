#include<stdio.h>

int main()
{
int n,i;
int str1[10000];

while(scanf("%d",&n),n)
{
	for(i=0;i<n;i++)
	{
	scanf("%d",&str1[i]);
	if(str1[i]%2)str1[i]++;
	}
	
	int num=0,p;

	bool pp;
	while(1)
	{
		pp=true;
		p=str1[0];
		for(i=0;i<n;i++)
		{
		    if(p!=str1[i]){pp=false;break;}		
		}	
		
		if(pp)break;
		
		int hhh=str1[n-1]/2;
		for(i=0;i<n;i++)
		{
		str1[i]=str1[i]/2+hhh;
		hhh=str1[i]-hhh;
		if(str1[i]%2)str1[i]++;	
		}
		num++;	
    }
    printf("%d %d\n",num,p);
	
}

	return 0;
}
