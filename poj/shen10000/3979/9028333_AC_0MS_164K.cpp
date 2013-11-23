#include<stdio.h>

int god(int x,int y)
{
if(x<0)x=-x;
if(!x||!y)return x>y?x:y;

for(int t;t=x%y;x=y,y=t);

return y;		
}

int main()
{
	int x1,y1,x2,y2,x3,y3,gcd;
	char c;
	//scanf("%d",&x1);
	while(scanf("%d/%d%c%d/%d",&x1,&y1,&c,&x2,&y2)!=EOF)
	{
		
		if(c=='-')x2=-x2;	
		
		x3=x1*y2+x2*y1;
		y3=y1*y2;		
		int k=x3%y3;
		if(k==0){printf("%d\n",x3/y3);continue;}
		

		gcd=god(x3,y3);
		x3/=gcd;
		y3/=gcd;
   printf("%d/%d\n",x3,y3);
			
	}

return 0;	
	
	
}

