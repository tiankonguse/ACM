#include<stdio.h>
#define INT __int64 
INT extgcd(INT a,INT b,INT &x,INT &y){
	if(b==0){x=1,y=0;return a;}
	INT d=extgcd(b,a%b,x,y);
	INT t=x;x=y;y=t-a/b*y;
	return d;
}
int main (void)
{
	INT x,y,m,n;
	INT x1,y1;
	INT a,b,c;
	while(scanf("%I64d %I64d %I64d %I64d %I64d",&x,&y,&m,&n,&b)!=EOF)
	{
		a=m-n;
		c=y-x;
		INT r=extgcd(a,b,x1,y1);
		if(c%r)
			printf("Impossible\n");
		else
		{
			x1=(c*x1/r)%b;
			if(x1<0)x1+=b;
			printf("%I64d\n",x1);
		}
	}
	return  0;
}
