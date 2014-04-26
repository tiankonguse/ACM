/*************************************************************************
  > File Name: prime2.cpp
  > Author: tiankonguse
  > Mail: i@tiankonguse.com 
  > Created Time: Sat 26 Apr 2014 09:22:04 PM CST
***********************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
#include<stdarg.h>
#include<ctime>
using namespace std;
#ifdef __int64
typedef __int64 LL;
#else
typedef long long LL;
#endif
const int N=1000000010;
const int M=300000000;
bool is[N]; 
int prm[M];
int getprm(){
	int e = (int)(sqrt(0.0 + N) + 1),k=0,i;
	memset(is, 1, sizeof(is));
	prm[k++] = 2; is[0] = is[1] = 0;
	for (i = 4; i < N; i += 2) is[i] = 0;
	for(i=3;i < e;i+=2){
		if(is[i]){
			prm[k++]=i;
			for(int s=i+i,j=i*i;j < N;j+=s)is[j]=0;
		}
	}
	for (; i < N; i += 2)
		if (is[i])prm[k++] = i;
	return k; 
}

int main() {
    int n;
    clock_t start, end;
    start = clock();
    int count = getprm();
    end = clock() - start;
    printf
    ("[%d]内的素数个数为%d，计算用时：%d毫秒\n",
     N, count, (int)end / 1000);

    return 0;
}
