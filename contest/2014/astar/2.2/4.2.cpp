/*************************************************************************
  > File Name: 4.2.cpp
  > Author: tiankonguse
  > Mail: i@tiankonguse.com
  > Created Time: Mon 26 May 2014 01:06:18 PM CST
***********************************************************************/
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
const int N = 10000010;
LL nod[N];
LL count[N];
LL ans[N];

void __sieve_nod() {
	memset(nod, 0,sizeof(nod));
    for (int i = 1; i < N; i+=2) {
        for (int j = i; j < N; j += i) {
            ++nod[j];
        }
    }
}

void init(){
	ans[0] = 1;
	ans[1] = 2;
	LL count = 1;
	for(int i=2;i<N;i++){
		count += nod[i-1];
		ans[i] = ans[i-1] + count;
	}
}


int main() {
	__sieve_nod();
	init();
    int t,n;
    scanf("%d",&t);
    for(int i=1; i<=t; i++) {
        scanf("%d",&n);
        printf("Case #%d:\n%I64d\n",i,ans[n]);
    }
    return 0;
}
