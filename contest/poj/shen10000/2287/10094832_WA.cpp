#include<stdio.h>
#include<stdlib.h>
int x[1005];
int y[1005];

int cmp(void const * a,void const *b)
{
	return *((int const *)a) -*((int const *)b);
}

int main()
{
	int n,maxi,maxj,ans,mini,minj;
	while(scanf("%d",&n),n)
	{
		for(int i=0;i<n;i++)
			scanf("%d",&x[i]);
		qsort(x,n,sizeof(int),cmp);
		
		for(int i=0;i<n;i++)
			scanf("%d",&y[i]);
		qsort(y,n,sizeof(int),cmp);	

		for(maxj=maxi=n-1,mini=minj=ans=0;maxj>=minj && maxi>=minj;)
		{
			if(x[maxi]>y[maxj])
			{
				ans+=200;
				maxi--;
				maxj--;
				
			}
			else if(x[maxi]<y[maxj])
			{
				mini++;
				maxj--;
				ans-=200;
			}
			else
			{
				if(x[mini]>y[minj])
				{
					mini++;
					minj++;
					continue;
				}
				if(x[mini]<y[maxj])
				{
					ans-=200;
				}
				mini++;
				maxj--;
			}
		}
		printf("%d\n",ans);
	}
	
return 0;	
}
