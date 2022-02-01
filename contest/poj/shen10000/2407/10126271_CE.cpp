#include<stdio.h>
#include<math.h>

int _euler(int x)//???
{
    int i,res=x;
    int max=(int)sqrt(x*1.0)+1;
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
int n;
while(scanf("%d",&n),n)
{
	printf("%d\n",_euler(n));
}
return 0;	
}
