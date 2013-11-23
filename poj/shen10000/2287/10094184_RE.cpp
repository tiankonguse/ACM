#include<stdio.h>
#include<stdlib.h>
int x[55];
int y[55];

int cmp(void const * a,void const *b)
{
	return *((int const *)b) -*((int const *)a);
}

int main()
{
	int n,m,i,j,p;
	while(scanf("%d",&n),n)
	{
		for(i=0;i<n;i++)
			scanf("%d",&x[i]);
		qsort(x,n,sizeof(int),cmp);
		
		for(i=0;i<n;i++)
			scanf("%d",&y[i]);
		qsort(y,n,sizeof(int),cmp);	
		p=n;
		for(m=j=i=0;j<n;j++)
		{
			if(x[i]<y[j])continue;
			if(x[i]>y[j])
			{
				i++;
				m++;
			}
			else
			{
				i++;
				p--;
			}
		}
		printf("%d\n",(m+m-p)*200);
	}
	
return 0;	
}
