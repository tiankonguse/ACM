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
	int a,b,n,op,ans;
	while(~scanf("%d%d%d",&n,&a,&b)){
		ans = 0;
		while(n--){
			scanf("%d",&op);
			if(op == 1){
				if(a == 0){
					ans++;
				}else{
					a--;
				}
			}else{
				if(b > 0){
					b--;
				}else if(a > 0){
					a--;
				}else{
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}


    return 0;
}
