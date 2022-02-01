#include<stdio.h>

int main(int argc, char *argv[])
{

 int c,sum,a,b,n,max;	
 scanf("%d",&n);
	while(scanf("%d",&n)!=EOF)
	{      sum=-999999;
		scanf("%d",&c);
		n--;
		a=b=max=c;
		if(a<0)a=0;
		while(n--)
		{
			scanf("%d",&c);
			a+=c;
			b+=c;//b代表目前中的两个最大字段的和
			if(a<0)a=0;
			if(sum<b)sum=b; 
			if(max<a)max=a;//max代表最大子段和 通过a求出 
			if(b<max)b=max;//代表b先付上第一个最大子段的值 
	    }
		printf("%d\n",sum);
	}
return 0;
}
