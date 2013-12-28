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
const int N = 555555;
int str[N];
int main() {
	int n,i,ans,l,r;
	while(~scanf("%d",&n)){
		for(i=0;i<n;i++){
			scanf("%d",&str[i]);
		}
		sort(str,str+n);
		ans = n;
		l = 0;

		int t = r = n/2;
		for(l=0,r=n/2;l < t && r<n;r++){
			if(str[l]*2 <= str[r]){
				ans--;
				l++;
			}
		}
		printf("%d\n",ans);
	}

    return 0;
}
