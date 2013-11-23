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
   /* 	    
	    for(int i=0;i<n;i++)
	    for(int j=0;j<n;j++)
	        sum+=((a=str[i]-str[j])>=0?a:(-a));
	    printf("%lld\n",sum);
	   */
	   
	    qsort(str,n,sizeof(long long),cmp);
	 for(int i=1;i<n;i++)
	    a+=(str[i]-str[0]);

	  if(n==1)
	  {
	    printf("0\n");
	  }
	  else if(n==2)
	  {
	    printf("%lld\n",a+a);
	  
	  }
	  else
	  {
	  
	      sum=a;
	      for(int i=1;i<n;i++)
	      {
	        a+=(i+i-n)*(str[i]-str[i-1]);
	        sum+=a;
	      }
	      printf("%lld\n",sum);

	  }
return 0;	
}
