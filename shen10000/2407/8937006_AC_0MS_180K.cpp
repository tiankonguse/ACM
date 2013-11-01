#include<stdio.h>
#include<math.h>


int main()
{
int n,i,res;
while(scanf("%d",&n),n)
{res=n;
for(i=2;i<(int)(sqrt(n*1.0))+1;i++)	
	if(n%i==0)
	{
	res=(res/i)*(i-1);
	while(n%i==0)n/=i;
    }


if(n>1)res=(res/n)*(n-1);
printf("%d\n",res);
}

return 0;
}
