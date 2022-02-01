#include<stdio.h>
#include<string.h>
const int N=500005;
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
		printf("%lld\n",str1[n]);
	}

return 0;
}