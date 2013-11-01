#include<stdio.h>
#include <float.h>
double x[32];
double y[32];
int n;
double xintersect(
   double x0, double y0, double x1, double y1,
    double xp, double yp, double k)
{
    return ((k * xp + y0 - yp) * (x1 - x0) + x0 * (y0 - y1)) / (k * (x1 - x0) + (y0 - y1));
}

double check(double x0,double y0)
{
	double k1,k2,l1,l2;
	k1=-DBL_MAX;
	k2=+DBL_MAX;
	for(int i=0;i<n;i++)
	{
		if(x[i]==x0)continue;
		l1=(y[i]-1.0-y0)/(x[i]-x0);
		l2=(y[i]-y0)/(x[i]-x0);
		if(l1>l2)
		{
			if((l1<k1) || (l2>k2))return x[0];
			if(l1<k2)k2=l1;
			if(l2>k1)k1=l2;
		}
		else
		{
			if(l1>k2)
			{
				return xintersect(x[i-1], y[i - 1] - 1.0, x[i], y[i] - 1.0, x0, y0, k2);
			}
			if (l2 < k1)
                return xintersect(x[i-1], y[i-1], x[i], y[i], x0, y0, k1);
                
            if (l2 < k2) k2 = l2;
            if (l1 > k1) k1 = l1;
		}
		
	}
return x[n - 1];	
}

int main()
{
	double c,r;
	while(scanf("%d",&n),n)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%lf%lf",&x[i],&y[i]);
		}
		r=x[0];
		for(int i=0;i<n;i++)
		{
			c=check(x[i],y[i]);
			if(c>r)r=c;
			c=check(x[i],y[i]-1.0);
			if(c>r)r=c;
			if(r==x[n-1])break;
		}
		if(r==x[n-1])printf("Through all the pipe.\n");
		else printf("%.2f\n",r);
	}

return 0;	
}
