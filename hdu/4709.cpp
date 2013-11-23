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
typedef long long LL;

const int N = 200;
const int inf = 9999999;

struct Point {
    double x,y;
} str[N];

double Cross(Point a, Point b, Point c) { //叉积，返回的是平行四边形的面积
    return(a.x - c.x)*(b.y - c.y) - (b.x - c.x)*(a.y - c.y);
}


int main() {

    int n;
    int cas,i,j,k;
    double ans,tmp;
    scanf("%d",&cas);
    while(cas--) {
        scanf("%d",&n);
        for(i=0;i<n;i++){
			scanf("%lf%lf",&str[i].x, &str[i].y);
        }
        ans = inf;
        for(i=0; i<n; i++) {
            for(j=i+1; j<n; j++) {
                for(k=j+1; k<n; k++) {
                	tmp = Cross(str[i],str[j],str[k]) / 2.0;
                	if(tmp < 0){
						tmp = -tmp;
                	}
                	if(tmp != 0 && tmp < ans){
                		ans = tmp;
                	}
                }
            }
        }
        if(ans == inf) {
            printf("Impossible\n");
        } else {
            printf("%.2f\n",ans);
        }
    }

    return 0;
}

