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
	int ans[1111];
	int n,l,r,k,sn,sk,mid;
	int v1,v2;
	while(~scanf("%d%d%d%d%d%d",&n,&k,&l,&r,&sn,&sk)){
		mid = sk % k;
		v2 = sk / k;
		v1 = v2 + 1;
		for(int i=0;i<mid;i++){
			ans[i] = v1;
		}
		for(int i=mid;i<k;i++){
			ans[i] = v2;
		}
		if(k != n){
			mid = (sn-sk)%(n-k) + k;
			v2 = (sn-sk)/(n-k);
			v1 = v2 + 1;
			for(int i=k;i<mid;i++){
				ans[i] = v1;
			}
			for(int i=mid;i<n;i++){
				ans[i] = v2;
			}
		}
		for(int i=0;i<n;i++){
			printf(i?" %d":"%d",ans[i]);
		}
		puts("");
	}


    return 0;
}
