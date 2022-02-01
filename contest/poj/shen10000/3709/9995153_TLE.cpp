#include<stdio.h>
#include<string.h>
const int N=500005;
int str0[N];
int str2[N];
int str1[N];

int fun(int l,int r)
{
	return str2[r]-str2[l]-(r-l)*str0[l];
}

int main()
{
	int t,n,k,sum,p,q,min,v;
	scanf("%d",&t);
	while(t--)
	{
		memset(str1,0,sizeof(str1));
		memset(str2,-1,sizeof(str2));
		scanf("%d%d",&n,&k);
		str2[0]=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&str0[i]);
			str2[i]=str2[i-1]+str0[i];
		}
			

		 sum=1;
		str1[k]=fun(1,k);
		p=1;
		for(int i=k+1;i<=n;i++)
		{
			q=i-k+1;
			v=p;
			min=str1[i-1]+str0[i]-str0[p];
			for(int j=p+1;j<=q;j++)
			{
				if(j<=k)continue;
				sum=str1[j-1]+fun(j,i);
				if(min>=sum){min=sum;v=j;}
			}
			p=v;
			str1[i]=min;
		}
		printf("%d\n",str1[n]);
	}

return 0;
}