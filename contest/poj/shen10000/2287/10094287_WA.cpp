#include<stdio.h>
#include<stdlib.h>
int x[1005];
int y[1005];

int cmp(void const * a,void const *b)
{
	return *((int const *)b) -*((int const *)a);
}

int main()
{
	int n,m,i,j,ans;
	while(scanf("%d",&n),n)
	{
		for(i=0;i<n;i++)
			scanf("%d",&x[i]);
		qsort(x,n,sizeof(int),cmp);
		
		for(i=0;i<n;i++)
			scanf("%d",&y[i]);
		qsort(y,n,sizeof(int),cmp);	
		ans=0;
		for(m=j=i=0;j<n;j++)
		{
			if(x[i]<y[j])
			{
				ans-=200;
			}
			else if(x[i]>y[j])
			{
				i++;
				ans+=200;
			}
			else
			{
				i++;
			}
		}
		printf("%d\n",ans);
	}
	
return 0;	
}
