#include <stdio.h>
#include <stdlib.h>

int an[1034];

int cmp(const void *x,const void *y)
{
	return *((int *)x)-*((int *)y);
}

int main()
{
	int num;
	int m,n,k,i,j;


	scanf("%d",&num);
	for(m=0;m<num;m++)
	{
		scanf("%d%d",&n,&k);

		for(i=1;i<=n;i++)
			scanf("%d",&an[i]);
		an[0]=100000;
		for(i=0;i<k;i++) 
		{
			for(j=n;j>=1 && an[j-1]>an[j];j--);
			if(j>=1)
			{
				int nMinLarger=an[j];
				int nMinIdx=j;
				int kk;
				for(kk=j;kk<=n;kk++)
				{
					if(nMinLarger>an[kk] && an[kk]>an[j-1])
					{
						nMinLarger=an[kk];
						nMinIdx=kk;
					}
				}
				an[nMinIdx]=an[j-1];
				an[j-1]=nMinLarger;
				qsort(an+j,n-j+1,sizeof(int),cmp);  
			}
			else  
			{
				for(j=1;j<=n;j++)
					an[j]=j;
			}
		}
		for(j=1;j<=n;j++)
			printf("%d ",an[j]);
		printf("\n");

	}
	return 0;
}
