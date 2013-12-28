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

int str[22];
int sum;
int ans;
int n;


void dfs(int lev, int all){
	int tmp = abs(sum - all - all);
	if(tmp < ans){
		ans = tmp;
	}

	if(lev == n){
		return;
	}
	dfs(lev+1,all);
	dfs(lev+1,all+str[lev]);
}

int main() {
	while(~scanf("%d",&n)){
		sum = 0;
		for(int i=0;i<n;i++){
			scanf("%d",&str[i]);
			sum += str[i];
		}
		ans = sum;
		dfs(0,0);
		printf("%d\n",ans);
	}

    return 0;
}
