#include<stdio.h>

int extgcd(int a,int b,int &x,int &y){
	if(b==0){x=1,y=0;return a;}
	int d=extgcd(b,a%b,x,y);
	int t=x;x=y;y=t-a/b*y;
	return d;
}
int main (void)
{
	int x,y,m,n;
	int x1,y1;
	int a,b,c;
	while(scanf("%d %d %d %d %d",&x,&y,&m,&n,&b)!=EOF)
	{
		a=m-n;
		c=y-x;
		int r=extgcd(a,b,x1,y1);
		if(c%r)
			printf("Impossible\n");
		else
		{
			x1=(c*x1/r)%b;
			if(x1<0)x1+=b;
			printf("%d\n",x1);
		}
	}
	return  0;
}
