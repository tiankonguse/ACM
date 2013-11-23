#include<stdio.h>

int main(int argc, char *argv[])
{

 int c,sum,a,b,n,max;	
 scanf("%d",&n);
	while(scanf("%d",&n)!=EOF)
	{
		scanf("%d",&c);
		n--;
		a=b=max=c;
		
		n--;
		scanf("%d",&c);
		if(a>0)a+=c;
		else a=c;
		b+=c;
		sum=b;
		if(max<a)max=a;
		if(b<max)b=max;
		
		while(n--)
		{
			scanf("%d",&c);
			if(a>0)a+=c;
			else a=c;
			b+=c;
			if(sum<b)sum=b; 
			if(max<a)max=a;
			if(b<max)b=max;
	    }
		printf("%d\n",sum);
	}
return 0;
}


