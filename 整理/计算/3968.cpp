#include<stdio.h>
#include<stdlib.h>
#include<math.h>
const double eps = 1e-7;
const double g=-9.80;
double xx1,xx2,yy1,yy2;
double vx,vy,a,b;

double myfun(double xx){
	double tt=2*a*xx+b;
	double tmp=sqrt(1+tt*tt);
	return (tt*tmp + log(tt+tmp))/(4*a);
}

int main()
{
	int T;
	double t;
	scanf("%d",&T);
	while(T--){
		scanf("%lf%lf%lf%lf%lf",&xx1,&yy1,&xx2,&yy2,&t);
		if(t<eps){
			printf("Impossible.\n");
		}else{
			xx2-=xx1;
			xx1=0;
			vx=(xx2-xx1)/t;
			vy=(yy2-yy1-g*t*t/2)/t;
			a=g/(2*vx*vx);
			b=vy/vx;
			printf("%.3f\n",fabs(myfun(xx2)-myfun(xx1)));			
		}

	}
	return 0;
}
