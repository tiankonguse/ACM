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

const int N = 30010;
double e = 0.6180339887498949;
int str[N];
int ansl,ansr;
double ans;

bool check(double l, double r){
	double ee = fabs(l/r - e);
	if(ee <= ans){
		ans = ee;
		return true;
	}else{
		return false;
	}
}

int main() {
    int n,i;

    int r;
    while(~scanf("%d",&n)){
    	ansl = n;
		for(i=0;i<n;i++){
			scanf("%d",&str[i]);
		}

		sort(str,str+n);
		ans = str[1]*1.0/str[0] + e;
		for(i=0;i<n-1;i++){
			r = lower_bound(str+i,str+n,(int)(str[i]/e)) - str;

			if(r - 1 > i && check(str[i],str[r-1])){
				ansl = str[i];
				ansr = str[r-1];
			}

			if(r < n && check(str[i],str[r])){
				ansl = str[i];
				ansr = str[r];
			}

			if(r + 1 < n && check(str[i],str[r+1])){
				ansl = str[i];
				ansr = str[r+1];
			}

		}
		printf("%d %d\n",ansl,ansr);
    }


    return 0;
}
