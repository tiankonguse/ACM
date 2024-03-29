#include<stdio.h>
#include<string.h>
#include<math.h>
#define LL long long
const int N=80000;
LL str[N];
LL phi[N+1];

void euler()//??
{
    LL i,j;
    for(i=1;i<=N;i++) phi[i]=i;
    for(i=2;i<=N;i+=2) phi[i]/=2;
    for(i=3;i<=N;i+=2)
        if(phi[i]==i)
            for(j=i;j<=N;j+=i)
                phi[j]=phi[j]/i*(i-1);
}

LL _euler(LL x)//???
{
	if(x<=N)return phi[x];
    LL i,res=x;
    LL max=(LL)sqrt(x*1.0)+1;
    for(i=2;i<max;i++)
        if(x%i==0)
        {
            res=res/i*(i-1);
            while(x%i==0)x/=i;
        }
    if(x>1)res=res/x*(x-1);
    return res;
}

int main()
{
euler();
LL n,ans,i,k;
while(scanf("%lld",&n)!=EOF)
{
	k=ans=0;
	for(i=1;i*i<n;i++)
	{
		if(n%i==0)
		{
			str[k++]=i;
			str[k++]=n/i;
		}
	}
	if(i*i==n)
	{
		str[k++]=i;
	}
	
	if(k==2)
	{
		printf("%lld\n",n+n-1);
		continue;
	}
	for(i=0;i<k;i++)
	{
		ans+=str[i]*_euler(n/str[i]);
	}
	printf("%lld\n",ans);

}
return 0;	
}
