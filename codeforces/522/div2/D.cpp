#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
#include<stdarg.h>
using namespace std;
#ifdef __int64
typedef __int64 LL;
#else
typedef long long LL;
#endif

const int debug = 0;
typedef unsigned uint;
typedef unsigned char uchar;

double dis(double x1, double y1, double x2, double y2) {
	return sqrt((x1-x2) * (x1-x2) + (y1-y2)*(y1-y2));

}

int main() {


#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	double a,b,c;
	double x1,y1,x2,y2;

	while(~scanf("%lf%lf%lf",&a,&b,&c)) {
		scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
		double ans;

		//第一种情况，不走斜道
		ans = fabs(x1 - x2) + fabs(y1 - y2);


		//x有两种情况
		//ax+by+c=0
		//x横，y横
		if(a == 0) {
			//y = -c/b
			//只能竖着走
			double y = -c/b;
			double tmpAns = fabs(y - y1) +fabs(y - y2)  + fabs(x1 - x2) ;
			if(tmpAns < ans) {
				ans = tmpAns;
			}

		} else if(b == 0) {
			// x = -c/a
			double x =  -c/a;
			double tmpAns = fabs(x - x1) +fabs(x - x2)  + fabs(y1 - y2) ;
			if(tmpAns < ans) {
				ans = tmpAns;
			}
		} else {
			//y = (-ax - c)/b
			//x = (-b * y - c)/a;
			//有四种情况

			//x1竖着走
			double xx11 = x1;
			double yy11 = (-a* xx11 - c)/b;
			double xy11 = fabs(yy11 - y1);


			double yy12 = y1;
			double xx12 = (-b * yy12 - c)/a;
			double xy12 = fabs(xx12 - x1);


			double xx21 = x2;
			double yy21 = (-a* xx21 - c)/b;
			double xy21 = fabs(yy21 - y2);


			double yy22 = y2;
			double xx22 = (-b * yy22 - c)/a;
			double xy22 = fabs(xx22 - x2);

			double tmpAns;

			//xy11 xy21
			tmpAns = xy11 + xy21 + dis(xx11, yy11, xx21, yy21);
			if(tmpAns < ans) {
				ans = tmpAns;
			}
			
			
			//xy11 xy22
			tmpAns = xy11 + xy22 + dis(xx11, yy11, xx22, yy22);
			if(tmpAns < ans) {
				ans = tmpAns;
			}


			//xy12 xy22
			tmpAns = xy12 + xy22 + dis(xx12, yy12, xx22, yy22);
			if(tmpAns < ans) {
				ans = tmpAns;
			}
			
			//xy12 xy21
			tmpAns = xy12 + xy21 + dis(xx12, yy12, xx21, yy21);
			if(tmpAns < ans) {
				ans = tmpAns;
			}
		}



		printf("%lf\n", ans);

	}


	return 0;
}
