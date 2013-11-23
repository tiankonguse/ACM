#include <stdio.h>
#include <math.h>
int main()
{
	double vs,r,c,w,vr;
	int i,t;
	scanf("%lf %lf %lf %d",&vs,&r,&c,&t);
	for(i=1;i<=t;i++)
	{
		scanf("%lf",&w);
		vr=c*r*w*vs/sqrt(1+c*r*w*c*r*w);
		printf("%.3lf\n",vr);
	}
	return 0;
}
