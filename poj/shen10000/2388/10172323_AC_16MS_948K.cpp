#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void * b)
{
return *((long long *)a)-*((long long *)b);
}

int main()
{
	int n;
	long long str[100010];
	scanf("%d",&n);

	    long long a=0,sum=0;
	    for(int i=0;i<n;i++)
	        scanf("%lld",&str[i]);
	   
	    qsort(str,n,sizeof(long long),cmp);
	    printf("%lld\n",str[n/2]);
getchar();getchar();getchar();getchar();getchar();

return 0;	
}