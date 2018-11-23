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

const int N=1000000;
const int M=300000;
bool is[N];
int prm[M];
int getprm() {
	int e = (int)(sqrt(0.0 + N) + 1),k=0,i;
	memset(is, 1, sizeof(is));
	prm[k++] = 2;
	is[0] = is[1] = 0;
	for (i = 4; i < N; i += 2) is[i] = 0;
	for(i=3; i<e; i+=2) {
		if(is[i]) {
			prm[k++]=i;
			for(int s=i+i,j=i*i; j<N; j+=s)is[j]=0;
		}
	}
	for (; i < N; i += 2)
		if (is[i])prm[k++] = i;
	return k;
}

LL str[110000];
LL sub[1100000]; //目前以坐标为长度的满足条件的子串个数
LL MOD = 1000000007;
LL factor[110000];

LL solverFactor(LL n) {
	LL index = 0;
	int e = (int)(sqrt(0.0 + n));

	for(int i=1; i<=e; i++) {
		if(n % i == 0) {
			factor[index++] = i;
			if(i  * i == n) {
				break;
			}
			factor[index++] = n / i;
		}
	}

	return index;
}

int main() {
	int maxPrm = getprm();

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif

	LL n;
	LL factorNum;
	LL ans = 0;
	while(~scanf("%lld", &n)) {
		for(int i=1; i<=n; i++) {
			scanf("%lld", &str[i]);
			sub[i] = 0;
		}

		ans = 0;
		for(int i=1; i<=n; i++) {
			factorNum = solverFactor(str[i]);
			sort(factor, factor + factorNum);
			//printf("i=%d value[%lld] factorNum=%lld\n", i,str[i], factorNum);
			for(int j = factorNum-1; j>= 0; j--) {
				LL factorj = factor[j];
				LL factorj_1 = factor[j] - 1;
				
				if(factorj > i) {
					continue;
				}
				if(factorj == 1){
					ans++;
					sub[1]++;
					continue;
				}
				if(sub[factorj_1] > 0){
					ans =  (ans + sub[factorj_1]) % MOD;
					sub[factorj] = (sub[factorj] + sub[factorj_1]) % MOD;
				}
			}
		}
		
		printf("%lld\n", ans);


	}


	return 0;
}
