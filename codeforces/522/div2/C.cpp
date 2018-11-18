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

const int debug = 0;
typedef unsigned uint;
typedef unsigned char uchar;

const int N = 200010;
int dp[6][N];
int a[N];


int main() {


#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	int n, ret;

	while(~scanf("%d",&n)) {
		for(int i=1; i<=n; i++) {
			scanf("%d", &a[i]);
		}
		memset(dp, 0, sizeof(dp));
		for(int j=1;j<=5;j++){
			dp[j][n] = j;
		}
		
		int minj = 1;
		int maxj = 5;
		int tmpMin, tmpMax;
		for(int i=n-1;i>=1;i--){
			tmpMin = 6;
			tmpMax = 0;
			for(int j=1;j<=5;j++){
				if(a[i] < a[i+1]){
					if(j < maxj){
						dp[j][i] = maxj;
					}
				}else if(a[i] > a[i+1]){
					if(j > minj){
						dp[j][i] = minj;
					}
				}else{
					if(j !=  maxj){
						dp[j][i] = maxj;
					}else if(j != minj){
						dp[j][i] = minj;
					}
				}
				
				if(dp[j][i] != 0){
					if(tmpMin > j){
						tmpMin = j;
					}
					if(tmpMax < j){
						tmpMax = j;
					}
				}
				
			}
			minj = tmpMin;
			maxj = tmpMax;
		}
		
		if(minj == 6){
			printf("-1\n");
		}else{
			for(int i=1;i<n;i++){
				printf("%d ", minj);
				minj = dp[minj][i];
			}
			printf("%d\n", minj);
		}
		
		
		
		

	}


	return 0;
}
