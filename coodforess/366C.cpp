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

const int N = 101000;

int a[111],b[N],dp[111][N];

int main() {
	int n,k,i,j,sum;
	while(~scanf("%d%d",&n,&k)){
		sum = 0;
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			sum += a[i];
		}
		for(i=0;i<n;i++){
			scanf("%d",&b[i]);
			b[i] *= k;
		}
		memset(dp,-1,sizeof(dp));

		dp[0][0] = 0;
		for(i=0;i<n;i++){
			for(j=0;j<)
		}

	}

    return 0;
}
