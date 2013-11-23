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


const int N = 101000;
LL b[N], p[N];
LL a;
int n,m;

bool ok(int k){
	LL tmp = a;
	int l = n - k;
	for(int i=0;i<k;i++,l++){
		if(b[i] <= p[l]){
			continue;
		}else if(b[i] > p[l] && b[i] <= p[l] + tmp){
			tmp -= (b[i] - p[l]);
		}else{
			return false;
		}
	}
	return true;
}


int main() {
	int i,j,k;
	int r,l,mid;
	int ans;
	LL s;
	while(~scanf("%d%d%lld",&n,&m,&a)){
		for(i=0;i<n;i++){
			scanf("%lld",&p[i]);
		}
		for(i=0;i<m;i++){
			scanf("%lld",&b[i]);
		}
		sort(b,b+m);
		sort(p,p+n);
		l = 0;
		r = min(m,n);
		while(l<=r){
			mid = (l+r)>>1;
			if(ok(mid)){
				l = mid + 1;
			}else{
				r = mid - 1;
			}
		}
//		printf("%d");
		ans = l -1;
		s = 0;
		for(i=0;i<ans;i++){
			s += b[i];
		}
		s  = max(s-a,0LL);
		printf("%d %lld\n",ans,s);
	}

    return 0;
}

//10 10 0
//1000000000  1000000000 1000000000 1000000000  1000000000 1000000000  1000000000  1000000000 1000000000 1000000000
//1000000000 1000000000 1000000000 1000000000  1000000000 1000000000 1000000000  1000000000 1000000000 1000000000
