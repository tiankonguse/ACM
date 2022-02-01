#include<stdio.h>
#include<string.h>
const int N=500015;
long long str0[N];
long long  str2[N];
long long  str1[N];

long long  fun(int l,int r)
{
	return str2[r]-str2[l]-(r-l)*str0[l];
}

int main()
{
	int t,n,k,p,q,v;
	long long  sum;
	scanf("%d",&t);
	str2[0]=0;	
	str1[0]=0;
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&str0[i]);
			str2[i]=str2[i-1]+str0[i];
		}
			
		str1[k]=fun(1,k);
		//printf("str1[%d]=%lld\n",k,str1[k]);
		p=1;
		
		for(int i=k+1;i<=n;i++)
		{
			str1[i]=str1[i-1]+str0[i]-str0[p];
			int j=p<=k?k+1:p;
			int end=i-k+1;
			
			for(;j<=end;j++)
			{
				sum=str1[j]+fun(j+1,i);
				if(sum<=str1[i]){str1[i]=sum;p=j+1;}
			}
			/*
			
			
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
			*/
		}
		printf("%lld\n",str1[n]);
	}

return 0;
}