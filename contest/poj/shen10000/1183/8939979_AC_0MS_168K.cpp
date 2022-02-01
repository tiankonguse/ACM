#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	__int64 a,num,m,i;
	scanf("%I64d",&a);
	num=a*a+1;
	for(i=a;i>=1;i--)
	{
		m=num%i;
		if(m==0){m=num/i;break;}
    }
    num=a+a+m+i;
    printf("%I64d\n",num);



getchar();getchar();
return 0;
}
