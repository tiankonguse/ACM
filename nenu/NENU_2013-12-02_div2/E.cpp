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
struct point {
    double x, y;
};
bool mult(point sp, point ep, point op) {
    return (sp.x - op.x) * (ep.y - op.y)
           >= (ep.x - op.x) * (sp.y - op.y);
}
bool operator < (const point &l, const point &r) {
    return l.y < r.y || (l.y == r.y && l.x < r.x);
}

double dis(point a, point b){
	return sqrt((a.x - b.x) *(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

int graham(point pnt[], int n, point res[]) {
    int i, len, k = 0, top = 1;
    sort(pnt, pnt + n);
    if (n == 0) return 0;
    res[0] = pnt[0];
    if (n == 1) return 1;
    res[1] = pnt[1];
    if (n == 2) return 2;
    res[2] = pnt[2];
    for (i = 2; i < n; i++) {
        while (top && mult(pnt[i], res[top], res[top-1]))
            top--;
        res[++top] = pnt[i];
    }
    len = top;
    res[++top] = pnt[n - 2];
    for (i = n - 3; i >= 0; i--) {
        while (top!=len && mult(pnt[i], res[top],
                                res[top-1])) top--;
        res[++top] = pnt[i];
    }
    return top;
// 返回凸包中点的个数
}


int main() {
	int n,num,i,j;
	double r,ans;
	point in[200];
	point out[200];
	while(~scanf("%d%lf",&n,&r)){
		for(i=0;i<n;i++){
			scanf("%lf%lf",&in[i].x,&in[i].y);
		}

		if(n==1){
			ans = 2*acos(-1)*r;
		}else if(n==2){
			ans = 2*acos(-1)*r+2*dis(in[0],in[1]);
		}else{
			bool ok=false;
			for(i=2;i<n;i++){
				if(fabs((in[i].x-in[i-1].x)*(in[i-1].y-in[i-2].y))!=fabs((in[i-1].x-in[i-2].x)*(in[i].y-in[i-1].y))){ok=true;break;}
			}
			if(ok){
				num = graham(in, n, out);
				out[num] = out[0];
				num++;
				ans = 0;
				for(int i=1;i<num;i++){
					ans += dis(out[i-1],out[i]);
				}
				ans += 2*acos(-1)*r;
			}else{
				double tmp =0;
				for(i=0;i<n;i++){
					for(j=i+1;j<n;j++){
						tmp = max(tmp,dis(in[i],in[j]));
					}
				}
				ans = tmp*2+2*acos(-1)*r;
			}
		}
		printf("%.2f\n",ans);

	}

    return 0;
}
