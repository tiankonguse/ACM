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


int main() {
	double minx,miny,maxx,maxy,x,y;
	int n;
	while(scanf("%d",&n),n){
		scanf("%lf%lf",&x,&y);
		minx = maxx = x;
		miny = maxy = y;
		for(int i=1;i<n;i++){
			scanf("%lf%lf",&x,&y);
			minx = min(x,minx);
			maxx = max(x,maxx);
			miny = min(miny,y);
			maxy = max(maxy,y);
		}
		printf("%.2f %.2f\n",(maxx + minx)/2, (maxy + miny)/2);
	}

    return 0;
}
