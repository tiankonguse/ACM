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
const int N = 1000000;
int str[N];
int sum[N];


int main() {
	int minVal,minPos;
	int n,k,tmp;
	while(~scanf("%d%d",&n,&k)){
		sum[0] = 0;
		for(int i=1;i<=n;i++){
			scanf("%d",&str[i]);
			sum[i] = sum[i-1] + str[i];
		}

		minPos = 1;
		minVal = sum[k];
		for(int i=2;i<=n;i++){
			if(i+k-1 > n){
				break;
			}
			tmp = sum[i + k-1] - sum[i-1];
			if(tmp < minVal){
				minVal = tmp;
				minPos = i;
			}
		}
		printf("%d\n",minPos);

	}

    return 0;
}
