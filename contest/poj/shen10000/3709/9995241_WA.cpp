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
	str2[0]=0;	
	while(t--)
	{
		memset(str1,0,sizeof(str1));
		memset(str2,-1,sizeof(str2));
		scanf("%d%d",&n,&k);

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
			str1[i]=str1[i-1]+str0[i]-str0[p];
			
			if(p>k && i-p==k)
			{
				sum=str1[p]+fun(p+1,i);
				if(sum<=str1[i]){str1[i]=sum;p++;}
			}
			else if(i-p+1==k+k)
			{
				sum=str1[p-1]+fun(p,p+k-1)+fun(p+k,i);
				if(sum<=str1[i]){str1[i]=sum;p+=k;}
			}
		}
		printf("%d\n",str1[n]);
	}

return 0;
}